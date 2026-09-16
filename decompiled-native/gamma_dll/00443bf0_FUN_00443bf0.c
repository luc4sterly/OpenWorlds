// 00443bf0 FUN_00443bf0 [Global]
// programa: gamma.dll

int __thiscall FUN_00443bf0(int param_1,uint *param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  piVar1 = *(int **)(param_1 + 0x18);
  if (piVar1 == (int *)0x0) {
    return -0x7ffbfded;
  }
  iVar4 = (**(code **)(*piVar1 + 0xc))(piVar1,param_2);
  if (iVar4 < 0) {
    return iVar4;
  }
  uVar2 = *param_2;
  uVar3 = *(uint *)(param_1 + 0x1c);
  iVar4 = *(int *)(param_1 + 0x20);
  *param_2 = uVar2 - *(uint *)(param_1 + 0x1c);
  param_2[1] = (param_2[1] - iVar4) - (uint)(uVar2 < uVar3);
  return 0;
}


