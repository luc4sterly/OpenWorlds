// 10026f80 RwReadMaskRaster [Global]
// programa: RWL21.DLL

int * RwReadMaskRaster(char *param_1)

{
  int *piVar1;
  
                    /* 0x26f80  319  RwReadMaskRaster */
  piVar1 = FUN_10026cc0(param_1,0xc,1);
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


