// 00441f30 _Java_NET_worlds_console_NSProtocolHandler_createLocal@8 [Global]
// program: gamma.dll

uint * _Java_NET_worlds_console_NSProtocolHandler_createLocal_8(int *param_1)

{
  uint *puVar1;
  
                    /* 0x41f30  54  _Java_NET_worlds_console_NSProtocolHandler_createLocal@8 */
  puVar1 = FUN_0044e010(8);
  if (puVar1 == (uint *)0x0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_00478bd4,s_Out_of_memory_00478bc4);
    return (uint *)0x0;
  }
  *puVar1 = (uint)&DAT_00477514;
  *puVar1 = (uint)&DAT_00478d0c;
  *puVar1 = (uint)&PTR_LAB_0046e3a4;
  puVar1[1] = 1;
  *puVar1 = (uint)&PTR_LAB_00478ce8;
  return puVar1;
}


