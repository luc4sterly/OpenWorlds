// 00403848 FUN_00403848 [Global]
// programa: gdkup.exe

void __fastcall FUN_00403848(undefined4 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = (*(code *)PTR_FUN_00408b38)(param_2);
  *(int *)((int)uVar1 + 4) = (int)((ulonglong)uVar1 >> 0x20);
  return;
}


