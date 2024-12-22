  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (GyroscopeHinfinityController_P)
    ;%
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% GyroscopeHinfinityController_P.ac
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GyroscopeHinfinityController_P.bc
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 9;
	
	  ;% GyroscopeHinfinityController_P.cc
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 12;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_analog_input_maxi
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 15;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_analog_input_mini
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 16;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_analog_output_max
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 17;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_analog_output_min
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 18;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_final_analog_outp
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 19;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_final_pwm_outputs
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 20;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_initial_analog_ou
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 21;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_initial_pwm_outpu
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 22;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_pwm_frequency
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 23;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_other_outputs
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 24;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_other_outpu_n
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 25;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_other_outpu_o
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 26;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_other_outpu_f
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 27;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_watchdog_analog_o
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 28;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_watchdog_pwm_outp
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 29;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% GyroscopeHinfinityController_P.HILInitialize_hardware_clocks
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_initial_encoder_c
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 3;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_pwm_modes
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 4;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_watchdog_digital_
	  section.data(4).logicalSrcIdx = 21;
	  section.data(4).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% GyroscopeHinfinityController_P.HILInitialize_analog_input_chan
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_analog_output_cha
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 2;
	
	  ;% GyroscopeHinfinityController_P.HILReadEncoder_channels
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 4;
	
	  ;% GyroscopeHinfinityController_P.HILWriteAnalog_channels
	  section.data(4).logicalSrcIdx = 25;
	  section.data(4).dtTransOffset = 6;
	
	  ;% GyroscopeHinfinityController_P.HILWriteDigital_channels
	  section.data(5).logicalSrcIdx = 26;
	  section.data(5).dtTransOffset = 7;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_digital_output_ch
	  section.data(6).logicalSrcIdx = 27;
	  section.data(6).dtTransOffset = 11;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_encoder_channels
	  section.data(7).logicalSrcIdx = 28;
	  section.data(7).dtTransOffset = 19;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_quadrature
	  section.data(8).logicalSrcIdx = 29;
	  section.data(8).dtTransOffset = 21;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% GyroscopeHinfinityController_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_final_digital_out
	  section.data(2).logicalSrcIdx = 31;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_initial_digital_o
	  section.data(3).logicalSrcIdx = 32;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_analog_input_
	  section.data(4).logicalSrcIdx = 33;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_analog_inpu_p
	  section.data(5).logicalSrcIdx = 34;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_analog_output
	  section.data(6).logicalSrcIdx = 35;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_analog_outp_j
	  section.data(7).logicalSrcIdx = 36;
	  section.data(7).dtTransOffset = 6;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_analog_outp_h
	  section.data(8).logicalSrcIdx = 37;
	  section.data(8).dtTransOffset = 7;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_analog_outp_i
	  section.data(9).logicalSrcIdx = 38;
	  section.data(9).dtTransOffset = 8;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_analog_outp_k
	  section.data(10).logicalSrcIdx = 39;
	  section.data(10).dtTransOffset = 9;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_analog_outp_b
	  section.data(11).logicalSrcIdx = 40;
	  section.data(11).dtTransOffset = 10;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_analog_outp_o
	  section.data(12).logicalSrcIdx = 41;
	  section.data(12).dtTransOffset = 11;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_clock_frequen
	  section.data(13).logicalSrcIdx = 42;
	  section.data(13).dtTransOffset = 12;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_clock_frequ_f
	  section.data(14).logicalSrcIdx = 43;
	  section.data(14).dtTransOffset = 13;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_clock_params_
	  section.data(15).logicalSrcIdx = 44;
	  section.data(15).dtTransOffset = 14;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_clock_param_a
	  section.data(16).logicalSrcIdx = 45;
	  section.data(16).dtTransOffset = 15;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_digital_outpu
	  section.data(17).logicalSrcIdx = 46;
	  section.data(17).dtTransOffset = 16;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_digital_out_h
	  section.data(18).logicalSrcIdx = 47;
	  section.data(18).dtTransOffset = 17;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_digital_out_e
	  section.data(19).logicalSrcIdx = 48;
	  section.data(19).dtTransOffset = 18;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_digital_out_f
	  section.data(20).logicalSrcIdx = 49;
	  section.data(20).dtTransOffset = 19;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_digital_out_i
	  section.data(21).logicalSrcIdx = 50;
	  section.data(21).dtTransOffset = 20;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_digital_out_j
	  section.data(22).logicalSrcIdx = 51;
	  section.data(22).dtTransOffset = 21;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_digital_out_o
	  section.data(23).logicalSrcIdx = 52;
	  section.data(23).dtTransOffset = 22;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_encoder_count
	  section.data(24).logicalSrcIdx = 53;
	  section.data(24).dtTransOffset = 23;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_encoder_cou_a
	  section.data(25).logicalSrcIdx = 54;
	  section.data(25).dtTransOffset = 24;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_encoder_param
	  section.data(26).logicalSrcIdx = 55;
	  section.data(26).dtTransOffset = 25;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_encoder_par_g
	  section.data(27).logicalSrcIdx = 56;
	  section.data(27).dtTransOffset = 26;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_other_outpu_i
	  section.data(28).logicalSrcIdx = 57;
	  section.data(28).dtTransOffset = 27;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_pwm_outputs_a
	  section.data(29).logicalSrcIdx = 58;
	  section.data(29).dtTransOffset = 28;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_pwm_outputs_p
	  section.data(30).logicalSrcIdx = 59;
	  section.data(30).dtTransOffset = 29;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_pwm_outputs_i
	  section.data(31).logicalSrcIdx = 60;
	  section.data(31).dtTransOffset = 30;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_pwm_outputs_g
	  section.data(32).logicalSrcIdx = 61;
	  section.data(32).dtTransOffset = 31;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_pwm_outputs_o
	  section.data(33).logicalSrcIdx = 62;
	  section.data(33).dtTransOffset = 32;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_pwm_params_at
	  section.data(34).logicalSrcIdx = 63;
	  section.data(34).dtTransOffset = 33;
	
	  ;% GyroscopeHinfinityController_P.HILInitialize_set_pwm_params__i
	  section.data(35).logicalSrcIdx = 64;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% GyroscopeHinfinityController_P.NegativeFeedback_Gain
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GyroscopeHinfinityController_P.IntegralGain_Gain
	  section.data(2).logicalSrcIdx = 66;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GyroscopeHinfinityController_P.GYROEcountstorad_Gain
	  section.data(3).logicalSrcIdx = 67;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GyroscopeHinfinityController_P.Gearratio_Gain
	  section.data(4).logicalSrcIdx = 68;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GyroscopeHinfinityController_P.NegFeedback_Gain
	  section.data(5).logicalSrcIdx = 69;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GyroscopeHinfinityController_P.ProportionalGain_Gain
	  section.data(6).logicalSrcIdx = 70;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GyroscopeHinfinityController_P.Integral_IC
	  section.data(7).logicalSrcIdx = 71;
	  section.data(7).dtTransOffset = 6;
	
	  ;% GyroscopeHinfinityController_P.Integral_UpperSat
	  section.data(8).logicalSrcIdx = 72;
	  section.data(8).dtTransOffset = 7;
	
	  ;% GyroscopeHinfinityController_P.Integral_LowerSat
	  section.data(9).logicalSrcIdx = 73;
	  section.data(9).dtTransOffset = 8;
	
	  ;% GyroscopeHinfinityController_P.HinfinityController_X0
	  section.data(10).logicalSrcIdx = 74;
	  section.data(10).dtTransOffset = 9;
	
	  ;% GyroscopeHinfinityController_P.DirectionConventionRightHandsys
	  section.data(11).logicalSrcIdx = 75;
	  section.data(11).dtTransOffset = 10;
	
	  ;% GyroscopeHinfinityController_P.AmplifierSaturationV_UpperSat
	  section.data(12).logicalSrcIdx = 76;
	  section.data(12).dtTransOffset = 11;
	
	  ;% GyroscopeHinfinityController_P.AmplifierSaturationV_LowerSat
	  section.data(13).logicalSrcIdx = 77;
	  section.data(13).dtTransOffset = 12;
	
	  ;% GyroscopeHinfinityController_P.InverseAmplifierGainVV_Gain
	  section.data(14).logicalSrcIdx = 78;
	  section.data(14).dtTransOffset = 13;
	
	  ;% GyroscopeHinfinityController_P.DACBSaturationV_UpperSat
	  section.data(15).logicalSrcIdx = 79;
	  section.data(15).dtTransOffset = 14;
	
	  ;% GyroscopeHinfinityController_P.DACBSaturationV_LowerSat
	  section.data(16).logicalSrcIdx = 80;
	  section.data(16).dtTransOffset = 15;
	
	  ;% GyroscopeHinfinityController_P.AmplifierGainVV_Gain
	  section.data(17).logicalSrcIdx = 81;
	  section.data(17).dtTransOffset = 16;
	
	  ;% GyroscopeHinfinityController_P.SRV02countstorad_Gain
	  section.data(18).logicalSrcIdx = 82;
	  section.data(18).dtTransOffset = 17;
	
	  ;% GyroscopeHinfinityController_P.EnableVoltPAQX2X4_Value
	  section.data(19).logicalSrcIdx = 83;
	  section.data(19).dtTransOffset = 18;
	
	  ;% GyroscopeHinfinityController_P.Gain_Gain
	  section.data(20).logicalSrcIdx = 84;
	  section.data(20).dtTransOffset = 22;
	
	  ;% GyroscopeHinfinityController_P.Gain_Gain_f
	  section.data(21).logicalSrcIdx = 85;
	  section.data(21).dtTransOffset = 23;
	
	  ;% GyroscopeHinfinityController_P.Integral_IC_k
	  section.data(22).logicalSrcIdx = 86;
	  section.data(22).dtTransOffset = 24;
	
	  ;% GyroscopeHinfinityController_P.Integral_UpperSat_m
	  section.data(23).logicalSrcIdx = 87;
	  section.data(23).dtTransOffset = 25;
	
	  ;% GyroscopeHinfinityController_P.Integral_LowerSat_d
	  section.data(24).logicalSrcIdx = 88;
	  section.data(24).dtTransOffset = 26;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GyroscopeHinfinityController_P.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 89;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% GyroscopeHinfinityController_P.HILReadEncoder_Active
	  section.data(1).logicalSrcIdx = 90;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GyroscopeHinfinityController_P.HILWriteAnalog_Active
	  section.data(2).logicalSrcIdx = 91;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GyroscopeHinfinityController_P.HILWriteDigital_Active
	  section.data(3).logicalSrcIdx = 92;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (GyroscopeHinfinityController_B)
    ;%
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% GyroscopeHinfinityController_B.HILReadEncoder_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GyroscopeHinfinityController_B.HILReadEncoder_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GyroscopeHinfinityController_B.GYROEcountstorad
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GyroscopeHinfinityController_B.Gearratio
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GyroscopeHinfinityController_B.NegFeedback
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GyroscopeHinfinityController_B.ProportionalGain
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GyroscopeHinfinityController_B.Integral
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% GyroscopeHinfinityController_B.HinfinityController
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% GyroscopeHinfinityController_B.ManualSwitch
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% GyroscopeHinfinityController_B.DirectionConventionRightHandsys
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% GyroscopeHinfinityController_B.AmplifierSaturationV
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% GyroscopeHinfinityController_B.InverseAmplifierGainVV
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% GyroscopeHinfinityController_B.DACBSaturationV
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% GyroscopeHinfinityController_B.AmplifierGainVV
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% GyroscopeHinfinityController_B.SRV02countstorad
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% GyroscopeHinfinityController_B.Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% GyroscopeHinfinityController_B.Gain_i
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% GyroscopeHinfinityController_B.Integral_n
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% GyroscopeHinfinityController_B.NegativeFeedback
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% GyroscopeHinfinityController_B.IntegralGain
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% GyroscopeHinfinityController_B.Add
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (GyroscopeHinfinityController_DW)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% GyroscopeHinfinityController_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GyroscopeHinfinityController_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% GyroscopeHinfinityController_DW.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 4;
	
	  ;% GyroscopeHinfinityController_DW.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
	  ;% GyroscopeHinfinityController_DW.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% GyroscopeHinfinityController_DW.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GyroscopeHinfinityController_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% GyroscopeHinfinityController_DW.HILReadEncoder_PWORK
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GyroscopeHinfinityController_DW.HILWriteAnalog_PWORK
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GyroscopeHinfinityController_DW.HILWriteDigital_PWORK
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GyroscopeHinfinityController_DW.Betadeg_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GyroscopeHinfinityController_DW.VmV_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GyroscopeHinfinityController_DW.theta_ldeg_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% GyroscopeHinfinityController_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GyroscopeHinfinityController_DW.HILInitialize_DOStates
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 3;
	
	  ;% GyroscopeHinfinityController_DW.HILInitialize_QuadratureModes
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 11;
	
	  ;% GyroscopeHinfinityController_DW.HILInitialize_InitialEICounts
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 13;
	
	  ;% GyroscopeHinfinityController_DW.HILReadEncoder_Buffer
	  section.data(5).logicalSrcIdx = 17;
	  section.data(5).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GyroscopeHinfinityController_DW.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GyroscopeHinfinityController_DW.HILWriteDigital_Buffer
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1107365244;
  targMap.checksum1 = 2617485010;
  targMap.checksum2 = 594206533;
  targMap.checksum3 = 681851005;

