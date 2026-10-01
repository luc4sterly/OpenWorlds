// 004547f0 FUN_004547f0 [Global]
// program: gamma.dll

void __cdecl
FUN_004547f0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,int *param_5,
            uint param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = (&DAT_00482458)[param_4];
  uVar3 = (&DAT_00482458)[param_4] + 4;
  uVar1 = param_6 / uVar3;
  uVar2 = 0;
  piVar6 = param_5;
  if (uVar1 != 1) {
    if (8 < uVar1 - 1) {
      do {
        puVar5 = (undefined4 *)(uVar3 + (int)piVar6);
        *piVar6 = (int)param_1;
        piVar6[1] = (int)puVar5;
        puVar4 = (undefined4 *)((int)puVar5 + uVar3);
        *puVar5 = param_1;
        puVar5[1] = puVar4;
        puVar5 = (undefined4 *)((int)puVar4 + uVar3);
        *puVar4 = param_1;
        puVar4[1] = puVar5;
        puVar4 = (undefined4 *)((int)puVar5 + uVar3);
        *puVar5 = param_1;
        puVar5[1] = puVar4;
        puVar5 = (undefined4 *)((int)puVar4 + uVar3);
        *puVar4 = param_1;
        puVar4[1] = puVar5;
        puVar4 = (undefined4 *)((int)puVar5 + uVar3);
        *puVar5 = param_1;
        puVar5[1] = puVar4;
        puVar5 = (undefined4 *)((int)puVar4 + uVar3);
        *puVar4 = param_1;
        puVar4[1] = puVar5;
        piVar6 = (int *)((int)puVar5 + uVar3);
        *puVar5 = param_1;
        puVar5[1] = piVar6;
        uVar2 = uVar2 + 8;
      } while (uVar2 < uVar1 - 9);
    }
    piVar7 = piVar6;
    if (uVar2 < uVar1 - 1) {
      do {
        piVar6 = (int *)(uVar3 + (int)piVar7);
        *piVar7 = (int)param_1;
        piVar7[1] = (int)piVar6;
        uVar2 = uVar2 + 1;
        piVar7 = piVar6;
      } while (uVar2 < uVar1 - 1);
    }
  }
  *piVar6 = (int)param_1;
  piVar6[1] = (&DAT_0049edfc)[param_4 * 3];
  (&DAT_0049edfc)[param_4 * 3] = param_5;
  return;
}


