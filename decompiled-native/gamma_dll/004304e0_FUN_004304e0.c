// 004304e0 FUN_004304e0 [Global]
// programa: gamma.dll

void __thiscall
FUN_004304e0(void *this,undefined4 param_1,int param_2,undefined4 *param_3,int param_4)

{
  uint *puVar1;
  bool bVar2;
  void *this_00;
  undefined3 extraout_var;
  int local_2bc;
  undefined4 local_2b8;
  undefined ***local_2b4;
  undefined1 auStack_2ac [52];
  undefined **local_278 [16];
  undefined **local_238;
  char local_234 [255];
  undefined1 local_135;
  undefined4 local_134;
  undefined **local_130;
  undefined4 *local_12c;
  undefined **local_124;
  char local_120 [259];
  undefined1 local_1d;
  undefined **local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  
  if (param_2 == 1) {
    FUN_00424260(&local_2bc,param_3,param_4);
    local_14 = &local_2b8;
    local_2b4 = local_278;
    local_278[0] = &PTR_LAB_0046f34c;
    FUN_00411ef0(local_14,0,(int)auStack_2ac);
    *local_14 = &PTR_FUN_00471860;
    *(undefined ***)local_14[1] = &PTR_LAB_0047186c;
    *(int *)(local_14[1] + 0x3c) = (int)local_14 + (0x40 - local_14[1]);
    FUN_004240f0(local_14 + 3,&local_2bc,8);
    if ((DAT_0049ff20 == (uint *)0x0) &&
       (DAT_0049ff20 = FUN_0044e010(0xc), DAT_0049ff20 != (uint *)0x0)) {
      *DAT_0049ff20 = 0;
      DAT_0049ff20[1] = 0;
      DAT_0049ff20[2] = 0;
    }
    puVar1 = DAT_0049ff20;
    if (DAT_0049ff20 == (uint *)0x0) {
      local_2b4[0xf] = (undefined **)((int)local_278 - (int)local_2b4);
      FUN_004231d0(&local_2b8);
      FUN_004108d0(local_278);
      FUN_00404ed0(&local_2bc);
      return;
    }
    FUN_00427410(&local_124,(char *)((int)this + 0x800),0xff);
    local_238 = &PTR_LAB_00471ff8;
    FUN_0044d6d0(local_234,local_120,0xff);
    local_135 = 0;
    local_134 = 0;
    local_130 = &PTR_LAB_00475040;
    local_12c = (undefined4 *)0x0;
    local_124 = &PTR_LAB_00471ff8;
    local_1d = DAT_0049dd28;
    this_00 = (void *)FUN_00430960(puVar1[2],puVar1[1] * 0x110 + puVar1[2],(int)&local_238);
    if ((this_00 == (void *)(puVar1[1] * 0x110 + puVar1[2])) ||
       (bVar2 = FUN_004274b0(this_00,(int)&local_238), CONCAT31(extraout_var,bVar2) != 0)) {
      local_130 = &PTR_LAB_00475040;
      if (local_12c != (undefined4 *)0x0) {
        FUN_0042f340(local_12c);
      }
      FUN_0042f320(&local_130);
      local_238 = &PTR_LAB_00471ff8;
      local_2b4[0xf] = (undefined **)((int)local_278 - (int)local_2b4);
      FUN_004231d0(&local_2b8);
      FUN_004108d0(local_278);
      FUN_00404ed0(&local_2bc);
      return;
    }
    FUN_00438050(&local_1c,&local_2b8);
    FUN_004308e0((void *)((int)this_00 + 0x108),(int)&local_1c);
    local_1c = &PTR_LAB_00475040;
    if (local_18 != (undefined4 *)0x0) {
      FUN_0042f340(local_18);
    }
    FUN_0042f320(&local_1c);
    local_130 = &PTR_LAB_00475040;
    if (local_12c != (undefined4 *)0x0) {
      FUN_0042f340(local_12c);
    }
    FUN_0042f320(&local_130);
    local_238 = &PTR_LAB_00471ff8;
    local_2b4[0xf] = (undefined **)((int)local_278 - (int)local_2b4);
    FUN_004231d0(&local_2b8);
    FUN_004108d0(local_278);
    FUN_00404ed0(&local_2bc);
  }
  return;
}


