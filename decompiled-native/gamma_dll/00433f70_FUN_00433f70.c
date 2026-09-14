// 00433f70 FUN_00433f70 [Global]
// programa: gamma.dll

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffcc : 0x004340a4 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 * FUN_00433f70(undefined4 *param_1,int *param_2,uint param_3,int param_4)

{
  uint *this;
  int iVar1;
  uint uVar2;
  undefined **local_38;
  undefined4 *local_34;
  undefined **local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  undefined ***local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  
  uVar2 = param_4 - 1;
  this = FUN_0042c7f0();
  if (this == (uint *)0x0) {
    local_28 = param_1;
    *param_1 = &PTR_LAB_00474bac;
    *param_1 = &PTR_LAB_0047545c;
    param_1[1] = 0;
    if (param_1[1] != 0) {
      FUN_0042f330(param_1[1]);
    }
    return local_28;
  }
  iVar1 = FUN_0042ca00(this,param_3);
  if (iVar1 == 0) {
    local_24 = param_1;
    *param_1 = &PTR_LAB_00474bac;
    *param_1 = &PTR_LAB_0047545c;
    param_1[1] = 0;
    if (param_1[1] != 0) {
      FUN_0042f330(param_1[1]);
    }
    return local_24;
  }
  iVar1 = FUN_0042bd50(iVar1);
  if (((int)uVar2 < 0) || (*(uint *)(iVar1 + 4) <= uVar2)) {
    local_20 = param_1;
    *param_1 = &PTR_LAB_00474bac;
    *param_1 = &PTR_LAB_0047545c;
    param_1[1] = 0;
    if (param_1[1] != 0) {
      FUN_0042f330(param_1[1]);
    }
    return local_20;
  }
  FUN_00439920(&local_30,param_2,(char *)(uVar2 * 0x104 + *(int *)(iVar1 + 8) + 4),1,0);
  local_1c = &local_38;
  local_38 = &PTR_LAB_0047545c;
  local_34 = local_2c;
  if (local_2c != (undefined4 *)0x0) {
    FUN_0042f330((int)local_2c);
  }
  local_30 = &PTR_LAB_0047545c;
  if (local_2c != (undefined4 *)0x0) {
    FUN_0042f340(local_2c);
  }
  FUN_0042f320(&local_30);
  if (local_34 == (undefined4 *)0x0) {
    local_18 = param_1;
    *param_1 = &PTR_LAB_00474bac;
    *param_1 = &PTR_LAB_0047545c;
    param_1[1] = 0;
    if (param_1[1] != 0) {
      FUN_0042f330(param_1[1]);
    }
    local_38 = &PTR_LAB_0047545c;
    if (local_34 != (undefined4 *)0x0) {
      FUN_0042f340(local_34);
    }
    FUN_0042f320(&local_38);
    return param_1;
  }
  local_14 = param_1;
  *param_1 = &PTR_LAB_00474bac;
  *param_1 = &PTR_LAB_0047545c;
  param_1[1] = local_34;
  if (param_1[1] != 0) {
    FUN_0042f330(param_1[1]);
  }
  local_38 = &PTR_LAB_0047545c;
  if (local_34 != (undefined4 *)0x0) {
    FUN_0042f340(local_34);
  }
  FUN_0042f320(&local_38);
  return param_1;
}


