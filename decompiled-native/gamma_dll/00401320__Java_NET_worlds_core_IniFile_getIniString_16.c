// 00401320 _Java_NET_worlds_core_IniFile_getIniString@16 [Global]
// program: gamma.dll

void _Java_NET_worlds_core_IniFile_getIniString_16
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  LPCSTR lpKeyName;
  char *lpFileName;
  char *lpDefault;
  LPCSTR lpAppName;
  char local_210 [512];
  
                    /* 0x1320  136  _Java_NET_worlds_core_IniFile_getIniString@16 */
  iVar1 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_00489008);
  uVar2 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_00489004);
  lpKeyName = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  if (iVar1 == 0) {
    lpFileName = s___worlds_ini_0046d048;
  }
  else {
    lpFileName = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,iVar1,0);
  }
  lpDefault = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_4,0);
  lpAppName = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,uVar2,0);
  FUN_0044d6b0(local_210,lpDefault);
  GetPrivateProfileStringA(lpAppName,lpKeyName,lpDefault,local_210,0x200,lpFileName);
  (**(code **)(*param_1 + 0x2a8))(param_1,uVar2,lpAppName);
  if (lpFileName != s___worlds_ini_0046d048) {
    (**(code **)(*param_1 + 0x2a8))(param_1,iVar1,lpFileName);
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_4,lpDefault);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpKeyName);
  (**(code **)(*param_1 + 0x29c))(param_1,local_210);
  return;
}


