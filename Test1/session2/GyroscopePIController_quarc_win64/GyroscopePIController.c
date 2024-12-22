/*
 * GyroscopePIController.c
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
#include "GyroscopePIController_dt.h"

/* Block signals (auto storage) */
B_GyroscopePIController_T GyroscopePIController_B;

/* Continuous states */
X_GyroscopePIController_T GyroscopePIController_X;

/* Block states (auto storage) */
DW_GyroscopePIController_T GyroscopePIController_DW;

/* Real-time model */
RT_MODEL_GyroscopePIControlle_T GyroscopePIController_M_;
RT_MODEL_GyroscopePIControlle_T *const GyroscopePIController_M =
  &GyroscopePIController_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  GyroscopePIController_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void GyroscopePIController_output(void)
{
  real_T u0;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(GyroscopePIController_M)) {
    /* set solver stop time */
    if (!(GyroscopePIController_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&GyroscopePIController_M->solverInfo,
                            ((GyroscopePIController_M->Timing.clockTickH0 + 1) *
        GyroscopePIController_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&GyroscopePIController_M->solverInfo,
                            ((GyroscopePIController_M->Timing.clockTick0 + 1) *
        GyroscopePIController_M->Timing.stepSize0 +
        GyroscopePIController_M->Timing.clockTickH0 *
        GyroscopePIController_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(GyroscopePIController_M)) {
    GyroscopePIController_M->Timing.t[0] = rtsiGetT
      (&GyroscopePIController_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(GyroscopePIController_M)) {
    /* S-Function (hil_read_encoder_block): '<S2>/HIL Read Encoder' */

    /* S-Function Block: GyroscopePIController/SRV02 Gyroscope/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder
        (GyroscopePIController_DW.HILInitialize_Card,
         GyroscopePIController_P.HILReadEncoder_channels, 2,
         &GyroscopePIController_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
      } else {
        GyroscopePIController_B.HILReadEncoder_o1 =
          GyroscopePIController_DW.HILReadEncoder_Buffer[0];
        GyroscopePIController_B.HILReadEncoder_o2 =
          GyroscopePIController_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S2>/GYRO-E: counts to rad' */
    GyroscopePIController_B.GYROEcountstorad =
      GyroscopePIController_P.GYROEcountstorad_Gain *
      GyroscopePIController_B.HILReadEncoder_o2;

    /* Gain: '<S2>/Gear ratio' */
    GyroscopePIController_B.Gearratio = GyroscopePIController_P.Gearratio_Gain *
      GyroscopePIController_B.GYROEcountstorad;

    /* Gain: '<Root>/Neg. Feedback' */
    GyroscopePIController_B.NegFeedback =
      GyroscopePIController_P.NegFeedback_Gain *
      GyroscopePIController_B.Gearratio;

    /* Gain: '<Root>/Proportional Gain' */
    GyroscopePIController_B.ProportionalGain =
      GyroscopePIController_P.ProportionalGain_Gain *
      GyroscopePIController_B.NegFeedback;
  }

  /* Integrator: '<Root>/Integral'
   * About '<Root>/Integral':
   *  Limited Integrator
   */
  if (GyroscopePIController_X.Integral_CSTATE >=
      GyroscopePIController_P.Integral_UpperSat ) {
    GyroscopePIController_X.Integral_CSTATE =
      GyroscopePIController_P.Integral_UpperSat;
  } else if (GyroscopePIController_X.Integral_CSTATE <=
             (GyroscopePIController_P.Integral_LowerSat) ) {
    GyroscopePIController_X.Integral_CSTATE =
      (GyroscopePIController_P.Integral_LowerSat);
  }

  GyroscopePIController_B.Integral = GyroscopePIController_X.Integral_CSTATE;

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Control OFF'
   */
  if (GyroscopePIController_P.ManualSwitch_CurrentSetting == 1) {
    GyroscopePIController_B.ManualSwitch =
      GyroscopePIController_P.ControlOFF_Value;
  } else {
    /* Gain: '<Root>/Negative Feedback' */
    GyroscopePIController_B.NegativeFeedback =
      GyroscopePIController_P.NegativeFeedback_Gain *
      GyroscopePIController_B.Integral;

    /* Gain: '<Root>/Integral Gain' */
    GyroscopePIController_B.IntegralGain =
      GyroscopePIController_P.IntegralGain_Gain *
      GyroscopePIController_B.NegativeFeedback;

    /* Sum: '<Root>/Add' */
    GyroscopePIController_B.Add = GyroscopePIController_B.ProportionalGain +
      GyroscopePIController_B.IntegralGain;
    GyroscopePIController_B.ManualSwitch = GyroscopePIController_B.Add;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Gain: '<S4>/Direction Convention: (Right-Hand) system' */
  GyroscopePIController_B.DirectionConventionRightHandsys =
    GyroscopePIController_P.DirectionConventionRightHandsys *
    GyroscopePIController_B.ManualSwitch;

  /* Saturate: '<S4>/Amplifier  Saturation (V)' */
  u0 = GyroscopePIController_B.DirectionConventionRightHandsys;
  u1 = GyroscopePIController_P.AmplifierSaturationV_LowerSat;
  u2 = GyroscopePIController_P.AmplifierSaturationV_UpperSat;
  if (u0 > u2) {
    GyroscopePIController_B.AmplifierSaturationV = u2;
  } else if (u0 < u1) {
    GyroscopePIController_B.AmplifierSaturationV = u1;
  } else {
    GyroscopePIController_B.AmplifierSaturationV = u0;
  }

  /* End of Saturate: '<S4>/Amplifier  Saturation (V)' */

  /* Gain: '<S4>/Inverse Amplifier  Gain (V//V)' */
  GyroscopePIController_B.InverseAmplifierGainVV =
    GyroscopePIController_P.InverseAmplifierGainVV_Gain *
    GyroscopePIController_B.AmplifierSaturationV;

  /* Saturate: '<S4>/DACB Saturation (V)' */
  u0 = GyroscopePIController_B.InverseAmplifierGainVV;
  u1 = GyroscopePIController_P.DACBSaturationV_LowerSat;
  u2 = GyroscopePIController_P.DACBSaturationV_UpperSat;
  if (u0 > u2) {
    GyroscopePIController_B.DACBSaturationV = u2;
  } else if (u0 < u1) {
    GyroscopePIController_B.DACBSaturationV = u1;
  } else {
    GyroscopePIController_B.DACBSaturationV = u0;
  }

  /* End of Saturate: '<S4>/DACB Saturation (V)' */
  if (rtmIsMajorTimeStep(GyroscopePIController_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/HIL Write Analog' */

    /* S-Function Block: GyroscopePIController/SRV02 Gyroscope/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(GyroscopePIController_DW.HILInitialize_Card,
        &GyroscopePIController_P.HILWriteAnalog_channels, 1,
        &GyroscopePIController_B.DACBSaturationV);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<S4>/Amplifier  Gain (V//V)' */
  GyroscopePIController_B.AmplifierGainVV =
    GyroscopePIController_P.AmplifierGainVV_Gain *
    GyroscopePIController_B.DACBSaturationV;
  if (rtmIsMajorTimeStep(GyroscopePIController_M)) {
    /* Gain: '<S2>/SRV02: counts to rad' */
    GyroscopePIController_B.SRV02countstorad =
      GyroscopePIController_P.SRV02countstorad_Gain *
      GyroscopePIController_B.HILReadEncoder_o1;

    /* S-Function (hil_write_digital_block): '<S2>/HIL Write Digital' */

    /* S-Function Block: GyroscopePIController/SRV02 Gyroscope/HIL Write Digital (hil_write_digital_block) */
    {
      t_error result;
      GyroscopePIController_DW.HILWriteDigital_Buffer[0] =
        (GyroscopePIController_P.EnableVoltPAQX2X4_Value[0] != 0);
      GyroscopePIController_DW.HILWriteDigital_Buffer[1] =
        (GyroscopePIController_P.EnableVoltPAQX2X4_Value[1] != 0);
      GyroscopePIController_DW.HILWriteDigital_Buffer[2] =
        (GyroscopePIController_P.EnableVoltPAQX2X4_Value[2] != 0);
      GyroscopePIController_DW.HILWriteDigital_Buffer[3] =
        (GyroscopePIController_P.EnableVoltPAQX2X4_Value[3] != 0);
      result = hil_write_digital(GyroscopePIController_DW.HILInitialize_Card,
        GyroscopePIController_P.HILWriteDigital_channels, 4,
        &GyroscopePIController_DW.HILWriteDigital_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
      }
    }

    /* Gain: '<S1>/Gain' */
    GyroscopePIController_B.Gain = GyroscopePIController_P.Gain_Gain *
      GyroscopePIController_B.Gearratio;

    /* Gain: '<S3>/Gain' */
    GyroscopePIController_B.Gain_i = GyroscopePIController_P.Gain_Gain_f *
      GyroscopePIController_B.SRV02countstorad;
  }
}

/* Model update function */
void GyroscopePIController_update(void)
{
  if (rtmIsMajorTimeStep(GyroscopePIController_M)) {
    rt_ertODEUpdateContinuousStates(&GyroscopePIController_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++GyroscopePIController_M->Timing.clockTick0)) {
    ++GyroscopePIController_M->Timing.clockTickH0;
  }

  GyroscopePIController_M->Timing.t[0] = rtsiGetSolverStopTime
    (&GyroscopePIController_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++GyroscopePIController_M->Timing.clockTick1)) {
      ++GyroscopePIController_M->Timing.clockTickH1;
    }

    GyroscopePIController_M->Timing.t[1] =
      GyroscopePIController_M->Timing.clockTick1 *
      GyroscopePIController_M->Timing.stepSize1 +
      GyroscopePIController_M->Timing.clockTickH1 *
      GyroscopePIController_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void GyroscopePIController_derivatives(void)
{
  /* Derivatives for Integrator: '<Root>/Integral' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( GyroscopePIController_X.Integral_CSTATE <=
            (GyroscopePIController_P.Integral_LowerSat) );
    usat = ( GyroscopePIController_X.Integral_CSTATE >=
            GyroscopePIController_P.Integral_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (GyroscopePIController_B.Gearratio > 0)) ||
        (usat && (GyroscopePIController_B.Gearratio < 0)) ) {
      ((XDot_GyroscopePIController_T *)
        GyroscopePIController_M->ModelData.derivs)->Integral_CSTATE =
        GyroscopePIController_B.Gearratio;
    } else {
      /* in saturation */
      ((XDot_GyroscopePIController_T *)
        GyroscopePIController_M->ModelData.derivs)->Integral_CSTATE = 0.0;
    }
  }
}

/* Model initialize function */
void GyroscopePIController_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

  /* S-Function Block: GyroscopePIController/SRV02 Gyroscope/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0",
                      &GyroscopePIController_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (GyroscopePIController_DW.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal", 50);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(GyroscopePIController_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
      return;
    }

    if ((GyroscopePIController_P.HILInitialize_set_analog_input_ &&
         !is_switching) ||
        (GyroscopePIController_P.HILInitialize_set_analog_inpu_p && is_switching))
    {
      GyroscopePIController_DW.HILInitialize_AIMinimums[0] =
        GyroscopePIController_P.HILInitialize_analog_input_mini;
      GyroscopePIController_DW.HILInitialize_AIMinimums[1] =
        GyroscopePIController_P.HILInitialize_analog_input_mini;
      GyroscopePIController_DW.HILInitialize_AIMaximums[0] =
        GyroscopePIController_P.HILInitialize_analog_input_maxi;
      GyroscopePIController_DW.HILInitialize_AIMaximums[1] =
        GyroscopePIController_P.HILInitialize_analog_input_maxi;
      result = hil_set_analog_input_ranges
        (GyroscopePIController_DW.HILInitialize_Card,
         GyroscopePIController_P.HILInitialize_analog_input_chan, 2U,
         &GyroscopePIController_DW.HILInitialize_AIMinimums[0],
         &GyroscopePIController_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
        return;
      }
    }

    if ((GyroscopePIController_P.HILInitialize_set_analog_output &&
         !is_switching) ||
        (GyroscopePIController_P.HILInitialize_set_analog_outp_j && is_switching))
    {
      GyroscopePIController_DW.HILInitialize_AOMinimums[0] =
        GyroscopePIController_P.HILInitialize_analog_output_min;
      GyroscopePIController_DW.HILInitialize_AOMinimums[1] =
        GyroscopePIController_P.HILInitialize_analog_output_min;
      GyroscopePIController_DW.HILInitialize_AOMaximums[0] =
        GyroscopePIController_P.HILInitialize_analog_output_max;
      GyroscopePIController_DW.HILInitialize_AOMaximums[1] =
        GyroscopePIController_P.HILInitialize_analog_output_max;
      result = hil_set_analog_output_ranges
        (GyroscopePIController_DW.HILInitialize_Card,
         GyroscopePIController_P.HILInitialize_analog_output_cha, 2U,
         &GyroscopePIController_DW.HILInitialize_AOMinimums[0],
         &GyroscopePIController_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
        return;
      }
    }

    if ((GyroscopePIController_P.HILInitialize_set_analog_outp_h &&
         !is_switching) ||
        (GyroscopePIController_P.HILInitialize_set_analog_outp_i && is_switching))
    {
      GyroscopePIController_DW.HILInitialize_AOVoltages[0] =
        GyroscopePIController_P.HILInitialize_initial_analog_ou;
      GyroscopePIController_DW.HILInitialize_AOVoltages[1] =
        GyroscopePIController_P.HILInitialize_initial_analog_ou;
      result = hil_write_analog(GyroscopePIController_DW.HILInitialize_Card,
        GyroscopePIController_P.HILInitialize_analog_output_cha, 2U,
        &GyroscopePIController_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
        return;
      }
    }

    if (GyroscopePIController_P.HILInitialize_set_analog_outp_o) {
      GyroscopePIController_DW.HILInitialize_AOVoltages[0] =
        GyroscopePIController_P.HILInitialize_watchdog_analog_o;
      GyroscopePIController_DW.HILInitialize_AOVoltages[1] =
        GyroscopePIController_P.HILInitialize_watchdog_analog_o;
      result = hil_watchdog_set_analog_expiration_state
        (GyroscopePIController_DW.HILInitialize_Card,
         GyroscopePIController_P.HILInitialize_analog_output_cha, 2U,
         &GyroscopePIController_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (GyroscopePIController_DW.HILInitialize_Card, NULL, 0U,
       GyroscopePIController_P.HILInitialize_digital_output_ch, 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
      return;
    }

    if ((GyroscopePIController_P.HILInitialize_set_digital_out_e &&
         !is_switching) ||
        (GyroscopePIController_P.HILInitialize_set_digital_out_f && is_switching))
    {
      {
        int_T i1;
        boolean_T *dw_DOBits = &GyroscopePIController_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] =
            GyroscopePIController_P.HILInitialize_initial_digital_o;
        }
      }

      result = hil_write_digital(GyroscopePIController_DW.HILInitialize_Card,
        GyroscopePIController_P.HILInitialize_digital_output_ch, 8U, (t_boolean *)
        &GyroscopePIController_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
        return;
      }
    }

    if (GyroscopePIController_P.HILInitialize_set_digital_out_o) {
      {
        int_T i1;
        int32_T *dw_DOStates = &GyroscopePIController_DW.HILInitialize_DOStates
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] =
            GyroscopePIController_P.HILInitialize_watchdog_digital_;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (GyroscopePIController_DW.HILInitialize_Card,
         GyroscopePIController_P.HILInitialize_digital_output_ch, 8U, (const
          t_digital_state *) &GyroscopePIController_DW.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
        return;
      }
    }

    if ((GyroscopePIController_P.HILInitialize_set_encoder_param &&
         !is_switching) ||
        (GyroscopePIController_P.HILInitialize_set_encoder_par_g && is_switching))
    {
      GyroscopePIController_DW.HILInitialize_QuadratureModes[0] =
        GyroscopePIController_P.HILInitialize_quadrature;
      GyroscopePIController_DW.HILInitialize_QuadratureModes[1] =
        GyroscopePIController_P.HILInitialize_quadrature;
      result = hil_set_encoder_quadrature_mode
        (GyroscopePIController_DW.HILInitialize_Card,
         GyroscopePIController_P.HILInitialize_encoder_channels, 2U,
         (t_encoder_quadrature_mode *)
         &GyroscopePIController_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
        return;
      }
    }

    if ((GyroscopePIController_P.HILInitialize_set_encoder_count &&
         !is_switching) ||
        (GyroscopePIController_P.HILInitialize_set_encoder_cou_a && is_switching))
    {
      GyroscopePIController_DW.HILInitialize_InitialEICounts[0] =
        GyroscopePIController_P.HILInitialize_initial_encoder_c;
      GyroscopePIController_DW.HILInitialize_InitialEICounts[1] =
        GyroscopePIController_P.HILInitialize_initial_encoder_c;
      result = hil_set_encoder_counts
        (GyroscopePIController_DW.HILInitialize_Card,
         GyroscopePIController_P.HILInitialize_encoder_channels, 2U,
         &GyroscopePIController_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Integrator: '<Root>/Integral' */
  GyroscopePIController_X.Integral_CSTATE = GyroscopePIController_P.Integral_IC;
}

/* Model terminate function */
void GyroscopePIController_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

  /* S-Function Block: GyroscopePIController/SRV02 Gyroscope/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    hil_task_stop_all(GyroscopePIController_DW.HILInitialize_Card);
    hil_monitor_stop_all(GyroscopePIController_DW.HILInitialize_Card);
    is_switching = false;
    if ((GyroscopePIController_P.HILInitialize_set_analog_outp_b &&
         !is_switching) ||
        (GyroscopePIController_P.HILInitialize_set_analog_outp_k && is_switching))
    {
      GyroscopePIController_DW.HILInitialize_AOVoltages[0] =
        GyroscopePIController_P.HILInitialize_final_analog_outp;
      GyroscopePIController_DW.HILInitialize_AOVoltages[1] =
        GyroscopePIController_P.HILInitialize_final_analog_outp;
      num_final_analog_outputs = 2U;
    }

    if ((GyroscopePIController_P.HILInitialize_set_digital_out_j &&
         !is_switching) ||
        (GyroscopePIController_P.HILInitialize_set_digital_out_i && is_switching))
    {
      {
        int_T i1;
        boolean_T *dw_DOBits = &GyroscopePIController_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] =
            GyroscopePIController_P.HILInitialize_final_digital_out;
        }
      }

      num_final_digital_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(GyroscopePIController_DW.HILInitialize_Card
                         ,
                         GyroscopePIController_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , NULL, 0
                         ,
                         GyroscopePIController_P.HILInitialize_digital_output_ch,
                         num_final_digital_outputs
                         , NULL, 0
                         , &GyroscopePIController_DW.HILInitialize_AOVoltages[0]
                         , NULL
                         , (t_boolean *)
                         &GyroscopePIController_DW.HILInitialize_DOBits[0]
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (GyroscopePIController_DW.HILInitialize_Card,
             GyroscopePIController_P.HILInitialize_analog_output_cha,
             num_final_analog_outputs,
             &GyroscopePIController_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (GyroscopePIController_DW.HILInitialize_Card,
             GyroscopePIController_P.HILInitialize_digital_output_ch,
             num_final_digital_outputs, (t_boolean *)
             &GyroscopePIController_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(GyroscopePIController_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(GyroscopePIController_DW.HILInitialize_Card);
    hil_monitor_delete_all(GyroscopePIController_DW.HILInitialize_Card);
    hil_close(GyroscopePIController_DW.HILInitialize_Card);
    GyroscopePIController_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  GyroscopePIController_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  GyroscopePIController_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  GyroscopePIController_initialize();
}

void MdlTerminate(void)
{
  GyroscopePIController_terminate();
}

/* Registration function */
RT_MODEL_GyroscopePIControlle_T *GyroscopePIController(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)GyroscopePIController_M, 0,
                sizeof(RT_MODEL_GyroscopePIControlle_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&GyroscopePIController_M->solverInfo,
                          &GyroscopePIController_M->Timing.simTimeStep);
    rtsiSetTPtr(&GyroscopePIController_M->solverInfo, &rtmGetTPtr
                (GyroscopePIController_M));
    rtsiSetStepSizePtr(&GyroscopePIController_M->solverInfo,
                       &GyroscopePIController_M->Timing.stepSize0);
    rtsiSetdXPtr(&GyroscopePIController_M->solverInfo,
                 &GyroscopePIController_M->ModelData.derivs);
    rtsiSetContStatesPtr(&GyroscopePIController_M->solverInfo, (real_T **)
                         &GyroscopePIController_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&GyroscopePIController_M->solverInfo,
      &GyroscopePIController_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&GyroscopePIController_M->solverInfo,
                          (&rtmGetErrorStatus(GyroscopePIController_M)));
    rtsiSetRTModelPtr(&GyroscopePIController_M->solverInfo,
                      GyroscopePIController_M);
  }

  rtsiSetSimTimeStep(&GyroscopePIController_M->solverInfo, MAJOR_TIME_STEP);
  GyroscopePIController_M->ModelData.intgData.f[0] =
    GyroscopePIController_M->ModelData.odeF[0];
  GyroscopePIController_M->ModelData.contStates = ((real_T *)
    &GyroscopePIController_X);
  rtsiSetSolverData(&GyroscopePIController_M->solverInfo, (void *)
                    &GyroscopePIController_M->ModelData.intgData);
  rtsiSetSolverName(&GyroscopePIController_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = GyroscopePIController_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    GyroscopePIController_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    GyroscopePIController_M->Timing.sampleTimes =
      (&GyroscopePIController_M->Timing.sampleTimesArray[0]);
    GyroscopePIController_M->Timing.offsetTimes =
      (&GyroscopePIController_M->Timing.offsetTimesArray[0]);

    /* task periods */
    GyroscopePIController_M->Timing.sampleTimes[0] = (0.0);
    GyroscopePIController_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    GyroscopePIController_M->Timing.offsetTimes[0] = (0.0);
    GyroscopePIController_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(GyroscopePIController_M, &GyroscopePIController_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = GyroscopePIController_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    GyroscopePIController_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(GyroscopePIController_M, -1);
  GyroscopePIController_M->Timing.stepSize0 = 0.002;
  GyroscopePIController_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  GyroscopePIController_M->Sizes.checksums[0] = (3879449109U);
  GyroscopePIController_M->Sizes.checksums[1] = (1244745441U);
  GyroscopePIController_M->Sizes.checksums[2] = (1503347110U);
  GyroscopePIController_M->Sizes.checksums[3] = (3231266983U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    GyroscopePIController_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(GyroscopePIController_M->extModeInfo,
      &GyroscopePIController_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(GyroscopePIController_M->extModeInfo,
                        GyroscopePIController_M->Sizes.checksums);
    rteiSetTPtr(GyroscopePIController_M->extModeInfo, rtmGetTPtr
                (GyroscopePIController_M));
  }

  GyroscopePIController_M->solverInfoPtr = (&GyroscopePIController_M->solverInfo);
  GyroscopePIController_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&GyroscopePIController_M->solverInfo, 0.002);
  rtsiSetSolverMode(&GyroscopePIController_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  GyroscopePIController_M->ModelData.blockIO = ((void *)
    &GyroscopePIController_B);

  {
    GyroscopePIController_B.HILReadEncoder_o1 = 0.0;
    GyroscopePIController_B.HILReadEncoder_o2 = 0.0;
    GyroscopePIController_B.GYROEcountstorad = 0.0;
    GyroscopePIController_B.Gearratio = 0.0;
    GyroscopePIController_B.NegFeedback = 0.0;
    GyroscopePIController_B.ProportionalGain = 0.0;
    GyroscopePIController_B.Integral = 0.0;
    GyroscopePIController_B.ManualSwitch = 0.0;
    GyroscopePIController_B.DirectionConventionRightHandsys = 0.0;
    GyroscopePIController_B.AmplifierSaturationV = 0.0;
    GyroscopePIController_B.InverseAmplifierGainVV = 0.0;
    GyroscopePIController_B.DACBSaturationV = 0.0;
    GyroscopePIController_B.AmplifierGainVV = 0.0;
    GyroscopePIController_B.SRV02countstorad = 0.0;
    GyroscopePIController_B.Gain = 0.0;
    GyroscopePIController_B.Gain_i = 0.0;
    GyroscopePIController_B.NegativeFeedback = 0.0;
    GyroscopePIController_B.IntegralGain = 0.0;
    GyroscopePIController_B.Add = 0.0;
  }

  /* parameters */
  GyroscopePIController_M->ModelData.defaultParam = ((real_T *)
    &GyroscopePIController_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &GyroscopePIController_X;
    GyroscopePIController_M->ModelData.contStates = (x);
    (void) memset((void *)&GyroscopePIController_X, 0,
                  sizeof(X_GyroscopePIController_T));
  }

  /* states (dwork) */
  GyroscopePIController_M->ModelData.dwork = ((void *) &GyroscopePIController_DW);
  (void) memset((void *)&GyroscopePIController_DW, 0,
                sizeof(DW_GyroscopePIController_T));
  GyroscopePIController_DW.HILInitialize_AIMinimums[0] = 0.0;
  GyroscopePIController_DW.HILInitialize_AIMinimums[1] = 0.0;
  GyroscopePIController_DW.HILInitialize_AIMaximums[0] = 0.0;
  GyroscopePIController_DW.HILInitialize_AIMaximums[1] = 0.0;
  GyroscopePIController_DW.HILInitialize_AOMinimums[0] = 0.0;
  GyroscopePIController_DW.HILInitialize_AOMinimums[1] = 0.0;
  GyroscopePIController_DW.HILInitialize_AOMaximums[0] = 0.0;
  GyroscopePIController_DW.HILInitialize_AOMaximums[1] = 0.0;
  GyroscopePIController_DW.HILInitialize_AOVoltages[0] = 0.0;
  GyroscopePIController_DW.HILInitialize_AOVoltages[1] = 0.0;
  GyroscopePIController_DW.HILInitialize_FilterFrequency[0] = 0.0;
  GyroscopePIController_DW.HILInitialize_FilterFrequency[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    GyroscopePIController_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  GyroscopePIController_M->Sizes.numContStates = (1);/* Number of continuous states */
  GyroscopePIController_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  GyroscopePIController_M->Sizes.numY = (0);/* Number of model outputs */
  GyroscopePIController_M->Sizes.numU = (0);/* Number of model inputs */
  GyroscopePIController_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  GyroscopePIController_M->Sizes.numSampTimes = (2);/* Number of sample times */
  GyroscopePIController_M->Sizes.numBlocks = (27);/* Number of blocks */
  GyroscopePIController_M->Sizes.numBlockIO = (19);/* Number of block outputs */
  GyroscopePIController_M->Sizes.numBlockPrms = (106);/* Sum of parameter "widths" */
  return GyroscopePIController_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
