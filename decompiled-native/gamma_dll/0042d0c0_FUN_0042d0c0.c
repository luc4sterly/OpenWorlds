// 0042d0c0 FUN_0042d0c0 [Global]
// programa: gamma.dll

void __thiscall FUN_0042d0c0(void *this,int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_768 [65];
  undefined1 auStack_664 [12];
  undefined1 auStack_658 [12];
  undefined1 local_64c [264];
  undefined **local_544 [65];
  undefined1 local_440 [264];
  undefined1 local_338 [264];
  undefined **local_230;
  char local_22c [255];
  undefined1 local_12d;
  undefined **local_12c [71];
  
  local_230 = &PTR_LAB_00471ff8;
  FUN_0044d6d0(local_22c,(char *)(param_3 + 4),0xff);
  local_12d = 0;
  FUN_0042bdc0(local_768,(int)&local_230);
  local_230 = &PTR_LAB_00471ff8;
  uVar2 = (**(code **)(*param_1 + 0x14))();
  *(undefined4 *)((int)this + 0xf0) = uVar2;
  while (iVar1 = *(int *)((int)this + 0xf0), iVar1 != 0x10c) {
    if (iVar1 != 0x10a) {
      FUN_0042c6a0(local_64c,param_1[3],iVar1);
      FUN_00451670();
    }
    FUN_004280b0(&DAT_0049eeb8,&DAT_0049eeb8);
    FUN_00427410(local_544,&DAT_0049eeb8,0xff);
    uVar2 = (**(code **)(*param_1 + 0x14))();
    *(undefined4 *)((int)this + 0xf0) = uVar2;
    if (*(int *)((int)this + 0xf0) != 0x101) {
      FUN_0042c6a0(local_440,param_1[3],*(int *)((int)this + 0xf0));
      FUN_00451670();
    }
    uVar2 = (**(code **)(*param_1 + 0x14))();
    *(undefined4 *)((int)this + 0xf0) = uVar2;
    if (*(int *)((int)this + 0xf0) != 0x10a) {
      FUN_0042c6a0(local_338,param_1[3],*(int *)((int)this + 0xf0));
      FUN_00451670();
    }
    FUN_0042e720(auStack_664,(int)local_544);
    FUN_00427410(local_12c,&DAT_0049eeb8,0xff);
    FUN_0042e720(auStack_658,(int)local_12c);
    local_544[0] = &PTR_LAB_00471ff8;
    local_12c[0] = &PTR_LAB_00471ff8;
    uVar2 = (**(code **)(*param_1 + 0x14))();
    *(undefined4 *)((int)this + 0xf0) = uVar2;
  }
  FUN_0042e7b0((void *)(param_2 + 0x40),(int)local_768);
  FUN_0042be30(local_768);
  return;
}


