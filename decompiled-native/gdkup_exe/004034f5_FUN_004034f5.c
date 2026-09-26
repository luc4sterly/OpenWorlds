// 004034f5 FUN_004034f5 [Global]
// programa: gdkup.exe

void __fastcall FUN_004034f5(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  int unaff_FS_OFFSET;
  
  GetModuleHandleA((LPCSTR)0x0);
  FUN_004033ce(extraout_ECX,param_2);
  FUN_00404d96(extraout_ECX_00,extraout_EDX);
  (*(code *)PTR_FUN_00408b78)();
  uVar1 = *(undefined4 *)(unaff_FS_OFFSET + 8);
  puVar2 = (undefined4 *)(*(code *)PTR_FUN_00408b38)();
  *puVar2 = uVar1;
  FUN_00405466();
  return;
}


