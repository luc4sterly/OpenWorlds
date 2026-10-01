// 00404710 FUN_00404710 [Global]
// program: run.exe

undefined ** FUN_00404710(void)

{
  bool bVar1;
  int *lpAddress;
  LPVOID pvVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined **lpMem;
  
  if (DAT_00409300 == -1) {
    lpMem = &PTR_LOOP_004092f0;
  }
  else {
    lpMem = HeapAlloc(DAT_0040ce60,0,0x2020);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (int *)0x0) {
    pvVar2 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar2 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_004092f0) {
        if (PTR_LOOP_004092f0 == (undefined *)0x0) {
          PTR_LOOP_004092f0 = (undefined *)&PTR_LOOP_004092f0;
        }
        if (PTR_LOOP_004092f4 == (undefined *)0x0) {
          PTR_LOOP_004092f4 = (undefined *)&PTR_LOOP_004092f0;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_004092f0;
        lpMem[1] = PTR_LOOP_004092f4;
        PTR_LOOP_004092f4 = (undefined *)lpMem;
        *(undefined ***)lpMem[1] = lpMem;
      }
      lpMem[5] = (undefined *)(lpAddress + 0x100000);
      ppuVar3 = lpMem + 6;
      lpMem[3] = (undefined *)(lpMem + 0x26);
      lpMem[4] = (undefined *)lpAddress;
      lpMem[2] = (undefined *)ppuVar3;
      iVar4 = 0;
      do {
        bVar1 = 0xf < iVar4;
        iVar4 = iVar4 + 1;
        *ppuVar3 = (undefined *)((bVar1 - 1 & 0xf1) - 1);
        ppuVar3[1] = (undefined *)0xf1;
        ppuVar3 = ppuVar3 + 2;
      } while (iVar4 < 0x400);
      _memset(lpAddress,0,0x10000);
      for (; lpAddress < lpMem[4] + 0x10000; lpAddress = lpAddress + 0x400) {
        *(undefined1 *)(lpAddress + 0x3e) = 0xff;
        *lpAddress = (int)(lpAddress + 2);
        lpAddress[1] = 0xf0;
      }
      return lpMem;
    }
    VirtualFree(lpAddress,0,0x8000);
  }
  if (lpMem != &PTR_LOOP_004092f0) {
    HeapFree(DAT_0040ce60,0,lpMem);
  }
  return (undefined **)0x0;
}


