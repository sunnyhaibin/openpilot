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
void car_err_fun(double *nom_x, double *delta_x, double *out_5155184678321054055);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_260336739787886255);
void car_H_mod_fun(double *state, double *out_2599023291947582855);
void car_f_fun(double *state, double dt, double *out_8697556517231450544);
void car_F_fun(double *state, double dt, double *out_808877034590597564);
void car_h_25(double *state, double *unused, double *out_5800912085437080381);
void car_H_25(double *state, double *unused, double *out_2304668533237081985);
void car_h_24(double *state, double *unused, double *out_4070289765820226730);
void car_H_24(double *state, double *unused, double *out_8880240339828600086);
void car_h_30(double *state, double *unused, double *out_1962353171383592060);
void car_H_30(double *state, double *unused, double *out_4823001491744330612);
void car_h_26(double *state, double *unused, double *out_4436688346030257086);
void car_H_26(double *state, double *unused, double *out_5609194502997882586);
void car_h_27(double *state, double *unused, double *out_3405291034744239686);
void car_H_27(double *state, double *unused, double *out_7046595562928273829);
void car_h_29(double *state, double *unused, double *out_3039320096277253585);
void car_H_29(double *state, double *unused, double *out_5333232836058722796);
void car_h_28(double *state, double *unused, double *out_1820616181091085261);
void car_H_28(double *state, double *unused, double *out_250833818989192222);
void car_h_31(double *state, double *unused, double *out_786915841039214782);
void car_H_31(double *state, double *unused, double *out_2335314495114042413);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}