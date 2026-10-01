// 00404d96 FUN_00404d96 [Global]
// program: gdkup.exe

void __fastcall FUN_00404d96(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_FS_OFFSET;
  undefined8 uVar2;
  
  uVar2 = (*(code *)PTR_FUN_00408b38)(param_2);
  *(int *)((int)uVar2 + 0x54) = (int)((ulonglong)uVar2 >> 0x20);
  uVar2 = (*(code *)PTR_FUN_00408b38)();
  **(undefined4 **)((int)uVar2 + 0x54) = (int)((ulonglong)uVar2 >> 0x20);
  iVar1 = (*(code *)PTR_FUN_00408b38)();
  *(undefined **)(*(int *)(iVar1 + 0x54) + 4) = &DAT_004049e3;
  uVar2 = (*(code *)PTR_FUN_00408b38)();
  *(undefined4 *)(unaff_FS_OFFSET + (int)((ulonglong)uVar2 >> 0x20)) =
       *(undefined4 *)((int)uVar2 + 0x54);
  return;
}


