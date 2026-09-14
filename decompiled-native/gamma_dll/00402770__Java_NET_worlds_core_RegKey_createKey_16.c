// 00402770 _Java_NET_worlds_core_RegKey_createKey@16 [Global]
// programa: gamma.dll

HKEY _Java_NET_worlds_core_RegKey_createKey_16
               (int *param_1,undefined4 param_2,HKEY param_3,undefined4 param_4)

{
  LPCSTR lpSubKey;
  LSTATUS LVar1;
  HKEY local_78;
  undefined1 local_74 [100];
  
                    /* 0x2770  141  _Java_NET_worlds_core_RegKey_createKey@16 */
  lpSubKey = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_4,0);
  local_78 = (HKEY)0x0;
  LVar1 = RegCreateKeyExA(param_3,lpSubKey,0,(LPSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_78,(LPDWORD)0x0);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_4,lpSubKey);
  if (LVar1 != 0) {
    FUN_0044d650((int)local_74,s_Key_not_found___d_0046d2ac);
    FUN_00402930(param_1,(byte *)s_NET_worlds_core_RegKeyNotFoundEx_0046d2c0,local_74);
  }
  return local_78;
}


