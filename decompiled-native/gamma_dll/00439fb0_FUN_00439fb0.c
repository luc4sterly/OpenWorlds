// 00439fb0 FUN_00439fb0 [Global]
// program: gamma.dll

undefined8 __fastcall
FUN_00439fb0(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 *extraout_EDX_02;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined **local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    local_3c = *param_5;
    local_38 = param_5[1];
    (**(code **)(**(int **)(param_1 + 0xc) + 4))(&local_34,param_4,&local_3c);
    FUN_00434350((void *)(param_1 + 8),(int)&local_34);
    local_34 = &PTR_LAB_00475468;
    if (local_30 != (undefined4 *)0x0) {
      FUN_0042f340(local_30);
    }
    FUN_0042f320(&local_34);
    param_2 = extraout_EDX;
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    local_2c = *param_5;
    local_28 = param_5[1];
    (**(code **)(**(int **)(param_1 + 0x14) + 4))(&local_24,param_4,&local_2c);
    FUN_00434350((void *)(param_1 + 0x10),(int)&local_24);
    local_24 = &PTR_LAB_00475468;
    if (local_20 != (undefined4 *)0x0) {
      FUN_0042f340(local_20);
    }
    FUN_0042f320(&local_24);
    param_2 = extraout_EDX_00;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    local_1c = param_3;
    *param_3 = &PTR_LAB_00474bac;
    *param_3 = &PTR_LAB_00475468;
    param_3[1] = *(undefined4 *)(param_1 + 0x14);
    if (param_3[1] != 0) {
      FUN_0042f330(param_3[1]);
    }
    return CONCAT44(local_1c,param_3);
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    local_18 = param_3;
    *param_3 = &PTR_LAB_00474bac;
    *param_3 = &PTR_LAB_00475468;
    param_3[1] = *(undefined4 *)(param_1 + 0xc);
    if (param_3[1] != 0) {
      FUN_0042f330(param_3[1]);
      param_2 = extraout_EDX_01;
    }
    return CONCAT44(param_2,param_3);
  }
  local_14 = param_3;
  *param_3 = &PTR_LAB_00474bac;
  *param_3 = &PTR_LAB_00475468;
  param_3[1] = param_1;
  if (param_3[1] != 0) {
    FUN_0042f330(param_3[1]);
    param_3 = extraout_EDX_02;
  }
  return CONCAT44(param_3,local_14);
}


