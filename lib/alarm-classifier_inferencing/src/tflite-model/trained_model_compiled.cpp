/* Generated by Edge Impulse
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
// Generated on: 10.03.2022 10:03:25

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#if EI_CLASSIFIER_PRINT_STATE
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C" {
    extern void ei_printf(const char *format, ...);
}
#else
extern void ei_printf(const char *format, ...);
#endif
#endif

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#endif

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

constexpr int kTensorArenaSize = 9040;

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) __attribute__((section(".tensor_arena")));
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_RESHAPE, OP_CONV_2D, OP_MAX_POOL_2D, OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext ctx{};
TfLiteTensor tflTensors[23];
TfLiteEvalTensor tflEvalTensors[23];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[11];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,3960 } };
const TfArray<1, float> quant0_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant0_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(16) int32_t tensor_data1[4] = { 1, 1, 99, 40, };
const TfArray<1, int> tensor_dimension1 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data2[4] = { 1, 99, 1, 8, };
const TfArray<1, int> tensor_dimension2 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data3[4] = { 1, 1, 50, 8, };
const TfArray<1, int> tensor_dimension3 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data4[4] = { 1, 50, 1, 16, };
const TfArray<1, int> tensor_dimension4 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data5[2] = { -1, 400, };
const TfArray<1, int> tensor_dimension5 = { 1, { 2 } };
const ALIGN(16) int8_t tensor_data6[8*1*3*40] = { 
  /* [0][0][][] */ -91,51,-57,38,50,-71,30,53,70,-48,-7,58,3,86,-63,-91,-25,-20,-54,-22,-94,56,-3,53,70,72,-107,5,-17,-48,-93,-13,-74,-37,75,25,-112,-43,-6,-90, 75,7,61,-69,-30,49,61,-98,-13,-27,83,-23,-44,-68,-40,72,-34,-76,8,-34,-87,-52,50,-39,-18,-127,-102,-63,4,-1,-73,57,82,-26,-60,-88,-53,-1,-65,-54, 5,-72,-37,42,71,20,39,-6,-66,-62,-58,-2,-13,23,-31,-2,-76,-100,-70,100,50,41,26,-85,12,35,-84,-63,-37,49,-107,-56,17,-31,-49,-28,76,51,81,-51, 
  /* [1][0][][] */ 8,5,-38,-56,31,8,21,-91,-2,77,27,-88,103,45,-17,75,0,24,35,-13,-82,57,-68,-93,86,60,16,23,-57,105,-10,-36,35,-36,-24,-33,43,9,40,46, -58,28,4,30,-65,71,85,-61,96,83,-12,64,-102,-105,-40,-85,-9,52,-42,-47,31,74,78,35,83,25,-29,-69,-40,25,-50,102,71,45,-32,112,-52,86,118,127, -122,-6,17,82,37,-102,-23,-103,69,45,-43,-20,85,19,-72,61,-13,-97,-80,-109,-65,-86,-105,16,-10,18,57,-77,60,-26,-84,36,107,74,22,50,103,87,79,10, 
  /* [2][0][][] */ 27,-104,-89,102,-122,-112,-113,94,-67,-77,-20,118,63,21,-51,-120,39,9,-20,86,-59,37,-20,80,-34,-19,9,-110,-85,-2,-76,19,89,-80,-32,53,-27,-59,23,-28, -31,-59,-31,68,-42,99,-19,-80,-40,-68,81,-53,84,-15,56,-46,89,-13,-64,68,-23,-23,-43,30,32,46,-70,99,43,7,7,53,28,-20,13,-81,108,68,-29,0, -65,-87,119,9,96,-69,125,73,-61,-107,35,-29,52,89,16,-35,-67,44,-16,-21,127,-20,-18,20,-74,26,113,50,-48,-82,-4,49,123,10,6,79,13,-90,105,-115, 
  /* [3][0][][] */ -56,79,-26,108,107,-87,-7,63,-56,9,2,-11,-2,81,77,-69,34,2,-88,-38,19,72,103,-66,86,18,-20,-32,-44,60,28,17,13,-30,-14,11,-75,74,0,-80, 0,7,16,-69,70,70,60,15,-65,35,-123,19,-47,-89,-52,104,-1,75,3,-92,-1,71,69,-76,-31,18,-25,-8,40,50,90,-58,-74,77,15,3,-105,-104,90,-85, 37,-68,89,-44,60,-35,55,17,-3,-58,-6,53,63,7,54,-90,86,47,38,74,-6,-63,-77,-89,-60,-20,-106,88,-63,-22,-79,-101,-54,81,62,72,-127,-36,67,67, 
  /* [4][0][][] */ 1,62,-49,52,99,-48,31,26,-74,31,46,96,24,56,16,-66,40,-61,-14,-37,27,-6,16,-79,39,41,6,-38,106,-69,7,-55,106,-23,-72,-62,123,127,-42,75, -65,59,-27,-25,43,21,-101,-69,10,-9,20,-94,-91,-31,-90,-42,84,-82,-63,66,-15,-90,-74,80,37,85,-73,46,26,17,100,91,-25,11,110,28,97,-70,57,2, -58,-18,107,39,63,-44,-84,-37,50,40,70,-42,73,17,-28,-74,-75,-8,18,38,41,-26,90,-88,102,-66,21,61,73,-69,-87,4,43,19,48,109,91,72,69,95, 
  /* [5][0][][] */ 63,39,52,40,25,-4,-12,-22,79,-78,12,32,121,16,-21,34,60,101,-26,85,1,30,67,-15,21,-46,112,-32,-22,46,102,64,-74,12,-10,110,42,-11,-17,-3, -48,-35,-61,109,-3,81,36,55,-65,87,-50,-96,-45,-52,-17,-18,49,-48,89,-86,-74,-111,-69,-81,-7,16,58,57,-63,101,53,102,18,74,74,77,-71,127,58,45, 7,53,3,-71,33,-22,81,100,110,-95,-7,102,73,89,30,102,60,-47,76,15,-4,-39,10,-47,71,91,70,10,63,80,-31,-47,-82,-65,119,-68,-21,26,15,121, 
  /* [6][0][][] */ -101,-83,-126,-109,-42,-32,88,25,-102,76,-62,33,5,-56,22,13,36,-46,-25,-94,-70,-10,-9,54,-46,-109,-111,-45,74,-91,-127,-108,-41,74,-28,76,-8,-110,-99,58, -36,-72,-39,54,-31,16,-59,-118,-24,-32,7,9,-30,-10,-110,86,-78,6,-113,92,12,45,73,17,-108,-70,-97,-73,44,-46,10,-63,-83,-107,-23,30,-1,64,-37,25, -82,64,29,-16,-3,-54,73,21,28,57,12,13,-28,-1,-28,-5,-95,-82,-25,54,71,-16,-37,-10,-123,-110,61,-24,78,-59,-32,-58,-5,53,68,62,51,-44,49,32, 
  /* [7][0][][] */ -21,-83,-46,59,50,-78,-43,35,-37,50,-90,-22,26,106,0,27,-55,23,94,-76,107,9,118,125,110,88,-49,-90,104,100,-64,-37,50,-70,-35,-72,86,-66,42,31, 16,-16,-30,58,-104,5,58,54,66,-20,-38,26,-69,-45,62,-103,29,-11,36,-85,-8,-26,118,-58,105,91,80,-37,93,111,53,10,15,62,-117,-111,-127,55,23,-95, -76,-112,-105,-35,61,11,68,80,-97,21,-99,-23,-19,58,-52,62,9,9,-26,-8,32,116,8,-5,-41,86,101,68,-85,54,-53,-31,-67,-11,24,47,-112,-99,-12,67, 
};
const TfArray<4, int> tensor_dimension6 = { 4, { 8,1,3,40 } };
const TfArray<8, float> quant6_scale = { 8, { 0.0019732986111193895, 0.0018644280498847365, 0.0017070492031052709, 0.0021491125226020813, 0.0019445633515715599, 0.0018836813978850842, 0.0018469957867637277, 0.0018761631799861789, } };
const TfArray<8, int> quant6_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(16) int32_t tensor_data7[8] = { -8388, -12657, 27993, 29688, -12195, -12648, -7401, 26623, };
const TfArray<1, int> tensor_dimension7 = { 1, { 8 } };
const TfArray<8, float> quant7_scale = { 8, { 7.7081976996851154e-06, 7.2829220698622521e-06, 6.6681609496299643e-06, 8.3949707914143801e-06, 7.5959505920764059e-06, 7.35813046048861e-06, 7.2148272920458112e-06, 7.3287624218210112e-06, } };
const TfArray<8, int> quant7_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const ALIGN(16) int8_t tensor_data8[16*1*3*8] = { 
  /* [0][0][][] */ -65,-24,-66,93,-58,-110,99,-53, 86,-35,-113,-37,-47,-127,33,-77, 74,-96,80,63,32,80,67,-2, 
  /* [1][0][][] */ -85,106,-111,-110,-13,-62,73,47, -127,-84,-69,-2,-108,39,-39,-30, 101,105,34,111,74,-51,-108,24, 
  /* [2][0][][] */ -78,69,-85,-88,17,89,-95,-114, 81,-16,14,70,26,-57,-94,54, -42,-99,-16,-127,22,27,40,-11, 
  /* [3][0][][] */ -86,51,15,-42,-27,94,-63,75, -55,-27,5,67,112,100,93,-66, 7,-127,68,-49,-35,58,98,-104, 
  /* [4][0][][] */ 8,11,75,73,24,-29,-9,74, -48,-19,37,44,-36,-35,33,99, 63,-66,78,127,-43,54,-38,95, 
  /* [5][0][][] */ 71,-25,-107,-12,118,127,18,73, -100,-61,-98,11,74,105,-107,-99, -59,31,76,-41,113,4,-75,37, 
  /* [6][0][][] */ 57,36,59,9,43,40,-57,40, 16,11,51,-127,20,92,-29,-99, -60,86,13,-86,71,-39,-10,-41, 
  /* [7][0][][] */ -76,-75,86,-7,-78,102,87,28, 58,-111,-69,45,101,70,60,-127, -107,-104,-87,13,87,20,-50,67, 
  /* [8][0][][] */ -25,-40,76,60,-34,-14,7,90, -2,-26,-19,127,30,22,35,75, 17,-53,57,19,-18,-33,48,61, 
  /* [9][0][][] */ -46,-50,29,-82,89,70,-95,-50, 0,113,98,-127,59,35,95,-74, -100,28,84,-51,38,-15,55,2, 
  /* [10][0][][] */ 1,-2,68,-41,-21,-122,-67,44, 107,4,4,2,93,25,93,-80, 13,-17,-31,-127,-67,-52,91,-46, 
  /* [11][0][][] */ -2,-32,-21,9,7,-43,83,-33, -61,109,65,-89,-33,7,31,73, 38,56,-107,31,127,-65,104,-10, 
  /* [12][0][][] */ 100,-7,-127,-46,43,72,36,-117, -38,-27,104,-6,59,-122,59,42, 12,30,-59,-75,-35,46,-8,69, 
  /* [13][0][][] */ -23,71,-45,45,-14,-38,-17,-127, -116,-9,68,-79,124,48,-94,-112, -65,-86,-24,36,28,82,100,-81, 
  /* [14][0][][] */ -17,39,69,14,-65,109,-51,-107, 11,67,-75,-28,108,6,5,-62, -58,103,71,-127,18,56,16,-32, 
  /* [15][0][][] */ 49,65,4,17,-24,-64,-58,-37, -46,44,9,-127,102,82,103,-16, 43,-37,47,-116,-5,51,-48,3, 
};
const TfArray<4, int> tensor_dimension8 = { 4, { 16,1,3,8 } };
const TfArray<16, float> quant8_scale = { 16, { 0.0023314799182116985, 0.0020276505965739489, 0.0024104469921439886, 0.0020392497535794973, 0.0047053676098585129, 0.0022518455516546965, 0.0030797377694398165, 0.0022630265448242426, 0.0050220559351146221, 0.0029944924172013998, 0.0024417000822722912, 0.0025418440345674753, 0.0023080648388713598, 0.0021893647499382496, 0.0028967626858502626, 0.0029366808012127876, } };
const TfArray<16, int> quant8_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const ALIGN(16) int32_t tensor_data9[16] = { -2483, -3107, -2470, -4464, 3843, -5081, -3624, -2689, 3885, -3490, -2180, -2834, -2152, -1637, -2601, -2262, };
const TfArray<1, int> tensor_dimension9 = { 1, { 16 } };
const TfArray<16, float> quant9_scale = { 16, { 2.2470734620583244e-05, 1.954243634827435e-05, 2.3231816157931462e-05, 1.9654229618026875e-05, 4.5350192522164434e-05, 2.1703221136704087e-05, 2.9682421882171184e-05, 2.1810983525938354e-05, 4.8402427637483925e-05, 2.8860829843324609e-05, 2.3533033527201042e-05, 2.449821840855293e-05, 2.2245059881242923e-05, 2.1101031961734407e-05, 2.791891347442288e-05, 2.8303642466198653e-05, } };
const TfArray<16, int> quant9_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const ALIGN(16) int8_t tensor_data10[2*400] = { 
  -2, -36, 2, -24, -67, -11, 54, 37, -70, 52, 7, 36, -28, 44, 34, 22, 9, 34, 31, -19, -55, 78, 21, 21, -103, -15, 57, -26, 64, 75, 39, 64, 14, 57, -16, -28, -71, -26, 80, 27, -118, 38, 8, 39, -22, 46, 77, 36, 3, -27, 63, 29, -31, 51, 3, 19, -55, -21, 55, 36, 34, -18, 41, 76, 6, 14, 22, -26, -30, -14, 39, 59, -94, -16, -32, 39, 4, 53, 16, 3, -6, 19, 30, -7, -113, 18, 59, -28, -72, 0, -26, -10, -28, 60, 27, 79, 30, 40, 68, 27, -77, -19, 85, -29, -63, 46, 21, 35, -11, 55, -1, -1, 17, 16, -13, 38, -111, -16, 6, -20, -66, 0, 20, 54, 15, 58, 73, 62, 12, -17, 28, 35, -39, 27, 52, 40, -41, 11, 69, 17, 44, 73, 54, 61, -28, -32, 48, 36, -73, 26, -2, 25, -61, 8, 29, 59, 12, 2, 80, -14, -5, 18, 30, 31, -91, -15, -15, 39, -126, 0, 31, 14, -25, 66, 83, -1, 27, 34, -13, 10, -104, -4, 76, -24, -110, 65, 2, 23, -25, 17, 30, 48, -46, -13, -15, -26, -38, 40, 64, 7, -55, 9, -8, 27, -7, 23, -4, 37, 25, -35, 53, 43, -119, 14, 19, 47, -116, 22, 24, -30, -8, 56, 41, 76, 44, -32, 49, 15, -23, 57, 32, -15, -72, 80, -18, -11, 7, -13, 57, 61, -3, -1, -4, 25, -84, 42, 12, -30, -125, 61, 20, -12, 2, 55, 43, 16, 36, -15, 42, 45, -122, 53, 59, -44, -110, 60, -14, -31, -4, -33, 80, 11, 42, 42, -43, 29, -111, 41, 64, 7, -116, 65, 47, 16, -9, 26, 33, 58, -11, 21, 37, 35, -126, 23, -20, -27, -91, 81, 68, 32, 14, -60, -8, 55, -40, 60, -31, -15, -108, -2, 70, -4, -108, 19, 19, 33, 50, 53, -26, 22, -24, 67, -12, -6, -59, -31, 9, 35, -82, 17, 39, 10, -4, 87, -15, -9, -43, 7, 9, 66, -120, 53, 39, 28, -86, -30, 49, 67, 15, -29, 30, 31, 43, 57, 63, -32, -98, -18, -19, -3, -79, 59, 56, 49, -25, 47, 52, 34, 50, -36, 66, 22, -66, 5, 62, -36, -47, -10, -7, 0, 61, -5, 84, 30, 10, 19, 10, 27, -16, 40, 42, -37, -41, 32, 61, 7, 62, 80, 3, 52, 
  18, -65, -11, 21, 113, 4, -5, -5, 83, -33, -4, -20, 25, -40, -53, -79, 30, -70, 31, 26, 29, -62, -52, -38, 28, -15, 37, -8, -54, -50, -21, 0, -20, -46, 25, -16, 75, -31, -43, -46, 59, 4, 14, 31, -10, -98, -38, -10, 37, 32, -29, 16, 36, -52, -22, 31, 87, -49, 3, -40, -32, -61, -35, -44, -36, 15, -41, -77, 22, -33, 2, -19, 89, -67, -9, -34, -31, -28, -60, -25, -39, 0, 31, -36, 79, -50, 9, 0, 23, -72, 19, -64, 6, -38, -17, -76, 2, 21, 19, -16, 72, 16, -11, 25, 114, -31, -24, -24, -56, -80, 17, 1, 6, -52, 22, -47, 74, -65, -5, 49, 112, 5, -4, -7, -36, -88, -48, -68, -19, 14, -12, 21, 68, -55, -57, -8, 123, -12, -12, 15, -47, -16, -52, -62, 38, -18, -7, 38, 120, -47, -1, -55, 120, 15, 27, -42, 21, -22, -43, -64, 1, 22, 34, 5, 120, -1, 13, 22, 38, -67, 27, -44, -58, -31, 2, -46, 22, 15, 18, 31, 23, -21, -20, 28, 16, 8, 3, 13, 13, 2, -63, -48, 47, 16, -30, -28, 112, -70, -52, -26, 127, -46, 24, 7, 33, -19, 10, 8, 49, -4, -1, -58, 96, -65, -12, -35, 30, 4, -48, -1, 36, -72, -78, -76, -12, 26, -7, 32, 113, 9, -15, -21, 81, -14, 9, -21, 7, -69, 5, -7, -45, 16, 33, 37, 38, -37, -76, 26, 124, 9, 5, -43, 5, -46, -25, -42, 50, 30, 34, -12, 97, 43, -8, 22, 73, -51, -73, 3, 17, -6, -21, -8, -28, -42, -40, -41, 27, -49, -11, -2, 47, -81, -17, -44, -10, -65, -28, -69, 29, -25, -14, -22, 56, -58, -22, 50, 35, -61, 32, -14, -4, -13, 1, 24, -41, -35, 21, -48, 78, -23, 18, -26, 84, -65, 23, -43, 39, -45, -78, -5, -6, 31, -6, -19, 90, 34, -77, 16, 34, -48, -56, -55, 2, -19, -56, -3, 38, -55, -32, -7, 84, -15, -53, 20, 51, -29, 11, 36, -15, -47, -74, -46, 27, 26, -30, -30, 69, 16, -8, 1, 52, -54, -6, -7, -32, -21, -6, -37, 22, -63, -75, -49, 57, -21, -43, 35, 66, -37, -3, 12, -55, -65, 2, -3, -3, -12, 33, -18, 40, 37, -44, 23, 127, -53, -43, 51, 24, -58, 10, 17, 
};
const TfArray<2, int> tensor_dimension10 = { 2, { 2,400 } };
const TfArray<1, float> quant10_scale = { 1, { 0.0022799414582550526, } };
const TfArray<1, int> quant10_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant10 = { (TfLiteFloatArray*)&quant10_scale, (TfLiteIntArray*)&quant10_zero, 0 };
const ALIGN(8) int32_t tensor_data11[2] = { -9250, 9250, };
const TfArray<1, int> tensor_dimension11 = { 1, { 2 } };
const TfArray<1, float> quant11_scale = { 1, { 1.5943320249789394e-05, } };
const TfArray<1, int> quant11_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant11 = { (TfLiteFloatArray*)&quant11_scale, (TfLiteIntArray*)&quant11_zero, 0 };
const TfArray<4, int> tensor_dimension12 = { 4, { 1,1,99,40 } };
const TfArray<1, float> quant12_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant12_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant12 = { (TfLiteFloatArray*)&quant12_scale, (TfLiteIntArray*)&quant12_zero, 0 };
const TfArray<4, int> tensor_dimension13 = { 4, { 1,1,99,8 } };
const TfArray<1, float> quant13_scale = { 1, { 0.0096379704773426056, } };
const TfArray<1, int> quant13_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant13 = { (TfLiteFloatArray*)&quant13_scale, (TfLiteIntArray*)&quant13_zero, 0 };
const TfArray<4, int> tensor_dimension14 = { 4, { 1,99,1,8 } };
const TfArray<1, float> quant14_scale = { 1, { 0.0096379704773426056, } };
const TfArray<1, int> quant14_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant14 = { (TfLiteFloatArray*)&quant14_scale, (TfLiteIntArray*)&quant14_zero, 0 };
const TfArray<4, int> tensor_dimension15 = { 4, { 1,50,1,8 } };
const TfArray<1, float> quant15_scale = { 1, { 0.0096379704773426056, } };
const TfArray<1, int> quant15_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant15 = { (TfLiteFloatArray*)&quant15_scale, (TfLiteIntArray*)&quant15_zero, 0 };
const TfArray<4, int> tensor_dimension16 = { 4, { 1,1,50,8 } };
const TfArray<1, float> quant16_scale = { 1, { 0.0096379704773426056, } };
const TfArray<1, int> quant16_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant16 = { (TfLiteFloatArray*)&quant16_scale, (TfLiteIntArray*)&quant16_zero, 0 };
const TfArray<4, int> tensor_dimension17 = { 4, { 1,1,50,16 } };
const TfArray<1, float> quant17_scale = { 1, { 0.0069928639568388462, } };
const TfArray<1, int> quant17_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant17 = { (TfLiteFloatArray*)&quant17_scale, (TfLiteIntArray*)&quant17_zero, 0 };
const TfArray<4, int> tensor_dimension18 = { 4, { 1,50,1,16 } };
const TfArray<1, float> quant18_scale = { 1, { 0.0069928639568388462, } };
const TfArray<1, int> quant18_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant18 = { (TfLiteFloatArray*)&quant18_scale, (TfLiteIntArray*)&quant18_zero, 0 };
const TfArray<4, int> tensor_dimension19 = { 4, { 1,25,1,16 } };
const TfArray<1, float> quant19_scale = { 1, { 0.0069928639568388462, } };
const TfArray<1, int> quant19_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant19 = { (TfLiteFloatArray*)&quant19_scale, (TfLiteIntArray*)&quant19_zero, 0 };
const TfArray<2, int> tensor_dimension20 = { 2, { 1,400 } };
const TfArray<1, float> quant20_scale = { 1, { 0.0069928639568388462, } };
const TfArray<1, int> quant20_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant20 = { (TfLiteFloatArray*)&quant20_scale, (TfLiteIntArray*)&quant20_zero, 0 };
const TfArray<2, int> tensor_dimension21 = { 2, { 1,2 } };
const TfArray<1, float> quant21_scale = { 1, { 0.089797705411911011, } };
const TfArray<1, int> quant21_zero = { 1, { 4 } };
const TfLiteAffineQuantization quant21 = { (TfLiteFloatArray*)&quant21_scale, (TfLiteIntArray*)&quant21_zero, 0 };
const TfArray<2, int> tensor_dimension22 = { 2, { 1,2 } };
const TfArray<1, float> quant22_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant22_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant22 = { (TfLiteFloatArray*)&quant22_scale, (TfLiteIntArray*)&quant22_zero, 0 };
const TfLiteReshapeParams opdata0 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs0 = { 2, { 0,1 } };
const TfArray<1, int> outputs0 = { 1, { 12 } };
const TfLiteConvParams opdata1 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs1 = { 3, { 12,6,7 } };
const TfArray<1, int> outputs1 = { 1, { 13 } };
const TfLiteReshapeParams opdata2 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs2 = { 2, { 13,2 } };
const TfArray<1, int> outputs2 = { 1, { 14 } };
const TfLitePoolParams opdata3 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs3 = { 1, { 14 } };
const TfArray<1, int> outputs3 = { 1, { 15 } };
const TfLiteReshapeParams opdata4 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs4 = { 2, { 15,3 } };
const TfArray<1, int> outputs4 = { 1, { 16 } };
const TfLiteConvParams opdata5 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs5 = { 3, { 16,8,9 } };
const TfArray<1, int> outputs5 = { 1, { 17 } };
const TfLiteReshapeParams opdata6 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs6 = { 2, { 17,4 } };
const TfArray<1, int> outputs6 = { 1, { 18 } };
const TfLitePoolParams opdata7 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs7 = { 1, { 18 } };
const TfArray<1, int> outputs7 = { 1, { 19 } };
const TfLiteReshapeParams opdata8 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs8 = { 2, { 19,5 } };
const TfArray<1, int> outputs8 = { 1, { 20 } };
const TfLiteFullyConnectedParams opdata9 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs9 = { 3, { 20,10,11 } };
const TfArray<1, int> outputs9 = { 1, { 21 } };
const TfLiteSoftmaxParams opdata10 = { 1 };
const TfArray<1, int> inputs10 = { 1, { 21 } };
const TfArray<1, int> outputs10 = { 1, { 22 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 3968, (TfLiteIntArray*)&tensor_dimension0, 3960, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 8, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 960, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data7, (TfLiteIntArray*)&tensor_dimension7, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data8, (TfLiteIntArray*)&tensor_dimension8, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data9, (TfLiteIntArray*)&tensor_dimension9, 64, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data10, (TfLiteIntArray*)&tensor_dimension10, 800, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant10))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data11, (TfLiteIntArray*)&tensor_dimension11, 8, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant11))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension12, 3960, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant12))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 3968, (TfLiteIntArray*)&tensor_dimension13, 792, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant13))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension14, 792, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant14))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 800, (TfLiteIntArray*)&tensor_dimension15, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant15))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension16, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant16))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 800, (TfLiteIntArray*)&tensor_dimension17, 800, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant17))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension18, 800, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant18))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 800, (TfLiteIntArray*)&tensor_dimension19, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant19))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension20, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant20))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension21, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant21))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension22, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant22))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs5, (TfLiteIntArray*)&outputs5, const_cast<void*>(static_cast<const void*>(&opdata5)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs6, (TfLiteIntArray*)&outputs6, const_cast<void*>(static_cast<const void*>(&opdata6)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs7, (TfLiteIntArray*)&outputs7, const_cast<void*>(static_cast<const void*>(&opdata7)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs8, (TfLiteIntArray*)&outputs8, const_cast<void*>(static_cast<const void*>(&opdata8)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs9, (TfLiteIntArray*)&outputs9, const_cast<void*>(static_cast<const void*>(&opdata9)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs10, (TfLiteIntArray*)&outputs10, const_cast<void*>(static_cast<const void*>(&opdata10)), OP_SOFTMAX, },
};
static std::vector<void*> overflow_buffers;
static void * AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  if (current_location - bytes < tensor_boundary) {
    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers.push_back(ptr);
    return ptr;
  }

  current_location -= bytes;

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static std::vector<scratch_buffer_t> scratch_buffers;

static TfLiteStatus RequestScratchBufferInArena(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBuffer(ctx, b.bytes);
  if (!b.ptr) {
    return kTfLiteError;
  }

  scratch_buffers.push_back(b);

  *buffer_idx = scratch_buffers.size() - 1;

  return kTfLiteOk;
}

static void* GetScratchBuffer(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > static_cast<int>(scratch_buffers.size()) - 1) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static TfLiteTensor* GetTensor(const struct TfLiteContext* context,
                               int tensor_idx) {
  return &tflTensors[tensor_idx];
}

static TfLiteEvalTensor* GetEvalTensor(const struct TfLiteContext* context,
                                       int tensor_idx) {
  return &tflEvalTensors[tensor_idx];
}

} // namespace

TfLiteStatus trained_model_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArena;
  ctx.GetScratchBuffer = &GetScratchBuffer;
  ctx.GetTensor = &GetTensor;
  ctx.GetEvalTensor = &GetEvalTensor;
  ctx.tensors = tflTensors;
  ctx.tensors_size = 23;
  for(size_t i = 0; i < 23; ++i) {
    tflTensors[i].type = tensorData[i].type;
    tflEvalTensors[i].type = tensorData[i].type;
    tflTensors[i].is_variable = 0;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    tflTensors[i].allocation_type = tensorData[i].allocation_type;
#else
    tflTensors[i].allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
    tflTensors[i].bytes = tensorData[i].bytes;
    tflTensors[i].dims = tensorData[i].dims;
    tflEvalTensors[i].dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    if(tflTensors[i].allocation_type == kTfLiteArenaRw){
      uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

     tflTensors[i].data.data =  start;
     tflEvalTensors[i].data.data =  start;
    }
    else{
       tflTensors[i].data.data = tensorData[i].data;
       tflEvalTensors[i].data.data = tensorData[i].data;
    }
#else
    tflTensors[i].data.data = tensorData[i].data;
    tflEvalTensors[i].data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
    tflTensors[i].quantization = tensorData[i].quantization;
    if (tflTensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
      tflTensors[i].params.scale = quant->scale->data[0];
      tflTensors[i].params.zero_point = quant->zero_point->data[0];
    }
    if (tflTensors[i].allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tflTensors[i].data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }
  if (tensor_boundary > current_location /* end of arena size */) {
    printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }
  registrations[OP_RESHAPE] = Register_RESHAPE();
  registrations[OP_CONV_2D] = Register_CONV_2D();
  registrations[OP_MAX_POOL_2D] = Register_MAX_POOL_2D();
  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for(size_t i = 0; i < 11; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
tflNodes[i].custom_initial_data = nullptr;
      tflNodes[i].custom_initial_data_size = 0;
if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for(size_t i = 0; i < 11; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteTensor* trained_model_input(int index) {
  return &ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  22, 
};
TfLiteTensor* trained_model_output(int index) {
  return &ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus trained_model_invoke() {
  for(size_t i = 0; i < 11; ++i) {
    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);

#if EI_CLASSIFIER_PRINT_STATE
    ei_printf("layer %lu\n", i);
    ei_printf("    inputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].inputs->size; ix++) {
      auto d = tensorData[tflNodes[i].inputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");

    ei_printf("    outputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].outputs->size; ix++) {
      auto d = tensorData[tflNodes[i].outputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");
#endif // EI_CLASSIFIER_PRINT_STATE

    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus trained_model_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif
  scratch_buffers.clear();
  for (size_t ix = 0; ix < overflow_buffers.size(); ix++) {
    free(overflow_buffers[ix]);
  }
  overflow_buffers.clear();
  return kTfLiteOk;
}
