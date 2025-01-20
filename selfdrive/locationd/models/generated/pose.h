#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_582162479678847507);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8183002877435981990);
void pose_H_mod_fun(double *state, double *out_721764794937271849);
void pose_f_fun(double *state, double dt, double *out_4641529343405726831);
void pose_F_fun(double *state, double dt, double *out_5067006879448835750);
void pose_h_4(double *state, double *unused, double *out_6721945205192637351);
void pose_H_4(double *state, double *unused, double *out_8291219624976412643);
void pose_h_10(double *state, double *unused, double *out_2430238044192408930);
void pose_H_10(double *state, double *unused, double *out_1293960980901307379);
void pose_h_13(double *state, double *unused, double *out_2389125531200423217);
void pose_H_13(double *state, double *unused, double *out_6943250623400806172);
void pose_h_14(double *state, double *unused, double *out_4727481890209973727);
void pose_H_14(double *state, double *unused, double *out_6192283592393654444);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}