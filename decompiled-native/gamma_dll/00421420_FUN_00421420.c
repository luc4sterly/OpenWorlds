// 00421420 FUN_00421420 [Global]
// programa: gamma.dll

int __cdecl FUN_00421420(char *param_1,int param_2,uint param_3)

{
  byte bVar1;
  byte *pbVar2;
  char *pcVar3;
  int iVar4;
  byte local_148 [260];
  char local_44 [52];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0049d148);
  iVar4 = 0;
  if (param_1 == (char *)0x0) {
    if (param_2 != 0) {
      iVar4 = FUN_00418430(0,param_2);
    }
  }
  else {
    FUN_0044d6b0((char *)local_148,param_1);
    iVar4 = -1;
    pbVar2 = local_148;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar1 = *pbVar2;
      pbVar2 = pbVar2 + 1;
    } while (bVar1 != 0);
    pbVar2 = local_148 + (-3 - iVar4);
    if (local_148 <= pbVar2) {
      do {
        bVar1 = *pbVar2;
        if (((bVar1 == 0x5c) || (bVar1 == 0x3a)) || ((byte)(bVar1 - 0x2e) < 2)) {
          *pbVar2 = 0x7c;
        }
        pbVar2 = pbVar2 + -1;
      } while (local_148 <= pbVar2);
    }
    FUN_00450890(local_148);
    if (0 < (int)param_3) {
      FUN_0044d700((char *)local_148,&DAT_00471308);
      pcVar3 = FUN_004509b0(param_3,local_44,10);
      FUN_0044d700((char *)local_148,pcVar3);
    }
    iVar4 = FUN_004183e0(local_148);
    if ((iVar4 == 0) && (param_2 != 0)) {
      iVar4 = FUN_00418430((int)local_148,param_2);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0049d148);
  return iVar4;
}


