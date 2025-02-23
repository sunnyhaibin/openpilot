#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4117449312389212167);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2619781936850820050);
void pose_H_mod_fun(double *state, double *out_7078650365136719116);
void pose_f_fun(double *state, double dt, double *out_1089863288273716995);
void pose_F_fun(double *state, double dt, double *out_1417775725995845595);
void pose_h_4(double *state, double *unused, double *out_1718190299387698220);
void pose_H_4(double *state, double *unused, double *out_3167788824599607733);
void pose_h_10(double *state, double *unused, double *out_5321237706151248965);
void pose_H_10(double *state, double *unused, double *out_1920250937061611591);
void pose_h_13(double *state, double *unused, double *out_8512972491309284140);
void pose_H_13(double *state, double *unused, double *out_4442842383717093196);
void pose_h_14(double *state, double *unused, double *out_4631166666474537982);
void pose_H_14(double *state, double *unused, double *out_795452031739876796);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}