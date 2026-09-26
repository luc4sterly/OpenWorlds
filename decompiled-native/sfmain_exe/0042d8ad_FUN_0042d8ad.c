// 0042d8ad FUN_0042d8ad [Global]
// programa: sfmain.exe

void __fastcall FUN_0042d8ad(undefined4 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = (*(code *)PTR_FUN_0043e7ec)(param_2);
  *(int *)((int)uVar1 + 4) = (int)((ulonglong)uVar1 >> 0x20);
  return;
}


