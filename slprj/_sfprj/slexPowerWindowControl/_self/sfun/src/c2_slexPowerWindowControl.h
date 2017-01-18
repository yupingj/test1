#ifndef __c2_slexPowerWindowControl_h__
#define __c2_slexPowerWindowControl_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_slexPowerWindowControlInstanceStruct
#define typedef_SFc2_slexPowerWindowControlInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  uint8_T c2_tp_safe;
  uint8_T c2_tp_driverNeutral;
  uint8_T c2_tp_passengerneutral;
  uint8_T c2_tp_passengerDown;
  uint8_T c2_tp_iniPassengerDown;
  uint8_T c2_b_tp_passengerDown;
  uint8_T c2_tp_autoPassengerDown;
  uint8_T c2_tp_passengerUp;
  uint8_T c2_tp_iniPassengerUp;
  uint8_T c2_tp_PassengerUp;
  uint8_T c2_tp_autoPassengerUp;
  uint8_T c2_tp_driverDown;
  uint8_T c2_tp_iniDriverDown;
  uint8_T c2_tp_autoDriverDown;
  uint8_T c2_tp_DriverDown;
  uint8_T c2_tp_driverUp;
  uint8_T c2_tp_iniDriverUp;
  uint8_T c2_tp_DriverUp;
  uint8_T c2_tp_autoDriverUp;
  uint8_T c2_tp_emergencyDown;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_slexPowerWindowControl;
  uint8_T c2_is_c2_slexPowerWindowControl;
  uint8_T c2_is_safe;
  uint8_T c2_is_driverNeutral;
  uint8_T c2_is_passengerDown;
  uint8_T c2_is_passengerUp;
  uint8_T c2_is_driverDown;
  uint8_T c2_is_driverUp;
  uint8_T c2_temporalCounter_i1;
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
  int8_T *c2_ticks;
  boolean_T *c2_moveUp;
  boolean_T *c2_moveDown;
  boolean_T *c2_endstop;
  boolean_T *c2_obstacle;
  boolean_T (*c2_driver)[3];
  boolean_T (*c2_passenger)[3];
} SFc2_slexPowerWindowControlInstanceStruct;

#endif                                 /*typedef_SFc2_slexPowerWindowControlInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_slexPowerWindowControl_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_slexPowerWindowControl_get_check_sum(mxArray *plhs[]);
extern void c2_slexPowerWindowControl_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
