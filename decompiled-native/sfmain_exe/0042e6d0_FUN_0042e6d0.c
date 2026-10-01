// 0042e6d0 FUN_0042e6d0 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042e6d0(void)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)&DAT_004e57b8;
  do {
    puVar2 = puVar1;
    puVar1 = (undefined4 *)*puVar2;
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
  } while (in_EAX != puVar1[1]);
  *(byte *)(in_EAX + 0xc) = *(byte *)(puVar1[1] + 0xc) | 3;
  *puVar2 = *puVar1;
  *puVar1 = _DAT_004e57a8;
  _DAT_004e57a8 = puVar1;
  return;
}


