// 00413a10 _Java_NET_worlds_scape_SendURLAction_launchViaRegistry@12 [Global]
// program: gamma.dll

bool _Java_NET_worlds_scape_SendURLAction_launchViaRegistry_12
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  byte *lpFile;
  HINSTANCE pHVar1;
  void *pvVar2;
  int iVar3;
  HINSTANCE pHVar4;
  char *pcVar5;
  byte *pbVar6;
  byte *pbVar7;
  
                    /* 0x13a10  283  _Java_NET_worlds_scape_SendURLAction_launchViaRegistry@12 */
  lpFile = (byte *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  pHVar1 = ShellExecuteA((HWND)0x0,&DAT_0046f748,(LPCSTR)lpFile,(LPCSTR)0x0,(LPCSTR)0x0,1);
  if ((int)pHVar1 < 0x21) {
    pbVar6 = &DAT_0046f750;
    pcVar5 = s_in_ShellExecuting_0046f754;
    pHVar4 = pHVar1;
    pbVar7 = lpFile;
    pvVar2 = (void *)FUN_00403350(0x49eda8,(byte *)s_Error_0046f768);
    iVar3 = FUN_0040f900(pvVar2,pHVar4);
    iVar3 = FUN_00403350(iVar3,(byte *)pcVar5);
    iVar3 = FUN_00403350(iVar3,pbVar7);
    FUN_00403350(iVar3,pbVar6);
    if (pHVar1 == (HINSTANCE)0x2) {
      pHVar1 = ShellExecuteA((HWND)0x0,&DAT_0046f748,(LPCSTR)lpFile,(LPCSTR)0x0,(LPCSTR)0x0,1);
      if ((int)pHVar1 < 0x21) {
        pbVar7 = &DAT_0046f770;
        pHVar4 = pHVar1;
        pvVar2 = (void *)FUN_00403350(0x49eda8,(byte *)s_Retry_failed_too_with_error_0046f774);
        iVar3 = FUN_0040f900(pvVar2,pHVar4);
        FUN_00403350(iVar3,pbVar7);
      }
    }
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpFile);
  return 0x20 < (int)pHVar1;
}


