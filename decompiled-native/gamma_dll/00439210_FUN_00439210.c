// 00439210 FUN_00439210 [Global]
// program: gamma.dll

void __cdecl FUN_00439210(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (param_1 != param_2) {
    for (; param_1 < param_2 + -2; param_1 = param_1 + 2) {
      puVar6 = param_1;
      puVar5 = param_1;
      if (param_1 != param_2) {
        while (puVar4 = puVar5 + 2, puVar4 != param_2) {
          piVar1 = puVar5 + 3;
          puVar5 = puVar4;
          if (*piVar1 < (int)puVar6[1]) {
            puVar6 = puVar4;
          }
        }
      }
      if (puVar6 != param_1) {
        uVar2 = *puVar6;
        uVar3 = puVar6[1];
        *puVar6 = *param_1;
        puVar6[1] = param_1[1];
        *param_1 = uVar2;
        param_1[1] = uVar3;
      }
    }
  }
  return;
}


