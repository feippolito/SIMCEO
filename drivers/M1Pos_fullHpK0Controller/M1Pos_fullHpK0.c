/*
 * File: M1Pos_fullHpK0.c
 *
 * Code generated for Simulink model 'M1Pos_fullHpK0'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Thu Feb 13 16:46:34 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1Pos_fullHpK0.h"
#include "M1Pos_fullHpK0_private.h"

/* Block states (default storage) */
DW_M1Pos_fullHpK0_T M1Pos_fullHpK0_DW;

/* External inputs (root inport signals with default storage) */
ExtU_M1Pos_fullHpK0_T M1Pos_fullHpK0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1Pos_fullHpK0_T M1Pos_fullHpK0_Y;

/* Real-time model */
RT_MODEL_M1Pos_fullHpK0_T M1Pos_fullHpK0_M_;
RT_MODEL_M1Pos_fullHpK0_T *const M1Pos_fullHpK0_M = &M1Pos_fullHpK0_M_;

/* Model step function */
void M1Pos_fullHpK0_step(void)
{
  real_T numAccum;
  int32_T k;
  int32_T memOffset;
  real_T numAccum_0;
  real_T numAccum_1;
  real_T numAccum_2;
  real_T numAccum_3;
  real_T numAccum_4;
  real_T numAccum_5;
  real_T rtb_DiscreteFilter[6];
  real_T rtb_DiscreteFilter1[6];
  real_T rtb_DiscreteFilter2[6];
  real_T rtb_DiscreteFilter3[6];
  real_T rtb_DiscreteFilter4[6];
  real_T rtb_DiscreteFilter5[6];
  real_T rtb_DiscreteFilter6[6];
  real_T rtb_DiscreteFilter_0[42];
  int32_T rtb_DiscreteFilter_tmp;
  for (k = 0; k < 6; k++) {
    /* DiscreteFilter: '<S1>/Discrete Filter' */
    memOffset = k << 2;
    numAccum = ((M1Pos_fullHpK0_DW.DiscreteFilter_states[memOffset + 1] *
                 -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                 M1Pos_fullHpK0_DW.DiscreteFilter_states[memOffset]) +
                M1Pos_fullHpK0_DW.DiscreteFilter_states[memOffset + 2] *
                -5.40605452685298E-5) +
      M1Pos_fullHpK0_DW.DiscreteFilter_states[memOffset + 3] *
      5.4366873931528294E-5;

    /* DiscreteFilter: '<S1>/Discrete Filter1' */
    memOffset = k << 2;
    numAccum_0 = ((M1Pos_fullHpK0_DW.DiscreteFilter1_states[memOffset + 1] *
                   -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                   M1Pos_fullHpK0_DW.DiscreteFilter1_states[memOffset]) +
                  M1Pos_fullHpK0_DW.DiscreteFilter1_states[memOffset + 2] *
                  -5.40605452685298E-5) +
      M1Pos_fullHpK0_DW.DiscreteFilter1_states[memOffset + 3] *
      5.4366873931528294E-5;

    /* DiscreteFilter: '<S1>/Discrete Filter2' */
    memOffset = k << 2;
    numAccum_1 = ((M1Pos_fullHpK0_DW.DiscreteFilter2_states[memOffset + 1] *
                   -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                   M1Pos_fullHpK0_DW.DiscreteFilter2_states[memOffset]) +
                  M1Pos_fullHpK0_DW.DiscreteFilter2_states[memOffset + 2] *
                  -5.40605452685298E-5) +
      M1Pos_fullHpK0_DW.DiscreteFilter2_states[memOffset + 3] *
      5.4366873931528294E-5;

    /* DiscreteFilter: '<S1>/Discrete Filter3' */
    memOffset = k << 2;
    numAccum_2 = ((M1Pos_fullHpK0_DW.DiscreteFilter3_states[memOffset + 1] *
                   -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                   M1Pos_fullHpK0_DW.DiscreteFilter3_states[memOffset]) +
                  M1Pos_fullHpK0_DW.DiscreteFilter3_states[memOffset + 2] *
                  -5.40605452685298E-5) +
      M1Pos_fullHpK0_DW.DiscreteFilter3_states[memOffset + 3] *
      5.4366873931528294E-5;

    /* DiscreteFilter: '<S1>/Discrete Filter4' */
    memOffset = k << 2;
    numAccum_3 = ((M1Pos_fullHpK0_DW.DiscreteFilter4_states[memOffset + 1] *
                   -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                   M1Pos_fullHpK0_DW.DiscreteFilter4_states[memOffset]) +
                  M1Pos_fullHpK0_DW.DiscreteFilter4_states[memOffset + 2] *
                  -5.40605452685298E-5) +
      M1Pos_fullHpK0_DW.DiscreteFilter4_states[memOffset + 3] *
      5.4366873931528294E-5;

    /* DiscreteFilter: '<S1>/Discrete Filter5' */
    memOffset = k << 2;
    numAccum_4 = ((M1Pos_fullHpK0_DW.DiscreteFilter5_states[memOffset + 1] *
                   -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                   M1Pos_fullHpK0_DW.DiscreteFilter5_states[memOffset]) +
                  M1Pos_fullHpK0_DW.DiscreteFilter5_states[memOffset + 2] *
                  -5.40605452685298E-5) +
      M1Pos_fullHpK0_DW.DiscreteFilter5_states[memOffset + 3] *
      5.4366873931528294E-5;

    /* DiscreteFilter: '<S1>/Discrete Filter6' */
    memOffset = k << 2;
    numAccum_5 = ((M1Pos_fullHpK0_DW.DiscreteFilter6_states[memOffset + 1] *
                   -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                   M1Pos_fullHpK0_DW.DiscreteFilter6_states[memOffset]) +
                  M1Pos_fullHpK0_DW.DiscreteFilter6_states[memOffset + 2] *
                  -5.40605452685298E-5) +
      M1Pos_fullHpK0_DW.DiscreteFilter6_states[memOffset + 3] *
      5.4366873931528294E-5;

    /* SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter'
     *  DiscreteFilter: '<S1>/Discrete Filter1'
     *  DiscreteFilter: '<S1>/Discrete Filter2'
     *  DiscreteFilter: '<S1>/Discrete Filter3'
     *  DiscreteFilter: '<S1>/Discrete Filter4'
     *  DiscreteFilter: '<S1>/Discrete Filter5'
     *  DiscreteFilter: '<S1>/Discrete Filter6'
     */
    rtb_DiscreteFilter_0[k] = numAccum;
    rtb_DiscreteFilter_0[k + 6] = numAccum_0;
    rtb_DiscreteFilter_0[k + 12] = numAccum_1;
    rtb_DiscreteFilter_0[k + 18] = numAccum_2;
    rtb_DiscreteFilter_0[k + 24] = numAccum_3;
    rtb_DiscreteFilter_0[k + 30] = numAccum_4;
    rtb_DiscreteFilter_0[k + 36] = numAccum_5;

    /* DiscreteFilter: '<S1>/Discrete Filter' */
    rtb_DiscreteFilter[k] = numAccum;

    /* DiscreteFilter: '<S1>/Discrete Filter1' */
    rtb_DiscreteFilter1[k] = numAccum_0;

    /* DiscreteFilter: '<S1>/Discrete Filter2' */
    rtb_DiscreteFilter2[k] = numAccum_1;

    /* DiscreteFilter: '<S1>/Discrete Filter3' */
    rtb_DiscreteFilter3[k] = numAccum_2;

    /* DiscreteFilter: '<S1>/Discrete Filter4' */
    rtb_DiscreteFilter4[k] = numAccum_3;

    /* DiscreteFilter: '<S1>/Discrete Filter5' */
    rtb_DiscreteFilter5[k] = numAccum_4;

    /* DiscreteFilter: '<S1>/Discrete Filter6' */
    rtb_DiscreteFilter6[k] = numAccum_5;
  }

  /* Outport: '<Root>/Output' incorporates:
   *  Gain: '<S1>/Gain'
   *  SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1'
   */
  for (memOffset = 0; memOffset < 42; memOffset++) {
    M1Pos_fullHpK0_Y.Output[memOffset] = 0.0;
    for (k = 0; k < 42; k++) {
      M1Pos_fullHpK0_Y.Output[memOffset] += M1Pos_fullHpK0_ConstP.Gain_Gain[42 *
        k + memOffset] * rtb_DiscreteFilter_0[k];
    }
  }

  /* End of Outport: '<Root>/Output' */
  for (k = 0; k < 6; k++) {
    /* Gain: '<S1>/CG2Hp1' */
    rtb_DiscreteFilter[k] = 0.0;

    /* Gain: '<S1>/CG2Hp2' */
    rtb_DiscreteFilter1[k] = 0.0;

    /* Gain: '<S1>/CG2Hp3' */
    rtb_DiscreteFilter2[k] = 0.0;

    /* Gain: '<S1>/CG2Hp4' */
    rtb_DiscreteFilter3[k] = 0.0;

    /* Gain: '<S1>/CG2Hp5' */
    rtb_DiscreteFilter4[k] = 0.0;

    /* Gain: '<S1>/CG2Hp6' */
    rtb_DiscreteFilter5[k] = 0.0;

    /* Gain: '<S1>/CG2Hp8' */
    rtb_DiscreteFilter6[k] = 0.0;
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
      rtb_DiscreteFilter_tmp = 6 * memOffset + k;
      rtb_DiscreteFilter[k] +=
        M1Pos_fullHpK0_ConstP.CG2Hp1_Gain[rtb_DiscreteFilter_tmp] *
        M1Pos_fullHpK0_U.Feedback[12 + memOffset];

      /* Gain: '<S1>/CG2Hp2' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_DiscreteFilter1[k] +=
        M1Pos_fullHpK0_ConstP.CG2Hp2_Gain[rtb_DiscreteFilter_tmp] *
        M1Pos_fullHpK0_U.Feedback[18 + memOffset];

      /* Gain: '<S1>/CG2Hp3' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_DiscreteFilter2[k] +=
        M1Pos_fullHpK0_ConstP.CG2Hp3_Gain[rtb_DiscreteFilter_tmp] *
        M1Pos_fullHpK0_U.Feedback[24 + memOffset];

      /* Gain: '<S1>/CG2Hp4' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_DiscreteFilter3[k] +=
        M1Pos_fullHpK0_ConstP.CG2Hp4_Gain[rtb_DiscreteFilter_tmp] *
        M1Pos_fullHpK0_U.Feedback[30 + memOffset];

      /* Gain: '<S1>/CG2Hp5' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_DiscreteFilter4[k] +=
        M1Pos_fullHpK0_ConstP.CG2Hp5_Gain[rtb_DiscreteFilter_tmp] *
        M1Pos_fullHpK0_U.Feedback[36 + memOffset];

      /* Gain: '<S1>/CG2Hp6' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_DiscreteFilter5[k] +=
        M1Pos_fullHpK0_ConstP.CG2Hp6_Gain[rtb_DiscreteFilter_tmp] *
        M1Pos_fullHpK0_U.Feedback[memOffset];

      /* Gain: '<S1>/CG2Hp8' incorporates:
       *  Inport: '<Root>/Feedback'
       */
      rtb_DiscreteFilter6[k] +=
        M1Pos_fullHpK0_ConstP.CG2Hp8_Gain[rtb_DiscreteFilter_tmp] *
        M1Pos_fullHpK0_U.Feedback[6 + memOffset];
    }

    /* Update for DiscreteFilter: '<S1>/Discrete Filter' */
    memOffset = k << 2;
    numAccum = (((rtb_DiscreteFilter5[k] - -3.9658259936667708 *
                  M1Pos_fullHpK0_DW.DiscreteFilter_states[memOffset]) -
                 M1Pos_fullHpK0_DW.DiscreteFilter_states[memOffset + 1] *
                 5.8976852476007764) -
                M1Pos_fullHpK0_DW.DiscreteFilter_states[memOffset + 2] *
                -3.8978920261025323) -
      M1Pos_fullHpK0_DW.DiscreteFilter_states[memOffset + 3] *
      0.96603277266632026;
    M1Pos_fullHpK0_DW.DiscreteFilter_states[memOffset + 3] =
      M1Pos_fullHpK0_DW.DiscreteFilter_states[memOffset + 2];
    M1Pos_fullHpK0_DW.DiscreteFilter_states[memOffset + 2] =
      M1Pos_fullHpK0_DW.DiscreteFilter_states[memOffset + 1];
    M1Pos_fullHpK0_DW.DiscreteFilter_states[memOffset + 1] =
      M1Pos_fullHpK0_DW.DiscreteFilter_states[memOffset];
    M1Pos_fullHpK0_DW.DiscreteFilter_states[memOffset] = numAccum;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter1' */
    memOffset = k << 2;
    numAccum = (((rtb_DiscreteFilter6[k] - -3.9658259936667708 *
                  M1Pos_fullHpK0_DW.DiscreteFilter1_states[memOffset]) -
                 M1Pos_fullHpK0_DW.DiscreteFilter1_states[memOffset + 1] *
                 5.8976852476007764) -
                M1Pos_fullHpK0_DW.DiscreteFilter1_states[memOffset + 2] *
                -3.8978920261025323) -
      M1Pos_fullHpK0_DW.DiscreteFilter1_states[memOffset + 3] *
      0.96603277266632026;
    M1Pos_fullHpK0_DW.DiscreteFilter1_states[memOffset + 3] =
      M1Pos_fullHpK0_DW.DiscreteFilter1_states[memOffset + 2];
    M1Pos_fullHpK0_DW.DiscreteFilter1_states[memOffset + 2] =
      M1Pos_fullHpK0_DW.DiscreteFilter1_states[memOffset + 1];
    M1Pos_fullHpK0_DW.DiscreteFilter1_states[memOffset + 1] =
      M1Pos_fullHpK0_DW.DiscreteFilter1_states[memOffset];
    M1Pos_fullHpK0_DW.DiscreteFilter1_states[memOffset] = numAccum;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter2' */
    memOffset = k << 2;
    numAccum = (((rtb_DiscreteFilter[k] - -3.9658259936667708 *
                  M1Pos_fullHpK0_DW.DiscreteFilter2_states[memOffset]) -
                 M1Pos_fullHpK0_DW.DiscreteFilter2_states[memOffset + 1] *
                 5.8976852476007764) -
                M1Pos_fullHpK0_DW.DiscreteFilter2_states[memOffset + 2] *
                -3.8978920261025323) -
      M1Pos_fullHpK0_DW.DiscreteFilter2_states[memOffset + 3] *
      0.96603277266632026;
    M1Pos_fullHpK0_DW.DiscreteFilter2_states[memOffset + 3] =
      M1Pos_fullHpK0_DW.DiscreteFilter2_states[memOffset + 2];
    M1Pos_fullHpK0_DW.DiscreteFilter2_states[memOffset + 2] =
      M1Pos_fullHpK0_DW.DiscreteFilter2_states[memOffset + 1];
    M1Pos_fullHpK0_DW.DiscreteFilter2_states[memOffset + 1] =
      M1Pos_fullHpK0_DW.DiscreteFilter2_states[memOffset];
    M1Pos_fullHpK0_DW.DiscreteFilter2_states[memOffset] = numAccum;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter3' */
    memOffset = k << 2;
    numAccum = (((rtb_DiscreteFilter1[k] - -3.9658259936667708 *
                  M1Pos_fullHpK0_DW.DiscreteFilter3_states[memOffset]) -
                 M1Pos_fullHpK0_DW.DiscreteFilter3_states[memOffset + 1] *
                 5.8976852476007764) -
                M1Pos_fullHpK0_DW.DiscreteFilter3_states[memOffset + 2] *
                -3.8978920261025323) -
      M1Pos_fullHpK0_DW.DiscreteFilter3_states[memOffset + 3] *
      0.96603277266632026;
    M1Pos_fullHpK0_DW.DiscreteFilter3_states[memOffset + 3] =
      M1Pos_fullHpK0_DW.DiscreteFilter3_states[memOffset + 2];
    M1Pos_fullHpK0_DW.DiscreteFilter3_states[memOffset + 2] =
      M1Pos_fullHpK0_DW.DiscreteFilter3_states[memOffset + 1];
    M1Pos_fullHpK0_DW.DiscreteFilter3_states[memOffset + 1] =
      M1Pos_fullHpK0_DW.DiscreteFilter3_states[memOffset];
    M1Pos_fullHpK0_DW.DiscreteFilter3_states[memOffset] = numAccum;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter4' */
    memOffset = k << 2;
    numAccum = (((rtb_DiscreteFilter2[k] - -3.9658259936667708 *
                  M1Pos_fullHpK0_DW.DiscreteFilter4_states[memOffset]) -
                 M1Pos_fullHpK0_DW.DiscreteFilter4_states[memOffset + 1] *
                 5.8976852476007764) -
                M1Pos_fullHpK0_DW.DiscreteFilter4_states[memOffset + 2] *
                -3.8978920261025323) -
      M1Pos_fullHpK0_DW.DiscreteFilter4_states[memOffset + 3] *
      0.96603277266632026;
    M1Pos_fullHpK0_DW.DiscreteFilter4_states[memOffset + 3] =
      M1Pos_fullHpK0_DW.DiscreteFilter4_states[memOffset + 2];
    M1Pos_fullHpK0_DW.DiscreteFilter4_states[memOffset + 2] =
      M1Pos_fullHpK0_DW.DiscreteFilter4_states[memOffset + 1];
    M1Pos_fullHpK0_DW.DiscreteFilter4_states[memOffset + 1] =
      M1Pos_fullHpK0_DW.DiscreteFilter4_states[memOffset];
    M1Pos_fullHpK0_DW.DiscreteFilter4_states[memOffset] = numAccum;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter5' */
    memOffset = k << 2;
    numAccum = (((rtb_DiscreteFilter3[k] - -3.9658259936667708 *
                  M1Pos_fullHpK0_DW.DiscreteFilter5_states[memOffset]) -
                 M1Pos_fullHpK0_DW.DiscreteFilter5_states[memOffset + 1] *
                 5.8976852476007764) -
                M1Pos_fullHpK0_DW.DiscreteFilter5_states[memOffset + 2] *
                -3.8978920261025323) -
      M1Pos_fullHpK0_DW.DiscreteFilter5_states[memOffset + 3] *
      0.96603277266632026;
    M1Pos_fullHpK0_DW.DiscreteFilter5_states[memOffset + 3] =
      M1Pos_fullHpK0_DW.DiscreteFilter5_states[memOffset + 2];
    M1Pos_fullHpK0_DW.DiscreteFilter5_states[memOffset + 2] =
      M1Pos_fullHpK0_DW.DiscreteFilter5_states[memOffset + 1];
    M1Pos_fullHpK0_DW.DiscreteFilter5_states[memOffset + 1] =
      M1Pos_fullHpK0_DW.DiscreteFilter5_states[memOffset];
    M1Pos_fullHpK0_DW.DiscreteFilter5_states[memOffset] = numAccum;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter6' */
    memOffset = k << 2;
    numAccum = (((rtb_DiscreteFilter4[k] - -3.9658259936667708 *
                  M1Pos_fullHpK0_DW.DiscreteFilter6_states[memOffset]) -
                 M1Pos_fullHpK0_DW.DiscreteFilter6_states[memOffset + 1] *
                 5.8976852476007764) -
                M1Pos_fullHpK0_DW.DiscreteFilter6_states[memOffset + 2] *
                -3.8978920261025323) -
      M1Pos_fullHpK0_DW.DiscreteFilter6_states[memOffset + 3] *
      0.96603277266632026;
    M1Pos_fullHpK0_DW.DiscreteFilter6_states[memOffset + 3] =
      M1Pos_fullHpK0_DW.DiscreteFilter6_states[memOffset + 2];
    M1Pos_fullHpK0_DW.DiscreteFilter6_states[memOffset + 2] =
      M1Pos_fullHpK0_DW.DiscreteFilter6_states[memOffset + 1];
    M1Pos_fullHpK0_DW.DiscreteFilter6_states[memOffset + 1] =
      M1Pos_fullHpK0_DW.DiscreteFilter6_states[memOffset];
    M1Pos_fullHpK0_DW.DiscreteFilter6_states[memOffset] = numAccum;
  }
}

/* Model initialize function */
void M1Pos_fullHpK0_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1Pos_fullHpK0_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&M1Pos_fullHpK0_DW, 0,
                sizeof(DW_M1Pos_fullHpK0_T));

  /* external inputs */
  (void)memset((void *)&M1Pos_fullHpK0_U, 0, sizeof(ExtU_M1Pos_fullHpK0_T));

  /* external outputs */
  (void) memset(&M1Pos_fullHpK0_Y.Output[0], 0,
                42U*sizeof(real_T));
}

/* Model terminate function */
void M1Pos_fullHpK0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
