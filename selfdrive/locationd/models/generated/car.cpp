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
void err_fun(double *nom_x, double *delta_x, double *out_6981285947428203759) {
   out_6981285947428203759[0] = delta_x[0] + nom_x[0];
   out_6981285947428203759[1] = delta_x[1] + nom_x[1];
   out_6981285947428203759[2] = delta_x[2] + nom_x[2];
   out_6981285947428203759[3] = delta_x[3] + nom_x[3];
   out_6981285947428203759[4] = delta_x[4] + nom_x[4];
   out_6981285947428203759[5] = delta_x[5] + nom_x[5];
   out_6981285947428203759[6] = delta_x[6] + nom_x[6];
   out_6981285947428203759[7] = delta_x[7] + nom_x[7];
   out_6981285947428203759[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3103352485653640338) {
   out_3103352485653640338[0] = -nom_x[0] + true_x[0];
   out_3103352485653640338[1] = -nom_x[1] + true_x[1];
   out_3103352485653640338[2] = -nom_x[2] + true_x[2];
   out_3103352485653640338[3] = -nom_x[3] + true_x[3];
   out_3103352485653640338[4] = -nom_x[4] + true_x[4];
   out_3103352485653640338[5] = -nom_x[5] + true_x[5];
   out_3103352485653640338[6] = -nom_x[6] + true_x[6];
   out_3103352485653640338[7] = -nom_x[7] + true_x[7];
   out_3103352485653640338[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_7545812970075001068) {
   out_7545812970075001068[0] = 1.0;
   out_7545812970075001068[1] = 0.0;
   out_7545812970075001068[2] = 0.0;
   out_7545812970075001068[3] = 0.0;
   out_7545812970075001068[4] = 0.0;
   out_7545812970075001068[5] = 0.0;
   out_7545812970075001068[6] = 0.0;
   out_7545812970075001068[7] = 0.0;
   out_7545812970075001068[8] = 0.0;
   out_7545812970075001068[9] = 0.0;
   out_7545812970075001068[10] = 1.0;
   out_7545812970075001068[11] = 0.0;
   out_7545812970075001068[12] = 0.0;
   out_7545812970075001068[13] = 0.0;
   out_7545812970075001068[14] = 0.0;
   out_7545812970075001068[15] = 0.0;
   out_7545812970075001068[16] = 0.0;
   out_7545812970075001068[17] = 0.0;
   out_7545812970075001068[18] = 0.0;
   out_7545812970075001068[19] = 0.0;
   out_7545812970075001068[20] = 1.0;
   out_7545812970075001068[21] = 0.0;
   out_7545812970075001068[22] = 0.0;
   out_7545812970075001068[23] = 0.0;
   out_7545812970075001068[24] = 0.0;
   out_7545812970075001068[25] = 0.0;
   out_7545812970075001068[26] = 0.0;
   out_7545812970075001068[27] = 0.0;
   out_7545812970075001068[28] = 0.0;
   out_7545812970075001068[29] = 0.0;
   out_7545812970075001068[30] = 1.0;
   out_7545812970075001068[31] = 0.0;
   out_7545812970075001068[32] = 0.0;
   out_7545812970075001068[33] = 0.0;
   out_7545812970075001068[34] = 0.0;
   out_7545812970075001068[35] = 0.0;
   out_7545812970075001068[36] = 0.0;
   out_7545812970075001068[37] = 0.0;
   out_7545812970075001068[38] = 0.0;
   out_7545812970075001068[39] = 0.0;
   out_7545812970075001068[40] = 1.0;
   out_7545812970075001068[41] = 0.0;
   out_7545812970075001068[42] = 0.0;
   out_7545812970075001068[43] = 0.0;
   out_7545812970075001068[44] = 0.0;
   out_7545812970075001068[45] = 0.0;
   out_7545812970075001068[46] = 0.0;
   out_7545812970075001068[47] = 0.0;
   out_7545812970075001068[48] = 0.0;
   out_7545812970075001068[49] = 0.0;
   out_7545812970075001068[50] = 1.0;
   out_7545812970075001068[51] = 0.0;
   out_7545812970075001068[52] = 0.0;
   out_7545812970075001068[53] = 0.0;
   out_7545812970075001068[54] = 0.0;
   out_7545812970075001068[55] = 0.0;
   out_7545812970075001068[56] = 0.0;
   out_7545812970075001068[57] = 0.0;
   out_7545812970075001068[58] = 0.0;
   out_7545812970075001068[59] = 0.0;
   out_7545812970075001068[60] = 1.0;
   out_7545812970075001068[61] = 0.0;
   out_7545812970075001068[62] = 0.0;
   out_7545812970075001068[63] = 0.0;
   out_7545812970075001068[64] = 0.0;
   out_7545812970075001068[65] = 0.0;
   out_7545812970075001068[66] = 0.0;
   out_7545812970075001068[67] = 0.0;
   out_7545812970075001068[68] = 0.0;
   out_7545812970075001068[69] = 0.0;
   out_7545812970075001068[70] = 1.0;
   out_7545812970075001068[71] = 0.0;
   out_7545812970075001068[72] = 0.0;
   out_7545812970075001068[73] = 0.0;
   out_7545812970075001068[74] = 0.0;
   out_7545812970075001068[75] = 0.0;
   out_7545812970075001068[76] = 0.0;
   out_7545812970075001068[77] = 0.0;
   out_7545812970075001068[78] = 0.0;
   out_7545812970075001068[79] = 0.0;
   out_7545812970075001068[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_7404244546590542183) {
   out_7404244546590542183[0] = state[0];
   out_7404244546590542183[1] = state[1];
   out_7404244546590542183[2] = state[2];
   out_7404244546590542183[3] = state[3];
   out_7404244546590542183[4] = state[4];
   out_7404244546590542183[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7404244546590542183[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7404244546590542183[7] = state[7];
   out_7404244546590542183[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7187733473119293793) {
   out_7187733473119293793[0] = 1;
   out_7187733473119293793[1] = 0;
   out_7187733473119293793[2] = 0;
   out_7187733473119293793[3] = 0;
   out_7187733473119293793[4] = 0;
   out_7187733473119293793[5] = 0;
   out_7187733473119293793[6] = 0;
   out_7187733473119293793[7] = 0;
   out_7187733473119293793[8] = 0;
   out_7187733473119293793[9] = 0;
   out_7187733473119293793[10] = 1;
   out_7187733473119293793[11] = 0;
   out_7187733473119293793[12] = 0;
   out_7187733473119293793[13] = 0;
   out_7187733473119293793[14] = 0;
   out_7187733473119293793[15] = 0;
   out_7187733473119293793[16] = 0;
   out_7187733473119293793[17] = 0;
   out_7187733473119293793[18] = 0;
   out_7187733473119293793[19] = 0;
   out_7187733473119293793[20] = 1;
   out_7187733473119293793[21] = 0;
   out_7187733473119293793[22] = 0;
   out_7187733473119293793[23] = 0;
   out_7187733473119293793[24] = 0;
   out_7187733473119293793[25] = 0;
   out_7187733473119293793[26] = 0;
   out_7187733473119293793[27] = 0;
   out_7187733473119293793[28] = 0;
   out_7187733473119293793[29] = 0;
   out_7187733473119293793[30] = 1;
   out_7187733473119293793[31] = 0;
   out_7187733473119293793[32] = 0;
   out_7187733473119293793[33] = 0;
   out_7187733473119293793[34] = 0;
   out_7187733473119293793[35] = 0;
   out_7187733473119293793[36] = 0;
   out_7187733473119293793[37] = 0;
   out_7187733473119293793[38] = 0;
   out_7187733473119293793[39] = 0;
   out_7187733473119293793[40] = 1;
   out_7187733473119293793[41] = 0;
   out_7187733473119293793[42] = 0;
   out_7187733473119293793[43] = 0;
   out_7187733473119293793[44] = 0;
   out_7187733473119293793[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7187733473119293793[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7187733473119293793[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7187733473119293793[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7187733473119293793[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7187733473119293793[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7187733473119293793[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7187733473119293793[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7187733473119293793[53] = -9.8000000000000007*dt;
   out_7187733473119293793[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7187733473119293793[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7187733473119293793[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7187733473119293793[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7187733473119293793[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7187733473119293793[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7187733473119293793[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7187733473119293793[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7187733473119293793[62] = 0;
   out_7187733473119293793[63] = 0;
   out_7187733473119293793[64] = 0;
   out_7187733473119293793[65] = 0;
   out_7187733473119293793[66] = 0;
   out_7187733473119293793[67] = 0;
   out_7187733473119293793[68] = 0;
   out_7187733473119293793[69] = 0;
   out_7187733473119293793[70] = 1;
   out_7187733473119293793[71] = 0;
   out_7187733473119293793[72] = 0;
   out_7187733473119293793[73] = 0;
   out_7187733473119293793[74] = 0;
   out_7187733473119293793[75] = 0;
   out_7187733473119293793[76] = 0;
   out_7187733473119293793[77] = 0;
   out_7187733473119293793[78] = 0;
   out_7187733473119293793[79] = 0;
   out_7187733473119293793[80] = 1;
}
void h_25(double *state, double *unused, double *out_6182079305000059618) {
   out_6182079305000059618[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5477287684314288312) {
   out_5477287684314288312[0] = 0;
   out_5477287684314288312[1] = 0;
   out_5477287684314288312[2] = 0;
   out_5477287684314288312[3] = 0;
   out_5477287684314288312[4] = 0;
   out_5477287684314288312[5] = 0;
   out_5477287684314288312[6] = 1;
   out_5477287684314288312[7] = 0;
   out_5477287684314288312[8] = 0;
}
void h_24(double *state, double *unused, double *out_8703248481960040622) {
   out_8703248481960040622[0] = state[4];
   out_8703248481960040622[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6393884582803745203) {
   out_6393884582803745203[0] = 0;
   out_6393884582803745203[1] = 0;
   out_6393884582803745203[2] = 0;
   out_6393884582803745203[3] = 0;
   out_6393884582803745203[4] = 1;
   out_6393884582803745203[5] = 0;
   out_6393884582803745203[6] = 0;
   out_6393884582803745203[7] = 0;
   out_6393884582803745203[8] = 0;
   out_6393884582803745203[9] = 0;
   out_6393884582803745203[10] = 0;
   out_6393884582803745203[11] = 0;
   out_6393884582803745203[12] = 0;
   out_6393884582803745203[13] = 0;
   out_6393884582803745203[14] = 1;
   out_6393884582803745203[15] = 0;
   out_6393884582803745203[16] = 0;
   out_6393884582803745203[17] = 0;
}
void h_30(double *state, double *unused, double *out_1581185951820612823) {
   out_1581185951820612823[0] = state[4];
}
void H_30(double *state, double *unused, double *out_6052766047903646549) {
   out_6052766047903646549[0] = 0;
   out_6052766047903646549[1] = 0;
   out_6052766047903646549[2] = 0;
   out_6052766047903646549[3] = 0;
   out_6052766047903646549[4] = 1;
   out_6052766047903646549[5] = 0;
   out_6052766047903646549[6] = 0;
   out_6052766047903646549[7] = 0;
   out_6052766047903646549[8] = 0;
}
void h_26(double *state, double *unused, double *out_9061678688093263158) {
   out_9061678688093263158[0] = state[7];
}
void H_26(double *state, double *unused, double *out_1735784365440232088) {
   out_1735784365440232088[0] = 0;
   out_1735784365440232088[1] = 0;
   out_1735784365440232088[2] = 0;
   out_1735784365440232088[3] = 0;
   out_1735784365440232088[4] = 0;
   out_1735784365440232088[5] = 0;
   out_1735784365440232088[6] = 0;
   out_1735784365440232088[7] = 1;
   out_1735784365440232088[8] = 0;
}
void h_27(double *state, double *unused, double *out_7262991501048646353) {
   out_7262991501048646353[0] = state[3];
}
void H_27(double *state, double *unused, double *out_8227529359704071460) {
   out_8227529359704071460[0] = 0;
   out_8227529359704071460[1] = 0;
   out_8227529359704071460[2] = 0;
   out_8227529359704071460[3] = 1;
   out_8227529359704071460[4] = 0;
   out_8227529359704071460[5] = 0;
   out_8227529359704071460[6] = 0;
   out_8227529359704071460[7] = 0;
   out_8227529359704071460[8] = 0;
}
void h_29(double *state, double *unused, double *out_3420487315840232822) {
   out_3420487315840232822[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5542534703589254365) {
   out_5542534703589254365[0] = 0;
   out_5542534703589254365[1] = 1;
   out_5542534703589254365[2] = 0;
   out_5542534703589254365[3] = 0;
   out_5542534703589254365[4] = 0;
   out_5542534703589254365[5] = 0;
   out_5542534703589254365[6] = 0;
   out_5542534703589254365[7] = 0;
   out_5542534703589254365[8] = 0;
}
void h_28(double *state, double *unused, double *out_2201783400654064498) {
   out_2201783400654064498[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7821810353050766677) {
   out_7821810353050766677[0] = 1;
   out_7821810353050766677[1] = 0;
   out_7821810353050766677[2] = 0;
   out_7821810353050766677[3] = 0;
   out_7821810353050766677[4] = 0;
   out_7821810353050766677[5] = 0;
   out_7821810353050766677[6] = 0;
   out_7821810353050766677[7] = 0;
   out_7821810353050766677[8] = 0;
}
void h_31(double *state, double *unused, double *out_5493829542359141062) {
   out_5493829542359141062[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5507933646191248740) {
   out_5507933646191248740[0] = 0;
   out_5507933646191248740[1] = 0;
   out_5507933646191248740[2] = 0;
   out_5507933646191248740[3] = 0;
   out_5507933646191248740[4] = 0;
   out_5507933646191248740[5] = 0;
   out_5507933646191248740[6] = 0;
   out_5507933646191248740[7] = 0;
   out_5507933646191248740[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_6981285947428203759) {
  err_fun(nom_x, delta_x, out_6981285947428203759);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3103352485653640338) {
  inv_err_fun(nom_x, true_x, out_3103352485653640338);
}
void car_H_mod_fun(double *state, double *out_7545812970075001068) {
  H_mod_fun(state, out_7545812970075001068);
}
void car_f_fun(double *state, double dt, double *out_7404244546590542183) {
  f_fun(state,  dt, out_7404244546590542183);
}
void car_F_fun(double *state, double dt, double *out_7187733473119293793) {
  F_fun(state,  dt, out_7187733473119293793);
}
void car_h_25(double *state, double *unused, double *out_6182079305000059618) {
  h_25(state, unused, out_6182079305000059618);
}
void car_H_25(double *state, double *unused, double *out_5477287684314288312) {
  H_25(state, unused, out_5477287684314288312);
}
void car_h_24(double *state, double *unused, double *out_8703248481960040622) {
  h_24(state, unused, out_8703248481960040622);
}
void car_H_24(double *state, double *unused, double *out_6393884582803745203) {
  H_24(state, unused, out_6393884582803745203);
}
void car_h_30(double *state, double *unused, double *out_1581185951820612823) {
  h_30(state, unused, out_1581185951820612823);
}
void car_H_30(double *state, double *unused, double *out_6052766047903646549) {
  H_30(state, unused, out_6052766047903646549);
}
void car_h_26(double *state, double *unused, double *out_9061678688093263158) {
  h_26(state, unused, out_9061678688093263158);
}
void car_H_26(double *state, double *unused, double *out_1735784365440232088) {
  H_26(state, unused, out_1735784365440232088);
}
void car_h_27(double *state, double *unused, double *out_7262991501048646353) {
  h_27(state, unused, out_7262991501048646353);
}
void car_H_27(double *state, double *unused, double *out_8227529359704071460) {
  H_27(state, unused, out_8227529359704071460);
}
void car_h_29(double *state, double *unused, double *out_3420487315840232822) {
  h_29(state, unused, out_3420487315840232822);
}
void car_H_29(double *state, double *unused, double *out_5542534703589254365) {
  H_29(state, unused, out_5542534703589254365);
}
void car_h_28(double *state, double *unused, double *out_2201783400654064498) {
  h_28(state, unused, out_2201783400654064498);
}
void car_H_28(double *state, double *unused, double *out_7821810353050766677) {
  H_28(state, unused, out_7821810353050766677);
}
void car_h_31(double *state, double *unused, double *out_5493829542359141062) {
  h_31(state, unused, out_5493829542359141062);
}
void car_H_31(double *state, double *unused, double *out_5507933646191248740) {
  H_31(state, unused, out_5507933646191248740);
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
