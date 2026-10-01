// 004310cc FUN_004310cc [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_004310cc(undefined4 param_1,undefined4 param_2)

{
  BOOL BVar1;
  
  if (DAT_0043ea3c != '\0') {
    BVar1 = SetConsoleCtrlHandler((PHANDLER_ROUTINE)&DAT_00431008,0);
    if (BVar1 != 0) {
      DAT_0043ea3c = '\0';
    }
  }
  return CONCAT44(param_2,(uint)(DAT_0043ea3c == '\0'));
}


