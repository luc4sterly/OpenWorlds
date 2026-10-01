// 0040386d FUN_0040386d [Global]
// program: gdkup.exe

void __fastcall FUN_0040386d(undefined4 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = (*(code *)PTR_FUN_00408b38)(param_2);
  *(int *)((int)uVar1 + 8) = (int)((ulonglong)uVar1 >> 0x20);
  return;
}


