#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_7547269211206820042);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6420366428061433715);
void pose_H_mod_fun(double *state, double *out_7812193377109128418);
void pose_f_fun(double *state, double dt, double *out_1977748915209978600);
void pose_F_fun(double *state, double dt, double *out_2388978117553328468);
void pose_h_4(double *state, double *unused, double *out_1855587536956700071);
void pose_H_4(double *state, double *unused, double *out_9010140858992026522);
void pose_h_10(double *state, double *unused, double *out_8454914287904169316);
void pose_H_10(double *state, double *unused, double *out_4142937433250982486);
void pose_h_13(double *state, double *unused, double *out_7515033349393404962);
void pose_H_13(double *state, double *unused, double *out_6224329389385192293);
void pose_h_14(double *state, double *unused, double *out_3054229621894193800);
void pose_H_14(double *state, double *unused, double *out_5473362358378040565);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}