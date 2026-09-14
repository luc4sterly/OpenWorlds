// 00402510 _Java_NET_worlds_core_RegKey_setStringValue@20 [Global]
// programa: gamma.dll

bool _Java_NET_worlds_core_RegKey_setStringValue_20
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  BYTE BVar1;
  HKEY hKey;
  LPCSTR lpValueName;
  BYTE *lpData;
  LSTATUS LVar2;
  int iVar3;
  DWORD dwType;
  BYTE *pBVar4;
  
                    /* 0x2510  148  _Java_NET_worlds_core_RegKey_setStringValue@20 */
  hKey = (HKEY)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_0048903c);
  lpValueName = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  lpData = (BYTE *)(**(code **)(*param_1 + 0x2a4))(param_1,param_4,0);
  dwType = 1;
  if (param_5 != '\0') {
    dwType = 2;
  }
  iVar3 = -1;
  pBVar4 = lpData;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    BVar1 = *pBVar4;
    pBVar4 = pBVar4 + 1;
  } while (BVar1 != '\0');
  LVar2 = RegSetValueExA(hKey,lpValueName,0,dwType,lpData,0xffffffff - iVar3);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpValueName);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_4,lpData);
  return (char)LVar2 == '\0';
}


