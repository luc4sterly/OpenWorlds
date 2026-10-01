// 00432d10 FUN_00432d10 [Global]
// program: gamma.dll

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffff7c : 0x00432da8 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

float10 __thiscall FUN_00432d10(void *param_1,int *param_2,uint param_3,int param_4,int param_5)

{
  ulonglong uVar1;
  undefined **local_88;
  undefined4 *local_84;
  undefined **local_80;
  undefined4 *local_7c;
  undefined **local_78;
  undefined4 *local_74;
  undefined **local_70;
  undefined4 *local_6c;
  undefined **local_68;
  undefined4 *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined **local_58;
  undefined4 *local_54;
  undefined **local_50;
  undefined4 *local_4c;
  undefined **local_48;
  undefined4 *local_44;
  undefined **local_40;
  undefined4 *local_3c;
  undefined4 local_38 [2];
  undefined **local_30;
  undefined4 *local_2c;
  uint local_28;
  uint local_24;
  undefined ***local_20;
  undefined ***local_1c;
  undefined ***local_18;
  undefined ***local_14;
  
  if (*(char *)((int)param_1 + 5) == '\0') {
    return (float10)_DAT_00475300;
  }
  FUN_004330a0(param_1,param_3,param_5);
  if ((-1 < param_4) && (param_4 != *(int *)((int)param_1 + 0x34))) {
    *(int *)((int)param_1 + 0x34) = param_4;
    if (*(int *)((int)param_1 + 0x34) == 0) {
      return (float10)_DAT_00475300;
    }
    FUN_00433a70(param_1,&local_78,param_2,param_3,*(int *)((int)param_1 + 0x34));
    local_20 = &local_88;
    local_88 = &PTR_LAB_00475468;
    local_84 = local_74;
    if (local_74 != (undefined4 *)0x0) {
      FUN_0042f330((int)local_74);
    }
    local_78 = &PTR_LAB_00475468;
    if (local_74 != (undefined4 *)0x0) {
      FUN_0042f340(local_74);
    }
    FUN_0042f320(&local_78);
    if (local_84 != (undefined4 *)0x0) {
      FUN_00433980(param_1,&local_70);
      local_1c = &local_68;
      local_68 = &PTR_LAB_00475468;
      local_64 = local_84;
      if (local_84 != (undefined4 *)0x0) {
        FUN_0042f330((int)local_84);
      }
      local_60 = 0;
      local_5c = 0xfa;
      FUN_0043a5f0(&local_58,(int)&local_70,(int)&local_68,&local_60);
      FUN_004339f0(param_1,(int)&local_58);
      local_58 = &PTR_LAB_00475468;
      if (local_54 != (undefined4 *)0x0) {
        FUN_0042f340(local_54);
      }
      FUN_0042f320(&local_58);
      local_68 = &PTR_LAB_00475468;
      if (local_64 != (undefined4 *)0x0) {
        FUN_0042f340(local_64);
      }
      FUN_0042f320(&local_68);
      local_70 = &PTR_LAB_00475468;
      if (local_6c != (undefined4 *)0x0) {
        FUN_0042f340(local_6c);
      }
      FUN_0042f320(&local_70);
    }
    local_88 = &PTR_LAB_00475468;
    if (local_84 != (undefined4 *)0x0) {
      FUN_0042f340(local_84);
    }
    FUN_0042f320(&local_88);
  }
  if (-1 < param_5) {
    *(int *)((int)param_1 + 0x38) = param_5;
    if (*(int *)((int)param_1 + 0x38) == 0) {
      return (float10)_DAT_00475300;
    }
    FUN_00433f70(&local_50,param_2,param_3,*(int *)((int)param_1 + 0x38));
    local_18 = &local_80;
    local_80 = &PTR_LAB_0047545c;
    local_7c = local_4c;
    if (local_4c != (undefined4 *)0x0) {
      FUN_0042f330((int)local_4c);
    }
    local_50 = &PTR_LAB_0047545c;
    if (local_4c != (undefined4 *)0x0) {
      FUN_0042f340(local_4c);
    }
    FUN_0042f320(&local_50);
    if (local_7c != (undefined4 *)0x0) {
      FUN_00433890(param_1,&local_48);
      local_14 = &local_40;
      local_40 = &PTR_LAB_00475468;
      local_3c = local_7c;
      if (local_7c != (undefined4 *)0x0) {
        FUN_0042f330((int)local_7c);
      }
      FUN_00439880(local_7c,local_38);
      FUN_0043ac60(&local_30,(int)&local_48,(int)&local_40,local_38);
      FUN_00433900(param_1,(int)&local_30);
      local_30 = &PTR_LAB_00475468;
      if (local_2c != (undefined4 *)0x0) {
        FUN_0042f340(local_2c);
      }
      FUN_0042f320(&local_30);
      local_40 = &PTR_LAB_00475468;
      if (local_3c != (undefined4 *)0x0) {
        FUN_0042f340(local_3c);
      }
      FUN_0042f320(&local_40);
      local_48 = &PTR_LAB_00475468;
      if (local_44 != (undefined4 *)0x0) {
        FUN_0042f340(local_44);
      }
      FUN_0042f320(&local_48);
    }
    FUN_00439880(local_7c,&local_28);
    uVar1 = (ulonglong)DAT_00472020;
    local_80 = &PTR_LAB_0047545c;
    if (local_7c != (undefined4 *)0x0) {
      FUN_0042f340(local_7c);
    }
    FUN_0042f320(&local_80);
    return (float10)(float)((float10)local_28 + (float10)local_24 / (float10)uVar1);
  }
  return (float10)_DAT_00475300;
}


