// 10006ff0 FUN_10006ff0 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_10006ff0(float *param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  float *pfVar8;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  int *piVar9;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  longlong lVar10;
  float *pfVar11;
  uint uStack_180;
  int *local_17c;
  int local_178;
  int local_174;
  int local_170;
  int iStack_16c;
  int local_168;
  uint local_160;
  float local_15c;
  float local_158;
  float afStack_154 [3];
  float afStack_148 [2];
  float afStack_140 [2];
  undefined4 local_138;
  undefined4 uStack_134;
  code *pcStack_130;
  undefined4 local_12c;
  int local_128;
  undefined4 local_124;
  float local_120 [3];
  float local_114;
  float afStack_110 [2];
  float local_108 [3];
  float fStack_fc;
  undefined1 uStack_ce;
  int iStack_cc;
  int iStack_c8;
  int iStack_c4;
  int iStack_c0;
  float afStack_44 [17];
  
  local_168 = 0;
  local_17c = (int *)0x0;
  if ((((-1 < param_2) && (param_2 < *(int *)(param_4 + 0x5c))) && (-1 < param_3)) &&
     ((param_3 < *(int *)(param_4 + 0x60) && (param_1[100] != 1.4013e-45)))) {
    rwupdateViewMatrix(param_4);
    local_138 = *(undefined4 *)(param_4 + 0x80);
    uStack_134 = *(undefined4 *)(param_4 + 0x84);
    local_124 = *(undefined4 *)(param_4 + 0x88);
    local_120[0] = 0.015;
    local_120[1] = 2.1474836e+09;
    iVar4 = FUN_10041c30();
    uVar7 = extraout_EDX;
    if (iVar4 == 0) {
      FUN_10041b80(param_4,local_120);
      uVar7 = extraout_EDX_00;
    }
    local_178 = 0;
    local_170 = 0;
    local_174 = 0;
    iStack_16c = 0;
    if (param_1[99] != 1.4013e-45) {
      FUN_10030b50(param_1);
      FUN_10030b90(param_1,param_4);
      uVar7 = extraout_EDX_01;
    }
    FUN_1001c440(param_4 + 0xbc,uVar7,param_1,param_4 + 0xbc,afStack_44);
    iVar4 = (int)param_1[0x22] + 0xc;
    uStack_180 = FUN_10006450(param_4,afStack_44,iVar4,afStack_154,afStack_148,afStack_140,
                              afStack_110,&local_15c);
    if (uStack_180 == 0) {
      iVar6 = *(int *)(PTR_DAT_1005b69c + 0x10);
      *(int *)(PTR_DAT_1005b69c + 0x10) = param_4;
      (**(code **)(PTR_DAT_1005b69c + 0x294))(iVar4,8,afStack_44,param_4,1);
      *(int *)(PTR_DAT_1005b69c + 0x10) = iVar6;
      fVar1 = param_1[0x22];
      local_178 = *(int *)((int)fVar1 + 0x24);
      local_174 = *(int *)((int)fVar1 + 0x28);
      piVar9 = (int *)((int)fVar1 + 0x98);
      iVar4 = 7;
      local_170 = local_178;
      iStack_16c = local_174;
      do {
        iVar6 = *piVar9;
        iVar3 = iVar6;
        if ((local_178 <= iVar6) && (iVar3 = local_178, local_170 < iVar6)) {
          local_170 = iVar6;
        }
        local_178 = iVar3;
        iVar6 = piVar9[1];
        iVar3 = iVar6;
        if ((local_174 <= iVar6) && (iVar3 = local_174, iStack_16c < iVar6)) {
          iStack_16c = iVar6;
        }
        local_174 = iVar3;
        piVar9 = piVar9 + 0x1d;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    else if ((uStack_180 & 0x3f00) == 0) {
      local_128 = *(int *)(PTR_DAT_1005b69c + 0x10);
      *(int *)(PTR_DAT_1005b69c + 0x10) = param_4;
      fVar1 = local_158;
      if ((uStack_180 & 0x30) != 0) {
        fVar1 = *(float *)(param_4 + 0x74);
        if (*(float *)(param_4 + 0x74) <= local_15c) {
          fVar1 = local_15c;
        }
        local_15c = fVar1;
        fVar1 = *(float *)(param_4 + 0x78);
        if (local_158 <= *(float *)(param_4 + 0x78)) {
          fVar1 = local_158;
        }
      }
      local_158 = fVar1;
      (**(code **)(PTR_DAT_1005b69c + 0x294))(iVar4,8,afStack_44,param_4,2);
      local_12c = FUN_10027500();
      pcStack_130 = (code *)FUN_1002a7d0(&DAT_10006160,uStack_180);
      _DAT_1005ddb0 = 0x7f7fffff;
      _DAT_1005dda0 = 0x7f7fffff;
      bVar2 = true;
      _DAT_1005dda8 = 0x7f7fffff;
      _DAT_1005ddb4 = 0xff7fffff;
      _DAT_1005dda4 = 0xff7fffff;
      piVar9 = &DAT_10052010;
      _DAT_1005ddac = 0xff7fffff;
      uStack_ce = 4;
      local_160 = 0;
      local_108[0] = 0.0;
      do {
        iStack_cc = iVar4 + *piVar9 * 0x74;
        iStack_c8 = iVar4 + piVar9[1] * 0x74;
        iStack_c4 = iVar4 + piVar9[2] * 0x74;
        iStack_c0 = iVar4 + piVar9[3] * 0x74;
        uVar5 = (*pcStack_130)(local_108);
        if ((bVar2) && ((uVar5 & 0x3f00) != 0)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        piVar9 = piVar9 + 4;
        local_160 = local_160 | uVar5;
      } while (piVar9 < &DAT_10052070);
      FUN_100274e0(local_12c);
      *(int *)(PTR_DAT_1005b69c + 0x10) = local_128;
      if (bVar2) {
        if (0 < (int)afStack_154[0]) {
          uStack_180 = uStack_180 | 0x200;
        }
        if (0 < (int)afStack_148[0]) {
          uStack_180 = uStack_180 | 0x100;
        }
        if (0 < (int)afStack_140[0]) {
          uStack_180 = uStack_180 | 0x800;
        }
        if (0 < (int)afStack_110[0]) {
          uStack_180 = uStack_180 | 0x400;
        }
        if (*(float *)(param_4 + 0x74) < local_15c) {
          uStack_180 = uStack_180 | 0x2000;
        }
        if (local_158 < *(float *)(param_4 + 0x78)) {
          uStack_180 = uStack_180 | 0x1000;
        }
      }
      else {
        uStack_180 = ((int)local_160 >> 8 | local_160) & 0x3f;
      }
      if ((uStack_180 & 0x3f00) == 0) {
        lVar10 = __ftol();
        local_178 = (int)lVar10;
        lVar10 = __ftol();
        local_170 = (int)lVar10;
        lVar10 = __ftol();
        local_174 = (int)lVar10;
        lVar10 = __ftol();
        iStack_16c = (int)lVar10;
      }
    }
    iVar4 = 0;
    afStack_154[0] = (float)(uStack_180 & 0x3f00);
    if (afStack_154[0] == 0.0) {
      local_178 = local_178 >> 0x10;
      local_174 = local_174 >> 0x10;
      iVar6 = (local_170 >> 0x10) - local_178;
      iVar4 = (iStack_16c >> 0x10) - local_174;
      local_120[2] = local_15c;
      local_114 = local_158;
    }
    else {
      iVar6 = 0;
      local_174 = 0;
      local_178 = 0;
    }
    *(undefined4 *)(param_4 + 0x80) = local_138;
    *(undefined4 *)(param_4 + 0x84) = uStack_134;
    *(undefined4 *)(param_4 + 0x88) = local_124;
    if (((afStack_154[0] == 0.0) && (iVar6 != 0)) && (iVar4 != 0)) {
      if (((local_178 <= param_2) && (param_2 <= iVar6 + local_178)) &&
         ((local_174 <= param_3 && (param_3 <= iVar4 + local_174)))) {
        fVar1 = *(float *)(PTR_DAT_1005b69c + 0x10);
        if (((param_1[0x31] != fVar1) || (*(float *)((int)fVar1 + 0x224) != param_1[0x32])) ||
           ((*(float *)((int)fVar1 + 0x80) != param_1[0x33] ||
            (param_1[0x34] != *(float *)((int)fVar1 + 0x84))))) {
          iVar4 = FUN_10041c30();
          if (iVar4 == 0) {
            FUN_10041b80(*(int *)(PTR_DAT_1005b69c + 0x10),local_120 + 2);
          }
          (**(code **)(PTR_DAT_1005b69c + 0x294))
                    ((int)param_1[0x22] + 0x3ac,*(int *)((int)param_1[0x22] + 8) + -8,afStack_44,
                     *(undefined4 *)(PTR_DAT_1005b69c + 0x10),2 - (uint)(uStack_180 == 0));
          param_1[0x31] = *(float *)(PTR_DAT_1005b69c + 0x10);
          param_1[0x32] = *(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x224);
          param_1[0x33] = *(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x80);
          param_1[0x34] = *(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x84);
          param_1[0x35] = *(float *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x88);
        }
        local_168 = FUN_10032d40(uStack_180,(int)param_1,param_4,param_2 << 0x10,param_3 << 0x10);
        if (local_168 != 0) {
          local_17c = param_5 + 1;
          *param_5 = 1;
          *local_17c = (int)param_1;
          param_5[2] = *(undefined4 *)(local_168 + 0x2c);
          uVar7 = FUN_10032810(*(int *)(local_168 + 0x2c),param_2,param_3,param_5 + 4);
          param_5[3] = uVar7;
          goto LAB_1000767b;
        }
      }
    }
  }
  *param_5 = 0;
LAB_1000767b:
  if (local_17c != (int *)0x0) {
    FUN_100014c0(local_168,local_108);
    pfVar11 = (float *)(local_17c + 4);
    FUN_1000a120(param_4,param_2,param_3,afStack_154,pfVar11);
    rwLengthNormaliseVector(pfVar11,pfVar11);
    RwDotProduct(local_108,extraout_EDX_02);
    afStack_140[0] = (float)extraout_ST0;
    RwDotProduct(local_108,afStack_154);
    afStack_148[0] = (float)(extraout_ST0_00 + (float10)fStack_fc);
    if (((uint)afStack_140[0] < 0x80000001) || ((int)afStack_148[0] < 1)) {
      pfVar8 = (float *)FUN_10041c90(*(int *)(*local_17c + 0x88),local_17c[2]);
      *pfVar11 = *pfVar8;
      local_17c[5] = (int)pfVar8[1];
      local_17c[6] = (int)pfVar8[2];
      RwTransformPoint(pfVar11,param_1);
    }
    else {
      pfVar8 = (float *)RwScaleVector(pfVar11,afStack_148[0] / afStack_140[0],pfVar11);
      RwSubtractVector(afStack_154,pfVar8,pfVar11);
    }
  }
  if (param_1[99] != 1.4013e-45) {
    FUN_10030b70(param_1);
  }
  return param_5;
}


