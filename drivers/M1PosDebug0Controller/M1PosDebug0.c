/*
 * File: M1PosDebug0.c
 *
 * Code generated for Simulink model 'M1PosDebug0'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue Jan 21 11:06:08 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1PosDebug0.h"
#include "M1PosDebug0_private.h"

/* Block states (default storage) */
DW_M1PosDebug0_T M1PosDebug0_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M1PosDebug0_T M1PosDebug0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1PosDebug0_T M1PosDebug0_Y;

/* Real-time model */
RT_MODEL_M1PosDebug0_T M1PosDebug0_M_;
RT_MODEL_M1PosDebug0_T *const M1PosDebug0_M = &M1PosDebug0_M_;

/* Model step function */
void M1PosDebug0_step(void)
{
  int32_T k;
  int32_T memOffset;
  real_T rtb_HpK8[6];
  real_T rtb_HpK1[6];
  real_T rtb_HpK2[6];
  real_T rtb_HpK3[6];
  real_T rtb_HpK4[6];
  real_T rtb_HpK5[6];
  real_T rtb_HpK6[6];
  real_T rtb_HpK8_a;
  real_T rtb_HpK1_m;
  real_T rtb_HpK2_l;
  real_T rtb_HpK3_l;
  real_T rtb_HpK4_o;
  real_T rtb_HpK5_m;
  real_T rtb_HpK6_n;
  int32_T rtb_HpK8_tmp;
  for (k = 0; k < 6; k++) {
    /* DiscreteFilter: '<S1>/Discrete Filter' */
    memOffset = k << 2;

    /* Gain: '<S1>/HpK8' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter'
     */
    rtb_HpK8_a = (((M1PosDebug0_DW.DiscreteFilter_states[memOffset + 1] *
                    -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                    M1PosDebug0_DW.DiscreteFilter_states[memOffset]) +
                   M1PosDebug0_DW.DiscreteFilter_states[memOffset + 2] *
                   -5.40605452685298E-5) +
                  M1PosDebug0_DW.DiscreteFilter_states[memOffset + 3] *
                  5.4366873931528294E-5) * 1.5743999886111712E+8;

    /* DiscreteFilter: '<S1>/Discrete Filter1' */
    memOffset = k << 2;

    /* Gain: '<S1>/HpK1' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter1'
     */
    rtb_HpK1_m = (((M1PosDebug0_DW.DiscreteFilter1_states[memOffset + 1] *
                    -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                    M1PosDebug0_DW.DiscreteFilter1_states[memOffset]) +
                   M1PosDebug0_DW.DiscreteFilter1_states[memOffset + 2] *
                   -5.40605452685298E-5) +
                  M1PosDebug0_DW.DiscreteFilter1_states[memOffset + 3] *
                  5.4366873931528294E-5) * 1.5743999886111712E+8;

    /* DiscreteFilter: '<S1>/Discrete Filter2' */
    memOffset = k << 2;

    /* Gain: '<S1>/HpK2' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter2'
     */
    rtb_HpK2_l = (((M1PosDebug0_DW.DiscreteFilter2_states[memOffset + 1] *
                    -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                    M1PosDebug0_DW.DiscreteFilter2_states[memOffset]) +
                   M1PosDebug0_DW.DiscreteFilter2_states[memOffset + 2] *
                   -5.40605452685298E-5) +
                  M1PosDebug0_DW.DiscreteFilter2_states[memOffset + 3] *
                  5.4366873931528294E-5) * 1.5743999886111712E+8;

    /* DiscreteFilter: '<S1>/Discrete Filter3' */
    memOffset = k << 2;

    /* Gain: '<S1>/HpK3' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter3'
     */
    rtb_HpK3_l = (((M1PosDebug0_DW.DiscreteFilter3_states[memOffset + 1] *
                    -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                    M1PosDebug0_DW.DiscreteFilter3_states[memOffset]) +
                   M1PosDebug0_DW.DiscreteFilter3_states[memOffset + 2] *
                   -5.40605452685298E-5) +
                  M1PosDebug0_DW.DiscreteFilter3_states[memOffset + 3] *
                  5.4366873931528294E-5) * 1.5743999886111712E+8;

    /* DiscreteFilter: '<S1>/Discrete Filter4' */
    memOffset = k << 2;

    /* Gain: '<S1>/HpK4' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter4'
     */
    rtb_HpK4_o = (((M1PosDebug0_DW.DiscreteFilter4_states[memOffset + 1] *
                    -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                    M1PosDebug0_DW.DiscreteFilter4_states[memOffset]) +
                   M1PosDebug0_DW.DiscreteFilter4_states[memOffset + 2] *
                   -5.40605452685298E-5) +
                  M1PosDebug0_DW.DiscreteFilter4_states[memOffset + 3] *
                  5.4366873931528294E-5) * 1.5743999886111712E+8;

    /* DiscreteFilter: '<S1>/Discrete Filter5' */
    memOffset = k << 2;

    /* Gain: '<S1>/HpK5' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter5'
     */
    rtb_HpK5_m = (((M1PosDebug0_DW.DiscreteFilter5_states[memOffset + 1] *
                    -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                    M1PosDebug0_DW.DiscreteFilter5_states[memOffset]) +
                   M1PosDebug0_DW.DiscreteFilter5_states[memOffset + 2] *
                   -5.40605452685298E-5) +
                  M1PosDebug0_DW.DiscreteFilter5_states[memOffset + 3] *
                  5.4366873931528294E-5) * 1.5743999886111712E+8;

    /* DiscreteFilter: '<S1>/Discrete Filter6' */
    memOffset = k << 2;

    /* Gain: '<S1>/HpK6' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter6'
     */
    rtb_HpK6_n = (((M1PosDebug0_DW.DiscreteFilter6_states[memOffset + 1] *
                    -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                    M1PosDebug0_DW.DiscreteFilter6_states[memOffset]) +
                   M1PosDebug0_DW.DiscreteFilter6_states[memOffset + 2] *
                   -5.40605452685298E-5) +
                  M1PosDebug0_DW.DiscreteFilter6_states[memOffset + 3] *
                  5.4366873931528294E-5) * 1.5743999886111712E+8;

    /* Outport: '<Root>/Output' */
    M1PosDebug0_Y.Output[k] = rtb_HpK8_a;
    M1PosDebug0_Y.Output[k + 6] = rtb_HpK1_m;
    M1PosDebug0_Y.Output[k + 12] = rtb_HpK2_l;
    M1PosDebug0_Y.Output[k + 18] = rtb_HpK3_l;
    M1PosDebug0_Y.Output[k + 24] = rtb_HpK4_o;
    M1PosDebug0_Y.Output[k + 30] = rtb_HpK5_m;
    M1PosDebug0_Y.Output[k + 36] = rtb_HpK6_n;

    /* DiscreteFilter: '<S1>/Discrete Filter' */
    rtb_HpK8[k] = rtb_HpK8_a;

    /* DiscreteFilter: '<S1>/Discrete Filter1' */
    rtb_HpK1[k] = rtb_HpK1_m;

    /* DiscreteFilter: '<S1>/Discrete Filter2' */
    rtb_HpK2[k] = rtb_HpK2_l;

    /* DiscreteFilter: '<S1>/Discrete Filter3' */
    rtb_HpK3[k] = rtb_HpK3_l;

    /* DiscreteFilter: '<S1>/Discrete Filter4' */
    rtb_HpK4[k] = rtb_HpK4_o;

    /* DiscreteFilter: '<S1>/Discrete Filter5' */
    rtb_HpK5[k] = rtb_HpK5_m;

    /* DiscreteFilter: '<S1>/Discrete Filter6' */
    rtb_HpK6[k] = rtb_HpK6_n;
  }

  /* Outport: '<Root>/Output' incorporates:
   *  Inport: '<Root>/Feedback'
   */
  memcpy(&M1PosDebug0_Y.Output[42], &M1PosDebug0_U.Feedback[0], 42U * sizeof
         (real_T));
  for (k = 0; k < 6; k++) {
    /* Gain: '<S1>/CG2Hp1' */
    rtb_HpK8[k] = 0.0;

    /* Gain: '<S1>/CG2Hp2' */
    rtb_HpK1[k] = 0.0;

    /* Gain: '<S1>/CG2Hp3' */
    rtb_HpK2[k] = 0.0;

    /* Gain: '<S1>/CG2Hp4' */
    rtb_HpK3[k] = 0.0;

    /* Gain: '<S1>/CG2Hp5' */
    rtb_HpK4[k] = 0.0;

    /* Gain: '<S1>/CG2Hp6' */
    rtb_HpK5[k] = 0.0;

    /* Gain: '<S1>/CG2Hp8' */
    rtb_HpK6[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      /* Gain: '<S1>/CG2Hp1' incorporates:
       *  Gain: '<S1>/CG2Hp2'
       *  Gain: '<S1>/CG2Hp3'
       *  Gain: '<S1>/CG2Hp4'
       *  Gain: '<S1>/CG2Hp5'
       *  Gain: '<S1>/CG2Hp6'
       *  Gain: '<S1>/CG2Hp8'
       *  Inport: '<Root>/Feedback'
       */
      rtb_HpK8_tmp = 6 * memOffset + k;
      rtb_HpK8[k] += M1PosDebug0_ConstP.CG2Hp1_Gain[rtb_HpK8_tmp] *
        M1PosDebug0_U.Feedback[12 + memOffset];

      /* Gain: '<S1>/CG2Hp2' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_HpK1[k] += M1PosDebug0_ConstP.CG2Hp2_Gain[rtb_HpK8_tmp] *
        M1PosDebug0_U.Feedback[18 + memOffset];

      /* Gain: '<S1>/CG2Hp3' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_HpK2[k] += M1PosDebug0_ConstP.CG2Hp3_Gain[rtb_HpK8_tmp] *
        M1PosDebug0_U.Feedback[24 + memOffset];

      /* Gain: '<S1>/CG2Hp4' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_HpK3[k] += M1PosDebug0_ConstP.CG2Hp4_Gain[rtb_HpK8_tmp] *
        M1PosDebug0_U.Feedback[30 + memOffset];

      /* Gain: '<S1>/CG2Hp5' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_HpK4[k] += M1PosDebug0_ConstP.CG2Hp5_Gain[rtb_HpK8_tmp] *
        M1PosDebug0_U.Feedback[36 + memOffset];

      /* Gain: '<S1>/CG2Hp6' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_HpK5[k] += M1PosDebug0_ConstP.CG2Hp6_Gain[rtb_HpK8_tmp] *
        M1PosDebug0_U.Feedback[memOffset];

      /* Gain: '<S1>/CG2Hp8' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_HpK6[k] += M1PosDebug0_ConstP.CG2Hp8_Gain[rtb_HpK8_tmp] *
        M1PosDebug0_U.Feedback[6 + memOffset];
    }

    /* Update for DiscreteFilter: '<S1>/Discrete Filter' */
    memOffset = k << 2;
    rtb_HpK8_a = (((rtb_HpK5[k] - -3.9658259936667708 *
                    M1PosDebug0_DW.DiscreteFilter_states[memOffset]) -
                   M1PosDebug0_DW.DiscreteFilter_states[memOffset + 1] *
                   5.8976852476007764) -
                  M1PosDebug0_DW.DiscreteFilter_states[memOffset + 2] *
                  -3.8978920261025323) -
      M1PosDebug0_DW.DiscreteFilter_states[memOffset + 3] * 0.96603277266632026;
    M1PosDebug0_DW.DiscreteFilter_states[memOffset + 3] =
      M1PosDebug0_DW.DiscreteFilter_states[memOffset + 2];
    M1PosDebug0_DW.DiscreteFilter_states[memOffset + 2] =
      M1PosDebug0_DW.DiscreteFilter_states[memOffset + 1];
    M1PosDebug0_DW.DiscreteFilter_states[memOffset + 1] =
      M1PosDebug0_DW.DiscreteFilter_states[memOffset];
    M1PosDebug0_DW.DiscreteFilter_states[memOffset] = rtb_HpK8_a;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter1' */
    memOffset = k << 2;
    rtb_HpK8_a = (((rtb_HpK6[k] - -3.9658259936667708 *
                    M1PosDebug0_DW.DiscreteFilter1_states[memOffset]) -
                   M1PosDebug0_DW.DiscreteFilter1_states[memOffset + 1] *
                   5.8976852476007764) -
                  M1PosDebug0_DW.DiscreteFilter1_states[memOffset + 2] *
                  -3.8978920261025323) -
      M1PosDebug0_DW.DiscreteFilter1_states[memOffset + 3] * 0.96603277266632026;
    M1PosDebug0_DW.DiscreteFilter1_states[memOffset + 3] =
      M1PosDebug0_DW.DiscreteFilter1_states[memOffset + 2];
    M1PosDebug0_DW.DiscreteFilter1_states[memOffset + 2] =
      M1PosDebug0_DW.DiscreteFilter1_states[memOffset + 1];
    M1PosDebug0_DW.DiscreteFilter1_states[memOffset + 1] =
      M1PosDebug0_DW.DiscreteFilter1_states[memOffset];
    M1PosDebug0_DW.DiscreteFilter1_states[memOffset] = rtb_HpK8_a;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter2' */
    memOffset = k << 2;
    rtb_HpK8_a = (((rtb_HpK8[k] - -3.9658259936667708 *
                    M1PosDebug0_DW.DiscreteFilter2_states[memOffset]) -
                   M1PosDebug0_DW.DiscreteFilter2_states[memOffset + 1] *
                   5.8976852476007764) -
                  M1PosDebug0_DW.DiscreteFilter2_states[memOffset + 2] *
                  -3.8978920261025323) -
      M1PosDebug0_DW.DiscreteFilter2_states[memOffset + 3] * 0.96603277266632026;
    M1PosDebug0_DW.DiscreteFilter2_states[memOffset + 3] =
      M1PosDebug0_DW.DiscreteFilter2_states[memOffset + 2];
    M1PosDebug0_DW.DiscreteFilter2_states[memOffset + 2] =
      M1PosDebug0_DW.DiscreteFilter2_states[memOffset + 1];
    M1PosDebug0_DW.DiscreteFilter2_states[memOffset + 1] =
      M1PosDebug0_DW.DiscreteFilter2_states[memOffset];
    M1PosDebug0_DW.DiscreteFilter2_states[memOffset] = rtb_HpK8_a;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter3' */
    memOffset = k << 2;
    rtb_HpK8_a = (((rtb_HpK1[k] - -3.9658259936667708 *
                    M1PosDebug0_DW.DiscreteFilter3_states[memOffset]) -
                   M1PosDebug0_DW.DiscreteFilter3_states[memOffset + 1] *
                   5.8976852476007764) -
                  M1PosDebug0_DW.DiscreteFilter3_states[memOffset + 2] *
                  -3.8978920261025323) -
      M1PosDebug0_DW.DiscreteFilter3_states[memOffset + 3] * 0.96603277266632026;
    M1PosDebug0_DW.DiscreteFilter3_states[memOffset + 3] =
      M1PosDebug0_DW.DiscreteFilter3_states[memOffset + 2];
    M1PosDebug0_DW.DiscreteFilter3_states[memOffset + 2] =
      M1PosDebug0_DW.DiscreteFilter3_states[memOffset + 1];
    M1PosDebug0_DW.DiscreteFilter3_states[memOffset + 1] =
      M1PosDebug0_DW.DiscreteFilter3_states[memOffset];
    M1PosDebug0_DW.DiscreteFilter3_states[memOffset] = rtb_HpK8_a;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter4' */
    memOffset = k << 2;
    rtb_HpK8_a = (((rtb_HpK2[k] - -3.9658259936667708 *
                    M1PosDebug0_DW.DiscreteFilter4_states[memOffset]) -
                   M1PosDebug0_DW.DiscreteFilter4_states[memOffset + 1] *
                   5.8976852476007764) -
                  M1PosDebug0_DW.DiscreteFilter4_states[memOffset + 2] *
                  -3.8978920261025323) -
      M1PosDebug0_DW.DiscreteFilter4_states[memOffset + 3] * 0.96603277266632026;
    M1PosDebug0_DW.DiscreteFilter4_states[memOffset + 3] =
      M1PosDebug0_DW.DiscreteFilter4_states[memOffset + 2];
    M1PosDebug0_DW.DiscreteFilter4_states[memOffset + 2] =
      M1PosDebug0_DW.DiscreteFilter4_states[memOffset + 1];
    M1PosDebug0_DW.DiscreteFilter4_states[memOffset + 1] =
      M1PosDebug0_DW.DiscreteFilter4_states[memOffset];
    M1PosDebug0_DW.DiscreteFilter4_states[memOffset] = rtb_HpK8_a;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter5' */
    memOffset = k << 2;
    rtb_HpK8_a = (((rtb_HpK3[k] - -3.9658259936667708 *
                    M1PosDebug0_DW.DiscreteFilter5_states[memOffset]) -
                   M1PosDebug0_DW.DiscreteFilter5_states[memOffset + 1] *
                   5.8976852476007764) -
                  M1PosDebug0_DW.DiscreteFilter5_states[memOffset + 2] *
                  -3.8978920261025323) -
      M1PosDebug0_DW.DiscreteFilter5_states[memOffset + 3] * 0.96603277266632026;
    M1PosDebug0_DW.DiscreteFilter5_states[memOffset + 3] =
      M1PosDebug0_DW.DiscreteFilter5_states[memOffset + 2];
    M1PosDebug0_DW.DiscreteFilter5_states[memOffset + 2] =
      M1PosDebug0_DW.DiscreteFilter5_states[memOffset + 1];
    M1PosDebug0_DW.DiscreteFilter5_states[memOffset + 1] =
      M1PosDebug0_DW.DiscreteFilter5_states[memOffset];
    M1PosDebug0_DW.DiscreteFilter5_states[memOffset] = rtb_HpK8_a;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter6' */
    memOffset = k << 2;
    rtb_HpK8_a = (((rtb_HpK4[k] - -3.9658259936667708 *
                    M1PosDebug0_DW.DiscreteFilter6_states[memOffset]) -
                   M1PosDebug0_DW.DiscreteFilter6_states[memOffset + 1] *
                   5.8976852476007764) -
                  M1PosDebug0_DW.DiscreteFilter6_states[memOffset + 2] *
                  -3.8978920261025323) -
      M1PosDebug0_DW.DiscreteFilter6_states[memOffset + 3] * 0.96603277266632026;
    M1PosDebug0_DW.DiscreteFilter6_states[memOffset + 3] =
      M1PosDebug0_DW.DiscreteFilter6_states[memOffset + 2];
    M1PosDebug0_DW.DiscreteFilter6_states[memOffset + 2] =
      M1PosDebug0_DW.DiscreteFilter6_states[memOffset + 1];
    M1PosDebug0_DW.DiscreteFilter6_states[memOffset + 1] =
      M1PosDebug0_DW.DiscreteFilter6_states[memOffset];
    M1PosDebug0_DW.DiscreteFilter6_states[memOffset] = rtb_HpK8_a;
  }
}

/* Model initialize function */
void M1PosDebug0_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1PosDebug0_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&M1PosDebug0_DW, 0,
                sizeof(DW_M1PosDebug0_T));

  /* external inputs */
  (void)memset((void *)&M1PosDebug0_U, 0, sizeof(ExtU_M1PosDebug0_T));

  /* external outputs */
  (void) memset(&M1PosDebug0_Y.Output[0], 0,
                84U*sizeof(real_T));
}

/* Model terminate function */
void M1PosDebug0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
