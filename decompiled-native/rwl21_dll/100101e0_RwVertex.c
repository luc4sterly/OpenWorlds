// 100101e0 RwVertex [Global]
// program: RWL21.DLL

int RwVertex(float param_1,float param_2,float param_3)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  float local_c;
  float local_8;
  float local_4;
  
                    /* 0x101e0  523  RwVertex */
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return 0;
  }
  local_c = param_1;
  iVar3 = **(int **)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94);
  local_4 = param_3;
  local_8 = param_2;
  pfVar1 = (float *)FUN_1001d770();
  RwTransformPoint(&local_c,pfVar1);
  iVar2 = FUN_10004a90(iVar3,local_c,local_8,local_4);
  if (iVar2 != 0) {
    iVar3 = FUN_10041c90(*(int *)(iVar3 + 0x88),iVar2);
    *(byte *)(iVar3 + 0x48) = *(byte *)(iVar3 + 0x48) | 0x20;
  }
  return iVar2;
}


