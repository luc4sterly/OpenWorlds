// 0042aed0 FUN_0042aed0 [Global]
// program: gamma.dll

void __thiscall FUN_0042aed0(void *this,undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  if (param_1 == *(undefined4 **)((int)this + 0x28)) {
    *(undefined4 *)((int)this + 0x28) = 0;
  }
  if (param_1[5] != 0) {
    FUN_0042b010((undefined4 *)param_1[1]);
  }
  FUN_0042b010(param_1);
  return;
}


