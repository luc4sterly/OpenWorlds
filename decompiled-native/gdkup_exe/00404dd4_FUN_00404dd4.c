// 00404dd4 FUN_00404dd4 [Global]
// program: gdkup.exe

void __fastcall FUN_00404dd4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *unaff_FS_OFFSET;
  
  iVar1 = (*(code *)PTR_FUN_00408b38)(param_2);
  if (*(undefined4 **)(iVar1 + 0x54) != (undefined4 *)0x0) {
    *unaff_FS_OFFSET = **(undefined4 **)(iVar1 + 0x54);
  }
  iVar1 = (*(code *)PTR_FUN_00408b38)();
  *(undefined4 *)(iVar1 + 0x54) = 0;
  iVar1 = FUN_0040478c();
  if (iVar1 != 0) {
    FUN_004047f7(extraout_ECX,extraout_EDX);
    iVar1 = (*(code *)PTR_FUN_00408b38)();
    *(undefined4 *)(iVar1 + 0x78) = 2;
    iVar1 = (*(code *)PTR_FUN_00408b38)();
    *(undefined4 *)(iVar1 + 0x90) = 2;
  }
  return;
}


