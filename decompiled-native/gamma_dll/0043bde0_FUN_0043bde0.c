// 0043bde0 FUN_0043bde0 [Global]
// program: gamma.dll

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffdc : 0x0043be1d */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 * __cdecl FUN_0043bde0(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  int local_30 [2];
  undefined **local_28;
  undefined4 *local_24;
  undefined **local_20;
  undefined4 *local_1c;
  undefined ***local_18;
  undefined ***local_14;
  
  FUN_0043c230(local_30,param_4);
  local_18 = &local_28;
  local_28 = &PTR_LAB_00475438;
  local_24 = *(undefined4 **)(param_2 + 4);
  if (local_24 != (undefined4 *)0x0) {
    FUN_0042f330((int)local_24);
  }
  local_14 = &local_20;
  local_20 = &PTR_LAB_00475438;
  local_1c = *(undefined4 **)(param_3 + 4);
  if (local_1c != (undefined4 *)0x0) {
    FUN_0042f330((int)local_1c);
  }
  FUN_0043bf80(param_1,(int)&local_28,(int)&local_20,local_30);
  local_20 = &PTR_LAB_00475438;
  if (local_1c != (undefined4 *)0x0) {
    FUN_0042f340(local_1c);
  }
  FUN_0042f320(&local_20);
  local_28 = &PTR_LAB_00475438;
  if (local_24 != (undefined4 *)0x0) {
    FUN_0042f340(local_24);
  }
  FUN_0042f320(&local_28);
  return param_1;
}


