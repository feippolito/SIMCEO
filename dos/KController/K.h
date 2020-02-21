/*
 * File: K.h
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

#ifndef RTW_HEADER_K_h_
#define RTW_HEADER_K_h_
#include <string.h>
#include <stddef.h>
#ifndef K_COMMON_INCLUDES_
# define K_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* K_COMMON_INCLUDES_ */

#include "K_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: Koa)
   * Referenced by:
   *   '<S1>/Seg1'
   *   '<S1>/Seg2'
   *   '<S1>/Seg3'
   *   '<S1>/Seg4'
   *   '<S1>/Seg5'
   *   '<S1>/Seg6'
   */
  real_T pooled1[25410];

  /* Expression: Kcs
   * Referenced by: '<S1>/Seg7'
   */
  real_T Seg7_Gain[23716];
} ConstP_K_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Feedback[1144];               /* '<Root>/Feedback' */
} ExtU_K_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output[1078];                 /* '<Root>/Output' */
} ExtY_K_T;

/* Real-time Model Data Structure */
struct tag_RTM_K_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_K_T K_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_K_T K_Y;

/* Constant parameters (default storage) */
extern const ConstP_K_T K_ConstP;

/* Model entry point functions */
extern void K_initialize(void);
extern void K_step(void);
extern void K_terminate(void);

/* Real-time Model object */
extern RT_MODEL_K_T *const K_M;

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
 * hilite_system('BendingModesInterfaceDrivers/K')    - opens subsystem BendingModesInterfaceDrivers/K
 * hilite_system('BendingModesInterfaceDrivers/K/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BendingModesInterfaceDrivers'
 * '<S1>'   : 'BendingModesInterfaceDrivers/K'
 */
#endif                                 /* RTW_HEADER_K_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
