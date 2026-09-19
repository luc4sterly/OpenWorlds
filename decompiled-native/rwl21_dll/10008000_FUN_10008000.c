// 10008000 FUN_10008000 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10008000(float *param_1)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined4 extraout_ECX;
  undefined4 uVar9;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar10;
  code *pcVar11;
  undefined *puVar12;
  int *piVar13;
  longlong lVar14;
  int local_180;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  int local_16c;
  int local_168;
  int iStack_164;
  int iStack_160;
  uint local_15c;
  float local_158;
  float local_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  code *pcStack_148;
  undefined4 local_144;
  int local_140;
  undefined4 local_13c;
  float local_138 [3];
  float local_12c;
  float afStack_128 [2];
  float afStack_120 [2];
  float afStack_118 [2];
  float afStack_110 [2];
  float afStack_108 [17];
  undefined4 auStack_c4 [14];
  undefined1 uStack_8a;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  
  if (param_1[100] == 1.4013e-45) {
    return 0;
  }
  rwupdateViewMatrix(*(int *)(PTR_DAT_1005b69c + 0x10));
  iVar7 = *(int *)(PTR_DAT_1005b69c + 0x10);
  uStack_14c = *(undefined4 *)(iVar7 + 0x84);
  local_150 = *(undefined4 *)(iVar7 + 0x80);
  local_13c = *(undefined4 *)(iVar7 + 0x88);
  local_138[0] = 0.015;
  local_138[1] = 2.1474836e+09;
  iVar4 = FUN_10041c30();
  uVar10 = extraout_EDX;
  if (iVar4 == 0) {
    FUN_10041b80(iVar7,local_138);
    uVar10 = extraout_EDX_00;
  }
  local_180 = 0;
  local_178 = 0;
  local_17c = 0;
  local_174 = 0;
  uVar9 = 1;
  if (param_1[99] != 1.4013e-45) {
    FUN_10030b50(param_1);
    FUN_10030b90(param_1,iVar7);
    uVar9 = extraout_ECX;
    uVar10 = extraout_EDX_01;
  }
  FUN_1001c440(uVar9,uVar10,param_1,iVar7 + 0xbc,afStack_108);
  iVar4 = (int)param_1[0x22] + 0xc;
  fVar5 = (float)FUN_10006450(iVar7,afStack_108,iVar4,afStack_128,afStack_120,afStack_118,
                              afStack_110,&local_158);
  if (fVar5 == 0.0) {
    iVar1 = *(int *)(PTR_DAT_1005b69c + 0x10);
    *(int *)(PTR_DAT_1005b69c + 0x10) = iVar7;
    (**(code **)(PTR_DAT_1005b69c + 0x294))(iVar4,8,afStack_108,iVar7,1);
    *(int *)(PTR_DAT_1005b69c + 0x10) = iVar1;
    fVar2 = param_1[0x22];
    local_180 = *(int *)((int)fVar2 + 0x24);
    local_17c = *(int *)((int)fVar2 + 0x28);
    piVar13 = (int *)((int)fVar2 + 0x98);
    iVar4 = 7;
    local_178 = local_180;
    local_174 = local_17c;
    do {
      iVar1 = *piVar13;
      iVar3 = iVar1;
      if ((local_180 <= iVar1) && (iVar3 = local_180, local_178 < iVar1)) {
        local_178 = iVar1;
      }
      local_180 = iVar3;
      iVar1 = piVar13[1];
      iVar3 = iVar1;
      if ((local_17c <= iVar1) && (iVar3 = local_17c, local_174 < iVar1)) {
        local_174 = iVar1;
      }
      local_17c = iVar3;
      piVar13 = piVar13 + 0x1d;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  else if (((uint)fVar5 & 0x3f00) == 0) {
    local_140 = *(int *)(PTR_DAT_1005b69c + 0x10);
    *(int *)(PTR_DAT_1005b69c + 0x10) = iVar7;
    fVar2 = local_154;
    if (((uint)fVar5 & 0x30) != 0) {
      fVar2 = *(float *)(iVar7 + 0x74);
      if (*(float *)(iVar7 + 0x74) <= local_158) {
        fVar2 = local_158;
      }
      local_158 = fVar2;
      fVar2 = *(float *)(iVar7 + 0x78);
      if (local_154 <= *(float *)(iVar7 + 0x78)) {
        fVar2 = local_154;
      }
    }
    local_154 = fVar2;
    (**(code **)(PTR_DAT_1005b69c + 0x294))(iVar4,8,afStack_108,iVar7,2);
    local_144 = FUN_10027500();
    pcStack_148 = (code *)FUN_1002a7d0(&DAT_10006160,(uint)fVar5);
    _DAT_1005ddb0 = 0x7f7fffff;
    _DAT_1005dda0 = 0x7f7fffff;
    iStack_160 = 1;
    _DAT_1005dda8 = 0x7f7fffff;
    _DAT_1005ddb4 = 0xff7fffff;
    _DAT_1005dda4 = 0xff7fffff;
    piVar13 = &DAT_10052010;
    _DAT_1005ddac = 0xff7fffff;
    uStack_8a = 4;
    local_15c = 0;
    auStack_c4[0] = 0;
    do {
      iStack_88 = iVar4 + *piVar13 * 0x74;
      iStack_84 = iVar4 + piVar13[1] * 0x74;
      iStack_80 = iVar4 + piVar13[2] * 0x74;
      iStack_7c = iVar4 + piVar13[3] * 0x74;
      uVar6 = (*pcStack_148)(auStack_c4);
      if ((iStack_160 == 0) || ((uVar6 & 0x3f00) == 0)) {
        iStack_160 = 0;
      }
      else {
        iStack_160 = 1;
      }
      piVar13 = piVar13 + 4;
      local_15c = local_15c | uVar6;
    } while (piVar13 < &DAT_10052070);
    FUN_100274e0(local_144);
    *(int *)(PTR_DAT_1005b69c + 0x10) = local_140;
    if (iStack_160 == 0) {
      fVar5 = (float)(((int)local_15c >> 8 | local_15c) & 0x3f);
    }
    else {
      if (0 < (int)afStack_128[0]) {
        fVar5 = (float)((uint)fVar5 | 0x200);
      }
      if (0 < (int)afStack_120[0]) {
        fVar5 = (float)((uint)fVar5 | 0x100);
      }
      if (0 < (int)afStack_118[0]) {
        fVar5 = (float)((uint)fVar5 | 0x800);
      }
      if (0 < (int)afStack_110[0]) {
        fVar5 = (float)((uint)fVar5 | 0x400);
      }
      if (*(float *)(iVar7 + 0x74) < local_158) {
        fVar5 = (float)((uint)fVar5 | 0x2000);
      }
      if (local_154 < *(float *)(iVar7 + 0x78)) {
        fVar5 = (float)((uint)fVar5 | 0x1000);
      }
    }
    if (((uint)fVar5 & 0x3f00) == 0) {
      lVar14 = __ftol();
      local_180 = (int)lVar14;
      lVar14 = __ftol();
      local_178 = (int)lVar14;
      lVar14 = __ftol();
      local_17c = (int)lVar14;
      lVar14 = __ftol();
      local_174 = (int)lVar14;
    }
  }
  if (((uint)fVar5 & 0x3f00) == 0) {
    local_170 = local_180 >> 0x10;
    local_168 = (local_178 >> 0x10) - local_170;
    local_16c = local_17c >> 0x10;
    local_138[2] = local_158;
    iStack_164 = (local_174 >> 0x10) - local_16c;
    local_12c = local_154;
  }
  else {
    iStack_164 = 0;
    local_168 = 0;
    local_16c = 0;
    local_170 = 0;
  }
  *(undefined4 *)(iVar7 + 0x80) = local_150;
  *(undefined4 *)(iVar7 + 0x84) = uStack_14c;
  *(undefined4 *)(iVar7 + 0x88) = local_13c;
  param_1[0x2f] = fVar5;
  if (((((uint)fVar5 & 0x3f00) != 0) || (local_168 == 0)) || (iStack_164 == 0)) {
    if (param_1[99] == 1.4013e-45) {
      return 0;
    }
    FUN_10030b70(param_1);
    return 0;
  }
  fVar2 = *(float *)(PTR_DAT_1005b69c + 0x10);
  if (((param_1[0x31] != fVar2) || (param_1[0x32] != *(float *)((int)fVar2 + 0x224))) ||
     ((*(float *)((int)fVar2 + 0x80) != param_1[0x33] ||
      (param_1[0x34] != *(float *)((int)fVar2 + 0x84))))) {
    iVar7 = FUN_10041c30();
    if (iVar7 == 0) {
      FUN_10041b80(*(int *)(PTR_DAT_1005b69c + 0x10),local_138 + 2);
    }
    (**(code **)(PTR_DAT_1005b69c + 0x294))
              ((int)param_1[0x22] + 0x3ac,*(int *)((int)param_1[0x22] + 8) + -8,afStack_108,
               *(undefined4 *)(PTR_DAT_1005b69c + 0x10),2 - (uint)(fVar5 == 0.0));
    param_1[0x31] = *(float *)(PTR_DAT_1005b69c + 0x10);
    param_1[0x32] = *(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x224);
    param_1[0x33] = *(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x80);
    param_1[0x34] = *(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x84);
    param_1[0x35] = *(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x88);
  }
  RwDamageCameraViewport
            (*(int *)(PTR_DAT_1005b69c + 0x10),local_170,local_16c,local_168 + 1,iStack_164 + 1);
  if (param_1[0x36] != 0.0) {
    FUN_1001b050((int)param_1);
  }
  FUN_1000cc10(param_1);
  if (*(code **)(PTR_DAT_1005b69c + 0x44) != (code *)0x0) {
    (**(code **)(PTR_DAT_1005b69c + 0x44))(param_1);
  }
  if (param_1[0x65] != 0.0) {
    iVar7 = FUN_10041c30();
    if (iVar7 == 0) {
      if (((uint)param_1[0x62] & 4) == 0) {
        uVar6 = ((uint)param_1[0x62] & 2) >> 1;
      }
      else {
        uVar6 = 2;
      }
      if (uVar6 == 2) {
        *(undefined4 *)(PTR_DAT_1005b69c + 0x348) = 1;
        (**(code **)(PTR_DAT_1005b69c + 0x40))(&local_170);
      }
      else {
        *(undefined4 *)(PTR_DAT_1005b69c + 0x348) = 0;
      }
    }
    else {
      *(undefined4 *)(PTR_DAT_1005b69c + 0x348) = 1;
    }
    *(float **)(PTR_DAT_1005b69c + 0x340) = afStack_108;
    *(float **)(PTR_DAT_1005b69c + 0x33c) = param_1;
    *(int **)(PTR_DAT_1005b69c + 0x344) = &local_170;
    if (fVar5 != 0.0) {
      pcVar11 = FUN_10029210;
      if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) != 1) {
        pcVar11 = (code *)&LAB_10027510;
      }
      FUN_100274c0(0);
      puVar8 = FUN_1002a7d0(pcVar11,(uint)fVar5);
      *(undefined1 **)(PTR_DAT_1005b69c + 0x2f4) = puVar8;
    }
    *(float *)(PTR_DAT_1005b69c + 0x2f0) = fVar5;
    (*(code *)param_1[0x65])(param_1);
    goto LAB_1000881a;
  }
  if (*(int *)param_1[0x26] == 0) {
    return 1;
  }
  if (param_1[0x37] == 0.0) {
    iVar7 = FUN_10041c30();
    if (iVar7 == 0) {
      if (((uint)param_1[0x62] & 4) == 0) {
        uVar6 = ((uint)param_1[0x62] & 2) >> 1;
      }
      else {
        uVar6 = 2;
      }
      puVar12 = &LAB_10027460;
      if (uVar6 == 2) {
        puVar12 = &LAB_10027490;
        goto LAB_100087cf;
      }
    }
    else {
      puVar12 = &LAB_10027490;
    }
  }
  else {
    iVar7 = FUN_10041c30();
    if (iVar7 == 0) {
      if (((uint)param_1[0x62] & 4) == 0) {
        uVar6 = ((uint)param_1[0x62] & 2) >> 1;
      }
      else {
        uVar6 = 2;
      }
      if (uVar6 == 2) {
        puVar12 = *(undefined **)(PTR_DAT_1005b69c + (int)param_1[0x38] * 4 + 0x154);
LAB_100087cf:
        (**(code **)(PTR_DAT_1005b69c + 0x40))(&local_170);
      }
      else {
        puVar12 = *(undefined **)(PTR_DAT_1005b69c + (int)param_1[0x38] * 4 + 0x54);
      }
    }
    else {
      puVar12 = *(undefined **)(PTR_DAT_1005b69c + (int)param_1[0x38] * 4 + 0x154);
    }
  }
  if (fVar5 == 0.0) {
    FUN_10032b50(puVar12,(int)param_1,&local_170);
  }
  else {
    pcVar11 = FUN_10029210;
    if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) != 1) {
      pcVar11 = (code *)&LAB_10027510;
    }
    FUN_100274c0(puVar12);
    puVar8 = FUN_1002a7d0(pcVar11,(uint)fVar5);
    FUN_10032c70(puVar8,(int)param_1,&local_170);
  }
LAB_1000881a:
  if (param_1[0x39] != 0.0) {
    FUN_10035db0((int)param_1,&local_170,*(int *)(PTR_DAT_1005b69c + 0x10));
  }
  if (param_1[99] != 1.4013e-45) {
    FUN_10030b70(param_1);
  }
  return 1;
}


