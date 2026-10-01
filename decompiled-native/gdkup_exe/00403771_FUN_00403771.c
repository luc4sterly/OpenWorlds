// 00403771 FUN_00403771 [Global]
// program: gdkup.exe

void __fastcall FUN_00403771(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  (*DAT_00408b7c)(param_2,param_1);
  FUN_00404dd4(extraout_ECX,extraout_EDX);
  if (DAT_0040b438 == 0) {
    FUN_00405225();
  }
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}


