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
void err_fun(double *nom_x, double *delta_x, double *out_5155184678321054055) {
   out_5155184678321054055[0] = delta_x[0] + nom_x[0];
   out_5155184678321054055[1] = delta_x[1] + nom_x[1];
   out_5155184678321054055[2] = delta_x[2] + nom_x[2];
   out_5155184678321054055[3] = delta_x[3] + nom_x[3];
   out_5155184678321054055[4] = delta_x[4] + nom_x[4];
   out_5155184678321054055[5] = delta_x[5] + nom_x[5];
   out_5155184678321054055[6] = delta_x[6] + nom_x[6];
   out_5155184678321054055[7] = delta_x[7] + nom_x[7];
   out_5155184678321054055[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_260336739787886255) {
   out_260336739787886255[0] = -nom_x[0] + true_x[0];
   out_260336739787886255[1] = -nom_x[1] + true_x[1];
   out_260336739787886255[2] = -nom_x[2] + true_x[2];
   out_260336739787886255[3] = -nom_x[3] + true_x[3];
   out_260336739787886255[4] = -nom_x[4] + true_x[4];
   out_260336739787886255[5] = -nom_x[5] + true_x[5];
   out_260336739787886255[6] = -nom_x[6] + true_x[6];
   out_260336739787886255[7] = -nom_x[7] + true_x[7];
   out_260336739787886255[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_2599023291947582855) {
   out_2599023291947582855[0] = 1.0;
   out_2599023291947582855[1] = 0.0;
   out_2599023291947582855[2] = 0.0;
   out_2599023291947582855[3] = 0.0;
   out_2599023291947582855[4] = 0.0;
   out_2599023291947582855[5] = 0.0;
   out_2599023291947582855[6] = 0.0;
   out_2599023291947582855[7] = 0.0;
   out_2599023291947582855[8] = 0.0;
   out_2599023291947582855[9] = 0.0;
   out_2599023291947582855[10] = 1.0;
   out_2599023291947582855[11] = 0.0;
   out_2599023291947582855[12] = 0.0;
   out_2599023291947582855[13] = 0.0;
   out_2599023291947582855[14] = 0.0;
   out_2599023291947582855[15] = 0.0;
   out_2599023291947582855[16] = 0.0;
   out_2599023291947582855[17] = 0.0;
   out_2599023291947582855[18] = 0.0;
   out_2599023291947582855[19] = 0.0;
   out_2599023291947582855[20] = 1.0;
   out_2599023291947582855[21] = 0.0;
   out_2599023291947582855[22] = 0.0;
   out_2599023291947582855[23] = 0.0;
   out_2599023291947582855[24] = 0.0;
   out_2599023291947582855[25] = 0.0;
   out_2599023291947582855[26] = 0.0;
   out_2599023291947582855[27] = 0.0;
   out_2599023291947582855[28] = 0.0;
   out_2599023291947582855[29] = 0.0;
   out_2599023291947582855[30] = 1.0;
   out_2599023291947582855[31] = 0.0;
   out_2599023291947582855[32] = 0.0;
   out_2599023291947582855[33] = 0.0;
   out_2599023291947582855[34] = 0.0;
   out_2599023291947582855[35] = 0.0;
   out_2599023291947582855[36] = 0.0;
   out_2599023291947582855[37] = 0.0;
   out_2599023291947582855[38] = 0.0;
   out_2599023291947582855[39] = 0.0;
   out_2599023291947582855[40] = 1.0;
   out_2599023291947582855[41] = 0.0;
   out_2599023291947582855[42] = 0.0;
   out_2599023291947582855[43] = 0.0;
   out_2599023291947582855[44] = 0.0;
   out_2599023291947582855[45] = 0.0;
   out_2599023291947582855[46] = 0.0;
   out_2599023291947582855[47] = 0.0;
   out_2599023291947582855[48] = 0.0;
   out_2599023291947582855[49] = 0.0;
   out_2599023291947582855[50] = 1.0;
   out_2599023291947582855[51] = 0.0;
   out_2599023291947582855[52] = 0.0;
   out_2599023291947582855[53] = 0.0;
   out_2599023291947582855[54] = 0.0;
   out_2599023291947582855[55] = 0.0;
   out_2599023291947582855[56] = 0.0;
   out_2599023291947582855[57] = 0.0;
   out_2599023291947582855[58] = 0.0;
   out_2599023291947582855[59] = 0.0;
   out_2599023291947582855[60] = 1.0;
   out_2599023291947582855[61] = 0.0;
   out_2599023291947582855[62] = 0.0;
   out_2599023291947582855[63] = 0.0;
   out_2599023291947582855[64] = 0.0;
   out_2599023291947582855[65] = 0.0;
   out_2599023291947582855[66] = 0.0;
   out_2599023291947582855[67] = 0.0;
   out_2599023291947582855[68] = 0.0;
   out_2599023291947582855[69] = 0.0;
   out_2599023291947582855[70] = 1.0;
   out_2599023291947582855[71] = 0.0;
   out_2599023291947582855[72] = 0.0;
   out_2599023291947582855[73] = 0.0;
   out_2599023291947582855[74] = 0.0;
   out_2599023291947582855[75] = 0.0;
   out_2599023291947582855[76] = 0.0;
   out_2599023291947582855[77] = 0.0;
   out_2599023291947582855[78] = 0.0;
   out_2599023291947582855[79] = 0.0;
   out_2599023291947582855[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8697556517231450544) {
   out_8697556517231450544[0] = state[0];
   out_8697556517231450544[1] = state[1];
   out_8697556517231450544[2] = state[2];
   out_8697556517231450544[3] = state[3];
   out_8697556517231450544[4] = state[4];
   out_8697556517231450544[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8697556517231450544[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8697556517231450544[7] = state[7];
   out_8697556517231450544[8] = state[8];
}
void F_fun(double *state, double dt, double *out_808877034590597564) {
   out_808877034590597564[0] = 1;
   out_808877034590597564[1] = 0;
   out_808877034590597564[2] = 0;
   out_808877034590597564[3] = 0;
   out_808877034590597564[4] = 0;
   out_808877034590597564[5] = 0;
   out_808877034590597564[6] = 0;
   out_808877034590597564[7] = 0;
   out_808877034590597564[8] = 0;
   out_808877034590597564[9] = 0;
   out_808877034590597564[10] = 1;
   out_808877034590597564[11] = 0;
   out_808877034590597564[12] = 0;
   out_808877034590597564[13] = 0;
   out_808877034590597564[14] = 0;
   out_808877034590597564[15] = 0;
   out_808877034590597564[16] = 0;
   out_808877034590597564[17] = 0;
   out_808877034590597564[18] = 0;
   out_808877034590597564[19] = 0;
   out_808877034590597564[20] = 1;
   out_808877034590597564[21] = 0;
   out_808877034590597564[22] = 0;
   out_808877034590597564[23] = 0;
   out_808877034590597564[24] = 0;
   out_808877034590597564[25] = 0;
   out_808877034590597564[26] = 0;
   out_808877034590597564[27] = 0;
   out_808877034590597564[28] = 0;
   out_808877034590597564[29] = 0;
   out_808877034590597564[30] = 1;
   out_808877034590597564[31] = 0;
   out_808877034590597564[32] = 0;
   out_808877034590597564[33] = 0;
   out_808877034590597564[34] = 0;
   out_808877034590597564[35] = 0;
   out_808877034590597564[36] = 0;
   out_808877034590597564[37] = 0;
   out_808877034590597564[38] = 0;
   out_808877034590597564[39] = 0;
   out_808877034590597564[40] = 1;
   out_808877034590597564[41] = 0;
   out_808877034590597564[42] = 0;
   out_808877034590597564[43] = 0;
   out_808877034590597564[44] = 0;
   out_808877034590597564[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_808877034590597564[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_808877034590597564[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_808877034590597564[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_808877034590597564[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_808877034590597564[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_808877034590597564[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_808877034590597564[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_808877034590597564[53] = -9.8000000000000007*dt;
   out_808877034590597564[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_808877034590597564[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_808877034590597564[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_808877034590597564[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_808877034590597564[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_808877034590597564[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_808877034590597564[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_808877034590597564[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_808877034590597564[62] = 0;
   out_808877034590597564[63] = 0;
   out_808877034590597564[64] = 0;
   out_808877034590597564[65] = 0;
   out_808877034590597564[66] = 0;
   out_808877034590597564[67] = 0;
   out_808877034590597564[68] = 0;
   out_808877034590597564[69] = 0;
   out_808877034590597564[70] = 1;
   out_808877034590597564[71] = 0;
   out_808877034590597564[72] = 0;
   out_808877034590597564[73] = 0;
   out_808877034590597564[74] = 0;
   out_808877034590597564[75] = 0;
   out_808877034590597564[76] = 0;
   out_808877034590597564[77] = 0;
   out_808877034590597564[78] = 0;
   out_808877034590597564[79] = 0;
   out_808877034590597564[80] = 1;
}
void h_25(double *state, double *unused, double *out_5800912085437080381) {
   out_5800912085437080381[0] = state[6];
}
void H_25(double *state, double *unused, double *out_2304668533237081985) {
   out_2304668533237081985[0] = 0;
   out_2304668533237081985[1] = 0;
   out_2304668533237081985[2] = 0;
   out_2304668533237081985[3] = 0;
   out_2304668533237081985[4] = 0;
   out_2304668533237081985[5] = 0;
   out_2304668533237081985[6] = 1;
   out_2304668533237081985[7] = 0;
   out_2304668533237081985[8] = 0;
}
void h_24(double *state, double *unused, double *out_4070289765820226730) {
   out_4070289765820226730[0] = state[4];
   out_4070289765820226730[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8880240339828600086) {
   out_8880240339828600086[0] = 0;
   out_8880240339828600086[1] = 0;
   out_8880240339828600086[2] = 0;
   out_8880240339828600086[3] = 0;
   out_8880240339828600086[4] = 1;
   out_8880240339828600086[5] = 0;
   out_8880240339828600086[6] = 0;
   out_8880240339828600086[7] = 0;
   out_8880240339828600086[8] = 0;
   out_8880240339828600086[9] = 0;
   out_8880240339828600086[10] = 0;
   out_8880240339828600086[11] = 0;
   out_8880240339828600086[12] = 0;
   out_8880240339828600086[13] = 0;
   out_8880240339828600086[14] = 1;
   out_8880240339828600086[15] = 0;
   out_8880240339828600086[16] = 0;
   out_8880240339828600086[17] = 0;
}
void h_30(double *state, double *unused, double *out_1962353171383592060) {
   out_1962353171383592060[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4823001491744330612) {
   out_4823001491744330612[0] = 0;
   out_4823001491744330612[1] = 0;
   out_4823001491744330612[2] = 0;
   out_4823001491744330612[3] = 0;
   out_4823001491744330612[4] = 1;
   out_4823001491744330612[5] = 0;
   out_4823001491744330612[6] = 0;
   out_4823001491744330612[7] = 0;
   out_4823001491744330612[8] = 0;
}
void h_26(double *state, double *unused, double *out_4436688346030257086) {
   out_4436688346030257086[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5609194502997882586) {
   out_5609194502997882586[0] = 0;
   out_5609194502997882586[1] = 0;
   out_5609194502997882586[2] = 0;
   out_5609194502997882586[3] = 0;
   out_5609194502997882586[4] = 0;
   out_5609194502997882586[5] = 0;
   out_5609194502997882586[6] = 0;
   out_5609194502997882586[7] = 1;
   out_5609194502997882586[8] = 0;
}
void h_27(double *state, double *unused, double *out_3405291034744239686) {
   out_3405291034744239686[0] = state[3];
}
void H_27(double *state, double *unused, double *out_7046595562928273829) {
   out_7046595562928273829[0] = 0;
   out_7046595562928273829[1] = 0;
   out_7046595562928273829[2] = 0;
   out_7046595562928273829[3] = 1;
   out_7046595562928273829[4] = 0;
   out_7046595562928273829[5] = 0;
   out_7046595562928273829[6] = 0;
   out_7046595562928273829[7] = 0;
   out_7046595562928273829[8] = 0;
}
void h_29(double *state, double *unused, double *out_3039320096277253585) {
   out_3039320096277253585[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5333232836058722796) {
   out_5333232836058722796[0] = 0;
   out_5333232836058722796[1] = 1;
   out_5333232836058722796[2] = 0;
   out_5333232836058722796[3] = 0;
   out_5333232836058722796[4] = 0;
   out_5333232836058722796[5] = 0;
   out_5333232836058722796[6] = 0;
   out_5333232836058722796[7] = 0;
   out_5333232836058722796[8] = 0;
}
void h_28(double *state, double *unused, double *out_1820616181091085261) {
   out_1820616181091085261[0] = state[0];
}
void H_28(double *state, double *unused, double *out_250833818989192222) {
   out_250833818989192222[0] = 1;
   out_250833818989192222[1] = 0;
   out_250833818989192222[2] = 0;
   out_250833818989192222[3] = 0;
   out_250833818989192222[4] = 0;
   out_250833818989192222[5] = 0;
   out_250833818989192222[6] = 0;
   out_250833818989192222[7] = 0;
   out_250833818989192222[8] = 0;
}
void h_31(double *state, double *unused, double *out_786915841039214782) {
   out_786915841039214782[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2335314495114042413) {
   out_2335314495114042413[0] = 0;
   out_2335314495114042413[1] = 0;
   out_2335314495114042413[2] = 0;
   out_2335314495114042413[3] = 0;
   out_2335314495114042413[4] = 0;
   out_2335314495114042413[5] = 0;
   out_2335314495114042413[6] = 0;
   out_2335314495114042413[7] = 0;
   out_2335314495114042413[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_5155184678321054055) {
  err_fun(nom_x, delta_x, out_5155184678321054055);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_260336739787886255) {
  inv_err_fun(nom_x, true_x, out_260336739787886255);
}
void car_H_mod_fun(double *state, double *out_2599023291947582855) {
  H_mod_fun(state, out_2599023291947582855);
}
void car_f_fun(double *state, double dt, double *out_8697556517231450544) {
  f_fun(state,  dt, out_8697556517231450544);
}
void car_F_fun(double *state, double dt, double *out_808877034590597564) {
  F_fun(state,  dt, out_808877034590597564);
}
void car_h_25(double *state, double *unused, double *out_5800912085437080381) {
  h_25(state, unused, out_5800912085437080381);
}
void car_H_25(double *state, double *unused, double *out_2304668533237081985) {
  H_25(state, unused, out_2304668533237081985);
}
void car_h_24(double *state, double *unused, double *out_4070289765820226730) {
  h_24(state, unused, out_4070289765820226730);
}
void car_H_24(double *state, double *unused, double *out_8880240339828600086) {
  H_24(state, unused, out_8880240339828600086);
}
void car_h_30(double *state, double *unused, double *out_1962353171383592060) {
  h_30(state, unused, out_1962353171383592060);
}
void car_H_30(double *state, double *unused, double *out_4823001491744330612) {
  H_30(state, unused, out_4823001491744330612);
}
void car_h_26(double *state, double *unused, double *out_4436688346030257086) {
  h_26(state, unused, out_4436688346030257086);
}
void car_H_26(double *state, double *unused, double *out_5609194502997882586) {
  H_26(state, unused, out_5609194502997882586);
}
void car_h_27(double *state, double *unused, double *out_3405291034744239686) {
  h_27(state, unused, out_3405291034744239686);
}
void car_H_27(double *state, double *unused, double *out_7046595562928273829) {
  H_27(state, unused, out_7046595562928273829);
}
void car_h_29(double *state, double *unused, double *out_3039320096277253585) {
  h_29(state, unused, out_3039320096277253585);
}
void car_H_29(double *state, double *unused, double *out_5333232836058722796) {
  H_29(state, unused, out_5333232836058722796);
}
void car_h_28(double *state, double *unused, double *out_1820616181091085261) {
  h_28(state, unused, out_1820616181091085261);
}
void car_H_28(double *state, double *unused, double *out_250833818989192222) {
  H_28(state, unused, out_250833818989192222);
}
void car_h_31(double *state, double *unused, double *out_786915841039214782) {
  h_31(state, unused, out_786915841039214782);
}
void car_H_31(double *state, double *unused, double *out_2335314495114042413) {
  H_31(state, unused, out_2335314495114042413);
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
