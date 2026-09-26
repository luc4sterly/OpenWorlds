// 0040353b FUN_0040353b [Global]
// programa: gdkup.exe

void __fastcall FUN_0040353b(undefined4 param_1,undefined4 param_2)

{
  UINT in_EAX;
  undefined4 extraout_ECX;
  
  FUN_00404dd4(param_1,param_2);
  FUN_004054b1(extraout_ECX,0xff);
  (*(code *)PTR_FUN_00408b74)();
                    /* WARNING: Subroutine does not return */
  ExitProcess(in_EAX);
}


