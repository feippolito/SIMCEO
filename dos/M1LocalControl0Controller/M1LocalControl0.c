/*
 * File: M1LocalControl0.c
 *
 * Code generated for Simulink model 'M1LocalControl0'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Fri Jan 24 15:35:58 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1LocalControl0.h"
#include "M1LocalControl0_private.h"

/* Block states (default storage) */
DW_M1LocalControl0_T M1LocalControl0_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M1LocalControl0_T M1LocalControl0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1LocalControl0_T M1LocalControl0_Y;

/* Real-time model */
RT_MODEL_M1LocalControl0_T M1LocalControl0_M_;
RT_MODEL_M1LocalControl0_T *const M1LocalControl0_M = &M1LocalControl0_M_;

/* Model step function */
void M1LocalControl0_step(void)
{
  real_T numAccum;
  int32_T j;
  int32_T denIdx;
  real_T numAccum_0;
  int32_T denIdx_0;
  real_T rtb_Forcebalance[335];
  real_T rtb_Forcebalance_p[335];
  real_T rtb_Forcebalance_l[335];
  real_T rtb_Forcebalance_j[335];
  real_T rtb_Forcebalance_b[335];
  real_T rtb_Forcebalance_i1[335];
  real_T MHP[6];
  real_T MHP_d[6];
  real_T MHP_k[6];
  real_T MHP_dr[6];
  real_T MHP_f[6];
  real_T MHP_m[6];
  real_T MHP_c[6];
  real_T rtb_MzController_0[6];
  real_T tmp[306];

  /* DiscreteTransferFcn: '<S2>/Mx Controller' */
  numAccum = 0.0;
  denIdx = 1;

  /* DiscreteTransferFcn: '<S2>/My Controller' */
  numAccum_0 = 0.0;
  denIdx_0 = 1;
  for (j = 0; j < 5; j++) {
    /* DiscreteTransferFcn: '<S2>/Mx Controller' */
    numAccum += M1LocalControl0_ConstP.pooled6[denIdx] *
      M1LocalControl0_DW.MxController_states[j];
    denIdx++;

    /* DiscreteTransferFcn: '<S2>/My Controller' */
    numAccum_0 += M1LocalControl0_ConstP.pooled6[denIdx_0] *
      M1LocalControl0_DW.MyController_states[j];
    denIdx_0++;
  }

  /* SignalConversion: '<S2>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S2>/Fx Controller'
   *  DiscreteTransferFcn: '<S2>/Fy Controller'
   *  DiscreteTransferFcn: '<S2>/Fz Controller'
   *  DiscreteTransferFcn: '<S2>/Mx Controller'
   *  DiscreteTransferFcn: '<S2>/My Controller'
   *  DiscreteTransferFcn: '<S2>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1LocalControl0_DW.FxController_states[0] + -0.0062083257567339973 *
    M1LocalControl0_DW.FxController_states[1]) + 0.0031046389635168946 *
    M1LocalControl0_DW.FxController_states[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1LocalControl0_DW.FyController_states[0] + -0.0062083257567339973 *
    M1LocalControl0_DW.FyController_states[1]) + 0.0031046389635168946 *
    M1LocalControl0_DW.FyController_states[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1LocalControl0_DW.FzController_states[0] + -0.0067736068594331216 *
    M1LocalControl0_DW.FzController_states[1]) + 0.0033881700821686029 *
    M1LocalControl0_DW.FzController_states[2];
  rtb_MzController_0[3] = numAccum;
  rtb_MzController_0[4] = numAccum_0;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1LocalControl0_DW.MzController_states[0] + -0.0068430176624178825 *
    M1LocalControl0_DW.MzController_states[1]) + 0.0034246827558012866 *
    M1LocalControl0_DW.MzController_states[2];

  /* Gain: '<S2>/Force balance' */
  for (j = 0; j < 335; j++) {
    rtb_Forcebalance[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      rtb_Forcebalance[j] += M1LocalControl0_ConstP.pooled10[335 * denIdx + j] *
        rtb_MzController_0[denIdx];
    }
  }

  /* End of Gain: '<S2>/Force balance' */

  /* DiscreteTransferFcn: '<S3>/Mx Controller' */
  numAccum = 0.0;
  denIdx = 1;

  /* DiscreteTransferFcn: '<S3>/My Controller' */
  numAccum_0 = 0.0;
  denIdx_0 = 1;
  for (j = 0; j < 5; j++) {
    /* DiscreteTransferFcn: '<S3>/Mx Controller' */
    numAccum += M1LocalControl0_ConstP.pooled6[denIdx] *
      M1LocalControl0_DW.MxController_states_c[j];
    denIdx++;

    /* DiscreteTransferFcn: '<S3>/My Controller' */
    numAccum_0 += M1LocalControl0_ConstP.pooled6[denIdx_0] *
      M1LocalControl0_DW.MyController_states_i[j];
    denIdx_0++;
  }

  /* SignalConversion: '<S3>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S3>/Fx Controller'
   *  DiscreteTransferFcn: '<S3>/Fy Controller'
   *  DiscreteTransferFcn: '<S3>/Fz Controller'
   *  DiscreteTransferFcn: '<S3>/Mx Controller'
   *  DiscreteTransferFcn: '<S3>/My Controller'
   *  DiscreteTransferFcn: '<S3>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1LocalControl0_DW.FxController_states_f[0] + -0.0062083257567339973 *
    M1LocalControl0_DW.FxController_states_f[1]) + 0.0031046389635168946 *
    M1LocalControl0_DW.FxController_states_f[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1LocalControl0_DW.FyController_states_p[0] + -0.0062083257567339973 *
    M1LocalControl0_DW.FyController_states_p[1]) + 0.0031046389635168946 *
    M1LocalControl0_DW.FyController_states_p[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1LocalControl0_DW.FzController_states_a[0] + -0.0067736068594331216 *
    M1LocalControl0_DW.FzController_states_a[1]) + 0.0033881700821686029 *
    M1LocalControl0_DW.FzController_states_a[2];
  rtb_MzController_0[3] = numAccum;
  rtb_MzController_0[4] = numAccum_0;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1LocalControl0_DW.MzController_states_e[0] + -0.0068430176624178825 *
    M1LocalControl0_DW.MzController_states_e[1]) + 0.0034246827558012866 *
    M1LocalControl0_DW.MzController_states_e[2];

  /* Gain: '<S3>/Force balance' */
  for (j = 0; j < 335; j++) {
    rtb_Forcebalance_p[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      rtb_Forcebalance_p[j] += M1LocalControl0_ConstP.pooled10[335 * denIdx + j]
        * rtb_MzController_0[denIdx];
    }
  }

  /* End of Gain: '<S3>/Force balance' */

  /* DiscreteTransferFcn: '<S4>/Mx Controller' */
  numAccum = 0.0;
  denIdx = 1;

  /* DiscreteTransferFcn: '<S4>/My Controller' */
  numAccum_0 = 0.0;
  denIdx_0 = 1;
  for (j = 0; j < 5; j++) {
    /* DiscreteTransferFcn: '<S4>/Mx Controller' */
    numAccum += M1LocalControl0_ConstP.pooled6[denIdx] *
      M1LocalControl0_DW.MxController_states_d[j];
    denIdx++;

    /* DiscreteTransferFcn: '<S4>/My Controller' */
    numAccum_0 += M1LocalControl0_ConstP.pooled6[denIdx_0] *
      M1LocalControl0_DW.MyController_states_n[j];
    denIdx_0++;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S4>/Fx Controller'
   *  DiscreteTransferFcn: '<S4>/Fy Controller'
   *  DiscreteTransferFcn: '<S4>/Fz Controller'
   *  DiscreteTransferFcn: '<S4>/Mx Controller'
   *  DiscreteTransferFcn: '<S4>/My Controller'
   *  DiscreteTransferFcn: '<S4>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1LocalControl0_DW.FxController_states_j[0] + -0.0062083257567339973 *
    M1LocalControl0_DW.FxController_states_j[1]) + 0.0031046389635168946 *
    M1LocalControl0_DW.FxController_states_j[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1LocalControl0_DW.FyController_states_d[0] + -0.0062083257567339973 *
    M1LocalControl0_DW.FyController_states_d[1]) + 0.0031046389635168946 *
    M1LocalControl0_DW.FyController_states_d[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1LocalControl0_DW.FzController_states_ac[0] + -0.0067736068594331216 *
    M1LocalControl0_DW.FzController_states_ac[1]) + 0.0033881700821686029 *
    M1LocalControl0_DW.FzController_states_ac[2];
  rtb_MzController_0[3] = numAccum;
  rtb_MzController_0[4] = numAccum_0;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1LocalControl0_DW.MzController_states_n[0] + -0.0068430176624178825 *
    M1LocalControl0_DW.MzController_states_n[1]) + 0.0034246827558012866 *
    M1LocalControl0_DW.MzController_states_n[2];

  /* Gain: '<S4>/Force balance' */
  for (j = 0; j < 335; j++) {
    rtb_Forcebalance_l[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      rtb_Forcebalance_l[j] += M1LocalControl0_ConstP.pooled10[335 * denIdx + j]
        * rtb_MzController_0[denIdx];
    }
  }

  /* End of Gain: '<S4>/Force balance' */

  /* DiscreteTransferFcn: '<S5>/Mx Controller' */
  numAccum = 0.0;
  denIdx = 1;

  /* DiscreteTransferFcn: '<S5>/My Controller' */
  numAccum_0 = 0.0;
  denIdx_0 = 1;
  for (j = 0; j < 5; j++) {
    /* DiscreteTransferFcn: '<S5>/Mx Controller' */
    numAccum += M1LocalControl0_ConstP.pooled6[denIdx] *
      M1LocalControl0_DW.MxController_states_f[j];
    denIdx++;

    /* DiscreteTransferFcn: '<S5>/My Controller' */
    numAccum_0 += M1LocalControl0_ConstP.pooled6[denIdx_0] *
      M1LocalControl0_DW.MyController_states_g[j];
    denIdx_0++;
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S5>/Fx Controller'
   *  DiscreteTransferFcn: '<S5>/Fy Controller'
   *  DiscreteTransferFcn: '<S5>/Fz Controller'
   *  DiscreteTransferFcn: '<S5>/Mx Controller'
   *  DiscreteTransferFcn: '<S5>/My Controller'
   *  DiscreteTransferFcn: '<S5>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1LocalControl0_DW.FxController_states_n[0] + -0.0062083257567339973 *
    M1LocalControl0_DW.FxController_states_n[1]) + 0.0031046389635168946 *
    M1LocalControl0_DW.FxController_states_n[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1LocalControl0_DW.FyController_states_e[0] + -0.0062083257567339973 *
    M1LocalControl0_DW.FyController_states_e[1]) + 0.0031046389635168946 *
    M1LocalControl0_DW.FyController_states_e[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1LocalControl0_DW.FzController_states_c[0] + -0.0067736068594331216 *
    M1LocalControl0_DW.FzController_states_c[1]) + 0.0033881700821686029 *
    M1LocalControl0_DW.FzController_states_c[2];
  rtb_MzController_0[3] = numAccum;
  rtb_MzController_0[4] = numAccum_0;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1LocalControl0_DW.MzController_states_h[0] + -0.0068430176624178825 *
    M1LocalControl0_DW.MzController_states_h[1]) + 0.0034246827558012866 *
    M1LocalControl0_DW.MzController_states_h[2];

  /* Gain: '<S5>/Force balance' */
  for (j = 0; j < 335; j++) {
    rtb_Forcebalance_j[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      rtb_Forcebalance_j[j] += M1LocalControl0_ConstP.pooled10[335 * denIdx + j]
        * rtb_MzController_0[denIdx];
    }
  }

  /* End of Gain: '<S5>/Force balance' */

  /* DiscreteTransferFcn: '<S6>/Mx Controller' */
  numAccum = 0.0;
  denIdx = 1;

  /* DiscreteTransferFcn: '<S6>/My Controller' */
  numAccum_0 = 0.0;
  denIdx_0 = 1;
  for (j = 0; j < 5; j++) {
    /* DiscreteTransferFcn: '<S6>/Mx Controller' */
    numAccum += M1LocalControl0_ConstP.pooled6[denIdx] *
      M1LocalControl0_DW.MxController_states_k[j];
    denIdx++;

    /* DiscreteTransferFcn: '<S6>/My Controller' */
    numAccum_0 += M1LocalControl0_ConstP.pooled6[denIdx_0] *
      M1LocalControl0_DW.MyController_states_k[j];
    denIdx_0++;
  }

  /* SignalConversion: '<S6>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S6>/Fx Controller'
   *  DiscreteTransferFcn: '<S6>/Fy Controller'
   *  DiscreteTransferFcn: '<S6>/Fz Controller'
   *  DiscreteTransferFcn: '<S6>/Mx Controller'
   *  DiscreteTransferFcn: '<S6>/My Controller'
   *  DiscreteTransferFcn: '<S6>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1LocalControl0_DW.FxController_states_o[0] + -0.0062083257567339973 *
    M1LocalControl0_DW.FxController_states_o[1]) + 0.0031046389635168946 *
    M1LocalControl0_DW.FxController_states_o[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1LocalControl0_DW.FyController_states_n[0] + -0.0062083257567339973 *
    M1LocalControl0_DW.FyController_states_n[1]) + 0.0031046389635168946 *
    M1LocalControl0_DW.FyController_states_n[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1LocalControl0_DW.FzController_states_k[0] + -0.0067736068594331216 *
    M1LocalControl0_DW.FzController_states_k[1]) + 0.0033881700821686029 *
    M1LocalControl0_DW.FzController_states_k[2];
  rtb_MzController_0[3] = numAccum;
  rtb_MzController_0[4] = numAccum_0;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1LocalControl0_DW.MzController_states_i[0] + -0.0068430176624178825 *
    M1LocalControl0_DW.MzController_states_i[1]) + 0.0034246827558012866 *
    M1LocalControl0_DW.MzController_states_i[2];

  /* Gain: '<S6>/Force balance' */
  for (j = 0; j < 335; j++) {
    rtb_Forcebalance_b[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      rtb_Forcebalance_b[j] += M1LocalControl0_ConstP.pooled10[335 * denIdx + j]
        * rtb_MzController_0[denIdx];
    }
  }

  /* End of Gain: '<S6>/Force balance' */

  /* DiscreteTransferFcn: '<S7>/Mx Controller' */
  numAccum = 0.0;
  denIdx = 1;

  /* DiscreteTransferFcn: '<S7>/My Controller' */
  numAccum_0 = 0.0;
  denIdx_0 = 1;
  for (j = 0; j < 5; j++) {
    /* DiscreteTransferFcn: '<S7>/Mx Controller' */
    numAccum += M1LocalControl0_ConstP.pooled6[denIdx] *
      M1LocalControl0_DW.MxController_states_m[j];
    denIdx++;

    /* DiscreteTransferFcn: '<S7>/My Controller' */
    numAccum_0 += M1LocalControl0_ConstP.pooled6[denIdx_0] *
      M1LocalControl0_DW.MyController_states_d[j];
    denIdx_0++;
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S7>/Fx Controller'
   *  DiscreteTransferFcn: '<S7>/Fy Controller'
   *  DiscreteTransferFcn: '<S7>/Fz Controller'
   *  DiscreteTransferFcn: '<S7>/Mx Controller'
   *  DiscreteTransferFcn: '<S7>/My Controller'
   *  DiscreteTransferFcn: '<S7>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1LocalControl0_DW.FxController_states_b[0] + -0.0062083257567339973 *
    M1LocalControl0_DW.FxController_states_b[1]) + 0.0031046389635168946 *
    M1LocalControl0_DW.FxController_states_b[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1LocalControl0_DW.FyController_states_c[0] + -0.0062083257567339973 *
    M1LocalControl0_DW.FyController_states_c[1]) + 0.0031046389635168946 *
    M1LocalControl0_DW.FyController_states_c[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1LocalControl0_DW.FzController_states_l[0] + -0.0067736068594331216 *
    M1LocalControl0_DW.FzController_states_l[1]) + 0.0033881700821686029 *
    M1LocalControl0_DW.FzController_states_l[2];
  rtb_MzController_0[3] = numAccum;
  rtb_MzController_0[4] = numAccum_0;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1LocalControl0_DW.MzController_states_o[0] + -0.0068430176624178825 *
    M1LocalControl0_DW.MzController_states_o[1]) + 0.0034246827558012866 *
    M1LocalControl0_DW.MzController_states_o[2];

  /* Gain: '<S7>/Force balance' */
  for (j = 0; j < 335; j++) {
    rtb_Forcebalance_i1[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      rtb_Forcebalance_i1[j] += M1LocalControl0_ConstP.pooled10[335 * denIdx + j]
        * rtb_MzController_0[denIdx];
    }
  }

  /* End of Gain: '<S7>/Force balance' */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S8>/Fx Controller'
   *  DiscreteTransferFcn: '<S8>/Fy Controller'
   *  DiscreteTransferFcn: '<S8>/Fz Controller'
   *  DiscreteTransferFcn: '<S8>/Mx Controller'
   *  DiscreteTransferFcn: '<S8>/My Controller'
   *  DiscreteTransferFcn: '<S8>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0027629307658847734 *
    M1LocalControl0_DW.FxController_states_fe[0] + -0.0055185117837635517 *
    M1LocalControl0_DW.FxController_states_fe[1]) + 0.0027590287412410657 *
    M1LocalControl0_DW.FxController_states_fe[2];
  rtb_MzController_0[1] = (1.6875923962320881E-7 *
    M1LocalControl0_DW.FyController_states_h[0] + 3.3751847924641762E-7 *
    M1LocalControl0_DW.FyController_states_h[1]) + 1.6875923962320881E-7 *
    M1LocalControl0_DW.FyController_states_h[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1LocalControl0_DW.FzController_states_j[0] + -0.0067736068594331216 *
    M1LocalControl0_DW.FzController_states_j[1]) + 0.0033881700821686029 *
    M1LocalControl0_DW.FzController_states_j[2];
  rtb_MzController_0[3] = (1.6875923962320881E-7 *
    M1LocalControl0_DW.MxController_states_cu[0] + 3.3751847924641762E-7 *
    M1LocalControl0_DW.MxController_states_cu[1]) + 1.6875923962320881E-7 *
    M1LocalControl0_DW.MxController_states_cu[2];
  rtb_MzController_0[4] = (1.6875923962320881E-7 *
    M1LocalControl0_DW.MyController_states_a[0] + 3.3751847924641762E-7 *
    M1LocalControl0_DW.MyController_states_a[1]) + 1.6875923962320881E-7 *
    M1LocalControl0_DW.MyController_states_a[2];
  rtb_MzController_0[5] = (1.6875923962320881E-7 *
    M1LocalControl0_DW.MzController_states_a[0] + 3.3751847924641762E-7 *
    M1LocalControl0_DW.MzController_states_a[1]) + 1.6875923962320881E-7 *
    M1LocalControl0_DW.MzController_states_a[2];

  /* Gain: '<S8>/Force balance' incorporates:
   *  Outport: '<Root>/Output'
   */
  for (j = 0; j < 306; j++) {
    tmp[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      tmp[j] += M1LocalControl0_ConstP.Forcebalance_Gain[306 * denIdx + j] *
        rtb_MzController_0[denIdx];
    }
  }

  /* End of Gain: '<S8>/Force balance' */

  /* Outport: '<Root>/Output' */
  for (j = 0; j < 335; j++) {
    M1LocalControl0_Y.Output[j] = rtb_Forcebalance[j];
    M1LocalControl0_Y.Output[j + 335] = rtb_Forcebalance_p[j];
    M1LocalControl0_Y.Output[j + 670] = rtb_Forcebalance_l[j];
    M1LocalControl0_Y.Output[j + 1005] = rtb_Forcebalance_j[j];
    M1LocalControl0_Y.Output[j + 1340] = rtb_Forcebalance_b[j];
    M1LocalControl0_Y.Output[j + 1675] = rtb_Forcebalance_i1[j];
  }

  memcpy(&M1LocalControl0_Y.Output[2010], &tmp[0], 306U * sizeof(real_T));
  for (j = 0; j < 6; j++) {
    /* Gain: '<S2>/MHP' */
    MHP[j] = 0.0;

    /* Gain: '<S3>/MHP' */
    MHP_d[j] = 0.0;

    /* Gain: '<S4>/MHP' */
    MHP_k[j] = 0.0;

    /* Gain: '<S5>/MHP' */
    MHP_dr[j] = 0.0;

    /* Gain: '<S6>/MHP' */
    MHP_f[j] = 0.0;

    /* Gain: '<S7>/MHP' */
    MHP_m[j] = 0.0;

    /* Gain: '<S8>/MHP' */
    MHP_c[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      /* Gain: '<S2>/MHP' incorporates:
       *  Gain: '<S3>/MHP'
       *  Gain: '<S4>/MHP'
       *  Gain: '<S5>/MHP'
       *  Gain: '<S6>/MHP'
       *  Gain: '<S7>/MHP'
       *  Gain: '<S8>/MHP'
       *  Inport: '<Root>/Feedback'
       */
      denIdx_0 = 6 * denIdx + j;
      MHP[j] += M1LocalControl0_ConstP.MHP_Gain[denIdx_0] *
        M1LocalControl0_U.Feedback[denIdx];

      /* Gain: '<S3>/MHP' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      MHP_d[j] += M1LocalControl0_ConstP.MHP_Gain_i[denIdx_0] *
        M1LocalControl0_U.Feedback[6 + denIdx];

      /* Gain: '<S4>/MHP' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      MHP_k[j] += M1LocalControl0_ConstP.MHP_Gain_c[denIdx_0] *
        M1LocalControl0_U.Feedback[12 + denIdx];

      /* Gain: '<S5>/MHP' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      MHP_dr[j] += M1LocalControl0_ConstP.MHP_Gain_j[denIdx_0] *
        M1LocalControl0_U.Feedback[18 + denIdx];

      /* Gain: '<S6>/MHP' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      MHP_f[j] += M1LocalControl0_ConstP.MHP_Gain_ii[denIdx_0] *
        M1LocalControl0_U.Feedback[24 + denIdx];

      /* Gain: '<S7>/MHP' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      MHP_m[j] += M1LocalControl0_ConstP.MHP_Gain_p[denIdx_0] *
        M1LocalControl0_U.Feedback[30 + denIdx];

      /* Gain: '<S8>/MHP' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      MHP_c[j] += M1LocalControl0_ConstP.MHP_Gain_k[denIdx_0] *
        M1LocalControl0_U.Feedback[36 + denIdx];
    }
  }

  /* Update for DiscreteTransferFcn: '<S2>/Fx Controller' */
  numAccum = ((MHP[0] - -2.97089706562984 *
               M1LocalControl0_DW.FxController_states[0]) - 2.9430254610319251 *
              M1LocalControl0_DW.FxController_states[1]) - -0.9721283954020854 *
    M1LocalControl0_DW.FxController_states[2];
  M1LocalControl0_DW.FxController_states[2] =
    M1LocalControl0_DW.FxController_states[1];
  M1LocalControl0_DW.FxController_states[1] =
    M1LocalControl0_DW.FxController_states[0];
  M1LocalControl0_DW.FxController_states[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S2>/Fy Controller' */
  numAccum = ((MHP[1] - -2.97089706562984 *
               M1LocalControl0_DW.FyController_states[0]) - 2.9430254610319251 *
              M1LocalControl0_DW.FyController_states[1]) - -0.9721283954020854 *
    M1LocalControl0_DW.FyController_states[2];
  M1LocalControl0_DW.FyController_states[2] =
    M1LocalControl0_DW.FyController_states[1];
  M1LocalControl0_DW.FyController_states[1] =
    M1LocalControl0_DW.FyController_states[0];
  M1LocalControl0_DW.FyController_states[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S2>/Fz Controller' */
  numAccum = ((MHP[2] - -2.935316245552321 *
               M1LocalControl0_DW.FzController_states[0]) - 2.8744564263243495 *
              M1LocalControl0_DW.FzController_states[1]) - -0.93914018077202877 *
    M1LocalControl0_DW.FzController_states[2];
  M1LocalControl0_DW.FzController_states[2] =
    M1LocalControl0_DW.FzController_states[1];
  M1LocalControl0_DW.FzController_states[1] =
    M1LocalControl0_DW.FzController_states[0];
  M1LocalControl0_DW.FzController_states[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S2>/Mx Controller' */
  numAccum = MHP[3];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl0_ConstP.pooled7[denIdx] *
      M1LocalControl0_DW.MxController_states[j];
    denIdx++;
  }

  M1LocalControl0_DW.MxController_states[4] =
    M1LocalControl0_DW.MxController_states[3];
  M1LocalControl0_DW.MxController_states[3] =
    M1LocalControl0_DW.MxController_states[2];
  M1LocalControl0_DW.MxController_states[2] =
    M1LocalControl0_DW.MxController_states[1];
  M1LocalControl0_DW.MxController_states[1] =
    M1LocalControl0_DW.MxController_states[0];
  M1LocalControl0_DW.MxController_states[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S2>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S2>/My Controller' */
  numAccum = MHP[4];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl0_ConstP.pooled7[denIdx] *
      M1LocalControl0_DW.MyController_states[j];
    denIdx++;
  }

  M1LocalControl0_DW.MyController_states[4] =
    M1LocalControl0_DW.MyController_states[3];
  M1LocalControl0_DW.MyController_states[3] =
    M1LocalControl0_DW.MyController_states[2];
  M1LocalControl0_DW.MyController_states[2] =
    M1LocalControl0_DW.MyController_states[1];
  M1LocalControl0_DW.MyController_states[1] =
    M1LocalControl0_DW.MyController_states[0];
  M1LocalControl0_DW.MyController_states[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S2>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S2>/Mz Controller' */
  numAccum = ((MHP[5] - -2.9551479035479664 *
               M1LocalControl0_DW.MzController_states[0]) - 2.9141589271132933 *
              M1LocalControl0_DW.MzController_states[1]) - -0.95901102356532664 *
    M1LocalControl0_DW.MzController_states[2];
  M1LocalControl0_DW.MzController_states[2] =
    M1LocalControl0_DW.MzController_states[1];
  M1LocalControl0_DW.MzController_states[1] =
    M1LocalControl0_DW.MzController_states[0];
  M1LocalControl0_DW.MzController_states[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S3>/Fx Controller' */
  numAccum = ((MHP_d[0] - -2.97089706562984 *
               M1LocalControl0_DW.FxController_states_f[0]) - 2.9430254610319251
              * M1LocalControl0_DW.FxController_states_f[1]) -
    -0.9721283954020854 * M1LocalControl0_DW.FxController_states_f[2];
  M1LocalControl0_DW.FxController_states_f[2] =
    M1LocalControl0_DW.FxController_states_f[1];
  M1LocalControl0_DW.FxController_states_f[1] =
    M1LocalControl0_DW.FxController_states_f[0];
  M1LocalControl0_DW.FxController_states_f[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S3>/Fy Controller' */
  numAccum = ((MHP_d[1] - -2.97089706562984 *
               M1LocalControl0_DW.FyController_states_p[0]) - 2.9430254610319251
              * M1LocalControl0_DW.FyController_states_p[1]) -
    -0.9721283954020854 * M1LocalControl0_DW.FyController_states_p[2];
  M1LocalControl0_DW.FyController_states_p[2] =
    M1LocalControl0_DW.FyController_states_p[1];
  M1LocalControl0_DW.FyController_states_p[1] =
    M1LocalControl0_DW.FyController_states_p[0];
  M1LocalControl0_DW.FyController_states_p[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S3>/Fz Controller' */
  numAccum = ((MHP_d[2] - -2.935316245552321 *
               M1LocalControl0_DW.FzController_states_a[0]) - 2.8744564263243495
              * M1LocalControl0_DW.FzController_states_a[1]) -
    -0.93914018077202877 * M1LocalControl0_DW.FzController_states_a[2];
  M1LocalControl0_DW.FzController_states_a[2] =
    M1LocalControl0_DW.FzController_states_a[1];
  M1LocalControl0_DW.FzController_states_a[1] =
    M1LocalControl0_DW.FzController_states_a[0];
  M1LocalControl0_DW.FzController_states_a[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S3>/Mx Controller' */
  numAccum = MHP_d[3];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl0_ConstP.pooled7[denIdx] *
      M1LocalControl0_DW.MxController_states_c[j];
    denIdx++;
  }

  M1LocalControl0_DW.MxController_states_c[4] =
    M1LocalControl0_DW.MxController_states_c[3];
  M1LocalControl0_DW.MxController_states_c[3] =
    M1LocalControl0_DW.MxController_states_c[2];
  M1LocalControl0_DW.MxController_states_c[2] =
    M1LocalControl0_DW.MxController_states_c[1];
  M1LocalControl0_DW.MxController_states_c[1] =
    M1LocalControl0_DW.MxController_states_c[0];
  M1LocalControl0_DW.MxController_states_c[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S3>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S3>/My Controller' */
  numAccum = MHP_d[4];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl0_ConstP.pooled7[denIdx] *
      M1LocalControl0_DW.MyController_states_i[j];
    denIdx++;
  }

  M1LocalControl0_DW.MyController_states_i[4] =
    M1LocalControl0_DW.MyController_states_i[3];
  M1LocalControl0_DW.MyController_states_i[3] =
    M1LocalControl0_DW.MyController_states_i[2];
  M1LocalControl0_DW.MyController_states_i[2] =
    M1LocalControl0_DW.MyController_states_i[1];
  M1LocalControl0_DW.MyController_states_i[1] =
    M1LocalControl0_DW.MyController_states_i[0];
  M1LocalControl0_DW.MyController_states_i[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S3>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S3>/Mz Controller' */
  numAccum = ((MHP_d[5] - -2.9551479035479664 *
               M1LocalControl0_DW.MzController_states_e[0]) - 2.9141589271132933
              * M1LocalControl0_DW.MzController_states_e[1]) -
    -0.95901102356532664 * M1LocalControl0_DW.MzController_states_e[2];
  M1LocalControl0_DW.MzController_states_e[2] =
    M1LocalControl0_DW.MzController_states_e[1];
  M1LocalControl0_DW.MzController_states_e[1] =
    M1LocalControl0_DW.MzController_states_e[0];
  M1LocalControl0_DW.MzController_states_e[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S4>/Fx Controller' */
  numAccum = ((MHP_k[0] - -2.97089706562984 *
               M1LocalControl0_DW.FxController_states_j[0]) - 2.9430254610319251
              * M1LocalControl0_DW.FxController_states_j[1]) -
    -0.9721283954020854 * M1LocalControl0_DW.FxController_states_j[2];
  M1LocalControl0_DW.FxController_states_j[2] =
    M1LocalControl0_DW.FxController_states_j[1];
  M1LocalControl0_DW.FxController_states_j[1] =
    M1LocalControl0_DW.FxController_states_j[0];
  M1LocalControl0_DW.FxController_states_j[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S4>/Fy Controller' */
  numAccum = ((MHP_k[1] - -2.97089706562984 *
               M1LocalControl0_DW.FyController_states_d[0]) - 2.9430254610319251
              * M1LocalControl0_DW.FyController_states_d[1]) -
    -0.9721283954020854 * M1LocalControl0_DW.FyController_states_d[2];
  M1LocalControl0_DW.FyController_states_d[2] =
    M1LocalControl0_DW.FyController_states_d[1];
  M1LocalControl0_DW.FyController_states_d[1] =
    M1LocalControl0_DW.FyController_states_d[0];
  M1LocalControl0_DW.FyController_states_d[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S4>/Fz Controller' */
  numAccum = ((MHP_k[2] - -2.935316245552321 *
               M1LocalControl0_DW.FzController_states_ac[0]) -
              2.8744564263243495 * M1LocalControl0_DW.FzController_states_ac[1])
    - -0.93914018077202877 * M1LocalControl0_DW.FzController_states_ac[2];
  M1LocalControl0_DW.FzController_states_ac[2] =
    M1LocalControl0_DW.FzController_states_ac[1];
  M1LocalControl0_DW.FzController_states_ac[1] =
    M1LocalControl0_DW.FzController_states_ac[0];
  M1LocalControl0_DW.FzController_states_ac[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S4>/Mx Controller' */
  numAccum = MHP_k[3];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl0_ConstP.pooled7[denIdx] *
      M1LocalControl0_DW.MxController_states_d[j];
    denIdx++;
  }

  M1LocalControl0_DW.MxController_states_d[4] =
    M1LocalControl0_DW.MxController_states_d[3];
  M1LocalControl0_DW.MxController_states_d[3] =
    M1LocalControl0_DW.MxController_states_d[2];
  M1LocalControl0_DW.MxController_states_d[2] =
    M1LocalControl0_DW.MxController_states_d[1];
  M1LocalControl0_DW.MxController_states_d[1] =
    M1LocalControl0_DW.MxController_states_d[0];
  M1LocalControl0_DW.MxController_states_d[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S4>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S4>/My Controller' */
  numAccum = MHP_k[4];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl0_ConstP.pooled7[denIdx] *
      M1LocalControl0_DW.MyController_states_n[j];
    denIdx++;
  }

  M1LocalControl0_DW.MyController_states_n[4] =
    M1LocalControl0_DW.MyController_states_n[3];
  M1LocalControl0_DW.MyController_states_n[3] =
    M1LocalControl0_DW.MyController_states_n[2];
  M1LocalControl0_DW.MyController_states_n[2] =
    M1LocalControl0_DW.MyController_states_n[1];
  M1LocalControl0_DW.MyController_states_n[1] =
    M1LocalControl0_DW.MyController_states_n[0];
  M1LocalControl0_DW.MyController_states_n[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S4>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S4>/Mz Controller' */
  numAccum = ((MHP_k[5] - -2.9551479035479664 *
               M1LocalControl0_DW.MzController_states_n[0]) - 2.9141589271132933
              * M1LocalControl0_DW.MzController_states_n[1]) -
    -0.95901102356532664 * M1LocalControl0_DW.MzController_states_n[2];
  M1LocalControl0_DW.MzController_states_n[2] =
    M1LocalControl0_DW.MzController_states_n[1];
  M1LocalControl0_DW.MzController_states_n[1] =
    M1LocalControl0_DW.MzController_states_n[0];
  M1LocalControl0_DW.MzController_states_n[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S5>/Fx Controller' */
  numAccum = ((MHP_dr[0] - -2.97089706562984 *
               M1LocalControl0_DW.FxController_states_n[0]) - 2.9430254610319251
              * M1LocalControl0_DW.FxController_states_n[1]) -
    -0.9721283954020854 * M1LocalControl0_DW.FxController_states_n[2];
  M1LocalControl0_DW.FxController_states_n[2] =
    M1LocalControl0_DW.FxController_states_n[1];
  M1LocalControl0_DW.FxController_states_n[1] =
    M1LocalControl0_DW.FxController_states_n[0];
  M1LocalControl0_DW.FxController_states_n[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S5>/Fy Controller' */
  numAccum = ((MHP_dr[1] - -2.97089706562984 *
               M1LocalControl0_DW.FyController_states_e[0]) - 2.9430254610319251
              * M1LocalControl0_DW.FyController_states_e[1]) -
    -0.9721283954020854 * M1LocalControl0_DW.FyController_states_e[2];
  M1LocalControl0_DW.FyController_states_e[2] =
    M1LocalControl0_DW.FyController_states_e[1];
  M1LocalControl0_DW.FyController_states_e[1] =
    M1LocalControl0_DW.FyController_states_e[0];
  M1LocalControl0_DW.FyController_states_e[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S5>/Fz Controller' */
  numAccum = ((MHP_dr[2] - -2.935316245552321 *
               M1LocalControl0_DW.FzController_states_c[0]) - 2.8744564263243495
              * M1LocalControl0_DW.FzController_states_c[1]) -
    -0.93914018077202877 * M1LocalControl0_DW.FzController_states_c[2];
  M1LocalControl0_DW.FzController_states_c[2] =
    M1LocalControl0_DW.FzController_states_c[1];
  M1LocalControl0_DW.FzController_states_c[1] =
    M1LocalControl0_DW.FzController_states_c[0];
  M1LocalControl0_DW.FzController_states_c[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S5>/Mx Controller' */
  numAccum = MHP_dr[3];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl0_ConstP.pooled7[denIdx] *
      M1LocalControl0_DW.MxController_states_f[j];
    denIdx++;
  }

  M1LocalControl0_DW.MxController_states_f[4] =
    M1LocalControl0_DW.MxController_states_f[3];
  M1LocalControl0_DW.MxController_states_f[3] =
    M1LocalControl0_DW.MxController_states_f[2];
  M1LocalControl0_DW.MxController_states_f[2] =
    M1LocalControl0_DW.MxController_states_f[1];
  M1LocalControl0_DW.MxController_states_f[1] =
    M1LocalControl0_DW.MxController_states_f[0];
  M1LocalControl0_DW.MxController_states_f[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S5>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S5>/My Controller' */
  numAccum = MHP_dr[4];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl0_ConstP.pooled7[denIdx] *
      M1LocalControl0_DW.MyController_states_g[j];
    denIdx++;
  }

  M1LocalControl0_DW.MyController_states_g[4] =
    M1LocalControl0_DW.MyController_states_g[3];
  M1LocalControl0_DW.MyController_states_g[3] =
    M1LocalControl0_DW.MyController_states_g[2];
  M1LocalControl0_DW.MyController_states_g[2] =
    M1LocalControl0_DW.MyController_states_g[1];
  M1LocalControl0_DW.MyController_states_g[1] =
    M1LocalControl0_DW.MyController_states_g[0];
  M1LocalControl0_DW.MyController_states_g[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S5>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S5>/Mz Controller' */
  numAccum = ((MHP_dr[5] - -2.9551479035479664 *
               M1LocalControl0_DW.MzController_states_h[0]) - 2.9141589271132933
              * M1LocalControl0_DW.MzController_states_h[1]) -
    -0.95901102356532664 * M1LocalControl0_DW.MzController_states_h[2];
  M1LocalControl0_DW.MzController_states_h[2] =
    M1LocalControl0_DW.MzController_states_h[1];
  M1LocalControl0_DW.MzController_states_h[1] =
    M1LocalControl0_DW.MzController_states_h[0];
  M1LocalControl0_DW.MzController_states_h[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S6>/Fx Controller' */
  numAccum = ((MHP_f[0] - -2.97089706562984 *
               M1LocalControl0_DW.FxController_states_o[0]) - 2.9430254610319251
              * M1LocalControl0_DW.FxController_states_o[1]) -
    -0.9721283954020854 * M1LocalControl0_DW.FxController_states_o[2];
  M1LocalControl0_DW.FxController_states_o[2] =
    M1LocalControl0_DW.FxController_states_o[1];
  M1LocalControl0_DW.FxController_states_o[1] =
    M1LocalControl0_DW.FxController_states_o[0];
  M1LocalControl0_DW.FxController_states_o[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S6>/Fy Controller' */
  numAccum = ((MHP_f[1] - -2.97089706562984 *
               M1LocalControl0_DW.FyController_states_n[0]) - 2.9430254610319251
              * M1LocalControl0_DW.FyController_states_n[1]) -
    -0.9721283954020854 * M1LocalControl0_DW.FyController_states_n[2];
  M1LocalControl0_DW.FyController_states_n[2] =
    M1LocalControl0_DW.FyController_states_n[1];
  M1LocalControl0_DW.FyController_states_n[1] =
    M1LocalControl0_DW.FyController_states_n[0];
  M1LocalControl0_DW.FyController_states_n[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S6>/Fz Controller' */
  numAccum = ((MHP_f[2] - -2.935316245552321 *
               M1LocalControl0_DW.FzController_states_k[0]) - 2.8744564263243495
              * M1LocalControl0_DW.FzController_states_k[1]) -
    -0.93914018077202877 * M1LocalControl0_DW.FzController_states_k[2];
  M1LocalControl0_DW.FzController_states_k[2] =
    M1LocalControl0_DW.FzController_states_k[1];
  M1LocalControl0_DW.FzController_states_k[1] =
    M1LocalControl0_DW.FzController_states_k[0];
  M1LocalControl0_DW.FzController_states_k[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S6>/Mx Controller' */
  numAccum = MHP_f[3];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl0_ConstP.pooled7[denIdx] *
      M1LocalControl0_DW.MxController_states_k[j];
    denIdx++;
  }

  M1LocalControl0_DW.MxController_states_k[4] =
    M1LocalControl0_DW.MxController_states_k[3];
  M1LocalControl0_DW.MxController_states_k[3] =
    M1LocalControl0_DW.MxController_states_k[2];
  M1LocalControl0_DW.MxController_states_k[2] =
    M1LocalControl0_DW.MxController_states_k[1];
  M1LocalControl0_DW.MxController_states_k[1] =
    M1LocalControl0_DW.MxController_states_k[0];
  M1LocalControl0_DW.MxController_states_k[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S6>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S6>/My Controller' */
  numAccum = MHP_f[4];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl0_ConstP.pooled7[denIdx] *
      M1LocalControl0_DW.MyController_states_k[j];
    denIdx++;
  }

  M1LocalControl0_DW.MyController_states_k[4] =
    M1LocalControl0_DW.MyController_states_k[3];
  M1LocalControl0_DW.MyController_states_k[3] =
    M1LocalControl0_DW.MyController_states_k[2];
  M1LocalControl0_DW.MyController_states_k[2] =
    M1LocalControl0_DW.MyController_states_k[1];
  M1LocalControl0_DW.MyController_states_k[1] =
    M1LocalControl0_DW.MyController_states_k[0];
  M1LocalControl0_DW.MyController_states_k[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S6>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S6>/Mz Controller' */
  numAccum = ((MHP_f[5] - -2.9551479035479664 *
               M1LocalControl0_DW.MzController_states_i[0]) - 2.9141589271132933
              * M1LocalControl0_DW.MzController_states_i[1]) -
    -0.95901102356532664 * M1LocalControl0_DW.MzController_states_i[2];
  M1LocalControl0_DW.MzController_states_i[2] =
    M1LocalControl0_DW.MzController_states_i[1];
  M1LocalControl0_DW.MzController_states_i[1] =
    M1LocalControl0_DW.MzController_states_i[0];
  M1LocalControl0_DW.MzController_states_i[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S7>/Fx Controller' */
  numAccum = ((MHP_m[0] - -2.97089706562984 *
               M1LocalControl0_DW.FxController_states_b[0]) - 2.9430254610319251
              * M1LocalControl0_DW.FxController_states_b[1]) -
    -0.9721283954020854 * M1LocalControl0_DW.FxController_states_b[2];
  M1LocalControl0_DW.FxController_states_b[2] =
    M1LocalControl0_DW.FxController_states_b[1];
  M1LocalControl0_DW.FxController_states_b[1] =
    M1LocalControl0_DW.FxController_states_b[0];
  M1LocalControl0_DW.FxController_states_b[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S7>/Fy Controller' */
  numAccum = ((MHP_m[1] - -2.97089706562984 *
               M1LocalControl0_DW.FyController_states_c[0]) - 2.9430254610319251
              * M1LocalControl0_DW.FyController_states_c[1]) -
    -0.9721283954020854 * M1LocalControl0_DW.FyController_states_c[2];
  M1LocalControl0_DW.FyController_states_c[2] =
    M1LocalControl0_DW.FyController_states_c[1];
  M1LocalControl0_DW.FyController_states_c[1] =
    M1LocalControl0_DW.FyController_states_c[0];
  M1LocalControl0_DW.FyController_states_c[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S7>/Fz Controller' */
  numAccum = ((MHP_m[2] - -2.935316245552321 *
               M1LocalControl0_DW.FzController_states_l[0]) - 2.8744564263243495
              * M1LocalControl0_DW.FzController_states_l[1]) -
    -0.93914018077202877 * M1LocalControl0_DW.FzController_states_l[2];
  M1LocalControl0_DW.FzController_states_l[2] =
    M1LocalControl0_DW.FzController_states_l[1];
  M1LocalControl0_DW.FzController_states_l[1] =
    M1LocalControl0_DW.FzController_states_l[0];
  M1LocalControl0_DW.FzController_states_l[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S7>/Mx Controller' */
  numAccum = MHP_m[3];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl0_ConstP.pooled7[denIdx] *
      M1LocalControl0_DW.MxController_states_m[j];
    denIdx++;
  }

  M1LocalControl0_DW.MxController_states_m[4] =
    M1LocalControl0_DW.MxController_states_m[3];
  M1LocalControl0_DW.MxController_states_m[3] =
    M1LocalControl0_DW.MxController_states_m[2];
  M1LocalControl0_DW.MxController_states_m[2] =
    M1LocalControl0_DW.MxController_states_m[1];
  M1LocalControl0_DW.MxController_states_m[1] =
    M1LocalControl0_DW.MxController_states_m[0];
  M1LocalControl0_DW.MxController_states_m[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S7>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S7>/My Controller' */
  numAccum = MHP_m[4];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl0_ConstP.pooled7[denIdx] *
      M1LocalControl0_DW.MyController_states_d[j];
    denIdx++;
  }

  M1LocalControl0_DW.MyController_states_d[4] =
    M1LocalControl0_DW.MyController_states_d[3];
  M1LocalControl0_DW.MyController_states_d[3] =
    M1LocalControl0_DW.MyController_states_d[2];
  M1LocalControl0_DW.MyController_states_d[2] =
    M1LocalControl0_DW.MyController_states_d[1];
  M1LocalControl0_DW.MyController_states_d[1] =
    M1LocalControl0_DW.MyController_states_d[0];
  M1LocalControl0_DW.MyController_states_d[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S7>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S7>/Mz Controller' */
  numAccum = ((MHP_m[5] - -2.9551479035479664 *
               M1LocalControl0_DW.MzController_states_o[0]) - 2.9141589271132933
              * M1LocalControl0_DW.MzController_states_o[1]) -
    -0.95901102356532664 * M1LocalControl0_DW.MzController_states_o[2];
  M1LocalControl0_DW.MzController_states_o[2] =
    M1LocalControl0_DW.MzController_states_o[1];
  M1LocalControl0_DW.MzController_states_o[1] =
    M1LocalControl0_DW.MzController_states_o[0];
  M1LocalControl0_DW.MzController_states_o[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S8>/Fx Controller' */
  numAccum = ((MHP_c[0] - -2.97089706562984 *
               M1LocalControl0_DW.FxController_states_fe[0]) -
              2.9430254610319251 * M1LocalControl0_DW.FxController_states_fe[1])
    - -0.9721283954020854 * M1LocalControl0_DW.FxController_states_fe[2];
  M1LocalControl0_DW.FxController_states_fe[2] =
    M1LocalControl0_DW.FxController_states_fe[1];
  M1LocalControl0_DW.FxController_states_fe[1] =
    M1LocalControl0_DW.FxController_states_fe[0];
  M1LocalControl0_DW.FxController_states_fe[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S8>/Fy Controller' */
  numAccum = ((MHP_c[1] - -2.9736051405026691 *
               M1LocalControl0_DW.FyController_states_h[0]) - 2.9475609495552049
              * M1LocalControl0_DW.FyController_states_h[1]) -
    -0.97395580905253565 * M1LocalControl0_DW.FyController_states_h[2];
  M1LocalControl0_DW.FyController_states_h[2] =
    M1LocalControl0_DW.FyController_states_h[1];
  M1LocalControl0_DW.FyController_states_h[1] =
    M1LocalControl0_DW.FyController_states_h[0];
  M1LocalControl0_DW.FyController_states_h[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S8>/Fz Controller' */
  numAccum = ((MHP_c[2] - -2.935316245552321 *
               M1LocalControl0_DW.FzController_states_j[0]) - 2.8744564263243495
              * M1LocalControl0_DW.FzController_states_j[1]) -
    -0.93914018077202877 * M1LocalControl0_DW.FzController_states_j[2];
  M1LocalControl0_DW.FzController_states_j[2] =
    M1LocalControl0_DW.FzController_states_j[1];
  M1LocalControl0_DW.FzController_states_j[1] =
    M1LocalControl0_DW.FzController_states_j[0];
  M1LocalControl0_DW.FzController_states_j[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S8>/Mx Controller' */
  numAccum = ((MHP_c[3] - -2.9736051405026691 *
               M1LocalControl0_DW.MxController_states_cu[0]) -
              2.9475609495552049 * M1LocalControl0_DW.MxController_states_cu[1])
    - -0.97395580905253565 * M1LocalControl0_DW.MxController_states_cu[2];
  M1LocalControl0_DW.MxController_states_cu[2] =
    M1LocalControl0_DW.MxController_states_cu[1];
  M1LocalControl0_DW.MxController_states_cu[1] =
    M1LocalControl0_DW.MxController_states_cu[0];
  M1LocalControl0_DW.MxController_states_cu[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S8>/My Controller' */
  numAccum = ((MHP_c[4] - -2.9736051405026691 *
               M1LocalControl0_DW.MyController_states_a[0]) - 2.9475609495552049
              * M1LocalControl0_DW.MyController_states_a[1]) -
    -0.97395580905253565 * M1LocalControl0_DW.MyController_states_a[2];
  M1LocalControl0_DW.MyController_states_a[2] =
    M1LocalControl0_DW.MyController_states_a[1];
  M1LocalControl0_DW.MyController_states_a[1] =
    M1LocalControl0_DW.MyController_states_a[0];
  M1LocalControl0_DW.MyController_states_a[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S8>/Mz Controller' */
  numAccum = ((MHP_c[5] - -2.9736051405026691 *
               M1LocalControl0_DW.MzController_states_a[0]) - 2.9475609495552049
              * M1LocalControl0_DW.MzController_states_a[1]) -
    -0.97395580905253565 * M1LocalControl0_DW.MzController_states_a[2];
  M1LocalControl0_DW.MzController_states_a[2] =
    M1LocalControl0_DW.MzController_states_a[1];
  M1LocalControl0_DW.MzController_states_a[1] =
    M1LocalControl0_DW.MzController_states_a[0];
  M1LocalControl0_DW.MzController_states_a[0] = numAccum;
}

/* Model initialize function */
void M1LocalControl0_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1LocalControl0_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&M1LocalControl0_DW, 0,
                sizeof(DW_M1LocalControl0_T));

  /* external inputs */
  (void)memset((void *)&M1LocalControl0_U, 0, sizeof(ExtU_M1LocalControl0_T));

  /* external outputs */
  (void) memset(&M1LocalControl0_Y.Output[0], 0,
                2316U*sizeof(real_T));
}

/* Model terminate function */
void M1LocalControl0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
