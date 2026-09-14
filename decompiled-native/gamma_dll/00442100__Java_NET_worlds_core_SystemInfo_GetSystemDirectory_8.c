// 00442100 _Java_NET_worlds_core_SystemInfo_GetSystemDirectory@8 [Global]
// programa: gamma.dll

undefined4 _Java_NET_worlds_core_SystemInfo_GetSystemDirectory_8(int *param_1)

{
  UINT UVar1;
  undefined4 uVar2;
  CHAR local_10c [260];
  
                    /* 0x42100  172  _Java_NET_worlds_core_SystemInfo_GetSystemDirectory@8 */
  UVar1 = GetSystemDirectoryA(local_10c,0x104);
  if (UVar1 == 0) {
    return 0;
  }
  uVar2 = (**(code **)(*param_1 + 0x29c))(param_1,local_10c);
  return uVar2;
}


