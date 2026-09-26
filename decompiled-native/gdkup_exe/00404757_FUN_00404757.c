// 00404757 FUN_00404757 [Global]
// programa: gdkup.exe

undefined4 __fastcall FUN_00404757(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_00404833(param_1,param_2);
  iVar1 = (int)((ulonglong)uVar2 >> 0x20);
  if ((iVar1 != 2) && (iVar1 != 3)) {
    return 1;
  }
  return 0;
}


