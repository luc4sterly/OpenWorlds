// 10020490 RwDuplicateSpline [Global]
// programa: RWL21.DLL

int * RwDuplicateSpline(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  
                    /* 0x20490  79  RwDuplicateSpline */
  if (param_1 == (int *)0x0) {
    FUN_1000cba0(1);
    return (int *)0x0;
  }
  piVar1 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(*param_1 * 0xc + 0x10);
  if (piVar1 == (int *)0x0) {
    FUN_1000cba0(3);
    return (int *)0x0;
  }
  if (param_1 == (int *)0x0) {
    iVar7 = 1;
  }
  else {
    if (param_1[1] == 1) {
      iVar7 = *param_1 + -2;
      goto LAB_100204f7;
    }
    if (param_1[1] == 2) {
      iVar7 = *param_1 + -3;
      goto LAB_100204f7;
    }
    iVar7 = 0x11;
  }
  FUN_1000cba0(iVar7);
  iVar7 = 0;
LAB_100204f7:
  *piVar1 = *param_1;
  piVar1[1] = param_1[1];
  piVar1[2] = param_1[2];
  piVar4 = param_1 + 4;
  piVar6 = piVar1 + 4;
  for (uVar3 = (uint)(*param_1 * 0xc) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *piVar6 = *piVar4;
    piVar4 = piVar4 + 1;
    piVar6 = piVar6 + 1;
  }
  puVar2 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(iVar7 * 0xc);
  piVar1[3] = (int)puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
    return (int *)0x0;
  }
  puVar5 = (undefined4 *)param_1[3];
  for (uVar3 = (uint)(iVar7 * 0xc) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar2 = puVar2 + 1;
  }
  for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined1 *)puVar2 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  return piVar1;
}


