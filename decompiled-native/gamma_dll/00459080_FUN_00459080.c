// 00459080 FUN_00459080 [Global]
// programa: gamma.dll

undefined4 * __cdecl FUN_00459080(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = GlobalAlloc(0,param_1 + 8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (((uint)puVar1 & 7) == 0) {
    puVar1 = puVar1 + 1;
    *puVar1 = 0;
  }
  else {
    *puVar1 = 1;
  }
  return puVar1 + 1;
}


