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
void err_fun(double *nom_x, double *delta_x, double *out_8839413807771918444) {
   out_8839413807771918444[0] = delta_x[0] + nom_x[0];
   out_8839413807771918444[1] = delta_x[1] + nom_x[1];
   out_8839413807771918444[2] = delta_x[2] + nom_x[2];
   out_8839413807771918444[3] = delta_x[3] + nom_x[3];
   out_8839413807771918444[4] = delta_x[4] + nom_x[4];
   out_8839413807771918444[5] = delta_x[5] + nom_x[5];
   out_8839413807771918444[6] = delta_x[6] + nom_x[6];
   out_8839413807771918444[7] = delta_x[7] + nom_x[7];
   out_8839413807771918444[8] = delta_x[8] + nom_x[8];
   out_8839413807771918444[9] = delta_x[9] + nom_x[9];
   out_8839413807771918444[10] = delta_x[10] + nom_x[10];
   out_8839413807771918444[11] = delta_x[11] + nom_x[11];
   out_8839413807771918444[12] = delta_x[12] + nom_x[12];
   out_8839413807771918444[13] = delta_x[13] + nom_x[13];
   out_8839413807771918444[14] = delta_x[14] + nom_x[14];
   out_8839413807771918444[15] = delta_x[15] + nom_x[15];
   out_8839413807771918444[16] = delta_x[16] + nom_x[16];
   out_8839413807771918444[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2623138420433239329) {
   out_2623138420433239329[0] = -nom_x[0] + true_x[0];
   out_2623138420433239329[1] = -nom_x[1] + true_x[1];
   out_2623138420433239329[2] = -nom_x[2] + true_x[2];
   out_2623138420433239329[3] = -nom_x[3] + true_x[3];
   out_2623138420433239329[4] = -nom_x[4] + true_x[4];
   out_2623138420433239329[5] = -nom_x[5] + true_x[5];
   out_2623138420433239329[6] = -nom_x[6] + true_x[6];
   out_2623138420433239329[7] = -nom_x[7] + true_x[7];
   out_2623138420433239329[8] = -nom_x[8] + true_x[8];
   out_2623138420433239329[9] = -nom_x[9] + true_x[9];
   out_2623138420433239329[10] = -nom_x[10] + true_x[10];
   out_2623138420433239329[11] = -nom_x[11] + true_x[11];
   out_2623138420433239329[12] = -nom_x[12] + true_x[12];
   out_2623138420433239329[13] = -nom_x[13] + true_x[13];
   out_2623138420433239329[14] = -nom_x[14] + true_x[14];
   out_2623138420433239329[15] = -nom_x[15] + true_x[15];
   out_2623138420433239329[16] = -nom_x[16] + true_x[16];
   out_2623138420433239329[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_56233860221111886) {
   out_56233860221111886[0] = 1.0;
   out_56233860221111886[1] = 0.0;
   out_56233860221111886[2] = 0.0;
   out_56233860221111886[3] = 0.0;
   out_56233860221111886[4] = 0.0;
   out_56233860221111886[5] = 0.0;
   out_56233860221111886[6] = 0.0;
   out_56233860221111886[7] = 0.0;
   out_56233860221111886[8] = 0.0;
   out_56233860221111886[9] = 0.0;
   out_56233860221111886[10] = 0.0;
   out_56233860221111886[11] = 0.0;
   out_56233860221111886[12] = 0.0;
   out_56233860221111886[13] = 0.0;
   out_56233860221111886[14] = 0.0;
   out_56233860221111886[15] = 0.0;
   out_56233860221111886[16] = 0.0;
   out_56233860221111886[17] = 0.0;
   out_56233860221111886[18] = 0.0;
   out_56233860221111886[19] = 1.0;
   out_56233860221111886[20] = 0.0;
   out_56233860221111886[21] = 0.0;
   out_56233860221111886[22] = 0.0;
   out_56233860221111886[23] = 0.0;
   out_56233860221111886[24] = 0.0;
   out_56233860221111886[25] = 0.0;
   out_56233860221111886[26] = 0.0;
   out_56233860221111886[27] = 0.0;
   out_56233860221111886[28] = 0.0;
   out_56233860221111886[29] = 0.0;
   out_56233860221111886[30] = 0.0;
   out_56233860221111886[31] = 0.0;
   out_56233860221111886[32] = 0.0;
   out_56233860221111886[33] = 0.0;
   out_56233860221111886[34] = 0.0;
   out_56233860221111886[35] = 0.0;
   out_56233860221111886[36] = 0.0;
   out_56233860221111886[37] = 0.0;
   out_56233860221111886[38] = 1.0;
   out_56233860221111886[39] = 0.0;
   out_56233860221111886[40] = 0.0;
   out_56233860221111886[41] = 0.0;
   out_56233860221111886[42] = 0.0;
   out_56233860221111886[43] = 0.0;
   out_56233860221111886[44] = 0.0;
   out_56233860221111886[45] = 0.0;
   out_56233860221111886[46] = 0.0;
   out_56233860221111886[47] = 0.0;
   out_56233860221111886[48] = 0.0;
   out_56233860221111886[49] = 0.0;
   out_56233860221111886[50] = 0.0;
   out_56233860221111886[51] = 0.0;
   out_56233860221111886[52] = 0.0;
   out_56233860221111886[53] = 0.0;
   out_56233860221111886[54] = 0.0;
   out_56233860221111886[55] = 0.0;
   out_56233860221111886[56] = 0.0;
   out_56233860221111886[57] = 1.0;
   out_56233860221111886[58] = 0.0;
   out_56233860221111886[59] = 0.0;
   out_56233860221111886[60] = 0.0;
   out_56233860221111886[61] = 0.0;
   out_56233860221111886[62] = 0.0;
   out_56233860221111886[63] = 0.0;
   out_56233860221111886[64] = 0.0;
   out_56233860221111886[65] = 0.0;
   out_56233860221111886[66] = 0.0;
   out_56233860221111886[67] = 0.0;
   out_56233860221111886[68] = 0.0;
   out_56233860221111886[69] = 0.0;
   out_56233860221111886[70] = 0.0;
   out_56233860221111886[71] = 0.0;
   out_56233860221111886[72] = 0.0;
   out_56233860221111886[73] = 0.0;
   out_56233860221111886[74] = 0.0;
   out_56233860221111886[75] = 0.0;
   out_56233860221111886[76] = 1.0;
   out_56233860221111886[77] = 0.0;
   out_56233860221111886[78] = 0.0;
   out_56233860221111886[79] = 0.0;
   out_56233860221111886[80] = 0.0;
   out_56233860221111886[81] = 0.0;
   out_56233860221111886[82] = 0.0;
   out_56233860221111886[83] = 0.0;
   out_56233860221111886[84] = 0.0;
   out_56233860221111886[85] = 0.0;
   out_56233860221111886[86] = 0.0;
   out_56233860221111886[87] = 0.0;
   out_56233860221111886[88] = 0.0;
   out_56233860221111886[89] = 0.0;
   out_56233860221111886[90] = 0.0;
   out_56233860221111886[91] = 0.0;
   out_56233860221111886[92] = 0.0;
   out_56233860221111886[93] = 0.0;
   out_56233860221111886[94] = 0.0;
   out_56233860221111886[95] = 1.0;
   out_56233860221111886[96] = 0.0;
   out_56233860221111886[97] = 0.0;
   out_56233860221111886[98] = 0.0;
   out_56233860221111886[99] = 0.0;
   out_56233860221111886[100] = 0.0;
   out_56233860221111886[101] = 0.0;
   out_56233860221111886[102] = 0.0;
   out_56233860221111886[103] = 0.0;
   out_56233860221111886[104] = 0.0;
   out_56233860221111886[105] = 0.0;
   out_56233860221111886[106] = 0.0;
   out_56233860221111886[107] = 0.0;
   out_56233860221111886[108] = 0.0;
   out_56233860221111886[109] = 0.0;
   out_56233860221111886[110] = 0.0;
   out_56233860221111886[111] = 0.0;
   out_56233860221111886[112] = 0.0;
   out_56233860221111886[113] = 0.0;
   out_56233860221111886[114] = 1.0;
   out_56233860221111886[115] = 0.0;
   out_56233860221111886[116] = 0.0;
   out_56233860221111886[117] = 0.0;
   out_56233860221111886[118] = 0.0;
   out_56233860221111886[119] = 0.0;
   out_56233860221111886[120] = 0.0;
   out_56233860221111886[121] = 0.0;
   out_56233860221111886[122] = 0.0;
   out_56233860221111886[123] = 0.0;
   out_56233860221111886[124] = 0.0;
   out_56233860221111886[125] = 0.0;
   out_56233860221111886[126] = 0.0;
   out_56233860221111886[127] = 0.0;
   out_56233860221111886[128] = 0.0;
   out_56233860221111886[129] = 0.0;
   out_56233860221111886[130] = 0.0;
   out_56233860221111886[131] = 0.0;
   out_56233860221111886[132] = 0.0;
   out_56233860221111886[133] = 1.0;
   out_56233860221111886[134] = 0.0;
   out_56233860221111886[135] = 0.0;
   out_56233860221111886[136] = 0.0;
   out_56233860221111886[137] = 0.0;
   out_56233860221111886[138] = 0.0;
   out_56233860221111886[139] = 0.0;
   out_56233860221111886[140] = 0.0;
   out_56233860221111886[141] = 0.0;
   out_56233860221111886[142] = 0.0;
   out_56233860221111886[143] = 0.0;
   out_56233860221111886[144] = 0.0;
   out_56233860221111886[145] = 0.0;
   out_56233860221111886[146] = 0.0;
   out_56233860221111886[147] = 0.0;
   out_56233860221111886[148] = 0.0;
   out_56233860221111886[149] = 0.0;
   out_56233860221111886[150] = 0.0;
   out_56233860221111886[151] = 0.0;
   out_56233860221111886[152] = 1.0;
   out_56233860221111886[153] = 0.0;
   out_56233860221111886[154] = 0.0;
   out_56233860221111886[155] = 0.0;
   out_56233860221111886[156] = 0.0;
   out_56233860221111886[157] = 0.0;
   out_56233860221111886[158] = 0.0;
   out_56233860221111886[159] = 0.0;
   out_56233860221111886[160] = 0.0;
   out_56233860221111886[161] = 0.0;
   out_56233860221111886[162] = 0.0;
   out_56233860221111886[163] = 0.0;
   out_56233860221111886[164] = 0.0;
   out_56233860221111886[165] = 0.0;
   out_56233860221111886[166] = 0.0;
   out_56233860221111886[167] = 0.0;
   out_56233860221111886[168] = 0.0;
   out_56233860221111886[169] = 0.0;
   out_56233860221111886[170] = 0.0;
   out_56233860221111886[171] = 1.0;
   out_56233860221111886[172] = 0.0;
   out_56233860221111886[173] = 0.0;
   out_56233860221111886[174] = 0.0;
   out_56233860221111886[175] = 0.0;
   out_56233860221111886[176] = 0.0;
   out_56233860221111886[177] = 0.0;
   out_56233860221111886[178] = 0.0;
   out_56233860221111886[179] = 0.0;
   out_56233860221111886[180] = 0.0;
   out_56233860221111886[181] = 0.0;
   out_56233860221111886[182] = 0.0;
   out_56233860221111886[183] = 0.0;
   out_56233860221111886[184] = 0.0;
   out_56233860221111886[185] = 0.0;
   out_56233860221111886[186] = 0.0;
   out_56233860221111886[187] = 0.0;
   out_56233860221111886[188] = 0.0;
   out_56233860221111886[189] = 0.0;
   out_56233860221111886[190] = 1.0;
   out_56233860221111886[191] = 0.0;
   out_56233860221111886[192] = 0.0;
   out_56233860221111886[193] = 0.0;
   out_56233860221111886[194] = 0.0;
   out_56233860221111886[195] = 0.0;
   out_56233860221111886[196] = 0.0;
   out_56233860221111886[197] = 0.0;
   out_56233860221111886[198] = 0.0;
   out_56233860221111886[199] = 0.0;
   out_56233860221111886[200] = 0.0;
   out_56233860221111886[201] = 0.0;
   out_56233860221111886[202] = 0.0;
   out_56233860221111886[203] = 0.0;
   out_56233860221111886[204] = 0.0;
   out_56233860221111886[205] = 0.0;
   out_56233860221111886[206] = 0.0;
   out_56233860221111886[207] = 0.0;
   out_56233860221111886[208] = 0.0;
   out_56233860221111886[209] = 1.0;
   out_56233860221111886[210] = 0.0;
   out_56233860221111886[211] = 0.0;
   out_56233860221111886[212] = 0.0;
   out_56233860221111886[213] = 0.0;
   out_56233860221111886[214] = 0.0;
   out_56233860221111886[215] = 0.0;
   out_56233860221111886[216] = 0.0;
   out_56233860221111886[217] = 0.0;
   out_56233860221111886[218] = 0.0;
   out_56233860221111886[219] = 0.0;
   out_56233860221111886[220] = 0.0;
   out_56233860221111886[221] = 0.0;
   out_56233860221111886[222] = 0.0;
   out_56233860221111886[223] = 0.0;
   out_56233860221111886[224] = 0.0;
   out_56233860221111886[225] = 0.0;
   out_56233860221111886[226] = 0.0;
   out_56233860221111886[227] = 0.0;
   out_56233860221111886[228] = 1.0;
   out_56233860221111886[229] = 0.0;
   out_56233860221111886[230] = 0.0;
   out_56233860221111886[231] = 0.0;
   out_56233860221111886[232] = 0.0;
   out_56233860221111886[233] = 0.0;
   out_56233860221111886[234] = 0.0;
   out_56233860221111886[235] = 0.0;
   out_56233860221111886[236] = 0.0;
   out_56233860221111886[237] = 0.0;
   out_56233860221111886[238] = 0.0;
   out_56233860221111886[239] = 0.0;
   out_56233860221111886[240] = 0.0;
   out_56233860221111886[241] = 0.0;
   out_56233860221111886[242] = 0.0;
   out_56233860221111886[243] = 0.0;
   out_56233860221111886[244] = 0.0;
   out_56233860221111886[245] = 0.0;
   out_56233860221111886[246] = 0.0;
   out_56233860221111886[247] = 1.0;
   out_56233860221111886[248] = 0.0;
   out_56233860221111886[249] = 0.0;
   out_56233860221111886[250] = 0.0;
   out_56233860221111886[251] = 0.0;
   out_56233860221111886[252] = 0.0;
   out_56233860221111886[253] = 0.0;
   out_56233860221111886[254] = 0.0;
   out_56233860221111886[255] = 0.0;
   out_56233860221111886[256] = 0.0;
   out_56233860221111886[257] = 0.0;
   out_56233860221111886[258] = 0.0;
   out_56233860221111886[259] = 0.0;
   out_56233860221111886[260] = 0.0;
   out_56233860221111886[261] = 0.0;
   out_56233860221111886[262] = 0.0;
   out_56233860221111886[263] = 0.0;
   out_56233860221111886[264] = 0.0;
   out_56233860221111886[265] = 0.0;
   out_56233860221111886[266] = 1.0;
   out_56233860221111886[267] = 0.0;
   out_56233860221111886[268] = 0.0;
   out_56233860221111886[269] = 0.0;
   out_56233860221111886[270] = 0.0;
   out_56233860221111886[271] = 0.0;
   out_56233860221111886[272] = 0.0;
   out_56233860221111886[273] = 0.0;
   out_56233860221111886[274] = 0.0;
   out_56233860221111886[275] = 0.0;
   out_56233860221111886[276] = 0.0;
   out_56233860221111886[277] = 0.0;
   out_56233860221111886[278] = 0.0;
   out_56233860221111886[279] = 0.0;
   out_56233860221111886[280] = 0.0;
   out_56233860221111886[281] = 0.0;
   out_56233860221111886[282] = 0.0;
   out_56233860221111886[283] = 0.0;
   out_56233860221111886[284] = 0.0;
   out_56233860221111886[285] = 1.0;
   out_56233860221111886[286] = 0.0;
   out_56233860221111886[287] = 0.0;
   out_56233860221111886[288] = 0.0;
   out_56233860221111886[289] = 0.0;
   out_56233860221111886[290] = 0.0;
   out_56233860221111886[291] = 0.0;
   out_56233860221111886[292] = 0.0;
   out_56233860221111886[293] = 0.0;
   out_56233860221111886[294] = 0.0;
   out_56233860221111886[295] = 0.0;
   out_56233860221111886[296] = 0.0;
   out_56233860221111886[297] = 0.0;
   out_56233860221111886[298] = 0.0;
   out_56233860221111886[299] = 0.0;
   out_56233860221111886[300] = 0.0;
   out_56233860221111886[301] = 0.0;
   out_56233860221111886[302] = 0.0;
   out_56233860221111886[303] = 0.0;
   out_56233860221111886[304] = 1.0;
   out_56233860221111886[305] = 0.0;
   out_56233860221111886[306] = 0.0;
   out_56233860221111886[307] = 0.0;
   out_56233860221111886[308] = 0.0;
   out_56233860221111886[309] = 0.0;
   out_56233860221111886[310] = 0.0;
   out_56233860221111886[311] = 0.0;
   out_56233860221111886[312] = 0.0;
   out_56233860221111886[313] = 0.0;
   out_56233860221111886[314] = 0.0;
   out_56233860221111886[315] = 0.0;
   out_56233860221111886[316] = 0.0;
   out_56233860221111886[317] = 0.0;
   out_56233860221111886[318] = 0.0;
   out_56233860221111886[319] = 0.0;
   out_56233860221111886[320] = 0.0;
   out_56233860221111886[321] = 0.0;
   out_56233860221111886[322] = 0.0;
   out_56233860221111886[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_9100409772207968194) {
   out_9100409772207968194[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_9100409772207968194[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_9100409772207968194[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_9100409772207968194[3] = dt*state[12] + state[3];
   out_9100409772207968194[4] = dt*state[13] + state[4];
   out_9100409772207968194[5] = dt*state[14] + state[5];
   out_9100409772207968194[6] = state[6];
   out_9100409772207968194[7] = state[7];
   out_9100409772207968194[8] = state[8];
   out_9100409772207968194[9] = state[9];
   out_9100409772207968194[10] = state[10];
   out_9100409772207968194[11] = state[11];
   out_9100409772207968194[12] = state[12];
   out_9100409772207968194[13] = state[13];
   out_9100409772207968194[14] = state[14];
   out_9100409772207968194[15] = state[15];
   out_9100409772207968194[16] = state[16];
   out_9100409772207968194[17] = state[17];
}
void F_fun(double *state, double dt, double *out_2832904802220701503) {
   out_2832904802220701503[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2832904802220701503[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2832904802220701503[2] = 0;
   out_2832904802220701503[3] = 0;
   out_2832904802220701503[4] = 0;
   out_2832904802220701503[5] = 0;
   out_2832904802220701503[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2832904802220701503[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2832904802220701503[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_2832904802220701503[9] = 0;
   out_2832904802220701503[10] = 0;
   out_2832904802220701503[11] = 0;
   out_2832904802220701503[12] = 0;
   out_2832904802220701503[13] = 0;
   out_2832904802220701503[14] = 0;
   out_2832904802220701503[15] = 0;
   out_2832904802220701503[16] = 0;
   out_2832904802220701503[17] = 0;
   out_2832904802220701503[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2832904802220701503[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2832904802220701503[20] = 0;
   out_2832904802220701503[21] = 0;
   out_2832904802220701503[22] = 0;
   out_2832904802220701503[23] = 0;
   out_2832904802220701503[24] = 0;
   out_2832904802220701503[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2832904802220701503[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_2832904802220701503[27] = 0;
   out_2832904802220701503[28] = 0;
   out_2832904802220701503[29] = 0;
   out_2832904802220701503[30] = 0;
   out_2832904802220701503[31] = 0;
   out_2832904802220701503[32] = 0;
   out_2832904802220701503[33] = 0;
   out_2832904802220701503[34] = 0;
   out_2832904802220701503[35] = 0;
   out_2832904802220701503[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2832904802220701503[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2832904802220701503[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2832904802220701503[39] = 0;
   out_2832904802220701503[40] = 0;
   out_2832904802220701503[41] = 0;
   out_2832904802220701503[42] = 0;
   out_2832904802220701503[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2832904802220701503[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_2832904802220701503[45] = 0;
   out_2832904802220701503[46] = 0;
   out_2832904802220701503[47] = 0;
   out_2832904802220701503[48] = 0;
   out_2832904802220701503[49] = 0;
   out_2832904802220701503[50] = 0;
   out_2832904802220701503[51] = 0;
   out_2832904802220701503[52] = 0;
   out_2832904802220701503[53] = 0;
   out_2832904802220701503[54] = 0;
   out_2832904802220701503[55] = 0;
   out_2832904802220701503[56] = 0;
   out_2832904802220701503[57] = 1;
   out_2832904802220701503[58] = 0;
   out_2832904802220701503[59] = 0;
   out_2832904802220701503[60] = 0;
   out_2832904802220701503[61] = 0;
   out_2832904802220701503[62] = 0;
   out_2832904802220701503[63] = 0;
   out_2832904802220701503[64] = 0;
   out_2832904802220701503[65] = 0;
   out_2832904802220701503[66] = dt;
   out_2832904802220701503[67] = 0;
   out_2832904802220701503[68] = 0;
   out_2832904802220701503[69] = 0;
   out_2832904802220701503[70] = 0;
   out_2832904802220701503[71] = 0;
   out_2832904802220701503[72] = 0;
   out_2832904802220701503[73] = 0;
   out_2832904802220701503[74] = 0;
   out_2832904802220701503[75] = 0;
   out_2832904802220701503[76] = 1;
   out_2832904802220701503[77] = 0;
   out_2832904802220701503[78] = 0;
   out_2832904802220701503[79] = 0;
   out_2832904802220701503[80] = 0;
   out_2832904802220701503[81] = 0;
   out_2832904802220701503[82] = 0;
   out_2832904802220701503[83] = 0;
   out_2832904802220701503[84] = 0;
   out_2832904802220701503[85] = dt;
   out_2832904802220701503[86] = 0;
   out_2832904802220701503[87] = 0;
   out_2832904802220701503[88] = 0;
   out_2832904802220701503[89] = 0;
   out_2832904802220701503[90] = 0;
   out_2832904802220701503[91] = 0;
   out_2832904802220701503[92] = 0;
   out_2832904802220701503[93] = 0;
   out_2832904802220701503[94] = 0;
   out_2832904802220701503[95] = 1;
   out_2832904802220701503[96] = 0;
   out_2832904802220701503[97] = 0;
   out_2832904802220701503[98] = 0;
   out_2832904802220701503[99] = 0;
   out_2832904802220701503[100] = 0;
   out_2832904802220701503[101] = 0;
   out_2832904802220701503[102] = 0;
   out_2832904802220701503[103] = 0;
   out_2832904802220701503[104] = dt;
   out_2832904802220701503[105] = 0;
   out_2832904802220701503[106] = 0;
   out_2832904802220701503[107] = 0;
   out_2832904802220701503[108] = 0;
   out_2832904802220701503[109] = 0;
   out_2832904802220701503[110] = 0;
   out_2832904802220701503[111] = 0;
   out_2832904802220701503[112] = 0;
   out_2832904802220701503[113] = 0;
   out_2832904802220701503[114] = 1;
   out_2832904802220701503[115] = 0;
   out_2832904802220701503[116] = 0;
   out_2832904802220701503[117] = 0;
   out_2832904802220701503[118] = 0;
   out_2832904802220701503[119] = 0;
   out_2832904802220701503[120] = 0;
   out_2832904802220701503[121] = 0;
   out_2832904802220701503[122] = 0;
   out_2832904802220701503[123] = 0;
   out_2832904802220701503[124] = 0;
   out_2832904802220701503[125] = 0;
   out_2832904802220701503[126] = 0;
   out_2832904802220701503[127] = 0;
   out_2832904802220701503[128] = 0;
   out_2832904802220701503[129] = 0;
   out_2832904802220701503[130] = 0;
   out_2832904802220701503[131] = 0;
   out_2832904802220701503[132] = 0;
   out_2832904802220701503[133] = 1;
   out_2832904802220701503[134] = 0;
   out_2832904802220701503[135] = 0;
   out_2832904802220701503[136] = 0;
   out_2832904802220701503[137] = 0;
   out_2832904802220701503[138] = 0;
   out_2832904802220701503[139] = 0;
   out_2832904802220701503[140] = 0;
   out_2832904802220701503[141] = 0;
   out_2832904802220701503[142] = 0;
   out_2832904802220701503[143] = 0;
   out_2832904802220701503[144] = 0;
   out_2832904802220701503[145] = 0;
   out_2832904802220701503[146] = 0;
   out_2832904802220701503[147] = 0;
   out_2832904802220701503[148] = 0;
   out_2832904802220701503[149] = 0;
   out_2832904802220701503[150] = 0;
   out_2832904802220701503[151] = 0;
   out_2832904802220701503[152] = 1;
   out_2832904802220701503[153] = 0;
   out_2832904802220701503[154] = 0;
   out_2832904802220701503[155] = 0;
   out_2832904802220701503[156] = 0;
   out_2832904802220701503[157] = 0;
   out_2832904802220701503[158] = 0;
   out_2832904802220701503[159] = 0;
   out_2832904802220701503[160] = 0;
   out_2832904802220701503[161] = 0;
   out_2832904802220701503[162] = 0;
   out_2832904802220701503[163] = 0;
   out_2832904802220701503[164] = 0;
   out_2832904802220701503[165] = 0;
   out_2832904802220701503[166] = 0;
   out_2832904802220701503[167] = 0;
   out_2832904802220701503[168] = 0;
   out_2832904802220701503[169] = 0;
   out_2832904802220701503[170] = 0;
   out_2832904802220701503[171] = 1;
   out_2832904802220701503[172] = 0;
   out_2832904802220701503[173] = 0;
   out_2832904802220701503[174] = 0;
   out_2832904802220701503[175] = 0;
   out_2832904802220701503[176] = 0;
   out_2832904802220701503[177] = 0;
   out_2832904802220701503[178] = 0;
   out_2832904802220701503[179] = 0;
   out_2832904802220701503[180] = 0;
   out_2832904802220701503[181] = 0;
   out_2832904802220701503[182] = 0;
   out_2832904802220701503[183] = 0;
   out_2832904802220701503[184] = 0;
   out_2832904802220701503[185] = 0;
   out_2832904802220701503[186] = 0;
   out_2832904802220701503[187] = 0;
   out_2832904802220701503[188] = 0;
   out_2832904802220701503[189] = 0;
   out_2832904802220701503[190] = 1;
   out_2832904802220701503[191] = 0;
   out_2832904802220701503[192] = 0;
   out_2832904802220701503[193] = 0;
   out_2832904802220701503[194] = 0;
   out_2832904802220701503[195] = 0;
   out_2832904802220701503[196] = 0;
   out_2832904802220701503[197] = 0;
   out_2832904802220701503[198] = 0;
   out_2832904802220701503[199] = 0;
   out_2832904802220701503[200] = 0;
   out_2832904802220701503[201] = 0;
   out_2832904802220701503[202] = 0;
   out_2832904802220701503[203] = 0;
   out_2832904802220701503[204] = 0;
   out_2832904802220701503[205] = 0;
   out_2832904802220701503[206] = 0;
   out_2832904802220701503[207] = 0;
   out_2832904802220701503[208] = 0;
   out_2832904802220701503[209] = 1;
   out_2832904802220701503[210] = 0;
   out_2832904802220701503[211] = 0;
   out_2832904802220701503[212] = 0;
   out_2832904802220701503[213] = 0;
   out_2832904802220701503[214] = 0;
   out_2832904802220701503[215] = 0;
   out_2832904802220701503[216] = 0;
   out_2832904802220701503[217] = 0;
   out_2832904802220701503[218] = 0;
   out_2832904802220701503[219] = 0;
   out_2832904802220701503[220] = 0;
   out_2832904802220701503[221] = 0;
   out_2832904802220701503[222] = 0;
   out_2832904802220701503[223] = 0;
   out_2832904802220701503[224] = 0;
   out_2832904802220701503[225] = 0;
   out_2832904802220701503[226] = 0;
   out_2832904802220701503[227] = 0;
   out_2832904802220701503[228] = 1;
   out_2832904802220701503[229] = 0;
   out_2832904802220701503[230] = 0;
   out_2832904802220701503[231] = 0;
   out_2832904802220701503[232] = 0;
   out_2832904802220701503[233] = 0;
   out_2832904802220701503[234] = 0;
   out_2832904802220701503[235] = 0;
   out_2832904802220701503[236] = 0;
   out_2832904802220701503[237] = 0;
   out_2832904802220701503[238] = 0;
   out_2832904802220701503[239] = 0;
   out_2832904802220701503[240] = 0;
   out_2832904802220701503[241] = 0;
   out_2832904802220701503[242] = 0;
   out_2832904802220701503[243] = 0;
   out_2832904802220701503[244] = 0;
   out_2832904802220701503[245] = 0;
   out_2832904802220701503[246] = 0;
   out_2832904802220701503[247] = 1;
   out_2832904802220701503[248] = 0;
   out_2832904802220701503[249] = 0;
   out_2832904802220701503[250] = 0;
   out_2832904802220701503[251] = 0;
   out_2832904802220701503[252] = 0;
   out_2832904802220701503[253] = 0;
   out_2832904802220701503[254] = 0;
   out_2832904802220701503[255] = 0;
   out_2832904802220701503[256] = 0;
   out_2832904802220701503[257] = 0;
   out_2832904802220701503[258] = 0;
   out_2832904802220701503[259] = 0;
   out_2832904802220701503[260] = 0;
   out_2832904802220701503[261] = 0;
   out_2832904802220701503[262] = 0;
   out_2832904802220701503[263] = 0;
   out_2832904802220701503[264] = 0;
   out_2832904802220701503[265] = 0;
   out_2832904802220701503[266] = 1;
   out_2832904802220701503[267] = 0;
   out_2832904802220701503[268] = 0;
   out_2832904802220701503[269] = 0;
   out_2832904802220701503[270] = 0;
   out_2832904802220701503[271] = 0;
   out_2832904802220701503[272] = 0;
   out_2832904802220701503[273] = 0;
   out_2832904802220701503[274] = 0;
   out_2832904802220701503[275] = 0;
   out_2832904802220701503[276] = 0;
   out_2832904802220701503[277] = 0;
   out_2832904802220701503[278] = 0;
   out_2832904802220701503[279] = 0;
   out_2832904802220701503[280] = 0;
   out_2832904802220701503[281] = 0;
   out_2832904802220701503[282] = 0;
   out_2832904802220701503[283] = 0;
   out_2832904802220701503[284] = 0;
   out_2832904802220701503[285] = 1;
   out_2832904802220701503[286] = 0;
   out_2832904802220701503[287] = 0;
   out_2832904802220701503[288] = 0;
   out_2832904802220701503[289] = 0;
   out_2832904802220701503[290] = 0;
   out_2832904802220701503[291] = 0;
   out_2832904802220701503[292] = 0;
   out_2832904802220701503[293] = 0;
   out_2832904802220701503[294] = 0;
   out_2832904802220701503[295] = 0;
   out_2832904802220701503[296] = 0;
   out_2832904802220701503[297] = 0;
   out_2832904802220701503[298] = 0;
   out_2832904802220701503[299] = 0;
   out_2832904802220701503[300] = 0;
   out_2832904802220701503[301] = 0;
   out_2832904802220701503[302] = 0;
   out_2832904802220701503[303] = 0;
   out_2832904802220701503[304] = 1;
   out_2832904802220701503[305] = 0;
   out_2832904802220701503[306] = 0;
   out_2832904802220701503[307] = 0;
   out_2832904802220701503[308] = 0;
   out_2832904802220701503[309] = 0;
   out_2832904802220701503[310] = 0;
   out_2832904802220701503[311] = 0;
   out_2832904802220701503[312] = 0;
   out_2832904802220701503[313] = 0;
   out_2832904802220701503[314] = 0;
   out_2832904802220701503[315] = 0;
   out_2832904802220701503[316] = 0;
   out_2832904802220701503[317] = 0;
   out_2832904802220701503[318] = 0;
   out_2832904802220701503[319] = 0;
   out_2832904802220701503[320] = 0;
   out_2832904802220701503[321] = 0;
   out_2832904802220701503[322] = 0;
   out_2832904802220701503[323] = 1;
}
void h_4(double *state, double *unused, double *out_1541878422273639399) {
   out_1541878422273639399[0] = state[6] + state[9];
   out_1541878422273639399[1] = state[7] + state[10];
   out_1541878422273639399[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3217988218569837367) {
   out_3217988218569837367[0] = 0;
   out_3217988218569837367[1] = 0;
   out_3217988218569837367[2] = 0;
   out_3217988218569837367[3] = 0;
   out_3217988218569837367[4] = 0;
   out_3217988218569837367[5] = 0;
   out_3217988218569837367[6] = 1;
   out_3217988218569837367[7] = 0;
   out_3217988218569837367[8] = 0;
   out_3217988218569837367[9] = 1;
   out_3217988218569837367[10] = 0;
   out_3217988218569837367[11] = 0;
   out_3217988218569837367[12] = 0;
   out_3217988218569837367[13] = 0;
   out_3217988218569837367[14] = 0;
   out_3217988218569837367[15] = 0;
   out_3217988218569837367[16] = 0;
   out_3217988218569837367[17] = 0;
   out_3217988218569837367[18] = 0;
   out_3217988218569837367[19] = 0;
   out_3217988218569837367[20] = 0;
   out_3217988218569837367[21] = 0;
   out_3217988218569837367[22] = 0;
   out_3217988218569837367[23] = 0;
   out_3217988218569837367[24] = 0;
   out_3217988218569837367[25] = 1;
   out_3217988218569837367[26] = 0;
   out_3217988218569837367[27] = 0;
   out_3217988218569837367[28] = 1;
   out_3217988218569837367[29] = 0;
   out_3217988218569837367[30] = 0;
   out_3217988218569837367[31] = 0;
   out_3217988218569837367[32] = 0;
   out_3217988218569837367[33] = 0;
   out_3217988218569837367[34] = 0;
   out_3217988218569837367[35] = 0;
   out_3217988218569837367[36] = 0;
   out_3217988218569837367[37] = 0;
   out_3217988218569837367[38] = 0;
   out_3217988218569837367[39] = 0;
   out_3217988218569837367[40] = 0;
   out_3217988218569837367[41] = 0;
   out_3217988218569837367[42] = 0;
   out_3217988218569837367[43] = 0;
   out_3217988218569837367[44] = 1;
   out_3217988218569837367[45] = 0;
   out_3217988218569837367[46] = 0;
   out_3217988218569837367[47] = 1;
   out_3217988218569837367[48] = 0;
   out_3217988218569837367[49] = 0;
   out_3217988218569837367[50] = 0;
   out_3217988218569837367[51] = 0;
   out_3217988218569837367[52] = 0;
   out_3217988218569837367[53] = 0;
}
void h_10(double *state, double *unused, double *out_4286388877957954392) {
   out_4286388877957954392[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4286388877957954392[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4286388877957954392[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_387235683895473982) {
   out_387235683895473982[0] = 0;
   out_387235683895473982[1] = 9.8100000000000005*cos(state[1]);
   out_387235683895473982[2] = 0;
   out_387235683895473982[3] = 0;
   out_387235683895473982[4] = -state[8];
   out_387235683895473982[5] = state[7];
   out_387235683895473982[6] = 0;
   out_387235683895473982[7] = state[5];
   out_387235683895473982[8] = -state[4];
   out_387235683895473982[9] = 0;
   out_387235683895473982[10] = 0;
   out_387235683895473982[11] = 0;
   out_387235683895473982[12] = 1;
   out_387235683895473982[13] = 0;
   out_387235683895473982[14] = 0;
   out_387235683895473982[15] = 1;
   out_387235683895473982[16] = 0;
   out_387235683895473982[17] = 0;
   out_387235683895473982[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_387235683895473982[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_387235683895473982[20] = 0;
   out_387235683895473982[21] = state[8];
   out_387235683895473982[22] = 0;
   out_387235683895473982[23] = -state[6];
   out_387235683895473982[24] = -state[5];
   out_387235683895473982[25] = 0;
   out_387235683895473982[26] = state[3];
   out_387235683895473982[27] = 0;
   out_387235683895473982[28] = 0;
   out_387235683895473982[29] = 0;
   out_387235683895473982[30] = 0;
   out_387235683895473982[31] = 1;
   out_387235683895473982[32] = 0;
   out_387235683895473982[33] = 0;
   out_387235683895473982[34] = 1;
   out_387235683895473982[35] = 0;
   out_387235683895473982[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_387235683895473982[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_387235683895473982[38] = 0;
   out_387235683895473982[39] = -state[7];
   out_387235683895473982[40] = state[6];
   out_387235683895473982[41] = 0;
   out_387235683895473982[42] = state[4];
   out_387235683895473982[43] = -state[3];
   out_387235683895473982[44] = 0;
   out_387235683895473982[45] = 0;
   out_387235683895473982[46] = 0;
   out_387235683895473982[47] = 0;
   out_387235683895473982[48] = 0;
   out_387235683895473982[49] = 0;
   out_387235683895473982[50] = 1;
   out_387235683895473982[51] = 0;
   out_387235683895473982[52] = 0;
   out_387235683895473982[53] = 1;
}
void h_13(double *state, double *unused, double *out_771705969490129500) {
   out_771705969490129500[0] = state[3];
   out_771705969490129500[1] = state[4];
   out_771705969490129500[2] = state[5];
}
void H_13(double *state, double *unused, double *out_5714393237504566) {
   out_5714393237504566[0] = 0;
   out_5714393237504566[1] = 0;
   out_5714393237504566[2] = 0;
   out_5714393237504566[3] = 1;
   out_5714393237504566[4] = 0;
   out_5714393237504566[5] = 0;
   out_5714393237504566[6] = 0;
   out_5714393237504566[7] = 0;
   out_5714393237504566[8] = 0;
   out_5714393237504566[9] = 0;
   out_5714393237504566[10] = 0;
   out_5714393237504566[11] = 0;
   out_5714393237504566[12] = 0;
   out_5714393237504566[13] = 0;
   out_5714393237504566[14] = 0;
   out_5714393237504566[15] = 0;
   out_5714393237504566[16] = 0;
   out_5714393237504566[17] = 0;
   out_5714393237504566[18] = 0;
   out_5714393237504566[19] = 0;
   out_5714393237504566[20] = 0;
   out_5714393237504566[21] = 0;
   out_5714393237504566[22] = 1;
   out_5714393237504566[23] = 0;
   out_5714393237504566[24] = 0;
   out_5714393237504566[25] = 0;
   out_5714393237504566[26] = 0;
   out_5714393237504566[27] = 0;
   out_5714393237504566[28] = 0;
   out_5714393237504566[29] = 0;
   out_5714393237504566[30] = 0;
   out_5714393237504566[31] = 0;
   out_5714393237504566[32] = 0;
   out_5714393237504566[33] = 0;
   out_5714393237504566[34] = 0;
   out_5714393237504566[35] = 0;
   out_5714393237504566[36] = 0;
   out_5714393237504566[37] = 0;
   out_5714393237504566[38] = 0;
   out_5714393237504566[39] = 0;
   out_5714393237504566[40] = 0;
   out_5714393237504566[41] = 1;
   out_5714393237504566[42] = 0;
   out_5714393237504566[43] = 0;
   out_5714393237504566[44] = 0;
   out_5714393237504566[45] = 0;
   out_5714393237504566[46] = 0;
   out_5714393237504566[47] = 0;
   out_5714393237504566[48] = 0;
   out_5714393237504566[49] = 0;
   out_5714393237504566[50] = 0;
   out_5714393237504566[51] = 0;
   out_5714393237504566[52] = 0;
   out_5714393237504566[53] = 0;
}
void h_14(double *state, double *unused, double *out_3822203570969529950) {
   out_3822203570969529950[0] = state[6];
   out_3822203570969529950[1] = state[7];
   out_3822203570969529950[2] = state[8];
}
void H_14(double *state, double *unused, double *out_745252637769647162) {
   out_745252637769647162[0] = 0;
   out_745252637769647162[1] = 0;
   out_745252637769647162[2] = 0;
   out_745252637769647162[3] = 0;
   out_745252637769647162[4] = 0;
   out_745252637769647162[5] = 0;
   out_745252637769647162[6] = 1;
   out_745252637769647162[7] = 0;
   out_745252637769647162[8] = 0;
   out_745252637769647162[9] = 0;
   out_745252637769647162[10] = 0;
   out_745252637769647162[11] = 0;
   out_745252637769647162[12] = 0;
   out_745252637769647162[13] = 0;
   out_745252637769647162[14] = 0;
   out_745252637769647162[15] = 0;
   out_745252637769647162[16] = 0;
   out_745252637769647162[17] = 0;
   out_745252637769647162[18] = 0;
   out_745252637769647162[19] = 0;
   out_745252637769647162[20] = 0;
   out_745252637769647162[21] = 0;
   out_745252637769647162[22] = 0;
   out_745252637769647162[23] = 0;
   out_745252637769647162[24] = 0;
   out_745252637769647162[25] = 1;
   out_745252637769647162[26] = 0;
   out_745252637769647162[27] = 0;
   out_745252637769647162[28] = 0;
   out_745252637769647162[29] = 0;
   out_745252637769647162[30] = 0;
   out_745252637769647162[31] = 0;
   out_745252637769647162[32] = 0;
   out_745252637769647162[33] = 0;
   out_745252637769647162[34] = 0;
   out_745252637769647162[35] = 0;
   out_745252637769647162[36] = 0;
   out_745252637769647162[37] = 0;
   out_745252637769647162[38] = 0;
   out_745252637769647162[39] = 0;
   out_745252637769647162[40] = 0;
   out_745252637769647162[41] = 0;
   out_745252637769647162[42] = 0;
   out_745252637769647162[43] = 0;
   out_745252637769647162[44] = 1;
   out_745252637769647162[45] = 0;
   out_745252637769647162[46] = 0;
   out_745252637769647162[47] = 0;
   out_745252637769647162[48] = 0;
   out_745252637769647162[49] = 0;
   out_745252637769647162[50] = 0;
   out_745252637769647162[51] = 0;
   out_745252637769647162[52] = 0;
   out_745252637769647162[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_8839413807771918444) {
  err_fun(nom_x, delta_x, out_8839413807771918444);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2623138420433239329) {
  inv_err_fun(nom_x, true_x, out_2623138420433239329);
}
void pose_H_mod_fun(double *state, double *out_56233860221111886) {
  H_mod_fun(state, out_56233860221111886);
}
void pose_f_fun(double *state, double dt, double *out_9100409772207968194) {
  f_fun(state,  dt, out_9100409772207968194);
}
void pose_F_fun(double *state, double dt, double *out_2832904802220701503) {
  F_fun(state,  dt, out_2832904802220701503);
}
void pose_h_4(double *state, double *unused, double *out_1541878422273639399) {
  h_4(state, unused, out_1541878422273639399);
}
void pose_H_4(double *state, double *unused, double *out_3217988218569837367) {
  H_4(state, unused, out_3217988218569837367);
}
void pose_h_10(double *state, double *unused, double *out_4286388877957954392) {
  h_10(state, unused, out_4286388877957954392);
}
void pose_H_10(double *state, double *unused, double *out_387235683895473982) {
  H_10(state, unused, out_387235683895473982);
}
void pose_h_13(double *state, double *unused, double *out_771705969490129500) {
  h_13(state, unused, out_771705969490129500);
}
void pose_H_13(double *state, double *unused, double *out_5714393237504566) {
  H_13(state, unused, out_5714393237504566);
}
void pose_h_14(double *state, double *unused, double *out_3822203570969529950) {
  h_14(state, unused, out_3822203570969529950);
}
void pose_H_14(double *state, double *unused, double *out_745252637769647162) {
  H_14(state, unused, out_745252637769647162);
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
