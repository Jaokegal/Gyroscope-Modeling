/*
 * GyroscopeHinfinityController.h
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

#ifndef RTW_HEADER_GyroscopeHinfinityController_h_
#define RTW_HEADER_GyroscopeHinfinityController_h_
#include <string.h>
#ifndef GyroscopeHinfinityController_COMMON_INCLUDES_
# define GyroscopeHinfinityController_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_extern.h"
#endif                                 /* GyroscopeHinfinityController_COMMON_INCLUDES_ */

#include "GyroscopeHinfinityController_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define GyroscopeHinfinityController_rtModel RT_MODEL_GyroscopeHinfinityCo_T

/* Block signals (auto storage) */
typedef struct {
  real_T HILReadEncoder_o1;            /* '<S3>/HIL Read Encoder' */
  real_T HILReadEncoder_o2;            /* '<S3>/HIL Read Encoder' */
  real_T GYROEcountstorad;             /* '<S3>/GYRO-E: counts to rad' */
  real_T Gearratio;                    /* '<S3>/Gear ratio' */
  real_T NegFeedback;                  /* '<S2>/Neg. Feedback' */
  real_T ProportionalGain;             /* '<S2>/Proportional Gain' */
  real_T Integral;                     /* '<S2>/Integral' */
  real_T HinfinityController;          /* '<Root>/H-infinity Controller' */
  real_T ManualSwitch;                 /* '<Root>/Manual Switch' */
  real_T DirectionConventionRightHandsys;/* '<S5>/Direction Convention: (Right-Hand) system' */
  real_T AmplifierSaturationV;         /* '<S5>/Amplifier  Saturation (V)' */
  real_T InverseAmplifierGainVV;       /* '<S5>/Inverse Amplifier  Gain (V//V)' */
  real_T DACBSaturationV;              /* '<S5>/DACB Saturation (V)' */
  real_T AmplifierGainVV;              /* '<S5>/Amplifier  Gain (V//V)' */
  real_T SRV02countstorad;             /* '<S3>/SRV02: counts to rad' */
  real_T Gain;                         /* '<S1>/Gain' */
  real_T Gain_i;                       /* '<S4>/Gain' */
  real_T Integral_n;                   /* '<Root>/Integral' */
  real_T NegativeFeedback;             /* '<S2>/Negative Feedback' */
  real_T IntegralGain;                 /* '<S2>/Integral Gain' */
  real_T Add;                          /* '<S2>/Add' */
} B_GyroscopeHinfinityControlle_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_AIMinimums[2];  /* '<S3>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[2];  /* '<S3>/HIL Initialize' */
  real_T HILInitialize_AOMinimums[2];  /* '<S3>/HIL Initialize' */
  real_T HILInitialize_AOMaximums[2];  /* '<S3>/HIL Initialize' */
  real_T HILInitialize_AOVoltages[2];  /* '<S3>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[2];/* '<S3>/HIL Initialize' */
  t_card HILInitialize_Card;           /* '<S3>/HIL Initialize' */
  void *HILReadEncoder_PWORK;          /* '<S3>/HIL Read Encoder' */
  void *HILWriteAnalog_PWORK;          /* '<S3>/HIL Write Analog' */
  void *HILWriteDigital_PWORK;         /* '<S3>/HIL Write Digital' */
  struct {
    void *LoggedData;
  } Betadeg_PWORK;                     /* '<Root>/Beta (deg)' */

  struct {
    void *LoggedData;
  } VmV_PWORK;                         /* '<Root>/Vm (V)' */

  struct {
    void *LoggedData;
  } theta_ldeg_PWORK;                  /* '<Root>/theta_l (deg)' */

  int32_T HILInitialize_ClockModes[3]; /* '<S3>/HIL Initialize' */
  int32_T HILInitialize_DOStates[8];   /* '<S3>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[2];/* '<S3>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[2];/* '<S3>/HIL Initialize' */
  int32_T HILReadEncoder_Buffer[2];    /* '<S3>/HIL Read Encoder' */
  boolean_T HILInitialize_DOBits[8];   /* '<S3>/HIL Initialize' */
  t_boolean HILWriteDigital_Buffer[4]; /* '<S3>/HIL Write Digital' */
} DW_GyroscopeHinfinityControll_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integral_CSTATE;              /* '<S2>/Integral' */
  real_T HinfinityController_CSTATE[3];/* '<Root>/H-infinity Controller' */
  real_T Integral_CSTATE_c;            /* '<Root>/Integral' */
} X_GyroscopeHinfinityControlle_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integral_CSTATE;              /* '<S2>/Integral' */
  real_T HinfinityController_CSTATE[3];/* '<Root>/H-infinity Controller' */
  real_T Integral_CSTATE_c;            /* '<Root>/Integral' */
} XDot_GyroscopeHinfinityContro_T;

/* State disabled  */
typedef struct {
  boolean_T Integral_CSTATE;           /* '<S2>/Integral' */
  boolean_T HinfinityController_CSTATE[3];/* '<Root>/H-infinity Controller' */
  boolean_T Integral_CSTATE_c;         /* '<Root>/Integral' */
} XDis_GyroscopeHinfinityContro_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            GyroscopeHinfinityController_B
#define BlockIO                        B_GyroscopeHinfinityControlle_T
#define rtX                            GyroscopeHinfinityController_X
#define ContinuousStates               X_GyroscopeHinfinityControlle_T
#define rtXdot                         GyroscopeHinfinityControll_XDot
#define StateDerivatives               XDot_GyroscopeHinfinityContro_T
#define tXdis                          GyroscopeHinfinityControll_XDis
#define StateDisabled                  XDis_GyroscopeHinfinityContro_T
#define rtP                            GyroscopeHinfinityController_P
#define Parameters                     P_GyroscopeHinfinityControlle_T
#define rtDWork                        GyroscopeHinfinityController_DW
#define D_Work                         DW_GyroscopeHinfinityControll_T

/* Parameters (auto storage) */
struct P_GyroscopeHinfinityControlle_T_ {
  real_T ac[9];                        /* Variable: ac
                                        * Referenced by: '<Root>/H-infinity Controller'
                                        */
  real_T bc[3];                        /* Variable: bc
                                        * Referenced by: '<Root>/H-infinity Controller'
                                        */
  real_T cc[3];                        /* Variable: cc
                                        * Referenced by: '<Root>/H-infinity Controller'
                                        */
  real_T HILInitialize_analog_input_maxi;/* Mask Parameter: HILInitialize_analog_input_maxi
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_analog_input_mini;/* Mask Parameter: HILInitialize_analog_input_mini
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_analog_output_max;/* Mask Parameter: HILInitialize_analog_output_max
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_analog_output_min;/* Mask Parameter: HILInitialize_analog_output_min
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_final_analog_outp;/* Mask Parameter: HILInitialize_final_analog_outp
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_final_pwm_outputs;/* Mask Parameter: HILInitialize_final_pwm_outputs
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_initial_analog_ou;/* Mask Parameter: HILInitialize_initial_analog_ou
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_initial_pwm_outpu;/* Mask Parameter: HILInitialize_initial_pwm_outpu
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_pwm_frequency;  /* Mask Parameter: HILInitialize_pwm_frequency
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  real_T HILInitialize_set_other_outputs;/* Mask Parameter: HILInitialize_set_other_outputs
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_n;/* Mask Parameter: HILInitialize_set_other_outpu_n
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_o;/* Mask Parameter: HILInitialize_set_other_outpu_o
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_set_other_outpu_f;/* Mask Parameter: HILInitialize_set_other_outpu_f
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_watchdog_analog_o;/* Mask Parameter: HILInitialize_watchdog_analog_o
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  real_T HILInitialize_watchdog_pwm_outp;/* Mask Parameter: HILInitialize_watchdog_pwm_outp
                                          * Referenced by: '<S3>/HIL Initialize'
                                          */
  int32_T HILInitialize_hardware_clocks[3];/* Mask Parameter: HILInitialize_hardware_clocks
                                            * Referenced by: '<S3>/HIL Initialize'
                                            */
  int32_T HILInitialize_initial_encoder_c;/* Mask Parameter: HILInitialize_initial_encoder_c
                                           * Referenced by: '<S3>/HIL Initialize'
                                           */
  int32_T HILInitialize_pwm_modes;     /* Mask Parameter: HILInitialize_pwm_modes
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  int32_T HILInitialize_watchdog_digital_;/* Mask Parameter: HILInitialize_watchdog_digital_
                                           * Referenced by: '<S3>/HIL Initialize'
                                           */
  uint32_T HILInitialize_analog_input_chan[2];/* Mask Parameter: HILInitialize_analog_input_chan
                                               * Referenced by: '<S3>/HIL Initialize'
                                               */
  uint32_T HILInitialize_analog_output_cha[2];/* Mask Parameter: HILInitialize_analog_output_cha
                                               * Referenced by: '<S3>/HIL Initialize'
                                               */
  uint32_T HILReadEncoder_channels[2]; /* Mask Parameter: HILReadEncoder_channels
                                        * Referenced by: '<S3>/HIL Read Encoder'
                                        */
  uint32_T HILWriteAnalog_channels;    /* Mask Parameter: HILWriteAnalog_channels
                                        * Referenced by: '<S3>/HIL Write Analog'
                                        */
  uint32_T HILWriteDigital_channels[4];/* Mask Parameter: HILWriteDigital_channels
                                        * Referenced by: '<S3>/HIL Write Digital'
                                        */
  uint32_T HILInitialize_digital_output_ch[8];/* Mask Parameter: HILInitialize_digital_output_ch
                                               * Referenced by: '<S3>/HIL Initialize'
                                               */
  uint32_T HILInitialize_encoder_channels[2];/* Mask Parameter: HILInitialize_encoder_channels
                                              * Referenced by: '<S3>/HIL Initialize'
                                              */
  uint32_T HILInitialize_quadrature;   /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  boolean_T HILInitialize_active;      /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<S3>/HIL Initialize'
                                        */
  boolean_T HILInitialize_final_digital_out;/* Mask Parameter: HILInitialize_final_digital_out
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_initial_digital_o;/* Mask Parameter: HILInitialize_initial_digital_o
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_input_;/* Mask Parameter: HILInitialize_set_analog_input_
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_inpu_p;/* Mask Parameter: HILInitialize_set_analog_inpu_p
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_output;/* Mask Parameter: HILInitialize_set_analog_output
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_j;/* Mask Parameter: HILInitialize_set_analog_outp_j
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_h;/* Mask Parameter: HILInitialize_set_analog_outp_h
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_i;/* Mask Parameter: HILInitialize_set_analog_outp_i
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_k;/* Mask Parameter: HILInitialize_set_analog_outp_k
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_b;/* Mask Parameter: HILInitialize_set_analog_outp_b
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_analog_outp_o;/* Mask Parameter: HILInitialize_set_analog_outp_o
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequen;/* Mask Parameter: HILInitialize_set_clock_frequen
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_frequ_f;/* Mask Parameter: HILInitialize_set_clock_frequ_f
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_params_;/* Mask Parameter: HILInitialize_set_clock_params_
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_clock_param_a;/* Mask Parameter: HILInitialize_set_clock_param_a
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_outpu;/* Mask Parameter: HILInitialize_set_digital_outpu
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_h;/* Mask Parameter: HILInitialize_set_digital_out_h
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_e;/* Mask Parameter: HILInitialize_set_digital_out_e
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_f;/* Mask Parameter: HILInitialize_set_digital_out_f
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_i;/* Mask Parameter: HILInitialize_set_digital_out_i
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_j;/* Mask Parameter: HILInitialize_set_digital_out_j
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_digital_out_o;/* Mask Parameter: HILInitialize_set_digital_out_o
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_count;/* Mask Parameter: HILInitialize_set_encoder_count
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_cou_a;/* Mask Parameter: HILInitialize_set_encoder_cou_a
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_param;/* Mask Parameter: HILInitialize_set_encoder_param
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_encoder_par_g;/* Mask Parameter: HILInitialize_set_encoder_par_g
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_other_outpu_i;/* Mask Parameter: HILInitialize_set_other_outpu_i
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_a;/* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_p;/* Mask Parameter: HILInitialize_set_pwm_outputs_p
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_i;/* Mask Parameter: HILInitialize_set_pwm_outputs_i
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_g;/* Mask Parameter: HILInitialize_set_pwm_outputs_g
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_outputs_o;/* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params_at;/* Mask Parameter: HILInitialize_set_pwm_params_at
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  boolean_T HILInitialize_set_pwm_params__i;/* Mask Parameter: HILInitialize_set_pwm_params__i
                                             * Referenced by: '<S3>/HIL Initialize'
                                             */
  real_T NegativeFeedback_Gain;        /* Expression: -1
                                        * Referenced by: '<S2>/Negative Feedback'
                                        */
  real_T IntegralGain_Gain;            /* Expression: 149.9188
                                        * Referenced by: '<S2>/Integral Gain'
                                        */
  real_T GYROEcountstorad_Gain;        /* Expression: 2*pi/4096
                                        * Referenced by: '<S3>/GYRO-E: counts to rad'
                                        */
  real_T Gearratio_Gain;               /* Expression: 1/4
                                        * Referenced by: '<S3>/Gear ratio'
                                        */
  real_T NegFeedback_Gain;             /* Expression: -1
                                        * Referenced by: '<S2>/Neg. Feedback'
                                        */
  real_T ProportionalGain_Gain;        /* Expression: 4.5828
                                        * Referenced by: '<S2>/Proportional Gain'
                                        */
  real_T Integral_IC;                  /* Expression: 0
                                        * Referenced by: '<S2>/Integral'
                                        */
  real_T Integral_UpperSat;            /* Expression: 5*pi/180
                                        * Referenced by: '<S2>/Integral'
                                        */
  real_T Integral_LowerSat;            /* Expression: -5*pi/180
                                        * Referenced by: '<S2>/Integral'
                                        */
  real_T HinfinityController_X0;       /* Expression: 0
                                        * Referenced by: '<Root>/H-infinity Controller'
                                        */
  real_T DirectionConventionRightHandsys;/* Expression: -1
                                          * Referenced by: '<S5>/Direction Convention: (Right-Hand) system'
                                          */
  real_T AmplifierSaturationV_UpperSat;/* Expression: 10
                                        * Referenced by: '<S5>/Amplifier  Saturation (V)'
                                        */
  real_T AmplifierSaturationV_LowerSat;/* Expression: -10
                                        * Referenced by: '<S5>/Amplifier  Saturation (V)'
                                        */
  real_T InverseAmplifierGainVV_Gain;  /* Expression: 1
                                        * Referenced by: '<S5>/Inverse Amplifier  Gain (V//V)'
                                        */
  real_T DACBSaturationV_UpperSat;     /* Expression: 10
                                        * Referenced by: '<S5>/DACB Saturation (V)'
                                        */
  real_T DACBSaturationV_LowerSat;     /* Expression: -10
                                        * Referenced by: '<S5>/DACB Saturation (V)'
                                        */
  real_T AmplifierGainVV_Gain;         /* Expression: -1
                                        * Referenced by: '<S5>/Amplifier  Gain (V//V)'
                                        */
  real_T SRV02countstorad_Gain;        /* Expression: -2*pi/4096
                                        * Referenced by: '<S3>/SRV02: counts to rad'
                                        */
  real_T EnableVoltPAQX2X4_Value[4];   /* Expression: [1 1 1 1]
                                        * Referenced by: '<S3>/Enable VoltPAQ-X2,X4'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 180/pi
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Integral_IC_k;                /* Expression: 0
                                        * Referenced by: '<Root>/Integral'
                                        */
  real_T Integral_UpperSat_m;          /* Expression: 5*pi/180
                                        * Referenced by: '<Root>/Integral'
                                        */
  real_T Integral_LowerSat_d;          /* Expression: -5*pi/180
                                        * Referenced by: '<Root>/Integral'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  boolean_T HILReadEncoder_Active;     /* Computed Parameter: HILReadEncoder_Active
                                        * Referenced by: '<S3>/HIL Read Encoder'
                                        */
  boolean_T HILWriteAnalog_Active;     /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S3>/HIL Write Analog'
                                        */
  boolean_T HILWriteDigital_Active;    /* Computed Parameter: HILWriteDigital_Active
                                        * Referenced by: '<S3>/HIL Write Digital'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_GyroscopeHinfinityCon_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][5];
    ODE1_IntgData intgData;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_GyroscopeHinfinityControlle_T GyroscopeHinfinityController_P;

/* Block signals (auto storage) */
extern B_GyroscopeHinfinityControlle_T GyroscopeHinfinityController_B;

/* Continuous states (auto storage) */
extern X_GyroscopeHinfinityControlle_T GyroscopeHinfinityController_X;

/* Block states (auto storage) */
extern DW_GyroscopeHinfinityControll_T GyroscopeHinfinityController_DW;

/* Model entry point functions */
extern void GyroscopeHinfinityController_initialize(void);
extern void GyroscopeHinfinityController_output(void);
extern void GyroscopeHinfinityController_update(void);
extern void GyroscopeHinfinityController_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern GyroscopeHinfinityController_rtModel *GyroscopeHinfinityController(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_GyroscopeHinfinityCo_T *const GyroscopeHinfinityController_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'GyroscopeHinfinityController'
 * '<S1>'   : 'GyroscopeHinfinityController/Beta: rad to deg'
 * '<S2>'   : 'GyroscopeHinfinityController/PI controller'
 * '<S3>'   : 'GyroscopeHinfinityController/SRV02 Gyroscope'
 * '<S4>'   : 'GyroscopeHinfinityController/theta:  rad to deg'
 * '<S5>'   : 'GyroscopeHinfinityController/SRV02 Gyroscope/Actuator Dynamics'
 */
#endif                                 /* RTW_HEADER_GyroscopeHinfinityController_h_ */
