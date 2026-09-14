// 00442470 _Java_NET_worlds_core_SystemInfo_GetProcessorType@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_core_SystemInfo_GetProcessorType_8(int *param_1)

{
  _union_530 local_2c [6];
  int local_14;
  uint local_c;
  
                    /* 0x42470  171  _Java_NET_worlds_core_SystemInfo_GetProcessorType@8 */
  GetSystemInfo((LPSYSTEM_INFO)&local_2c[0].s);
  if (local_2c[0].s.wProcessorArchitecture != 0) {
    (**(code **)(*param_1 + 0x29c))(param_1,s_Unknown_Architecture_00478dd0);
    return;
  }
  if (local_14 == 0x182) {
    (**(code **)(*param_1 + 0x29c))(param_1,s_Intel_386_00478de8);
    return;
  }
  if (local_14 == 0x1e6) {
    (**(code **)(*param_1 + 0x29c))(param_1,s_Intel_486_00478df4);
    return;
  }
  if (local_14 == 0x24a) {
    (**(code **)(*param_1 + 0x29c))(param_1,s_Intel_Pentium__Generic___I_II_II_00478e00);
    return;
  }
  switch(local_c & 0xffff) {
  case 3:
    (**(code **)(*param_1 + 0x29c))(param_1,s_Intel_80386_00478e28);
    return;
  case 4:
    (**(code **)(*param_1 + 0x29c))(param_1,s_Intel_80486_00478e34);
    return;
  case 5:
    (**(code **)(*param_1 + 0x29c))(param_1,s_Intel_80586_00478e40);
    return;
  case 6:
    (**(code **)(*param_1 + 0x29c))(param_1,s_Intel_Pentium_Pro_or_II_00478e4c);
    return;
  default:
    (**(code **)(*param_1 + 0x29c))(param_1,s_Unknown_Processor_Type_00478e64);
    return;
  }
}


