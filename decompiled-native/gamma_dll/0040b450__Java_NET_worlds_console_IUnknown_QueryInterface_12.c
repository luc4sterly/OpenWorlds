// 0040b450 _Java_NET_worlds_console_IUnknown_QueryInterface@12 [Global]
// program: gamma.dll

undefined4
_Java_NET_worlds_console_IUnknown_QueryInterface_12
          (int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  HRESULT HVar3;
  undefined4 *puVar4;
  IID local_24;
  undefined4 local_14;
  
                    /* 0xb450  45  _Java_NET_worlds_console_IUnknown_QueryInterface@12 */
  uVar1 = (**(code **)(*param_1 + 0x7c))(param_1,param_2);
  iVar2 = (**(code **)(*param_1 + 0x178))(param_1,uVar1,s__pInterface_0046e628,&DAT_0046e624);
  if (iVar2 == 0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e610,s_Invalid_field_name_0046e634);
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)(**(code **)(*param_1 + 400))(param_1,param_2,iVar2);
    if (puVar4 == (undefined4 *)0x0) {
      FUN_00402930(param_1,(byte *)s_NET_worlds_console_OLEInvalidObj_0046e660,
                   s_No_C___mirror_object_0046e648);
    }
  }
  if (puVar4 == (undefined4 *)0x0) {
    return 0;
  }
  HVar3 = FUN_0040a4d0(param_1,param_3,&local_24);
  if (HVar3 != 0) {
    return 0;
  }
  iVar2 = (**(code **)*puVar4)(puVar4,&local_24,&local_14);
  if (iVar2 < 0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e610,
                 s_IUnknown_QueryInterface__interfa_0046e690);
    return 0;
  }
  return local_14;
}


