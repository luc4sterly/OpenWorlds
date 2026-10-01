// 0044df50 FUN_0044df50 [Global]
// program: gamma.dll

undefined4 * __cdecl FUN_0044df50(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
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
  return param_1;
}


