// 10026c30 RwReadRaster [Global]
// programa: RWL21.DLL

int * RwReadRaster(char *param_1,uint param_2)

{
  int *piVar1;
  
                    /* 0x26c30  321  RwReadRaster */
  if (((param_2 & 0x20) != 0) && ((param_2 & 8) == 0)) {
    param_2 = param_2 | 8;
  }
  if (((param_2 & 8) != 0) && ((param_2 & 0x17) != 0)) {
    FUN_1000cba0(0x3d);
    return (int *)0x0;
  }
  if ((*(int *)(PTR_DAT_1005b69c + 0x14) != 8) && ((param_2 & 8) != 0)) {
    param_2 = param_2 & 0xffffffd7;
  }
  piVar1 = FUN_10026cc0(param_1,param_2,0);
  if (piVar1 == (int *)0x0) {
    return (int *)0x0;
  }
  if (*(int *)(PTR_DAT_1005b69c + 0x14) == piVar1[9]) {
    return piVar1;
  }
  RwDestroyRaster(piVar1);
  FUN_1000cba0(0x6d);
  return (int *)0x0;
}


