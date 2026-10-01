// 00433a70 FUN_00433a70 [Global]
// program: gamma.dll

/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffe9c : 0x00433d71 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 * __thiscall
FUN_00433a70(void *this,undefined4 *param_1,int *param_2,uint param_3,int param_4)

{
  char *pcVar1;
  bool bVar2;
  uint *this_00;
  int iVar3;
  undefined3 extraout_var;
  void *pvVar4;
  void *this_01;
  undefined **local_168;
  undefined4 *local_164;
  undefined **local_160;
  undefined4 *local_15c;
  undefined **local_158;
  undefined4 *local_154;
  undefined **local_150;
  undefined4 *local_14c;
  undefined **local_148 [65];
  undefined **local_44;
  undefined4 *local_40;
  undefined **local_3c;
  undefined4 *local_38;
  undefined **local_34;
  undefined4 *local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  undefined ***local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  
  if ((param_4 < 1) || (9 < param_4)) {
    param_4 = 1;
  }
  pcVar1 = (&PTR_DAT_00475288)[param_4 * 3];
  if (*pcVar1 == '\0') {
    FUN_004398c0(&local_160);
    local_2c = param_1;
    *param_1 = &PTR_LAB_00474bac;
    *param_1 = &PTR_LAB_00475468;
    param_1[1] = local_15c;
    if (param_1[1] != 0) {
      FUN_0042f330(param_1[1]);
    }
    local_160 = &PTR_LAB_0047545c;
    if (local_15c != (undefined4 *)0x0) {
      FUN_0042f340(local_15c);
    }
    FUN_0042f320(&local_160);
    return param_1;
  }
  this_00 = FUN_0042c7f0();
  if (this_00 == (uint *)0x0) {
    FUN_004398c0(&local_158);
    local_28 = param_1;
    *param_1 = &PTR_LAB_00474bac;
    *param_1 = &PTR_LAB_00475468;
    param_1[1] = local_154;
    if (param_1[1] != 0) {
      FUN_0042f330(param_1[1]);
    }
    local_158 = &PTR_LAB_0047545c;
    if (local_154 != (undefined4 *)0x0) {
      FUN_0042f340(local_154);
    }
    FUN_0042f320(&local_158);
    return param_1;
  }
  iVar3 = FUN_0042ca00(this_00,param_3);
  if (iVar3 == 0) {
    FUN_004398c0(&local_150);
    local_24 = param_1;
    *param_1 = &PTR_LAB_00474bac;
    *param_1 = &PTR_LAB_00475468;
    param_1[1] = local_14c;
    if (param_1[1] != 0) {
      FUN_0042f330(param_1[1]);
    }
    local_150 = &PTR_LAB_0047545c;
    if (local_14c != (undefined4 *)0x0) {
      FUN_0042f340(local_14c);
    }
    FUN_0042f320(&local_150);
    return param_1;
  }
  FUN_00427410(local_148,pcVar1,0xff);
  this_01 = *(void **)((int)this + 0x20);
  pvVar4 = (void *)(*(int *)((int)this + 0x1c) * 0x104 + (int)this_01);
  for (; this_01 != pvVar4; this_01 = (void *)((int)this_01 + 0x104)) {
    bVar2 = FUN_00427480(this_01,(int)local_148);
    if (CONCAT31(extraout_var,bVar2) != 0) break;
  }
  local_148[0] = &PTR_LAB_00471ff8;
  if (this_01 == (void *)(*(int *)((int)this + 0x1c) * 0x104 + *(int *)((int)this + 0x20))) {
    FUN_004398c0(&local_44);
    local_20 = param_1;
    *param_1 = &PTR_LAB_00474bac;
    *param_1 = &PTR_LAB_00475468;
    param_1[1] = local_40;
    if (param_1[1] != 0) {
      FUN_0042f330(param_1[1]);
    }
    local_44 = &PTR_LAB_0047545c;
    if (local_40 != (undefined4 *)0x0) {
      FUN_0042f340(local_40);
    }
    FUN_0042f320(&local_44);
    return param_1;
  }
  FUN_00439920(&local_3c,param_2,
               (char *)((((int)this_01 - *(int *)((int)this + 0x20)) / 0x104) * 0x104 +
                        *(int *)((int)this + 0x2c) + 4),*(int *)(param_4 * 0xc + 0x47528c),
               *(undefined4 *)(param_4 * 0xc + 0x475290));
  local_1c = &local_168;
  local_168 = &PTR_LAB_00475468;
  local_164 = local_38;
  if (local_38 != (undefined4 *)0x0) {
    FUN_0042f330((int)local_38);
  }
  local_3c = &PTR_LAB_0047545c;
  if (local_38 != (undefined4 *)0x0) {
    FUN_0042f340(local_38);
  }
  FUN_0042f320(&local_3c);
  if (local_164 == (undefined4 *)0x0) {
    FUN_004398c0(&local_34);
    local_18 = param_1;
    *param_1 = &PTR_LAB_00474bac;
    *param_1 = &PTR_LAB_00475468;
    param_1[1] = local_30;
    if (param_1[1] != 0) {
      FUN_0042f330(param_1[1]);
    }
    local_34 = &PTR_LAB_0047545c;
    if (local_30 != (undefined4 *)0x0) {
      FUN_0042f340(local_30);
    }
    FUN_0042f320(&local_34);
    local_168 = &PTR_LAB_00475468;
    if (local_164 != (undefined4 *)0x0) {
      FUN_0042f340(local_164);
    }
    FUN_0042f320(&local_168);
    return param_1;
  }
  local_14 = param_1;
  *param_1 = &PTR_LAB_00474bac;
  *param_1 = &PTR_LAB_00475468;
  param_1[1] = local_164;
  if (param_1[1] != 0) {
    FUN_0042f330(param_1[1]);
  }
  local_168 = &PTR_LAB_00475468;
  if (local_164 != (undefined4 *)0x0) {
    FUN_0042f340(local_164);
  }
  FUN_0042f320(&local_168);
  return param_1;
}


