// 0043b950 FUN_0043b950 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall
FUN_0043b950(int param_1,undefined4 *param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 *puStack_18;
  undefined4 *puStack_14;
  
  FUN_00427c50(&iStack_20,(int *)(param_1 + 0x18),param_4);
  *(int *)(param_1 + 0x18) = iStack_20;
  *(undefined4 *)(param_1 + 0x1c) = uStack_1c;
  *(short *)(param_1 + 0x14) =
       (short)(int)ROUND(((float10)*(uint *)(param_1 + 0x18) +
                         (float10)*(uint *)(param_1 + 0x1c) / (float10)DAT_00472020) *
                         (float10)_DAT_00476ec8);
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(short *)(iVar1 + 0x228) < *(short *)(param_1 + 0x14)) {
    if (*(int *)(param_1 + 0x10) == 2) {
      *(short *)(param_1 + 0x14) =
           *(short *)(param_1 + 0x14) % (short)(*(short *)(iVar1 + 0x228) + 1);
    }
    else {
      if (*(int *)(param_1 + 0x10) != 1) {
        puStack_18 = param_2;
        *param_2 = &PTR_LAB_00474bac;
        *param_2 = &PTR_LAB_00475fac;
        param_2[1] = 0;
        if (param_2[1] != 0) {
          FUN_0042f330(param_2[1]);
        }
        return puStack_18;
      }
      *(undefined2 *)(param_1 + 0x14) = *(undefined2 *)(iVar1 + 0x228);
    }
  }
  puStack_14 = param_2;
  *param_2 = &PTR_LAB_00474bac;
  *param_2 = &PTR_LAB_00475fac;
  param_2[1] = param_1;
  if (param_2[1] != 0) {
    FUN_0042f330(param_2[1]);
  }
  return puStack_14;
}


