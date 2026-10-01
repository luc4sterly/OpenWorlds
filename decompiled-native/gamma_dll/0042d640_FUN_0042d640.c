// 0042d640 FUN_0042d640 [Global]
// program: gamma.dll

void __thiscall FUN_0042d640(void *this,int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined **ppuVar3;
  undefined **local_64c;
  char local_648 [255];
  undefined1 local_549;
  undefined1 local_548 [264];
  undefined **local_440 [65];
  undefined1 local_33c [264];
  undefined1 local_234 [264];
  undefined **local_12c [71];
  
  local_648[0] = '\0';
  local_64c = &PTR_LAB_00471ff8;
  uVar2 = (**(code **)(*param_1 + 0x14))();
  *(undefined4 *)((int)this + 0xf0) = uVar2;
  ppuVar3 = &PTR_LAB_00471ff8;
  while (iVar1 = *(int *)((int)this + 0xf0), iVar1 != 0x108) {
    if (iVar1 == 0x10b) {
      FUN_0042d0c0(this,param_1,param_2,(int)&local_64c);
    }
    else {
      if (iVar1 != 0x10a) {
        FUN_0042c6a0(local_548,param_1[3],iVar1);
        FUN_00451670();
      }
      FUN_004280b0(&DAT_0049eeb8,&DAT_0049eeb8);
      FUN_00427410(local_440,&DAT_0049eeb8,0xff);
      FUN_0044d6d0(local_648,&DAT_0049eeb8,0xff);
      local_549 = 0;
      uVar2 = (**(code **)(*param_1 + 0x14))();
      *(undefined4 *)((int)this + 0xf0) = uVar2;
      if (*(int *)((int)this + 0xf0) != 0x101) {
        FUN_0042c6a0(local_33c,param_1[3],*(int *)((int)this + 0xf0));
        FUN_00451670();
      }
      uVar2 = (**(code **)(*param_1 + 0x14))();
      *(undefined4 *)((int)this + 0xf0) = uVar2;
      if (*(int *)((int)this + 0xf0) != 0x10a) {
        FUN_0042c6a0(local_234,param_1[3],*(int *)((int)this + 0xf0));
        FUN_00451670();
      }
      FUN_0042e720((void *)(param_2 + 0x28),(int)local_440);
      FUN_00427410(local_12c,&DAT_0049eeb8,0xff);
      FUN_0042e720((void *)(param_2 + 0x34),(int)local_12c);
      local_440[0] = ppuVar3;
      local_12c[0] = ppuVar3;
    }
    uVar2 = (**(code **)(*param_1 + 0x14))(ppuVar3);
    *(undefined4 *)((int)this + 0xf0) = uVar2;
  }
  return;
}


