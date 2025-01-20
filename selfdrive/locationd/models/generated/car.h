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
void car_err_fun(double *nom_x, double *delta_x, double *out_3729180171091771888);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6964334479301239449);
void car_H_mod_fun(double *state, double *out_6971916085428182136);
void car_f_fun(double *state, double dt, double *out_6948150360176626138);
void car_F_fun(double *state, double dt, double *out_4619557020690583171);
void car_h_25(double *state, double *unused, double *out_8479108228489595249);
void car_H_25(double *state, double *unused, double *out_7951779349636004332);
void car_h_24(double *state, double *unused, double *out_3909636304809658351);
void car_H_24(double *state, double *unused, double *out_6937039125271224148);
void car_h_30(double *state, double *unused, double *out_4380804930210223385);
void car_H_30(double *state, double *unused, double *out_7976631765566298657);
void car_h_26(double *state, double *unused, double *out_4415504534055773755);
void car_H_26(double *state, double *unused, double *out_4210276030761948108);
void car_h_27(double *state, double *unused, double *out_1379473163415114959);
void car_H_27(double *state, double *unused, double *out_5753037694382355440);
void car_h_29(double *state, double *unused, double *out_1104279101130609070);
void car_H_29(double *state, double *unused, double *out_7466400421251906473);
void car_h_28(double *state, double *unused, double *out_4498812324143600129);
void car_H_28(double *state, double *unused, double *out_5897944635388114569);
void car_h_31(double *state, double *unused, double *out_8203914166205089360);
void car_H_31(double *state, double *unused, double *out_7982425311512964760);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}