// 00433817 FUN_00433817 [Global]
// program: sfmain.exe

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00433817(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  undefined4 extraout_ECX_02;
  uint extraout_EDX;
  undefined4 extraout_EDX_00;
  longlong lVar5;
  undefined4 uStackY_24;
  
  pcVar1 = (code *)*param_1;
  uVar2 = *(undefined4 *)param_1[5];
  if (_DAT_004e57ac == 0) {
    iVar3 = -(DAT_0043eac8 + 3U & 0xfffffffc);
    *(undefined4 *)(&stack0xffffffe0 + iVar3) = 0x433857;
    FUN_00408098(param_1,0);
    *(undefined4 *)(&stack0xffffffe0 + iVar3) = 0x43385e;
    lVar5 = FUN_00431aad(extraout_ECX,extraout_EDX);
    if ((int)lVar5 == 0) {
      *(undefined4 *)(&stack0xffffffe0 + iVar3) = uVar2;
      *(undefined4 *)((int)&uStackY_24 + iVar3) = 0x43386b;
      CloseHandle(*(HANDLE *)(&stack0xffffffe0 + iVar3));
      return;
    }
  }
  iVar3 = (*(code *)PTR_FUN_0043e7ec)();
  *(undefined4 *)(iVar3 + 0xde) = uVar2;
  iVar3 = 0;
  if (*(int *)(extraout_ECX_00 + 0xc) != 0) {
    iVar3 = ((uint)(&stack0x00000fe3 + -*(int *)(extraout_ECX_00 + 0xc)) >> 8 & 0xfffff0) << 8;
  }
  piVar4 = (int *)(*(code *)PTR_FUN_0043e7ec)();
  *piVar4 = iVar3;
  uStackY_24 = 0x4338a5;
  SetEvent(*(HANDLE *)(extraout_ECX_01 + 0x10));
  FUN_0043166b(extraout_ECX_02,extraout_EDX_00);
  (*(code *)PTR_FUN_0043e82c)();
  (*pcVar1)();
  FUN_004331da();
  return;
}


