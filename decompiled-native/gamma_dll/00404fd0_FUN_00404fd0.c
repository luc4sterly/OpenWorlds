// 00404fd0 FUN_00404fd0 [Global]
// programa: gamma.dll

void __thiscall FUN_00404fd0(void *this,undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint local_30;
  
  if (param_2 == 0) {
    return;
  }
  uVar2 = *(int *)((int)this + 4) + param_2;
  local_30 = *(uint *)this;
  if (local_30 < uVar2) {
    puVar8 = *(undefined4 **)((int)this + 8);
    iVar3 = (int)(((int)param_1 - (int)puVar8) + ((int)param_1 - (int)puVar8 >> 0x1f & 3U)) >> 2;
    if (local_30 == 0) {
      local_30 = 1;
    }
    for (; local_30 < uVar2; local_30 = local_30 * 2) {
    }
    puVar4 = FUN_0044e010(local_30 * 4);
    *(uint **)((int)this + 8) = puVar4;
    if (puVar8 != (undefined4 *)0x0) {
      puVar7 = *(undefined4 **)((int)this + 8);
      puVar5 = puVar8 + iVar3;
      for (puVar6 = puVar8; puVar6 < puVar5; puVar6 = puVar6 + 1) {
        *puVar7 = *puVar6;
        puVar7 = puVar7 + 1;
      }
      iVar1 = *(int *)((int)this + 4);
      puVar7 = (undefined4 *)(param_2 * 4 + *(int *)((int)this + 8) + iVar3 * 4);
      for (; puVar5 < puVar8 + iVar1; puVar5 = puVar5 + 1) {
        *puVar7 = *puVar5;
        puVar7 = puVar7 + 1;
      }
      FUN_0044e100(puVar8);
    }
    puVar8 = (undefined4 *)(iVar3 * 4 + *(int *)((int)this + 8));
    for (; param_2 != 0; param_2 = param_2 + -1) {
      *puVar8 = *param_3;
      puVar8 = puVar8 + 1;
    }
    *(uint *)((int)this + 4) = uVar2;
    *(uint *)this = local_30;
  }
  else {
    puVar8 = (undefined4 *)(*(int *)((int)this + 4) * 4 + *(int *)((int)this + 8));
    iVar3 = param_2;
    if ((int)(((int)puVar8 - (int)param_1) + ((int)puVar8 - (int)param_1 >> 0x1f & 3U)) >> 2 != 0) {
      puVar7 = puVar8 + param_2;
      while (param_1 < puVar8) {
        puVar8 = puVar8 + -1;
        puVar7 = puVar7 + -1;
        *puVar7 = *puVar8;
      }
    }
    for (; iVar3 != 0; iVar3 = iVar3 + -1) {
      *param_1 = *param_3;
      param_1 = param_1 + 1;
    }
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + param_2;
  }
  return;
}


