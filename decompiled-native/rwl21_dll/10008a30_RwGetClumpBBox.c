// 10008a30 RwGetClumpBBox [Global]
// program: RWL21.DLL

float * RwGetClumpBBox(float *param_1,float *param_2,float *param_3)

{
  float *pfVar1;
  float *pfVar2;
  
                    /* 0x8a30  147  RwGetClumpBBox */
  pfVar2 = (float *)0x0;
  if (((param_1 != (float *)0x0) && (param_2 != (float *)0x0)) &&
     (pfVar1 = param_1, param_3 != (float *)0x0)) {
    for (; pfVar1 != (float *)0x0; pfVar1 = (float *)pfVar1[0x5d]) {
      if ((*(char *)((int)pfVar1 + 0x12d) != '\0') || (*(char *)((int)pfVar1 + 0x171) != '\0')) {
        pfVar2 = pfVar1;
      }
    }
    if (pfVar2 != (float *)0x0) {
      FUN_10004700(0,pfVar2,pfVar2);
    }
    FUN_100088d0(param_1,param_2,param_3);
    return param_1;
  }
  FUN_1000cba0(1);
  return (float *)0x0;
}


