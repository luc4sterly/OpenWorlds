// 004379a0 FUN_004379a0 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_004379a0(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_1 == param_2) {
    return param_1;
  }
  puVar3 = (undefined4 *)(*(int *)((int)this + 4) * 0x11c + *(int *)((int)this + 8));
  iVar1 = ((int)puVar3 - (int)param_2) / 0x11c;
  puVar4 = param_1;
  puVar2 = param_2;
  if (iVar1 != 0) {
    for (; puVar2 < puVar3; puVar2 = puVar2 + 0x47) {
      FUN_004358f0(puVar4,puVar2);
      puVar4 = puVar4 + 0x47;
    }
  }
  for (puVar4 = param_1 + iVar1 * 0x47; puVar4 < puVar3; puVar4 = puVar4 + 0x47) {
    (**(code **)*puVar4)(0);
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) - ((int)param_2 - (int)param_1) / 0x11c;
  return param_1;
}


