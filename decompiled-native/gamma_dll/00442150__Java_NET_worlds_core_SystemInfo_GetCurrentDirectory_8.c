// 00442150 _Java_NET_worlds_core_SystemInfo_GetCurrentDirectory@8 [Global]
// programa: gamma.dll

undefined4 _Java_NET_worlds_core_SystemInfo_GetCurrentDirectory_8(int *param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  CHAR local_10c [260];
  
                    /* 0x42150  167  _Java_NET_worlds_core_SystemInfo_GetCurrentDirectory@8 */
  DVar1 = GetCurrentDirectoryA(0x104,local_10c);
  if (DVar1 == 0) {
    return 0;
  }
  uVar2 = (**(code **)(*param_1 + 0x29c))(param_1,local_10c);
  return uVar2;
}


