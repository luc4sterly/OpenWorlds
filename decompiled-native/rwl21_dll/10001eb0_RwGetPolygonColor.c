// 10001eb0 RwGetPolygonColor [Global]
// program: RWL21.DLL

float * RwGetPolygonColor(int *param_1,float *param_2)

{
  float *pfVar1;
  
                    /* 0x1eb0  215  RwGetPolygonColor */
  if (param_1 != (int *)0x0) {
    pfVar1 = RwGetMaterialColor(*param_1,param_2);
    return pfVar1;
  }
  FUN_1000cba0(1);
  return (float *)0x0;
}


