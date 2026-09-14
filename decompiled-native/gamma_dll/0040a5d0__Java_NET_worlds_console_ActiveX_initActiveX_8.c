// 0040a5d0 _Java_NET_worlds_console_ActiveX_initActiveX@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_ActiveX_initActiveX_8(int *param_1)

{
  HRESULT HVar1;
  
                    /* 0xa5d0  16  _Java_NET_worlds_console_ActiveX_initActiveX@8 */
  HVar1 = CoInitialize((LPVOID)0x0);
  if ((HVar1 != 0) && (HVar1 != 1)) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e090,
                 s_nActiveX__Couldn_t_initialize_CO_0046e108);
  }
  return;
}


