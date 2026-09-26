// 00432e87 FUN_00432e87 [Global]
// programa: sfmain.exe

void __fastcall FUN_00432e87(undefined4 param_1,undefined4 param_2)

{
  HANDLE hConsoleOutput;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  LPVOID lpReserved;
  DWORD DStack_14;
  undefined1 local_10 [4];
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = param_2;
  uStack_8 = param_1;
  if (DAT_0043e8bc == (code *)0x0) {
    (*(code *)PTR_FUN_0043e7f0)();
    hConsoleOutput = (HANDLE)FUN_00432589(extraout_ECX,extraout_EDX);
    WriteConsoleA(hConsoleOutput,local_10,1,&DStack_14,lpReserved);
    (*(code *)PTR_FUN_0043e7f4)();
  }
  else {
    (*DAT_0043e880)();
    (*DAT_0043e8bc)();
  }
  return;
}


