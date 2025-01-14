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
void err_fun(double *nom_x, double *delta_x, double *out_8578357905241103501) {
   out_8578357905241103501[0] = delta_x[0] + nom_x[0];
   out_8578357905241103501[1] = delta_x[1] + nom_x[1];
   out_8578357905241103501[2] = delta_x[2] + nom_x[2];
   out_8578357905241103501[3] = delta_x[3] + nom_x[3];
   out_8578357905241103501[4] = delta_x[4] + nom_x[4];
   out_8578357905241103501[5] = delta_x[5] + nom_x[5];
   out_8578357905241103501[6] = delta_x[6] + nom_x[6];
   out_8578357905241103501[7] = delta_x[7] + nom_x[7];
   out_8578357905241103501[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6406521346220384629) {
   out_6406521346220384629[0] = -nom_x[0] + true_x[0];
   out_6406521346220384629[1] = -nom_x[1] + true_x[1];
   out_6406521346220384629[2] = -nom_x[2] + true_x[2];
   out_6406521346220384629[3] = -nom_x[3] + true_x[3];
   out_6406521346220384629[4] = -nom_x[4] + true_x[4];
   out_6406521346220384629[5] = -nom_x[5] + true_x[5];
   out_6406521346220384629[6] = -nom_x[6] + true_x[6];
   out_6406521346220384629[7] = -nom_x[7] + true_x[7];
   out_6406521346220384629[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6196802311871331349) {
   out_6196802311871331349[0] = 1.0;
   out_6196802311871331349[1] = 0.0;
   out_6196802311871331349[2] = 0.0;
   out_6196802311871331349[3] = 0.0;
   out_6196802311871331349[4] = 0.0;
   out_6196802311871331349[5] = 0.0;
   out_6196802311871331349[6] = 0.0;
   out_6196802311871331349[7] = 0.0;
   out_6196802311871331349[8] = 0.0;
   out_6196802311871331349[9] = 0.0;
   out_6196802311871331349[10] = 1.0;
   out_6196802311871331349[11] = 0.0;
   out_6196802311871331349[12] = 0.0;
   out_6196802311871331349[13] = 0.0;
   out_6196802311871331349[14] = 0.0;
   out_6196802311871331349[15] = 0.0;
   out_6196802311871331349[16] = 0.0;
   out_6196802311871331349[17] = 0.0;
   out_6196802311871331349[18] = 0.0;
   out_6196802311871331349[19] = 0.0;
   out_6196802311871331349[20] = 1.0;
   out_6196802311871331349[21] = 0.0;
   out_6196802311871331349[22] = 0.0;
   out_6196802311871331349[23] = 0.0;
   out_6196802311871331349[24] = 0.0;
   out_6196802311871331349[25] = 0.0;
   out_6196802311871331349[26] = 0.0;
   out_6196802311871331349[27] = 0.0;
   out_6196802311871331349[28] = 0.0;
   out_6196802311871331349[29] = 0.0;
   out_6196802311871331349[30] = 1.0;
   out_6196802311871331349[31] = 0.0;
   out_6196802311871331349[32] = 0.0;
   out_6196802311871331349[33] = 0.0;
   out_6196802311871331349[34] = 0.0;
   out_6196802311871331349[35] = 0.0;
   out_6196802311871331349[36] = 0.0;
   out_6196802311871331349[37] = 0.0;
   out_6196802311871331349[38] = 0.0;
   out_6196802311871331349[39] = 0.0;
   out_6196802311871331349[40] = 1.0;
   out_6196802311871331349[41] = 0.0;
   out_6196802311871331349[42] = 0.0;
   out_6196802311871331349[43] = 0.0;
   out_6196802311871331349[44] = 0.0;
   out_6196802311871331349[45] = 0.0;
   out_6196802311871331349[46] = 0.0;
   out_6196802311871331349[47] = 0.0;
   out_6196802311871331349[48] = 0.0;
   out_6196802311871331349[49] = 0.0;
   out_6196802311871331349[50] = 1.0;
   out_6196802311871331349[51] = 0.0;
   out_6196802311871331349[52] = 0.0;
   out_6196802311871331349[53] = 0.0;
   out_6196802311871331349[54] = 0.0;
   out_6196802311871331349[55] = 0.0;
   out_6196802311871331349[56] = 0.0;
   out_6196802311871331349[57] = 0.0;
   out_6196802311871331349[58] = 0.0;
   out_6196802311871331349[59] = 0.0;
   out_6196802311871331349[60] = 1.0;
   out_6196802311871331349[61] = 0.0;
   out_6196802311871331349[62] = 0.0;
   out_6196802311871331349[63] = 0.0;
   out_6196802311871331349[64] = 0.0;
   out_6196802311871331349[65] = 0.0;
   out_6196802311871331349[66] = 0.0;
   out_6196802311871331349[67] = 0.0;
   out_6196802311871331349[68] = 0.0;
   out_6196802311871331349[69] = 0.0;
   out_6196802311871331349[70] = 1.0;
   out_6196802311871331349[71] = 0.0;
   out_6196802311871331349[72] = 0.0;
   out_6196802311871331349[73] = 0.0;
   out_6196802311871331349[74] = 0.0;
   out_6196802311871331349[75] = 0.0;
   out_6196802311871331349[76] = 0.0;
   out_6196802311871331349[77] = 0.0;
   out_6196802311871331349[78] = 0.0;
   out_6196802311871331349[79] = 0.0;
   out_6196802311871331349[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1188073981125929343) {
   out_1188073981125929343[0] = state[0];
   out_1188073981125929343[1] = state[1];
   out_1188073981125929343[2] = state[2];
   out_1188073981125929343[3] = state[3];
   out_1188073981125929343[4] = state[4];
   out_1188073981125929343[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1188073981125929343[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1188073981125929343[7] = state[7];
   out_1188073981125929343[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8306680979977818681) {
   out_8306680979977818681[0] = 1;
   out_8306680979977818681[1] = 0;
   out_8306680979977818681[2] = 0;
   out_8306680979977818681[3] = 0;
   out_8306680979977818681[4] = 0;
   out_8306680979977818681[5] = 0;
   out_8306680979977818681[6] = 0;
   out_8306680979977818681[7] = 0;
   out_8306680979977818681[8] = 0;
   out_8306680979977818681[9] = 0;
   out_8306680979977818681[10] = 1;
   out_8306680979977818681[11] = 0;
   out_8306680979977818681[12] = 0;
   out_8306680979977818681[13] = 0;
   out_8306680979977818681[14] = 0;
   out_8306680979977818681[15] = 0;
   out_8306680979977818681[16] = 0;
   out_8306680979977818681[17] = 0;
   out_8306680979977818681[18] = 0;
   out_8306680979977818681[19] = 0;
   out_8306680979977818681[20] = 1;
   out_8306680979977818681[21] = 0;
   out_8306680979977818681[22] = 0;
   out_8306680979977818681[23] = 0;
   out_8306680979977818681[24] = 0;
   out_8306680979977818681[25] = 0;
   out_8306680979977818681[26] = 0;
   out_8306680979977818681[27] = 0;
   out_8306680979977818681[28] = 0;
   out_8306680979977818681[29] = 0;
   out_8306680979977818681[30] = 1;
   out_8306680979977818681[31] = 0;
   out_8306680979977818681[32] = 0;
   out_8306680979977818681[33] = 0;
   out_8306680979977818681[34] = 0;
   out_8306680979977818681[35] = 0;
   out_8306680979977818681[36] = 0;
   out_8306680979977818681[37] = 0;
   out_8306680979977818681[38] = 0;
   out_8306680979977818681[39] = 0;
   out_8306680979977818681[40] = 1;
   out_8306680979977818681[41] = 0;
   out_8306680979977818681[42] = 0;
   out_8306680979977818681[43] = 0;
   out_8306680979977818681[44] = 0;
   out_8306680979977818681[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8306680979977818681[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8306680979977818681[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8306680979977818681[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8306680979977818681[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8306680979977818681[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8306680979977818681[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8306680979977818681[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8306680979977818681[53] = -9.8000000000000007*dt;
   out_8306680979977818681[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8306680979977818681[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8306680979977818681[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8306680979977818681[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8306680979977818681[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8306680979977818681[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8306680979977818681[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8306680979977818681[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8306680979977818681[62] = 0;
   out_8306680979977818681[63] = 0;
   out_8306680979977818681[64] = 0;
   out_8306680979977818681[65] = 0;
   out_8306680979977818681[66] = 0;
   out_8306680979977818681[67] = 0;
   out_8306680979977818681[68] = 0;
   out_8306680979977818681[69] = 0;
   out_8306680979977818681[70] = 1;
   out_8306680979977818681[71] = 0;
   out_8306680979977818681[72] = 0;
   out_8306680979977818681[73] = 0;
   out_8306680979977818681[74] = 0;
   out_8306680979977818681[75] = 0;
   out_8306680979977818681[76] = 0;
   out_8306680979977818681[77] = 0;
   out_8306680979977818681[78] = 0;
   out_8306680979977818681[79] = 0;
   out_8306680979977818681[80] = 1;
}
void h_25(double *state, double *unused, double *out_2865462067079422281) {
   out_2865462067079422281[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3866970214647675977) {
   out_3866970214647675977[0] = 0;
   out_3866970214647675977[1] = 0;
   out_3866970214647675977[2] = 0;
   out_3866970214647675977[3] = 0;
   out_3866970214647675977[4] = 0;
   out_3866970214647675977[5] = 0;
   out_3866970214647675977[6] = 1;
   out_3866970214647675977[7] = 0;
   out_3866970214647675977[8] = 0;
}
void h_24(double *state, double *unused, double *out_8545275959805781298) {
   out_8545275959805781298[0] = state[4];
   out_8545275959805781298[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8735785079675382829) {
   out_8735785079675382829[0] = 0;
   out_8735785079675382829[1] = 0;
   out_8735785079675382829[2] = 0;
   out_8735785079675382829[3] = 0;
   out_8735785079675382829[4] = 1;
   out_8735785079675382829[5] = 0;
   out_8735785079675382829[6] = 0;
   out_8735785079675382829[7] = 0;
   out_8735785079675382829[8] = 0;
   out_8735785079675382829[9] = 0;
   out_8735785079675382829[10] = 0;
   out_8735785079675382829[11] = 0;
   out_8735785079675382829[12] = 0;
   out_8735785079675382829[13] = 0;
   out_8735785079675382829[14] = 1;
   out_8735785079675382829[15] = 0;
   out_8735785079675382829[16] = 0;
   out_8735785079675382829[17] = 0;
}
void h_30(double *state, double *unused, double *out_7902582873852301211) {
   out_7902582873852301211[0] = state[4];
}
void H_30(double *state, double *unused, double *out_8394666544775284175) {
   out_8394666544775284175[0] = 0;
   out_8394666544775284175[1] = 0;
   out_8394666544775284175[2] = 0;
   out_8394666544775284175[3] = 0;
   out_8394666544775284175[4] = 1;
   out_8394666544775284175[5] = 0;
   out_8394666544775284175[6] = 0;
   out_8394666544775284175[7] = 0;
   out_8394666544775284175[8] = 0;
}
void h_26(double *state, double *unused, double *out_1503541356438452065) {
   out_1503541356438452065[0] = state[7];
}
void H_26(double *state, double *unused, double *out_7608473533521732201) {
   out_7608473533521732201[0] = 0;
   out_7608473533521732201[1] = 0;
   out_7608473533521732201[2] = 0;
   out_7608473533521732201[3] = 0;
   out_7608473533521732201[4] = 0;
   out_7608473533521732201[5] = 0;
   out_7608473533521732201[6] = 0;
   out_7608473533521732201[7] = 1;
   out_7608473533521732201[8] = 0;
}
void h_27(double *state, double *unused, double *out_1385533962505075321) {
   out_1385533962505075321[0] = state[3];
}
void H_27(double *state, double *unused, double *out_7877314217133842530) {
   out_7877314217133842530[0] = 0;
   out_7877314217133842530[1] = 0;
   out_7877314217133842530[2] = 0;
   out_7877314217133842530[3] = 1;
   out_7877314217133842530[4] = 0;
   out_7877314217133842530[5] = 0;
   out_7877314217133842530[6] = 0;
   out_7877314217133842530[7] = 0;
   out_7877314217133842530[8] = 0;
}
void h_29(double *state, double *unused, double *out_1986952120118438875) {
   out_1986952120118438875[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7884435200460891991) {
   out_7884435200460891991[0] = 0;
   out_7884435200460891991[1] = 1;
   out_7884435200460891991[2] = 0;
   out_7884435200460891991[3] = 0;
   out_7884435200460891991[4] = 0;
   out_7884435200460891991[5] = 0;
   out_7884435200460891991[6] = 0;
   out_7884435200460891991[7] = 0;
   out_7884435200460891991[8] = 0;
}
void h_28(double *state, double *unused, double *out_3616139305155770324) {
   out_3616139305155770324[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5479909856179129051) {
   out_5479909856179129051[0] = 1;
   out_5479909856179129051[1] = 0;
   out_5479909856179129051[2] = 0;
   out_5479909856179129051[3] = 0;
   out_5479909856179129051[4] = 0;
   out_5479909856179129051[5] = 0;
   out_5479909856179129051[6] = 0;
   out_5479909856179129051[7] = 0;
   out_5479909856179129051[8] = 0;
}
void h_31(double *state, double *unused, double *out_5027477427805101078) {
   out_5027477427805101078[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8234681635755083677) {
   out_8234681635755083677[0] = 0;
   out_8234681635755083677[1] = 0;
   out_8234681635755083677[2] = 0;
   out_8234681635755083677[3] = 0;
   out_8234681635755083677[4] = 0;
   out_8234681635755083677[5] = 0;
   out_8234681635755083677[6] = 0;
   out_8234681635755083677[7] = 0;
   out_8234681635755083677[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_8578357905241103501) {
  err_fun(nom_x, delta_x, out_8578357905241103501);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6406521346220384629) {
  inv_err_fun(nom_x, true_x, out_6406521346220384629);
}
void car_H_mod_fun(double *state, double *out_6196802311871331349) {
  H_mod_fun(state, out_6196802311871331349);
}
void car_f_fun(double *state, double dt, double *out_1188073981125929343) {
  f_fun(state,  dt, out_1188073981125929343);
}
void car_F_fun(double *state, double dt, double *out_8306680979977818681) {
  F_fun(state,  dt, out_8306680979977818681);
}
void car_h_25(double *state, double *unused, double *out_2865462067079422281) {
  h_25(state, unused, out_2865462067079422281);
}
void car_H_25(double *state, double *unused, double *out_3866970214647675977) {
  H_25(state, unused, out_3866970214647675977);
}
void car_h_24(double *state, double *unused, double *out_8545275959805781298) {
  h_24(state, unused, out_8545275959805781298);
}
void car_H_24(double *state, double *unused, double *out_8735785079675382829) {
  H_24(state, unused, out_8735785079675382829);
}
void car_h_30(double *state, double *unused, double *out_7902582873852301211) {
  h_30(state, unused, out_7902582873852301211);
}
void car_H_30(double *state, double *unused, double *out_8394666544775284175) {
  H_30(state, unused, out_8394666544775284175);
}
void car_h_26(double *state, double *unused, double *out_1503541356438452065) {
  h_26(state, unused, out_1503541356438452065);
}
void car_H_26(double *state, double *unused, double *out_7608473533521732201) {
  H_26(state, unused, out_7608473533521732201);
}
void car_h_27(double *state, double *unused, double *out_1385533962505075321) {
  h_27(state, unused, out_1385533962505075321);
}
void car_H_27(double *state, double *unused, double *out_7877314217133842530) {
  H_27(state, unused, out_7877314217133842530);
}
void car_h_29(double *state, double *unused, double *out_1986952120118438875) {
  h_29(state, unused, out_1986952120118438875);
}
void car_H_29(double *state, double *unused, double *out_7884435200460891991) {
  H_29(state, unused, out_7884435200460891991);
}
void car_h_28(double *state, double *unused, double *out_3616139305155770324) {
  h_28(state, unused, out_3616139305155770324);
}
void car_H_28(double *state, double *unused, double *out_5479909856179129051) {
  H_28(state, unused, out_5479909856179129051);
}
void car_h_31(double *state, double *unused, double *out_5027477427805101078) {
  h_31(state, unused, out_5027477427805101078);
}
void car_H_31(double *state, double *unused, double *out_8234681635755083677) {
  H_31(state, unused, out_8234681635755083677);
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
