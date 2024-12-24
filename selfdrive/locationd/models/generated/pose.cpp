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
void err_fun(double *nom_x, double *delta_x, double *out_7547269211206820042) {
   out_7547269211206820042[0] = delta_x[0] + nom_x[0];
   out_7547269211206820042[1] = delta_x[1] + nom_x[1];
   out_7547269211206820042[2] = delta_x[2] + nom_x[2];
   out_7547269211206820042[3] = delta_x[3] + nom_x[3];
   out_7547269211206820042[4] = delta_x[4] + nom_x[4];
   out_7547269211206820042[5] = delta_x[5] + nom_x[5];
   out_7547269211206820042[6] = delta_x[6] + nom_x[6];
   out_7547269211206820042[7] = delta_x[7] + nom_x[7];
   out_7547269211206820042[8] = delta_x[8] + nom_x[8];
   out_7547269211206820042[9] = delta_x[9] + nom_x[9];
   out_7547269211206820042[10] = delta_x[10] + nom_x[10];
   out_7547269211206820042[11] = delta_x[11] + nom_x[11];
   out_7547269211206820042[12] = delta_x[12] + nom_x[12];
   out_7547269211206820042[13] = delta_x[13] + nom_x[13];
   out_7547269211206820042[14] = delta_x[14] + nom_x[14];
   out_7547269211206820042[15] = delta_x[15] + nom_x[15];
   out_7547269211206820042[16] = delta_x[16] + nom_x[16];
   out_7547269211206820042[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6420366428061433715) {
   out_6420366428061433715[0] = -nom_x[0] + true_x[0];
   out_6420366428061433715[1] = -nom_x[1] + true_x[1];
   out_6420366428061433715[2] = -nom_x[2] + true_x[2];
   out_6420366428061433715[3] = -nom_x[3] + true_x[3];
   out_6420366428061433715[4] = -nom_x[4] + true_x[4];
   out_6420366428061433715[5] = -nom_x[5] + true_x[5];
   out_6420366428061433715[6] = -nom_x[6] + true_x[6];
   out_6420366428061433715[7] = -nom_x[7] + true_x[7];
   out_6420366428061433715[8] = -nom_x[8] + true_x[8];
   out_6420366428061433715[9] = -nom_x[9] + true_x[9];
   out_6420366428061433715[10] = -nom_x[10] + true_x[10];
   out_6420366428061433715[11] = -nom_x[11] + true_x[11];
   out_6420366428061433715[12] = -nom_x[12] + true_x[12];
   out_6420366428061433715[13] = -nom_x[13] + true_x[13];
   out_6420366428061433715[14] = -nom_x[14] + true_x[14];
   out_6420366428061433715[15] = -nom_x[15] + true_x[15];
   out_6420366428061433715[16] = -nom_x[16] + true_x[16];
   out_6420366428061433715[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_7812193377109128418) {
   out_7812193377109128418[0] = 1.0;
   out_7812193377109128418[1] = 0.0;
   out_7812193377109128418[2] = 0.0;
   out_7812193377109128418[3] = 0.0;
   out_7812193377109128418[4] = 0.0;
   out_7812193377109128418[5] = 0.0;
   out_7812193377109128418[6] = 0.0;
   out_7812193377109128418[7] = 0.0;
   out_7812193377109128418[8] = 0.0;
   out_7812193377109128418[9] = 0.0;
   out_7812193377109128418[10] = 0.0;
   out_7812193377109128418[11] = 0.0;
   out_7812193377109128418[12] = 0.0;
   out_7812193377109128418[13] = 0.0;
   out_7812193377109128418[14] = 0.0;
   out_7812193377109128418[15] = 0.0;
   out_7812193377109128418[16] = 0.0;
   out_7812193377109128418[17] = 0.0;
   out_7812193377109128418[18] = 0.0;
   out_7812193377109128418[19] = 1.0;
   out_7812193377109128418[20] = 0.0;
   out_7812193377109128418[21] = 0.0;
   out_7812193377109128418[22] = 0.0;
   out_7812193377109128418[23] = 0.0;
   out_7812193377109128418[24] = 0.0;
   out_7812193377109128418[25] = 0.0;
   out_7812193377109128418[26] = 0.0;
   out_7812193377109128418[27] = 0.0;
   out_7812193377109128418[28] = 0.0;
   out_7812193377109128418[29] = 0.0;
   out_7812193377109128418[30] = 0.0;
   out_7812193377109128418[31] = 0.0;
   out_7812193377109128418[32] = 0.0;
   out_7812193377109128418[33] = 0.0;
   out_7812193377109128418[34] = 0.0;
   out_7812193377109128418[35] = 0.0;
   out_7812193377109128418[36] = 0.0;
   out_7812193377109128418[37] = 0.0;
   out_7812193377109128418[38] = 1.0;
   out_7812193377109128418[39] = 0.0;
   out_7812193377109128418[40] = 0.0;
   out_7812193377109128418[41] = 0.0;
   out_7812193377109128418[42] = 0.0;
   out_7812193377109128418[43] = 0.0;
   out_7812193377109128418[44] = 0.0;
   out_7812193377109128418[45] = 0.0;
   out_7812193377109128418[46] = 0.0;
   out_7812193377109128418[47] = 0.0;
   out_7812193377109128418[48] = 0.0;
   out_7812193377109128418[49] = 0.0;
   out_7812193377109128418[50] = 0.0;
   out_7812193377109128418[51] = 0.0;
   out_7812193377109128418[52] = 0.0;
   out_7812193377109128418[53] = 0.0;
   out_7812193377109128418[54] = 0.0;
   out_7812193377109128418[55] = 0.0;
   out_7812193377109128418[56] = 0.0;
   out_7812193377109128418[57] = 1.0;
   out_7812193377109128418[58] = 0.0;
   out_7812193377109128418[59] = 0.0;
   out_7812193377109128418[60] = 0.0;
   out_7812193377109128418[61] = 0.0;
   out_7812193377109128418[62] = 0.0;
   out_7812193377109128418[63] = 0.0;
   out_7812193377109128418[64] = 0.0;
   out_7812193377109128418[65] = 0.0;
   out_7812193377109128418[66] = 0.0;
   out_7812193377109128418[67] = 0.0;
   out_7812193377109128418[68] = 0.0;
   out_7812193377109128418[69] = 0.0;
   out_7812193377109128418[70] = 0.0;
   out_7812193377109128418[71] = 0.0;
   out_7812193377109128418[72] = 0.0;
   out_7812193377109128418[73] = 0.0;
   out_7812193377109128418[74] = 0.0;
   out_7812193377109128418[75] = 0.0;
   out_7812193377109128418[76] = 1.0;
   out_7812193377109128418[77] = 0.0;
   out_7812193377109128418[78] = 0.0;
   out_7812193377109128418[79] = 0.0;
   out_7812193377109128418[80] = 0.0;
   out_7812193377109128418[81] = 0.0;
   out_7812193377109128418[82] = 0.0;
   out_7812193377109128418[83] = 0.0;
   out_7812193377109128418[84] = 0.0;
   out_7812193377109128418[85] = 0.0;
   out_7812193377109128418[86] = 0.0;
   out_7812193377109128418[87] = 0.0;
   out_7812193377109128418[88] = 0.0;
   out_7812193377109128418[89] = 0.0;
   out_7812193377109128418[90] = 0.0;
   out_7812193377109128418[91] = 0.0;
   out_7812193377109128418[92] = 0.0;
   out_7812193377109128418[93] = 0.0;
   out_7812193377109128418[94] = 0.0;
   out_7812193377109128418[95] = 1.0;
   out_7812193377109128418[96] = 0.0;
   out_7812193377109128418[97] = 0.0;
   out_7812193377109128418[98] = 0.0;
   out_7812193377109128418[99] = 0.0;
   out_7812193377109128418[100] = 0.0;
   out_7812193377109128418[101] = 0.0;
   out_7812193377109128418[102] = 0.0;
   out_7812193377109128418[103] = 0.0;
   out_7812193377109128418[104] = 0.0;
   out_7812193377109128418[105] = 0.0;
   out_7812193377109128418[106] = 0.0;
   out_7812193377109128418[107] = 0.0;
   out_7812193377109128418[108] = 0.0;
   out_7812193377109128418[109] = 0.0;
   out_7812193377109128418[110] = 0.0;
   out_7812193377109128418[111] = 0.0;
   out_7812193377109128418[112] = 0.0;
   out_7812193377109128418[113] = 0.0;
   out_7812193377109128418[114] = 1.0;
   out_7812193377109128418[115] = 0.0;
   out_7812193377109128418[116] = 0.0;
   out_7812193377109128418[117] = 0.0;
   out_7812193377109128418[118] = 0.0;
   out_7812193377109128418[119] = 0.0;
   out_7812193377109128418[120] = 0.0;
   out_7812193377109128418[121] = 0.0;
   out_7812193377109128418[122] = 0.0;
   out_7812193377109128418[123] = 0.0;
   out_7812193377109128418[124] = 0.0;
   out_7812193377109128418[125] = 0.0;
   out_7812193377109128418[126] = 0.0;
   out_7812193377109128418[127] = 0.0;
   out_7812193377109128418[128] = 0.0;
   out_7812193377109128418[129] = 0.0;
   out_7812193377109128418[130] = 0.0;
   out_7812193377109128418[131] = 0.0;
   out_7812193377109128418[132] = 0.0;
   out_7812193377109128418[133] = 1.0;
   out_7812193377109128418[134] = 0.0;
   out_7812193377109128418[135] = 0.0;
   out_7812193377109128418[136] = 0.0;
   out_7812193377109128418[137] = 0.0;
   out_7812193377109128418[138] = 0.0;
   out_7812193377109128418[139] = 0.0;
   out_7812193377109128418[140] = 0.0;
   out_7812193377109128418[141] = 0.0;
   out_7812193377109128418[142] = 0.0;
   out_7812193377109128418[143] = 0.0;
   out_7812193377109128418[144] = 0.0;
   out_7812193377109128418[145] = 0.0;
   out_7812193377109128418[146] = 0.0;
   out_7812193377109128418[147] = 0.0;
   out_7812193377109128418[148] = 0.0;
   out_7812193377109128418[149] = 0.0;
   out_7812193377109128418[150] = 0.0;
   out_7812193377109128418[151] = 0.0;
   out_7812193377109128418[152] = 1.0;
   out_7812193377109128418[153] = 0.0;
   out_7812193377109128418[154] = 0.0;
   out_7812193377109128418[155] = 0.0;
   out_7812193377109128418[156] = 0.0;
   out_7812193377109128418[157] = 0.0;
   out_7812193377109128418[158] = 0.0;
   out_7812193377109128418[159] = 0.0;
   out_7812193377109128418[160] = 0.0;
   out_7812193377109128418[161] = 0.0;
   out_7812193377109128418[162] = 0.0;
   out_7812193377109128418[163] = 0.0;
   out_7812193377109128418[164] = 0.0;
   out_7812193377109128418[165] = 0.0;
   out_7812193377109128418[166] = 0.0;
   out_7812193377109128418[167] = 0.0;
   out_7812193377109128418[168] = 0.0;
   out_7812193377109128418[169] = 0.0;
   out_7812193377109128418[170] = 0.0;
   out_7812193377109128418[171] = 1.0;
   out_7812193377109128418[172] = 0.0;
   out_7812193377109128418[173] = 0.0;
   out_7812193377109128418[174] = 0.0;
   out_7812193377109128418[175] = 0.0;
   out_7812193377109128418[176] = 0.0;
   out_7812193377109128418[177] = 0.0;
   out_7812193377109128418[178] = 0.0;
   out_7812193377109128418[179] = 0.0;
   out_7812193377109128418[180] = 0.0;
   out_7812193377109128418[181] = 0.0;
   out_7812193377109128418[182] = 0.0;
   out_7812193377109128418[183] = 0.0;
   out_7812193377109128418[184] = 0.0;
   out_7812193377109128418[185] = 0.0;
   out_7812193377109128418[186] = 0.0;
   out_7812193377109128418[187] = 0.0;
   out_7812193377109128418[188] = 0.0;
   out_7812193377109128418[189] = 0.0;
   out_7812193377109128418[190] = 1.0;
   out_7812193377109128418[191] = 0.0;
   out_7812193377109128418[192] = 0.0;
   out_7812193377109128418[193] = 0.0;
   out_7812193377109128418[194] = 0.0;
   out_7812193377109128418[195] = 0.0;
   out_7812193377109128418[196] = 0.0;
   out_7812193377109128418[197] = 0.0;
   out_7812193377109128418[198] = 0.0;
   out_7812193377109128418[199] = 0.0;
   out_7812193377109128418[200] = 0.0;
   out_7812193377109128418[201] = 0.0;
   out_7812193377109128418[202] = 0.0;
   out_7812193377109128418[203] = 0.0;
   out_7812193377109128418[204] = 0.0;
   out_7812193377109128418[205] = 0.0;
   out_7812193377109128418[206] = 0.0;
   out_7812193377109128418[207] = 0.0;
   out_7812193377109128418[208] = 0.0;
   out_7812193377109128418[209] = 1.0;
   out_7812193377109128418[210] = 0.0;
   out_7812193377109128418[211] = 0.0;
   out_7812193377109128418[212] = 0.0;
   out_7812193377109128418[213] = 0.0;
   out_7812193377109128418[214] = 0.0;
   out_7812193377109128418[215] = 0.0;
   out_7812193377109128418[216] = 0.0;
   out_7812193377109128418[217] = 0.0;
   out_7812193377109128418[218] = 0.0;
   out_7812193377109128418[219] = 0.0;
   out_7812193377109128418[220] = 0.0;
   out_7812193377109128418[221] = 0.0;
   out_7812193377109128418[222] = 0.0;
   out_7812193377109128418[223] = 0.0;
   out_7812193377109128418[224] = 0.0;
   out_7812193377109128418[225] = 0.0;
   out_7812193377109128418[226] = 0.0;
   out_7812193377109128418[227] = 0.0;
   out_7812193377109128418[228] = 1.0;
   out_7812193377109128418[229] = 0.0;
   out_7812193377109128418[230] = 0.0;
   out_7812193377109128418[231] = 0.0;
   out_7812193377109128418[232] = 0.0;
   out_7812193377109128418[233] = 0.0;
   out_7812193377109128418[234] = 0.0;
   out_7812193377109128418[235] = 0.0;
   out_7812193377109128418[236] = 0.0;
   out_7812193377109128418[237] = 0.0;
   out_7812193377109128418[238] = 0.0;
   out_7812193377109128418[239] = 0.0;
   out_7812193377109128418[240] = 0.0;
   out_7812193377109128418[241] = 0.0;
   out_7812193377109128418[242] = 0.0;
   out_7812193377109128418[243] = 0.0;
   out_7812193377109128418[244] = 0.0;
   out_7812193377109128418[245] = 0.0;
   out_7812193377109128418[246] = 0.0;
   out_7812193377109128418[247] = 1.0;
   out_7812193377109128418[248] = 0.0;
   out_7812193377109128418[249] = 0.0;
   out_7812193377109128418[250] = 0.0;
   out_7812193377109128418[251] = 0.0;
   out_7812193377109128418[252] = 0.0;
   out_7812193377109128418[253] = 0.0;
   out_7812193377109128418[254] = 0.0;
   out_7812193377109128418[255] = 0.0;
   out_7812193377109128418[256] = 0.0;
   out_7812193377109128418[257] = 0.0;
   out_7812193377109128418[258] = 0.0;
   out_7812193377109128418[259] = 0.0;
   out_7812193377109128418[260] = 0.0;
   out_7812193377109128418[261] = 0.0;
   out_7812193377109128418[262] = 0.0;
   out_7812193377109128418[263] = 0.0;
   out_7812193377109128418[264] = 0.0;
   out_7812193377109128418[265] = 0.0;
   out_7812193377109128418[266] = 1.0;
   out_7812193377109128418[267] = 0.0;
   out_7812193377109128418[268] = 0.0;
   out_7812193377109128418[269] = 0.0;
   out_7812193377109128418[270] = 0.0;
   out_7812193377109128418[271] = 0.0;
   out_7812193377109128418[272] = 0.0;
   out_7812193377109128418[273] = 0.0;
   out_7812193377109128418[274] = 0.0;
   out_7812193377109128418[275] = 0.0;
   out_7812193377109128418[276] = 0.0;
   out_7812193377109128418[277] = 0.0;
   out_7812193377109128418[278] = 0.0;
   out_7812193377109128418[279] = 0.0;
   out_7812193377109128418[280] = 0.0;
   out_7812193377109128418[281] = 0.0;
   out_7812193377109128418[282] = 0.0;
   out_7812193377109128418[283] = 0.0;
   out_7812193377109128418[284] = 0.0;
   out_7812193377109128418[285] = 1.0;
   out_7812193377109128418[286] = 0.0;
   out_7812193377109128418[287] = 0.0;
   out_7812193377109128418[288] = 0.0;
   out_7812193377109128418[289] = 0.0;
   out_7812193377109128418[290] = 0.0;
   out_7812193377109128418[291] = 0.0;
   out_7812193377109128418[292] = 0.0;
   out_7812193377109128418[293] = 0.0;
   out_7812193377109128418[294] = 0.0;
   out_7812193377109128418[295] = 0.0;
   out_7812193377109128418[296] = 0.0;
   out_7812193377109128418[297] = 0.0;
   out_7812193377109128418[298] = 0.0;
   out_7812193377109128418[299] = 0.0;
   out_7812193377109128418[300] = 0.0;
   out_7812193377109128418[301] = 0.0;
   out_7812193377109128418[302] = 0.0;
   out_7812193377109128418[303] = 0.0;
   out_7812193377109128418[304] = 1.0;
   out_7812193377109128418[305] = 0.0;
   out_7812193377109128418[306] = 0.0;
   out_7812193377109128418[307] = 0.0;
   out_7812193377109128418[308] = 0.0;
   out_7812193377109128418[309] = 0.0;
   out_7812193377109128418[310] = 0.0;
   out_7812193377109128418[311] = 0.0;
   out_7812193377109128418[312] = 0.0;
   out_7812193377109128418[313] = 0.0;
   out_7812193377109128418[314] = 0.0;
   out_7812193377109128418[315] = 0.0;
   out_7812193377109128418[316] = 0.0;
   out_7812193377109128418[317] = 0.0;
   out_7812193377109128418[318] = 0.0;
   out_7812193377109128418[319] = 0.0;
   out_7812193377109128418[320] = 0.0;
   out_7812193377109128418[321] = 0.0;
   out_7812193377109128418[322] = 0.0;
   out_7812193377109128418[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_1977748915209978600) {
   out_1977748915209978600[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_1977748915209978600[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_1977748915209978600[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_1977748915209978600[3] = dt*state[12] + state[3];
   out_1977748915209978600[4] = dt*state[13] + state[4];
   out_1977748915209978600[5] = dt*state[14] + state[5];
   out_1977748915209978600[6] = state[6];
   out_1977748915209978600[7] = state[7];
   out_1977748915209978600[8] = state[8];
   out_1977748915209978600[9] = state[9];
   out_1977748915209978600[10] = state[10];
   out_1977748915209978600[11] = state[11];
   out_1977748915209978600[12] = state[12];
   out_1977748915209978600[13] = state[13];
   out_1977748915209978600[14] = state[14];
   out_1977748915209978600[15] = state[15];
   out_1977748915209978600[16] = state[16];
   out_1977748915209978600[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2388978117553328468) {
   out_2388978117553328468[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2388978117553328468[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2388978117553328468[2] = 0;
   out_2388978117553328468[3] = 0;
   out_2388978117553328468[4] = 0;
   out_2388978117553328468[5] = 0;
   out_2388978117553328468[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2388978117553328468[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2388978117553328468[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2388978117553328468[9] = 0;
   out_2388978117553328468[10] = 0;
   out_2388978117553328468[11] = 0;
   out_2388978117553328468[12] = 0;
   out_2388978117553328468[13] = 0;
   out_2388978117553328468[14] = 0;
   out_2388978117553328468[15] = 0;
   out_2388978117553328468[16] = 0;
   out_2388978117553328468[17] = 0;
   out_2388978117553328468[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2388978117553328468[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2388978117553328468[20] = 0;
   out_2388978117553328468[21] = 0;
   out_2388978117553328468[22] = 0;
   out_2388978117553328468[23] = 0;
   out_2388978117553328468[24] = 0;
   out_2388978117553328468[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2388978117553328468[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2388978117553328468[27] = 0;
   out_2388978117553328468[28] = 0;
   out_2388978117553328468[29] = 0;
   out_2388978117553328468[30] = 0;
   out_2388978117553328468[31] = 0;
   out_2388978117553328468[32] = 0;
   out_2388978117553328468[33] = 0;
   out_2388978117553328468[34] = 0;
   out_2388978117553328468[35] = 0;
   out_2388978117553328468[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2388978117553328468[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2388978117553328468[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2388978117553328468[39] = 0;
   out_2388978117553328468[40] = 0;
   out_2388978117553328468[41] = 0;
   out_2388978117553328468[42] = 0;
   out_2388978117553328468[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2388978117553328468[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2388978117553328468[45] = 0;
   out_2388978117553328468[46] = 0;
   out_2388978117553328468[47] = 0;
   out_2388978117553328468[48] = 0;
   out_2388978117553328468[49] = 0;
   out_2388978117553328468[50] = 0;
   out_2388978117553328468[51] = 0;
   out_2388978117553328468[52] = 0;
   out_2388978117553328468[53] = 0;
   out_2388978117553328468[54] = 0;
   out_2388978117553328468[55] = 0;
   out_2388978117553328468[56] = 0;
   out_2388978117553328468[57] = 1;
   out_2388978117553328468[58] = 0;
   out_2388978117553328468[59] = 0;
   out_2388978117553328468[60] = 0;
   out_2388978117553328468[61] = 0;
   out_2388978117553328468[62] = 0;
   out_2388978117553328468[63] = 0;
   out_2388978117553328468[64] = 0;
   out_2388978117553328468[65] = 0;
   out_2388978117553328468[66] = dt;
   out_2388978117553328468[67] = 0;
   out_2388978117553328468[68] = 0;
   out_2388978117553328468[69] = 0;
   out_2388978117553328468[70] = 0;
   out_2388978117553328468[71] = 0;
   out_2388978117553328468[72] = 0;
   out_2388978117553328468[73] = 0;
   out_2388978117553328468[74] = 0;
   out_2388978117553328468[75] = 0;
   out_2388978117553328468[76] = 1;
   out_2388978117553328468[77] = 0;
   out_2388978117553328468[78] = 0;
   out_2388978117553328468[79] = 0;
   out_2388978117553328468[80] = 0;
   out_2388978117553328468[81] = 0;
   out_2388978117553328468[82] = 0;
   out_2388978117553328468[83] = 0;
   out_2388978117553328468[84] = 0;
   out_2388978117553328468[85] = dt;
   out_2388978117553328468[86] = 0;
   out_2388978117553328468[87] = 0;
   out_2388978117553328468[88] = 0;
   out_2388978117553328468[89] = 0;
   out_2388978117553328468[90] = 0;
   out_2388978117553328468[91] = 0;
   out_2388978117553328468[92] = 0;
   out_2388978117553328468[93] = 0;
   out_2388978117553328468[94] = 0;
   out_2388978117553328468[95] = 1;
   out_2388978117553328468[96] = 0;
   out_2388978117553328468[97] = 0;
   out_2388978117553328468[98] = 0;
   out_2388978117553328468[99] = 0;
   out_2388978117553328468[100] = 0;
   out_2388978117553328468[101] = 0;
   out_2388978117553328468[102] = 0;
   out_2388978117553328468[103] = 0;
   out_2388978117553328468[104] = dt;
   out_2388978117553328468[105] = 0;
   out_2388978117553328468[106] = 0;
   out_2388978117553328468[107] = 0;
   out_2388978117553328468[108] = 0;
   out_2388978117553328468[109] = 0;
   out_2388978117553328468[110] = 0;
   out_2388978117553328468[111] = 0;
   out_2388978117553328468[112] = 0;
   out_2388978117553328468[113] = 0;
   out_2388978117553328468[114] = 1;
   out_2388978117553328468[115] = 0;
   out_2388978117553328468[116] = 0;
   out_2388978117553328468[117] = 0;
   out_2388978117553328468[118] = 0;
   out_2388978117553328468[119] = 0;
   out_2388978117553328468[120] = 0;
   out_2388978117553328468[121] = 0;
   out_2388978117553328468[122] = 0;
   out_2388978117553328468[123] = 0;
   out_2388978117553328468[124] = 0;
   out_2388978117553328468[125] = 0;
   out_2388978117553328468[126] = 0;
   out_2388978117553328468[127] = 0;
   out_2388978117553328468[128] = 0;
   out_2388978117553328468[129] = 0;
   out_2388978117553328468[130] = 0;
   out_2388978117553328468[131] = 0;
   out_2388978117553328468[132] = 0;
   out_2388978117553328468[133] = 1;
   out_2388978117553328468[134] = 0;
   out_2388978117553328468[135] = 0;
   out_2388978117553328468[136] = 0;
   out_2388978117553328468[137] = 0;
   out_2388978117553328468[138] = 0;
   out_2388978117553328468[139] = 0;
   out_2388978117553328468[140] = 0;
   out_2388978117553328468[141] = 0;
   out_2388978117553328468[142] = 0;
   out_2388978117553328468[143] = 0;
   out_2388978117553328468[144] = 0;
   out_2388978117553328468[145] = 0;
   out_2388978117553328468[146] = 0;
   out_2388978117553328468[147] = 0;
   out_2388978117553328468[148] = 0;
   out_2388978117553328468[149] = 0;
   out_2388978117553328468[150] = 0;
   out_2388978117553328468[151] = 0;
   out_2388978117553328468[152] = 1;
   out_2388978117553328468[153] = 0;
   out_2388978117553328468[154] = 0;
   out_2388978117553328468[155] = 0;
   out_2388978117553328468[156] = 0;
   out_2388978117553328468[157] = 0;
   out_2388978117553328468[158] = 0;
   out_2388978117553328468[159] = 0;
   out_2388978117553328468[160] = 0;
   out_2388978117553328468[161] = 0;
   out_2388978117553328468[162] = 0;
   out_2388978117553328468[163] = 0;
   out_2388978117553328468[164] = 0;
   out_2388978117553328468[165] = 0;
   out_2388978117553328468[166] = 0;
   out_2388978117553328468[167] = 0;
   out_2388978117553328468[168] = 0;
   out_2388978117553328468[169] = 0;
   out_2388978117553328468[170] = 0;
   out_2388978117553328468[171] = 1;
   out_2388978117553328468[172] = 0;
   out_2388978117553328468[173] = 0;
   out_2388978117553328468[174] = 0;
   out_2388978117553328468[175] = 0;
   out_2388978117553328468[176] = 0;
   out_2388978117553328468[177] = 0;
   out_2388978117553328468[178] = 0;
   out_2388978117553328468[179] = 0;
   out_2388978117553328468[180] = 0;
   out_2388978117553328468[181] = 0;
   out_2388978117553328468[182] = 0;
   out_2388978117553328468[183] = 0;
   out_2388978117553328468[184] = 0;
   out_2388978117553328468[185] = 0;
   out_2388978117553328468[186] = 0;
   out_2388978117553328468[187] = 0;
   out_2388978117553328468[188] = 0;
   out_2388978117553328468[189] = 0;
   out_2388978117553328468[190] = 1;
   out_2388978117553328468[191] = 0;
   out_2388978117553328468[192] = 0;
   out_2388978117553328468[193] = 0;
   out_2388978117553328468[194] = 0;
   out_2388978117553328468[195] = 0;
   out_2388978117553328468[196] = 0;
   out_2388978117553328468[197] = 0;
   out_2388978117553328468[198] = 0;
   out_2388978117553328468[199] = 0;
   out_2388978117553328468[200] = 0;
   out_2388978117553328468[201] = 0;
   out_2388978117553328468[202] = 0;
   out_2388978117553328468[203] = 0;
   out_2388978117553328468[204] = 0;
   out_2388978117553328468[205] = 0;
   out_2388978117553328468[206] = 0;
   out_2388978117553328468[207] = 0;
   out_2388978117553328468[208] = 0;
   out_2388978117553328468[209] = 1;
   out_2388978117553328468[210] = 0;
   out_2388978117553328468[211] = 0;
   out_2388978117553328468[212] = 0;
   out_2388978117553328468[213] = 0;
   out_2388978117553328468[214] = 0;
   out_2388978117553328468[215] = 0;
   out_2388978117553328468[216] = 0;
   out_2388978117553328468[217] = 0;
   out_2388978117553328468[218] = 0;
   out_2388978117553328468[219] = 0;
   out_2388978117553328468[220] = 0;
   out_2388978117553328468[221] = 0;
   out_2388978117553328468[222] = 0;
   out_2388978117553328468[223] = 0;
   out_2388978117553328468[224] = 0;
   out_2388978117553328468[225] = 0;
   out_2388978117553328468[226] = 0;
   out_2388978117553328468[227] = 0;
   out_2388978117553328468[228] = 1;
   out_2388978117553328468[229] = 0;
   out_2388978117553328468[230] = 0;
   out_2388978117553328468[231] = 0;
   out_2388978117553328468[232] = 0;
   out_2388978117553328468[233] = 0;
   out_2388978117553328468[234] = 0;
   out_2388978117553328468[235] = 0;
   out_2388978117553328468[236] = 0;
   out_2388978117553328468[237] = 0;
   out_2388978117553328468[238] = 0;
   out_2388978117553328468[239] = 0;
   out_2388978117553328468[240] = 0;
   out_2388978117553328468[241] = 0;
   out_2388978117553328468[242] = 0;
   out_2388978117553328468[243] = 0;
   out_2388978117553328468[244] = 0;
   out_2388978117553328468[245] = 0;
   out_2388978117553328468[246] = 0;
   out_2388978117553328468[247] = 1;
   out_2388978117553328468[248] = 0;
   out_2388978117553328468[249] = 0;
   out_2388978117553328468[250] = 0;
   out_2388978117553328468[251] = 0;
   out_2388978117553328468[252] = 0;
   out_2388978117553328468[253] = 0;
   out_2388978117553328468[254] = 0;
   out_2388978117553328468[255] = 0;
   out_2388978117553328468[256] = 0;
   out_2388978117553328468[257] = 0;
   out_2388978117553328468[258] = 0;
   out_2388978117553328468[259] = 0;
   out_2388978117553328468[260] = 0;
   out_2388978117553328468[261] = 0;
   out_2388978117553328468[262] = 0;
   out_2388978117553328468[263] = 0;
   out_2388978117553328468[264] = 0;
   out_2388978117553328468[265] = 0;
   out_2388978117553328468[266] = 1;
   out_2388978117553328468[267] = 0;
   out_2388978117553328468[268] = 0;
   out_2388978117553328468[269] = 0;
   out_2388978117553328468[270] = 0;
   out_2388978117553328468[271] = 0;
   out_2388978117553328468[272] = 0;
   out_2388978117553328468[273] = 0;
   out_2388978117553328468[274] = 0;
   out_2388978117553328468[275] = 0;
   out_2388978117553328468[276] = 0;
   out_2388978117553328468[277] = 0;
   out_2388978117553328468[278] = 0;
   out_2388978117553328468[279] = 0;
   out_2388978117553328468[280] = 0;
   out_2388978117553328468[281] = 0;
   out_2388978117553328468[282] = 0;
   out_2388978117553328468[283] = 0;
   out_2388978117553328468[284] = 0;
   out_2388978117553328468[285] = 1;
   out_2388978117553328468[286] = 0;
   out_2388978117553328468[287] = 0;
   out_2388978117553328468[288] = 0;
   out_2388978117553328468[289] = 0;
   out_2388978117553328468[290] = 0;
   out_2388978117553328468[291] = 0;
   out_2388978117553328468[292] = 0;
   out_2388978117553328468[293] = 0;
   out_2388978117553328468[294] = 0;
   out_2388978117553328468[295] = 0;
   out_2388978117553328468[296] = 0;
   out_2388978117553328468[297] = 0;
   out_2388978117553328468[298] = 0;
   out_2388978117553328468[299] = 0;
   out_2388978117553328468[300] = 0;
   out_2388978117553328468[301] = 0;
   out_2388978117553328468[302] = 0;
   out_2388978117553328468[303] = 0;
   out_2388978117553328468[304] = 1;
   out_2388978117553328468[305] = 0;
   out_2388978117553328468[306] = 0;
   out_2388978117553328468[307] = 0;
   out_2388978117553328468[308] = 0;
   out_2388978117553328468[309] = 0;
   out_2388978117553328468[310] = 0;
   out_2388978117553328468[311] = 0;
   out_2388978117553328468[312] = 0;
   out_2388978117553328468[313] = 0;
   out_2388978117553328468[314] = 0;
   out_2388978117553328468[315] = 0;
   out_2388978117553328468[316] = 0;
   out_2388978117553328468[317] = 0;
   out_2388978117553328468[318] = 0;
   out_2388978117553328468[319] = 0;
   out_2388978117553328468[320] = 0;
   out_2388978117553328468[321] = 0;
   out_2388978117553328468[322] = 0;
   out_2388978117553328468[323] = 1;
}
void h_4(double *state, double *unused, double *out_1855587536956700071) {
   out_1855587536956700071[0] = state[6] + state[9];
   out_1855587536956700071[1] = state[7] + state[10];
   out_1855587536956700071[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_9010140858992026522) {
   out_9010140858992026522[0] = 0;
   out_9010140858992026522[1] = 0;
   out_9010140858992026522[2] = 0;
   out_9010140858992026522[3] = 0;
   out_9010140858992026522[4] = 0;
   out_9010140858992026522[5] = 0;
   out_9010140858992026522[6] = 1;
   out_9010140858992026522[7] = 0;
   out_9010140858992026522[8] = 0;
   out_9010140858992026522[9] = 1;
   out_9010140858992026522[10] = 0;
   out_9010140858992026522[11] = 0;
   out_9010140858992026522[12] = 0;
   out_9010140858992026522[13] = 0;
   out_9010140858992026522[14] = 0;
   out_9010140858992026522[15] = 0;
   out_9010140858992026522[16] = 0;
   out_9010140858992026522[17] = 0;
   out_9010140858992026522[18] = 0;
   out_9010140858992026522[19] = 0;
   out_9010140858992026522[20] = 0;
   out_9010140858992026522[21] = 0;
   out_9010140858992026522[22] = 0;
   out_9010140858992026522[23] = 0;
   out_9010140858992026522[24] = 0;
   out_9010140858992026522[25] = 1;
   out_9010140858992026522[26] = 0;
   out_9010140858992026522[27] = 0;
   out_9010140858992026522[28] = 1;
   out_9010140858992026522[29] = 0;
   out_9010140858992026522[30] = 0;
   out_9010140858992026522[31] = 0;
   out_9010140858992026522[32] = 0;
   out_9010140858992026522[33] = 0;
   out_9010140858992026522[34] = 0;
   out_9010140858992026522[35] = 0;
   out_9010140858992026522[36] = 0;
   out_9010140858992026522[37] = 0;
   out_9010140858992026522[38] = 0;
   out_9010140858992026522[39] = 0;
   out_9010140858992026522[40] = 0;
   out_9010140858992026522[41] = 0;
   out_9010140858992026522[42] = 0;
   out_9010140858992026522[43] = 0;
   out_9010140858992026522[44] = 1;
   out_9010140858992026522[45] = 0;
   out_9010140858992026522[46] = 0;
   out_9010140858992026522[47] = 1;
   out_9010140858992026522[48] = 0;
   out_9010140858992026522[49] = 0;
   out_9010140858992026522[50] = 0;
   out_9010140858992026522[51] = 0;
   out_9010140858992026522[52] = 0;
   out_9010140858992026522[53] = 0;
}
void h_10(double *state, double *unused, double *out_8454914287904169316) {
   out_8454914287904169316[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_8454914287904169316[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_8454914287904169316[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4142937433250982486) {
   out_4142937433250982486[0] = 0;
   out_4142937433250982486[1] = 9.8100000000000005*cos(state[1]);
   out_4142937433250982486[2] = 0;
   out_4142937433250982486[3] = 0;
   out_4142937433250982486[4] = -state[8];
   out_4142937433250982486[5] = state[7];
   out_4142937433250982486[6] = 0;
   out_4142937433250982486[7] = state[5];
   out_4142937433250982486[8] = -state[4];
   out_4142937433250982486[9] = 0;
   out_4142937433250982486[10] = 0;
   out_4142937433250982486[11] = 0;
   out_4142937433250982486[12] = 1;
   out_4142937433250982486[13] = 0;
   out_4142937433250982486[14] = 0;
   out_4142937433250982486[15] = 1;
   out_4142937433250982486[16] = 0;
   out_4142937433250982486[17] = 0;
   out_4142937433250982486[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4142937433250982486[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4142937433250982486[20] = 0;
   out_4142937433250982486[21] = state[8];
   out_4142937433250982486[22] = 0;
   out_4142937433250982486[23] = -state[6];
   out_4142937433250982486[24] = -state[5];
   out_4142937433250982486[25] = 0;
   out_4142937433250982486[26] = state[3];
   out_4142937433250982486[27] = 0;
   out_4142937433250982486[28] = 0;
   out_4142937433250982486[29] = 0;
   out_4142937433250982486[30] = 0;
   out_4142937433250982486[31] = 1;
   out_4142937433250982486[32] = 0;
   out_4142937433250982486[33] = 0;
   out_4142937433250982486[34] = 1;
   out_4142937433250982486[35] = 0;
   out_4142937433250982486[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4142937433250982486[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4142937433250982486[38] = 0;
   out_4142937433250982486[39] = -state[7];
   out_4142937433250982486[40] = state[6];
   out_4142937433250982486[41] = 0;
   out_4142937433250982486[42] = state[4];
   out_4142937433250982486[43] = -state[3];
   out_4142937433250982486[44] = 0;
   out_4142937433250982486[45] = 0;
   out_4142937433250982486[46] = 0;
   out_4142937433250982486[47] = 0;
   out_4142937433250982486[48] = 0;
   out_4142937433250982486[49] = 0;
   out_4142937433250982486[50] = 1;
   out_4142937433250982486[51] = 0;
   out_4142937433250982486[52] = 0;
   out_4142937433250982486[53] = 1;
}
void h_13(double *state, double *unused, double *out_7515033349393404962) {
   out_7515033349393404962[0] = state[3];
   out_7515033349393404962[1] = state[4];
   out_7515033349393404962[2] = state[5];
}
void H_13(double *state, double *unused, double *out_6224329389385192293) {
   out_6224329389385192293[0] = 0;
   out_6224329389385192293[1] = 0;
   out_6224329389385192293[2] = 0;
   out_6224329389385192293[3] = 1;
   out_6224329389385192293[4] = 0;
   out_6224329389385192293[5] = 0;
   out_6224329389385192293[6] = 0;
   out_6224329389385192293[7] = 0;
   out_6224329389385192293[8] = 0;
   out_6224329389385192293[9] = 0;
   out_6224329389385192293[10] = 0;
   out_6224329389385192293[11] = 0;
   out_6224329389385192293[12] = 0;
   out_6224329389385192293[13] = 0;
   out_6224329389385192293[14] = 0;
   out_6224329389385192293[15] = 0;
   out_6224329389385192293[16] = 0;
   out_6224329389385192293[17] = 0;
   out_6224329389385192293[18] = 0;
   out_6224329389385192293[19] = 0;
   out_6224329389385192293[20] = 0;
   out_6224329389385192293[21] = 0;
   out_6224329389385192293[22] = 1;
   out_6224329389385192293[23] = 0;
   out_6224329389385192293[24] = 0;
   out_6224329389385192293[25] = 0;
   out_6224329389385192293[26] = 0;
   out_6224329389385192293[27] = 0;
   out_6224329389385192293[28] = 0;
   out_6224329389385192293[29] = 0;
   out_6224329389385192293[30] = 0;
   out_6224329389385192293[31] = 0;
   out_6224329389385192293[32] = 0;
   out_6224329389385192293[33] = 0;
   out_6224329389385192293[34] = 0;
   out_6224329389385192293[35] = 0;
   out_6224329389385192293[36] = 0;
   out_6224329389385192293[37] = 0;
   out_6224329389385192293[38] = 0;
   out_6224329389385192293[39] = 0;
   out_6224329389385192293[40] = 0;
   out_6224329389385192293[41] = 1;
   out_6224329389385192293[42] = 0;
   out_6224329389385192293[43] = 0;
   out_6224329389385192293[44] = 0;
   out_6224329389385192293[45] = 0;
   out_6224329389385192293[46] = 0;
   out_6224329389385192293[47] = 0;
   out_6224329389385192293[48] = 0;
   out_6224329389385192293[49] = 0;
   out_6224329389385192293[50] = 0;
   out_6224329389385192293[51] = 0;
   out_6224329389385192293[52] = 0;
   out_6224329389385192293[53] = 0;
}
void h_14(double *state, double *unused, double *out_3054229621894193800) {
   out_3054229621894193800[0] = state[6];
   out_3054229621894193800[1] = state[7];
   out_3054229621894193800[2] = state[8];
}
void H_14(double *state, double *unused, double *out_5473362358378040565) {
   out_5473362358378040565[0] = 0;
   out_5473362358378040565[1] = 0;
   out_5473362358378040565[2] = 0;
   out_5473362358378040565[3] = 0;
   out_5473362358378040565[4] = 0;
   out_5473362358378040565[5] = 0;
   out_5473362358378040565[6] = 1;
   out_5473362358378040565[7] = 0;
   out_5473362358378040565[8] = 0;
   out_5473362358378040565[9] = 0;
   out_5473362358378040565[10] = 0;
   out_5473362358378040565[11] = 0;
   out_5473362358378040565[12] = 0;
   out_5473362358378040565[13] = 0;
   out_5473362358378040565[14] = 0;
   out_5473362358378040565[15] = 0;
   out_5473362358378040565[16] = 0;
   out_5473362358378040565[17] = 0;
   out_5473362358378040565[18] = 0;
   out_5473362358378040565[19] = 0;
   out_5473362358378040565[20] = 0;
   out_5473362358378040565[21] = 0;
   out_5473362358378040565[22] = 0;
   out_5473362358378040565[23] = 0;
   out_5473362358378040565[24] = 0;
   out_5473362358378040565[25] = 1;
   out_5473362358378040565[26] = 0;
   out_5473362358378040565[27] = 0;
   out_5473362358378040565[28] = 0;
   out_5473362358378040565[29] = 0;
   out_5473362358378040565[30] = 0;
   out_5473362358378040565[31] = 0;
   out_5473362358378040565[32] = 0;
   out_5473362358378040565[33] = 0;
   out_5473362358378040565[34] = 0;
   out_5473362358378040565[35] = 0;
   out_5473362358378040565[36] = 0;
   out_5473362358378040565[37] = 0;
   out_5473362358378040565[38] = 0;
   out_5473362358378040565[39] = 0;
   out_5473362358378040565[40] = 0;
   out_5473362358378040565[41] = 0;
   out_5473362358378040565[42] = 0;
   out_5473362358378040565[43] = 0;
   out_5473362358378040565[44] = 1;
   out_5473362358378040565[45] = 0;
   out_5473362358378040565[46] = 0;
   out_5473362358378040565[47] = 0;
   out_5473362358378040565[48] = 0;
   out_5473362358378040565[49] = 0;
   out_5473362358378040565[50] = 0;
   out_5473362358378040565[51] = 0;
   out_5473362358378040565[52] = 0;
   out_5473362358378040565[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_7547269211206820042) {
  err_fun(nom_x, delta_x, out_7547269211206820042);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6420366428061433715) {
  inv_err_fun(nom_x, true_x, out_6420366428061433715);
}
void pose_H_mod_fun(double *state, double *out_7812193377109128418) {
  H_mod_fun(state, out_7812193377109128418);
}
void pose_f_fun(double *state, double dt, double *out_1977748915209978600) {
  f_fun(state,  dt, out_1977748915209978600);
}
void pose_F_fun(double *state, double dt, double *out_2388978117553328468) {
  F_fun(state,  dt, out_2388978117553328468);
}
void pose_h_4(double *state, double *unused, double *out_1855587536956700071) {
  h_4(state, unused, out_1855587536956700071);
}
void pose_H_4(double *state, double *unused, double *out_9010140858992026522) {
  H_4(state, unused, out_9010140858992026522);
}
void pose_h_10(double *state, double *unused, double *out_8454914287904169316) {
  h_10(state, unused, out_8454914287904169316);
}
void pose_H_10(double *state, double *unused, double *out_4142937433250982486) {
  H_10(state, unused, out_4142937433250982486);
}
void pose_h_13(double *state, double *unused, double *out_7515033349393404962) {
  h_13(state, unused, out_7515033349393404962);
}
void pose_H_13(double *state, double *unused, double *out_6224329389385192293) {
  H_13(state, unused, out_6224329389385192293);
}
void pose_h_14(double *state, double *unused, double *out_3054229621894193800) {
  h_14(state, unused, out_3054229621894193800);
}
void pose_H_14(double *state, double *unused, double *out_5473362358378040565) {
  H_14(state, unused, out_5473362358378040565);
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
