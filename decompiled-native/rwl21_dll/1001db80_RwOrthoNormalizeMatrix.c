// 1001db80 RwOrthoNormalizeMatrix [Global]
// programa: RWL21.DLL

float * __fastcall
RwOrthoNormalizeMatrix(undefined4 param_1,undefined4 param_2,float *param_3,float *param_4)

{
  float *pfVar1;
  
                    /* 0x1db80  300  RwOrthoNormalizeMatrix */
  if ((param_3 != (float *)0x0) && (param_4 != (float *)0x0)) {
    pfVar1 = FUN_1001c150(param_1,param_2,param_3,param_4);
    return pfVar1;
  }
  FUN_1000cba0(1);
  return (float *)0x0;
}


