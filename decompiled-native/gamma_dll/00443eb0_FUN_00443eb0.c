// 00443eb0 FUN_00443eb0 [Global]
// program: gamma.dll

undefined4 __thiscall FUN_00443eb0(void *this,int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)((int)this + 0x40);
  if (piVar1 != (int *)0x0) {
    if ((param_1 == 1) && (param_3 = (int)this, this != (void *)0x0)) {
      param_3 = (int)this + 0xc;
    }
    uVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,param_1,param_2,param_3);
    return uVar2;
  }
  return 0x80004001;
}


