// 0042260d FUN_0042260d [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_0042260d(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  HGLOBAL hMem;
  LPVOID pvVar3;
  undefined4 extraout_ECX;
  
  iVar1 = *in_EAX;
  iVar2 = (int)*(char *)(iVar1 + 1);
  hMem = GlobalAlloc(0x40,iVar2 + 1);
  pvVar3 = GlobalLock(hMem);
  if (pvVar3 != (LPVOID)0x0) {
    FUN_004080a4(extraout_ECX,(undefined1 *)(iVar1 + 2));
    *(undefined1 *)((int)pvVar3 + iVar2) = 0;
  }
  *in_EAX = iVar1 + iVar2 + 2;
  return CONCAT44(param_2,pvVar3);
}


