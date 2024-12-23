/*
 * GyroscopeHinfinityController_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GyroscopeHinfinityController".
 *
 * Model version              : 1.117
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed May 10 17:38:15 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_card),
  sizeof(t_boolean)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_card",
  "t_boolean"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&GyroscopeHinfinityController_B.HILReadEncoder_o1), 0, 0, 21 }
  ,

  { (char_T *)(&GyroscopeHinfinityController_DW.HILInitialize_AIMinimums[0]), 0,
    0, 12 },

  { (char_T *)(&GyroscopeHinfinityController_DW.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&GyroscopeHinfinityController_DW.HILReadEncoder_PWORK), 11, 0, 6
  },

  { (char_T *)(&GyroscopeHinfinityController_DW.HILInitialize_ClockModes[0]), 6,
    0, 17 },

  { (char_T *)(&GyroscopeHinfinityController_DW.HILInitialize_DOBits[0]), 8, 0,
    8 },

  { (char_T *)(&GyroscopeHinfinityController_DW.HILWriteDigital_Buffer[0]), 15,
    0, 4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&GyroscopeHinfinityController_P.ac[0]), 0, 0, 30 },

  { (char_T *)(&GyroscopeHinfinityController_P.HILInitialize_hardware_clocks[0]),
    6, 0, 6 },

  { (char_T *)(&GyroscopeHinfinityController_P.HILInitialize_analog_input_chan[0]),
    7, 0, 22 },

  { (char_T *)(&GyroscopeHinfinityController_P.HILInitialize_active), 8, 0, 35 },

  { (char_T *)(&GyroscopeHinfinityController_P.NegativeFeedback_Gain), 0, 0, 27
  },

  { (char_T *)(&GyroscopeHinfinityController_P.ManualSwitch_CurrentSetting), 3,
    0, 1 },

  { (char_T *)(&GyroscopeHinfinityController_P.HILReadEncoder_Active), 8, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] GyroscopeHinfinityController_dt.h */
