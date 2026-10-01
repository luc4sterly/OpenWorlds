// 0041cea0 FUN_0041cea0 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_0041cea0(uint *param_1,float *param_2,int param_3,uint *param_4)

{
  byte bVar1;
  byte *pbVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  bool bVar11;
  bool bVar12;
  uint local_898;
  int local_890;
  uint local_88c;
  uint local_888;
  uint local_880;
  float local_868;
  float local_864;
  float local_860;
  float local_85c;
  float local_858;
  float local_854;
  float *local_840;
  undefined4 local_83c;
  float local_838;
  float local_834;
  float afStack_830 [256];
  float afStack_430 [256];
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  pbVar2 = (byte *)*param_1;
  if (param_2 < pbVar2 + 2) {
    return 0;
  }
  local_88c = (uint)*pbVar2;
  bVar11 = (*pbVar2 & 0x80) != 0;
  if (bVar11) {
    local_88c = (local_88c & 0x7f) + 0x8000000;
  }
  local_83c = 0;
  bVar1 = pbVar2[1];
  local_840 = (float *)(pbVar2 + 2);
  local_838 = 0.0;
  local_834 = 0.0;
  bVar12 = (bVar1 & 0x80) != 0;
  if ((bVar1 & 0x40) != 0) {
    local_840 = (float *)(pbVar2 + 6);
    if (param_2 < local_840) {
      return 0;
    }
    local_83c = *(undefined4 *)(pbVar2 + 2);
  }
  if ((bVar1 & 0x20) != 0) {
    if (param_2 < local_840 + 1) {
      return 0;
    }
    local_838 = *local_840;
    local_840 = local_840 + 1;
  }
  if ((bVar1 & 0x10) != 0) {
    if (param_2 < local_840 + 1) {
      return 0;
    }
    local_834 = *local_840;
    local_840 = local_840 + 1;
  }
  iVar8 = FUN_00418f90();
  if (iVar8 == 0) {
    FUN_00402800(s_nShape_00470970,0x217);
  }
  FUN_00419da0(iVar8,local_88c);
  uVar9 = FUN_00419950();
  FUN_00418ce0(uVar9,local_83c,local_838,local_834);
  FUN_00418bc0(iVar8,uVar9);
  FUN_004198f0();
  if (bVar11) {
    *param_1 = (uint)local_840;
    return iVar8;
  }
  if (param_2 < local_840 + 1) {
    FUN_004190d0(iVar8);
    return 0;
  }
  fVar3 = (float)*(byte *)local_840 * _DAT_00470aac;
  fVar4 = (float)*(byte *)((int)local_840 + 1) * _DAT_00470aac;
  pbVar2 = (byte *)((int)local_840 + 3);
  fVar5 = (float)*(byte *)((int)local_840 + 2) * _DAT_00470aac;
  local_840 = local_840 + 1;
  local_880 = (uint)*pbVar2;
  if (0x40 < local_880) {
    local_880 = (local_880 - 0x40) * 4 + 0x40;
  }
  local_868 = DAT_00470ab0;
  local_890 = 0;
  local_864 = DAT_00470ab4;
  local_854 = DAT_00470ab4;
  local_860 = DAT_00470ab0;
  local_858 = DAT_00470ab0;
  local_85c = DAT_00470ab4;
  if (0 < (int)local_880) {
    do {
      if (param_2 < (float *)((int)local_840 + 1)) {
        local_840 = (float *)0x0;
      }
      else {
        bVar1 = *(byte *)local_840;
        if ((bVar1 & 1) == 0) {
          if (param_2 < local_840 + 1) {
            local_840 = (float *)0x0;
          }
          else {
            local_30 = *local_840;
            *(float *)(param_3 + *param_4 * 4) = local_30;
            *param_4 = *param_4 + 1 & 0x7f;
            local_840 = local_840 + 1;
          }
        }
        else {
          local_840 = (float *)((int)local_840 + 1);
          local_30 = *(float *)(param_3 + (*param_4 - (((int)(uint)bVar1 >> 1) + 1) & 0x7f) * 4);
        }
      }
      if (local_840 == (float *)0x0) {
LAB_0041d45d:
        FUN_004190d0(iVar8);
        return 0;
      }
      if (param_2 < (float *)((int)local_840 + 1)) {
        local_840 = (float *)0x0;
      }
      else {
        bVar1 = *(byte *)local_840;
        if ((bVar1 & 1) == 0) {
          if (param_2 < local_840 + 1) {
            local_840 = (float *)0x0;
          }
          else {
            local_2c = *local_840;
            *(float *)(param_3 + 0x200 + param_4[1] * 4) = local_2c;
            param_4[1] = param_4[1] + 1 & 0x7f;
            local_840 = local_840 + 1;
          }
        }
        else {
          local_840 = (float *)((int)local_840 + 1);
          local_2c = *(float *)(param_3 + 0x200 +
                               (param_4[1] - (((int)(uint)bVar1 >> 1) + 1) & 0x7f) * 4);
        }
      }
      if (local_840 == (float *)0x0) goto LAB_0041d45d;
      if (param_2 < (float *)((int)local_840 + 1)) {
        local_840 = (float *)0x0;
      }
      else {
        bVar1 = *(byte *)local_840;
        if ((bVar1 & 1) == 0) {
          if (param_2 < local_840 + 1) {
            local_840 = (float *)0x0;
          }
          else {
            local_28 = *local_840;
            *(float *)(param_3 + 0x400 + param_4[2] * 4) = local_28;
            param_4[2] = param_4[2] + 1 & 0x7f;
            local_840 = local_840 + 1;
          }
        }
        else {
          local_840 = (float *)((int)local_840 + 1);
          local_28 = *(float *)(param_3 + 0x400 +
                               (param_4[2] - (((int)(uint)bVar1 >> 1) + 1) & 0x7f) * 4);
        }
      }
      if (local_840 == (float *)0x0) goto LAB_0041d45d;
      if (bVar12) {
        if (param_2 < (float *)((int)local_840 + 1)) {
          local_840 = (float *)0x0;
        }
        else {
          bVar1 = *(byte *)local_840;
          if ((bVar1 & 1) == 0) {
            if (param_2 < local_840 + 1) {
              local_840 = (float *)0x0;
            }
            else {
              local_24 = *local_840;
              *(float *)(param_3 + 0x600 + param_4[3] * 4) = local_24;
              param_4[3] = param_4[3] + 1 & 0x7f;
              local_840 = local_840 + 1;
            }
          }
          else {
            local_840 = (float *)((int)local_840 + 1);
            local_24 = *(float *)(param_3 + 0x600 +
                                 (param_4[3] - (((int)(uint)bVar1 >> 1) + 1) & 0x7f) * 4);
          }
        }
        if (local_840 == (float *)0x0) goto LAB_0041d45d;
        if (param_2 < (float *)((int)local_840 + 1)) {
          local_840 = (float *)0x0;
        }
        else {
          bVar1 = *(byte *)local_840;
          if ((bVar1 & 1) == 0) {
            if (param_2 < local_840 + 1) {
              local_840 = (float *)0x0;
            }
            else {
              local_20 = *local_840;
              *(float *)(param_3 + 0x800 + param_4[4] * 4) = local_20;
              param_4[4] = param_4[4] + 1 & 0x7f;
              local_840 = local_840 + 1;
            }
          }
          else {
            local_840 = (float *)((int)local_840 + 1);
            local_20 = *(float *)(param_3 + 0x800 +
                                 (param_4[4] - (((int)(uint)bVar1 >> 1) + 1) & 0x7f) * 4);
          }
        }
        if (local_840 == (float *)0x0) goto LAB_0041d45d;
      }
      iVar10 = FUN_00418e70(iVar8,local_30,local_2c,local_28);
      if (iVar10 != local_890 + 1) {
        FUN_00402800(s_nShape_00470970,0x24b);
      }
      if (bVar12) {
        FUN_00419e00(iVar8,iVar10,local_24,local_20);
      }
      afStack_830[local_890] = local_30;
      if ((byte)(local_30 < local_868 |
                (byte)((ushort)((ushort)(NAN(local_30) || NAN(local_868)) << 10) >> 8)) == 1) {
        local_868 = local_30;
      }
      if (local_864 < local_30) {
        local_864 = local_30;
      }
      afStack_430[local_890] = local_2c;
      if ((byte)(local_2c < local_860 |
                (byte)((ushort)((ushort)(NAN(local_2c) || NAN(local_860)) << 10) >> 8)) == 1) {
        local_860 = local_2c;
      }
      if (local_85c < local_2c) {
        local_85c = local_2c;
      }
      if ((byte)(local_28 < local_858 |
                (byte)((ushort)((ushort)(NAN(local_28) || NAN(local_858)) << 10) >> 8)) == 1) {
        local_858 = local_28;
      }
      if (local_854 < local_28) {
        local_854 = local_28;
      }
      local_890 = local_890 + 1;
    } while (local_890 < (int)local_880);
  }
  if (param_2 < (float *)((int)local_840 + 1)) {
    FUN_004190d0(iVar8);
    return 0;
  }
  if (((!bVar12) && (local_868 < local_864)) && (local_860 < local_85c)) {
    iVar10 = 0;
    fVar6 = _DAT_00470ab8 / (local_864 - local_868);
    fVar7 = _DAT_00470ab8 / (local_85c - local_860);
    if (0 < (int)local_880) {
      do {
        FUN_00419e00(iVar8,iVar10 + 1,(afStack_830[iVar10] - local_868) * fVar6,
                     (local_85c - afStack_430[iVar10]) * fVar7);
        iVar10 = iVar10 + 1;
      } while (iVar10 < (int)local_880);
    }
  }
  bVar1 = *(byte *)local_840;
  local_840 = (float *)((int)local_840 + 1);
  local_888 = (uint)bVar1;
  if (0x40 < local_888) {
    local_888 = (local_888 - 0x40) * 4 + 0x40;
  }
  if (param_2 < (float *)((int)local_840 + local_888 * 3 + 1)) {
    FUN_004190d0(iVar8);
    return 0;
  }
  uVar9 = FUN_00419920();
  FUN_00419ef0(uVar9,DAT_00470ac4,DAT_00470ac0,DAT_00470abc);
  FUN_00419e90(uVar9,fVar3,fVar4,fVar5);
  FUN_00417a10(uVar9);
  iVar10 = 0;
  if (local_888 != 3 && -1 < (int)(local_888 - 3)) {
    do {
      local_1c = *(byte *)local_840 + 1;
      pbVar2 = (byte *)((int)local_840 + 2);
      local_18 = *(byte *)((int)local_840 + 1) + 1;
      local_840 = (float *)((int)local_840 + 3);
      local_14 = *pbVar2 + 1;
      FUN_00418e30(iVar8,3,&local_1c);
      iVar10 = iVar10 + 1;
    } while (iVar10 < (int)(local_888 - 3));
  }
  for (; iVar10 < (int)local_888; iVar10 = iVar10 + 1) {
    local_1c = *(byte *)local_840 + 1;
    pbVar2 = (byte *)((int)local_840 + 2);
    local_18 = *(byte *)((int)local_840 + 1) + 1;
    local_840 = (float *)((int)local_840 + 3);
    local_14 = *pbVar2 + 1;
    if (((local_1c != 1) || (local_18 != 1)) || (local_14 != 1)) {
      FUN_00418e30(iVar8,3,&local_1c);
    }
  }
  FUN_00417a90(iVar8);
  FUN_004198c0();
  bVar1 = *(byte *)local_840;
  local_840 = (float *)((int)local_840 + 1);
  local_898 = (uint)bVar1;
  while( true ) {
    local_898 = local_898 - 1;
    if ((int)local_898 < 0) {
      *param_1 = (uint)local_840;
      return iVar8;
    }
    iVar10 = FUN_0041cea0((uint *)&local_840,param_2,param_3,param_4);
    if (iVar10 == 0) break;
    FUN_00418da0(iVar8,iVar10);
  }
  FUN_004190d0(iVar8);
  return 0;
}


