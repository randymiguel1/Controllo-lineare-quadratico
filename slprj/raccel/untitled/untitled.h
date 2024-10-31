#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#ifndef untitled_COMMON_INCLUDES_
#define untitled_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "untitled_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME untitled
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (43) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (6)   
#elif NCSTATES != 6
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T o0exiazmut ; real_T kj3lusgpyv ; real_T cxnkqagze2 ;
real_T ab31ckmc1a ; real_T cyr5ludheo ; real_T jvb02h1oc5 ; real_T cme4xuiwky
[ 6 ] ; real_T po5onpuvn4 ; real_T jyfoeudl2q ; real_T gmvs3wwowg ; real_T
igk3ef1igr ; real_T hc5bjkc5kt ; real_T gdanjzyc2u ; real_T cw5yzcdmaq [ 2 ]
; real_T bnhtxjyxk2 ; real_T jliulylrzv ; real_T nnfeioattm ; real_T
o3r0s2aug2 ; real_T nzwjkbw5x3 ; real_T cyrxnsdt3w ; real_T byqiddisjh ;
real_T bjgyvns5gp ; real_T oioq1wpgc5 ; real_T nxmuuzho4k ; real_T dmbgltqa1p
; real_T ft5dvj2xy2 ; real_T d3hioucrij ; real_T oxxpdxdjrz ; real_T
dwpyxuko14 ; real_T dwx142rb5m ; real_T of0l4p5cfb ; real_T gjziua45oo ;
real_T oilazgswio ; real_T jhj1ql1k1k ; real_T j0e1xtukkh ; real_T cnpiutyf2u
; real_T jvcjbj1a5l ; real_T mgqe2jsh0w ; real_T dbzgnveifb ; real_T
gvaowacf1r ; real_T obdgflwa5b ; real_T jbeqg1clca ; real_T ooptsb0lyw ; } B
; typedef struct { real_T ciuykz1u0w [ 6 ] ; struct { void * LoggedData ; }
akx2w4hbdp ; int_T patzva3pkv ; int_T oscg4jla3e ; int_T hslfdwpwqj ;
boolean_T hb2znypvs3 ; boolean_T mkmbvwue4g ; boolean_T l0feflwbnw ; } DW ;
typedef struct { real_T gc4fvsjtzb [ 2 ] ; real_T e25bhufqi1 [ 2 ] ; real_T
b5wv4uxlu4 [ 2 ] ; } X ; typedef struct { real_T gc4fvsjtzb [ 2 ] ; real_T
e25bhufqi1 [ 2 ] ; real_T b5wv4uxlu4 [ 2 ] ; } XDot ; typedef struct {
boolean_T gc4fvsjtzb [ 2 ] ; boolean_T e25bhufqi1 [ 2 ] ; boolean_T
b5wv4uxlu4 [ 2 ] ; } XDis ; typedef struct { real_T gc4fvsjtzb [ 2 ] ; real_T
e25bhufqi1 [ 2 ] ; real_T b5wv4uxlu4 [ 2 ] ; } CStateAbsTol ; typedef struct
{ real_T gc4fvsjtzb [ 2 ] ; real_T e25bhufqi1 [ 2 ] ; real_T b5wv4uxlu4 [ 2 ]
; } CXPtMin ; typedef struct { real_T gc4fvsjtzb [ 2 ] ; real_T e25bhufqi1 [
2 ] ; real_T b5wv4uxlu4 [ 2 ] ; } CXPtMax ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T F_inf [ 12
] ; real_T btheta ; real_T g ; real_T ktheta ; real_T m1 ; real_T m2 ; real_T
u_eq [ 2 ] ; real_T ud ; real_T x_0 [ 6 ] ; real_T x_eq [ 6 ] ; real_T
Gain_Gain ; real_T Gain1_Gain ; real_T Gain2_Gain ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern mxArray * mr_untitled_GetDWork ( ) ; extern void
mr_untitled_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_untitled_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * untitled_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
