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
void car_err_fun(double *nom_x, double *delta_x, double *out_1140227036079585444);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5212577056806210372);
void car_H_mod_fun(double *state, double *out_5162633318968107627);
void car_f_fun(double *state, double dt, double *out_6160854576209296037);
void car_F_fun(double *state, double dt, double *out_939256608556051694);
void car_h_25(double *state, double *unused, double *out_1962884221865330862);
void car_H_25(double *state, double *unused, double *out_1517062800868197284);
void car_h_24(double *state, double *unused, double *out_8894343782379777004);
void car_H_24(double *state, double *unused, double *out_7701616086772159107);
void car_h_30(double *state, double *unused, double *out_8602587201090171569);
void car_H_30(double *state, double *unused, double *out_1387723853724957214);
void car_h_26(double *state, double *unused, double *out_3640207203408878337);
void car_H_26(double *state, double *unused, double *out_2224440518005858940);
void car_h_27(double *state, double *unused, double *out_7188791437700655809);
void car_H_27(double *state, double *unused, double *out_787039458075467697);
void car_h_29(double *state, double *unused, double *out_7620503107754873457);
void car_H_29(double *state, double *unused, double *out_2500402184945018730);
void car_h_28(double *state, double *unused, double *out_6256279368348050162);
void car_H_28(double *state, double *unused, double *out_7582801202014549304);
void car_h_31(double *state, double *unused, double *out_8720594595023548313);
void car_H_31(double *state, double *unused, double *out_1547708762745157712);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}