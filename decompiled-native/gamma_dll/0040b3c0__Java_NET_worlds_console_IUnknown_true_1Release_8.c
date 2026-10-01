// 0040b3c0 _Java_NET_worlds_console_IUnknown_true_1Release@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_IUnknown_true_1Release_8(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
                    /* 0xb3c0  48  _Java_NET_worlds_console_IUnknown_true_1Release@8 */
  uVar1 = (**(code **)(*param_1 + 0x7c))(param_1,param_2);
  iVar2 = (**(code **)(*param_1 + 0x178))(param_1,uVar1,s__pInterface_0046e628,&DAT_0046e624);
  if (iVar2 == 0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e610,s_Invalid_field_name_0046e634);
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(*param_1 + 400))(param_1,param_2,iVar2);
    if (piVar3 == (int *)0x0) {
      FUN_00402930(param_1,(byte *)s_NET_worlds_console_OLEInvalidObj_0046e660,
                   s_No_C___mirror_object_0046e648);
    }
  }
  if (piVar3 == (int *)0x0) {
    return;
  }
  (**(code **)(*piVar3 + 8))(piVar3);
  return;
}


