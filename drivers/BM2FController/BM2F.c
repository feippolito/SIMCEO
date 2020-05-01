/*
 * File: BM2F.c
 *
 * Code generated for Simulink model 'BM2F'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Fri Feb 21 11:53:19 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BM2F.h"
#include "BM2F_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_BM2F_T BM2F_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_BM2F_T BM2F_Y;

/* Real-time model */
RT_MODEL_BM2F_T BM2F_M_;
RT_MODEL_BM2F_T *const BM2F_M = &BM2F_M_;

/* Model step function */
void BM2F_step(void)
{
  real_T tmp[165];
  int32_T i;
  int32_T i_0;
  real_T tmp_0[165];
  real_T tmp_1[165];
  real_T tmp_2[165];
  real_T tmp_3[165];
  real_T tmp_4[165];
  real_T tmp_5[154];
  for (i = 0; i < 165; i++) {
    /* Gain: '<S2>/Gain' incorporates:
     *  Outport: '<Root>/Output'
     */
    tmp[i] = 0.0;

    /* Gain: '<S3>/Gain' incorporates:
     *  Outport: '<Root>/Output'
     */
    tmp_0[i] = 0.0;

    /* Gain: '<S4>/Gain' incorporates:
     *  Outport: '<Root>/Output'
     */
    tmp_1[i] = 0.0;

    /* Gain: '<S5>/Gain' incorporates:
     *  Outport: '<Root>/Output'
     */
    tmp_2[i] = 0.0;

    /* Gain: '<S6>/Gain' incorporates:
     *  Outport: '<Root>/Output'
     */
    tmp_3[i] = 0.0;

    /* Gain: '<S7>/Gain' incorporates:
     *  Outport: '<Root>/Output'
     */
    tmp_4[i] = 0.0;
    for (i_0 = 0; i_0 < 27; i_0++) {
      /* Gain: '<S2>/Gain' incorporates:
       *  Inport: '<Root>/Feedback'
       *  Outport: '<Root>/Output'
       */
      tmp[i] += BM2F_ConstP.pooled1[165 * i_0 + i] * BM2F_U.Feedback[i_0];

      /* Gain: '<S3>/Gain' incorporates:
       *  Inport: '<Root>/Feedback'
       *  Outport: '<Root>/Output'
       */
      tmp_0[i] += BM2F_ConstP.pooled1[165 * i_0 + i] * BM2F_U.Feedback[27 + i_0];

      /* Gain: '<S4>/Gain' incorporates:
       *  Inport: '<Root>/Feedback'
       *  Outport: '<Root>/Output'
       */
      tmp_1[i] += BM2F_ConstP.pooled1[165 * i_0 + i] * BM2F_U.Feedback[54 + i_0];

      /* Gain: '<S5>/Gain' incorporates:
       *  Inport: '<Root>/Feedback'
       *  Outport: '<Root>/Output'
       */
      tmp_2[i] += BM2F_ConstP.pooled1[165 * i_0 + i] * BM2F_U.Feedback[81 + i_0];

      /* Gain: '<S6>/Gain' incorporates:
       *  Inport: '<Root>/Feedback'
       *  Outport: '<Root>/Output'
       */
      tmp_3[i] += BM2F_ConstP.pooled1[165 * i_0 + i] * BM2F_U.Feedback[108 + i_0];

      /* Gain: '<S7>/Gain' incorporates:
       *  Inport: '<Root>/Feedback'
       *  Outport: '<Root>/Output'
       */
      tmp_4[i] += BM2F_ConstP.pooled1[165 * i_0 + i] * BM2F_U.Feedback[135 + i_0];
    }
  }

  /* Gain: '<S8>/Gain' incorporates:
   *  Inport: '<Root>/Feedback'
   *  Outport: '<Root>/Output'
   */
  for (i = 0; i < 154; i++) {
    tmp_5[i] = 0.0;
    for (i_0 = 0; i_0 < 27; i_0++) {
      tmp_5[i] += BM2F_ConstP.Gain_Gain[154 * i_0 + i] * BM2F_U.Feedback[162 +
        i_0];
    }
  }

  /* End of Gain: '<S8>/Gain' */

  /* Outport: '<Root>/Output' */
  for (i = 0; i < 165; i++) {
    BM2F_Y.Output[i] = tmp[i];
    BM2F_Y.Output[i + 165] = tmp_0[i];
    BM2F_Y.Output[i + 330] = tmp_1[i];
    BM2F_Y.Output[i + 495] = tmp_2[i];
    BM2F_Y.Output[i + 660] = tmp_3[i];
    BM2F_Y.Output[i + 825] = tmp_4[i];
  }

  memcpy(&BM2F_Y.Output[990], &tmp_5[0], 154U * sizeof(real_T));
}

/* Model initialize function */
void BM2F_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(BM2F_M, (NULL));

  /* external inputs */
  (void)memset((void *)&BM2F_U, 0, sizeof(ExtU_BM2F_T));

  /* external outputs */
  (void) memset(&BM2F_Y.Output[0], 0,
                1144U*sizeof(real_T));
}

/* Model terminate function */
void BM2F_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
