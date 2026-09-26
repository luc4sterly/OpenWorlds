// 0043166b FUN_0043166b [Global]
// programa: sfmain.exe

void __fastcall FUN_0043166b(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int unaff_FS_OFFSET;
  undefined8 uVar2;
  
  uVar2 = (*(code *)PTR_FUN_0043e7ec)(param_2);
  *(int *)((int)uVar2 + 0x54) = (int)((ulonglong)uVar2 >> 0x20);
  uVar2 = (*(code *)PTR_FUN_0043e7ec)();
  **(undefined4 **)((int)uVar2 + 0x54) = (int)((ulonglong)uVar2 >> 0x20);
  iVar1 = (*(code *)PTR_FUN_0043e7ec)();
  *(undefined **)(*(int *)(iVar1 + 0x54) + 4) = &DAT_004312b8;
  uVar2 = (*(code *)PTR_FUN_0043e7ec)();
  *(undefined4 *)(unaff_FS_OFFSET + (int)((ulonglong)uVar2 >> 0x20)) =
       *(undefined4 *)((int)uVar2 + 0x54);
  return;
}


