/*
 * GyroscopeHinfinityController.c
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

#include "GyroscopeHinfinityController.h"
#include "GyroscopeHinfinityController_private.h"
#include "GyroscopeHinfinityController_dt.h"

/* Block signals (auto storage) */
B_GyroscopeHinfinityControlle_T GyroscopeHinfinityController_B;

/* Continuous states */
X_GyroscopeHinfinityControlle_T GyroscopeHinfinityController_X;

/* Block states (auto storage) */
DW_GyroscopeHinfinityControll_T GyroscopeHinfinityController_DW;

/* Real-time model */
RT_MODEL_GyroscopeHinfinityCo_T GyroscopeHinfinityController_M_;
RT_MODEL_GyroscopeHinfinityCo_T *const GyroscopeHinfinityController_M =
  &GyroscopeHinfinityController_M_;

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
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  GyroscopeHinfinityController_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void GyroscopeHinfinityController_output(void)
{
  real_T u0;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(GyroscopeHinfinityController_M)) {
    /* set solver stop time */
    if (!(GyroscopeHinfinityController_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&GyroscopeHinfinityController_M->solverInfo,
                            ((GyroscopeHinfinityController_M->Timing.clockTickH0
        + 1) * GyroscopeHinfinityController_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&GyroscopeHinfinityController_M->solverInfo,
                            ((GyroscopeHinfinityController_M->Timing.clockTick0
        + 1) * GyroscopeHinfinityController_M->Timing.stepSize0 +
        GyroscopeHinfinityController_M->Timing.clockTickH0 *
        GyroscopeHinfinityController_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(GyroscopeHinfinityController_M)) {
    GyroscopeHinfinityController_M->Timing.t[0] = rtsiGetT
      (&GyroscopeHinfinityController_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(GyroscopeHinfinityController_M)) {
    /* S-Function (hil_read_encoder_block): '<S3>/HIL Read Encoder' */

    /* S-Function Block: GyroscopeHinfinityController/SRV02 Gyroscope/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder
        (GyroscopeHinfinityController_DW.HILInitialize_Card,
         GyroscopeHinfinityController_P.HILReadEncoder_channels, 2,
         &GyroscopeHinfinityController_DW.HILReadEncoder_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
      } else {
        GyroscopeHinfinityController_B.HILReadEncoder_o1 =
          GyroscopeHinfinityController_DW.HILReadEncoder_Buffer[0];
        GyroscopeHinfinityController_B.HILReadEncoder_o2 =
          GyroscopeHinfinityController_DW.HILReadEncoder_Buffer[1];
      }
    }

    /* Gain: '<S3>/GYRO-E: counts to rad' */
    GyroscopeHinfinityController_B.GYROEcountstorad =
      GyroscopeHinfinityController_P.GYROEcountstorad_Gain *
      GyroscopeHinfinityController_B.HILReadEncoder_o2;

    /* Gain: '<S3>/Gear ratio' */
    GyroscopeHinfinityController_B.Gearratio =
      GyroscopeHinfinityController_P.Gearratio_Gain *
      GyroscopeHinfinityController_B.GYROEcountstorad;

    /* Gain: '<S2>/Neg. Feedback' */
    GyroscopeHinfinityController_B.NegFeedback =
      GyroscopeHinfinityController_P.NegFeedback_Gain *
      GyroscopeHinfinityController_B.Gearratio;

    /* Gain: '<S2>/Proportional Gain' */
    GyroscopeHinfinityController_B.ProportionalGain =
      GyroscopeHinfinityController_P.ProportionalGain_Gain *
      GyroscopeHinfinityController_B.NegFeedback;
  }

  /* Integrator: '<S2>/Integral'
   * About '<S2>/Integral':
   *  Limited Integrator
   */
  if (GyroscopeHinfinityController_X.Integral_CSTATE >=
      GyroscopeHinfinityController_P.Integral_UpperSat ) {
    GyroscopeHinfinityController_X.Integral_CSTATE =
      GyroscopeHinfinityController_P.Integral_UpperSat;
  } else if (GyroscopeHinfinityController_X.Integral_CSTATE <=
             (GyroscopeHinfinityController_P.Integral_LowerSat) ) {
    GyroscopeHinfinityController_X.Integral_CSTATE =
      (GyroscopeHinfinityController_P.Integral_LowerSat);
  }

  GyroscopeHinfinityController_B.Integral =
    GyroscopeHinfinityController_X.Integral_CSTATE;

  /* StateSpace: '<Root>/H-infinity Controller' */
  GyroscopeHinfinityController_B.HinfinityController = 0.0;
  GyroscopeHinfinityController_B.HinfinityController +=
    GyroscopeHinfinityController_P.cc[0] *
    GyroscopeHinfinityController_X.HinfinityController_CSTATE[0];
  GyroscopeHinfinityController_B.HinfinityController +=
    GyroscopeHinfinityController_P.cc[1] *
    GyroscopeHinfinityController_X.HinfinityController_CSTATE[1];
  GyroscopeHinfinityController_B.HinfinityController +=
    GyroscopeHinfinityController_P.cc[2] *
    GyroscopeHinfinityController_X.HinfinityController_CSTATE[2];

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (GyroscopeHinfinityController_P.ManualSwitch_CurrentSetting == 1) {
    /* Gain: '<S2>/Negative Feedback' */
    GyroscopeHinfinityController_B.NegativeFeedback =
      GyroscopeHinfinityController_P.NegativeFeedback_Gain *
      GyroscopeHinfinityController_B.Integral;

    /* Gain: '<S2>/Integral Gain' */
    GyroscopeHinfinityController_B.IntegralGain =
      GyroscopeHinfinityController_P.IntegralGain_Gain *
      GyroscopeHinfinityController_B.NegativeFeedback;

    /* Sum: '<S2>/Add' */
    GyroscopeHinfinityController_B.Add =
      GyroscopeHinfinityController_B.ProportionalGain +
      GyroscopeHinfinityController_B.IntegralGain;
    GyroscopeHinfinityController_B.ManualSwitch =
      GyroscopeHinfinityController_B.Add;
  } else {
    GyroscopeHinfinityController_B.ManualSwitch =
      GyroscopeHinfinityController_B.HinfinityController;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Gain: '<S5>/Direction Convention: (Right-Hand) system' */
  GyroscopeHinfinityController_B.DirectionConventionRightHandsys =
    GyroscopeHinfinityController_P.DirectionConventionRightHandsys *
    GyroscopeHinfinityController_B.ManualSwitch;

  /* Saturate: '<S5>/Amplifier  Saturation (V)' */
  u0 = GyroscopeHinfinityController_B.DirectionConventionRightHandsys;
  u1 = GyroscopeHinfinityController_P.AmplifierSaturationV_LowerSat;
  u2 = GyroscopeHinfinityController_P.AmplifierSaturationV_UpperSat;
  if (u0 > u2) {
    GyroscopeHinfinityController_B.AmplifierSaturationV = u2;
  } else if (u0 < u1) {
    GyroscopeHinfinityController_B.AmplifierSaturationV = u1;
  } else {
    GyroscopeHinfinityController_B.AmplifierSaturationV = u0;
  }

  /* End of Saturate: '<S5>/Amplifier  Saturation (V)' */

  /* Gain: '<S5>/Inverse Amplifier  Gain (V//V)' */
  GyroscopeHinfinityController_B.InverseAmplifierGainVV =
    GyroscopeHinfinityController_P.InverseAmplifierGainVV_Gain *
    GyroscopeHinfinityController_B.AmplifierSaturationV;

  /* Saturate: '<S5>/DACB Saturation (V)' */
  u0 = GyroscopeHinfinityController_B.InverseAmplifierGainVV;
  u1 = GyroscopeHinfinityController_P.DACBSaturationV_LowerSat;
  u2 = GyroscopeHinfinityController_P.DACBSaturationV_UpperSat;
  if (u0 > u2) {
    GyroscopeHinfinityController_B.DACBSaturationV = u2;
  } else if (u0 < u1) {
    GyroscopeHinfinityController_B.DACBSaturationV = u1;
  } else {
    GyroscopeHinfinityController_B.DACBSaturationV = u0;
  }

  /* End of Saturate: '<S5>/DACB Saturation (V)' */
  if (rtmIsMajorTimeStep(GyroscopeHinfinityController_M)) {
    /* S-Function (hil_write_analog_block): '<S3>/HIL Write Analog' */

    /* S-Function Block: GyroscopeHinfinityController/SRV02 Gyroscope/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog
        (GyroscopeHinfinityController_DW.HILInitialize_Card,
         &GyroscopeHinfinityController_P.HILWriteAnalog_channels, 1,
         &GyroscopeHinfinityController_B.DACBSaturationV);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<S5>/Amplifier  Gain (V//V)' */
  GyroscopeHinfinityController_B.AmplifierGainVV =
    GyroscopeHinfinityController_P.AmplifierGainVV_Gain *
    GyroscopeHinfinityController_B.DACBSaturationV;
  if (rtmIsMajorTimeStep(GyroscopeHinfinityController_M)) {
    /* Gain: '<S3>/SRV02: counts to rad' */
    GyroscopeHinfinityController_B.SRV02countstorad =
      GyroscopeHinfinityController_P.SRV02countstorad_Gain *
      GyroscopeHinfinityController_B.HILReadEncoder_o1;

    /* S-Function (hil_write_digital_block): '<S3>/HIL Write Digital' */

    /* S-Function Block: GyroscopeHinfinityController/SRV02 Gyroscope/HIL Write Digital (hil_write_digital_block) */
    {
      t_error result;
      GyroscopeHinfinityController_DW.HILWriteDigital_Buffer[0] =
        (GyroscopeHinfinityController_P.EnableVoltPAQX2X4_Value[0] != 0);
      GyroscopeHinfinityController_DW.HILWriteDigital_Buffer[1] =
        (GyroscopeHinfinityController_P.EnableVoltPAQX2X4_Value[1] != 0);
      GyroscopeHinfinityController_DW.HILWriteDigital_Buffer[2] =
        (GyroscopeHinfinityController_P.EnableVoltPAQX2X4_Value[2] != 0);
      GyroscopeHinfinityController_DW.HILWriteDigital_Buffer[3] =
        (GyroscopeHinfinityController_P.EnableVoltPAQX2X4_Value[3] != 0);
      result = hil_write_digital
        (GyroscopeHinfinityController_DW.HILInitialize_Card,
         GyroscopeHinfinityController_P.HILWriteDigital_channels, 4,
         &GyroscopeHinfinityController_DW.HILWriteDigital_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
      }
    }

    /* Gain: '<S1>/Gain' */
    GyroscopeHinfinityController_B.Gain =
      GyroscopeHinfinityController_P.Gain_Gain *
      GyroscopeHinfinityController_B.Gearratio;

    /* Gain: '<S4>/Gain' */
    GyroscopeHinfinityController_B.Gain_i =
      GyroscopeHinfinityController_P.Gain_Gain_f *
      GyroscopeHinfinityController_B.SRV02countstorad;
  }

  /* Integrator: '<Root>/Integral'
   * About '<Root>/Integral':
   *  Limited Integrator
   */
  if (GyroscopeHinfinityController_X.Integral_CSTATE_c >=
      GyroscopeHinfinityController_P.Integral_UpperSat_m ) {
    GyroscopeHinfinityController_X.Integral_CSTATE_c =
      GyroscopeHinfinityController_P.Integral_UpperSat_m;
  } else if (GyroscopeHinfinityController_X.Integral_CSTATE_c <=
             (GyroscopeHinfinityController_P.Integral_LowerSat_d) ) {
    GyroscopeHinfinityController_X.Integral_CSTATE_c =
      (GyroscopeHinfinityController_P.Integral_LowerSat_d);
  }

  GyroscopeHinfinityController_B.Integral_n =
    GyroscopeHinfinityController_X.Integral_CSTATE_c;
}

/* Model update function */
void GyroscopeHinfinityController_update(void)
{
  if (rtmIsMajorTimeStep(GyroscopeHinfinityController_M)) {
    rt_ertODEUpdateContinuousStates(&GyroscopeHinfinityController_M->solverInfo);
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
  if (!(++GyroscopeHinfinityController_M->Timing.clockTick0)) {
    ++GyroscopeHinfinityController_M->Timing.clockTickH0;
  }

  GyroscopeHinfinityController_M->Timing.t[0] = rtsiGetSolverStopTime
    (&GyroscopeHinfinityController_M->solverInfo);

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
    if (!(++GyroscopeHinfinityController_M->Timing.clockTick1)) {
      ++GyroscopeHinfinityController_M->Timing.clockTickH1;
    }

    GyroscopeHinfinityController_M->Timing.t[1] =
      GyroscopeHinfinityController_M->Timing.clockTick1 *
      GyroscopeHinfinityController_M->Timing.stepSize1 +
      GyroscopeHinfinityController_M->Timing.clockTickH1 *
      GyroscopeHinfinityController_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void GyroscopeHinfinityController_derivatives(void)
{
  int_T is;
  XDot_GyroscopeHinfinityContro_T *_rtXdot;
  _rtXdot = ((XDot_GyroscopeHinfinityContro_T *)
             GyroscopeHinfinityController_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S2>/Integral' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( GyroscopeHinfinityController_X.Integral_CSTATE <=
            (GyroscopeHinfinityController_P.Integral_LowerSat) );
    usat = ( GyroscopeHinfinityController_X.Integral_CSTATE >=
            GyroscopeHinfinityController_P.Integral_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (GyroscopeHinfinityController_B.Gearratio > 0)) ||
        (usat && (GyroscopeHinfinityController_B.Gearratio < 0)) ) {
      ((XDot_GyroscopeHinfinityContro_T *)
        GyroscopeHinfinityController_M->ModelData.derivs)->Integral_CSTATE =
        GyroscopeHinfinityController_B.Gearratio;
    } else {
      /* in saturation */
      ((XDot_GyroscopeHinfinityContro_T *)
        GyroscopeHinfinityController_M->ModelData.derivs)->Integral_CSTATE = 0.0;
    }
  }

  /* Derivatives for StateSpace: '<Root>/H-infinity Controller' */
  _rtXdot->HinfinityController_CSTATE[0] = 0.0;
  _rtXdot->HinfinityController_CSTATE[1] = 0.0;
  _rtXdot->HinfinityController_CSTATE[2] = 0.0;
  for (is = 0; is < 3; is++) {
    _rtXdot->HinfinityController_CSTATE[is] +=
      GyroscopeHinfinityController_P.ac[is] *
      GyroscopeHinfinityController_X.HinfinityController_CSTATE[0];
    _rtXdot->HinfinityController_CSTATE[is] +=
      GyroscopeHinfinityController_P.ac[3 + is] *
      GyroscopeHinfinityController_X.HinfinityController_CSTATE[1];
    _rtXdot->HinfinityController_CSTATE[is] +=
      GyroscopeHinfinityController_P.ac[6 + is] *
      GyroscopeHinfinityController_X.HinfinityController_CSTATE[2];
  }

  _rtXdot->HinfinityController_CSTATE[0] += GyroscopeHinfinityController_P.bc[0]
    * GyroscopeHinfinityController_B.Integral_n;
  _rtXdot->HinfinityController_CSTATE[1] += GyroscopeHinfinityController_P.bc[1]
    * GyroscopeHinfinityController_B.Integral_n;
  _rtXdot->HinfinityController_CSTATE[2] += GyroscopeHinfinityController_P.bc[2]
    * GyroscopeHinfinityController_B.Integral_n;

  /* End of Derivatives for StateSpace: '<Root>/H-infinity Controller' */
  /* Derivatives for Integrator: '<Root>/Integral' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( GyroscopeHinfinityController_X.Integral_CSTATE_c <=
            (GyroscopeHinfinityController_P.Integral_LowerSat_d) );
    usat = ( GyroscopeHinfinityController_X.Integral_CSTATE_c >=
            GyroscopeHinfinityController_P.Integral_UpperSat_m );
    if ((!lsat && !usat) ||
        (lsat && (GyroscopeHinfinityController_B.Gearratio > 0)) ||
        (usat && (GyroscopeHinfinityController_B.Gearratio < 0)) ) {
      ((XDot_GyroscopeHinfinityContro_T *)
        GyroscopeHinfinityController_M->ModelData.derivs)->Integral_CSTATE_c =
        GyroscopeHinfinityController_B.Gearratio;
    } else {
      /* in saturation */
      ((XDot_GyroscopeHinfinityContro_T *)
        GyroscopeHinfinityController_M->ModelData.derivs)->Integral_CSTATE_c =
        0.0;
    }
  }
}

/* Model initialize function */
void GyroscopeHinfinityController_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: GyroscopeHinfinityController/SRV02 Gyroscope/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0",
                      &GyroscopeHinfinityController_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (GyroscopeHinfinityController_DW.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal", 50);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (GyroscopeHinfinityController_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
      return;
    }

    if ((GyroscopeHinfinityController_P.HILInitialize_set_analog_input_ &&
         !is_switching) ||
        (GyroscopeHinfinityController_P.HILInitialize_set_analog_inpu_p &&
         is_switching)) {
      GyroscopeHinfinityController_DW.HILInitialize_AIMinimums[0] =
        GyroscopeHinfinityController_P.HILInitialize_analog_input_mini;
      GyroscopeHinfinityController_DW.HILInitialize_AIMinimums[1] =
        GyroscopeHinfinityController_P.HILInitialize_analog_input_mini;
      GyroscopeHinfinityController_DW.HILInitialize_AIMaximums[0] =
        GyroscopeHinfinityController_P.HILInitialize_analog_input_maxi;
      GyroscopeHinfinityController_DW.HILInitialize_AIMaximums[1] =
        GyroscopeHinfinityController_P.HILInitialize_analog_input_maxi;
      result = hil_set_analog_input_ranges
        (GyroscopeHinfinityController_DW.HILInitialize_Card,
         GyroscopeHinfinityController_P.HILInitialize_analog_input_chan, 2U,
         &GyroscopeHinfinityController_DW.HILInitialize_AIMinimums[0],
         &GyroscopeHinfinityController_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
        return;
      }
    }

    if ((GyroscopeHinfinityController_P.HILInitialize_set_analog_output &&
         !is_switching) ||
        (GyroscopeHinfinityController_P.HILInitialize_set_analog_outp_j &&
         is_switching)) {
      GyroscopeHinfinityController_DW.HILInitialize_AOMinimums[0] =
        GyroscopeHinfinityController_P.HILInitialize_analog_output_min;
      GyroscopeHinfinityController_DW.HILInitialize_AOMinimums[1] =
        GyroscopeHinfinityController_P.HILInitialize_analog_output_min;
      GyroscopeHinfinityController_DW.HILInitialize_AOMaximums[0] =
        GyroscopeHinfinityController_P.HILInitialize_analog_output_max;
      GyroscopeHinfinityController_DW.HILInitialize_AOMaximums[1] =
        GyroscopeHinfinityController_P.HILInitialize_analog_output_max;
      result = hil_set_analog_output_ranges
        (GyroscopeHinfinityController_DW.HILInitialize_Card,
         GyroscopeHinfinityController_P.HILInitialize_analog_output_cha, 2U,
         &GyroscopeHinfinityController_DW.HILInitialize_AOMinimums[0],
         &GyroscopeHinfinityController_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
        return;
      }
    }

    if ((GyroscopeHinfinityController_P.HILInitialize_set_analog_outp_h &&
         !is_switching) ||
        (GyroscopeHinfinityController_P.HILInitialize_set_analog_outp_i &&
         is_switching)) {
      GyroscopeHinfinityController_DW.HILInitialize_AOVoltages[0] =
        GyroscopeHinfinityController_P.HILInitialize_initial_analog_ou;
      GyroscopeHinfinityController_DW.HILInitialize_AOVoltages[1] =
        GyroscopeHinfinityController_P.HILInitialize_initial_analog_ou;
      result = hil_write_analog
        (GyroscopeHinfinityController_DW.HILInitialize_Card,
         GyroscopeHinfinityController_P.HILInitialize_analog_output_cha, 2U,
         &GyroscopeHinfinityController_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
        return;
      }
    }

    if (GyroscopeHinfinityController_P.HILInitialize_set_analog_outp_o) {
      GyroscopeHinfinityController_DW.HILInitialize_AOVoltages[0] =
        GyroscopeHinfinityController_P.HILInitialize_watchdog_analog_o;
      GyroscopeHinfinityController_DW.HILInitialize_AOVoltages[1] =
        GyroscopeHinfinityController_P.HILInitialize_watchdog_analog_o;
      result = hil_watchdog_set_analog_expiration_state
        (GyroscopeHinfinityController_DW.HILInitialize_Card,
         GyroscopeHinfinityController_P.HILInitialize_analog_output_cha, 2U,
         &GyroscopeHinfinityController_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (GyroscopeHinfinityController_DW.HILInitialize_Card, NULL, 0U,
       GyroscopeHinfinityController_P.HILInitialize_digital_output_ch, 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
      return;
    }

    if ((GyroscopeHinfinityController_P.HILInitialize_set_digital_out_e &&
         !is_switching) ||
        (GyroscopeHinfinityController_P.HILInitialize_set_digital_out_f &&
         is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits =
          &GyroscopeHinfinityController_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] =
            GyroscopeHinfinityController_P.HILInitialize_initial_digital_o;
        }
      }

      result = hil_write_digital
        (GyroscopeHinfinityController_DW.HILInitialize_Card,
         GyroscopeHinfinityController_P.HILInitialize_digital_output_ch, 8U,
         (t_boolean *) &GyroscopeHinfinityController_DW.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
        return;
      }
    }

    if (GyroscopeHinfinityController_P.HILInitialize_set_digital_out_o) {
      {
        int_T i1;
        int32_T *dw_DOStates =
          &GyroscopeHinfinityController_DW.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] =
            GyroscopeHinfinityController_P.HILInitialize_watchdog_digital_;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (GyroscopeHinfinityController_DW.HILInitialize_Card,
         GyroscopeHinfinityController_P.HILInitialize_digital_output_ch, 8U, (
          const t_digital_state *)
         &GyroscopeHinfinityController_DW.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
        return;
      }
    }

    if ((GyroscopeHinfinityController_P.HILInitialize_set_encoder_param &&
         !is_switching) ||
        (GyroscopeHinfinityController_P.HILInitialize_set_encoder_par_g &&
         is_switching)) {
      GyroscopeHinfinityController_DW.HILInitialize_QuadratureModes[0] =
        GyroscopeHinfinityController_P.HILInitialize_quadrature;
      GyroscopeHinfinityController_DW.HILInitialize_QuadratureModes[1] =
        GyroscopeHinfinityController_P.HILInitialize_quadrature;
      result = hil_set_encoder_quadrature_mode
        (GyroscopeHinfinityController_DW.HILInitialize_Card,
         GyroscopeHinfinityController_P.HILInitialize_encoder_channels, 2U,
         (t_encoder_quadrature_mode *)
         &GyroscopeHinfinityController_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
        return;
      }
    }

    if ((GyroscopeHinfinityController_P.HILInitialize_set_encoder_count &&
         !is_switching) ||
        (GyroscopeHinfinityController_P.HILInitialize_set_encoder_cou_a &&
         is_switching)) {
      GyroscopeHinfinityController_DW.HILInitialize_InitialEICounts[0] =
        GyroscopeHinfinityController_P.HILInitialize_initial_encoder_c;
      GyroscopeHinfinityController_DW.HILInitialize_InitialEICounts[1] =
        GyroscopeHinfinityController_P.HILInitialize_initial_encoder_c;
      result = hil_set_encoder_counts
        (GyroscopeHinfinityController_DW.HILInitialize_Card,
         GyroscopeHinfinityController_P.HILInitialize_encoder_channels, 2U,
         &GyroscopeHinfinityController_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Integrator: '<S2>/Integral' */
  GyroscopeHinfinityController_X.Integral_CSTATE =
    GyroscopeHinfinityController_P.Integral_IC;

  /* InitializeConditions for StateSpace: '<Root>/H-infinity Controller' */
  GyroscopeHinfinityController_X.HinfinityController_CSTATE[0] =
    GyroscopeHinfinityController_P.HinfinityController_X0;
  GyroscopeHinfinityController_X.HinfinityController_CSTATE[1] =
    GyroscopeHinfinityController_P.HinfinityController_X0;
  GyroscopeHinfinityController_X.HinfinityController_CSTATE[2] =
    GyroscopeHinfinityController_P.HinfinityController_X0;

  /* InitializeConditions for Integrator: '<Root>/Integral' */
  GyroscopeHinfinityController_X.Integral_CSTATE_c =
    GyroscopeHinfinityController_P.Integral_IC_k;
}

/* Model terminate function */
void GyroscopeHinfinityController_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S3>/HIL Initialize' */

  /* S-Function Block: GyroscopeHinfinityController/SRV02 Gyroscope/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    hil_task_stop_all(GyroscopeHinfinityController_DW.HILInitialize_Card);
    hil_monitor_stop_all(GyroscopeHinfinityController_DW.HILInitialize_Card);
    is_switching = false;
    if ((GyroscopeHinfinityController_P.HILInitialize_set_analog_outp_b &&
         !is_switching) ||
        (GyroscopeHinfinityController_P.HILInitialize_set_analog_outp_k &&
         is_switching)) {
      GyroscopeHinfinityController_DW.HILInitialize_AOVoltages[0] =
        GyroscopeHinfinityController_P.HILInitialize_final_analog_outp;
      GyroscopeHinfinityController_DW.HILInitialize_AOVoltages[1] =
        GyroscopeHinfinityController_P.HILInitialize_final_analog_outp;
      num_final_analog_outputs = 2U;
    }

    if ((GyroscopeHinfinityController_P.HILInitialize_set_digital_out_j &&
         !is_switching) ||
        (GyroscopeHinfinityController_P.HILInitialize_set_digital_out_i &&
         is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits =
          &GyroscopeHinfinityController_DW.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] =
            GyroscopeHinfinityController_P.HILInitialize_final_digital_out;
        }
      }

      num_final_digital_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(GyroscopeHinfinityController_DW.HILInitialize_Card
                         ,
                         GyroscopeHinfinityController_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , NULL, 0
                         ,
                         GyroscopeHinfinityController_P.HILInitialize_digital_output_ch,
                         num_final_digital_outputs
                         , NULL, 0
                         ,
                         &GyroscopeHinfinityController_DW.HILInitialize_AOVoltages
                         [0]
                         , NULL
                         , (t_boolean *)
                         &GyroscopeHinfinityController_DW.HILInitialize_DOBits[0]
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (GyroscopeHinfinityController_DW.HILInitialize_Card,
             GyroscopeHinfinityController_P.HILInitialize_analog_output_cha,
             num_final_analog_outputs,
             &GyroscopeHinfinityController_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (GyroscopeHinfinityController_DW.HILInitialize_Card,
             GyroscopeHinfinityController_P.HILInitialize_digital_output_ch,
             num_final_digital_outputs, (t_boolean *)
             &GyroscopeHinfinityController_DW.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(GyroscopeHinfinityController_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(GyroscopeHinfinityController_DW.HILInitialize_Card);
    hil_monitor_delete_all(GyroscopeHinfinityController_DW.HILInitialize_Card);
    hil_close(GyroscopeHinfinityController_DW.HILInitialize_Card);
    GyroscopeHinfinityController_DW.HILInitialize_Card = NULL;
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
  GyroscopeHinfinityController_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  GyroscopeHinfinityController_update();
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
  GyroscopeHinfinityController_initialize();
}

void MdlTerminate(void)
{
  GyroscopeHinfinityController_terminate();
}

/* Registration function */
RT_MODEL_GyroscopeHinfinityCo_T *GyroscopeHinfinityController(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)GyroscopeHinfinityController_M, 0,
                sizeof(RT_MODEL_GyroscopeHinfinityCo_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&GyroscopeHinfinityController_M->solverInfo,
                          &GyroscopeHinfinityController_M->Timing.simTimeStep);
    rtsiSetTPtr(&GyroscopeHinfinityController_M->solverInfo, &rtmGetTPtr
                (GyroscopeHinfinityController_M));
    rtsiSetStepSizePtr(&GyroscopeHinfinityController_M->solverInfo,
                       &GyroscopeHinfinityController_M->Timing.stepSize0);
    rtsiSetdXPtr(&GyroscopeHinfinityController_M->solverInfo,
                 &GyroscopeHinfinityController_M->ModelData.derivs);
    rtsiSetContStatesPtr(&GyroscopeHinfinityController_M->solverInfo, (real_T **)
                         &GyroscopeHinfinityController_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&GyroscopeHinfinityController_M->solverInfo,
      &GyroscopeHinfinityController_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&GyroscopeHinfinityController_M->solverInfo,
                          (&rtmGetErrorStatus(GyroscopeHinfinityController_M)));
    rtsiSetRTModelPtr(&GyroscopeHinfinityController_M->solverInfo,
                      GyroscopeHinfinityController_M);
  }

  rtsiSetSimTimeStep(&GyroscopeHinfinityController_M->solverInfo,
                     MAJOR_TIME_STEP);
  GyroscopeHinfinityController_M->ModelData.intgData.f[0] =
    GyroscopeHinfinityController_M->ModelData.odeF[0];
  GyroscopeHinfinityController_M->ModelData.contStates = ((real_T *)
    &GyroscopeHinfinityController_X);
  rtsiSetSolverData(&GyroscopeHinfinityController_M->solverInfo, (void *)
                    &GyroscopeHinfinityController_M->ModelData.intgData);
  rtsiSetSolverName(&GyroscopeHinfinityController_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      GyroscopeHinfinityController_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    GyroscopeHinfinityController_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    GyroscopeHinfinityController_M->Timing.sampleTimes =
      (&GyroscopeHinfinityController_M->Timing.sampleTimesArray[0]);
    GyroscopeHinfinityController_M->Timing.offsetTimes =
      (&GyroscopeHinfinityController_M->Timing.offsetTimesArray[0]);

    /* task periods */
    GyroscopeHinfinityController_M->Timing.sampleTimes[0] = (0.0);
    GyroscopeHinfinityController_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    GyroscopeHinfinityController_M->Timing.offsetTimes[0] = (0.0);
    GyroscopeHinfinityController_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(GyroscopeHinfinityController_M,
             &GyroscopeHinfinityController_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = GyroscopeHinfinityController_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    GyroscopeHinfinityController_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(GyroscopeHinfinityController_M, -1);
  GyroscopeHinfinityController_M->Timing.stepSize0 = 0.002;
  GyroscopeHinfinityController_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  GyroscopeHinfinityController_M->Sizes.checksums[0] = (1107365244U);
  GyroscopeHinfinityController_M->Sizes.checksums[1] = (2617485010U);
  GyroscopeHinfinityController_M->Sizes.checksums[2] = (594206533U);
  GyroscopeHinfinityController_M->Sizes.checksums[3] = (681851005U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    GyroscopeHinfinityController_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(GyroscopeHinfinityController_M->extModeInfo,
      &GyroscopeHinfinityController_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(GyroscopeHinfinityController_M->extModeInfo,
                        GyroscopeHinfinityController_M->Sizes.checksums);
    rteiSetTPtr(GyroscopeHinfinityController_M->extModeInfo, rtmGetTPtr
                (GyroscopeHinfinityController_M));
  }

  GyroscopeHinfinityController_M->solverInfoPtr =
    (&GyroscopeHinfinityController_M->solverInfo);
  GyroscopeHinfinityController_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&GyroscopeHinfinityController_M->solverInfo, 0.002);
  rtsiSetSolverMode(&GyroscopeHinfinityController_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  GyroscopeHinfinityController_M->ModelData.blockIO = ((void *)
    &GyroscopeHinfinityController_B);

  {
    GyroscopeHinfinityController_B.HILReadEncoder_o1 = 0.0;
    GyroscopeHinfinityController_B.HILReadEncoder_o2 = 0.0;
    GyroscopeHinfinityController_B.GYROEcountstorad = 0.0;
    GyroscopeHinfinityController_B.Gearratio = 0.0;
    GyroscopeHinfinityController_B.NegFeedback = 0.0;
    GyroscopeHinfinityController_B.ProportionalGain = 0.0;
    GyroscopeHinfinityController_B.Integral = 0.0;
    GyroscopeHinfinityController_B.HinfinityController = 0.0;
    GyroscopeHinfinityController_B.ManualSwitch = 0.0;
    GyroscopeHinfinityController_B.DirectionConventionRightHandsys = 0.0;
    GyroscopeHinfinityController_B.AmplifierSaturationV = 0.0;
    GyroscopeHinfinityController_B.InverseAmplifierGainVV = 0.0;
    GyroscopeHinfinityController_B.DACBSaturationV = 0.0;
    GyroscopeHinfinityController_B.AmplifierGainVV = 0.0;
    GyroscopeHinfinityController_B.SRV02countstorad = 0.0;
    GyroscopeHinfinityController_B.Gain = 0.0;
    GyroscopeHinfinityController_B.Gain_i = 0.0;
    GyroscopeHinfinityController_B.Integral_n = 0.0;
    GyroscopeHinfinityController_B.NegativeFeedback = 0.0;
    GyroscopeHinfinityController_B.IntegralGain = 0.0;
    GyroscopeHinfinityController_B.Add = 0.0;
  }

  /* parameters */
  GyroscopeHinfinityController_M->ModelData.defaultParam = ((real_T *)
    &GyroscopeHinfinityController_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &GyroscopeHinfinityController_X;
    GyroscopeHinfinityController_M->ModelData.contStates = (x);
    (void) memset((void *)&GyroscopeHinfinityController_X, 0,
                  sizeof(X_GyroscopeHinfinityControlle_T));
  }

  /* states (dwork) */
  GyroscopeHinfinityController_M->ModelData.dwork = ((void *)
    &GyroscopeHinfinityController_DW);
  (void) memset((void *)&GyroscopeHinfinityController_DW, 0,
                sizeof(DW_GyroscopeHinfinityControll_T));
  GyroscopeHinfinityController_DW.HILInitialize_AIMinimums[0] = 0.0;
  GyroscopeHinfinityController_DW.HILInitialize_AIMinimums[1] = 0.0;
  GyroscopeHinfinityController_DW.HILInitialize_AIMaximums[0] = 0.0;
  GyroscopeHinfinityController_DW.HILInitialize_AIMaximums[1] = 0.0;
  GyroscopeHinfinityController_DW.HILInitialize_AOMinimums[0] = 0.0;
  GyroscopeHinfinityController_DW.HILInitialize_AOMinimums[1] = 0.0;
  GyroscopeHinfinityController_DW.HILInitialize_AOMaximums[0] = 0.0;
  GyroscopeHinfinityController_DW.HILInitialize_AOMaximums[1] = 0.0;
  GyroscopeHinfinityController_DW.HILInitialize_AOVoltages[0] = 0.0;
  GyroscopeHinfinityController_DW.HILInitialize_AOVoltages[1] = 0.0;
  GyroscopeHinfinityController_DW.HILInitialize_FilterFrequency[0] = 0.0;
  GyroscopeHinfinityController_DW.HILInitialize_FilterFrequency[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    GyroscopeHinfinityController_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  GyroscopeHinfinityController_M->Sizes.numContStates = (5);/* Number of continuous states */
  GyroscopeHinfinityController_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  GyroscopeHinfinityController_M->Sizes.numY = (0);/* Number of model outputs */
  GyroscopeHinfinityController_M->Sizes.numU = (0);/* Number of model inputs */
  GyroscopeHinfinityController_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  GyroscopeHinfinityController_M->Sizes.numSampTimes = (2);/* Number of sample times */
  GyroscopeHinfinityController_M->Sizes.numBlocks = (28);/* Number of blocks */
  GyroscopeHinfinityController_M->Sizes.numBlockIO = (21);/* Number of block outputs */
  GyroscopeHinfinityController_M->Sizes.numBlockPrms = (124);/* Sum of parameter "widths" */
  return GyroscopeHinfinityController_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
