// 0042cda0 FUN_0042cda0 [Global]
// program: gamma.dll

undefined4 __thiscall FUN_0042cda0(void *this,int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_54c [264];
  undefined1 local_444 [264];
  int local_33c;
  undefined **local_338;
  char local_334 [255];
  undefined1 local_235;
  undefined1 local_234 [264];
  undefined **local_12c;
  char local_128 [280];
  
  uVar2 = (**(code **)(*param_1 + 0x14))();
  *(undefined4 *)((int)this + 0xf0) = uVar2;
  if (*(int *)((int)this + 0xf0) != 0x102) {
    FUN_0042c6a0(local_54c,param_1[3],*(int *)((int)this + 0xf0));
    FUN_00451670();
  }
  uVar2 = (**(code **)(*param_1 + 0x14))();
  *(undefined4 *)((int)this + 0xf0) = uVar2;
  if (*(int *)((int)this + 0xf0) != 0x109) {
    FUN_0042c6a0(local_444,param_1[3],*(int *)((int)this + 0xf0));
    FUN_00451670();
  }
  if (DAT_0049fe04 != 3) {
    FUN_00427410(&local_12c,s_can_t_handle_requested_file_vers_0047498c,0xff);
    local_33c = param_1[3];
    local_338 = &PTR_LAB_00471ff8;
    FUN_0044d6d0(local_334,local_128,0xff);
    local_235 = 0;
    FUN_00451670();
    local_12c = &PTR_LAB_00471ff8;
  }
  uVar2 = (**(code **)(*param_1 + 0x14))();
  *(undefined4 *)((int)this + 0xf0) = uVar2;
  while (iVar1 = *(int *)((int)this + 0xf0), iVar1 != -1) {
    if (iVar1 == 0x103) {
      FUN_0042cf30(this,param_1);
    }
    else {
      FUN_0042c6a0(local_234,param_1[3],iVar1);
      FUN_00451670();
    }
    uVar2 = (**(code **)(*param_1 + 0x14))();
    *(undefined4 *)((int)this + 0xf0) = uVar2;
  }
  return uVar2;
}


