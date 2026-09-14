// 00452380 FUN_00452380 [Global]
// programa: gamma.dll

void * __thiscall FUN_00452380(void *this,void *param_1,uint param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  uint *local_18 [2];
  
  FUN_004538d0(local_18,this,0,param_2 + 1);
  *param_3 = (int)*(short *)((int)this + 4);
  iVar1 = FUN_004089f0((int *)local_18);
  if (param_2 < *local_18[0]) {
    if ('\x04' < *(char *)(iVar1 + -1)) {
      for (pcVar4 = (char *)(iVar1 + -2); '\b' < *pcVar4; pcVar4 = pcVar4 + -1) {
        *pcVar4 = '\0';
        pcVar3 = (char *)FUN_004088e0((int *)local_18);
        if (pcVar4 == pcVar3) {
          iVar1 = FUN_004088e0((int *)local_18);
          iVar2 = FUN_004088e0((int *)local_18);
          FUN_00408f50(local_18,iVar1 - iVar2,0,1,1);
          FUN_004088e0((int *)local_18);
          FUN_004537e0(local_18,*local_18[0] - 1,0);
          *param_3 = *param_3 + 1;
          goto LAB_00452423;
        }
      }
      *pcVar4 = *pcVar4 + '\x01';
    }
LAB_00452423:
    FUN_004537e0(local_18,*local_18[0] - 1,0);
  }
  pcVar3 = (char *)FUN_004089f0((int *)local_18);
  for (pcVar4 = (char *)FUN_004088e0((int *)local_18); pcVar4 < pcVar3; pcVar4 = pcVar4 + 1) {
    *pcVar4 = *pcVar4 + '0';
  }
  FUN_00406490(param_1,local_18);
  FUN_00404ed0((int *)local_18);
  return param_1;
}


