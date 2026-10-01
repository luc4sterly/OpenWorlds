// 00433420 FUN_00433420 [Global]
// program: gamma.dll

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffb8 : 0x00433468 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __fastcall FUN_00433420(int param_1)

{
  undefined **local_4c;
  undefined4 *local_48;
  undefined **local_44;
  undefined4 *local_40;
  undefined **local_3c;
  undefined4 *local_38;
  undefined **local_34;
  undefined4 *local_30;
  undefined **local_2c;
  undefined4 *local_28;
  undefined **local_24;
  undefined4 *local_20;
  undefined ***local_1c;
  undefined ***local_18;
  undefined ***local_14;
  
  *(undefined4 *)(param_1 + 0x34) = 1;
  *(undefined4 *)(param_1 + 0x38) = 0;
  FUN_004398c0(&local_44);
  local_1c = &local_4c;
  local_4c = &PTR_LAB_00475468;
  local_48 = local_40;
  if (local_40 != (undefined4 *)0x0) {
    FUN_0042f330((int)local_40);
  }
  local_44 = &PTR_LAB_0047545c;
  if (local_40 != (undefined4 *)0x0) {
    FUN_0042f340(local_40);
  }
  FUN_0042f320(&local_44);
  local_18 = &local_3c;
  local_3c = &PTR_LAB_00475468;
  local_38 = local_48;
  if (local_48 != (undefined4 *)0x0) {
    FUN_0042f330((int)local_48);
  }
  FUN_00439d00(&local_34,(int)&local_3c);
  FUN_00434390((void *)(param_1 + 8),local_30);
  local_34 = &PTR_LAB_00475450;
  if (local_30 != (undefined4 *)0x0) {
    FUN_0042f340(local_30);
  }
  FUN_0042f320(&local_34);
  local_3c = &PTR_LAB_00475468;
  if (local_38 != (undefined4 *)0x0) {
    FUN_0042f340(local_38);
  }
  FUN_0042f320(&local_3c);
  local_14 = &local_2c;
  local_2c = &PTR_LAB_00475468;
  local_28 = *(undefined4 **)(param_1 + 0xc);
  if (local_28 != (undefined4 *)0x0) {
    FUN_0042f330((int)local_28);
  }
  FUN_00439e20(&local_24,(int)&local_2c);
  FUN_00434390((void *)(param_1 + 0x10),local_20);
  local_24 = &PTR_LAB_00475444;
  if (local_20 != (undefined4 *)0x0) {
    FUN_0042f340(local_20);
  }
  FUN_0042f320(&local_24);
  local_2c = &PTR_LAB_00475468;
  if (local_28 != (undefined4 *)0x0) {
    FUN_0042f340(local_28);
  }
  FUN_0042f320(&local_2c);
  local_4c = &PTR_LAB_00475468;
  if (local_48 != (undefined4 *)0x0) {
    FUN_0042f340(local_48);
  }
  FUN_0042f320(&local_4c);
  return;
}


