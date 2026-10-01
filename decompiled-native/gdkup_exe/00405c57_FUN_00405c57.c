// 00405c57 FUN_00405c57 [Global]
// program: gdkup.exe

void FUN_00405c57(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  
  iVar1 = (*(code *)PTR_FUN_00408b38)();
  *(char **)(iVar1 + DAT_0040b440 + 0xc) = s_stack_data_has_been_corrupted__004085bc;
  FUN_00405c40(extraout_ECX);
  return;
}


