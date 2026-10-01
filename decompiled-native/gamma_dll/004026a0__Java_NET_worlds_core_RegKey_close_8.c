// 004026a0 _Java_NET_worlds_core_RegKey_close@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_core_RegKey_close_8(int *param_1,undefined4 param_2)

{
  HKEY hKey;
  
                    /* 0x26a0  140  _Java_NET_worlds_core_RegKey_close@8 */
  hKey = (HKEY)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_0048903c);
  RegCloseKey(hKey);
  return;
}


