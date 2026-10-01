// 10064a90 ___sbh_new_region [Global]
// program: rwdlmd21.dll

/* Library Function - Single Match
    ___sbh_new_region
   
   Library: Visual Studio 1998 Release */

undefined ** ___sbh_new_region(void)

{
  undefined4 *lpAddress;
  LPVOID pvVar1;
  int iVar2;
  int iVar3;
  undefined **lpMem;
  undefined4 *puVar4;
  
  if (DAT_10088728 == 0) {
    lpMem = &PTR_LOOP_10087f18;
  }
  else {
    lpMem = HeapAlloc(DAT_1008b454,0,0x814);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar1 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar1 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_10087f18) {
        if (PTR_LOOP_10087f18 == (undefined *)0x0) {
          PTR_LOOP_10087f18 = (undefined *)&PTR_LOOP_10087f18;
        }
        if (PTR_LOOP_10087f1c == (undefined *)0x0) {
          PTR_LOOP_10087f1c = (undefined *)&PTR_LOOP_10087f18;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_10087f18;
        lpMem[1] = PTR_LOOP_10087f1c;
        PTR_LOOP_10087f1c = (undefined *)lpMem;
        *(undefined ***)lpMem[1] = lpMem;
      }
      lpMem[0x204] = (undefined *)lpAddress;
      lpMem[2] = (undefined *)0x0;
      lpMem[3] = (undefined *)0x10;
      iVar2 = 0;
      do {
        if (iVar2 < 0x10) {
          *(undefined1 *)((int)lpMem + iVar2 + 0x10) = 0xf0;
        }
        else {
          *(undefined1 *)((int)lpMem + iVar2 + 0x10) = 0xff;
        }
        iVar3 = iVar2 + 1;
        *(undefined1 *)((int)lpMem + iVar2 + 0x410) = 0xf1;
        iVar2 = iVar3;
      } while (iVar3 < 0x400);
      puVar4 = lpAddress;
      for (iVar2 = 0x4000; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      if (lpAddress < lpMem[0x204] + 0x10000) {
        do {
          *lpAddress = lpAddress + 2;
          lpAddress[1] = 0xf0;
          *(undefined1 *)(lpAddress + 0x3e) = 0xff;
          lpAddress = lpAddress + 0x400;
        } while (lpAddress < lpMem[0x204] + 0x10000);
      }
      return lpMem;
    }
    VirtualFree(lpAddress,0,0x8000);
  }
  if (lpMem != &PTR_LOOP_10087f18) {
    HeapFree(DAT_1008b454,0,lpMem);
  }
  return (undefined **)0x0;
}


