// 00432be0 FUN_00432be0 [Global]
// program: gamma.dll

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffe0 : 0x00432c3e */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

float10 __thiscall FUN_00432be0(int param_1,int *param_2,uint param_3,int param_4)

{
  ulonglong uVar1;
  undefined **local_24;
  undefined4 *local_20;
  undefined **local_1c;
  undefined4 *local_18;
  uint local_14;
  uint local_10;
  undefined ***local_c;
  
  if (*(char *)(param_1 + 5) == '\0') {
    return (float10)_DAT_00475300;
  }
  if (-1 < param_4) {
    FUN_00433f70(&local_1c,param_2,param_3,param_4);
    local_c = &local_24;
    local_24 = &PTR_LAB_0047545c;
    local_20 = local_18;
    if (local_18 != (undefined4 *)0x0) {
      FUN_0042f330((int)local_18);
    }
    local_1c = &PTR_LAB_0047545c;
    if (local_18 != (undefined4 *)0x0) {
      FUN_0042f340(local_18);
    }
    FUN_0042f320(&local_1c);
    FUN_00439880(local_20,&local_14);
    uVar1 = (ulonglong)DAT_00472020;
    local_24 = &PTR_LAB_0047545c;
    if (local_20 != (undefined4 *)0x0) {
      FUN_0042f340(local_20);
    }
    FUN_0042f320(&local_24);
    return (float10)(float)((float10)local_14 + (float10)local_10 / (float10)uVar1);
  }
  return (float10)_DAT_00475300;
}


