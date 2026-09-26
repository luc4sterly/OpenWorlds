// 0042bd96 FUN_0042bd96 [Global]
// programa: sfmain.exe

void __fastcall FUN_0042bd96(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  
  (*(code *)PTR_FUN_0043e750)(param_2);
  (*(code *)PTR_FUN_0043e754)();
  uVar1 = extraout_ECX;
  uVar2 = extraout_EDX;
  if (DAT_0043e8c0 != (code *)0x0) {
    (*DAT_0043e8c0)();
    uVar1 = extraout_ECX_00;
    uVar2 = extraout_EDX_00;
  }
  FUN_0042d40e(uVar1,uVar2);
  return;
}


