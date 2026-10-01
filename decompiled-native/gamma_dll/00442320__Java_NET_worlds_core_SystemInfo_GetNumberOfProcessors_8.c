// 00442320 _Java_NET_worlds_core_SystemInfo_GetNumberOfProcessors@8 [Global]
// program: gamma.dll

DWORD _Java_NET_worlds_core_SystemInfo_GetNumberOfProcessors_8(void)

{
  _SYSTEM_INFO local_28;
  
                    /* 0x42320  169  _Java_NET_worlds_core_SystemInfo_GetNumberOfProcessors@8 */
  GetSystemInfo(&local_28);
  return local_28.dwNumberOfProcessors;
}


