// 004206d0 _Java_NET_worlds_scape_Surface_addSubPolys@16 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _Java_NET_worlds_scape_Surface_addSubPolys_16
              (int *param_1,undefined4 param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  int iVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined4 uVar18;
  int iVar19;
  int iVar20;
  undefined4 uVar21;
  uint uVar22;
  int iVar23;
  undefined4 uVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int local_11c;
  int local_118;
  int local_110;
  uint local_fc;
  uint local_dc;
  uint local_c4;
  uint local_c0;
  float local_68;
  float local_64;
  float local_58;
  float local_54;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  float local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
                    /* 0x206d0  300  _Java_NET_worlds_scape_Surface_addSubPolys@16 */
  uVar18 = FUN_00412cf0(param_1,param_2);
  FUN_004195e0(uVar18,1,&local_34);
  FUN_00419610(uVar18,1,&local_3c,&local_38);
  fVar17 = local_2c;
  fVar16 = local_34;
  fVar15 = local_38;
  fVar14 = local_3c;
  FUN_004195e0(uVar18,2,&local_34);
  FUN_00419610(uVar18,2,&local_3c,&local_38);
  FUN_004195e0(uVar18,4,&local_34);
  FUN_00419610(uVar18,4,&local_3c,&local_38);
  local_30 = 0;
  local_118 = 5;
  local_11c = 0;
  fVar1 = fVar14 + (local_3c - fVar14);
  fVar3 = fVar14;
  if ((byte)(fVar1 < fVar14 | (byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar14)) << 10) >> 8)) == 1
     ) {
    fVar3 = fVar1;
  }
  fVar4 = fVar15 + (local_38 - fVar15);
  fVar5 = fVar15;
  if ((byte)(fVar4 < fVar15 | (byte)((ushort)((ushort)(NAN(fVar4) || NAN(fVar15)) << 10) >> 8)) == 1
     ) {
    fVar5 = fVar4;
  }
  fVar2 = fVar14;
  if (fVar14 < fVar1) {
    fVar2 = fVar1;
  }
  fVar1 = fVar15;
  if (fVar15 < fVar4) {
    fVar1 = fVar4;
  }
  iVar19 = (int)ROUND(ROUND(fVar3)) * param_3;
  iVar27 = (int)ROUND(ROUND(fVar5)) * param_4;
  iVar20 = ((int)ROUND(ROUND(fVar2)) * param_3 - iVar19) *
           ((int)ROUND(ROUND(fVar1)) * param_4 - iVar27);
  uVar21 = (**(code **)(*param_1 + 0x2cc))(param_1,iVar20);
  (**(code **)(*param_1 + 0x1a0))(param_1,param_2,DAT_0049ff58,uVar21);
  if (iVar20 != 0) {
    fVar5 = (float)param_4 * fVar5;
    fVar4 = (float)param_4 * fVar1;
    fVar3 = (float)param_3 * fVar3;
    fVar6 = (float)param_3 * fVar2;
    fVar7 = (local_2c - fVar17) / ((float)param_4 * (local_38 - fVar15));
    fVar8 = (local_34 - fVar16) / ((float)param_3 * (local_3c - fVar14));
    uVar22 = FUN_00412d20(param_1,param_2);
    local_fc = 0;
    local_c4 = (uint)((uVar22 & 0x100000) != 0);
    if (local_c4 != 0) {
      local_fc = iVar27 / param_4 & 1;
    }
    local_c0 = 0;
    local_dc = (uint)((uVar22 & 0x80000) != 0);
    if (local_dc != 0) {
      local_c0 = iVar19 / param_3 & 1;
    }
    iVar23 = (**(code **)(*param_1 + 0x2ec))(param_1,uVar21,0);
    for (; iVar13 = iVar19, uVar22 = local_c0, iVar27 < (int)ROUND(ROUND(fVar1)) * param_4;
        iVar27 = iVar27 + param_4) {
      for (; iVar13 < (int)ROUND(ROUND(fVar2)) * param_3; iVar13 = iVar13 + param_3) {
        if (local_fc == 0) {
          local_110 = param_4 + -1;
        }
        else {
          local_110 = 0;
        }
        for (; (-1 < local_110 && (local_110 < param_4)); local_110 = local_110 + iVar26) {
          iVar26 = iVar27 + local_110;
          local_68 = fVar4;
          if ((float)(iVar26 + 1) <= fVar4) {
            local_68 = (float)(iVar26 + 1);
          }
          local_64 = fVar5;
          if ((byte)((float)iVar26 < fVar5 |
                    (byte)((ushort)((ushort)(NAN((float)iVar26) || NAN(fVar5)) << 10) >> 8)) != 1) {
            local_64 = (float)iVar26;
          }
          if (local_68 < local_64) {
            local_68 = fVar4;
            local_64 = fVar4;
          }
          fVar9 = (local_68 - (float)param_4 * fVar15) * fVar7 + fVar17;
          fVar10 = (local_64 - (float)param_4 * fVar15) * fVar7 + fVar17;
          local_68 = local_68 - (float)iVar26;
          local_64 = local_64 - (float)iVar26;
          if (local_fc != 0) {
            local_68 = _DAT_004712b4 - local_68;
            local_64 = _DAT_004712b4 - local_64;
          }
          if (uVar22 == 0) {
            iVar26 = 0;
          }
          else {
            iVar26 = param_3 + -1;
          }
          for (; (-1 < iVar26 && (iVar26 < param_3)); iVar26 = iVar26 + iVar25) {
            iVar25 = iVar13 + iVar26;
            local_58 = fVar3;
            if ((byte)((float)iVar25 < fVar3 |
                      (byte)((ushort)((ushort)(NAN((float)iVar25) || NAN(fVar3)) << 10) >> 8)) != 1)
            {
              local_58 = (float)iVar25;
            }
            local_54 = fVar6;
            if ((float)(iVar25 + 1) <= fVar6) {
              local_54 = (float)(iVar25 + 1);
            }
            if (local_54 < local_58) {
              local_58 = fVar6;
              local_54 = fVar6;
            }
            fVar11 = (local_58 - (float)param_3 * fVar14) * fVar8 + fVar16;
            fVar12 = (local_54 - (float)param_3 * fVar14) * fVar8 + fVar16;
            local_58 = local_58 - (float)iVar25;
            local_54 = local_54 - (float)iVar25;
            if (uVar22 != 0) {
              local_58 = _DAT_004712b4 - local_58;
              local_54 = _DAT_004712b4 - local_54;
            }
            FUN_00418e70(uVar18,fVar11,DAT_004712ac,fVar9);
            FUN_00418e70(uVar18,fVar12,DAT_004712ac,fVar9);
            FUN_00418e70(uVar18,fVar12,DAT_004712ac,fVar10);
            FUN_00418e70(uVar18,fVar11,DAT_004712ac,fVar10);
            FUN_00419e00(uVar18,local_118,local_58,local_68);
            FUN_00419e00(uVar18,local_118 + 1,local_54,local_68);
            FUN_00419e00(uVar18,local_118 + 2,local_54,local_64);
            FUN_00419e00(uVar18,local_118 + 3,local_58,local_64);
            local_28 = local_118;
            local_24 = local_118 + 1;
            local_20 = local_118 + 2;
            local_1c = local_118 + 3;
            uVar24 = FUN_00418e30(uVar18,4,&local_28);
            *(undefined4 *)(iVar23 + local_11c * 4) = uVar24;
            if (uVar22 == 0) {
              iVar25 = 1;
            }
            else {
              iVar25 = -1;
            }
            local_118 = local_118 + 4;
            local_11c = local_11c + 1;
          }
          if (local_fc == 0) {
            iVar26 = -1;
          }
          else {
            iVar26 = 1;
          }
        }
        uVar22 = uVar22 ^ local_dc;
      }
      local_fc = local_fc ^ local_c4;
    }
    (**(code **)(*param_1 + 0x30c))(param_1,uVar21,iVar23,0);
    if (local_11c != iVar20) {
      FUN_00402800(s_nSurface_00471244,0x16e);
    }
    return iVar20;
  }
  return 0;
}


