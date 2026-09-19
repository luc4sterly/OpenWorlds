// 1002d8b0 FUN_1002d8b0 [Global]
// programa: RWL21.DLL

uint * __fastcall
FUN_1002d8b0(undefined4 param_1,undefined4 param_2,uint *param_3,uint *param_4,uint *param_5)

{
  float fVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  float *pfVar2;
  undefined4 extraout_ECX_04;
  undefined4 extraout_EDX;
  uint *puVar3;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  undefined8 uVar4;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  uint local_4;
  
  if (((param_3 == (uint *)0x0) || (param_4 == (uint *)0x0)) || (param_5 == (uint *)0x0)) {
    param_3 = (uint *)0x0;
  }
  if (param_3 != (uint *)0x0) {
    uVar4 = FUN_1002d750(param_1,param_2,&local_14,param_4,(float *)&DAT_1005adb8);
    uVar4 = FUN_1002d750(extraout_ECX,(int)((ulonglong)uVar4 >> 0x20),&local_1c,param_5,
                         (float *)&DAT_1005adb8);
    fVar1 = local_1c;
    if (local_14 <= local_1c) {
      fVar1 = local_14;
    }
    param_3[7] = (uint)fVar1;
    fVar1 = local_18;
    if (local_18 <= local_10) {
      fVar1 = local_10;
    }
    param_3[8] = (uint)fVar1;
    uVar4 = FUN_1002d750(extraout_ECX_00,(int)((ulonglong)uVar4 >> 0x20),&local_14,param_4,
                         (float *)&DAT_1005adc4);
    uVar4 = FUN_1002d750(extraout_ECX_01,(int)((ulonglong)uVar4 >> 0x20),&local_1c,param_5,
                         (float *)&DAT_1005adc4);
    fVar1 = local_1c;
    if (local_14 <= local_1c) {
      fVar1 = local_14;
    }
    param_3[9] = (uint)fVar1;
    fVar1 = local_18;
    if (local_18 <= local_10) {
      fVar1 = local_10;
    }
    param_3[10] = (uint)fVar1;
    uVar4 = FUN_1002d750(extraout_ECX_02,(int)((ulonglong)uVar4 >> 0x20),&local_14,param_4,
                         (float *)&DAT_1005add0);
    uVar4 = FUN_1002d750(extraout_ECX_03,(int)((ulonglong)uVar4 >> 0x20),&local_1c,param_5,
                         (float *)&DAT_1005add0);
    if (local_14 <= local_1c) {
      local_1c = local_14;
    }
    param_3[0xb] = (uint)local_1c;
    if (local_18 <= local_10) {
      local_18 = local_10;
    }
    param_3[0xc] = (uint)local_18;
    param_3[0xd] = (uint)((float)param_3[8] - (float)param_3[7]);
    param_3[0xe] = (uint)((float)param_3[10] - (float)param_3[9]);
    param_3[0xf] = (uint)((float)param_3[0xc] - (float)param_3[0xb]);
    if (((param_3 == (uint *)0x0) || (param_3[0x11] == 0)) ||
       (puVar3 = param_3, (*param_3 & 8) != 0)) {
      puVar3 = (uint *)0x0;
    }
    if (puVar3 != (uint *)0x0) {
      if ((puVar3[0x11] != 1) || (pfVar2 = (float *)puVar3[0x12], *(char *)(pfVar2 + 0x10) != '\0'))
      {
        pfVar2 = (float *)0x0;
      }
      if (pfVar2 != (float *)0x0) {
        local_c = (float)puVar3[0xd];
        local_8 = puVar3[0xe];
        local_4 = puVar3[0xf];
        RwTransformVector(&local_c,pfVar2);
        RwDotProduct(extraout_ECX_04,extraout_EDX);
        puVar3[0x10] = (uint)(float)extraout_ST0;
        return param_3;
      }
      RwDotProduct(0,(int)((ulonglong)uVar4 >> 0x20));
      puVar3[0x10] = (uint)(float)extraout_ST0_00;
      return param_3;
    }
  }
  FUN_1000cba0(0x65);
  return param_3;
}


