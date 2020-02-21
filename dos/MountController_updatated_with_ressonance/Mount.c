/*
 * File: Mount.c
 *
 * Code generated for Simulink model 'Mount'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Fri Feb 14 16:23:01 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mount.h"
#include "Mount_private.h"

/* Block states (default storage) */
DW_Mount_T Mount_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Mount_T Mount_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Mount_T Mount_Y;

/* Real-time model */
RT_MODEL_Mount_T Mount_M_;
RT_MODEL_Mount_T *const Mount_M = &Mount_M_;

/* Model step function */
void Mount_step(void)
{
  /* local block i/o variables */
  real_T rtb_AzAverage;
  real_T rtb_Elaverage;
  real_T rtb_Sum4;
  real_T rtb_Sum1;
  real_T rtb_DiscreteStateSpace;
  real_T rtb_Sum;
  real_T rtb_DiscreteStateSpace_b;
  real_T rtb_Internal;
  real_T rtb_converttoAzdriveforces[8];
  real_T rtb_converttoEldriveforces[8];
  int32_T i;

  /* DiscreteStateSpace: '<S3>/Internal' */
  {
    rtb_Internal = (0.6282)*Mount_DW.Internal_DSTATE[3] + (-0.2846)*
      Mount_DW.Internal_DSTATE[4];
  }

  /* Gain: '<S1>/convert to Az drive forces' */
  for (i = 0; i < 8; i++) {
    rtb_converttoAzdriveforces[i] = Mount_ConstP.pooled6[i] * rtb_Internal;
  }

  /* End of Gain: '<S1>/convert to Az drive forces' */

  /* DiscreteStateSpace: '<S6>/Internal' */
  {
    rtb_Internal = (0.6282)*Mount_DW.Internal_DSTATE_a[3] + (-0.2846)*
      Mount_DW.Internal_DSTATE_a[4];
  }

  /* Gain: '<S1>/convert to El drive forces' */
  for (i = 0; i < 8; i++) {
    rtb_converttoEldriveforces[i] = Mount_ConstP.pooled6[i] * rtb_Internal;
  }

  /* End of Gain: '<S1>/convert to El drive forces' */

  /* DiscreteStateSpace: '<S8>/Discrete State-Space' */
  {
    {
      static const int_T colCidxRow0[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = Mount_ConstP.DiscreteStateSpace_C;
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE[0];
      real_T *y0 = &rtb_Internal;
      int_T numNonZero = 8;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }
  }

  /* Outport: '<Root>/Output' incorporates:
   *  Gain: '<S1>/convert to GIR drive forces'
   */
  for (i = 0; i < 8; i++) {
    Mount_Y.Output[i] = rtb_converttoAzdriveforces[i];
    Mount_Y.Output[i + 8] = rtb_converttoEldriveforces[i];
  }

  Mount_Y.Output[16] = -rtb_Internal;
  Mount_Y.Output[17] = -rtb_Internal;
  Mount_Y.Output[18] = rtb_Internal;
  Mount_Y.Output[19] = rtb_Internal;

  /* End of Outport: '<Root>/Output' */

  /* Gain: '<S1>/Az Average' incorporates:
   *  Inport: '<Root>/Feedback'
   *  Sum: '<S1>/Sum7'
   */
  rtb_AzAverage = (((Mount_U.Feedback[4] - Mount_U.Feedback[0]) * 0.25 +
                    (Mount_U.Feedback[5] - Mount_U.Feedback[1]) * 0.25) +
                   (Mount_U.Feedback[6] - Mount_U.Feedback[2]) * 0.25) +
    (Mount_U.Feedback[7] - Mount_U.Feedback[3]) * 0.25;

  /* Gain: '<S1>/El average' incorporates:
   *  Inport: '<Root>/Feedback'
   *  Sum: '<S1>/Sum6'
   */
  rtb_Elaverage = (((Mount_U.Feedback[12] - Mount_U.Feedback[8]) * 0.25 +
                    (Mount_U.Feedback[13] - Mount_U.Feedback[9]) * 0.25) +
                   (Mount_U.Feedback[14] - Mount_U.Feedback[10]) * 0.25) +
    (Mount_U.Feedback[15] - Mount_U.Feedback[11]) * 0.25;

  /* Gain: '<S1>/average2' incorporates:
   *  Inport: '<Root>/Feedback'
   *  Sum: '<S1>/Sum5'
   */
  rtb_Internal = (Mount_U.Feedback[18] - Mount_U.Feedback[16]) * 0.5 +
    (Mount_U.Feedback[19] - Mount_U.Feedback[17]) * 0.5;

  /* Sum: '<S1>/Sum4' incorporates:
   *  Inport: '<Root>/Reference'
   */
  rtb_Sum4 = Mount_U.Reference[2] - rtb_Internal;

  /* DiscreteStateSpace: '<S2>/Internal' */
  {
    rtb_Internal = 0.0*Mount_DW.Internal_DSTATE_l[0] + 0.0*
      Mount_DW.Internal_DSTATE_l[1]
      + 0.0*Mount_DW.Internal_DSTATE_l[2]
      + 1.0*Mount_DW.Internal_DSTATE_l[3];
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Inport: '<Root>/Reference'
   */
  rtb_Sum1 = Mount_U.Reference[0] - rtb_Internal;

  /* DiscreteStateSpace: '<S4>/Discrete State-Space' */
  {
    {
      static const int_T colCidxRow0[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = Mount_ConstP.DiscreteStateSpace_C_h;
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_g[0];
      real_T *y0 = &rtb_DiscreteStateSpace;
      int_T numNonZero = 8;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }
  }

  /* DiscreteStateSpace: '<S5>/Internal' */
  {
    rtb_Internal = 0.0*Mount_DW.Internal_DSTATE_e[0] + 0.0*
      Mount_DW.Internal_DSTATE_e[1]
      + 0.0*Mount_DW.Internal_DSTATE_e[2]
      + 1.0*Mount_DW.Internal_DSTATE_e[3];
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  Inport: '<Root>/Reference'
   */
  rtb_Sum = Mount_U.Reference[1] - rtb_Internal;

  /* DiscreteStateSpace: '<S7>/Discrete State-Space' */
  {
    {
      static const int_T colCidxRow0[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = Mount_ConstP.DiscreteStateSpace_C_a;
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_c[0];
      real_T *y0 = &rtb_DiscreteStateSpace_b;
      int_T numNonZero = 8;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }
  }

  /* Update for DiscreteStateSpace: '<S3>/Internal' */
  {
    real_T xnew[5];
    xnew[0] = (0.8282)*Mount_DW.Internal_DSTATE[0];
    xnew[0] += 0.5*rtb_DiscreteStateSpace;
    xnew[1] = (1.0)*Mount_DW.Internal_DSTATE[0];
    xnew[2] = (1.0)*Mount_DW.Internal_DSTATE[1];
    xnew[3] = (1.0)*Mount_DW.Internal_DSTATE[2];
    xnew[4] = (1.0)*Mount_DW.Internal_DSTATE[3];
    (void) memcpy(&Mount_DW.Internal_DSTATE[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S6>/Internal' */
  {
    real_T xnew[5];
    xnew[0] = (0.8282)*Mount_DW.Internal_DSTATE_a[0];
    xnew[0] += 0.5*rtb_DiscreteStateSpace_b;
    xnew[1] = (1.0)*Mount_DW.Internal_DSTATE_a[0];
    xnew[2] = (1.0)*Mount_DW.Internal_DSTATE_a[1];
    xnew[3] = (1.0)*Mount_DW.Internal_DSTATE_a[2];
    xnew[4] = (1.0)*Mount_DW.Internal_DSTATE_a[3];
    (void) memcpy(&Mount_DW.Internal_DSTATE_a[0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S8>/Discrete State-Space' */
  {
    real_T xnew[9];
    xnew[0] = (1.0)*Mount_DW.DiscreteStateSpace_DSTATE[0];
    xnew[0] += (-0.73779834346491513)*rtb_Sum4;

    {
      static const int_T colAidxRow1[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA1 = &Mount_ConstP.DiscreteStateSpace_A[1];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 7;
      *pxnew1 = (*pA1++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA1++) * xd[*pAidx++];
      }
    }

    xnew[1] += (7.7574414043652791)*rtb_Sum4;

    {
      static const int_T colAidxRow2[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA9 = &Mount_ConstP.DiscreteStateSpace_A[9];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 7;
      *pxnew2 = (*pA9++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA9++) * xd[*pAidx++];
      }
    }

    xnew[2] += (-54.295350765290571)*rtb_Sum4;

    {
      static const int_T colAidxRow3[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA17 = &Mount_ConstP.DiscreteStateSpace_A[17];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 7;
      *pxnew3 = (*pA17++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA17++) * xd[*pAidx++];
      }
    }

    xnew[3] += (22.753203298635377)*rtb_Sum4;

    {
      static const int_T colAidxRow4[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA25 = &Mount_ConstP.DiscreteStateSpace_A[25];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 7;
      *pxnew4 = (*pA25++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA25++) * xd[*pAidx++];
      }
    }

    xnew[4] += (2.4734922827840045)*rtb_Sum4;

    {
      static const int_T colAidxRow5[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA33 = &Mount_ConstP.DiscreteStateSpace_A[33];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 7;
      *pxnew5 = (*pA33++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA33++) * xd[*pAidx++];
      }
    }

    xnew[5] += (0.86328659965850263)*rtb_Sum4;

    {
      static const int_T colAidxRow6[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA41 = &Mount_ConstP.DiscreteStateSpace_A[41];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 7;
      *pxnew6 = (*pA41++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA41++) * xd[*pAidx++];
      }
    }

    xnew[6] += (-1.0755588687526791)*rtb_Sum4;

    {
      static const int_T colAidxRow7[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA49 = &Mount_ConstP.DiscreteStateSpace_A[49];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 7;
      *pxnew7 = (*pA49++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA49++) * xd[*pAidx++];
      }
    }

    xnew[7] += (-3.3435694297110636)*rtb_Sum4;

    {
      static const int_T colAidxRow8[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA57 = &Mount_ConstP.DiscreteStateSpace_A[57];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 7;
      *pxnew8 = (*pA57++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA57++) * xd[*pAidx++];
      }
    }

    xnew[8] += (-1.0137772694793006)*rtb_Sum4;
    (void) memcpy(&Mount_DW.DiscreteStateSpace_DSTATE[0], xnew,
                  sizeof(real_T)*9);
  }

  /* Update for DiscreteStateSpace: '<S2>/Internal' */
  {
    real_T xtmp = rtb_AzAverage;
    xtmp += (-0.0)*Mount_DW.Internal_DSTATE_l[0] + (-0.0)*
      Mount_DW.Internal_DSTATE_l[1]
      + (-0.0)*Mount_DW.Internal_DSTATE_l[2]
      + (-0.0)*Mount_DW.Internal_DSTATE_l[3];
    Mount_DW.Internal_DSTATE_l[3] = Mount_DW.Internal_DSTATE_l[2];
    Mount_DW.Internal_DSTATE_l[2] = Mount_DW.Internal_DSTATE_l[1];
    Mount_DW.Internal_DSTATE_l[1] = Mount_DW.Internal_DSTATE_l[0];
    Mount_DW.Internal_DSTATE_l[0] = xtmp;
  }

  /* Update for DiscreteStateSpace: '<S4>/Discrete State-Space' */
  {
    real_T xnew[9];
    xnew[0] = (1.0)*Mount_DW.DiscreteStateSpace_DSTATE_g[0];
    xnew[0] += (-1.0624296145894747)*rtb_Sum1;

    {
      static const int_T colAidxRow1[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA1 = &Mount_ConstP.DiscreteStateSpace_A_k[1];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_g[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 7;
      *pxnew1 = (*pA1++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA1++) * xd[*pAidx++];
      }
    }

    xnew[1] += (13.438834548471775)*rtb_Sum1;

    {
      static const int_T colAidxRow2[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA9 = &Mount_ConstP.DiscreteStateSpace_A_k[9];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_g[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 7;
      *pxnew2 = (*pA9++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA9++) * xd[*pAidx++];
      }
    }

    xnew[2] += (-81.339864385616991)*rtb_Sum1;

    {
      static const int_T colAidxRow3[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA17 = &Mount_ConstP.DiscreteStateSpace_A_k[17];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_g[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 7;
      *pxnew3 = (*pA17++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA17++) * xd[*pAidx++];
      }
    }

    xnew[3] += (-52.158871582063213)*rtb_Sum1;

    {
      static const int_T colAidxRow4[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA25 = &Mount_ConstP.DiscreteStateSpace_A_k[25];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_g[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 7;
      *pxnew4 = (*pA25++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA25++) * xd[*pAidx++];
      }
    }

    xnew[4] += (3.1459846358294947)*rtb_Sum1;

    {
      static const int_T colAidxRow5[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA33 = &Mount_ConstP.DiscreteStateSpace_A_k[33];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_g[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 7;
      *pxnew5 = (*pA33++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA33++) * xd[*pAidx++];
      }
    }

    xnew[5] += (-6.57560621478371)*rtb_Sum1;

    {
      static const int_T colAidxRow6[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA41 = &Mount_ConstP.DiscreteStateSpace_A_k[41];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_g[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 7;
      *pxnew6 = (*pA41++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA41++) * xd[*pAidx++];
      }
    }

    xnew[6] += (7.6463534155762138)*rtb_Sum1;

    {
      static const int_T colAidxRow7[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA49 = &Mount_ConstP.DiscreteStateSpace_A_k[49];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_g[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 7;
      *pxnew7 = (*pA49++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA49++) * xd[*pAidx++];
      }
    }

    xnew[7] += (-4.1451026152997041)*rtb_Sum1;

    {
      static const int_T colAidxRow8[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA57 = &Mount_ConstP.DiscreteStateSpace_A_k[57];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_g[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 7;
      *pxnew8 = (*pA57++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA57++) * xd[*pAidx++];
      }
    }

    xnew[8] += (-0.3897158991897659)*rtb_Sum1;
    (void) memcpy(&Mount_DW.DiscreteStateSpace_DSTATE_g[0], xnew,
                  sizeof(real_T)*9);
  }

  /* Update for DiscreteStateSpace: '<S5>/Internal' */
  {
    real_T xtmp = rtb_Elaverage;
    xtmp += (-0.0)*Mount_DW.Internal_DSTATE_e[0] + (-0.0)*
      Mount_DW.Internal_DSTATE_e[1]
      + (-0.0)*Mount_DW.Internal_DSTATE_e[2]
      + (-0.0)*Mount_DW.Internal_DSTATE_e[3];
    Mount_DW.Internal_DSTATE_e[3] = Mount_DW.Internal_DSTATE_e[2];
    Mount_DW.Internal_DSTATE_e[2] = Mount_DW.Internal_DSTATE_e[1];
    Mount_DW.Internal_DSTATE_e[1] = Mount_DW.Internal_DSTATE_e[0];
    Mount_DW.Internal_DSTATE_e[0] = xtmp;
  }

  /* Update for DiscreteStateSpace: '<S7>/Discrete State-Space' */
  {
    real_T xnew[9];
    xnew[0] = (1.0)*Mount_DW.DiscreteStateSpace_DSTATE_c[0];
    xnew[0] += (-1.1772073291850156)*rtb_Sum;

    {
      static const int_T colAidxRow1[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA1 = &Mount_ConstP.DiscreteStateSpace_A_a[1];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_c[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 7;
      *pxnew1 = (*pA1++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA1++) * xd[*pAidx++];
      }
    }

    xnew[1] += (-49.137708337382037)*rtb_Sum;

    {
      static const int_T colAidxRow2[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA9 = &Mount_ConstP.DiscreteStateSpace_A_a[9];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_c[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 7;
      *pxnew2 = (*pA9++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA9++) * xd[*pAidx++];
      }
    }

    xnew[2] += (1.5580043786528874)*rtb_Sum;

    {
      static const int_T colAidxRow3[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA17 = &Mount_ConstP.DiscreteStateSpace_A_a[17];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_c[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 7;
      *pxnew3 = (*pA17++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA17++) * xd[*pAidx++];
      }
    }

    xnew[3] += (-17.69414043507885)*rtb_Sum;

    {
      static const int_T colAidxRow4[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA25 = &Mount_ConstP.DiscreteStateSpace_A_a[25];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_c[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 7;
      *pxnew4 = (*pA25++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA25++) * xd[*pAidx++];
      }
    }

    xnew[4] += (-0.062907626936175173)*rtb_Sum;

    {
      static const int_T colAidxRow5[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA33 = &Mount_ConstP.DiscreteStateSpace_A_a[33];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_c[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 7;
      *pxnew5 = (*pA33++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA33++) * xd[*pAidx++];
      }
    }

    xnew[5] += (-13.455284914561293)*rtb_Sum;

    {
      static const int_T colAidxRow6[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA41 = &Mount_ConstP.DiscreteStateSpace_A_a[41];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_c[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 7;
      *pxnew6 = (*pA41++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA41++) * xd[*pAidx++];
      }
    }

    xnew[6] += (-0.69639635920865617)*rtb_Sum;

    {
      static const int_T colAidxRow7[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA49 = &Mount_ConstP.DiscreteStateSpace_A_a[49];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_c[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 7;
      *pxnew7 = (*pA49++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA49++) * xd[*pAidx++];
      }
    }

    xnew[7] += (5.5107220591116972)*rtb_Sum;

    {
      static const int_T colAidxRow8[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA57 = &Mount_ConstP.DiscreteStateSpace_A_a[57];
      const real_T *xd = &Mount_DW.DiscreteStateSpace_DSTATE_c[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 7;
      *pxnew8 = (*pA57++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA57++) * xd[*pAidx++];
      }
    }

    xnew[8] += (-0.37139138307004754)*rtb_Sum;
    (void) memcpy(&Mount_DW.DiscreteStateSpace_DSTATE_c[0], xnew,
                  sizeof(real_T)*9);
  }
}

/* Model initialize function */
void Mount_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Mount_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Mount_DW, 0,
                sizeof(DW_Mount_T));

  /* external inputs */
  (void)memset((void *)&Mount_U, 0, sizeof(ExtU_Mount_T));

  /* external outputs */
  (void) memset(&Mount_Y.Output[0], 0,
                20U*sizeof(real_T));
}

/* Model terminate function */
void Mount_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
