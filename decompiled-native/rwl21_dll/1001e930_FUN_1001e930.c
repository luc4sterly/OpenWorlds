// 1001e930 FUN_1001e930 [Global]
// program: RWL21.DLL

uint FUN_1001e930(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar2 = param_1[2] + *param_1;
  iVar6 = param_1[1];
  iVar5 = param_1[3] + iVar6;
  iVar1 = param_2[1];
  local_14 = *param_2;
  local_c = param_2[2];
  local_8 = param_2[3];
  local_10 = iVar1;
  if (iVar1 < iVar6) {
    *param_3 = local_14;
    param_3[1] = iVar1;
    param_3[2] = local_c;
    param_3[3] = local_8;
    local_8 = local_8 - (param_1[1] - iVar1);
    param_3[3] = param_1[1] - iVar1;
    local_10 = param_1[1];
  }
  uVar3 = (uint)(iVar1 < iVar6);
  if (iVar5 < local_10 + local_8) {
    piVar4 = param_3 + uVar3 * 4;
    *piVar4 = local_14;
    piVar4[1] = local_10;
    piVar4[2] = local_c;
    piVar4[3] = local_8;
    piVar4[1] = iVar5;
    uVar3 = uVar3 + 1;
    iVar6 = (local_10 - iVar5) + local_8;
    local_8 = local_8 - iVar6;
    piVar4[3] = iVar6;
  }
  if (local_14 < *param_1) {
    piVar4 = param_3 + uVar3 * 4;
    *piVar4 = local_14;
    piVar4[1] = local_10;
    piVar4[2] = local_c;
    piVar4[3] = local_8;
    local_c = local_c - (*param_1 - local_14);
    uVar3 = uVar3 + 1;
    piVar4[2] = *param_1 - local_14;
    local_14 = *param_1;
  }
  if (iVar2 < local_c + local_14) {
    piVar4 = param_3 + uVar3 * 4;
    *piVar4 = local_14;
    piVar4[1] = local_10;
    piVar4[2] = local_c;
    uVar3 = uVar3 + 1;
    piVar4[3] = local_8;
    *piVar4 = iVar2;
    piVar4[2] = (local_c - iVar2) + local_14;
  }
  return uVar3;
}


