/*
 * GyroscopePIController_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GyroscopePIController".
 *
 * Model version              : 1.116
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sat May 06 15:04:50 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "GyroscopePIController.h"
#include "GyroscopePIController_private.h"

/* Block parameters (auto storage) */
P_GyroscopePIController_T GyroscopePIController_P = {
  10.0,                                /* Mask Parameter: HILInitialize_analog_input_maxi
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  -10.0,                               /* Mask Parameter: HILInitialize_analog_input_mini
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  10.0,                                /* Mask Parameter: HILInitialize_analog_output_max
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  -10.0,                               /* Mask Parameter: HILInitialize_analog_output_min
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_analog_outp
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_pwm_outputs
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_initial_analog_ou
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_initial_pwm_outpu
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  50.0,                                /* Mask Parameter: HILInitialize_pwm_frequency
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outputs
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_n
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_o
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_f
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_analog_o
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_pwm_outp
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */

  /*  Mask Parameter: HILInitialize_hardware_clocks
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 0, 1, 2 },
  0,                                   /* Mask Parameter: HILInitialize_initial_encoder_c
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_modes
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_watchdog_digital_
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */

  /*  Mask Parameter: HILInitialize_analog_input_chan
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 0U, 1U },

  /*  Mask Parameter: HILInitialize_analog_output_cha
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 0U, 1U },

  /*  Mask Parameter: HILReadEncoder_channels
   * Referenced by: '<S2>/HIL Read Encoder'
   */
  { 0U, 1U },
  0U,                                  /* Mask Parameter: HILWriteAnalog_channels
                                        * Referenced by: '<S2>/HIL Write Analog'
                                        */

  /*  Mask Parameter: HILWriteDigital_channels
   * Referenced by: '<S2>/HIL Write Digital'
   */
  { 0U, 1U, 2U, 3U },

  /*  Mask Parameter: HILInitialize_digital_output_ch
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILInitialize_encoder_channels
   * Referenced by: '<S2>/HIL Initialize'
   */
  { 0U, 1U },
  4U,                                  /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_final_digital_out
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_initial_digital_o
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_input_
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_inpu_p
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_output
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_j
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_outp_h
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_i
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_k
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_outp_b
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_o
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequen
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequ_f
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_params_
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_param_a
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_outpu
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_h
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_e
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_f
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_i
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_j
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_o
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_count
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_cou_a
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_param
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_par_g
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_other_outpu_i
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_p
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_i
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_g
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_params_at
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_params__i
                                        * Referenced by: '<S2>/HIL Initialize'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Negative Feedback'
                                        */
  149.9188,                            /* Expression: 149.9188
                                        * Referenced by: '<Root>/Integral Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Control OFF'
                                        */
  0.0015339807878856412,               /* Expression: 2*pi/4096
                                        * Referenced by: '<S2>/GYRO-E: counts to rad'
                                        */
  0.25,                                /* Expression: 1/4
                                        * Referenced by: '<S2>/Gear ratio'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Neg. Feedback'
                                        */
  4.5828,                              /* Expression: 4.5828
                                        * Referenced by: '<Root>/Proportional Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integral'
                                        */
  0.087266462599716474,                /* Expression: 5*pi/180
                                        * Referenced by: '<Root>/Integral'
                                        */
  -0.087266462599716474,               /* Expression: -5*pi/180
                                        * Referenced by: '<Root>/Integral'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S4>/Direction Convention: (Right-Hand) system'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S4>/Amplifier  Saturation (V)'
                                        */
  -10.0,                               /* Expression: -10
                                        * Referenced by: '<S4>/Amplifier  Saturation (V)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Inverse Amplifier  Gain (V//V)'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S4>/DACB Saturation (V)'
                                        */
  -10.0,                               /* Expression: -10
                                        * Referenced by: '<S4>/DACB Saturation (V)'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S4>/Amplifier  Gain (V//V)'
                                        */
  -0.0015339807878856412,              /* Expression: -2*pi/4096
                                        * Referenced by: '<S2>/SRV02: counts to rad'
                                        */

  /*  Expression: [1 1 1 1]
   * Referenced by: '<S2>/Enable VoltPAQ-X2,X4'
   */
  { 1.0, 1.0, 1.0, 1.0 },
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S1>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S3>/Gain'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  1,                                   /* Computed Parameter: HILReadEncoder_Active
                                        * Referenced by: '<S2>/HIL Read Encoder'
                                        */
  0,                                   /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S2>/HIL Write Analog'
                                        */
  0                                    /* Computed Parameter: HILWriteDigital_Active
                                        * Referenced by: '<S2>/HIL Write Digital'
                                        */
};
