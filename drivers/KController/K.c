/*
 * File: K.c
 *
 * Code generated for Simulink model 'K'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Feb 19 18:27:37 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "K.h"
#include "K_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_K_T K_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_K_T K_Y;

/* Real-time model */
RT_MODEL_K_T K_M_;
RT_MODEL_K_T *const K_M = &K_M_;

/* Model step function */
void K_step(void)
{
  real_T tmp[154];
  int32_T i;
  int32_T i_0;
  real_T tmp_0[154];
  real_T tmp_1[154];
  real_T tmp_2[154];
  real_T tmp_3[154];
  real_T tmp_4[154];
  real_T tmp_5[154];
  for (i = 0; i < 154; i++) {
    /* Gain: '<S1>/Seg1' incorporates:
     *  Outport: '<Root>/Output'
     */
    tmp[i] = 0.0;

    /* Gain: '<S1>/Seg2' incorporates:
     *  Outport: '<Root>/Output'
     */
    tmp_0[i] = 0.0;

    /* Gain: '<S1>/Seg3' incorporates:
     *  Outport: '<Root>/Output'
     */
    tmp_1[i] = 0.0;

    /* Gain: '<S1>/Seg4' incorporates:
     *  Outport: '<Root>/Output'
     */
    tmp_2[i] = 0.0;

    /* Gain: '<S1>/Seg5' incorporates:
     *  Outport: '<Root>/Output'
     */
    tmp_3[i] = 0.0;

    /* Gain: '<S1>/Seg6' incorporates:
     *  Outport: '<Root>/Output'
     */
    tmp_4[i] = 0.0;
    for (i_0 = 0; i_0 < 165; i_0++) {
      /* Gain: '<S1>/Seg1' incorporates:
       *  Inport: '<Root>/Feedback'
       *  Outport: '<Root>/Output'
       */
      tmp[i] += K_ConstP.pooled1[154 * i_0 + i] * K_U.Feedback[i_0];

      /* Gain: '<S1>/Seg2' incorporates:
       *  Inport: '<Root>/Feedback'
       *  Outport: '<Root>/Output'
       */
      tmp_0[i] += K_ConstP.pooled1[154 * i_0 + i] * K_U.Feedback[165 + i_0];

      /* Gain: '<S1>/Seg3' incorporates:
       *  Inport: '<Root>/Feedback'
       *  Outport: '<Root>/Output'
       */
      tmp_1[i] += K_ConstP.pooled1[154 * i_0 + i] * K_U.Feedback[330 + i_0];

      /* Gain: '<S1>/Seg4' incorporates:
       *  Inport: '<Root>/Feedback'
       *  Outport: '<Root>/Output'
       */
      tmp_2[i] += K_ConstP.pooled1[154 * i_0 + i] * K_U.Feedback[495 + i_0];

      /* Gain: '<S1>/Seg5' incorporates:
       *  Inport: '<Root>/Feedback'
       *  Outport: '<Root>/Output'
       */
      tmp_3[i] += K_ConstP.pooled1[154 * i_0 + i] * K_U.Feedback[660 + i_0];

      /* Gain: '<S1>/Seg6' incorporates:
       *  Inport: '<Root>/Feedback'
       *  Outport: '<Root>/Output'
       */
      tmp_4[i] += K_ConstP.pooled1[154 * i_0 + i] * K_U.Feedback[825 + i_0];
    }

    /* Gain: '<S1>/Seg7' incorporates:
     *  Inport: '<Root>/Feedback'
     *  Outport: '<Root>/Output'
     */
    tmp_5[i] = 0.0;
    for (i_0 = 0; i_0 < 154; i_0++) {
      tmp_5[i] += K_ConstP.Seg7_Gain[154 * i_0 + i] * K_U.Feedback[990 + i_0];
    }

    /* End of Gain: '<S1>/Seg7' */

    /* Outport: '<Root>/Output' */
    K_Y.Output[i] = tmp[i];
    K_Y.Output[i + 154] = tmp_0[i];
    K_Y.Output[i + 308] = tmp_1[i];
    K_Y.Output[i + 462] = tmp_2[i];
    K_Y.Output[i + 616] = tmp_3[i];
    K_Y.Output[i + 770] = tmp_4[i];
    K_Y.Output[i + 924] = tmp_5[i];
  }
}

/* Model initialize function */
void K_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(K_M, (NULL));

  /* external inputs */
  (void)memset((void *)&K_U, 0, sizeof(ExtU_K_T));

  /* external outputs */
  (void) memset(&K_Y.Output[0], 0,
                1078U*sizeof(real_T));
}

/* Model terminate function */
void K_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
