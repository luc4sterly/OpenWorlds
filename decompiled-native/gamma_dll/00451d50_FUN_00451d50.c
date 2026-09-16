// 00451d50 FUN_00451d50 [Global]
// programa: gamma.dll

undefined1
FUN_00451d50(undefined4 param_1,undefined4 *param_2,int param_3,int *param_4,undefined4 *param_5,
            int param_6,int *param_7)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (int)(((param_3 - (int)param_2) + 1U) -
               (uint)((uint)(param_3 - (int)param_2) < 0x80000000)) >> 1;
  uVar2 = uVar3 * 2;
  uVar1 = 0;
  if ((uint)(param_6 - (int)param_5) < uVar2) {
    uVar1 = 1;
    uVar3 = (uint)(param_6 - (int)param_5) >> 1;
    if (uVar3 == 0) {
      return 2;
    }
    uVar2 = uVar3 * 2;
  }
  FUN_0044df50(param_5,param_2,uVar2);
  *param_4 = uVar3 * 2 + (int)param_2;
  *param_7 = (int)param_5 + uVar2;
  return uVar1;
}


