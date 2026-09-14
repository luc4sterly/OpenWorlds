// 00421560 FUN_00421560 [Global]
// programa: gamma.dll

int __cdecl FUN_00421560(char *param_1,uint param_2,undefined4 *param_3)

{
  byte bVar1;
  byte *pbVar2;
  char *pcVar3;
  int iVar4;
  byte local_148 [260];
  char local_44 [52];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0049d148);
  if (param_1 == (char *)0x0) {
    iVar4 = FUN_00417920();
    iVar4 = FUN_004182d0(0,param_3,iVar4);
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
    if (0 < (int)param_2) {
      FUN_0044d700((char *)local_148,&DAT_00471308);
      pcVar3 = FUN_004509b0(param_2,local_44,10);
      FUN_0044d700((char *)local_148,pcVar3);
    }
    iVar4 = FUN_004183e0(local_148);
    if (iVar4 == 0) {
      iVar4 = FUN_00417920();
      iVar4 = FUN_004182d0((int)local_148,param_3,iVar4);
    }
    else {
      FUN_00454a60(param_3);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0049d148);
  return iVar4;
}


