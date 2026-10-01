// 004080db FUN_004080db [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall
FUN_004080db(int param_1,int param_2,float *param_3,int param_4,int *param_5,undefined4 param_6,
            undefined4 param_7,float *param_8,float *param_9,float *param_10,float *param_11)

{
  double dVar1;
  float fVar2;
  int in_EAX;
  int *extraout_EAX;
  int *extraout_EAX_00;
  float *pfVar3;
  int iVar4;
  uint uVar5;
  float *pfVar6;
  int unaff_EBX;
  float *pfVar7;
  float *pfVar8;
  float10 fVar9;
  uint uStack_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 local_70;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int local_1c;
  float local_14;
  float local_10;
  
  local_30 = 0.0;
  local_38 = 0.0;
  local_2c = 0.0;
  local_28 = 0.0;
  *param_9 = 0.0;
  local_10 = 0.0;
  local_24 = 0.0;
  local_34 = 0.0;
  *param_5 = 0;
  local_14 = 0.0;
  iVar4 = (*(int *)(in_EAX + 0x14) - *(int *)(in_EAX + 8)) + 1 >> 1;
  local_1c = *(int *)(in_EAX + 8) + (param_1 + -1) * iVar4 + 1;
  iVar4 = iVar4 + local_1c;
  if (0.0 <= *(float *)(param_2 + -4 + local_1c * 4) - *param_3) {
    uVar5 = 0x3ff00000;
  }
  else {
    uVar5 = 0xbff00000;
  }
  local_20 = (float)(double)((ulonglong)uVar5 << 0x20);
  pfVar7 = (float *)(unaff_EBX + local_1c * 4);
  pfVar6 = (float *)(local_1c * 4 + param_2);
  pfVar3 = pfVar7 + param_4;
  pfVar8 = pfVar7 + -param_4;
  while (local_1c <= iVar4 + -1) {
    local_30 = ABS(*pfVar6) + local_30;
    local_38 = ABS(*pfVar6 - pfVar6[-1]) + local_38;
    local_2c = *pfVar6 * *pfVar6 + local_2c;
    *param_9 = *pfVar6 * pfVar6[-1] + *param_9;
    local_24 = *pfVar7 * *pfVar7 + local_24;
    local_28 = *pfVar8 * *pfVar8 + local_28;
    local_34 = *pfVar3 * *pfVar3 + local_34;
    local_10 = *pfVar7 * *pfVar3 + local_10;
    local_14 = *pfVar7 * *pfVar8 + local_14;
    if (0.0 <= *pfVar6 + *param_3) {
      uStack_cc = 0x3ff00000;
    }
    else {
      uStack_cc = 0xbff00000;
    }
    if ((double)((ulonglong)uStack_cc << 0x20) != (double)local_20) {
      local_20 = -local_20;
      *param_5 = *param_5 + 1;
    }
    pfVar3 = pfVar3 + 1;
    pfVar8 = pfVar8 + 1;
    pfVar7 = pfVar7 + 1;
    pfVar6 = pfVar6 + 1;
    local_1c = local_1c + 1;
    *param_3 = -*param_3;
  }
  if ((int)local_2c < 0x3f800001) {
    local_2c = 1.0;
  }
  *param_9 = *param_9 / local_2c;
  dVar1 = (double)(local_30 * (float)_DAT_0043575c);
  if (dVar1 <= 1.0) {
    uStack_c4 = 0x3ff00000;
    local_70 = 0;
  }
  else {
    local_c8 = SUB84(dVar1,0);
    local_70 = local_c8;
    uStack_c4 = (undefined4)((ulonglong)dVar1 >> 0x20);
  }
  *param_8 = local_38 / (float)(double)CONCAT44(uStack_c4,local_70);
  if ((int)local_28 < 0x3f800001) {
    local_28 = 1.0;
  }
  fVar2 = local_24;
  if ((int)local_24 < 0x3f800001) {
    fVar2 = 1.0;
  }
  *param_10 = (local_14 * local_14) / (local_28 * fVar2);
  if ((int)local_34 < 0x3f800001) {
    local_34 = 1.0;
  }
  if ((int)local_24 < 0x3f800001) {
    local_24 = 1.0;
  }
  *param_11 = (local_10 / local_24) * (local_10 / local_34);
  fVar9 = FUN_0042b8ce();
  *param_5 = (int)ROUND(fVar9);
  fVar9 = FUN_0042b8ce();
  *extraout_EAX = (int)ROUND(fVar9);
  fVar9 = FUN_0042b8ce();
  *extraout_EAX_00 = (int)ROUND(fVar9);
  return;
}


