// 0043173d FUN_0043173d [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_0043173d(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  (*(code *)PTR_FUN_0043e820)();
  iVar2 = 0;
  iVar1 = 0;
  while( true ) {
    if (_DAT_004e57c4 * 4 <= iVar1) {
      _DAT_004e57c8 = FUN_00432594(_DAT_004e57c4 * 4,(_DAT_004e57c4 + 1) * 4);
      _DAT_004e57c8[_DAT_004e57c4] = in_EAX;
      _DAT_004e57c4 = _DAT_004e57c4 + 1;
      (*(code *)PTR_FUN_0043e824)();
      return CONCAT44(param_2,_DAT_004e57c4 + -1);
    }
    if (*(int *)((int)_DAT_004e57c8 + iVar1) == 0) break;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + 1;
  }
  *(int *)((int)_DAT_004e57c8 + iVar1) = in_EAX;
  (*(code *)PTR_FUN_0043e824)();
  return CONCAT44(param_2,iVar2);
}


