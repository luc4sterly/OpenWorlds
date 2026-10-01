// 10004bc0 FUN_10004bc0 [Global]
// program: RWL21.DLL

uint FUN_10004bc0(uint param_1,float *param_2)

{
  float *pfVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  float *pfVar4;
  int iVar5;
  int *piVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int local_1c;
  float local_10;
  float local_c;
  float local_8;
  int local_4;
  
  pfVar7 = (float *)0x0;
  local_4 = 0;
  if ((param_1 == 0) || (pfVar4 = param_2, param_2 == (float *)0x0)) {
    FUN_1000cba0(1);
    return 0;
  }
  do {
    if ((*(char *)((int)pfVar4 + 0x12d) != '\0') || (*(char *)((int)pfVar4 + 0x171) != '\0')) {
      pfVar7 = pfVar4;
    }
    pfVar1 = pfVar4 + 0x5d;
    pfVar4 = (float *)*pfVar1;
  } while ((float *)*pfVar1 != (float *)0x0);
  if (pfVar7 != (float *)0x0) {
    FUN_10004700(0,pfVar7,pfVar7);
  }
  local_1c = 8;
  if (8 < *(int *)((int)param_2[0x22] + 8)) {
    iVar9 = 0x3a0;
    do {
      local_10 = *(float *)((int)param_2[0x22] + 0xc + iVar9);
      local_c = *(float *)((int)param_2[0x22] + 0x10 + iVar9);
      local_8 = *(float *)((int)param_2[0x22] + 0x14 + iVar9);
      RwTransformPoint(&local_10,param_2);
      iVar5 = FUN_100424f0(*(int **)(param_1 + 0x88),local_10,local_c,local_8);
      if (iVar5 == 0) {
        return 0;
      }
      if (iVar9 == 0x3a0) {
        local_4 = iVar5;
      }
      iVar5 = iVar5 * 0x74;
      iVar8 = *(int *)(param_1 + 0x88) + iVar5;
      uVar2 = *(undefined4 *)((int)param_2[0x22] + iVar9 + 0x74);
      *(undefined4 *)(iVar8 + 0x39c) = *(undefined4 *)((int)param_2[0x22] + iVar9 + 0x70);
      *(undefined4 *)(iVar8 + 0x3a0) = uVar2;
      *(byte *)(*(int *)(param_1 + 0x88) + 0x380 + iVar5) =
           *(byte *)(*(int *)(param_1 + 0x88) + 0x380 + iVar5) |
           *(byte *)((int)param_2[0x22] + 0x54 + iVar9) & 0x80;
      if ((*(byte *)((int)param_2[0x22] + 0x54 + iVar9) & 0x40) != 0) {
        *(byte *)(*(int *)(param_1 + 0x88) + 0x380 + iVar5) =
             *(byte *)(*(int *)(param_1 + 0x88) + 0x380 + iVar5) | 0x40;
        iVar8 = (int)param_2[0x22] + iVar9;
        local_10 = *(float *)(iVar8 + 0x58);
        local_c = *(float *)(iVar8 + 0x5c);
        local_8 = *(float *)(iVar8 + 0x60);
        FUN_1001e660(&local_10,&local_10,param_2);
        iVar5 = *(int *)(param_1 + 0x88) + iVar5;
        *(float *)(iVar5 + 900) = local_10;
        *(float *)(iVar5 + 0x388) = local_c;
        *(float *)(iVar5 + 0x38c) = local_8;
      }
      iVar9 = iVar9 + 0x74;
      local_1c = local_1c + 1;
    } while (local_1c < *(int *)((int)param_2[0x22] + 8));
  }
  *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + 1;
  if (param_1 == 0) {
    FUN_1000cba0(1);
    local_1c = 0;
    FUN_1000cba0(1);
  }
  else {
    local_1c = *(undefined4 *)(param_1 + 0xb0);
    *(int **)(param_1 + 0xb0) = &local_4;
  }
  if (param_2 == (float *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    piVar6 = FUN_10003930((int)param_2);
    if (piVar6 != (int *)0x0) {
      piVar10 = piVar6 + 2;
      iVar9 = *piVar6;
      iVar5 = RwGetError();
      do {
        if (iVar9 == 0) {
          FUN_10020be0(piVar6);
          FUN_1000cb60(iVar5);
          goto LAB_10004e69;
        }
        puVar3 = (undefined4 *)*piVar10;
        piVar10 = piVar10 + 1;
        FUN_10004ee0(puVar3,param_1);
        iVar8 = FUN_1000cbd0();
        iVar9 = iVar9 + -1;
      } while (iVar8 == 0);
      FUN_10020be0(piVar6);
      if (iVar5 != 0) {
        FUN_1000cb60(iVar5);
      }
    }
  }
  param_2 = (float *)0x0;
LAB_10004e69:
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    *(int *)(param_1 + 0xb0) = local_1c;
  }
  *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + -1;
  if (param_2 == (float *)0x0) {
    return 0;
  }
  iVar9 = FUN_100329e0(param_1);
  return (iVar9 == 0) - 1 & param_1;
}


