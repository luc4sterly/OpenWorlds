// 004421a0 _Java_NET_worlds_core_SystemInfo_GetTotalPhysicalMemory@8 [Global]
// program: gamma.dll

uint _Java_NET_worlds_core_SystemInfo_GetTotalPhysicalMemory_8(void)

{
  _MEMORYSTATUS local_24;
  
                    /* 0x421a0  174  _Java_NET_worlds_core_SystemInfo_GetTotalPhysicalMemory@8 */
  local_24.dwLength = 0x20;
  GlobalMemoryStatus(&local_24);
  if (0x7fffffff < local_24.dwTotalPhys) {
    local_24.dwTotalPhys = 0x7fffffff;
  }
  return local_24.dwTotalPhys;
}


