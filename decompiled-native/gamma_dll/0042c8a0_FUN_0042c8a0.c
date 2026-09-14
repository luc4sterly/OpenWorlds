// 0042c8a0 FUN_0042c8a0 [Global]
// programa: gamma.dll

int __thiscall FUN_0042c8a0(void *this,char *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  void *this_00;
  undefined1 local_420 [260];
  undefined **local_31c;
  char acStack_318 [255];
  undefined1 local_219;
  undefined **local_218 [65];
  undefined **local_114;
  char acStack_110 [256];
  
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    FUN_00427410(local_420,param_1,0xff);
    this_00 = *(void **)((int)this + 8);
    while( true ) {
      if (this_00 == (void *)(*(int *)((int)this + 4) * 0x4c + *(int *)((int)this + 8))) {
        return -1;
      }
      FUN_00427410(local_218,&DAT_004748f0,0xff);
      FUN_0042bcb0(this_00,&local_114,local_218);
      local_31c = &PTR_LAB_00471ff8;
      FUN_0044d6d0(acStack_318,acStack_110,0xff);
      local_218[0] = &PTR_LAB_00471ff8;
      local_219 = 0;
      local_114 = &PTR_LAB_00471ff8;
      bVar1 = FUN_00427450(local_420,(int)&local_31c);
      if (CONCAT31(extraout_var,bVar1) != 0) break;
      this_00 = (void *)((int)this_00 + 0x4c);
      local_31c = &PTR_LAB_00471ff8;
    }
    return ((int)this_00 - *(int *)((int)this + 8)) / 0x4c;
  }
  return -1;
}


