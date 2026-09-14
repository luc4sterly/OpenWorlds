// 00404f60 FUN_00404f60 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00404f60(void *this,undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_1 == param_2) {
    return param_1;
  }
  puVar4 = (undefined4 *)(*(int *)((int)this + 4) * 4 + *(int *)((int)this + 8));
  iVar3 = (int)puVar4 - (int)param_2;
  puVar1 = param_1;
  puVar2 = param_2;
  if ((int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2 != 0) {
    for (; puVar2 < puVar4; puVar2 = puVar2 + 1) {
      *puVar1 = *puVar2;
      puVar1 = puVar1 + 1;
    }
  }
  *(int *)((int)this + 4) =
       *(int *)((int)this + 4) -
       ((int)(((int)param_2 - (int)param_1) + ((int)param_2 - (int)param_1 >> 0x1f & 3U)) >> 2);
  return param_1;
}


