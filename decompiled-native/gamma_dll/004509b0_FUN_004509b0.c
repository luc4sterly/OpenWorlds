// 004509b0 FUN_004509b0 [Global]
// programa: gamma.dll

char * __cdecl FUN_004509b0(uint param_1,char *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  
  bVar4 = (int)param_1 < 0;
  iVar2 = 0;
  if (bVar4) {
    param_1 = -param_1;
  }
  do {
    iVar1 = iVar2;
    cVar3 = (char)((ulonglong)param_1 % (ulonglong)param_3);
    if ((int)((ulonglong)param_1 % (ulonglong)param_3) < 10) {
      param_2[iVar1] = cVar3 + '0';
    }
    else {
      param_2[iVar1] = cVar3 + '7';
    }
    iVar2 = iVar1 + 1;
    param_1 = param_1 / param_3;
  } while (param_1 != 0);
  if (bVar4) {
    param_2[iVar2] = '-';
    iVar2 = iVar1 + 2;
  }
  param_2[iVar2] = '\0';
  FUN_00450a30(param_2);
  return param_2;
}


