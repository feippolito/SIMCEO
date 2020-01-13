/*
 * File: rM1Pos0.c
 *
 * Code generated for Simulink model 'rM1Pos0'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Jan 13 14:33:08 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rM1Pos0.h"
#include "rM1Pos0_private.h"

/* Block states (default storage) */
DW_rM1Pos0_T rM1Pos0_DW;

/* External inputs (root inport signals with default storage) */
ExtU_rM1Pos0_T rM1Pos0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_rM1Pos0_T rM1Pos0_Y;

/* Real-time model */
RT_MODEL_rM1Pos0_T rM1Pos0_M_;
RT_MODEL_rM1Pos0_T *const rM1Pos0_M = &rM1Pos0_M_;

/* Model step function */
void rM1Pos0_step(void)
{
  int32_T k;
  int32_T memOffset;
  real_T rtb_HpK8[6];
  real_T rtb_HpK1[6];
  real_T rtb_HpK2[6];
  real_T rtb_HpK3[6];
  real_T rtb_HpK4[6];
  real_T rtb_HpK5[6];
  real_T rtb_TmpSignalConversionAtCG2Hp8[6];
  real_T tmp[6];
  real_T tmp_0[6];
  real_T tmp_1[6];
  real_T tmp_2[6];
  real_T tmp_3[6];
  real_T tmp_4[6];
  real_T tmp_5[6];
  real_T rtb_HpK8_a;
  real_T rtb_HpK1_m;
  real_T rtb_HpK2_l;
  real_T rtb_HpK3_l;
  real_T rtb_HpK4_o;
  real_T rtb_HpK5_m;
  real_T rtb_TmpSignalConversionAtCG2H_a;
  int32_T rtb_HpK8_tmp;

  /* SignalConversion: '<S1>/TmpSignal ConversionAtCG2Hp1Inport1' incorporates:
   *  Gain: '<S1>/CG2Hp1'
   *  Inport: '<Root>/Feedback'
   */
  tmp[0] = rM1Pos0_U.Feedback[6];
  tmp[3] = rM1Pos0_U.Feedback[27];
  tmp[1] = rM1Pos0_U.Feedback[7];
  tmp[4] = rM1Pos0_U.Feedback[28];
  tmp[2] = rM1Pos0_U.Feedback[8];
  tmp[5] = rM1Pos0_U.Feedback[29];

  /* SignalConversion: '<S1>/TmpSignal ConversionAtCG2Hp2Inport1' incorporates:
   *  Gain: '<S1>/CG2Hp2'
   *  Inport: '<Root>/Feedback'
   */
  tmp_0[0] = rM1Pos0_U.Feedback[9];
  tmp_0[3] = rM1Pos0_U.Feedback[30];
  tmp_0[1] = rM1Pos0_U.Feedback[10];
  tmp_0[4] = rM1Pos0_U.Feedback[31];
  tmp_0[2] = rM1Pos0_U.Feedback[11];
  tmp_0[5] = rM1Pos0_U.Feedback[32];

  /* SignalConversion: '<S1>/TmpSignal ConversionAtCG2Hp3Inport1' incorporates:
   *  Gain: '<S1>/CG2Hp3'
   *  Inport: '<Root>/Feedback'
   */
  tmp_1[0] = rM1Pos0_U.Feedback[12];
  tmp_1[3] = rM1Pos0_U.Feedback[33];
  tmp_1[1] = rM1Pos0_U.Feedback[13];
  tmp_1[4] = rM1Pos0_U.Feedback[34];
  tmp_1[2] = rM1Pos0_U.Feedback[14];
  tmp_1[5] = rM1Pos0_U.Feedback[35];

  /* SignalConversion: '<S1>/TmpSignal ConversionAtCG2Hp4Inport1' incorporates:
   *  Gain: '<S1>/CG2Hp4'
   *  Inport: '<Root>/Feedback'
   */
  tmp_2[0] = rM1Pos0_U.Feedback[15];
  tmp_2[3] = rM1Pos0_U.Feedback[36];
  tmp_2[1] = rM1Pos0_U.Feedback[16];
  tmp_2[4] = rM1Pos0_U.Feedback[37];
  tmp_2[2] = rM1Pos0_U.Feedback[17];
  tmp_2[5] = rM1Pos0_U.Feedback[38];

  /* SignalConversion: '<S1>/TmpSignal ConversionAtCG2Hp5Inport1' incorporates:
   *  Gain: '<S1>/CG2Hp5'
   *  Inport: '<Root>/Feedback'
   */
  tmp_3[0] = rM1Pos0_U.Feedback[18];
  tmp_3[3] = rM1Pos0_U.Feedback[39];
  tmp_3[1] = rM1Pos0_U.Feedback[19];
  tmp_3[4] = rM1Pos0_U.Feedback[40];
  tmp_3[2] = rM1Pos0_U.Feedback[20];
  tmp_3[5] = rM1Pos0_U.Feedback[41];

  /* SignalConversion: '<S1>/TmpSignal ConversionAtCG2Hp6Inport1' incorporates:
   *  Gain: '<S1>/CG2Hp6'
   *  Inport: '<Root>/Feedback'
   */
  tmp_4[0] = rM1Pos0_U.Feedback[0];
  tmp_4[3] = rM1Pos0_U.Feedback[21];
  tmp_4[1] = rM1Pos0_U.Feedback[1];
  tmp_4[4] = rM1Pos0_U.Feedback[22];
  tmp_4[2] = rM1Pos0_U.Feedback[2];
  tmp_4[5] = rM1Pos0_U.Feedback[23];

  /* SignalConversion: '<S1>/TmpSignal ConversionAtCG2Hp8Inport1' incorporates:
   *  Gain: '<S1>/CG2Hp8'
   *  Inport: '<Root>/Feedback'
   */
  tmp_5[0] = rM1Pos0_U.Feedback[3];
  tmp_5[3] = rM1Pos0_U.Feedback[24];
  tmp_5[1] = rM1Pos0_U.Feedback[4];
  tmp_5[4] = rM1Pos0_U.Feedback[25];
  tmp_5[2] = rM1Pos0_U.Feedback[5];
  tmp_5[5] = rM1Pos0_U.Feedback[26];
  for (k = 0; k < 6; k++) {
    /* DiscreteFilter: '<S1>/Discrete Filter' */
    memOffset = k << 2;

    /* Gain: '<S1>/HpK8' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter'
     */
    rtb_HpK8_a = (((rM1Pos0_DW.DiscreteFilter_states[memOffset + 1] *
                    -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                    rM1Pos0_DW.DiscreteFilter_states[memOffset]) +
                   rM1Pos0_DW.DiscreteFilter_states[memOffset + 2] *
                   -5.40605452685298E-5) +
                  rM1Pos0_DW.DiscreteFilter_states[memOffset + 3] *
                  5.4366873931528294E-5) * 1.5743999886111712E+8;

    /* DiscreteFilter: '<S1>/Discrete Filter1' */
    memOffset = k << 2;

    /* Gain: '<S1>/HpK1' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter1'
     */
    rtb_HpK1_m = (((rM1Pos0_DW.DiscreteFilter1_states[memOffset + 1] *
                    -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                    rM1Pos0_DW.DiscreteFilter1_states[memOffset]) +
                   rM1Pos0_DW.DiscreteFilter1_states[memOffset + 2] *
                   -5.40605452685298E-5) +
                  rM1Pos0_DW.DiscreteFilter1_states[memOffset + 3] *
                  5.4366873931528294E-5) * 1.5743999886111712E+8;

    /* DiscreteFilter: '<S1>/Discrete Filter2' */
    memOffset = k << 2;

    /* Gain: '<S1>/HpK2' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter2'
     */
    rtb_HpK2_l = (((rM1Pos0_DW.DiscreteFilter2_states[memOffset + 1] *
                    -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                    rM1Pos0_DW.DiscreteFilter2_states[memOffset]) +
                   rM1Pos0_DW.DiscreteFilter2_states[memOffset + 2] *
                   -5.40605452685298E-5) +
                  rM1Pos0_DW.DiscreteFilter2_states[memOffset + 3] *
                  5.4366873931528294E-5) * 1.5743999886111712E+8;

    /* DiscreteFilter: '<S1>/Discrete Filter3' */
    memOffset = k << 2;

    /* Gain: '<S1>/HpK3' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter3'
     */
    rtb_HpK3_l = (((rM1Pos0_DW.DiscreteFilter3_states[memOffset + 1] *
                    -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                    rM1Pos0_DW.DiscreteFilter3_states[memOffset]) +
                   rM1Pos0_DW.DiscreteFilter3_states[memOffset + 2] *
                   -5.40605452685298E-5) +
                  rM1Pos0_DW.DiscreteFilter3_states[memOffset + 3] *
                  5.4366873931528294E-5) * 1.5743999886111712E+8;

    /* DiscreteFilter: '<S1>/Discrete Filter4' */
    memOffset = k << 2;

    /* Gain: '<S1>/HpK4' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter4'
     */
    rtb_HpK4_o = (((rM1Pos0_DW.DiscreteFilter4_states[memOffset + 1] *
                    -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                    rM1Pos0_DW.DiscreteFilter4_states[memOffset]) +
                   rM1Pos0_DW.DiscreteFilter4_states[memOffset + 2] *
                   -5.40605452685298E-5) +
                  rM1Pos0_DW.DiscreteFilter4_states[memOffset + 3] *
                  5.4366873931528294E-5) * 1.5743999886111712E+8;

    /* DiscreteFilter: '<S1>/Discrete Filter5' */
    memOffset = k << 2;

    /* Gain: '<S1>/HpK5' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter5'
     */
    rtb_HpK5_m = (((rM1Pos0_DW.DiscreteFilter5_states[memOffset + 1] *
                    -5.5465887689329465E-5 + 5.5160056819196816E-5 *
                    rM1Pos0_DW.DiscreteFilter5_states[memOffset]) +
                   rM1Pos0_DW.DiscreteFilter5_states[memOffset + 2] *
                   -5.40605452685298E-5) +
                  rM1Pos0_DW.DiscreteFilter5_states[memOffset + 3] *
                  5.4366873931528294E-5) * 1.5743999886111712E+8;

    /* DiscreteFilter: '<S1>/Discrete Filter6' */
    memOffset = k << 2;

    /* Gain: '<S1>/HpK6' incorporates:
     *  DiscreteFilter: '<S1>/Discrete Filter6'
     */
    rtb_TmpSignalConversionAtCG2H_a =
      (((rM1Pos0_DW.DiscreteFilter6_states[memOffset + 1] *
         -5.5465887689329465E-5 + 5.5160056819196816E-5 *
         rM1Pos0_DW.DiscreteFilter6_states[memOffset]) +
        rM1Pos0_DW.DiscreteFilter6_states[memOffset + 2] * -5.40605452685298E-5)
       + rM1Pos0_DW.DiscreteFilter6_states[memOffset + 3] *
       5.4366873931528294E-5) * 1.5743999886111712E+8;

    /* Outport: '<Root>/Output' */
    rM1Pos0_Y.Output[k] = rtb_HpK8_a;
    rM1Pos0_Y.Output[k + 6] = rtb_HpK1_m;
    rM1Pos0_Y.Output[k + 12] = rtb_HpK2_l;
    rM1Pos0_Y.Output[k + 18] = rtb_HpK3_l;
    rM1Pos0_Y.Output[k + 24] = rtb_HpK4_o;
    rM1Pos0_Y.Output[k + 30] = rtb_HpK5_m;
    rM1Pos0_Y.Output[k + 36] = rtb_TmpSignalConversionAtCG2H_a;

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
    rtb_TmpSignalConversionAtCG2Hp8[k] = rtb_TmpSignalConversionAtCG2H_a;

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
    rtb_TmpSignalConversionAtCG2Hp8[k] = 0.0;
    for (memOffset = 0; memOffset < 6; memOffset++) {
      /* Gain: '<S1>/CG2Hp1' incorporates:
       *  Gain: '<S1>/CG2Hp2'
       *  Gain: '<S1>/CG2Hp3'
       *  Gain: '<S1>/CG2Hp4'
       *  Gain: '<S1>/CG2Hp5'
       *  Gain: '<S1>/CG2Hp6'
       *  Gain: '<S1>/CG2Hp8'
       */
      rtb_HpK8_tmp = 6 * memOffset + k;
      rtb_HpK8[k] += rM1Pos0_ConstP.CG2Hp1_Gain[rtb_HpK8_tmp] * tmp[memOffset];

      /* Gain: '<S1>/CG2Hp2' */
      rtb_HpK1[k] += rM1Pos0_ConstP.CG2Hp2_Gain[rtb_HpK8_tmp] * tmp_0[memOffset];

      /* Gain: '<S1>/CG2Hp3' */
      rtb_HpK2[k] += rM1Pos0_ConstP.CG2Hp3_Gain[rtb_HpK8_tmp] * tmp_1[memOffset];

      /* Gain: '<S1>/CG2Hp4' */
      rtb_HpK3[k] += rM1Pos0_ConstP.CG2Hp4_Gain[rtb_HpK8_tmp] * tmp_2[memOffset];

      /* Gain: '<S1>/CG2Hp5' */
      rtb_HpK4[k] += rM1Pos0_ConstP.CG2Hp5_Gain[rtb_HpK8_tmp] * tmp_3[memOffset];

      /* Gain: '<S1>/CG2Hp6' */
      rtb_HpK5[k] += rM1Pos0_ConstP.CG2Hp6_Gain[rtb_HpK8_tmp] * tmp_4[memOffset];

      /* Gain: '<S1>/CG2Hp8' */
      rtb_TmpSignalConversionAtCG2Hp8[k] +=
        rM1Pos0_ConstP.CG2Hp8_Gain[rtb_HpK8_tmp] * tmp_5[memOffset];
    }

    /* Update for DiscreteFilter: '<S1>/Discrete Filter' */
    memOffset = k << 2;
    rtb_HpK8_a = (((rtb_HpK5[k] - -3.9658259936667708 *
                    rM1Pos0_DW.DiscreteFilter_states[memOffset]) -
                   rM1Pos0_DW.DiscreteFilter_states[memOffset + 1] *
                   5.8976852476007764) -
                  rM1Pos0_DW.DiscreteFilter_states[memOffset + 2] *
                  -3.8978920261025323) -
      rM1Pos0_DW.DiscreteFilter_states[memOffset + 3] * 0.96603277266632026;
    rM1Pos0_DW.DiscreteFilter_states[memOffset + 3] =
      rM1Pos0_DW.DiscreteFilter_states[memOffset + 2];
    rM1Pos0_DW.DiscreteFilter_states[memOffset + 2] =
      rM1Pos0_DW.DiscreteFilter_states[memOffset + 1];
    rM1Pos0_DW.DiscreteFilter_states[memOffset + 1] =
      rM1Pos0_DW.DiscreteFilter_states[memOffset];
    rM1Pos0_DW.DiscreteFilter_states[memOffset] = rtb_HpK8_a;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter1' */
    memOffset = k << 2;
    rtb_HpK8_a = (((rtb_TmpSignalConversionAtCG2Hp8[k] - -3.9658259936667708 *
                    rM1Pos0_DW.DiscreteFilter1_states[memOffset]) -
                   rM1Pos0_DW.DiscreteFilter1_states[memOffset + 1] *
                   5.8976852476007764) -
                  rM1Pos0_DW.DiscreteFilter1_states[memOffset + 2] *
                  -3.8978920261025323) -
      rM1Pos0_DW.DiscreteFilter1_states[memOffset + 3] * 0.96603277266632026;
    rM1Pos0_DW.DiscreteFilter1_states[memOffset + 3] =
      rM1Pos0_DW.DiscreteFilter1_states[memOffset + 2];
    rM1Pos0_DW.DiscreteFilter1_states[memOffset + 2] =
      rM1Pos0_DW.DiscreteFilter1_states[memOffset + 1];
    rM1Pos0_DW.DiscreteFilter1_states[memOffset + 1] =
      rM1Pos0_DW.DiscreteFilter1_states[memOffset];
    rM1Pos0_DW.DiscreteFilter1_states[memOffset] = rtb_HpK8_a;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter2' */
    memOffset = k << 2;
    rtb_HpK8_a = (((rtb_HpK8[k] - -3.9658259936667708 *
                    rM1Pos0_DW.DiscreteFilter2_states[memOffset]) -
                   rM1Pos0_DW.DiscreteFilter2_states[memOffset + 1] *
                   5.8976852476007764) -
                  rM1Pos0_DW.DiscreteFilter2_states[memOffset + 2] *
                  -3.8978920261025323) -
      rM1Pos0_DW.DiscreteFilter2_states[memOffset + 3] * 0.96603277266632026;
    rM1Pos0_DW.DiscreteFilter2_states[memOffset + 3] =
      rM1Pos0_DW.DiscreteFilter2_states[memOffset + 2];
    rM1Pos0_DW.DiscreteFilter2_states[memOffset + 2] =
      rM1Pos0_DW.DiscreteFilter2_states[memOffset + 1];
    rM1Pos0_DW.DiscreteFilter2_states[memOffset + 1] =
      rM1Pos0_DW.DiscreteFilter2_states[memOffset];
    rM1Pos0_DW.DiscreteFilter2_states[memOffset] = rtb_HpK8_a;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter3' */
    memOffset = k << 2;
    rtb_HpK8_a = (((rtb_HpK1[k] - -3.9658259936667708 *
                    rM1Pos0_DW.DiscreteFilter3_states[memOffset]) -
                   rM1Pos0_DW.DiscreteFilter3_states[memOffset + 1] *
                   5.8976852476007764) -
                  rM1Pos0_DW.DiscreteFilter3_states[memOffset + 2] *
                  -3.8978920261025323) -
      rM1Pos0_DW.DiscreteFilter3_states[memOffset + 3] * 0.96603277266632026;
    rM1Pos0_DW.DiscreteFilter3_states[memOffset + 3] =
      rM1Pos0_DW.DiscreteFilter3_states[memOffset + 2];
    rM1Pos0_DW.DiscreteFilter3_states[memOffset + 2] =
      rM1Pos0_DW.DiscreteFilter3_states[memOffset + 1];
    rM1Pos0_DW.DiscreteFilter3_states[memOffset + 1] =
      rM1Pos0_DW.DiscreteFilter3_states[memOffset];
    rM1Pos0_DW.DiscreteFilter3_states[memOffset] = rtb_HpK8_a;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter4' */
    memOffset = k << 2;
    rtb_HpK8_a = (((rtb_HpK2[k] - -3.9658259936667708 *
                    rM1Pos0_DW.DiscreteFilter4_states[memOffset]) -
                   rM1Pos0_DW.DiscreteFilter4_states[memOffset + 1] *
                   5.8976852476007764) -
                  rM1Pos0_DW.DiscreteFilter4_states[memOffset + 2] *
                  -3.8978920261025323) -
      rM1Pos0_DW.DiscreteFilter4_states[memOffset + 3] * 0.96603277266632026;
    rM1Pos0_DW.DiscreteFilter4_states[memOffset + 3] =
      rM1Pos0_DW.DiscreteFilter4_states[memOffset + 2];
    rM1Pos0_DW.DiscreteFilter4_states[memOffset + 2] =
      rM1Pos0_DW.DiscreteFilter4_states[memOffset + 1];
    rM1Pos0_DW.DiscreteFilter4_states[memOffset + 1] =
      rM1Pos0_DW.DiscreteFilter4_states[memOffset];
    rM1Pos0_DW.DiscreteFilter4_states[memOffset] = rtb_HpK8_a;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter5' */
    memOffset = k << 2;
    rtb_HpK8_a = (((rtb_HpK3[k] - -3.9658259936667708 *
                    rM1Pos0_DW.DiscreteFilter5_states[memOffset]) -
                   rM1Pos0_DW.DiscreteFilter5_states[memOffset + 1] *
                   5.8976852476007764) -
                  rM1Pos0_DW.DiscreteFilter5_states[memOffset + 2] *
                  -3.8978920261025323) -
      rM1Pos0_DW.DiscreteFilter5_states[memOffset + 3] * 0.96603277266632026;
    rM1Pos0_DW.DiscreteFilter5_states[memOffset + 3] =
      rM1Pos0_DW.DiscreteFilter5_states[memOffset + 2];
    rM1Pos0_DW.DiscreteFilter5_states[memOffset + 2] =
      rM1Pos0_DW.DiscreteFilter5_states[memOffset + 1];
    rM1Pos0_DW.DiscreteFilter5_states[memOffset + 1] =
      rM1Pos0_DW.DiscreteFilter5_states[memOffset];
    rM1Pos0_DW.DiscreteFilter5_states[memOffset] = rtb_HpK8_a;

    /* Update for DiscreteFilter: '<S1>/Discrete Filter6' */
    memOffset = k << 2;
    rtb_HpK8_a = (((rtb_HpK4[k] - -3.9658259936667708 *
                    rM1Pos0_DW.DiscreteFilter6_states[memOffset]) -
                   rM1Pos0_DW.DiscreteFilter6_states[memOffset + 1] *
                   5.8976852476007764) -
                  rM1Pos0_DW.DiscreteFilter6_states[memOffset + 2] *
                  -3.8978920261025323) -
      rM1Pos0_DW.DiscreteFilter6_states[memOffset + 3] * 0.96603277266632026;
    rM1Pos0_DW.DiscreteFilter6_states[memOffset + 3] =
      rM1Pos0_DW.DiscreteFilter6_states[memOffset + 2];
    rM1Pos0_DW.DiscreteFilter6_states[memOffset + 2] =
      rM1Pos0_DW.DiscreteFilter6_states[memOffset + 1];
    rM1Pos0_DW.DiscreteFilter6_states[memOffset + 1] =
      rM1Pos0_DW.DiscreteFilter6_states[memOffset];
    rM1Pos0_DW.DiscreteFilter6_states[memOffset] = rtb_HpK8_a;
  }
}

/* Model initialize function */
void rM1Pos0_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(rM1Pos0_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&rM1Pos0_DW, 0,
                sizeof(DW_rM1Pos0_T));

  /* external inputs */
  (void)memset((void *)&rM1Pos0_U, 0, sizeof(ExtU_rM1Pos0_T));

  /* external outputs */
  (void) memset(&rM1Pos0_Y.Output[0], 0,
                42U*sizeof(real_T));
}

/* Model terminate function */
void rM1Pos0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
