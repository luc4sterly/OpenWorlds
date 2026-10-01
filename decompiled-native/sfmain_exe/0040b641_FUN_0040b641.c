// 0040b641 FUN_0040b641 [Global]
// program: sfmain.exe

void FUN_0040b641(int *param_1,uint *param_2,int *param_3)

{
  int in_EAX;
  uint uVar1;
  int extraout_ECX;
  int extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_EDX;
  int iVar2;
  int *piVar3;
  int iVar4;
  bool bVar5;
  float10 fVar6;
  int local_1c;
  int local_18;
  int local_14;
  
  fVar6 = FUN_0042b8ce();
  iVar2 = extraout_ECX + 4;
  *param_2 = (int)ROUND(fVar6);
  piVar3 = param_3;
  do {
    piVar3 = piVar3 + 1;
    fVar6 = FUN_0042b8ce();
    iVar2 = iVar2 + 4;
    *piVar3 = (int)ROUND(fVar6);
  } while (iVar2 != extraout_ECX_00);
  if ((*(int *)(in_EAX + 4) == 0) || (*(int *)(in_EAX + 8) == 0)) {
    *param_1 = 0;
  }
  else {
    *param_1 = *(int *)(&DAT_00438934 + *extraout_EDX * 4);
  }
  if (*(int *)(in_EAX + 4) != *(int *)(in_EAX + 8)) {
    *param_1 = 0x7f;
  }
  uVar1 = *param_2;
  local_18 = 0x20;
  local_1c = 0x10;
  if (0x3fe < (int)uVar1) {
    uVar1 = 0x3ff;
  }
  *param_2 = uVar1;
  while (0 < local_1c) {
    if ((int)(&DAT_00438b84)[local_18] < (int)*param_2) {
      local_18 = local_18 - local_1c;
    }
    if ((int)*param_2 < (int)(&DAT_00438b84)[local_18]) {
      local_18 = local_18 + local_1c;
    }
    fVar6 = FUN_0042b8ce();
    local_1c = (int)ROUND(fVar6);
  }
  piVar3 = param_3 + 1;
  fVar6 = FUN_0042b8ce();
  *param_2 = (int)ROUND(fVar6);
  do {
    iVar2 = *piVar3;
    bVar5 = iVar2 < 0;
    if (bVar5) {
      iVar2 = -iVar2;
    }
    iVar2 = iVar2 >> 9;
    if (0x3e < iVar2) {
      iVar2 = 0x3f;
    }
    iVar2 = *(int *)(&DAT_00438a88 + iVar2 * 4);
    if (bVar5) {
      iVar2 = -iVar2;
    }
    *piVar3 = iVar2;
    piVar3 = piVar3 + 1;
  } while (piVar3 != extraout_ECX_01);
  iVar2 = 0x1c;
  piVar3 = param_3 + 3;
  do {
    if (*(int *)(iVar2 + 0x438a28) < 0) {
      fVar6 = FUN_0042b8ce();
      local_14 = -(int)ROUND(fVar6);
    }
    else {
      fVar6 = FUN_0042b8ce();
      local_14 = (int)ROUND(fVar6);
    }
    if ((local_14 < -0x7f) || (0x7f < local_14)) {
      if (local_14 < -0x7f) {
        local_14 = -0x7f;
      }
      else if (0x7f < local_14) {
        local_14 = 0x7f;
      }
    }
    iVar4 = 0;
    if (local_14 < 0) {
      iVar4 = -1;
    }
    local_14 = local_14 / (2 << ((char)*(undefined4 *)(iVar2 + 0x438a68) - 1U & 0x1f));
    if (iVar4 == -1) {
      local_14 = local_14 + -1;
    }
    iVar2 = iVar2 + -4;
    *piVar3 = local_14;
    piVar3 = piVar3 + 1;
  } while (iVar2 != -4);
  if ((*param_1 == 0) || (*param_1 == 0x7f)) {
    param_3[5] = *(int *)(&DAT_004388f8 + ((int)(param_3[1] & 0x1eU) >> 1) * 4);
    param_3[6] = *(int *)(&DAT_004388f8 + ((int)(param_3[2] & 0x1eU) >> 1) * 4);
    param_3[7] = *(int *)(&DAT_004388f8 + ((int)(param_3[3] & 0x1eU) >> 1) * 4);
    param_3[8] = *(int *)(&DAT_004388f8 + ((int)(*param_2 & 0x1e) >> 1) * 4);
    param_3[9] = *(int *)(&DAT_004388f8 + ((int)(param_3[4] & 0x1eU) >> 1) * 4) >> 1;
    param_3[10] = *(uint *)(&DAT_004388f8 + ((int)(param_3[4] & 0x1eU) >> 1) * 4) & 1;
  }
  return;
}


