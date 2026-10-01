// 1001df40 RwRotateMatrixCos [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
RwRotateMatrixCos(float *param_1,float param_2,undefined4 param_3,undefined4 param_4,float param_5,
                 uint param_6,int param_7)

{
  undefined4 uVar1;
  float10 fVar2;
  float local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
                    /* 0x1df40  358  RwRotateMatrixCos */
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
    if ((0xbf800000 < (uint)param_5) || (0x3f800000 < (int)param_5)) {
      param_1 = (float *)0x0;
    }
    if (param_1 != (float *)0x0) {
      local_c = local_1c;
      local_10 = _DAT_10052184 - param_5;
      local_20 = SQRT(_DAT_10052184 - param_5 * param_5);
      uStack_4 = local_14;
      uStack_8 = local_18;
      if (0x80000000 < param_6) {
        local_20 = -local_20;
      }
      uVar1 = FUN_1001cb20(local_20,local_10,param_1,&local_c,local_10,local_20,param_7);
      return uVar1;
    }
    FUN_1000cba0(0xb);
    return 0;
  }
  FUN_1000cba0(0x20);
  return 0;
}


