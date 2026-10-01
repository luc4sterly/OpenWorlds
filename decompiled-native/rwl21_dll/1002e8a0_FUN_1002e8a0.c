// 1002e8a0 FUN_1002e8a0 [Global]
// program: RWL21.DLL

uint * __fastcall FUN_1002e8a0(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  float fVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar2;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  float *pfVar3;
  undefined4 extraout_ECX_05;
  undefined4 uVar4;
  undefined4 extraout_EDX;
  int iVar5;
  undefined4 *puVar6;
  uint *puVar7;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  undefined8 uVar8;
  float local_14;
  float local_10;
  uint *local_c;
  uint local_8;
  uint local_4;
  
  if ((param_3 == (uint *)0x0) || (param_3[0x11] != 2)) {
    param_3 = (uint *)0x0;
  }
  if (param_3 != (uint *)0x0) {
    local_c = param_3 + 0x12;
    puVar6 = (undefined4 *)param_3[0x13];
    puVar7 = (uint *)*puVar6;
    uVar8 = FUN_1002d750(param_1,param_2,(float *)(param_3 + 7),puVar7,(float *)&DAT_1005adb8);
    uVar8 = FUN_1002d750(extraout_ECX,(int)((ulonglong)uVar8 >> 0x20),(float *)(param_3 + 9),puVar7,
                         (float *)&DAT_1005adc4);
    iVar5 = 1;
    uVar8 = FUN_1002d750(extraout_ECX_00,(int)((ulonglong)uVar8 >> 0x20),(float *)(param_3 + 0xb),
                         puVar7,(float *)&DAT_1005add0);
    uVar4 = (undefined4)((ulonglong)uVar8 >> 0x20);
    uVar2 = extraout_ECX_01;
    if (1 < (int)*local_c) {
      do {
        puVar6 = puVar6 + 1;
        puVar7 = (uint *)*puVar6;
        uVar8 = FUN_1002d750(uVar2,uVar4,&local_14,puVar7,(float *)&DAT_1005adb8);
        fVar1 = (float)param_3[7];
        if (local_14 <= (float)param_3[7]) {
          fVar1 = local_14;
        }
        param_3[7] = (uint)fVar1;
        fVar1 = (float)param_3[8];
        if ((float)param_3[8] <= local_10) {
          fVar1 = local_10;
        }
        param_3[8] = (uint)fVar1;
        uVar8 = FUN_1002d750(extraout_ECX_02,(int)((ulonglong)uVar8 >> 0x20),&local_14,puVar7,
                             (float *)&DAT_1005adc4);
        fVar1 = (float)param_3[9];
        if (local_14 <= (float)param_3[9]) {
          fVar1 = local_14;
        }
        param_3[9] = (uint)fVar1;
        fVar1 = (float)param_3[10];
        if ((float)param_3[10] <= local_10) {
          fVar1 = local_10;
        }
        param_3[10] = (uint)fVar1;
        uVar8 = FUN_1002d750(extraout_ECX_03,(int)((ulonglong)uVar8 >> 0x20),&local_14,puVar7,
                             (float *)&DAT_1005add0);
        uVar4 = (undefined4)((ulonglong)uVar8 >> 0x20);
        fVar1 = (float)param_3[0xb];
        if (local_14 <= (float)param_3[0xb]) {
          fVar1 = local_14;
        }
        param_3[0xb] = (uint)fVar1;
        fVar1 = (float)param_3[0xc];
        if ((float)param_3[0xc] <= local_10) {
          fVar1 = local_10;
        }
        param_3[0xc] = (uint)fVar1;
        iVar5 = iVar5 + 1;
        uVar2 = extraout_ECX_04;
      } while (iVar5 < (int)*local_c);
    }
    param_3[0xd] = (uint)((float)param_3[8] - (float)param_3[7]);
    param_3[0xe] = (uint)((float)param_3[10] - (float)param_3[9]);
    param_3[0xf] = (uint)((float)param_3[0xc] - (float)param_3[0xb]);
    if (((param_3 == (uint *)0x0) || (param_3[0x11] == 0)) ||
       (puVar7 = param_3, (*param_3 & 8) != 0)) {
      puVar7 = (uint *)0x0;
    }
    if (puVar7 != (uint *)0x0) {
      if ((puVar7[0x11] != 1) || (pfVar3 = (float *)puVar7[0x12], *(char *)(pfVar3 + 0x10) != '\0'))
      {
        pfVar3 = (float *)0x0;
      }
      if (pfVar3 != (float *)0x0) {
        local_c = (uint *)puVar7[0xd];
        local_8 = puVar7[0xe];
        local_4 = puVar7[0xf];
        RwTransformVector((float *)&local_c,pfVar3);
        RwDotProduct(extraout_ECX_05,extraout_EDX);
        puVar7[0x10] = (uint)(float)extraout_ST0;
        return param_3;
      }
      RwDotProduct(0,uVar4);
      puVar7[0x10] = (uint)(float)extraout_ST0_00;
      return param_3;
    }
  }
  FUN_1000cba0(0x65);
  return param_3;
}


