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
void err_fun(double *nom_x, double *delta_x, double *out_1541433372370496057) {
   out_1541433372370496057[0] = delta_x[0] + nom_x[0];
   out_1541433372370496057[1] = delta_x[1] + nom_x[1];
   out_1541433372370496057[2] = delta_x[2] + nom_x[2];
   out_1541433372370496057[3] = delta_x[3] + nom_x[3];
   out_1541433372370496057[4] = delta_x[4] + nom_x[4];
   out_1541433372370496057[5] = delta_x[5] + nom_x[5];
   out_1541433372370496057[6] = delta_x[6] + nom_x[6];
   out_1541433372370496057[7] = delta_x[7] + nom_x[7];
   out_1541433372370496057[8] = delta_x[8] + nom_x[8];
   out_1541433372370496057[9] = delta_x[9] + nom_x[9];
   out_1541433372370496057[10] = delta_x[10] + nom_x[10];
   out_1541433372370496057[11] = delta_x[11] + nom_x[11];
   out_1541433372370496057[12] = delta_x[12] + nom_x[12];
   out_1541433372370496057[13] = delta_x[13] + nom_x[13];
   out_1541433372370496057[14] = delta_x[14] + nom_x[14];
   out_1541433372370496057[15] = delta_x[15] + nom_x[15];
   out_1541433372370496057[16] = delta_x[16] + nom_x[16];
   out_1541433372370496057[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8373660040473895336) {
   out_8373660040473895336[0] = -nom_x[0] + true_x[0];
   out_8373660040473895336[1] = -nom_x[1] + true_x[1];
   out_8373660040473895336[2] = -nom_x[2] + true_x[2];
   out_8373660040473895336[3] = -nom_x[3] + true_x[3];
   out_8373660040473895336[4] = -nom_x[4] + true_x[4];
   out_8373660040473895336[5] = -nom_x[5] + true_x[5];
   out_8373660040473895336[6] = -nom_x[6] + true_x[6];
   out_8373660040473895336[7] = -nom_x[7] + true_x[7];
   out_8373660040473895336[8] = -nom_x[8] + true_x[8];
   out_8373660040473895336[9] = -nom_x[9] + true_x[9];
   out_8373660040473895336[10] = -nom_x[10] + true_x[10];
   out_8373660040473895336[11] = -nom_x[11] + true_x[11];
   out_8373660040473895336[12] = -nom_x[12] + true_x[12];
   out_8373660040473895336[13] = -nom_x[13] + true_x[13];
   out_8373660040473895336[14] = -nom_x[14] + true_x[14];
   out_8373660040473895336[15] = -nom_x[15] + true_x[15];
   out_8373660040473895336[16] = -nom_x[16] + true_x[16];
   out_8373660040473895336[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_2891433507387146264) {
   out_2891433507387146264[0] = 1.0;
   out_2891433507387146264[1] = 0.0;
   out_2891433507387146264[2] = 0.0;
   out_2891433507387146264[3] = 0.0;
   out_2891433507387146264[4] = 0.0;
   out_2891433507387146264[5] = 0.0;
   out_2891433507387146264[6] = 0.0;
   out_2891433507387146264[7] = 0.0;
   out_2891433507387146264[8] = 0.0;
   out_2891433507387146264[9] = 0.0;
   out_2891433507387146264[10] = 0.0;
   out_2891433507387146264[11] = 0.0;
   out_2891433507387146264[12] = 0.0;
   out_2891433507387146264[13] = 0.0;
   out_2891433507387146264[14] = 0.0;
   out_2891433507387146264[15] = 0.0;
   out_2891433507387146264[16] = 0.0;
   out_2891433507387146264[17] = 0.0;
   out_2891433507387146264[18] = 0.0;
   out_2891433507387146264[19] = 1.0;
   out_2891433507387146264[20] = 0.0;
   out_2891433507387146264[21] = 0.0;
   out_2891433507387146264[22] = 0.0;
   out_2891433507387146264[23] = 0.0;
   out_2891433507387146264[24] = 0.0;
   out_2891433507387146264[25] = 0.0;
   out_2891433507387146264[26] = 0.0;
   out_2891433507387146264[27] = 0.0;
   out_2891433507387146264[28] = 0.0;
   out_2891433507387146264[29] = 0.0;
   out_2891433507387146264[30] = 0.0;
   out_2891433507387146264[31] = 0.0;
   out_2891433507387146264[32] = 0.0;
   out_2891433507387146264[33] = 0.0;
   out_2891433507387146264[34] = 0.0;
   out_2891433507387146264[35] = 0.0;
   out_2891433507387146264[36] = 0.0;
   out_2891433507387146264[37] = 0.0;
   out_2891433507387146264[38] = 1.0;
   out_2891433507387146264[39] = 0.0;
   out_2891433507387146264[40] = 0.0;
   out_2891433507387146264[41] = 0.0;
   out_2891433507387146264[42] = 0.0;
   out_2891433507387146264[43] = 0.0;
   out_2891433507387146264[44] = 0.0;
   out_2891433507387146264[45] = 0.0;
   out_2891433507387146264[46] = 0.0;
   out_2891433507387146264[47] = 0.0;
   out_2891433507387146264[48] = 0.0;
   out_2891433507387146264[49] = 0.0;
   out_2891433507387146264[50] = 0.0;
   out_2891433507387146264[51] = 0.0;
   out_2891433507387146264[52] = 0.0;
   out_2891433507387146264[53] = 0.0;
   out_2891433507387146264[54] = 0.0;
   out_2891433507387146264[55] = 0.0;
   out_2891433507387146264[56] = 0.0;
   out_2891433507387146264[57] = 1.0;
   out_2891433507387146264[58] = 0.0;
   out_2891433507387146264[59] = 0.0;
   out_2891433507387146264[60] = 0.0;
   out_2891433507387146264[61] = 0.0;
   out_2891433507387146264[62] = 0.0;
   out_2891433507387146264[63] = 0.0;
   out_2891433507387146264[64] = 0.0;
   out_2891433507387146264[65] = 0.0;
   out_2891433507387146264[66] = 0.0;
   out_2891433507387146264[67] = 0.0;
   out_2891433507387146264[68] = 0.0;
   out_2891433507387146264[69] = 0.0;
   out_2891433507387146264[70] = 0.0;
   out_2891433507387146264[71] = 0.0;
   out_2891433507387146264[72] = 0.0;
   out_2891433507387146264[73] = 0.0;
   out_2891433507387146264[74] = 0.0;
   out_2891433507387146264[75] = 0.0;
   out_2891433507387146264[76] = 1.0;
   out_2891433507387146264[77] = 0.0;
   out_2891433507387146264[78] = 0.0;
   out_2891433507387146264[79] = 0.0;
   out_2891433507387146264[80] = 0.0;
   out_2891433507387146264[81] = 0.0;
   out_2891433507387146264[82] = 0.0;
   out_2891433507387146264[83] = 0.0;
   out_2891433507387146264[84] = 0.0;
   out_2891433507387146264[85] = 0.0;
   out_2891433507387146264[86] = 0.0;
   out_2891433507387146264[87] = 0.0;
   out_2891433507387146264[88] = 0.0;
   out_2891433507387146264[89] = 0.0;
   out_2891433507387146264[90] = 0.0;
   out_2891433507387146264[91] = 0.0;
   out_2891433507387146264[92] = 0.0;
   out_2891433507387146264[93] = 0.0;
   out_2891433507387146264[94] = 0.0;
   out_2891433507387146264[95] = 1.0;
   out_2891433507387146264[96] = 0.0;
   out_2891433507387146264[97] = 0.0;
   out_2891433507387146264[98] = 0.0;
   out_2891433507387146264[99] = 0.0;
   out_2891433507387146264[100] = 0.0;
   out_2891433507387146264[101] = 0.0;
   out_2891433507387146264[102] = 0.0;
   out_2891433507387146264[103] = 0.0;
   out_2891433507387146264[104] = 0.0;
   out_2891433507387146264[105] = 0.0;
   out_2891433507387146264[106] = 0.0;
   out_2891433507387146264[107] = 0.0;
   out_2891433507387146264[108] = 0.0;
   out_2891433507387146264[109] = 0.0;
   out_2891433507387146264[110] = 0.0;
   out_2891433507387146264[111] = 0.0;
   out_2891433507387146264[112] = 0.0;
   out_2891433507387146264[113] = 0.0;
   out_2891433507387146264[114] = 1.0;
   out_2891433507387146264[115] = 0.0;
   out_2891433507387146264[116] = 0.0;
   out_2891433507387146264[117] = 0.0;
   out_2891433507387146264[118] = 0.0;
   out_2891433507387146264[119] = 0.0;
   out_2891433507387146264[120] = 0.0;
   out_2891433507387146264[121] = 0.0;
   out_2891433507387146264[122] = 0.0;
   out_2891433507387146264[123] = 0.0;
   out_2891433507387146264[124] = 0.0;
   out_2891433507387146264[125] = 0.0;
   out_2891433507387146264[126] = 0.0;
   out_2891433507387146264[127] = 0.0;
   out_2891433507387146264[128] = 0.0;
   out_2891433507387146264[129] = 0.0;
   out_2891433507387146264[130] = 0.0;
   out_2891433507387146264[131] = 0.0;
   out_2891433507387146264[132] = 0.0;
   out_2891433507387146264[133] = 1.0;
   out_2891433507387146264[134] = 0.0;
   out_2891433507387146264[135] = 0.0;
   out_2891433507387146264[136] = 0.0;
   out_2891433507387146264[137] = 0.0;
   out_2891433507387146264[138] = 0.0;
   out_2891433507387146264[139] = 0.0;
   out_2891433507387146264[140] = 0.0;
   out_2891433507387146264[141] = 0.0;
   out_2891433507387146264[142] = 0.0;
   out_2891433507387146264[143] = 0.0;
   out_2891433507387146264[144] = 0.0;
   out_2891433507387146264[145] = 0.0;
   out_2891433507387146264[146] = 0.0;
   out_2891433507387146264[147] = 0.0;
   out_2891433507387146264[148] = 0.0;
   out_2891433507387146264[149] = 0.0;
   out_2891433507387146264[150] = 0.0;
   out_2891433507387146264[151] = 0.0;
   out_2891433507387146264[152] = 1.0;
   out_2891433507387146264[153] = 0.0;
   out_2891433507387146264[154] = 0.0;
   out_2891433507387146264[155] = 0.0;
   out_2891433507387146264[156] = 0.0;
   out_2891433507387146264[157] = 0.0;
   out_2891433507387146264[158] = 0.0;
   out_2891433507387146264[159] = 0.0;
   out_2891433507387146264[160] = 0.0;
   out_2891433507387146264[161] = 0.0;
   out_2891433507387146264[162] = 0.0;
   out_2891433507387146264[163] = 0.0;
   out_2891433507387146264[164] = 0.0;
   out_2891433507387146264[165] = 0.0;
   out_2891433507387146264[166] = 0.0;
   out_2891433507387146264[167] = 0.0;
   out_2891433507387146264[168] = 0.0;
   out_2891433507387146264[169] = 0.0;
   out_2891433507387146264[170] = 0.0;
   out_2891433507387146264[171] = 1.0;
   out_2891433507387146264[172] = 0.0;
   out_2891433507387146264[173] = 0.0;
   out_2891433507387146264[174] = 0.0;
   out_2891433507387146264[175] = 0.0;
   out_2891433507387146264[176] = 0.0;
   out_2891433507387146264[177] = 0.0;
   out_2891433507387146264[178] = 0.0;
   out_2891433507387146264[179] = 0.0;
   out_2891433507387146264[180] = 0.0;
   out_2891433507387146264[181] = 0.0;
   out_2891433507387146264[182] = 0.0;
   out_2891433507387146264[183] = 0.0;
   out_2891433507387146264[184] = 0.0;
   out_2891433507387146264[185] = 0.0;
   out_2891433507387146264[186] = 0.0;
   out_2891433507387146264[187] = 0.0;
   out_2891433507387146264[188] = 0.0;
   out_2891433507387146264[189] = 0.0;
   out_2891433507387146264[190] = 1.0;
   out_2891433507387146264[191] = 0.0;
   out_2891433507387146264[192] = 0.0;
   out_2891433507387146264[193] = 0.0;
   out_2891433507387146264[194] = 0.0;
   out_2891433507387146264[195] = 0.0;
   out_2891433507387146264[196] = 0.0;
   out_2891433507387146264[197] = 0.0;
   out_2891433507387146264[198] = 0.0;
   out_2891433507387146264[199] = 0.0;
   out_2891433507387146264[200] = 0.0;
   out_2891433507387146264[201] = 0.0;
   out_2891433507387146264[202] = 0.0;
   out_2891433507387146264[203] = 0.0;
   out_2891433507387146264[204] = 0.0;
   out_2891433507387146264[205] = 0.0;
   out_2891433507387146264[206] = 0.0;
   out_2891433507387146264[207] = 0.0;
   out_2891433507387146264[208] = 0.0;
   out_2891433507387146264[209] = 1.0;
   out_2891433507387146264[210] = 0.0;
   out_2891433507387146264[211] = 0.0;
   out_2891433507387146264[212] = 0.0;
   out_2891433507387146264[213] = 0.0;
   out_2891433507387146264[214] = 0.0;
   out_2891433507387146264[215] = 0.0;
   out_2891433507387146264[216] = 0.0;
   out_2891433507387146264[217] = 0.0;
   out_2891433507387146264[218] = 0.0;
   out_2891433507387146264[219] = 0.0;
   out_2891433507387146264[220] = 0.0;
   out_2891433507387146264[221] = 0.0;
   out_2891433507387146264[222] = 0.0;
   out_2891433507387146264[223] = 0.0;
   out_2891433507387146264[224] = 0.0;
   out_2891433507387146264[225] = 0.0;
   out_2891433507387146264[226] = 0.0;
   out_2891433507387146264[227] = 0.0;
   out_2891433507387146264[228] = 1.0;
   out_2891433507387146264[229] = 0.0;
   out_2891433507387146264[230] = 0.0;
   out_2891433507387146264[231] = 0.0;
   out_2891433507387146264[232] = 0.0;
   out_2891433507387146264[233] = 0.0;
   out_2891433507387146264[234] = 0.0;
   out_2891433507387146264[235] = 0.0;
   out_2891433507387146264[236] = 0.0;
   out_2891433507387146264[237] = 0.0;
   out_2891433507387146264[238] = 0.0;
   out_2891433507387146264[239] = 0.0;
   out_2891433507387146264[240] = 0.0;
   out_2891433507387146264[241] = 0.0;
   out_2891433507387146264[242] = 0.0;
   out_2891433507387146264[243] = 0.0;
   out_2891433507387146264[244] = 0.0;
   out_2891433507387146264[245] = 0.0;
   out_2891433507387146264[246] = 0.0;
   out_2891433507387146264[247] = 1.0;
   out_2891433507387146264[248] = 0.0;
   out_2891433507387146264[249] = 0.0;
   out_2891433507387146264[250] = 0.0;
   out_2891433507387146264[251] = 0.0;
   out_2891433507387146264[252] = 0.0;
   out_2891433507387146264[253] = 0.0;
   out_2891433507387146264[254] = 0.0;
   out_2891433507387146264[255] = 0.0;
   out_2891433507387146264[256] = 0.0;
   out_2891433507387146264[257] = 0.0;
   out_2891433507387146264[258] = 0.0;
   out_2891433507387146264[259] = 0.0;
   out_2891433507387146264[260] = 0.0;
   out_2891433507387146264[261] = 0.0;
   out_2891433507387146264[262] = 0.0;
   out_2891433507387146264[263] = 0.0;
   out_2891433507387146264[264] = 0.0;
   out_2891433507387146264[265] = 0.0;
   out_2891433507387146264[266] = 1.0;
   out_2891433507387146264[267] = 0.0;
   out_2891433507387146264[268] = 0.0;
   out_2891433507387146264[269] = 0.0;
   out_2891433507387146264[270] = 0.0;
   out_2891433507387146264[271] = 0.0;
   out_2891433507387146264[272] = 0.0;
   out_2891433507387146264[273] = 0.0;
   out_2891433507387146264[274] = 0.0;
   out_2891433507387146264[275] = 0.0;
   out_2891433507387146264[276] = 0.0;
   out_2891433507387146264[277] = 0.0;
   out_2891433507387146264[278] = 0.0;
   out_2891433507387146264[279] = 0.0;
   out_2891433507387146264[280] = 0.0;
   out_2891433507387146264[281] = 0.0;
   out_2891433507387146264[282] = 0.0;
   out_2891433507387146264[283] = 0.0;
   out_2891433507387146264[284] = 0.0;
   out_2891433507387146264[285] = 1.0;
   out_2891433507387146264[286] = 0.0;
   out_2891433507387146264[287] = 0.0;
   out_2891433507387146264[288] = 0.0;
   out_2891433507387146264[289] = 0.0;
   out_2891433507387146264[290] = 0.0;
   out_2891433507387146264[291] = 0.0;
   out_2891433507387146264[292] = 0.0;
   out_2891433507387146264[293] = 0.0;
   out_2891433507387146264[294] = 0.0;
   out_2891433507387146264[295] = 0.0;
   out_2891433507387146264[296] = 0.0;
   out_2891433507387146264[297] = 0.0;
   out_2891433507387146264[298] = 0.0;
   out_2891433507387146264[299] = 0.0;
   out_2891433507387146264[300] = 0.0;
   out_2891433507387146264[301] = 0.0;
   out_2891433507387146264[302] = 0.0;
   out_2891433507387146264[303] = 0.0;
   out_2891433507387146264[304] = 1.0;
   out_2891433507387146264[305] = 0.0;
   out_2891433507387146264[306] = 0.0;
   out_2891433507387146264[307] = 0.0;
   out_2891433507387146264[308] = 0.0;
   out_2891433507387146264[309] = 0.0;
   out_2891433507387146264[310] = 0.0;
   out_2891433507387146264[311] = 0.0;
   out_2891433507387146264[312] = 0.0;
   out_2891433507387146264[313] = 0.0;
   out_2891433507387146264[314] = 0.0;
   out_2891433507387146264[315] = 0.0;
   out_2891433507387146264[316] = 0.0;
   out_2891433507387146264[317] = 0.0;
   out_2891433507387146264[318] = 0.0;
   out_2891433507387146264[319] = 0.0;
   out_2891433507387146264[320] = 0.0;
   out_2891433507387146264[321] = 0.0;
   out_2891433507387146264[322] = 0.0;
   out_2891433507387146264[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_3325430116042611385) {
   out_3325430116042611385[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_3325430116042611385[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_3325430116042611385[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_3325430116042611385[3] = dt*state[12] + state[3];
   out_3325430116042611385[4] = dt*state[13] + state[4];
   out_3325430116042611385[5] = dt*state[14] + state[5];
   out_3325430116042611385[6] = state[6];
   out_3325430116042611385[7] = state[7];
   out_3325430116042611385[8] = state[8];
   out_3325430116042611385[9] = state[9];
   out_3325430116042611385[10] = state[10];
   out_3325430116042611385[11] = state[11];
   out_3325430116042611385[12] = state[12];
   out_3325430116042611385[13] = state[13];
   out_3325430116042611385[14] = state[14];
   out_3325430116042611385[15] = state[15];
   out_3325430116042611385[16] = state[16];
   out_3325430116042611385[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1604126537921635908) {
   out_1604126537921635908[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1604126537921635908[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1604126537921635908[2] = 0;
   out_1604126537921635908[3] = 0;
   out_1604126537921635908[4] = 0;
   out_1604126537921635908[5] = 0;
   out_1604126537921635908[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1604126537921635908[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1604126537921635908[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1604126537921635908[9] = 0;
   out_1604126537921635908[10] = 0;
   out_1604126537921635908[11] = 0;
   out_1604126537921635908[12] = 0;
   out_1604126537921635908[13] = 0;
   out_1604126537921635908[14] = 0;
   out_1604126537921635908[15] = 0;
   out_1604126537921635908[16] = 0;
   out_1604126537921635908[17] = 0;
   out_1604126537921635908[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1604126537921635908[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1604126537921635908[20] = 0;
   out_1604126537921635908[21] = 0;
   out_1604126537921635908[22] = 0;
   out_1604126537921635908[23] = 0;
   out_1604126537921635908[24] = 0;
   out_1604126537921635908[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1604126537921635908[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1604126537921635908[27] = 0;
   out_1604126537921635908[28] = 0;
   out_1604126537921635908[29] = 0;
   out_1604126537921635908[30] = 0;
   out_1604126537921635908[31] = 0;
   out_1604126537921635908[32] = 0;
   out_1604126537921635908[33] = 0;
   out_1604126537921635908[34] = 0;
   out_1604126537921635908[35] = 0;
   out_1604126537921635908[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1604126537921635908[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1604126537921635908[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1604126537921635908[39] = 0;
   out_1604126537921635908[40] = 0;
   out_1604126537921635908[41] = 0;
   out_1604126537921635908[42] = 0;
   out_1604126537921635908[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1604126537921635908[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1604126537921635908[45] = 0;
   out_1604126537921635908[46] = 0;
   out_1604126537921635908[47] = 0;
   out_1604126537921635908[48] = 0;
   out_1604126537921635908[49] = 0;
   out_1604126537921635908[50] = 0;
   out_1604126537921635908[51] = 0;
   out_1604126537921635908[52] = 0;
   out_1604126537921635908[53] = 0;
   out_1604126537921635908[54] = 0;
   out_1604126537921635908[55] = 0;
   out_1604126537921635908[56] = 0;
   out_1604126537921635908[57] = 1;
   out_1604126537921635908[58] = 0;
   out_1604126537921635908[59] = 0;
   out_1604126537921635908[60] = 0;
   out_1604126537921635908[61] = 0;
   out_1604126537921635908[62] = 0;
   out_1604126537921635908[63] = 0;
   out_1604126537921635908[64] = 0;
   out_1604126537921635908[65] = 0;
   out_1604126537921635908[66] = dt;
   out_1604126537921635908[67] = 0;
   out_1604126537921635908[68] = 0;
   out_1604126537921635908[69] = 0;
   out_1604126537921635908[70] = 0;
   out_1604126537921635908[71] = 0;
   out_1604126537921635908[72] = 0;
   out_1604126537921635908[73] = 0;
   out_1604126537921635908[74] = 0;
   out_1604126537921635908[75] = 0;
   out_1604126537921635908[76] = 1;
   out_1604126537921635908[77] = 0;
   out_1604126537921635908[78] = 0;
   out_1604126537921635908[79] = 0;
   out_1604126537921635908[80] = 0;
   out_1604126537921635908[81] = 0;
   out_1604126537921635908[82] = 0;
   out_1604126537921635908[83] = 0;
   out_1604126537921635908[84] = 0;
   out_1604126537921635908[85] = dt;
   out_1604126537921635908[86] = 0;
   out_1604126537921635908[87] = 0;
   out_1604126537921635908[88] = 0;
   out_1604126537921635908[89] = 0;
   out_1604126537921635908[90] = 0;
   out_1604126537921635908[91] = 0;
   out_1604126537921635908[92] = 0;
   out_1604126537921635908[93] = 0;
   out_1604126537921635908[94] = 0;
   out_1604126537921635908[95] = 1;
   out_1604126537921635908[96] = 0;
   out_1604126537921635908[97] = 0;
   out_1604126537921635908[98] = 0;
   out_1604126537921635908[99] = 0;
   out_1604126537921635908[100] = 0;
   out_1604126537921635908[101] = 0;
   out_1604126537921635908[102] = 0;
   out_1604126537921635908[103] = 0;
   out_1604126537921635908[104] = dt;
   out_1604126537921635908[105] = 0;
   out_1604126537921635908[106] = 0;
   out_1604126537921635908[107] = 0;
   out_1604126537921635908[108] = 0;
   out_1604126537921635908[109] = 0;
   out_1604126537921635908[110] = 0;
   out_1604126537921635908[111] = 0;
   out_1604126537921635908[112] = 0;
   out_1604126537921635908[113] = 0;
   out_1604126537921635908[114] = 1;
   out_1604126537921635908[115] = 0;
   out_1604126537921635908[116] = 0;
   out_1604126537921635908[117] = 0;
   out_1604126537921635908[118] = 0;
   out_1604126537921635908[119] = 0;
   out_1604126537921635908[120] = 0;
   out_1604126537921635908[121] = 0;
   out_1604126537921635908[122] = 0;
   out_1604126537921635908[123] = 0;
   out_1604126537921635908[124] = 0;
   out_1604126537921635908[125] = 0;
   out_1604126537921635908[126] = 0;
   out_1604126537921635908[127] = 0;
   out_1604126537921635908[128] = 0;
   out_1604126537921635908[129] = 0;
   out_1604126537921635908[130] = 0;
   out_1604126537921635908[131] = 0;
   out_1604126537921635908[132] = 0;
   out_1604126537921635908[133] = 1;
   out_1604126537921635908[134] = 0;
   out_1604126537921635908[135] = 0;
   out_1604126537921635908[136] = 0;
   out_1604126537921635908[137] = 0;
   out_1604126537921635908[138] = 0;
   out_1604126537921635908[139] = 0;
   out_1604126537921635908[140] = 0;
   out_1604126537921635908[141] = 0;
   out_1604126537921635908[142] = 0;
   out_1604126537921635908[143] = 0;
   out_1604126537921635908[144] = 0;
   out_1604126537921635908[145] = 0;
   out_1604126537921635908[146] = 0;
   out_1604126537921635908[147] = 0;
   out_1604126537921635908[148] = 0;
   out_1604126537921635908[149] = 0;
   out_1604126537921635908[150] = 0;
   out_1604126537921635908[151] = 0;
   out_1604126537921635908[152] = 1;
   out_1604126537921635908[153] = 0;
   out_1604126537921635908[154] = 0;
   out_1604126537921635908[155] = 0;
   out_1604126537921635908[156] = 0;
   out_1604126537921635908[157] = 0;
   out_1604126537921635908[158] = 0;
   out_1604126537921635908[159] = 0;
   out_1604126537921635908[160] = 0;
   out_1604126537921635908[161] = 0;
   out_1604126537921635908[162] = 0;
   out_1604126537921635908[163] = 0;
   out_1604126537921635908[164] = 0;
   out_1604126537921635908[165] = 0;
   out_1604126537921635908[166] = 0;
   out_1604126537921635908[167] = 0;
   out_1604126537921635908[168] = 0;
   out_1604126537921635908[169] = 0;
   out_1604126537921635908[170] = 0;
   out_1604126537921635908[171] = 1;
   out_1604126537921635908[172] = 0;
   out_1604126537921635908[173] = 0;
   out_1604126537921635908[174] = 0;
   out_1604126537921635908[175] = 0;
   out_1604126537921635908[176] = 0;
   out_1604126537921635908[177] = 0;
   out_1604126537921635908[178] = 0;
   out_1604126537921635908[179] = 0;
   out_1604126537921635908[180] = 0;
   out_1604126537921635908[181] = 0;
   out_1604126537921635908[182] = 0;
   out_1604126537921635908[183] = 0;
   out_1604126537921635908[184] = 0;
   out_1604126537921635908[185] = 0;
   out_1604126537921635908[186] = 0;
   out_1604126537921635908[187] = 0;
   out_1604126537921635908[188] = 0;
   out_1604126537921635908[189] = 0;
   out_1604126537921635908[190] = 1;
   out_1604126537921635908[191] = 0;
   out_1604126537921635908[192] = 0;
   out_1604126537921635908[193] = 0;
   out_1604126537921635908[194] = 0;
   out_1604126537921635908[195] = 0;
   out_1604126537921635908[196] = 0;
   out_1604126537921635908[197] = 0;
   out_1604126537921635908[198] = 0;
   out_1604126537921635908[199] = 0;
   out_1604126537921635908[200] = 0;
   out_1604126537921635908[201] = 0;
   out_1604126537921635908[202] = 0;
   out_1604126537921635908[203] = 0;
   out_1604126537921635908[204] = 0;
   out_1604126537921635908[205] = 0;
   out_1604126537921635908[206] = 0;
   out_1604126537921635908[207] = 0;
   out_1604126537921635908[208] = 0;
   out_1604126537921635908[209] = 1;
   out_1604126537921635908[210] = 0;
   out_1604126537921635908[211] = 0;
   out_1604126537921635908[212] = 0;
   out_1604126537921635908[213] = 0;
   out_1604126537921635908[214] = 0;
   out_1604126537921635908[215] = 0;
   out_1604126537921635908[216] = 0;
   out_1604126537921635908[217] = 0;
   out_1604126537921635908[218] = 0;
   out_1604126537921635908[219] = 0;
   out_1604126537921635908[220] = 0;
   out_1604126537921635908[221] = 0;
   out_1604126537921635908[222] = 0;
   out_1604126537921635908[223] = 0;
   out_1604126537921635908[224] = 0;
   out_1604126537921635908[225] = 0;
   out_1604126537921635908[226] = 0;
   out_1604126537921635908[227] = 0;
   out_1604126537921635908[228] = 1;
   out_1604126537921635908[229] = 0;
   out_1604126537921635908[230] = 0;
   out_1604126537921635908[231] = 0;
   out_1604126537921635908[232] = 0;
   out_1604126537921635908[233] = 0;
   out_1604126537921635908[234] = 0;
   out_1604126537921635908[235] = 0;
   out_1604126537921635908[236] = 0;
   out_1604126537921635908[237] = 0;
   out_1604126537921635908[238] = 0;
   out_1604126537921635908[239] = 0;
   out_1604126537921635908[240] = 0;
   out_1604126537921635908[241] = 0;
   out_1604126537921635908[242] = 0;
   out_1604126537921635908[243] = 0;
   out_1604126537921635908[244] = 0;
   out_1604126537921635908[245] = 0;
   out_1604126537921635908[246] = 0;
   out_1604126537921635908[247] = 1;
   out_1604126537921635908[248] = 0;
   out_1604126537921635908[249] = 0;
   out_1604126537921635908[250] = 0;
   out_1604126537921635908[251] = 0;
   out_1604126537921635908[252] = 0;
   out_1604126537921635908[253] = 0;
   out_1604126537921635908[254] = 0;
   out_1604126537921635908[255] = 0;
   out_1604126537921635908[256] = 0;
   out_1604126537921635908[257] = 0;
   out_1604126537921635908[258] = 0;
   out_1604126537921635908[259] = 0;
   out_1604126537921635908[260] = 0;
   out_1604126537921635908[261] = 0;
   out_1604126537921635908[262] = 0;
   out_1604126537921635908[263] = 0;
   out_1604126537921635908[264] = 0;
   out_1604126537921635908[265] = 0;
   out_1604126537921635908[266] = 1;
   out_1604126537921635908[267] = 0;
   out_1604126537921635908[268] = 0;
   out_1604126537921635908[269] = 0;
   out_1604126537921635908[270] = 0;
   out_1604126537921635908[271] = 0;
   out_1604126537921635908[272] = 0;
   out_1604126537921635908[273] = 0;
   out_1604126537921635908[274] = 0;
   out_1604126537921635908[275] = 0;
   out_1604126537921635908[276] = 0;
   out_1604126537921635908[277] = 0;
   out_1604126537921635908[278] = 0;
   out_1604126537921635908[279] = 0;
   out_1604126537921635908[280] = 0;
   out_1604126537921635908[281] = 0;
   out_1604126537921635908[282] = 0;
   out_1604126537921635908[283] = 0;
   out_1604126537921635908[284] = 0;
   out_1604126537921635908[285] = 1;
   out_1604126537921635908[286] = 0;
   out_1604126537921635908[287] = 0;
   out_1604126537921635908[288] = 0;
   out_1604126537921635908[289] = 0;
   out_1604126537921635908[290] = 0;
   out_1604126537921635908[291] = 0;
   out_1604126537921635908[292] = 0;
   out_1604126537921635908[293] = 0;
   out_1604126537921635908[294] = 0;
   out_1604126537921635908[295] = 0;
   out_1604126537921635908[296] = 0;
   out_1604126537921635908[297] = 0;
   out_1604126537921635908[298] = 0;
   out_1604126537921635908[299] = 0;
   out_1604126537921635908[300] = 0;
   out_1604126537921635908[301] = 0;
   out_1604126537921635908[302] = 0;
   out_1604126537921635908[303] = 0;
   out_1604126537921635908[304] = 1;
   out_1604126537921635908[305] = 0;
   out_1604126537921635908[306] = 0;
   out_1604126537921635908[307] = 0;
   out_1604126537921635908[308] = 0;
   out_1604126537921635908[309] = 0;
   out_1604126537921635908[310] = 0;
   out_1604126537921635908[311] = 0;
   out_1604126537921635908[312] = 0;
   out_1604126537921635908[313] = 0;
   out_1604126537921635908[314] = 0;
   out_1604126537921635908[315] = 0;
   out_1604126537921635908[316] = 0;
   out_1604126537921635908[317] = 0;
   out_1604126537921635908[318] = 0;
   out_1604126537921635908[319] = 0;
   out_1604126537921635908[320] = 0;
   out_1604126537921635908[321] = 0;
   out_1604126537921635908[322] = 0;
   out_1604126537921635908[323] = 1;
}
void h_4(double *state, double *unused, double *out_3074186152133531416) {
   out_3074186152133531416[0] = state[6] + state[9];
   out_3074186152133531416[1] = state[7] + state[10];
   out_3074186152133531416[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_382788571403802989) {
   out_382788571403802989[0] = 0;
   out_382788571403802989[1] = 0;
   out_382788571403802989[2] = 0;
   out_382788571403802989[3] = 0;
   out_382788571403802989[4] = 0;
   out_382788571403802989[5] = 0;
   out_382788571403802989[6] = 1;
   out_382788571403802989[7] = 0;
   out_382788571403802989[8] = 0;
   out_382788571403802989[9] = 1;
   out_382788571403802989[10] = 0;
   out_382788571403802989[11] = 0;
   out_382788571403802989[12] = 0;
   out_382788571403802989[13] = 0;
   out_382788571403802989[14] = 0;
   out_382788571403802989[15] = 0;
   out_382788571403802989[16] = 0;
   out_382788571403802989[17] = 0;
   out_382788571403802989[18] = 0;
   out_382788571403802989[19] = 0;
   out_382788571403802989[20] = 0;
   out_382788571403802989[21] = 0;
   out_382788571403802989[22] = 0;
   out_382788571403802989[23] = 0;
   out_382788571403802989[24] = 0;
   out_382788571403802989[25] = 1;
   out_382788571403802989[26] = 0;
   out_382788571403802989[27] = 0;
   out_382788571403802989[28] = 1;
   out_382788571403802989[29] = 0;
   out_382788571403802989[30] = 0;
   out_382788571403802989[31] = 0;
   out_382788571403802989[32] = 0;
   out_382788571403802989[33] = 0;
   out_382788571403802989[34] = 0;
   out_382788571403802989[35] = 0;
   out_382788571403802989[36] = 0;
   out_382788571403802989[37] = 0;
   out_382788571403802989[38] = 0;
   out_382788571403802989[39] = 0;
   out_382788571403802989[40] = 0;
   out_382788571403802989[41] = 0;
   out_382788571403802989[42] = 0;
   out_382788571403802989[43] = 0;
   out_382788571403802989[44] = 1;
   out_382788571403802989[45] = 0;
   out_382788571403802989[46] = 0;
   out_382788571403802989[47] = 1;
   out_382788571403802989[48] = 0;
   out_382788571403802989[49] = 0;
   out_382788571403802989[50] = 0;
   out_382788571403802989[51] = 0;
   out_382788571403802989[52] = 0;
   out_382788571403802989[53] = 0;
}
void h_10(double *state, double *unused, double *out_3256203287108299981) {
   out_3256203287108299981[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_3256203287108299981[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_3256203287108299981[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4548123818980190037) {
   out_4548123818980190037[0] = 0;
   out_4548123818980190037[1] = 9.8100000000000005*cos(state[1]);
   out_4548123818980190037[2] = 0;
   out_4548123818980190037[3] = 0;
   out_4548123818980190037[4] = -state[8];
   out_4548123818980190037[5] = state[7];
   out_4548123818980190037[6] = 0;
   out_4548123818980190037[7] = state[5];
   out_4548123818980190037[8] = -state[4];
   out_4548123818980190037[9] = 0;
   out_4548123818980190037[10] = 0;
   out_4548123818980190037[11] = 0;
   out_4548123818980190037[12] = 1;
   out_4548123818980190037[13] = 0;
   out_4548123818980190037[14] = 0;
   out_4548123818980190037[15] = 1;
   out_4548123818980190037[16] = 0;
   out_4548123818980190037[17] = 0;
   out_4548123818980190037[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4548123818980190037[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4548123818980190037[20] = 0;
   out_4548123818980190037[21] = state[8];
   out_4548123818980190037[22] = 0;
   out_4548123818980190037[23] = -state[6];
   out_4548123818980190037[24] = -state[5];
   out_4548123818980190037[25] = 0;
   out_4548123818980190037[26] = state[3];
   out_4548123818980190037[27] = 0;
   out_4548123818980190037[28] = 0;
   out_4548123818980190037[29] = 0;
   out_4548123818980190037[30] = 0;
   out_4548123818980190037[31] = 1;
   out_4548123818980190037[32] = 0;
   out_4548123818980190037[33] = 0;
   out_4548123818980190037[34] = 1;
   out_4548123818980190037[35] = 0;
   out_4548123818980190037[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4548123818980190037[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4548123818980190037[38] = 0;
   out_4548123818980190037[39] = -state[7];
   out_4548123818980190037[40] = state[6];
   out_4548123818980190037[41] = 0;
   out_4548123818980190037[42] = state[4];
   out_4548123818980190037[43] = -state[3];
   out_4548123818980190037[44] = 0;
   out_4548123818980190037[45] = 0;
   out_4548123818980190037[46] = 0;
   out_4548123818980190037[47] = 0;
   out_4548123818980190037[48] = 0;
   out_4548123818980190037[49] = 0;
   out_4548123818980190037[50] = 1;
   out_4548123818980190037[51] = 0;
   out_4548123818980190037[52] = 0;
   out_4548123818980190037[53] = 1;
}
void h_13(double *state, double *unused, double *out_8906736968435166145) {
   out_8906736968435166145[0] = state[3];
   out_8906736968435166145[1] = state[4];
   out_8906736968435166145[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2829485253928529812) {
   out_2829485253928529812[0] = 0;
   out_2829485253928529812[1] = 0;
   out_2829485253928529812[2] = 0;
   out_2829485253928529812[3] = 1;
   out_2829485253928529812[4] = 0;
   out_2829485253928529812[5] = 0;
   out_2829485253928529812[6] = 0;
   out_2829485253928529812[7] = 0;
   out_2829485253928529812[8] = 0;
   out_2829485253928529812[9] = 0;
   out_2829485253928529812[10] = 0;
   out_2829485253928529812[11] = 0;
   out_2829485253928529812[12] = 0;
   out_2829485253928529812[13] = 0;
   out_2829485253928529812[14] = 0;
   out_2829485253928529812[15] = 0;
   out_2829485253928529812[16] = 0;
   out_2829485253928529812[17] = 0;
   out_2829485253928529812[18] = 0;
   out_2829485253928529812[19] = 0;
   out_2829485253928529812[20] = 0;
   out_2829485253928529812[21] = 0;
   out_2829485253928529812[22] = 1;
   out_2829485253928529812[23] = 0;
   out_2829485253928529812[24] = 0;
   out_2829485253928529812[25] = 0;
   out_2829485253928529812[26] = 0;
   out_2829485253928529812[27] = 0;
   out_2829485253928529812[28] = 0;
   out_2829485253928529812[29] = 0;
   out_2829485253928529812[30] = 0;
   out_2829485253928529812[31] = 0;
   out_2829485253928529812[32] = 0;
   out_2829485253928529812[33] = 0;
   out_2829485253928529812[34] = 0;
   out_2829485253928529812[35] = 0;
   out_2829485253928529812[36] = 0;
   out_2829485253928529812[37] = 0;
   out_2829485253928529812[38] = 0;
   out_2829485253928529812[39] = 0;
   out_2829485253928529812[40] = 0;
   out_2829485253928529812[41] = 1;
   out_2829485253928529812[42] = 0;
   out_2829485253928529812[43] = 0;
   out_2829485253928529812[44] = 0;
   out_2829485253928529812[45] = 0;
   out_2829485253928529812[46] = 0;
   out_2829485253928529812[47] = 0;
   out_2829485253928529812[48] = 0;
   out_2829485253928529812[49] = 0;
   out_2829485253928529812[50] = 0;
   out_2829485253928529812[51] = 0;
   out_2829485253928529812[52] = 0;
   out_2829485253928529812[53] = 0;
}
void h_14(double *state, double *unused, double *out_6007503255828837104) {
   out_6007503255828837104[0] = state[6];
   out_6007503255828837104[1] = state[7];
   out_6007503255828837104[2] = state[8];
}
void H_14(double *state, double *unused, double *out_3580452284935681540) {
   out_3580452284935681540[0] = 0;
   out_3580452284935681540[1] = 0;
   out_3580452284935681540[2] = 0;
   out_3580452284935681540[3] = 0;
   out_3580452284935681540[4] = 0;
   out_3580452284935681540[5] = 0;
   out_3580452284935681540[6] = 1;
   out_3580452284935681540[7] = 0;
   out_3580452284935681540[8] = 0;
   out_3580452284935681540[9] = 0;
   out_3580452284935681540[10] = 0;
   out_3580452284935681540[11] = 0;
   out_3580452284935681540[12] = 0;
   out_3580452284935681540[13] = 0;
   out_3580452284935681540[14] = 0;
   out_3580452284935681540[15] = 0;
   out_3580452284935681540[16] = 0;
   out_3580452284935681540[17] = 0;
   out_3580452284935681540[18] = 0;
   out_3580452284935681540[19] = 0;
   out_3580452284935681540[20] = 0;
   out_3580452284935681540[21] = 0;
   out_3580452284935681540[22] = 0;
   out_3580452284935681540[23] = 0;
   out_3580452284935681540[24] = 0;
   out_3580452284935681540[25] = 1;
   out_3580452284935681540[26] = 0;
   out_3580452284935681540[27] = 0;
   out_3580452284935681540[28] = 0;
   out_3580452284935681540[29] = 0;
   out_3580452284935681540[30] = 0;
   out_3580452284935681540[31] = 0;
   out_3580452284935681540[32] = 0;
   out_3580452284935681540[33] = 0;
   out_3580452284935681540[34] = 0;
   out_3580452284935681540[35] = 0;
   out_3580452284935681540[36] = 0;
   out_3580452284935681540[37] = 0;
   out_3580452284935681540[38] = 0;
   out_3580452284935681540[39] = 0;
   out_3580452284935681540[40] = 0;
   out_3580452284935681540[41] = 0;
   out_3580452284935681540[42] = 0;
   out_3580452284935681540[43] = 0;
   out_3580452284935681540[44] = 1;
   out_3580452284935681540[45] = 0;
   out_3580452284935681540[46] = 0;
   out_3580452284935681540[47] = 0;
   out_3580452284935681540[48] = 0;
   out_3580452284935681540[49] = 0;
   out_3580452284935681540[50] = 0;
   out_3580452284935681540[51] = 0;
   out_3580452284935681540[52] = 0;
   out_3580452284935681540[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_1541433372370496057) {
  err_fun(nom_x, delta_x, out_1541433372370496057);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8373660040473895336) {
  inv_err_fun(nom_x, true_x, out_8373660040473895336);
}
void pose_H_mod_fun(double *state, double *out_2891433507387146264) {
  H_mod_fun(state, out_2891433507387146264);
}
void pose_f_fun(double *state, double dt, double *out_3325430116042611385) {
  f_fun(state,  dt, out_3325430116042611385);
}
void pose_F_fun(double *state, double dt, double *out_1604126537921635908) {
  F_fun(state,  dt, out_1604126537921635908);
}
void pose_h_4(double *state, double *unused, double *out_3074186152133531416) {
  h_4(state, unused, out_3074186152133531416);
}
void pose_H_4(double *state, double *unused, double *out_382788571403802989) {
  H_4(state, unused, out_382788571403802989);
}
void pose_h_10(double *state, double *unused, double *out_3256203287108299981) {
  h_10(state, unused, out_3256203287108299981);
}
void pose_H_10(double *state, double *unused, double *out_4548123818980190037) {
  H_10(state, unused, out_4548123818980190037);
}
void pose_h_13(double *state, double *unused, double *out_8906736968435166145) {
  h_13(state, unused, out_8906736968435166145);
}
void pose_H_13(double *state, double *unused, double *out_2829485253928529812) {
  H_13(state, unused, out_2829485253928529812);
}
void pose_h_14(double *state, double *unused, double *out_6007503255828837104) {
  h_14(state, unused, out_6007503255828837104);
}
void pose_H_14(double *state, double *unused, double *out_3580452284935681540) {
  H_14(state, unused, out_3580452284935681540);
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
