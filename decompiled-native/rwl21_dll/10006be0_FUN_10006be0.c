// 10006be0 FUN_10006be0 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall
FUN_10006be0(undefined4 param_1,undefined4 param_2,float *param_3,float *param_4,int param_5,
            int *param_6,float *param_7)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 extraout_EDX;
  int *piVar7;
  int iVar8;
  longlong lVar9;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  uint uStack_fc;
  float local_f8;
  float local_f4;
  int local_f0;
  code *pcStack_ec;
  undefined4 uStack_e8;
  float local_e4 [2];
  float local_dc [2];
  float local_d4 [2];
  float local_cc [2];
  undefined4 auStack_c4 [14];
  undefined1 uStack_8a;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  
  if (param_3[99] != 1.4013e-45) {
    FUN_10030b50(param_3);
    FUN_10030b90(param_3,param_5);
    param_2 = extraout_EDX;
  }
  FUN_1001c440(param_5 + 0xbc,param_2,param_3,param_5 + 0xbc,param_4);
  iVar8 = (int)param_3[0x22] + 0xc;
  uVar5 = FUN_10006450(param_5,param_4,iVar8,local_e4,local_dc,local_d4,local_cc,&local_f8);
  if (uVar5 == 0) {
    local_f0 = *(int *)(PTR_DAT_1005b69c + 0x10);
    *(int *)(PTR_DAT_1005b69c + 0x10) = param_5;
    (**(code **)(PTR_DAT_1005b69c + 0x294))(iVar8,8,param_4,param_5,1);
    *(int *)(PTR_DAT_1005b69c + 0x10) = local_f0;
    fVar1 = param_3[0x22];
    local_110 = *(int *)((int)fVar1 + 0x24);
    local_10c = *(int *)((int)fVar1 + 0x28);
    piVar7 = (int *)((int)fVar1 + 0x98);
    iVar8 = 7;
    local_108 = local_110;
    local_104 = local_10c;
    do {
      iVar2 = *piVar7;
      iVar4 = iVar2;
      if ((local_110 <= iVar2) && (iVar4 = local_110, local_108 < iVar2)) {
        local_108 = iVar2;
      }
      local_110 = iVar4;
      iVar2 = piVar7[1];
      iVar4 = iVar2;
      if ((local_10c <= iVar2) && (iVar4 = local_10c, local_104 < iVar2)) {
        local_104 = iVar2;
      }
      local_10c = iVar4;
      piVar7 = piVar7 + 0x1d;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  else {
    if ((uVar5 & 0x3f00) != 0) goto LAB_10006f75;
    local_f0 = *(int *)(PTR_DAT_1005b69c + 0x10);
    *(int *)(PTR_DAT_1005b69c + 0x10) = param_5;
    fVar1 = local_f4;
    if ((uVar5 & 0x30) != 0) {
      fVar1 = *(float *)(param_5 + 0x74);
      if (*(float *)(param_5 + 0x74) <= local_f8) {
        fVar1 = local_f8;
      }
      local_f8 = fVar1;
      fVar1 = *(float *)(param_5 + 0x78);
      if (local_f4 <= *(float *)(param_5 + 0x78)) {
        fVar1 = local_f4;
      }
    }
    local_f4 = fVar1;
    (**(code **)(PTR_DAT_1005b69c + 0x294))(iVar8,8,param_4,param_5,2);
    uStack_e8 = FUN_10027500();
    pcStack_ec = (code *)FUN_1002a7d0(&DAT_10006160,uVar5);
    _DAT_1005ddb0 = 0x7f7fffff;
    _DAT_1005dda0 = 0x7f7fffff;
    bVar3 = true;
    _DAT_1005dda8 = 0x7f7fffff;
    _DAT_1005ddb4 = 0xff7fffff;
    _DAT_1005dda4 = 0xff7fffff;
    piVar7 = &DAT_10052010;
    _DAT_1005ddac = 0xff7fffff;
    uStack_8a = 4;
    uStack_fc = 0;
    auStack_c4[0] = 0;
    do {
      iStack_88 = iVar8 + *piVar7 * 0x74;
      iStack_84 = iVar8 + piVar7[1] * 0x74;
      iStack_80 = iVar8 + piVar7[2] * 0x74;
      iStack_7c = iVar8 + piVar7[3] * 0x74;
      uVar6 = (*pcStack_ec)(auStack_c4);
      if ((bVar3) && ((uVar6 & 0x3f00) != 0)) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      piVar7 = piVar7 + 4;
      uStack_fc = uStack_fc | uVar6;
    } while (piVar7 < &DAT_10052070);
    FUN_100274e0(uStack_e8);
    *(int *)(PTR_DAT_1005b69c + 0x10) = local_f0;
    if (bVar3) {
      if (0 < (int)local_e4[0]) {
        uVar5 = uVar5 | 0x200;
      }
      if (0 < (int)local_dc[0]) {
        uVar5 = uVar5 | 0x100;
      }
      if (0 < (int)local_d4[0]) {
        uVar5 = uVar5 | 0x800;
      }
      if (0 < (int)local_cc[0]) {
        uVar5 = uVar5 | 0x400;
      }
      if (*(float *)(param_5 + 0x74) < local_f8) {
        uVar5 = uVar5 | 0x2000;
      }
      if (local_f4 < *(float *)(param_5 + 0x78)) {
        uVar5 = uVar5 | 0x1000;
      }
    }
    else {
      uVar5 = ((int)uStack_fc >> 8 | uStack_fc) & 0x3f;
    }
    if ((uVar5 & 0x3f00) != 0) goto LAB_10006f75;
    lVar9 = __ftol();
    local_110 = (int)lVar9;
    lVar9 = __ftol();
    local_108 = (int)lVar9;
    lVar9 = __ftol();
    local_10c = (int)lVar9;
    lVar9 = __ftol();
    local_104 = (int)lVar9;
  }
  if ((uVar5 & 0x3f00) == 0) {
    *param_6 = local_110 >> 0x10;
    param_6[2] = (local_108 >> 0x10) - (local_110 >> 0x10);
    param_6[1] = local_10c >> 0x10;
    param_6[3] = (local_104 >> 0x10) - (local_10c >> 0x10);
    if (param_7 == (float *)0x0) {
      return uVar5;
    }
    *param_7 = local_f8;
    param_7[1] = local_f4;
    return uVar5;
  }
LAB_10006f75:
  param_6[3] = 0;
  param_6[2] = 0;
  param_6[1] = 0;
  *param_6 = 0;
  return uVar5;
}


