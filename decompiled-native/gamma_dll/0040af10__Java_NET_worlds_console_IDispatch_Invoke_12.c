// 0040af10 _Java_NET_worlds_console_IDispatch_Invoke@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_IDispatch_Invoke_12
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
                    /* 0xaf10  30  _Java_NET_worlds_console_IDispatch_Invoke@12 */
  piVar1 = (int *)_Java_NET_worlds_console_IUnknown_getPtr_8(param_1,param_2);
  local_28 = FUN_0040a420(param_1,param_3);
  local_24 = DAT_00489130;
  uStack_20 = DAT_00489134;
  uStack_1c = DAT_00489138;
  uStack_18 = DAT_0048913c;
  iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,&DAT_00466e50,&local_28,1,0x400,&local_14);
  Ordinal_6(local_28);
  if (iVar2 != 0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e4a8,
                 s_IDispatch__bad_function_name_0046e4bc);
  }
  iVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,local_14,&DAT_00466e50,0x400,1,&local_24,0,0,0);
  if (iVar2 != 0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e4a8,
                 s_IDispatch__unable_to_invoke_func_0046e4dc);
  }
  return;
}


