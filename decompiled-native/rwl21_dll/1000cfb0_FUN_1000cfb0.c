// 1000cfb0 FUN_1000cfb0 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000cfb0(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  float fVar4;
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
  puVar3 = DAT_1005a0b0;
  do {
    if (iVar5 < 0) {
      DAT_1005a0b0 = puVar3;
      return;
    }
    piVar1 = (int *)*param_1;
    param_1 = param_1 + 1;
    local_1c = *(float *)(*piVar1 + 0xc) * _DAT_100520d4;
    DAT_1005a0b0 = puVar3;
    for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
      if (puVar3[1] == 1) {
        uVar8 = RwDotProduct(piVar1 + 4,iVar6);
        iVar6 = (int)((ulonglong)uVar8 >> 0x20);
        local_24 = (float)extraout_ST0;
        if ((float10)_DAT_100520d8 < extraout_ST0) {
          iVar2 = *piVar1;
          fVar4 = *(float *)(iVar2 + 0x18) * local_24;
joined_r0x1000d14f:
          if (0x3f333333 < (int)local_24) {
            lVar9 = __ftol();
            iVar6 = (int)((ulonglong)lVar9 >> 0x20);
            fVar4 = *(float *)(DAT_1005a0b4 + (int)lVar9 * 4) * *(float *)(iVar2 + 0x24) + fVar4;
          }
          local_1c = (float)puVar3[0x1e] * fVar4 + local_1c;
        }
      }
      else {
        RwSubtractVector((float *)(puVar3 + 0x13),(float *)(piVar1 + 7),local_c);
        uVar8 = RwDotProduct(local_c,piVar1 + 4);
        iVar6 = (int)((ulonglong)uVar8 >> 0x20);
        if ((float10)_DAT_100520d8 < extraout_ST0_00) {
          uVar8 = RwDotProduct(extraout_ECX,iVar6);
          iVar6 = (int)((ulonglong)uVar8 >> 0x20);
          local_18 = (float)extraout_ST0_01;
          if (extraout_ST0_01 < (float10)(float)puVar3[0x1c]) {
            if (puVar3[1] == 3) {
              uVar8 = RwDotProduct(puVar3 + 0x16,iVar6);
              iVar6 = (int)((ulonglong)uVar8 >> 0x20);
              local_14 = (float)extraout_ST0_02;
              local_20 = local_14;
              if (extraout_ST0_02 < (float10)_DAT_100520d8) {
                local_20 = -local_14;
              }
              if (local_14 * local_20 < (float)puVar3[0x1d] * local_18) goto LAB_1000d187;
            }
            if (local_18 <= (float)puVar3[0x1b]) {
              fVar7 = FUN_10041770((int *)&local_18);
              fVar7 = (float10)(float)extraout_ST0_00 / fVar7;
              iVar6 = extraout_EDX;
            }
            else {
              fVar7 = ((float10)(float)extraout_ST0_00 / (float10)local_18) *
                      (float10)(float)puVar3[0x1a];
            }
            local_24 = (float)fVar7;
            if (0x3f7f0000 < (int)local_24) {
              local_24 = 0.99609375;
            }
            iVar2 = *piVar1;
            fVar4 = *(float *)(iVar2 + 0x18) * local_24;
            goto joined_r0x1000d14f;
          }
        }
      }
LAB_1000d187:
    }
    if ((*(int *)(PTR_DAT_1005b69c + 0x2ec) == 2) &&
       (_DAT_1005a0b8 < *(float *)(piVar1[0xf] + 0x14))) {
      iVar6 = *(int *)(PTR_DAT_1005b69c + 0x10);
      fVar4 = (*(float *)(iVar6 + 0x78) - *(float *)(piVar1[0xf] + 0x14)) * local_10;
      if (fVar4 <= _DAT_100520d8) {
        local_1c = 0.0;
      }
      else {
        local_1c = fVar4 * local_1c;
      }
    }
    if ((int)local_1c < 0x41f80000) {
      lVar9 = __ftol();
      iVar6 = (int)((ulonglong)lVar9 >> 0x20);
      piVar1[1] = (int)lVar9;
    }
    else {
      piVar1[1] = 0x1f0000;
    }
    iVar5 = iVar5 + -1;
    puVar3 = DAT_1005a0b0;
  } while( true );
}


