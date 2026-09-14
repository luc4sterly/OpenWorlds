// 004422c0 _Java_NET_worlds_core_SystemInfo_GetAvailPagedMemory@8 [Global]
// programa: gamma.dll

uint _Java_NET_worlds_core_SystemInfo_GetAvailPagedMemory_8(void)

{
  _MEMORYSTATUS local_24;
  
                    /* 0x422c0  165  _Java_NET_worlds_core_SystemInfo_GetAvailPagedMemory@8 */
  local_24.dwLength = 0x20;
  GlobalMemoryStatus(&local_24);
  if (0x7fffffff < local_24.dwAvailPageFile) {
    local_24.dwAvailPageFile = 0x7fffffff;
  }
  return local_24.dwAvailPageFile;
}


