#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "untitled_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "untitled.h"
#include "untitled_capi.h"
#include "untitled_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"untitled/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "untitled/Sum1" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1
} , { 2 , 0 , TARGET_STRING ( "untitled/Subsystem/Gain" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"untitled/Subsystem/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , {
4 , 0 , TARGET_STRING ( "untitled/Subsystem/Gain2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 2 , 0 , 0 } , { 5 , 0 , TARGET_STRING ( "untitled/Subsystem/Divide" )
, TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"untitled/Subsystem/Divide1" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } ,
{ 7 , 0 , TARGET_STRING ( "untitled/Subsystem/Divide10" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"untitled/Subsystem/Divide11" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 }
, { 9 , 0 , TARGET_STRING ( "untitled/Subsystem/Divide2" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 1 } , { 10 , 0 , TARGET_STRING (
"untitled/Subsystem/Divide3" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } ,
{ 11 , 0 , TARGET_STRING ( "untitled/Subsystem/Divide4" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"untitled/Subsystem/Divide5" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } ,
{ 13 , 0 , TARGET_STRING ( "untitled/Subsystem/Divide6" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 1 } , { 14 , 0 , TARGET_STRING (
"untitled/Subsystem/Divide7" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } ,
{ 15 , 0 , TARGET_STRING ( "untitled/Subsystem/Divide8" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"untitled/Subsystem/Divide9" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } ,
{ 17 , 0 , TARGET_STRING ( "untitled/Subsystem/Product" ) , TARGET_STRING (
"" ) , 0 , 0 , 2 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"untitled/Subsystem/Product1" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 }
, { 19 , 0 , TARGET_STRING ( "untitled/Subsystem/Product10" ) , TARGET_STRING
( "" ) , 0 , 0 , 2 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"untitled/Subsystem/Product11" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 }
, { 21 , 0 , TARGET_STRING ( "untitled/Subsystem/Product12" ) , TARGET_STRING
( "" ) , 0 , 0 , 2 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"untitled/Subsystem/Product13" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 }
, { 23 , 0 , TARGET_STRING ( "untitled/Subsystem/Product2" ) , TARGET_STRING
( "" ) , 0 , 0 , 2 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
"untitled/Subsystem/Product3" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 }
, { 25 , 0 , TARGET_STRING ( "untitled/Subsystem/Product4" ) , TARGET_STRING
( "" ) , 0 , 0 , 2 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
"untitled/Subsystem/Product5" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 }
, { 27 , 0 , TARGET_STRING ( "untitled/Subsystem/Product6" ) , TARGET_STRING
( "" ) , 0 , 0 , 2 , 0 , 0 } , { 28 , 0 , TARGET_STRING (
"untitled/Subsystem/Product7" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 }
, { 29 , 0 , TARGET_STRING ( "untitled/Subsystem/Product8" ) , TARGET_STRING
( "" ) , 0 , 0 , 2 , 0 , 0 } , { 30 , 0 , TARGET_STRING (
"untitled/Subsystem/Product9" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 }
, { 31 , 0 , TARGET_STRING ( "untitled/Subsystem/Add" ) , TARGET_STRING ( ""
) , 0 , 0 , 2 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
"untitled/Subsystem/Add1" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , {
33 , 0 , TARGET_STRING ( "untitled/Subsystem/Add2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 2 , 0 , 1 } , { 34 , 0 , TARGET_STRING ( "untitled/Subsystem/Add3" )
, TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 35 , 0 , TARGET_STRING (
"untitled/Subsystem/Add4" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , {
36 , 0 , TARGET_STRING ( "untitled/Subsystem/Add5" ) , TARGET_STRING ( "" ) ,
0 , 0 , 2 , 0 , 0 } , { 37 , 0 , TARGET_STRING (
"untitled/Subsystem/Integrator, Second-Order" ) , TARGET_STRING ( "" ) , 0 ,
0 , 2 , 0 , 0 } , { 38 , 0 , TARGET_STRING (
"untitled/Subsystem/Integrator, Second-Order" ) , TARGET_STRING ( "" ) , 1 ,
0 , 2 , 0 , 0 } , { 39 , 0 , TARGET_STRING (
"untitled/Subsystem/Integrator, Second-Order1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 2 , 0 , 0 } , { 40 , 0 , TARGET_STRING (
"untitled/Subsystem/Integrator, Second-Order1" ) , TARGET_STRING ( "" ) , 1 ,
0 , 2 , 0 , 0 } , { 41 , 0 , TARGET_STRING (
"untitled/Subsystem/Integrator, Second-Order2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 2 , 0 , 0 } , { 42 , 0 , TARGET_STRING (
"untitled/Subsystem/Integrator, Second-Order2" ) , TARGET_STRING ( "" ) , 1 ,
0 , 2 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 43 ,
TARGET_STRING ( "untitled/Subsystem/Gain" ) , TARGET_STRING ( "Gain" ) , 0 ,
2 , 0 } , { 44 , TARGET_STRING ( "untitled/Subsystem/Gain1" ) , TARGET_STRING
( "Gain" ) , 0 , 2 , 0 } , { 45 , TARGET_STRING ( "untitled/Subsystem/Gain2"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 46 , TARGET_STRING (
"F_inf" ) , 0 , 3 , 0 } , { 47 , TARGET_STRING ( "btheta" ) , 0 , 2 , 0 } , {
48 , TARGET_STRING ( "g" ) , 0 , 2 , 0 } , { 49 , TARGET_STRING ( "ktheta" )
, 0 , 2 , 0 } , { 50 , TARGET_STRING ( "m1" ) , 0 , 2 , 0 } , { 51 ,
TARGET_STRING ( "m2" ) , 0 , 2 , 0 } , { 52 , TARGET_STRING ( "u_eq" ) , 0 ,
1 , 0 } , { 53 , TARGET_STRING ( "ud" ) , 0 , 2 , 0 } , { 54 , TARGET_STRING
( "x_0" ) , 0 , 0 , 0 } , { 55 , TARGET_STRING ( "x_eq" ) , 0 , 0 , 0 } , { 0
, ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . cme4xuiwky [ 0 ] , & rtB .
cw5yzcdmaq [ 0 ] , & rtB . cyrxnsdt3w , & rtB . bjgyvns5gp , & rtB .
gvaowacf1r , & rtB . gdanjzyc2u , & rtB . jliulylrzv , & rtB . dbzgnveifb , &
rtB . jbeqg1clca , & rtB . o3r0s2aug2 , & rtB . oioq1wpgc5 , & rtB .
nxmuuzho4k , & rtB . ft5dvj2xy2 , & rtB . d3hioucrij , & rtB . gjziua45oo , &
rtB . jhj1ql1k1k , & rtB . jvcjbj1a5l , & rtB . po5onpuvn4 , & rtB .
jyfoeudl2q , & rtB . oilazgswio , & rtB . j0e1xtukkh , & rtB . mgqe2jsh0w , &
rtB . obdgflwa5b , & rtB . igk3ef1igr , & rtB . hc5bjkc5kt , & rtB .
bnhtxjyxk2 , & rtB . byqiddisjh , & rtB . dmbgltqa1p , & rtB . oxxpdxdjrz , &
rtB . dwpyxuko14 , & rtB . of0l4p5cfb , & rtB . nzwjkbw5x3 , & rtB .
gmvs3wwowg , & rtB . nnfeioattm , & rtB . dwx142rb5m , & rtB . ooptsb0lyw , &
rtB . cnpiutyf2u , & rtB . o0exiazmut , & rtB . kj3lusgpyv , & rtB .
cxnkqagze2 , & rtB . ab31ckmc1a , & rtB . cyr5ludheo , & rtB . jvb02h1oc5 , &
rtP . Gain_Gain , & rtP . Gain1_Gain , & rtP . Gain2_Gain , & rtP . F_inf [ 0
] , & rtP . btheta , & rtP . g , & rtP . ktheta , & rtP . m1 , & rtP . m2 , &
rtP . u_eq [ 0 ] , & rtP . ud , & rtP . x_0 [ 0 ] , & rtP . x_eq [ 0 ] , } ;
static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_SCALAR , 4 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 , 0 } } ;
static const uint_T rtDimensionArray [ ] = { 6 , 1 , 2 , 1 , 1 , 1 , 2 , 6 }
; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 0.1 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 2 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 43 , rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 3 ,
rtModelParameters , 10 } , { ( NULL ) , 0 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 2746031948U , 1439074739U , 830516166U ,
2364538730U } , ( NULL ) , 0 , 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * untitled_GetCAPIStaticMap ( void ) { return
& mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void untitled_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void untitled_host_InitializeDataMapInfo ( untitled_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
