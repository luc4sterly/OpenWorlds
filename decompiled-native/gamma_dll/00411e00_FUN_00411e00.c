// 00411e00 FUN_00411e00 [Global]
// program: gamma.dll

int __cdecl FUN_00411e00(int *param_1)

{
  void *this;
  uint uVar1;
  uint uVar2;
  uint *this_00;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  if (DAT_0049f99c == 0) {
    DAT_0049fcf4 = DAT_0049fcf4 + 1;
    DAT_0049f99c = DAT_0049fcf4;
  }
  uVar1 = DAT_0049f99c;
  if ((*(uint *)(*param_1 + 4) <= DAT_0049f99c) ||
     (iVar3 = *(int *)(DAT_0049f99c * 4 + *(int *)(*param_1 + 8)), iVar3 == 0)) {
    this_00 = FUN_0044e010(8);
    if (this_00 != (uint *)0x0) {
      FUN_00451f60(this_00,0);
    }
    this = (void *)*param_1;
    if (DAT_0049f99c == 0) {
      DAT_0049fcf4 = DAT_0049fcf4 + 1;
      DAT_0049f99c = DAT_0049fcf4;
    }
    uVar2 = DAT_0049f99c;
    if (*(uint *)((int)this + 4) <= DAT_0049f99c) {
      FUN_00404e00(this,DAT_0049f99c + 1,(undefined4 *)&DAT_0046f324);
    }
    piVar5 = (int *)(uVar2 * 4 + *(int *)((int)this + 8));
    puVar4 = (undefined4 *)*piVar5;
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[1] = puVar4[1] + -1;
      if (puVar4[1] != 0) {
        puVar4 = (undefined4 *)0x0;
      }
      if (puVar4 != (undefined4 *)0x0) {
        (**(code **)*puVar4)(1);
      }
    }
    this_00[1] = this_00[1] + 1;
    *piVar5 = (int)this_00;
    iVar3 = *(int *)(uVar1 * 4 + *(int *)(*param_1 + 8));
  }
  return iVar3;
}


