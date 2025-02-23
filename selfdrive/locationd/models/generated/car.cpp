#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.13.2                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_5299514782424555133) {
   out_5299514782424555133[0] = delta_x[0] + nom_x[0];
   out_5299514782424555133[1] = delta_x[1] + nom_x[1];
   out_5299514782424555133[2] = delta_x[2] + nom_x[2];
   out_5299514782424555133[3] = delta_x[3] + nom_x[3];
   out_5299514782424555133[4] = delta_x[4] + nom_x[4];
   out_5299514782424555133[5] = delta_x[5] + nom_x[5];
   out_5299514782424555133[6] = delta_x[6] + nom_x[6];
   out_5299514782424555133[7] = delta_x[7] + nom_x[7];
   out_5299514782424555133[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3535349126216233199) {
   out_3535349126216233199[0] = -nom_x[0] + true_x[0];
   out_3535349126216233199[1] = -nom_x[1] + true_x[1];
   out_3535349126216233199[2] = -nom_x[2] + true_x[2];
   out_3535349126216233199[3] = -nom_x[3] + true_x[3];
   out_3535349126216233199[4] = -nom_x[4] + true_x[4];
   out_3535349126216233199[5] = -nom_x[5] + true_x[5];
   out_3535349126216233199[6] = -nom_x[6] + true_x[6];
   out_3535349126216233199[7] = -nom_x[7] + true_x[7];
   out_3535349126216233199[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5252922282480581452) {
   out_5252922282480581452[0] = 1.0;
   out_5252922282480581452[1] = 0.0;
   out_5252922282480581452[2] = 0.0;
   out_5252922282480581452[3] = 0.0;
   out_5252922282480581452[4] = 0.0;
   out_5252922282480581452[5] = 0.0;
   out_5252922282480581452[6] = 0.0;
   out_5252922282480581452[7] = 0.0;
   out_5252922282480581452[8] = 0.0;
   out_5252922282480581452[9] = 0.0;
   out_5252922282480581452[10] = 1.0;
   out_5252922282480581452[11] = 0.0;
   out_5252922282480581452[12] = 0.0;
   out_5252922282480581452[13] = 0.0;
   out_5252922282480581452[14] = 0.0;
   out_5252922282480581452[15] = 0.0;
   out_5252922282480581452[16] = 0.0;
   out_5252922282480581452[17] = 0.0;
   out_5252922282480581452[18] = 0.0;
   out_5252922282480581452[19] = 0.0;
   out_5252922282480581452[20] = 1.0;
   out_5252922282480581452[21] = 0.0;
   out_5252922282480581452[22] = 0.0;
   out_5252922282480581452[23] = 0.0;
   out_5252922282480581452[24] = 0.0;
   out_5252922282480581452[25] = 0.0;
   out_5252922282480581452[26] = 0.0;
   out_5252922282480581452[27] = 0.0;
   out_5252922282480581452[28] = 0.0;
   out_5252922282480581452[29] = 0.0;
   out_5252922282480581452[30] = 1.0;
   out_5252922282480581452[31] = 0.0;
   out_5252922282480581452[32] = 0.0;
   out_5252922282480581452[33] = 0.0;
   out_5252922282480581452[34] = 0.0;
   out_5252922282480581452[35] = 0.0;
   out_5252922282480581452[36] = 0.0;
   out_5252922282480581452[37] = 0.0;
   out_5252922282480581452[38] = 0.0;
   out_5252922282480581452[39] = 0.0;
   out_5252922282480581452[40] = 1.0;
   out_5252922282480581452[41] = 0.0;
   out_5252922282480581452[42] = 0.0;
   out_5252922282480581452[43] = 0.0;
   out_5252922282480581452[44] = 0.0;
   out_5252922282480581452[45] = 0.0;
   out_5252922282480581452[46] = 0.0;
   out_5252922282480581452[47] = 0.0;
   out_5252922282480581452[48] = 0.0;
   out_5252922282480581452[49] = 0.0;
   out_5252922282480581452[50] = 1.0;
   out_5252922282480581452[51] = 0.0;
   out_5252922282480581452[52] = 0.0;
   out_5252922282480581452[53] = 0.0;
   out_5252922282480581452[54] = 0.0;
   out_5252922282480581452[55] = 0.0;
   out_5252922282480581452[56] = 0.0;
   out_5252922282480581452[57] = 0.0;
   out_5252922282480581452[58] = 0.0;
   out_5252922282480581452[59] = 0.0;
   out_5252922282480581452[60] = 1.0;
   out_5252922282480581452[61] = 0.0;
   out_5252922282480581452[62] = 0.0;
   out_5252922282480581452[63] = 0.0;
   out_5252922282480581452[64] = 0.0;
   out_5252922282480581452[65] = 0.0;
   out_5252922282480581452[66] = 0.0;
   out_5252922282480581452[67] = 0.0;
   out_5252922282480581452[68] = 0.0;
   out_5252922282480581452[69] = 0.0;
   out_5252922282480581452[70] = 1.0;
   out_5252922282480581452[71] = 0.0;
   out_5252922282480581452[72] = 0.0;
   out_5252922282480581452[73] = 0.0;
   out_5252922282480581452[74] = 0.0;
   out_5252922282480581452[75] = 0.0;
   out_5252922282480581452[76] = 0.0;
   out_5252922282480581452[77] = 0.0;
   out_5252922282480581452[78] = 0.0;
   out_5252922282480581452[79] = 0.0;
   out_5252922282480581452[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2019747047538005833) {
   out_2019747047538005833[0] = state[0];
   out_2019747047538005833[1] = state[1];
   out_2019747047538005833[2] = state[2];
   out_2019747047538005833[3] = state[3];
   out_2019747047538005833[4] = state[4];
   out_2019747047538005833[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_2019747047538005833[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2019747047538005833[7] = state[7];
   out_2019747047538005833[8] = state[8];
}
void F_fun(double *state, double dt, double *out_9121343994600952035) {
   out_9121343994600952035[0] = 1;
   out_9121343994600952035[1] = 0;
   out_9121343994600952035[2] = 0;
   out_9121343994600952035[3] = 0;
   out_9121343994600952035[4] = 0;
   out_9121343994600952035[5] = 0;
   out_9121343994600952035[6] = 0;
   out_9121343994600952035[7] = 0;
   out_9121343994600952035[8] = 0;
   out_9121343994600952035[9] = 0;
   out_9121343994600952035[10] = 1;
   out_9121343994600952035[11] = 0;
   out_9121343994600952035[12] = 0;
   out_9121343994600952035[13] = 0;
   out_9121343994600952035[14] = 0;
   out_9121343994600952035[15] = 0;
   out_9121343994600952035[16] = 0;
   out_9121343994600952035[17] = 0;
   out_9121343994600952035[18] = 0;
   out_9121343994600952035[19] = 0;
   out_9121343994600952035[20] = 1;
   out_9121343994600952035[21] = 0;
   out_9121343994600952035[22] = 0;
   out_9121343994600952035[23] = 0;
   out_9121343994600952035[24] = 0;
   out_9121343994600952035[25] = 0;
   out_9121343994600952035[26] = 0;
   out_9121343994600952035[27] = 0;
   out_9121343994600952035[28] = 0;
   out_9121343994600952035[29] = 0;
   out_9121343994600952035[30] = 1;
   out_9121343994600952035[31] = 0;
   out_9121343994600952035[32] = 0;
   out_9121343994600952035[33] = 0;
   out_9121343994600952035[34] = 0;
   out_9121343994600952035[35] = 0;
   out_9121343994600952035[36] = 0;
   out_9121343994600952035[37] = 0;
   out_9121343994600952035[38] = 0;
   out_9121343994600952035[39] = 0;
   out_9121343994600952035[40] = 1;
   out_9121343994600952035[41] = 0;
   out_9121343994600952035[42] = 0;
   out_9121343994600952035[43] = 0;
   out_9121343994600952035[44] = 0;
   out_9121343994600952035[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_9121343994600952035[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_9121343994600952035[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_9121343994600952035[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_9121343994600952035[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_9121343994600952035[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_9121343994600952035[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_9121343994600952035[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_9121343994600952035[53] = -9.8000000000000007*dt;
   out_9121343994600952035[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_9121343994600952035[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_9121343994600952035[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_9121343994600952035[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_9121343994600952035[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_9121343994600952035[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_9121343994600952035[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_9121343994600952035[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_9121343994600952035[62] = 0;
   out_9121343994600952035[63] = 0;
   out_9121343994600952035[64] = 0;
   out_9121343994600952035[65] = 0;
   out_9121343994600952035[66] = 0;
   out_9121343994600952035[67] = 0;
   out_9121343994600952035[68] = 0;
   out_9121343994600952035[69] = 0;
   out_9121343994600952035[70] = 1;
   out_9121343994600952035[71] = 0;
   out_9121343994600952035[72] = 0;
   out_9121343994600952035[73] = 0;
   out_9121343994600952035[74] = 0;
   out_9121343994600952035[75] = 0;
   out_9121343994600952035[76] = 0;
   out_9121343994600952035[77] = 0;
   out_9121343994600952035[78] = 0;
   out_9121343994600952035[79] = 0;
   out_9121343994600952035[80] = 1;
}
void h_25(double *state, double *unused, double *out_7335794429038047257) {
   out_7335794429038047257[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6019370044562788701) {
   out_6019370044562788701[0] = 0;
   out_6019370044562788701[1] = 0;
   out_6019370044562788701[2] = 0;
   out_6019370044562788701[3] = 0;
   out_6019370044562788701[4] = 0;
   out_6019370044562788701[5] = 0;
   out_6019370044562788701[6] = 1;
   out_6019370044562788701[7] = 0;
   out_6019370044562788701[8] = 0;
}
void h_24(double *state, double *unused, double *out_8140094201337253727) {
   out_8140094201337253727[0] = state[4];
   out_8140094201337253727[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6226341349295601489) {
   out_6226341349295601489[0] = 0;
   out_6226341349295601489[1] = 0;
   out_6226341349295601489[2] = 0;
   out_6226341349295601489[3] = 0;
   out_6226341349295601489[4] = 1;
   out_6226341349295601489[5] = 0;
   out_6226341349295601489[6] = 0;
   out_6226341349295601489[7] = 0;
   out_6226341349295601489[8] = 0;
   out_6226341349295601489[9] = 0;
   out_6226341349295601489[10] = 0;
   out_6226341349295601489[11] = 0;
   out_6226341349295601489[12] = 0;
   out_6226341349295601489[13] = 0;
   out_6226341349295601489[14] = 1;
   out_6226341349295601489[15] = 0;
   out_6226341349295601489[16] = 0;
   out_6226341349295601489[17] = 0;
}
void h_30(double *state, double *unused, double *out_1168680389066912954) {
   out_1168680389066912954[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7899677699019154717) {
   out_7899677699019154717[0] = 0;
   out_7899677699019154717[1] = 0;
   out_7899677699019154717[2] = 0;
   out_7899677699019154717[3] = 0;
   out_7899677699019154717[4] = 1;
   out_7899677699019154717[5] = 0;
   out_7899677699019154717[6] = 0;
   out_7899677699019154717[7] = 0;
   out_7899677699019154717[8] = 0;
}
void h_26(double *state, double *unused, double *out_5906826438573726884) {
   out_5906826438573726884[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8685870710272706691) {
   out_8685870710272706691[0] = 0;
   out_8685870710272706691[1] = 0;
   out_8685870710272706691[2] = 0;
   out_8685870710272706691[3] = 0;
   out_8685870710272706691[4] = 0;
   out_8685870710272706691[5] = 0;
   out_8685870710272706691[6] = 0;
   out_8685870710272706691[7] = 1;
   out_8685870710272706691[8] = 0;
}
void h_27(double *state, double *unused, double *out_6109276377010658714) {
   out_6109276377010658714[0] = state[3];
}
void H_27(double *state, double *unused, double *out_8323472303506453682) {
   out_8323472303506453682[0] = 0;
   out_8323472303506453682[1] = 0;
   out_8323472303506453682[2] = 0;
   out_8323472303506453682[3] = 1;
   out_8323472303506453682[4] = 0;
   out_8323472303506453682[5] = 0;
   out_8323472303506453682[6] = 0;
   out_8323472303506453682[7] = 0;
   out_8323472303506453682[8] = 0;
}
void h_29(double *state, double *unused, double *out_2471826848756636364) {
   out_2471826848756636364[0] = state[1];
}
void H_29(double *state, double *unused, double *out_8409909043333546901) {
   out_8409909043333546901[0] = 0;
   out_8409909043333546901[1] = 1;
   out_8409909043333546901[2] = 0;
   out_8409909043333546901[3] = 0;
   out_8409909043333546901[4] = 0;
   out_8409909043333546901[5] = 0;
   out_8409909043333546901[6] = 0;
   out_8409909043333546901[7] = 0;
   out_8409909043333546901[8] = 0;
}
void h_28(double *state, double *unused, double *out_8921828480280512097) {
   out_8921828480280512097[0] = state[0];
}
void H_28(double *state, double *unused, double *out_8073204758810678464) {
   out_8073204758810678464[0] = 1;
   out_8073204758810678464[1] = 0;
   out_8073204758810678464[2] = 0;
   out_8073204758810678464[3] = 0;
   out_8073204758810678464[4] = 0;
   out_8073204758810678464[5] = 0;
   out_8073204758810678464[6] = 0;
   out_8073204758810678464[7] = 0;
   out_8073204758810678464[8] = 0;
}
void h_31(double *state, double *unused, double *out_3347684387850831918) {
   out_3347684387850831918[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5988724082685828273) {
   out_5988724082685828273[0] = 0;
   out_5988724082685828273[1] = 0;
   out_5988724082685828273[2] = 0;
   out_5988724082685828273[3] = 0;
   out_5988724082685828273[4] = 0;
   out_5988724082685828273[5] = 0;
   out_5988724082685828273[6] = 0;
   out_5988724082685828273[7] = 0;
   out_5988724082685828273[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_5299514782424555133) {
  err_fun(nom_x, delta_x, out_5299514782424555133);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3535349126216233199) {
  inv_err_fun(nom_x, true_x, out_3535349126216233199);
}
void car_H_mod_fun(double *state, double *out_5252922282480581452) {
  H_mod_fun(state, out_5252922282480581452);
}
void car_f_fun(double *state, double dt, double *out_2019747047538005833) {
  f_fun(state,  dt, out_2019747047538005833);
}
void car_F_fun(double *state, double dt, double *out_9121343994600952035) {
  F_fun(state,  dt, out_9121343994600952035);
}
void car_h_25(double *state, double *unused, double *out_7335794429038047257) {
  h_25(state, unused, out_7335794429038047257);
}
void car_H_25(double *state, double *unused, double *out_6019370044562788701) {
  H_25(state, unused, out_6019370044562788701);
}
void car_h_24(double *state, double *unused, double *out_8140094201337253727) {
  h_24(state, unused, out_8140094201337253727);
}
void car_H_24(double *state, double *unused, double *out_6226341349295601489) {
  H_24(state, unused, out_6226341349295601489);
}
void car_h_30(double *state, double *unused, double *out_1168680389066912954) {
  h_30(state, unused, out_1168680389066912954);
}
void car_H_30(double *state, double *unused, double *out_7899677699019154717) {
  H_30(state, unused, out_7899677699019154717);
}
void car_h_26(double *state, double *unused, double *out_5906826438573726884) {
  h_26(state, unused, out_5906826438573726884);
}
void car_H_26(double *state, double *unused, double *out_8685870710272706691) {
  H_26(state, unused, out_8685870710272706691);
}
void car_h_27(double *state, double *unused, double *out_6109276377010658714) {
  h_27(state, unused, out_6109276377010658714);
}
void car_H_27(double *state, double *unused, double *out_8323472303506453682) {
  H_27(state, unused, out_8323472303506453682);
}
void car_h_29(double *state, double *unused, double *out_2471826848756636364) {
  h_29(state, unused, out_2471826848756636364);
}
void car_H_29(double *state, double *unused, double *out_8409909043333546901) {
  H_29(state, unused, out_8409909043333546901);
}
void car_h_28(double *state, double *unused, double *out_8921828480280512097) {
  h_28(state, unused, out_8921828480280512097);
}
void car_H_28(double *state, double *unused, double *out_8073204758810678464) {
  H_28(state, unused, out_8073204758810678464);
}
void car_h_31(double *state, double *unused, double *out_3347684387850831918) {
  h_31(state, unused, out_3347684387850831918);
}
void car_H_31(double *state, double *unused, double *out_5988724082685828273) {
  H_31(state, unused, out_5988724082685828273);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
