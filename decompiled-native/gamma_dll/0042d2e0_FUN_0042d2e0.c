// 0042d2e0 FUN_0042d2e0 [Global]
// program: gamma.dll

void __thiscall FUN_0042d2e0(void *this,int *param_1,void *param_2,void *param_3)

{
  undefined4 uVar1;
  uint *puVar2;
  undefined1 local_33c [264];
  undefined1 local_234 [264];
  undefined1 local_12c [4];
  char local_128 [280];
  
  uVar1 = (**(code **)(*param_1 + 0x14))();
  *(undefined4 *)((int)this + 0xf0) = uVar1;
  if (*(int *)((int)this + 0xf0) != 0x101) {
    FUN_0042c6a0(local_33c,param_1[3],*(int *)((int)this + 0xf0));
    FUN_00451670();
  }
  uVar1 = (**(code **)(*param_1 + 0x14))();
  *(undefined4 *)((int)this + 0xf0) = uVar1;
  if (*(int *)((int)this + 0xf0) != 0x10a) {
    FUN_0042c6a0(local_234,param_1[3],*(int *)((int)this + 0xf0));
    FUN_00451670();
  }
  FUN_00427410(local_12c,&DAT_0049eeb8,0xff);
  puVar2 = FUN_0042e0e0(param_2,param_3);
  FUN_0044d6d0((char *)(puVar2 + 0x42),local_128,0xff);
  *(undefined1 *)((int)puVar2 + 0x207) = 0;
  return;
}


