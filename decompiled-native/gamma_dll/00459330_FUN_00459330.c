// 00459330 FUN_00459330 [Global]
// programa: gamma.dll

int __cdecl FUN_00459330(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  
  FUN_00459300((int)param_1);
  if (param_3 == 1) {
    param_1[0xb] = param_1[9];
  }
  iVar3 = (*(code *)param_1[0x10])(*param_1,param_1[8],param_1 + 0xb,param_1[0x13]);
  if (iVar3 == 2) {
    param_1[0xb] = 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_1[0xb];
  }
  if (iVar3 == 0) {
    param_1[7] = param_1[7] + param_1[0xb];
    if ((*(byte *)((int)param_1 + 5) >> 4 & 1) == 0) {
      iVar3 = param_1[0xb];
      pcVar2 = (char *)param_1[8];
      while (iVar3 != 0) {
        iVar3 = iVar3 + -1;
        pcVar4 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar4;
        if (cVar1 == '\n') {
          param_1[7] = param_1[7] + 1;
        }
      }
    }
    if ((*(byte *)((int)param_1 + 5) >> 4 & 1) == 0) {
      FUN_004592f0();
    }
    return 0;
  }
  return iVar3;
}


