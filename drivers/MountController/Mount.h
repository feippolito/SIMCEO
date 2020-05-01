/*
 * File: Mount.h
 *
 * Code generated for Simulink model 'Mount'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Wed Feb 19 08:10:39 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Mount_h_
#define RTW_HEADER_Mount_h_
#include <string.h>
#include <stddef.h>
#ifndef Mount_COMMON_INCLUDES_
# define Mount_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Mount_COMMON_INCLUDES_ */

#include "Mount_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Internal_DSTATE[5];           /* '<S3>/Internal' */
  real_T Internal_DSTATE_a[5];         /* '<S6>/Internal' */
  real_T DiscreteStateSpace_DSTATE[9]; /* '<S8>/Discrete State-Space' */
  real_T Internal_DSTATE_l[4];         /* '<S2>/Internal' */
  real_T DiscreteStateSpace_DSTATE_g[9];/* '<S4>/Discrete State-Space' */
  real_T Internal_DSTATE_e[4];         /* '<S5>/Internal' */
  real_T DiscreteStateSpace_DSTATE_c[9];/* '<S7>/Discrete State-Space' */
} DW_Mount_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: [-1 -1 -1 -1 1 1 1 1])
   * Referenced by:
   *   '<S1>/convert to Az drive forces'
   *   '<S1>/convert to El drive forces'
   */
  real_T pooled6[8];

  /* Computed Parameter: DiscreteStateSpace_A
   * Referenced by: '<S8>/Discrete State-Space'
   */
  real_T DiscreteStateSpace_A[65];

  /* Computed Parameter: DiscreteStateSpace_C
   * Referenced by: '<S8>/Discrete State-Space'
   */
  real_T DiscreteStateSpace_C[9];

  /* Computed Parameter: DiscreteStateSpace_A_k
   * Referenced by: '<S4>/Discrete State-Space'
   */
  real_T DiscreteStateSpace_A_k[65];

  /* Computed Parameter: DiscreteStateSpace_C_h
   * Referenced by: '<S4>/Discrete State-Space'
   */
  real_T DiscreteStateSpace_C_h[9];

  /* Computed Parameter: DiscreteStateSpace_A_a
   * Referenced by: '<S7>/Discrete State-Space'
   */
  real_T DiscreteStateSpace_A_a[65];

  /* Computed Parameter: DiscreteStateSpace_C_a
   * Referenced by: '<S7>/Discrete State-Space'
   */
  real_T DiscreteStateSpace_C_a[9];
} ConstP_Mount_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Reference[3];                 /* '<Root>/Reference' */
  real_T Feedback[20];                 /* '<Root>/Feedback' */
} ExtU_Mount_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Output[20];                   /* '<Root>/Output' */
} ExtY_Mount_T;

/* Real-time Model Data Structure */
struct tag_RTM_Mount_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Mount_T Mount_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Mount_T Mount_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Mount_T Mount_Y;

/* Constant parameters (default storage) */
extern const ConstP_Mount_T Mount_ConstP;

/* Model entry point functions */
extern void Mount_initialize(void);
extern void Mount_step(void);
extern void Mount_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Mount_T *const Mount_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Manual Switch' : Eliminated due to constant selection input
 * Block '<S1>/Manual Switch1' : Eliminated due to constant selection input
 */

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
 * hilite_system('MountControl_driver/Mount')    - opens subsystem MountControl_driver/Mount
 * hilite_system('MountControl_driver/Mount/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MountControl_driver'
 * '<S1>'   : 'MountControl_driver/Mount'
 * '<S2>'   : 'MountControl_driver/Mount/Az Encoder Tf'
 * '<S3>'   : 'MountControl_driver/Mount/Az Motor Tf1'
 * '<S4>'   : 'MountControl_driver/Mount/Azimuth Controller'
 * '<S5>'   : 'MountControl_driver/Mount/El Encoder Tf'
 * '<S6>'   : 'MountControl_driver/Mount/El Motor Tf'
 * '<S7>'   : 'MountControl_driver/Mount/Elevation Controller'
 * '<S8>'   : 'MountControl_driver/Mount/GIR Controller'
 * '<S9>'   : 'MountControl_driver/Mount/GIR Encoder Tf'
 * '<S10>'  : 'MountControl_driver/Mount/GIR Motor Tf'
 * '<S11>'  : 'MountControl_driver/Mount/Az Encoder Tf/IO Delay'
 * '<S12>'  : 'MountControl_driver/Mount/Az Encoder Tf/Input Delay'
 * '<S13>'  : 'MountControl_driver/Mount/Az Encoder Tf/Output Delay'
 * '<S14>'  : 'MountControl_driver/Mount/Az Motor Tf1/IO Delay'
 * '<S15>'  : 'MountControl_driver/Mount/Az Motor Tf1/Input Delay'
 * '<S16>'  : 'MountControl_driver/Mount/Az Motor Tf1/Output Delay'
 * '<S17>'  : 'MountControl_driver/Mount/El Encoder Tf/IO Delay'
 * '<S18>'  : 'MountControl_driver/Mount/El Encoder Tf/Input Delay'
 * '<S19>'  : 'MountControl_driver/Mount/El Encoder Tf/Output Delay'
 * '<S20>'  : 'MountControl_driver/Mount/El Motor Tf/IO Delay'
 * '<S21>'  : 'MountControl_driver/Mount/El Motor Tf/Input Delay'
 * '<S22>'  : 'MountControl_driver/Mount/El Motor Tf/Output Delay'
 * '<S23>'  : 'MountControl_driver/Mount/GIR Encoder Tf/IO Delay'
 * '<S24>'  : 'MountControl_driver/Mount/GIR Encoder Tf/Input Delay'
 * '<S25>'  : 'MountControl_driver/Mount/GIR Encoder Tf/Output Delay'
 * '<S26>'  : 'MountControl_driver/Mount/GIR Motor Tf/IO Delay'
 * '<S27>'  : 'MountControl_driver/Mount/GIR Motor Tf/Input Delay'
 * '<S28>'  : 'MountControl_driver/Mount/GIR Motor Tf/Output Delay'
 */
#endif                                 /* RTW_HEADER_Mount_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
