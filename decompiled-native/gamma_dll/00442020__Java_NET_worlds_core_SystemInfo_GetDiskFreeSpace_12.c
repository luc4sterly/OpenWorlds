// 00442020 _Java_NET_worlds_core_SystemInfo_GetDiskFreeSpace@12 [Global]
// programa: gamma.dll

uint _Java_NET_worlds_core_SystemInfo_GetDiskFreeSpace_12
               (int *param_1,undefined4 param_2,int param_3)

{
  BOOL BVar1;
  LPCSTR lpRootPathName;
  uint uVar2;
  DWORD local_20;
  DWORD local_1c;
  DWORD local_18;
  DWORD local_14;
  
                    /* 0x42020  168  _Java_NET_worlds_core_SystemInfo_GetDiskFreeSpace@12 */
  lpRootPathName = (LPCSTR)0x0;
  if (param_3 != 0) {
    lpRootPathName = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  }
  uVar2 = 0;
  BVar1 = GetDiskFreeSpaceA(lpRootPathName,&local_20,&local_1c,&local_18,&local_14);
  if (BVar1 != 0) {
    uVar2 = local_1c * local_20 * local_18 >> 10;
  }
  if (lpRootPathName != (LPCSTR)0x0) {
    (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpRootPathName);
  }
  return uVar2;
}


