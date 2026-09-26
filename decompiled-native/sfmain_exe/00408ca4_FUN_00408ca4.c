// 00408ca4 FUN_00408ca4 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall
FUN_00408ca4(int param_1,int param_2,float param_3,float param_4,int param_5,undefined4 param_6,
            int param_7,int *param_8)

{
  float *pfVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar6;
  undefined4 extraout_ECX_02;
  int iVar7;
  int extraout_EDX;
  int extraout_EDX_00;
  bool bVar8;
  float10 fVar9;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  undefined8 uVar10;
  float local_bc [29];
  float local_48;
  int local_44;
  float local_40;
  float local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  float local_20;
  int local_1c;
  int local_18;
  int local_14;
  float local_10;
  
  local_14 = 3000;
  if (DAT_00438560 != 0) {
    DAT_0043fe4c = 3000;
    DAT_0043fe44 = 3000;
    DAT_0043fe40 = 0xbb;
    DAT_0043fe3c = 0xbb;
    DAT_0043fe08 = 0x44160000;
    DAT_0043fe48 = 0x5d;
    DAT_0043fe38 = 0x5d;
    _DAT_0043fe6c = 1024.0;
    _DAT_0043fe10 = 0x43960000;
    DAT_00438560 = 0;
    _DAT_0043fe0c = 0x43e10000;
    _DAT_0043fe18 = 0;
    _DAT_0043fe14 = 0x43480000;
    iVar7 = 0;
    do {
      iVar4 = iVar7 + 4;
      *(undefined4 *)((int)&DAT_0043fe5c + iVar7) = 0;
      *(undefined4 *)((int)&DAT_0043fe50 + iVar7) = 0;
      iVar7 = iVar4;
    } while (iVar4 != 0xc);
  }
  if (param_1 == 1) {
    DAT_0043fe50 = DAT_0043fe54;
    DAT_0043fe5c = DAT_0043fe60;
    DAT_0043fe54 = DAT_0043fe58;
    DAT_0043fe60 = DAT_0043fe64;
    if ((int)param_3 < 0x3f800001) {
      param_3 = 1.0;
    }
    DAT_0043fe68 = param_4 / param_3;
  }
  FUN_004080db(param_1,param_2,(float *)&DAT_00438558,param_5,&local_34,&local_1c,&local_44,
               &local_48,&local_3c,&local_20,&local_40);
  if (DAT_0043fe40 < 2) {
    local_24 = 1;
  }
  else {
    local_24 = DAT_0043fe40;
  }
  fVar9 = FUN_0042b8ce();
  _DAT_0043fe6c = (float)fVar9;
  local_18 = extraout_ECX;
  if (extraout_ECX < 2) {
    local_18 = 1;
  }
  local_10 = ((float)DAT_0043fe40 * _DAT_0043fe6c) / (float)local_18;
  iVar4 = 1;
  for (iVar7 = 4; (iVar7 < DAT_004383c0 * 4 && (local_10 <= *(float *)(iVar7 + 0x43fe04)));
      iVar7 = iVar7 + 4) {
    iVar4 = iVar4 + 1;
  }
  if (DAT_0043fe4c < 2) {
    local_28 = 1;
  }
  else {
    local_28 = DAT_0043fe4c;
  }
  iVar7 = param_1 + -1;
  iVar4 = iVar4 * 4;
  iVar5 = 4;
  (&DAT_0043fe58)[iVar7 * 3] = (float)*(undefined4 *)(iVar4 + 0x438528);
  do {
    pfVar1 = (float *)((int)&DAT_004383c0 + iVar4);
    iVar3 = iVar5 + -4;
    iVar5 = iVar5 + 4;
    iVar4 = iVar4 + 0x28;
    (&DAT_0043fe58)[iVar7 * 3] =
         *pfVar1 * *(float *)((int)local_bc + iVar3) + (&DAT_0043fe58)[iVar7 * 3];
  } while (iVar5 != 0x28);
  param_8[param_1 * 4 + -1] = (uint)(0.0 < (&DAT_0043fe58)[iVar7 * 3]);
  if (param_1 == 1) goto switchD_00409007_caseD_0;
  if ((((*(byte *)(param_7 + 4) & 2) == 0) && (*(int *)(param_7 + 8) != 1)) ||
     ((*(byte *)(param_7 + 0xc) & 1) != 0)) {
    bVar8 = false;
  }
  else {
    bVar8 = true;
  }
  _DAT_00438554 = param_8[5] * 4 + param_8[1] * 8 + param_8[2] * 2 + param_8[6];
  switch(_DAT_00438554) {
  default:
    goto switchD_00409007_caseD_0;
  case 1:
    if (!bVar8) goto switchD_00409007_caseD_0;
    iVar7 = param_8[3];
    bVar8 = iVar7 == 1;
    goto LAB_0040901e;
  case 2:
    if ((param_8[3] == 0) || (DAT_0043fe54 < -DAT_0043fe60)) {
LAB_0040913b:
      param_8[2] = 0;
      goto switchD_00409007_caseD_0;
    }
    goto LAB_00409147;
  case 4:
    break;
  case 5:
    if (-DAT_0043fe54 <= DAT_0043fe5c) goto LAB_00409166;
    break;
  case 6:
    if (((*param_8 != 1) && (param_8[3] != 1)) && (DAT_0043fe60 <= DAT_0043fe50)) {
      param_8[1] = 1;
      goto switchD_00409007_caseD_0;
    }
LAB_00409147:
    param_8[6] = 1;
    goto switchD_00409007_caseD_0;
  case 7:
    if (!bVar8) goto switchD_00409007_caseD_0;
    break;
  case 8:
    if (!bVar8) goto switchD_00409007_caseD_0;
  case 0xb:
switchD_00409007_caseD_b:
    param_8[5] = 1;
    goto switchD_00409007_caseD_0;
  case 10:
    if (DAT_0043fe54 < -DAT_0043fe5c) goto LAB_0040913b;
    goto switchD_00409007_caseD_b;
  case 0xd:
    if ((param_8[3] == 0) && (DAT_0043fe60 < -DAT_0043fe54)) {
      param_8[6] = 0;
      goto switchD_00409007_caseD_0;
    }
LAB_00409166:
    param_8[2] = 1;
    goto switchD_00409007_caseD_0;
  case 0xe:
    if (!bVar8) goto switchD_00409007_caseD_0;
    iVar7 = param_8[3];
    bVar8 = iVar7 == 0;
LAB_0040901e:
    if (bVar8) {
      param_8[2] = iVar7;
    }
    goto switchD_00409007_caseD_0;
  }
  param_8[5] = 0;
switchD_00409007_caseD_0:
  if (param_8[param_1 * 4 + -1] == 0) {
    iVar7 = DAT_0043fe3c * 3;
    if (local_44 < DAT_0043fe3c * 3) {
      iVar7 = local_44;
    }
    local_38 = DAT_0043fe34 * 0x3f + iVar7 * 8;
    fVar9 = FUN_0042b8ce();
    DAT_0043fe34 = (int)ROUND(fVar9);
    DAT_0043fe40 = (int)((DAT_0043fe34 + (DAT_0043fe34 >> 0x1f) * -8) -
                        (uint)((DAT_0043fe34 >> 0x1f) << 2 < 0)) >> 3;
    DAT_0043fe3c = local_44;
    iVar7 = DAT_0043fe38 * 3;
    if (local_1c < DAT_0043fe38 * 3) {
      iVar7 = local_1c;
    }
    local_38 = DAT_0043855c * 0x3f + iVar7 * 8;
    fVar9 = FUN_0042b8ce();
    DAT_0043855c = (int)ROUND(fVar9);
    iVar4 = DAT_0043855c >> 0x1f;
    iVar7 = iVar4 * 8;
    DAT_0043fe48 = (int)((DAT_0043855c + iVar4 * -8) - (uint)(iVar4 << 2 < 0)) >> 3;
    DAT_0043fe38 = local_1c;
    uVar6 = extraout_ECX_00;
  }
  else {
    local_38 = local_1c + DAT_0043fe4c * 0x3f;
    fVar9 = FUN_0042b8ce();
    DAT_0043fe4c = (int)ROUND(fVar9);
    local_38 = extraout_EDX;
    fVar9 = FUN_0042b8ce();
    DAT_0043fe44 = (int)ROUND(fVar9);
    uVar6 = extraout_ECX_01;
    iVar7 = extraout_EDX_00;
  }
  local_30 = DAT_0043fe48 * DAT_0043fe4c;
  uVar10 = FUN_0042b7a8(uVar6,iVar7);
  dVar2 = (double)(extraout_ST0 * (float10)_DAT_004357e4) / (double)local_14;
  if (dVar2 <= 1.0) {
    dVar2 = 1.0;
  }
  if (_DAT_004357ec <= dVar2) {
    _DAT_00438558 = 20.0;
  }
  else {
    local_2c = DAT_0043fe48 * DAT_0043fe4c;
    FUN_0042b7a8(extraout_ECX_02,(int)((ulonglong)uVar10 >> 0x20));
    _DAT_00438558 = (float)(extraout_ST0_00 * (float10)_DAT_004357e4) / (float)local_14;
    if (_DAT_00438558 <= 1.0) {
      _DAT_00438558 = 1.0;
    }
  }
  return;
}


