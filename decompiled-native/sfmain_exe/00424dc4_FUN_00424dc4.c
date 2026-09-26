// 00424dc4 FUN_00424dc4 [Global]
// programa: sfmain.exe

void FUN_00424dc4(void)

{
  int in_EAX;
  HGLOBAL pvVar1;
  
  if (*(int *)(in_EAX + 0x644) != 0) {
    mmioClose(*(HMMIO *)(in_EAX + 0x644),0);
    *(undefined4 *)(in_EAX + 0x644) = 0;
  }
  if (*(int *)(in_EAX + 0x648) != 0) {
    pvVar1 = GlobalHandle(*(LPCVOID *)(in_EAX + 0x648));
    GlobalUnlock(pvVar1);
    pvVar1 = GlobalHandle(*(LPCVOID *)(in_EAX + 0x648));
    GlobalFree(pvVar1);
    *(undefined4 *)(in_EAX + 0x648) = 0;
  }
  return;
}


