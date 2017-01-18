/* Include files */

#include <stddef.h>
#include "blas.h"
#include "slexPowerWindowControl_sfun.h"
#include "c2_slexPowerWindowControl.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "slexPowerWindowControl_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c2_event_ticks                 (0)
#define CALL_EVENT                     (-1)
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_IN_emergencyDown            ((uint8_T)1U)
#define c2_IN_safe                     ((uint8_T)2U)
#define c2_IN_driverDown               ((uint8_T)1U)
#define c2_IN_driverNeutral            ((uint8_T)2U)
#define c2_IN_driverUp                 ((uint8_T)3U)
#define c2_IN_passengerDown            ((uint8_T)1U)
#define c2_IN_passengerUp              ((uint8_T)2U)
#define c2_IN_passengerneutral         ((uint8_T)3U)
#define c2_IN_autoPassengerDown        ((uint8_T)1U)
#define c2_IN_iniPassengerDown         ((uint8_T)2U)
#define c2_b_IN_passengerDown          ((uint8_T)3U)
#define c2_IN_PassengerUp              ((uint8_T)1U)
#define c2_IN_autoPassengerUp          ((uint8_T)2U)
#define c2_IN_iniPassengerUp           ((uint8_T)3U)
#define c2_IN_DriverDown               ((uint8_T)1U)
#define c2_IN_autoDriverDown           ((uint8_T)2U)
#define c2_IN_iniDriverDown            ((uint8_T)3U)
#define c2_IN_DriverUp                 ((uint8_T)1U)
#define c2_IN_autoDriverUp             ((uint8_T)2U)
#define c2_IN_iniDriverUp              ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void initialize_params_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void enable_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void disable_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void set_sim_state_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void c2_set_sim_state_side_effects_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void finalize_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void sf_gateway_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void mdl_start_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void initSimStructsc2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void c2_safe(SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void c2_exit_internal_safe(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance);
static void c2_exit_internal_driverNeutral
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void c2_passengerDown(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance);
static void c2_exit_internal_passengerDown
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void c2_passengerUp(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance);
static void c2_exit_internal_passengerUp
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void c2_driverDown(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance);
static void c2_exit_internal_driverDown
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void c2_driverUp(SFc2_slexPowerWindowControlInstanceStruct *chartInstance);
static void c2_exit_internal_driverUp(SFc2_slexPowerWindowControlInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static int8_T c2_emlrt_marshallIn(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_b_emlrt_marshallIn(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_c_emlrt_marshallIn(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance, const mxArray *c2_b_tp_safe, const char_T *c2_identifier);
static uint8_T c2_d_emlrt_marshallIn(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static boolean_T c2_e_emlrt_marshallIn(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance, const mxArray *c2_b_moveUp, const char_T *c2_identifier);
static boolean_T c2_f_emlrt_marshallIn(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_g_emlrt_marshallIn
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier);
static const mxArray *c2_h_emlrt_marshallIn
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance, const mxArray *c2_u,
   const emlrtMsgIdentifier *c2_parentId);
static uint8_T c2__u8_s32_(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance, int32_T c2_b);
static void init_dsm_address_info(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_tp_emergencyDown = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_is_safe = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_tp_safe = 0U;
  chartInstance->c2_is_driverDown = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_tp_driverDown = 0U;
  chartInstance->c2_tp_DriverDown = 0U;
  chartInstance->c2_tp_autoDriverDown = 0U;
  chartInstance->c2_tp_iniDriverDown = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_is_driverNeutral = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_tp_driverNeutral = 0U;
  chartInstance->c2_is_passengerDown = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_tp_passengerDown = 0U;
  chartInstance->c2_tp_autoPassengerDown = 0U;
  chartInstance->c2_tp_iniPassengerDown = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_b_tp_passengerDown = 0U;
  chartInstance->c2_is_passengerUp = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_tp_passengerUp = 0U;
  chartInstance->c2_tp_PassengerUp = 0U;
  chartInstance->c2_tp_autoPassengerUp = 0U;
  chartInstance->c2_tp_iniPassengerUp = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_passengerneutral = 0U;
  chartInstance->c2_is_driverUp = c2_IN_NO_ACTIVE_CHILD;
  chartInstance->c2_tp_driverUp = 0U;
  chartInstance->c2_tp_DriverUp = 0U;
  chartInstance->c2_tp_autoDriverUp = 0U;
  chartInstance->c2_tp_iniDriverUp = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_is_active_c2_slexPowerWindowControl = 0U;
  chartInstance->c2_is_c2_slexPowerWindowControl = c2_IN_NO_ACTIVE_CHILD;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c2_moveUp = false;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *chartInstance->c2_moveDown = false;
  }

  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_active_c2_slexPowerWindowControl = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_c2_slexPowerWindowControl = c2_IN_safe;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_safe = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_safe = c2_IN_driverNeutral;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_driverNeutral = 1U;
  *chartInstance->c2_moveUp = false;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
  *chartInstance->c2_moveDown = false;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
  chartInstance->c2_is_driverNeutral = c2_IN_passengerneutral;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
  chartInstance->c2_tp_passengerneutral = 1U;
  *chartInstance->c2_moveUp = false;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
  *chartInstance->c2_moveDown = false;
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_slexPowerWindowControlMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initialize_params_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c2_is_active_c2_slexPowerWindowControl == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_slexPowerWindowControl == c2_IN_safe) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_safe == c2_IN_driverNeutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_driverNeutral == c2_IN_passengerneutral) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_driverNeutral == c2_IN_passengerDown) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_passengerDown == c2_IN_iniPassengerDown) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_passengerDown == c2_b_IN_passengerDown) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_passengerDown == c2_IN_autoPassengerDown) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_driverNeutral == c2_IN_passengerUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_passengerUp == c2_IN_iniPassengerUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_passengerUp == c2_IN_PassengerUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_passengerUp == c2_IN_autoPassengerUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_safe == c2_IN_driverDown) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_driverDown == c2_IN_iniDriverDown) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_driverDown == c2_IN_autoDriverDown) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_driverDown == c2_IN_DriverDown) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_safe == c2_IN_driverUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_driverUp == c2_IN_iniDriverUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_driverUp == c2_IN_DriverUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_driverUp == c2_IN_autoDriverUp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_slexPowerWindowControl == c2_IN_emergencyDown) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  _SFD_SET_ANIMATION(c2_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  boolean_T c2_hoistedGlobal;
  boolean_T c2_u;
  const mxArray *c2_b_y = NULL;
  boolean_T c2_b_hoistedGlobal;
  boolean_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_e_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  uint8_T c2_f_hoistedGlobal;
  uint8_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  uint8_T c2_g_hoistedGlobal;
  uint8_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  uint8_T c2_h_hoistedGlobal;
  uint8_T c2_h_u;
  const mxArray *c2_i_y = NULL;
  uint8_T c2_i_hoistedGlobal;
  uint8_T c2_i_u;
  const mxArray *c2_j_y = NULL;
  uint8_T c2_j_hoistedGlobal;
  uint8_T c2_j_u;
  const mxArray *c2_k_y = NULL;
  uint8_T c2_k_hoistedGlobal;
  uint8_T c2_k_u;
  const mxArray *c2_l_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(11, 1), false);
  c2_hoistedGlobal = *chartInstance->c2_moveDown;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *chartInstance->c2_moveUp;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_active_c2_slexPowerWindowControl;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = chartInstance->c2_is_c2_slexPowerWindowControl;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_is_passengerUp;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = chartInstance->c2_is_passengerDown;
  c2_f_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_g_hoistedGlobal = chartInstance->c2_is_driverUp;
  c2_g_u = c2_g_hoistedGlobal;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  c2_h_hoistedGlobal = chartInstance->c2_is_driverDown;
  c2_h_u = c2_h_hoistedGlobal;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 7, c2_i_y);
  c2_i_hoistedGlobal = chartInstance->c2_is_driverNeutral;
  c2_i_u = c2_i_hoistedGlobal;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 8, c2_j_y);
  c2_j_hoistedGlobal = chartInstance->c2_is_safe;
  c2_j_u = c2_j_hoistedGlobal;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_j_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 9, c2_k_y);
  c2_k_hoistedGlobal = chartInstance->c2_temporalCounter_i1;
  c2_k_u = c2_k_hoistedGlobal;
  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_k_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 10, c2_l_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  *chartInstance->c2_moveDown = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 0)), "moveDown");
  *chartInstance->c2_moveUp = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "moveUp");
  chartInstance->c2_is_active_c2_slexPowerWindowControl = c2_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_active_c2_slexPowerWindowControl");
  chartInstance->c2_is_c2_slexPowerWindowControl = c2_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
     "is_c2_slexPowerWindowControl");
  chartInstance->c2_is_passengerUp = c2_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 4)), "is_passengerUp");
  chartInstance->c2_is_passengerDown = c2_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 5)), "is_passengerDown");
  chartInstance->c2_is_driverUp = c2_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 6)), "is_driverUp");
  chartInstance->c2_is_driverDown = c2_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 7)), "is_driverDown");
  chartInstance->c2_is_driverNeutral = c2_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 8)), "is_driverNeutral");
  chartInstance->c2_is_safe = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 9)), "is_safe");
  chartInstance->c2_temporalCounter_i1 = c2_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 10)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 11)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_slexPowerWindowControl(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    if (chartInstance->c2_is_c2_slexPowerWindowControl == c2_IN_emergencyDown) {
      chartInstance->c2_tp_emergencyDown = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_emergencyDown = 0U;
    }

    if (chartInstance->c2_is_c2_slexPowerWindowControl == c2_IN_safe) {
      chartInstance->c2_tp_safe = 1U;
    } else {
      chartInstance->c2_tp_safe = 0U;
    }

    if (chartInstance->c2_is_safe == c2_IN_driverDown) {
      chartInstance->c2_tp_driverDown = 1U;
    } else {
      chartInstance->c2_tp_driverDown = 0U;
    }

    if (chartInstance->c2_is_driverDown == c2_IN_DriverDown) {
      chartInstance->c2_tp_DriverDown = 1U;
    } else {
      chartInstance->c2_tp_DriverDown = 0U;
    }

    if (chartInstance->c2_is_driverDown == c2_IN_autoDriverDown) {
      chartInstance->c2_tp_autoDriverDown = 1U;
    } else {
      chartInstance->c2_tp_autoDriverDown = 0U;
    }

    if (chartInstance->c2_is_driverDown == c2_IN_iniDriverDown) {
      chartInstance->c2_tp_iniDriverDown = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_iniDriverDown = 0U;
    }

    if (chartInstance->c2_is_safe == c2_IN_driverNeutral) {
      chartInstance->c2_tp_driverNeutral = 1U;
    } else {
      chartInstance->c2_tp_driverNeutral = 0U;
    }

    if (chartInstance->c2_is_driverNeutral == c2_IN_passengerDown) {
      chartInstance->c2_tp_passengerDown = 1U;
    } else {
      chartInstance->c2_tp_passengerDown = 0U;
    }

    if (chartInstance->c2_is_passengerDown == c2_IN_autoPassengerDown) {
      chartInstance->c2_tp_autoPassengerDown = 1U;
    } else {
      chartInstance->c2_tp_autoPassengerDown = 0U;
    }

    if (chartInstance->c2_is_passengerDown == c2_IN_iniPassengerDown) {
      chartInstance->c2_tp_iniPassengerDown = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 11) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_iniPassengerDown = 0U;
    }

    if (chartInstance->c2_is_passengerDown == c2_b_IN_passengerDown) {
      chartInstance->c2_b_tp_passengerDown = 1U;
    } else {
      chartInstance->c2_b_tp_passengerDown = 0U;
    }

    if (chartInstance->c2_is_driverNeutral == c2_IN_passengerUp) {
      chartInstance->c2_tp_passengerUp = 1U;
    } else {
      chartInstance->c2_tp_passengerUp = 0U;
    }

    if (chartInstance->c2_is_passengerUp == c2_IN_PassengerUp) {
      chartInstance->c2_tp_PassengerUp = 1U;
    } else {
      chartInstance->c2_tp_PassengerUp = 0U;
    }

    if (chartInstance->c2_is_passengerUp == c2_IN_autoPassengerUp) {
      chartInstance->c2_tp_autoPassengerUp = 1U;
    } else {
      chartInstance->c2_tp_autoPassengerUp = 0U;
    }

    if (chartInstance->c2_is_passengerUp == c2_IN_iniPassengerUp) {
      chartInstance->c2_tp_iniPassengerUp = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 16) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_iniPassengerUp = 0U;
    }

    if (chartInstance->c2_is_driverNeutral == c2_IN_passengerneutral) {
      chartInstance->c2_tp_passengerneutral = 1U;
    } else {
      chartInstance->c2_tp_passengerneutral = 0U;
    }

    if (chartInstance->c2_is_safe == c2_IN_driverUp) {
      chartInstance->c2_tp_driverUp = 1U;
    } else {
      chartInstance->c2_tp_driverUp = 0U;
    }

    if (chartInstance->c2_is_driverUp == c2_IN_DriverUp) {
      chartInstance->c2_tp_DriverUp = 1U;
    } else {
      chartInstance->c2_tp_DriverUp = 0U;
    }

    if (chartInstance->c2_is_driverUp == c2_IN_autoDriverUp) {
      chartInstance->c2_tp_autoDriverUp = 1U;
    } else {
      chartInstance->c2_tp_autoDriverUp = 0U;
    }

    if (chartInstance->c2_is_driverUp == c2_IN_iniDriverUp) {
      chartInstance->c2_tp_iniDriverUp = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 21) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_iniDriverUp = 0U;
    }

    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_gateway_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  int32_T c2_i0;
  int32_T c2_i1;
  boolean_T c2_temp;
  boolean_T c2_out;
  c2_set_sim_state_side_effects_c2_slexPowerWindowControl(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_endstop, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_obstacle, 3U);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_driver)[c2_i0], 4U);
  }

  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_passenger)[c2_i1], 5U);
  }

  if (chartInstance->c2_temporalCounter_i1 < 127U) {
    chartInstance->c2_temporalCounter_i1 = c2__u8_s32_(chartInstance,
      chartInstance->c2_temporalCounter_i1 + 1);
  }

  chartInstance->c2_sfEvent = c2_event_ticks;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c2_event_ticks,
               chartInstance->c2_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  switch (chartInstance->c2_is_c2_slexPowerWindowControl) {
   case c2_IN_emergencyDown:
    CV_CHART_EVAL(0, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c2_sfEvent);
    c2_temp = (_SFD_CCP_CALL(1U, 0, *chartInstance->c2_endstop != 0U,
                chartInstance->c2_sfEvent) != 0);
    if (!c2_temp) {
      c2_temp = (_SFD_CCP_CALL(1U, 1, chartInstance->c2_temporalCounter_i1 >=
                  100 != 0U, chartInstance->c2_sfEvent) != 0);
    }

    c2_out = (CV_TRANSITION_EVAL(1U, (int32_T)c2_temp) != 0);
    if (c2_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_emergencyDown = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
      chartInstance->c2_is_c2_slexPowerWindowControl = c2_IN_safe;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_safe = 1U;
      chartInstance->c2_is_safe = c2_IN_driverNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_driverNeutral = 1U;
      *chartInstance->c2_moveUp = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
      *chartInstance->c2_moveDown = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
      chartInstance->c2_is_driverNeutral = c2_IN_passengerneutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_passengerneutral = 1U;
      *chartInstance->c2_moveUp = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
      *chartInstance->c2_moveDown = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c2_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_safe:
    CV_CHART_EVAL(0, 0, 2);
    c2_safe(chartInstance);
    break;

   default:
    CV_CHART_EVAL(0, 0, 0);
    chartInstance->c2_is_c2_slexPowerWindowControl = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c2_event_ticks,
               chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_slexPowerWindowControlMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc2_slexPowerWindowControl
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_safe(SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  boolean_T c2_out;
  boolean_T c2_b_out;
  boolean_T c2_c_out;
  boolean_T c2_d_out;
  boolean_T c2_e_out;
  boolean_T c2_f_out;
  boolean_T c2_g_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c2_sfEvent);
  c2_out = (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U, 0,
              *chartInstance->c2_obstacle != 0U, chartInstance->c2_sfEvent)) !=
            0);
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
    c2_exit_internal_safe(chartInstance);
    chartInstance->c2_tp_safe = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_slexPowerWindowControl = c2_IN_emergencyDown;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_temporalCounter_i1 = 0U;
    chartInstance->c2_tp_emergencyDown = 1U;
    *chartInstance->c2_moveUp = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
    *chartInstance->c2_moveDown = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
    switch (chartInstance->c2_is_safe) {
     case c2_IN_driverDown:
      CV_STATE_EVAL(1, 0, 1);
      c2_driverDown(chartInstance);
      break;

     case c2_IN_driverNeutral:
      CV_STATE_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U,
                   chartInstance->c2_sfEvent);
      c2_b_out = (CV_TRANSITION_EVAL(26U, (int32_T)_SFD_CCP_CALL(26U, 0,
        (*chartInstance->c2_driver)[1] != 0U, chartInstance->c2_sfEvent)) != 0);
      if (c2_b_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 26;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          c2_c_out = (*chartInstance->c2_driver)[2];
          if (c2_c_out) {
            transitionList[numTransitions] = 17;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c2_sfEvent);
        c2_exit_internal_driverNeutral(chartInstance);
        chartInstance->c2_tp_driverNeutral = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_safe = c2_IN_driverUp;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_driverUp = 1U;
        *chartInstance->c2_moveUp = true;
        _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
        chartInstance->c2_is_driverUp = c2_IN_iniDriverUp;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
        chartInstance->c2_temporalCounter_i1 = 0U;
        chartInstance->c2_tp_iniDriverUp = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                     chartInstance->c2_sfEvent);
        c2_d_out = (CV_TRANSITION_EVAL(17U, (int32_T)_SFD_CCP_CALL(17U, 0,
          (*chartInstance->c2_driver)[2] != 0U, chartInstance->c2_sfEvent)) != 0);
        if (c2_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
          c2_exit_internal_driverNeutral(chartInstance);
          chartInstance->c2_tp_driverNeutral = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_safe = c2_IN_driverDown;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_driverDown = 1U;
          *chartInstance->c2_moveDown = true;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
          chartInstance->c2_is_driverDown = c2_IN_iniDriverDown;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
          chartInstance->c2_temporalCounter_i1 = 0U;
          chartInstance->c2_tp_iniDriverDown = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                       chartInstance->c2_sfEvent);
          switch (chartInstance->c2_is_driverNeutral) {
           case c2_IN_passengerDown:
            CV_STATE_EVAL(6, 0, 1);
            c2_passengerDown(chartInstance);
            break;

           case c2_IN_passengerUp:
            CV_STATE_EVAL(6, 0, 2);
            c2_passengerUp(chartInstance);
            break;

           case c2_IN_passengerneutral:
            CV_STATE_EVAL(6, 0, 3);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                         chartInstance->c2_sfEvent);
            c2_e_out = (CV_TRANSITION_EVAL(8U, (int32_T)_SFD_CCP_CALL(8U, 0,
              (*chartInstance->c2_passenger)[1] != 0U, chartInstance->c2_sfEvent))
                        != 0);
            if (c2_e_out) {
              if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
                unsigned int transitionList[2];
                unsigned int numTransitions = 1;
                transitionList[0] = 8;
                _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
                c2_f_out = (*chartInstance->c2_passenger)[2];
                if (c2_f_out) {
                  transitionList[numTransitions] = 7;
                  numTransitions++;
                }

                _SFD_TRANSITION_CONFLICT_CHECK_END();
                if (numTransitions > 1) {
                  _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
                }
              }

              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
              chartInstance->c2_tp_passengerneutral = 0U;
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
              chartInstance->c2_is_driverNeutral = c2_IN_passengerUp;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
              chartInstance->c2_tp_passengerUp = 1U;
              *chartInstance->c2_moveUp = true;
              _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
              chartInstance->c2_is_passengerUp = c2_IN_iniPassengerUp;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
              chartInstance->c2_temporalCounter_i1 = 0U;
              chartInstance->c2_tp_iniPassengerUp = 1U;
            } else {
              _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                           chartInstance->c2_sfEvent);
              c2_g_out = (CV_TRANSITION_EVAL(7U, (int32_T)_SFD_CCP_CALL(7U, 0, (*
                chartInstance->c2_passenger)[2] != 0U, chartInstance->c2_sfEvent))
                          != 0);
              if (c2_g_out) {
                _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U,
                             chartInstance->c2_sfEvent);
                chartInstance->c2_tp_passengerneutral = 0U;
                _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
                chartInstance->c2_is_driverNeutral = c2_IN_passengerDown;
                _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
                chartInstance->c2_tp_passengerDown = 1U;
                *chartInstance->c2_moveDown = true;
                _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
                chartInstance->c2_is_passengerDown = c2_IN_iniPassengerDown;
                _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
                chartInstance->c2_temporalCounter_i1 = 0U;
                chartInstance->c2_tp_iniPassengerDown = 1U;
              } else {
                _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                             chartInstance->c2_sfEvent);
              }
            }

            _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U,
                         chartInstance->c2_sfEvent);
            break;

           default:
            CV_STATE_EVAL(6, 0, 0);
            chartInstance->c2_is_driverNeutral = c2_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
            break;
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_driverUp:
      CV_STATE_EVAL(1, 0, 3);
      c2_driverUp(chartInstance);
      break;

     default:
      CV_STATE_EVAL(1, 0, 0);
      chartInstance->c2_is_safe = c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void c2_exit_internal_safe(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c2_is_safe) {
   case c2_IN_driverDown:
    CV_STATE_EVAL(1, 1, 1);
    c2_exit_internal_driverDown(chartInstance);
    chartInstance->c2_tp_driverDown = 0U;
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
    *chartInstance->c2_moveDown = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_safe = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_driverNeutral:
    CV_STATE_EVAL(1, 1, 2);
    c2_exit_internal_driverNeutral(chartInstance);
    chartInstance->c2_tp_driverNeutral = 0U;
    chartInstance->c2_is_safe = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_driverUp:
    CV_STATE_EVAL(1, 1, 3);
    c2_exit_internal_driverUp(chartInstance);
    chartInstance->c2_tp_driverUp = 0U;
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 16U, chartInstance->c2_sfEvent);
    *chartInstance->c2_moveUp = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_safe = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 1, 0);
    chartInstance->c2_is_safe = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
    break;
  }
}

static void c2_exit_internal_driverNeutral
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  switch (chartInstance->c2_is_driverNeutral) {
   case c2_IN_passengerDown:
    CV_STATE_EVAL(6, 1, 1);
    c2_exit_internal_passengerDown(chartInstance);
    chartInstance->c2_tp_passengerDown = 0U;
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
    *chartInstance->c2_moveDown = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_driverNeutral = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_passengerUp:
    CV_STATE_EVAL(6, 1, 2);
    c2_exit_internal_passengerUp(chartInstance);
    chartInstance->c2_tp_passengerUp = 0U;
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 11U, chartInstance->c2_sfEvent);
    *chartInstance->c2_moveUp = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_driverNeutral = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_passengerneutral:
    CV_STATE_EVAL(6, 1, 3);
    chartInstance->c2_tp_passengerneutral = 0U;
    chartInstance->c2_is_driverNeutral = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_STATE_EVAL(6, 1, 0);
    chartInstance->c2_is_driverNeutral = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
    break;
  }
}

static void c2_passengerDown(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance)
{
  boolean_T c2_out;
  boolean_T c2_b_out;
  boolean_T c2_c_out;
  boolean_T c2_temp;
  boolean_T c2_d_out;
  boolean_T c2_e_out;
  boolean_T c2_f_out;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, chartInstance->c2_sfEvent);
  c2_out = (CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(4U, 0,
              *chartInstance->c2_endstop != 0U, chartInstance->c2_sfEvent)) != 0);
  guard1 = false;
  if (c2_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[2];
      unsigned int numTransitions = 1;
      transitionList[0] = 4;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      c2_b_out = (*chartInstance->c2_passenger)[1];
      if (c2_b_out) {
        transitionList[numTransitions] = 10;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
    c2_exit_internal_passengerDown(chartInstance);
    chartInstance->c2_tp_passengerDown = 0U;
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
    *chartInstance->c2_moveDown = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_driverNeutral = c2_IN_passengerneutral;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_passengerneutral = 1U;
    *chartInstance->c2_moveUp = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
    *chartInstance->c2_moveDown = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
    guard1 = true;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c2_sfEvent);
    c2_c_out = (CV_TRANSITION_EVAL(10U, (int32_T)_SFD_CCP_CALL(10U, 0,
      (*chartInstance->c2_passenger)[1] != 0U, chartInstance->c2_sfEvent)) != 0);
    if (c2_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
      c2_exit_internal_passengerDown(chartInstance);
      chartInstance->c2_tp_passengerDown = 0U;
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
      *chartInstance->c2_moveDown = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
      chartInstance->c2_is_driverNeutral = c2_IN_passengerUp;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_passengerUp = 1U;
      *chartInstance->c2_moveUp = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
      chartInstance->c2_is_passengerUp = c2_IN_PassengerUp;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_PassengerUp = 1U;
      guard1 = true;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c2_sfEvent);
      switch (chartInstance->c2_is_passengerDown) {
       case c2_IN_autoPassengerDown:
        CV_STATE_EVAL(7, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                     chartInstance->c2_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c2_sfEvent);
        guard1 = true;
        break;

       case c2_IN_iniPassengerDown:
        CV_STATE_EVAL(7, 0, 2);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                     chartInstance->c2_sfEvent);
        c2_temp = (_SFD_CCP_CALL(9U, 0, chartInstance->c2_sfEvent ==
                    c2_event_ticks != 0U, chartInstance->c2_sfEvent) != 0);
        if (c2_temp) {
          c2_temp = (_SFD_CCP_CALL(9U, 1, chartInstance->c2_temporalCounter_i1 >=
                      100 != 0U, chartInstance->c2_sfEvent) != 0);
        }

        c2_d_out = (CV_TRANSITION_EVAL(9U, (int32_T)c2_temp) != 0);
        if (c2_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                       chartInstance->c2_sfEvent);
          c2_e_out = (CV_TRANSITION_EVAL(0U, (int32_T)_SFD_CCP_CALL(0U, 0,
            (*chartInstance->c2_passenger)[0] != 0U, chartInstance->c2_sfEvent))
                      != 0);
          if (c2_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_iniPassengerDown = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
            chartInstance->c2_is_passengerDown = c2_IN_autoPassengerDown;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_autoPassengerDown = 1U;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_iniPassengerDown = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
            chartInstance->c2_is_passengerDown = c2_b_IN_passengerDown;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
            chartInstance->c2_b_tp_passengerDown = 1U;
          }
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                       chartInstance->c2_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c2_sfEvent);
        guard1 = true;
        break;

       case c2_b_IN_passengerDown:
        CV_STATE_EVAL(7, 0, 3);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                     chartInstance->c2_sfEvent);
        c2_f_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0,
          (*chartInstance->c2_passenger)[0] != 0U, chartInstance->c2_sfEvent))
                    != 0);
        if (c2_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
          chartInstance->c2_b_tp_passengerDown = 0U;
          chartInstance->c2_is_passengerDown = c2_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_passengerDown = 0U;
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 7U,
                       chartInstance->c2_sfEvent);
          *chartInstance->c2_moveDown = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_driverNeutral = c2_IN_passengerneutral;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_passengerneutral = 1U;
          *chartInstance->c2_moveUp = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
          *chartInstance->c2_moveDown = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                       chartInstance->c2_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c2_sfEvent);
        if (chartInstance->c2_is_driverNeutral != c2_IN_passengerDown) {
        } else {
          guard1 = true;
        }
        break;

       default:
        CV_STATE_EVAL(7, 0, 0);
        chartInstance->c2_is_passengerDown = c2_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
        guard1 = true;
        break;
      }
    }
  }

  if (guard1 == true) {
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c2_sfEvent);
  }
}

static void c2_exit_internal_passengerDown
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  switch (chartInstance->c2_is_passengerDown) {
   case c2_IN_autoPassengerDown:
    CV_STATE_EVAL(7, 1, 1);
    chartInstance->c2_tp_autoPassengerDown = 0U;
    chartInstance->c2_is_passengerDown = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_iniPassengerDown:
    CV_STATE_EVAL(7, 1, 2);
    chartInstance->c2_tp_iniPassengerDown = 0U;
    chartInstance->c2_is_passengerDown = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
    break;

   case c2_b_IN_passengerDown:
    CV_STATE_EVAL(7, 1, 3);
    chartInstance->c2_b_tp_passengerDown = 0U;
    chartInstance->c2_is_passengerDown = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_STATE_EVAL(7, 1, 0);
    chartInstance->c2_is_passengerDown = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
    break;
  }
}

static void c2_passengerUp(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance)
{
  boolean_T c2_out;
  boolean_T c2_b_out;
  boolean_T c2_c_out;
  boolean_T c2_d_out;
  boolean_T c2_temp;
  boolean_T c2_e_out;
  boolean_T c2_f_out;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U, chartInstance->c2_sfEvent);
  c2_out = (CV_TRANSITION_EVAL(11U, (int32_T)_SFD_CCP_CALL(11U, 0,
              (*chartInstance->c2_passenger)[2] != 0U, chartInstance->c2_sfEvent))
            != 0);
  guard1 = false;
  if (c2_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[2];
      unsigned int numTransitions = 1;
      transitionList[0] = 11;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      c2_b_out = *chartInstance->c2_endstop;
      if (c2_b_out) {
        transitionList[numTransitions] = 6;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
    c2_exit_internal_passengerUp(chartInstance);
    chartInstance->c2_tp_passengerUp = 0U;
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 11U, chartInstance->c2_sfEvent);
    *chartInstance->c2_moveUp = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c2_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_driverNeutral = c2_IN_passengerDown;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_passengerDown = 1U;
    *chartInstance->c2_moveDown = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
    chartInstance->c2_is_passengerDown = c2_b_IN_passengerDown;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
    chartInstance->c2_b_tp_passengerDown = 1U;
    guard1 = true;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c2_sfEvent);
    c2_c_out = (CV_TRANSITION_EVAL(6U, (int32_T)_SFD_CCP_CALL(6U, 0,
      *chartInstance->c2_endstop != 0U, chartInstance->c2_sfEvent)) != 0);
    if (c2_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
      c2_exit_internal_passengerUp(chartInstance);
      chartInstance->c2_tp_passengerUp = 0U;
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 11U, chartInstance->c2_sfEvent);
      *chartInstance->c2_moveUp = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c2_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
      chartInstance->c2_is_driverNeutral = c2_IN_passengerneutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_passengerneutral = 1U;
      *chartInstance->c2_moveUp = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
      *chartInstance->c2_moveDown = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
      guard1 = true;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                   chartInstance->c2_sfEvent);
      switch (chartInstance->c2_is_passengerUp) {
       case c2_IN_PassengerUp:
        CV_STATE_EVAL(11, 0, 1);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                     chartInstance->c2_sfEvent);
        c2_d_out = (CV_TRANSITION_EVAL(5U, (int32_T)_SFD_CCP_CALL(5U, 0,
          (*chartInstance->c2_passenger)[0] != 0U, chartInstance->c2_sfEvent))
                    != 0);
        if (c2_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_PassengerUp = 0U;
          chartInstance->c2_is_passengerUp = c2_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_passengerUp = 0U;
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 11U,
                       chartInstance->c2_sfEvent);
          *chartInstance->c2_moveUp = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c2_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_driverNeutral = c2_IN_passengerneutral;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_passengerneutral = 1U;
          *chartInstance->c2_moveUp = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
          *chartInstance->c2_moveDown = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                       chartInstance->c2_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c2_sfEvent);
        if (chartInstance->c2_is_driverNeutral != c2_IN_passengerUp) {
        } else {
          guard1 = true;
        }
        break;

       case c2_IN_autoPassengerUp:
        CV_STATE_EVAL(11, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                     chartInstance->c2_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c2_sfEvent);
        guard1 = true;
        break;

       case c2_IN_iniPassengerUp:
        CV_STATE_EVAL(11, 0, 3);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                     chartInstance->c2_sfEvent);
        c2_temp = (_SFD_CCP_CALL(16U, 0, chartInstance->c2_sfEvent ==
                    c2_event_ticks != 0U, chartInstance->c2_sfEvent) != 0);
        if (c2_temp) {
          c2_temp = (_SFD_CCP_CALL(16U, 1, chartInstance->c2_temporalCounter_i1 >=
                      100 != 0U, chartInstance->c2_sfEvent) != 0);
        }

        c2_e_out = (CV_TRANSITION_EVAL(16U, (int32_T)c2_temp) != 0);
        if (c2_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                       chartInstance->c2_sfEvent);
          c2_f_out = (CV_TRANSITION_EVAL(15U, (int32_T)_SFD_CCP_CALL(15U, 0,
            (*chartInstance->c2_passenger)[0] != 0U, chartInstance->c2_sfEvent))
                      != 0);
          if (c2_f_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_iniPassengerUp = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
            chartInstance->c2_is_passengerUp = c2_IN_autoPassengerUp;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_autoPassengerUp = 1U;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_iniPassengerUp = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
            chartInstance->c2_is_passengerUp = c2_IN_PassengerUp;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_PassengerUp = 1U;
          }
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                       chartInstance->c2_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c2_sfEvent);
        guard1 = true;
        break;

       default:
        CV_STATE_EVAL(11, 0, 0);
        chartInstance->c2_is_passengerUp = c2_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
        guard1 = true;
        break;
      }
    }
  }

  if (guard1 == true) {
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c2_sfEvent);
  }
}

static void c2_exit_internal_passengerUp
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  switch (chartInstance->c2_is_passengerUp) {
   case c2_IN_PassengerUp:
    CV_STATE_EVAL(11, 1, 1);
    chartInstance->c2_tp_PassengerUp = 0U;
    chartInstance->c2_is_passengerUp = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_autoPassengerUp:
    CV_STATE_EVAL(11, 1, 2);
    chartInstance->c2_tp_autoPassengerUp = 0U;
    chartInstance->c2_is_passengerUp = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_iniPassengerUp:
    CV_STATE_EVAL(11, 1, 3);
    chartInstance->c2_tp_iniPassengerUp = 0U;
    chartInstance->c2_is_passengerUp = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_STATE_EVAL(11, 1, 0);
    chartInstance->c2_is_passengerUp = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
    break;
  }
}

static void c2_driverDown(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance)
{
  boolean_T c2_out;
  boolean_T c2_b_out;
  boolean_T c2_c_out;
  boolean_T c2_d_out;
  boolean_T c2_temp;
  boolean_T c2_e_out;
  boolean_T c2_f_out;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 29U, chartInstance->c2_sfEvent);
  c2_out = (CV_TRANSITION_EVAL(29U, (int32_T)_SFD_CCP_CALL(29U, 0,
              *chartInstance->c2_endstop != 0U, chartInstance->c2_sfEvent)) != 0);
  guard1 = false;
  if (c2_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[2];
      unsigned int numTransitions = 1;
      transitionList[0] = 29;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      c2_b_out = (*chartInstance->c2_driver)[1];
      if (c2_b_out) {
        transitionList[numTransitions] = 25;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c2_sfEvent);
    c2_exit_internal_driverDown(chartInstance);
    chartInstance->c2_tp_driverDown = 0U;
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
    *chartInstance->c2_moveDown = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_safe = c2_IN_driverNeutral;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_driverNeutral = 1U;
    *chartInstance->c2_moveUp = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
    *chartInstance->c2_moveDown = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_driverNeutral = c2_IN_passengerneutral;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_passengerneutral = 1U;
    *chartInstance->c2_moveUp = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
    *chartInstance->c2_moveDown = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
    guard1 = true;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U,
                 chartInstance->c2_sfEvent);
    c2_c_out = (CV_TRANSITION_EVAL(25U, (int32_T)_SFD_CCP_CALL(25U, 0,
      (*chartInstance->c2_driver)[1] != 0U, chartInstance->c2_sfEvent)) != 0);
    if (c2_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c2_sfEvent);
      c2_exit_internal_driverDown(chartInstance);
      chartInstance->c2_tp_driverDown = 0U;
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
      *chartInstance->c2_moveDown = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
      chartInstance->c2_is_safe = c2_IN_driverUp;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_driverUp = 1U;
      *chartInstance->c2_moveUp = true;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
      chartInstance->c2_is_driverUp = c2_IN_DriverUp;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_DriverUp = 1U;
      guard1 = true;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c2_sfEvent);
      switch (chartInstance->c2_is_driverDown) {
       case c2_IN_DriverDown:
        CV_STATE_EVAL(2, 0, 1);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U,
                     chartInstance->c2_sfEvent);
        c2_d_out = (CV_TRANSITION_EVAL(27U, (int32_T)_SFD_CCP_CALL(27U, 0,
          (*chartInstance->c2_driver)[0] != 0U, chartInstance->c2_sfEvent)) != 0);
        if (c2_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_DriverDown = 0U;
          chartInstance->c2_is_driverDown = c2_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_driverDown = 0U;
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 2U,
                       chartInstance->c2_sfEvent);
          *chartInstance->c2_moveDown = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_safe = c2_IN_driverNeutral;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_driverNeutral = 1U;
          *chartInstance->c2_moveUp = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
          *chartInstance->c2_moveDown = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_driverNeutral = c2_IN_passengerneutral;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_passengerneutral = 1U;
          *chartInstance->c2_moveUp = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
          *chartInstance->c2_moveDown = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                       chartInstance->c2_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c2_sfEvent);
        if (chartInstance->c2_is_safe != c2_IN_driverDown) {
        } else {
          guard1 = true;
        }
        break;

       case c2_IN_autoDriverDown:
        CV_STATE_EVAL(2, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c2_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c2_sfEvent);
        guard1 = true;
        break;

       case c2_IN_iniDriverDown:
        CV_STATE_EVAL(2, 0, 3);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                     chartInstance->c2_sfEvent);
        c2_temp = (_SFD_CCP_CALL(18U, 0, chartInstance->c2_sfEvent ==
                    c2_event_ticks != 0U, chartInstance->c2_sfEvent) != 0);
        if (c2_temp) {
          c2_temp = (_SFD_CCP_CALL(18U, 1, chartInstance->c2_temporalCounter_i1 >=
                      100 != 0U, chartInstance->c2_sfEvent) != 0);
        }

        c2_e_out = (CV_TRANSITION_EVAL(18U, (int32_T)c2_temp) != 0);
        if (c2_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                       chartInstance->c2_sfEvent);
          c2_f_out = (CV_TRANSITION_EVAL(19U, (int32_T)_SFD_CCP_CALL(19U, 0,
            (*chartInstance->c2_driver)[0] != 0U, chartInstance->c2_sfEvent)) !=
                      0);
          if (c2_f_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_iniDriverDown = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
            chartInstance->c2_is_driverDown = c2_IN_autoDriverDown;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_autoDriverDown = 1U;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_iniDriverDown = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
            chartInstance->c2_is_driverDown = c2_IN_DriverDown;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_DriverDown = 1U;
          }
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                       chartInstance->c2_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c2_sfEvent);
        guard1 = true;
        break;

       default:
        CV_STATE_EVAL(2, 0, 0);
        chartInstance->c2_is_driverDown = c2_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
        guard1 = true;
        break;
      }
    }
  }

  if (guard1 == true) {
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
  }
}

static void c2_exit_internal_driverDown
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  switch (chartInstance->c2_is_driverDown) {
   case c2_IN_DriverDown:
    CV_STATE_EVAL(2, 1, 1);
    chartInstance->c2_tp_DriverDown = 0U;
    chartInstance->c2_is_driverDown = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_autoDriverDown:
    CV_STATE_EVAL(2, 1, 2);
    chartInstance->c2_tp_autoDriverDown = 0U;
    chartInstance->c2_is_driverDown = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_iniDriverDown:
    CV_STATE_EVAL(2, 1, 3);
    chartInstance->c2_tp_iniDriverDown = 0U;
    chartInstance->c2_is_driverDown = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_STATE_EVAL(2, 1, 0);
    chartInstance->c2_is_driverDown = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
    break;
  }
}

static void c2_driverUp(SFc2_slexPowerWindowControlInstanceStruct *chartInstance)
{
  boolean_T c2_out;
  boolean_T c2_b_out;
  boolean_T c2_c_out;
  boolean_T c2_d_out;
  boolean_T c2_temp;
  boolean_T c2_e_out;
  boolean_T c2_f_out;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U, chartInstance->c2_sfEvent);
  c2_out = (CV_TRANSITION_EVAL(24U, (int32_T)_SFD_CCP_CALL(24U, 0,
              (*chartInstance->c2_driver)[2] != 0U, chartInstance->c2_sfEvent))
            != 0);
  guard1 = false;
  if (c2_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[2];
      unsigned int numTransitions = 1;
      transitionList[0] = 24;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      c2_b_out = *chartInstance->c2_endstop;
      if (c2_b_out) {
        transitionList[numTransitions] = 30;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c2_sfEvent);
    c2_exit_internal_driverUp(chartInstance);
    chartInstance->c2_tp_driverUp = 0U;
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 16U, chartInstance->c2_sfEvent);
    *chartInstance->c2_moveUp = false;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c2_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_safe = c2_IN_driverDown;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_driverDown = 1U;
    *chartInstance->c2_moveDown = true;
    _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
    chartInstance->c2_is_driverDown = c2_IN_DriverDown;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_DriverDown = 1U;
    guard1 = true;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 30U,
                 chartInstance->c2_sfEvent);
    c2_c_out = (CV_TRANSITION_EVAL(30U, (int32_T)_SFD_CCP_CALL(30U, 0,
      *chartInstance->c2_endstop != 0U, chartInstance->c2_sfEvent)) != 0);
    if (c2_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c2_sfEvent);
      c2_exit_internal_driverUp(chartInstance);
      chartInstance->c2_tp_driverUp = 0U;
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 16U, chartInstance->c2_sfEvent);
      *chartInstance->c2_moveUp = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c2_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
      chartInstance->c2_is_safe = c2_IN_driverNeutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_driverNeutral = 1U;
      *chartInstance->c2_moveUp = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
      *chartInstance->c2_moveDown = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
      chartInstance->c2_is_driverNeutral = c2_IN_passengerneutral;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_passengerneutral = 1U;
      *chartInstance->c2_moveUp = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
      *chartInstance->c2_moveDown = false;
      _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
      guard1 = true;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U,
                   chartInstance->c2_sfEvent);
      switch (chartInstance->c2_is_driverUp) {
       case c2_IN_DriverUp:
        CV_STATE_EVAL(16, 0, 1);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                     chartInstance->c2_sfEvent);
        c2_d_out = (CV_TRANSITION_EVAL(28U, (int32_T)_SFD_CCP_CALL(28U, 0,
          (*chartInstance->c2_driver)[0] != 0U, chartInstance->c2_sfEvent)) != 0);
        if (c2_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_DriverUp = 0U;
          chartInstance->c2_is_driverUp = c2_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_driverUp = 0U;
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 16U,
                       chartInstance->c2_sfEvent);
          *chartInstance->c2_moveUp = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c2_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_safe = c2_IN_driverNeutral;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_driverNeutral = 1U;
          *chartInstance->c2_moveUp = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
          *chartInstance->c2_moveDown = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_driverNeutral = c2_IN_passengerneutral;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_passengerneutral = 1U;
          *chartInstance->c2_moveUp = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveUp, 0U);
          *chartInstance->c2_moveDown = false;
          _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c2_moveDown, 1U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U,
                       chartInstance->c2_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c2_sfEvent);
        if (chartInstance->c2_is_safe != c2_IN_driverUp) {
        } else {
          guard1 = true;
        }
        break;

       case c2_IN_autoDriverUp:
        CV_STATE_EVAL(16, 0, 2);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U,
                     chartInstance->c2_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c2_sfEvent);
        guard1 = true;
        break;

       case c2_IN_iniDriverUp:
        CV_STATE_EVAL(16, 0, 3);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                     chartInstance->c2_sfEvent);
        c2_temp = (_SFD_CCP_CALL(21U, 0, chartInstance->c2_sfEvent ==
                    c2_event_ticks != 0U, chartInstance->c2_sfEvent) != 0);
        if (c2_temp) {
          c2_temp = (_SFD_CCP_CALL(21U, 1, chartInstance->c2_temporalCounter_i1 >=
                      100 != 0U, chartInstance->c2_sfEvent) != 0);
        }

        c2_e_out = (CV_TRANSITION_EVAL(21U, (int32_T)c2_temp) != 0);
        if (c2_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c2_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 23U,
                       chartInstance->c2_sfEvent);
          c2_f_out = (CV_TRANSITION_EVAL(23U, (int32_T)_SFD_CCP_CALL(23U, 0,
            (*chartInstance->c2_driver)[0] != 0U, chartInstance->c2_sfEvent)) !=
                      0);
          if (c2_f_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_iniDriverUp = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
            chartInstance->c2_is_driverUp = c2_IN_autoDriverUp;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_autoDriverUp = 1U;
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_iniDriverUp = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
            chartInstance->c2_is_driverUp = c2_IN_DriverUp;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_DriverUp = 1U;
          }
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U,
                       chartInstance->c2_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c2_sfEvent);
        guard1 = true;
        break;

       default:
        CV_STATE_EVAL(16, 0, 0);
        chartInstance->c2_is_driverUp = c2_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
        guard1 = true;
        break;
      }
    }
  }

  if (guard1 == true) {
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c2_sfEvent);
  }
}

static void c2_exit_internal_driverUp(SFc2_slexPowerWindowControlInstanceStruct *
  chartInstance)
{
  switch (chartInstance->c2_is_driverUp) {
   case c2_IN_DriverUp:
    CV_STATE_EVAL(16, 1, 1);
    chartInstance->c2_tp_DriverUp = 0U;
    chartInstance->c2_is_driverUp = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_autoDriverUp:
    CV_STATE_EVAL(16, 1, 2);
    chartInstance->c2_tp_autoDriverUp = 0U;
    chartInstance->c2_is_driverUp = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c2_sfEvent);
    break;

   case c2_IN_iniDriverUp:
    CV_STATE_EVAL(16, 1, 3);
    chartInstance->c2_tp_iniDriverUp = 0U;
    chartInstance->c2_is_driverUp = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c2_sfEvent);
    break;

   default:
    CV_STATE_EVAL(16, 1, 0);
    chartInstance->c2_is_driverUp = c2_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
    break;
  }
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  (void)c2_chartNumber;
  (void)c2_instanceNumber;
}

const mxArray *sf_c2_slexPowerWindowControl_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_slexPowerWindowControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_slexPowerWindowControlInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int8_T c2_emlrt_marshallIn(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int8_T c2_y;
  int8_T c2_i2;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i2, 1, 2, 0U, 0, 0U, 0);
  c2_y = c2_i2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_ticks;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int8_T c2_y;
  SFc2_slexPowerWindowControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_slexPowerWindowControlInstanceStruct *)chartInstanceVoid;
  c2_b_ticks = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_ticks), &c2_thisId);
  sf_mex_destroy(&c2_b_ticks);
  *(int8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_slexPowerWindowControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_slexPowerWindowControlInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_b_emlrt_marshallIn(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i3;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i3, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i3;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_slexPowerWindowControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_slexPowerWindowControlInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_slexPowerWindowControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_slexPowerWindowControlInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static uint8_T c2_c_emlrt_marshallIn(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance, const mxArray *c2_b_tp_safe, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_safe),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_safe);
  return c2_y;
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_tp_safe;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_slexPowerWindowControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_slexPowerWindowControlInstanceStruct *)chartInstanceVoid;
  c2_b_tp_safe = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_safe),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_safe);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  boolean_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_slexPowerWindowControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_slexPowerWindowControlInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(boolean_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static boolean_T c2_e_emlrt_marshallIn(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance, const mxArray *c2_b_moveUp, const char_T *c2_identifier)
{
  boolean_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_moveUp),
    &c2_thisId);
  sf_mex_destroy(&c2_b_moveUp);
  return c2_y;
}

static boolean_T c2_f_emlrt_marshallIn(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  boolean_T c2_y;
  boolean_T c2_b0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b0, 1, 11, 0U, 0, 0U, 0);
  c2_y = c2_b0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_moveUp;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  boolean_T c2_y;
  SFc2_slexPowerWindowControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_slexPowerWindowControlInstanceStruct *)chartInstanceVoid;
  c2_b_moveUp = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_moveUp),
    &c2_thisId);
  sf_mex_destroy(&c2_b_moveUp);
  *(boolean_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i4;
  boolean_T c2_b_inData[3];
  int32_T c2_i5;
  boolean_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_slexPowerWindowControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_slexPowerWindowControlInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
    c2_b_inData[c2_i4] = (*(boolean_T (*)[3])c2_inData)[c2_i4];
  }

  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    c2_u[c2_i5] = c2_b_inData[c2_i5];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 11, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_g_emlrt_marshallIn
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  sf_mex_assign(&c2_y, c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), false);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_h_emlrt_marshallIn
  (SFc2_slexPowerWindowControlInstanceStruct *chartInstance, const mxArray *c2_u,
   const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  (void)c2_parentId;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), false);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static uint8_T c2__u8_s32_(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance, int32_T c2_b)
{
  uint8_T c2_a;
  (void)chartInstance;
  c2_a = (uint8_T)c2_b;
  if (c2_a != c2_b) {
    _SFD_OVERFLOW_DETECTION(SFDB_OVERFLOW);
  }

  return c2_a;
}

static void init_dsm_address_info(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_slexPowerWindowControlInstanceStruct
  *chartInstance)
{
  chartInstance->c2_ticks = (int8_T *)(ssGetInputPortSignalPtrs_wrapper
    (chartInstance->S, 4))[0U];
  chartInstance->c2_moveUp = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_moveDown = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_endstop = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_obstacle = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_driver = (boolean_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_passenger = (boolean_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_slexPowerWindowControl_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3122684947U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2812520414U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4243414581U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1920752136U);
}

mxArray* sf_c2_slexPowerWindowControl_get_post_codegen_info(void);
mxArray *sf_c2_slexPowerWindowControl_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("U4pJ5ZHQrYkgdBrZAeen2B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c2_slexPowerWindowControl_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_slexPowerWindowControl_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_slexPowerWindowControl_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c2_slexPowerWindowControl_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_slexPowerWindowControl_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c2_slexPowerWindowControl(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[59],T\"moveDown\",},{M[1],M[58],T\"moveUp\",},{M[8],M[0],T\"is_active_c2_slexPowerWindowControl\",},{M[9],M[0],T\"is_c2_slexPowerWindowControl\",},{M[9],M[3],T\"is_passengerUp\",},{M[9],M[4],T\"is_passengerDown\",},{M[9],M[11],T\"is_driverUp\",},{M[9],M[12],T\"is_driverDown\",},{M[9],M[13],T\"is_driverNeutral\",},{M[9],M[20],T\"is_safe\",}}",
    "100 S'type','srcId','name','auxInfo'{{M[11],M[64],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x5[6 5 14 17 2],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 11, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_slexPowerWindowControl_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_slexPowerWindowControlInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_slexPowerWindowControlInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _slexPowerWindowControlMachineNumber_,
           2,
           20,
           33,
           0,
           6,
           1,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_slexPowerWindowControlMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_slexPowerWindowControlMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _slexPowerWindowControlMachineNumber_,
            chartInstance->chartNumber,
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,2,0,1,"moveUp");
          _SFD_SET_DATA_PROPS(1,2,0,1,"moveDown");
          _SFD_SET_DATA_PROPS(2,1,1,0,"endstop");
          _SFD_SET_DATA_PROPS(3,1,1,0,"obstacle");
          _SFD_SET_DATA_PROPS(4,1,1,0,"driver");
          _SFD_SET_DATA_PROPS(5,1,1,0,"passenger");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(17,0,0);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,3);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,6);
          _SFD_ST_SUBSTATE_INDEX(1,2,16);
          _SFD_ST_SUBSTATE_COUNT(2,3);
          _SFD_ST_SUBSTATE_INDEX(2,0,3);
          _SFD_ST_SUBSTATE_INDEX(2,1,4);
          _SFD_ST_SUBSTATE_INDEX(2,2,5);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,3);
          _SFD_ST_SUBSTATE_INDEX(6,0,7);
          _SFD_ST_SUBSTATE_INDEX(6,1,11);
          _SFD_ST_SUBSTATE_INDEX(6,2,15);
          _SFD_ST_SUBSTATE_COUNT(7,3);
          _SFD_ST_SUBSTATE_INDEX(7,0,8);
          _SFD_ST_SUBSTATE_INDEX(7,1,9);
          _SFD_ST_SUBSTATE_INDEX(7,2,10);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,3);
          _SFD_ST_SUBSTATE_INDEX(11,0,12);
          _SFD_ST_SUBSTATE_INDEX(11,1,13);
          _SFD_ST_SUBSTATE_INDEX(11,2,14);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(16,3);
          _SFD_ST_SUBSTATE_INDEX(16,0,17);
          _SFD_ST_SUBSTATE_INDEX(16,1,18);
          _SFD_ST_SUBSTATE_INDEX(16,2,19);
          _SFD_ST_SUBSTATE_COUNT(17,0);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(19,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(19,0,0,0,0,0,NULL,NULL);
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 11 };

          static unsigned int sEndGuardMap[] = { 8, 27 };

          static int sPostFixPredicateTree[] = { 0, 1, -2 };

          _SFD_CV_INIT_TRANS(1,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(17,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(27,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(29,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(28,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(30,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(26,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(25,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(24,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(8,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(7,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 8 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(10,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(11,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(9,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(0,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(16,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(15,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(18,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(19,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 10, 0 };

          static unsigned int sEndGuardMap[] = { 15, 16 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(21,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(23,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c2_moveUp);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c2_moveDown);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c2_endstop);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c2_obstacle);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c2_driver);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c2_passenger);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _slexPowerWindowControlMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "ll5njPDcJRxLAy719BdDKG";
}

static void sf_opaque_initialize_c2_slexPowerWindowControl(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_slexPowerWindowControlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_slexPowerWindowControl
    ((SFc2_slexPowerWindowControlInstanceStruct*) chartInstanceVar);
  initialize_c2_slexPowerWindowControl
    ((SFc2_slexPowerWindowControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_slexPowerWindowControl(void *chartInstanceVar)
{
  enable_c2_slexPowerWindowControl((SFc2_slexPowerWindowControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_slexPowerWindowControl(void *chartInstanceVar)
{
  disable_c2_slexPowerWindowControl((SFc2_slexPowerWindowControlInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_slexPowerWindowControl(void *chartInstanceVar)
{
  sf_gateway_c2_slexPowerWindowControl
    ((SFc2_slexPowerWindowControlInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_slexPowerWindowControl
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c2_slexPowerWindowControl
    ((SFc2_slexPowerWindowControlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_slexPowerWindowControl(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c2_slexPowerWindowControl
    ((SFc2_slexPowerWindowControlInstanceStruct*)chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c2_slexPowerWindowControl(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_slexPowerWindowControlInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_slexPowerWindowControl_optimization_info();
    }

    finalize_c2_slexPowerWindowControl
      ((SFc2_slexPowerWindowControlInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_slexPowerWindowControl
    ((SFc2_slexPowerWindowControlInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_slexPowerWindowControl(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c2_slexPowerWindowControl
      ((SFc2_slexPowerWindowControlInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_slexPowerWindowControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_slexPowerWindowControl_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
    }

    ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetCallsOutputInInitFcn(S,1);
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1880458204U));
  ssSetChecksum1(S,(2692112040U));
  ssSetChecksum2(S,(2625384003U));
  ssSetChecksum3(S,(2362948135U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_slexPowerWindowControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_slexPowerWindowControl(SimStruct *S)
{
  SFc2_slexPowerWindowControlInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_slexPowerWindowControlInstanceStruct *)utMalloc(sizeof
    (SFc2_slexPowerWindowControlInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_slexPowerWindowControlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_slexPowerWindowControl;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_slexPowerWindowControl;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_slexPowerWindowControl;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_slexPowerWindowControl;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_slexPowerWindowControl;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_slexPowerWindowControl;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_slexPowerWindowControl;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_slexPowerWindowControl;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_slexPowerWindowControl;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_slexPowerWindowControl;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_slexPowerWindowControl;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_slexPowerWindowControl_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_slexPowerWindowControl(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_slexPowerWindowControl(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_slexPowerWindowControl(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_slexPowerWindowControl_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
