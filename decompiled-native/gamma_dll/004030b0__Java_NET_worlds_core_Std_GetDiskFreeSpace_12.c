// 004030b0 _Java_NET_worlds_core_Std_GetDiskFreeSpace@12 [Global]
// programa: gamma.dll

uint _Java_NET_worlds_core_Std_GetDiskFreeSpace_12(int *param_1,undefined4 param_2,int param_3)

{
  BOOL BVar1;
  uint uVar2;
  LPCSTR lpDirectoryName;
  ULARGE_INTEGER local_28;
  ULARGE_INTEGER local_20;
  ULARGE_INTEGER local_18;
  
                    /* 0x30b0  149  _Java_NET_worlds_core_Std_GetDiskFreeSpace@12 */
  lpDirectoryName = (LPCSTR)0x0;
  if (param_3 != 0) {
    lpDirectoryName = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  }
  uVar2 = 0xffffffff;
  BVar1 = GetDiskFreeSpaceExA(lpDirectoryName,&local_18,&local_28,&local_20);
  if (BVar1 != 0) {
    uVar2 = local_18.s.LowPart >> 10 | local_18.s.HighPart << 0x16;
  }
  if (lpDirectoryName != (LPCSTR)0x0) {
    (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpDirectoryName);
  }
  return uVar2;
}


