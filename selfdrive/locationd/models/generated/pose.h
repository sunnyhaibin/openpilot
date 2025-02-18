#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_1541433372370496057);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8373660040473895336);
void pose_H_mod_fun(double *state, double *out_2891433507387146264);
void pose_f_fun(double *state, double dt, double *out_3325430116042611385);
void pose_F_fun(double *state, double dt, double *out_1604126537921635908);
void pose_h_4(double *state, double *unused, double *out_3074186152133531416);
void pose_H_4(double *state, double *unused, double *out_382788571403802989);
void pose_h_10(double *state, double *unused, double *out_3256203287108299981);
void pose_H_10(double *state, double *unused, double *out_4548123818980190037);
void pose_h_13(double *state, double *unused, double *out_8906736968435166145);
void pose_H_13(double *state, double *unused, double *out_2829485253928529812);
void pose_h_14(double *state, double *unused, double *out_6007503255828837104);
void pose_H_14(double *state, double *unused, double *out_3580452284935681540);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}