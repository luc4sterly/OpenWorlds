// 004339f0 FUN_004339f0 [Global]
// programa: gamma.dll

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffec : 0x00433a2f */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __thiscall FUN_004339f0(void *this,int param_1)

{
  void *this_00;
  undefined **local_18;
  undefined4 *local_14;
  undefined ***local_10;
  
  this_00 = *(void **)((int)this + 0xc);
  if (this_00 != (void *)0x0) {
    local_10 = &local_18;
    local_18 = &PTR_LAB_00475468;
    local_14 = *(undefined4 **)(param_1 + 4);
    if (local_14 != (undefined4 *)0x0) {
      FUN_0042f330((int)local_14);
    }
    FUN_00439c40(this_00,(int)&local_18);
    local_18 = &PTR_LAB_00475468;
    if (local_14 != (undefined4 *)0x0) {
      FUN_0042f340(local_14);
    }
    FUN_0042f320(&local_18);
  }
  return;
}


