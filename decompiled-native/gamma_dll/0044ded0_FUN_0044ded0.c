// 0044ded0 FUN_0044ded0 [Global]
// programa: gamma.dll

undefined4 * __cdecl FUN_0044ded0(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  
  if (param_2 < param_1) {
    puVar4 = (undefined1 *)((int)param_2 + (param_3 - 1));
    puVar6 = (undefined1 *)((int)param_1 + (param_3 - 1));
    uVar1 = param_3;
    if (0xf < (int)param_3) {
      uVar1 = (uint)(puVar6 + -3) & 3;
      if (uVar1 != 0) {
        param_3 = param_3 - uVar1;
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar6 = *puVar4;
          puVar4 = puVar4 + -1;
          puVar6 = puVar6 + -1;
        }
      }
      uVar1 = param_3 & 3;
      puVar3 = (undefined4 *)(puVar4 + -3);
      puVar5 = (undefined4 *)(puVar6 + -3);
      for (uVar2 = param_3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + -1;
        puVar5 = puVar5 + -1;
      }
      if (uVar1 == 0) {
        return param_1;
      }
      puVar4 = (undefined1 *)((int)puVar3 + 3);
      puVar6 = (undefined1 *)((int)puVar5 + 3);
    }
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + -1;
      puVar6 = puVar6 + -1;
    }
  }
  else {
    uVar1 = param_3;
    puVar3 = param_1;
    if (0xf < (int)param_3) {
      uVar1 = -(int)param_1 & 3;
      if (uVar1 != 0) {
        param_3 = param_3 - uVar1;
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *(undefined1 *)puVar3 = *(undefined1 *)param_2;
          param_2 = (undefined4 *)((int)param_2 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + 1);
        }
      }
      uVar1 = param_3 & 3;
      for (uVar2 = param_3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      if (uVar1 == 0) {
        return param_1;
      }
    }
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  return param_1;
}


