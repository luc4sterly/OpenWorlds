// 10008870 RwRenderClump [Global]
// programa: RWL21.DLL

float * RwRenderClump(float *param_1)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  
                    /* 0x8870  345  RwRenderClump */
  pfVar3 = (float *)0x0;
  pfVar2 = param_1;
  if (param_1 == (float *)0x0) {
    FUN_1000cba0(1);
    return (float *)0x0;
  }
  do {
    if ((*(char *)((int)pfVar2 + 0x12d) != '\0') || (*(char *)((int)pfVar2 + 0x171) != '\0')) {
      pfVar3 = pfVar2;
    }
    pfVar1 = pfVar2 + 0x5d;
    pfVar2 = (float *)*pfVar1;
  } while ((float *)*pfVar1 != (float *)0x0);
  if (pfVar3 != (float *)0x0) {
    FUN_10004700(pfVar3,0,pfVar3);
  }
  FUN_10008000(param_1);
  return param_1;
}


