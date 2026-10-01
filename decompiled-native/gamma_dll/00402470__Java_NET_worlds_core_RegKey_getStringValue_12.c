// 00402470 _Java_NET_worlds_core_RegKey_getStringValue@12 [Global]
// program: gamma.dll

undefined4
_Java_NET_worlds_core_RegKey_getStringValue_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  HKEY hKey;
  LPCSTR lpValueName;
  LSTATUS LVar1;
  undefined4 uVar2;
  BYTE local_418 [1024];
  DWORD local_18 [2];
  
                    /* 0x2470  144  _Java_NET_worlds_core_RegKey_getStringValue@12 */
  hKey = (HKEY)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_0048903c);
  lpValueName = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  local_18[1] = 0x400;
  uVar2 = 0;
  LVar1 = RegQueryValueExA(hKey,lpValueName,(LPDWORD)0x0,local_18,local_418,local_18 + 1);
  if ((LVar1 == 0) && (local_18[0] - 1 < 2)) {
    uVar2 = (**(code **)(*param_1 + 0x29c))(param_1,local_418);
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpValueName);
  return uVar2;
}


