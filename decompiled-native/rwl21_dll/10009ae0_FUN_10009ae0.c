// 10009ae0 FUN_10009ae0 [Global]
// program: RWL21.DLL

undefined4 * FUN_10009ae0(char *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char local_210 [16];
  char local_200 [512];
  
  iVar2 = FUN_10043d50(param_1);
  if (iVar2 != 0) {
    iVar2 = FUN_10043cb0(param_1,1);
    return (undefined4 *)(-(uint)(iVar2 == 0) & (uint)param_1);
  }
  pcVar5 = (char *)&DAT_10058070;
  _sprintf(local_210,s______c__1005a080,(int)DAT_1005a079);
  iVar2 = _sscanf((char *)&DAT_10058070,local_210,&DAT_1005ddc0);
  while( true ) {
    if (iVar2 == 0) {
      return (undefined4 *)0x0;
    }
    FUN_10043db0(local_200,&DAT_1005ddc0,param_1);
    iVar2 = FUN_10043cb0(local_200,1);
    if (iVar2 == 0) break;
    pcVar5 = _strchr(pcVar5,(int)DAT_1005a079);
    if (pcVar5 == (char *)0x0) {
      return (undefined4 *)0x0;
    }
    pcVar5 = pcVar5 + 1;
    iVar2 = _sscanf(pcVar5,local_210,&DAT_1005ddc0);
  }
  uVar3 = 0xffffffff;
  pcVar5 = local_200;
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar6 + -uVar3;
  pcVar6 = (char *)&DAT_1005ddc0;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  return &DAT_1005ddc0;
}


