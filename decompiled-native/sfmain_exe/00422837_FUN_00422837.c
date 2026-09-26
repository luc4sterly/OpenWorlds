// 00422837 FUN_00422837 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_00422837(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  undefined4 local_24;
  undefined4 local_20;
  
  local_20 = _DAT_004b2bf8;
  local_24 = in_EAX;
  while ((local_20 != (undefined4 *)0x0 && (0 < local_24))) {
    local_20 = (undefined4 *)*local_20;
    local_24 = local_24 + -1;
  }
  return CONCAT44(param_2,local_20);
}


