// 00437d00 FUN_00437d00 [Global]
// program: gamma.dll

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffb0 : 0x00437d68 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 * __cdecl
FUN_00437d00(undefined4 *param_1,int *param_2,char *param_3,int param_4,undefined4 param_5)

{
  uint *this;
  undefined ***pppuVar1;
  undefined **local_54;
  undefined4 *local_50;
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
  undefined ***local_24;
  undefined ***local_20;
  undefined4 *local_1c;
  undefined ***local_18;
  undefined4 *local_14;
  
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    FUN_00437c60(param_1);
    return param_1;
  }
  pppuVar1 = &local_4c;
  this = FUN_0042fc50();
  FUN_0042fc90(this,pppuVar1,param_2,param_3);
  local_24 = &local_54;
  local_54 = &PTR_LAB_00475040;
  local_50 = local_48;
  if (local_48 != (undefined4 *)0x0) {
    FUN_0042f330((int)local_48);
  }
  local_4c = &PTR_LAB_00475040;
  if (local_48 != (undefined4 *)0x0) {
    FUN_0042f340(local_48);
  }
  FUN_0042f320(&local_4c);
  if (local_50 == (undefined4 *)0x0) {
    FUN_00437c60(param_1);
    local_54 = &PTR_LAB_00475040;
    if (local_50 != (undefined4 *)0x0) {
      FUN_0042f340(local_50);
    }
    FUN_0042f320(&local_54);
    return param_1;
  }
  if (param_4 == 0) {
    local_20 = &local_44;
    local_44 = &PTR_LAB_00475040;
    local_40 = local_50;
    if (local_50 != (undefined4 *)0x0) {
      FUN_0042f330((int)local_50);
    }
    FUN_0043b3e0(&local_3c,(int)&local_44,param_5);
    local_1c = param_1;
    *param_1 = &PTR_LAB_00474bac;
    *param_1 = &PTR_LAB_00475fac;
    param_1[1] = local_38;
    if (param_1[1] != 0) {
      FUN_0042f330(param_1[1]);
    }
    local_3c = &PTR_LAB_00475fac;
    if (local_38 != (undefined4 *)0x0) {
      FUN_0042f340(local_38);
    }
    FUN_0042f320(&local_3c);
    local_44 = &PTR_LAB_00475040;
    if (local_40 != (undefined4 *)0x0) {
      FUN_0042f340(local_40);
    }
    FUN_0042f320(&local_44);
    local_54 = &PTR_LAB_00475040;
    if (local_50 != (undefined4 *)0x0) {
      FUN_0042f340(local_50);
    }
    FUN_0042f320(&local_54);
    return param_1;
  }
  local_18 = &local_34;
  local_34 = &PTR_LAB_00475040;
  local_30 = local_50;
  if (local_50 != (undefined4 *)0x0) {
    FUN_0042f330((int)local_50);
  }
  FUN_0043b790(&local_2c,(int)&local_34,param_5);
  local_14 = param_1;
  *param_1 = &PTR_LAB_00474bac;
  *param_1 = &PTR_LAB_00475fac;
  param_1[1] = local_28;
  if (param_1[1] != 0) {
    FUN_0042f330(param_1[1]);
  }
  local_2c = &PTR_LAB_00475fac;
  if (local_28 != (undefined4 *)0x0) {
    FUN_0042f340(local_28);
  }
  FUN_0042f320(&local_2c);
  local_34 = &PTR_LAB_00475040;
  if (local_30 != (undefined4 *)0x0) {
    FUN_0042f340(local_30);
  }
  FUN_0042f320(&local_34);
  local_54 = &PTR_LAB_00475040;
  if (local_50 != (undefined4 *)0x0) {
    FUN_0042f340(local_50);
  }
  FUN_0042f320(&local_54);
  return param_1;
}


