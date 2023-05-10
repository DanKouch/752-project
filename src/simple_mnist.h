#include "ebnn.h"
float l_conv_pool_bn_bst0_bconv_b[10] = {0.0013100981,0.001399203,0.0017230948,0.024209941,-0.0060366672,0.0033805103,-0.0094644753,0.0049478835,-0.0021037918,-0.011334958};
uint8_t l_conv_pool_bn_bst0_bconv_W[20] = {27,255,15,255,9,255,224,127,94,127,241,255,228,127,234,127,247,255,37,255};
float l_conv_pool_bn_bst0_bn_beta[10] = {-0.55817193,-0.30276805,-0.51059455,-0.47079924,-0.23738748,-0.33949313,-0.51129502,-0.27581051,-0.11652919,-0.40916726};
float l_conv_pool_bn_bst0_bn_gamma[10] = {1.1175779,0.80334842,1.1644053,1.0309528,0.76619667,0.83233267,1.0995027,1.1048702,0.53803885,0.96208674};
float l_conv_pool_bn_bst0_bn_mean[10] = {1.1252871,1.2539475,0.26034799,0.43928567,0.91338098,1.4778961,0.65796793,1.0754046,2.9302435,0.86354005};
float l_conv_pool_bn_bst0_bn_std[10] = {1.2298298,1.3209409,0.45731518,0.68497282,0.92040253,1.3025718,0.90514964,1.1048282,2.4770014,1.0458035};
void l_conv_pool_bn_bst0(float* input, uint8_t* output){
  fconv_layer(input, l_conv_pool_bn_bst0_bconv_W, output, l_conv_pool_bn_bst0_bconv_b, l_conv_pool_bn_bst0_bn_gamma, l_conv_pool_bn_bst0_bn_beta, l_conv_pool_bn_bst0_bn_mean, l_conv_pool_bn_bst0_bn_std, 1, 10, 28, 28, 1, 3, 3, 2, 2, 0, 0, 3, 3, 2, 2, 0, 0);
}

float l_b_linear_bn_softmax1_bl_b[10] = {0.0021418647,-0.00088884449,0.0011457953,-0.0011375663,-0.0021664687,-0.0032370447,-0.00054983149,-0.001796403,0.0090369461,0.0052212267};
uint8_t l_b_linear_bn_softmax1_bl_W[450] = {24,112,64,50,221,108,195,51,129,235,140,6,60,52,16,48,80,202,7,214,249,72,16,231,207,30,189,34,97,129,195,224,48,56,182,235,24,124,121,207,184,47,255,125,240,216,4,64,2,107,196,162,2,144,6,9,0,90,72,33,5,10,2,158,20,5,133,130,5,80,213,91,2,0,161,22,128,97,87,28,81,75,91,45,183,167,193,182,250,220,223,236,61,13,179,32,27,252,195,161,14,255,204,22,28,247,189,251,118,184,188,255,63,238,1,77,221,249,239,1,15,120,9,143,111,123,253,240,20,91,40,31,27,206,112,247,197,183,243,143,36,113,43,188,226,207,168,243,232,56,254,204,159,239,15,228,131,239,116,26,252,187,227,202,30,241,192,59,216,200,188,186,3,135,135,78,103,48,57,243,205,2,15,135,191,227,79,178,88,253,56,229,77,144,49,0,180,103,254,162,183,0,240,49,107,63,225,131,0,63,176,120,43,43,239,129,2,62,186,49,127,239,123,81,46,0,115,255,241,192,75,100,15,243,14,112,100,249,227,135,21,197,14,8,114,8,208,180,17,224,192,87,12,121,254,225,219,131,35,192,93,109,95,4,28,55,0,65,108,209,5,1,198,179,13,200,124,193,225,14,227,196,11,59,223,88,73,222,124,7,79,58,15,193,165,125,236,14,16,129,120,207,245,112,67,239,126,132,86,236,143,200,199,214,192,195,252,3,0,96,63,3,121,56,66,97,94,11,11,208,243,172,160,2,255,179,22,3,249,40,40,184,223,207,34,10,7,131,243,40,212,5,252,194,19,224,16,16,102,108,156,247,6,57,193,217,157,142,38,51,176,218,0,110,196,12,56,22,117,147,236,96,96,63,252,254,31,144,110,255,17,199,76,14,231,71,31,138,213,160,132,239,188,159,223,240,115,216,192,57,188,248,131,56,19,207,6,47,154,92,32,67,32,64,206,206,48,220,79,251,232,51,244,225,188,226,62,124,116,244,35,229,201,186,192,44,12,207,81,47};
float l_b_linear_bn_softmax1_bn_beta[10] = {-0.087895885,-0.13657779,0.12318978,0.083548136,-0.039687563,-0.0038500342,-0.13571718,0.058700237,0.087708674,0.036141276};
float l_b_linear_bn_softmax1_bn_gamma[10] = {1.9116997,1.87517,1.8178381,1.893056,1.8975471,1.818992,1.896561,1.8710274,1.8150749,1.8474073};
float l_b_linear_bn_softmax1_bn_mean[10] = {21.863476,17.281767,-26.20944,-15.18664,-2.5975568,17.921856,8.1386652,10.443426,28.181669,24.527216};
float l_b_linear_bn_softmax1_bn_std[10] = {28.596811,31.616959,29.135447,26.32029,23.809271,23.051489,26.144327,29.256929,21.304688,24.553493};
void l_b_linear_bn_softmax1(uint8_t* input, uint8_t* output, float* res_array){
  blinear_sm_layer(input, l_b_linear_bn_softmax1_bl_W, output, l_b_linear_bn_softmax1_bl_b, l_b_linear_bn_softmax1_bn_gamma, l_b_linear_bn_softmax1_bn_beta, l_b_linear_bn_softmax1_bn_mean, l_b_linear_bn_softmax1_bn_std, 1, 360, 10, res_array); 
}

__attribute__ ((section(".ram")))
uint8_t temp1[104] = {0};

__attribute__ ((section(".ram")))
uint8_t temp2[104] = {0};

void ebnn_compute(float *input, uint8_t *output, float *res_array){
  l_conv_pool_bn_bst0(input, temp1);
  l_b_linear_bn_softmax1(temp1, output, res_array);
}