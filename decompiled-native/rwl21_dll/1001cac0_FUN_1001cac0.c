// 1001cac0 FUN_1001cac0 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001cac0(undefined4 param_1,float param_2,undefined4 param_3,undefined4 param_4,
                 float param_5,int param_6)

{
  undefined1 auVar1 [10];
  undefined1 auVar2 [10];
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = param_2;
  local_8 = param_3;
  local_4 = param_4;
  auVar1 = FUN_10041750(param_5);
  auVar2 = FUN_10041760(param_5);
  FUN_1001cb20(param_1,(float)(float10)auVar1,(float *)param_1,&local_c,
               (float)((float10)_DAT_10052184 - (float10)auVar2),(float)(float10)auVar1,param_6);
  return;
}


