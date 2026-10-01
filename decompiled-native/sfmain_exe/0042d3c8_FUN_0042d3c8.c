// 0042d3c8 FUN_0042d3c8 [Global]
// program: sfmain.exe

void __fastcall FUN_0042d3c8(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  int unaff_FS_OFFSET;
  
  GetModuleHandleA((LPCSTR)0x0);
  FUN_0042d2a1(extraout_ECX,param_2);
  FUN_0043166b(extraout_ECX_00,extraout_EDX);
  (*(code *)PTR_FUN_0043e82c)();
  uVar1 = *(undefined4 *)(unaff_FS_OFFSET + 8);
  puVar2 = (undefined4 *)(*(code *)PTR_FUN_0043e7ec)();
  *puVar2 = uVar1;
  FUN_00431cf6();
  return;
}


