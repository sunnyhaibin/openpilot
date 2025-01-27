#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4331083049534056355);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5197883329726451987);
void pose_H_mod_fun(double *state, double *out_8877666100320465704);
void pose_f_fun(double *state, double dt, double *out_3376588760060985122);
void pose_F_fun(double *state, double dt, double *out_2519439478573749592);
void pose_h_4(double *state, double *unused, double *out_4122032360045161599);
void pose_H_4(double *state, double *unused, double *out_6299007443242394437);
void pose_h_10(double *state, double *unused, double *out_3087000031012309486);
void pose_H_10(double *state, double *unused, double *out_8202087792414705539);
void pose_h_13(double *state, double *unused, double *out_6042732269179361123);
void pose_H_13(double *state, double *unused, double *out_3086733617910061636);
void pose_h_14(double *state, double *unused, double *out_7471847647180952458);
void pose_H_14(double *state, double *unused, double *out_2335766586902909908);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}