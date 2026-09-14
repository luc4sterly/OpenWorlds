// 00401220 _Java_NET_worlds_core_IniFile_setIniInt@16 [Global]
// programa: gamma.dll

void _Java_NET_worlds_core_IniFile_setIniInt_16(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  LPCSTR lpKeyName;
  char *lpFileName;
  LPCSTR lpAppName;
  CHAR local_114 [260];
  
                    /* 0x1220  138  _Java_NET_worlds_core_IniFile_setIniInt@16 */
  iVar1 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_00489008);
  uVar2 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_00489004);
  lpKeyName = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  if (iVar1 == 0) {
    lpFileName = s___worlds_ini_0046d048;
  }
  else {
    lpFileName = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,iVar1,0);
  }
  lpAppName = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,uVar2,0);
  FUN_0044d650((int)local_114,&DAT_0046d154);
  WritePrivateProfileStringA(lpAppName,lpKeyName,local_114,lpFileName);
  (**(code **)(*param_1 + 0x2a8))(param_1,uVar2,lpAppName);
  if (lpFileName != s___worlds_ini_0046d048) {
    (**(code **)(*param_1 + 0x2a8))(param_1,iVar1,lpFileName);
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpKeyName);
  return;
}


