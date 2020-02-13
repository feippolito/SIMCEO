/*
 * File: BendingModesStatic0.c
 *
 * Code generated for Simulink model 'BendingModesStatic0'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue Feb 11 16:07:28 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BendingModesStatic0.h"
#include "BendingModesStatic0_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_BendingModesStatic0_T BendingModesStatic0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_BendingModesStatic0_T BendingModesStatic0_Y;

/* Real-time model */
RT_MODEL_BendingModesStatic0_T BendingModesStatic0_M_;
RT_MODEL_BendingModesStatic0_T *const BendingModesStatic0_M =
  &BendingModesStatic0_M_;

/* Model step function */
void BendingModesStatic0_step(void)
{
  real_T rtb_Gain1_o[495];
  real_T rtb_Gain1_h[495];
  real_T rtb_Gain1_e5[495];
  real_T rtb_Gain1_i[495];
  real_T rtb_Gain1_p[495];
  real_T rtb_Gain1_ov[495];
  real_T rtb_Gain1[462];
  real_T tmp[495];
  int32_T i;
  int32_T i_0;
  real_T tmp_0[165];
  real_T tmp_1[27];

  /* Gain: '<S6>/Gain2' incorporates:
   *  Gain: '<S6>/Gain3'
   *  Inport: '<Root>/Feedback'
   */
  for (i = 0; i < 495; i++) {
    tmp[i] = 0.0;
    for (i_0 = 0; i_0 < 335; i_0++) {
      tmp[i] += BendingModesStatic0_ConstP.pooled1[495 * i_0 + i] *
        BendingModesStatic0_U.Feedback[1340 + i_0];
    }
  }

  /* End of Gain: '<S6>/Gain2' */

  /* Gain: '<S6>/Gain3' */
  for (i = 0; i < 165; i++) {
    rtb_Gain1_ov[i] = 0.0;
    for (i_0 = 0; i_0 < 495; i_0++) {
      rtb_Gain1_ov[i] += BendingModesStatic0_ConstP.pooled2[165 * i_0 + i] *
        tmp[i_0];
    }
  }

  /* Gain: '<S5>/Gain2' incorporates:
   *  Gain: '<S5>/Gain3'
   *  Inport: '<Root>/Feedback'
   */
  for (i = 0; i < 495; i++) {
    tmp[i] = 0.0;
    for (i_0 = 0; i_0 < 335; i_0++) {
      tmp[i] += BendingModesStatic0_ConstP.pooled1[495 * i_0 + i] *
        BendingModesStatic0_U.Feedback[1005 + i_0];
    }
  }

  /* End of Gain: '<S5>/Gain2' */

  /* Gain: '<S5>/Gain3' */
  for (i = 0; i < 165; i++) {
    rtb_Gain1_p[i] = 0.0;
    for (i_0 = 0; i_0 < 495; i_0++) {
      rtb_Gain1_p[i] += BendingModesStatic0_ConstP.pooled2[165 * i_0 + i] *
        tmp[i_0];
    }
  }

  /* Gain: '<S4>/Gain2' incorporates:
   *  Gain: '<S4>/Gain3'
   *  Inport: '<Root>/Feedback'
   */
  for (i = 0; i < 495; i++) {
    tmp[i] = 0.0;
    for (i_0 = 0; i_0 < 335; i_0++) {
      tmp[i] += BendingModesStatic0_ConstP.pooled1[495 * i_0 + i] *
        BendingModesStatic0_U.Feedback[670 + i_0];
    }
  }

  /* End of Gain: '<S4>/Gain2' */

  /* Gain: '<S4>/Gain3' */
  for (i = 0; i < 165; i++) {
    rtb_Gain1_i[i] = 0.0;
    for (i_0 = 0; i_0 < 495; i_0++) {
      rtb_Gain1_i[i] += BendingModesStatic0_ConstP.pooled2[165 * i_0 + i] *
        tmp[i_0];
    }
  }

  /* Gain: '<S3>/Gain2' incorporates:
   *  Gain: '<S3>/Gain3'
   *  Inport: '<Root>/Feedback'
   */
  for (i = 0; i < 495; i++) {
    tmp[i] = 0.0;
    for (i_0 = 0; i_0 < 335; i_0++) {
      tmp[i] += BendingModesStatic0_ConstP.pooled1[495 * i_0 + i] *
        BendingModesStatic0_U.Feedback[335 + i_0];
    }
  }

  /* End of Gain: '<S3>/Gain2' */

  /* Gain: '<S3>/Gain3' */
  for (i = 0; i < 165; i++) {
    rtb_Gain1_e5[i] = 0.0;
    for (i_0 = 0; i_0 < 495; i_0++) {
      rtb_Gain1_e5[i] += BendingModesStatic0_ConstP.pooled2[165 * i_0 + i] *
        tmp[i_0];
    }
  }

  /* Gain: '<S2>/Gain2' incorporates:
   *  Gain: '<S2>/Gain3'
   *  Inport: '<Root>/Feedback'
   */
  for (i = 0; i < 495; i++) {
    tmp[i] = 0.0;
    for (i_0 = 0; i_0 < 335; i_0++) {
      tmp[i] += BendingModesStatic0_ConstP.pooled1[495 * i_0 + i] *
        BendingModesStatic0_U.Feedback[i_0];
    }
  }

  /* End of Gain: '<S2>/Gain2' */

  /* Gain: '<S2>/Gain3' */
  for (i = 0; i < 165; i++) {
    rtb_Gain1_h[i] = 0.0;
    for (i_0 = 0; i_0 < 495; i_0++) {
      rtb_Gain1_h[i] += BendingModesStatic0_ConstP.pooled2[165 * i_0 + i] *
        tmp[i_0];
    }
  }

  /* Gain: '<S8>/Gain2' incorporates:
   *  Gain: '<S8>/Gain3'
   *  Inport: '<Root>/Feedback'
   */
  for (i = 0; i < 462; i++) {
    rtb_Gain1[i] = 0.0;
    for (i_0 = 0; i_0 < 306; i_0++) {
      rtb_Gain1[i] += BendingModesStatic0_ConstP.Gain2_Gain[462 * i_0 + i] *
        BendingModesStatic0_U.Feedback[2010 + i_0];
    }
  }

  /* End of Gain: '<S8>/Gain2' */

  /* Gain: '<S8>/Gain3' */
  for (i = 0; i < 154; i++) {
    rtb_Gain1_o[i] = 0.0;
    for (i_0 = 0; i_0 < 462; i_0++) {
      rtb_Gain1_o[i] += BendingModesStatic0_ConstP.Gain3_Gain[154 * i_0 + i] *
        rtb_Gain1[i_0];
    }
  }

  /* Gain: '<S8>/Gain1' */
  for (i = 0; i < 27; i++) {
    rtb_Gain1[i] = 0.0;
    for (i_0 = 0; i_0 < 154; i_0++) {
      rtb_Gain1[i] += BendingModesStatic0_ConstP.Gain1_Gain[27 * i_0 + i] *
        rtb_Gain1_o[i_0];
    }
  }

  /* End of Gain: '<S8>/Gain1' */

  /* Gain: '<S2>/Gain1' */
  for (i = 0; i < 27; i++) {
    rtb_Gain1_o[i] = 0.0;
    for (i_0 = 0; i_0 < 165; i_0++) {
      rtb_Gain1_o[i] += BendingModesStatic0_ConstP.pooled3[27 * i_0 + i] *
        rtb_Gain1_h[i_0];
    }
  }

  /* End of Gain: '<S2>/Gain1' */

  /* Gain: '<S3>/Gain1' */
  for (i = 0; i < 27; i++) {
    rtb_Gain1_h[i] = 0.0;
    for (i_0 = 0; i_0 < 165; i_0++) {
      rtb_Gain1_h[i] += BendingModesStatic0_ConstP.pooled3[27 * i_0 + i] *
        rtb_Gain1_e5[i_0];
    }
  }

  /* End of Gain: '<S3>/Gain1' */

  /* Gain: '<S4>/Gain1' */
  for (i = 0; i < 27; i++) {
    rtb_Gain1_e5[i] = 0.0;
    for (i_0 = 0; i_0 < 165; i_0++) {
      rtb_Gain1_e5[i] += BendingModesStatic0_ConstP.pooled3[27 * i_0 + i] *
        rtb_Gain1_i[i_0];
    }
  }

  /* End of Gain: '<S4>/Gain1' */

  /* Gain: '<S5>/Gain1' */
  for (i = 0; i < 27; i++) {
    rtb_Gain1_i[i] = 0.0;
    for (i_0 = 0; i_0 < 165; i_0++) {
      rtb_Gain1_i[i] += BendingModesStatic0_ConstP.pooled3[27 * i_0 + i] *
        rtb_Gain1_p[i_0];
    }
  }

  /* End of Gain: '<S5>/Gain1' */

  /* Gain: '<S6>/Gain1' */
  for (i = 0; i < 27; i++) {
    rtb_Gain1_p[i] = 0.0;
    for (i_0 = 0; i_0 < 165; i_0++) {
      rtb_Gain1_p[i] += BendingModesStatic0_ConstP.pooled3[27 * i_0 + i] *
        rtb_Gain1_ov[i_0];
    }
  }

  /* End of Gain: '<S6>/Gain1' */

  /* Gain: '<S7>/Gain2' incorporates:
   *  Gain: '<S7>/Gain3'
   *  Inport: '<Root>/Feedback'
   */
  for (i = 0; i < 495; i++) {
    tmp[i] = 0.0;
    for (i_0 = 0; i_0 < 335; i_0++) {
      tmp[i] += BendingModesStatic0_ConstP.pooled1[495 * i_0 + i] *
        BendingModesStatic0_U.Feedback[1675 + i_0];
    }
  }

  /* End of Gain: '<S7>/Gain2' */

  /* Gain: '<S7>/Gain3' incorporates:
   *  Gain: '<S7>/Gain1'
   */
  for (i = 0; i < 165; i++) {
    tmp_0[i] = 0.0;
    for (i_0 = 0; i_0 < 495; i_0++) {
      tmp_0[i] += BendingModesStatic0_ConstP.pooled2[165 * i_0 + i] * tmp[i_0];
    }
  }

  for (i = 0; i < 27; i++) {
    /* Gain: '<S7>/Gain1' incorporates:
     *  Outport: '<Root>/Output'
     */
    tmp_1[i] = 0.0;
    for (i_0 = 0; i_0 < 165; i_0++) {
      tmp_1[i] += BendingModesStatic0_ConstP.pooled3[27 * i_0 + i] * tmp_0[i_0];
    }

    /* Outport: '<Root>/Output' */
    BendingModesStatic0_Y.Output[i] = rtb_Gain1_o[i];
    BendingModesStatic0_Y.Output[i + 27] = rtb_Gain1_h[i];
    BendingModesStatic0_Y.Output[i + 54] = rtb_Gain1_e5[i];
    BendingModesStatic0_Y.Output[i + 81] = rtb_Gain1_i[i];
    BendingModesStatic0_Y.Output[i + 108] = rtb_Gain1_p[i];
    BendingModesStatic0_Y.Output[i + 135] = tmp_1[i];
    BendingModesStatic0_Y.Output[i + 162] = rtb_Gain1[i];
  }
}

/* Model initialize function */
void BendingModesStatic0_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(BendingModesStatic0_M, (NULL));

  /* external inputs */
  (void)memset((void *)&BendingModesStatic0_U, 0, sizeof
               (ExtU_BendingModesStatic0_T));

  /* external outputs */
  (void) memset(&BendingModesStatic0_Y.Output[0], 0,
                189U*sizeof(real_T));
}

/* Model terminate function */
void BendingModesStatic0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
