// 00431061 FUN_00431061 [Global]
// program: sfmain.exe

undefined4 FUN_00431061(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_0043e7ec)();
  if ((*(int *)(iVar1 + 0x78) != 2) &&
     (iVar1 = (*(code *)PTR_FUN_0043e7ec)(), *(int *)(iVar1 + 0x78) != 3)) {
    return 1;
  }
  iVar1 = (*(code *)PTR_FUN_0043e7ec)();
  if ((*(int *)(iVar1 + 0x90) != 2) &&
     (iVar1 = (*(code *)PTR_FUN_0043e7ec)(), *(int *)(iVar1 + 0x90) != 3)) {
    return 1;
  }
  return 0;
}


