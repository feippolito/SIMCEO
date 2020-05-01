/*
 * File: M1loadcells_fullHpK_SD.c
 *
 * Code generated for Simulink model 'M1loadcells_fullHpK_SD'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Fri Feb 14 10:04:12 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1loadcells_fullHpK_SD.h"
#include "M1loadcells_fullHpK_SD_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_M1loadcells_fullHpK_SD_T M1loadcells_fullHpK_SD_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1loadcells_fullHpK_SD_T M1loadcells_fullHpK_SD_Y;

/* Real-time model */
RT_MODEL_M1loadcells_fullHpK__T M1loadcells_fullHpK_SD_M_;
RT_MODEL_M1loadcells_fullHpK__T *const M1loadcells_fullHpK_SD_M =
  &M1loadcells_fullHpK_SD_M_;

/* Model step function */
void M1loadcells_fullHpK_SD_step(void)
{
  real_T tmp[42];
  int32_T i;
  int32_T i_0;
  real_T tmp_0;

  /* SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1' incorporates:
   *  Inport: '<Root>/Feedback'
   *  Sum: '<S2>/Sum9'
   *  Sum: '<S3>/Sum9'
   *  Sum: '<S4>/Sum9'
   *  Sum: '<S5>/Sum9'
   *  Sum: '<S6>/Sum9'
   *  Sum: '<S7>/Sum9'
   *  Sum: '<S8>/Sum9'
   */
  for (i = 0; i < 6; i++) {
    tmp[i] = M1loadcells_fullHpK_SD_U.Feedback[48 + i] -
      M1loadcells_fullHpK_SD_U.Feedback[42 + i];
    tmp[i + 6] = M1loadcells_fullHpK_SD_U.Feedback[60 + i] -
      M1loadcells_fullHpK_SD_U.Feedback[54 + i];
    tmp[i + 12] = M1loadcells_fullHpK_SD_U.Feedback[72 + i] -
      M1loadcells_fullHpK_SD_U.Feedback[66 + i];
    tmp[i + 18] = M1loadcells_fullHpK_SD_U.Feedback[84 + i] -
      M1loadcells_fullHpK_SD_U.Feedback[78 + i];
    tmp[i + 24] = M1loadcells_fullHpK_SD_U.Feedback[96 + i] -
      M1loadcells_fullHpK_SD_U.Feedback[90 + i];
    tmp[i + 30] = M1loadcells_fullHpK_SD_U.Feedback[108 + i] -
      M1loadcells_fullHpK_SD_U.Feedback[102 + i];
    tmp[i + 36] = M1loadcells_fullHpK_SD_U.Feedback[120 + i] -
      M1loadcells_fullHpK_SD_U.Feedback[114 + i];
  }

  /* Outport: '<Root>/Output' incorporates:
   *  Gain: '<S1>/Gain'
   *  Inport: '<Root>/Feedback'
   *  SignalConversion: '<S1>/TmpSignal ConversionAtGainInport1'
   *  Sum: '<S1>/Sum9'
   */
  for (i = 0; i < 42; i++) {
    tmp_0 = 0.0;
    for (i_0 = 0; i_0 < 42; i_0++) {
      tmp_0 += M1loadcells_fullHpK_SD_ConstP.Gain_Gain[42 * i_0 + i] * tmp[i_0];
    }

    M1loadcells_fullHpK_SD_Y.Output[i] = tmp_0 -
      M1loadcells_fullHpK_SD_U.Feedback[i];
  }

  /* End of Outport: '<Root>/Output' */
}

/* Model initialize function */
void M1loadcells_fullHpK_SD_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1loadcells_fullHpK_SD_M, (NULL));

  /* external inputs */
  (void)memset((void *)&M1loadcells_fullHpK_SD_U, 0, sizeof
               (ExtU_M1loadcells_fullHpK_SD_T));

  /* external outputs */
  (void) memset(&M1loadcells_fullHpK_SD_Y.Output[0], 0,
                42U*sizeof(real_T));
}

/* Model terminate function */
void M1loadcells_fullHpK_SD_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
