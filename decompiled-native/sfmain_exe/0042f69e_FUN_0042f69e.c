// 0042f69e FUN_0042f69e [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_0042f69e(undefined4 param_1,undefined4 param_2)

{
  HANDLE hObject;
  int in_EAX;
  int iVar1;
  BOOL BVar2;
  int iVar3;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 uVar4;
  
  iVar3 = 0;
  hObject = *(HANDLE *)(_DAT_004e57c8 + in_EAX * 4);
  uVar4 = 0;
  if (DAT_0043e88c != (code *)0x0) {
    iVar1 = (*DAT_0043e880)();
    iVar3 = extraout_ECX;
    if (iVar1 != 0) {
      (*DAT_0043e884)();
      (*DAT_0043e88c)();
      iVar3 = extraout_ECX_00;
    }
  }
  if (iVar3 == 0) {
    BVar2 = CloseHandle(hObject);
    iVar3 = extraout_ECX_01;
    if (BVar2 == 0) {
      uVar4 = 0xffffffff;
      FUN_0042d8ad(extraout_ECX_01,extraout_EDX);
      goto LAB_0042f705;
    }
  }
  FUN_004321b2(iVar3,0);
LAB_0042f705:
  return CONCAT44(param_2,uVar4);
}


