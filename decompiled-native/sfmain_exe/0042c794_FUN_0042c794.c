// 0042c794 FUN_0042c794 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0042c794(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  undefined4 extraout_ECX;
  int extraout_EDX;
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  uVar3 = FUN_0042f45e(param_1,in_EAX);
  iVar2 = (int)uVar3;
  if (iVar2 != -1) {
    (*(code *)PTR_FUN_0043e7f0)();
    iVar1 = extraout_EDX;
    if (((*(byte *)(extraout_EDX + 0xc) & 0x80) != 0) &&
       ((*(byte *)(extraout_EDX + 0xd) & 0x10) != 0)) {
      uVar4 = FUN_0042c82b(extraout_ECX,extraout_EDX);
      iVar1 = (int)(uVar4 >> 0x20);
    }
    if (*(int *)(iVar1 + 4) != 0) {
      if ((*(byte *)(iVar1 + 0xd) & 0x10) == 0) {
        iVar2 = iVar2 - *(int *)(iVar1 + 4);
      }
      else {
        iVar2 = iVar2 + *(int *)(iVar1 + 4);
      }
    }
    (*(code *)PTR_FUN_0043e7f4)();
  }
  return CONCAT44(param_2,iVar2);
}


