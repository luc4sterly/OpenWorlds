// 00431852 FUN_00431852 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00431852(undefined4 param_1,undefined4 param_2)

{
  int extraout_EDX;
  
  (*(code *)PTR_FUN_0043e820)(param_2);
  if ((0 < extraout_EDX) && (extraout_EDX < _DAT_004e57c4)) {
    *(undefined4 *)(_DAT_004e57c8 + extraout_EDX * 4) = 0;
  }
  (*(code *)PTR_FUN_0043e824)();
  return;
}


