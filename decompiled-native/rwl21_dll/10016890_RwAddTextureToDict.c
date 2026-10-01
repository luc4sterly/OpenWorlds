// 10016890 RwAddTextureToDict [Global]
// program: RWL21.DLL

int * RwAddTextureToDict(char *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  
                    /* 0x16890  15  RwAddTextureToDict */
  piVar3 = *(int **)(DAT_1005abf4 + -4 + DAT_1005abfc * 4);
  piVar2 = (int *)*param_2;
  if (piVar2 == (int *)0x0) {
    iVar8 = 0;
    if ((param_1 != (char *)0x0) && (0 < piVar3[2])) {
      iVar11 = 0;
      do {
        if ((*(char **)(*piVar3 + iVar11) != (char *)0x0) &&
           (iVar5 = FUN_10043f20(param_1,*(char **)(*piVar3 + iVar11)), iVar5 != 0)) {
          if (iVar8 != -1) {
            FUN_1000cba0(0x69);
            return (int *)0x0;
          }
          break;
        }
        iVar11 = iVar11 + 8;
        iVar8 = iVar8 + 1;
      } while (iVar8 < piVar3[2]);
    }
    iVar8 = FUN_100169e0(piVar3,param_1,param_2);
    return (int *)((iVar8 == -1) - 1 & (uint)param_2);
  }
  iVar8 = 0;
  if (0 < piVar2[2]) {
    piVar3 = (int *)(*piVar2 + 4);
    do {
      if ((int *)*piVar3 == param_2) goto LAB_100168d3;
      piVar3 = piVar3 + 2;
      iVar8 = iVar8 + 1;
    } while (iVar8 < piVar2[2]);
  }
  iVar8 = -1;
LAB_100168d3:
  if ((iVar8 != -1) && (*(int *)(*piVar2 + iVar8 * 8) == 0)) {
    FUN_1000cba0(0x69);
    return (int *)0x0;
  }
  uVar6 = 0xffffffff;
  pcVar4 = param_1;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  pcVar4 = (char *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(~uVar6);
  uVar6 = 0xffffffff;
  if (pcVar4 != (char *)0x0) {
    do {
      pcVar9 = param_1;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar9 = param_1 + 1;
      cVar1 = *param_1;
      param_1 = pcVar9;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar9 = pcVar9 + -uVar6;
    pcVar10 = pcVar4;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar10 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar10 = pcVar10 + 1;
    }
    *(char **)(*(int *)*param_2 + iVar8 * 8) = pcVar4;
    return param_2;
  }
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  FUN_1000cba0(3);
  return (int *)0x0;
}


