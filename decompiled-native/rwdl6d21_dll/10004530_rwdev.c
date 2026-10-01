// 10004530 rwdev [Global]
// program: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* rwdev */

undefined1 * __cdecl rwdev(char *param_1,undefined4 *param_2,undefined4 param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  
                    /* 0x4530  1  _rwdev */
  DAT_1007bda8 = param_3;
  _DAT_1007f7cc = param_3;
  if (param_1 == (char *)0x0) {
    if (param_2 == (undefined4 *)0x0) {
      return &LAB_10004630;
    }
    *param_2 = s_MSWindows_10079150._0_4_;
    param_2[1] = s_MSWindows_10079150._4_4_;
    *(undefined2 *)(param_2 + 2) = s_MSWindows_10079150._8_2_;
  }
  else {
    pcVar6 = s_MSWindows_10079150;
    cVar1 = *param_1;
    pcVar7 = param_1;
    cVar2 = cVar1;
    while( true ) {
      if ((cVar2 == '\0') || (cVar2 = *pcVar6, cVar2 == '\0')) {
        return &LAB_10004630;
      }
      cVar3 = *pcVar7;
      if ((cVar3 < 'a') || ('z' < cVar3)) {
        iVar5 = (int)cVar3;
      }
      else {
        iVar5 = cVar3 + -0x20;
      }
      if ((cVar2 < 'a') || ('z' < cVar2)) {
        iVar4 = (int)cVar2;
      }
      else {
        iVar4 = cVar2 + -0x20;
      }
      if (iVar5 != iVar4) break;
      cVar2 = pcVar7[1];
      pcVar7 = pcVar7 + 1;
      pcVar6 = pcVar6 + 1;
    }
    pcVar6 = s_MSWindowsDD_10079144;
    while( true ) {
      if ((cVar1 == '\0') || (cVar2 = *pcVar6, cVar2 == '\0')) {
        return &LAB_10004990;
      }
      cVar1 = *param_1;
      if ((cVar1 < 'a') || ('z' < cVar1)) {
        iVar5 = (int)cVar1;
      }
      else {
        iVar5 = cVar1 + -0x20;
      }
      if ((cVar2 < 'a') || ('z' < cVar2)) {
        iVar4 = (int)cVar2;
      }
      else {
        iVar4 = cVar2 + -0x20;
      }
      if (iVar5 != iVar4) break;
      cVar1 = param_1[1];
      param_1 = param_1 + 1;
      pcVar6 = pcVar6 + 1;
    }
  }
  return (undefined1 *)0x0;
}


