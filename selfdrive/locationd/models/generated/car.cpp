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
void err_fun(double *nom_x, double *delta_x, double *out_354464779286764365) {
   out_354464779286764365[0] = delta_x[0] + nom_x[0];
   out_354464779286764365[1] = delta_x[1] + nom_x[1];
   out_354464779286764365[2] = delta_x[2] + nom_x[2];
   out_354464779286764365[3] = delta_x[3] + nom_x[3];
   out_354464779286764365[4] = delta_x[4] + nom_x[4];
   out_354464779286764365[5] = delta_x[5] + nom_x[5];
   out_354464779286764365[6] = delta_x[6] + nom_x[6];
   out_354464779286764365[7] = delta_x[7] + nom_x[7];
   out_354464779286764365[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5129529406128162473) {
   out_5129529406128162473[0] = -nom_x[0] + true_x[0];
   out_5129529406128162473[1] = -nom_x[1] + true_x[1];
   out_5129529406128162473[2] = -nom_x[2] + true_x[2];
   out_5129529406128162473[3] = -nom_x[3] + true_x[3];
   out_5129529406128162473[4] = -nom_x[4] + true_x[4];
   out_5129529406128162473[5] = -nom_x[5] + true_x[5];
   out_5129529406128162473[6] = -nom_x[6] + true_x[6];
   out_5129529406128162473[7] = -nom_x[7] + true_x[7];
   out_5129529406128162473[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5015646059088940531) {
   out_5015646059088940531[0] = 1.0;
   out_5015646059088940531[1] = 0.0;
   out_5015646059088940531[2] = 0.0;
   out_5015646059088940531[3] = 0.0;
   out_5015646059088940531[4] = 0.0;
   out_5015646059088940531[5] = 0.0;
   out_5015646059088940531[6] = 0.0;
   out_5015646059088940531[7] = 0.0;
   out_5015646059088940531[8] = 0.0;
   out_5015646059088940531[9] = 0.0;
   out_5015646059088940531[10] = 1.0;
   out_5015646059088940531[11] = 0.0;
   out_5015646059088940531[12] = 0.0;
   out_5015646059088940531[13] = 0.0;
   out_5015646059088940531[14] = 0.0;
   out_5015646059088940531[15] = 0.0;
   out_5015646059088940531[16] = 0.0;
   out_5015646059088940531[17] = 0.0;
   out_5015646059088940531[18] = 0.0;
   out_5015646059088940531[19] = 0.0;
   out_5015646059088940531[20] = 1.0;
   out_5015646059088940531[21] = 0.0;
   out_5015646059088940531[22] = 0.0;
   out_5015646059088940531[23] = 0.0;
   out_5015646059088940531[24] = 0.0;
   out_5015646059088940531[25] = 0.0;
   out_5015646059088940531[26] = 0.0;
   out_5015646059088940531[27] = 0.0;
   out_5015646059088940531[28] = 0.0;
   out_5015646059088940531[29] = 0.0;
   out_5015646059088940531[30] = 1.0;
   out_5015646059088940531[31] = 0.0;
   out_5015646059088940531[32] = 0.0;
   out_5015646059088940531[33] = 0.0;
   out_5015646059088940531[34] = 0.0;
   out_5015646059088940531[35] = 0.0;
   out_5015646059088940531[36] = 0.0;
   out_5015646059088940531[37] = 0.0;
   out_5015646059088940531[38] = 0.0;
   out_5015646059088940531[39] = 0.0;
   out_5015646059088940531[40] = 1.0;
   out_5015646059088940531[41] = 0.0;
   out_5015646059088940531[42] = 0.0;
   out_5015646059088940531[43] = 0.0;
   out_5015646059088940531[44] = 0.0;
   out_5015646059088940531[45] = 0.0;
   out_5015646059088940531[46] = 0.0;
   out_5015646059088940531[47] = 0.0;
   out_5015646059088940531[48] = 0.0;
   out_5015646059088940531[49] = 0.0;
   out_5015646059088940531[50] = 1.0;
   out_5015646059088940531[51] = 0.0;
   out_5015646059088940531[52] = 0.0;
   out_5015646059088940531[53] = 0.0;
   out_5015646059088940531[54] = 0.0;
   out_5015646059088940531[55] = 0.0;
   out_5015646059088940531[56] = 0.0;
   out_5015646059088940531[57] = 0.0;
   out_5015646059088940531[58] = 0.0;
   out_5015646059088940531[59] = 0.0;
   out_5015646059088940531[60] = 1.0;
   out_5015646059088940531[61] = 0.0;
   out_5015646059088940531[62] = 0.0;
   out_5015646059088940531[63] = 0.0;
   out_5015646059088940531[64] = 0.0;
   out_5015646059088940531[65] = 0.0;
   out_5015646059088940531[66] = 0.0;
   out_5015646059088940531[67] = 0.0;
   out_5015646059088940531[68] = 0.0;
   out_5015646059088940531[69] = 0.0;
   out_5015646059088940531[70] = 1.0;
   out_5015646059088940531[71] = 0.0;
   out_5015646059088940531[72] = 0.0;
   out_5015646059088940531[73] = 0.0;
   out_5015646059088940531[74] = 0.0;
   out_5015646059088940531[75] = 0.0;
   out_5015646059088940531[76] = 0.0;
   out_5015646059088940531[77] = 0.0;
   out_5015646059088940531[78] = 0.0;
   out_5015646059088940531[79] = 0.0;
   out_5015646059088940531[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1996750297433401186) {
   out_1996750297433401186[0] = state[0];
   out_1996750297433401186[1] = state[1];
   out_1996750297433401186[2] = state[2];
   out_1996750297433401186[3] = state[3];
   out_1996750297433401186[4] = state[4];
   out_1996750297433401186[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1996750297433401186[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1996750297433401186[7] = state[7];
   out_1996750297433401186[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7116257316432458665) {
   out_7116257316432458665[0] = 1;
   out_7116257316432458665[1] = 0;
   out_7116257316432458665[2] = 0;
   out_7116257316432458665[3] = 0;
   out_7116257316432458665[4] = 0;
   out_7116257316432458665[5] = 0;
   out_7116257316432458665[6] = 0;
   out_7116257316432458665[7] = 0;
   out_7116257316432458665[8] = 0;
   out_7116257316432458665[9] = 0;
   out_7116257316432458665[10] = 1;
   out_7116257316432458665[11] = 0;
   out_7116257316432458665[12] = 0;
   out_7116257316432458665[13] = 0;
   out_7116257316432458665[14] = 0;
   out_7116257316432458665[15] = 0;
   out_7116257316432458665[16] = 0;
   out_7116257316432458665[17] = 0;
   out_7116257316432458665[18] = 0;
   out_7116257316432458665[19] = 0;
   out_7116257316432458665[20] = 1;
   out_7116257316432458665[21] = 0;
   out_7116257316432458665[22] = 0;
   out_7116257316432458665[23] = 0;
   out_7116257316432458665[24] = 0;
   out_7116257316432458665[25] = 0;
   out_7116257316432458665[26] = 0;
   out_7116257316432458665[27] = 0;
   out_7116257316432458665[28] = 0;
   out_7116257316432458665[29] = 0;
   out_7116257316432458665[30] = 1;
   out_7116257316432458665[31] = 0;
   out_7116257316432458665[32] = 0;
   out_7116257316432458665[33] = 0;
   out_7116257316432458665[34] = 0;
   out_7116257316432458665[35] = 0;
   out_7116257316432458665[36] = 0;
   out_7116257316432458665[37] = 0;
   out_7116257316432458665[38] = 0;
   out_7116257316432458665[39] = 0;
   out_7116257316432458665[40] = 1;
   out_7116257316432458665[41] = 0;
   out_7116257316432458665[42] = 0;
   out_7116257316432458665[43] = 0;
   out_7116257316432458665[44] = 0;
   out_7116257316432458665[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7116257316432458665[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7116257316432458665[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7116257316432458665[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7116257316432458665[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7116257316432458665[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7116257316432458665[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7116257316432458665[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7116257316432458665[53] = -9.8000000000000007*dt;
   out_7116257316432458665[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7116257316432458665[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7116257316432458665[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7116257316432458665[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7116257316432458665[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7116257316432458665[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7116257316432458665[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7116257316432458665[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7116257316432458665[62] = 0;
   out_7116257316432458665[63] = 0;
   out_7116257316432458665[64] = 0;
   out_7116257316432458665[65] = 0;
   out_7116257316432458665[66] = 0;
   out_7116257316432458665[67] = 0;
   out_7116257316432458665[68] = 0;
   out_7116257316432458665[69] = 0;
   out_7116257316432458665[70] = 1;
   out_7116257316432458665[71] = 0;
   out_7116257316432458665[72] = 0;
   out_7116257316432458665[73] = 0;
   out_7116257316432458665[74] = 0;
   out_7116257316432458665[75] = 0;
   out_7116257316432458665[76] = 0;
   out_7116257316432458665[77] = 0;
   out_7116257316432458665[78] = 0;
   out_7116257316432458665[79] = 0;
   out_7116257316432458665[80] = 1;
}
void h_25(double *state, double *unused, double *out_6950824494898730012) {
   out_6950824494898730012[0] = state[6];
}
void H_25(double *state, double *unused, double *out_111954233904275691) {
   out_111954233904275691[0] = 0;
   out_111954233904275691[1] = 0;
   out_111954233904275691[2] = 0;
   out_111954233904275691[3] = 0;
   out_111954233904275691[4] = 0;
   out_111954233904275691[5] = 0;
   out_111954233904275691[6] = 1;
   out_111954233904275691[7] = 0;
   out_111954233904275691[8] = 0;
}
void h_24(double *state, double *unused, double *out_7242744353424038527) {
   out_7242744353424038527[0] = state[4];
   out_7242744353424038527[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6463617572687242410) {
   out_6463617572687242410[0] = 0;
   out_6463617572687242410[1] = 0;
   out_6463617572687242410[2] = 0;
   out_6463617572687242410[3] = 0;
   out_6463617572687242410[4] = 1;
   out_6463617572687242410[5] = 0;
   out_6463617572687242410[6] = 0;
   out_6463617572687242410[7] = 0;
   out_6463617572687242410[8] = 0;
   out_6463617572687242410[9] = 0;
   out_6463617572687242410[10] = 0;
   out_6463617572687242410[11] = 0;
   out_6463617572687242410[12] = 0;
   out_6463617572687242410[13] = 0;
   out_6463617572687242410[14] = 1;
   out_6463617572687242410[15] = 0;
   out_6463617572687242410[16] = 0;
   out_6463617572687242410[17] = 0;
}
void h_30(double *state, double *unused, double *out_3313374966644707662) {
   out_3313374966644707662[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2406378724602972936) {
   out_2406378724602972936[0] = 0;
   out_2406378724602972936[1] = 0;
   out_2406378724602972936[2] = 0;
   out_2406378724602972936[3] = 0;
   out_2406378724602972936[4] = 1;
   out_2406378724602972936[5] = 0;
   out_2406378724602972936[6] = 0;
   out_2406378724602972936[7] = 0;
   out_2406378724602972936[8] = 0;
}
void h_26(double *state, double *unused, double *out_276588915200374977) {
   out_276588915200374977[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3853457552778331915) {
   out_3853457552778331915[0] = 0;
   out_3853457552778331915[1] = 0;
   out_3853457552778331915[2] = 0;
   out_3853457552778331915[3] = 0;
   out_3853457552778331915[4] = 0;
   out_3853457552778331915[5] = 0;
   out_3853457552778331915[6] = 0;
   out_3853457552778331915[7] = 1;
   out_3853457552778331915[8] = 0;
}
void h_27(double *state, double *unused, double *out_7894334347800392447) {
   out_7894334347800392447[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4629972795786916153) {
   out_4629972795786916153[0] = 0;
   out_4629972795786916153[1] = 0;
   out_4629972795786916153[2] = 0;
   out_4629972795786916153[3] = 1;
   out_4629972795786916153[4] = 0;
   out_4629972795786916153[5] = 0;
   out_4629972795786916153[6] = 0;
   out_4629972795786916153[7] = 0;
   out_4629972795786916153[8] = 0;
}
void h_29(double *state, double *unused, double *out_1912532249190617285) {
   out_1912532249190617285[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2916610068917365120) {
   out_2916610068917365120[0] = 0;
   out_2916610068917365120[1] = 1;
   out_2916610068917365120[2] = 0;
   out_2916610068917365120[3] = 0;
   out_2916610068917365120[4] = 0;
   out_2916610068917365120[5] = 0;
   out_2916610068917365120[6] = 0;
   out_2916610068917365120[7] = 0;
   out_2916610068917365120[8] = 0;
}
void h_28(double *state, double *unused, double *out_7515623674464826484) {
   out_7515623674464826484[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2165788948152165454) {
   out_2165788948152165454[0] = 1;
   out_2165788948152165454[1] = 0;
   out_2165788948152165454[2] = 0;
   out_2165788948152165454[3] = 0;
   out_2165788948152165454[4] = 0;
   out_2165788948152165454[5] = 0;
   out_2165788948152165454[6] = 0;
   out_2165788948152165454[7] = 0;
   out_2165788948152165454[8] = 0;
}
void h_31(double *state, double *unused, double *out_7226018557183235901) {
   out_7226018557183235901[0] = state[8];
}
void H_31(double *state, double *unused, double *out_81308272027315263) {
   out_81308272027315263[0] = 0;
   out_81308272027315263[1] = 0;
   out_81308272027315263[2] = 0;
   out_81308272027315263[3] = 0;
   out_81308272027315263[4] = 0;
   out_81308272027315263[5] = 0;
   out_81308272027315263[6] = 0;
   out_81308272027315263[7] = 0;
   out_81308272027315263[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_354464779286764365) {
  err_fun(nom_x, delta_x, out_354464779286764365);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5129529406128162473) {
  inv_err_fun(nom_x, true_x, out_5129529406128162473);
}
void car_H_mod_fun(double *state, double *out_5015646059088940531) {
  H_mod_fun(state, out_5015646059088940531);
}
void car_f_fun(double *state, double dt, double *out_1996750297433401186) {
  f_fun(state,  dt, out_1996750297433401186);
}
void car_F_fun(double *state, double dt, double *out_7116257316432458665) {
  F_fun(state,  dt, out_7116257316432458665);
}
void car_h_25(double *state, double *unused, double *out_6950824494898730012) {
  h_25(state, unused, out_6950824494898730012);
}
void car_H_25(double *state, double *unused, double *out_111954233904275691) {
  H_25(state, unused, out_111954233904275691);
}
void car_h_24(double *state, double *unused, double *out_7242744353424038527) {
  h_24(state, unused, out_7242744353424038527);
}
void car_H_24(double *state, double *unused, double *out_6463617572687242410) {
  H_24(state, unused, out_6463617572687242410);
}
void car_h_30(double *state, double *unused, double *out_3313374966644707662) {
  h_30(state, unused, out_3313374966644707662);
}
void car_H_30(double *state, double *unused, double *out_2406378724602972936) {
  H_30(state, unused, out_2406378724602972936);
}
void car_h_26(double *state, double *unused, double *out_276588915200374977) {
  h_26(state, unused, out_276588915200374977);
}
void car_H_26(double *state, double *unused, double *out_3853457552778331915) {
  H_26(state, unused, out_3853457552778331915);
}
void car_h_27(double *state, double *unused, double *out_7894334347800392447) {
  h_27(state, unused, out_7894334347800392447);
}
void car_H_27(double *state, double *unused, double *out_4629972795786916153) {
  H_27(state, unused, out_4629972795786916153);
}
void car_h_29(double *state, double *unused, double *out_1912532249190617285) {
  h_29(state, unused, out_1912532249190617285);
}
void car_H_29(double *state, double *unused, double *out_2916610068917365120) {
  H_29(state, unused, out_2916610068917365120);
}
void car_h_28(double *state, double *unused, double *out_7515623674464826484) {
  h_28(state, unused, out_7515623674464826484);
}
void car_H_28(double *state, double *unused, double *out_2165788948152165454) {
  H_28(state, unused, out_2165788948152165454);
}
void car_h_31(double *state, double *unused, double *out_7226018557183235901) {
  h_31(state, unused, out_7226018557183235901);
}
void car_H_31(double *state, double *unused, double *out_81308272027315263) {
  H_31(state, unused, out_81308272027315263);
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
