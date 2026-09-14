// 00439c60 FUN_00439c60 [Global]
// programa: gamma.dll

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffe4 : 0x00439c98 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 * __thiscall FUN_00439c60(void *this,undefined4 *param_1)

{
  undefined **local_20;
  undefined4 *local_1c;
  undefined ***local_18;
  undefined4 *local_14;
  
  local_18 = &local_20;
  local_20 = &PTR_LAB_00475468;
  local_1c = *(undefined4 **)((int)this + 0xc);
  if (local_1c != (undefined4 *)0x0) {
    FUN_0042f330((int)local_1c);
  }
  FUN_00434390((void *)((int)this + 8),0);
  local_14 = param_1;
  *param_1 = &PTR_LAB_00474bac;
  *param_1 = &PTR_LAB_00475468;
  param_1[1] = local_1c;
  if (param_1[1] != 0) {
    FUN_0042f330(param_1[1]);
  }
  local_20 = &PTR_LAB_00475468;
  if (local_1c != (undefined4 *)0x0) {
    FUN_0042f340(local_1c);
  }
  FUN_0042f320(&local_20);
  return param_1;
}


