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
void err_fun(double *nom_x, double *delta_x, double *out_3729180171091771888) {
   out_3729180171091771888[0] = delta_x[0] + nom_x[0];
   out_3729180171091771888[1] = delta_x[1] + nom_x[1];
   out_3729180171091771888[2] = delta_x[2] + nom_x[2];
   out_3729180171091771888[3] = delta_x[3] + nom_x[3];
   out_3729180171091771888[4] = delta_x[4] + nom_x[4];
   out_3729180171091771888[5] = delta_x[5] + nom_x[5];
   out_3729180171091771888[6] = delta_x[6] + nom_x[6];
   out_3729180171091771888[7] = delta_x[7] + nom_x[7];
   out_3729180171091771888[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6964334479301239449) {
   out_6964334479301239449[0] = -nom_x[0] + true_x[0];
   out_6964334479301239449[1] = -nom_x[1] + true_x[1];
   out_6964334479301239449[2] = -nom_x[2] + true_x[2];
   out_6964334479301239449[3] = -nom_x[3] + true_x[3];
   out_6964334479301239449[4] = -nom_x[4] + true_x[4];
   out_6964334479301239449[5] = -nom_x[5] + true_x[5];
   out_6964334479301239449[6] = -nom_x[6] + true_x[6];
   out_6964334479301239449[7] = -nom_x[7] + true_x[7];
   out_6964334479301239449[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6971916085428182136) {
   out_6971916085428182136[0] = 1.0;
   out_6971916085428182136[1] = 0.0;
   out_6971916085428182136[2] = 0.0;
   out_6971916085428182136[3] = 0.0;
   out_6971916085428182136[4] = 0.0;
   out_6971916085428182136[5] = 0.0;
   out_6971916085428182136[6] = 0.0;
   out_6971916085428182136[7] = 0.0;
   out_6971916085428182136[8] = 0.0;
   out_6971916085428182136[9] = 0.0;
   out_6971916085428182136[10] = 1.0;
   out_6971916085428182136[11] = 0.0;
   out_6971916085428182136[12] = 0.0;
   out_6971916085428182136[13] = 0.0;
   out_6971916085428182136[14] = 0.0;
   out_6971916085428182136[15] = 0.0;
   out_6971916085428182136[16] = 0.0;
   out_6971916085428182136[17] = 0.0;
   out_6971916085428182136[18] = 0.0;
   out_6971916085428182136[19] = 0.0;
   out_6971916085428182136[20] = 1.0;
   out_6971916085428182136[21] = 0.0;
   out_6971916085428182136[22] = 0.0;
   out_6971916085428182136[23] = 0.0;
   out_6971916085428182136[24] = 0.0;
   out_6971916085428182136[25] = 0.0;
   out_6971916085428182136[26] = 0.0;
   out_6971916085428182136[27] = 0.0;
   out_6971916085428182136[28] = 0.0;
   out_6971916085428182136[29] = 0.0;
   out_6971916085428182136[30] = 1.0;
   out_6971916085428182136[31] = 0.0;
   out_6971916085428182136[32] = 0.0;
   out_6971916085428182136[33] = 0.0;
   out_6971916085428182136[34] = 0.0;
   out_6971916085428182136[35] = 0.0;
   out_6971916085428182136[36] = 0.0;
   out_6971916085428182136[37] = 0.0;
   out_6971916085428182136[38] = 0.0;
   out_6971916085428182136[39] = 0.0;
   out_6971916085428182136[40] = 1.0;
   out_6971916085428182136[41] = 0.0;
   out_6971916085428182136[42] = 0.0;
   out_6971916085428182136[43] = 0.0;
   out_6971916085428182136[44] = 0.0;
   out_6971916085428182136[45] = 0.0;
   out_6971916085428182136[46] = 0.0;
   out_6971916085428182136[47] = 0.0;
   out_6971916085428182136[48] = 0.0;
   out_6971916085428182136[49] = 0.0;
   out_6971916085428182136[50] = 1.0;
   out_6971916085428182136[51] = 0.0;
   out_6971916085428182136[52] = 0.0;
   out_6971916085428182136[53] = 0.0;
   out_6971916085428182136[54] = 0.0;
   out_6971916085428182136[55] = 0.0;
   out_6971916085428182136[56] = 0.0;
   out_6971916085428182136[57] = 0.0;
   out_6971916085428182136[58] = 0.0;
   out_6971916085428182136[59] = 0.0;
   out_6971916085428182136[60] = 1.0;
   out_6971916085428182136[61] = 0.0;
   out_6971916085428182136[62] = 0.0;
   out_6971916085428182136[63] = 0.0;
   out_6971916085428182136[64] = 0.0;
   out_6971916085428182136[65] = 0.0;
   out_6971916085428182136[66] = 0.0;
   out_6971916085428182136[67] = 0.0;
   out_6971916085428182136[68] = 0.0;
   out_6971916085428182136[69] = 0.0;
   out_6971916085428182136[70] = 1.0;
   out_6971916085428182136[71] = 0.0;
   out_6971916085428182136[72] = 0.0;
   out_6971916085428182136[73] = 0.0;
   out_6971916085428182136[74] = 0.0;
   out_6971916085428182136[75] = 0.0;
   out_6971916085428182136[76] = 0.0;
   out_6971916085428182136[77] = 0.0;
   out_6971916085428182136[78] = 0.0;
   out_6971916085428182136[79] = 0.0;
   out_6971916085428182136[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_6948150360176626138) {
   out_6948150360176626138[0] = state[0];
   out_6948150360176626138[1] = state[1];
   out_6948150360176626138[2] = state[2];
   out_6948150360176626138[3] = state[3];
   out_6948150360176626138[4] = state[4];
   out_6948150360176626138[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_6948150360176626138[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6948150360176626138[7] = state[7];
   out_6948150360176626138[8] = state[8];
}
void F_fun(double *state, double dt, double *out_4619557020690583171) {
   out_4619557020690583171[0] = 1;
   out_4619557020690583171[1] = 0;
   out_4619557020690583171[2] = 0;
   out_4619557020690583171[3] = 0;
   out_4619557020690583171[4] = 0;
   out_4619557020690583171[5] = 0;
   out_4619557020690583171[6] = 0;
   out_4619557020690583171[7] = 0;
   out_4619557020690583171[8] = 0;
   out_4619557020690583171[9] = 0;
   out_4619557020690583171[10] = 1;
   out_4619557020690583171[11] = 0;
   out_4619557020690583171[12] = 0;
   out_4619557020690583171[13] = 0;
   out_4619557020690583171[14] = 0;
   out_4619557020690583171[15] = 0;
   out_4619557020690583171[16] = 0;
   out_4619557020690583171[17] = 0;
   out_4619557020690583171[18] = 0;
   out_4619557020690583171[19] = 0;
   out_4619557020690583171[20] = 1;
   out_4619557020690583171[21] = 0;
   out_4619557020690583171[22] = 0;
   out_4619557020690583171[23] = 0;
   out_4619557020690583171[24] = 0;
   out_4619557020690583171[25] = 0;
   out_4619557020690583171[26] = 0;
   out_4619557020690583171[27] = 0;
   out_4619557020690583171[28] = 0;
   out_4619557020690583171[29] = 0;
   out_4619557020690583171[30] = 1;
   out_4619557020690583171[31] = 0;
   out_4619557020690583171[32] = 0;
   out_4619557020690583171[33] = 0;
   out_4619557020690583171[34] = 0;
   out_4619557020690583171[35] = 0;
   out_4619557020690583171[36] = 0;
   out_4619557020690583171[37] = 0;
   out_4619557020690583171[38] = 0;
   out_4619557020690583171[39] = 0;
   out_4619557020690583171[40] = 1;
   out_4619557020690583171[41] = 0;
   out_4619557020690583171[42] = 0;
   out_4619557020690583171[43] = 0;
   out_4619557020690583171[44] = 0;
   out_4619557020690583171[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_4619557020690583171[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_4619557020690583171[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4619557020690583171[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4619557020690583171[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_4619557020690583171[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_4619557020690583171[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_4619557020690583171[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_4619557020690583171[53] = -9.8000000000000007*dt;
   out_4619557020690583171[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_4619557020690583171[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_4619557020690583171[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4619557020690583171[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4619557020690583171[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_4619557020690583171[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_4619557020690583171[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_4619557020690583171[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4619557020690583171[62] = 0;
   out_4619557020690583171[63] = 0;
   out_4619557020690583171[64] = 0;
   out_4619557020690583171[65] = 0;
   out_4619557020690583171[66] = 0;
   out_4619557020690583171[67] = 0;
   out_4619557020690583171[68] = 0;
   out_4619557020690583171[69] = 0;
   out_4619557020690583171[70] = 1;
   out_4619557020690583171[71] = 0;
   out_4619557020690583171[72] = 0;
   out_4619557020690583171[73] = 0;
   out_4619557020690583171[74] = 0;
   out_4619557020690583171[75] = 0;
   out_4619557020690583171[76] = 0;
   out_4619557020690583171[77] = 0;
   out_4619557020690583171[78] = 0;
   out_4619557020690583171[79] = 0;
   out_4619557020690583171[80] = 1;
}
void h_25(double *state, double *unused, double *out_8479108228489595249) {
   out_8479108228489595249[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7951779349636004332) {
   out_7951779349636004332[0] = 0;
   out_7951779349636004332[1] = 0;
   out_7951779349636004332[2] = 0;
   out_7951779349636004332[3] = 0;
   out_7951779349636004332[4] = 0;
   out_7951779349636004332[5] = 0;
   out_7951779349636004332[6] = 1;
   out_7951779349636004332[7] = 0;
   out_7951779349636004332[8] = 0;
}
void h_24(double *state, double *unused, double *out_3909636304809658351) {
   out_3909636304809658351[0] = state[4];
   out_3909636304809658351[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6937039125271224148) {
   out_6937039125271224148[0] = 0;
   out_6937039125271224148[1] = 0;
   out_6937039125271224148[2] = 0;
   out_6937039125271224148[3] = 0;
   out_6937039125271224148[4] = 1;
   out_6937039125271224148[5] = 0;
   out_6937039125271224148[6] = 0;
   out_6937039125271224148[7] = 0;
   out_6937039125271224148[8] = 0;
   out_6937039125271224148[9] = 0;
   out_6937039125271224148[10] = 0;
   out_6937039125271224148[11] = 0;
   out_6937039125271224148[12] = 0;
   out_6937039125271224148[13] = 0;
   out_6937039125271224148[14] = 1;
   out_6937039125271224148[15] = 0;
   out_6937039125271224148[16] = 0;
   out_6937039125271224148[17] = 0;
}
void h_30(double *state, double *unused, double *out_4380804930210223385) {
   out_4380804930210223385[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7976631765566298657) {
   out_7976631765566298657[0] = 0;
   out_7976631765566298657[1] = 0;
   out_7976631765566298657[2] = 0;
   out_7976631765566298657[3] = 0;
   out_7976631765566298657[4] = 1;
   out_7976631765566298657[5] = 0;
   out_7976631765566298657[6] = 0;
   out_7976631765566298657[7] = 0;
   out_7976631765566298657[8] = 0;
}
void h_26(double *state, double *unused, double *out_4415504534055773755) {
   out_4415504534055773755[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4210276030761948108) {
   out_4210276030761948108[0] = 0;
   out_4210276030761948108[1] = 0;
   out_4210276030761948108[2] = 0;
   out_4210276030761948108[3] = 0;
   out_4210276030761948108[4] = 0;
   out_4210276030761948108[5] = 0;
   out_4210276030761948108[6] = 0;
   out_4210276030761948108[7] = 1;
   out_4210276030761948108[8] = 0;
}
void h_27(double *state, double *unused, double *out_1379473163415114959) {
   out_1379473163415114959[0] = state[3];
}
void H_27(double *state, double *unused, double *out_5753037694382355440) {
   out_5753037694382355440[0] = 0;
   out_5753037694382355440[1] = 0;
   out_5753037694382355440[2] = 0;
   out_5753037694382355440[3] = 1;
   out_5753037694382355440[4] = 0;
   out_5753037694382355440[5] = 0;
   out_5753037694382355440[6] = 0;
   out_5753037694382355440[7] = 0;
   out_5753037694382355440[8] = 0;
}
void h_29(double *state, double *unused, double *out_1104279101130609070) {
   out_1104279101130609070[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7466400421251906473) {
   out_7466400421251906473[0] = 0;
   out_7466400421251906473[1] = 1;
   out_7466400421251906473[2] = 0;
   out_7466400421251906473[3] = 0;
   out_7466400421251906473[4] = 0;
   out_7466400421251906473[5] = 0;
   out_7466400421251906473[6] = 0;
   out_7466400421251906473[7] = 0;
   out_7466400421251906473[8] = 0;
}
void h_28(double *state, double *unused, double *out_4498812324143600129) {
   out_4498812324143600129[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5897944635388114569) {
   out_5897944635388114569[0] = 1;
   out_5897944635388114569[1] = 0;
   out_5897944635388114569[2] = 0;
   out_5897944635388114569[3] = 0;
   out_5897944635388114569[4] = 0;
   out_5897944635388114569[5] = 0;
   out_5897944635388114569[6] = 0;
   out_5897944635388114569[7] = 0;
   out_5897944635388114569[8] = 0;
}
void h_31(double *state, double *unused, double *out_8203914166205089360) {
   out_8203914166205089360[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7982425311512964760) {
   out_7982425311512964760[0] = 0;
   out_7982425311512964760[1] = 0;
   out_7982425311512964760[2] = 0;
   out_7982425311512964760[3] = 0;
   out_7982425311512964760[4] = 0;
   out_7982425311512964760[5] = 0;
   out_7982425311512964760[6] = 0;
   out_7982425311512964760[7] = 0;
   out_7982425311512964760[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3729180171091771888) {
  err_fun(nom_x, delta_x, out_3729180171091771888);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6964334479301239449) {
  inv_err_fun(nom_x, true_x, out_6964334479301239449);
}
void car_H_mod_fun(double *state, double *out_6971916085428182136) {
  H_mod_fun(state, out_6971916085428182136);
}
void car_f_fun(double *state, double dt, double *out_6948150360176626138) {
  f_fun(state,  dt, out_6948150360176626138);
}
void car_F_fun(double *state, double dt, double *out_4619557020690583171) {
  F_fun(state,  dt, out_4619557020690583171);
}
void car_h_25(double *state, double *unused, double *out_8479108228489595249) {
  h_25(state, unused, out_8479108228489595249);
}
void car_H_25(double *state, double *unused, double *out_7951779349636004332) {
  H_25(state, unused, out_7951779349636004332);
}
void car_h_24(double *state, double *unused, double *out_3909636304809658351) {
  h_24(state, unused, out_3909636304809658351);
}
void car_H_24(double *state, double *unused, double *out_6937039125271224148) {
  H_24(state, unused, out_6937039125271224148);
}
void car_h_30(double *state, double *unused, double *out_4380804930210223385) {
  h_30(state, unused, out_4380804930210223385);
}
void car_H_30(double *state, double *unused, double *out_7976631765566298657) {
  H_30(state, unused, out_7976631765566298657);
}
void car_h_26(double *state, double *unused, double *out_4415504534055773755) {
  h_26(state, unused, out_4415504534055773755);
}
void car_H_26(double *state, double *unused, double *out_4210276030761948108) {
  H_26(state, unused, out_4210276030761948108);
}
void car_h_27(double *state, double *unused, double *out_1379473163415114959) {
  h_27(state, unused, out_1379473163415114959);
}
void car_H_27(double *state, double *unused, double *out_5753037694382355440) {
  H_27(state, unused, out_5753037694382355440);
}
void car_h_29(double *state, double *unused, double *out_1104279101130609070) {
  h_29(state, unused, out_1104279101130609070);
}
void car_H_29(double *state, double *unused, double *out_7466400421251906473) {
  H_29(state, unused, out_7466400421251906473);
}
void car_h_28(double *state, double *unused, double *out_4498812324143600129) {
  h_28(state, unused, out_4498812324143600129);
}
void car_H_28(double *state, double *unused, double *out_5897944635388114569) {
  H_28(state, unused, out_5897944635388114569);
}
void car_h_31(double *state, double *unused, double *out_8203914166205089360) {
  h_31(state, unused, out_8203914166205089360);
}
void car_H_31(double *state, double *unused, double *out_7982425311512964760) {
  H_31(state, unused, out_7982425311512964760);
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
