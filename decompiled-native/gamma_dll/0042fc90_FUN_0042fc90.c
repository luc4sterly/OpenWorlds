// 0042fc90 FUN_0042fc90 [Global]
// programa: gamma.dll

/* WARNING: Removing unreachable block (ram,0x0042fe85) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffedc : 0x0042fdcc */
/* WARNING: Removing unreachable block (ram,0x0042fdd3) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 * __thiscall FUN_0042fc90(void *this,undefined4 *param_1,int *param_2,char *param_3)

{
  bool bVar1;
  uint *this_00;
  char *pcVar2;
  void *this_01;
  undefined3 extraout_var;
  uint uVar3;
  undefined **local_238;
  char local_234 [255];
  undefined1 local_135;
  undefined4 local_134;
  undefined **local_130;
  undefined4 *local_12c;
  undefined **local_128;
  undefined4 *local_124;
  undefined **local_120;
  char local_11c [259];
  undefined1 local_19;
  undefined ***local_18;
  undefined4 *local_14;
  
  this_00 = FUN_0044e010(0x1004);
  if (this_00 != (uint *)0x0) {
    FUN_004303a0(this_00,param_3);
  }
  FUN_00430490((int)this_00);
  uVar3 = 0xff;
  pcVar2 = (char *)FUN_004304d0((int)this_00);
  FUN_00427410(&local_120,pcVar2,uVar3);
  local_238 = &PTR_LAB_00471ff8;
  FUN_0044d6d0(local_234,local_11c,0xff);
  local_135 = 0;
  local_134 = 0;
  local_12c = (undefined4 *)0x0;
  local_120 = &PTR_LAB_00471ff8;
  local_19 = DAT_0049dd25;
  this_01 = (void *)FUN_00430960(*(int *)((int)this + 8),
                                 *(int *)((int)this + 4) * 0x110 + *(int *)((int)this + 8),
                                 (int)&local_238);
  local_18 = &local_128;
  local_124 = (undefined4 *)0x0;
  local_128 = &PTR_LAB_00475040;
  if (((this_01 != (void *)(*(int *)((int)this + 4) * 0x110 + *(int *)((int)this + 8))) &&
      (bVar1 = FUN_00427480(this_01,(int)&local_238), CONCAT31(extraout_var,bVar1) != 0)) &&
     (FUN_004308e0(&local_128,(int)this_01 + 0x108), local_124 == (undefined4 *)0x0)) {
    FUN_00430330(param_2,1);
    FUN_004308e0(&local_128,(int)this_01 + 0x108);
  }
  FUN_004304a0(this_00);
  if (local_124 == (undefined4 *)0x0) {
    *param_1 = &PTR_LAB_00474bac;
    *param_1 = &PTR_LAB_00475040;
    param_1[1] = 0;
    local_128 = &PTR_LAB_00475040;
    FUN_0042f320(&local_128);
    local_130 = &PTR_LAB_00475040;
    if (local_12c != (undefined4 *)0x0) {
      FUN_0042f340(local_12c);
    }
    FUN_0042f320(&local_130);
    return param_1;
  }
  local_14 = param_1;
  *param_1 = &PTR_LAB_00474bac;
  *param_1 = &PTR_LAB_00475040;
  param_1[1] = local_124;
  if (param_1[1] != 0) {
    FUN_0042f330(param_1[1]);
  }
  local_128 = &PTR_LAB_00475040;
  if (local_124 != (undefined4 *)0x0) {
    FUN_0042f340(local_124);
  }
  FUN_0042f320(&local_128);
  local_130 = &PTR_LAB_00475040;
  if (local_12c != (undefined4 *)0x0) {
    FUN_0042f340(local_12c);
  }
  FUN_0042f320(&local_130);
  return param_1;
}


