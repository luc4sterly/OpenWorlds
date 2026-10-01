// 10010270 RwVertexExt [Global]
// program: RWL21.DLL

int RwVertexExt(float param_1,float param_2,float param_3,float *param_4,float *param_5)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  float local_18;
  float local_14;
  float local_10;
  float local_c [3];
  
                    /* 0x10270  524  RwVertexExt */
  iVar3 = *(int *)(DAT_1005dfcc + 0x1c);
  if (iVar3 == 0) {
    FUN_1000cba0(0x27);
    return 0;
  }
  if (param_4 == (float *)0x0) {
    if (iVar3 == 0) {
      iVar2 = 0;
      FUN_1000cba0(0x27);
    }
    else {
      iVar3 = **(int **)(iVar3 + 0x94);
      local_18 = param_1;
      local_14 = param_2;
      local_10 = param_3;
      pfVar1 = (float *)FUN_1001d770();
      RwTransformPoint(&local_18,pfVar1);
      iVar2 = FUN_10004a90(iVar3,local_18,local_14,local_10);
      if (iVar2 == 0) {
        return 0;
      }
      iVar3 = FUN_10041c90(*(int *)(iVar3 + 0x88),iVar2);
      *(byte *)(iVar3 + 0x48) = *(byte *)(iVar3 + 0x48) | 0x20;
    }
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    iVar3 = **(int **)(iVar3 + 0x94);
    local_18 = param_1;
    local_14 = param_2;
    local_10 = param_3;
    pfVar1 = (float *)FUN_1001d770();
    RwTransformPoint(&local_18,pfVar1);
    iVar2 = FUN_10004a90(iVar3,local_18,local_14,local_10);
    if (iVar2 == 0) {
      return 0;
    }
    iVar3 = FUN_10041c90(*(int *)(iVar3 + 0x88),iVar2);
    *(byte *)(iVar3 + 0x48) = *(byte *)(iVar3 + 0x48) | 0x20;
    if (iVar2 < 1) {
      return 0;
    }
    iVar3 = RwSetClumpVertexUV(**(int **)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94),iVar2,*param_4,
                               param_4[1]);
    if (iVar3 == 0) {
      return 0;
    }
  }
  if (param_5 != (float *)0x0) {
    pfVar1 = (float *)FUN_1001d770();
    FUN_1001e660(local_c,param_5,pfVar1);
    iVar3 = RwSetClumpVertexNormal(**(int **)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94),iVar2,local_c);
    if (iVar3 == 0) {
      return 0;
    }
  }
  iVar3 = FUN_10041c90(*(int *)(**(int **)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94) + 0x88),iVar2);
  *(byte *)(iVar3 + 0x48) = *(byte *)(iVar3 + 0x48) | 0x20;
  return iVar2;
}


