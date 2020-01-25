/*
 * File: M1HPloadcells0.c
 *
 * Code generated for Simulink model 'M1HPloadcells0'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Fri Jan 24 15:37:35 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "M1HPloadcells0.h"
#include "M1HPloadcells0_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_M1HPloadcells0_T M1HPloadcells0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_M1HPloadcells0_T M1HPloadcells0_Y;

/* Real-time model */
RT_MODEL_M1HPloadcells0_T M1HPloadcells0_M_;
RT_MODEL_M1HPloadcells0_T *const M1HPloadcells0_M = &M1HPloadcells0_M_;

/* Model step function */
void M1HPloadcells0_step(void)
{
  int32_T i;

  /* Outport: '<Root>/Output' incorporates:
   *  Gain: '<S2>/HpK'
   *  Gain: '<S3>/HpK'
   *  Gain: '<S4>/HpK'
   *  Gain: '<S5>/HpK'
   *  Gain: '<S6>/HpK'
   *  Gain: '<S7>/HpK'
   *  Gain: '<S8>/HpK'
   *  Inport: '<Root>/Feedback'
   *  Sum: '<S2>/Sum1'
   *  Sum: '<S2>/Sum9'
   *  Sum: '<S3>/Sum1'
   *  Sum: '<S3>/Sum9'
   *  Sum: '<S4>/Sum1'
   *  Sum: '<S4>/Sum9'
   *  Sum: '<S5>/Sum1'
   *  Sum: '<S5>/Sum9'
   *  Sum: '<S6>/Sum1'
   *  Sum: '<S6>/Sum9'
   *  Sum: '<S7>/Sum1'
   *  Sum: '<S7>/Sum9'
   *  Sum: '<S8>/Sum1'
   *  Sum: '<S8>/Sum9'
   */
  for (i = 0; i < 6; i++) {
    M1HPloadcells0_Y.Output[i] = (M1HPloadcells0_U.Feedback[i + 48] -
      M1HPloadcells0_U.Feedback[i + 42]) * 1.5743999886111712E+8 -
      M1HPloadcells0_U.Feedback[i];
    M1HPloadcells0_Y.Output[i + 6] = (M1HPloadcells0_U.Feedback[i + 60] -
      M1HPloadcells0_U.Feedback[i + 54]) * 1.5743999886111712E+8 -
      M1HPloadcells0_U.Feedback[i + 6];
    M1HPloadcells0_Y.Output[i + 12] = (M1HPloadcells0_U.Feedback[i + 72] -
      M1HPloadcells0_U.Feedback[i + 66]) * 1.5743999886111712E+8 -
      M1HPloadcells0_U.Feedback[i + 12];
    M1HPloadcells0_Y.Output[i + 18] = (M1HPloadcells0_U.Feedback[i + 84] -
      M1HPloadcells0_U.Feedback[i + 78]) * 1.5743999886111712E+8 -
      M1HPloadcells0_U.Feedback[i + 18];
    M1HPloadcells0_Y.Output[i + 24] = (M1HPloadcells0_U.Feedback[i + 96] -
      M1HPloadcells0_U.Feedback[i + 90]) * 1.5743999886111712E+8 -
      M1HPloadcells0_U.Feedback[i + 24];
    M1HPloadcells0_Y.Output[i + 30] = (M1HPloadcells0_U.Feedback[i + 108] -
      M1HPloadcells0_U.Feedback[i + 102]) * 1.5743999886111712E+8 -
      M1HPloadcells0_U.Feedback[i + 30];
    M1HPloadcells0_Y.Output[i + 36] = (M1HPloadcells0_U.Feedback[i + 120] -
      M1HPloadcells0_U.Feedback[i + 114]) * 1.5743999886111712E+8 -
      M1HPloadcells0_U.Feedback[i + 36];
  }

  /* End of Outport: '<Root>/Output' */
}

/* Model initialize function */
void M1HPloadcells0_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(M1HPloadcells0_M, (NULL));

  /* external inputs */
  (void)memset((void *)&M1HPloadcells0_U, 0, sizeof(ExtU_M1HPloadcells0_T));

  /* external outputs */
  (void) memset(&M1HPloadcells0_Y.Output[0], 0,
                42U*sizeof(real_T));
}

/* Model terminate function */
void M1HPloadcells0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
