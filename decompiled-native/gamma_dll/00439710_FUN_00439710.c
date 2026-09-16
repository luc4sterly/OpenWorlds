// 00439710 FUN_00439710 [Global]
// programa: gamma.dll

undefined4 * __thiscall
FUN_00439710(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined **ppuStack_1c;
  undefined4 *puStack_18;
  undefined4 *puStack_14;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    uStack_24 = *param_4;
    uStack_20 = param_4[1];
    (**(code **)(**(int **)(param_1 + 0xc) + 8))(&ppuStack_1c,param_3,&uStack_24);
    FUN_0043b240((void *)(param_1 + 8),(int)&ppuStack_1c);
    ppuStack_1c = &PTR_LAB_00475fac;
    if (puStack_18 != (undefined4 *)0x0) {
      FUN_0042f340(puStack_18);
    }
    FUN_0042f320(&ppuStack_1c);
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    puStack_14 = param_2;
    *param_2 = &PTR_LAB_00474bac;
    *param_2 = &PTR_LAB_00475468;
    param_2[1] = param_1;
    if (param_2[1] != 0) {
      FUN_0042f330(param_2[1]);
    }
    return puStack_14;
  }
  *param_2 = &PTR_LAB_00474bac;
  *param_2 = &PTR_LAB_00475468;
  param_2[1] = 0;
  return param_2;
}


