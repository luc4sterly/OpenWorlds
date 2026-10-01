// 00402803 FUN_00402803 [Global]
// program: gdkup.exe

void __fastcall FUN_00402803(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  
  (*(code *)PTR_FUN_00408a60)(param_2);
  (*(code *)PTR_FUN_00408a64)();
  uVar1 = extraout_ECX;
  uVar2 = extraout_EDX;
  if (DAT_00408bc0 != (code *)0x0) {
    (*DAT_00408bc0)();
    uVar1 = extraout_ECX_00;
    uVar2 = extraout_EDX_00;
  }
  FUN_0040353b(uVar1,uVar2);
  return;
}


