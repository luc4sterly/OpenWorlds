// 00444380 FUN_00444380 [Global]
// programa: gamma.dll

uint FUN_00444380(int param_1,uint param_2,undefined4 *param_3,uint *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  uint uStack_18;
  uint uStack_14;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  if (param_4 == (uint *)0x0) {
    if (1 < param_2) {
      return 0x80070057;
    }
  }
  else {
    *param_4 = 0;
  }
  uStack_14 = 0;
  iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0xb0))();
  if (*(int *)(param_1 + 0x10) != iVar2) {
    FUN_00444560(param_1);
  }
  uVar4 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
  uStack_18 = param_2;
  if ((int)uVar4 <= (int)param_2) {
    uStack_18 = uVar4;
  }
  if (uStack_18 != 0) {
    while ((uStack_18 != 0 && (*(int *)(param_1 + 8) != *(int *)(param_1 + 4)))) {
      uVar1 = *(undefined4 *)(param_1 + 4);
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
      piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0xc) + 0xb8))(uVar1);
      if (piVar3 == (int *)0x0) {
        return 0x80040203;
      }
      iVar2 = FUN_0044b140((void *)(param_1 + 0x18),(int)piVar3);
      if (iVar2 == 0) {
        piVar5 = piVar3;
        if (piVar3 != (int *)0x0) {
          piVar5 = piVar3 + 3;
        }
        *param_3 = piVar5;
        (**(code **)(*piVar3 + 0x80))(piVar3);
        uStack_14 = uStack_14 + 1;
        param_3 = param_3 + 1;
        FUN_0044b180((void *)(param_1 + 0x18),(uint)piVar3);
        uStack_18 = uStack_18 - 1;
      }
    }
    if (param_4 != (uint *)0x0) {
      *param_4 = uStack_14;
    }
    return (uint)(param_2 != uStack_14);
  }
  return 1;
}


