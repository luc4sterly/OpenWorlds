// 00442200 _Java_NET_worlds_core_SystemInfo_GetAvailPhysicalMemory@8 [Global]
// program: gamma.dll

uint _Java_NET_worlds_core_SystemInfo_GetAvailPhysicalMemory_8(void)

{
  _MEMORYSTATUS local_24;
  
                    /* 0x42200  166  _Java_NET_worlds_core_SystemInfo_GetAvailPhysicalMemory@8 */
  local_24.dwLength = 0x20;
  GlobalMemoryStatus(&local_24);
  if (0x7fffffff < local_24.dwAvailPhys) {
    local_24.dwAvailPhys = 0x7fffffff;
  }
  return local_24.dwAvailPhys;
}


