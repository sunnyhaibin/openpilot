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
void car_err_fun(double *nom_x, double *delta_x, double *out_4012158837685738846);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6627786481829846872);
void car_H_mod_fun(double *state, double *out_8124874952638661265);
void car_f_fun(double *state, double dt, double *out_7752599678791453808);
void car_F_fun(double *state, double dt, double *out_5892850043538329353);
void car_h_25(double *state, double *unused, double *out_1945291144542620166);
void car_H_25(double *state, double *unused, double *out_3221183127453996425);
void car_h_24(double *state, double *unused, double *out_1518205842954197550);
void car_H_24(double *state, double *unused, double *out_1043968703846846452);
void car_h_30(double *state, double *unused, double *out_1670097082258114277);
void car_H_30(double *state, double *unused, double *out_702850168946747798);
void car_h_26(double *state, double *unused, double *out_7548382569816829365);
void car_H_26(double *state, double *unused, double *out_6962686446328052649);
void car_h_27(double *state, double *unused, double *out_3635738979278301126);
void car_H_27(double *state, double *unused, double *out_8523101304327522082);
void car_h_29(double *state, double *unused, double *out_3972632788822842558);
void car_H_29(double *state, double *unused, double *out_192618824632355614);
void car_h_28(double *state, double *unused, double *out_2006990891802655709);
void car_H_28(double *state, double *unused, double *out_5275017841701886188);
void car_h_31(double *state, double *unused, double *out_1788104476191491021);
void car_H_31(double *state, double *unused, double *out_7588894548561404125);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}