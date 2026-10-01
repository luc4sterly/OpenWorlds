// 0042a9f0 FUN_0042a9f0 [Global]
// program: gamma.dll

undefined4 __thiscall FUN_0042a9f0(int param_1,undefined1 *param_2)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x20) + 4) + 0x32);
  if (((bVar1 & 2) != 0) || ((bVar1 & 5) != 0)) {
    return 0;
  }
  uVar2 = FUN_00427560(*(int *)(param_1 + 0x20));
  if (uVar2 != 0xffffffff) {
    *param_2 = (char)uVar2;
  }
  bVar1 = *(byte *)(*(int *)(*(int *)(param_1 + 0x20) + 4) + 0x32);
  if ((bVar1 & 2) == 0) {
    if ((bVar1 & 1) == 0) {
      return 1;
    }
    return 0xffffffff;
  }
  return 0;
}


