// 0040b690 _Java_NET_worlds_console_IWebBrowserApp_Navigate@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_IWebBrowserApp_Navigate_12
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
                    /* 0xb690  49  _Java_NET_worlds_console_IWebBrowserApp_Navigate@12 */
  piVar1 = (int *)_Java_NET_worlds_console_IUnknown_getPtr_8(param_1,param_2);
  uVar2 = FUN_0040a420(param_1,param_3);
  local_20 = DAT_00489170;
  uStack_1c = DAT_00489174;
  uStack_18 = DAT_00489178;
  uStack_14 = DAT_0048917c;
  iVar3 = (**(code **)(*piVar1 + 0x2c))(piVar1,uVar2,&local_20,&local_20,&local_20,&local_20);
  Ordinal_6(uVar2);
  if (iVar3 != 0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e6f8,s_nIWebBrowserApp_0046e6e8);
  }
  return;
}


