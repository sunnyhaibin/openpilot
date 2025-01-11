#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.13.2                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_3808871484533937584) {
   out_3808871484533937584[0] = delta_x[0] + nom_x[0];
   out_3808871484533937584[1] = delta_x[1] + nom_x[1];
   out_3808871484533937584[2] = delta_x[2] + nom_x[2];
   out_3808871484533937584[3] = delta_x[3] + nom_x[3];
   out_3808871484533937584[4] = delta_x[4] + nom_x[4];
   out_3808871484533937584[5] = delta_x[5] + nom_x[5];
   out_3808871484533937584[6] = delta_x[6] + nom_x[6];
   out_3808871484533937584[7] = delta_x[7] + nom_x[7];
   out_3808871484533937584[8] = delta_x[8] + nom_x[8];
   out_3808871484533937584[9] = delta_x[9] + nom_x[9];
   out_3808871484533937584[10] = delta_x[10] + nom_x[10];
   out_3808871484533937584[11] = delta_x[11] + nom_x[11];
   out_3808871484533937584[12] = delta_x[12] + nom_x[12];
   out_3808871484533937584[13] = delta_x[13] + nom_x[13];
   out_3808871484533937584[14] = delta_x[14] + nom_x[14];
   out_3808871484533937584[15] = delta_x[15] + nom_x[15];
   out_3808871484533937584[16] = delta_x[16] + nom_x[16];
   out_3808871484533937584[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5966866822242435171) {
   out_5966866822242435171[0] = -nom_x[0] + true_x[0];
   out_5966866822242435171[1] = -nom_x[1] + true_x[1];
   out_5966866822242435171[2] = -nom_x[2] + true_x[2];
   out_5966866822242435171[3] = -nom_x[3] + true_x[3];
   out_5966866822242435171[4] = -nom_x[4] + true_x[4];
   out_5966866822242435171[5] = -nom_x[5] + true_x[5];
   out_5966866822242435171[6] = -nom_x[6] + true_x[6];
   out_5966866822242435171[7] = -nom_x[7] + true_x[7];
   out_5966866822242435171[8] = -nom_x[8] + true_x[8];
   out_5966866822242435171[9] = -nom_x[9] + true_x[9];
   out_5966866822242435171[10] = -nom_x[10] + true_x[10];
   out_5966866822242435171[11] = -nom_x[11] + true_x[11];
   out_5966866822242435171[12] = -nom_x[12] + true_x[12];
   out_5966866822242435171[13] = -nom_x[13] + true_x[13];
   out_5966866822242435171[14] = -nom_x[14] + true_x[14];
   out_5966866822242435171[15] = -nom_x[15] + true_x[15];
   out_5966866822242435171[16] = -nom_x[16] + true_x[16];
   out_5966866822242435171[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_8196089614431620713) {
   out_8196089614431620713[0] = 1.0;
   out_8196089614431620713[1] = 0.0;
   out_8196089614431620713[2] = 0.0;
   out_8196089614431620713[3] = 0.0;
   out_8196089614431620713[4] = 0.0;
   out_8196089614431620713[5] = 0.0;
   out_8196089614431620713[6] = 0.0;
   out_8196089614431620713[7] = 0.0;
   out_8196089614431620713[8] = 0.0;
   out_8196089614431620713[9] = 0.0;
   out_8196089614431620713[10] = 0.0;
   out_8196089614431620713[11] = 0.0;
   out_8196089614431620713[12] = 0.0;
   out_8196089614431620713[13] = 0.0;
   out_8196089614431620713[14] = 0.0;
   out_8196089614431620713[15] = 0.0;
   out_8196089614431620713[16] = 0.0;
   out_8196089614431620713[17] = 0.0;
   out_8196089614431620713[18] = 0.0;
   out_8196089614431620713[19] = 1.0;
   out_8196089614431620713[20] = 0.0;
   out_8196089614431620713[21] = 0.0;
   out_8196089614431620713[22] = 0.0;
   out_8196089614431620713[23] = 0.0;
   out_8196089614431620713[24] = 0.0;
   out_8196089614431620713[25] = 0.0;
   out_8196089614431620713[26] = 0.0;
   out_8196089614431620713[27] = 0.0;
   out_8196089614431620713[28] = 0.0;
   out_8196089614431620713[29] = 0.0;
   out_8196089614431620713[30] = 0.0;
   out_8196089614431620713[31] = 0.0;
   out_8196089614431620713[32] = 0.0;
   out_8196089614431620713[33] = 0.0;
   out_8196089614431620713[34] = 0.0;
   out_8196089614431620713[35] = 0.0;
   out_8196089614431620713[36] = 0.0;
   out_8196089614431620713[37] = 0.0;
   out_8196089614431620713[38] = 1.0;
   out_8196089614431620713[39] = 0.0;
   out_8196089614431620713[40] = 0.0;
   out_8196089614431620713[41] = 0.0;
   out_8196089614431620713[42] = 0.0;
   out_8196089614431620713[43] = 0.0;
   out_8196089614431620713[44] = 0.0;
   out_8196089614431620713[45] = 0.0;
   out_8196089614431620713[46] = 0.0;
   out_8196089614431620713[47] = 0.0;
   out_8196089614431620713[48] = 0.0;
   out_8196089614431620713[49] = 0.0;
   out_8196089614431620713[50] = 0.0;
   out_8196089614431620713[51] = 0.0;
   out_8196089614431620713[52] = 0.0;
   out_8196089614431620713[53] = 0.0;
   out_8196089614431620713[54] = 0.0;
   out_8196089614431620713[55] = 0.0;
   out_8196089614431620713[56] = 0.0;
   out_8196089614431620713[57] = 1.0;
   out_8196089614431620713[58] = 0.0;
   out_8196089614431620713[59] = 0.0;
   out_8196089614431620713[60] = 0.0;
   out_8196089614431620713[61] = 0.0;
   out_8196089614431620713[62] = 0.0;
   out_8196089614431620713[63] = 0.0;
   out_8196089614431620713[64] = 0.0;
   out_8196089614431620713[65] = 0.0;
   out_8196089614431620713[66] = 0.0;
   out_8196089614431620713[67] = 0.0;
   out_8196089614431620713[68] = 0.0;
   out_8196089614431620713[69] = 0.0;
   out_8196089614431620713[70] = 0.0;
   out_8196089614431620713[71] = 0.0;
   out_8196089614431620713[72] = 0.0;
   out_8196089614431620713[73] = 0.0;
   out_8196089614431620713[74] = 0.0;
   out_8196089614431620713[75] = 0.0;
   out_8196089614431620713[76] = 1.0;
   out_8196089614431620713[77] = 0.0;
   out_8196089614431620713[78] = 0.0;
   out_8196089614431620713[79] = 0.0;
   out_8196089614431620713[80] = 0.0;
   out_8196089614431620713[81] = 0.0;
   out_8196089614431620713[82] = 0.0;
   out_8196089614431620713[83] = 0.0;
   out_8196089614431620713[84] = 0.0;
   out_8196089614431620713[85] = 0.0;
   out_8196089614431620713[86] = 0.0;
   out_8196089614431620713[87] = 0.0;
   out_8196089614431620713[88] = 0.0;
   out_8196089614431620713[89] = 0.0;
   out_8196089614431620713[90] = 0.0;
   out_8196089614431620713[91] = 0.0;
   out_8196089614431620713[92] = 0.0;
   out_8196089614431620713[93] = 0.0;
   out_8196089614431620713[94] = 0.0;
   out_8196089614431620713[95] = 1.0;
   out_8196089614431620713[96] = 0.0;
   out_8196089614431620713[97] = 0.0;
   out_8196089614431620713[98] = 0.0;
   out_8196089614431620713[99] = 0.0;
   out_8196089614431620713[100] = 0.0;
   out_8196089614431620713[101] = 0.0;
   out_8196089614431620713[102] = 0.0;
   out_8196089614431620713[103] = 0.0;
   out_8196089614431620713[104] = 0.0;
   out_8196089614431620713[105] = 0.0;
   out_8196089614431620713[106] = 0.0;
   out_8196089614431620713[107] = 0.0;
   out_8196089614431620713[108] = 0.0;
   out_8196089614431620713[109] = 0.0;
   out_8196089614431620713[110] = 0.0;
   out_8196089614431620713[111] = 0.0;
   out_8196089614431620713[112] = 0.0;
   out_8196089614431620713[113] = 0.0;
   out_8196089614431620713[114] = 1.0;
   out_8196089614431620713[115] = 0.0;
   out_8196089614431620713[116] = 0.0;
   out_8196089614431620713[117] = 0.0;
   out_8196089614431620713[118] = 0.0;
   out_8196089614431620713[119] = 0.0;
   out_8196089614431620713[120] = 0.0;
   out_8196089614431620713[121] = 0.0;
   out_8196089614431620713[122] = 0.0;
   out_8196089614431620713[123] = 0.0;
   out_8196089614431620713[124] = 0.0;
   out_8196089614431620713[125] = 0.0;
   out_8196089614431620713[126] = 0.0;
   out_8196089614431620713[127] = 0.0;
   out_8196089614431620713[128] = 0.0;
   out_8196089614431620713[129] = 0.0;
   out_8196089614431620713[130] = 0.0;
   out_8196089614431620713[131] = 0.0;
   out_8196089614431620713[132] = 0.0;
   out_8196089614431620713[133] = 1.0;
   out_8196089614431620713[134] = 0.0;
   out_8196089614431620713[135] = 0.0;
   out_8196089614431620713[136] = 0.0;
   out_8196089614431620713[137] = 0.0;
   out_8196089614431620713[138] = 0.0;
   out_8196089614431620713[139] = 0.0;
   out_8196089614431620713[140] = 0.0;
   out_8196089614431620713[141] = 0.0;
   out_8196089614431620713[142] = 0.0;
   out_8196089614431620713[143] = 0.0;
   out_8196089614431620713[144] = 0.0;
   out_8196089614431620713[145] = 0.0;
   out_8196089614431620713[146] = 0.0;
   out_8196089614431620713[147] = 0.0;
   out_8196089614431620713[148] = 0.0;
   out_8196089614431620713[149] = 0.0;
   out_8196089614431620713[150] = 0.0;
   out_8196089614431620713[151] = 0.0;
   out_8196089614431620713[152] = 1.0;
   out_8196089614431620713[153] = 0.0;
   out_8196089614431620713[154] = 0.0;
   out_8196089614431620713[155] = 0.0;
   out_8196089614431620713[156] = 0.0;
   out_8196089614431620713[157] = 0.0;
   out_8196089614431620713[158] = 0.0;
   out_8196089614431620713[159] = 0.0;
   out_8196089614431620713[160] = 0.0;
   out_8196089614431620713[161] = 0.0;
   out_8196089614431620713[162] = 0.0;
   out_8196089614431620713[163] = 0.0;
   out_8196089614431620713[164] = 0.0;
   out_8196089614431620713[165] = 0.0;
   out_8196089614431620713[166] = 0.0;
   out_8196089614431620713[167] = 0.0;
   out_8196089614431620713[168] = 0.0;
   out_8196089614431620713[169] = 0.0;
   out_8196089614431620713[170] = 0.0;
   out_8196089614431620713[171] = 1.0;
   out_8196089614431620713[172] = 0.0;
   out_8196089614431620713[173] = 0.0;
   out_8196089614431620713[174] = 0.0;
   out_8196089614431620713[175] = 0.0;
   out_8196089614431620713[176] = 0.0;
   out_8196089614431620713[177] = 0.0;
   out_8196089614431620713[178] = 0.0;
   out_8196089614431620713[179] = 0.0;
   out_8196089614431620713[180] = 0.0;
   out_8196089614431620713[181] = 0.0;
   out_8196089614431620713[182] = 0.0;
   out_8196089614431620713[183] = 0.0;
   out_8196089614431620713[184] = 0.0;
   out_8196089614431620713[185] = 0.0;
   out_8196089614431620713[186] = 0.0;
   out_8196089614431620713[187] = 0.0;
   out_8196089614431620713[188] = 0.0;
   out_8196089614431620713[189] = 0.0;
   out_8196089614431620713[190] = 1.0;
   out_8196089614431620713[191] = 0.0;
   out_8196089614431620713[192] = 0.0;
   out_8196089614431620713[193] = 0.0;
   out_8196089614431620713[194] = 0.0;
   out_8196089614431620713[195] = 0.0;
   out_8196089614431620713[196] = 0.0;
   out_8196089614431620713[197] = 0.0;
   out_8196089614431620713[198] = 0.0;
   out_8196089614431620713[199] = 0.0;
   out_8196089614431620713[200] = 0.0;
   out_8196089614431620713[201] = 0.0;
   out_8196089614431620713[202] = 0.0;
   out_8196089614431620713[203] = 0.0;
   out_8196089614431620713[204] = 0.0;
   out_8196089614431620713[205] = 0.0;
   out_8196089614431620713[206] = 0.0;
   out_8196089614431620713[207] = 0.0;
   out_8196089614431620713[208] = 0.0;
   out_8196089614431620713[209] = 1.0;
   out_8196089614431620713[210] = 0.0;
   out_8196089614431620713[211] = 0.0;
   out_8196089614431620713[212] = 0.0;
   out_8196089614431620713[213] = 0.0;
   out_8196089614431620713[214] = 0.0;
   out_8196089614431620713[215] = 0.0;
   out_8196089614431620713[216] = 0.0;
   out_8196089614431620713[217] = 0.0;
   out_8196089614431620713[218] = 0.0;
   out_8196089614431620713[219] = 0.0;
   out_8196089614431620713[220] = 0.0;
   out_8196089614431620713[221] = 0.0;
   out_8196089614431620713[222] = 0.0;
   out_8196089614431620713[223] = 0.0;
   out_8196089614431620713[224] = 0.0;
   out_8196089614431620713[225] = 0.0;
   out_8196089614431620713[226] = 0.0;
   out_8196089614431620713[227] = 0.0;
   out_8196089614431620713[228] = 1.0;
   out_8196089614431620713[229] = 0.0;
   out_8196089614431620713[230] = 0.0;
   out_8196089614431620713[231] = 0.0;
   out_8196089614431620713[232] = 0.0;
   out_8196089614431620713[233] = 0.0;
   out_8196089614431620713[234] = 0.0;
   out_8196089614431620713[235] = 0.0;
   out_8196089614431620713[236] = 0.0;
   out_8196089614431620713[237] = 0.0;
   out_8196089614431620713[238] = 0.0;
   out_8196089614431620713[239] = 0.0;
   out_8196089614431620713[240] = 0.0;
   out_8196089614431620713[241] = 0.0;
   out_8196089614431620713[242] = 0.0;
   out_8196089614431620713[243] = 0.0;
   out_8196089614431620713[244] = 0.0;
   out_8196089614431620713[245] = 0.0;
   out_8196089614431620713[246] = 0.0;
   out_8196089614431620713[247] = 1.0;
   out_8196089614431620713[248] = 0.0;
   out_8196089614431620713[249] = 0.0;
   out_8196089614431620713[250] = 0.0;
   out_8196089614431620713[251] = 0.0;
   out_8196089614431620713[252] = 0.0;
   out_8196089614431620713[253] = 0.0;
   out_8196089614431620713[254] = 0.0;
   out_8196089614431620713[255] = 0.0;
   out_8196089614431620713[256] = 0.0;
   out_8196089614431620713[257] = 0.0;
   out_8196089614431620713[258] = 0.0;
   out_8196089614431620713[259] = 0.0;
   out_8196089614431620713[260] = 0.0;
   out_8196089614431620713[261] = 0.0;
   out_8196089614431620713[262] = 0.0;
   out_8196089614431620713[263] = 0.0;
   out_8196089614431620713[264] = 0.0;
   out_8196089614431620713[265] = 0.0;
   out_8196089614431620713[266] = 1.0;
   out_8196089614431620713[267] = 0.0;
   out_8196089614431620713[268] = 0.0;
   out_8196089614431620713[269] = 0.0;
   out_8196089614431620713[270] = 0.0;
   out_8196089614431620713[271] = 0.0;
   out_8196089614431620713[272] = 0.0;
   out_8196089614431620713[273] = 0.0;
   out_8196089614431620713[274] = 0.0;
   out_8196089614431620713[275] = 0.0;
   out_8196089614431620713[276] = 0.0;
   out_8196089614431620713[277] = 0.0;
   out_8196089614431620713[278] = 0.0;
   out_8196089614431620713[279] = 0.0;
   out_8196089614431620713[280] = 0.0;
   out_8196089614431620713[281] = 0.0;
   out_8196089614431620713[282] = 0.0;
   out_8196089614431620713[283] = 0.0;
   out_8196089614431620713[284] = 0.0;
   out_8196089614431620713[285] = 1.0;
   out_8196089614431620713[286] = 0.0;
   out_8196089614431620713[287] = 0.0;
   out_8196089614431620713[288] = 0.0;
   out_8196089614431620713[289] = 0.0;
   out_8196089614431620713[290] = 0.0;
   out_8196089614431620713[291] = 0.0;
   out_8196089614431620713[292] = 0.0;
   out_8196089614431620713[293] = 0.0;
   out_8196089614431620713[294] = 0.0;
   out_8196089614431620713[295] = 0.0;
   out_8196089614431620713[296] = 0.0;
   out_8196089614431620713[297] = 0.0;
   out_8196089614431620713[298] = 0.0;
   out_8196089614431620713[299] = 0.0;
   out_8196089614431620713[300] = 0.0;
   out_8196089614431620713[301] = 0.0;
   out_8196089614431620713[302] = 0.0;
   out_8196089614431620713[303] = 0.0;
   out_8196089614431620713[304] = 1.0;
   out_8196089614431620713[305] = 0.0;
   out_8196089614431620713[306] = 0.0;
   out_8196089614431620713[307] = 0.0;
   out_8196089614431620713[308] = 0.0;
   out_8196089614431620713[309] = 0.0;
   out_8196089614431620713[310] = 0.0;
   out_8196089614431620713[311] = 0.0;
   out_8196089614431620713[312] = 0.0;
   out_8196089614431620713[313] = 0.0;
   out_8196089614431620713[314] = 0.0;
   out_8196089614431620713[315] = 0.0;
   out_8196089614431620713[316] = 0.0;
   out_8196089614431620713[317] = 0.0;
   out_8196089614431620713[318] = 0.0;
   out_8196089614431620713[319] = 0.0;
   out_8196089614431620713[320] = 0.0;
   out_8196089614431620713[321] = 0.0;
   out_8196089614431620713[322] = 0.0;
   out_8196089614431620713[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5274084714105371283) {
   out_5274084714105371283[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5274084714105371283[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5274084714105371283[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5274084714105371283[3] = dt*state[12] + state[3];
   out_5274084714105371283[4] = dt*state[13] + state[4];
   out_5274084714105371283[5] = dt*state[14] + state[5];
   out_5274084714105371283[6] = state[6];
   out_5274084714105371283[7] = state[7];
   out_5274084714105371283[8] = state[8];
   out_5274084714105371283[9] = state[9];
   out_5274084714105371283[10] = state[10];
   out_5274084714105371283[11] = state[11];
   out_5274084714105371283[12] = state[12];
   out_5274084714105371283[13] = state[13];
   out_5274084714105371283[14] = state[14];
   out_5274084714105371283[15] = state[15];
   out_5274084714105371283[16] = state[16];
   out_5274084714105371283[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6609214454909701691) {
   out_6609214454909701691[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6609214454909701691[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6609214454909701691[2] = 0;
   out_6609214454909701691[3] = 0;
   out_6609214454909701691[4] = 0;
   out_6609214454909701691[5] = 0;
   out_6609214454909701691[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6609214454909701691[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6609214454909701691[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6609214454909701691[9] = 0;
   out_6609214454909701691[10] = 0;
   out_6609214454909701691[11] = 0;
   out_6609214454909701691[12] = 0;
   out_6609214454909701691[13] = 0;
   out_6609214454909701691[14] = 0;
   out_6609214454909701691[15] = 0;
   out_6609214454909701691[16] = 0;
   out_6609214454909701691[17] = 0;
   out_6609214454909701691[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6609214454909701691[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6609214454909701691[20] = 0;
   out_6609214454909701691[21] = 0;
   out_6609214454909701691[22] = 0;
   out_6609214454909701691[23] = 0;
   out_6609214454909701691[24] = 0;
   out_6609214454909701691[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6609214454909701691[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6609214454909701691[27] = 0;
   out_6609214454909701691[28] = 0;
   out_6609214454909701691[29] = 0;
   out_6609214454909701691[30] = 0;
   out_6609214454909701691[31] = 0;
   out_6609214454909701691[32] = 0;
   out_6609214454909701691[33] = 0;
   out_6609214454909701691[34] = 0;
   out_6609214454909701691[35] = 0;
   out_6609214454909701691[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6609214454909701691[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6609214454909701691[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6609214454909701691[39] = 0;
   out_6609214454909701691[40] = 0;
   out_6609214454909701691[41] = 0;
   out_6609214454909701691[42] = 0;
   out_6609214454909701691[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6609214454909701691[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6609214454909701691[45] = 0;
   out_6609214454909701691[46] = 0;
   out_6609214454909701691[47] = 0;
   out_6609214454909701691[48] = 0;
   out_6609214454909701691[49] = 0;
   out_6609214454909701691[50] = 0;
   out_6609214454909701691[51] = 0;
   out_6609214454909701691[52] = 0;
   out_6609214454909701691[53] = 0;
   out_6609214454909701691[54] = 0;
   out_6609214454909701691[55] = 0;
   out_6609214454909701691[56] = 0;
   out_6609214454909701691[57] = 1;
   out_6609214454909701691[58] = 0;
   out_6609214454909701691[59] = 0;
   out_6609214454909701691[60] = 0;
   out_6609214454909701691[61] = 0;
   out_6609214454909701691[62] = 0;
   out_6609214454909701691[63] = 0;
   out_6609214454909701691[64] = 0;
   out_6609214454909701691[65] = 0;
   out_6609214454909701691[66] = dt;
   out_6609214454909701691[67] = 0;
   out_6609214454909701691[68] = 0;
   out_6609214454909701691[69] = 0;
   out_6609214454909701691[70] = 0;
   out_6609214454909701691[71] = 0;
   out_6609214454909701691[72] = 0;
   out_6609214454909701691[73] = 0;
   out_6609214454909701691[74] = 0;
   out_6609214454909701691[75] = 0;
   out_6609214454909701691[76] = 1;
   out_6609214454909701691[77] = 0;
   out_6609214454909701691[78] = 0;
   out_6609214454909701691[79] = 0;
   out_6609214454909701691[80] = 0;
   out_6609214454909701691[81] = 0;
   out_6609214454909701691[82] = 0;
   out_6609214454909701691[83] = 0;
   out_6609214454909701691[84] = 0;
   out_6609214454909701691[85] = dt;
   out_6609214454909701691[86] = 0;
   out_6609214454909701691[87] = 0;
   out_6609214454909701691[88] = 0;
   out_6609214454909701691[89] = 0;
   out_6609214454909701691[90] = 0;
   out_6609214454909701691[91] = 0;
   out_6609214454909701691[92] = 0;
   out_6609214454909701691[93] = 0;
   out_6609214454909701691[94] = 0;
   out_6609214454909701691[95] = 1;
   out_6609214454909701691[96] = 0;
   out_6609214454909701691[97] = 0;
   out_6609214454909701691[98] = 0;
   out_6609214454909701691[99] = 0;
   out_6609214454909701691[100] = 0;
   out_6609214454909701691[101] = 0;
   out_6609214454909701691[102] = 0;
   out_6609214454909701691[103] = 0;
   out_6609214454909701691[104] = dt;
   out_6609214454909701691[105] = 0;
   out_6609214454909701691[106] = 0;
   out_6609214454909701691[107] = 0;
   out_6609214454909701691[108] = 0;
   out_6609214454909701691[109] = 0;
   out_6609214454909701691[110] = 0;
   out_6609214454909701691[111] = 0;
   out_6609214454909701691[112] = 0;
   out_6609214454909701691[113] = 0;
   out_6609214454909701691[114] = 1;
   out_6609214454909701691[115] = 0;
   out_6609214454909701691[116] = 0;
   out_6609214454909701691[117] = 0;
   out_6609214454909701691[118] = 0;
   out_6609214454909701691[119] = 0;
   out_6609214454909701691[120] = 0;
   out_6609214454909701691[121] = 0;
   out_6609214454909701691[122] = 0;
   out_6609214454909701691[123] = 0;
   out_6609214454909701691[124] = 0;
   out_6609214454909701691[125] = 0;
   out_6609214454909701691[126] = 0;
   out_6609214454909701691[127] = 0;
   out_6609214454909701691[128] = 0;
   out_6609214454909701691[129] = 0;
   out_6609214454909701691[130] = 0;
   out_6609214454909701691[131] = 0;
   out_6609214454909701691[132] = 0;
   out_6609214454909701691[133] = 1;
   out_6609214454909701691[134] = 0;
   out_6609214454909701691[135] = 0;
   out_6609214454909701691[136] = 0;
   out_6609214454909701691[137] = 0;
   out_6609214454909701691[138] = 0;
   out_6609214454909701691[139] = 0;
   out_6609214454909701691[140] = 0;
   out_6609214454909701691[141] = 0;
   out_6609214454909701691[142] = 0;
   out_6609214454909701691[143] = 0;
   out_6609214454909701691[144] = 0;
   out_6609214454909701691[145] = 0;
   out_6609214454909701691[146] = 0;
   out_6609214454909701691[147] = 0;
   out_6609214454909701691[148] = 0;
   out_6609214454909701691[149] = 0;
   out_6609214454909701691[150] = 0;
   out_6609214454909701691[151] = 0;
   out_6609214454909701691[152] = 1;
   out_6609214454909701691[153] = 0;
   out_6609214454909701691[154] = 0;
   out_6609214454909701691[155] = 0;
   out_6609214454909701691[156] = 0;
   out_6609214454909701691[157] = 0;
   out_6609214454909701691[158] = 0;
   out_6609214454909701691[159] = 0;
   out_6609214454909701691[160] = 0;
   out_6609214454909701691[161] = 0;
   out_6609214454909701691[162] = 0;
   out_6609214454909701691[163] = 0;
   out_6609214454909701691[164] = 0;
   out_6609214454909701691[165] = 0;
   out_6609214454909701691[166] = 0;
   out_6609214454909701691[167] = 0;
   out_6609214454909701691[168] = 0;
   out_6609214454909701691[169] = 0;
   out_6609214454909701691[170] = 0;
   out_6609214454909701691[171] = 1;
   out_6609214454909701691[172] = 0;
   out_6609214454909701691[173] = 0;
   out_6609214454909701691[174] = 0;
   out_6609214454909701691[175] = 0;
   out_6609214454909701691[176] = 0;
   out_6609214454909701691[177] = 0;
   out_6609214454909701691[178] = 0;
   out_6609214454909701691[179] = 0;
   out_6609214454909701691[180] = 0;
   out_6609214454909701691[181] = 0;
   out_6609214454909701691[182] = 0;
   out_6609214454909701691[183] = 0;
   out_6609214454909701691[184] = 0;
   out_6609214454909701691[185] = 0;
   out_6609214454909701691[186] = 0;
   out_6609214454909701691[187] = 0;
   out_6609214454909701691[188] = 0;
   out_6609214454909701691[189] = 0;
   out_6609214454909701691[190] = 1;
   out_6609214454909701691[191] = 0;
   out_6609214454909701691[192] = 0;
   out_6609214454909701691[193] = 0;
   out_6609214454909701691[194] = 0;
   out_6609214454909701691[195] = 0;
   out_6609214454909701691[196] = 0;
   out_6609214454909701691[197] = 0;
   out_6609214454909701691[198] = 0;
   out_6609214454909701691[199] = 0;
   out_6609214454909701691[200] = 0;
   out_6609214454909701691[201] = 0;
   out_6609214454909701691[202] = 0;
   out_6609214454909701691[203] = 0;
   out_6609214454909701691[204] = 0;
   out_6609214454909701691[205] = 0;
   out_6609214454909701691[206] = 0;
   out_6609214454909701691[207] = 0;
   out_6609214454909701691[208] = 0;
   out_6609214454909701691[209] = 1;
   out_6609214454909701691[210] = 0;
   out_6609214454909701691[211] = 0;
   out_6609214454909701691[212] = 0;
   out_6609214454909701691[213] = 0;
   out_6609214454909701691[214] = 0;
   out_6609214454909701691[215] = 0;
   out_6609214454909701691[216] = 0;
   out_6609214454909701691[217] = 0;
   out_6609214454909701691[218] = 0;
   out_6609214454909701691[219] = 0;
   out_6609214454909701691[220] = 0;
   out_6609214454909701691[221] = 0;
   out_6609214454909701691[222] = 0;
   out_6609214454909701691[223] = 0;
   out_6609214454909701691[224] = 0;
   out_6609214454909701691[225] = 0;
   out_6609214454909701691[226] = 0;
   out_6609214454909701691[227] = 0;
   out_6609214454909701691[228] = 1;
   out_6609214454909701691[229] = 0;
   out_6609214454909701691[230] = 0;
   out_6609214454909701691[231] = 0;
   out_6609214454909701691[232] = 0;
   out_6609214454909701691[233] = 0;
   out_6609214454909701691[234] = 0;
   out_6609214454909701691[235] = 0;
   out_6609214454909701691[236] = 0;
   out_6609214454909701691[237] = 0;
   out_6609214454909701691[238] = 0;
   out_6609214454909701691[239] = 0;
   out_6609214454909701691[240] = 0;
   out_6609214454909701691[241] = 0;
   out_6609214454909701691[242] = 0;
   out_6609214454909701691[243] = 0;
   out_6609214454909701691[244] = 0;
   out_6609214454909701691[245] = 0;
   out_6609214454909701691[246] = 0;
   out_6609214454909701691[247] = 1;
   out_6609214454909701691[248] = 0;
   out_6609214454909701691[249] = 0;
   out_6609214454909701691[250] = 0;
   out_6609214454909701691[251] = 0;
   out_6609214454909701691[252] = 0;
   out_6609214454909701691[253] = 0;
   out_6609214454909701691[254] = 0;
   out_6609214454909701691[255] = 0;
   out_6609214454909701691[256] = 0;
   out_6609214454909701691[257] = 0;
   out_6609214454909701691[258] = 0;
   out_6609214454909701691[259] = 0;
   out_6609214454909701691[260] = 0;
   out_6609214454909701691[261] = 0;
   out_6609214454909701691[262] = 0;
   out_6609214454909701691[263] = 0;
   out_6609214454909701691[264] = 0;
   out_6609214454909701691[265] = 0;
   out_6609214454909701691[266] = 1;
   out_6609214454909701691[267] = 0;
   out_6609214454909701691[268] = 0;
   out_6609214454909701691[269] = 0;
   out_6609214454909701691[270] = 0;
   out_6609214454909701691[271] = 0;
   out_6609214454909701691[272] = 0;
   out_6609214454909701691[273] = 0;
   out_6609214454909701691[274] = 0;
   out_6609214454909701691[275] = 0;
   out_6609214454909701691[276] = 0;
   out_6609214454909701691[277] = 0;
   out_6609214454909701691[278] = 0;
   out_6609214454909701691[279] = 0;
   out_6609214454909701691[280] = 0;
   out_6609214454909701691[281] = 0;
   out_6609214454909701691[282] = 0;
   out_6609214454909701691[283] = 0;
   out_6609214454909701691[284] = 0;
   out_6609214454909701691[285] = 1;
   out_6609214454909701691[286] = 0;
   out_6609214454909701691[287] = 0;
   out_6609214454909701691[288] = 0;
   out_6609214454909701691[289] = 0;
   out_6609214454909701691[290] = 0;
   out_6609214454909701691[291] = 0;
   out_6609214454909701691[292] = 0;
   out_6609214454909701691[293] = 0;
   out_6609214454909701691[294] = 0;
   out_6609214454909701691[295] = 0;
   out_6609214454909701691[296] = 0;
   out_6609214454909701691[297] = 0;
   out_6609214454909701691[298] = 0;
   out_6609214454909701691[299] = 0;
   out_6609214454909701691[300] = 0;
   out_6609214454909701691[301] = 0;
   out_6609214454909701691[302] = 0;
   out_6609214454909701691[303] = 0;
   out_6609214454909701691[304] = 1;
   out_6609214454909701691[305] = 0;
   out_6609214454909701691[306] = 0;
   out_6609214454909701691[307] = 0;
   out_6609214454909701691[308] = 0;
   out_6609214454909701691[309] = 0;
   out_6609214454909701691[310] = 0;
   out_6609214454909701691[311] = 0;
   out_6609214454909701691[312] = 0;
   out_6609214454909701691[313] = 0;
   out_6609214454909701691[314] = 0;
   out_6609214454909701691[315] = 0;
   out_6609214454909701691[316] = 0;
   out_6609214454909701691[317] = 0;
   out_6609214454909701691[318] = 0;
   out_6609214454909701691[319] = 0;
   out_6609214454909701691[320] = 0;
   out_6609214454909701691[321] = 0;
   out_6609214454909701691[322] = 0;
   out_6609214454909701691[323] = 1;
}
void h_4(double *state, double *unused, double *out_3366909334215694695) {
   out_3366909334215694695[0] = state[6] + state[9];
   out_3366909334215694695[1] = state[7] + state[10];
   out_3366909334215694695[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8430955733371634042) {
   out_8430955733371634042[0] = 0;
   out_8430955733371634042[1] = 0;
   out_8430955733371634042[2] = 0;
   out_8430955733371634042[3] = 0;
   out_8430955733371634042[4] = 0;
   out_8430955733371634042[5] = 0;
   out_8430955733371634042[6] = 1;
   out_8430955733371634042[7] = 0;
   out_8430955733371634042[8] = 0;
   out_8430955733371634042[9] = 1;
   out_8430955733371634042[10] = 0;
   out_8430955733371634042[11] = 0;
   out_8430955733371634042[12] = 0;
   out_8430955733371634042[13] = 0;
   out_8430955733371634042[14] = 0;
   out_8430955733371634042[15] = 0;
   out_8430955733371634042[16] = 0;
   out_8430955733371634042[17] = 0;
   out_8430955733371634042[18] = 0;
   out_8430955733371634042[19] = 0;
   out_8430955733371634042[20] = 0;
   out_8430955733371634042[21] = 0;
   out_8430955733371634042[22] = 0;
   out_8430955733371634042[23] = 0;
   out_8430955733371634042[24] = 0;
   out_8430955733371634042[25] = 1;
   out_8430955733371634042[26] = 0;
   out_8430955733371634042[27] = 0;
   out_8430955733371634042[28] = 1;
   out_8430955733371634042[29] = 0;
   out_8430955733371634042[30] = 0;
   out_8430955733371634042[31] = 0;
   out_8430955733371634042[32] = 0;
   out_8430955733371634042[33] = 0;
   out_8430955733371634042[34] = 0;
   out_8430955733371634042[35] = 0;
   out_8430955733371634042[36] = 0;
   out_8430955733371634042[37] = 0;
   out_8430955733371634042[38] = 0;
   out_8430955733371634042[39] = 0;
   out_8430955733371634042[40] = 0;
   out_8430955733371634042[41] = 0;
   out_8430955733371634042[42] = 0;
   out_8430955733371634042[43] = 0;
   out_8430955733371634042[44] = 1;
   out_8430955733371634042[45] = 0;
   out_8430955733371634042[46] = 0;
   out_8430955733371634042[47] = 1;
   out_8430955733371634042[48] = 0;
   out_8430955733371634042[49] = 0;
   out_8430955733371634042[50] = 0;
   out_8430955733371634042[51] = 0;
   out_8430955733371634042[52] = 0;
   out_8430955733371634042[53] = 0;
}
void h_10(double *state, double *unused, double *out_4720353580216428160) {
   out_4720353580216428160[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4720353580216428160[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4720353580216428160[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4173229103338726482) {
   out_4173229103338726482[0] = 0;
   out_4173229103338726482[1] = 9.8100000000000005*cos(state[1]);
   out_4173229103338726482[2] = 0;
   out_4173229103338726482[3] = 0;
   out_4173229103338726482[4] = -state[8];
   out_4173229103338726482[5] = state[7];
   out_4173229103338726482[6] = 0;
   out_4173229103338726482[7] = state[5];
   out_4173229103338726482[8] = -state[4];
   out_4173229103338726482[9] = 0;
   out_4173229103338726482[10] = 0;
   out_4173229103338726482[11] = 0;
   out_4173229103338726482[12] = 1;
   out_4173229103338726482[13] = 0;
   out_4173229103338726482[14] = 0;
   out_4173229103338726482[15] = 1;
   out_4173229103338726482[16] = 0;
   out_4173229103338726482[17] = 0;
   out_4173229103338726482[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4173229103338726482[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4173229103338726482[20] = 0;
   out_4173229103338726482[21] = state[8];
   out_4173229103338726482[22] = 0;
   out_4173229103338726482[23] = -state[6];
   out_4173229103338726482[24] = -state[5];
   out_4173229103338726482[25] = 0;
   out_4173229103338726482[26] = state[3];
   out_4173229103338726482[27] = 0;
   out_4173229103338726482[28] = 0;
   out_4173229103338726482[29] = 0;
   out_4173229103338726482[30] = 0;
   out_4173229103338726482[31] = 1;
   out_4173229103338726482[32] = 0;
   out_4173229103338726482[33] = 0;
   out_4173229103338726482[34] = 1;
   out_4173229103338726482[35] = 0;
   out_4173229103338726482[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4173229103338726482[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4173229103338726482[38] = 0;
   out_4173229103338726482[39] = -state[7];
   out_4173229103338726482[40] = state[6];
   out_4173229103338726482[41] = 0;
   out_4173229103338726482[42] = state[4];
   out_4173229103338726482[43] = -state[3];
   out_4173229103338726482[44] = 0;
   out_4173229103338726482[45] = 0;
   out_4173229103338726482[46] = 0;
   out_4173229103338726482[47] = 0;
   out_4173229103338726482[48] = 0;
   out_4173229103338726482[49] = 0;
   out_4173229103338726482[50] = 1;
   out_4173229103338726482[51] = 0;
   out_4173229103338726482[52] = 0;
   out_4173229103338726482[53] = 1;
}
void h_13(double *state, double *unused, double *out_2154140950857846094) {
   out_2154140950857846094[0] = state[3];
   out_2154140950857846094[1] = state[4];
   out_2154140950857846094[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2405157132021216645) {
   out_2405157132021216645[0] = 0;
   out_2405157132021216645[1] = 0;
   out_2405157132021216645[2] = 0;
   out_2405157132021216645[3] = 1;
   out_2405157132021216645[4] = 0;
   out_2405157132021216645[5] = 0;
   out_2405157132021216645[6] = 0;
   out_2405157132021216645[7] = 0;
   out_2405157132021216645[8] = 0;
   out_2405157132021216645[9] = 0;
   out_2405157132021216645[10] = 0;
   out_2405157132021216645[11] = 0;
   out_2405157132021216645[12] = 0;
   out_2405157132021216645[13] = 0;
   out_2405157132021216645[14] = 0;
   out_2405157132021216645[15] = 0;
   out_2405157132021216645[16] = 0;
   out_2405157132021216645[17] = 0;
   out_2405157132021216645[18] = 0;
   out_2405157132021216645[19] = 0;
   out_2405157132021216645[20] = 0;
   out_2405157132021216645[21] = 0;
   out_2405157132021216645[22] = 1;
   out_2405157132021216645[23] = 0;
   out_2405157132021216645[24] = 0;
   out_2405157132021216645[25] = 0;
   out_2405157132021216645[26] = 0;
   out_2405157132021216645[27] = 0;
   out_2405157132021216645[28] = 0;
   out_2405157132021216645[29] = 0;
   out_2405157132021216645[30] = 0;
   out_2405157132021216645[31] = 0;
   out_2405157132021216645[32] = 0;
   out_2405157132021216645[33] = 0;
   out_2405157132021216645[34] = 0;
   out_2405157132021216645[35] = 0;
   out_2405157132021216645[36] = 0;
   out_2405157132021216645[37] = 0;
   out_2405157132021216645[38] = 0;
   out_2405157132021216645[39] = 0;
   out_2405157132021216645[40] = 0;
   out_2405157132021216645[41] = 1;
   out_2405157132021216645[42] = 0;
   out_2405157132021216645[43] = 0;
   out_2405157132021216645[44] = 0;
   out_2405157132021216645[45] = 0;
   out_2405157132021216645[46] = 0;
   out_2405157132021216645[47] = 0;
   out_2405157132021216645[48] = 0;
   out_2405157132021216645[49] = 0;
   out_2405157132021216645[50] = 0;
   out_2405157132021216645[51] = 0;
   out_2405157132021216645[52] = 0;
   out_2405157132021216645[53] = 0;
}
void h_14(double *state, double *unused, double *out_9066320572095185705) {
   out_9066320572095185705[0] = state[6];
   out_9066320572095185705[1] = state[7];
   out_9066320572095185705[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6052547483998433045) {
   out_6052547483998433045[0] = 0;
   out_6052547483998433045[1] = 0;
   out_6052547483998433045[2] = 0;
   out_6052547483998433045[3] = 0;
   out_6052547483998433045[4] = 0;
   out_6052547483998433045[5] = 0;
   out_6052547483998433045[6] = 1;
   out_6052547483998433045[7] = 0;
   out_6052547483998433045[8] = 0;
   out_6052547483998433045[9] = 0;
   out_6052547483998433045[10] = 0;
   out_6052547483998433045[11] = 0;
   out_6052547483998433045[12] = 0;
   out_6052547483998433045[13] = 0;
   out_6052547483998433045[14] = 0;
   out_6052547483998433045[15] = 0;
   out_6052547483998433045[16] = 0;
   out_6052547483998433045[17] = 0;
   out_6052547483998433045[18] = 0;
   out_6052547483998433045[19] = 0;
   out_6052547483998433045[20] = 0;
   out_6052547483998433045[21] = 0;
   out_6052547483998433045[22] = 0;
   out_6052547483998433045[23] = 0;
   out_6052547483998433045[24] = 0;
   out_6052547483998433045[25] = 1;
   out_6052547483998433045[26] = 0;
   out_6052547483998433045[27] = 0;
   out_6052547483998433045[28] = 0;
   out_6052547483998433045[29] = 0;
   out_6052547483998433045[30] = 0;
   out_6052547483998433045[31] = 0;
   out_6052547483998433045[32] = 0;
   out_6052547483998433045[33] = 0;
   out_6052547483998433045[34] = 0;
   out_6052547483998433045[35] = 0;
   out_6052547483998433045[36] = 0;
   out_6052547483998433045[37] = 0;
   out_6052547483998433045[38] = 0;
   out_6052547483998433045[39] = 0;
   out_6052547483998433045[40] = 0;
   out_6052547483998433045[41] = 0;
   out_6052547483998433045[42] = 0;
   out_6052547483998433045[43] = 0;
   out_6052547483998433045[44] = 1;
   out_6052547483998433045[45] = 0;
   out_6052547483998433045[46] = 0;
   out_6052547483998433045[47] = 0;
   out_6052547483998433045[48] = 0;
   out_6052547483998433045[49] = 0;
   out_6052547483998433045[50] = 0;
   out_6052547483998433045[51] = 0;
   out_6052547483998433045[52] = 0;
   out_6052547483998433045[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_3808871484533937584) {
  err_fun(nom_x, delta_x, out_3808871484533937584);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5966866822242435171) {
  inv_err_fun(nom_x, true_x, out_5966866822242435171);
}
void pose_H_mod_fun(double *state, double *out_8196089614431620713) {
  H_mod_fun(state, out_8196089614431620713);
}
void pose_f_fun(double *state, double dt, double *out_5274084714105371283) {
  f_fun(state,  dt, out_5274084714105371283);
}
void pose_F_fun(double *state, double dt, double *out_6609214454909701691) {
  F_fun(state,  dt, out_6609214454909701691);
}
void pose_h_4(double *state, double *unused, double *out_3366909334215694695) {
  h_4(state, unused, out_3366909334215694695);
}
void pose_H_4(double *state, double *unused, double *out_8430955733371634042) {
  H_4(state, unused, out_8430955733371634042);
}
void pose_h_10(double *state, double *unused, double *out_4720353580216428160) {
  h_10(state, unused, out_4720353580216428160);
}
void pose_H_10(double *state, double *unused, double *out_4173229103338726482) {
  H_10(state, unused, out_4173229103338726482);
}
void pose_h_13(double *state, double *unused, double *out_2154140950857846094) {
  h_13(state, unused, out_2154140950857846094);
}
void pose_H_13(double *state, double *unused, double *out_2405157132021216645) {
  H_13(state, unused, out_2405157132021216645);
}
void pose_h_14(double *state, double *unused, double *out_9066320572095185705) {
  h_14(state, unused, out_9066320572095185705);
}
void pose_H_14(double *state, double *unused, double *out_6052547483998433045) {
  H_14(state, unused, out_6052547483998433045);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
