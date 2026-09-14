// 00439ed0 FUN_00439ed0 [Global]
// programa: gamma.dll

/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffff0 : 0x00439f01 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 * __thiscall FUN_00439ed0(void *this,int param_1)

{
  undefined **local_14;
  undefined4 *local_10;
  undefined ***local_c;
  
  local_c = &local_14;
  local_14 = &PTR_LAB_00475468;
  local_10 = *(undefined4 **)(param_1 + 4);
  if (local_10 != (undefined4 *)0x0) {
    FUN_0042f330((int)local_10);
  }
  FUN_00439db0(this,(int)&local_14);
  local_14 = &PTR_LAB_00475468;
  if (local_10 != (undefined4 *)0x0) {
    FUN_0042f340(local_10);
  }
  FUN_0042f320(&local_14);
  *(undefined ***)this = &PTR_LAB_00476e48;
  return this;
}


