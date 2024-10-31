#include "rt_logging_mmi.h"
#include "untitled_capi.h"
#include <math.h>
#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 4 ; const char_T
* gbl_raccel_Version = "9.5 (R2021a) 14-Nov-2020" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { boolean_T tmp ; rtDW . patzva3pkv =
0 ; rtDW . hb2znypvs3 = true ; if ( ssIsFirstInitCond ( rtS ) ) { tmp =
slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) { tmp =
ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . hb2znypvs3 = ! tmp ; }
else { rtDW . hb2znypvs3 = true ; } } rtDW . oscg4jla3e = 0 ; rtDW .
mkmbvwue4g = true ; if ( ssIsFirstInitCond ( rtS ) ) { tmp =
slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) { tmp =
ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . mkmbvwue4g = ! tmp ; }
else { rtDW . mkmbvwue4g = true ; } } rtDW . hslfdwpwqj = 0 ; rtDW .
l0feflwbnw = true ; if ( ssIsFirstInitCond ( rtS ) ) { tmp =
slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) { tmp =
ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . l0feflwbnw = ! tmp ; }
else { rtDW . l0feflwbnw = true ; } } } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { RTWLogSignalInfo rt_ScopeSignalInfo ; static int_T rt_ScopeSignalWidths [
] = { 6 } ; static int_T rt_ScopeSignalNumDimensions [ ] = { 1 } ; static
int_T rt_ScopeSignalDimensions [ ] = { 6 } ; static void *
rt_ScopeCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ScopeCurrSigDimsSize
[ ] = { 4 } ; static const char_T * rt_ScopeSignalLabels [ ] = { "" } ;
static char_T rt_ScopeSignalTitles [ ] = "" ; static int_T
rt_ScopeSignalTitleLengths [ ] = { 0 } ; static boolean_T
rt_ScopeSignalIsVarDims [ ] = { 0 } ; static int_T rt_ScopeSignalPlotStyles [
] = { 0 , 0 , 0 , 0 , 0 , 0 } ; BuiltInDTypeId dTypes [ 1 ] = { SS_DOUBLE } ;
static char_T rt_ScopeBlockName [ ] = "untitled/Scope1" ; static int_T
rt_ScopeFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ScopeSignalLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ;
rt_ScopeSignalInfo . numSignals = 1 ; rt_ScopeSignalInfo . numCols =
rt_ScopeSignalWidths ; rt_ScopeSignalInfo . numDims =
rt_ScopeSignalNumDimensions ; rt_ScopeSignalInfo . dims =
rt_ScopeSignalDimensions ; rt_ScopeSignalInfo . isVarDims =
rt_ScopeSignalIsVarDims ; rt_ScopeSignalInfo . currSigDims =
rt_ScopeCurrSigDims ; rt_ScopeSignalInfo . currSigDimsSize =
rt_ScopeCurrSigDimsSize ; rt_ScopeSignalInfo . dataTypes = dTypes ;
rt_ScopeSignalInfo . complexSignals = ( NULL ) ; rt_ScopeSignalInfo .
frameData = rt_ScopeFrameData ; rt_ScopeSignalInfo . preprocessingPtrs =
rt_ScopeSignalLoggingPreprocessingFcnPtrs ; rt_ScopeSignalInfo . labels .
cptr = rt_ScopeSignalLabels ; rt_ScopeSignalInfo . titles =
rt_ScopeSignalTitles ; rt_ScopeSignalInfo . titleLengths =
rt_ScopeSignalTitleLengths ; rt_ScopeSignalInfo . plotStyles =
rt_ScopeSignalPlotStyles ; rt_ScopeSignalInfo . blockNames . cptr = ( NULL )
; rt_ScopeSignalInfo . stateNames . cptr = ( NULL ) ; rt_ScopeSignalInfo .
crossMdlRef = ( NULL ) ; rt_ScopeSignalInfo . dataTypeConvert = ( NULL ) ;
rtDW . akx2w4hbdp . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "stati" , 1 , 0 , 1 , 0.0 , & rt_ScopeSignalInfo
, rt_ScopeBlockName ) ; if ( rtDW . akx2w4hbdp . LoggedData == ( NULL ) )
return ; } MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T
pf0xwonh2x [ 2 ] ; real_T bdj1vvyrct ; real_T nn0bv0x1hj ; int32_T i ;
int32_T i_p ; if ( rtDW . hb2znypvs3 ) { rtX . gc4fvsjtzb [ 0 ] = rtP . x_0 [
0 ] ; rtX . gc4fvsjtzb [ 1 ] = rtP . x_0 [ 1 ] ; } rtB . o0exiazmut = rtX .
gc4fvsjtzb [ 0 ] ; rtB . kj3lusgpyv = rtX . gc4fvsjtzb [ 1 ] ; if ( rtDW .
mkmbvwue4g ) { rtX . e25bhufqi1 [ 0 ] = rtP . x_0 [ 2 ] ; rtX . e25bhufqi1 [
1 ] = rtP . x_0 [ 3 ] ; } rtB . cxnkqagze2 = rtX . e25bhufqi1 [ 0 ] ; rtB .
ab31ckmc1a = rtX . e25bhufqi1 [ 1 ] ; if ( rtDW . l0feflwbnw ) { rtX .
b5wv4uxlu4 [ 0 ] = rtP . x_0 [ 4 ] ; rtX . b5wv4uxlu4 [ 1 ] = rtP . x_0 [ 5 ]
; } rtB . cyr5ludheo = rtX . b5wv4uxlu4 [ 0 ] ; rtB . jvb02h1oc5 = rtX .
b5wv4uxlu4 [ 1 ] ; if ( ssGetLogOutput ( rtS ) ) { StructLogVar * svar = (
StructLogVar * ) rtDW . akx2w4hbdp . LoggedData ; LogVar * var = svar ->
signals . values ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
rt_UpdateLogVar ( ( LogVar * ) svar -> time , & locTime , 0 ) ; } { real_T
up0 [ 6 ] ; up0 [ 0 ] = rtB . o0exiazmut ; up0 [ 1 ] = rtB . kj3lusgpyv ; up0
[ 2 ] = rtB . cxnkqagze2 ; up0 [ 3 ] = rtB . ab31ckmc1a ; up0 [ 4 ] = rtB .
cyr5ludheo ; up0 [ 5 ] = rtB . jvb02h1oc5 ; rt_UpdateLogVar ( ( LogVar * )
var , up0 , 0 ) ; } } rtB . cme4xuiwky [ 0 ] = rtB . o0exiazmut - rtP . x_eq
[ 0 ] ; rtB . cme4xuiwky [ 1 ] = rtB . kj3lusgpyv - rtP . x_eq [ 1 ] ; rtB .
cme4xuiwky [ 2 ] = rtB . cxnkqagze2 - rtP . x_eq [ 2 ] ; rtB . cme4xuiwky [ 3
] = rtB . ab31ckmc1a - rtP . x_eq [ 3 ] ; rtB . cme4xuiwky [ 4 ] = rtB .
cyr5ludheo - rtP . x_eq [ 4 ] ; rtB . cme4xuiwky [ 5 ] = rtB . jvb02h1oc5 -
rtP . x_eq [ 5 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) && ssIsSampleHit ( rtS
, 2 , 0 ) ) { for ( i = 0 ; i < 6 ; i ++ ) { rtDW . ciuykz1u0w [ i ] = rtB .
cme4xuiwky [ i ] ; } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { for ( i = 0 ; i
< 2 ; i ++ ) { pf0xwonh2x [ i ] = 0.0 ; for ( i_p = 0 ; i_p < 6 ; i_p ++ ) {
pf0xwonh2x [ i ] += rtP . F_inf [ ( i_p << 1 ) + i ] * rtDW . ciuykz1u0w [
i_p ] ; } } rtB . cw5yzcdmaq [ 0 ] = rtP . u_eq [ 0 ] + pf0xwonh2x [ 0 ] ;
rtB . cw5yzcdmaq [ 1 ] = rtP . u_eq [ 1 ] + pf0xwonh2x [ 1 ] ; } nn0bv0x1hj =
muDoubleScalarCos ( rtB . cyr5ludheo ) ; rtB . po5onpuvn4 = rtP . btheta *
rtB . jvb02h1oc5 ; rtB . jyfoeudl2q = rtP . ktheta * rtB . cyr5ludheo ; rtB .
gmvs3wwowg = rtB . po5onpuvn4 + rtB . jyfoeudl2q ; rtB . igk3ef1igr =
nn0bv0x1hj * rtB . gmvs3wwowg ; rtB . hc5bjkc5kt = rtB . cxnkqagze2 * rtP .
m1 ; rtB . gdanjzyc2u = rtB . igk3ef1igr / rtB . hc5bjkc5kt ; bdj1vvyrct =
muDoubleScalarSin ( rtB . cyr5ludheo ) ; rtB . bnhtxjyxk2 = rtB . cw5yzcdmaq
[ 1 ] * bdj1vvyrct ; rtB . jliulylrzv = rtB . bnhtxjyxk2 / rtP . m1 ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . nnfeioattm = rtB . cw5yzcdmaq [ 0 ] +
rtP . ud ; rtB . o3r0s2aug2 = rtB . nnfeioattm / rtP . m1 ; rtB . d3hioucrij
= rtB . cw5yzcdmaq [ 1 ] / rtP . m2 ; } rtB . nzwjkbw5x3 = ( rtB . jliulylrzv
- rtB . gdanjzyc2u ) + rtB . o3r0s2aug2 ; rtB . cyrxnsdt3w = rtP . Gain_Gain
* rtB . cyr5ludheo ; rtB . byqiddisjh = muDoubleScalarSin ( rtB . cyrxnsdt3w
) * rtB . gmvs3wwowg ; rtB . bjgyvns5gp = rtP . Gain1_Gain * rtB . hc5bjkc5kt
; rtB . oioq1wpgc5 = rtB . byqiddisjh / rtB . bjgyvns5gp ; rtB . nxmuuzho4k =
bdj1vvyrct * bdj1vvyrct / rtP . m1 ; rtB . dmbgltqa1p = rtB . nnfeioattm *
bdj1vvyrct ; rtB . ft5dvj2xy2 = rtB . dmbgltqa1p / rtP . m1 ; rtB .
oxxpdxdjrz = rtP . g * nn0bv0x1hj ; rtB . dwpyxuko14 = rtB . jvb02h1oc5 * rtB
. jvb02h1oc5 * rtB . cxnkqagze2 ; rtB . dwx142rb5m = ( ( ( ( rtB . nxmuuzho4k
- rtB . oioq1wpgc5 ) + rtB . ft5dvj2xy2 ) + rtB . d3hioucrij ) - rtB .
oxxpdxdjrz ) + rtB . dwpyxuko14 ; rtB . of0l4p5cfb = rtB . cxnkqagze2 * rtB .
cxnkqagze2 * rtP . m2 ; rtB . gjziua45oo = rtB . gmvs3wwowg / rtB .
of0l4p5cfb ; rtB . oilazgswio = nn0bv0x1hj * nn0bv0x1hj * rtB . gmvs3wwowg ;
rtB . jhj1ql1k1k = rtB . oilazgswio / rtB . of0l4p5cfb ; rtB . j0e1xtukkh =
rtB . cw5yzcdmaq [ 1 ] * bdj1vvyrct ; rtB . cnpiutyf2u = rtB . j0e1xtukkh +
rtB . nnfeioattm ; rtB . jvcjbj1a5l = rtB . cnpiutyf2u / rtP . m1 ; rtB .
mgqe2jsh0w = rtP . g * bdj1vvyrct ; rtB . dbzgnveifb = rtB . mgqe2jsh0w / rtB
. cxnkqagze2 ; rtB . gvaowacf1r = rtP . Gain2_Gain * rtB . jvb02h1oc5 ; rtB .
obdgflwa5b = rtB . gvaowacf1r * rtB . ab31ckmc1a ; rtB . jbeqg1clca = rtB .
obdgflwa5b / rtB . cxnkqagze2 ; rtB . ooptsb0lyw = ( ( ( rtB . jvcjbj1a5l -
rtB . gjziua45oo ) - rtB . jhj1ql1k1k ) + rtB . dbzgnveifb ) - rtB .
jbeqg1clca ; UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID3 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { rtDW . hb2znypvs3
= false ; rtDW . mkmbvwue4g = false ; rtDW . l0feflwbnw = false ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID3 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; if ( rtDW . patzva3pkv == 0 ) {
_rtXdot -> gc4fvsjtzb [ 0 ] = rtX . gc4fvsjtzb [ 1 ] ; _rtXdot -> gc4fvsjtzb
[ 1 ] = rtB . nzwjkbw5x3 ; } if ( rtDW . oscg4jla3e == 0 ) { _rtXdot ->
e25bhufqi1 [ 0 ] = rtX . e25bhufqi1 [ 1 ] ; _rtXdot -> e25bhufqi1 [ 1 ] = rtB
. dwx142rb5m ; } if ( rtDW . hslfdwpwqj == 0 ) { _rtXdot -> b5wv4uxlu4 [ 0 ]
= rtX . b5wv4uxlu4 [ 1 ] ; _rtXdot -> b5wv4uxlu4 [ 1 ] = rtB . ooptsb0lyw ; }
} void MdlProjection ( void ) { } void MdlTerminate ( void ) { } static void
mr_untitled_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) ; static void
mr_untitled_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_untitled_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_untitled_restoreDataFromMxArray ( void * destData , const mxArray *
srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_untitled_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_untitled_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j
, uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_untitled_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) ; static uint_T
mr_untitled_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_untitled_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_untitled_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_untitled_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_untitled_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_untitled_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_untitled_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
double ) fieldVal ) ) ; } static uint_T
mr_untitled_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T
mr_untitled_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T
fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray
, i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; }
mxArray * mr_untitled_GetDWork ( ) { static const char * ssDWFieldNames [ 3 ]
= { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_untitled_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB ) ,
sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 7 ] = {
"rtDW.ciuykz1u0w" , "rtDW.patzva3pkv" , "rtDW.oscg4jla3e" , "rtDW.hslfdwpwqj"
, "rtDW.hb2znypvs3" , "rtDW.mkmbvwue4g" , "rtDW.l0feflwbnw" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 7 , rtdwDataFieldNames ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & ( rtDW
. ciuykz1u0w ) , sizeof ( rtDW . ciuykz1u0w ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & ( rtDW
. patzva3pkv ) , sizeof ( rtDW . patzva3pkv ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & ( rtDW
. oscg4jla3e ) , sizeof ( rtDW . oscg4jla3e ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & ( rtDW
. hslfdwpwqj ) , sizeof ( rtDW . hslfdwpwqj ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & ( rtDW
. hb2znypvs3 ) , sizeof ( rtDW . hb2znypvs3 ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & ( rtDW
. mkmbvwue4g ) , sizeof ( rtDW . mkmbvwue4g ) ) ;
mr_untitled_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & ( rtDW
. l0feflwbnw ) , sizeof ( rtDW . l0feflwbnw ) ) ; mxSetFieldByNumber ( ssDW ,
0 , 1 , rtdwData ) ; } return ssDW ; } void mr_untitled_SetDWork ( const
mxArray * ssDW ) { ( void ) ssDW ; mr_untitled_restoreDataFromMxArray ( (
void * ) & ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray *
rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . ciuykz1u0w ) ,
rtdwData , 0 , 0 , sizeof ( rtDW . ciuykz1u0w ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . patzva3pkv ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . patzva3pkv ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . oscg4jla3e ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . oscg4jla3e ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . hslfdwpwqj ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . hslfdwpwqj ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . hb2znypvs3 ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . hb2znypvs3 ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . mkmbvwue4g ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . mkmbvwue4g ) ) ;
mr_untitled_restoreDataFromMxArray ( ( void * ) & ( rtDW . l0feflwbnw ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . l0feflwbnw ) ) ; } } mxArray *
mr_untitled_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 1 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char * blockType [ 1 ] = { "Scope" , } ; static const char * blockPath [ 1 ]
= { "untitled/Scope1" , } ; static const int reason [ 1 ] = { 0 , } ; for (
subs [ 0 ] = 0 ; subs [ 0 ] < 1 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateDoubleScalar ( ( double ) reason [ subs [ 0 ] ] ) ) ; } }
return data ; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS ,
6 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ;
ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 3 ) ; ssSetNumBlocks ( rtS , 59 ) ;
ssSetNumBlockIO ( rtS , 43 ) ; ssSetNumBlockParams ( rtS , 35 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , 0.1 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 2746031948U ) ; ssSetChecksumVal ( rtS , 1 ,
1439074739U ) ; ssSetChecksumVal ( rtS , 2 , 830516166U ) ; ssSetChecksumVal
( rtS , 3 , 2364538730U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
untitled_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "untitled" ) ; ssSetPath
( rtS , "untitled" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 30.0 )
; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ;
} { { static int_T rt_LoggedStateWidths [ ] = { 2 , 2 , 2 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 2 , 2 , 2 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ;
static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = {
"CSTATE" , "CSTATE" , "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"untitled/Subsystem/Integrator,\nSecond-Order" ,
"untitled/Subsystem/Integrator,\nSecond-Order1" ,
"untitled/Subsystem/Integrator,\nSecond-Order2" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } ,
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 3 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 3 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . gc4fvsjtzb [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . e25bhufqi1 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . b5wv4uxlu4 [ 0 ] ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 6 ] ;
static real_T absTol [ 6 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 } ; static uint8_T absTolControl [ 6 ] = { 0U , 0U , 0U , 0U , 0U , 0U
} ; static real_T contStateJacPerturbBoundMinVec [ 6 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 6 ] ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 4 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
d3hioucrij ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
o3r0s2aug2 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
nnfeioattm ) , ( NULL ) } , { 2 * sizeof ( real_T ) , ( char * ) ( & rtB .
cw5yzcdmaq [ 0 ] ) , ( NULL ) } } ; { int i ; for ( i = 0 ; i < 6 ; ++ i ) {
contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [ i
] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.1 )
; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 1 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 4 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS
, 1 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol ) ; ssSetAbsTolControlVector (
rtS , absTolControl ) ; ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 2746031948U ) ; ssSetChecksumVal ( rtS , 1 ,
1439074739U ) ; ssSetChecksumVal ( rtS , 2 , 830516166U ) ; ssSetChecksumVal
( rtS , 3 , 2364538730U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_untitled_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP (
rtS , mr_untitled_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_untitled_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 3 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID3 ( tid ) ; }
