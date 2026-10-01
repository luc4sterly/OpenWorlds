// 00404f7d FUN_00404f7d [Global]
// program: gdkup.exe

void __fastcall FUN_00404f7d(undefined4 param_1,undefined4 param_2)

{
  int extraout_EDX;
  
  (*(code *)PTR_FUN_00408b6c)(param_2);
  if ((0 < extraout_EDX) && (extraout_EDX < DAT_0040b474)) {
    *(undefined4 *)(DAT_0040b478 + extraout_EDX * 4) = 0;
  }
  (*(code *)PTR_FUN_00408b70)();
  return;
}


