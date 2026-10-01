// 004047f7 FUN_004047f7 [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_004047f7(undefined4 param_1,undefined4 param_2)

{
  BOOL BVar1;
  
  if (DAT_00408e50 != '\0') {
    BVar1 = SetConsoleCtrlHandler((PHANDLER_ROUTINE)&DAT_00404733,0);
    if (BVar1 != 0) {
      DAT_00408e50 = '\0';
    }
  }
  return CONCAT44(param_2,(uint)(DAT_00408e50 == '\0'));
}


