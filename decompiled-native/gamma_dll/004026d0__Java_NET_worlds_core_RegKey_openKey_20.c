// 004026d0 _Java_NET_worlds_core_RegKey_openKey@20 [Global]
// programa: gamma.dll

HKEY _Java_NET_worlds_core_RegKey_openKey_20
               (int *param_1,undefined4 param_2,HKEY param_3,undefined4 param_4,uint param_5)

{
  LPCSTR lpSubKey;
  LSTATUS LVar1;
  REGSAM samDesired;
  HKEY local_78;
  undefined1 local_74 [100];
  
                    /* 0x26d0  146  _Java_NET_worlds_core_RegKey_openKey@20 */
  lpSubKey = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_4,0);
  local_78 = (HKEY)0x0;
  samDesired = 0x20019;
  if ((param_5 & 1) != 0) {
    samDesired = 0x2001f;
  }
  LVar1 = RegOpenKeyExA(param_3,lpSubKey,0,samDesired,&local_78);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_4,lpSubKey);
  if (LVar1 != 0) {
    FUN_0044d650((int)local_74,s_Key_not_found___d_0046d2ac);
    FUN_00402930(param_1,(byte *)s_NET_worlds_core_RegKeyNotFoundEx_0046d2c0,local_74);
  }
  return local_78;
}


