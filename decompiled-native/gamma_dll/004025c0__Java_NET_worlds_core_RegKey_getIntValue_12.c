// 004025c0 _Java_NET_worlds_core_RegKey_getIntValue@12 [Global]
// programa: gamma.dll

undefined4
_Java_NET_worlds_core_RegKey_getIntValue_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  HKEY hKey;
  LPCSTR lpValueName;
  LSTATUS LVar1;
  undefined4 uVar2;
  undefined4 local_1c;
  DWORD local_18 [2];
  
                    /* 0x25c0  142  _Java_NET_worlds_core_RegKey_getIntValue@12 */
  hKey = (HKEY)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_0048903c);
  lpValueName = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  local_18[1] = 4;
  LVar1 = RegQueryValueExA(hKey,lpValueName,(LPDWORD)0x0,local_18,(LPBYTE)&local_1c,local_18 + 1);
  uVar2 = 0;
  if ((LVar1 == 0) && (local_18[0] == 4)) {
    uVar2 = local_1c;
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpValueName);
  return uVar2;
}


