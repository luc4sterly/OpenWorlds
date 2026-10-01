// 00409e80 _Java_NET_worlds_console_Startup_computeVolumeInfo@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_Startup_computeVolumeInfo_12
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  LPCSTR lpRootPathName;
  BOOL BVar1;
  
                    /* 0x9e80  68  _Java_NET_worlds_console_Startup_computeVolumeInfo@12 */
  lpRootPathName = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  BVar1 = GetVolumeInformationA
                    (lpRootPathName,(LPSTR)0x0,0,&DAT_0049fa6c,(LPDWORD)0x0,(LPDWORD)0x0,(LPSTR)0x0,
                     0);
  if (BVar1 == 0) {
    FUN_00402800(s_nStartup_0046dcc8,0x9c);
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpRootPathName);
  return;
}


