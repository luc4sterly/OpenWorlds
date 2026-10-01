// 0041e780 FUN_0041e780 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041e780(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  bool bVar2;
  bool bVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  iVar5 = (**(code **)(*DAT_0049cfc0 + 0x3c))(DAT_0049cfc0);
  if (iVar5 != 0) {
    return;
  }
  iVar5 = FUN_004197d0(param_1);
  if (iVar5 != 3) {
    FUN_00402b70(DAT_0049cfc0,s_Special_clump_contains_a_non_tri_00470ad4);
    return;
  }
  FUN_00419800(param_1,&local_54);
  FUN_004195e0(DAT_0049cfc8,local_54,&local_48);
  FUN_004195e0(DAT_0049cfc8,local_50,&local_3c);
  FUN_004195e0(DAT_0049cfc8,local_4c,&local_30);
  bVar2 = false;
  bVar3 = false;
  fVar1 = local_44 - local_38;
  if (((byte)(fVar1 < _DAT_00470acc |
             (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_00470acc)) << 10) >> 8)) == 1) &&
     (_DAT_00470ad0 < fVar1)) {
    bVar2 = true;
  }
  if (bVar2) {
    local_10 = local_28;
    local_14 = local_2c;
    local_18 = local_30;
    fVar1 = local_48 - local_30;
    bVar2 = false;
    if (((byte)(fVar1 < _DAT_00470acc |
               (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_00470acc)) << 10) >> 8)) == 1) &&
       (_DAT_00470ad0 < fVar1)) {
      bVar2 = true;
    }
    if (bVar2) {
      bVar2 = false;
      fVar1 = local_40 - local_28;
      if (((byte)(fVar1 < _DAT_00470acc |
                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_00470acc)) << 10) >> 8)) == 1) &&
         (_DAT_00470ad0 < fVar1)) {
        bVar2 = true;
      }
      if (bVar2) {
        local_24 = local_3c;
        local_20 = local_38;
        local_1c = local_34;
        goto LAB_0041ecb0;
      }
    }
    local_3c = local_3c - local_30;
    bVar2 = false;
    if (((byte)(local_3c < _DAT_00470acc |
               (byte)((ushort)((ushort)(NAN(local_3c) || NAN(_DAT_00470acc)) << 10) >> 8)) == 1) &&
       (_DAT_00470ad0 < local_3c)) {
      bVar2 = true;
    }
    if (bVar2) {
      local_34 = local_34 - local_28;
      bVar2 = false;
      if (((byte)(local_34 < _DAT_00470acc |
                 (byte)((ushort)((ushort)(NAN(local_34) || NAN(_DAT_00470acc)) << 10) >> 8)) == 1)
         && (_DAT_00470ad0 < local_34)) {
        bVar2 = true;
      }
      if (bVar2) {
        bVar3 = true;
        local_24 = local_48;
        local_20 = local_44;
        local_1c = local_40;
        goto LAB_0041ecb0;
      }
    }
    FUN_00402b70(DAT_0049cfc0,s_Special_clump_has_a_non_vertical_00470afc);
    return;
  }
  bVar2 = false;
  fVar1 = local_44 - local_2c;
  if (((byte)(fVar1 < _DAT_00470acc |
             (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_00470acc)) << 10) >> 8)) == 1) &&
     (_DAT_00470ad0 < fVar1)) {
    bVar2 = true;
  }
  if (!bVar2) {
    bVar2 = false;
    fVar1 = local_38 - local_2c;
    if (((byte)(fVar1 < _DAT_00470acc |
               (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_00470acc)) << 10) >> 8)) == 1) &&
       (_DAT_00470ad0 < fVar1)) {
      bVar2 = true;
    }
    if (!bVar2) {
      FUN_00402b70(DAT_0049cfc0,s_Special_clump_has_a_non_horizont_00470b24);
      return;
    }
    local_14 = local_44;
    bVar2 = false;
    local_10 = local_40;
    fVar1 = local_48 - local_3c;
    local_18 = local_48;
    if (((byte)(fVar1 < _DAT_00470acc |
               (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_00470acc)) << 10) >> 8)) == 1) &&
       (_DAT_00470ad0 < fVar1)) {
      bVar2 = true;
    }
    if (bVar2) {
      fVar1 = local_40 - local_34;
      bVar2 = false;
      if (((byte)(fVar1 < _DAT_00470acc |
                 (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_00470acc)) << 10) >> 8)) == 1) &&
         (_DAT_00470ad0 < fVar1)) {
        bVar2 = true;
      }
      if (bVar2) {
        local_24 = local_30;
        local_20 = local_2c;
        local_1c = local_28;
        goto LAB_0041ecb0;
      }
    }
    local_48 = local_48 - local_30;
    bVar2 = false;
    if (((byte)(local_48 < _DAT_00470acc |
               (byte)((ushort)((ushort)(NAN(local_48) || NAN(_DAT_00470acc)) << 10) >> 8)) == 1) &&
       (_DAT_00470ad0 < local_48)) {
      bVar2 = true;
    }
    if (bVar2) {
      local_40 = local_40 - local_28;
      bVar2 = false;
      if (((byte)(local_40 < _DAT_00470acc |
                 (byte)((ushort)((ushort)(NAN(local_40) || NAN(_DAT_00470acc)) << 10) >> 8)) == 1)
         && (_DAT_00470ad0 < local_40)) {
        bVar2 = true;
      }
      if (bVar2) {
        bVar3 = true;
        local_24 = local_3c;
        local_20 = local_38;
        local_1c = local_34;
        goto LAB_0041ecb0;
      }
    }
    FUN_00402b70(DAT_0049cfc0,s_Special_clump_has_a_non_vertical_00470afc);
    return;
  }
  local_14 = local_38;
  bVar2 = false;
  local_10 = local_34;
  fVar1 = local_48 - local_3c;
  local_18 = local_3c;
  if (((byte)(fVar1 < _DAT_00470acc |
             (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_00470acc)) << 10) >> 8)) == 1) &&
     (_DAT_00470ad0 < fVar1)) {
    bVar2 = true;
  }
  if (bVar2) {
    fVar1 = local_40 - local_34;
    bVar2 = false;
    if (((byte)(fVar1 < _DAT_00470acc |
               (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_00470acc)) << 10) >> 8)) == 1) &&
       (_DAT_00470ad0 < fVar1)) {
      bVar2 = true;
    }
    if (bVar2) {
      bVar3 = true;
      local_24 = local_30;
      local_20 = local_2c;
      local_1c = local_28;
      goto LAB_0041ecb0;
    }
  }
  local_30 = local_30 - local_3c;
  bVar2 = false;
  if (((byte)(local_30 < _DAT_00470acc |
             (byte)((ushort)((ushort)(NAN(local_30) || NAN(_DAT_00470acc)) << 10) >> 8)) == 1) &&
     (_DAT_00470ad0 < local_30)) {
    bVar2 = true;
  }
  if (bVar2) {
    local_28 = local_28 - local_34;
    bVar2 = false;
    if (((byte)(local_28 < _DAT_00470acc |
               (byte)((ushort)((ushort)(NAN(local_28) || NAN(_DAT_00470acc)) << 10) >> 8)) == 1) &&
       (_DAT_00470ad0 < local_28)) {
      bVar2 = true;
    }
    if (bVar2) {
      local_24 = local_48;
      local_20 = local_44;
      local_1c = local_40;
LAB_0041ecb0:
      fVar4 = local_10;
      fVar1 = local_18;
      if (local_14 <= local_20) {
        return;
      }
      if (!bVar3) {
        local_18 = local_24;
        local_24 = fVar1;
        local_10 = local_1c;
        local_1c = fVar4;
      }
      uVar6 = FUN_00419950();
      FUN_004193c0(DAT_0049cfc8,uVar6);
      FUN_0041a080(&local_24,uVar6);
      FUN_0041a080(&local_18,uVar6);
      FUN_004198f0();
      if (DAT_0049cfc4 == 0) {
        uVar6 = FUN_00415a40(DAT_0049cfc0,DAT_00489648,DAT_00489654);
        FUN_00412800(DAT_0049cfc0,uVar6,DAT_004a0428);
      }
      else {
        (**(code **)(*DAT_0049cfc0 + 0x29c))(DAT_0049cfc0,DAT_0049cfc4);
        uVar6 = FUN_00415a40(DAT_0049cfc0,DAT_0048964c,DAT_00489658);
      }
      iVar5 = (**(code **)(*DAT_0049cfc0 + 0x3c))(DAT_0049cfc0);
      if (iVar5 == 0) {
        FUN_00412800(DAT_0049cfc0,uVar6,DAT_0049fa74);
        iVar5 = (**(code **)(*DAT_0049cfc0 + 0x3c))(DAT_0049cfc0);
        if (iVar5 == 0) {
          FUN_00412800(DAT_0049cfc0,param_2,DAT_0049fcf0);
          return;
        }
        return;
      }
      return;
    }
  }
  FUN_00402b70(DAT_0049cfc0,s_Special_clump_has_a_non_vertical_00470afc);
  return;
}


