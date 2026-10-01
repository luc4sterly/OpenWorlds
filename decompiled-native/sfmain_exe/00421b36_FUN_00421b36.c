// 00421b36 FUN_00421b36 [Global]
// program: sfmain.exe

void FUN_00421b36(void)

{
  LPCVOID pMem;
  int in_EAX;
  HGLOBAL pvVar1;
  
  while (*(int *)(in_EAX + 0x4e44) != 0) {
    pMem = *(LPCVOID *)(in_EAX + 0x4e44);
    *(undefined4 *)(in_EAX + 0x4e44) = **(undefined4 **)(in_EAX + 0x4e44);
    pvVar1 = GlobalHandle(pMem);
    GlobalUnlock(pvVar1);
    pvVar1 = GlobalHandle(pMem);
    GlobalFree(pvVar1);
  }
  *(undefined4 *)(in_EAX + 0x4e48) = 0;
  *(undefined4 *)(in_EAX + 0x4e44) = *(undefined4 *)(in_EAX + 0x4e48);
  *(byte *)(in_EAX + 0x4e42) = *(byte *)(in_EAX + 0x4e42) & 0xfd;
  return;
}


