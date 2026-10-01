// 0040a360 _Java_NET_worlds_console_StatMemNode_updateMemoryStatus@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_StatMemNode_updateMemoryStatus_8(int *param_1,undefined4 param_2)

{
  _MEMORYSTATUS local_30;
  
                    /* 0xa360  72  _Java_NET_worlds_console_StatMemNode_updateMemoryStatus@8 */
  local_30.dwLength = 0x20;
  GlobalMemoryStatus(&local_30);
  if (0x7fffffff < local_30.dwTotalPhys) {
    local_30.dwTotalPhys = 0x7fffffff;
  }
  if (0x7fffffff < local_30.dwAvailPhys) {
    local_30.dwAvailPhys = 0x7fffffff;
  }
  if (0x7fffffff < local_30.dwTotalPageFile) {
    local_30.dwTotalPageFile = 0x7fffffff;
  }
  if (0x7fffffff < local_30.dwAvailPageFile) {
    local_30.dwAvailPageFile = 0x7fffffff;
  }
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_004890d4,local_30.dwTotalPhys);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_004890d8,local_30.dwAvailPhys);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_004890dc,local_30.dwTotalPageFile);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_004890e0,local_30.dwAvailPageFile);
  return;
}


