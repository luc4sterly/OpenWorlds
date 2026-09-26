// 0040b910 FUN_0040b910 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_0040b910(undefined4 param_1,int param_2,int *param_3)

{
  float fVar1;
  int iVar2;
  int in_EAX;
  int extraout_EAX;
  int extraout_EAX_00;
  int *extraout_ECX;
  int extraout_EDX;
  int iVar3;
  int iVar4;
  int unaff_EBX;
  float *pfVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  int aiStack_4c [6];
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  float local_24;
  float local_20;
  int local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  local_28 = 2;
  if (unaff_EBX == 1) {
    _DAT_004452c8 =
         _DAT_004452c8 * (float)_DAT_004358f4 +
         *(float *)(param_2 * 4 + in_EAX) * (float)_DAT_004358ec;
  }
  else {
    _DAT_004452c8 = _DAT_004452c8 * (float)_DAT_004358e4;
  }
  local_10 = _DAT_004452c8 * (float)_DAT_004358fc;
  if ((unaff_EBX == 0) && (_DAT_004452c8 < _DAT_00435904)) {
    local_10 = 8.0;
  }
  aiStack_4c[0] = 0x40b99f;
  local_30 = in_EAX;
  fVar8 = FUN_0042b8ce();
  iVar2 = local_28;
  local_34 = (int)ROUND(fVar8);
  *(int *)(&DAT_004403ac + local_34 * 4) = extraout_EDX;
  local_18 = DAT_00440590;
  iVar3 = 4;
  iVar7 = extraout_EDX;
  iVar6 = extraout_EDX;
  iVar4 = local_34 * 4;
  do {
    local_18 = local_18 + local_10;
    if (*(float *)(&DAT_0044058c + iVar3) <= local_18) {
      local_18 = *(float *)(&DAT_0044058c + iVar3);
      *(int *)(&DAT_004403ac + iVar4) = iVar6;
      iVar7 = iVar6;
    }
    else {
      *(int *)(&DAT_004403ac + iVar4) = iVar7;
      *(float *)(&DAT_0044058c + iVar3) = local_18;
    }
    iVar6 = iVar6 + 1;
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 8;
  } while (iVar6 < 0x3d);
  iVar4 = iVar7 + -1;
  local_14 = (&DAT_00440590)[iVar4];
  local_2c = local_34 * 4;
  for (; 0 < iVar4; iVar4 = iVar4 + -1) {
    local_14 = local_14 + local_10;
    iVar6 = iVar4 * 8 + local_2c;
    if (*(float *)(&DAT_0044058c + iVar4 * 4) <= local_14) {
      iVar4 = *(int *)(&DAT_004403a4 + iVar6);
      local_14 = *(float *)(&DAT_0044058c + iVar4 * 4);
      iVar7 = iVar4;
    }
    else {
      *(int *)(&DAT_004403a4 + iVar6) = iVar7;
      *(float *)(&DAT_0044058c + iVar4 * 4) = local_14;
    }
  }
  iVar7 = 2;
  local_24 = *(float *)(local_30 + 4) * (float)_DAT_004358ec + DAT_00440590;
  iVar4 = 8;
  pfVar5 = (float *)(local_30 + 8);
  DAT_00440590 = local_24;
  *param_3 = 1;
  local_20 = local_24;
  do {
    fVar1 = *pfVar5 * (float)_DAT_004358ec + *(float *)(&DAT_0044058c + iVar4);
    *(float *)(&DAT_0044058c + iVar4) = fVar1;
    if (local_24 < fVar1) {
      local_24 = *(float *)(&DAT_0044058c + iVar4);
    }
    if (*(float *)(&DAT_0044058c + iVar4) < local_20) {
      *param_3 = iVar7;
      local_20 = *(float *)(&DAT_0044058c + iVar4);
    }
    pfVar5 = pfVar5 + 1;
    iVar7 = iVar7 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar7 < 0x3d);
  iVar4 = 4;
  do {
    iVar7 = iVar4 + 4;
    *(float *)(&DAT_0044058c + iVar4) = *(float *)(&DAT_0044058c + iVar4) - local_20;
    iVar4 = iVar7;
  } while (iVar7 != 0xf4);
  local_1c = 0;
  local_24 = local_24 - local_20;
  iVar7 = 0x14;
  iVar4 = *param_3 * 4 + -0x50;
  do {
    if ((iVar7 < *param_3) && (*(float *)(&DAT_0044058c + iVar4) < local_24 * (float)_DAT_00435908))
    {
      local_1c = iVar7;
    }
    iVar7 = iVar7 + 10;
    iVar4 = iVar4 + -0x28;
  } while (iVar7 < 0x29);
  aiStack_4c[0] = 0x40bb95;
  fVar8 = FUN_0042b8ce();
  iVar7 = local_28;
  iVar4 = *param_3;
  local_1c = (int)ROUND(fVar8);
  *param_3 = iVar4 - extraout_EAX;
  *extraout_ECX = iVar4 - extraout_EAX;
  for (iVar4 = 4; iVar4 <= iVar2 * 4; iVar4 = iVar4 + 4) {
    local_1c = local_1c % iVar7 + 1;
    iVar6 = *(int *)(&DAT_004403a4 + *extraout_ECX * 8 + local_1c * 4);
    *extraout_ECX = iVar6;
    *(int *)((int)aiStack_4c + iVar4) = iVar6;
  }
  aiStack_4c[0] = 0x40bbe8;
  fVar8 = FUN_0042b8ce();
  iVar4 = (int)ROUND(fVar8) + extraout_EAX_00 + -1;
  _DAT_00438c88 = (float)(iVar4 % local_28);
  return iVar4 / local_28;
}


