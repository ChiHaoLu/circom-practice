#include "circom.hpp"
#include "calcwit.hpp"
#define NSignals 20
#define NComponents 1
#define NOutputs 1
#define NInputs 9
#define NVars 11
#define NPublic 10
#define __P__ "21888242871839275222246405745257275088548364400416034343698204186575808495617"

/*
operation
k=9
*/
void operation_d6c1bd8047f9cc9b(Circom_CalcWit *ctx, int __cIdx) {
    FrElement _sigValue[1];
    FrElement _tmp[1];
    FrElement _tmp_1[1];
    FrElement _tmp_2[1];
    FrElement _tmp_3[1];
    FrElement temp[1];
    FrElement _sigValue_1[1];
    FrElement _sigValue_2[1];
    FrElement _sigValue_3[1];
    FrElement _tmp_4[1];
    FrElement _sigValue_4[1];
    FrElement _sigValue_5[1];
    FrElement _tmp_5[1];
    FrElement _sigValue_6[1];
    FrElement _sigValue_7[1];
    FrElement _tmp_6[1];
    FrElement _sigValue_8[1];
    FrElement _sigValue_9[1];
    FrElement _tmp_7[1];
    FrElement _sigValue_10[1];
    FrElement _tmp_8[1];
    FrElement _sigValue_11[1];
    FrElement _sigValue_12[1];
    int _arr_sigIdx_;
    int _offset_1;
    int _offset_4;
    int _result_sigIdx_;
    int _offset_5;
    int _offset_6;
    int _offset_7;
    int _offset_8;
    int _offset_9;
    int _offset_10;
    int _offset_11;
    int _offset_12;
    int _offset_13;
    int _offset_14;
    int _offset_15;
    int _offset_16;
    int _offset_17;
    int _offset_18;
    int _offset_20;
    int _offset_22;
    int _out_sigIdx_;
    Circom_Sizes _sigSizes_arr;
    Circom_Sizes _sigSizes_result;
    _arr_sigIdx_ = ctx->getSignalOffset(__cIdx, 0xe756b1190570b338LL /* arr */);
    _result_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x9b51cd7cd76778c4LL /* result */);
    _out_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x19f79b1921bbcfffLL /* out */);
    _sigSizes_arr = ctx->getSignalSizes(__cIdx, 0xe756b1190570b338LL /* arr */);
    _sigSizes_result = ctx->getSignalSizes(__cIdx, 0x9b51cd7cd76778c4LL /* result */);
    /* signal input arr[k] */
    /* signal output out */
    /* var temp = (((arr[0] + 3) * 5) -6) * 4 */
    _offset_1 = _arr_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_1, _sigValue, 1);
    Fr_add(_tmp, _sigValue, (ctx->circuit->constants + 2));
    Fr_mul(_tmp_1, _tmp, (ctx->circuit->constants + 3));
    Fr_sub(_tmp_2, _tmp_1, (ctx->circuit->constants + 4));
    Fr_mul(_tmp_3, _tmp_2, (ctx->circuit->constants + 5));
    Fr_copyn(temp, _tmp_3, 1);
    /* signal result[k] */
    /* result[0] <-- arr[0] */
    _offset_4 = _arr_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_4, _sigValue_1, 1);
    _offset_5 = _result_sigIdx_;
    ctx->setSignal(__cIdx, __cIdx, _offset_5, _sigValue_1);
    /* result[1] <-- result[0] + arr[2] */
    _offset_6 = _result_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_6, _sigValue_2, 1);
    _offset_7 = _arr_sigIdx_ + 2*_sigSizes_arr[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_7, _sigValue_3, 1);
    Fr_add(_tmp_4, _sigValue_2, _sigValue_3);
    _offset_8 = _result_sigIdx_ + 1*_sigSizes_result[1];
    ctx->setSignal(__cIdx, __cIdx, _offset_8, _tmp_4);
    /* result[2] <-- result[1] * arr[4] */
    _offset_9 = _result_sigIdx_ + 1*_sigSizes_result[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_9, _sigValue_4, 1);
    _offset_10 = _arr_sigIdx_ + 4*_sigSizes_arr[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_10, _sigValue_5, 1);
    Fr_mul(_tmp_5, _sigValue_4, _sigValue_5);
    _offset_11 = _result_sigIdx_ + 2*_sigSizes_result[1];
    ctx->setSignal(__cIdx, __cIdx, _offset_11, _tmp_5);
    /* result[3] <-- result[2] - arr[6] */
    _offset_12 = _result_sigIdx_ + 2*_sigSizes_result[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_12, _sigValue_6, 1);
    _offset_13 = _arr_sigIdx_ + 6*_sigSizes_arr[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_13, _sigValue_7, 1);
    Fr_sub(_tmp_6, _sigValue_6, _sigValue_7);
    _offset_14 = _result_sigIdx_ + 3*_sigSizes_result[1];
    ctx->setSignal(__cIdx, __cIdx, _offset_14, _tmp_6);
    /* result[4] <-- result[3] * arr[8] */
    _offset_15 = _result_sigIdx_ + 3*_sigSizes_result[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_15, _sigValue_8, 1);
    _offset_16 = _arr_sigIdx_ + 8*_sigSizes_arr[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_16, _sigValue_9, 1);
    Fr_mul(_tmp_7, _sigValue_8, _sigValue_9);
    _offset_17 = _result_sigIdx_ + 4*_sigSizes_result[1];
    ctx->setSignal(__cIdx, __cIdx, _offset_17, _tmp_7);
    /* log(result[4] - temp) */
    _offset_18 = _result_sigIdx_ + 4*_sigSizes_result[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_18, _sigValue_10, 1);
    Fr_sub(_tmp_8, _sigValue_10, temp);
    ctx->log(_tmp_8);
    /* result[4] === temp */
    _offset_20 = _result_sigIdx_ + 4*_sigSizes_result[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_20, _sigValue_11, 1);
    ctx->checkConstraint(__cIdx, _sigValue_11, temp, "/Users/chihaolu/Desktop/circom/circuit.circom:58:4");
    /* out <== result[4] */
    _offset_22 = _result_sigIdx_ + 4*_sigSizes_result[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_22, _sigValue_12, 1);
    ctx->setSignal(__cIdx, __cIdx, _out_sigIdx_, _sigValue_12);
    ctx->finished(__cIdx);
}
// Function Table
Circom_ComponentFunction _functionTable[1] = {
     operation_d6c1bd8047f9cc9b
};
