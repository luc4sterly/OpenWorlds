// 00402e60 _Java_NET_worlds_core_Std_getPerformanceCount@8 [Global]
// program: gamma.dll

LARGE_INTEGER _Java_NET_worlds_core_Std_getPerformanceCount_8(void)

{
  BOOL BVar1;
  LARGE_INTEGER local_c;
  
                    /* 0x2e60  158  _Java_NET_worlds_core_Std_getPerformanceCount@8 */
  BVar1 = QueryPerformanceCounter(&local_c);
  if (BVar1 != 0) {
    return (LARGE_INTEGER)local_c.QuadPart;
  }
  return (LARGE_INTEGER)0.0;
}


