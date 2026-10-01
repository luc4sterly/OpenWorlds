// 00424410 FUN_00424410 [Global]
// program: gamma.dll

void __thiscall FUN_00424410(void *this,uint param_1,undefined1 *param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)((int)this + 4);
  if (uVar1 < param_1) {
    FUN_004244b0(this,(undefined4 *)(*(int *)((int)this + 8) + uVar1),param_1 - uVar1,param_2);
  }
  else if (param_1 < uVar1) {
    FUN_00424460(this,(undefined4 *)(*(int *)((int)this + 8) + param_1),
                 (undefined4 *)(uVar1 + *(int *)((int)this + 8)));
  }
  return;
}


