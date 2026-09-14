// 00402e30 _Java_NET_worlds_core_Std_getPerformanceFrequency@8 [Global]
// programa: gamma.dll

LARGE_INTEGER _Java_NET_worlds_core_Std_getPerformanceFrequency_8(void)

{
  BOOL BVar1;
  LARGE_INTEGER local_c;
  
                    /* 0x2e30  159  _Java_NET_worlds_core_Std_getPerformanceFrequency@8 */
  BVar1 = QueryPerformanceFrequency(&local_c);
  if (BVar1 != 0) {
    return (LARGE_INTEGER)local_c.QuadPart;
  }
  return (LARGE_INTEGER)0.0;
}


