// 10009bf0 RwReadShape [Global]
// programa: RWL21.DLL

undefined4 * RwReadShape(char *param_1)

{
  char cVar1;
  int iVar2;
  FILE *_File;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char local_210 [16];
  char local_200 [512];
  
                    /* 0x9bf0  322  RwReadShape */
  iVar2 = FUN_10043d50(param_1);
  if (iVar2 == 0) {
    pcVar6 = (char *)&DAT_10058070;
    _sprintf(local_210,s______c__1005a080,(int)DAT_1005a079);
    iVar2 = _sscanf((char *)&DAT_10058070,local_210,&DAT_1005ddc0);
    while (iVar2 != 0) {
      FUN_10043db0(local_200,&DAT_1005ddc0,param_1);
      iVar2 = FUN_10043cb0(local_200,1);
      if (iVar2 == 0) {
        uVar4 = 0xffffffff;
        pcVar6 = local_200;
        goto code_r0x10009cc1;
      }
      pcVar6 = _strchr(pcVar6,(int)DAT_1005a079);
      if (pcVar6 == (char *)0x0) break;
      pcVar6 = pcVar6 + 1;
      iVar2 = _sscanf(pcVar6,local_210,&DAT_1005ddc0);
    }
    pcVar6 = (char *)0x0;
  }
  else {
    iVar2 = FUN_10043cb0(param_1,1);
    pcVar6 = (char *)(-(uint)(iVar2 == 0) & (uint)param_1);
  }
  goto LAB_10009cad;
  while( true ) {
    uVar4 = uVar4 - 1;
    pcVar7 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar7;
    if (cVar1 == '\0') break;
code_r0x10009cc1:
    pcVar7 = pcVar6;
    if (uVar4 == 0) break;
  }
  uVar4 = ~uVar4;
  pcVar6 = pcVar7 + -uVar4;
  pcVar7 = (char *)&DAT_1005ddc0;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  pcVar6 = (char *)&DAT_1005ddc0;
LAB_10009cad:
  if (pcVar6 == (char *)0x0) {
    iVar2 = 0xd;
  }
  else {
    _File = FID_conflict___wfopen(pcVar6,&DAT_1005a088);
    if (_File != (FILE *)0x0) {
      puVar3 = FUN_100163e0(_File);
      _fclose(_File);
      return puVar3;
    }
    iVar2 = 0xe;
  }
  FUN_1000cba0(iVar2);
  return (undefined4 *)0x0;
}


