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
void err_fun(double *nom_x, double *delta_x, double *out_4331083049534056355) {
   out_4331083049534056355[0] = delta_x[0] + nom_x[0];
   out_4331083049534056355[1] = delta_x[1] + nom_x[1];
   out_4331083049534056355[2] = delta_x[2] + nom_x[2];
   out_4331083049534056355[3] = delta_x[3] + nom_x[3];
   out_4331083049534056355[4] = delta_x[4] + nom_x[4];
   out_4331083049534056355[5] = delta_x[5] + nom_x[5];
   out_4331083049534056355[6] = delta_x[6] + nom_x[6];
   out_4331083049534056355[7] = delta_x[7] + nom_x[7];
   out_4331083049534056355[8] = delta_x[8] + nom_x[8];
   out_4331083049534056355[9] = delta_x[9] + nom_x[9];
   out_4331083049534056355[10] = delta_x[10] + nom_x[10];
   out_4331083049534056355[11] = delta_x[11] + nom_x[11];
   out_4331083049534056355[12] = delta_x[12] + nom_x[12];
   out_4331083049534056355[13] = delta_x[13] + nom_x[13];
   out_4331083049534056355[14] = delta_x[14] + nom_x[14];
   out_4331083049534056355[15] = delta_x[15] + nom_x[15];
   out_4331083049534056355[16] = delta_x[16] + nom_x[16];
   out_4331083049534056355[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5197883329726451987) {
   out_5197883329726451987[0] = -nom_x[0] + true_x[0];
   out_5197883329726451987[1] = -nom_x[1] + true_x[1];
   out_5197883329726451987[2] = -nom_x[2] + true_x[2];
   out_5197883329726451987[3] = -nom_x[3] + true_x[3];
   out_5197883329726451987[4] = -nom_x[4] + true_x[4];
   out_5197883329726451987[5] = -nom_x[5] + true_x[5];
   out_5197883329726451987[6] = -nom_x[6] + true_x[6];
   out_5197883329726451987[7] = -nom_x[7] + true_x[7];
   out_5197883329726451987[8] = -nom_x[8] + true_x[8];
   out_5197883329726451987[9] = -nom_x[9] + true_x[9];
   out_5197883329726451987[10] = -nom_x[10] + true_x[10];
   out_5197883329726451987[11] = -nom_x[11] + true_x[11];
   out_5197883329726451987[12] = -nom_x[12] + true_x[12];
   out_5197883329726451987[13] = -nom_x[13] + true_x[13];
   out_5197883329726451987[14] = -nom_x[14] + true_x[14];
   out_5197883329726451987[15] = -nom_x[15] + true_x[15];
   out_5197883329726451987[16] = -nom_x[16] + true_x[16];
   out_5197883329726451987[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_8877666100320465704) {
   out_8877666100320465704[0] = 1.0;
   out_8877666100320465704[1] = 0.0;
   out_8877666100320465704[2] = 0.0;
   out_8877666100320465704[3] = 0.0;
   out_8877666100320465704[4] = 0.0;
   out_8877666100320465704[5] = 0.0;
   out_8877666100320465704[6] = 0.0;
   out_8877666100320465704[7] = 0.0;
   out_8877666100320465704[8] = 0.0;
   out_8877666100320465704[9] = 0.0;
   out_8877666100320465704[10] = 0.0;
   out_8877666100320465704[11] = 0.0;
   out_8877666100320465704[12] = 0.0;
   out_8877666100320465704[13] = 0.0;
   out_8877666100320465704[14] = 0.0;
   out_8877666100320465704[15] = 0.0;
   out_8877666100320465704[16] = 0.0;
   out_8877666100320465704[17] = 0.0;
   out_8877666100320465704[18] = 0.0;
   out_8877666100320465704[19] = 1.0;
   out_8877666100320465704[20] = 0.0;
   out_8877666100320465704[21] = 0.0;
   out_8877666100320465704[22] = 0.0;
   out_8877666100320465704[23] = 0.0;
   out_8877666100320465704[24] = 0.0;
   out_8877666100320465704[25] = 0.0;
   out_8877666100320465704[26] = 0.0;
   out_8877666100320465704[27] = 0.0;
   out_8877666100320465704[28] = 0.0;
   out_8877666100320465704[29] = 0.0;
   out_8877666100320465704[30] = 0.0;
   out_8877666100320465704[31] = 0.0;
   out_8877666100320465704[32] = 0.0;
   out_8877666100320465704[33] = 0.0;
   out_8877666100320465704[34] = 0.0;
   out_8877666100320465704[35] = 0.0;
   out_8877666100320465704[36] = 0.0;
   out_8877666100320465704[37] = 0.0;
   out_8877666100320465704[38] = 1.0;
   out_8877666100320465704[39] = 0.0;
   out_8877666100320465704[40] = 0.0;
   out_8877666100320465704[41] = 0.0;
   out_8877666100320465704[42] = 0.0;
   out_8877666100320465704[43] = 0.0;
   out_8877666100320465704[44] = 0.0;
   out_8877666100320465704[45] = 0.0;
   out_8877666100320465704[46] = 0.0;
   out_8877666100320465704[47] = 0.0;
   out_8877666100320465704[48] = 0.0;
   out_8877666100320465704[49] = 0.0;
   out_8877666100320465704[50] = 0.0;
   out_8877666100320465704[51] = 0.0;
   out_8877666100320465704[52] = 0.0;
   out_8877666100320465704[53] = 0.0;
   out_8877666100320465704[54] = 0.0;
   out_8877666100320465704[55] = 0.0;
   out_8877666100320465704[56] = 0.0;
   out_8877666100320465704[57] = 1.0;
   out_8877666100320465704[58] = 0.0;
   out_8877666100320465704[59] = 0.0;
   out_8877666100320465704[60] = 0.0;
   out_8877666100320465704[61] = 0.0;
   out_8877666100320465704[62] = 0.0;
   out_8877666100320465704[63] = 0.0;
   out_8877666100320465704[64] = 0.0;
   out_8877666100320465704[65] = 0.0;
   out_8877666100320465704[66] = 0.0;
   out_8877666100320465704[67] = 0.0;
   out_8877666100320465704[68] = 0.0;
   out_8877666100320465704[69] = 0.0;
   out_8877666100320465704[70] = 0.0;
   out_8877666100320465704[71] = 0.0;
   out_8877666100320465704[72] = 0.0;
   out_8877666100320465704[73] = 0.0;
   out_8877666100320465704[74] = 0.0;
   out_8877666100320465704[75] = 0.0;
   out_8877666100320465704[76] = 1.0;
   out_8877666100320465704[77] = 0.0;
   out_8877666100320465704[78] = 0.0;
   out_8877666100320465704[79] = 0.0;
   out_8877666100320465704[80] = 0.0;
   out_8877666100320465704[81] = 0.0;
   out_8877666100320465704[82] = 0.0;
   out_8877666100320465704[83] = 0.0;
   out_8877666100320465704[84] = 0.0;
   out_8877666100320465704[85] = 0.0;
   out_8877666100320465704[86] = 0.0;
   out_8877666100320465704[87] = 0.0;
   out_8877666100320465704[88] = 0.0;
   out_8877666100320465704[89] = 0.0;
   out_8877666100320465704[90] = 0.0;
   out_8877666100320465704[91] = 0.0;
   out_8877666100320465704[92] = 0.0;
   out_8877666100320465704[93] = 0.0;
   out_8877666100320465704[94] = 0.0;
   out_8877666100320465704[95] = 1.0;
   out_8877666100320465704[96] = 0.0;
   out_8877666100320465704[97] = 0.0;
   out_8877666100320465704[98] = 0.0;
   out_8877666100320465704[99] = 0.0;
   out_8877666100320465704[100] = 0.0;
   out_8877666100320465704[101] = 0.0;
   out_8877666100320465704[102] = 0.0;
   out_8877666100320465704[103] = 0.0;
   out_8877666100320465704[104] = 0.0;
   out_8877666100320465704[105] = 0.0;
   out_8877666100320465704[106] = 0.0;
   out_8877666100320465704[107] = 0.0;
   out_8877666100320465704[108] = 0.0;
   out_8877666100320465704[109] = 0.0;
   out_8877666100320465704[110] = 0.0;
   out_8877666100320465704[111] = 0.0;
   out_8877666100320465704[112] = 0.0;
   out_8877666100320465704[113] = 0.0;
   out_8877666100320465704[114] = 1.0;
   out_8877666100320465704[115] = 0.0;
   out_8877666100320465704[116] = 0.0;
   out_8877666100320465704[117] = 0.0;
   out_8877666100320465704[118] = 0.0;
   out_8877666100320465704[119] = 0.0;
   out_8877666100320465704[120] = 0.0;
   out_8877666100320465704[121] = 0.0;
   out_8877666100320465704[122] = 0.0;
   out_8877666100320465704[123] = 0.0;
   out_8877666100320465704[124] = 0.0;
   out_8877666100320465704[125] = 0.0;
   out_8877666100320465704[126] = 0.0;
   out_8877666100320465704[127] = 0.0;
   out_8877666100320465704[128] = 0.0;
   out_8877666100320465704[129] = 0.0;
   out_8877666100320465704[130] = 0.0;
   out_8877666100320465704[131] = 0.0;
   out_8877666100320465704[132] = 0.0;
   out_8877666100320465704[133] = 1.0;
   out_8877666100320465704[134] = 0.0;
   out_8877666100320465704[135] = 0.0;
   out_8877666100320465704[136] = 0.0;
   out_8877666100320465704[137] = 0.0;
   out_8877666100320465704[138] = 0.0;
   out_8877666100320465704[139] = 0.0;
   out_8877666100320465704[140] = 0.0;
   out_8877666100320465704[141] = 0.0;
   out_8877666100320465704[142] = 0.0;
   out_8877666100320465704[143] = 0.0;
   out_8877666100320465704[144] = 0.0;
   out_8877666100320465704[145] = 0.0;
   out_8877666100320465704[146] = 0.0;
   out_8877666100320465704[147] = 0.0;
   out_8877666100320465704[148] = 0.0;
   out_8877666100320465704[149] = 0.0;
   out_8877666100320465704[150] = 0.0;
   out_8877666100320465704[151] = 0.0;
   out_8877666100320465704[152] = 1.0;
   out_8877666100320465704[153] = 0.0;
   out_8877666100320465704[154] = 0.0;
   out_8877666100320465704[155] = 0.0;
   out_8877666100320465704[156] = 0.0;
   out_8877666100320465704[157] = 0.0;
   out_8877666100320465704[158] = 0.0;
   out_8877666100320465704[159] = 0.0;
   out_8877666100320465704[160] = 0.0;
   out_8877666100320465704[161] = 0.0;
   out_8877666100320465704[162] = 0.0;
   out_8877666100320465704[163] = 0.0;
   out_8877666100320465704[164] = 0.0;
   out_8877666100320465704[165] = 0.0;
   out_8877666100320465704[166] = 0.0;
   out_8877666100320465704[167] = 0.0;
   out_8877666100320465704[168] = 0.0;
   out_8877666100320465704[169] = 0.0;
   out_8877666100320465704[170] = 0.0;
   out_8877666100320465704[171] = 1.0;
   out_8877666100320465704[172] = 0.0;
   out_8877666100320465704[173] = 0.0;
   out_8877666100320465704[174] = 0.0;
   out_8877666100320465704[175] = 0.0;
   out_8877666100320465704[176] = 0.0;
   out_8877666100320465704[177] = 0.0;
   out_8877666100320465704[178] = 0.0;
   out_8877666100320465704[179] = 0.0;
   out_8877666100320465704[180] = 0.0;
   out_8877666100320465704[181] = 0.0;
   out_8877666100320465704[182] = 0.0;
   out_8877666100320465704[183] = 0.0;
   out_8877666100320465704[184] = 0.0;
   out_8877666100320465704[185] = 0.0;
   out_8877666100320465704[186] = 0.0;
   out_8877666100320465704[187] = 0.0;
   out_8877666100320465704[188] = 0.0;
   out_8877666100320465704[189] = 0.0;
   out_8877666100320465704[190] = 1.0;
   out_8877666100320465704[191] = 0.0;
   out_8877666100320465704[192] = 0.0;
   out_8877666100320465704[193] = 0.0;
   out_8877666100320465704[194] = 0.0;
   out_8877666100320465704[195] = 0.0;
   out_8877666100320465704[196] = 0.0;
   out_8877666100320465704[197] = 0.0;
   out_8877666100320465704[198] = 0.0;
   out_8877666100320465704[199] = 0.0;
   out_8877666100320465704[200] = 0.0;
   out_8877666100320465704[201] = 0.0;
   out_8877666100320465704[202] = 0.0;
   out_8877666100320465704[203] = 0.0;
   out_8877666100320465704[204] = 0.0;
   out_8877666100320465704[205] = 0.0;
   out_8877666100320465704[206] = 0.0;
   out_8877666100320465704[207] = 0.0;
   out_8877666100320465704[208] = 0.0;
   out_8877666100320465704[209] = 1.0;
   out_8877666100320465704[210] = 0.0;
   out_8877666100320465704[211] = 0.0;
   out_8877666100320465704[212] = 0.0;
   out_8877666100320465704[213] = 0.0;
   out_8877666100320465704[214] = 0.0;
   out_8877666100320465704[215] = 0.0;
   out_8877666100320465704[216] = 0.0;
   out_8877666100320465704[217] = 0.0;
   out_8877666100320465704[218] = 0.0;
   out_8877666100320465704[219] = 0.0;
   out_8877666100320465704[220] = 0.0;
   out_8877666100320465704[221] = 0.0;
   out_8877666100320465704[222] = 0.0;
   out_8877666100320465704[223] = 0.0;
   out_8877666100320465704[224] = 0.0;
   out_8877666100320465704[225] = 0.0;
   out_8877666100320465704[226] = 0.0;
   out_8877666100320465704[227] = 0.0;
   out_8877666100320465704[228] = 1.0;
   out_8877666100320465704[229] = 0.0;
   out_8877666100320465704[230] = 0.0;
   out_8877666100320465704[231] = 0.0;
   out_8877666100320465704[232] = 0.0;
   out_8877666100320465704[233] = 0.0;
   out_8877666100320465704[234] = 0.0;
   out_8877666100320465704[235] = 0.0;
   out_8877666100320465704[236] = 0.0;
   out_8877666100320465704[237] = 0.0;
   out_8877666100320465704[238] = 0.0;
   out_8877666100320465704[239] = 0.0;
   out_8877666100320465704[240] = 0.0;
   out_8877666100320465704[241] = 0.0;
   out_8877666100320465704[242] = 0.0;
   out_8877666100320465704[243] = 0.0;
   out_8877666100320465704[244] = 0.0;
   out_8877666100320465704[245] = 0.0;
   out_8877666100320465704[246] = 0.0;
   out_8877666100320465704[247] = 1.0;
   out_8877666100320465704[248] = 0.0;
   out_8877666100320465704[249] = 0.0;
   out_8877666100320465704[250] = 0.0;
   out_8877666100320465704[251] = 0.0;
   out_8877666100320465704[252] = 0.0;
   out_8877666100320465704[253] = 0.0;
   out_8877666100320465704[254] = 0.0;
   out_8877666100320465704[255] = 0.0;
   out_8877666100320465704[256] = 0.0;
   out_8877666100320465704[257] = 0.0;
   out_8877666100320465704[258] = 0.0;
   out_8877666100320465704[259] = 0.0;
   out_8877666100320465704[260] = 0.0;
   out_8877666100320465704[261] = 0.0;
   out_8877666100320465704[262] = 0.0;
   out_8877666100320465704[263] = 0.0;
   out_8877666100320465704[264] = 0.0;
   out_8877666100320465704[265] = 0.0;
   out_8877666100320465704[266] = 1.0;
   out_8877666100320465704[267] = 0.0;
   out_8877666100320465704[268] = 0.0;
   out_8877666100320465704[269] = 0.0;
   out_8877666100320465704[270] = 0.0;
   out_8877666100320465704[271] = 0.0;
   out_8877666100320465704[272] = 0.0;
   out_8877666100320465704[273] = 0.0;
   out_8877666100320465704[274] = 0.0;
   out_8877666100320465704[275] = 0.0;
   out_8877666100320465704[276] = 0.0;
   out_8877666100320465704[277] = 0.0;
   out_8877666100320465704[278] = 0.0;
   out_8877666100320465704[279] = 0.0;
   out_8877666100320465704[280] = 0.0;
   out_8877666100320465704[281] = 0.0;
   out_8877666100320465704[282] = 0.0;
   out_8877666100320465704[283] = 0.0;
   out_8877666100320465704[284] = 0.0;
   out_8877666100320465704[285] = 1.0;
   out_8877666100320465704[286] = 0.0;
   out_8877666100320465704[287] = 0.0;
   out_8877666100320465704[288] = 0.0;
   out_8877666100320465704[289] = 0.0;
   out_8877666100320465704[290] = 0.0;
   out_8877666100320465704[291] = 0.0;
   out_8877666100320465704[292] = 0.0;
   out_8877666100320465704[293] = 0.0;
   out_8877666100320465704[294] = 0.0;
   out_8877666100320465704[295] = 0.0;
   out_8877666100320465704[296] = 0.0;
   out_8877666100320465704[297] = 0.0;
   out_8877666100320465704[298] = 0.0;
   out_8877666100320465704[299] = 0.0;
   out_8877666100320465704[300] = 0.0;
   out_8877666100320465704[301] = 0.0;
   out_8877666100320465704[302] = 0.0;
   out_8877666100320465704[303] = 0.0;
   out_8877666100320465704[304] = 1.0;
   out_8877666100320465704[305] = 0.0;
   out_8877666100320465704[306] = 0.0;
   out_8877666100320465704[307] = 0.0;
   out_8877666100320465704[308] = 0.0;
   out_8877666100320465704[309] = 0.0;
   out_8877666100320465704[310] = 0.0;
   out_8877666100320465704[311] = 0.0;
   out_8877666100320465704[312] = 0.0;
   out_8877666100320465704[313] = 0.0;
   out_8877666100320465704[314] = 0.0;
   out_8877666100320465704[315] = 0.0;
   out_8877666100320465704[316] = 0.0;
   out_8877666100320465704[317] = 0.0;
   out_8877666100320465704[318] = 0.0;
   out_8877666100320465704[319] = 0.0;
   out_8877666100320465704[320] = 0.0;
   out_8877666100320465704[321] = 0.0;
   out_8877666100320465704[322] = 0.0;
   out_8877666100320465704[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_3376588760060985122) {
   out_3376588760060985122[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_3376588760060985122[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_3376588760060985122[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_3376588760060985122[3] = dt*state[12] + state[3];
   out_3376588760060985122[4] = dt*state[13] + state[4];
   out_3376588760060985122[5] = dt*state[14] + state[5];
   out_3376588760060985122[6] = state[6];
   out_3376588760060985122[7] = state[7];
   out_3376588760060985122[8] = state[8];
   out_3376588760060985122[9] = state[9];
   out_3376588760060985122[10] = state[10];
   out_3376588760060985122[11] = state[11];
   out_3376588760060985122[12] = state[12];
   out_3376588760060985122[13] = state[13];
   out_3376588760060985122[14] = state[14];
   out_3376588760060985122[15] = state[15];
   out_3376588760060985122[16] = state[16];
   out_3376588760060985122[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2519439478573749592) {
   out_2519439478573749592[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2519439478573749592[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2519439478573749592[2] = 0;
   out_2519439478573749592[3] = 0;
   out_2519439478573749592[4] = 0;
   out_2519439478573749592[5] = 0;
   out_2519439478573749592[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2519439478573749592[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2519439478573749592[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2519439478573749592[9] = 0;
   out_2519439478573749592[10] = 0;
   out_2519439478573749592[11] = 0;
   out_2519439478573749592[12] = 0;
   out_2519439478573749592[13] = 0;
   out_2519439478573749592[14] = 0;
   out_2519439478573749592[15] = 0;
   out_2519439478573749592[16] = 0;
   out_2519439478573749592[17] = 0;
   out_2519439478573749592[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2519439478573749592[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2519439478573749592[20] = 0;
   out_2519439478573749592[21] = 0;
   out_2519439478573749592[22] = 0;
   out_2519439478573749592[23] = 0;
   out_2519439478573749592[24] = 0;
   out_2519439478573749592[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2519439478573749592[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2519439478573749592[27] = 0;
   out_2519439478573749592[28] = 0;
   out_2519439478573749592[29] = 0;
   out_2519439478573749592[30] = 0;
   out_2519439478573749592[31] = 0;
   out_2519439478573749592[32] = 0;
   out_2519439478573749592[33] = 0;
   out_2519439478573749592[34] = 0;
   out_2519439478573749592[35] = 0;
   out_2519439478573749592[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2519439478573749592[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2519439478573749592[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2519439478573749592[39] = 0;
   out_2519439478573749592[40] = 0;
   out_2519439478573749592[41] = 0;
   out_2519439478573749592[42] = 0;
   out_2519439478573749592[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2519439478573749592[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2519439478573749592[45] = 0;
   out_2519439478573749592[46] = 0;
   out_2519439478573749592[47] = 0;
   out_2519439478573749592[48] = 0;
   out_2519439478573749592[49] = 0;
   out_2519439478573749592[50] = 0;
   out_2519439478573749592[51] = 0;
   out_2519439478573749592[52] = 0;
   out_2519439478573749592[53] = 0;
   out_2519439478573749592[54] = 0;
   out_2519439478573749592[55] = 0;
   out_2519439478573749592[56] = 0;
   out_2519439478573749592[57] = 1;
   out_2519439478573749592[58] = 0;
   out_2519439478573749592[59] = 0;
   out_2519439478573749592[60] = 0;
   out_2519439478573749592[61] = 0;
   out_2519439478573749592[62] = 0;
   out_2519439478573749592[63] = 0;
   out_2519439478573749592[64] = 0;
   out_2519439478573749592[65] = 0;
   out_2519439478573749592[66] = dt;
   out_2519439478573749592[67] = 0;
   out_2519439478573749592[68] = 0;
   out_2519439478573749592[69] = 0;
   out_2519439478573749592[70] = 0;
   out_2519439478573749592[71] = 0;
   out_2519439478573749592[72] = 0;
   out_2519439478573749592[73] = 0;
   out_2519439478573749592[74] = 0;
   out_2519439478573749592[75] = 0;
   out_2519439478573749592[76] = 1;
   out_2519439478573749592[77] = 0;
   out_2519439478573749592[78] = 0;
   out_2519439478573749592[79] = 0;
   out_2519439478573749592[80] = 0;
   out_2519439478573749592[81] = 0;
   out_2519439478573749592[82] = 0;
   out_2519439478573749592[83] = 0;
   out_2519439478573749592[84] = 0;
   out_2519439478573749592[85] = dt;
   out_2519439478573749592[86] = 0;
   out_2519439478573749592[87] = 0;
   out_2519439478573749592[88] = 0;
   out_2519439478573749592[89] = 0;
   out_2519439478573749592[90] = 0;
   out_2519439478573749592[91] = 0;
   out_2519439478573749592[92] = 0;
   out_2519439478573749592[93] = 0;
   out_2519439478573749592[94] = 0;
   out_2519439478573749592[95] = 1;
   out_2519439478573749592[96] = 0;
   out_2519439478573749592[97] = 0;
   out_2519439478573749592[98] = 0;
   out_2519439478573749592[99] = 0;
   out_2519439478573749592[100] = 0;
   out_2519439478573749592[101] = 0;
   out_2519439478573749592[102] = 0;
   out_2519439478573749592[103] = 0;
   out_2519439478573749592[104] = dt;
   out_2519439478573749592[105] = 0;
   out_2519439478573749592[106] = 0;
   out_2519439478573749592[107] = 0;
   out_2519439478573749592[108] = 0;
   out_2519439478573749592[109] = 0;
   out_2519439478573749592[110] = 0;
   out_2519439478573749592[111] = 0;
   out_2519439478573749592[112] = 0;
   out_2519439478573749592[113] = 0;
   out_2519439478573749592[114] = 1;
   out_2519439478573749592[115] = 0;
   out_2519439478573749592[116] = 0;
   out_2519439478573749592[117] = 0;
   out_2519439478573749592[118] = 0;
   out_2519439478573749592[119] = 0;
   out_2519439478573749592[120] = 0;
   out_2519439478573749592[121] = 0;
   out_2519439478573749592[122] = 0;
   out_2519439478573749592[123] = 0;
   out_2519439478573749592[124] = 0;
   out_2519439478573749592[125] = 0;
   out_2519439478573749592[126] = 0;
   out_2519439478573749592[127] = 0;
   out_2519439478573749592[128] = 0;
   out_2519439478573749592[129] = 0;
   out_2519439478573749592[130] = 0;
   out_2519439478573749592[131] = 0;
   out_2519439478573749592[132] = 0;
   out_2519439478573749592[133] = 1;
   out_2519439478573749592[134] = 0;
   out_2519439478573749592[135] = 0;
   out_2519439478573749592[136] = 0;
   out_2519439478573749592[137] = 0;
   out_2519439478573749592[138] = 0;
   out_2519439478573749592[139] = 0;
   out_2519439478573749592[140] = 0;
   out_2519439478573749592[141] = 0;
   out_2519439478573749592[142] = 0;
   out_2519439478573749592[143] = 0;
   out_2519439478573749592[144] = 0;
   out_2519439478573749592[145] = 0;
   out_2519439478573749592[146] = 0;
   out_2519439478573749592[147] = 0;
   out_2519439478573749592[148] = 0;
   out_2519439478573749592[149] = 0;
   out_2519439478573749592[150] = 0;
   out_2519439478573749592[151] = 0;
   out_2519439478573749592[152] = 1;
   out_2519439478573749592[153] = 0;
   out_2519439478573749592[154] = 0;
   out_2519439478573749592[155] = 0;
   out_2519439478573749592[156] = 0;
   out_2519439478573749592[157] = 0;
   out_2519439478573749592[158] = 0;
   out_2519439478573749592[159] = 0;
   out_2519439478573749592[160] = 0;
   out_2519439478573749592[161] = 0;
   out_2519439478573749592[162] = 0;
   out_2519439478573749592[163] = 0;
   out_2519439478573749592[164] = 0;
   out_2519439478573749592[165] = 0;
   out_2519439478573749592[166] = 0;
   out_2519439478573749592[167] = 0;
   out_2519439478573749592[168] = 0;
   out_2519439478573749592[169] = 0;
   out_2519439478573749592[170] = 0;
   out_2519439478573749592[171] = 1;
   out_2519439478573749592[172] = 0;
   out_2519439478573749592[173] = 0;
   out_2519439478573749592[174] = 0;
   out_2519439478573749592[175] = 0;
   out_2519439478573749592[176] = 0;
   out_2519439478573749592[177] = 0;
   out_2519439478573749592[178] = 0;
   out_2519439478573749592[179] = 0;
   out_2519439478573749592[180] = 0;
   out_2519439478573749592[181] = 0;
   out_2519439478573749592[182] = 0;
   out_2519439478573749592[183] = 0;
   out_2519439478573749592[184] = 0;
   out_2519439478573749592[185] = 0;
   out_2519439478573749592[186] = 0;
   out_2519439478573749592[187] = 0;
   out_2519439478573749592[188] = 0;
   out_2519439478573749592[189] = 0;
   out_2519439478573749592[190] = 1;
   out_2519439478573749592[191] = 0;
   out_2519439478573749592[192] = 0;
   out_2519439478573749592[193] = 0;
   out_2519439478573749592[194] = 0;
   out_2519439478573749592[195] = 0;
   out_2519439478573749592[196] = 0;
   out_2519439478573749592[197] = 0;
   out_2519439478573749592[198] = 0;
   out_2519439478573749592[199] = 0;
   out_2519439478573749592[200] = 0;
   out_2519439478573749592[201] = 0;
   out_2519439478573749592[202] = 0;
   out_2519439478573749592[203] = 0;
   out_2519439478573749592[204] = 0;
   out_2519439478573749592[205] = 0;
   out_2519439478573749592[206] = 0;
   out_2519439478573749592[207] = 0;
   out_2519439478573749592[208] = 0;
   out_2519439478573749592[209] = 1;
   out_2519439478573749592[210] = 0;
   out_2519439478573749592[211] = 0;
   out_2519439478573749592[212] = 0;
   out_2519439478573749592[213] = 0;
   out_2519439478573749592[214] = 0;
   out_2519439478573749592[215] = 0;
   out_2519439478573749592[216] = 0;
   out_2519439478573749592[217] = 0;
   out_2519439478573749592[218] = 0;
   out_2519439478573749592[219] = 0;
   out_2519439478573749592[220] = 0;
   out_2519439478573749592[221] = 0;
   out_2519439478573749592[222] = 0;
   out_2519439478573749592[223] = 0;
   out_2519439478573749592[224] = 0;
   out_2519439478573749592[225] = 0;
   out_2519439478573749592[226] = 0;
   out_2519439478573749592[227] = 0;
   out_2519439478573749592[228] = 1;
   out_2519439478573749592[229] = 0;
   out_2519439478573749592[230] = 0;
   out_2519439478573749592[231] = 0;
   out_2519439478573749592[232] = 0;
   out_2519439478573749592[233] = 0;
   out_2519439478573749592[234] = 0;
   out_2519439478573749592[235] = 0;
   out_2519439478573749592[236] = 0;
   out_2519439478573749592[237] = 0;
   out_2519439478573749592[238] = 0;
   out_2519439478573749592[239] = 0;
   out_2519439478573749592[240] = 0;
   out_2519439478573749592[241] = 0;
   out_2519439478573749592[242] = 0;
   out_2519439478573749592[243] = 0;
   out_2519439478573749592[244] = 0;
   out_2519439478573749592[245] = 0;
   out_2519439478573749592[246] = 0;
   out_2519439478573749592[247] = 1;
   out_2519439478573749592[248] = 0;
   out_2519439478573749592[249] = 0;
   out_2519439478573749592[250] = 0;
   out_2519439478573749592[251] = 0;
   out_2519439478573749592[252] = 0;
   out_2519439478573749592[253] = 0;
   out_2519439478573749592[254] = 0;
   out_2519439478573749592[255] = 0;
   out_2519439478573749592[256] = 0;
   out_2519439478573749592[257] = 0;
   out_2519439478573749592[258] = 0;
   out_2519439478573749592[259] = 0;
   out_2519439478573749592[260] = 0;
   out_2519439478573749592[261] = 0;
   out_2519439478573749592[262] = 0;
   out_2519439478573749592[263] = 0;
   out_2519439478573749592[264] = 0;
   out_2519439478573749592[265] = 0;
   out_2519439478573749592[266] = 1;
   out_2519439478573749592[267] = 0;
   out_2519439478573749592[268] = 0;
   out_2519439478573749592[269] = 0;
   out_2519439478573749592[270] = 0;
   out_2519439478573749592[271] = 0;
   out_2519439478573749592[272] = 0;
   out_2519439478573749592[273] = 0;
   out_2519439478573749592[274] = 0;
   out_2519439478573749592[275] = 0;
   out_2519439478573749592[276] = 0;
   out_2519439478573749592[277] = 0;
   out_2519439478573749592[278] = 0;
   out_2519439478573749592[279] = 0;
   out_2519439478573749592[280] = 0;
   out_2519439478573749592[281] = 0;
   out_2519439478573749592[282] = 0;
   out_2519439478573749592[283] = 0;
   out_2519439478573749592[284] = 0;
   out_2519439478573749592[285] = 1;
   out_2519439478573749592[286] = 0;
   out_2519439478573749592[287] = 0;
   out_2519439478573749592[288] = 0;
   out_2519439478573749592[289] = 0;
   out_2519439478573749592[290] = 0;
   out_2519439478573749592[291] = 0;
   out_2519439478573749592[292] = 0;
   out_2519439478573749592[293] = 0;
   out_2519439478573749592[294] = 0;
   out_2519439478573749592[295] = 0;
   out_2519439478573749592[296] = 0;
   out_2519439478573749592[297] = 0;
   out_2519439478573749592[298] = 0;
   out_2519439478573749592[299] = 0;
   out_2519439478573749592[300] = 0;
   out_2519439478573749592[301] = 0;
   out_2519439478573749592[302] = 0;
   out_2519439478573749592[303] = 0;
   out_2519439478573749592[304] = 1;
   out_2519439478573749592[305] = 0;
   out_2519439478573749592[306] = 0;
   out_2519439478573749592[307] = 0;
   out_2519439478573749592[308] = 0;
   out_2519439478573749592[309] = 0;
   out_2519439478573749592[310] = 0;
   out_2519439478573749592[311] = 0;
   out_2519439478573749592[312] = 0;
   out_2519439478573749592[313] = 0;
   out_2519439478573749592[314] = 0;
   out_2519439478573749592[315] = 0;
   out_2519439478573749592[316] = 0;
   out_2519439478573749592[317] = 0;
   out_2519439478573749592[318] = 0;
   out_2519439478573749592[319] = 0;
   out_2519439478573749592[320] = 0;
   out_2519439478573749592[321] = 0;
   out_2519439478573749592[322] = 0;
   out_2519439478573749592[323] = 1;
}
void h_4(double *state, double *unused, double *out_4122032360045161599) {
   out_4122032360045161599[0] = state[6] + state[9];
   out_4122032360045161599[1] = state[7] + state[10];
   out_4122032360045161599[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_6299007443242394437) {
   out_6299007443242394437[0] = 0;
   out_6299007443242394437[1] = 0;
   out_6299007443242394437[2] = 0;
   out_6299007443242394437[3] = 0;
   out_6299007443242394437[4] = 0;
   out_6299007443242394437[5] = 0;
   out_6299007443242394437[6] = 1;
   out_6299007443242394437[7] = 0;
   out_6299007443242394437[8] = 0;
   out_6299007443242394437[9] = 1;
   out_6299007443242394437[10] = 0;
   out_6299007443242394437[11] = 0;
   out_6299007443242394437[12] = 0;
   out_6299007443242394437[13] = 0;
   out_6299007443242394437[14] = 0;
   out_6299007443242394437[15] = 0;
   out_6299007443242394437[16] = 0;
   out_6299007443242394437[17] = 0;
   out_6299007443242394437[18] = 0;
   out_6299007443242394437[19] = 0;
   out_6299007443242394437[20] = 0;
   out_6299007443242394437[21] = 0;
   out_6299007443242394437[22] = 0;
   out_6299007443242394437[23] = 0;
   out_6299007443242394437[24] = 0;
   out_6299007443242394437[25] = 1;
   out_6299007443242394437[26] = 0;
   out_6299007443242394437[27] = 0;
   out_6299007443242394437[28] = 1;
   out_6299007443242394437[29] = 0;
   out_6299007443242394437[30] = 0;
   out_6299007443242394437[31] = 0;
   out_6299007443242394437[32] = 0;
   out_6299007443242394437[33] = 0;
   out_6299007443242394437[34] = 0;
   out_6299007443242394437[35] = 0;
   out_6299007443242394437[36] = 0;
   out_6299007443242394437[37] = 0;
   out_6299007443242394437[38] = 0;
   out_6299007443242394437[39] = 0;
   out_6299007443242394437[40] = 0;
   out_6299007443242394437[41] = 0;
   out_6299007443242394437[42] = 0;
   out_6299007443242394437[43] = 0;
   out_6299007443242394437[44] = 1;
   out_6299007443242394437[45] = 0;
   out_6299007443242394437[46] = 0;
   out_6299007443242394437[47] = 1;
   out_6299007443242394437[48] = 0;
   out_6299007443242394437[49] = 0;
   out_6299007443242394437[50] = 0;
   out_6299007443242394437[51] = 0;
   out_6299007443242394437[52] = 0;
   out_6299007443242394437[53] = 0;
}
void h_10(double *state, double *unused, double *out_3087000031012309486) {
   out_3087000031012309486[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_3087000031012309486[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_3087000031012309486[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_8202087792414705539) {
   out_8202087792414705539[0] = 0;
   out_8202087792414705539[1] = 9.8100000000000005*cos(state[1]);
   out_8202087792414705539[2] = 0;
   out_8202087792414705539[3] = 0;
   out_8202087792414705539[4] = -state[8];
   out_8202087792414705539[5] = state[7];
   out_8202087792414705539[6] = 0;
   out_8202087792414705539[7] = state[5];
   out_8202087792414705539[8] = -state[4];
   out_8202087792414705539[9] = 0;
   out_8202087792414705539[10] = 0;
   out_8202087792414705539[11] = 0;
   out_8202087792414705539[12] = 1;
   out_8202087792414705539[13] = 0;
   out_8202087792414705539[14] = 0;
   out_8202087792414705539[15] = 1;
   out_8202087792414705539[16] = 0;
   out_8202087792414705539[17] = 0;
   out_8202087792414705539[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_8202087792414705539[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_8202087792414705539[20] = 0;
   out_8202087792414705539[21] = state[8];
   out_8202087792414705539[22] = 0;
   out_8202087792414705539[23] = -state[6];
   out_8202087792414705539[24] = -state[5];
   out_8202087792414705539[25] = 0;
   out_8202087792414705539[26] = state[3];
   out_8202087792414705539[27] = 0;
   out_8202087792414705539[28] = 0;
   out_8202087792414705539[29] = 0;
   out_8202087792414705539[30] = 0;
   out_8202087792414705539[31] = 1;
   out_8202087792414705539[32] = 0;
   out_8202087792414705539[33] = 0;
   out_8202087792414705539[34] = 1;
   out_8202087792414705539[35] = 0;
   out_8202087792414705539[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_8202087792414705539[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_8202087792414705539[38] = 0;
   out_8202087792414705539[39] = -state[7];
   out_8202087792414705539[40] = state[6];
   out_8202087792414705539[41] = 0;
   out_8202087792414705539[42] = state[4];
   out_8202087792414705539[43] = -state[3];
   out_8202087792414705539[44] = 0;
   out_8202087792414705539[45] = 0;
   out_8202087792414705539[46] = 0;
   out_8202087792414705539[47] = 0;
   out_8202087792414705539[48] = 0;
   out_8202087792414705539[49] = 0;
   out_8202087792414705539[50] = 1;
   out_8202087792414705539[51] = 0;
   out_8202087792414705539[52] = 0;
   out_8202087792414705539[53] = 1;
}
void h_13(double *state, double *unused, double *out_6042732269179361123) {
   out_6042732269179361123[0] = state[3];
   out_6042732269179361123[1] = state[4];
   out_6042732269179361123[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3086733617910061636) {
   out_3086733617910061636[0] = 0;
   out_3086733617910061636[1] = 0;
   out_3086733617910061636[2] = 0;
   out_3086733617910061636[3] = 1;
   out_3086733617910061636[4] = 0;
   out_3086733617910061636[5] = 0;
   out_3086733617910061636[6] = 0;
   out_3086733617910061636[7] = 0;
   out_3086733617910061636[8] = 0;
   out_3086733617910061636[9] = 0;
   out_3086733617910061636[10] = 0;
   out_3086733617910061636[11] = 0;
   out_3086733617910061636[12] = 0;
   out_3086733617910061636[13] = 0;
   out_3086733617910061636[14] = 0;
   out_3086733617910061636[15] = 0;
   out_3086733617910061636[16] = 0;
   out_3086733617910061636[17] = 0;
   out_3086733617910061636[18] = 0;
   out_3086733617910061636[19] = 0;
   out_3086733617910061636[20] = 0;
   out_3086733617910061636[21] = 0;
   out_3086733617910061636[22] = 1;
   out_3086733617910061636[23] = 0;
   out_3086733617910061636[24] = 0;
   out_3086733617910061636[25] = 0;
   out_3086733617910061636[26] = 0;
   out_3086733617910061636[27] = 0;
   out_3086733617910061636[28] = 0;
   out_3086733617910061636[29] = 0;
   out_3086733617910061636[30] = 0;
   out_3086733617910061636[31] = 0;
   out_3086733617910061636[32] = 0;
   out_3086733617910061636[33] = 0;
   out_3086733617910061636[34] = 0;
   out_3086733617910061636[35] = 0;
   out_3086733617910061636[36] = 0;
   out_3086733617910061636[37] = 0;
   out_3086733617910061636[38] = 0;
   out_3086733617910061636[39] = 0;
   out_3086733617910061636[40] = 0;
   out_3086733617910061636[41] = 1;
   out_3086733617910061636[42] = 0;
   out_3086733617910061636[43] = 0;
   out_3086733617910061636[44] = 0;
   out_3086733617910061636[45] = 0;
   out_3086733617910061636[46] = 0;
   out_3086733617910061636[47] = 0;
   out_3086733617910061636[48] = 0;
   out_3086733617910061636[49] = 0;
   out_3086733617910061636[50] = 0;
   out_3086733617910061636[51] = 0;
   out_3086733617910061636[52] = 0;
   out_3086733617910061636[53] = 0;
}
void h_14(double *state, double *unused, double *out_7471847647180952458) {
   out_7471847647180952458[0] = state[6];
   out_7471847647180952458[1] = state[7];
   out_7471847647180952458[2] = state[8];
}
void H_14(double *state, double *unused, double *out_2335766586902909908) {
   out_2335766586902909908[0] = 0;
   out_2335766586902909908[1] = 0;
   out_2335766586902909908[2] = 0;
   out_2335766586902909908[3] = 0;
   out_2335766586902909908[4] = 0;
   out_2335766586902909908[5] = 0;
   out_2335766586902909908[6] = 1;
   out_2335766586902909908[7] = 0;
   out_2335766586902909908[8] = 0;
   out_2335766586902909908[9] = 0;
   out_2335766586902909908[10] = 0;
   out_2335766586902909908[11] = 0;
   out_2335766586902909908[12] = 0;
   out_2335766586902909908[13] = 0;
   out_2335766586902909908[14] = 0;
   out_2335766586902909908[15] = 0;
   out_2335766586902909908[16] = 0;
   out_2335766586902909908[17] = 0;
   out_2335766586902909908[18] = 0;
   out_2335766586902909908[19] = 0;
   out_2335766586902909908[20] = 0;
   out_2335766586902909908[21] = 0;
   out_2335766586902909908[22] = 0;
   out_2335766586902909908[23] = 0;
   out_2335766586902909908[24] = 0;
   out_2335766586902909908[25] = 1;
   out_2335766586902909908[26] = 0;
   out_2335766586902909908[27] = 0;
   out_2335766586902909908[28] = 0;
   out_2335766586902909908[29] = 0;
   out_2335766586902909908[30] = 0;
   out_2335766586902909908[31] = 0;
   out_2335766586902909908[32] = 0;
   out_2335766586902909908[33] = 0;
   out_2335766586902909908[34] = 0;
   out_2335766586902909908[35] = 0;
   out_2335766586902909908[36] = 0;
   out_2335766586902909908[37] = 0;
   out_2335766586902909908[38] = 0;
   out_2335766586902909908[39] = 0;
   out_2335766586902909908[40] = 0;
   out_2335766586902909908[41] = 0;
   out_2335766586902909908[42] = 0;
   out_2335766586902909908[43] = 0;
   out_2335766586902909908[44] = 1;
   out_2335766586902909908[45] = 0;
   out_2335766586902909908[46] = 0;
   out_2335766586902909908[47] = 0;
   out_2335766586902909908[48] = 0;
   out_2335766586902909908[49] = 0;
   out_2335766586902909908[50] = 0;
   out_2335766586902909908[51] = 0;
   out_2335766586902909908[52] = 0;
   out_2335766586902909908[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_4331083049534056355) {
  err_fun(nom_x, delta_x, out_4331083049534056355);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5197883329726451987) {
  inv_err_fun(nom_x, true_x, out_5197883329726451987);
}
void pose_H_mod_fun(double *state, double *out_8877666100320465704) {
  H_mod_fun(state, out_8877666100320465704);
}
void pose_f_fun(double *state, double dt, double *out_3376588760060985122) {
  f_fun(state,  dt, out_3376588760060985122);
}
void pose_F_fun(double *state, double dt, double *out_2519439478573749592) {
  F_fun(state,  dt, out_2519439478573749592);
}
void pose_h_4(double *state, double *unused, double *out_4122032360045161599) {
  h_4(state, unused, out_4122032360045161599);
}
void pose_H_4(double *state, double *unused, double *out_6299007443242394437) {
  H_4(state, unused, out_6299007443242394437);
}
void pose_h_10(double *state, double *unused, double *out_3087000031012309486) {
  h_10(state, unused, out_3087000031012309486);
}
void pose_H_10(double *state, double *unused, double *out_8202087792414705539) {
  H_10(state, unused, out_8202087792414705539);
}
void pose_h_13(double *state, double *unused, double *out_6042732269179361123) {
  h_13(state, unused, out_6042732269179361123);
}
void pose_H_13(double *state, double *unused, double *out_3086733617910061636) {
  H_13(state, unused, out_3086733617910061636);
}
void pose_h_14(double *state, double *unused, double *out_7471847647180952458) {
  h_14(state, unused, out_7471847647180952458);
}
void pose_H_14(double *state, double *unused, double *out_2335766586902909908) {
  H_14(state, unused, out_2335766586902909908);
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
