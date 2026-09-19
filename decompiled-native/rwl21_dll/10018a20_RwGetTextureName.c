// 10018a20 RwGetTextureName [Global]
// programa: RWL21.DLL

char * RwGetTextureName(int *param_1,char *param_2,size_t param_3)

{
  int *piVar1;
  char *_Source;
  int iVar2;
  int *piVar3;
  
                    /* 0x18a20  259  RwGetTextureName */
  if (param_1 == (int *)0x0) {
    FUN_1000cba0(1);
    return (char *)0x0;
  }
  if (param_2 == (char *)0x0) {
    FUN_1000cba0(1);
    return (char *)0x0;
  }
  if ((int)param_3 < 1) {
    FUN_1000cba0(0x47);
    return (char *)0x0;
  }
  piVar1 = (int *)*param_1;
  if (piVar1 == (int *)0x0) {
    return (char *)0x0;
  }
  iVar2 = 0;
  if (0 < piVar1[2]) {
    piVar3 = (int *)(*piVar1 + 4);
    do {
      if ((int *)*piVar3 == param_1) goto LAB_10018abe;
      piVar3 = piVar3 + 2;
      iVar2 = iVar2 + 1;
    } while (iVar2 < piVar1[2]);
  }
  iVar2 = -1;
LAB_10018abe:
  if (iVar2 == -1) {
    FUN_1000cba0(0x6a);
    return (char *)0x0;
  }
  _Source = *(char **)(*piVar1 + iVar2 * 8);
  if (_Source == (char *)0x0) {
    *param_2 = '\0';
    return param_2;
  }
  _strncpy(param_2,_Source,param_3);
  param_2[param_3 - 1] = '\0';
  return param_2;
}


