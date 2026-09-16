// 00410d70 FUN_00410d70 [Global]
// programa: gamma.dll

uint __thiscall FUN_00410d70(int *param_1,undefined4 *param_2,uint param_3)

{
  byte *pbVar1;
  uint uVar2;
  uint *puVar3;
  uint uStack_18;
  uint uStack_14;
  
  uStack_14 = param_1[3] - param_1[2];
  if (param_1[3] - param_1[2] < (int)param_3) {
    puVar3 = &uStack_14;
  }
  else {
    puVar3 = &param_3;
  }
  uStack_18 = *puVar3;
  if (0 < (int)uStack_18) {
    FUN_0044df50(param_2,(undefined4 *)param_1[2],uStack_18);
    param_1[2] = param_1[2] + uStack_18;
    param_3 = param_3 - uStack_18;
    param_2 = (undefined4 *)((int)param_2 + uStack_18);
  }
  while( true ) {
    if ((int)param_3 < 1) {
      return uStack_18;
    }
    if ((uint)param_1[2] < (uint)param_1[3]) {
      pbVar1 = (byte *)param_1[2];
      param_1[2] = param_1[2] + 1;
      uVar2 = (uint)*pbVar1;
    }
    else {
      uVar2 = (**(code **)(*param_1 + 0x24))();
    }
    if (uVar2 == 0xffffffff) break;
    *(char *)param_2 = (char)uVar2;
    param_3 = param_3 - 1;
    uStack_18 = uStack_18 + 1;
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  return uStack_18;
}


