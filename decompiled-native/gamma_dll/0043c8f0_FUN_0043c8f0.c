// 0043c8f0 FUN_0043c8f0 [Global]
// programa: gamma.dll

byte * __cdecl FUN_0043c8f0(byte *param_1)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  int *piVar4;
  char *pcVar5;
  char *pcVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  uint uVar10;
  byte *local_818;
  char local_810 [512];
  char local_610 [509];
  char acStack_413 [515];
  byte local_210 [512];
  
  local_818 = param_1;
  bVar3 = false;
  if ((char)DAT_0049de65 == '\0') {
    return param_1;
  }
  piVar4 = FUN_00455020((LPCSTR)&DAT_0049de65,&DAT_00477364);
  do {
    do {
      do {
        if ((char)piVar4[3] != '\0') goto LAB_0043cb64;
        pcVar5 = FUN_00455530(local_810,0xff,piVar4);
      } while ((pcVar5 == (char *)0x0) || (*pcVar5 == '#'));
      FUN_0044d6b0(local_610,local_810);
      pcVar6 = FUN_0044d7a0(local_610,'=');
    } while ((pcVar5 == (char *)0x0) ||
            (((*pcVar5 == '#' || (*pcVar5 == '\n')) || (pcVar6 == (char *)0x0))));
    pbVar7 = FUN_0044d810((int)local_810,&DAT_004773c4);
    iVar9 = -1;
    pbVar8 = pbVar7;
    do {
      if (iVar9 == 0) break;
      iVar9 = iVar9 + -1;
      bVar1 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    } while (bVar1 != 0);
    iVar9 = FUN_0044d760(pbVar7,param_1,-2 - iVar9);
  } while (iVar9 != 0);
  bVar3 = true;
  pbVar8 = FUN_0044d810(0,&DAT_00477334);
  pcVar5 = FUN_0044d7a0((char *)pbVar8,'=');
  FUN_0044d6b0((char *)local_210,pcVar5 + 2);
  pcVar5 = FUN_0044d7a0((char *)local_210,'\\');
joined_r0x0043ca41:
  if (((pcVar5 != (char *)0x0) && (cVar2 = pcVar5[1], cVar2 != 'n')) &&
     ((cVar2 != 't' && (cVar2 != 'u')))) {
    FUN_0044d810((int)local_210,&DAT_004773c8);
    FUN_00455530(local_810,0xff,piVar4);
    FUN_0044d6b0(local_610,local_810);
    uVar10 = 0;
    do {
      iVar9 = -1;
      pcVar5 = local_810;
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
      if (-iVar9 - 2U <= uVar10) goto LAB_0043cb0c;
      if ((local_810[uVar10] != ' ') && (local_810[uVar10] != '\t')) goto code_r0x0043cab7;
      uVar10 = uVar10 + 1;
    } while( true );
  }
  local_818 = local_210;
LAB_0043cb64:
  FUN_00454eb0(piVar4);
  if ((!bVar3) && (DAT_0047729c != '\0')) {
    FUN_0044d6b0((char *)&DAT_0049de65,s_MessagesBundle_properties_00477280);
    DAT_0047729c = '\0';
    local_818 = FUN_0043c8f0(param_1);
  }
  if ((DAT_0047729c == '\0') && (DAT_0049de85 != '\0')) {
    FUN_0044d6b0((char *)&DAT_0049de65,&DAT_0049de85);
    DAT_0047729c = '\x01';
  }
  return local_818;
code_r0x0043cab7:
  iVar9 = -1;
  pcVar5 = local_810;
  do {
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    cVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  FUN_0044d6d0(acStack_413 + 3,local_810 + uVar10,(-uVar10 - iVar9) + -3);
  acStack_413[-uVar10 - iVar9] = '\0';
LAB_0043cb0c:
  FUN_0044d700((char *)local_210,acStack_413 + 3);
  pcVar5 = FUN_0044d7a0(local_610,'\\');
  goto joined_r0x0043ca41;
}


