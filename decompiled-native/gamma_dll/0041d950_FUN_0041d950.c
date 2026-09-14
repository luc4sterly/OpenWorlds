// 0041d950 FUN_0041d950 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0041d950(undefined4 param_1,uint *param_2,uint3 *param_3)

{
  uint3 *puVar1;
  byte bVar2;
  byte *pbVar3;
  bool bVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  bool bVar11;
  uint3 *puVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint3 *puVar17;
  int iVar18;
  uint3 *puVar19;
  bool bVar20;
  bool bVar21;
  float local_90;
  float local_8c;
  float local_88;
  float local_78;
  float local_74;
  uint3 *local_64;
  int local_60;
  int local_5c;
  int local_58;
  uint local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  uint local_28;
  uint local_24;
  int local_20 [4];
  
  pbVar3 = (byte *)*param_2;
  if (param_3 < pbVar3 + 2) {
    return 1;
  }
  uVar15 = (uint)*pbVar3;
  bVar20 = (*pbVar3 & 0x80) != 0;
  if (bVar20) {
    uVar15 = (uVar15 & 0x7f) + 0x8000000;
  }
  local_60 = 0;
  bVar2 = pbVar3[1];
  local_64 = (uint3 *)(pbVar3 + 2);
  local_5c = 0;
  local_58 = 0;
  bVar21 = (bVar2 & 0x80) != 0;
  if ((bVar2 & 0x40) != 0) {
    local_64 = (uint3 *)(pbVar3 + 5);
    if (param_3 < local_64) {
      return 2;
    }
    local_60 = (uint)*(uint3 *)(pbVar3 + 2) << 8;
  }
  if ((bVar2 & 0x20) != 0) {
    if (param_3 < (uint3 *)((int)local_64 + 3U)) {
      return 3;
    }
    local_5c = (uint)*local_64 << 8;
    local_64 = (uint3 *)((int)local_64 + 3U);
  }
  if ((bVar2 & 0x10) != 0) {
    if (param_3 < (uint3 *)((int)local_64 + 3U)) {
      return 4;
    }
    local_58 = (uint)*local_64 << 8;
    local_64 = (uint3 *)((int)local_64 + 3U);
  }
  FUN_00419da0(param_1,uVar15);
  uVar13 = FUN_00419950();
  FUN_00418ce0(uVar13,local_60,local_5c,local_58);
  FUN_00418bc0(param_1,uVar13);
  FUN_004198f0();
  if (bVar20) {
    *param_2 = (uint)local_64;
    return 0;
  }
  if (param_3 < local_64 + 1) {
    return 5;
  }
  fVar5 = (float)(byte)*local_64 * _DAT_00470aac;
  fVar6 = (float)*(byte *)((int)local_64 + 1) * _DAT_00470aac;
  puVar1 = (uint3 *)((int)local_64 + 5);
  fVar7 = (float)*(byte *)((int)local_64 + 2) * _DAT_00470aac;
  if (param_3 < puVar1) {
    return 6;
  }
  local_54 = (uint)*(ushort *)((int)local_64 + 3);
  uVar15 = local_54;
  if (local_54 != 0) {
    local_2c = 1.0;
    local_30 = 0.0;
    local_34 = 1.0;
    local_38 = 0.0;
    if (bVar21) {
      if (param_3 < (uint3 *)((int)local_64 + 0xbU)) {
        return 7;
      }
      local_30 = (float)((uint)*(uint3 *)((int)local_64 + 5) << 8);
      local_2c = (float)((uint)local_64[2] << 8);
      puVar1 = (uint3 *)((int)local_64 + 0xbU);
    }
    local_64 = puVar1;
    if (param_3 < (uint3 *)((int)local_64 + 0x12U)) {
      return 8;
    }
    local_48 = (float)((uint)*local_64 << 8);
    local_44 = (float)((uint)*(uint3 *)((int)local_64 + 3) << 8);
    local_40 = (float)((uint)*(uint3 *)((int)local_64 + 6) << 8);
    local_3c = (float)((uint)*(uint3 *)((int)local_64 + 9) << 8);
    local_50 = (float)((uint)local_64[3] << 8);
    local_4c = (float)((uint)*(uint3 *)((int)local_64 + 0xf) << 8);
    puVar1 = (uint3 *)((int)local_64 + 0x12U);
    if (bVar21) {
      if (param_3 < local_64 + 6) {
        return 9;
      }
      local_38 = (float)((uint)*(uint3 *)((int)local_64 + 0x12) << 8);
      local_34 = (float)((uint)*(uint3 *)((int)local_64 + 0x15) << 8);
      puVar1 = local_64 + 6;
    }
    local_64 = puVar1;
    puVar12 = local_64;
    bVar20 = false;
    if (((bVar2 & 8) != 0) && (bVar21)) {
      bVar20 = true;
    }
    bVar11 = true;
    if (((bVar2 & 4) == 0) && (bVar21)) {
      bVar11 = false;
    }
    bVar4 = true;
    if (((bVar2 & 2) == 0) && (bVar21)) {
      bVar4 = false;
    }
    local_88 = DAT_00470abc;
    local_90 = DAT_00470abc;
    local_8c = DAT_00470abc;
    if (((local_50 < local_4c) && (local_48 < local_44)) && (local_40 < local_3c)) {
      local_90 = (local_34 - local_38) / (local_4c - local_50);
      local_8c = (local_2c - local_30) / (local_44 - local_48);
      local_88 = (local_2c - local_30) / (local_3c - local_40);
    }
    iVar18 = local_54 * 2;
    local_64 = (uint3 *)((int)local_64 + local_54 * 3);
    if ((!bVar21) || (bVar4)) {
      puVar17 = (uint3 *)0x0;
    }
    else {
      puVar17 = local_64;
      local_64 = (uint3 *)((int)local_64 + local_54);
    }
    if (((!bVar21) || (bVar20)) || (bVar11)) {
      puVar19 = (uint3 *)0x0;
    }
    else {
      puVar19 = local_64;
      local_64 = (uint3 *)((int)local_64 + local_54);
    }
    if (param_3 < local_64) {
      return 10;
    }
    iVar16 = 0;
    puVar1 = local_64;
    if (local_54 != 0) {
      do {
        fVar8 = (local_4c - local_50) * (float)*(byte *)((int)puVar12 + iVar16) * _DAT_00470ac8 +
                local_50;
        fVar9 = (local_44 - local_48) * (float)*(byte *)((int)puVar12 + iVar16 + uVar15) *
                _DAT_00470ac8 + local_48;
        fVar10 = (local_3c - local_40) * (float)*(byte *)((int)puVar12 + iVar16 + iVar18) *
                 _DAT_00470ac8 + local_40;
        iVar14 = FUN_00418e70(param_1,fVar8,fVar9,fVar10);
        if (iVar14 != iVar16 + 1) {
          FUN_00402800(s_nShape_00470970,0x386);
        }
        if (puVar17 == (uint3 *)0x0) {
          local_78 = (fVar8 - local_50) * local_90;
        }
        else {
          local_78 = (local_34 - local_38) * (float)*(byte *)((int)puVar17 + iVar16) * _DAT_00470ac8
          ;
        }
        local_78 = local_78 + local_38;
        if (puVar19 == (uint3 *)0x0) {
          if (bVar20) {
            local_74 = (fVar10 - local_40) * local_88 + local_30;
          }
          else if (bVar11) {
            local_74 = (local_44 - fVar9) * local_8c + local_30;
          }
          else {
            FUN_00402800(s_nShape_00470970,0x396);
          }
        }
        else {
          local_74 = (local_2c - local_30) * (float)*(byte *)((int)puVar19 + iVar16) * _DAT_00470ac8
                     + local_30;
        }
        if ((byte)(local_78 < DAT_00470abc |
                  (byte)((ushort)((ushort)(NAN(local_78) || NAN(DAT_00470abc)) << 10) >> 8)) == 1) {
          local_78 = DAT_00470abc;
        }
        if ((byte)(local_74 < DAT_00470abc |
                  (byte)((ushort)((ushort)(NAN(local_74) || NAN(DAT_00470abc)) << 10) >> 8)) == 1) {
          local_74 = DAT_00470abc;
        }
        FUN_00419e00(param_1,iVar14,local_78,local_74);
        iVar16 = iVar16 + 1;
        puVar1 = local_64;
      } while (iVar16 < (int)local_54);
    }
  }
  local_64 = puVar1;
  if (param_3 < (uint3 *)((int)local_64 + 2U)) {
    return 0xd;
  }
  local_28 = (uint)(ushort)*local_64;
  local_64 = (uint3 *)((int)local_64 + 2U);
  uVar13 = FUN_00419920();
  FUN_00419ef0(uVar13,DAT_00470ac4,DAT_00470ac0,DAT_00470abc);
  FUN_00419e90(uVar13,fVar5,fVar6,fVar7);
  FUN_00417a10(uVar13);
  local_24 = 1;
  if (param_3 <= local_64) {
    return 0xe;
  }
  if (0 < (int)local_28) {
    local_20[0] = 1;
    local_20[1] = 2;
    local_20[2] = 3;
    FUN_00418e30(param_1,3,local_20);
  }
  iVar16 = 1;
  iVar18 = 2;
  if (1 < (int)local_28) {
    do {
      local_20[3] = 0;
      local_20[0] = FUN_0041d8e0(2,&local_64,&local_24,(byte *)param_3,local_20 + 3);
      local_20[0] = local_20[0] + iVar18;
      iVar14 = iVar18 + 4;
      local_20[1] = FUN_0041d8e0(iVar14,&local_64,&local_24,(byte *)param_3,local_20 + 3);
      local_20[1] = iVar18 - local_20[1];
      if (local_20[1] < 0) {
        local_20[1] = local_20[1] + iVar14;
      }
      if (local_20[1] == local_20[0]) {
        iVar18 = iVar18 + 1;
        iVar16 = iVar16 + -1;
      }
      else {
        local_20[2] = FUN_0041d8e0(iVar14,&local_64,&local_24,(byte *)param_3,local_20 + 3);
        local_20[2] = iVar18 - local_20[2];
        if (local_20[2] < 0) {
          local_20[2] = local_20[2] + iVar14;
        }
        iVar14 = 0;
        do {
          if (iVar18 < local_20[iVar14]) {
            iVar18 = local_20[iVar14];
          }
          iVar14 = iVar14 + 1;
        } while (iVar14 < 3);
        local_20[0] = local_20[0] + 1;
        local_20[1] = local_20[1] + 1;
        local_20[2] = local_20[2] + 1;
        FUN_00418e30(param_1,3,local_20);
      }
      if (local_20[3] != 0) {
        return 0xf;
      }
      iVar16 = iVar16 + 1;
    } while (iVar16 < (int)local_28);
  }
  if (1 < (int)local_24) {
    local_64 = (uint3 *)((int)local_64 + 1);
  }
  FUN_00417a90(param_1);
  FUN_004198c0();
  if (param_3 <= local_64) {
    return 0x10;
  }
  uVar15 = (uint)(byte)*local_64;
  local_64 = (uint3 *)((int)local_64 + 1);
  while( true ) {
    uVar15 = uVar15 - 1;
    if ((int)uVar15 < 0) {
      *param_2 = (uint)local_64;
      return 0;
    }
    iVar18 = FUN_00418f90();
    if (iVar18 == 0) {
      FUN_00402800(s_nShape_00470970,0x3e3);
    }
    iVar16 = FUN_0041d950(iVar18,(uint *)&local_64,param_3);
    if (iVar16 != 0) break;
    FUN_00418da0(param_1,iVar18);
  }
  FUN_004190d0(iVar18);
  return 0x11;
}


