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
void car_err_fun(double *nom_x, double *delta_x, double *out_5299514782424555133);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3535349126216233199);
void car_H_mod_fun(double *state, double *out_5252922282480581452);
void car_f_fun(double *state, double dt, double *out_2019747047538005833);
void car_F_fun(double *state, double dt, double *out_9121343994600952035);
void car_h_25(double *state, double *unused, double *out_7335794429038047257);
void car_H_25(double *state, double *unused, double *out_6019370044562788701);
void car_h_24(double *state, double *unused, double *out_8140094201337253727);
void car_H_24(double *state, double *unused, double *out_6226341349295601489);
void car_h_30(double *state, double *unused, double *out_1168680389066912954);
void car_H_30(double *state, double *unused, double *out_7899677699019154717);
void car_h_26(double *state, double *unused, double *out_5906826438573726884);
void car_H_26(double *state, double *unused, double *out_8685870710272706691);
void car_h_27(double *state, double *unused, double *out_6109276377010658714);
void car_H_27(double *state, double *unused, double *out_8323472303506453682);
void car_h_29(double *state, double *unused, double *out_2471826848756636364);
void car_H_29(double *state, double *unused, double *out_8409909043333546901);
void car_h_28(double *state, double *unused, double *out_8921828480280512097);
void car_H_28(double *state, double *unused, double *out_8073204758810678464);
void car_h_31(double *state, double *unused, double *out_3347684387850831918);
void car_H_31(double *state, double *unused, double *out_5988724082685828273);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}