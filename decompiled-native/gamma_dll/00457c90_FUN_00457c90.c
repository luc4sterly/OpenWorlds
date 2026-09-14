// 00457c90 FUN_00457c90 [Global]
// programa: gamma.dll

uint __cdecl FUN_00457c90(uint param_1,char *param_2,HANDLE param_3)

{
  char cVar1;
  DWORD DVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  short sVar7;
  
  uVar5 = 0;
  sVar7 = 0;
  if (param_2 != (char *)0x0) {
    iVar4 = -1;
    pcVar6 = param_2;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    sVar7 = -6 - (short)iVar4;
  }
  if (param_3 == (HANDLE)0x0) {
    if ((param_1 & 0x10) != 0) {
      uVar5 = 0x4200;
      goto switchD_00457cce_default;
    }
LAB_00457d05:
    uVar5 = 0x8000;
  }
  else {
    DVar2 = GetFileType(param_3);
    switch(DVar2) {
    case 1:
      if ((param_1 & 0x10) != 0) {
        uVar5 = 0x4200;
        break;
      }
      goto LAB_00457d05;
    case 2:
      uVar5 = 0x2000;
      break;
    case 3:
      uVar5 = 0x1000;
    }
  }
switchD_00457cce_default:
  if ((param_1 & 1) == 0) {
    uVar5 = uVar5 | 0xc00;
  }
  else {
    uVar5 = uVar5 | 0x800;
  }
  if (((0 < sVar7) && (pcVar6 = param_2 + sVar7, *pcVar6 == '.')) &&
     ((pcVar3 = FUN_0044d910(pcVar6,&DAT_00482cc0), pcVar3 != (char *)0x0 ||
      (((pcVar3 = FUN_0044d910(pcVar6,&DAT_00482cc8), pcVar3 != (char *)0x0 ||
        (pcVar3 = FUN_0044d910(pcVar6,&DAT_00482cd0), pcVar3 != (char *)0x0)) ||
       (pcVar6 = FUN_0044d910(pcVar6,&DAT_00482cd8), pcVar6 != (char *)0x0)))))) {
    uVar5 = uVar5 | 0x200;
  }
  return uVar5;
}


