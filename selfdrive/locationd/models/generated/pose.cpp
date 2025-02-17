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
void err_fun(double *nom_x, double *delta_x, double *out_4117449312389212167) {
   out_4117449312389212167[0] = delta_x[0] + nom_x[0];
   out_4117449312389212167[1] = delta_x[1] + nom_x[1];
   out_4117449312389212167[2] = delta_x[2] + nom_x[2];
   out_4117449312389212167[3] = delta_x[3] + nom_x[3];
   out_4117449312389212167[4] = delta_x[4] + nom_x[4];
   out_4117449312389212167[5] = delta_x[5] + nom_x[5];
   out_4117449312389212167[6] = delta_x[6] + nom_x[6];
   out_4117449312389212167[7] = delta_x[7] + nom_x[7];
   out_4117449312389212167[8] = delta_x[8] + nom_x[8];
   out_4117449312389212167[9] = delta_x[9] + nom_x[9];
   out_4117449312389212167[10] = delta_x[10] + nom_x[10];
   out_4117449312389212167[11] = delta_x[11] + nom_x[11];
   out_4117449312389212167[12] = delta_x[12] + nom_x[12];
   out_4117449312389212167[13] = delta_x[13] + nom_x[13];
   out_4117449312389212167[14] = delta_x[14] + nom_x[14];
   out_4117449312389212167[15] = delta_x[15] + nom_x[15];
   out_4117449312389212167[16] = delta_x[16] + nom_x[16];
   out_4117449312389212167[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2619781936850820050) {
   out_2619781936850820050[0] = -nom_x[0] + true_x[0];
   out_2619781936850820050[1] = -nom_x[1] + true_x[1];
   out_2619781936850820050[2] = -nom_x[2] + true_x[2];
   out_2619781936850820050[3] = -nom_x[3] + true_x[3];
   out_2619781936850820050[4] = -nom_x[4] + true_x[4];
   out_2619781936850820050[5] = -nom_x[5] + true_x[5];
   out_2619781936850820050[6] = -nom_x[6] + true_x[6];
   out_2619781936850820050[7] = -nom_x[7] + true_x[7];
   out_2619781936850820050[8] = -nom_x[8] + true_x[8];
   out_2619781936850820050[9] = -nom_x[9] + true_x[9];
   out_2619781936850820050[10] = -nom_x[10] + true_x[10];
   out_2619781936850820050[11] = -nom_x[11] + true_x[11];
   out_2619781936850820050[12] = -nom_x[12] + true_x[12];
   out_2619781936850820050[13] = -nom_x[13] + true_x[13];
   out_2619781936850820050[14] = -nom_x[14] + true_x[14];
   out_2619781936850820050[15] = -nom_x[15] + true_x[15];
   out_2619781936850820050[16] = -nom_x[16] + true_x[16];
   out_2619781936850820050[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_7078650365136719116) {
   out_7078650365136719116[0] = 1.0;
   out_7078650365136719116[1] = 0.0;
   out_7078650365136719116[2] = 0.0;
   out_7078650365136719116[3] = 0.0;
   out_7078650365136719116[4] = 0.0;
   out_7078650365136719116[5] = 0.0;
   out_7078650365136719116[6] = 0.0;
   out_7078650365136719116[7] = 0.0;
   out_7078650365136719116[8] = 0.0;
   out_7078650365136719116[9] = 0.0;
   out_7078650365136719116[10] = 0.0;
   out_7078650365136719116[11] = 0.0;
   out_7078650365136719116[12] = 0.0;
   out_7078650365136719116[13] = 0.0;
   out_7078650365136719116[14] = 0.0;
   out_7078650365136719116[15] = 0.0;
   out_7078650365136719116[16] = 0.0;
   out_7078650365136719116[17] = 0.0;
   out_7078650365136719116[18] = 0.0;
   out_7078650365136719116[19] = 1.0;
   out_7078650365136719116[20] = 0.0;
   out_7078650365136719116[21] = 0.0;
   out_7078650365136719116[22] = 0.0;
   out_7078650365136719116[23] = 0.0;
   out_7078650365136719116[24] = 0.0;
   out_7078650365136719116[25] = 0.0;
   out_7078650365136719116[26] = 0.0;
   out_7078650365136719116[27] = 0.0;
   out_7078650365136719116[28] = 0.0;
   out_7078650365136719116[29] = 0.0;
   out_7078650365136719116[30] = 0.0;
   out_7078650365136719116[31] = 0.0;
   out_7078650365136719116[32] = 0.0;
   out_7078650365136719116[33] = 0.0;
   out_7078650365136719116[34] = 0.0;
   out_7078650365136719116[35] = 0.0;
   out_7078650365136719116[36] = 0.0;
   out_7078650365136719116[37] = 0.0;
   out_7078650365136719116[38] = 1.0;
   out_7078650365136719116[39] = 0.0;
   out_7078650365136719116[40] = 0.0;
   out_7078650365136719116[41] = 0.0;
   out_7078650365136719116[42] = 0.0;
   out_7078650365136719116[43] = 0.0;
   out_7078650365136719116[44] = 0.0;
   out_7078650365136719116[45] = 0.0;
   out_7078650365136719116[46] = 0.0;
   out_7078650365136719116[47] = 0.0;
   out_7078650365136719116[48] = 0.0;
   out_7078650365136719116[49] = 0.0;
   out_7078650365136719116[50] = 0.0;
   out_7078650365136719116[51] = 0.0;
   out_7078650365136719116[52] = 0.0;
   out_7078650365136719116[53] = 0.0;
   out_7078650365136719116[54] = 0.0;
   out_7078650365136719116[55] = 0.0;
   out_7078650365136719116[56] = 0.0;
   out_7078650365136719116[57] = 1.0;
   out_7078650365136719116[58] = 0.0;
   out_7078650365136719116[59] = 0.0;
   out_7078650365136719116[60] = 0.0;
   out_7078650365136719116[61] = 0.0;
   out_7078650365136719116[62] = 0.0;
   out_7078650365136719116[63] = 0.0;
   out_7078650365136719116[64] = 0.0;
   out_7078650365136719116[65] = 0.0;
   out_7078650365136719116[66] = 0.0;
   out_7078650365136719116[67] = 0.0;
   out_7078650365136719116[68] = 0.0;
   out_7078650365136719116[69] = 0.0;
   out_7078650365136719116[70] = 0.0;
   out_7078650365136719116[71] = 0.0;
   out_7078650365136719116[72] = 0.0;
   out_7078650365136719116[73] = 0.0;
   out_7078650365136719116[74] = 0.0;
   out_7078650365136719116[75] = 0.0;
   out_7078650365136719116[76] = 1.0;
   out_7078650365136719116[77] = 0.0;
   out_7078650365136719116[78] = 0.0;
   out_7078650365136719116[79] = 0.0;
   out_7078650365136719116[80] = 0.0;
   out_7078650365136719116[81] = 0.0;
   out_7078650365136719116[82] = 0.0;
   out_7078650365136719116[83] = 0.0;
   out_7078650365136719116[84] = 0.0;
   out_7078650365136719116[85] = 0.0;
   out_7078650365136719116[86] = 0.0;
   out_7078650365136719116[87] = 0.0;
   out_7078650365136719116[88] = 0.0;
   out_7078650365136719116[89] = 0.0;
   out_7078650365136719116[90] = 0.0;
   out_7078650365136719116[91] = 0.0;
   out_7078650365136719116[92] = 0.0;
   out_7078650365136719116[93] = 0.0;
   out_7078650365136719116[94] = 0.0;
   out_7078650365136719116[95] = 1.0;
   out_7078650365136719116[96] = 0.0;
   out_7078650365136719116[97] = 0.0;
   out_7078650365136719116[98] = 0.0;
   out_7078650365136719116[99] = 0.0;
   out_7078650365136719116[100] = 0.0;
   out_7078650365136719116[101] = 0.0;
   out_7078650365136719116[102] = 0.0;
   out_7078650365136719116[103] = 0.0;
   out_7078650365136719116[104] = 0.0;
   out_7078650365136719116[105] = 0.0;
   out_7078650365136719116[106] = 0.0;
   out_7078650365136719116[107] = 0.0;
   out_7078650365136719116[108] = 0.0;
   out_7078650365136719116[109] = 0.0;
   out_7078650365136719116[110] = 0.0;
   out_7078650365136719116[111] = 0.0;
   out_7078650365136719116[112] = 0.0;
   out_7078650365136719116[113] = 0.0;
   out_7078650365136719116[114] = 1.0;
   out_7078650365136719116[115] = 0.0;
   out_7078650365136719116[116] = 0.0;
   out_7078650365136719116[117] = 0.0;
   out_7078650365136719116[118] = 0.0;
   out_7078650365136719116[119] = 0.0;
   out_7078650365136719116[120] = 0.0;
   out_7078650365136719116[121] = 0.0;
   out_7078650365136719116[122] = 0.0;
   out_7078650365136719116[123] = 0.0;
   out_7078650365136719116[124] = 0.0;
   out_7078650365136719116[125] = 0.0;
   out_7078650365136719116[126] = 0.0;
   out_7078650365136719116[127] = 0.0;
   out_7078650365136719116[128] = 0.0;
   out_7078650365136719116[129] = 0.0;
   out_7078650365136719116[130] = 0.0;
   out_7078650365136719116[131] = 0.0;
   out_7078650365136719116[132] = 0.0;
   out_7078650365136719116[133] = 1.0;
   out_7078650365136719116[134] = 0.0;
   out_7078650365136719116[135] = 0.0;
   out_7078650365136719116[136] = 0.0;
   out_7078650365136719116[137] = 0.0;
   out_7078650365136719116[138] = 0.0;
   out_7078650365136719116[139] = 0.0;
   out_7078650365136719116[140] = 0.0;
   out_7078650365136719116[141] = 0.0;
   out_7078650365136719116[142] = 0.0;
   out_7078650365136719116[143] = 0.0;
   out_7078650365136719116[144] = 0.0;
   out_7078650365136719116[145] = 0.0;
   out_7078650365136719116[146] = 0.0;
   out_7078650365136719116[147] = 0.0;
   out_7078650365136719116[148] = 0.0;
   out_7078650365136719116[149] = 0.0;
   out_7078650365136719116[150] = 0.0;
   out_7078650365136719116[151] = 0.0;
   out_7078650365136719116[152] = 1.0;
   out_7078650365136719116[153] = 0.0;
   out_7078650365136719116[154] = 0.0;
   out_7078650365136719116[155] = 0.0;
   out_7078650365136719116[156] = 0.0;
   out_7078650365136719116[157] = 0.0;
   out_7078650365136719116[158] = 0.0;
   out_7078650365136719116[159] = 0.0;
   out_7078650365136719116[160] = 0.0;
   out_7078650365136719116[161] = 0.0;
   out_7078650365136719116[162] = 0.0;
   out_7078650365136719116[163] = 0.0;
   out_7078650365136719116[164] = 0.0;
   out_7078650365136719116[165] = 0.0;
   out_7078650365136719116[166] = 0.0;
   out_7078650365136719116[167] = 0.0;
   out_7078650365136719116[168] = 0.0;
   out_7078650365136719116[169] = 0.0;
   out_7078650365136719116[170] = 0.0;
   out_7078650365136719116[171] = 1.0;
   out_7078650365136719116[172] = 0.0;
   out_7078650365136719116[173] = 0.0;
   out_7078650365136719116[174] = 0.0;
   out_7078650365136719116[175] = 0.0;
   out_7078650365136719116[176] = 0.0;
   out_7078650365136719116[177] = 0.0;
   out_7078650365136719116[178] = 0.0;
   out_7078650365136719116[179] = 0.0;
   out_7078650365136719116[180] = 0.0;
   out_7078650365136719116[181] = 0.0;
   out_7078650365136719116[182] = 0.0;
   out_7078650365136719116[183] = 0.0;
   out_7078650365136719116[184] = 0.0;
   out_7078650365136719116[185] = 0.0;
   out_7078650365136719116[186] = 0.0;
   out_7078650365136719116[187] = 0.0;
   out_7078650365136719116[188] = 0.0;
   out_7078650365136719116[189] = 0.0;
   out_7078650365136719116[190] = 1.0;
   out_7078650365136719116[191] = 0.0;
   out_7078650365136719116[192] = 0.0;
   out_7078650365136719116[193] = 0.0;
   out_7078650365136719116[194] = 0.0;
   out_7078650365136719116[195] = 0.0;
   out_7078650365136719116[196] = 0.0;
   out_7078650365136719116[197] = 0.0;
   out_7078650365136719116[198] = 0.0;
   out_7078650365136719116[199] = 0.0;
   out_7078650365136719116[200] = 0.0;
   out_7078650365136719116[201] = 0.0;
   out_7078650365136719116[202] = 0.0;
   out_7078650365136719116[203] = 0.0;
   out_7078650365136719116[204] = 0.0;
   out_7078650365136719116[205] = 0.0;
   out_7078650365136719116[206] = 0.0;
   out_7078650365136719116[207] = 0.0;
   out_7078650365136719116[208] = 0.0;
   out_7078650365136719116[209] = 1.0;
   out_7078650365136719116[210] = 0.0;
   out_7078650365136719116[211] = 0.0;
   out_7078650365136719116[212] = 0.0;
   out_7078650365136719116[213] = 0.0;
   out_7078650365136719116[214] = 0.0;
   out_7078650365136719116[215] = 0.0;
   out_7078650365136719116[216] = 0.0;
   out_7078650365136719116[217] = 0.0;
   out_7078650365136719116[218] = 0.0;
   out_7078650365136719116[219] = 0.0;
   out_7078650365136719116[220] = 0.0;
   out_7078650365136719116[221] = 0.0;
   out_7078650365136719116[222] = 0.0;
   out_7078650365136719116[223] = 0.0;
   out_7078650365136719116[224] = 0.0;
   out_7078650365136719116[225] = 0.0;
   out_7078650365136719116[226] = 0.0;
   out_7078650365136719116[227] = 0.0;
   out_7078650365136719116[228] = 1.0;
   out_7078650365136719116[229] = 0.0;
   out_7078650365136719116[230] = 0.0;
   out_7078650365136719116[231] = 0.0;
   out_7078650365136719116[232] = 0.0;
   out_7078650365136719116[233] = 0.0;
   out_7078650365136719116[234] = 0.0;
   out_7078650365136719116[235] = 0.0;
   out_7078650365136719116[236] = 0.0;
   out_7078650365136719116[237] = 0.0;
   out_7078650365136719116[238] = 0.0;
   out_7078650365136719116[239] = 0.0;
   out_7078650365136719116[240] = 0.0;
   out_7078650365136719116[241] = 0.0;
   out_7078650365136719116[242] = 0.0;
   out_7078650365136719116[243] = 0.0;
   out_7078650365136719116[244] = 0.0;
   out_7078650365136719116[245] = 0.0;
   out_7078650365136719116[246] = 0.0;
   out_7078650365136719116[247] = 1.0;
   out_7078650365136719116[248] = 0.0;
   out_7078650365136719116[249] = 0.0;
   out_7078650365136719116[250] = 0.0;
   out_7078650365136719116[251] = 0.0;
   out_7078650365136719116[252] = 0.0;
   out_7078650365136719116[253] = 0.0;
   out_7078650365136719116[254] = 0.0;
   out_7078650365136719116[255] = 0.0;
   out_7078650365136719116[256] = 0.0;
   out_7078650365136719116[257] = 0.0;
   out_7078650365136719116[258] = 0.0;
   out_7078650365136719116[259] = 0.0;
   out_7078650365136719116[260] = 0.0;
   out_7078650365136719116[261] = 0.0;
   out_7078650365136719116[262] = 0.0;
   out_7078650365136719116[263] = 0.0;
   out_7078650365136719116[264] = 0.0;
   out_7078650365136719116[265] = 0.0;
   out_7078650365136719116[266] = 1.0;
   out_7078650365136719116[267] = 0.0;
   out_7078650365136719116[268] = 0.0;
   out_7078650365136719116[269] = 0.0;
   out_7078650365136719116[270] = 0.0;
   out_7078650365136719116[271] = 0.0;
   out_7078650365136719116[272] = 0.0;
   out_7078650365136719116[273] = 0.0;
   out_7078650365136719116[274] = 0.0;
   out_7078650365136719116[275] = 0.0;
   out_7078650365136719116[276] = 0.0;
   out_7078650365136719116[277] = 0.0;
   out_7078650365136719116[278] = 0.0;
   out_7078650365136719116[279] = 0.0;
   out_7078650365136719116[280] = 0.0;
   out_7078650365136719116[281] = 0.0;
   out_7078650365136719116[282] = 0.0;
   out_7078650365136719116[283] = 0.0;
   out_7078650365136719116[284] = 0.0;
   out_7078650365136719116[285] = 1.0;
   out_7078650365136719116[286] = 0.0;
   out_7078650365136719116[287] = 0.0;
   out_7078650365136719116[288] = 0.0;
   out_7078650365136719116[289] = 0.0;
   out_7078650365136719116[290] = 0.0;
   out_7078650365136719116[291] = 0.0;
   out_7078650365136719116[292] = 0.0;
   out_7078650365136719116[293] = 0.0;
   out_7078650365136719116[294] = 0.0;
   out_7078650365136719116[295] = 0.0;
   out_7078650365136719116[296] = 0.0;
   out_7078650365136719116[297] = 0.0;
   out_7078650365136719116[298] = 0.0;
   out_7078650365136719116[299] = 0.0;
   out_7078650365136719116[300] = 0.0;
   out_7078650365136719116[301] = 0.0;
   out_7078650365136719116[302] = 0.0;
   out_7078650365136719116[303] = 0.0;
   out_7078650365136719116[304] = 1.0;
   out_7078650365136719116[305] = 0.0;
   out_7078650365136719116[306] = 0.0;
   out_7078650365136719116[307] = 0.0;
   out_7078650365136719116[308] = 0.0;
   out_7078650365136719116[309] = 0.0;
   out_7078650365136719116[310] = 0.0;
   out_7078650365136719116[311] = 0.0;
   out_7078650365136719116[312] = 0.0;
   out_7078650365136719116[313] = 0.0;
   out_7078650365136719116[314] = 0.0;
   out_7078650365136719116[315] = 0.0;
   out_7078650365136719116[316] = 0.0;
   out_7078650365136719116[317] = 0.0;
   out_7078650365136719116[318] = 0.0;
   out_7078650365136719116[319] = 0.0;
   out_7078650365136719116[320] = 0.0;
   out_7078650365136719116[321] = 0.0;
   out_7078650365136719116[322] = 0.0;
   out_7078650365136719116[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_1089863288273716995) {
   out_1089863288273716995[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_1089863288273716995[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_1089863288273716995[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_1089863288273716995[3] = dt*state[12] + state[3];
   out_1089863288273716995[4] = dt*state[13] + state[4];
   out_1089863288273716995[5] = dt*state[14] + state[5];
   out_1089863288273716995[6] = state[6];
   out_1089863288273716995[7] = state[7];
   out_1089863288273716995[8] = state[8];
   out_1089863288273716995[9] = state[9];
   out_1089863288273716995[10] = state[10];
   out_1089863288273716995[11] = state[11];
   out_1089863288273716995[12] = state[12];
   out_1089863288273716995[13] = state[13];
   out_1089863288273716995[14] = state[14];
   out_1089863288273716995[15] = state[15];
   out_1089863288273716995[16] = state[16];
   out_1089863288273716995[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1417775725995845595) {
   out_1417775725995845595[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1417775725995845595[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1417775725995845595[2] = 0;
   out_1417775725995845595[3] = 0;
   out_1417775725995845595[4] = 0;
   out_1417775725995845595[5] = 0;
   out_1417775725995845595[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1417775725995845595[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1417775725995845595[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1417775725995845595[9] = 0;
   out_1417775725995845595[10] = 0;
   out_1417775725995845595[11] = 0;
   out_1417775725995845595[12] = 0;
   out_1417775725995845595[13] = 0;
   out_1417775725995845595[14] = 0;
   out_1417775725995845595[15] = 0;
   out_1417775725995845595[16] = 0;
   out_1417775725995845595[17] = 0;
   out_1417775725995845595[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1417775725995845595[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1417775725995845595[20] = 0;
   out_1417775725995845595[21] = 0;
   out_1417775725995845595[22] = 0;
   out_1417775725995845595[23] = 0;
   out_1417775725995845595[24] = 0;
   out_1417775725995845595[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1417775725995845595[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1417775725995845595[27] = 0;
   out_1417775725995845595[28] = 0;
   out_1417775725995845595[29] = 0;
   out_1417775725995845595[30] = 0;
   out_1417775725995845595[31] = 0;
   out_1417775725995845595[32] = 0;
   out_1417775725995845595[33] = 0;
   out_1417775725995845595[34] = 0;
   out_1417775725995845595[35] = 0;
   out_1417775725995845595[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1417775725995845595[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1417775725995845595[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1417775725995845595[39] = 0;
   out_1417775725995845595[40] = 0;
   out_1417775725995845595[41] = 0;
   out_1417775725995845595[42] = 0;
   out_1417775725995845595[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1417775725995845595[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1417775725995845595[45] = 0;
   out_1417775725995845595[46] = 0;
   out_1417775725995845595[47] = 0;
   out_1417775725995845595[48] = 0;
   out_1417775725995845595[49] = 0;
   out_1417775725995845595[50] = 0;
   out_1417775725995845595[51] = 0;
   out_1417775725995845595[52] = 0;
   out_1417775725995845595[53] = 0;
   out_1417775725995845595[54] = 0;
   out_1417775725995845595[55] = 0;
   out_1417775725995845595[56] = 0;
   out_1417775725995845595[57] = 1;
   out_1417775725995845595[58] = 0;
   out_1417775725995845595[59] = 0;
   out_1417775725995845595[60] = 0;
   out_1417775725995845595[61] = 0;
   out_1417775725995845595[62] = 0;
   out_1417775725995845595[63] = 0;
   out_1417775725995845595[64] = 0;
   out_1417775725995845595[65] = 0;
   out_1417775725995845595[66] = dt;
   out_1417775725995845595[67] = 0;
   out_1417775725995845595[68] = 0;
   out_1417775725995845595[69] = 0;
   out_1417775725995845595[70] = 0;
   out_1417775725995845595[71] = 0;
   out_1417775725995845595[72] = 0;
   out_1417775725995845595[73] = 0;
   out_1417775725995845595[74] = 0;
   out_1417775725995845595[75] = 0;
   out_1417775725995845595[76] = 1;
   out_1417775725995845595[77] = 0;
   out_1417775725995845595[78] = 0;
   out_1417775725995845595[79] = 0;
   out_1417775725995845595[80] = 0;
   out_1417775725995845595[81] = 0;
   out_1417775725995845595[82] = 0;
   out_1417775725995845595[83] = 0;
   out_1417775725995845595[84] = 0;
   out_1417775725995845595[85] = dt;
   out_1417775725995845595[86] = 0;
   out_1417775725995845595[87] = 0;
   out_1417775725995845595[88] = 0;
   out_1417775725995845595[89] = 0;
   out_1417775725995845595[90] = 0;
   out_1417775725995845595[91] = 0;
   out_1417775725995845595[92] = 0;
   out_1417775725995845595[93] = 0;
   out_1417775725995845595[94] = 0;
   out_1417775725995845595[95] = 1;
   out_1417775725995845595[96] = 0;
   out_1417775725995845595[97] = 0;
   out_1417775725995845595[98] = 0;
   out_1417775725995845595[99] = 0;
   out_1417775725995845595[100] = 0;
   out_1417775725995845595[101] = 0;
   out_1417775725995845595[102] = 0;
   out_1417775725995845595[103] = 0;
   out_1417775725995845595[104] = dt;
   out_1417775725995845595[105] = 0;
   out_1417775725995845595[106] = 0;
   out_1417775725995845595[107] = 0;
   out_1417775725995845595[108] = 0;
   out_1417775725995845595[109] = 0;
   out_1417775725995845595[110] = 0;
   out_1417775725995845595[111] = 0;
   out_1417775725995845595[112] = 0;
   out_1417775725995845595[113] = 0;
   out_1417775725995845595[114] = 1;
   out_1417775725995845595[115] = 0;
   out_1417775725995845595[116] = 0;
   out_1417775725995845595[117] = 0;
   out_1417775725995845595[118] = 0;
   out_1417775725995845595[119] = 0;
   out_1417775725995845595[120] = 0;
   out_1417775725995845595[121] = 0;
   out_1417775725995845595[122] = 0;
   out_1417775725995845595[123] = 0;
   out_1417775725995845595[124] = 0;
   out_1417775725995845595[125] = 0;
   out_1417775725995845595[126] = 0;
   out_1417775725995845595[127] = 0;
   out_1417775725995845595[128] = 0;
   out_1417775725995845595[129] = 0;
   out_1417775725995845595[130] = 0;
   out_1417775725995845595[131] = 0;
   out_1417775725995845595[132] = 0;
   out_1417775725995845595[133] = 1;
   out_1417775725995845595[134] = 0;
   out_1417775725995845595[135] = 0;
   out_1417775725995845595[136] = 0;
   out_1417775725995845595[137] = 0;
   out_1417775725995845595[138] = 0;
   out_1417775725995845595[139] = 0;
   out_1417775725995845595[140] = 0;
   out_1417775725995845595[141] = 0;
   out_1417775725995845595[142] = 0;
   out_1417775725995845595[143] = 0;
   out_1417775725995845595[144] = 0;
   out_1417775725995845595[145] = 0;
   out_1417775725995845595[146] = 0;
   out_1417775725995845595[147] = 0;
   out_1417775725995845595[148] = 0;
   out_1417775725995845595[149] = 0;
   out_1417775725995845595[150] = 0;
   out_1417775725995845595[151] = 0;
   out_1417775725995845595[152] = 1;
   out_1417775725995845595[153] = 0;
   out_1417775725995845595[154] = 0;
   out_1417775725995845595[155] = 0;
   out_1417775725995845595[156] = 0;
   out_1417775725995845595[157] = 0;
   out_1417775725995845595[158] = 0;
   out_1417775725995845595[159] = 0;
   out_1417775725995845595[160] = 0;
   out_1417775725995845595[161] = 0;
   out_1417775725995845595[162] = 0;
   out_1417775725995845595[163] = 0;
   out_1417775725995845595[164] = 0;
   out_1417775725995845595[165] = 0;
   out_1417775725995845595[166] = 0;
   out_1417775725995845595[167] = 0;
   out_1417775725995845595[168] = 0;
   out_1417775725995845595[169] = 0;
   out_1417775725995845595[170] = 0;
   out_1417775725995845595[171] = 1;
   out_1417775725995845595[172] = 0;
   out_1417775725995845595[173] = 0;
   out_1417775725995845595[174] = 0;
   out_1417775725995845595[175] = 0;
   out_1417775725995845595[176] = 0;
   out_1417775725995845595[177] = 0;
   out_1417775725995845595[178] = 0;
   out_1417775725995845595[179] = 0;
   out_1417775725995845595[180] = 0;
   out_1417775725995845595[181] = 0;
   out_1417775725995845595[182] = 0;
   out_1417775725995845595[183] = 0;
   out_1417775725995845595[184] = 0;
   out_1417775725995845595[185] = 0;
   out_1417775725995845595[186] = 0;
   out_1417775725995845595[187] = 0;
   out_1417775725995845595[188] = 0;
   out_1417775725995845595[189] = 0;
   out_1417775725995845595[190] = 1;
   out_1417775725995845595[191] = 0;
   out_1417775725995845595[192] = 0;
   out_1417775725995845595[193] = 0;
   out_1417775725995845595[194] = 0;
   out_1417775725995845595[195] = 0;
   out_1417775725995845595[196] = 0;
   out_1417775725995845595[197] = 0;
   out_1417775725995845595[198] = 0;
   out_1417775725995845595[199] = 0;
   out_1417775725995845595[200] = 0;
   out_1417775725995845595[201] = 0;
   out_1417775725995845595[202] = 0;
   out_1417775725995845595[203] = 0;
   out_1417775725995845595[204] = 0;
   out_1417775725995845595[205] = 0;
   out_1417775725995845595[206] = 0;
   out_1417775725995845595[207] = 0;
   out_1417775725995845595[208] = 0;
   out_1417775725995845595[209] = 1;
   out_1417775725995845595[210] = 0;
   out_1417775725995845595[211] = 0;
   out_1417775725995845595[212] = 0;
   out_1417775725995845595[213] = 0;
   out_1417775725995845595[214] = 0;
   out_1417775725995845595[215] = 0;
   out_1417775725995845595[216] = 0;
   out_1417775725995845595[217] = 0;
   out_1417775725995845595[218] = 0;
   out_1417775725995845595[219] = 0;
   out_1417775725995845595[220] = 0;
   out_1417775725995845595[221] = 0;
   out_1417775725995845595[222] = 0;
   out_1417775725995845595[223] = 0;
   out_1417775725995845595[224] = 0;
   out_1417775725995845595[225] = 0;
   out_1417775725995845595[226] = 0;
   out_1417775725995845595[227] = 0;
   out_1417775725995845595[228] = 1;
   out_1417775725995845595[229] = 0;
   out_1417775725995845595[230] = 0;
   out_1417775725995845595[231] = 0;
   out_1417775725995845595[232] = 0;
   out_1417775725995845595[233] = 0;
   out_1417775725995845595[234] = 0;
   out_1417775725995845595[235] = 0;
   out_1417775725995845595[236] = 0;
   out_1417775725995845595[237] = 0;
   out_1417775725995845595[238] = 0;
   out_1417775725995845595[239] = 0;
   out_1417775725995845595[240] = 0;
   out_1417775725995845595[241] = 0;
   out_1417775725995845595[242] = 0;
   out_1417775725995845595[243] = 0;
   out_1417775725995845595[244] = 0;
   out_1417775725995845595[245] = 0;
   out_1417775725995845595[246] = 0;
   out_1417775725995845595[247] = 1;
   out_1417775725995845595[248] = 0;
   out_1417775725995845595[249] = 0;
   out_1417775725995845595[250] = 0;
   out_1417775725995845595[251] = 0;
   out_1417775725995845595[252] = 0;
   out_1417775725995845595[253] = 0;
   out_1417775725995845595[254] = 0;
   out_1417775725995845595[255] = 0;
   out_1417775725995845595[256] = 0;
   out_1417775725995845595[257] = 0;
   out_1417775725995845595[258] = 0;
   out_1417775725995845595[259] = 0;
   out_1417775725995845595[260] = 0;
   out_1417775725995845595[261] = 0;
   out_1417775725995845595[262] = 0;
   out_1417775725995845595[263] = 0;
   out_1417775725995845595[264] = 0;
   out_1417775725995845595[265] = 0;
   out_1417775725995845595[266] = 1;
   out_1417775725995845595[267] = 0;
   out_1417775725995845595[268] = 0;
   out_1417775725995845595[269] = 0;
   out_1417775725995845595[270] = 0;
   out_1417775725995845595[271] = 0;
   out_1417775725995845595[272] = 0;
   out_1417775725995845595[273] = 0;
   out_1417775725995845595[274] = 0;
   out_1417775725995845595[275] = 0;
   out_1417775725995845595[276] = 0;
   out_1417775725995845595[277] = 0;
   out_1417775725995845595[278] = 0;
   out_1417775725995845595[279] = 0;
   out_1417775725995845595[280] = 0;
   out_1417775725995845595[281] = 0;
   out_1417775725995845595[282] = 0;
   out_1417775725995845595[283] = 0;
   out_1417775725995845595[284] = 0;
   out_1417775725995845595[285] = 1;
   out_1417775725995845595[286] = 0;
   out_1417775725995845595[287] = 0;
   out_1417775725995845595[288] = 0;
   out_1417775725995845595[289] = 0;
   out_1417775725995845595[290] = 0;
   out_1417775725995845595[291] = 0;
   out_1417775725995845595[292] = 0;
   out_1417775725995845595[293] = 0;
   out_1417775725995845595[294] = 0;
   out_1417775725995845595[295] = 0;
   out_1417775725995845595[296] = 0;
   out_1417775725995845595[297] = 0;
   out_1417775725995845595[298] = 0;
   out_1417775725995845595[299] = 0;
   out_1417775725995845595[300] = 0;
   out_1417775725995845595[301] = 0;
   out_1417775725995845595[302] = 0;
   out_1417775725995845595[303] = 0;
   out_1417775725995845595[304] = 1;
   out_1417775725995845595[305] = 0;
   out_1417775725995845595[306] = 0;
   out_1417775725995845595[307] = 0;
   out_1417775725995845595[308] = 0;
   out_1417775725995845595[309] = 0;
   out_1417775725995845595[310] = 0;
   out_1417775725995845595[311] = 0;
   out_1417775725995845595[312] = 0;
   out_1417775725995845595[313] = 0;
   out_1417775725995845595[314] = 0;
   out_1417775725995845595[315] = 0;
   out_1417775725995845595[316] = 0;
   out_1417775725995845595[317] = 0;
   out_1417775725995845595[318] = 0;
   out_1417775725995845595[319] = 0;
   out_1417775725995845595[320] = 0;
   out_1417775725995845595[321] = 0;
   out_1417775725995845595[322] = 0;
   out_1417775725995845595[323] = 1;
}
void h_4(double *state, double *unused, double *out_1718190299387698220) {
   out_1718190299387698220[0] = state[6] + state[9];
   out_1718190299387698220[1] = state[7] + state[10];
   out_1718190299387698220[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3167788824599607733) {
   out_3167788824599607733[0] = 0;
   out_3167788824599607733[1] = 0;
   out_3167788824599607733[2] = 0;
   out_3167788824599607733[3] = 0;
   out_3167788824599607733[4] = 0;
   out_3167788824599607733[5] = 0;
   out_3167788824599607733[6] = 1;
   out_3167788824599607733[7] = 0;
   out_3167788824599607733[8] = 0;
   out_3167788824599607733[9] = 1;
   out_3167788824599607733[10] = 0;
   out_3167788824599607733[11] = 0;
   out_3167788824599607733[12] = 0;
   out_3167788824599607733[13] = 0;
   out_3167788824599607733[14] = 0;
   out_3167788824599607733[15] = 0;
   out_3167788824599607733[16] = 0;
   out_3167788824599607733[17] = 0;
   out_3167788824599607733[18] = 0;
   out_3167788824599607733[19] = 0;
   out_3167788824599607733[20] = 0;
   out_3167788824599607733[21] = 0;
   out_3167788824599607733[22] = 0;
   out_3167788824599607733[23] = 0;
   out_3167788824599607733[24] = 0;
   out_3167788824599607733[25] = 1;
   out_3167788824599607733[26] = 0;
   out_3167788824599607733[27] = 0;
   out_3167788824599607733[28] = 1;
   out_3167788824599607733[29] = 0;
   out_3167788824599607733[30] = 0;
   out_3167788824599607733[31] = 0;
   out_3167788824599607733[32] = 0;
   out_3167788824599607733[33] = 0;
   out_3167788824599607733[34] = 0;
   out_3167788824599607733[35] = 0;
   out_3167788824599607733[36] = 0;
   out_3167788824599607733[37] = 0;
   out_3167788824599607733[38] = 0;
   out_3167788824599607733[39] = 0;
   out_3167788824599607733[40] = 0;
   out_3167788824599607733[41] = 0;
   out_3167788824599607733[42] = 0;
   out_3167788824599607733[43] = 0;
   out_3167788824599607733[44] = 1;
   out_3167788824599607733[45] = 0;
   out_3167788824599607733[46] = 0;
   out_3167788824599607733[47] = 1;
   out_3167788824599607733[48] = 0;
   out_3167788824599607733[49] = 0;
   out_3167788824599607733[50] = 0;
   out_3167788824599607733[51] = 0;
   out_3167788824599607733[52] = 0;
   out_3167788824599607733[53] = 0;
}
void h_10(double *state, double *unused, double *out_5321237706151248965) {
   out_5321237706151248965[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_5321237706151248965[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_5321237706151248965[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_1920250937061611591) {
   out_1920250937061611591[0] = 0;
   out_1920250937061611591[1] = 9.8100000000000005*cos(state[1]);
   out_1920250937061611591[2] = 0;
   out_1920250937061611591[3] = 0;
   out_1920250937061611591[4] = -state[8];
   out_1920250937061611591[5] = state[7];
   out_1920250937061611591[6] = 0;
   out_1920250937061611591[7] = state[5];
   out_1920250937061611591[8] = -state[4];
   out_1920250937061611591[9] = 0;
   out_1920250937061611591[10] = 0;
   out_1920250937061611591[11] = 0;
   out_1920250937061611591[12] = 1;
   out_1920250937061611591[13] = 0;
   out_1920250937061611591[14] = 0;
   out_1920250937061611591[15] = 1;
   out_1920250937061611591[16] = 0;
   out_1920250937061611591[17] = 0;
   out_1920250937061611591[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_1920250937061611591[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_1920250937061611591[20] = 0;
   out_1920250937061611591[21] = state[8];
   out_1920250937061611591[22] = 0;
   out_1920250937061611591[23] = -state[6];
   out_1920250937061611591[24] = -state[5];
   out_1920250937061611591[25] = 0;
   out_1920250937061611591[26] = state[3];
   out_1920250937061611591[27] = 0;
   out_1920250937061611591[28] = 0;
   out_1920250937061611591[29] = 0;
   out_1920250937061611591[30] = 0;
   out_1920250937061611591[31] = 1;
   out_1920250937061611591[32] = 0;
   out_1920250937061611591[33] = 0;
   out_1920250937061611591[34] = 1;
   out_1920250937061611591[35] = 0;
   out_1920250937061611591[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_1920250937061611591[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_1920250937061611591[38] = 0;
   out_1920250937061611591[39] = -state[7];
   out_1920250937061611591[40] = state[6];
   out_1920250937061611591[41] = 0;
   out_1920250937061611591[42] = state[4];
   out_1920250937061611591[43] = -state[3];
   out_1920250937061611591[44] = 0;
   out_1920250937061611591[45] = 0;
   out_1920250937061611591[46] = 0;
   out_1920250937061611591[47] = 0;
   out_1920250937061611591[48] = 0;
   out_1920250937061611591[49] = 0;
   out_1920250937061611591[50] = 1;
   out_1920250937061611591[51] = 0;
   out_1920250937061611591[52] = 0;
   out_1920250937061611591[53] = 1;
}
void h_13(double *state, double *unused, double *out_8512972491309284140) {
   out_8512972491309284140[0] = state[3];
   out_8512972491309284140[1] = state[4];
   out_8512972491309284140[2] = state[5];
}
void H_13(double *state, double *unused, double *out_4442842383717093196) {
   out_4442842383717093196[0] = 0;
   out_4442842383717093196[1] = 0;
   out_4442842383717093196[2] = 0;
   out_4442842383717093196[3] = 1;
   out_4442842383717093196[4] = 0;
   out_4442842383717093196[5] = 0;
   out_4442842383717093196[6] = 0;
   out_4442842383717093196[7] = 0;
   out_4442842383717093196[8] = 0;
   out_4442842383717093196[9] = 0;
   out_4442842383717093196[10] = 0;
   out_4442842383717093196[11] = 0;
   out_4442842383717093196[12] = 0;
   out_4442842383717093196[13] = 0;
   out_4442842383717093196[14] = 0;
   out_4442842383717093196[15] = 0;
   out_4442842383717093196[16] = 0;
   out_4442842383717093196[17] = 0;
   out_4442842383717093196[18] = 0;
   out_4442842383717093196[19] = 0;
   out_4442842383717093196[20] = 0;
   out_4442842383717093196[21] = 0;
   out_4442842383717093196[22] = 1;
   out_4442842383717093196[23] = 0;
   out_4442842383717093196[24] = 0;
   out_4442842383717093196[25] = 0;
   out_4442842383717093196[26] = 0;
   out_4442842383717093196[27] = 0;
   out_4442842383717093196[28] = 0;
   out_4442842383717093196[29] = 0;
   out_4442842383717093196[30] = 0;
   out_4442842383717093196[31] = 0;
   out_4442842383717093196[32] = 0;
   out_4442842383717093196[33] = 0;
   out_4442842383717093196[34] = 0;
   out_4442842383717093196[35] = 0;
   out_4442842383717093196[36] = 0;
   out_4442842383717093196[37] = 0;
   out_4442842383717093196[38] = 0;
   out_4442842383717093196[39] = 0;
   out_4442842383717093196[40] = 0;
   out_4442842383717093196[41] = 1;
   out_4442842383717093196[42] = 0;
   out_4442842383717093196[43] = 0;
   out_4442842383717093196[44] = 0;
   out_4442842383717093196[45] = 0;
   out_4442842383717093196[46] = 0;
   out_4442842383717093196[47] = 0;
   out_4442842383717093196[48] = 0;
   out_4442842383717093196[49] = 0;
   out_4442842383717093196[50] = 0;
   out_4442842383717093196[51] = 0;
   out_4442842383717093196[52] = 0;
   out_4442842383717093196[53] = 0;
}
void h_14(double *state, double *unused, double *out_4631166666474537982) {
   out_4631166666474537982[0] = state[6];
   out_4631166666474537982[1] = state[7];
   out_4631166666474537982[2] = state[8];
}
void H_14(double *state, double *unused, double *out_795452031739876796) {
   out_795452031739876796[0] = 0;
   out_795452031739876796[1] = 0;
   out_795452031739876796[2] = 0;
   out_795452031739876796[3] = 0;
   out_795452031739876796[4] = 0;
   out_795452031739876796[5] = 0;
   out_795452031739876796[6] = 1;
   out_795452031739876796[7] = 0;
   out_795452031739876796[8] = 0;
   out_795452031739876796[9] = 0;
   out_795452031739876796[10] = 0;
   out_795452031739876796[11] = 0;
   out_795452031739876796[12] = 0;
   out_795452031739876796[13] = 0;
   out_795452031739876796[14] = 0;
   out_795452031739876796[15] = 0;
   out_795452031739876796[16] = 0;
   out_795452031739876796[17] = 0;
   out_795452031739876796[18] = 0;
   out_795452031739876796[19] = 0;
   out_795452031739876796[20] = 0;
   out_795452031739876796[21] = 0;
   out_795452031739876796[22] = 0;
   out_795452031739876796[23] = 0;
   out_795452031739876796[24] = 0;
   out_795452031739876796[25] = 1;
   out_795452031739876796[26] = 0;
   out_795452031739876796[27] = 0;
   out_795452031739876796[28] = 0;
   out_795452031739876796[29] = 0;
   out_795452031739876796[30] = 0;
   out_795452031739876796[31] = 0;
   out_795452031739876796[32] = 0;
   out_795452031739876796[33] = 0;
   out_795452031739876796[34] = 0;
   out_795452031739876796[35] = 0;
   out_795452031739876796[36] = 0;
   out_795452031739876796[37] = 0;
   out_795452031739876796[38] = 0;
   out_795452031739876796[39] = 0;
   out_795452031739876796[40] = 0;
   out_795452031739876796[41] = 0;
   out_795452031739876796[42] = 0;
   out_795452031739876796[43] = 0;
   out_795452031739876796[44] = 1;
   out_795452031739876796[45] = 0;
   out_795452031739876796[46] = 0;
   out_795452031739876796[47] = 0;
   out_795452031739876796[48] = 0;
   out_795452031739876796[49] = 0;
   out_795452031739876796[50] = 0;
   out_795452031739876796[51] = 0;
   out_795452031739876796[52] = 0;
   out_795452031739876796[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_4117449312389212167) {
  err_fun(nom_x, delta_x, out_4117449312389212167);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2619781936850820050) {
  inv_err_fun(nom_x, true_x, out_2619781936850820050);
}
void pose_H_mod_fun(double *state, double *out_7078650365136719116) {
  H_mod_fun(state, out_7078650365136719116);
}
void pose_f_fun(double *state, double dt, double *out_1089863288273716995) {
  f_fun(state,  dt, out_1089863288273716995);
}
void pose_F_fun(double *state, double dt, double *out_1417775725995845595) {
  F_fun(state,  dt, out_1417775725995845595);
}
void pose_h_4(double *state, double *unused, double *out_1718190299387698220) {
  h_4(state, unused, out_1718190299387698220);
}
void pose_H_4(double *state, double *unused, double *out_3167788824599607733) {
  H_4(state, unused, out_3167788824599607733);
}
void pose_h_10(double *state, double *unused, double *out_5321237706151248965) {
  h_10(state, unused, out_5321237706151248965);
}
void pose_H_10(double *state, double *unused, double *out_1920250937061611591) {
  H_10(state, unused, out_1920250937061611591);
}
void pose_h_13(double *state, double *unused, double *out_8512972491309284140) {
  h_13(state, unused, out_8512972491309284140);
}
void pose_H_13(double *state, double *unused, double *out_4442842383717093196) {
  H_13(state, unused, out_4442842383717093196);
}
void pose_h_14(double *state, double *unused, double *out_4631166666474537982) {
  h_14(state, unused, out_4631166666474537982);
}
void pose_H_14(double *state, double *unused, double *out_795452031739876796) {
  H_14(state, unused, out_795452031739876796);
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
