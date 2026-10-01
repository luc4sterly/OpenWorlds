// 10039640 RwOpenStream [Global]
// program: RWL21.DLL

int * RwOpenStream(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  FILE *pFVar2;
  int iVar3;
  char *_Mode;
  
                    /* 0x39640  299  RwOpenStream */
  piVar1 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(0x14);
  if (piVar1 == (int *)0x0) {
    FUN_1000cba0(3);
    return (int *)0x0;
  }
  *piVar1 = param_1;
  piVar1[1] = param_2;
  if (param_1 == 1) {
    if (param_3 != (int *)0x0) {
      piVar1[2] = (int)param_3;
      return piVar1;
    }
    iVar3 = 1;
  }
  else if (param_1 == 2) {
    if (param_3 != (int *)0x0) {
      pFVar2 = (FILE *)0x0;
      if (param_2 == 1) {
        _Mode = &DAT_1005ad0c;
LAB_100396e3:
        pFVar2 = FID_conflict___wfopen((char *)param_3,_Mode);
      }
      else {
        if (param_2 == 2) {
          _Mode = &DAT_1005b78c;
          goto LAB_100396e3;
        }
        if (param_2 == 3) {
          _Mode = &DAT_1005b788;
          goto LAB_100396e3;
        }
        FUN_1000cba0(0x56);
      }
      if (pFVar2 != (FILE *)0x0) {
        piVar1[2] = (int)pFVar2;
        return piVar1;
      }
      FUN_1000cba0(0xe);
      goto LAB_10039727;
    }
    iVar3 = 1;
  }
  else if (param_1 == 3) {
    if (param_2 == 1) {
      piVar1[2] = 0;
      piVar1[3] = param_3[1];
      piVar1[4] = *param_3;
      return piVar1;
    }
    if (param_2 == 2) {
      piVar1[2] = 0;
      piVar1[3] = 0;
      piVar1[4] = 0;
      return piVar1;
    }
    if (param_2 == 3) {
      piVar1[2] = param_3[1];
      piVar1[3] = param_3[1];
      piVar1[4] = *param_3;
      return piVar1;
    }
    iVar3 = 0x56;
  }
  else {
    iVar3 = 0x57;
  }
  FUN_1000cba0(iVar3);
LAB_10039727:
  (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar1);
  return (int *)0x0;
}


