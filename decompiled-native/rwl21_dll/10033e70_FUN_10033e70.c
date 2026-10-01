// 10033e70 FUN_10033e70 [Global]
// program: RWL21.DLL

void __thiscall FUN_10033e70(void *this,undefined1 *param_1,int param_2)

{
  undefined *puVar1;
  
  if (param_1 == &LAB_10027460) {
    puVar1 = &LAB_10027490;
    param_1 = &LAB_10027460;
  }
  else {
    this = PTR_DAT_1005b69c + *(int *)(param_2 + 0xe0) * 4;
    if (*(undefined1 **)(PTR_DAT_1005b69c + *(int *)(param_2 + 0xe0) * 4 + 0x54) == param_1) {
      puVar1 = *(undefined **)((int)this + 0x154);
    }
    else {
      param_1 = &LAB_10027460;
      puVar1 = &LAB_10027490;
    }
  }
  FUN_10033ed0(this,param_2,param_1,puVar1,param_2);
  return;
}


