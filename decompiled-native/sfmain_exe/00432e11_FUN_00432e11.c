// 00432e11 FUN_00432e11 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_00432e11(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  HANDLE hConsoleHandle;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined8 uVar2;
  DWORD DStack_14;
  
  iVar1 = DAT_0043e85c;
  if (DAT_0043e85c == 0) {
    if (DAT_0043e8b4 == (code *)0x0) {
      (*(code *)PTR_FUN_0043e7f0)();
      hConsoleHandle = (HANDLE)FUN_0043257e(extraout_ECX,extraout_EDX);
      GetConsoleMode(hConsoleHandle,&DStack_14);
      SetConsoleMode(hConsoleHandle,0);
      uVar2 = FUN_00432d06(extraout_ECX_00,extraout_EDX_00);
      iVar1 = (int)uVar2;
      SetConsoleMode(hConsoleHandle,DStack_14);
      (*(code *)PTR_FUN_0043e7f4)();
    }
    else {
      (*DAT_0043e880)();
      iVar1 = (*DAT_0043e8b4)();
    }
  }
  else {
    DAT_0043e85c = 0;
  }
  return CONCAT44(param_2,iVar1);
}


