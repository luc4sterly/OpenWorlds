// 00453a60 FUN_00453a60 [Global]
// program: gamma.dll

void __thiscall FUN_00453a60(void *this,int param_1,undefined4 *param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  
  if (param_1 != 0) {
    puVar1 = FUN_0044e010(param_1 * 4);
    *(uint **)((int)this + 8) = puVar1;
    *(int *)((int)this + 4) = param_1;
    *(undefined4 *)this = *(undefined4 *)((int)this + 4);
    puVar2 = *(undefined4 **)((int)this + 8);
    for (; param_1 != 0; param_1 = param_1 + -1) {
      *puVar2 = *param_2;
      puVar2 = puVar2 + 1;
    }
  }
  return;
}


