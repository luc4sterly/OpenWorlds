// 00429b40 FUN_00429b40 [Global]
// programa: gamma.dll

void __thiscall FUN_00429b40(void *this,uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (*(uint *)this < param_1) {
    puVar1 = *(undefined4 **)((int)this + 8);
    puVar3 = FUN_0044e010(param_1 * 4);
    *(uint **)((int)this + 8) = puVar3;
    if (puVar1 != (undefined4 *)0x0) {
      iVar2 = *(int *)((int)this + 4);
      puVar5 = *(undefined4 **)((int)this + 8);
      for (puVar4 = puVar1; puVar4 < puVar1 + iVar2; puVar4 = puVar4 + 1) {
        *puVar5 = *puVar4;
        puVar5 = puVar5 + 1;
      }
      FUN_0044e100(puVar1);
    }
    *(uint *)this = param_1;
  }
  return;
}


