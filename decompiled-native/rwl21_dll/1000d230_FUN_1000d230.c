// 1000d230 FUN_1000d230 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000d230(int *param_1,int param_2)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 extraout_ECX;
  int iVar5;
  int iVar6;
  int extraout_EDX;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 fVar7;
  undefined8 uVar8;
  longlong lVar9;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c [3];
  
  iVar5 = param_2 + -1;
  local_10 = _DAT_100520d0 / (*(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x78) - _DAT_1005a0b8);
  iVar6 = iVar5;
  puVar4 = DAT_1005a0b0;
  do {
    if (iVar5 < 0) {
      DAT_1005a0b0 = puVar4;
      return;
    }
    piVar2 = (int *)*param_1;
    param_1 = param_1 + 1;
    iVar3 = *piVar2;
    local_24 = *(float *)(iVar3 + 0xc) * _DAT_100520d4;
    local_20 = *(float *)(iVar3 + 0x10) * _DAT_100520d4;
    local_1c = *(float *)(iVar3 + 0x14) * _DAT_100520d4;
    DAT_1005a0b0 = puVar4;
    for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
      if (puVar4[1] == 1) {
        uVar8 = RwDotProduct(piVar2 + 4,iVar6);
        iVar6 = (int)((ulonglong)uVar8 >> 0x20);
        local_30 = (float)extraout_ST0;
        if ((float10)_DAT_100520d8 < extraout_ST0) {
          iVar3 = *piVar2;
          local_2c = *(float *)(iVar3 + 0x18) * local_30;
          local_28 = *(float *)(iVar3 + 0x1c) * local_30;
          local_18 = *(float *)(iVar3 + 0x20) * local_30;
joined_r0x1000d41f:
          if (0x3f333333 < (int)local_30) {
            lVar9 = __ftol();
            iVar6 = (int)((ulonglong)lVar9 >> 0x20);
            fVar1 = *(float *)(DAT_1005a0b4 + (int)lVar9 * 4);
            local_2c = *(float *)(iVar3 + 0x24) * fVar1 + local_2c;
            local_28 = *(float *)(iVar3 + 0x28) * fVar1 + local_28;
            local_18 = fVar1 * *(float *)(iVar3 + 0x2c) + local_18;
          }
          local_24 = (float)puVar4[0x1e] * local_2c + local_24;
          local_20 = (float)puVar4[0x1f] * local_28 + local_20;
          local_1c = (float)puVar4[0x20] * local_18 + local_1c;
        }
      }
      else {
        RwSubtractVector((float *)(puVar4 + 0x13),(float *)(piVar2 + 7),local_c);
        uVar8 = RwDotProduct(local_c,piVar2 + 4);
        iVar6 = (int)((ulonglong)uVar8 >> 0x20);
        if ((float10)_DAT_100520d8 < extraout_ST0_00) {
          uVar8 = RwDotProduct(extraout_ECX,iVar6);
          iVar6 = (int)((ulonglong)uVar8 >> 0x20);
          local_14 = (float)extraout_ST0_01;
          if (extraout_ST0_01 < (float10)(float)puVar4[0x1c]) {
            if (puVar4[1] == 3) {
              uVar8 = RwDotProduct(puVar4 + 0x16,iVar6);
              iVar6 = (int)((ulonglong)uVar8 >> 0x20);
              fVar1 = (float)extraout_ST0_02;
              local_2c = fVar1;
              if (extraout_ST0_02 < (float10)_DAT_100520d8) {
                local_2c = -fVar1;
              }
              if (fVar1 * local_2c < (float)puVar4[0x1d] * local_14) goto LAB_1000d49e;
            }
            if (local_14 <= (float)puVar4[0x1b]) {
              fVar7 = FUN_10041770((int *)&local_14);
              fVar7 = (float10)(float)extraout_ST0_00 / fVar7;
              iVar6 = extraout_EDX;
            }
            else {
              fVar7 = ((float10)(float)extraout_ST0_00 / (float10)local_14) *
                      (float10)(float)puVar4[0x1a];
            }
            local_30 = (float)fVar7;
            if (0x3f7f0000 < (int)local_30) {
              local_30 = 0.99609375;
            }
            iVar3 = *piVar2;
            local_2c = *(float *)(iVar3 + 0x18) * local_30;
            local_28 = *(float *)(iVar3 + 0x1c) * local_30;
            local_18 = *(float *)(iVar3 + 0x20) * local_30;
            goto joined_r0x1000d41f;
          }
        }
      }
LAB_1000d49e:
    }
    if ((*(int *)(PTR_DAT_1005b69c + 0x2ec) == 2) &&
       (_DAT_1005a0b8 < *(float *)(piVar2[0xf] + 0x14))) {
      iVar6 = *(int *)(PTR_DAT_1005b69c + 0x10);
      fVar1 = (*(float *)(iVar6 + 0x78) - *(float *)(piVar2[0xf] + 0x14)) * local_10;
      if (fVar1 <= _DAT_100520d8) {
        local_1c = 0.0;
        local_20 = 0.0;
        local_24 = 0.0;
      }
      else {
        local_24 = local_24 * fVar1;
        local_20 = local_20 * fVar1;
        local_1c = local_1c * fVar1;
      }
    }
    if ((int)local_24 < 0x41f80000) {
      lVar9 = __ftol();
      iVar6 = (int)((ulonglong)lVar9 >> 0x20);
      piVar2[1] = (int)lVar9;
    }
    else {
      piVar2[1] = 0x1f0000;
    }
    if ((int)local_20 < 0x41f80000) {
      lVar9 = __ftol();
      iVar6 = (int)((ulonglong)lVar9 >> 0x20);
      piVar2[2] = (int)lVar9;
    }
    else {
      piVar2[2] = 0x1f0000;
    }
    if ((int)local_1c < 0x41f80000) {
      lVar9 = __ftol();
      iVar6 = (int)((ulonglong)lVar9 >> 0x20);
      piVar2[3] = (int)lVar9;
    }
    else {
      piVar2[3] = 0x1f0000;
    }
    iVar5 = iVar5 + -1;
    puVar4 = DAT_1005a0b0;
  } while( true );
}


