#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_8578357905241103501);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6406521346220384629);
void car_H_mod_fun(double *state, double *out_6196802311871331349);
void car_f_fun(double *state, double dt, double *out_1188073981125929343);
void car_F_fun(double *state, double dt, double *out_8306680979977818681);
void car_h_25(double *state, double *unused, double *out_2865462067079422281);
void car_H_25(double *state, double *unused, double *out_3866970214647675977);
void car_h_24(double *state, double *unused, double *out_8545275959805781298);
void car_H_24(double *state, double *unused, double *out_8735785079675382829);
void car_h_30(double *state, double *unused, double *out_7902582873852301211);
void car_H_30(double *state, double *unused, double *out_8394666544775284175);
void car_h_26(double *state, double *unused, double *out_1503541356438452065);
void car_H_26(double *state, double *unused, double *out_7608473533521732201);
void car_h_27(double *state, double *unused, double *out_1385533962505075321);
void car_H_27(double *state, double *unused, double *out_7877314217133842530);
void car_h_29(double *state, double *unused, double *out_1986952120118438875);
void car_H_29(double *state, double *unused, double *out_7884435200460891991);
void car_h_28(double *state, double *unused, double *out_3616139305155770324);
void car_H_28(double *state, double *unused, double *out_5479909856179129051);
void car_h_31(double *state, double *unused, double *out_5027477427805101078);
void car_H_31(double *state, double *unused, double *out_8234681635755083677);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}