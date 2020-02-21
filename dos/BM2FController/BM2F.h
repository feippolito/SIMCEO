/*
 * File: BM2F.h
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

#ifndef RTW_HEADER_BM2F_h_
#define RTW_HEADER_BM2F_h_
#include <string.h>
#include <stddef.h>
#ifndef BM2F_COMMON_INCLUDES_
# define BM2F_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* BM2F_COMMON_INCLUDES_ */

#include "BM2F_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S2>/Gain'
   *   '<S3>/Gain'
   *   '<S4>/Gain'
   *   '<S5>/Gain'
   *   '<S6>/Gain'
   *   '<S7>/Gain'
   */
  real_T pooled1[4455];

  /* Expression: bm2F{7}
   * Referenced by: '<S8>/Gain'
   */
  real_T Gain_Gain[4158];
} ConstP_BM2F_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Feedback[189];                /* '<Root>/Feedback' */
} ExtU_BM2F_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output[1144];                 /* '<Root>/Output' */
} ExtY_BM2F_T;

/* Real-time Model Data Structure */
struct tag_RTM_BM2F_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_BM2F_T BM2F_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_BM2F_T BM2F_Y;

/* Constant parameters (default storage) */
extern const ConstP_BM2F_T BM2F_ConstP;

/* Model entry point functions */
extern void BM2F_initialize(void);
extern void BM2F_step(void);
extern void BM2F_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BM2F_T *const BM2F_M;

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
 * hilite_system('BendingModesInterfaceDrivers/BM2F')    - opens subsystem BendingModesInterfaceDrivers/BM2F
 * hilite_system('BendingModesInterfaceDrivers/BM2F/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BendingModesInterfaceDrivers'
 * '<S1>'   : 'BendingModesInterfaceDrivers/BM2F'
 * '<S2>'   : 'BendingModesInterfaceDrivers/BM2F/M1S1 BM2Fxyz'
 * '<S3>'   : 'BendingModesInterfaceDrivers/BM2F/M1S2 BM2Fxyz'
 * '<S4>'   : 'BendingModesInterfaceDrivers/BM2F/M1S3 BM2Fxyz'
 * '<S5>'   : 'BendingModesInterfaceDrivers/BM2F/M1S4 BM2Fxyz'
 * '<S6>'   : 'BendingModesInterfaceDrivers/BM2F/M1S5 BM2Fxyz'
 * '<S7>'   : 'BendingModesInterfaceDrivers/BM2F/M1S6 BM2Fxyz'
 * '<S8>'   : 'BendingModesInterfaceDrivers/BM2F/M1S7 BM2Fxyz'
 */
#endif                                 /* RTW_HEADER_BM2F_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
