// 0043bf80 FUN_0043bf80 [Global]
// program: gamma.dll

undefined4 * __cdecl FUN_0043bf80(undefined4 *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4 [7];
  undefined4 local_88 [7];
  undefined4 local_6c [7];
  undefined4 local_50 [7];
  undefined4 local_34 [7];
  undefined4 *local_18;
  undefined4 *local_14;
  
  if (*(int *)(param_2 + 4) == 0) {
    local_18 = param_1;
    *param_1 = &PTR_LAB_00474bac;
    *param_1 = &PTR_LAB_00475438;
    param_1[1] = *(undefined4 *)(param_3 + 4);
    if (param_1[1] != 0) {
      FUN_0042f330(param_1[1]);
    }
    return param_1;
  }
  if (*(int *)(param_3 + 4) != 0) {
    local_b0 = 0;
    local_a8 = 0;
    local_ac = 0;
    FUN_00438a40(&local_b0,
                 *(int *)(*(int *)(param_2 + 4) + 0xc) + *(int *)(*(int *)(param_3 + 4) + 0xc));
    iVar1 = *(int *)(param_2 + 4);
    piVar3 = (int *)(*(int *)(iVar1 + 0xc) * 0x1c + *(int *)(iVar1 + 0x10));
    iVar2 = *(int *)(param_3 + 4);
    piVar4 = (int *)(*(int *)(iVar2 + 0xc) * 0x1c + *(int *)(iVar2 + 0x10));
    piVar5 = *(int **)(iVar1 + 0x10);
    piVar6 = *(int **)(iVar2 + 0x10);
    while ((piVar5 != piVar3 && (piVar6 != piVar4))) {
      if (*piVar5 < *piVar6) {
        (**(code **)*param_4)(local_a4,piVar5);
        FUN_004389d0(&local_b0,local_a4);
        piVar5 = piVar5 + 7;
      }
      else if (*piVar6 < *piVar5) {
        (**(code **)(*param_4 + 4))(local_88,piVar6);
        FUN_004389d0(&local_b0,local_88);
        piVar6 = piVar6 + 7;
      }
      else {
        (**(code **)(*param_4 + 8))(local_6c,piVar5,piVar6);
        FUN_004389d0(&local_b0,local_6c);
        piVar5 = piVar5 + 7;
        piVar6 = piVar6 + 7;
      }
    }
    for (; piVar5 != piVar3; piVar5 = piVar5 + 7) {
      (**(code **)*param_4)(local_50,piVar5);
      FUN_004389d0(&local_b0,local_50);
    }
    for (; piVar6 != piVar4; piVar6 = piVar6 + 7) {
      (**(code **)(*param_4 + 4))(local_34,piVar6);
      FUN_004389d0(&local_b0,local_34);
    }
    FUN_0043bc80(param_1,(int)&local_b0);
    FUN_00438c50((int)&local_b0);
    return param_1;
  }
  local_14 = param_1;
  *param_1 = &PTR_LAB_00474bac;
  *param_1 = &PTR_LAB_00475438;
  param_1[1] = *(undefined4 *)(param_2 + 4);
  if (param_1[1] != 0) {
    FUN_0042f330(param_1[1]);
  }
  return param_1;
}


