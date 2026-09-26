// 00406a2a FUN_00406a2a [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_00406a2a(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  HANDLE hConsoleHandle;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined8 uVar2;
  DWORD DStack_14;
  
  iVar1 = DAT_00408e8c;
  if (DAT_00408e8c == 0) {
    if (DAT_00408bb4 == (code *)0x0) {
      (*(code *)PTR_FUN_00408b3c)();
      hConsoleHandle = (HANDLE)FUN_00406767(extraout_ECX,extraout_EDX);
      GetConsoleMode(hConsoleHandle,&DStack_14);
      SetConsoleMode(hConsoleHandle,0);
      uVar2 = FUN_0040691f(extraout_ECX_00,extraout_EDX_00);
      iVar1 = (int)uVar2;
      SetConsoleMode(hConsoleHandle,DStack_14);
      (*(code *)PTR_FUN_00408b40)();
    }
    else {
      (*DAT_00408b80)();
      iVar1 = (*DAT_00408bb4)();
    }
  }
  else {
    DAT_00408e8c = 0;
  }
  return CONCAT44(param_2,iVar1);
}


