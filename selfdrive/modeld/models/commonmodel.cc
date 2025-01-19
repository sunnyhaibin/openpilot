#include "selfdrive/modeld/models/commonmodel.h"

#include <cmath>
#include <cstring>

#include "common/clutil.h"

DrivingModelFrame::DrivingModelFrame(cl_device_id device_id, cl_context context, uint8_t buffer_length) : ModelFrame(device_id, context), buffer_length(buffer_length) {
  input_frames = std::make_unique<uint8_t[]>(buf_size);
  input_frames_cl = CL_CHECK_ERR(clCreateBuffer(context, CL_MEM_READ_WRITE, buf_size, NULL, &err));
  img_buffer_20hz_cl = CL_CHECK_ERR(clCreateBuffer(context, CL_MEM_READ_WRITE, buffer_length*frame_size_bytes, NULL, &err));
  region.origin = (buffer_length - 1)  * frame_size_bytes;
  region.size = frame_size_bytes;
  last_img_cl = CL_CHECK_ERR(clCreateSubBuffer(img_buffer_20hz_cl, CL_MEM_READ_WRITE, CL_BUFFER_CREATE_TYPE_REGION, &region, &err));
  printf("Buffer length: %d, region origin: %lu, region size: %lu\n", buffer_length, region.origin, region.size);

  loadyuv_init(&loadyuv, context, device_id, MODEL_WIDTH, MODEL_HEIGHT);
  init_transform(device_id, context, MODEL_WIDTH, MODEL_HEIGHT);
}

cl_mem* DrivingModelFrame::prepare(cl_mem yuv_cl, int frame_width, int frame_height, int frame_stride, int frame_uv_offset, const mat3& projection) {
  run_transform(yuv_cl, MODEL_WIDTH, MODEL_HEIGHT, frame_width, frame_height, frame_stride, frame_uv_offset, projection);

  for (int i = 0; i < (buffer_length - 1); i++) {
    printf("Moving %d to %d from src_offset %lu to dst_offset %lu with size %lu\n", i+1, i, (i+1)*frame_size_bytes, i*frame_size_bytes, frame_size_bytes);
    CL_CHECK(clEnqueueCopyBuffer(q, img_buffer_20hz_cl, img_buffer_20hz_cl, (i+1)*frame_size_bytes, i*frame_size_bytes, frame_size_bytes, 0, nullptr, nullptr));
  }
  loadyuv_queue(&loadyuv, q, y_cl, u_cl, v_cl, last_img_cl);

  copy_queue(&loadyuv, q, img_buffer_20hz_cl, input_frames_cl, 0, 0, frame_size_bytes);
  copy_queue(&loadyuv, q, last_img_cl, input_frames_cl, 0, frame_size_bytes, frame_size_bytes);

  // NOTE: Since thneed is using a different command queue, this clFinish is needed to ensure the image is ready.
  clFinish(q);
  return &input_frames_cl;
}

DrivingModelFrame::~DrivingModelFrame() {
  deinit_transform();
  loadyuv_destroy(&loadyuv);
  CL_CHECK(clReleaseMemObject(img_buffer_20hz_cl));
  CL_CHECK(clReleaseMemObject(last_img_cl));
  CL_CHECK(clReleaseCommandQueue(q));
}


MonitoringModelFrame::MonitoringModelFrame(cl_device_id device_id, cl_context context) : ModelFrame(device_id, context) {
  input_frames = std::make_unique<uint8_t[]>(buf_size);
  input_frame_cl = CL_CHECK_ERR(clCreateBuffer(context, CL_MEM_READ_WRITE, buf_size, NULL, &err));

  init_transform(device_id, context, MODEL_WIDTH, MODEL_HEIGHT);
}

cl_mem* MonitoringModelFrame::prepare(cl_mem yuv_cl, int frame_width, int frame_height, int frame_stride, int frame_uv_offset, const mat3& projection) {
  run_transform(yuv_cl, MODEL_WIDTH, MODEL_HEIGHT, frame_width, frame_height, frame_stride, frame_uv_offset, projection);
  clFinish(q);
  return &y_cl;
}

MonitoringModelFrame::~MonitoringModelFrame() {
  deinit_transform();
  CL_CHECK(clReleaseCommandQueue(q));
}
