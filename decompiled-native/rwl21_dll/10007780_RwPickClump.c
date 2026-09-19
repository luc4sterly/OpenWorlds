// 10007780 RwPickClump [Global]
// programa: RWL21.DLL

undefined4 * RwPickClump(float *param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  float *pfVar2;
  undefined4 *puVar3;
  float *pfVar4;
  
                    /* 0x7780  302  RwPickClump */
  iVar1 = *(int *)(PTR_DAT_1005b69c + 0x10);
  *(int *)(PTR_DAT_1005b69c + 0x10) = param_4;
  if (((param_5 == (undefined4 *)0x0) || (param_1 == (float *)0x0)) || (param_4 == 0)) {
    param_5 = (undefined4 *)0x0;
  }
  if (param_5 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    puVar3 = (undefined4 *)0x0;
  }
  else {
    if (*(int *)(param_4 + 0x8c) == 2) {
      *(undefined4 *)(PTR_DAT_1005b69c + 0x2e4) = 0;
    }
    pfVar4 = (float *)0x0;
    for (pfVar2 = param_1; pfVar2 != (float *)0x0; pfVar2 = (float *)pfVar2[0x5d]) {
      if ((*(char *)((int)pfVar2 + 0x12d) != '\0') || (*(char *)((int)pfVar2 + 0x171) != '\0')) {
        pfVar4 = pfVar2;
      }
    }
    if (pfVar4 != (float *)0x0) {
      FUN_10004700(0,pfVar4,pfVar4);
    }
    puVar3 = FUN_10006ff0(param_1,param_2,param_3,param_4,param_5);
  }
  *(int *)(PTR_DAT_1005b69c + 0x10) = iVar1;
  return puVar3;
}


