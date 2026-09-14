// 0043ad60 FUN_0043ad60 [Global]
// programa: gamma.dll

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffdc : 0x0043ad97 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 * __thiscall FUN_0043ad60(void *this,int param_1,int param_2,undefined4 *param_3)

{
  undefined **local_28;
  undefined4 *local_24;
  undefined **local_20;
  undefined4 *local_1c;
  undefined ***local_18;
  undefined ***local_14;
  
  local_18 = &local_28;
  local_28 = &PTR_LAB_00475468;
  local_24 = *(undefined4 **)(param_1 + 4);
  if (local_24 != (undefined4 *)0x0) {
    FUN_0042f330((int)local_24);
  }
  local_14 = &local_20;
  local_20 = &PTR_LAB_00475468;
  local_1c = *(undefined4 **)(param_2 + 4);
  if (local_1c != (undefined4 *)0x0) {
    FUN_0042f330((int)local_1c);
  }
  FUN_0043a150(this,(int)&local_28,(int)&local_20);
  local_20 = &PTR_LAB_00475468;
  if (local_1c != (undefined4 *)0x0) {
    FUN_0042f340(local_1c);
  }
  FUN_0042f320(&local_20);
  local_28 = &PTR_LAB_00475468;
  if (local_24 != (undefined4 *)0x0) {
    FUN_0042f340(local_24);
  }
  FUN_0042f320(&local_28);
  *(undefined ***)this = &PTR_LAB_00476df8;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = *param_3;
  *(undefined4 *)((int)this + 0x24) = param_3[1];
  return this;
}


