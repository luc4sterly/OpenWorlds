// 00442bc0 FUN_00442bc0 [Global]
// program: gamma.dll

int __thiscall FUN_00442bc0(void *this,int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  uint *this_00;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined1 *local_68;
  int local_60;
  ushort *local_5c;
  uint local_54;
  uint local_50;
  int local_4c;
  int local_3c;
  int local_38;
  ushort *local_34 [2];
  int local_2c [5];
  int local_18;
  undefined4 local_14;
  
  if (*(int *)((int)this + 0x54) == 0) {
    this_00 = FUN_0044e010(8);
    if (this_00 != (uint *)0x0) {
      FUN_004269c0(this_00,(byte *)((int)this + 0x58),*(int *)((int)this + 0x158),(char *)0x0,0);
    }
    *(uint **)((int)this + 0x54) = this_00;
    if (*(int *)((int)this + 0x54) == 0) {
      *(undefined4 *)this = 4;
      return *(int *)this;
    }
  }
  if (param_3 < *(int *)((int)this + 8)) {
    FUN_00402800(s_scapeimpl_00479318,0x13b);
  }
  if (param_3 != *(int *)((int)this + 0x38)) {
    iVar4 = 0;
    do {
      *(int *)(*(int *)((int)this + 0x34) + iVar4 * 4) =
           (&DAT_00478e9c)[iVar4 * 2] - param_3 * (&DAT_00478e98)[iVar4 * 2];
      *(int *)(*(int *)((int)this + 0x34) + 4 + iVar4 * 4) =
           (&DAT_00478ea4)[iVar4 * 2] - param_3 * (&DAT_00478ea0)[iVar4 * 2];
      *(int *)(*(int *)((int)this + 0x34) + 8 + iVar4 * 4) =
           (&DAT_00478eac)[iVar4 * 2] - param_3 * (&DAT_00478ea8)[iVar4 * 2];
      *(int *)(*(int *)((int)this + 0x34) + 0xc + iVar4 * 4) =
           (&DAT_00478eb4)[iVar4 * 2] - param_3 * (&DAT_00478eb0)[iVar4 * 2];
      *(int *)(*(int *)((int)this + 0x34) + 0x10 + iVar4 * 4) =
           (&DAT_00478ebc)[iVar4 * 2] - param_3 * (&DAT_00478eb8)[iVar4 * 2];
      *(int *)(*(int *)((int)this + 0x34) + 0x14 + iVar4 * 4) =
           (&DAT_00478ec4)[iVar4 * 2] - param_3 * (&DAT_00478ec0)[iVar4 * 2];
      *(int *)(*(int *)((int)this + 0x34) + 0x18 + iVar4 * 4) =
           (&DAT_00478ecc)[iVar4 * 2] - param_3 * (&DAT_00478ec8)[iVar4 * 2];
      *(int *)(*(int *)((int)this + 0x34) + 0x1c + iVar4 * 4) =
           (&DAT_00478ed4)[iVar4 * 2] - param_3 * (&DAT_00478ed0)[iVar4 * 2];
      iVar4 = iVar4 + 8;
    } while (iVar4 < 0x2a);
    *(int *)(*(int *)((int)this + 0x34) + iVar4 * 4) =
         (&DAT_00478e9c)[iVar4 * 2] - param_3 * (&DAT_00478e98)[iVar4 * 2];
    *(int *)(*(int *)((int)this + 0x34) + 4 + iVar4 * 4) =
         (&DAT_00478ea4)[iVar4 * 2] - param_3 * (&DAT_00478ea0)[iVar4 * 2];
    *(int *)((int)this + 0x38) = param_3;
  }
  if (*(int *)((int)this + 0x24) <= param_1) {
    FUN_00402800(s_scapeimpl_00479318,0x145);
  }
  iVar4 = *(int *)(*(int *)((int)this + 0x28) + param_1 * 4);
  if (*(int *)((int)this + 0x30) != iVar4) {
    local_14 = 0;
    local_18 = iVar4;
    FUN_004431d0(*(void **)((int)this + 4),iVar4,0);
    *(int *)((int)this + 0x30) = iVar4;
  }
  if (*(char *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x32) == '\0') {
    uVar5 = 0;
  }
  else {
    uVar5 = 2;
  }
  *(undefined4 *)this = uVar5;
  local_54 = *(uint *)(*(int *)((int)this + 0x2c) + param_1 * 4);
  FUN_00426bc0(&local_3c,*(int *)((int)this + 0x40));
  iVar4 = *(int *)((int)this + 8);
  local_4c = 0;
  iVar2 = *(int *)((int)this + 0xc);
  while( true ) {
    if (*(int *)((int)this + 0xc) <= local_4c) {
      iVar4 = *(int *)this;
      FUN_00426c40(&local_3c);
      return iVar4;
    }
    FUN_00426bc0(local_34,local_54);
    puVar3 = local_34[0];
    FUN_0042f460(*(void **)((int)this + 4),(undefined1 *)local_34[0],local_54);
    *(int *)((int)this + 0x30) = *(int *)((int)this + 0x30) + local_54;
    if (*(char *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x32) == '\0') {
      uVar5 = 0;
    }
    else {
      uVar5 = 2;
    }
    *(undefined4 *)this = uVar5;
    if (*(int *)this != 0) break;
    local_54 = (uint)puVar3[6];
    local_5c = puVar3 + 8;
    local_50 = (uint)*puVar3;
    if (((puVar3[7] & 0x7fff) != 0) || (*(char *)((int)puVar3 + 0xf) < '\0')) {
      *(undefined4 *)this = 6;
      iVar4 = *(int *)this;
      FUN_00426c40((int *)local_34);
      FUN_00426c40(&local_3c);
      return iVar4;
    }
    local_60 = 0;
    local_68 = (undefined1 *)(local_3c + 0x400);
    iVar1 = local_38 + -0x400;
    iVar7 = 0;
    do {
      uVar6 = (uint)puVar3[iVar7 + 1];
      if (uVar6 != 0) {
        local_60 = local_60 + uVar6;
        if (iVar1 < local_60) {
          *(undefined4 *)this = 6;
          iVar4 = *(int *)this;
          FUN_00426c40((int *)local_34);
          FUN_00426c40(&local_3c);
          return iVar4;
        }
        uVar8 = FUN_00426af0(*(void **)((int)this + iVar7 * 4 + 0x44),local_5c,local_68,uVar6);
        local_2c[iVar7] = (int)local_68;
        if (iVar7 == 0) {
          uVar6 = uVar6 + 2 & 0xfffffffc;
        }
        local_68 = local_68 + uVar6;
        local_5c = (ushort *)((int)local_5c + (int)uVar8);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 5);
    FUN_0044df50((undefined4 *)&DAT_00482d0d,*(undefined4 **)((int)this + 0x34),200);
    FUN_00457d88((undefined4 *)((((iVar2 + 1U & 0xfffffffe) - 1) - local_4c) * param_3 + param_2),
                 *(undefined2 **)((int)this + 0x3c),local_50,iVar4 + 3 >> 2,-param_3,local_2c);
    local_4c = local_4c + local_50 * 2;
    FUN_00426c40((int *)local_34);
  }
  iVar4 = *(int *)this;
  FUN_00426c40((int *)local_34);
  FUN_00426c40(&local_3c);
  return iVar4;
}


