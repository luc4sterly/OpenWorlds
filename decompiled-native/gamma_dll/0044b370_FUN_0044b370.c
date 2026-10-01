// 0044b370 FUN_0044b370 [Global]
// program: gamma.dll

undefined8
FUN_0044b370(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
            uint param_7,uint param_8)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  uint local_cc;
  uint local_c8;
  undefined8 local_c4;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  int local_a8;
  int local_98;
  uint local_7c;
  uint local_74;
  uint local_6c;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  int local_54;
  uint local_4c;
  uint local_14;
  uint local_10;
  
  uVar6 = param_2;
  if (param_2 == 0) {
    uVar6 = param_1;
  }
  if ((int)uVar6 < 0) {
    local_7c = -param_1;
    uVar6 = -(param_2 + (param_1 != 0));
  }
  else {
    local_7c = param_1;
    uVar6 = param_2;
  }
  uVar3 = param_4;
  if (param_4 == 0) {
    uVar3 = param_3;
  }
  if ((int)uVar3 < 0) {
    local_74 = -param_3;
    uVar3 = -(param_4 + (param_3 != 0));
  }
  else {
    local_74 = param_3;
    uVar3 = param_4;
  }
  uVar4 = param_6;
  if (param_6 == 0) {
    uVar4 = param_5;
  }
  if ((int)uVar4 < 0) {
    local_6c = -param_5;
    uVar4 = -(param_6 + (param_5 != 0));
  }
  else {
    local_6c = param_5;
    uVar4 = param_6;
  }
  bVar9 = 0x7fffffff < param_4 != 0x7fffffff < param_2;
  local_cc = (uint)((ulonglong)local_7c * (ulonglong)local_74);
  uVar10 = (ulonglong)local_7c * (ulonglong)uVar3 + (ulonglong)uVar6 * (ulonglong)local_74 +
           ((ulonglong)local_7c * (ulonglong)local_74 >> 0x20);
  local_c8 = (uint)uVar10;
  local_c4 = (ulonglong)uVar6 * (ulonglong)uVar3 + (uVar10 >> 0x20);
  if (param_8 == 0 && param_7 == 0) goto LAB_0044b752;
  if (bVar9) {
    local_b4 = -param_7;
    local_b0 = -(param_8 + (param_7 != 0));
    if (((param_8 == 0) && (param_8 = param_7, param_7 == 0)) || ((int)param_8 < 0)) {
LAB_0044b670:
      local_a8 = 0;
      local_ac = 0;
    }
    else {
      local_ac = 0xffffffff;
      local_a8 = -1;
    }
  }
  else {
    local_b4 = param_7;
    local_b0 = param_8;
    if ((param_8 == 0) || (-1 < (int)param_8)) goto LAB_0044b670;
    local_ac = 0xffffffff;
    local_a8 = -1;
  }
  bVar7 = CARRY4(local_b4,local_cc);
  local_cc = local_b4 + local_cc;
  bVar8 = CARRY4(local_b0,local_c8);
  local_b0 = local_b0 + local_c8;
  local_c8 = bVar7 + local_b0;
  uVar6 = (uint)bVar8 + (uint)CARRY4((uint)bVar7,local_b0);
  lVar1 = CONCAT44(local_a8 + (uint)CARRY4(local_ac,uVar6),local_ac + uVar6);
  lVar2 = local_c4 + lVar1;
  local_c4 = local_c4 + lVar1;
  if (lVar2 < 0) {
    bVar9 = !bVar9;
    uVar6 = ~local_cc;
    local_cc = uVar6 + 1;
    local_c8 = ~local_c8 + (uint)(0xfffffffe < uVar6);
    uVar6 = (uint)(local_c8 == 0 && local_cc == 0);
    local_c4 = CONCAT44(~(uint)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(~(uint)lVar2,uVar6),
                        ~(uint)lVar2 + uVar6);
  }
LAB_0044b752:
  if ((param_6 != 0) && ((int)param_6 < 0)) {
    bVar9 = !bVar9;
  }
  bVar7 = uVar4 < local_c4._4_4_;
  if (uVar4 == local_c4._4_4_) {
    bVar7 = local_6c < (uint)local_c4;
  }
  if (bVar7 || uVar4 == local_c4._4_4_ && local_6c == (uint)local_c4) {
    if (bVar9) {
      local_60 = 0x80000000;
      local_64 = 0;
    }
    else {
      local_64 = 0xffffffff;
      local_60 = 0x7fffffff;
    }
    return CONCAT44(local_60,local_64);
  }
  if (local_c4._4_4_ == 0 && (uint)local_c4 == 0) {
    uVar10 = FUN_00453bc0(local_cc,local_c8,local_6c,uVar4);
    local_5c = (int)uVar10;
    local_98 = (int)(uVar10 >> 0x20);
    if (bVar9) {
      bVar9 = local_5c != 0;
      local_5c = -local_5c;
      local_98 = -(local_98 + (uint)bVar9);
    }
    return CONCAT44(local_98,local_5c);
  }
  if (uVar4 != 0) {
    iVar5 = 0;
    local_14 = 0;
    local_10 = 0;
    do {
      local_10 = local_10 << 1 | local_14 >> 0x1f;
      uVar6 = local_c4._4_4_ << 1 | (uint)local_c4 >> 0x1f;
      local_14 = local_14 * 2;
      local_c4._0_4_ = (uint)local_c4 * 2;
      if ((local_c8 & 0x80000000) != 0) {
        local_c4._0_4_ = (uint)local_c4 + 1;
      }
      local_c4 = CONCAT44(uVar6,(uint)local_c4);
      local_c8 = local_c8 << 1 | local_cc >> 0x1f;
      local_cc = local_cc * 2;
      bVar7 = uVar4 < uVar6;
      if (uVar4 == uVar6) {
        bVar7 = local_6c < (uint)local_c4;
      }
      if (bVar7 || uVar4 == uVar6 && local_6c == (uint)local_c4) {
        local_c4 = CONCAT44((uVar6 - uVar4) - (uint)((uint)local_c4 < local_6c),
                            (uint)local_c4 - local_6c);
        bVar7 = 0xfffffffe < local_14;
        local_14 = local_14 + 1;
        local_10 = local_10 + bVar7;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x40);
    if (bVar9) {
      local_4c = -local_14;
      local_10 = -(local_10 + (local_14 != 0));
    }
    else {
      local_4c = local_14;
    }
    return CONCAT44(local_10,local_4c);
  }
  uVar10 = FUN_00453bc0(local_c8,(uint)local_c4,local_6c,0);
  uVar11 = FUN_00453d00(local_c8,(uint)local_c4,local_6c,0);
  uVar11 = FUN_00453bc0(local_cc,(uint)uVar11,local_6c,0);
  local_54 = (int)uVar11;
  iVar5 = (int)uVar10 + (int)(uVar11 >> 0x20);
  if (bVar9) {
    bVar9 = local_54 != 0;
    local_54 = -local_54;
    iVar5 = -(iVar5 + (uint)bVar9);
  }
  return CONCAT44(iVar5,local_54);
}


