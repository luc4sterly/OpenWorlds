// 004316f8 FUN_004316f8 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_004316f8(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (_DAT_004e57c4 < DAT_0043ea6c) {
LAB_0043170e:
    uVar1 = 0;
  }
  else {
    for (iVar2 = 0; iVar2 < (int)(_DAT_004e57c4 * 4); iVar2 = iVar2 + 4) {
      if (*(int *)(_DAT_004e57c8 + iVar2) == 0) goto LAB_0043170e;
    }
    uVar1 = 1;
  }
  return CONCAT44(param_2,uVar1);
}


