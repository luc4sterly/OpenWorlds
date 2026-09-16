// 00451dd0 FUN_00451dd0 [Global]
// programa: gamma.dll

undefined1
FUN_00451dd0(undefined4 param_1,undefined4 *param_2,int param_3,int *param_4,undefined4 *param_5,
            int param_6,int *param_7)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_3 - (int)param_2;
  if ((uVar3 & 1) != 0) {
    return 2;
  }
  uVar4 = (int)(((param_6 - (int)param_5) + 1U) -
               (uint)((uint)(param_6 - (int)param_5) < 0x80000000)) >> 1;
  uVar2 = 0;
  uVar1 = uVar4 * 2;
  if (uVar1 < uVar3) {
    uVar2 = 1;
    uVar3 = uVar1;
    if (uVar1 == 0) {
      return 2;
    }
  }
  else {
    uVar4 = uVar3 >> 1;
  }
  FUN_0044df50(param_5,param_2,uVar3);
  *param_4 = (int)param_2 + uVar3;
  *param_7 = uVar4 * 2 + (int)param_5;
  return uVar2;
}


