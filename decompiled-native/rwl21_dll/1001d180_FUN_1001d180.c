// 1001d180 FUN_1001d180 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_1001d180(float *param_1,float param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined1 auVar1 [10];
  undefined1 auVar2 [10];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_4 = 0;
  local_8 = 0x3f800000;
  auVar1 = FUN_10041750(param_2);
  auVar2 = FUN_10041760(param_2);
  FUN_1001cb20((float)(float10)auVar1,&local_c,param_1,(float *)&local_c,
               (float)((float10)_DAT_10052184 - (float10)auVar2),(float)(float10)auVar1,2);
  FUN_1001c150(extraout_ECX,extraout_EDX,param_1,param_1);
  return param_1;
}


