// 0042e830 FUN_0042e830 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_0042e830(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 == param_2) {
    return param_1;
  }
  puVar3 = (undefined4 *)(*(int *)((int)this + 4) * 0x4c + *(int *)((int)this + 8));
  iVar1 = ((int)puVar3 - (int)param_2) / 0x4c;
  if (iVar1 != 0) {
    FUN_0042e8d0(param_2,puVar3,param_1);
  }
  for (puVar2 = param_1 + iVar1 * 0x13; puVar2 < puVar3; puVar2 = puVar2 + 0x13) {
    FUN_0042bc60((int)puVar2);
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) - ((int)param_2 - (int)param_1) / 0x4c;
  return param_1;
}


