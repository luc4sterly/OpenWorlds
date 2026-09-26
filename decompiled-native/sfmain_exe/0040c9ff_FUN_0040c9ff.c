// 0040c9ff FUN_0040c9ff [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040c9ff(float *param_1,int param_2,float param_3,float param_4,float param_5)

{
  float *pfVar1;
  float fVar2;
  float10 fVar3;
  float *in_EAX;
  int iVar4;
  float *pfVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 extraout_ECX;
  float extraout_ECX_00;
  float fVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int unaff_EBX;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  undefined8 uVar12;
  float afStack_2e4 [156];
  double local_74;
  double local_6c;
  double local_64;
  float local_5c;
  float local_58;
  float *local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  int local_28;
  int local_24;
  float local_20;
  int local_1c;
  float local_18;
  float local_14;
  int local_10;
  
  local_64 = (double)(param_3 + (float)_DAT_00435a40);
  _DAT_0043925c = _DAT_0043925c / (param_3 + (float)_DAT_00435a40);
  uVar7 = 0x3f400000;
  local_48 = 0.125;
  local_30 = 0.75;
  local_34 = 0.125;
  local_2c = -0.125;
  local_44 = 0.25;
  local_4c = -0.125;
  local_6c = (double)_DAT_0043925c;
  local_74 = local_6c;
  if ((float)_DAT_00435a48 <= _DAT_0043925c) {
    uVar7 = 0;
    local_74 = 8.0;
  }
  local_38 = (float)local_74;
  _DAT_0043925c = param_3;
  iVar9 = DAT_00439258 << 2;
  iVar10 = 0;
  do {
    pfVar5 = (float *)((int)&DAT_00441d38 + iVar9);
    iVar4 = iVar10 + 4;
    iVar9 = iVar9 + 4;
    *(float *)((int)&DAT_00441d38 + iVar10) = *pfVar5 * local_38;
    iVar10 = iVar4;
  } while (iVar4 != 0x28);
  DAT_00439258 = param_2;
  local_54 = param_1;
  local_1c = param_2;
  if (unaff_EBX == 0) {
    for (iVar10 = 0; iVar10 < param_2 * 4; iVar10 = iVar10 + 4) {
      uVar12 = FUN_0040999a(uVar7,iVar10);
      iVar10 = (int)((ulonglong)uVar12 >> 0x20);
      local_10 = (int)uVar12 >> 6;
      *(float *)((int)&DAT_004424d8 + iVar10) = (float)local_10;
      uVar7 = extraout_ECX;
    }
    uVar12 = FUN_0040999a(uVar7,iVar10);
    local_50 = param_4 * (float)_DAT_00435a58;
    iVar10 = (((int)uVar12 + 0x8000) * (local_1c + -1) >> 0x10) + 0xb;
    if (_DAT_00435a60 < local_50) {
      local_50 = 2000.0;
    }
    *(float *)(&DAT_004424ac + iVar10 * 4) = *(float *)(&DAT_004424ac + iVar10 * 4) + local_50;
    (&DAT_004424b0)[iVar10] = (float)(&DAT_004424b0)[iVar10] - local_50;
  }
  else {
    FUN_0042b7a8(uVar7,iVar9);
    fVar3 = (float10)_DAT_00435a50;
    local_3c = (float)(extraout_ST0 * fVar3);
    iVar10 = 0;
    fVar8 = extraout_ECX_00;
    for (iVar9 = 0; iVar9 < local_1c; iVar9 = iVar9 + 1) {
      *(undefined4 *)((int)&DAT_004424d8 + iVar10) = 0;
      if (iVar9 < 0x1a) {
        *(float *)((int)&DAT_004424d8 + iVar10) =
             (float)(extraout_ST0 * fVar3) * *(float *)((int)&DAT_004391f4 + iVar10);
      }
      local_58 = *(float *)((int)&DAT_004424d8 + iVar10);
      *(float *)((int)&DAT_004424d8 + iVar10) =
           local_34 * _DAT_00439264 + local_30 * DAT_00439260 + local_48 * local_58;
      _DAT_00439264 = DAT_00439260;
      iVar10 = iVar10 + 4;
      fVar8 = DAT_00439260;
      DAT_00439260 = local_58;
    }
    iVar9 = local_1c * 4;
    for (iVar10 = 0; iVar10 < iVar9; iVar10 = iVar10 + 4) {
      uVar12 = FUN_0040999a(fVar8,iVar10);
      iVar10 = (int)((ulonglong)uVar12 >> 0x20);
      local_10 = (int)uVar12 >> 6;
      *(float *)((int)afStack_2e4 + iVar10) = (float)local_10;
      fVar2 = *(float *)((int)afStack_2e4 + iVar10);
      local_5c = fVar2;
      *(float *)((int)afStack_2e4 + iVar10) =
           local_4c * _DAT_0043926c + local_44 * DAT_00439268 + local_2c * fVar2;
      _DAT_0043926c = DAT_00439268;
      fVar8 = DAT_00439268;
      DAT_00439268 = fVar2;
    }
    for (iVar10 = 0; iVar10 < local_1c * 4; iVar10 = iVar10 + 4) {
      *(float *)((int)&DAT_004424d8 + iVar10) =
           *(float *)((int)afStack_2e4 + iVar10) + *(float *)((int)&DAT_004424d8 + iVar10);
    }
  }
  local_20 = 0.0;
  iVar9 = 0x28;
  for (iVar10 = 0; iVar10 < local_1c; iVar10 = iVar10 + 1) {
    local_24 = iVar10 + 10;
    local_14 = 0.0;
    pfVar5 = in_EAX;
    iVar4 = iVar9;
    do {
      fVar8 = *pfVar5;
      pfVar1 = (float *)(&DAT_004424ac + iVar4);
      iVar4 = iVar4 + -4;
      pfVar5 = pfVar5 + 1;
      local_14 = fVar8 * *pfVar1 + local_14;
    } while (pfVar5 != in_EAX + 10);
    local_14 = local_14 * param_5;
    iVar9 = iVar9 + 4;
    (&DAT_00441d38)[local_24] = local_14 + (float)(&DAT_004424b0)[local_24];
  }
  iVar9 = 0x28;
  for (iVar10 = 0; iVar10 < local_1c; iVar10 = iVar10 + 1) {
    local_28 = iVar10 + 10;
    local_18 = 0.0;
    pfVar5 = in_EAX;
    iVar4 = iVar9;
    do {
      fVar8 = *pfVar5;
      pfVar1 = (float *)(iVar4 + 0x441d34);
      iVar4 = iVar4 + -4;
      pfVar5 = pfVar5 + 1;
      local_18 = fVar8 * *pfVar1 + local_18;
    } while (pfVar5 != in_EAX + 10);
    fVar8 = (float)(&DAT_00441d38)[local_28];
    (&DAT_00441d38)[local_28] = fVar8 + local_18;
    iVar9 = iVar9 + 4;
    local_20 = (fVar8 + local_18) * (float)(&DAT_00441d38)[local_28] + local_20;
  }
  iVar9 = 0;
  iVar4 = local_1c << 2;
  do {
    iVar11 = iVar4 + 4;
    *(undefined4 *)((int)&DAT_004424b0 + iVar9) = *(undefined4 *)((int)&DAT_004424b0 + iVar4);
    iVar6 = iVar9 + 4;
    *(undefined4 *)((int)&DAT_00441d38 + iVar9) = *(undefined4 *)((int)&DAT_00441d38 + iVar4);
    iVar9 = iVar6;
    iVar4 = iVar11;
  } while (iVar6 != 0x28);
  FUN_0042b7a8(iVar10,iVar11);
  for (iVar10 = 0; iVar10 < local_1c; iVar10 = iVar10 + 1) {
    *local_54 = (float)extraout_ST0_00 * (float)(&DAT_00441d60)[iVar10];
    local_54 = local_54 + 1;
  }
  return;
}


