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
void err_fun(double *nom_x, double *delta_x, double *out_38746564740330454) {
   out_38746564740330454[0] = delta_x[0] + nom_x[0];
   out_38746564740330454[1] = delta_x[1] + nom_x[1];
   out_38746564740330454[2] = delta_x[2] + nom_x[2];
   out_38746564740330454[3] = delta_x[3] + nom_x[3];
   out_38746564740330454[4] = delta_x[4] + nom_x[4];
   out_38746564740330454[5] = delta_x[5] + nom_x[5];
   out_38746564740330454[6] = delta_x[6] + nom_x[6];
   out_38746564740330454[7] = delta_x[7] + nom_x[7];
   out_38746564740330454[8] = delta_x[8] + nom_x[8];
   out_38746564740330454[9] = delta_x[9] + nom_x[9];
   out_38746564740330454[10] = delta_x[10] + nom_x[10];
   out_38746564740330454[11] = delta_x[11] + nom_x[11];
   out_38746564740330454[12] = delta_x[12] + nom_x[12];
   out_38746564740330454[13] = delta_x[13] + nom_x[13];
   out_38746564740330454[14] = delta_x[14] + nom_x[14];
   out_38746564740330454[15] = delta_x[15] + nom_x[15];
   out_38746564740330454[16] = delta_x[16] + nom_x[16];
   out_38746564740330454[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7177343441098663951) {
   out_7177343441098663951[0] = -nom_x[0] + true_x[0];
   out_7177343441098663951[1] = -nom_x[1] + true_x[1];
   out_7177343441098663951[2] = -nom_x[2] + true_x[2];
   out_7177343441098663951[3] = -nom_x[3] + true_x[3];
   out_7177343441098663951[4] = -nom_x[4] + true_x[4];
   out_7177343441098663951[5] = -nom_x[5] + true_x[5];
   out_7177343441098663951[6] = -nom_x[6] + true_x[6];
   out_7177343441098663951[7] = -nom_x[7] + true_x[7];
   out_7177343441098663951[8] = -nom_x[8] + true_x[8];
   out_7177343441098663951[9] = -nom_x[9] + true_x[9];
   out_7177343441098663951[10] = -nom_x[10] + true_x[10];
   out_7177343441098663951[11] = -nom_x[11] + true_x[11];
   out_7177343441098663951[12] = -nom_x[12] + true_x[12];
   out_7177343441098663951[13] = -nom_x[13] + true_x[13];
   out_7177343441098663951[14] = -nom_x[14] + true_x[14];
   out_7177343441098663951[15] = -nom_x[15] + true_x[15];
   out_7177343441098663951[16] = -nom_x[16] + true_x[16];
   out_7177343441098663951[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_3413607092153665585) {
   out_3413607092153665585[0] = 1.0;
   out_3413607092153665585[1] = 0.0;
   out_3413607092153665585[2] = 0.0;
   out_3413607092153665585[3] = 0.0;
   out_3413607092153665585[4] = 0.0;
   out_3413607092153665585[5] = 0.0;
   out_3413607092153665585[6] = 0.0;
   out_3413607092153665585[7] = 0.0;
   out_3413607092153665585[8] = 0.0;
   out_3413607092153665585[9] = 0.0;
   out_3413607092153665585[10] = 0.0;
   out_3413607092153665585[11] = 0.0;
   out_3413607092153665585[12] = 0.0;
   out_3413607092153665585[13] = 0.0;
   out_3413607092153665585[14] = 0.0;
   out_3413607092153665585[15] = 0.0;
   out_3413607092153665585[16] = 0.0;
   out_3413607092153665585[17] = 0.0;
   out_3413607092153665585[18] = 0.0;
   out_3413607092153665585[19] = 1.0;
   out_3413607092153665585[20] = 0.0;
   out_3413607092153665585[21] = 0.0;
   out_3413607092153665585[22] = 0.0;
   out_3413607092153665585[23] = 0.0;
   out_3413607092153665585[24] = 0.0;
   out_3413607092153665585[25] = 0.0;
   out_3413607092153665585[26] = 0.0;
   out_3413607092153665585[27] = 0.0;
   out_3413607092153665585[28] = 0.0;
   out_3413607092153665585[29] = 0.0;
   out_3413607092153665585[30] = 0.0;
   out_3413607092153665585[31] = 0.0;
   out_3413607092153665585[32] = 0.0;
   out_3413607092153665585[33] = 0.0;
   out_3413607092153665585[34] = 0.0;
   out_3413607092153665585[35] = 0.0;
   out_3413607092153665585[36] = 0.0;
   out_3413607092153665585[37] = 0.0;
   out_3413607092153665585[38] = 1.0;
   out_3413607092153665585[39] = 0.0;
   out_3413607092153665585[40] = 0.0;
   out_3413607092153665585[41] = 0.0;
   out_3413607092153665585[42] = 0.0;
   out_3413607092153665585[43] = 0.0;
   out_3413607092153665585[44] = 0.0;
   out_3413607092153665585[45] = 0.0;
   out_3413607092153665585[46] = 0.0;
   out_3413607092153665585[47] = 0.0;
   out_3413607092153665585[48] = 0.0;
   out_3413607092153665585[49] = 0.0;
   out_3413607092153665585[50] = 0.0;
   out_3413607092153665585[51] = 0.0;
   out_3413607092153665585[52] = 0.0;
   out_3413607092153665585[53] = 0.0;
   out_3413607092153665585[54] = 0.0;
   out_3413607092153665585[55] = 0.0;
   out_3413607092153665585[56] = 0.0;
   out_3413607092153665585[57] = 1.0;
   out_3413607092153665585[58] = 0.0;
   out_3413607092153665585[59] = 0.0;
   out_3413607092153665585[60] = 0.0;
   out_3413607092153665585[61] = 0.0;
   out_3413607092153665585[62] = 0.0;
   out_3413607092153665585[63] = 0.0;
   out_3413607092153665585[64] = 0.0;
   out_3413607092153665585[65] = 0.0;
   out_3413607092153665585[66] = 0.0;
   out_3413607092153665585[67] = 0.0;
   out_3413607092153665585[68] = 0.0;
   out_3413607092153665585[69] = 0.0;
   out_3413607092153665585[70] = 0.0;
   out_3413607092153665585[71] = 0.0;
   out_3413607092153665585[72] = 0.0;
   out_3413607092153665585[73] = 0.0;
   out_3413607092153665585[74] = 0.0;
   out_3413607092153665585[75] = 0.0;
   out_3413607092153665585[76] = 1.0;
   out_3413607092153665585[77] = 0.0;
   out_3413607092153665585[78] = 0.0;
   out_3413607092153665585[79] = 0.0;
   out_3413607092153665585[80] = 0.0;
   out_3413607092153665585[81] = 0.0;
   out_3413607092153665585[82] = 0.0;
   out_3413607092153665585[83] = 0.0;
   out_3413607092153665585[84] = 0.0;
   out_3413607092153665585[85] = 0.0;
   out_3413607092153665585[86] = 0.0;
   out_3413607092153665585[87] = 0.0;
   out_3413607092153665585[88] = 0.0;
   out_3413607092153665585[89] = 0.0;
   out_3413607092153665585[90] = 0.0;
   out_3413607092153665585[91] = 0.0;
   out_3413607092153665585[92] = 0.0;
   out_3413607092153665585[93] = 0.0;
   out_3413607092153665585[94] = 0.0;
   out_3413607092153665585[95] = 1.0;
   out_3413607092153665585[96] = 0.0;
   out_3413607092153665585[97] = 0.0;
   out_3413607092153665585[98] = 0.0;
   out_3413607092153665585[99] = 0.0;
   out_3413607092153665585[100] = 0.0;
   out_3413607092153665585[101] = 0.0;
   out_3413607092153665585[102] = 0.0;
   out_3413607092153665585[103] = 0.0;
   out_3413607092153665585[104] = 0.0;
   out_3413607092153665585[105] = 0.0;
   out_3413607092153665585[106] = 0.0;
   out_3413607092153665585[107] = 0.0;
   out_3413607092153665585[108] = 0.0;
   out_3413607092153665585[109] = 0.0;
   out_3413607092153665585[110] = 0.0;
   out_3413607092153665585[111] = 0.0;
   out_3413607092153665585[112] = 0.0;
   out_3413607092153665585[113] = 0.0;
   out_3413607092153665585[114] = 1.0;
   out_3413607092153665585[115] = 0.0;
   out_3413607092153665585[116] = 0.0;
   out_3413607092153665585[117] = 0.0;
   out_3413607092153665585[118] = 0.0;
   out_3413607092153665585[119] = 0.0;
   out_3413607092153665585[120] = 0.0;
   out_3413607092153665585[121] = 0.0;
   out_3413607092153665585[122] = 0.0;
   out_3413607092153665585[123] = 0.0;
   out_3413607092153665585[124] = 0.0;
   out_3413607092153665585[125] = 0.0;
   out_3413607092153665585[126] = 0.0;
   out_3413607092153665585[127] = 0.0;
   out_3413607092153665585[128] = 0.0;
   out_3413607092153665585[129] = 0.0;
   out_3413607092153665585[130] = 0.0;
   out_3413607092153665585[131] = 0.0;
   out_3413607092153665585[132] = 0.0;
   out_3413607092153665585[133] = 1.0;
   out_3413607092153665585[134] = 0.0;
   out_3413607092153665585[135] = 0.0;
   out_3413607092153665585[136] = 0.0;
   out_3413607092153665585[137] = 0.0;
   out_3413607092153665585[138] = 0.0;
   out_3413607092153665585[139] = 0.0;
   out_3413607092153665585[140] = 0.0;
   out_3413607092153665585[141] = 0.0;
   out_3413607092153665585[142] = 0.0;
   out_3413607092153665585[143] = 0.0;
   out_3413607092153665585[144] = 0.0;
   out_3413607092153665585[145] = 0.0;
   out_3413607092153665585[146] = 0.0;
   out_3413607092153665585[147] = 0.0;
   out_3413607092153665585[148] = 0.0;
   out_3413607092153665585[149] = 0.0;
   out_3413607092153665585[150] = 0.0;
   out_3413607092153665585[151] = 0.0;
   out_3413607092153665585[152] = 1.0;
   out_3413607092153665585[153] = 0.0;
   out_3413607092153665585[154] = 0.0;
   out_3413607092153665585[155] = 0.0;
   out_3413607092153665585[156] = 0.0;
   out_3413607092153665585[157] = 0.0;
   out_3413607092153665585[158] = 0.0;
   out_3413607092153665585[159] = 0.0;
   out_3413607092153665585[160] = 0.0;
   out_3413607092153665585[161] = 0.0;
   out_3413607092153665585[162] = 0.0;
   out_3413607092153665585[163] = 0.0;
   out_3413607092153665585[164] = 0.0;
   out_3413607092153665585[165] = 0.0;
   out_3413607092153665585[166] = 0.0;
   out_3413607092153665585[167] = 0.0;
   out_3413607092153665585[168] = 0.0;
   out_3413607092153665585[169] = 0.0;
   out_3413607092153665585[170] = 0.0;
   out_3413607092153665585[171] = 1.0;
   out_3413607092153665585[172] = 0.0;
   out_3413607092153665585[173] = 0.0;
   out_3413607092153665585[174] = 0.0;
   out_3413607092153665585[175] = 0.0;
   out_3413607092153665585[176] = 0.0;
   out_3413607092153665585[177] = 0.0;
   out_3413607092153665585[178] = 0.0;
   out_3413607092153665585[179] = 0.0;
   out_3413607092153665585[180] = 0.0;
   out_3413607092153665585[181] = 0.0;
   out_3413607092153665585[182] = 0.0;
   out_3413607092153665585[183] = 0.0;
   out_3413607092153665585[184] = 0.0;
   out_3413607092153665585[185] = 0.0;
   out_3413607092153665585[186] = 0.0;
   out_3413607092153665585[187] = 0.0;
   out_3413607092153665585[188] = 0.0;
   out_3413607092153665585[189] = 0.0;
   out_3413607092153665585[190] = 1.0;
   out_3413607092153665585[191] = 0.0;
   out_3413607092153665585[192] = 0.0;
   out_3413607092153665585[193] = 0.0;
   out_3413607092153665585[194] = 0.0;
   out_3413607092153665585[195] = 0.0;
   out_3413607092153665585[196] = 0.0;
   out_3413607092153665585[197] = 0.0;
   out_3413607092153665585[198] = 0.0;
   out_3413607092153665585[199] = 0.0;
   out_3413607092153665585[200] = 0.0;
   out_3413607092153665585[201] = 0.0;
   out_3413607092153665585[202] = 0.0;
   out_3413607092153665585[203] = 0.0;
   out_3413607092153665585[204] = 0.0;
   out_3413607092153665585[205] = 0.0;
   out_3413607092153665585[206] = 0.0;
   out_3413607092153665585[207] = 0.0;
   out_3413607092153665585[208] = 0.0;
   out_3413607092153665585[209] = 1.0;
   out_3413607092153665585[210] = 0.0;
   out_3413607092153665585[211] = 0.0;
   out_3413607092153665585[212] = 0.0;
   out_3413607092153665585[213] = 0.0;
   out_3413607092153665585[214] = 0.0;
   out_3413607092153665585[215] = 0.0;
   out_3413607092153665585[216] = 0.0;
   out_3413607092153665585[217] = 0.0;
   out_3413607092153665585[218] = 0.0;
   out_3413607092153665585[219] = 0.0;
   out_3413607092153665585[220] = 0.0;
   out_3413607092153665585[221] = 0.0;
   out_3413607092153665585[222] = 0.0;
   out_3413607092153665585[223] = 0.0;
   out_3413607092153665585[224] = 0.0;
   out_3413607092153665585[225] = 0.0;
   out_3413607092153665585[226] = 0.0;
   out_3413607092153665585[227] = 0.0;
   out_3413607092153665585[228] = 1.0;
   out_3413607092153665585[229] = 0.0;
   out_3413607092153665585[230] = 0.0;
   out_3413607092153665585[231] = 0.0;
   out_3413607092153665585[232] = 0.0;
   out_3413607092153665585[233] = 0.0;
   out_3413607092153665585[234] = 0.0;
   out_3413607092153665585[235] = 0.0;
   out_3413607092153665585[236] = 0.0;
   out_3413607092153665585[237] = 0.0;
   out_3413607092153665585[238] = 0.0;
   out_3413607092153665585[239] = 0.0;
   out_3413607092153665585[240] = 0.0;
   out_3413607092153665585[241] = 0.0;
   out_3413607092153665585[242] = 0.0;
   out_3413607092153665585[243] = 0.0;
   out_3413607092153665585[244] = 0.0;
   out_3413607092153665585[245] = 0.0;
   out_3413607092153665585[246] = 0.0;
   out_3413607092153665585[247] = 1.0;
   out_3413607092153665585[248] = 0.0;
   out_3413607092153665585[249] = 0.0;
   out_3413607092153665585[250] = 0.0;
   out_3413607092153665585[251] = 0.0;
   out_3413607092153665585[252] = 0.0;
   out_3413607092153665585[253] = 0.0;
   out_3413607092153665585[254] = 0.0;
   out_3413607092153665585[255] = 0.0;
   out_3413607092153665585[256] = 0.0;
   out_3413607092153665585[257] = 0.0;
   out_3413607092153665585[258] = 0.0;
   out_3413607092153665585[259] = 0.0;
   out_3413607092153665585[260] = 0.0;
   out_3413607092153665585[261] = 0.0;
   out_3413607092153665585[262] = 0.0;
   out_3413607092153665585[263] = 0.0;
   out_3413607092153665585[264] = 0.0;
   out_3413607092153665585[265] = 0.0;
   out_3413607092153665585[266] = 1.0;
   out_3413607092153665585[267] = 0.0;
   out_3413607092153665585[268] = 0.0;
   out_3413607092153665585[269] = 0.0;
   out_3413607092153665585[270] = 0.0;
   out_3413607092153665585[271] = 0.0;
   out_3413607092153665585[272] = 0.0;
   out_3413607092153665585[273] = 0.0;
   out_3413607092153665585[274] = 0.0;
   out_3413607092153665585[275] = 0.0;
   out_3413607092153665585[276] = 0.0;
   out_3413607092153665585[277] = 0.0;
   out_3413607092153665585[278] = 0.0;
   out_3413607092153665585[279] = 0.0;
   out_3413607092153665585[280] = 0.0;
   out_3413607092153665585[281] = 0.0;
   out_3413607092153665585[282] = 0.0;
   out_3413607092153665585[283] = 0.0;
   out_3413607092153665585[284] = 0.0;
   out_3413607092153665585[285] = 1.0;
   out_3413607092153665585[286] = 0.0;
   out_3413607092153665585[287] = 0.0;
   out_3413607092153665585[288] = 0.0;
   out_3413607092153665585[289] = 0.0;
   out_3413607092153665585[290] = 0.0;
   out_3413607092153665585[291] = 0.0;
   out_3413607092153665585[292] = 0.0;
   out_3413607092153665585[293] = 0.0;
   out_3413607092153665585[294] = 0.0;
   out_3413607092153665585[295] = 0.0;
   out_3413607092153665585[296] = 0.0;
   out_3413607092153665585[297] = 0.0;
   out_3413607092153665585[298] = 0.0;
   out_3413607092153665585[299] = 0.0;
   out_3413607092153665585[300] = 0.0;
   out_3413607092153665585[301] = 0.0;
   out_3413607092153665585[302] = 0.0;
   out_3413607092153665585[303] = 0.0;
   out_3413607092153665585[304] = 1.0;
   out_3413607092153665585[305] = 0.0;
   out_3413607092153665585[306] = 0.0;
   out_3413607092153665585[307] = 0.0;
   out_3413607092153665585[308] = 0.0;
   out_3413607092153665585[309] = 0.0;
   out_3413607092153665585[310] = 0.0;
   out_3413607092153665585[311] = 0.0;
   out_3413607092153665585[312] = 0.0;
   out_3413607092153665585[313] = 0.0;
   out_3413607092153665585[314] = 0.0;
   out_3413607092153665585[315] = 0.0;
   out_3413607092153665585[316] = 0.0;
   out_3413607092153665585[317] = 0.0;
   out_3413607092153665585[318] = 0.0;
   out_3413607092153665585[319] = 0.0;
   out_3413607092153665585[320] = 0.0;
   out_3413607092153665585[321] = 0.0;
   out_3413607092153665585[322] = 0.0;
   out_3413607092153665585[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2670038371119115624) {
   out_2670038371119115624[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2670038371119115624[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2670038371119115624[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2670038371119115624[3] = dt*state[12] + state[3];
   out_2670038371119115624[4] = dt*state[13] + state[4];
   out_2670038371119115624[5] = dt*state[14] + state[5];
   out_2670038371119115624[6] = state[6];
   out_2670038371119115624[7] = state[7];
   out_2670038371119115624[8] = state[8];
   out_2670038371119115624[9] = state[9];
   out_2670038371119115624[10] = state[10];
   out_2670038371119115624[11] = state[11];
   out_2670038371119115624[12] = state[12];
   out_2670038371119115624[13] = state[13];
   out_2670038371119115624[14] = state[14];
   out_2670038371119115624[15] = state[15];
   out_2670038371119115624[16] = state[16];
   out_2670038371119115624[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6628185752545362634) {
   out_6628185752545362634[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6628185752545362634[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6628185752545362634[2] = 0;
   out_6628185752545362634[3] = 0;
   out_6628185752545362634[4] = 0;
   out_6628185752545362634[5] = 0;
   out_6628185752545362634[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6628185752545362634[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6628185752545362634[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6628185752545362634[9] = 0;
   out_6628185752545362634[10] = 0;
   out_6628185752545362634[11] = 0;
   out_6628185752545362634[12] = 0;
   out_6628185752545362634[13] = 0;
   out_6628185752545362634[14] = 0;
   out_6628185752545362634[15] = 0;
   out_6628185752545362634[16] = 0;
   out_6628185752545362634[17] = 0;
   out_6628185752545362634[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6628185752545362634[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6628185752545362634[20] = 0;
   out_6628185752545362634[21] = 0;
   out_6628185752545362634[22] = 0;
   out_6628185752545362634[23] = 0;
   out_6628185752545362634[24] = 0;
   out_6628185752545362634[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6628185752545362634[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6628185752545362634[27] = 0;
   out_6628185752545362634[28] = 0;
   out_6628185752545362634[29] = 0;
   out_6628185752545362634[30] = 0;
   out_6628185752545362634[31] = 0;
   out_6628185752545362634[32] = 0;
   out_6628185752545362634[33] = 0;
   out_6628185752545362634[34] = 0;
   out_6628185752545362634[35] = 0;
   out_6628185752545362634[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6628185752545362634[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6628185752545362634[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6628185752545362634[39] = 0;
   out_6628185752545362634[40] = 0;
   out_6628185752545362634[41] = 0;
   out_6628185752545362634[42] = 0;
   out_6628185752545362634[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6628185752545362634[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6628185752545362634[45] = 0;
   out_6628185752545362634[46] = 0;
   out_6628185752545362634[47] = 0;
   out_6628185752545362634[48] = 0;
   out_6628185752545362634[49] = 0;
   out_6628185752545362634[50] = 0;
   out_6628185752545362634[51] = 0;
   out_6628185752545362634[52] = 0;
   out_6628185752545362634[53] = 0;
   out_6628185752545362634[54] = 0;
   out_6628185752545362634[55] = 0;
   out_6628185752545362634[56] = 0;
   out_6628185752545362634[57] = 1;
   out_6628185752545362634[58] = 0;
   out_6628185752545362634[59] = 0;
   out_6628185752545362634[60] = 0;
   out_6628185752545362634[61] = 0;
   out_6628185752545362634[62] = 0;
   out_6628185752545362634[63] = 0;
   out_6628185752545362634[64] = 0;
   out_6628185752545362634[65] = 0;
   out_6628185752545362634[66] = dt;
   out_6628185752545362634[67] = 0;
   out_6628185752545362634[68] = 0;
   out_6628185752545362634[69] = 0;
   out_6628185752545362634[70] = 0;
   out_6628185752545362634[71] = 0;
   out_6628185752545362634[72] = 0;
   out_6628185752545362634[73] = 0;
   out_6628185752545362634[74] = 0;
   out_6628185752545362634[75] = 0;
   out_6628185752545362634[76] = 1;
   out_6628185752545362634[77] = 0;
   out_6628185752545362634[78] = 0;
   out_6628185752545362634[79] = 0;
   out_6628185752545362634[80] = 0;
   out_6628185752545362634[81] = 0;
   out_6628185752545362634[82] = 0;
   out_6628185752545362634[83] = 0;
   out_6628185752545362634[84] = 0;
   out_6628185752545362634[85] = dt;
   out_6628185752545362634[86] = 0;
   out_6628185752545362634[87] = 0;
   out_6628185752545362634[88] = 0;
   out_6628185752545362634[89] = 0;
   out_6628185752545362634[90] = 0;
   out_6628185752545362634[91] = 0;
   out_6628185752545362634[92] = 0;
   out_6628185752545362634[93] = 0;
   out_6628185752545362634[94] = 0;
   out_6628185752545362634[95] = 1;
   out_6628185752545362634[96] = 0;
   out_6628185752545362634[97] = 0;
   out_6628185752545362634[98] = 0;
   out_6628185752545362634[99] = 0;
   out_6628185752545362634[100] = 0;
   out_6628185752545362634[101] = 0;
   out_6628185752545362634[102] = 0;
   out_6628185752545362634[103] = 0;
   out_6628185752545362634[104] = dt;
   out_6628185752545362634[105] = 0;
   out_6628185752545362634[106] = 0;
   out_6628185752545362634[107] = 0;
   out_6628185752545362634[108] = 0;
   out_6628185752545362634[109] = 0;
   out_6628185752545362634[110] = 0;
   out_6628185752545362634[111] = 0;
   out_6628185752545362634[112] = 0;
   out_6628185752545362634[113] = 0;
   out_6628185752545362634[114] = 1;
   out_6628185752545362634[115] = 0;
   out_6628185752545362634[116] = 0;
   out_6628185752545362634[117] = 0;
   out_6628185752545362634[118] = 0;
   out_6628185752545362634[119] = 0;
   out_6628185752545362634[120] = 0;
   out_6628185752545362634[121] = 0;
   out_6628185752545362634[122] = 0;
   out_6628185752545362634[123] = 0;
   out_6628185752545362634[124] = 0;
   out_6628185752545362634[125] = 0;
   out_6628185752545362634[126] = 0;
   out_6628185752545362634[127] = 0;
   out_6628185752545362634[128] = 0;
   out_6628185752545362634[129] = 0;
   out_6628185752545362634[130] = 0;
   out_6628185752545362634[131] = 0;
   out_6628185752545362634[132] = 0;
   out_6628185752545362634[133] = 1;
   out_6628185752545362634[134] = 0;
   out_6628185752545362634[135] = 0;
   out_6628185752545362634[136] = 0;
   out_6628185752545362634[137] = 0;
   out_6628185752545362634[138] = 0;
   out_6628185752545362634[139] = 0;
   out_6628185752545362634[140] = 0;
   out_6628185752545362634[141] = 0;
   out_6628185752545362634[142] = 0;
   out_6628185752545362634[143] = 0;
   out_6628185752545362634[144] = 0;
   out_6628185752545362634[145] = 0;
   out_6628185752545362634[146] = 0;
   out_6628185752545362634[147] = 0;
   out_6628185752545362634[148] = 0;
   out_6628185752545362634[149] = 0;
   out_6628185752545362634[150] = 0;
   out_6628185752545362634[151] = 0;
   out_6628185752545362634[152] = 1;
   out_6628185752545362634[153] = 0;
   out_6628185752545362634[154] = 0;
   out_6628185752545362634[155] = 0;
   out_6628185752545362634[156] = 0;
   out_6628185752545362634[157] = 0;
   out_6628185752545362634[158] = 0;
   out_6628185752545362634[159] = 0;
   out_6628185752545362634[160] = 0;
   out_6628185752545362634[161] = 0;
   out_6628185752545362634[162] = 0;
   out_6628185752545362634[163] = 0;
   out_6628185752545362634[164] = 0;
   out_6628185752545362634[165] = 0;
   out_6628185752545362634[166] = 0;
   out_6628185752545362634[167] = 0;
   out_6628185752545362634[168] = 0;
   out_6628185752545362634[169] = 0;
   out_6628185752545362634[170] = 0;
   out_6628185752545362634[171] = 1;
   out_6628185752545362634[172] = 0;
   out_6628185752545362634[173] = 0;
   out_6628185752545362634[174] = 0;
   out_6628185752545362634[175] = 0;
   out_6628185752545362634[176] = 0;
   out_6628185752545362634[177] = 0;
   out_6628185752545362634[178] = 0;
   out_6628185752545362634[179] = 0;
   out_6628185752545362634[180] = 0;
   out_6628185752545362634[181] = 0;
   out_6628185752545362634[182] = 0;
   out_6628185752545362634[183] = 0;
   out_6628185752545362634[184] = 0;
   out_6628185752545362634[185] = 0;
   out_6628185752545362634[186] = 0;
   out_6628185752545362634[187] = 0;
   out_6628185752545362634[188] = 0;
   out_6628185752545362634[189] = 0;
   out_6628185752545362634[190] = 1;
   out_6628185752545362634[191] = 0;
   out_6628185752545362634[192] = 0;
   out_6628185752545362634[193] = 0;
   out_6628185752545362634[194] = 0;
   out_6628185752545362634[195] = 0;
   out_6628185752545362634[196] = 0;
   out_6628185752545362634[197] = 0;
   out_6628185752545362634[198] = 0;
   out_6628185752545362634[199] = 0;
   out_6628185752545362634[200] = 0;
   out_6628185752545362634[201] = 0;
   out_6628185752545362634[202] = 0;
   out_6628185752545362634[203] = 0;
   out_6628185752545362634[204] = 0;
   out_6628185752545362634[205] = 0;
   out_6628185752545362634[206] = 0;
   out_6628185752545362634[207] = 0;
   out_6628185752545362634[208] = 0;
   out_6628185752545362634[209] = 1;
   out_6628185752545362634[210] = 0;
   out_6628185752545362634[211] = 0;
   out_6628185752545362634[212] = 0;
   out_6628185752545362634[213] = 0;
   out_6628185752545362634[214] = 0;
   out_6628185752545362634[215] = 0;
   out_6628185752545362634[216] = 0;
   out_6628185752545362634[217] = 0;
   out_6628185752545362634[218] = 0;
   out_6628185752545362634[219] = 0;
   out_6628185752545362634[220] = 0;
   out_6628185752545362634[221] = 0;
   out_6628185752545362634[222] = 0;
   out_6628185752545362634[223] = 0;
   out_6628185752545362634[224] = 0;
   out_6628185752545362634[225] = 0;
   out_6628185752545362634[226] = 0;
   out_6628185752545362634[227] = 0;
   out_6628185752545362634[228] = 1;
   out_6628185752545362634[229] = 0;
   out_6628185752545362634[230] = 0;
   out_6628185752545362634[231] = 0;
   out_6628185752545362634[232] = 0;
   out_6628185752545362634[233] = 0;
   out_6628185752545362634[234] = 0;
   out_6628185752545362634[235] = 0;
   out_6628185752545362634[236] = 0;
   out_6628185752545362634[237] = 0;
   out_6628185752545362634[238] = 0;
   out_6628185752545362634[239] = 0;
   out_6628185752545362634[240] = 0;
   out_6628185752545362634[241] = 0;
   out_6628185752545362634[242] = 0;
   out_6628185752545362634[243] = 0;
   out_6628185752545362634[244] = 0;
   out_6628185752545362634[245] = 0;
   out_6628185752545362634[246] = 0;
   out_6628185752545362634[247] = 1;
   out_6628185752545362634[248] = 0;
   out_6628185752545362634[249] = 0;
   out_6628185752545362634[250] = 0;
   out_6628185752545362634[251] = 0;
   out_6628185752545362634[252] = 0;
   out_6628185752545362634[253] = 0;
   out_6628185752545362634[254] = 0;
   out_6628185752545362634[255] = 0;
   out_6628185752545362634[256] = 0;
   out_6628185752545362634[257] = 0;
   out_6628185752545362634[258] = 0;
   out_6628185752545362634[259] = 0;
   out_6628185752545362634[260] = 0;
   out_6628185752545362634[261] = 0;
   out_6628185752545362634[262] = 0;
   out_6628185752545362634[263] = 0;
   out_6628185752545362634[264] = 0;
   out_6628185752545362634[265] = 0;
   out_6628185752545362634[266] = 1;
   out_6628185752545362634[267] = 0;
   out_6628185752545362634[268] = 0;
   out_6628185752545362634[269] = 0;
   out_6628185752545362634[270] = 0;
   out_6628185752545362634[271] = 0;
   out_6628185752545362634[272] = 0;
   out_6628185752545362634[273] = 0;
   out_6628185752545362634[274] = 0;
   out_6628185752545362634[275] = 0;
   out_6628185752545362634[276] = 0;
   out_6628185752545362634[277] = 0;
   out_6628185752545362634[278] = 0;
   out_6628185752545362634[279] = 0;
   out_6628185752545362634[280] = 0;
   out_6628185752545362634[281] = 0;
   out_6628185752545362634[282] = 0;
   out_6628185752545362634[283] = 0;
   out_6628185752545362634[284] = 0;
   out_6628185752545362634[285] = 1;
   out_6628185752545362634[286] = 0;
   out_6628185752545362634[287] = 0;
   out_6628185752545362634[288] = 0;
   out_6628185752545362634[289] = 0;
   out_6628185752545362634[290] = 0;
   out_6628185752545362634[291] = 0;
   out_6628185752545362634[292] = 0;
   out_6628185752545362634[293] = 0;
   out_6628185752545362634[294] = 0;
   out_6628185752545362634[295] = 0;
   out_6628185752545362634[296] = 0;
   out_6628185752545362634[297] = 0;
   out_6628185752545362634[298] = 0;
   out_6628185752545362634[299] = 0;
   out_6628185752545362634[300] = 0;
   out_6628185752545362634[301] = 0;
   out_6628185752545362634[302] = 0;
   out_6628185752545362634[303] = 0;
   out_6628185752545362634[304] = 1;
   out_6628185752545362634[305] = 0;
   out_6628185752545362634[306] = 0;
   out_6628185752545362634[307] = 0;
   out_6628185752545362634[308] = 0;
   out_6628185752545362634[309] = 0;
   out_6628185752545362634[310] = 0;
   out_6628185752545362634[311] = 0;
   out_6628185752545362634[312] = 0;
   out_6628185752545362634[313] = 0;
   out_6628185752545362634[314] = 0;
   out_6628185752545362634[315] = 0;
   out_6628185752545362634[316] = 0;
   out_6628185752545362634[317] = 0;
   out_6628185752545362634[318] = 0;
   out_6628185752545362634[319] = 0;
   out_6628185752545362634[320] = 0;
   out_6628185752545362634[321] = 0;
   out_6628185752545362634[322] = 0;
   out_6628185752545362634[323] = 1;
}
void h_4(double *state, double *unused, double *out_1095094246816165977) {
   out_1095094246816165977[0] = state[6] + state[9];
   out_1095094246816165977[1] = state[7] + state[10];
   out_1095094246816165977[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_5530754573904155757) {
   out_5530754573904155757[0] = 0;
   out_5530754573904155757[1] = 0;
   out_5530754573904155757[2] = 0;
   out_5530754573904155757[3] = 0;
   out_5530754573904155757[4] = 0;
   out_5530754573904155757[5] = 0;
   out_5530754573904155757[6] = 1;
   out_5530754573904155757[7] = 0;
   out_5530754573904155757[8] = 0;
   out_5530754573904155757[9] = 1;
   out_5530754573904155757[10] = 0;
   out_5530754573904155757[11] = 0;
   out_5530754573904155757[12] = 0;
   out_5530754573904155757[13] = 0;
   out_5530754573904155757[14] = 0;
   out_5530754573904155757[15] = 0;
   out_5530754573904155757[16] = 0;
   out_5530754573904155757[17] = 0;
   out_5530754573904155757[18] = 0;
   out_5530754573904155757[19] = 0;
   out_5530754573904155757[20] = 0;
   out_5530754573904155757[21] = 0;
   out_5530754573904155757[22] = 0;
   out_5530754573904155757[23] = 0;
   out_5530754573904155757[24] = 0;
   out_5530754573904155757[25] = 1;
   out_5530754573904155757[26] = 0;
   out_5530754573904155757[27] = 0;
   out_5530754573904155757[28] = 1;
   out_5530754573904155757[29] = 0;
   out_5530754573904155757[30] = 0;
   out_5530754573904155757[31] = 0;
   out_5530754573904155757[32] = 0;
   out_5530754573904155757[33] = 0;
   out_5530754573904155757[34] = 0;
   out_5530754573904155757[35] = 0;
   out_5530754573904155757[36] = 0;
   out_5530754573904155757[37] = 0;
   out_5530754573904155757[38] = 0;
   out_5530754573904155757[39] = 0;
   out_5530754573904155757[40] = 0;
   out_5530754573904155757[41] = 0;
   out_5530754573904155757[42] = 0;
   out_5530754573904155757[43] = 0;
   out_5530754573904155757[44] = 1;
   out_5530754573904155757[45] = 0;
   out_5530754573904155757[46] = 0;
   out_5530754573904155757[47] = 1;
   out_5530754573904155757[48] = 0;
   out_5530754573904155757[49] = 0;
   out_5530754573904155757[50] = 0;
   out_5530754573904155757[51] = 0;
   out_5530754573904155757[52] = 0;
   out_5530754573904155757[53] = 0;
}
void h_10(double *state, double *unused, double *out_6379475221413403009) {
   out_6379475221413403009[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_6379475221413403009[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_6379475221413403009[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4074749303757361303) {
   out_4074749303757361303[0] = 0;
   out_4074749303757361303[1] = 9.8100000000000005*cos(state[1]);
   out_4074749303757361303[2] = 0;
   out_4074749303757361303[3] = 0;
   out_4074749303757361303[4] = -state[8];
   out_4074749303757361303[5] = state[7];
   out_4074749303757361303[6] = 0;
   out_4074749303757361303[7] = state[5];
   out_4074749303757361303[8] = -state[4];
   out_4074749303757361303[9] = 0;
   out_4074749303757361303[10] = 0;
   out_4074749303757361303[11] = 0;
   out_4074749303757361303[12] = 1;
   out_4074749303757361303[13] = 0;
   out_4074749303757361303[14] = 0;
   out_4074749303757361303[15] = 1;
   out_4074749303757361303[16] = 0;
   out_4074749303757361303[17] = 0;
   out_4074749303757361303[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4074749303757361303[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4074749303757361303[20] = 0;
   out_4074749303757361303[21] = state[8];
   out_4074749303757361303[22] = 0;
   out_4074749303757361303[23] = -state[6];
   out_4074749303757361303[24] = -state[5];
   out_4074749303757361303[25] = 0;
   out_4074749303757361303[26] = state[3];
   out_4074749303757361303[27] = 0;
   out_4074749303757361303[28] = 0;
   out_4074749303757361303[29] = 0;
   out_4074749303757361303[30] = 0;
   out_4074749303757361303[31] = 1;
   out_4074749303757361303[32] = 0;
   out_4074749303757361303[33] = 0;
   out_4074749303757361303[34] = 1;
   out_4074749303757361303[35] = 0;
   out_4074749303757361303[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4074749303757361303[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4074749303757361303[38] = 0;
   out_4074749303757361303[39] = -state[7];
   out_4074749303757361303[40] = state[6];
   out_4074749303757361303[41] = 0;
   out_4074749303757361303[42] = state[4];
   out_4074749303757361303[43] = -state[3];
   out_4074749303757361303[44] = 0;
   out_4074749303757361303[45] = 0;
   out_4074749303757361303[46] = 0;
   out_4074749303757361303[47] = 0;
   out_4074749303757361303[48] = 0;
   out_4074749303757361303[49] = 0;
   out_4074749303757361303[50] = 1;
   out_4074749303757361303[51] = 0;
   out_4074749303757361303[52] = 0;
   out_4074749303757361303[53] = 1;
}
void h_13(double *state, double *unused, double *out_193722928821992681) {
   out_193722928821992681[0] = state[3];
   out_193722928821992681[1] = state[4];
   out_193722928821992681[2] = state[5];
}
void H_13(double *state, double *unused, double *out_9082234036502871835) {
   out_9082234036502871835[0] = 0;
   out_9082234036502871835[1] = 0;
   out_9082234036502871835[2] = 0;
   out_9082234036502871835[3] = 1;
   out_9082234036502871835[4] = 0;
   out_9082234036502871835[5] = 0;
   out_9082234036502871835[6] = 0;
   out_9082234036502871835[7] = 0;
   out_9082234036502871835[8] = 0;
   out_9082234036502871835[9] = 0;
   out_9082234036502871835[10] = 0;
   out_9082234036502871835[11] = 0;
   out_9082234036502871835[12] = 0;
   out_9082234036502871835[13] = 0;
   out_9082234036502871835[14] = 0;
   out_9082234036502871835[15] = 0;
   out_9082234036502871835[16] = 0;
   out_9082234036502871835[17] = 0;
   out_9082234036502871835[18] = 0;
   out_9082234036502871835[19] = 0;
   out_9082234036502871835[20] = 0;
   out_9082234036502871835[21] = 0;
   out_9082234036502871835[22] = 1;
   out_9082234036502871835[23] = 0;
   out_9082234036502871835[24] = 0;
   out_9082234036502871835[25] = 0;
   out_9082234036502871835[26] = 0;
   out_9082234036502871835[27] = 0;
   out_9082234036502871835[28] = 0;
   out_9082234036502871835[29] = 0;
   out_9082234036502871835[30] = 0;
   out_9082234036502871835[31] = 0;
   out_9082234036502871835[32] = 0;
   out_9082234036502871835[33] = 0;
   out_9082234036502871835[34] = 0;
   out_9082234036502871835[35] = 0;
   out_9082234036502871835[36] = 0;
   out_9082234036502871835[37] = 0;
   out_9082234036502871835[38] = 0;
   out_9082234036502871835[39] = 0;
   out_9082234036502871835[40] = 0;
   out_9082234036502871835[41] = 1;
   out_9082234036502871835[42] = 0;
   out_9082234036502871835[43] = 0;
   out_9082234036502871835[44] = 0;
   out_9082234036502871835[45] = 0;
   out_9082234036502871835[46] = 0;
   out_9082234036502871835[47] = 0;
   out_9082234036502871835[48] = 0;
   out_9082234036502871835[49] = 0;
   out_9082234036502871835[50] = 0;
   out_9082234036502871835[51] = 0;
   out_9082234036502871835[52] = 0;
   out_9082234036502871835[53] = 0;
}
void h_14(double *state, double *unused, double *out_9219347760475627175) {
   out_9219347760475627175[0] = state[6];
   out_9219347760475627175[1] = state[7];
   out_9219347760475627175[2] = state[8];
}
void H_14(double *state, double *unused, double *out_8613543006199528053) {
   out_8613543006199528053[0] = 0;
   out_8613543006199528053[1] = 0;
   out_8613543006199528053[2] = 0;
   out_8613543006199528053[3] = 0;
   out_8613543006199528053[4] = 0;
   out_8613543006199528053[5] = 0;
   out_8613543006199528053[6] = 1;
   out_8613543006199528053[7] = 0;
   out_8613543006199528053[8] = 0;
   out_8613543006199528053[9] = 0;
   out_8613543006199528053[10] = 0;
   out_8613543006199528053[11] = 0;
   out_8613543006199528053[12] = 0;
   out_8613543006199528053[13] = 0;
   out_8613543006199528053[14] = 0;
   out_8613543006199528053[15] = 0;
   out_8613543006199528053[16] = 0;
   out_8613543006199528053[17] = 0;
   out_8613543006199528053[18] = 0;
   out_8613543006199528053[19] = 0;
   out_8613543006199528053[20] = 0;
   out_8613543006199528053[21] = 0;
   out_8613543006199528053[22] = 0;
   out_8613543006199528053[23] = 0;
   out_8613543006199528053[24] = 0;
   out_8613543006199528053[25] = 1;
   out_8613543006199528053[26] = 0;
   out_8613543006199528053[27] = 0;
   out_8613543006199528053[28] = 0;
   out_8613543006199528053[29] = 0;
   out_8613543006199528053[30] = 0;
   out_8613543006199528053[31] = 0;
   out_8613543006199528053[32] = 0;
   out_8613543006199528053[33] = 0;
   out_8613543006199528053[34] = 0;
   out_8613543006199528053[35] = 0;
   out_8613543006199528053[36] = 0;
   out_8613543006199528053[37] = 0;
   out_8613543006199528053[38] = 0;
   out_8613543006199528053[39] = 0;
   out_8613543006199528053[40] = 0;
   out_8613543006199528053[41] = 0;
   out_8613543006199528053[42] = 0;
   out_8613543006199528053[43] = 0;
   out_8613543006199528053[44] = 1;
   out_8613543006199528053[45] = 0;
   out_8613543006199528053[46] = 0;
   out_8613543006199528053[47] = 0;
   out_8613543006199528053[48] = 0;
   out_8613543006199528053[49] = 0;
   out_8613543006199528053[50] = 0;
   out_8613543006199528053[51] = 0;
   out_8613543006199528053[52] = 0;
   out_8613543006199528053[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_38746564740330454) {
  err_fun(nom_x, delta_x, out_38746564740330454);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7177343441098663951) {
  inv_err_fun(nom_x, true_x, out_7177343441098663951);
}
void pose_H_mod_fun(double *state, double *out_3413607092153665585) {
  H_mod_fun(state, out_3413607092153665585);
}
void pose_f_fun(double *state, double dt, double *out_2670038371119115624) {
  f_fun(state,  dt, out_2670038371119115624);
}
void pose_F_fun(double *state, double dt, double *out_6628185752545362634) {
  F_fun(state,  dt, out_6628185752545362634);
}
void pose_h_4(double *state, double *unused, double *out_1095094246816165977) {
  h_4(state, unused, out_1095094246816165977);
}
void pose_H_4(double *state, double *unused, double *out_5530754573904155757) {
  H_4(state, unused, out_5530754573904155757);
}
void pose_h_10(double *state, double *unused, double *out_6379475221413403009) {
  h_10(state, unused, out_6379475221413403009);
}
void pose_H_10(double *state, double *unused, double *out_4074749303757361303) {
  H_10(state, unused, out_4074749303757361303);
}
void pose_h_13(double *state, double *unused, double *out_193722928821992681) {
  h_13(state, unused, out_193722928821992681);
}
void pose_H_13(double *state, double *unused, double *out_9082234036502871835) {
  H_13(state, unused, out_9082234036502871835);
}
void pose_h_14(double *state, double *unused, double *out_9219347760475627175) {
  h_14(state, unused, out_9219347760475627175);
}
void pose_H_14(double *state, double *unused, double *out_8613543006199528053) {
  H_14(state, unused, out_8613543006199528053);
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
