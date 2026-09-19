// 10006450 FUN_10006450 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_10006450(int param_1,float *param_2,int param_3,float *param_4,float *param_5,
                 float *param_6,float *param_7,float *param_8)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  float local_28;
  float local_24;
  float local_20;
  
  uVar13 = 0;
  fVar1 = *(float *)(param_3 + 0x2b8);
  fVar2 = *(float *)(param_3 + 0x74);
  fVar3 = *(float *)(param_3 + 700);
  fVar4 = *(float *)(param_3 + 0x78);
  fVar5 = *(float *)(param_3 + 0x2c0);
  fVar6 = *(float *)(param_3 + 0x7c);
  fVar7 = param_2[2];
  fVar8 = param_2[6];
  fVar9 = param_2[10];
  fVar10 = param_2[0xe];
  fVar11 = fVar2;
  fVar12 = fVar1;
  if (0x80000000 < (uint)fVar7) {
    fVar11 = fVar1;
    fVar12 = fVar2;
  }
  *param_8 = fVar12 * fVar7;
  param_8[1] = fVar11 * fVar7;
  if ((uint)fVar8 < 0x80000001) {
    fVar7 = fVar3 * fVar8 + *param_8;
    fVar12 = fVar4;
  }
  else {
    fVar7 = fVar4 * fVar8 + *param_8;
    fVar12 = fVar3;
  }
  *param_8 = fVar7;
  param_8[1] = fVar12 * fVar8 + param_8[1];
  if ((uint)fVar9 < 0x80000001) {
    fVar7 = fVar5 * fVar9 + *param_8;
    fVar8 = fVar6;
  }
  else {
    fVar7 = fVar6 * fVar9 + *param_8;
    fVar8 = fVar5;
  }
  *param_8 = fVar7;
  param_8[1] = fVar8 * fVar9 + param_8[1];
  *param_8 = *param_8 + fVar10;
  param_8[1] = param_8[1] + fVar10;
  if (param_8[1] < *(float *)(param_1 + 0x74)) {
    return 0x1000;
  }
  if (*param_8 < *(float *)(param_1 + 0x74)) {
    uVar13 = 0x10;
  }
  if (*(float *)(param_1 + 0x78) < *param_8) {
    return 0x2000;
  }
  if (*(float *)(param_1 + 0x78) < param_8[1]) {
    uVar13 = uVar13 | 0x20;
  }
  fVar7 = *param_2;
  fVar8 = param_2[4];
  fVar9 = param_2[8];
  fVar10 = param_2[0xc];
  fVar11 = fVar2;
  fVar12 = fVar1;
  if (0x80000000 < (uint)fVar7) {
    fVar11 = fVar1;
    fVar12 = fVar2;
  }
  *param_4 = fVar12 * fVar7;
  param_4[1] = fVar11 * fVar7;
  if ((uint)fVar8 < 0x80000001) {
    fVar7 = fVar3 * fVar8 + *param_4;
    fVar12 = fVar4;
  }
  else {
    fVar7 = fVar4 * fVar8 + *param_4;
    fVar12 = fVar3;
  }
  *param_4 = fVar7;
  param_4[1] = fVar12 * fVar8 + param_4[1];
  if ((uint)fVar9 < 0x80000001) {
    fVar7 = fVar5 * fVar9 + *param_4;
    fVar8 = fVar6;
  }
  else {
    fVar7 = fVar6 * fVar9 + *param_4;
    fVar8 = fVar5;
  }
  *param_4 = fVar7;
  param_4[1] = fVar8 * fVar9 + param_4[1];
  *param_4 = *param_4 + fVar10;
  param_4[1] = param_4[1] + fVar10;
  if (0x80000000 < (uint)param_4[1]) {
    return 0x100;
  }
  if (0x80000000 < (uint)*param_4) {
    uVar13 = uVar13 | 1;
  }
  fVar7 = param_2[1];
  fVar8 = param_2[5];
  fVar9 = param_2[9];
  fVar10 = param_2[0xd];
  fVar11 = fVar2;
  fVar12 = fVar1;
  if (0x80000000 < (uint)fVar7) {
    fVar11 = fVar1;
    fVar12 = fVar2;
  }
  *param_6 = fVar12 * fVar7;
  param_6[1] = fVar11 * fVar7;
  if ((uint)fVar8 < 0x80000001) {
    fVar7 = fVar3 * fVar8 + *param_6;
    fVar12 = fVar4;
  }
  else {
    fVar7 = fVar4 * fVar8 + *param_6;
    fVar12 = fVar3;
  }
  *param_6 = fVar7;
  param_6[1] = fVar12 * fVar8 + param_6[1];
  if ((uint)fVar9 < 0x80000001) {
    fVar7 = fVar5 * fVar9 + *param_6;
    fVar8 = fVar6;
  }
  else {
    fVar7 = fVar6 * fVar9 + *param_6;
    fVar8 = fVar5;
  }
  *param_6 = fVar7;
  param_6[1] = fVar8 * fVar9 + param_6[1];
  *param_6 = *param_6 + fVar10;
  param_6[1] = param_6[1] + fVar10;
  if (0x80000000 < (uint)param_6[1]) {
    return 0x400;
  }
  if (0x80000000 < (uint)*param_6) {
    uVar13 = uVar13 | 4;
  }
  if (*(int *)(param_1 + 0x218) == 1) {
    local_28 = param_2[2] - *param_2;
    local_24 = param_2[6] - param_2[4];
    local_20 = param_2[10] - param_2[8];
    fVar7 = param_2[0xe];
  }
  else {
    local_28 = -*param_2;
    local_24 = -param_2[4];
    local_20 = -param_2[8];
    fVar7 = _DAT_10052088;
  }
  fVar8 = param_2[0xc];
  fVar10 = fVar2;
  fVar9 = fVar1;
  if (0x80000000 < (uint)local_28) {
    fVar10 = fVar1;
    fVar9 = fVar2;
  }
  *param_5 = fVar9 * local_28;
  param_5[1] = fVar10 * local_28;
  if ((uint)local_24 < 0x80000001) {
    fVar9 = fVar3 * local_24 + *param_5;
    fVar10 = fVar4;
  }
  else {
    fVar9 = fVar4 * local_24 + *param_5;
    fVar10 = fVar3;
  }
  *param_5 = fVar9;
  param_5[1] = fVar10 * local_24 + param_5[1];
  if ((uint)local_20 < 0x80000001) {
    fVar9 = fVar5 * local_20 + *param_5;
    fVar10 = fVar6;
  }
  else {
    fVar9 = fVar6 * local_20 + *param_5;
    fVar10 = fVar5;
  }
  *param_5 = fVar9;
  param_5[1] = fVar10 * local_20 + param_5[1];
  *param_5 = *param_5 + (fVar7 - fVar8);
  param_5[1] = param_5[1] + (fVar7 - fVar8);
  if (0x80000000 < (uint)param_5[1]) {
    return 0x200;
  }
  if (0x80000000 < (uint)*param_5) {
    uVar13 = uVar13 | 2;
  }
  if (*(int *)(param_1 + 0x218) == 1) {
    local_28 = param_2[2] - param_2[1];
    local_24 = param_2[6] - param_2[5];
    local_20 = param_2[10] - param_2[9];
    fVar7 = param_2[0xe];
  }
  else {
    local_28 = -param_2[1];
    local_24 = -param_2[5];
    local_20 = -param_2[9];
    fVar7 = _DAT_10052088;
  }
  fVar8 = param_2[0xd];
  fVar9 = fVar2;
  if (0x80000000 < (uint)local_28) {
    fVar9 = fVar1;
    fVar1 = fVar2;
  }
  *param_7 = fVar1 * local_28;
  param_7[1] = fVar9 * local_28;
  if ((uint)local_24 < 0x80000001) {
    fVar2 = fVar3 * local_24 + *param_7;
  }
  else {
    fVar2 = fVar4 * local_24 + *param_7;
    fVar4 = fVar3;
  }
  *param_7 = fVar2;
  param_7[1] = fVar4 * local_24 + param_7[1];
  if ((uint)local_20 < 0x80000001) {
    fVar2 = fVar5 * local_20 + *param_7;
  }
  else {
    fVar2 = fVar6 * local_20 + *param_7;
    fVar6 = fVar5;
  }
  *param_7 = fVar2;
  param_7[1] = fVar6 * local_20 + param_7[1];
  *param_7 = *param_7 + (fVar7 - fVar8);
  param_7[1] = param_7[1] + (fVar7 - fVar8);
  if ((uint)param_7[1] < 0x80000001) {
    if (0x80000000 < (uint)*param_7) {
      uVar13 = uVar13 | 8;
    }
    return uVar13;
  }
  return 0x800;
}


