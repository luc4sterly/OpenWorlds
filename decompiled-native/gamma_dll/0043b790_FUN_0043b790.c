// 0043b790 FUN_0043b790 [Global]
// program: gamma.dll

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffe4 : 0x0043b7c9 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 * __cdecl FUN_0043b790(undefined4 *param_1,int param_2,undefined4 param_3)

{
  uint *this;
  undefined **local_20;
  undefined4 *local_1c;
  undefined ***local_18;
  undefined4 *local_14;
  
  local_18 = &local_20;
  local_20 = &PTR_LAB_00475040;
  local_1c = *(undefined4 **)(param_2 + 4);
  if (local_1c != (undefined4 *)0x0) {
    FUN_0042f330((int)local_1c);
  }
  this = FUN_0044e010(0x20);
  if (this != (uint *)0x0) {
    FUN_0043b840(this,(int)&local_20,param_3);
  }
  local_14 = param_1;
  *param_1 = &PTR_LAB_00474bac;
  *param_1 = &PTR_LAB_00475fac;
  param_1[1] = this;
  if (param_1[1] != 0) {
    FUN_0042f330(param_1[1]);
  }
  local_20 = &PTR_LAB_00475040;
  if (local_1c != (undefined4 *)0x0) {
    FUN_0042f340(local_1c);
  }
  FUN_0042f320(&local_20);
  return param_1;
}


