// 0040478c FUN_0040478c [Global]
// program: gdkup.exe

undefined4 FUN_0040478c(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_00408b38)();
  if ((*(int *)(iVar1 + 0x78) != 2) &&
     (iVar1 = (*(code *)PTR_FUN_00408b38)(), *(int *)(iVar1 + 0x78) != 3)) {
    return 1;
  }
  iVar1 = (*(code *)PTR_FUN_00408b38)();
  if ((*(int *)(iVar1 + 0x90) != 2) &&
     (iVar1 = (*(code *)PTR_FUN_00408b38)(), *(int *)(iVar1 + 0x90) != 3)) {
    return 1;
  }
  return 0;
}


