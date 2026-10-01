// 00433997 FUN_00433997 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00433997(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  (*DAT_0043e830)(param_2,param_1);
  FUN_004316a9(extraout_ECX,extraout_EDX);
  if (_DAT_004e57ac == 0) {
    FUN_00431afa();
  }
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}


