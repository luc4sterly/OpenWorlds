// 00402640 _Java_NET_worlds_core_RegKey_setIntValue@16 [Global]
// program: gamma.dll

bool _Java_NET_worlds_core_RegKey_setIntValue_16(int *param_1,undefined4 param_2,undefined4 param_3)

{
  HKEY hKey;
  LPCSTR lpValueName;
  LSTATUS LVar1;
  
                    /* 0x2640  147  _Java_NET_worlds_core_RegKey_setIntValue@16 */
  hKey = (HKEY)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_0048903c);
  lpValueName = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  LVar1 = RegSetValueExA(hKey,lpValueName,0,4,&stack0x00000010,4);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpValueName);
  return (char)LVar1 == '\0';
}


