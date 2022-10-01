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
    FrElement _sigValue_1[1];
    FrElement _tmp[1];
    FrElement _sigValue_2[1];
    FrElement _tmp_1[1];
    FrElement _sigValue_3[1];
    FrElement _tmp_2[1];
    FrElement _sigValue_4[1];
    FrElement _tmp_3[1];
    FrElement _sigValue_5[1];
    FrElement _tmp_4[1];
    FrElement _tmp_5[1];
    FrElement _tmp_6[1];
    FrElement _tmp_7[1];
    FrElement temp[1];
    FrElement _sigValue_6[1];
    FrElement _tmp_8[1];
    FrElement _sigValue_7[1];
    FrElement _sigValue_8[1];
    int _arr_sigIdx_;
    int _offset_1;
    int _result_sigIdx_;
    int _offset_2;
    int _offset_3;
    int _offset_4;
    int _offset_5;
    int _offset_6;
    int _offset_7;
    int _offset_8;
    int _offset_9;
    int _offset_10;
    int _offset_11;
    int _offset_13;
    int _offset_15;
    int _offset_17;
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
    /* signal result[9] */
    /* result[0] <-- arr[0] */
    _offset_1 = _arr_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_1, _sigValue, 1);
    _offset_2 = _result_sigIdx_;
    ctx->setSignal(__cIdx, __cIdx, _offset_2, _sigValue);
    /* result[1] <-- result[0] + 3 */
    _offset_3 = _result_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_3, _sigValue_1, 1);
    Fr_add(_tmp, _sigValue_1, (ctx->circuit->constants + 2));
    _offset_4 = _result_sigIdx_ + 1*_sigSizes_result[1];
    ctx->setSignal(__cIdx, __cIdx, _offset_4, _tmp);
    /* result[2] <-- result[1] * 5 */
    _offset_5 = _result_sigIdx_ + 1*_sigSizes_result[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_5, _sigValue_2, 1);
    Fr_mul(_tmp_1, _sigValue_2, (ctx->circuit->constants + 3));
    _offset_6 = _result_sigIdx_ + 2*_sigSizes_result[1];
    ctx->setSignal(__cIdx, __cIdx, _offset_6, _tmp_1);
    /* result[3] <-- result[2] - 6 */
    _offset_7 = _result_sigIdx_ + 2*_sigSizes_result[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_7, _sigValue_3, 1);
    Fr_sub(_tmp_2, _sigValue_3, (ctx->circuit->constants + 4));
    _offset_8 = _result_sigIdx_ + 3*_sigSizes_result[1];
    ctx->setSignal(__cIdx, __cIdx, _offset_8, _tmp_2);
    /* result[4] <-- result[3] * 4 */
    _offset_9 = _result_sigIdx_ + 3*_sigSizes_result[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_9, _sigValue_4, 1);
    Fr_mul(_tmp_3, _sigValue_4, (ctx->circuit->constants + 5));
    _offset_10 = _result_sigIdx_ + 4*_sigSizes_result[1];
    ctx->setSignal(__cIdx, __cIdx, _offset_10, _tmp_3);
    /* var temp = (((arr[0] + 3) * 5) -6) * 4 */
    _offset_11 = _arr_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_11, _sigValue_5, 1);
    Fr_add(_tmp_4, _sigValue_5, (ctx->circuit->constants + 2));
    Fr_mul(_tmp_5, _tmp_4, (ctx->circuit->constants + 3));
    Fr_sub(_tmp_6, _tmp_5, (ctx->circuit->constants + 4));
    Fr_mul(_tmp_7, _tmp_6, (ctx->circuit->constants + 5));
    Fr_copyn(temp, _tmp_7, 1);
    /* log(result[4] - temp) */
    _offset_13 = _result_sigIdx_ + 4*_sigSizes_result[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_13, _sigValue_6, 1);
    Fr_sub(_tmp_8, _sigValue_6, temp);
    ctx->log(_tmp_8);
    /* result[4] === temp */
    _offset_15 = _result_sigIdx_ + 4*_sigSizes_result[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_15, _sigValue_7, 1);
    ctx->checkConstraint(__cIdx, _sigValue_7, temp, "/Users/chihaolu/Desktop/circom/circuit.circom:57:4");
    /* out <== result[4] */
    _offset_17 = _result_sigIdx_ + 4*_sigSizes_result[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_17, _sigValue_8, 1);
    ctx->setSignal(__cIdx, __cIdx, _out_sigIdx_, _sigValue_8);
    ctx->finished(__cIdx);
}
// Function Table
Circom_ComponentFunction _functionTable[1] = {
     operation_d6c1bd8047f9cc9b
};
