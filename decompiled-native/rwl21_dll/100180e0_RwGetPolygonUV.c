// 100180e0 RwGetPolygonUV [Global]
// program: RWL21.DLL

float * RwGetPolygonUV(int param_1,float *param_2)

{
  int iVar1;
  float *pfVar2;
  int *piVar3;
  int iVar4;
  float *pfVar5;
  
                    /* 0x180e0  230  RwGetPolygonUV */
  if ((param_1 != 0) && (param_2 != (float *)0x0)) {
    iVar4 = 0;
    if (*(char *)(param_1 + 0x3a) != '\0') {
      piVar3 = (int *)(param_1 + 0x3c);
      pfVar5 = param_2;
      do {
        pfVar2 = pfVar5;
        iVar1 = FUN_10041c70(*(int *)(*(int *)(param_1 + 0x34) + 0x88),*piVar3);
        pfVar2 = RwGetClumpVertexUV(*(int *)(param_1 + 0x34),iVar1,pfVar2);
        if (pfVar2 == (float *)0x0) {
          return (float *)0x0;
        }
        piVar3 = piVar3 + 1;
        pfVar5 = pfVar5 + 2;
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x3a));
    }
    return param_2;
  }
  FUN_1000cba0(1);
  return (float *)0x0;
}


