// 0042d40e FUN_0042d40e [Global]
// program: sfmain.exe

void __fastcall FUN_0042d40e(undefined4 param_1,undefined4 param_2)

{
  UINT in_EAX;
  undefined4 extraout_ECX;
  
  FUN_004316a9(param_1,param_2);
  FUN_00431d41(extraout_ECX,0xff);
  (*(code *)PTR_FUN_0043e828)();
                    /* WARNING: Subroutine does not return */
  ExitProcess(in_EAX);
}


