// 0043102c FUN_0043102c [Global]
// programa: sfmain.exe

undefined4 __fastcall FUN_0043102c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_00431108(param_1,param_2);
  iVar1 = (int)((ulonglong)uVar2 >> 0x20);
  if ((iVar1 != 2) && (iVar1 != 3)) {
    return 1;
  }
  return 0;
}


