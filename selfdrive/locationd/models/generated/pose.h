#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3808871484533937584);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5966866822242435171);
void pose_H_mod_fun(double *state, double *out_8196089614431620713);
void pose_f_fun(double *state, double dt, double *out_5274084714105371283);
void pose_F_fun(double *state, double dt, double *out_6609214454909701691);
void pose_h_4(double *state, double *unused, double *out_3366909334215694695);
void pose_H_4(double *state, double *unused, double *out_8430955733371634042);
void pose_h_10(double *state, double *unused, double *out_4720353580216428160);
void pose_H_10(double *state, double *unused, double *out_4173229103338726482);
void pose_h_13(double *state, double *unused, double *out_2154140950857846094);
void pose_H_13(double *state, double *unused, double *out_2405157132021216645);
void pose_h_14(double *state, double *unused, double *out_9066320572095185705);
void pose_H_14(double *state, double *unused, double *out_6052547483998433045);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}