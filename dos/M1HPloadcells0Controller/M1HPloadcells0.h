/*
 * File: M1HPloadcells0.h
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

#ifndef RTW_HEADER_M1HPloadcells0_h_
#define RTW_HEADER_M1HPloadcells0_h_
#include <string.h>
#include <stddef.h>
#ifndef M1HPloadcells0_COMMON_INCLUDES_
# define M1HPloadcells0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* M1HPloadcells0_COMMON_INCLUDES_ */

#include "M1HPloadcells0_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Feedback[126];                /* '<Root>/Feedback' */
} ExtU_M1HPloadcells0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output[42];                   /* '<Root>/Output' */
} ExtY_M1HPloadcells0_T;

/* Real-time Model Data Structure */
struct tag_RTM_M1HPloadcells0_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_M1HPloadcells0_T M1HPloadcells0_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_M1HPloadcells0_T M1HPloadcells0_Y;

/* Model entry point functions */
extern void M1HPloadcells0_initialize(void);
extern void M1HPloadcells0_step(void);
extern void M1HPloadcells0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_M1HPloadcells0_T *const M1HPloadcells0_M;

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
 * hilite_system('M1HPloadcells/M1HPloadcells')    - opens subsystem M1HPloadcells/M1HPloadcells
 * hilite_system('M1HPloadcells/M1HPloadcells/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'M1HPloadcells'
 * '<S1>'   : 'M1HPloadcells/M1HPloadcells'
 * '<S2>'   : 'M1HPloadcells/M1HPloadcells/M1S1 Loadcell'
 * '<S3>'   : 'M1HPloadcells/M1HPloadcells/M1S2 Loadcell'
 * '<S4>'   : 'M1HPloadcells/M1HPloadcells/M1S3 Loadcell'
 * '<S5>'   : 'M1HPloadcells/M1HPloadcells/M1S4 Loadcell'
 * '<S6>'   : 'M1HPloadcells/M1HPloadcells/M1S5 Loadcell'
 * '<S7>'   : 'M1HPloadcells/M1HPloadcells/M1S6 Loadcell'
 * '<S8>'   : 'M1HPloadcells/M1HPloadcells/M1S7 Control'
 */
#endif                                 /* RTW_HEADER_M1HPloadcells0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
