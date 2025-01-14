#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_38746564740330454);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7177343441098663951);
void pose_H_mod_fun(double *state, double *out_3413607092153665585);
void pose_f_fun(double *state, double dt, double *out_2670038371119115624);
void pose_F_fun(double *state, double dt, double *out_6628185752545362634);
void pose_h_4(double *state, double *unused, double *out_1095094246816165977);
void pose_H_4(double *state, double *unused, double *out_5530754573904155757);
void pose_h_10(double *state, double *unused, double *out_6379475221413403009);
void pose_H_10(double *state, double *unused, double *out_4074749303757361303);
void pose_h_13(double *state, double *unused, double *out_193722928821992681);
void pose_H_13(double *state, double *unused, double *out_9082234036502871835);
void pose_h_14(double *state, double *unused, double *out_9219347760475627175);
void pose_H_14(double *state, double *unused, double *out_8613543006199528053);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}