// 0042cfc0 FUN_0042cfc0 [Global]
// programa: gamma.dll

void __thiscall FUN_0042cfc0(void *this,int *param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_234 [264];
  undefined **local_12c [71];
  
  uVar2 = (**(code **)(*param_1 + 0x14))();
  *(undefined4 *)((int)this + 0xf0) = uVar2;
  while (iVar1 = *(int *)((int)this + 0xf0), iVar1 != 0x104) {
    if (iVar1 == 0x10a) {
      FUN_00427410(local_12c,&DAT_0049eeb8,0xff);
      FUN_0042d2e0(this,param_1,param_2,local_12c);
      local_12c[0] = &PTR_LAB_00471ff8;
    }
    else if (iVar1 == 0x105) {
      FUN_0042d3e0(this,param_1,(int)param_2);
    }
    else if (iVar1 == 0x107) {
      FUN_0042d640(this,param_1,(int)param_2);
    }
    else {
      FUN_0042c6a0(local_234,param_1[3],iVar1);
      FUN_00451670();
    }
    uVar2 = (**(code **)(*param_1 + 0x14))();
    *(undefined4 *)((int)this + 0xf0) = uVar2;
  }
  return;
}


