// 0040ad80 _Java_NET_worlds_console_IClassFactory_nActivate@12 [Global]
// program: gamma.dll

undefined4
_Java_NET_worlds_console_IClassFactory_nActivate_12
          (int *param_1,undefined4 param_2,undefined4 param_3)

{
  LPUNKNOWN pUnk;
  LPCOLESTR lpsz;
  HRESULT HVar1;
  CLSID local_24;
  DWORD local_14;
  
                    /* 0xad80  28  _Java_NET_worlds_console_IClassFactory_nActivate@12 */
  pUnk = (LPUNKNOWN)_Java_NET_worlds_console_IUnknown_getPtr_8(param_1,param_2);
  lpsz = (LPCOLESTR)FUN_0040a420(param_1,param_3);
  if (lpsz == (LPCOLESTR)0x0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e3e0,s_Out_of_memory_0046e3f4);
    return 0;
  }
  HVar1 = CLSIDFromString(lpsz,&local_24);
  Ordinal_6(lpsz);
  if (HVar1 != 0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e3e0,s_Unable_to_determine_CLSID_0046e404
                );
    return 0;
  }
  HVar1 = CoRegisterClassObject(&local_24,pUnk,4,1,&local_14);
  if (HVar1 != 0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e3e0,
                 s_Failed_to_register_class_with_Ac_0046e420);
    return 0;
  }
  return local_14;
}


