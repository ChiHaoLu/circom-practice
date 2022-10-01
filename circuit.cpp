#include "circom.hpp"
#include "calcwit.hpp"
#define NSignals 14
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
    FrElement _sigValue_2[1];
    FrElement _tmp_2[1];
    FrElement _sigValue_3[1];
    FrElement _sigValue_4[1];
    FrElement _tmp_3[1];
    FrElement _sigValue_5[1];
    FrElement _tmp_4[1];
    FrElement _sigValue_6[1];
    FrElement _sigValue_7[1];
    FrElement _tmp_5[1];
    FrElement _sigValue_8[1];
    FrElement _tmp_6[1];
    FrElement _sigValue_9[1];
    FrElement _sigValue_10[1];
    FrElement _tmp_7[1];
    FrElement _tmp_10[1];
    FrElement i[1];
    FrElement _tmp_11[1];
    FrElement _sigValue_11[1];
    FrElement _tmp_12[1];
    FrElement _sigValue_12[1];
    FrElement _tmp_13[1];
    FrElement _sigValue_13[1];
    FrElement _tmp_14[1];
    FrElement _sigValue_14[1];
    FrElement _tmp_15[1];
    FrElement _sigValue_15[1];
    FrElement _sigValue_16[1];
    FrElement _tmp_16[1];
    FrElement _sigValue_17[1];
    FrElement _tmp_17[1];
    FrElement _sigValue_18[1];
    FrElement _sigValue_19[1];
    FrElement _tmp_18[1];
    FrElement _sigValue_20[1];
    FrElement _tmp_19[1];
    FrElement _sigValue_21[1];
    FrElement _sigValue_22[1];
    FrElement _tmp_20[1];
    FrElement _tmp_22[1];
    FrElement _tmp_21[1];
    FrElement _tmp_23[1];
    FrElement _sigValue_23[1];
    FrElement _sigValue_24[1];
    FrElement _tmp_24[1];
    FrElement _sigValue_25[1];
    FrElement _tmp_25[1];
    FrElement _sigValue_26[1];
    FrElement _tmp_26[1];
    FrElement _sigValue_27[1];
    FrElement _tmp_27[1];
    FrElement _sigValue_28[1];
    FrElement _sigValue_29[1];
    FrElement _tmp_28[1];
    FrElement _sigValue_30[1];
    FrElement _sigValue_31[1];
    FrElement _sigValue_32[1];
    int _arr_sigIdx_;
    int _offset_1;
    int _result_sigIdx_;
    int _offset_2;
    int _temp_op_sigIdx_;
    int _offset_8;
    int _offset_10;
    int _offset_12;
    int _offset_19;
    int _offset_21;
    int _offset_23;
    int _offset_25;
    int _offset_27;
    int _offset_29;
    int _offset_34;
    int _temp_sigIdx_;
    int _out_sigIdx_;
    Circom_Sizes _sigSizes_arr;
    PFrElement _loopCond;
    Fr_copy(&(_tmp_10[0]), ctx->circuit->constants +1);
    Fr_copy(&(i[0]), ctx->circuit->constants +5);
    _arr_sigIdx_ = ctx->getSignalOffset(__cIdx, 0xe756b1190570b338LL /* arr */);
    _result_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x9b51cd7cd76778c4LL /* result */);
    _temp_op_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x2b77d89c66cc3dcfLL /* temp_op */);
    _temp_sigIdx_ = ctx->getSignalOffset(__cIdx, 0xfa4cf6ef19d2f987LL /* temp */);
    _out_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x19f79b1921bbcfffLL /* out */);
    _sigSizes_arr = ctx->getSignalSizes(__cIdx, 0xe756b1190570b338LL /* arr */);
    /* signal input arr[k] */
    /* signal output out */
    /* signal result <-- arr[0] */
    _offset_1 = _arr_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_1, _sigValue, 1);
    ctx->setSignal(__cIdx, __cIdx, _result_sigIdx_, _sigValue);
    /* signal temp_op <-- arr[1] */
    _offset_2 = _arr_sigIdx_ + 1*_sigSizes_arr[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_2, _sigValue_1, 1);
    ctx->setSignal(__cIdx, __cIdx, _temp_op_sigIdx_, _sigValue_1);
    /* for (var i = 2;i < k;i++) */
    /* if (i % 2) */
    /* if (temp_op == 147) */
    ctx->multiGetSignal(__cIdx, __cIdx, _temp_op_sigIdx_, _sigValue_2, 1);
    Fr_eq(_tmp_2, _sigValue_2, (ctx->circuit->constants + 2));
    if (Fr_isTrue(_tmp_2)) {
        /* result <-- result + arr[i] */
        ctx->multiGetSignal(__cIdx, __cIdx, _result_sigIdx_, _sigValue_3, 1);
        _offset_8 = _arr_sigIdx_ + 2*_sigSizes_arr[1];
        ctx->multiGetSignal(__cIdx, __cIdx, _offset_8, _sigValue_4, 1);
        Fr_add(_tmp_3, _sigValue_3, _sigValue_4);
        ctx->setSignal(__cIdx, __cIdx, _result_sigIdx_, _tmp_3);
    } else {
        /* if (temp_op == 148) */
        ctx->multiGetSignal(__cIdx, __cIdx, _temp_op_sigIdx_, _sigValue_5, 1);
        Fr_eq(_tmp_4, _sigValue_5, (ctx->circuit->constants + 3));
        if (Fr_isTrue(_tmp_4)) {
            /* result <-- result - arr[i] */
            ctx->multiGetSignal(__cIdx, __cIdx, _result_sigIdx_, _sigValue_6, 1);
            _offset_10 = _arr_sigIdx_ + 2*_sigSizes_arr[1];
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_10, _sigValue_7, 1);
            Fr_sub(_tmp_5, _sigValue_6, _sigValue_7);
            ctx->setSignal(__cIdx, __cIdx, _result_sigIdx_, _tmp_5);
        } else {
            /* if (temp_op == 149) */
            ctx->multiGetSignal(__cIdx, __cIdx, _temp_op_sigIdx_, _sigValue_8, 1);
            Fr_eq(_tmp_6, _sigValue_8, (ctx->circuit->constants + 4));
            if (Fr_isTrue(_tmp_6)) {
                /* result <-- result * arr[i] */
                ctx->multiGetSignal(__cIdx, __cIdx, _result_sigIdx_, _sigValue_9, 1);
                _offset_12 = _arr_sigIdx_ + 2*_sigSizes_arr[1];
                ctx->multiGetSignal(__cIdx, __cIdx, _offset_12, _sigValue_10, 1);
                Fr_mul(_tmp_7, _sigValue_9, _sigValue_10);
                ctx->setSignal(__cIdx, __cIdx, _result_sigIdx_, _tmp_7);
            }
        }
    }
    _loopCond = _tmp_10;
    while (Fr_isTrue(_loopCond)) {
        /* if (i % 2) */
        Fr_mod(_tmp_11, i, (ctx->circuit->constants + 6));
        if (Fr_isTrue(_tmp_11)) {
            /* if (arr[i] == 147) */
            _offset_19 = _arr_sigIdx_ + Fr_toInt(i)*_sigSizes_arr[1];
            ctx->multiGetSignal(__cIdx, __cIdx, _offset_19, _sigValue_11, 1);
            Fr_eq(_tmp_12, _sigValue_11, (ctx->circuit->constants + 2));
            if (Fr_isTrue(_tmp_12)) {
                /* temp_op <-- 147 */
                ctx->setSignal(__cIdx, __cIdx, _temp_op_sigIdx_, (ctx->circuit->constants + 2));
            } else {
                /* if (arr[i] == 148) */
                _offset_21 = _arr_sigIdx_ + Fr_toInt(i)*_sigSizes_arr[1];
                ctx->multiGetSignal(__cIdx, __cIdx, _offset_21, _sigValue_12, 1);
                Fr_eq(_tmp_13, _sigValue_12, (ctx->circuit->constants + 3));
                if (Fr_isTrue(_tmp_13)) {
                    /* temp_op <-- 148 */
                    ctx->setSignal(__cIdx, __cIdx, _temp_op_sigIdx_, (ctx->circuit->constants + 3));
                } else {
                    /* if (arr[i] == 149) */
                    _offset_23 = _arr_sigIdx_ + Fr_toInt(i)*_sigSizes_arr[1];
                    ctx->multiGetSignal(__cIdx, __cIdx, _offset_23, _sigValue_13, 1);
                    Fr_eq(_tmp_14, _sigValue_13, (ctx->circuit->constants + 4));
                    if (Fr_isTrue(_tmp_14)) {
                        /* temp_op <-- 149 */
                        ctx->setSignal(__cIdx, __cIdx, _temp_op_sigIdx_, (ctx->circuit->constants + 4));
                    }
                }
            }
        } else {
            /* if (temp_op == 147) */
            ctx->multiGetSignal(__cIdx, __cIdx, _temp_op_sigIdx_, _sigValue_14, 1);
            Fr_eq(_tmp_15, _sigValue_14, (ctx->circuit->constants + 2));
            if (Fr_isTrue(_tmp_15)) {
                /* result <-- result + arr[i] */
                ctx->multiGetSignal(__cIdx, __cIdx, _result_sigIdx_, _sigValue_15, 1);
                _offset_25 = _arr_sigIdx_ + Fr_toInt(i)*_sigSizes_arr[1];
                ctx->multiGetSignal(__cIdx, __cIdx, _offset_25, _sigValue_16, 1);
                Fr_add(_tmp_16, _sigValue_15, _sigValue_16);
                ctx->setSignal(__cIdx, __cIdx, _result_sigIdx_, _tmp_16);
            } else {
                /* if (temp_op == 148) */
                ctx->multiGetSignal(__cIdx, __cIdx, _temp_op_sigIdx_, _sigValue_17, 1);
                Fr_eq(_tmp_17, _sigValue_17, (ctx->circuit->constants + 3));
                if (Fr_isTrue(_tmp_17)) {
                    /* result <-- result - arr[i] */
                    ctx->multiGetSignal(__cIdx, __cIdx, _result_sigIdx_, _sigValue_18, 1);
                    _offset_27 = _arr_sigIdx_ + Fr_toInt(i)*_sigSizes_arr[1];
                    ctx->multiGetSignal(__cIdx, __cIdx, _offset_27, _sigValue_19, 1);
                    Fr_sub(_tmp_18, _sigValue_18, _sigValue_19);
                    ctx->setSignal(__cIdx, __cIdx, _result_sigIdx_, _tmp_18);
                } else {
                    /* if (temp_op == 149) */
                    ctx->multiGetSignal(__cIdx, __cIdx, _temp_op_sigIdx_, _sigValue_20, 1);
                    Fr_eq(_tmp_19, _sigValue_20, (ctx->circuit->constants + 4));
                    if (Fr_isTrue(_tmp_19)) {
                        /* result <-- result * arr[i] */
                        ctx->multiGetSignal(__cIdx, __cIdx, _result_sigIdx_, _sigValue_21, 1);
                        _offset_29 = _arr_sigIdx_ + Fr_toInt(i)*_sigSizes_arr[1];
                        ctx->multiGetSignal(__cIdx, __cIdx, _offset_29, _sigValue_22, 1);
                        Fr_mul(_tmp_20, _sigValue_21, _sigValue_22);
                        ctx->setSignal(__cIdx, __cIdx, _result_sigIdx_, _tmp_20);
                    }
                }
            }
        }
        Fr_copyn(_tmp_22, i, 1);
        Fr_add(_tmp_21, i, (ctx->circuit->constants + 1));
        Fr_copyn(i, _tmp_21, 1);
        Fr_lt(_tmp_23, i, (ctx->circuit->constants + 7));
        _loopCond = _tmp_23;
    }
    /* signal temp <== arr[0] */
    _offset_34 = _arr_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_34, _sigValue_23, 1);
    ctx->setSignal(__cIdx, __cIdx, _temp_sigIdx_, _sigValue_23);
    /* temp <== temp + 3 */
    ctx->multiGetSignal(__cIdx, __cIdx, _temp_sigIdx_, _sigValue_24, 1);
    Fr_add(_tmp_24, _sigValue_24, (ctx->circuit->constants + 5));
    ctx->setSignal(__cIdx, __cIdx, _temp_sigIdx_, _tmp_24);
    /* temp <== temp * 5 */
    ctx->multiGetSignal(__cIdx, __cIdx, _temp_sigIdx_, _sigValue_25, 1);
    Fr_mul(_tmp_25, _sigValue_25, (ctx->circuit->constants + 8));
    ctx->setSignal(__cIdx, __cIdx, _temp_sigIdx_, _tmp_25);
    /* temp <== temp - 6 */
    ctx->multiGetSignal(__cIdx, __cIdx, _temp_sigIdx_, _sigValue_26, 1);
    Fr_sub(_tmp_26, _sigValue_26, (ctx->circuit->constants + 9));
    ctx->setSignal(__cIdx, __cIdx, _temp_sigIdx_, _tmp_26);
    /* temp <== temp * 4 */
    ctx->multiGetSignal(__cIdx, __cIdx, _temp_sigIdx_, _sigValue_27, 1);
    Fr_mul(_tmp_27, _sigValue_27, (ctx->circuit->constants + 10));
    ctx->setSignal(__cIdx, __cIdx, _temp_sigIdx_, _tmp_27);
    /* log(result - temp) */
    ctx->multiGetSignal(__cIdx, __cIdx, _result_sigIdx_, _sigValue_28, 1);
    ctx->multiGetSignal(__cIdx, __cIdx, _temp_sigIdx_, _sigValue_29, 1);
    Fr_sub(_tmp_28, _sigValue_28, _sigValue_29);
    ctx->log(_tmp_28);
    /* result === temp */
    ctx->multiGetSignal(__cIdx, __cIdx, _result_sigIdx_, _sigValue_30, 1);
    ctx->multiGetSignal(__cIdx, __cIdx, _temp_sigIdx_, _sigValue_31, 1);
    ctx->checkConstraint(__cIdx, _sigValue_30, _sigValue_31, "/Users/chihaolu/Desktop/circom/circuit.circom:54:4");
    /* out <== result */
    ctx->multiGetSignal(__cIdx, __cIdx, _result_sigIdx_, _sigValue_32, 1);
    ctx->setSignal(__cIdx, __cIdx, _out_sigIdx_, _sigValue_32);
    ctx->finished(__cIdx);
}
// Function Table
Circom_ComponentFunction _functionTable[1] = {
     operation_d6c1bd8047f9cc9b
};
