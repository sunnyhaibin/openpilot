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
void car_err_fun(double *nom_x, double *delta_x, double *out_6981285947428203759);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3103352485653640338);
void car_H_mod_fun(double *state, double *out_7545812970075001068);
void car_f_fun(double *state, double dt, double *out_7404244546590542183);
void car_F_fun(double *state, double dt, double *out_7187733473119293793);
void car_h_25(double *state, double *unused, double *out_6182079305000059618);
void car_H_25(double *state, double *unused, double *out_5477287684314288312);
void car_h_24(double *state, double *unused, double *out_8703248481960040622);
void car_H_24(double *state, double *unused, double *out_6393884582803745203);
void car_h_30(double *state, double *unused, double *out_1581185951820612823);
void car_H_30(double *state, double *unused, double *out_6052766047903646549);
void car_h_26(double *state, double *unused, double *out_9061678688093263158);
void car_H_26(double *state, double *unused, double *out_1735784365440232088);
void car_h_27(double *state, double *unused, double *out_7262991501048646353);
void car_H_27(double *state, double *unused, double *out_8227529359704071460);
void car_h_29(double *state, double *unused, double *out_3420487315840232822);
void car_H_29(double *state, double *unused, double *out_5542534703589254365);
void car_h_28(double *state, double *unused, double *out_2201783400654064498);
void car_H_28(double *state, double *unused, double *out_7821810353050766677);
void car_h_31(double *state, double *unused, double *out_5493829542359141062);
void car_H_31(double *state, double *unused, double *out_5507933646191248740);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}