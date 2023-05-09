#include "ebnn.h"
float l_b_conv_pool_bn_bst0_bconv_b[10] = {-0.0019964674,-0.0014448628,0.035571262,0.0011312434,0.00052776962,-0.0024792235,0.0030493855,-0.0082627721,0.009665288,-0.0015612287};
uint8_t l_b_conv_pool_bn_bst0_bconv_W[20] = {248,127,228,127,228,127,110,255,189,255,158,255,183,127,19,255,91,127,101,255};
float l_b_conv_pool_bn_bst0_bn_beta[10] = {-0.44869453,-0.36304367,-0.72027928,-0.52004105,0.0420793,-0.070259444,-0.28672469,-0.34335798,-0.24082467,-0.51694465};
float l_b_conv_pool_bn_bst0_bn_gamma[10] = {1.0057141,0.91785663,0.90325022,0.90230775,0.81065816,0.93027312,0.8877396,0.86638236,0.7668674,1.078504};
float l_b_conv_pool_bn_bst0_bn_mean[10] = {2.0757804,2.3014512,2.7197518,1.3350036,0.91946429,1.0179693,0.78374344,2.964381,1.6609945,1.7927171};
float l_b_conv_pool_bn_bst0_bn_std[10] = {3.2608018,2.7385249,2.1224995,3.3819435,4.5014768,3.7332389,2.9808712,2.2145314,2.6149683,3.2134039};
void l_b_conv_pool_bn_bst0(uint8_t* input, uint8_t* output){
  bconv_layer(input, l_b_conv_pool_bn_bst0_bconv_W, output, l_b_conv_pool_bn_bst0_bconv_b, l_b_conv_pool_bn_bst0_bn_gamma, l_b_conv_pool_bn_bst0_bn_beta, l_b_conv_pool_bn_bst0_bn_mean, l_b_conv_pool_bn_bst0_bn_std, 1, 10, 28, 28, 1, 3, 3, 2, 2, 0, 0, 3, 3, 2, 2, 0, 0);
}

float l_b_linear_bn_softmax1_bl_b[10] = {-0.0030055868,-0.0011136349,-0.00034322278,0.0024574662,-0.00028333769,-0.0010476325,0.0024891661,-0.00016313365,-0.018592985,0.0032423565};
uint8_t l_b_linear_bn_softmax1_bl_W[450] = {98,3,128,79,224,36,56,24,94,89,65,130,3,146,36,111,53,216,250,126,179,43,19,207,196,146,185,33,118,121,236,203,131,192,67,7,98,118,57,60,37,46,207,61,245,0,12,161,37,160,32,75,24,96,34,2,34,129,10,208,32,82,19,188,75,41,32,59,197,2,152,115,167,68,129,21,37,192,164,28,167,128,5,49,85,176,128,180,18,106,113,238,177,255,31,60,240,59,243,244,239,1,15,126,63,153,222,32,239,225,53,159,55,127,3,201,211,56,240,116,253,155,18,211,240,195,91,104,140,20,18,59,29,78,113,35,204,204,219,226,60,172,205,254,59,130,30,243,0,38,50,137,248,230,10,142,203,199,176,190,238,253,163,59,167,143,206,236,242,191,56,255,40,243,202,100,36,56,169,244,2,16,111,248,88,17,2,189,129,63,0,59,236,113,247,95,78,46,125,61,178,80,30,235,235,176,3,102,18,146,82,15,208,50,116,115,255,135,203,129,208,223,89,97,15,8,115,252,193,248,199,183,196,31,192,119,254,107,137,9,65,9,197,78,119,124,201,214,231,83,78,219,1,2,5,13,114,79,30,127,12,100,147,32,66,246,113,192,9,227,188,113,3,124,235,247,146,124,222,134,48,102,99,235,236,53,246,192,20,140,119,88,233,200,149,98,168,126,7,71,62,0,40,124,96,32,118,143,222,159,15,128,213,182,192,255,63,242,76,3,241,113,36,160,71,159,35,136,3,32,146,103,25,1,228,162,27,144,63,90,33,53,38,173,51,51,36,31,195,120,48,3,56,243,61,194,50,28,103,120,240,124,199,34,250,12,237,243,15,140,102,75,25,195,53,157,134,143,63,219,197,160,227,223,61,226,15,141,251,206,104,115,175,19,56,134,57,243,206,112,115,127,127,142,127,230,227,29,114,52,94,51,222,129,10,240,152,96,28,8,251,73,28,129,252,184,48,28,15,29,230,97,192,239,255,199,211,191,116,138,59,0,238,226,14,217,152,207,243,103};
float l_b_linear_bn_softmax1_bn_beta[10] = {-0.12386253,-0.13802822,0.083668754,0.084427208,0.0110215,0.0053780014,-0.10728264,0.03886269,0.10919367,0.03057849};
float l_b_linear_bn_softmax1_bn_gamma[10] = {1.9055973,1.8344553,1.8852386,1.8764985,1.8410195,1.7907674,1.8511354,1.8892865,1.7601967,1.7847425};
float l_b_linear_bn_softmax1_bn_mean[10] = {32.604347,3.7339218,-15.641062,0.30107751,-6.0577564,13.673304,15.538383,7.6556573,46.733898,28.500366};
float l_b_linear_bn_softmax1_bn_std[10] = {28.082285,29.841702,30.142958,26.488661,25.52788,25.87661,27.551304,30.894911,23.24127,28.76712};
void l_b_linear_bn_softmax1(uint8_t* input, uint8_t* output){
  blinear_sm_layer(input, l_b_linear_bn_softmax1_bl_W, output, l_b_linear_bn_softmax1_bl_b, l_b_linear_bn_softmax1_bn_gamma, l_b_linear_bn_softmax1_bn_beta, l_b_linear_bn_softmax1_bn_mean, l_b_linear_bn_softmax1_bn_std, 1, 360, 10); 
}

__attribute__ ((section(".ram")))
uint8_t temp1[104] = {0};

__attribute__ ((section(".ram")))
uint8_t temp2[104] = {0};

void ebnn_compute(uint8_t *input, uint8_t *output){
  l_b_conv_pool_bn_bst0(input, temp1);
  l_b_linear_bn_softmax1(temp1, output);
}