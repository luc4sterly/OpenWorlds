// 00401000 FUN_00401000 [Global]
// program: run.exe

undefined4 FUN_00401000(void)

{
  bool bVar1;
  HWND pHVar2;
  LPCSTR pCVar3;
  char *pcVar4;
  CHAR *pCVar5;
  LPCSTR pCVar6;
  INT IVar7;
  UINT uType;
  _MEMORYSTATUS local_438;
  HINSTANCE local_418;
  CHAR local_414 [1024];
  undefined1 local_14 [16];
  
  local_418 = (HINSTANCE)0x0;
  GlobalMemoryStatus(&local_438);
  if (local_438.dwTotalPhys < 0x4000000) {
    FUN_00401238(local_14,(byte *)s__nojit_00409198);
  }
  else {
    local_14[0] = 0;
  }
  bVar1 = FUN_00401170(s_bin_javaw_exe_00409188);
  if (bVar1) {
    FUN_00401238(local_414,(byte *)s__Xbootclasspath_lib_i18ncls_zip__00409114);
    IVar7 = 1;
    pCVar6 = &DAT_00409110;
    pCVar5 = local_414;
    pcVar4 = s_bin_javaw_exe_00409188;
    pCVar3 = &DAT_00409108;
    pHVar2 = GetDesktopWindow();
    local_418 = ShellExecuteA(pHVar2,pCVar3,pcVar4,pCVar5,pCVar6,IVar7);
  }
  else {
    FUN_004011a4((uint *)s_PATH__PATH____bin_004090f4);
    FUN_00401238(local_414,(byte *)s__cp___lib_gammacls_zip_bin_NET_w_004090b0);
    IVar7 = 1;
    pCVar6 = &DAT_00409110;
    pCVar5 = local_414;
    pcVar4 = s_wjview_exe_004090a4;
    pCVar3 = &DAT_00409108;
    pHVar2 = GetDesktopWindow();
    local_418 = ShellExecuteA(pHVar2,pCVar3,pcVar4,pCVar5,pCVar6,IVar7);
    if (local_418 == (HINSTANCE)0x2) {
      IVar7 = 0;
      pCVar6 = &DAT_00409110;
      pCVar5 = local_414;
      pcVar4 = s_jview_exe_00409098;
      pCVar3 = &DAT_00409108;
      pHVar2 = GetDesktopWindow();
      local_418 = ShellExecuteA(pHVar2,pCVar3,pcVar4,pCVar5,pCVar6,IVar7);
    }
  }
  if ((int)local_418 < 0x21) {
    FUN_00401238(local_414,(byte *)s_ERROR__Can_t_find_java_runtime_e_00409030);
    uType = 0;
    pCVar3 = (LPCSTR)0x0;
    pCVar5 = local_414;
    pHVar2 = GetDesktopWindow();
    MessageBoxA(pHVar2,pCVar5,pCVar3,uType);
  }
  return 0;
}


