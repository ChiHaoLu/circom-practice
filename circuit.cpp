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
    FrElement _tmp_3[1];
    FrElement _sigValue_2[1];
    FrElement _tmp_4[1];
    FrElement _tmp_5[1];
    FrElement _sigValue_3[1];
    FrElement _tmp_6[1];
    FrElement _tmp_7[1];
    FrElement _sigValue_4[1];
    FrElement _tmp_8[1];
    FrElement _tmp_11[1];
    FrElement i[1];
    FrElement _tmp_12[1];
    FrElement _tmp_13[1];
    FrElement _sigValue_5[1];
    FrElement _tmp_14[1];
    FrElement _num_11[1];
    FrElement _sigValue_6[1];
    FrElement _tmp_15[1];
    FrElement _num_13[1];
    FrElement _sigValue_7[1];
    FrElement _tmp_16[1];
    FrElement _num_15[1];
    FrElement _tmp_17[1];
    FrElement _sigValue_8[1];
    FrElement _tmp_18[1];
    FrElement _tmp_19[1];
    FrElement _sigValue_9[1];
    FrElement _tmp_20[1];
    FrElement _tmp_21[1];
    FrElement _sigValue_10[1];
    FrElement _tmp_22[1];
    FrElement _tmp_24[1];
    FrElement _tmp_23[1];
    FrElement _tmp_25[1];
    FrElement _sigValue_11[1];
    FrElement _tmp_26[1];
    FrElement _tmp_27[1];
    FrElement _tmp_28[1];
    FrElement _tmp_29[1];
    FrElement _sigValue_12[1];
    FrElement _tmp_30[1];
    FrElement _tmp_31[1];
    FrElement _tmp_32[1];
    FrElement _tmp_33[1];
    FrElement _tmp_34[1];
    int _arr_sigIdx_;
    int _offset_1;
    int _offset_3;
    int _offset_12;
    int _offset_17;
    int _offset_22;
    int _offset_30;
    int _offset_33;
    int _offset_36;
    int _offset_41;
    int _offset_46;
    int _offset_51;
    int _offset_58;
    int _offset_60;
    int _out_sigIdx_;
    Circom_Sizes _sigSizes_arr;
    PFrElement _loopCond;
    Fr_copy(&(_tmp_11[0]), ctx->circuit->constants +1);
    Fr_copy(&(i[0]), ctx->circuit->constants +5);
    Fr_copy(&(_num_11[0]), ctx->circuit->constants +2);
    Fr_copy(&(_num_13[0]), ctx->circuit->constants +3);
    Fr_copy(&(_num_15[0]), ctx->circuit->constants +4);
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
    /* for (var i = 2;i < k;i++) */
    /* if (i % 2 != 0) */
    /* if (temp_op == 147) */
    Fr_eq(_tmp_3, temp_op, (ctx->circuit->constants + 2));
    if (Fr_isTrue(_tmp_3)) {
        /* result = result + arr[i] */
        _offset_12 = _arr_sigIdx_ + 2*_sigSizes_arr[1];
        ctx->multiGetSignal(__cIdx, __cIdx, _offset_12, _sigValue_2, 1);
        Fr_add(_tmp_4, result, _sigValue_2);
        Fr_copyn(result, _tmp_4, 1);
    } else {
        /* if (temp_op == 148) */
        Fr_eq(_tmp_5, temp_op, (ctx->circuit->constants + 3));
        if (Fr_isTrue(_tmp_5)) {
            /* result = result - arr[i] */
            _offset_17 = _arr_sigIdx_ + 2*_sigSizes_arr[1];
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_17, _sigValue_3, 1);
            Fr_sub(_tmp_6, result, _sigValue_3);
            Fr_copyn(result, _tmp_6, 1);
        } else {
            /* if (temp_op == 149) */
            Fr_eq(_tmp_7, temp_op, (ctx->circuit->constants + 4));
            if (Fr_isTrue(_tmp_7)) {
                /* result = result * arr[i] */
                _offset_22 = _arr_sigIdx_ + 2*_sigSizes_arr[1];
                ctx->multiGetSignal(__cIdx, __cIdx, _offset_22, _sigValue_4, 1);
                Fr_mul(_tmp_8, result, _sigValue_4);
                Fr_copyn(result, _tmp_8, 1);
            }
        }
    }
    _loopCond = _tmp_11;
    while (Fr_isTrue(_loopCond)) {
        /* if (i % 2 != 0) */
        Fr_mod(_tmp_12, i, (ctx->circuit->constants + 6));
        Fr_neq(_tmp_13, _tmp_12, (ctx->circuit->constants + 0));
        if (Fr_isTrue(_tmp_13)) {
            /* if (arr[i] == 147) */
            _offset_30 = _arr_sigIdx_ + Fr_toInt(i)*_sigSizes_arr[1];
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_30, _sigValue_5, 1);
            Fr_eq(_tmp_14, _sigValue_5, (ctx->circuit->constants + 2));
            if (Fr_isTrue(_tmp_14)) {
                /* temp_op = 147 */
                Fr_copyn(temp_op, _num_11, 1);
            } else {
                /* if (arr[i] == 148) */
                _offset_33 = _arr_sigIdx_ + Fr_toInt(i)*_sigSizes_arr[1];
                ctx->multiGetSignal(__cIdx, __cIdx, _offset_33, _sigValue_6, 1);
                Fr_eq(_tmp_15, _sigValue_6, (ctx->circuit->constants + 3));
                if (Fr_isTrue(_tmp_15)) {
                    /* temp_op = 148 */
                    Fr_copyn(temp_op, _num_13, 1);
                } else {
                    /* if (arr[i] == 149) */
                    _offset_36 = _arr_sigIdx_ + Fr_toInt(i)*_sigSizes_arr[1];
                    ctx->multiGetSignal(__cIdx, __cIdx, _offset_36, _sigValue_7, 1);
                    Fr_eq(_tmp_16, _sigValue_7, (ctx->circuit->constants + 4));
                    if (Fr_isTrue(_tmp_16)) {
                        /* temp_op = 149 */
                        Fr_copyn(temp_op, _num_15, 1);
                    }
                }
            }
        } else {
            /* if (temp_op == 147) */
            Fr_eq(_tmp_17, temp_op, (ctx->circuit->constants + 2));
            if (Fr_isTrue(_tmp_17)) {
                /* result = result + arr[i] */
                _offset_41 = _arr_sigIdx_ + Fr_toInt(i)*_sigSizes_arr[1];
                ctx->multiGetSignal(__cIdx, __cIdx, _offset_41, _sigValue_8, 1);
                Fr_add(_tmp_18, result, _sigValue_8);
                Fr_copyn(result, _tmp_18, 1);
            } else {
                /* if (temp_op == 148) */
                Fr_eq(_tmp_19, temp_op, (ctx->circuit->constants + 3));
                if (Fr_isTrue(_tmp_19)) {
                    /* result = result - arr[i] */
                    _offset_46 = _arr_sigIdx_ + Fr_toInt(i)*_sigSizes_arr[1];
                    ctx->multiGetSignal(__cIdx, __cIdx, _offset_46, _sigValue_9, 1);
                    Fr_sub(_tmp_20, result, _sigValue_9);
                    Fr_copyn(result, _tmp_20, 1);
                } else {
                    /* if (temp_op == 149) */
                    Fr_eq(_tmp_21, temp_op, (ctx->circuit->constants + 4));
                    if (Fr_isTrue(_tmp_21)) {
                        /* result = result * arr[i] */
                        _offset_51 = _arr_sigIdx_ + Fr_toInt(i)*_sigSizes_arr[1];
                        ctx->multiGetSignal(__cIdx, __cIdx, _offset_51, _sigValue_10, 1);
                        Fr_mul(_tmp_22, result, _sigValue_10);
                        Fr_copyn(result, _tmp_22, 1);
                    }
                }
            }
        }
        Fr_copyn(_tmp_24, i, 1);
        Fr_add(_tmp_23, i, (ctx->circuit->constants + 1));
        Fr_copyn(i, _tmp_23, 1);
        Fr_lt(_tmp_25, i, (ctx->circuit->constants + 7));
        _loopCond = _tmp_25;
    }
    /* log(result) */
    ctx->log(result);
    /* log(((arr[0] + 3) * 5 - 6) * 4) */
    _offset_58 = _arr_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_58, _sigValue_11, 1);
    Fr_add(_tmp_26, _sigValue_11, (ctx->circuit->constants + 5));
    Fr_mul(_tmp_27, _tmp_26, (ctx->circuit->constants + 8));
    Fr_sub(_tmp_28, _tmp_27, (ctx->circuit->constants + 9));
    Fr_mul(_tmp_29, _tmp_28, (ctx->circuit->constants + 10));
    ctx->log(_tmp_29);
    /* assert(result == ((arr[0] + 3) * 5 - 6) * 4) */
    _offset_60 = _arr_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_60, _sigValue_12, 1);
    Fr_add(_tmp_30, _sigValue_12, (ctx->circuit->constants + 5));
    Fr_mul(_tmp_31, _tmp_30, (ctx->circuit->constants + 8));
    Fr_sub(_tmp_32, _tmp_31, (ctx->circuit->constants + 9));
    Fr_mul(_tmp_33, _tmp_32, (ctx->circuit->constants + 10));
    Fr_eq(_tmp_34, result, _tmp_33);
    ctx->checkAssert(__cIdx, _tmp_34, "/Users/chihaolu/Desktop/circom/circuit.circom:46:4");
    /* out <== result */
    ctx->setSignal(__cIdx, __cIdx, _out_sigIdx_, result);
    ctx->finished(__cIdx);
}
// Function Table
Circom_ComponentFunction _functionTable[1] = {
     operation_d6c1bd8047f9cc9b
};
