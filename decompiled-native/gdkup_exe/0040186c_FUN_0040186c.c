// 0040186c FUN_0040186c [Global]
// program: gdkup.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_0040186c(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_004017d0(param_1,param_2);
  puVar1 = (undefined4 *)uVar2;
  puVar1[1] = 1;
  *puVar1 = &PTR_FUN_00408938;
  _DAT_0040b014 = _DAT_0040b014 + 1;
  return CONCAT44(param_2,puVar1);
}


