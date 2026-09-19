// 10008ab0 RwGetClumpLocalBBox [Global]
// programa: RWL21.DLL

int RwGetClumpLocalBBox(int param_1,float *param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
                    /* 0x8ab0  156  RwGetClumpLocalBBox */
  if (((param_1 != 0) && (param_2 != (float *)0x0)) && (param_3 != (float *)0x0)) {
    iVar3 = *(int *)(param_1 + 0x88);
    if (8 < *(int *)(iVar3 + 8)) {
      *param_2 = *(float *)(iVar3 + 0xc);
      param_2[1] = *(float *)(iVar3 + 0x10);
      param_2[2] = *(float *)(iVar3 + 0x14);
      *param_3 = *(float *)(iVar3 + 0xc);
      param_3[1] = *(float *)(iVar3 + 0x10);
      iVar4 = 0x74;
      param_3[2] = *(float *)(iVar3 + 0x14);
      do {
        fVar2 = *(float *)(*(int *)(param_1 + 0x88) + 0xc + iVar4);
        pfVar1 = (float *)(*(int *)(param_1 + 0x88) + 0xc + iVar4);
        if (*param_2 <= fVar2) {
          fVar2 = *param_2;
        }
        *param_2 = fVar2;
        fVar2 = *pfVar1;
        if (*pfVar1 <= *param_3) {
          fVar2 = *param_3;
        }
        *param_3 = fVar2;
        fVar2 = pfVar1[1];
        if (param_2[1] <= pfVar1[1]) {
          fVar2 = param_2[1];
        }
        param_2[1] = fVar2;
        fVar2 = pfVar1[1];
        if (pfVar1[1] <= param_3[1]) {
          fVar2 = param_3[1];
        }
        param_3[1] = fVar2;
        fVar2 = pfVar1[2];
        if (param_2[2] <= pfVar1[2]) {
          fVar2 = param_2[2];
        }
        param_2[2] = fVar2;
        fVar2 = pfVar1[2];
        if (pfVar1[2] <= param_3[2]) {
          fVar2 = param_3[2];
        }
        param_3[2] = fVar2;
        iVar4 = iVar4 + 0x74;
      } while (iVar4 < 0x3a0);
      return param_1;
    }
    *param_3 = 0.0;
    *param_2 = 0.0;
    param_3[1] = 0.0;
    param_2[1] = 0.0;
    param_3[2] = 0.0;
    param_2[2] = 0.0;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


