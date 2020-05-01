/*
 * File: M1Pos0.h
 *
 * Code generated for Simulink model 'M1Pos0'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue Jan 21 09:48:41 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_M1Pos0_h_
#define RTW_HEADER_M1Pos0_h_
#include <string.h>
#include <stddef.h>
#ifndef M1Pos0_COMMON_INCLUDES_
# define M1Pos0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* M1Pos0_COMMON_INCLUDES_ */

#include "M1Pos0_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteFilter_states[24];    /* '<S1>/Discrete Filter' */
  real_T DiscreteFilter1_states[24];   /* '<S1>/Discrete Filter1' */
  real_T DiscreteFilter2_states[24];   /* '<S1>/Discrete Filter2' */
  real_T DiscreteFilter3_states[24];   /* '<S1>/Discrete Filter3' */
  real_T DiscreteFilter4_states[24];   /* '<S1>/Discrete Filter4' */
  real_T DiscreteFilter5_states[24];   /* '<S1>/Discrete Filter5' */
  real_T DiscreteFilter6_states[24];   /* '<S1>/Discrete Filter6' */
} DW_M1Pos0_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: M1Ctrl(3).CG2Hp
   * Referenced by: '<S1>/CG2Hp1'
   */
  real_T CG2Hp1_Gain[36];

  /* Expression: M1Ctrl(4).CG2Hp
   * Referenced by: '<S1>/CG2Hp2'
   */
  real_T CG2Hp2_Gain[36];

  /* Expression: M1Ctrl(5).CG2Hp
   * Referenced by: '<S1>/CG2Hp3'
   */
  real_T CG2Hp3_Gain[36];

  /* Expression: M1Ctrl(6).CG2Hp
   * Referenced by: '<S1>/CG2Hp4'
   */
  real_T CG2Hp4_Gain[36];

  /* Expression: M1Ctrl(7).CG2Hp
   * Referenced by: '<S1>/CG2Hp5'
   */
  real_T CG2Hp5_Gain[36];

  /* Expression: M1Ctrl(1).CG2Hp
   * Referenced by: '<S1>/CG2Hp6'
   */
  real_T CG2Hp6_Gain[36];

  /* Expression: M1Ctrl(2).CG2Hp
   * Referenced by: '<S1>/CG2Hp8'
   */
  real_T CG2Hp8_Gain[36];
} ConstP_M1Pos0_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Feedback[42];                 /* '<Root>/Feedback' */
} ExtU_M1Pos0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output[42];                   /* '<Root>/Output' */
} ExtY_M1Pos0_T;

/* Real-time Model Data Structure */
struct tag_RTM_M1Pos0_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_M1Pos0_T M1Pos0_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_M1Pos0_T M1Pos0_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_M1Pos0_T M1Pos0_Y;

/* Constant parameters (default storage) */
extern const ConstP_M1Pos0_T M1Pos0_ConstP;

/* Model entry point functions */
extern void M1Pos0_initialize(void);
extern void M1Pos0_step(void);
extern void M1Pos0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_M1Pos0_T *const M1Pos0_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('M1Pos/M1Pos')    - opens subsystem M1Pos/M1Pos
 * hilite_system('M1Pos/M1Pos/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'M1Pos'
 * '<S1>'   : 'M1Pos/M1Pos'
 */
#endif                                 /* RTW_HEADER_M1Pos0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
