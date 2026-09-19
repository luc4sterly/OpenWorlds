// 100059b0 RwClumpDistance [Global]
// programa: RWL21.DLL

float10 RwClumpDistance(int param_1,float *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float local_10;
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* 0x59b0  32  RwClumpDistance */
  local_10 = 0.0;
  if ((param_1 == 0) || (param_2 == (float *)0x0)) {
    param_1 = 0;
  }
  iVar3 = 0;
  iVar2 = param_1;
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    do {
      if ((*(char *)(iVar2 + 0x12d) != '\0') || (*(char *)(iVar2 + 0x171) != '\0')) {
        iVar3 = iVar2;
      }
      piVar1 = (int *)(iVar2 + 0x174);
      iVar2 = *piVar1;
    } while (*piVar1 != 0);
    if (iVar3 != 0) {
      FUN_10004700(0,iVar3,(float *)iVar3);
    }
    local_c = *(float *)(param_1 + 0x30);
    local_8 = *(undefined4 *)(param_1 + 0x34);
    local_4 = *(undefined4 *)(param_1 + 0x38);
    RwSubtractVector(param_2,&local_c,&local_c);
    fVar4 = rwLengthNormaliseVector(&local_c,&local_c);
    local_10 = (float)fVar4;
  }
  return (float10)local_10;
}


