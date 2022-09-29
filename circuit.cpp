#include "circom.hpp"
#include "calcwit.hpp"
#define NSignals 11
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
    FrElement result[1];
    FrElement _sigValue_1[1];
    FrElement temp_op[1];
    int _arr_sigIdx_;
    int _offset_1;
    int _offset_3;
    int _out_sigIdx_;
    Circom_Sizes _sigSizes_arr;
    _arr_sigIdx_ = ctx->getSignalOffset(__cIdx, 0xe756b1190570b338LL /* arr */);
    _out_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x19f79b1921bbcfffLL /* out */);
    _sigSizes_arr = ctx->getSignalSizes(__cIdx, 0xe756b1190570b338LL /* arr */);
    /* signal input arr[k] */
    /* signal output out */
    /* var result = arr[0] */
    _offset_1 = _arr_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_1, _sigValue, 1);
    Fr_copyn(result, _sigValue, 1);
    /* var temp_op = arr[1] */
    _offset_3 = _arr_sigIdx_ + 1*_sigSizes_arr[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_3, _sigValue_1, 1);
    Fr_copyn(temp_op, _sigValue_1, 1);
    /* out <== result */
    ctx->setSignal(__cIdx, __cIdx, _out_sigIdx_, result);
    ctx->finished(__cIdx);
}
// Function Table
Circom_ComponentFunction _functionTable[1] = {
     operation_d6c1bd8047f9cc9b
};
