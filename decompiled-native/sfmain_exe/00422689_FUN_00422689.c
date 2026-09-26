// 00422689 FUN_00422689 [Global]
// programa: sfmain.exe

void FUN_00422689(void)

{
  LPCVOID in_EAX;
  HGLOBAL pvVar1;
  
  if (*(int *)((int)in_EAX + 0x14) != 0) {
    pvVar1 = GlobalHandle(*(LPCVOID *)((int)in_EAX + 0x14));
    GlobalUnlock(pvVar1);
    pvVar1 = GlobalHandle(*(LPCVOID *)((int)in_EAX + 0x14));
    GlobalFree(pvVar1);
  }
  if (*(int *)((int)in_EAX + 0x18) != 0) {
    pvVar1 = GlobalHandle(*(LPCVOID *)((int)in_EAX + 0x18));
    GlobalUnlock(pvVar1);
    pvVar1 = GlobalHandle(*(LPCVOID *)((int)in_EAX + 0x18));
    GlobalFree(pvVar1);
  }
  if (*(int *)((int)in_EAX + 0x1c) != 0) {
    pvVar1 = GlobalHandle(*(LPCVOID *)((int)in_EAX + 0x1c));
    GlobalUnlock(pvVar1);
    pvVar1 = GlobalHandle(*(LPCVOID *)((int)in_EAX + 0x1c));
    GlobalFree(pvVar1);
  }
  if (*(int *)((int)in_EAX + 0x20) != 0) {
    pvVar1 = GlobalHandle(*(LPCVOID *)((int)in_EAX + 0x20));
    GlobalUnlock(pvVar1);
    pvVar1 = GlobalHandle(*(LPCVOID *)((int)in_EAX + 0x20));
    GlobalFree(pvVar1);
  }
  if (*(int *)((int)in_EAX + 0x24) != 0) {
    pvVar1 = GlobalHandle(*(LPCVOID *)((int)in_EAX + 0x24));
    GlobalUnlock(pvVar1);
    pvVar1 = GlobalHandle(*(LPCVOID *)((int)in_EAX + 0x24));
    GlobalFree(pvVar1);
  }
  if (*(int *)((int)in_EAX + 0x28) != 0) {
    pvVar1 = GlobalHandle(*(LPCVOID *)((int)in_EAX + 0x28));
    GlobalUnlock(pvVar1);
    pvVar1 = GlobalHandle(*(LPCVOID *)((int)in_EAX + 0x28));
    GlobalFree(pvVar1);
  }
  pvVar1 = GlobalHandle(in_EAX);
  GlobalUnlock(pvVar1);
  pvVar1 = GlobalHandle(in_EAX);
  GlobalFree(pvVar1);
  return;
}


