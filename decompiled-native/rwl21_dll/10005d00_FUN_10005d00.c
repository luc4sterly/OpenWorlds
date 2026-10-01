// 10005d00 FUN_10005d00 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_10005d00(float *param_1,float *param_2,int param_3,int *param_4,float *param_5)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar8;
  int *piVar9;
  longlong lVar10;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  uint uStack_110;
  float local_10c;
  float local_108;
  int local_104;
  undefined4 local_100;
  undefined4 local_fc;
  code *pcStack_f8;
  undefined4 uStack_f4;
  undefined4 local_f0;
  float local_ec [4];
  float local_dc [2];
  float local_d4 [2];
  float local_cc [2];
  undefined4 auStack_c4 [14];
  undefined1 uStack_8a;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  
  local_fc = *(undefined4 *)(param_3 + 0x84);
  local_100 = *(undefined4 *)(param_3 + 0x80);
  local_f0 = *(undefined4 *)(param_3 + 0x88);
  local_ec[0] = 0.015;
  local_ec[1] = 2.1474836e+09;
  iVar5 = FUN_10041c30();
  uVar8 = extraout_EDX;
  if (iVar5 == 0) {
    FUN_10041b80(param_3,local_ec);
    uVar8 = extraout_EDX_00;
  }
  if (param_1[99] != 1.4013e-45) {
    FUN_10030b50(param_1);
    FUN_10030b90(param_1,param_3);
    uVar8 = extraout_EDX_01;
  }
  FUN_1001c440(param_3 + 0xbc,uVar8,param_1,param_3 + 0xbc,param_2);
  iVar5 = (int)param_1[0x22] + 0xc;
  uVar6 = FUN_10006450(param_3,param_2,iVar5,local_ec + 2,local_dc,local_d4,local_cc,&local_10c);
  if (uVar6 == 0) {
    local_104 = *(int *)(PTR_DAT_1005b69c + 0x10);
    *(int *)(PTR_DAT_1005b69c + 0x10) = param_3;
    (**(code **)(PTR_DAT_1005b69c + 0x294))(iVar5,8,param_2,param_3,1);
    *(int *)(PTR_DAT_1005b69c + 0x10) = local_104;
    fVar1 = param_1[0x22];
    local_124 = *(int *)((int)fVar1 + 0x24);
    local_120 = *(int *)((int)fVar1 + 0x28);
    piVar9 = (int *)((int)fVar1 + 0x98);
    iVar5 = 7;
    local_11c = local_124;
    local_118 = local_120;
    do {
      iVar2 = *piVar9;
      iVar4 = iVar2;
      if ((local_124 <= iVar2) && (iVar4 = local_124, local_11c < iVar2)) {
        local_11c = iVar2;
      }
      local_124 = iVar4;
      iVar2 = piVar9[1];
      iVar4 = iVar2;
      if ((local_120 <= iVar2) && (iVar4 = local_120, local_118 < iVar2)) {
        local_118 = iVar2;
      }
      local_120 = iVar4;
      piVar9 = piVar9 + 0x1d;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
LAB_100060c7:
    if ((uVar6 & 0x3f00) == 0) {
      *param_4 = local_124 >> 0x10;
      param_4[2] = (local_11c >> 0x10) - (local_124 >> 0x10);
      param_4[1] = local_120 >> 0x10;
      param_4[3] = (local_118 >> 0x10) - (local_120 >> 0x10);
      if (param_5 != (float *)0x0) {
        *param_5 = local_10c;
        param_5[1] = local_108;
      }
      goto LAB_1000612f;
    }
  }
  else if ((uVar6 & 0x3f00) == 0) {
    local_104 = *(int *)(PTR_DAT_1005b69c + 0x10);
    *(int *)(PTR_DAT_1005b69c + 0x10) = param_3;
    fVar1 = local_108;
    if ((uVar6 & 0x30) != 0) {
      fVar1 = *(float *)(param_3 + 0x74);
      if (*(float *)(param_3 + 0x74) <= local_10c) {
        fVar1 = local_10c;
      }
      local_10c = fVar1;
      fVar1 = *(float *)(param_3 + 0x78);
      if (local_108 <= *(float *)(param_3 + 0x78)) {
        fVar1 = local_108;
      }
    }
    local_108 = fVar1;
    (**(code **)(PTR_DAT_1005b69c + 0x294))(iVar5,8,param_2,param_3,2);
    uStack_f4 = FUN_10027500();
    pcStack_f8 = (code *)FUN_1002a7d0(&DAT_10006160,uVar6);
    _DAT_1005ddb0 = 0x7f7fffff;
    _DAT_1005dda0 = 0x7f7fffff;
    bVar3 = true;
    _DAT_1005dda8 = 0x7f7fffff;
    _DAT_1005ddb4 = 0xff7fffff;
    _DAT_1005dda4 = 0xff7fffff;
    piVar9 = &DAT_10052010;
    _DAT_1005ddac = 0xff7fffff;
    uStack_8a = 4;
    uStack_110 = 0;
    auStack_c4[0] = 0;
    do {
      iStack_88 = iVar5 + *piVar9 * 0x74;
      iStack_84 = iVar5 + piVar9[1] * 0x74;
      iStack_80 = iVar5 + piVar9[2] * 0x74;
      iStack_7c = iVar5 + piVar9[3] * 0x74;
      uVar7 = (*pcStack_f8)(auStack_c4);
      if ((bVar3) && ((uVar7 & 0x3f00) != 0)) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      piVar9 = piVar9 + 4;
      uStack_110 = uStack_110 | uVar7;
    } while (piVar9 < &DAT_10052070);
    FUN_100274e0(uStack_f4);
    *(int *)(PTR_DAT_1005b69c + 0x10) = local_104;
    if (bVar3) {
      if (0 < (int)local_ec[2]) {
        uVar6 = uVar6 | 0x200;
      }
      if (0 < (int)local_dc[0]) {
        uVar6 = uVar6 | 0x100;
      }
      if (0 < (int)local_d4[0]) {
        uVar6 = uVar6 | 0x800;
      }
      if (0 < (int)local_cc[0]) {
        uVar6 = uVar6 | 0x400;
      }
      if (*(float *)(param_3 + 0x74) < local_10c) {
        uVar6 = uVar6 | 0x2000;
      }
      if (local_108 < *(float *)(param_3 + 0x78)) {
        uVar6 = uVar6 | 0x1000;
      }
    }
    else {
      uVar6 = ((int)uStack_110 >> 8 | uStack_110) & 0x3f;
    }
    if ((uVar6 & 0x3f00) == 0) {
      lVar10 = __ftol();
      local_124 = (int)lVar10;
      lVar10 = __ftol();
      local_11c = (int)lVar10;
      lVar10 = __ftol();
      local_120 = (int)lVar10;
      lVar10 = __ftol();
      local_118 = (int)lVar10;
      goto LAB_100060c7;
    }
  }
  param_4[3] = 0;
  param_4[2] = 0;
  param_4[1] = 0;
  *param_4 = 0;
LAB_1000612f:
  *(undefined4 *)(param_3 + 0x80) = local_100;
  *(undefined4 *)(param_3 + 0x84) = local_fc;
  *(undefined4 *)(param_3 + 0x88) = local_f0;
  return uVar6;
}


