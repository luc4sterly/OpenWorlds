// 0044a5d0 FUN_0044a5d0 [Global]
// program: gamma.dll

uint __thiscall FUN_0044a5d0(void *this,int *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  uint local_5c;
  uint local_58;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_38;
  int local_34;
  
  uVar6 = param_2[1];
  bVar7 = false;
  if (uVar6 == 0) {
    uVar1 = *param_2;
    bVar7 = SBORROW4(uVar1,80000);
    uVar6 = uVar1 - 80000;
    if (79999 < uVar1) goto LAB_0044a5ec;
  }
  else {
LAB_0044a5ec:
    if (bVar7 == (int)uVar6 < 0) {
      uVar6 = *param_2;
      *param_2 = *param_2 - 80000;
      param_2[1] = param_2[1] - (uint)(uVar6 < 80000);
      uVar6 = *param_3;
      *param_3 = *param_3 - 80000;
      param_3[1] = param_3[1] - (uint)(uVar6 < 80000);
    }
  }
  uVar6 = param_2[1];
  *(uint *)((int)this + 0xf0) = *param_2;
  *(uint *)((int)this + 0xf4) = uVar6;
  (**(code **)(**(int **)((int)this + 0x18) + 0xc))(*(int **)((int)this + 0x18),&local_48);
  bVar7 = local_48 < *(uint *)((int)this + 0x1c);
  local_48 = local_48 - *(uint *)((int)this + 0x1c);
  local_44 = (local_44 - *(int *)((int)this + 0x20)) - (uint)bVar7;
  local_38 = local_48 - *param_2;
  local_34 = (local_44 - param_2[1]) - (uint)(local_48 < *param_2);
  bVar7 = SBORROW4(local_34,-1);
  iVar2 = local_34 + 1;
  if (local_34 == -1) {
    bVar7 = SBORROW4(local_38,-500000000);
    iVar2 = local_38 + 500000000;
    if (local_38 < 0xe2329b00) goto LAB_0044a64d;
LAB_0044a658:
    bVar9 = false;
    bVar7 = false;
    iVar2 = local_34;
    local_58 = local_38;
    if (local_34 == 0) {
      bVar9 = SBORROW4(local_38,500000000);
      iVar2 = local_38 + 0xe2329b00;
      bVar7 = local_38 == 500000000;
      if (local_38 < 0x1dcd6501) goto LAB_0044a678;
    }
    if (!bVar7 && bVar9 == iVar2 < 0) {
      local_58 = 500000000;
    }
  }
  else {
LAB_0044a64d:
    if (bVar7 == iVar2 < 0) goto LAB_0044a658;
    local_58 = 0xe2329b00;
  }
LAB_0044a678:
  iVar2 = (**(code **)(*(int *)this + 0x1b4))(local_58,(int)local_58 >> 0x1f,local_48,local_44);
  *(uint *)((int)this + 200) = (uint)(iVar2 == 0);
  iVar3 = *param_3 - *param_2;
  iVar2 = *(int *)((int)this + 0xec);
  iVar4 = (int)(iVar2 + (iVar2 >> 0x1f & 0x1fU)) >> 5;
  if ((iVar4 + iVar2 < iVar3) || (iVar3 < iVar2 - iVar4)) {
    *(int *)((int)this + 0xe8) = iVar3;
    *(int *)((int)this + 0xec) = iVar3;
  }
  bVar7 = false;
  bVar9 = true;
  if ((*(int *)((int)this + 200) != 0) &&
     (iVar2 = (**(code **)(*param_1 + 0x3c))(param_1), iVar2 == 0)) {
    bVar7 = true;
  }
  if ((!bVar7) && (*(int *)((int)this + 0xc4) != -1)) {
    bVar9 = false;
  }
  if ((int)local_58 < 1) {
    iVar2 = *(int *)((int)this + 0xdc);
    if ((iVar2 <= (int)local_58) || (bVar9)) {
      *(uint *)((int)this + 0xdc) = local_58;
    }
    else {
      *(int *)((int)this + 0xdc) = iVar2 - ((int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3);
    }
  }
  else {
    *(undefined4 *)((int)this + 0xdc) = 0;
  }
  if ((int)local_58 < 0) {
    iVar2 = -local_58;
  }
  else {
    iVar2 = 0;
  }
  iVar2 = *(int *)((int)this + 0xe4) * 3 + iVar2;
  iVar5 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
  uVar6 = local_48 - *(uint *)((int)this + 0x110);
  iVar4 = (local_44 - *(int *)((int)this + 0x114)) - (uint)(local_48 < *(uint *)((int)this + 0x110))
  ;
  bVar8 = false;
  bVar7 = iVar4 == 0;
  iVar2 = iVar4;
  local_40 = uVar6;
  if (bVar7) {
    bVar8 = SBORROW4(uVar6,10000000);
    iVar2 = uVar6 - 10000000;
    bVar7 = uVar6 == 10000000;
    if (10000000 < uVar6) goto LAB_0044a7b8;
  }
  else {
LAB_0044a7b8:
    if (!bVar7 && bVar8 == iVar2 < 0) {
      local_40 = 10000000;
    }
  }
  local_5c = local_40;
  if (*(int *)((int)this + 0xe8) < *(int *)((int)this + 0xd0) * 3) {
    if (*(int *)((int)this + 200) == 0) {
      bVar7 = (int)(local_58 * 2) < iVar3;
    }
    else {
      bVar7 = (int)local_58 <= iVar3 * 4;
    }
    if ((!bVar7) && (*(int *)((int)this + 0xe4) < 0x13881)) {
      bVar8 = false;
      bVar7 = false;
      if (iVar4 == 0) {
        bVar8 = SBORROW4(uVar6,10000000);
        iVar4 = uVar6 - 10000000;
        bVar7 = uVar6 == 10000000;
        if (uVar6 < 0x989681) goto LAB_0044aa32;
      }
      if (bVar7 || bVar8 != iVar4 < 0) {
LAB_0044aa32:
        *(int *)((int)this + 0xe4) = iVar5;
        *(undefined4 *)((int)this + 0xc4) = 0xffffffff;
        return 0x80004005;
      }
    }
  }
  bVar7 = false;
  if (bVar9) {
    bVar7 = true;
  }
  else if ((((int)(iVar3 + (iVar3 >> 0x1f & 0xfU)) >> 4) + iVar3 < *(int *)((int)this + 0xe8)) &&
          (iVar3 * -10 < (int)local_58)) {
    bVar7 = true;
  }
  if ((int)local_58 < -9000000) {
    bVar7 = false;
  }
  if (bVar7) {
    *(undefined4 *)((int)this + 0xc4) = 0;
    iVar2 = *(int *)((int)this + 0xe4) * 3;
    *(int *)((int)this + 0xe4) = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
    iVar2 = *(int *)((int)this + 0xe8) * 3 + local_40;
    *(int *)((int)this + 0xe8) = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
    *(uint *)((int)this + 0x128) = local_58;
    *(uint *)((int)this + 300) = local_40;
    *(uint *)((int)this + 0x110) = local_48;
    *(uint *)((int)this + 0x114) = local_44;
    if ((int)local_58 < *(int *)((int)this + 0xdc)) {
      *(uint *)((int)this + 0xdc) = local_58;
    }
    return 0;
  }
  *(int *)((int)this + 0xc4) = *(int *)((int)this + 0xc4) + 1;
  *(int *)((int)this + 0xe8) = iVar3;
  uVar6 = *(uint *)((int)this + 0xdc);
  if ((int)*(uint *)((int)this + 0xdc) < -*(int *)((int)this + 0xe8)) {
    uVar6 = -*(int *)((int)this + 0xe8);
  }
  uVar1 = *param_2;
  *param_2 = *param_2 + uVar6;
  param_2[1] = param_2[1] + ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar1,uVar6);
  uVar6 = (uint)(0 < (int)-local_58);
  *(int *)((int)this + 0xe4) = iVar5;
  if (uVar6 == 1) {
    local_44 = param_2[1];
    local_48 = *param_2;
    local_5c = local_48 - *(uint *)((int)this + 0x110);
    iVar3 = (local_44 - *(int *)((int)this + 0x114)) -
            (uint)(local_48 < *(uint *)((int)this + 0x110));
    bVar7 = SBORROW4(iVar3,-1);
    iVar2 = iVar3 + 1;
    if (iVar3 == -1) {
      bVar7 = SBORROW4(local_5c,-500000000);
      iVar2 = local_5c + 500000000;
      if (local_5c < 0xe2329b00) goto LAB_0044a96f;
    }
    else {
LAB_0044a96f:
      if (bVar7 != iVar2 < 0) {
        local_5c = 0xe2329b00;
        goto LAB_0044a9b6;
      }
    }
    bVar9 = false;
    bVar7 = false;
    if (iVar3 == 0) {
      bVar9 = SBORROW4(local_5c,500000000);
      iVar3 = local_5c + 0xe2329b00;
      bVar7 = local_5c == 500000000;
      if (local_5c < 0x1dcd6501) goto LAB_0044a9b6;
    }
    if (!bVar7 && bVar9 == iVar3 < 0) {
      local_5c = 500000000;
    }
  }
LAB_0044a9b6:
  *(uint *)((int)this + 0x110) = local_48;
  *(uint *)((int)this + 0x114) = local_44;
  if ((int)-local_58 < 1) goto LAB_0044aa16;
  local_58 = *param_2 - *(uint *)((int)this + 0xf0);
  iVar3 = (param_2[1] - *(int *)((int)this + 0xf4)) - (uint)(*param_2 < *(uint *)((int)this + 0xf0))
  ;
  bVar7 = SBORROW4(iVar3,-1);
  iVar2 = iVar3 + 1;
  if (iVar3 == -1) {
    bVar7 = SBORROW4(local_58,-500000000);
    iVar2 = local_58 + 500000000;
    if (local_58 < 0xe2329b00) goto LAB_0044a9ea;
  }
  else {
LAB_0044a9ea:
    if (bVar7 != iVar2 < 0) {
      local_58 = 0xe2329b00;
      goto LAB_0044aa16;
    }
  }
  bVar9 = false;
  bVar7 = false;
  if (iVar3 == 0) {
    bVar9 = SBORROW4(local_58,500000000);
    iVar3 = local_58 + 0xe2329b00;
    bVar7 = local_58 == 500000000;
    if (local_58 < 0x1dcd6501) goto LAB_0044aa16;
  }
  if (!bVar7 && bVar9 == iVar3 < 0) {
    local_58 = 500000000;
  }
LAB_0044aa16:
  *(uint *)((int)this + 0x128) = local_58;
  *(uint *)((int)this + 300) = local_5c;
  return uVar6;
}


