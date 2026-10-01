// 100088d0 FUN_100088d0 [Global]
// program: RWL21.DLL

void FUN_100088d0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float local_c;
  float local_8;
  float local_4;
  
  fVar1 = param_1[0x22];
  if (8 < *(int *)((int)fVar1 + 8)) {
    local_c = *(float *)((int)fVar1 + 0xc);
    local_8 = *(float *)((int)fVar1 + 0x10);
    local_4 = *(float *)((int)fVar1 + 0x14);
    RwTransformPoint(&local_c,param_1);
    *param_2 = local_c;
    iVar3 = 0x74;
    param_2[1] = local_8;
    param_2[2] = local_4;
    *param_3 = local_c;
    param_3[1] = local_8;
    param_3[2] = local_4;
    do {
      iVar2 = (int)param_1[0x22] + iVar3;
      local_c = *(float *)(iVar2 + 0xc);
      local_8 = *(float *)(iVar2 + 0x10);
      local_4 = *(float *)(iVar2 + 0x14);
      RwTransformPoint(&local_c,param_1);
      fVar1 = *param_2;
      if (local_c <= *param_2) {
        fVar1 = local_c;
      }
      *param_2 = fVar1;
      fVar1 = *param_3;
      if (*param_3 <= local_c) {
        fVar1 = local_c;
      }
      *param_3 = fVar1;
      fVar1 = param_2[1];
      if (local_8 <= param_2[1]) {
        fVar1 = local_8;
      }
      param_2[1] = fVar1;
      fVar1 = param_3[1];
      if (param_3[1] <= local_8) {
        fVar1 = local_8;
      }
      param_3[1] = fVar1;
      fVar1 = param_2[2];
      if (local_4 <= param_2[2]) {
        fVar1 = local_4;
      }
      param_2[2] = fVar1;
      fVar1 = param_3[2];
      if (param_3[2] <= local_4) {
        fVar1 = local_4;
      }
      param_3[2] = fVar1;
      iVar3 = iVar3 + 0x74;
    } while (iVar3 < 0x3a0);
    return;
  }
  fVar1 = param_1[0xc];
  *param_3 = fVar1;
  *param_2 = fVar1;
  fVar1 = param_1[0xd];
  param_3[1] = fVar1;
  param_2[1] = fVar1;
  fVar1 = param_1[0xe];
  param_3[2] = fVar1;
  param_2[2] = fVar1;
  return;
}


