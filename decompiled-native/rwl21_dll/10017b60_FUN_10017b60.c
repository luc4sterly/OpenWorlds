// 10017b60 FUN_10017b60 [Global]
// program: RWL21.DLL

int * FUN_10017b60(char *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == (char *)0x0) {
    FUN_1000cba0(1);
    return (int *)0x0;
  }
  piVar2 = RwReadRaster(param_1,DAT_1005ac04);
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  iVar1 = piVar2[7];
  if (iVar1 == *(int *)(PTR_DAT_1005b69c + 0x20)) {
LAB_10017bde:
    if (piVar2[8] / *(int *)(PTR_DAT_1005b69c + 0x24) < 1) goto LAB_10017c1e;
  }
  else {
    if ((*(int *)(PTR_DAT_1005b69c + 700) == 0) || (iVar1 != *(int *)(PTR_DAT_1005b69c + 700))) {
      if ((undefined4 *)piVar2[0xc] != (undefined4 *)0x0) {
        RwDestroyRaster((undefined4 *)piVar2[0xc]);
      }
      RwDestroyRaster(piVar2);
      FUN_1000cba0(0x16);
      return (int *)0x0;
    }
    if (iVar1 == *(int *)(PTR_DAT_1005b69c + 0x20)) goto LAB_10017bde;
  }
  if (((*(int *)(PTR_DAT_1005b69c + 700) == 0) || (iVar1 != *(int *)(PTR_DAT_1005b69c + 700))) ||
     (0 < piVar2[8] / *(int *)(PTR_DAT_1005b69c + 0x2c0))) {
    return piVar2;
  }
LAB_10017c1e:
  if ((undefined4 *)piVar2[0xc] != (undefined4 *)0x0) {
    RwDestroyRaster((undefined4 *)piVar2[0xc]);
  }
  RwDestroyRaster(piVar2);
  FUN_1000cba0(0x17);
  return (int *)0x0;
}


