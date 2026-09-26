// 10009b40 rwdev [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* rwdev */

undefined1 * __cdecl rwdev(char *param_1,undefined4 *param_2,undefined4 param_3)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
                    /* 0x9b40  1  _rwdev */
  if (DAT_10038a10 != 0) {
    return (undefined1 *)0x0;
  }
  DAT_100394fc = param_3;
  _DAT_100457ec = param_3;
  if (param_1 == (char *)0x0) {
    if (param_2 == (undefined4 *)0x0) {
      return &LAB_10009bf0;
    }
    *param_2 = s_MSWindows_100362a0._0_4_;
    param_2[1] = s_MSWindows_100362a0._4_4_;
    *(undefined2 *)(param_2 + 2) = s_MSWindows_100362a0._8_2_;
  }
  else {
    pcVar3 = s_MSWindows_100362a0;
    cVar1 = *param_1;
    while( true ) {
      if ((cVar1 == '\0') || (cVar1 = *pcVar3, cVar1 == '\0')) {
        return &LAB_10009bf0;
      }
      cVar2 = *param_1;
      if ((cVar2 < 'a') || ('z' < cVar2)) {
        iVar5 = (int)cVar2;
      }
      else {
        iVar5 = cVar2 + -0x20;
      }
      if ((cVar1 < 'a') || ('z' < cVar1)) {
        iVar4 = (int)cVar1;
      }
      else {
        iVar4 = cVar1 + -0x20;
      }
      if (iVar5 != iVar4) break;
      cVar1 = param_1[1];
      param_1 = param_1 + 1;
      pcVar3 = pcVar3 + 1;
    }
  }
  return (undefined1 *)0x0;
}


