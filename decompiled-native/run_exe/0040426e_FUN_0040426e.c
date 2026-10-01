// 0040426e FUN_0040426e [Global]
// program: run.exe

undefined4 * FUN_0040426e(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_0040ce54 == DAT_0040ce44) {
    pvVar2 = HeapReAlloc(DAT_0040ce60,0,DAT_0040ce58,(DAT_0040ce44 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_0040ce44 = DAT_0040ce44 + 0x10;
    DAT_0040ce58 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_0040ce58 + DAT_0040ce54 * 0x14);
  pvVar2 = HeapAlloc(DAT_0040ce60,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_0040ce54 = DAT_0040ce54 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_0040ce60,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}


