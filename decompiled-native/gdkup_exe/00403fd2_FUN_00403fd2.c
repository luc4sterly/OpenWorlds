// 00403fd2 FUN_00403fd2 [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_00403fd2(undefined4 param_1,undefined4 param_2)

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
  hObject = *(HANDLE *)(DAT_0040b478 + in_EAX * 4);
  uVar4 = 0;
  if (DAT_00408b8c != (code *)0x0) {
    iVar1 = (*DAT_00408b80)();
    iVar3 = extraout_ECX;
    if (iVar1 != 0) {
      (*DAT_00408b84)();
      (*DAT_00408b8c)();
      iVar3 = extraout_ECX_00;
    }
  }
  if (iVar3 == 0) {
    BVar2 = CloseHandle(hObject);
    iVar3 = extraout_ECX_01;
    if (BVar2 == 0) {
      uVar4 = 0xffffffff;
      FUN_00403848(extraout_ECX_01,extraout_EDX);
      goto LAB_00404039;
    }
  }
  FUN_004056ae(iVar3,0);
LAB_00404039:
  return CONCAT44(param_2,uVar4);
}


