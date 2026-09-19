// 1001de70 RwRotateMatrix [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
RwRotateMatrix(float *param_1,float param_2,undefined4 param_3,undefined4 param_4,float param_5,
              undefined4 param_6)

{
  undefined4 uVar1;
  float10 fVar2;
  undefined1 auVar3 [10];
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
                    /* 0x1de70  357  RwRotateMatrix */
  if (param_1 == (float *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  local_1c = param_2;
  local_18 = param_3;
  local_14 = param_4;
  fVar2 = rwLengthNormaliseVector(&local_1c,&local_1c);
  if (fVar2 <= (float10)_DAT_10052180) {
    param_1 = (float *)0x0;
  }
  if (param_1 != (float *)0x0) {
    local_c = local_1c;
    uStack_8 = local_18;
    uStack_4 = local_14;
    auVar3 = FUN_10041750(param_5);
    local_10 = (float)(float10)auVar3;
    auVar3 = FUN_10041760(param_5);
    uVar1 = FUN_1001cb20(param_6,local_10,param_1,&local_c,
                         (float)((float10)_DAT_10052184 - (float10)auVar3),local_10,param_6);
    return uVar1;
  }
  FUN_1000cba0(0x20);
  return 0;
}


