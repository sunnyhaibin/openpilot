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
void car_err_fun(double *nom_x, double *delta_x, double *out_354464779286764365);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5129529406128162473);
void car_H_mod_fun(double *state, double *out_5015646059088940531);
void car_f_fun(double *state, double dt, double *out_1996750297433401186);
void car_F_fun(double *state, double dt, double *out_7116257316432458665);
void car_h_25(double *state, double *unused, double *out_6950824494898730012);
void car_H_25(double *state, double *unused, double *out_111954233904275691);
void car_h_24(double *state, double *unused, double *out_7242744353424038527);
void car_H_24(double *state, double *unused, double *out_6463617572687242410);
void car_h_30(double *state, double *unused, double *out_3313374966644707662);
void car_H_30(double *state, double *unused, double *out_2406378724602972936);
void car_h_26(double *state, double *unused, double *out_276588915200374977);
void car_H_26(double *state, double *unused, double *out_3853457552778331915);
void car_h_27(double *state, double *unused, double *out_7894334347800392447);
void car_H_27(double *state, double *unused, double *out_4629972795786916153);
void car_h_29(double *state, double *unused, double *out_1912532249190617285);
void car_H_29(double *state, double *unused, double *out_2916610068917365120);
void car_h_28(double *state, double *unused, double *out_7515623674464826484);
void car_H_28(double *state, double *unused, double *out_2165788948152165454);
void car_h_31(double *state, double *unused, double *out_7226018557183235901);
void car_H_31(double *state, double *unused, double *out_81308272027315263);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}