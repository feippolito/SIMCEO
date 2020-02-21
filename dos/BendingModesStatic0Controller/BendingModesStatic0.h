/*
 * File: BendingModesStatic0.h
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

#ifndef RTW_HEADER_BendingModesStatic0_h_
#define RTW_HEADER_BendingModesStatic0_h_
#include <string.h>
#include <stddef.h>
#ifndef BendingModesStatic0_COMMON_INCLUDES_
# define BendingModesStatic0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* BendingModesStatic0_COMMON_INCLUDES_ */

#include "BendingModesStatic0_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: OA_Kred')
   * Referenced by:
   *   '<S2>/Gain2'
   *   '<S3>/Gain2'
   *   '<S4>/Gain2'
   *   '<S5>/Gain2'
   *   '<S6>/Gain2'
   *   '<S7>/Gain2'
   */
  real_T pooled1[165825];

  /* Expression: CS_Kred'
   * Referenced by: '<S8>/Gain2'
   */
  real_T Gain2_Gain[141372];

  /* Pooled Parameter (Expression: includeXY')
   * Referenced by:
   *   '<S2>/Gain3'
   *   '<S3>/Gain3'
   *   '<S4>/Gain3'
   *   '<S5>/Gain3'
   *   '<S6>/Gain3'
   *   '<S7>/Gain3'
   */
  real_T pooled2[81675];

  /* Expression: includeXY7'
   * Referenced by: '<S8>/Gain3'
   */
  real_T Gain3_Gain[71148];

  /* Expression: f2bm_cs
   * Referenced by: '<S8>/Gain1'
   */
  real_T Gain1_Gain[4158];

  /* Pooled Parameter (Expression: f2bm_oa)
   * Referenced by:
   *   '<S2>/Gain1'
   *   '<S3>/Gain1'
   *   '<S4>/Gain1'
   *   '<S5>/Gain1'
   *   '<S6>/Gain1'
   *   '<S7>/Gain1'
   */
  real_T pooled3[4455];
} ConstP_BendingModesStatic0_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Feedback[2316];               /* '<Root>/Feedback' */
} ExtU_BendingModesStatic0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output[189];                  /* '<Root>/Output' */
} ExtY_BendingModesStatic0_T;

/* Real-time Model Data Structure */
struct tag_RTM_BendingModesStatic0_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_BendingModesStatic0_T BendingModesStatic0_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_BendingModesStatic0_T BendingModesStatic0_Y;

/* Constant parameters (default storage) */
extern const ConstP_BendingModesStatic0_T BendingModesStatic0_ConstP;

/* Model entry point functions */
extern void BendingModesStatic0_initialize(void);
extern void BendingModesStatic0_step(void);
extern void BendingModesStatic0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BendingModesStatic0_T *const BendingModesStatic0_M;

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
 * hilite_system('BendingModesStatic/BendingModesStatic')    - opens subsystem BendingModesStatic/BendingModesStatic
 * hilite_system('BendingModesStatic/BendingModesStatic/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BendingModesStatic'
 * '<S1>'   : 'BendingModesStatic/BendingModesStatic'
 * '<S2>'   : 'BendingModesStatic/BendingModesStatic/S1'
 * '<S3>'   : 'BendingModesStatic/BendingModesStatic/S2'
 * '<S4>'   : 'BendingModesStatic/BendingModesStatic/S3'
 * '<S5>'   : 'BendingModesStatic/BendingModesStatic/S4'
 * '<S6>'   : 'BendingModesStatic/BendingModesStatic/S5'
 * '<S7>'   : 'BendingModesStatic/BendingModesStatic/S6'
 * '<S8>'   : 'BendingModesStatic/BendingModesStatic/S7'
 */
#endif                                 /* RTW_HEADER_BendingModesStatic0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
