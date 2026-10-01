// 10018060 RwSetPolygonUV [Global]
// program: RWL21.DLL

int RwSetPolygonUV(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  
                    /* 0x18060  445  RwSetPolygonUV */
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar3 = 0;
    if (*(char *)(param_1 + 0x3a) != '\0') {
      piVar2 = (int *)(param_1 + 0x3c);
      pfVar4 = (float *)(param_2 + 4);
      do {
        fVar6 = *pfVar4;
        fVar5 = pfVar4[-1];
        iVar1 = FUN_10041c70(*(int *)(*(int *)(param_1 + 0x34) + 0x88),*piVar2);
        iVar1 = RwSetClumpVertexUV(*(int *)(param_1 + 0x34),iVar1,fVar5,fVar6);
        if (iVar1 == 0) {
          return 0;
        }
        piVar2 = piVar2 + 1;
        pfVar4 = pfVar4 + 2;
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x3a));
    }
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


