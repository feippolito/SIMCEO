/*
 * File: M1LocalControl_wBM0.c
 *
 * Code generated for Simulink model 'M1LocalControl_wBM0'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Feb 12 09:45:37 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1LocalControl_wBM0.h"
#include "M1LocalControl_wBM0_private.h"

/* Block signals (default storage) */
B_M1LocalControl_wBM0_T M1LocalControl_wBM0_B;

/* Block states (default storage) */
DW_M1LocalControl_wBM0_T M1LocalControl_wBM0_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M1LocalControl_wBM0_T M1LocalControl_wBM0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1LocalControl_wBM0_T M1LocalControl_wBM0_Y;

/* Real-time model */
RT_MODEL_M1LocalControl_wBM0_T M1LocalControl_wBM0_M_;
RT_MODEL_M1LocalControl_wBM0_T *const M1LocalControl_wBM0_M =
  &M1LocalControl_wBM0_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void M1LocalControl_wBM0_step(void)
{
  real_T numAccum;
  int32_T j;
  int32_T denIdx;
  real_T numAccum_0;
  int32_T denIdx_0;
  real_T rtb_Forcebalance[335];
  real_T rtb_Forcebalance_h[335];
  real_T rtb_Forcebalance_n[335];
  real_T rtb_Forcebalance_e4[335];
  real_T rtb_Forcebalance_b[495];
  real_T MHP[6];
  real_T MHP_d[6];
  real_T MHP_k[6];
  real_T MHP_dr[6];
  real_T MHP_f[6];
  real_T MHP_m[6];
  real_T MHP_c[6];
  real_T rtb_MzController_0[6];
  real_T tmp[306];
  real_T tmp_0[165];
  real_T tmp_1[335];
  real_T tmp_2[335];
  real_T tmp_3[154];
  real_T tmp_4[462];

  /* DiscreteTransferFcn: '<S11>/Mx Controller' */
  numAccum = 0.0;
  denIdx = 1;

  /* DiscreteTransferFcn: '<S11>/My Controller' */
  numAccum_0 = 0.0;
  denIdx_0 = 1;
  for (j = 0; j < 5; j++) {
    /* DiscreteTransferFcn: '<S11>/Mx Controller' */
    numAccum += M1LocalControl_wBM0_ConstP.pooled6[denIdx] *
      M1LocalControl_wBM0_DW.MxController_states[j];
    denIdx++;

    /* DiscreteTransferFcn: '<S11>/My Controller' */
    numAccum_0 += M1LocalControl_wBM0_ConstP.pooled6[denIdx_0] *
      M1LocalControl_wBM0_DW.MyController_states[j];
    denIdx_0++;
  }

  /* SignalConversion: '<S11>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S11>/Fx Controller'
   *  DiscreteTransferFcn: '<S11>/Fy Controller'
   *  DiscreteTransferFcn: '<S11>/Fz Controller'
   *  DiscreteTransferFcn: '<S11>/Mx Controller'
   *  DiscreteTransferFcn: '<S11>/My Controller'
   *  DiscreteTransferFcn: '<S11>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1LocalControl_wBM0_DW.FxController_states[0] + -0.0062083257567339973 *
    M1LocalControl_wBM0_DW.FxController_states[1]) + 0.0031046389635168946 *
    M1LocalControl_wBM0_DW.FxController_states[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1LocalControl_wBM0_DW.FyController_states[0] + -0.0062083257567339973 *
    M1LocalControl_wBM0_DW.FyController_states[1]) + 0.0031046389635168946 *
    M1LocalControl_wBM0_DW.FyController_states[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1LocalControl_wBM0_DW.FzController_states[0] + -0.0067736068594331216 *
    M1LocalControl_wBM0_DW.FzController_states[1]) + 0.0033881700821686029 *
    M1LocalControl_wBM0_DW.FzController_states[2];
  rtb_MzController_0[3] = numAccum;
  rtb_MzController_0[4] = numAccum_0;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1LocalControl_wBM0_DW.MzController_states[0] + -0.0068430176624178825 *
    M1LocalControl_wBM0_DW.MzController_states[1]) + 0.0034246827558012866 *
    M1LocalControl_wBM0_DW.MzController_states[2];

  /* Gain: '<S11>/Force balance' */
  for (j = 0; j < 335; j++) {
    M1LocalControl_wBM0_B.Quantizer[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      M1LocalControl_wBM0_B.Quantizer[j] += M1LocalControl_wBM0_ConstP.pooled10
        [335 * denIdx + j] * rtb_MzController_0[denIdx];
    }
  }

  /* End of Gain: '<S11>/Force balance' */

  /* DiscreteTransferFcn: '<S12>/Mx Controller' */
  numAccum = 0.0;
  denIdx = 1;

  /* DiscreteTransferFcn: '<S12>/My Controller' */
  numAccum_0 = 0.0;
  denIdx_0 = 1;
  for (j = 0; j < 5; j++) {
    /* DiscreteTransferFcn: '<S12>/Mx Controller' */
    numAccum += M1LocalControl_wBM0_ConstP.pooled6[denIdx] *
      M1LocalControl_wBM0_DW.MxController_states_c[j];
    denIdx++;

    /* DiscreteTransferFcn: '<S12>/My Controller' */
    numAccum_0 += M1LocalControl_wBM0_ConstP.pooled6[denIdx_0] *
      M1LocalControl_wBM0_DW.MyController_states_i[j];
    denIdx_0++;
  }

  /* SignalConversion: '<S12>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S12>/Fx Controller'
   *  DiscreteTransferFcn: '<S12>/Fy Controller'
   *  DiscreteTransferFcn: '<S12>/Fz Controller'
   *  DiscreteTransferFcn: '<S12>/Mx Controller'
   *  DiscreteTransferFcn: '<S12>/My Controller'
   *  DiscreteTransferFcn: '<S12>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1LocalControl_wBM0_DW.FxController_states_f[0] + -0.0062083257567339973 *
    M1LocalControl_wBM0_DW.FxController_states_f[1]) + 0.0031046389635168946 *
    M1LocalControl_wBM0_DW.FxController_states_f[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1LocalControl_wBM0_DW.FyController_states_p[0] + -0.0062083257567339973 *
    M1LocalControl_wBM0_DW.FyController_states_p[1]) + 0.0031046389635168946 *
    M1LocalControl_wBM0_DW.FyController_states_p[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1LocalControl_wBM0_DW.FzController_states_a[0] + -0.0067736068594331216 *
    M1LocalControl_wBM0_DW.FzController_states_a[1]) + 0.0033881700821686029 *
    M1LocalControl_wBM0_DW.FzController_states_a[2];
  rtb_MzController_0[3] = numAccum;
  rtb_MzController_0[4] = numAccum_0;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1LocalControl_wBM0_DW.MzController_states_e[0] + -0.0068430176624178825 *
    M1LocalControl_wBM0_DW.MzController_states_e[1]) + 0.0034246827558012866 *
    M1LocalControl_wBM0_DW.MzController_states_e[2];

  /* Gain: '<S12>/Force balance' */
  for (j = 0; j < 335; j++) {
    rtb_Forcebalance[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      rtb_Forcebalance[j] += M1LocalControl_wBM0_ConstP.pooled10[335 * denIdx +
        j] * rtb_MzController_0[denIdx];
    }
  }

  /* End of Gain: '<S12>/Force balance' */

  /* DiscreteTransferFcn: '<S13>/Mx Controller' */
  numAccum = 0.0;
  denIdx = 1;

  /* DiscreteTransferFcn: '<S13>/My Controller' */
  numAccum_0 = 0.0;
  denIdx_0 = 1;
  for (j = 0; j < 5; j++) {
    /* DiscreteTransferFcn: '<S13>/Mx Controller' */
    numAccum += M1LocalControl_wBM0_ConstP.pooled6[denIdx] *
      M1LocalControl_wBM0_DW.MxController_states_d[j];
    denIdx++;

    /* DiscreteTransferFcn: '<S13>/My Controller' */
    numAccum_0 += M1LocalControl_wBM0_ConstP.pooled6[denIdx_0] *
      M1LocalControl_wBM0_DW.MyController_states_n[j];
    denIdx_0++;
  }

  /* SignalConversion: '<S13>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S13>/Fx Controller'
   *  DiscreteTransferFcn: '<S13>/Fy Controller'
   *  DiscreteTransferFcn: '<S13>/Fz Controller'
   *  DiscreteTransferFcn: '<S13>/Mx Controller'
   *  DiscreteTransferFcn: '<S13>/My Controller'
   *  DiscreteTransferFcn: '<S13>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1LocalControl_wBM0_DW.FxController_states_j[0] + -0.0062083257567339973 *
    M1LocalControl_wBM0_DW.FxController_states_j[1]) + 0.0031046389635168946 *
    M1LocalControl_wBM0_DW.FxController_states_j[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1LocalControl_wBM0_DW.FyController_states_d[0] + -0.0062083257567339973 *
    M1LocalControl_wBM0_DW.FyController_states_d[1]) + 0.0031046389635168946 *
    M1LocalControl_wBM0_DW.FyController_states_d[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1LocalControl_wBM0_DW.FzController_states_ac[0] + -0.0067736068594331216 *
    M1LocalControl_wBM0_DW.FzController_states_ac[1]) + 0.0033881700821686029 *
    M1LocalControl_wBM0_DW.FzController_states_ac[2];
  rtb_MzController_0[3] = numAccum;
  rtb_MzController_0[4] = numAccum_0;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1LocalControl_wBM0_DW.MzController_states_n[0] + -0.0068430176624178825 *
    M1LocalControl_wBM0_DW.MzController_states_n[1]) + 0.0034246827558012866 *
    M1LocalControl_wBM0_DW.MzController_states_n[2];

  /* Gain: '<S13>/Force balance' */
  for (j = 0; j < 335; j++) {
    rtb_Forcebalance_h[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      rtb_Forcebalance_h[j] += M1LocalControl_wBM0_ConstP.pooled10[335 * denIdx
        + j] * rtb_MzController_0[denIdx];
    }
  }

  /* End of Gain: '<S13>/Force balance' */

  /* DiscreteTransferFcn: '<S14>/Mx Controller' */
  numAccum = 0.0;
  denIdx = 1;

  /* DiscreteTransferFcn: '<S14>/My Controller' */
  numAccum_0 = 0.0;
  denIdx_0 = 1;
  for (j = 0; j < 5; j++) {
    /* DiscreteTransferFcn: '<S14>/Mx Controller' */
    numAccum += M1LocalControl_wBM0_ConstP.pooled6[denIdx] *
      M1LocalControl_wBM0_DW.MxController_states_f[j];
    denIdx++;

    /* DiscreteTransferFcn: '<S14>/My Controller' */
    numAccum_0 += M1LocalControl_wBM0_ConstP.pooled6[denIdx_0] *
      M1LocalControl_wBM0_DW.MyController_states_g[j];
    denIdx_0++;
  }

  /* SignalConversion: '<S14>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S14>/Fx Controller'
   *  DiscreteTransferFcn: '<S14>/Fy Controller'
   *  DiscreteTransferFcn: '<S14>/Fz Controller'
   *  DiscreteTransferFcn: '<S14>/Mx Controller'
   *  DiscreteTransferFcn: '<S14>/My Controller'
   *  DiscreteTransferFcn: '<S14>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1LocalControl_wBM0_DW.FxController_states_n[0] + -0.0062083257567339973 *
    M1LocalControl_wBM0_DW.FxController_states_n[1]) + 0.0031046389635168946 *
    M1LocalControl_wBM0_DW.FxController_states_n[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1LocalControl_wBM0_DW.FyController_states_e[0] + -0.0062083257567339973 *
    M1LocalControl_wBM0_DW.FyController_states_e[1]) + 0.0031046389635168946 *
    M1LocalControl_wBM0_DW.FyController_states_e[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1LocalControl_wBM0_DW.FzController_states_c[0] + -0.0067736068594331216 *
    M1LocalControl_wBM0_DW.FzController_states_c[1]) + 0.0033881700821686029 *
    M1LocalControl_wBM0_DW.FzController_states_c[2];
  rtb_MzController_0[3] = numAccum;
  rtb_MzController_0[4] = numAccum_0;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1LocalControl_wBM0_DW.MzController_states_h[0] + -0.0068430176624178825 *
    M1LocalControl_wBM0_DW.MzController_states_h[1]) + 0.0034246827558012866 *
    M1LocalControl_wBM0_DW.MzController_states_h[2];

  /* Gain: '<S14>/Force balance' */
  for (j = 0; j < 335; j++) {
    rtb_Forcebalance_n[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      rtb_Forcebalance_n[j] += M1LocalControl_wBM0_ConstP.pooled10[335 * denIdx
        + j] * rtb_MzController_0[denIdx];
    }
  }

  /* End of Gain: '<S14>/Force balance' */

  /* DiscreteTransferFcn: '<S15>/Mx Controller' */
  numAccum = 0.0;
  denIdx = 1;

  /* DiscreteTransferFcn: '<S15>/My Controller' */
  numAccum_0 = 0.0;
  denIdx_0 = 1;
  for (j = 0; j < 5; j++) {
    /* DiscreteTransferFcn: '<S15>/Mx Controller' */
    numAccum += M1LocalControl_wBM0_ConstP.pooled6[denIdx] *
      M1LocalControl_wBM0_DW.MxController_states_k[j];
    denIdx++;

    /* DiscreteTransferFcn: '<S15>/My Controller' */
    numAccum_0 += M1LocalControl_wBM0_ConstP.pooled6[denIdx_0] *
      M1LocalControl_wBM0_DW.MyController_states_k[j];
    denIdx_0++;
  }

  /* SignalConversion: '<S15>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S15>/Fx Controller'
   *  DiscreteTransferFcn: '<S15>/Fy Controller'
   *  DiscreteTransferFcn: '<S15>/Fz Controller'
   *  DiscreteTransferFcn: '<S15>/Mx Controller'
   *  DiscreteTransferFcn: '<S15>/My Controller'
   *  DiscreteTransferFcn: '<S15>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1LocalControl_wBM0_DW.FxController_states_o[0] + -0.0062083257567339973 *
    M1LocalControl_wBM0_DW.FxController_states_o[1]) + 0.0031046389635168946 *
    M1LocalControl_wBM0_DW.FxController_states_o[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1LocalControl_wBM0_DW.FyController_states_n[0] + -0.0062083257567339973 *
    M1LocalControl_wBM0_DW.FyController_states_n[1]) + 0.0031046389635168946 *
    M1LocalControl_wBM0_DW.FyController_states_n[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1LocalControl_wBM0_DW.FzController_states_k[0] + -0.0067736068594331216 *
    M1LocalControl_wBM0_DW.FzController_states_k[1]) + 0.0033881700821686029 *
    M1LocalControl_wBM0_DW.FzController_states_k[2];
  rtb_MzController_0[3] = numAccum;
  rtb_MzController_0[4] = numAccum_0;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1LocalControl_wBM0_DW.MzController_states_i[0] + -0.0068430176624178825 *
    M1LocalControl_wBM0_DW.MzController_states_i[1]) + 0.0034246827558012866 *
    M1LocalControl_wBM0_DW.MzController_states_i[2];

  /* Gain: '<S15>/Force balance' */
  for (j = 0; j < 335; j++) {
    rtb_Forcebalance_e4[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      rtb_Forcebalance_e4[j] += M1LocalControl_wBM0_ConstP.pooled10[335 * denIdx
        + j] * rtb_MzController_0[denIdx];
    }
  }

  /* End of Gain: '<S15>/Force balance' */

  /* DiscreteTransferFcn: '<S16>/Mx Controller' */
  numAccum = 0.0;
  denIdx = 1;

  /* DiscreteTransferFcn: '<S16>/My Controller' */
  numAccum_0 = 0.0;
  denIdx_0 = 1;
  for (j = 0; j < 5; j++) {
    /* DiscreteTransferFcn: '<S16>/Mx Controller' */
    numAccum += M1LocalControl_wBM0_ConstP.pooled6[denIdx] *
      M1LocalControl_wBM0_DW.MxController_states_m[j];
    denIdx++;

    /* DiscreteTransferFcn: '<S16>/My Controller' */
    numAccum_0 += M1LocalControl_wBM0_ConstP.pooled6[denIdx_0] *
      M1LocalControl_wBM0_DW.MyController_states_d[j];
    denIdx_0++;
  }

  /* SignalConversion: '<S16>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S16>/Fx Controller'
   *  DiscreteTransferFcn: '<S16>/Fy Controller'
   *  DiscreteTransferFcn: '<S16>/Fz Controller'
   *  DiscreteTransferFcn: '<S16>/Mx Controller'
   *  DiscreteTransferFcn: '<S16>/My Controller'
   *  DiscreteTransferFcn: '<S16>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0031075654819996759 *
    M1LocalControl_wBM0_DW.FxController_states_b[0] + -0.0062083257567339973 *
    M1LocalControl_wBM0_DW.FxController_states_b[1]) + 0.0031046389635168946 *
    M1LocalControl_wBM0_DW.FxController_states_b[2];
  rtb_MzController_0[1] = (0.0031075654819996759 *
    M1LocalControl_wBM0_DW.FyController_states_c[0] + -0.0062083257567339973 *
    M1LocalControl_wBM0_DW.FyController_states_c[1]) + 0.0031046389635168946 *
    M1LocalControl_wBM0_DW.FyController_states_c[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1LocalControl_wBM0_DW.FzController_states_l[0] + -0.0067736068594331216 *
    M1LocalControl_wBM0_DW.FzController_states_l[1]) + 0.0033881700821686029 *
    M1LocalControl_wBM0_DW.FzController_states_l[2];
  rtb_MzController_0[3] = numAccum;
  rtb_MzController_0[4] = numAccum_0;
  rtb_MzController_0[5] = (0.0034318558266773552 *
    M1LocalControl_wBM0_DW.MzController_states_o[0] + -0.0068430176624178825 *
    M1LocalControl_wBM0_DW.MzController_states_o[1]) + 0.0034246827558012866 *
    M1LocalControl_wBM0_DW.MzController_states_o[2];

  /* Gain: '<S16>/Force balance' */
  for (j = 0; j < 335; j++) {
    rtb_Forcebalance_b[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      rtb_Forcebalance_b[j] += M1LocalControl_wBM0_ConstP.pooled10[335 * denIdx
        + j] * rtb_MzController_0[denIdx];
    }
  }

  /* End of Gain: '<S16>/Force balance' */

  /* SignalConversion: '<S17>/TmpSignal ConversionAtForce balanceInport1' incorporates:
   *  DiscreteTransferFcn: '<S17>/Fx Controller'
   *  DiscreteTransferFcn: '<S17>/Fy Controller'
   *  DiscreteTransferFcn: '<S17>/Fz Controller'
   *  DiscreteTransferFcn: '<S17>/Mx Controller'
   *  DiscreteTransferFcn: '<S17>/My Controller'
   *  DiscreteTransferFcn: '<S17>/Mz Controller'
   */
  rtb_MzController_0[0] = (0.0027629307658847734 *
    M1LocalControl_wBM0_DW.FxController_states_fe[0] + -0.0055185117837635517 *
    M1LocalControl_wBM0_DW.FxController_states_fe[1]) + 0.0027590287412410657 *
    M1LocalControl_wBM0_DW.FxController_states_fe[2];
  rtb_MzController_0[1] = (1.6875923962320881E-7 *
    M1LocalControl_wBM0_DW.FyController_states_h[0] + 3.3751847924641762E-7 *
    M1LocalControl_wBM0_DW.FyController_states_h[1]) + 1.6875923962320881E-7 *
    M1LocalControl_wBM0_DW.FyController_states_h[2];
  rtb_MzController_0[2] = (0.0033988205505334976 *
    M1LocalControl_wBM0_DW.FzController_states_j[0] + -0.0067736068594331216 *
    M1LocalControl_wBM0_DW.FzController_states_j[1]) + 0.0033881700821686029 *
    M1LocalControl_wBM0_DW.FzController_states_j[2];
  rtb_MzController_0[3] = (1.6875923962320881E-7 *
    M1LocalControl_wBM0_DW.MxController_states_cu[0] + 3.3751847924641762E-7 *
    M1LocalControl_wBM0_DW.MxController_states_cu[1]) + 1.6875923962320881E-7 *
    M1LocalControl_wBM0_DW.MxController_states_cu[2];
  rtb_MzController_0[4] = (1.6875923962320881E-7 *
    M1LocalControl_wBM0_DW.MyController_states_a[0] + 3.3751847924641762E-7 *
    M1LocalControl_wBM0_DW.MyController_states_a[1]) + 1.6875923962320881E-7 *
    M1LocalControl_wBM0_DW.MyController_states_a[2];
  rtb_MzController_0[5] = (1.6875923962320881E-7 *
    M1LocalControl_wBM0_DW.MzController_states_a[0] + 3.3751847924641762E-7 *
    M1LocalControl_wBM0_DW.MzController_states_a[1]) + 1.6875923962320881E-7 *
    M1LocalControl_wBM0_DW.MzController_states_a[2];

  /* Gain: '<S17>/Force balance' incorporates:
   *  Quantizer: '<S3>/Quantizer'
   */
  for (j = 0; j < 306; j++) {
    tmp[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      tmp[j] += M1LocalControl_wBM0_ConstP.Forcebalance_Gain[306 * denIdx + j] *
        rtb_MzController_0[denIdx];
    }
  }

  /* End of Gain: '<S17>/Force balance' */

  /* Quantizer: '<S3>/Quantizer' */
  for (j = 0; j < 335; j++) {
    M1LocalControl_wBM0_B.rtb_Quantizer_m[j] = M1LocalControl_wBM0_B.Quantizer[j];
    M1LocalControl_wBM0_B.rtb_Quantizer_m[j + 335] = rtb_Forcebalance[j];
    M1LocalControl_wBM0_B.rtb_Quantizer_m[j + 670] = rtb_Forcebalance_h[j];
    M1LocalControl_wBM0_B.rtb_Quantizer_m[j + 1005] = rtb_Forcebalance_n[j];
    M1LocalControl_wBM0_B.rtb_Quantizer_m[j + 1340] = rtb_Forcebalance_e4[j];
    M1LocalControl_wBM0_B.rtb_Quantizer_m[j + 1675] = rtb_Forcebalance_b[j];
  }

  memcpy(&M1LocalControl_wBM0_B.rtb_Quantizer_m[2010], &tmp[0], 306U * sizeof
         (real_T));
  for (j = 0; j < 2316; j++) {
    M1LocalControl_wBM0_B.Quantizer[j] = rt_roundd_snf
      (M1LocalControl_wBM0_B.rtb_Quantizer_m[j] / 5.0E-10) * 5.0E-10;
  }

  /* Gain: '<S4>/Gain' incorporates:
   *  Gain: '<S4>/Gain1'
   *  Inport: '<Root>/Feedback'
   */
  for (j = 0; j < 165; j++) {
    tmp_0[j] = 0.0;
    for (denIdx = 0; denIdx < 27; denIdx++) {
      tmp_0[j] += M1LocalControl_wBM0_ConstP.pooled13[165 * denIdx + j] *
        M1LocalControl_wBM0_U.Feedback[42 + denIdx];
    }
  }

  /* End of Gain: '<S4>/Gain' */

  /* Gain: '<S4>/Gain1' incorporates:
   *  Gain: '<S4>/Force balance'
   */
  for (j = 0; j < 495; j++) {
    rtb_Forcebalance_b[j] = 0.0;
    for (denIdx = 0; denIdx < 165; denIdx++) {
      rtb_Forcebalance_b[j] += M1LocalControl_wBM0_ConstP.pooled14[495 * denIdx
        + j] * tmp_0[denIdx];
    }
  }

  /* Gain: '<S4>/Force balance' incorporates:
   *  Sum: '<S1>/Sum'
   */
  for (j = 0; j < 335; j++) {
    rtb_Forcebalance[j] = 0.0;
    for (denIdx = 0; denIdx < 495; denIdx++) {
      rtb_Forcebalance[j] += M1LocalControl_wBM0_ConstP.pooled15[335 * denIdx +
        j] * rtb_Forcebalance_b[denIdx];
    }
  }

  /* Gain: '<S5>/Gain' incorporates:
   *  Gain: '<S5>/Gain1'
   *  Inport: '<Root>/Feedback'
   */
  for (j = 0; j < 165; j++) {
    tmp_0[j] = 0.0;
    for (denIdx = 0; denIdx < 27; denIdx++) {
      tmp_0[j] += M1LocalControl_wBM0_ConstP.pooled13[165 * denIdx + j] *
        M1LocalControl_wBM0_U.Feedback[69 + denIdx];
    }
  }

  /* End of Gain: '<S5>/Gain' */

  /* Gain: '<S5>/Gain1' incorporates:
   *  Gain: '<S5>/Force balance'
   */
  for (j = 0; j < 495; j++) {
    rtb_Forcebalance_b[j] = 0.0;
    for (denIdx = 0; denIdx < 165; denIdx++) {
      rtb_Forcebalance_b[j] += M1LocalControl_wBM0_ConstP.pooled14[495 * denIdx
        + j] * tmp_0[denIdx];
    }
  }

  /* Gain: '<S5>/Force balance' incorporates:
   *  Sum: '<S1>/Sum'
   */
  for (j = 0; j < 335; j++) {
    rtb_Forcebalance_h[j] = 0.0;
    for (denIdx = 0; denIdx < 495; denIdx++) {
      rtb_Forcebalance_h[j] += M1LocalControl_wBM0_ConstP.pooled15[335 * denIdx
        + j] * rtb_Forcebalance_b[denIdx];
    }
  }

  /* Gain: '<S6>/Gain' incorporates:
   *  Gain: '<S6>/Gain1'
   *  Inport: '<Root>/Feedback'
   */
  for (j = 0; j < 165; j++) {
    tmp_0[j] = 0.0;
    for (denIdx = 0; denIdx < 27; denIdx++) {
      tmp_0[j] += M1LocalControl_wBM0_ConstP.pooled13[165 * denIdx + j] *
        M1LocalControl_wBM0_U.Feedback[96 + denIdx];
    }
  }

  /* End of Gain: '<S6>/Gain' */

  /* Gain: '<S6>/Gain1' incorporates:
   *  Gain: '<S6>/Force balance'
   */
  for (j = 0; j < 495; j++) {
    rtb_Forcebalance_b[j] = 0.0;
    for (denIdx = 0; denIdx < 165; denIdx++) {
      rtb_Forcebalance_b[j] += M1LocalControl_wBM0_ConstP.pooled14[495 * denIdx
        + j] * tmp_0[denIdx];
    }
  }

  /* Gain: '<S6>/Force balance' incorporates:
   *  Sum: '<S1>/Sum'
   */
  for (j = 0; j < 335; j++) {
    rtb_Forcebalance_n[j] = 0.0;
    for (denIdx = 0; denIdx < 495; denIdx++) {
      rtb_Forcebalance_n[j] += M1LocalControl_wBM0_ConstP.pooled15[335 * denIdx
        + j] * rtb_Forcebalance_b[denIdx];
    }
  }

  /* Gain: '<S7>/Gain' incorporates:
   *  Gain: '<S7>/Gain1'
   *  Inport: '<Root>/Feedback'
   */
  for (j = 0; j < 165; j++) {
    tmp_0[j] = 0.0;
    for (denIdx = 0; denIdx < 27; denIdx++) {
      tmp_0[j] += M1LocalControl_wBM0_ConstP.pooled13[165 * denIdx + j] *
        M1LocalControl_wBM0_U.Feedback[123 + denIdx];
    }
  }

  /* End of Gain: '<S7>/Gain' */

  /* Gain: '<S7>/Gain1' incorporates:
   *  Gain: '<S7>/Force balance'
   */
  for (j = 0; j < 495; j++) {
    rtb_Forcebalance_b[j] = 0.0;
    for (denIdx = 0; denIdx < 165; denIdx++) {
      rtb_Forcebalance_b[j] += M1LocalControl_wBM0_ConstP.pooled14[495 * denIdx
        + j] * tmp_0[denIdx];
    }
  }

  /* Gain: '<S7>/Force balance' incorporates:
   *  Sum: '<S1>/Sum'
   */
  for (j = 0; j < 335; j++) {
    rtb_Forcebalance_e4[j] = 0.0;
    for (denIdx = 0; denIdx < 495; denIdx++) {
      rtb_Forcebalance_e4[j] += M1LocalControl_wBM0_ConstP.pooled15[335 * denIdx
        + j] * rtb_Forcebalance_b[denIdx];
    }
  }

  /* Gain: '<S8>/Gain' incorporates:
   *  Gain: '<S8>/Gain1'
   *  Inport: '<Root>/Feedback'
   */
  for (j = 0; j < 165; j++) {
    tmp_0[j] = 0.0;
    for (denIdx = 0; denIdx < 27; denIdx++) {
      tmp_0[j] += M1LocalControl_wBM0_ConstP.pooled13[165 * denIdx + j] *
        M1LocalControl_wBM0_U.Feedback[150 + denIdx];
    }
  }

  /* End of Gain: '<S8>/Gain' */

  /* Gain: '<S8>/Gain1' incorporates:
   *  Gain: '<S8>/Force balance'
   */
  for (j = 0; j < 495; j++) {
    rtb_Forcebalance_b[j] = 0.0;
    for (denIdx = 0; denIdx < 165; denIdx++) {
      rtb_Forcebalance_b[j] += M1LocalControl_wBM0_ConstP.pooled14[495 * denIdx
        + j] * tmp_0[denIdx];
    }
  }

  /* Gain: '<S8>/Force balance' incorporates:
   *  Sum: '<S1>/Sum'
   */
  for (j = 0; j < 335; j++) {
    tmp_1[j] = 0.0;
    for (denIdx = 0; denIdx < 495; denIdx++) {
      tmp_1[j] += M1LocalControl_wBM0_ConstP.pooled15[335 * denIdx + j] *
        rtb_Forcebalance_b[denIdx];
    }
  }

  /* Gain: '<S9>/Gain' incorporates:
   *  Gain: '<S9>/Gain1'
   *  Inport: '<Root>/Feedback'
   */
  for (j = 0; j < 165; j++) {
    tmp_0[j] = 0.0;
    for (denIdx = 0; denIdx < 27; denIdx++) {
      tmp_0[j] += M1LocalControl_wBM0_ConstP.pooled13[165 * denIdx + j] *
        M1LocalControl_wBM0_U.Feedback[177 + denIdx];
    }
  }

  /* End of Gain: '<S9>/Gain' */

  /* Gain: '<S9>/Gain1' incorporates:
   *  Gain: '<S9>/Force balance'
   */
  for (j = 0; j < 495; j++) {
    rtb_Forcebalance_b[j] = 0.0;
    for (denIdx = 0; denIdx < 165; denIdx++) {
      rtb_Forcebalance_b[j] += M1LocalControl_wBM0_ConstP.pooled14[495 * denIdx
        + j] * tmp_0[denIdx];
    }
  }

  /* Gain: '<S9>/Force balance' incorporates:
   *  Sum: '<S1>/Sum'
   */
  for (j = 0; j < 335; j++) {
    tmp_2[j] = 0.0;
    for (denIdx = 0; denIdx < 495; denIdx++) {
      tmp_2[j] += M1LocalControl_wBM0_ConstP.pooled15[335 * denIdx + j] *
        rtb_Forcebalance_b[denIdx];
    }
  }

  /* Gain: '<S10>/Gain' incorporates:
   *  Gain: '<S10>/Gain1'
   *  Inport: '<Root>/Feedback'
   */
  for (j = 0; j < 154; j++) {
    tmp_3[j] = 0.0;
    for (denIdx = 0; denIdx < 27; denIdx++) {
      tmp_3[j] += M1LocalControl_wBM0_ConstP.Gain_Gain[154 * denIdx + j] *
        M1LocalControl_wBM0_U.Feedback[204 + denIdx];
    }
  }

  /* End of Gain: '<S10>/Gain' */

  /* Gain: '<S10>/Gain1' incorporates:
   *  Gain: '<S10>/Force balance'
   */
  for (j = 0; j < 462; j++) {
    tmp_4[j] = 0.0;
    for (denIdx = 0; denIdx < 154; denIdx++) {
      tmp_4[j] += M1LocalControl_wBM0_ConstP.Gain1_Gain[462 * denIdx + j] *
        tmp_3[denIdx];
    }
  }

  /* Gain: '<S10>/Force balance' incorporates:
   *  Sum: '<S1>/Sum'
   */
  for (j = 0; j < 306; j++) {
    tmp[j] = 0.0;
    for (denIdx = 0; denIdx < 462; denIdx++) {
      tmp[j] += M1LocalControl_wBM0_ConstP.Forcebalance_Gain_j[306 * denIdx + j]
        * tmp_4[denIdx];
    }
  }

  /* Sum: '<S1>/Sum' */
  for (j = 0; j < 335; j++) {
    M1LocalControl_wBM0_B.rtb_Quantizer_m[j] = rtb_Forcebalance[j];
    M1LocalControl_wBM0_B.rtb_Quantizer_m[j + 335] = rtb_Forcebalance_h[j];
    M1LocalControl_wBM0_B.rtb_Quantizer_m[j + 670] = rtb_Forcebalance_n[j];
    M1LocalControl_wBM0_B.rtb_Quantizer_m[j + 1005] = rtb_Forcebalance_e4[j];
    M1LocalControl_wBM0_B.rtb_Quantizer_m[j + 1340] = tmp_1[j];
    M1LocalControl_wBM0_B.rtb_Quantizer_m[j + 1675] = tmp_2[j];
  }

  memcpy(&M1LocalControl_wBM0_B.rtb_Quantizer_m[2010], &tmp[0], 306U * sizeof
         (real_T));

  /* Outport: '<Root>/Output' incorporates:
   *  Sum: '<S1>/Sum'
   */
  for (j = 0; j < 2316; j++) {
    M1LocalControl_wBM0_Y.Output[j] = M1LocalControl_wBM0_B.Quantizer[j] +
      M1LocalControl_wBM0_B.rtb_Quantizer_m[j];
  }

  /* End of Outport: '<Root>/Output' */
  for (j = 0; j < 6; j++) {
    /* Gain: '<S11>/MHP' */
    MHP[j] = 0.0;

    /* Gain: '<S12>/MHP' */
    MHP_d[j] = 0.0;

    /* Gain: '<S13>/MHP' */
    MHP_k[j] = 0.0;

    /* Gain: '<S14>/MHP' */
    MHP_dr[j] = 0.0;

    /* Gain: '<S15>/MHP' */
    MHP_f[j] = 0.0;

    /* Gain: '<S16>/MHP' */
    MHP_m[j] = 0.0;

    /* Gain: '<S17>/MHP' */
    MHP_c[j] = 0.0;
    for (denIdx = 0; denIdx < 6; denIdx++) {
      /* Gain: '<S11>/MHP' incorporates:
       *  Gain: '<S12>/MHP'
       *  Gain: '<S13>/MHP'
       *  Gain: '<S14>/MHP'
       *  Gain: '<S15>/MHP'
       *  Gain: '<S16>/MHP'
       *  Gain: '<S17>/MHP'
       *  Inport: '<Root>/Feedback'
       */
      denIdx_0 = 6 * denIdx + j;
      MHP[j] += M1LocalControl_wBM0_ConstP.MHP_Gain[denIdx_0] *
        M1LocalControl_wBM0_U.Feedback[denIdx];

      /* Gain: '<S12>/MHP' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      MHP_d[j] += M1LocalControl_wBM0_ConstP.MHP_Gain_i[denIdx_0] *
        M1LocalControl_wBM0_U.Feedback[6 + denIdx];

      /* Gain: '<S13>/MHP' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      MHP_k[j] += M1LocalControl_wBM0_ConstP.MHP_Gain_c[denIdx_0] *
        M1LocalControl_wBM0_U.Feedback[12 + denIdx];

      /* Gain: '<S14>/MHP' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      MHP_dr[j] += M1LocalControl_wBM0_ConstP.MHP_Gain_j[denIdx_0] *
        M1LocalControl_wBM0_U.Feedback[18 + denIdx];

      /* Gain: '<S15>/MHP' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      MHP_f[j] += M1LocalControl_wBM0_ConstP.MHP_Gain_ii[denIdx_0] *
        M1LocalControl_wBM0_U.Feedback[24 + denIdx];

      /* Gain: '<S16>/MHP' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      MHP_m[j] += M1LocalControl_wBM0_ConstP.MHP_Gain_p[denIdx_0] *
        M1LocalControl_wBM0_U.Feedback[30 + denIdx];

      /* Gain: '<S17>/MHP' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      MHP_c[j] += M1LocalControl_wBM0_ConstP.MHP_Gain_k[denIdx_0] *
        M1LocalControl_wBM0_U.Feedback[36 + denIdx];
    }
  }

  /* Update for DiscreteTransferFcn: '<S11>/Fx Controller' */
  numAccum = ((MHP[0] - -2.97089706562984 *
               M1LocalControl_wBM0_DW.FxController_states[0]) -
              2.9430254610319251 * M1LocalControl_wBM0_DW.FxController_states[1])
    - -0.9721283954020854 * M1LocalControl_wBM0_DW.FxController_states[2];
  M1LocalControl_wBM0_DW.FxController_states[2] =
    M1LocalControl_wBM0_DW.FxController_states[1];
  M1LocalControl_wBM0_DW.FxController_states[1] =
    M1LocalControl_wBM0_DW.FxController_states[0];
  M1LocalControl_wBM0_DW.FxController_states[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S11>/Fy Controller' */
  numAccum = ((MHP[1] - -2.97089706562984 *
               M1LocalControl_wBM0_DW.FyController_states[0]) -
              2.9430254610319251 * M1LocalControl_wBM0_DW.FyController_states[1])
    - -0.9721283954020854 * M1LocalControl_wBM0_DW.FyController_states[2];
  M1LocalControl_wBM0_DW.FyController_states[2] =
    M1LocalControl_wBM0_DW.FyController_states[1];
  M1LocalControl_wBM0_DW.FyController_states[1] =
    M1LocalControl_wBM0_DW.FyController_states[0];
  M1LocalControl_wBM0_DW.FyController_states[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S11>/Fz Controller' */
  numAccum = ((MHP[2] - -2.935316245552321 *
               M1LocalControl_wBM0_DW.FzController_states[0]) -
              2.8744564263243495 * M1LocalControl_wBM0_DW.FzController_states[1])
    - -0.93914018077202877 * M1LocalControl_wBM0_DW.FzController_states[2];
  M1LocalControl_wBM0_DW.FzController_states[2] =
    M1LocalControl_wBM0_DW.FzController_states[1];
  M1LocalControl_wBM0_DW.FzController_states[1] =
    M1LocalControl_wBM0_DW.FzController_states[0];
  M1LocalControl_wBM0_DW.FzController_states[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S11>/Mx Controller' */
  numAccum = MHP[3];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl_wBM0_ConstP.pooled7[denIdx] *
      M1LocalControl_wBM0_DW.MxController_states[j];
    denIdx++;
  }

  M1LocalControl_wBM0_DW.MxController_states[4] =
    M1LocalControl_wBM0_DW.MxController_states[3];
  M1LocalControl_wBM0_DW.MxController_states[3] =
    M1LocalControl_wBM0_DW.MxController_states[2];
  M1LocalControl_wBM0_DW.MxController_states[2] =
    M1LocalControl_wBM0_DW.MxController_states[1];
  M1LocalControl_wBM0_DW.MxController_states[1] =
    M1LocalControl_wBM0_DW.MxController_states[0];
  M1LocalControl_wBM0_DW.MxController_states[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S11>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S11>/My Controller' */
  numAccum = MHP[4];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl_wBM0_ConstP.pooled7[denIdx] *
      M1LocalControl_wBM0_DW.MyController_states[j];
    denIdx++;
  }

  M1LocalControl_wBM0_DW.MyController_states[4] =
    M1LocalControl_wBM0_DW.MyController_states[3];
  M1LocalControl_wBM0_DW.MyController_states[3] =
    M1LocalControl_wBM0_DW.MyController_states[2];
  M1LocalControl_wBM0_DW.MyController_states[2] =
    M1LocalControl_wBM0_DW.MyController_states[1];
  M1LocalControl_wBM0_DW.MyController_states[1] =
    M1LocalControl_wBM0_DW.MyController_states[0];
  M1LocalControl_wBM0_DW.MyController_states[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S11>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S11>/Mz Controller' */
  numAccum = ((MHP[5] - -2.9551479035479664 *
               M1LocalControl_wBM0_DW.MzController_states[0]) -
              2.9141589271132933 * M1LocalControl_wBM0_DW.MzController_states[1])
    - -0.95901102356532664 * M1LocalControl_wBM0_DW.MzController_states[2];
  M1LocalControl_wBM0_DW.MzController_states[2] =
    M1LocalControl_wBM0_DW.MzController_states[1];
  M1LocalControl_wBM0_DW.MzController_states[1] =
    M1LocalControl_wBM0_DW.MzController_states[0];
  M1LocalControl_wBM0_DW.MzController_states[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S12>/Fx Controller' */
  numAccum = ((MHP_d[0] - -2.97089706562984 *
               M1LocalControl_wBM0_DW.FxController_states_f[0]) -
              2.9430254610319251 * M1LocalControl_wBM0_DW.FxController_states_f
              [1]) - -0.9721283954020854 *
    M1LocalControl_wBM0_DW.FxController_states_f[2];
  M1LocalControl_wBM0_DW.FxController_states_f[2] =
    M1LocalControl_wBM0_DW.FxController_states_f[1];
  M1LocalControl_wBM0_DW.FxController_states_f[1] =
    M1LocalControl_wBM0_DW.FxController_states_f[0];
  M1LocalControl_wBM0_DW.FxController_states_f[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S12>/Fy Controller' */
  numAccum = ((MHP_d[1] - -2.97089706562984 *
               M1LocalControl_wBM0_DW.FyController_states_p[0]) -
              2.9430254610319251 * M1LocalControl_wBM0_DW.FyController_states_p
              [1]) - -0.9721283954020854 *
    M1LocalControl_wBM0_DW.FyController_states_p[2];
  M1LocalControl_wBM0_DW.FyController_states_p[2] =
    M1LocalControl_wBM0_DW.FyController_states_p[1];
  M1LocalControl_wBM0_DW.FyController_states_p[1] =
    M1LocalControl_wBM0_DW.FyController_states_p[0];
  M1LocalControl_wBM0_DW.FyController_states_p[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S12>/Fz Controller' */
  numAccum = ((MHP_d[2] - -2.935316245552321 *
               M1LocalControl_wBM0_DW.FzController_states_a[0]) -
              2.8744564263243495 * M1LocalControl_wBM0_DW.FzController_states_a
              [1]) - -0.93914018077202877 *
    M1LocalControl_wBM0_DW.FzController_states_a[2];
  M1LocalControl_wBM0_DW.FzController_states_a[2] =
    M1LocalControl_wBM0_DW.FzController_states_a[1];
  M1LocalControl_wBM0_DW.FzController_states_a[1] =
    M1LocalControl_wBM0_DW.FzController_states_a[0];
  M1LocalControl_wBM0_DW.FzController_states_a[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S12>/Mx Controller' */
  numAccum = MHP_d[3];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl_wBM0_ConstP.pooled7[denIdx] *
      M1LocalControl_wBM0_DW.MxController_states_c[j];
    denIdx++;
  }

  M1LocalControl_wBM0_DW.MxController_states_c[4] =
    M1LocalControl_wBM0_DW.MxController_states_c[3];
  M1LocalControl_wBM0_DW.MxController_states_c[3] =
    M1LocalControl_wBM0_DW.MxController_states_c[2];
  M1LocalControl_wBM0_DW.MxController_states_c[2] =
    M1LocalControl_wBM0_DW.MxController_states_c[1];
  M1LocalControl_wBM0_DW.MxController_states_c[1] =
    M1LocalControl_wBM0_DW.MxController_states_c[0];
  M1LocalControl_wBM0_DW.MxController_states_c[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S12>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S12>/My Controller' */
  numAccum = MHP_d[4];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl_wBM0_ConstP.pooled7[denIdx] *
      M1LocalControl_wBM0_DW.MyController_states_i[j];
    denIdx++;
  }

  M1LocalControl_wBM0_DW.MyController_states_i[4] =
    M1LocalControl_wBM0_DW.MyController_states_i[3];
  M1LocalControl_wBM0_DW.MyController_states_i[3] =
    M1LocalControl_wBM0_DW.MyController_states_i[2];
  M1LocalControl_wBM0_DW.MyController_states_i[2] =
    M1LocalControl_wBM0_DW.MyController_states_i[1];
  M1LocalControl_wBM0_DW.MyController_states_i[1] =
    M1LocalControl_wBM0_DW.MyController_states_i[0];
  M1LocalControl_wBM0_DW.MyController_states_i[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S12>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S12>/Mz Controller' */
  numAccum = ((MHP_d[5] - -2.9551479035479664 *
               M1LocalControl_wBM0_DW.MzController_states_e[0]) -
              2.9141589271132933 * M1LocalControl_wBM0_DW.MzController_states_e
              [1]) - -0.95901102356532664 *
    M1LocalControl_wBM0_DW.MzController_states_e[2];
  M1LocalControl_wBM0_DW.MzController_states_e[2] =
    M1LocalControl_wBM0_DW.MzController_states_e[1];
  M1LocalControl_wBM0_DW.MzController_states_e[1] =
    M1LocalControl_wBM0_DW.MzController_states_e[0];
  M1LocalControl_wBM0_DW.MzController_states_e[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S13>/Fx Controller' */
  numAccum = ((MHP_k[0] - -2.97089706562984 *
               M1LocalControl_wBM0_DW.FxController_states_j[0]) -
              2.9430254610319251 * M1LocalControl_wBM0_DW.FxController_states_j
              [1]) - -0.9721283954020854 *
    M1LocalControl_wBM0_DW.FxController_states_j[2];
  M1LocalControl_wBM0_DW.FxController_states_j[2] =
    M1LocalControl_wBM0_DW.FxController_states_j[1];
  M1LocalControl_wBM0_DW.FxController_states_j[1] =
    M1LocalControl_wBM0_DW.FxController_states_j[0];
  M1LocalControl_wBM0_DW.FxController_states_j[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S13>/Fy Controller' */
  numAccum = ((MHP_k[1] - -2.97089706562984 *
               M1LocalControl_wBM0_DW.FyController_states_d[0]) -
              2.9430254610319251 * M1LocalControl_wBM0_DW.FyController_states_d
              [1]) - -0.9721283954020854 *
    M1LocalControl_wBM0_DW.FyController_states_d[2];
  M1LocalControl_wBM0_DW.FyController_states_d[2] =
    M1LocalControl_wBM0_DW.FyController_states_d[1];
  M1LocalControl_wBM0_DW.FyController_states_d[1] =
    M1LocalControl_wBM0_DW.FyController_states_d[0];
  M1LocalControl_wBM0_DW.FyController_states_d[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S13>/Fz Controller' */
  numAccum = ((MHP_k[2] - -2.935316245552321 *
               M1LocalControl_wBM0_DW.FzController_states_ac[0]) -
              2.8744564263243495 *
              M1LocalControl_wBM0_DW.FzController_states_ac[1]) -
    -0.93914018077202877 * M1LocalControl_wBM0_DW.FzController_states_ac[2];
  M1LocalControl_wBM0_DW.FzController_states_ac[2] =
    M1LocalControl_wBM0_DW.FzController_states_ac[1];
  M1LocalControl_wBM0_DW.FzController_states_ac[1] =
    M1LocalControl_wBM0_DW.FzController_states_ac[0];
  M1LocalControl_wBM0_DW.FzController_states_ac[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S13>/Mx Controller' */
  numAccum = MHP_k[3];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl_wBM0_ConstP.pooled7[denIdx] *
      M1LocalControl_wBM0_DW.MxController_states_d[j];
    denIdx++;
  }

  M1LocalControl_wBM0_DW.MxController_states_d[4] =
    M1LocalControl_wBM0_DW.MxController_states_d[3];
  M1LocalControl_wBM0_DW.MxController_states_d[3] =
    M1LocalControl_wBM0_DW.MxController_states_d[2];
  M1LocalControl_wBM0_DW.MxController_states_d[2] =
    M1LocalControl_wBM0_DW.MxController_states_d[1];
  M1LocalControl_wBM0_DW.MxController_states_d[1] =
    M1LocalControl_wBM0_DW.MxController_states_d[0];
  M1LocalControl_wBM0_DW.MxController_states_d[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S13>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S13>/My Controller' */
  numAccum = MHP_k[4];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl_wBM0_ConstP.pooled7[denIdx] *
      M1LocalControl_wBM0_DW.MyController_states_n[j];
    denIdx++;
  }

  M1LocalControl_wBM0_DW.MyController_states_n[4] =
    M1LocalControl_wBM0_DW.MyController_states_n[3];
  M1LocalControl_wBM0_DW.MyController_states_n[3] =
    M1LocalControl_wBM0_DW.MyController_states_n[2];
  M1LocalControl_wBM0_DW.MyController_states_n[2] =
    M1LocalControl_wBM0_DW.MyController_states_n[1];
  M1LocalControl_wBM0_DW.MyController_states_n[1] =
    M1LocalControl_wBM0_DW.MyController_states_n[0];
  M1LocalControl_wBM0_DW.MyController_states_n[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S13>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S13>/Mz Controller' */
  numAccum = ((MHP_k[5] - -2.9551479035479664 *
               M1LocalControl_wBM0_DW.MzController_states_n[0]) -
              2.9141589271132933 * M1LocalControl_wBM0_DW.MzController_states_n
              [1]) - -0.95901102356532664 *
    M1LocalControl_wBM0_DW.MzController_states_n[2];
  M1LocalControl_wBM0_DW.MzController_states_n[2] =
    M1LocalControl_wBM0_DW.MzController_states_n[1];
  M1LocalControl_wBM0_DW.MzController_states_n[1] =
    M1LocalControl_wBM0_DW.MzController_states_n[0];
  M1LocalControl_wBM0_DW.MzController_states_n[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S14>/Fx Controller' */
  numAccum = ((MHP_dr[0] - -2.97089706562984 *
               M1LocalControl_wBM0_DW.FxController_states_n[0]) -
              2.9430254610319251 * M1LocalControl_wBM0_DW.FxController_states_n
              [1]) - -0.9721283954020854 *
    M1LocalControl_wBM0_DW.FxController_states_n[2];
  M1LocalControl_wBM0_DW.FxController_states_n[2] =
    M1LocalControl_wBM0_DW.FxController_states_n[1];
  M1LocalControl_wBM0_DW.FxController_states_n[1] =
    M1LocalControl_wBM0_DW.FxController_states_n[0];
  M1LocalControl_wBM0_DW.FxController_states_n[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S14>/Fy Controller' */
  numAccum = ((MHP_dr[1] - -2.97089706562984 *
               M1LocalControl_wBM0_DW.FyController_states_e[0]) -
              2.9430254610319251 * M1LocalControl_wBM0_DW.FyController_states_e
              [1]) - -0.9721283954020854 *
    M1LocalControl_wBM0_DW.FyController_states_e[2];
  M1LocalControl_wBM0_DW.FyController_states_e[2] =
    M1LocalControl_wBM0_DW.FyController_states_e[1];
  M1LocalControl_wBM0_DW.FyController_states_e[1] =
    M1LocalControl_wBM0_DW.FyController_states_e[0];
  M1LocalControl_wBM0_DW.FyController_states_e[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S14>/Fz Controller' */
  numAccum = ((MHP_dr[2] - -2.935316245552321 *
               M1LocalControl_wBM0_DW.FzController_states_c[0]) -
              2.8744564263243495 * M1LocalControl_wBM0_DW.FzController_states_c
              [1]) - -0.93914018077202877 *
    M1LocalControl_wBM0_DW.FzController_states_c[2];
  M1LocalControl_wBM0_DW.FzController_states_c[2] =
    M1LocalControl_wBM0_DW.FzController_states_c[1];
  M1LocalControl_wBM0_DW.FzController_states_c[1] =
    M1LocalControl_wBM0_DW.FzController_states_c[0];
  M1LocalControl_wBM0_DW.FzController_states_c[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S14>/Mx Controller' */
  numAccum = MHP_dr[3];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl_wBM0_ConstP.pooled7[denIdx] *
      M1LocalControl_wBM0_DW.MxController_states_f[j];
    denIdx++;
  }

  M1LocalControl_wBM0_DW.MxController_states_f[4] =
    M1LocalControl_wBM0_DW.MxController_states_f[3];
  M1LocalControl_wBM0_DW.MxController_states_f[3] =
    M1LocalControl_wBM0_DW.MxController_states_f[2];
  M1LocalControl_wBM0_DW.MxController_states_f[2] =
    M1LocalControl_wBM0_DW.MxController_states_f[1];
  M1LocalControl_wBM0_DW.MxController_states_f[1] =
    M1LocalControl_wBM0_DW.MxController_states_f[0];
  M1LocalControl_wBM0_DW.MxController_states_f[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S14>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S14>/My Controller' */
  numAccum = MHP_dr[4];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl_wBM0_ConstP.pooled7[denIdx] *
      M1LocalControl_wBM0_DW.MyController_states_g[j];
    denIdx++;
  }

  M1LocalControl_wBM0_DW.MyController_states_g[4] =
    M1LocalControl_wBM0_DW.MyController_states_g[3];
  M1LocalControl_wBM0_DW.MyController_states_g[3] =
    M1LocalControl_wBM0_DW.MyController_states_g[2];
  M1LocalControl_wBM0_DW.MyController_states_g[2] =
    M1LocalControl_wBM0_DW.MyController_states_g[1];
  M1LocalControl_wBM0_DW.MyController_states_g[1] =
    M1LocalControl_wBM0_DW.MyController_states_g[0];
  M1LocalControl_wBM0_DW.MyController_states_g[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S14>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S14>/Mz Controller' */
  numAccum = ((MHP_dr[5] - -2.9551479035479664 *
               M1LocalControl_wBM0_DW.MzController_states_h[0]) -
              2.9141589271132933 * M1LocalControl_wBM0_DW.MzController_states_h
              [1]) - -0.95901102356532664 *
    M1LocalControl_wBM0_DW.MzController_states_h[2];
  M1LocalControl_wBM0_DW.MzController_states_h[2] =
    M1LocalControl_wBM0_DW.MzController_states_h[1];
  M1LocalControl_wBM0_DW.MzController_states_h[1] =
    M1LocalControl_wBM0_DW.MzController_states_h[0];
  M1LocalControl_wBM0_DW.MzController_states_h[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S15>/Fx Controller' */
  numAccum = ((MHP_f[0] - -2.97089706562984 *
               M1LocalControl_wBM0_DW.FxController_states_o[0]) -
              2.9430254610319251 * M1LocalControl_wBM0_DW.FxController_states_o
              [1]) - -0.9721283954020854 *
    M1LocalControl_wBM0_DW.FxController_states_o[2];
  M1LocalControl_wBM0_DW.FxController_states_o[2] =
    M1LocalControl_wBM0_DW.FxController_states_o[1];
  M1LocalControl_wBM0_DW.FxController_states_o[1] =
    M1LocalControl_wBM0_DW.FxController_states_o[0];
  M1LocalControl_wBM0_DW.FxController_states_o[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S15>/Fy Controller' */
  numAccum = ((MHP_f[1] - -2.97089706562984 *
               M1LocalControl_wBM0_DW.FyController_states_n[0]) -
              2.9430254610319251 * M1LocalControl_wBM0_DW.FyController_states_n
              [1]) - -0.9721283954020854 *
    M1LocalControl_wBM0_DW.FyController_states_n[2];
  M1LocalControl_wBM0_DW.FyController_states_n[2] =
    M1LocalControl_wBM0_DW.FyController_states_n[1];
  M1LocalControl_wBM0_DW.FyController_states_n[1] =
    M1LocalControl_wBM0_DW.FyController_states_n[0];
  M1LocalControl_wBM0_DW.FyController_states_n[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S15>/Fz Controller' */
  numAccum = ((MHP_f[2] - -2.935316245552321 *
               M1LocalControl_wBM0_DW.FzController_states_k[0]) -
              2.8744564263243495 * M1LocalControl_wBM0_DW.FzController_states_k
              [1]) - -0.93914018077202877 *
    M1LocalControl_wBM0_DW.FzController_states_k[2];
  M1LocalControl_wBM0_DW.FzController_states_k[2] =
    M1LocalControl_wBM0_DW.FzController_states_k[1];
  M1LocalControl_wBM0_DW.FzController_states_k[1] =
    M1LocalControl_wBM0_DW.FzController_states_k[0];
  M1LocalControl_wBM0_DW.FzController_states_k[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S15>/Mx Controller' */
  numAccum = MHP_f[3];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl_wBM0_ConstP.pooled7[denIdx] *
      M1LocalControl_wBM0_DW.MxController_states_k[j];
    denIdx++;
  }

  M1LocalControl_wBM0_DW.MxController_states_k[4] =
    M1LocalControl_wBM0_DW.MxController_states_k[3];
  M1LocalControl_wBM0_DW.MxController_states_k[3] =
    M1LocalControl_wBM0_DW.MxController_states_k[2];
  M1LocalControl_wBM0_DW.MxController_states_k[2] =
    M1LocalControl_wBM0_DW.MxController_states_k[1];
  M1LocalControl_wBM0_DW.MxController_states_k[1] =
    M1LocalControl_wBM0_DW.MxController_states_k[0];
  M1LocalControl_wBM0_DW.MxController_states_k[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S15>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S15>/My Controller' */
  numAccum = MHP_f[4];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl_wBM0_ConstP.pooled7[denIdx] *
      M1LocalControl_wBM0_DW.MyController_states_k[j];
    denIdx++;
  }

  M1LocalControl_wBM0_DW.MyController_states_k[4] =
    M1LocalControl_wBM0_DW.MyController_states_k[3];
  M1LocalControl_wBM0_DW.MyController_states_k[3] =
    M1LocalControl_wBM0_DW.MyController_states_k[2];
  M1LocalControl_wBM0_DW.MyController_states_k[2] =
    M1LocalControl_wBM0_DW.MyController_states_k[1];
  M1LocalControl_wBM0_DW.MyController_states_k[1] =
    M1LocalControl_wBM0_DW.MyController_states_k[0];
  M1LocalControl_wBM0_DW.MyController_states_k[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S15>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S15>/Mz Controller' */
  numAccum = ((MHP_f[5] - -2.9551479035479664 *
               M1LocalControl_wBM0_DW.MzController_states_i[0]) -
              2.9141589271132933 * M1LocalControl_wBM0_DW.MzController_states_i
              [1]) - -0.95901102356532664 *
    M1LocalControl_wBM0_DW.MzController_states_i[2];
  M1LocalControl_wBM0_DW.MzController_states_i[2] =
    M1LocalControl_wBM0_DW.MzController_states_i[1];
  M1LocalControl_wBM0_DW.MzController_states_i[1] =
    M1LocalControl_wBM0_DW.MzController_states_i[0];
  M1LocalControl_wBM0_DW.MzController_states_i[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S16>/Fx Controller' */
  numAccum = ((MHP_m[0] - -2.97089706562984 *
               M1LocalControl_wBM0_DW.FxController_states_b[0]) -
              2.9430254610319251 * M1LocalControl_wBM0_DW.FxController_states_b
              [1]) - -0.9721283954020854 *
    M1LocalControl_wBM0_DW.FxController_states_b[2];
  M1LocalControl_wBM0_DW.FxController_states_b[2] =
    M1LocalControl_wBM0_DW.FxController_states_b[1];
  M1LocalControl_wBM0_DW.FxController_states_b[1] =
    M1LocalControl_wBM0_DW.FxController_states_b[0];
  M1LocalControl_wBM0_DW.FxController_states_b[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S16>/Fy Controller' */
  numAccum = ((MHP_m[1] - -2.97089706562984 *
               M1LocalControl_wBM0_DW.FyController_states_c[0]) -
              2.9430254610319251 * M1LocalControl_wBM0_DW.FyController_states_c
              [1]) - -0.9721283954020854 *
    M1LocalControl_wBM0_DW.FyController_states_c[2];
  M1LocalControl_wBM0_DW.FyController_states_c[2] =
    M1LocalControl_wBM0_DW.FyController_states_c[1];
  M1LocalControl_wBM0_DW.FyController_states_c[1] =
    M1LocalControl_wBM0_DW.FyController_states_c[0];
  M1LocalControl_wBM0_DW.FyController_states_c[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S16>/Fz Controller' */
  numAccum = ((MHP_m[2] - -2.935316245552321 *
               M1LocalControl_wBM0_DW.FzController_states_l[0]) -
              2.8744564263243495 * M1LocalControl_wBM0_DW.FzController_states_l
              [1]) - -0.93914018077202877 *
    M1LocalControl_wBM0_DW.FzController_states_l[2];
  M1LocalControl_wBM0_DW.FzController_states_l[2] =
    M1LocalControl_wBM0_DW.FzController_states_l[1];
  M1LocalControl_wBM0_DW.FzController_states_l[1] =
    M1LocalControl_wBM0_DW.FzController_states_l[0];
  M1LocalControl_wBM0_DW.FzController_states_l[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S16>/Mx Controller' */
  numAccum = MHP_m[3];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl_wBM0_ConstP.pooled7[denIdx] *
      M1LocalControl_wBM0_DW.MxController_states_m[j];
    denIdx++;
  }

  M1LocalControl_wBM0_DW.MxController_states_m[4] =
    M1LocalControl_wBM0_DW.MxController_states_m[3];
  M1LocalControl_wBM0_DW.MxController_states_m[3] =
    M1LocalControl_wBM0_DW.MxController_states_m[2];
  M1LocalControl_wBM0_DW.MxController_states_m[2] =
    M1LocalControl_wBM0_DW.MxController_states_m[1];
  M1LocalControl_wBM0_DW.MxController_states_m[1] =
    M1LocalControl_wBM0_DW.MxController_states_m[0];
  M1LocalControl_wBM0_DW.MxController_states_m[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S16>/Mx Controller' */

  /* Update for DiscreteTransferFcn: '<S16>/My Controller' */
  numAccum = MHP_m[4];
  denIdx = 1;
  for (j = 0; j < 5; j++) {
    numAccum -= M1LocalControl_wBM0_ConstP.pooled7[denIdx] *
      M1LocalControl_wBM0_DW.MyController_states_d[j];
    denIdx++;
  }

  M1LocalControl_wBM0_DW.MyController_states_d[4] =
    M1LocalControl_wBM0_DW.MyController_states_d[3];
  M1LocalControl_wBM0_DW.MyController_states_d[3] =
    M1LocalControl_wBM0_DW.MyController_states_d[2];
  M1LocalControl_wBM0_DW.MyController_states_d[2] =
    M1LocalControl_wBM0_DW.MyController_states_d[1];
  M1LocalControl_wBM0_DW.MyController_states_d[1] =
    M1LocalControl_wBM0_DW.MyController_states_d[0];
  M1LocalControl_wBM0_DW.MyController_states_d[0] = numAccum;

  /* End of Update for DiscreteTransferFcn: '<S16>/My Controller' */

  /* Update for DiscreteTransferFcn: '<S16>/Mz Controller' */
  numAccum = ((MHP_m[5] - -2.9551479035479664 *
               M1LocalControl_wBM0_DW.MzController_states_o[0]) -
              2.9141589271132933 * M1LocalControl_wBM0_DW.MzController_states_o
              [1]) - -0.95901102356532664 *
    M1LocalControl_wBM0_DW.MzController_states_o[2];
  M1LocalControl_wBM0_DW.MzController_states_o[2] =
    M1LocalControl_wBM0_DW.MzController_states_o[1];
  M1LocalControl_wBM0_DW.MzController_states_o[1] =
    M1LocalControl_wBM0_DW.MzController_states_o[0];
  M1LocalControl_wBM0_DW.MzController_states_o[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S17>/Fx Controller' */
  numAccum = ((MHP_c[0] - -2.97089706562984 *
               M1LocalControl_wBM0_DW.FxController_states_fe[0]) -
              2.9430254610319251 *
              M1LocalControl_wBM0_DW.FxController_states_fe[1]) -
    -0.9721283954020854 * M1LocalControl_wBM0_DW.FxController_states_fe[2];
  M1LocalControl_wBM0_DW.FxController_states_fe[2] =
    M1LocalControl_wBM0_DW.FxController_states_fe[1];
  M1LocalControl_wBM0_DW.FxController_states_fe[1] =
    M1LocalControl_wBM0_DW.FxController_states_fe[0];
  M1LocalControl_wBM0_DW.FxController_states_fe[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S17>/Fy Controller' */
  numAccum = ((MHP_c[1] - -2.9736051405026691 *
               M1LocalControl_wBM0_DW.FyController_states_h[0]) -
              2.9475609495552049 * M1LocalControl_wBM0_DW.FyController_states_h
              [1]) - -0.97395580905253565 *
    M1LocalControl_wBM0_DW.FyController_states_h[2];
  M1LocalControl_wBM0_DW.FyController_states_h[2] =
    M1LocalControl_wBM0_DW.FyController_states_h[1];
  M1LocalControl_wBM0_DW.FyController_states_h[1] =
    M1LocalControl_wBM0_DW.FyController_states_h[0];
  M1LocalControl_wBM0_DW.FyController_states_h[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S17>/Fz Controller' */
  numAccum = ((MHP_c[2] - -2.935316245552321 *
               M1LocalControl_wBM0_DW.FzController_states_j[0]) -
              2.8744564263243495 * M1LocalControl_wBM0_DW.FzController_states_j
              [1]) - -0.93914018077202877 *
    M1LocalControl_wBM0_DW.FzController_states_j[2];
  M1LocalControl_wBM0_DW.FzController_states_j[2] =
    M1LocalControl_wBM0_DW.FzController_states_j[1];
  M1LocalControl_wBM0_DW.FzController_states_j[1] =
    M1LocalControl_wBM0_DW.FzController_states_j[0];
  M1LocalControl_wBM0_DW.FzController_states_j[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S17>/Mx Controller' */
  numAccum = ((MHP_c[3] - -2.9736051405026691 *
               M1LocalControl_wBM0_DW.MxController_states_cu[0]) -
              2.9475609495552049 *
              M1LocalControl_wBM0_DW.MxController_states_cu[1]) -
    -0.97395580905253565 * M1LocalControl_wBM0_DW.MxController_states_cu[2];
  M1LocalControl_wBM0_DW.MxController_states_cu[2] =
    M1LocalControl_wBM0_DW.MxController_states_cu[1];
  M1LocalControl_wBM0_DW.MxController_states_cu[1] =
    M1LocalControl_wBM0_DW.MxController_states_cu[0];
  M1LocalControl_wBM0_DW.MxController_states_cu[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S17>/My Controller' */
  numAccum = ((MHP_c[4] - -2.9736051405026691 *
               M1LocalControl_wBM0_DW.MyController_states_a[0]) -
              2.9475609495552049 * M1LocalControl_wBM0_DW.MyController_states_a
              [1]) - -0.97395580905253565 *
    M1LocalControl_wBM0_DW.MyController_states_a[2];
  M1LocalControl_wBM0_DW.MyController_states_a[2] =
    M1LocalControl_wBM0_DW.MyController_states_a[1];
  M1LocalControl_wBM0_DW.MyController_states_a[1] =
    M1LocalControl_wBM0_DW.MyController_states_a[0];
  M1LocalControl_wBM0_DW.MyController_states_a[0] = numAccum;

  /* Update for DiscreteTransferFcn: '<S17>/Mz Controller' */
  numAccum = ((MHP_c[5] - -2.9736051405026691 *
               M1LocalControl_wBM0_DW.MzController_states_a[0]) -
              2.9475609495552049 * M1LocalControl_wBM0_DW.MzController_states_a
              [1]) - -0.97395580905253565 *
    M1LocalControl_wBM0_DW.MzController_states_a[2];
  M1LocalControl_wBM0_DW.MzController_states_a[2] =
    M1LocalControl_wBM0_DW.MzController_states_a[1];
  M1LocalControl_wBM0_DW.MzController_states_a[1] =
    M1LocalControl_wBM0_DW.MzController_states_a[0];
  M1LocalControl_wBM0_DW.MzController_states_a[0] = numAccum;
}

/* Model initialize function */
void M1LocalControl_wBM0_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1LocalControl_wBM0_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&M1LocalControl_wBM0_DW, 0,
                sizeof(DW_M1LocalControl_wBM0_T));

  /* external inputs */
  (void)memset((void *)&M1LocalControl_wBM0_U, 0, sizeof
               (ExtU_M1LocalControl_wBM0_T));

  /* external outputs */
  (void) memset(&M1LocalControl_wBM0_Y.Output[0], 0,
                2316U*sizeof(real_T));
}

/* Model terminate function */
void M1LocalControl_wBM0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
