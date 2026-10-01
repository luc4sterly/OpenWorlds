// 0043a290 FUN_0043a290 [Global]
// program: gamma.dll

undefined4 * __thiscall FUN_0043a290(int *param_1,undefined4 *param_2)

{
  float fVar1;
  int *piVar2;
  float10 fVar3;
  undefined **ppuStack_40;
  undefined4 *puStack_3c;
  undefined **ppuStack_38;
  undefined4 *puStack_34;
  undefined **ppuStack_30;
  undefined4 *puStack_2c;
  undefined **ppuStack_28;
  undefined4 *puStack_24;
  undefined **ppuStack_20;
  undefined4 *puStack_1c;
  undefined **ppuStack_18;
  undefined4 *puStack_14;
  
  fVar3 = (float10)(**(code **)(*param_1 + 0x10))();
  fVar1 = (float)fVar3;
  piVar2 = (int *)param_1[3];
  if (piVar2 != (int *)0x0) {
    if (param_1[5] == 0) {
      (**(code **)(*piVar2 + 8))(&ppuStack_30);
      FUN_0043bc20(&ppuStack_28);
      FUN_0043bde0(param_2,(int)&ppuStack_30,(int)&ppuStack_28,fVar1);
      ppuStack_28 = &PTR_LAB_00475438;
      if (puStack_24 != (undefined4 *)0x0) {
        FUN_0042f340(puStack_24);
      }
      FUN_0042f320(&ppuStack_28);
      ppuStack_30 = &PTR_LAB_00475438;
      if (puStack_2c != (undefined4 *)0x0) {
        FUN_0042f340(puStack_2c);
      }
      FUN_0042f320(&ppuStack_30);
      return param_2;
    }
    (**(code **)(*piVar2 + 8))(&ppuStack_20);
    (**(code **)(*(int *)param_1[5] + 8))(&ppuStack_18);
    FUN_0043bde0(param_2,(int)&ppuStack_20,(int)&ppuStack_18,fVar1);
    ppuStack_18 = &PTR_LAB_00475438;
    if (puStack_14 != (undefined4 *)0x0) {
      FUN_0042f340(puStack_14);
    }
    FUN_0042f320(&ppuStack_18);
    ppuStack_20 = &PTR_LAB_00475438;
    if (puStack_1c != (undefined4 *)0x0) {
      FUN_0042f340(puStack_1c);
    }
    FUN_0042f320(&ppuStack_20);
    return param_2;
  }
  if (param_1[5] == 0) {
    FUN_0043bc20(param_2);
    return param_2;
  }
  FUN_0043bc20(&ppuStack_40);
  (**(code **)(*(int *)param_1[5] + 8))(&ppuStack_38);
  FUN_0043bde0(param_2,(int)&ppuStack_40,(int)&ppuStack_38,fVar1);
  ppuStack_38 = &PTR_LAB_00475438;
  if (puStack_34 != (undefined4 *)0x0) {
    FUN_0042f340(puStack_34);
  }
  FUN_0042f320(&ppuStack_38);
  ppuStack_40 = &PTR_LAB_00475438;
  if (puStack_3c != (undefined4 *)0x0) {
    FUN_0042f340(puStack_3c);
  }
  FUN_0042f320(&ppuStack_40);
  return param_2;
}


