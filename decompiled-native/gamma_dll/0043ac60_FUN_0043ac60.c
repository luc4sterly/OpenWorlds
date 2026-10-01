// 0043ac60 FUN_0043ac60 [Global]
// program: gamma.dll

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffd0 : 0x0043ac94 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 * __cdecl FUN_0043ac60(undefined4 *param_1,int param_2,int param_3,undefined4 *param_4)

{
  uint *this;
  undefined **local_34;
  undefined4 *local_30;
  undefined **local_2c;
  undefined4 *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined ***local_1c;
  undefined ***local_18;
  undefined4 *local_14;
  
  local_1c = &local_34;
  local_34 = &PTR_LAB_00475468;
  local_30 = *(undefined4 **)(param_2 + 4);
  if (local_30 != (undefined4 *)0x0) {
    FUN_0042f330((int)local_30);
  }
  local_18 = &local_2c;
  local_2c = &PTR_LAB_00475468;
  local_28 = *(undefined4 **)(param_3 + 4);
  if (local_28 != (undefined4 *)0x0) {
    FUN_0042f330((int)local_28);
  }
  local_24 = *param_4;
  local_20 = param_4[1];
  this = FUN_0044e010(0x28);
  if (this != (uint *)0x0) {
    FUN_0043ad60(this,(int)&local_34,(int)&local_2c,&local_24);
  }
  local_14 = param_1;
  *param_1 = &PTR_LAB_00474bac;
  *param_1 = &PTR_LAB_00475468;
  param_1[1] = this;
  if (param_1[1] != 0) {
    FUN_0042f330(param_1[1]);
  }
  local_2c = &PTR_LAB_00475468;
  if (local_28 != (undefined4 *)0x0) {
    FUN_0042f340(local_28);
  }
  FUN_0042f320(&local_2c);
  local_34 = &PTR_LAB_00475468;
  if (local_30 != (undefined4 *)0x0) {
    FUN_0042f340(local_30);
  }
  FUN_0042f320(&local_34);
  return param_1;
}


