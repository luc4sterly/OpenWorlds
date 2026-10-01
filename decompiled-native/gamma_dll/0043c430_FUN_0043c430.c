// 0043c430 FUN_0043c430 [Global]
// program: gamma.dll

int * __thiscall FUN_0043c430(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  iVar1 = ((int)param_2 - (int)param_1) / 0x1c;
  piVar3 = (int *)(((int)param_2 - (int)param_1) * -0x6db6db6d);
  if (iVar1 != 0) {
    puVar2 = FUN_0044e010(iVar1 * 0x1c);
    *(uint **)((int)this + 8) = puVar2;
    *(int *)this = iVar1;
    puVar4 = *(undefined4 **)((int)this + 8);
    for (; piVar3 = this, param_1 != param_2; param_1 = param_1 + 7) {
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = *param_1;
        puVar4[1] = param_1[1];
        puVar4[2] = param_1[2];
        puVar4[3] = param_1[3];
        puVar4[4] = param_1[4];
        puVar4[5] = param_1[5];
        puVar4[6] = param_1[6];
      }
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
      puVar4 = puVar4 + 7;
    }
  }
  return piVar3;
}


