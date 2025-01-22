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
void err_fun(double *nom_x, double *delta_x, double *out_582162479678847507) {
   out_582162479678847507[0] = delta_x[0] + nom_x[0];
   out_582162479678847507[1] = delta_x[1] + nom_x[1];
   out_582162479678847507[2] = delta_x[2] + nom_x[2];
   out_582162479678847507[3] = delta_x[3] + nom_x[3];
   out_582162479678847507[4] = delta_x[4] + nom_x[4];
   out_582162479678847507[5] = delta_x[5] + nom_x[5];
   out_582162479678847507[6] = delta_x[6] + nom_x[6];
   out_582162479678847507[7] = delta_x[7] + nom_x[7];
   out_582162479678847507[8] = delta_x[8] + nom_x[8];
   out_582162479678847507[9] = delta_x[9] + nom_x[9];
   out_582162479678847507[10] = delta_x[10] + nom_x[10];
   out_582162479678847507[11] = delta_x[11] + nom_x[11];
   out_582162479678847507[12] = delta_x[12] + nom_x[12];
   out_582162479678847507[13] = delta_x[13] + nom_x[13];
   out_582162479678847507[14] = delta_x[14] + nom_x[14];
   out_582162479678847507[15] = delta_x[15] + nom_x[15];
   out_582162479678847507[16] = delta_x[16] + nom_x[16];
   out_582162479678847507[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8183002877435981990) {
   out_8183002877435981990[0] = -nom_x[0] + true_x[0];
   out_8183002877435981990[1] = -nom_x[1] + true_x[1];
   out_8183002877435981990[2] = -nom_x[2] + true_x[2];
   out_8183002877435981990[3] = -nom_x[3] + true_x[3];
   out_8183002877435981990[4] = -nom_x[4] + true_x[4];
   out_8183002877435981990[5] = -nom_x[5] + true_x[5];
   out_8183002877435981990[6] = -nom_x[6] + true_x[6];
   out_8183002877435981990[7] = -nom_x[7] + true_x[7];
   out_8183002877435981990[8] = -nom_x[8] + true_x[8];
   out_8183002877435981990[9] = -nom_x[9] + true_x[9];
   out_8183002877435981990[10] = -nom_x[10] + true_x[10];
   out_8183002877435981990[11] = -nom_x[11] + true_x[11];
   out_8183002877435981990[12] = -nom_x[12] + true_x[12];
   out_8183002877435981990[13] = -nom_x[13] + true_x[13];
   out_8183002877435981990[14] = -nom_x[14] + true_x[14];
   out_8183002877435981990[15] = -nom_x[15] + true_x[15];
   out_8183002877435981990[16] = -nom_x[16] + true_x[16];
   out_8183002877435981990[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_721764794937271849) {
   out_721764794937271849[0] = 1.0;
   out_721764794937271849[1] = 0.0;
   out_721764794937271849[2] = 0.0;
   out_721764794937271849[3] = 0.0;
   out_721764794937271849[4] = 0.0;
   out_721764794937271849[5] = 0.0;
   out_721764794937271849[6] = 0.0;
   out_721764794937271849[7] = 0.0;
   out_721764794937271849[8] = 0.0;
   out_721764794937271849[9] = 0.0;
   out_721764794937271849[10] = 0.0;
   out_721764794937271849[11] = 0.0;
   out_721764794937271849[12] = 0.0;
   out_721764794937271849[13] = 0.0;
   out_721764794937271849[14] = 0.0;
   out_721764794937271849[15] = 0.0;
   out_721764794937271849[16] = 0.0;
   out_721764794937271849[17] = 0.0;
   out_721764794937271849[18] = 0.0;
   out_721764794937271849[19] = 1.0;
   out_721764794937271849[20] = 0.0;
   out_721764794937271849[21] = 0.0;
   out_721764794937271849[22] = 0.0;
   out_721764794937271849[23] = 0.0;
   out_721764794937271849[24] = 0.0;
   out_721764794937271849[25] = 0.0;
   out_721764794937271849[26] = 0.0;
   out_721764794937271849[27] = 0.0;
   out_721764794937271849[28] = 0.0;
   out_721764794937271849[29] = 0.0;
   out_721764794937271849[30] = 0.0;
   out_721764794937271849[31] = 0.0;
   out_721764794937271849[32] = 0.0;
   out_721764794937271849[33] = 0.0;
   out_721764794937271849[34] = 0.0;
   out_721764794937271849[35] = 0.0;
   out_721764794937271849[36] = 0.0;
   out_721764794937271849[37] = 0.0;
   out_721764794937271849[38] = 1.0;
   out_721764794937271849[39] = 0.0;
   out_721764794937271849[40] = 0.0;
   out_721764794937271849[41] = 0.0;
   out_721764794937271849[42] = 0.0;
   out_721764794937271849[43] = 0.0;
   out_721764794937271849[44] = 0.0;
   out_721764794937271849[45] = 0.0;
   out_721764794937271849[46] = 0.0;
   out_721764794937271849[47] = 0.0;
   out_721764794937271849[48] = 0.0;
   out_721764794937271849[49] = 0.0;
   out_721764794937271849[50] = 0.0;
   out_721764794937271849[51] = 0.0;
   out_721764794937271849[52] = 0.0;
   out_721764794937271849[53] = 0.0;
   out_721764794937271849[54] = 0.0;
   out_721764794937271849[55] = 0.0;
   out_721764794937271849[56] = 0.0;
   out_721764794937271849[57] = 1.0;
   out_721764794937271849[58] = 0.0;
   out_721764794937271849[59] = 0.0;
   out_721764794937271849[60] = 0.0;
   out_721764794937271849[61] = 0.0;
   out_721764794937271849[62] = 0.0;
   out_721764794937271849[63] = 0.0;
   out_721764794937271849[64] = 0.0;
   out_721764794937271849[65] = 0.0;
   out_721764794937271849[66] = 0.0;
   out_721764794937271849[67] = 0.0;
   out_721764794937271849[68] = 0.0;
   out_721764794937271849[69] = 0.0;
   out_721764794937271849[70] = 0.0;
   out_721764794937271849[71] = 0.0;
   out_721764794937271849[72] = 0.0;
   out_721764794937271849[73] = 0.0;
   out_721764794937271849[74] = 0.0;
   out_721764794937271849[75] = 0.0;
   out_721764794937271849[76] = 1.0;
   out_721764794937271849[77] = 0.0;
   out_721764794937271849[78] = 0.0;
   out_721764794937271849[79] = 0.0;
   out_721764794937271849[80] = 0.0;
   out_721764794937271849[81] = 0.0;
   out_721764794937271849[82] = 0.0;
   out_721764794937271849[83] = 0.0;
   out_721764794937271849[84] = 0.0;
   out_721764794937271849[85] = 0.0;
   out_721764794937271849[86] = 0.0;
   out_721764794937271849[87] = 0.0;
   out_721764794937271849[88] = 0.0;
   out_721764794937271849[89] = 0.0;
   out_721764794937271849[90] = 0.0;
   out_721764794937271849[91] = 0.0;
   out_721764794937271849[92] = 0.0;
   out_721764794937271849[93] = 0.0;
   out_721764794937271849[94] = 0.0;
   out_721764794937271849[95] = 1.0;
   out_721764794937271849[96] = 0.0;
   out_721764794937271849[97] = 0.0;
   out_721764794937271849[98] = 0.0;
   out_721764794937271849[99] = 0.0;
   out_721764794937271849[100] = 0.0;
   out_721764794937271849[101] = 0.0;
   out_721764794937271849[102] = 0.0;
   out_721764794937271849[103] = 0.0;
   out_721764794937271849[104] = 0.0;
   out_721764794937271849[105] = 0.0;
   out_721764794937271849[106] = 0.0;
   out_721764794937271849[107] = 0.0;
   out_721764794937271849[108] = 0.0;
   out_721764794937271849[109] = 0.0;
   out_721764794937271849[110] = 0.0;
   out_721764794937271849[111] = 0.0;
   out_721764794937271849[112] = 0.0;
   out_721764794937271849[113] = 0.0;
   out_721764794937271849[114] = 1.0;
   out_721764794937271849[115] = 0.0;
   out_721764794937271849[116] = 0.0;
   out_721764794937271849[117] = 0.0;
   out_721764794937271849[118] = 0.0;
   out_721764794937271849[119] = 0.0;
   out_721764794937271849[120] = 0.0;
   out_721764794937271849[121] = 0.0;
   out_721764794937271849[122] = 0.0;
   out_721764794937271849[123] = 0.0;
   out_721764794937271849[124] = 0.0;
   out_721764794937271849[125] = 0.0;
   out_721764794937271849[126] = 0.0;
   out_721764794937271849[127] = 0.0;
   out_721764794937271849[128] = 0.0;
   out_721764794937271849[129] = 0.0;
   out_721764794937271849[130] = 0.0;
   out_721764794937271849[131] = 0.0;
   out_721764794937271849[132] = 0.0;
   out_721764794937271849[133] = 1.0;
   out_721764794937271849[134] = 0.0;
   out_721764794937271849[135] = 0.0;
   out_721764794937271849[136] = 0.0;
   out_721764794937271849[137] = 0.0;
   out_721764794937271849[138] = 0.0;
   out_721764794937271849[139] = 0.0;
   out_721764794937271849[140] = 0.0;
   out_721764794937271849[141] = 0.0;
   out_721764794937271849[142] = 0.0;
   out_721764794937271849[143] = 0.0;
   out_721764794937271849[144] = 0.0;
   out_721764794937271849[145] = 0.0;
   out_721764794937271849[146] = 0.0;
   out_721764794937271849[147] = 0.0;
   out_721764794937271849[148] = 0.0;
   out_721764794937271849[149] = 0.0;
   out_721764794937271849[150] = 0.0;
   out_721764794937271849[151] = 0.0;
   out_721764794937271849[152] = 1.0;
   out_721764794937271849[153] = 0.0;
   out_721764794937271849[154] = 0.0;
   out_721764794937271849[155] = 0.0;
   out_721764794937271849[156] = 0.0;
   out_721764794937271849[157] = 0.0;
   out_721764794937271849[158] = 0.0;
   out_721764794937271849[159] = 0.0;
   out_721764794937271849[160] = 0.0;
   out_721764794937271849[161] = 0.0;
   out_721764794937271849[162] = 0.0;
   out_721764794937271849[163] = 0.0;
   out_721764794937271849[164] = 0.0;
   out_721764794937271849[165] = 0.0;
   out_721764794937271849[166] = 0.0;
   out_721764794937271849[167] = 0.0;
   out_721764794937271849[168] = 0.0;
   out_721764794937271849[169] = 0.0;
   out_721764794937271849[170] = 0.0;
   out_721764794937271849[171] = 1.0;
   out_721764794937271849[172] = 0.0;
   out_721764794937271849[173] = 0.0;
   out_721764794937271849[174] = 0.0;
   out_721764794937271849[175] = 0.0;
   out_721764794937271849[176] = 0.0;
   out_721764794937271849[177] = 0.0;
   out_721764794937271849[178] = 0.0;
   out_721764794937271849[179] = 0.0;
   out_721764794937271849[180] = 0.0;
   out_721764794937271849[181] = 0.0;
   out_721764794937271849[182] = 0.0;
   out_721764794937271849[183] = 0.0;
   out_721764794937271849[184] = 0.0;
   out_721764794937271849[185] = 0.0;
   out_721764794937271849[186] = 0.0;
   out_721764794937271849[187] = 0.0;
   out_721764794937271849[188] = 0.0;
   out_721764794937271849[189] = 0.0;
   out_721764794937271849[190] = 1.0;
   out_721764794937271849[191] = 0.0;
   out_721764794937271849[192] = 0.0;
   out_721764794937271849[193] = 0.0;
   out_721764794937271849[194] = 0.0;
   out_721764794937271849[195] = 0.0;
   out_721764794937271849[196] = 0.0;
   out_721764794937271849[197] = 0.0;
   out_721764794937271849[198] = 0.0;
   out_721764794937271849[199] = 0.0;
   out_721764794937271849[200] = 0.0;
   out_721764794937271849[201] = 0.0;
   out_721764794937271849[202] = 0.0;
   out_721764794937271849[203] = 0.0;
   out_721764794937271849[204] = 0.0;
   out_721764794937271849[205] = 0.0;
   out_721764794937271849[206] = 0.0;
   out_721764794937271849[207] = 0.0;
   out_721764794937271849[208] = 0.0;
   out_721764794937271849[209] = 1.0;
   out_721764794937271849[210] = 0.0;
   out_721764794937271849[211] = 0.0;
   out_721764794937271849[212] = 0.0;
   out_721764794937271849[213] = 0.0;
   out_721764794937271849[214] = 0.0;
   out_721764794937271849[215] = 0.0;
   out_721764794937271849[216] = 0.0;
   out_721764794937271849[217] = 0.0;
   out_721764794937271849[218] = 0.0;
   out_721764794937271849[219] = 0.0;
   out_721764794937271849[220] = 0.0;
   out_721764794937271849[221] = 0.0;
   out_721764794937271849[222] = 0.0;
   out_721764794937271849[223] = 0.0;
   out_721764794937271849[224] = 0.0;
   out_721764794937271849[225] = 0.0;
   out_721764794937271849[226] = 0.0;
   out_721764794937271849[227] = 0.0;
   out_721764794937271849[228] = 1.0;
   out_721764794937271849[229] = 0.0;
   out_721764794937271849[230] = 0.0;
   out_721764794937271849[231] = 0.0;
   out_721764794937271849[232] = 0.0;
   out_721764794937271849[233] = 0.0;
   out_721764794937271849[234] = 0.0;
   out_721764794937271849[235] = 0.0;
   out_721764794937271849[236] = 0.0;
   out_721764794937271849[237] = 0.0;
   out_721764794937271849[238] = 0.0;
   out_721764794937271849[239] = 0.0;
   out_721764794937271849[240] = 0.0;
   out_721764794937271849[241] = 0.0;
   out_721764794937271849[242] = 0.0;
   out_721764794937271849[243] = 0.0;
   out_721764794937271849[244] = 0.0;
   out_721764794937271849[245] = 0.0;
   out_721764794937271849[246] = 0.0;
   out_721764794937271849[247] = 1.0;
   out_721764794937271849[248] = 0.0;
   out_721764794937271849[249] = 0.0;
   out_721764794937271849[250] = 0.0;
   out_721764794937271849[251] = 0.0;
   out_721764794937271849[252] = 0.0;
   out_721764794937271849[253] = 0.0;
   out_721764794937271849[254] = 0.0;
   out_721764794937271849[255] = 0.0;
   out_721764794937271849[256] = 0.0;
   out_721764794937271849[257] = 0.0;
   out_721764794937271849[258] = 0.0;
   out_721764794937271849[259] = 0.0;
   out_721764794937271849[260] = 0.0;
   out_721764794937271849[261] = 0.0;
   out_721764794937271849[262] = 0.0;
   out_721764794937271849[263] = 0.0;
   out_721764794937271849[264] = 0.0;
   out_721764794937271849[265] = 0.0;
   out_721764794937271849[266] = 1.0;
   out_721764794937271849[267] = 0.0;
   out_721764794937271849[268] = 0.0;
   out_721764794937271849[269] = 0.0;
   out_721764794937271849[270] = 0.0;
   out_721764794937271849[271] = 0.0;
   out_721764794937271849[272] = 0.0;
   out_721764794937271849[273] = 0.0;
   out_721764794937271849[274] = 0.0;
   out_721764794937271849[275] = 0.0;
   out_721764794937271849[276] = 0.0;
   out_721764794937271849[277] = 0.0;
   out_721764794937271849[278] = 0.0;
   out_721764794937271849[279] = 0.0;
   out_721764794937271849[280] = 0.0;
   out_721764794937271849[281] = 0.0;
   out_721764794937271849[282] = 0.0;
   out_721764794937271849[283] = 0.0;
   out_721764794937271849[284] = 0.0;
   out_721764794937271849[285] = 1.0;
   out_721764794937271849[286] = 0.0;
   out_721764794937271849[287] = 0.0;
   out_721764794937271849[288] = 0.0;
   out_721764794937271849[289] = 0.0;
   out_721764794937271849[290] = 0.0;
   out_721764794937271849[291] = 0.0;
   out_721764794937271849[292] = 0.0;
   out_721764794937271849[293] = 0.0;
   out_721764794937271849[294] = 0.0;
   out_721764794937271849[295] = 0.0;
   out_721764794937271849[296] = 0.0;
   out_721764794937271849[297] = 0.0;
   out_721764794937271849[298] = 0.0;
   out_721764794937271849[299] = 0.0;
   out_721764794937271849[300] = 0.0;
   out_721764794937271849[301] = 0.0;
   out_721764794937271849[302] = 0.0;
   out_721764794937271849[303] = 0.0;
   out_721764794937271849[304] = 1.0;
   out_721764794937271849[305] = 0.0;
   out_721764794937271849[306] = 0.0;
   out_721764794937271849[307] = 0.0;
   out_721764794937271849[308] = 0.0;
   out_721764794937271849[309] = 0.0;
   out_721764794937271849[310] = 0.0;
   out_721764794937271849[311] = 0.0;
   out_721764794937271849[312] = 0.0;
   out_721764794937271849[313] = 0.0;
   out_721764794937271849[314] = 0.0;
   out_721764794937271849[315] = 0.0;
   out_721764794937271849[316] = 0.0;
   out_721764794937271849[317] = 0.0;
   out_721764794937271849[318] = 0.0;
   out_721764794937271849[319] = 0.0;
   out_721764794937271849[320] = 0.0;
   out_721764794937271849[321] = 0.0;
   out_721764794937271849[322] = 0.0;
   out_721764794937271849[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_4641529343405726831) {
   out_4641529343405726831[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_4641529343405726831[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_4641529343405726831[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_4641529343405726831[3] = dt*state[12] + state[3];
   out_4641529343405726831[4] = dt*state[13] + state[4];
   out_4641529343405726831[5] = dt*state[14] + state[5];
   out_4641529343405726831[6] = state[6];
   out_4641529343405726831[7] = state[7];
   out_4641529343405726831[8] = state[8];
   out_4641529343405726831[9] = state[9];
   out_4641529343405726831[10] = state[10];
   out_4641529343405726831[11] = state[11];
   out_4641529343405726831[12] = state[12];
   out_4641529343405726831[13] = state[13];
   out_4641529343405726831[14] = state[14];
   out_4641529343405726831[15] = state[15];
   out_4641529343405726831[16] = state[16];
   out_4641529343405726831[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5067006879448835750) {
   out_5067006879448835750[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5067006879448835750[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5067006879448835750[2] = 0;
   out_5067006879448835750[3] = 0;
   out_5067006879448835750[4] = 0;
   out_5067006879448835750[5] = 0;
   out_5067006879448835750[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5067006879448835750[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5067006879448835750[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5067006879448835750[9] = 0;
   out_5067006879448835750[10] = 0;
   out_5067006879448835750[11] = 0;
   out_5067006879448835750[12] = 0;
   out_5067006879448835750[13] = 0;
   out_5067006879448835750[14] = 0;
   out_5067006879448835750[15] = 0;
   out_5067006879448835750[16] = 0;
   out_5067006879448835750[17] = 0;
   out_5067006879448835750[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5067006879448835750[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5067006879448835750[20] = 0;
   out_5067006879448835750[21] = 0;
   out_5067006879448835750[22] = 0;
   out_5067006879448835750[23] = 0;
   out_5067006879448835750[24] = 0;
   out_5067006879448835750[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5067006879448835750[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5067006879448835750[27] = 0;
   out_5067006879448835750[28] = 0;
   out_5067006879448835750[29] = 0;
   out_5067006879448835750[30] = 0;
   out_5067006879448835750[31] = 0;
   out_5067006879448835750[32] = 0;
   out_5067006879448835750[33] = 0;
   out_5067006879448835750[34] = 0;
   out_5067006879448835750[35] = 0;
   out_5067006879448835750[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5067006879448835750[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5067006879448835750[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5067006879448835750[39] = 0;
   out_5067006879448835750[40] = 0;
   out_5067006879448835750[41] = 0;
   out_5067006879448835750[42] = 0;
   out_5067006879448835750[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5067006879448835750[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5067006879448835750[45] = 0;
   out_5067006879448835750[46] = 0;
   out_5067006879448835750[47] = 0;
   out_5067006879448835750[48] = 0;
   out_5067006879448835750[49] = 0;
   out_5067006879448835750[50] = 0;
   out_5067006879448835750[51] = 0;
   out_5067006879448835750[52] = 0;
   out_5067006879448835750[53] = 0;
   out_5067006879448835750[54] = 0;
   out_5067006879448835750[55] = 0;
   out_5067006879448835750[56] = 0;
   out_5067006879448835750[57] = 1;
   out_5067006879448835750[58] = 0;
   out_5067006879448835750[59] = 0;
   out_5067006879448835750[60] = 0;
   out_5067006879448835750[61] = 0;
   out_5067006879448835750[62] = 0;
   out_5067006879448835750[63] = 0;
   out_5067006879448835750[64] = 0;
   out_5067006879448835750[65] = 0;
   out_5067006879448835750[66] = dt;
   out_5067006879448835750[67] = 0;
   out_5067006879448835750[68] = 0;
   out_5067006879448835750[69] = 0;
   out_5067006879448835750[70] = 0;
   out_5067006879448835750[71] = 0;
   out_5067006879448835750[72] = 0;
   out_5067006879448835750[73] = 0;
   out_5067006879448835750[74] = 0;
   out_5067006879448835750[75] = 0;
   out_5067006879448835750[76] = 1;
   out_5067006879448835750[77] = 0;
   out_5067006879448835750[78] = 0;
   out_5067006879448835750[79] = 0;
   out_5067006879448835750[80] = 0;
   out_5067006879448835750[81] = 0;
   out_5067006879448835750[82] = 0;
   out_5067006879448835750[83] = 0;
   out_5067006879448835750[84] = 0;
   out_5067006879448835750[85] = dt;
   out_5067006879448835750[86] = 0;
   out_5067006879448835750[87] = 0;
   out_5067006879448835750[88] = 0;
   out_5067006879448835750[89] = 0;
   out_5067006879448835750[90] = 0;
   out_5067006879448835750[91] = 0;
   out_5067006879448835750[92] = 0;
   out_5067006879448835750[93] = 0;
   out_5067006879448835750[94] = 0;
   out_5067006879448835750[95] = 1;
   out_5067006879448835750[96] = 0;
   out_5067006879448835750[97] = 0;
   out_5067006879448835750[98] = 0;
   out_5067006879448835750[99] = 0;
   out_5067006879448835750[100] = 0;
   out_5067006879448835750[101] = 0;
   out_5067006879448835750[102] = 0;
   out_5067006879448835750[103] = 0;
   out_5067006879448835750[104] = dt;
   out_5067006879448835750[105] = 0;
   out_5067006879448835750[106] = 0;
   out_5067006879448835750[107] = 0;
   out_5067006879448835750[108] = 0;
   out_5067006879448835750[109] = 0;
   out_5067006879448835750[110] = 0;
   out_5067006879448835750[111] = 0;
   out_5067006879448835750[112] = 0;
   out_5067006879448835750[113] = 0;
   out_5067006879448835750[114] = 1;
   out_5067006879448835750[115] = 0;
   out_5067006879448835750[116] = 0;
   out_5067006879448835750[117] = 0;
   out_5067006879448835750[118] = 0;
   out_5067006879448835750[119] = 0;
   out_5067006879448835750[120] = 0;
   out_5067006879448835750[121] = 0;
   out_5067006879448835750[122] = 0;
   out_5067006879448835750[123] = 0;
   out_5067006879448835750[124] = 0;
   out_5067006879448835750[125] = 0;
   out_5067006879448835750[126] = 0;
   out_5067006879448835750[127] = 0;
   out_5067006879448835750[128] = 0;
   out_5067006879448835750[129] = 0;
   out_5067006879448835750[130] = 0;
   out_5067006879448835750[131] = 0;
   out_5067006879448835750[132] = 0;
   out_5067006879448835750[133] = 1;
   out_5067006879448835750[134] = 0;
   out_5067006879448835750[135] = 0;
   out_5067006879448835750[136] = 0;
   out_5067006879448835750[137] = 0;
   out_5067006879448835750[138] = 0;
   out_5067006879448835750[139] = 0;
   out_5067006879448835750[140] = 0;
   out_5067006879448835750[141] = 0;
   out_5067006879448835750[142] = 0;
   out_5067006879448835750[143] = 0;
   out_5067006879448835750[144] = 0;
   out_5067006879448835750[145] = 0;
   out_5067006879448835750[146] = 0;
   out_5067006879448835750[147] = 0;
   out_5067006879448835750[148] = 0;
   out_5067006879448835750[149] = 0;
   out_5067006879448835750[150] = 0;
   out_5067006879448835750[151] = 0;
   out_5067006879448835750[152] = 1;
   out_5067006879448835750[153] = 0;
   out_5067006879448835750[154] = 0;
   out_5067006879448835750[155] = 0;
   out_5067006879448835750[156] = 0;
   out_5067006879448835750[157] = 0;
   out_5067006879448835750[158] = 0;
   out_5067006879448835750[159] = 0;
   out_5067006879448835750[160] = 0;
   out_5067006879448835750[161] = 0;
   out_5067006879448835750[162] = 0;
   out_5067006879448835750[163] = 0;
   out_5067006879448835750[164] = 0;
   out_5067006879448835750[165] = 0;
   out_5067006879448835750[166] = 0;
   out_5067006879448835750[167] = 0;
   out_5067006879448835750[168] = 0;
   out_5067006879448835750[169] = 0;
   out_5067006879448835750[170] = 0;
   out_5067006879448835750[171] = 1;
   out_5067006879448835750[172] = 0;
   out_5067006879448835750[173] = 0;
   out_5067006879448835750[174] = 0;
   out_5067006879448835750[175] = 0;
   out_5067006879448835750[176] = 0;
   out_5067006879448835750[177] = 0;
   out_5067006879448835750[178] = 0;
   out_5067006879448835750[179] = 0;
   out_5067006879448835750[180] = 0;
   out_5067006879448835750[181] = 0;
   out_5067006879448835750[182] = 0;
   out_5067006879448835750[183] = 0;
   out_5067006879448835750[184] = 0;
   out_5067006879448835750[185] = 0;
   out_5067006879448835750[186] = 0;
   out_5067006879448835750[187] = 0;
   out_5067006879448835750[188] = 0;
   out_5067006879448835750[189] = 0;
   out_5067006879448835750[190] = 1;
   out_5067006879448835750[191] = 0;
   out_5067006879448835750[192] = 0;
   out_5067006879448835750[193] = 0;
   out_5067006879448835750[194] = 0;
   out_5067006879448835750[195] = 0;
   out_5067006879448835750[196] = 0;
   out_5067006879448835750[197] = 0;
   out_5067006879448835750[198] = 0;
   out_5067006879448835750[199] = 0;
   out_5067006879448835750[200] = 0;
   out_5067006879448835750[201] = 0;
   out_5067006879448835750[202] = 0;
   out_5067006879448835750[203] = 0;
   out_5067006879448835750[204] = 0;
   out_5067006879448835750[205] = 0;
   out_5067006879448835750[206] = 0;
   out_5067006879448835750[207] = 0;
   out_5067006879448835750[208] = 0;
   out_5067006879448835750[209] = 1;
   out_5067006879448835750[210] = 0;
   out_5067006879448835750[211] = 0;
   out_5067006879448835750[212] = 0;
   out_5067006879448835750[213] = 0;
   out_5067006879448835750[214] = 0;
   out_5067006879448835750[215] = 0;
   out_5067006879448835750[216] = 0;
   out_5067006879448835750[217] = 0;
   out_5067006879448835750[218] = 0;
   out_5067006879448835750[219] = 0;
   out_5067006879448835750[220] = 0;
   out_5067006879448835750[221] = 0;
   out_5067006879448835750[222] = 0;
   out_5067006879448835750[223] = 0;
   out_5067006879448835750[224] = 0;
   out_5067006879448835750[225] = 0;
   out_5067006879448835750[226] = 0;
   out_5067006879448835750[227] = 0;
   out_5067006879448835750[228] = 1;
   out_5067006879448835750[229] = 0;
   out_5067006879448835750[230] = 0;
   out_5067006879448835750[231] = 0;
   out_5067006879448835750[232] = 0;
   out_5067006879448835750[233] = 0;
   out_5067006879448835750[234] = 0;
   out_5067006879448835750[235] = 0;
   out_5067006879448835750[236] = 0;
   out_5067006879448835750[237] = 0;
   out_5067006879448835750[238] = 0;
   out_5067006879448835750[239] = 0;
   out_5067006879448835750[240] = 0;
   out_5067006879448835750[241] = 0;
   out_5067006879448835750[242] = 0;
   out_5067006879448835750[243] = 0;
   out_5067006879448835750[244] = 0;
   out_5067006879448835750[245] = 0;
   out_5067006879448835750[246] = 0;
   out_5067006879448835750[247] = 1;
   out_5067006879448835750[248] = 0;
   out_5067006879448835750[249] = 0;
   out_5067006879448835750[250] = 0;
   out_5067006879448835750[251] = 0;
   out_5067006879448835750[252] = 0;
   out_5067006879448835750[253] = 0;
   out_5067006879448835750[254] = 0;
   out_5067006879448835750[255] = 0;
   out_5067006879448835750[256] = 0;
   out_5067006879448835750[257] = 0;
   out_5067006879448835750[258] = 0;
   out_5067006879448835750[259] = 0;
   out_5067006879448835750[260] = 0;
   out_5067006879448835750[261] = 0;
   out_5067006879448835750[262] = 0;
   out_5067006879448835750[263] = 0;
   out_5067006879448835750[264] = 0;
   out_5067006879448835750[265] = 0;
   out_5067006879448835750[266] = 1;
   out_5067006879448835750[267] = 0;
   out_5067006879448835750[268] = 0;
   out_5067006879448835750[269] = 0;
   out_5067006879448835750[270] = 0;
   out_5067006879448835750[271] = 0;
   out_5067006879448835750[272] = 0;
   out_5067006879448835750[273] = 0;
   out_5067006879448835750[274] = 0;
   out_5067006879448835750[275] = 0;
   out_5067006879448835750[276] = 0;
   out_5067006879448835750[277] = 0;
   out_5067006879448835750[278] = 0;
   out_5067006879448835750[279] = 0;
   out_5067006879448835750[280] = 0;
   out_5067006879448835750[281] = 0;
   out_5067006879448835750[282] = 0;
   out_5067006879448835750[283] = 0;
   out_5067006879448835750[284] = 0;
   out_5067006879448835750[285] = 1;
   out_5067006879448835750[286] = 0;
   out_5067006879448835750[287] = 0;
   out_5067006879448835750[288] = 0;
   out_5067006879448835750[289] = 0;
   out_5067006879448835750[290] = 0;
   out_5067006879448835750[291] = 0;
   out_5067006879448835750[292] = 0;
   out_5067006879448835750[293] = 0;
   out_5067006879448835750[294] = 0;
   out_5067006879448835750[295] = 0;
   out_5067006879448835750[296] = 0;
   out_5067006879448835750[297] = 0;
   out_5067006879448835750[298] = 0;
   out_5067006879448835750[299] = 0;
   out_5067006879448835750[300] = 0;
   out_5067006879448835750[301] = 0;
   out_5067006879448835750[302] = 0;
   out_5067006879448835750[303] = 0;
   out_5067006879448835750[304] = 1;
   out_5067006879448835750[305] = 0;
   out_5067006879448835750[306] = 0;
   out_5067006879448835750[307] = 0;
   out_5067006879448835750[308] = 0;
   out_5067006879448835750[309] = 0;
   out_5067006879448835750[310] = 0;
   out_5067006879448835750[311] = 0;
   out_5067006879448835750[312] = 0;
   out_5067006879448835750[313] = 0;
   out_5067006879448835750[314] = 0;
   out_5067006879448835750[315] = 0;
   out_5067006879448835750[316] = 0;
   out_5067006879448835750[317] = 0;
   out_5067006879448835750[318] = 0;
   out_5067006879448835750[319] = 0;
   out_5067006879448835750[320] = 0;
   out_5067006879448835750[321] = 0;
   out_5067006879448835750[322] = 0;
   out_5067006879448835750[323] = 1;
}
void h_4(double *state, double *unused, double *out_6721945205192637351) {
   out_6721945205192637351[0] = state[6] + state[9];
   out_6721945205192637351[1] = state[7] + state[10];
   out_6721945205192637351[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8291219624976412643) {
   out_8291219624976412643[0] = 0;
   out_8291219624976412643[1] = 0;
   out_8291219624976412643[2] = 0;
   out_8291219624976412643[3] = 0;
   out_8291219624976412643[4] = 0;
   out_8291219624976412643[5] = 0;
   out_8291219624976412643[6] = 1;
   out_8291219624976412643[7] = 0;
   out_8291219624976412643[8] = 0;
   out_8291219624976412643[9] = 1;
   out_8291219624976412643[10] = 0;
   out_8291219624976412643[11] = 0;
   out_8291219624976412643[12] = 0;
   out_8291219624976412643[13] = 0;
   out_8291219624976412643[14] = 0;
   out_8291219624976412643[15] = 0;
   out_8291219624976412643[16] = 0;
   out_8291219624976412643[17] = 0;
   out_8291219624976412643[18] = 0;
   out_8291219624976412643[19] = 0;
   out_8291219624976412643[20] = 0;
   out_8291219624976412643[21] = 0;
   out_8291219624976412643[22] = 0;
   out_8291219624976412643[23] = 0;
   out_8291219624976412643[24] = 0;
   out_8291219624976412643[25] = 1;
   out_8291219624976412643[26] = 0;
   out_8291219624976412643[27] = 0;
   out_8291219624976412643[28] = 1;
   out_8291219624976412643[29] = 0;
   out_8291219624976412643[30] = 0;
   out_8291219624976412643[31] = 0;
   out_8291219624976412643[32] = 0;
   out_8291219624976412643[33] = 0;
   out_8291219624976412643[34] = 0;
   out_8291219624976412643[35] = 0;
   out_8291219624976412643[36] = 0;
   out_8291219624976412643[37] = 0;
   out_8291219624976412643[38] = 0;
   out_8291219624976412643[39] = 0;
   out_8291219624976412643[40] = 0;
   out_8291219624976412643[41] = 0;
   out_8291219624976412643[42] = 0;
   out_8291219624976412643[43] = 0;
   out_8291219624976412643[44] = 1;
   out_8291219624976412643[45] = 0;
   out_8291219624976412643[46] = 0;
   out_8291219624976412643[47] = 1;
   out_8291219624976412643[48] = 0;
   out_8291219624976412643[49] = 0;
   out_8291219624976412643[50] = 0;
   out_8291219624976412643[51] = 0;
   out_8291219624976412643[52] = 0;
   out_8291219624976412643[53] = 0;
}
void h_10(double *state, double *unused, double *out_2430238044192408930) {
   out_2430238044192408930[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_2430238044192408930[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_2430238044192408930[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_1293960980901307379) {
   out_1293960980901307379[0] = 0;
   out_1293960980901307379[1] = 9.8100000000000005*cos(state[1]);
   out_1293960980901307379[2] = 0;
   out_1293960980901307379[3] = 0;
   out_1293960980901307379[4] = -state[8];
   out_1293960980901307379[5] = state[7];
   out_1293960980901307379[6] = 0;
   out_1293960980901307379[7] = state[5];
   out_1293960980901307379[8] = -state[4];
   out_1293960980901307379[9] = 0;
   out_1293960980901307379[10] = 0;
   out_1293960980901307379[11] = 0;
   out_1293960980901307379[12] = 1;
   out_1293960980901307379[13] = 0;
   out_1293960980901307379[14] = 0;
   out_1293960980901307379[15] = 1;
   out_1293960980901307379[16] = 0;
   out_1293960980901307379[17] = 0;
   out_1293960980901307379[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_1293960980901307379[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_1293960980901307379[20] = 0;
   out_1293960980901307379[21] = state[8];
   out_1293960980901307379[22] = 0;
   out_1293960980901307379[23] = -state[6];
   out_1293960980901307379[24] = -state[5];
   out_1293960980901307379[25] = 0;
   out_1293960980901307379[26] = state[3];
   out_1293960980901307379[27] = 0;
   out_1293960980901307379[28] = 0;
   out_1293960980901307379[29] = 0;
   out_1293960980901307379[30] = 0;
   out_1293960980901307379[31] = 1;
   out_1293960980901307379[32] = 0;
   out_1293960980901307379[33] = 0;
   out_1293960980901307379[34] = 1;
   out_1293960980901307379[35] = 0;
   out_1293960980901307379[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_1293960980901307379[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_1293960980901307379[38] = 0;
   out_1293960980901307379[39] = -state[7];
   out_1293960980901307379[40] = state[6];
   out_1293960980901307379[41] = 0;
   out_1293960980901307379[42] = state[4];
   out_1293960980901307379[43] = -state[3];
   out_1293960980901307379[44] = 0;
   out_1293960980901307379[45] = 0;
   out_1293960980901307379[46] = 0;
   out_1293960980901307379[47] = 0;
   out_1293960980901307379[48] = 0;
   out_1293960980901307379[49] = 0;
   out_1293960980901307379[50] = 1;
   out_1293960980901307379[51] = 0;
   out_1293960980901307379[52] = 0;
   out_1293960980901307379[53] = 1;
}
void h_13(double *state, double *unused, double *out_2389125531200423217) {
   out_2389125531200423217[0] = state[3];
   out_2389125531200423217[1] = state[4];
   out_2389125531200423217[2] = state[5];
}
void H_13(double *state, double *unused, double *out_6943250623400806172) {
   out_6943250623400806172[0] = 0;
   out_6943250623400806172[1] = 0;
   out_6943250623400806172[2] = 0;
   out_6943250623400806172[3] = 1;
   out_6943250623400806172[4] = 0;
   out_6943250623400806172[5] = 0;
   out_6943250623400806172[6] = 0;
   out_6943250623400806172[7] = 0;
   out_6943250623400806172[8] = 0;
   out_6943250623400806172[9] = 0;
   out_6943250623400806172[10] = 0;
   out_6943250623400806172[11] = 0;
   out_6943250623400806172[12] = 0;
   out_6943250623400806172[13] = 0;
   out_6943250623400806172[14] = 0;
   out_6943250623400806172[15] = 0;
   out_6943250623400806172[16] = 0;
   out_6943250623400806172[17] = 0;
   out_6943250623400806172[18] = 0;
   out_6943250623400806172[19] = 0;
   out_6943250623400806172[20] = 0;
   out_6943250623400806172[21] = 0;
   out_6943250623400806172[22] = 1;
   out_6943250623400806172[23] = 0;
   out_6943250623400806172[24] = 0;
   out_6943250623400806172[25] = 0;
   out_6943250623400806172[26] = 0;
   out_6943250623400806172[27] = 0;
   out_6943250623400806172[28] = 0;
   out_6943250623400806172[29] = 0;
   out_6943250623400806172[30] = 0;
   out_6943250623400806172[31] = 0;
   out_6943250623400806172[32] = 0;
   out_6943250623400806172[33] = 0;
   out_6943250623400806172[34] = 0;
   out_6943250623400806172[35] = 0;
   out_6943250623400806172[36] = 0;
   out_6943250623400806172[37] = 0;
   out_6943250623400806172[38] = 0;
   out_6943250623400806172[39] = 0;
   out_6943250623400806172[40] = 0;
   out_6943250623400806172[41] = 1;
   out_6943250623400806172[42] = 0;
   out_6943250623400806172[43] = 0;
   out_6943250623400806172[44] = 0;
   out_6943250623400806172[45] = 0;
   out_6943250623400806172[46] = 0;
   out_6943250623400806172[47] = 0;
   out_6943250623400806172[48] = 0;
   out_6943250623400806172[49] = 0;
   out_6943250623400806172[50] = 0;
   out_6943250623400806172[51] = 0;
   out_6943250623400806172[52] = 0;
   out_6943250623400806172[53] = 0;
}
void h_14(double *state, double *unused, double *out_4727481890209973727) {
   out_4727481890209973727[0] = state[6];
   out_4727481890209973727[1] = state[7];
   out_4727481890209973727[2] = state[8];
}
void H_14(double *state, double *unused, double *out_6192283592393654444) {
   out_6192283592393654444[0] = 0;
   out_6192283592393654444[1] = 0;
   out_6192283592393654444[2] = 0;
   out_6192283592393654444[3] = 0;
   out_6192283592393654444[4] = 0;
   out_6192283592393654444[5] = 0;
   out_6192283592393654444[6] = 1;
   out_6192283592393654444[7] = 0;
   out_6192283592393654444[8] = 0;
   out_6192283592393654444[9] = 0;
   out_6192283592393654444[10] = 0;
   out_6192283592393654444[11] = 0;
   out_6192283592393654444[12] = 0;
   out_6192283592393654444[13] = 0;
   out_6192283592393654444[14] = 0;
   out_6192283592393654444[15] = 0;
   out_6192283592393654444[16] = 0;
   out_6192283592393654444[17] = 0;
   out_6192283592393654444[18] = 0;
   out_6192283592393654444[19] = 0;
   out_6192283592393654444[20] = 0;
   out_6192283592393654444[21] = 0;
   out_6192283592393654444[22] = 0;
   out_6192283592393654444[23] = 0;
   out_6192283592393654444[24] = 0;
   out_6192283592393654444[25] = 1;
   out_6192283592393654444[26] = 0;
   out_6192283592393654444[27] = 0;
   out_6192283592393654444[28] = 0;
   out_6192283592393654444[29] = 0;
   out_6192283592393654444[30] = 0;
   out_6192283592393654444[31] = 0;
   out_6192283592393654444[32] = 0;
   out_6192283592393654444[33] = 0;
   out_6192283592393654444[34] = 0;
   out_6192283592393654444[35] = 0;
   out_6192283592393654444[36] = 0;
   out_6192283592393654444[37] = 0;
   out_6192283592393654444[38] = 0;
   out_6192283592393654444[39] = 0;
   out_6192283592393654444[40] = 0;
   out_6192283592393654444[41] = 0;
   out_6192283592393654444[42] = 0;
   out_6192283592393654444[43] = 0;
   out_6192283592393654444[44] = 1;
   out_6192283592393654444[45] = 0;
   out_6192283592393654444[46] = 0;
   out_6192283592393654444[47] = 0;
   out_6192283592393654444[48] = 0;
   out_6192283592393654444[49] = 0;
   out_6192283592393654444[50] = 0;
   out_6192283592393654444[51] = 0;
   out_6192283592393654444[52] = 0;
   out_6192283592393654444[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_582162479678847507) {
  err_fun(nom_x, delta_x, out_582162479678847507);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8183002877435981990) {
  inv_err_fun(nom_x, true_x, out_8183002877435981990);
}
void pose_H_mod_fun(double *state, double *out_721764794937271849) {
  H_mod_fun(state, out_721764794937271849);
}
void pose_f_fun(double *state, double dt, double *out_4641529343405726831) {
  f_fun(state,  dt, out_4641529343405726831);
}
void pose_F_fun(double *state, double dt, double *out_5067006879448835750) {
  F_fun(state,  dt, out_5067006879448835750);
}
void pose_h_4(double *state, double *unused, double *out_6721945205192637351) {
  h_4(state, unused, out_6721945205192637351);
}
void pose_H_4(double *state, double *unused, double *out_8291219624976412643) {
  H_4(state, unused, out_8291219624976412643);
}
void pose_h_10(double *state, double *unused, double *out_2430238044192408930) {
  h_10(state, unused, out_2430238044192408930);
}
void pose_H_10(double *state, double *unused, double *out_1293960980901307379) {
  H_10(state, unused, out_1293960980901307379);
}
void pose_h_13(double *state, double *unused, double *out_2389125531200423217) {
  h_13(state, unused, out_2389125531200423217);
}
void pose_H_13(double *state, double *unused, double *out_6943250623400806172) {
  H_13(state, unused, out_6943250623400806172);
}
void pose_h_14(double *state, double *unused, double *out_4727481890209973727) {
  h_14(state, unused, out_4727481890209973727);
}
void pose_H_14(double *state, double *unused, double *out_6192283592393654444) {
  H_14(state, unused, out_6192283592393654444);
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
