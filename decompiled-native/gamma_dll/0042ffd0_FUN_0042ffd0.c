// 0042ffd0 FUN_0042ffd0 [Global]
// program: gamma.dll

void __thiscall FUN_0042ffd0(void *this,int *param_1,char *param_2)

{
  bool bVar1;
  uint *this_00;
  char *pcVar2;
  undefined4 *this_01;
  undefined3 extraout_var;
  int iVar3;
  uint uVar4;
  undefined **local_228;
  char local_224 [255];
  undefined1 local_125;
  undefined4 local_124;
  undefined **local_120;
  undefined4 *local_11c;
  undefined **local_118;
  char local_114 [259];
  undefined1 local_11;
  
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    return;
  }
  this_00 = FUN_0044e010(0x1004);
  if (this_00 != (uint *)0x0) {
    FUN_004303a0(this_00,param_2);
  }
  FUN_00430490((int)this_00);
  uVar4 = 0xff;
  pcVar2 = (char *)FUN_004304d0((int)this_00);
  FUN_00427410(&local_118,pcVar2,uVar4);
  local_228 = &PTR_LAB_00471ff8;
  FUN_0044d6d0(local_224,local_114,0xff);
  local_125 = 0;
  local_124 = 0;
  local_11c = (undefined4 *)0x0;
  local_118 = &PTR_LAB_00471ff8;
  local_11 = DAT_0049dd26;
  this_01 = (undefined4 *)
            FUN_00430960(*(int *)((int)this + 8),
                         *(int *)((int)this + 4) * 0x110 + *(int *)((int)this + 8),(int)&local_228);
  if (this_01 != (undefined4 *)(*(int *)((int)this + 4) * 0x110 + *(int *)((int)this + 8))) {
    bVar1 = FUN_004274b0(this_01,(int)&local_228);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      this_01[0x41] = this_01[0x41] + 1;
      FUN_00430330(param_1,0);
      goto LAB_00430177;
    }
  }
  iVar3 = *(int *)((int)this + 8);
  FUN_00430ad0(this,this_01,(undefined4 *)0x1,(int)&local_228);
  iVar3 = (((int)this_01 - iVar3) / 0x110) * 0x110 + *(int *)((int)this + 8);
  *(undefined4 *)(iVar3 + 0x104) = 1;
  FUN_00430920((void *)(iVar3 + 0x108),0);
LAB_00430177:
  FUN_004304a0(this_00);
  local_120 = &PTR_LAB_00475040;
  if (local_11c != (undefined4 *)0x0) {
    FUN_0042f340(local_11c);
  }
  FUN_0042f320(&local_120);
  return;
}


