// 00406aa0 FUN_00406aa0 [Global]
// program: gdkup.exe

void __fastcall FUN_00406aa0(undefined4 param_1,undefined4 param_2)

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
  if (DAT_00408bbc == (code *)0x0) {
    (*(code *)PTR_FUN_00408b3c)();
    hConsoleOutput = (HANDLE)FUN_00406772(extraout_ECX,extraout_EDX);
    WriteConsoleA(hConsoleOutput,local_10,1,&DStack_14,lpReserved);
    (*(code *)PTR_FUN_00408b40)();
  }
  else {
    (*DAT_00408b80)();
    (*DAT_00408bbc)();
  }
  return;
}


