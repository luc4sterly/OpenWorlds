// 1000cc10 FUN_1000cc10 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000cc10(float *param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  float fVar3;
  float extraout_ECX;
  float fVar4;
  undefined4 extraout_ECX_00;
  float extraout_EDX;
  float extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 uVar5;
  undefined4 extraout_EDX_03;
  float *pfVar6;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 fVar7;
  undefined8 uVar8;
  longlong lVar9;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  int local_14;
  float local_10;
  float local_c [3];
  
  bVar2 = *(char *)((int)param_1 + 0x19a) + 1;
  *(byte *)((int)param_1 + 0x19a) = bVar2;
  if ((*(char *)((int)param_1 + 0x19b) == '\0') && ((ushort)bVar2 <= *(ushort *)(param_1 + 0x66))) {
    return;
  }
  fVar3 = (float)FUN_1002c2b0((int)param_1);
  DAT_1005a0b0 = (undefined4 *)FUN_1002c280((int)param_1);
  fVar4 = *(float *)(PTR_DAT_1005b69c + 0x2ec);
  DAT_1005a0ac = fVar3;
  if (fVar4 == 2.8026e-45) {
LAB_1000cc84:
    fVar3 = extraout_EDX;
    if (*(char *)((int)param_1 + 0x41) != '\0') goto LAB_1000cc8b;
  }
  else {
    if (*(char *)((int)param_1 + 0x41) == '\0') {
      if (param_1[0x30] == fVar3) goto LAB_1000cf8f;
      goto LAB_1000cc84;
    }
LAB_1000cc8b:
    FUN_1001c650(param_1,param_1 + 0x11);
    *(undefined1 *)((int)param_1 + 0x41) = 0;
    fVar4 = extraout_ECX;
    fVar3 = extraout_EDX_00;
  }
  FUN_1000d950(fVar4,fVar3,param_1 + 0x11);
  if (*(int *)(PTR_DAT_1005b69c + 0x14) == 8) {
    uVar5 = extraout_EDX_01;
    if (((uint)param_1[0x23] & 1) != 0) {
      FUN_1000cfb0((int *)param_1[0x26] + 2,*(int *)param_1[0x26]);
      uVar5 = extraout_EDX_02;
    }
    if (((uint)param_1[0x23] & 2) != 0) {
      pfVar6 = (float *)((int)param_1[0x22] + 0x3ac);
      local_10 = _DAT_100520d0 /
                 (*(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x78) - _DAT_1005a0b8);
      for (local_14 = *(int *)((int)param_1[0x22] + 8) + -9; -1 < local_14; local_14 = local_14 + -1
          ) {
        local_20 = pfVar6[9] * _DAT_100520d4;
        for (puVar1 = DAT_1005a0b0; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
          if (puVar1[1] == 1) {
            uVar8 = RwDotProduct(pfVar6 + 0x13,uVar5);
            uVar5 = (undefined4)((ulonglong)uVar8 >> 0x20);
            local_28 = (float)extraout_ST0;
            if ((float10)_DAT_100520d8 < extraout_ST0) {
              fVar4 = pfVar6[0xc] * local_28;
joined_r0x1000ce6d:
              if (0x3f333333 < (int)local_28) {
                lVar9 = __ftol();
                uVar5 = (undefined4)((ulonglong)lVar9 >> 0x20);
                fVar4 = *(float *)(DAT_1005a0b4 + (int)lVar9 * 4) * pfVar6[0xf] + fVar4;
              }
              local_20 = (float)puVar1[0x1e] * fVar4 + local_20;
            }
          }
          else {
            RwSubtractVector((float *)(puVar1 + 0x13),pfVar6,local_c);
            uVar8 = RwDotProduct(local_c,pfVar6 + 0x13);
            uVar5 = (undefined4)((ulonglong)uVar8 >> 0x20);
            if ((float10)_DAT_100520d8 < extraout_ST0_00) {
              uVar8 = RwDotProduct(extraout_ECX_00,uVar5);
              uVar5 = (undefined4)((ulonglong)uVar8 >> 0x20);
              local_1c = (float)extraout_ST0_01;
              if (extraout_ST0_01 < (float10)(float)puVar1[0x1c]) {
                if (puVar1[1] == 3) {
                  uVar8 = RwDotProduct(puVar1 + 0x16,uVar5);
                  uVar5 = (undefined4)((ulonglong)uVar8 >> 0x20);
                  local_18 = (float)extraout_ST0_02;
                  local_24 = local_18;
                  if (extraout_ST0_02 < (float10)_DAT_100520d8) {
                    local_24 = -local_18;
                  }
                  if (local_18 * local_24 < (float)puVar1[0x1d] * local_1c) goto LAB_1000cea5;
                }
                if (local_1c <= (float)puVar1[0x1b]) {
                  fVar7 = FUN_10041770((int *)&local_1c);
                  fVar7 = (float10)(float)extraout_ST0_00 / fVar7;
                  uVar5 = extraout_EDX_03;
                }
                else {
                  fVar7 = ((float10)(float)extraout_ST0_00 / (float10)local_1c) *
                          (float10)(float)puVar1[0x1a];
                }
                local_28 = (float)fVar7;
                if (0x3f7f0000 < (int)local_28) {
                  local_28 = 0.99609375;
                }
                fVar4 = pfVar6[0xc] * local_28;
                goto joined_r0x1000ce6d;
              }
            }
          }
LAB_1000cea5:
        }
        if ((*(int *)(PTR_DAT_1005b69c + 0x2ec) == 2) && (_DAT_1005a0b8 < pfVar6[5])) {
          fVar4 = (*(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x78) - pfVar6[5]) * local_10;
          if (fVar4 <= _DAT_100520d8) {
            local_20 = 0.0;
          }
          else {
            local_20 = local_20 * fVar4;
          }
        }
        if ((int)local_20 < 0x41f80000) {
          lVar9 = __ftol();
          uVar5 = (undefined4)((ulonglong)lVar9 >> 0x20);
          pfVar6[0x16] = (float)lVar9;
        }
        else {
          pfVar6[0x16] = 2.8469e-39;
        }
        pfVar6 = pfVar6 + 0x1d;
      }
    }
  }
  else {
    if (((uint)param_1[0x23] & 1) != 0) {
      FUN_1000d230((int *)param_1[0x26] + 2,*(int *)param_1[0x26]);
    }
    if (((uint)param_1[0x23] & 2) != 0) {
      FUN_1000d5c0((int)param_1);
    }
  }
  if (*(int *)(PTR_DAT_1005b69c + 0x2ec) == 2) {
    param_1[0x30] = 0.0;
  }
  else {
    param_1[0x30] = DAT_1005a0ac;
  }
LAB_1000cf8f:
  *(undefined1 *)((int)param_1 + 0x19b) = 0;
  *(undefined1 *)((int)param_1 + 0x19a) = 0;
  return;
}


