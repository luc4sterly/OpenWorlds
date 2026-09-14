// 004500b0 FUN_004500b0 [Global]
// programa: gamma.dll

int __cdecl FUN_004500b0(int *param_1)

{
  void *this;
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  if (DAT_0049f994 == 0) {
    DAT_0049fcf4 = DAT_0049fcf4 + 1;
    DAT_0049f994 = DAT_0049fcf4;
  }
  uVar1 = DAT_0049f994;
  if ((*(uint *)(*param_1 + 4) <= DAT_0049f994) ||
     (iVar4 = *(int *)(DAT_0049f994 * 4 + *(int *)(*param_1 + 8)), iVar4 == 0)) {
    puVar3 = FUN_0044e010(8);
    if (puVar3 != (uint *)0x0) {
      *puVar3 = (uint)&PTR_LAB_0046d714;
      puVar3[1] = 0;
      *puVar3 = (uint)&PTR_LAB_004810b4;
    }
    this = (void *)*param_1;
    if (DAT_0049f994 == 0) {
      DAT_0049fcf4 = DAT_0049fcf4 + 1;
      DAT_0049f994 = DAT_0049fcf4;
    }
    uVar2 = DAT_0049f994;
    if (*(uint *)((int)this + 4) <= DAT_0049f994) {
      FUN_00404e00(this,DAT_0049f994 + 1,(undefined4 *)&DAT_00480f28);
    }
    piVar6 = (int *)(uVar2 * 4 + *(int *)((int)this + 8));
    puVar5 = (undefined4 *)*piVar6;
    if (puVar5 != (undefined4 *)0x0) {
      puVar5[1] = puVar5[1] + -1;
      if (puVar5[1] != 0) {
        puVar5 = (undefined4 *)0x0;
      }
      if (puVar5 != (undefined4 *)0x0) {
        (**(code **)*puVar5)(1);
      }
    }
    puVar3[1] = puVar3[1] + 1;
    *piVar6 = (int)puVar3;
    iVar4 = *(int *)(uVar1 * 4 + *(int *)(*param_1 + 8));
  }
  return iVar4;
}


