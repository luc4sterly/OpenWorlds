// 1000d5c0 FUN_1000d5c0 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000d5c0(int param_1)

{
  float fVar1;
  undefined4 *puVar2;
  undefined4 extraout_ECX;
  int extraout_EDX;
  float *pfVar3;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 fVar4;
  undefined8 uVar5;
  longlong lVar6;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  int local_14;
  float local_10;
  float local_c [3];
  
  local_10 = _DAT_100520d0 / (*(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x78) - _DAT_1005a0b8);
  pfVar3 = (float *)(*(int *)(param_1 + 0x88) + 0x3ac);
  local_14 = *(int *)(*(int *)(param_1 + 0x88) + 8) + -9;
  do {
    if (local_14 < 0) {
      return;
    }
    local_28 = pfVar3[9] * _DAT_100520d4;
    local_24 = pfVar3[10] * _DAT_100520d4;
    local_20 = pfVar3[0xb] * _DAT_100520d4;
    for (puVar2 = DAT_1005a0b0; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
      if (puVar2[1] == 1) {
        uVar5 = RwDotProduct(pfVar3 + 0x13,param_1);
        param_1 = (int)((ulonglong)uVar5 >> 0x20);
        local_34 = (float)extraout_ST0;
        if ((float10)_DAT_100520d8 < extraout_ST0) {
          local_30 = pfVar3[0xc] * local_34;
          local_2c = pfVar3[0xd] * local_34;
          local_1c = pfVar3[0xe] * local_34;
joined_r0x1000d7a7:
          if (0x3f333333 < (int)local_34) {
            lVar6 = __ftol();
            param_1 = (int)((ulonglong)lVar6 >> 0x20);
            fVar1 = *(float *)(DAT_1005a0b4 + (int)lVar6 * 4);
            local_30 = pfVar3[0xf] * fVar1 + local_30;
            local_2c = pfVar3[0x10] * fVar1 + local_2c;
            local_1c = fVar1 * pfVar3[0x11] + local_1c;
          }
          local_28 = (float)puVar2[0x1e] * local_30 + local_28;
          local_24 = (float)puVar2[0x1f] * local_2c + local_24;
          local_20 = (float)puVar2[0x20] * local_1c + local_20;
        }
      }
      else {
        RwSubtractVector((float *)(puVar2 + 0x13),pfVar3,local_c);
        uVar5 = RwDotProduct(local_c,pfVar3 + 0x13);
        param_1 = (int)((ulonglong)uVar5 >> 0x20);
        if ((float10)_DAT_100520d8 < extraout_ST0_00) {
          uVar5 = RwDotProduct(extraout_ECX,param_1);
          param_1 = (int)((ulonglong)uVar5 >> 0x20);
          local_18 = (float)extraout_ST0_01;
          if (extraout_ST0_01 < (float10)(float)puVar2[0x1c]) {
            if (puVar2[1] == 3) {
              uVar5 = RwDotProduct(puVar2 + 0x16,param_1);
              param_1 = (int)((ulonglong)uVar5 >> 0x20);
              fVar1 = (float)extraout_ST0_02;
              local_30 = fVar1;
              if (extraout_ST0_02 < (float10)_DAT_100520d8) {
                local_30 = -fVar1;
              }
              if (fVar1 * local_30 < (float)puVar2[0x1d] * local_18) goto LAB_1000d826;
            }
            if (local_18 <= (float)puVar2[0x1b]) {
              fVar4 = FUN_10041770((int *)&local_18);
              fVar4 = (float10)(float)extraout_ST0_00 / fVar4;
              param_1 = extraout_EDX;
            }
            else {
              fVar4 = ((float10)(float)extraout_ST0_00 / (float10)local_18) *
                      (float10)(float)puVar2[0x1a];
            }
            local_34 = (float)fVar4;
            if (0x3f7f0000 < (int)local_34) {
              local_34 = 0.99609375;
            }
            local_30 = pfVar3[0xc] * local_34;
            local_2c = pfVar3[0xd] * local_34;
            local_1c = pfVar3[0xe] * local_34;
            goto joined_r0x1000d7a7;
          }
        }
      }
LAB_1000d826:
    }
    if ((*(int *)(PTR_DAT_1005b69c + 0x2ec) == 2) && (_DAT_1005a0b8 < pfVar3[5])) {
      fVar1 = (*(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x78) - pfVar3[5]) * local_10;
      if (fVar1 <= _DAT_100520d8) {
        local_20 = 0.0;
        local_24 = 0.0;
        local_28 = 0.0;
      }
      else {
        local_28 = local_28 * fVar1;
        local_24 = local_24 * fVar1;
        local_20 = local_20 * fVar1;
      }
    }
    if ((int)local_28 < 0x41f80000) {
      lVar6 = __ftol();
      param_1 = (int)((ulonglong)lVar6 >> 0x20);
      pfVar3[0x16] = (float)lVar6;
    }
    else {
      pfVar3[0x16] = 2.8469e-39;
    }
    if ((int)local_24 < 0x41f80000) {
      lVar6 = __ftol();
      param_1 = (int)((ulonglong)lVar6 >> 0x20);
      pfVar3[0x17] = (float)lVar6;
    }
    else {
      pfVar3[0x17] = 2.8469e-39;
    }
    if ((int)local_20 < 0x41f80000) {
      lVar6 = __ftol();
      param_1 = (int)((ulonglong)lVar6 >> 0x20);
      pfVar3[0x18] = (float)lVar6;
    }
    else {
      pfVar3[0x18] = 2.8469e-39;
    }
    pfVar3 = pfVar3 + 0x1d;
    local_14 = local_14 + -1;
  } while( true );
}


