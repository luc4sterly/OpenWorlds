// 004244b0 FUN_004244b0 [Global]
// program: gamma.dll

void __thiscall FUN_004244b0(void *this,undefined4 *param_1,int param_2,undefined1 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  undefined1 *puVar7;
  uint uVar8;
  
  if (param_2 == 0) {
    return;
  }
  uVar3 = *(int *)((int)this + 4) + param_2;
  uVar8 = *(uint *)this;
  if (uVar8 < uVar3) {
    puVar1 = *(undefined4 **)((int)this + 8);
    uVar5 = (int)param_1 - (int)puVar1;
    if (uVar8 == 0) {
      uVar8 = 1;
    }
    for (; uVar8 < uVar3; uVar8 = uVar8 * 2) {
    }
    puVar6 = FUN_0044e010(uVar8);
    *(uint **)((int)this + 8) = puVar6;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_0044df50(*(undefined4 **)((int)this + 8),puVar1,uVar5);
      FUN_0044df50((undefined4 *)(*(int *)((int)this + 8) + uVar5 + param_2),
                   (undefined4 *)((int)puVar1 + uVar5),
                   (int)puVar1 + (*(int *)((int)this + 4) - (int)((int)puVar1 + uVar5)));
      FUN_0044e100(puVar1);
    }
    puVar7 = (undefined1 *)(*(int *)((int)this + 8) + uVar5);
    for (; param_2 != 0; param_2 = param_2 + -1) {
      *puVar7 = *param_3;
      puVar7 = puVar7 + 1;
    }
    *(uint *)((int)this + 4) = uVar3;
    *(uint *)this = uVar8;
  }
  else {
    iVar4 = *(int *)((int)this + 8) + *(int *)((int)this + 4);
    uVar8 = iVar4 - (int)param_1;
    iVar2 = param_2;
    if (uVar8 != 0) {
      FUN_0044ded0((undefined4 *)((iVar4 + param_2) - uVar8),param_1,uVar8);
    }
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)param_1 = *param_3;
      param_1 = (undefined4 *)((int)param_1 + 1);
    }
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + param_2;
  }
  return;
}


