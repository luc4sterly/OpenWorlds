// 0040ae60 _Java_NET_worlds_console_IClassFactory_nDeactivate@16 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_IClassFactory_nDeactivate_16
               (int *param_1,undefined4 param_2,DWORD param_3)

{
  HRESULT HVar1;
  
                    /* 0xae60  29  _Java_NET_worlds_console_IClassFactory_nDeactivate@16 */
  HVar1 = CoRevokeClassObject(param_3);
  if (HVar1 == -0x7fff0001) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e3e0,
                 s_Unexpected_registration_ID_0046e448);
    return;
  }
  if (HVar1 == -0x7ff8fff2) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e3e0,s_Out_of_memory_0046e3f4);
    return;
  }
  if (HVar1 < 0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e3e0,
                 s_Failed_to_revoke_class_factory_0046e464);
  }
  return;
}


