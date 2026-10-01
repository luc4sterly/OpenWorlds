// 004316a9 FUN_004316a9 [Global]
// program: sfmain.exe

void __fastcall FUN_004316a9(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *unaff_FS_OFFSET;
  
  iVar1 = (*(code *)PTR_FUN_0043e7ec)(param_2);
  if (*(undefined4 **)(iVar1 + 0x54) != (undefined4 *)0x0) {
    *unaff_FS_OFFSET = **(undefined4 **)(iVar1 + 0x54);
  }
  iVar1 = (*(code *)PTR_FUN_0043e7ec)();
  *(undefined4 *)(iVar1 + 0x54) = 0;
  iVar1 = FUN_00431061();
  if (iVar1 != 0) {
    FUN_004310cc(extraout_ECX,extraout_EDX);
    iVar1 = (*(code *)PTR_FUN_0043e7ec)();
    *(undefined4 *)(iVar1 + 0x78) = 2;
    iVar1 = (*(code *)PTR_FUN_0043e7ec)();
    *(undefined4 *)(iVar1 + 0x90) = 2;
  }
  return;
}


