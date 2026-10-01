// 004301c0 FUN_004301c0 [Global]
// program: gamma.dll

void __fastcall FUN_004301c0(undefined4 param_1,undefined4 param_2,char *param_3)

{
  bool bVar1;
  char *pcVar2;
  void *this;
  undefined3 extraout_var;
  void *this_00;
  undefined1 local_122c [4100];
  undefined **local_228;
  char local_224 [255];
  undefined1 local_125;
  undefined4 local_124;
  undefined **local_120;
  undefined4 *local_11c;
  undefined **local_118;
  char local_114 [240];
  undefined4 uStackY_24;
  uint uVar3;
  
  FUN_004574c0(param_1,param_2);
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    FUN_004303a0(local_122c,param_3);
    uVar3 = 0xff;
    pcVar2 = (char *)FUN_004304d0((int)local_122c);
    FUN_00427410(&local_118,pcVar2,uVar3);
    local_228 = &PTR_LAB_00471ff8;
    FUN_0044d6d0(local_224,local_114,0xff);
    local_125 = 0;
    local_124 = 0;
    local_120 = &PTR_LAB_00475040;
    local_11c = (undefined4 *)0x0;
    local_118 = &PTR_LAB_00471ff8;
    uStackY_24 = 0x4302ad;
    this = (void *)FUN_00430960(*(int *)((int)this_00 + 8),
                                *(int *)((int)this_00 + 4) * 0x110 + *(int *)((int)this_00 + 8),
                                (int)&local_228);
    if (this != (void *)(*(int *)((int)this_00 + 4) * 0x110 + *(int *)((int)this_00 + 8))) {
      bVar1 = FUN_00427480(this,(int)&local_228);
      if ((CONCAT31(extraout_var,bVar1) != 0) &&
         (*(int *)((int)this + 0x104) = *(int *)((int)this + 0x104) + -1,
         *(int *)((int)this + 0x104) == 0)) {
        FUN_004309d0(this_00,(uint)this);
      }
    }
    local_120 = &PTR_LAB_00475040;
    if (local_11c != (undefined4 *)0x0) {
      FUN_0042f340(local_11c);
    }
    FUN_0042f320(&local_120);
    local_228 = &PTR_LAB_00471ff8;
    FUN_00430480(local_122c);
    return;
  }
  return;
}


