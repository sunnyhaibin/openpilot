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
void err_fun(double *nom_x, double *delta_x, double *out_1140227036079585444) {
   out_1140227036079585444[0] = delta_x[0] + nom_x[0];
   out_1140227036079585444[1] = delta_x[1] + nom_x[1];
   out_1140227036079585444[2] = delta_x[2] + nom_x[2];
   out_1140227036079585444[3] = delta_x[3] + nom_x[3];
   out_1140227036079585444[4] = delta_x[4] + nom_x[4];
   out_1140227036079585444[5] = delta_x[5] + nom_x[5];
   out_1140227036079585444[6] = delta_x[6] + nom_x[6];
   out_1140227036079585444[7] = delta_x[7] + nom_x[7];
   out_1140227036079585444[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5212577056806210372) {
   out_5212577056806210372[0] = -nom_x[0] + true_x[0];
   out_5212577056806210372[1] = -nom_x[1] + true_x[1];
   out_5212577056806210372[2] = -nom_x[2] + true_x[2];
   out_5212577056806210372[3] = -nom_x[3] + true_x[3];
   out_5212577056806210372[4] = -nom_x[4] + true_x[4];
   out_5212577056806210372[5] = -nom_x[5] + true_x[5];
   out_5212577056806210372[6] = -nom_x[6] + true_x[6];
   out_5212577056806210372[7] = -nom_x[7] + true_x[7];
   out_5212577056806210372[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5162633318968107627) {
   out_5162633318968107627[0] = 1.0;
   out_5162633318968107627[1] = 0.0;
   out_5162633318968107627[2] = 0.0;
   out_5162633318968107627[3] = 0.0;
   out_5162633318968107627[4] = 0.0;
   out_5162633318968107627[5] = 0.0;
   out_5162633318968107627[6] = 0.0;
   out_5162633318968107627[7] = 0.0;
   out_5162633318968107627[8] = 0.0;
   out_5162633318968107627[9] = 0.0;
   out_5162633318968107627[10] = 1.0;
   out_5162633318968107627[11] = 0.0;
   out_5162633318968107627[12] = 0.0;
   out_5162633318968107627[13] = 0.0;
   out_5162633318968107627[14] = 0.0;
   out_5162633318968107627[15] = 0.0;
   out_5162633318968107627[16] = 0.0;
   out_5162633318968107627[17] = 0.0;
   out_5162633318968107627[18] = 0.0;
   out_5162633318968107627[19] = 0.0;
   out_5162633318968107627[20] = 1.0;
   out_5162633318968107627[21] = 0.0;
   out_5162633318968107627[22] = 0.0;
   out_5162633318968107627[23] = 0.0;
   out_5162633318968107627[24] = 0.0;
   out_5162633318968107627[25] = 0.0;
   out_5162633318968107627[26] = 0.0;
   out_5162633318968107627[27] = 0.0;
   out_5162633318968107627[28] = 0.0;
   out_5162633318968107627[29] = 0.0;
   out_5162633318968107627[30] = 1.0;
   out_5162633318968107627[31] = 0.0;
   out_5162633318968107627[32] = 0.0;
   out_5162633318968107627[33] = 0.0;
   out_5162633318968107627[34] = 0.0;
   out_5162633318968107627[35] = 0.0;
   out_5162633318968107627[36] = 0.0;
   out_5162633318968107627[37] = 0.0;
   out_5162633318968107627[38] = 0.0;
   out_5162633318968107627[39] = 0.0;
   out_5162633318968107627[40] = 1.0;
   out_5162633318968107627[41] = 0.0;
   out_5162633318968107627[42] = 0.0;
   out_5162633318968107627[43] = 0.0;
   out_5162633318968107627[44] = 0.0;
   out_5162633318968107627[45] = 0.0;
   out_5162633318968107627[46] = 0.0;
   out_5162633318968107627[47] = 0.0;
   out_5162633318968107627[48] = 0.0;
   out_5162633318968107627[49] = 0.0;
   out_5162633318968107627[50] = 1.0;
   out_5162633318968107627[51] = 0.0;
   out_5162633318968107627[52] = 0.0;
   out_5162633318968107627[53] = 0.0;
   out_5162633318968107627[54] = 0.0;
   out_5162633318968107627[55] = 0.0;
   out_5162633318968107627[56] = 0.0;
   out_5162633318968107627[57] = 0.0;
   out_5162633318968107627[58] = 0.0;
   out_5162633318968107627[59] = 0.0;
   out_5162633318968107627[60] = 1.0;
   out_5162633318968107627[61] = 0.0;
   out_5162633318968107627[62] = 0.0;
   out_5162633318968107627[63] = 0.0;
   out_5162633318968107627[64] = 0.0;
   out_5162633318968107627[65] = 0.0;
   out_5162633318968107627[66] = 0.0;
   out_5162633318968107627[67] = 0.0;
   out_5162633318968107627[68] = 0.0;
   out_5162633318968107627[69] = 0.0;
   out_5162633318968107627[70] = 1.0;
   out_5162633318968107627[71] = 0.0;
   out_5162633318968107627[72] = 0.0;
   out_5162633318968107627[73] = 0.0;
   out_5162633318968107627[74] = 0.0;
   out_5162633318968107627[75] = 0.0;
   out_5162633318968107627[76] = 0.0;
   out_5162633318968107627[77] = 0.0;
   out_5162633318968107627[78] = 0.0;
   out_5162633318968107627[79] = 0.0;
   out_5162633318968107627[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_6160854576209296037) {
   out_6160854576209296037[0] = state[0];
   out_6160854576209296037[1] = state[1];
   out_6160854576209296037[2] = state[2];
   out_6160854576209296037[3] = state[3];
   out_6160854576209296037[4] = state[4];
   out_6160854576209296037[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_6160854576209296037[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6160854576209296037[7] = state[7];
   out_6160854576209296037[8] = state[8];
}
void F_fun(double *state, double dt, double *out_939256608556051694) {
   out_939256608556051694[0] = 1;
   out_939256608556051694[1] = 0;
   out_939256608556051694[2] = 0;
   out_939256608556051694[3] = 0;
   out_939256608556051694[4] = 0;
   out_939256608556051694[5] = 0;
   out_939256608556051694[6] = 0;
   out_939256608556051694[7] = 0;
   out_939256608556051694[8] = 0;
   out_939256608556051694[9] = 0;
   out_939256608556051694[10] = 1;
   out_939256608556051694[11] = 0;
   out_939256608556051694[12] = 0;
   out_939256608556051694[13] = 0;
   out_939256608556051694[14] = 0;
   out_939256608556051694[15] = 0;
   out_939256608556051694[16] = 0;
   out_939256608556051694[17] = 0;
   out_939256608556051694[18] = 0;
   out_939256608556051694[19] = 0;
   out_939256608556051694[20] = 1;
   out_939256608556051694[21] = 0;
   out_939256608556051694[22] = 0;
   out_939256608556051694[23] = 0;
   out_939256608556051694[24] = 0;
   out_939256608556051694[25] = 0;
   out_939256608556051694[26] = 0;
   out_939256608556051694[27] = 0;
   out_939256608556051694[28] = 0;
   out_939256608556051694[29] = 0;
   out_939256608556051694[30] = 1;
   out_939256608556051694[31] = 0;
   out_939256608556051694[32] = 0;
   out_939256608556051694[33] = 0;
   out_939256608556051694[34] = 0;
   out_939256608556051694[35] = 0;
   out_939256608556051694[36] = 0;
   out_939256608556051694[37] = 0;
   out_939256608556051694[38] = 0;
   out_939256608556051694[39] = 0;
   out_939256608556051694[40] = 1;
   out_939256608556051694[41] = 0;
   out_939256608556051694[42] = 0;
   out_939256608556051694[43] = 0;
   out_939256608556051694[44] = 0;
   out_939256608556051694[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_939256608556051694[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_939256608556051694[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_939256608556051694[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_939256608556051694[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_939256608556051694[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_939256608556051694[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_939256608556051694[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_939256608556051694[53] = -9.8000000000000007*dt;
   out_939256608556051694[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_939256608556051694[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_939256608556051694[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_939256608556051694[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_939256608556051694[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_939256608556051694[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_939256608556051694[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_939256608556051694[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_939256608556051694[62] = 0;
   out_939256608556051694[63] = 0;
   out_939256608556051694[64] = 0;
   out_939256608556051694[65] = 0;
   out_939256608556051694[66] = 0;
   out_939256608556051694[67] = 0;
   out_939256608556051694[68] = 0;
   out_939256608556051694[69] = 0;
   out_939256608556051694[70] = 1;
   out_939256608556051694[71] = 0;
   out_939256608556051694[72] = 0;
   out_939256608556051694[73] = 0;
   out_939256608556051694[74] = 0;
   out_939256608556051694[75] = 0;
   out_939256608556051694[76] = 0;
   out_939256608556051694[77] = 0;
   out_939256608556051694[78] = 0;
   out_939256608556051694[79] = 0;
   out_939256608556051694[80] = 1;
}
void h_25(double *state, double *unused, double *out_1962884221865330862) {
   out_1962884221865330862[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1517062800868197284) {
   out_1517062800868197284[0] = 0;
   out_1517062800868197284[1] = 0;
   out_1517062800868197284[2] = 0;
   out_1517062800868197284[3] = 0;
   out_1517062800868197284[4] = 0;
   out_1517062800868197284[5] = 0;
   out_1517062800868197284[6] = 1;
   out_1517062800868197284[7] = 0;
   out_1517062800868197284[8] = 0;
}
void h_24(double *state, double *unused, double *out_8894343782379777004) {
   out_8894343782379777004[0] = state[4];
   out_8894343782379777004[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7701616086772159107) {
   out_7701616086772159107[0] = 0;
   out_7701616086772159107[1] = 0;
   out_7701616086772159107[2] = 0;
   out_7701616086772159107[3] = 0;
   out_7701616086772159107[4] = 1;
   out_7701616086772159107[5] = 0;
   out_7701616086772159107[6] = 0;
   out_7701616086772159107[7] = 0;
   out_7701616086772159107[8] = 0;
   out_7701616086772159107[9] = 0;
   out_7701616086772159107[10] = 0;
   out_7701616086772159107[11] = 0;
   out_7701616086772159107[12] = 0;
   out_7701616086772159107[13] = 0;
   out_7701616086772159107[14] = 1;
   out_7701616086772159107[15] = 0;
   out_7701616086772159107[16] = 0;
   out_7701616086772159107[17] = 0;
}
void h_30(double *state, double *unused, double *out_8602587201090171569) {
   out_8602587201090171569[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1387723853724957214) {
   out_1387723853724957214[0] = 0;
   out_1387723853724957214[1] = 0;
   out_1387723853724957214[2] = 0;
   out_1387723853724957214[3] = 0;
   out_1387723853724957214[4] = 1;
   out_1387723853724957214[5] = 0;
   out_1387723853724957214[6] = 0;
   out_1387723853724957214[7] = 0;
   out_1387723853724957214[8] = 0;
}
void h_26(double *state, double *unused, double *out_3640207203408878337) {
   out_3640207203408878337[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2224440518005858940) {
   out_2224440518005858940[0] = 0;
   out_2224440518005858940[1] = 0;
   out_2224440518005858940[2] = 0;
   out_2224440518005858940[3] = 0;
   out_2224440518005858940[4] = 0;
   out_2224440518005858940[5] = 0;
   out_2224440518005858940[6] = 0;
   out_2224440518005858940[7] = 1;
   out_2224440518005858940[8] = 0;
}
void h_27(double *state, double *unused, double *out_7188791437700655809) {
   out_7188791437700655809[0] = state[3];
}
void H_27(double *state, double *unused, double *out_787039458075467697) {
   out_787039458075467697[0] = 0;
   out_787039458075467697[1] = 0;
   out_787039458075467697[2] = 0;
   out_787039458075467697[3] = 1;
   out_787039458075467697[4] = 0;
   out_787039458075467697[5] = 0;
   out_787039458075467697[6] = 0;
   out_787039458075467697[7] = 0;
   out_787039458075467697[8] = 0;
}
void h_29(double *state, double *unused, double *out_7620503107754873457) {
   out_7620503107754873457[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2500402184945018730) {
   out_2500402184945018730[0] = 0;
   out_2500402184945018730[1] = 1;
   out_2500402184945018730[2] = 0;
   out_2500402184945018730[3] = 0;
   out_2500402184945018730[4] = 0;
   out_2500402184945018730[5] = 0;
   out_2500402184945018730[6] = 0;
   out_2500402184945018730[7] = 0;
   out_2500402184945018730[8] = 0;
}
void h_28(double *state, double *unused, double *out_6256279368348050162) {
   out_6256279368348050162[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7582801202014549304) {
   out_7582801202014549304[0] = 1;
   out_7582801202014549304[1] = 0;
   out_7582801202014549304[2] = 0;
   out_7582801202014549304[3] = 0;
   out_7582801202014549304[4] = 0;
   out_7582801202014549304[5] = 0;
   out_7582801202014549304[6] = 0;
   out_7582801202014549304[7] = 0;
   out_7582801202014549304[8] = 0;
}
void h_31(double *state, double *unused, double *out_8720594595023548313) {
   out_8720594595023548313[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1547708762745157712) {
   out_1547708762745157712[0] = 0;
   out_1547708762745157712[1] = 0;
   out_1547708762745157712[2] = 0;
   out_1547708762745157712[3] = 0;
   out_1547708762745157712[4] = 0;
   out_1547708762745157712[5] = 0;
   out_1547708762745157712[6] = 0;
   out_1547708762745157712[7] = 0;
   out_1547708762745157712[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_1140227036079585444) {
  err_fun(nom_x, delta_x, out_1140227036079585444);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5212577056806210372) {
  inv_err_fun(nom_x, true_x, out_5212577056806210372);
}
void car_H_mod_fun(double *state, double *out_5162633318968107627) {
  H_mod_fun(state, out_5162633318968107627);
}
void car_f_fun(double *state, double dt, double *out_6160854576209296037) {
  f_fun(state,  dt, out_6160854576209296037);
}
void car_F_fun(double *state, double dt, double *out_939256608556051694) {
  F_fun(state,  dt, out_939256608556051694);
}
void car_h_25(double *state, double *unused, double *out_1962884221865330862) {
  h_25(state, unused, out_1962884221865330862);
}
void car_H_25(double *state, double *unused, double *out_1517062800868197284) {
  H_25(state, unused, out_1517062800868197284);
}
void car_h_24(double *state, double *unused, double *out_8894343782379777004) {
  h_24(state, unused, out_8894343782379777004);
}
void car_H_24(double *state, double *unused, double *out_7701616086772159107) {
  H_24(state, unused, out_7701616086772159107);
}
void car_h_30(double *state, double *unused, double *out_8602587201090171569) {
  h_30(state, unused, out_8602587201090171569);
}
void car_H_30(double *state, double *unused, double *out_1387723853724957214) {
  H_30(state, unused, out_1387723853724957214);
}
void car_h_26(double *state, double *unused, double *out_3640207203408878337) {
  h_26(state, unused, out_3640207203408878337);
}
void car_H_26(double *state, double *unused, double *out_2224440518005858940) {
  H_26(state, unused, out_2224440518005858940);
}
void car_h_27(double *state, double *unused, double *out_7188791437700655809) {
  h_27(state, unused, out_7188791437700655809);
}
void car_H_27(double *state, double *unused, double *out_787039458075467697) {
  H_27(state, unused, out_787039458075467697);
}
void car_h_29(double *state, double *unused, double *out_7620503107754873457) {
  h_29(state, unused, out_7620503107754873457);
}
void car_H_29(double *state, double *unused, double *out_2500402184945018730) {
  H_29(state, unused, out_2500402184945018730);
}
void car_h_28(double *state, double *unused, double *out_6256279368348050162) {
  h_28(state, unused, out_6256279368348050162);
}
void car_H_28(double *state, double *unused, double *out_7582801202014549304) {
  H_28(state, unused, out_7582801202014549304);
}
void car_h_31(double *state, double *unused, double *out_8720594595023548313) {
  h_31(state, unused, out_8720594595023548313);
}
void car_H_31(double *state, double *unused, double *out_1547708762745157712) {
  H_31(state, unused, out_1547708762745157712);
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
