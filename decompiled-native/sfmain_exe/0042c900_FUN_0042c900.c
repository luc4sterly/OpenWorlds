// 0042c900 FUN_0042c900 [Global]
// programa: sfmain.exe

uint __fastcall FUN_0042c900(undefined4 param_1,int param_2)

{
  int in_EAX;
  uint uVar1;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  int iVar2;
  undefined4 extraout_ECX_04;
  undefined4 extraout_EDX;
  undefined4 uVar3;
  undefined4 extraout_EDX_00;
  uint extraout_EDX_01;
  undefined8 uVar4;
  
  if (*(int *)(in_EAX + 0xc) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    if ((*(byte *)(in_EAX + 0xd) & 0x10) != 0) {
      uVar4 = FUN_0042d957(in_EAX,param_2);
      uVar1 = (uint)uVar4;
    }
    (*(code *)PTR_FUN_0043e7f0)();
    uVar4 = FUN_0042c794(extraout_ECX,extraout_EDX);
    uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
    iVar2 = extraout_ECX_00;
    if ((int)uVar4 != -1) {
      FUN_0042f424();
      iVar2 = extraout_ECX_01;
      uVar3 = extraout_EDX_00;
    }
    if (param_2 != 0) {
      uVar4 = FUN_0042f69e(iVar2,uVar3);
      uVar1 = uVar1 | (uint)uVar4;
      iVar2 = extraout_ECX_02;
    }
    if ((*(byte *)(iVar2 + 0xc) & 8) != 0) {
      FUN_0042b9b8();
      *(undefined4 *)(extraout_ECX_03 + 8) = 0;
      iVar2 = extraout_ECX_03;
    }
    if ((*(byte *)(iVar2 + 0xd) & 8) != 0) {
      FUN_0042c89b();
      thunk_FUN_0042cb9a(extraout_ECX_04,extraout_EDX_01);
    }
    (*(code *)PTR_FUN_0043e7f4)();
    (*(code *)PTR_thunk_FUN_00431852_0043e7fc)();
  }
  return uVar1;
}


