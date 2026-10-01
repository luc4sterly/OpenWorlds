// 0040b560 _Java_NET_worlds_console_IWebBrowserApp_put_1StatusBar@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_IWebBrowserApp_put_1StatusBar_12
               (int *param_1,undefined4 param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  
                    /* 0xb560  52  _Java_NET_worlds_console_IWebBrowserApp_put_1StatusBar@12 */
  piVar1 = (int *)_Java_NET_worlds_console_IUnknown_getPtr_8(param_1,param_2);
  if (param_3 == '\0') {
    iVar2 = (**(code **)(*piVar1 + 0xac))(piVar1,0);
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0xac))(piVar1,0xffffffff);
  }
  if (iVar2 != 0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e6f8,s_nIWebBrowserApp_0046e6e8);
  }
  return;
}


