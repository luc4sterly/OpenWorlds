// 00406190 FUN_00406190 [Global]
// programa: gamma.dll

int __cdecl FUN_00406190(int *param_1)

{
  void *this;
  uint uVar1;
  uint *this_00;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  
  if (DAT_0049f9a0 == 0) {
    DAT_0049fcf4 = DAT_0049fcf4 + 1;
    DAT_0049f9a0 = DAT_0049fcf4;
  }
  uVar1 = DAT_0049f9a0;
  if ((*(uint *)(*param_1 + 4) <= DAT_0049f9a0) ||
     (iVar6 = *(int *)(DAT_0049f9a0 * 4 + *(int *)(*param_1 + 8)), iVar6 == 0)) {
    this_00 = FUN_0044e010(8);
    if (this_00 != (uint *)0x0) {
      FUN_00451f00(this_00,0);
    }
    this = (void *)*param_1;
    uVar2 = FUN_00405ec0((int *)&DAT_0049f9a0);
    uVar3 = FUN_00405eb0((int)this);
    if (uVar3 <= uVar2) {
      FUN_00405e50(this,uVar2 + 1);
    }
    piVar4 = (int *)FUN_00405e30(this,uVar2);
    if (*piVar4 != 0) {
      puVar5 = (undefined4 *)FUN_00405e20(*piVar4);
      if (puVar5 != (undefined4 *)0x0) {
        (**(code **)*puVar5)(1);
      }
    }
    iVar6 = FUN_00405e10((int)this_00);
    *piVar4 = iVar6;
    iVar6 = *(int *)(uVar1 * 4 + *(int *)(*param_1 + 8));
  }
  return iVar6;
}


