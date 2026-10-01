// 004309d0 FUN_004309d0 [Global]
// program: gamma.dll

uint __thiscall FUN_004309d0(void *this,uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = *(int *)((int)this + 4) * 0x110 + *(int *)((int)this + 8);
  uVar1 = param_1;
  uVar2 = param_1;
  if ((int)(uVar4 - param_1) / 0x110 != 1) {
    while (uVar2 + 0x110 < uVar4) {
      FUN_0044d6d0((char *)(uVar1 + 4),(char *)(uVar2 + 0x114),0xff);
      *(undefined1 *)(uVar1 + 0x103) = 0;
      *(undefined4 *)(uVar1 + 0x104) = *(undefined4 *)(uVar2 + 0x214);
      if (*(undefined4 **)(uVar1 + 0x10c) != (undefined4 *)0x0) {
        FUN_0042f340(*(undefined4 **)(uVar1 + 0x10c));
      }
      *(undefined4 *)(uVar1 + 0x10c) = *(undefined4 *)(uVar2 + 0x21c);
      if (*(int *)(uVar1 + 0x10c) != 0) {
        FUN_0042f330(*(int *)(uVar1 + 0x10c));
      }
      uVar1 = uVar1 + 0x110;
      uVar2 = uVar2 + 0x110;
    }
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  puVar3 = (undefined4 *)(*(int *)((int)this + 4) * 0x110 + *(int *)((int)this + 8));
  puVar3[0x42] = &PTR_LAB_00475040;
  if ((undefined4 *)puVar3[0x43] != (undefined4 *)0x0) {
    FUN_0042f340((undefined4 *)puVar3[0x43]);
  }
  FUN_0042f320(puVar3 + 0x42);
  *puVar3 = &PTR_LAB_00471ff8;
  return param_1;
}


