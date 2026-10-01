// 00404e00 FUN_00404e00 [Global]
// program: gamma.dll

void __thiscall FUN_00404e00(void *this,uint param_1,undefined4 *param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)((int)this + 4);
  if (uVar1 < param_1) {
    FUN_00404fd0(this,(undefined4 *)(uVar1 * 4 + *(int *)((int)this + 8)),param_1 - uVar1,param_2);
  }
  else if (param_1 < uVar1) {
    FUN_00404f60(this,(undefined4 *)(param_1 * 4 + *(int *)((int)this + 8)),
                 (undefined4 *)(uVar1 * 4 + *(int *)((int)this + 8)));
  }
  return;
}


