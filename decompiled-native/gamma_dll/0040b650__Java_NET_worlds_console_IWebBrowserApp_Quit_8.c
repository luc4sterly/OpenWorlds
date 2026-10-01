// 0040b650 _Java_NET_worlds_console_IWebBrowserApp_Quit@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_IWebBrowserApp_Quit_8(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
                    /* 0xb650  50  _Java_NET_worlds_console_IWebBrowserApp_Quit@8 */
  piVar1 = (int *)_Java_NET_worlds_console_IUnknown_getPtr_8(param_1,param_2);
  iVar2 = (**(code **)(*piVar1 + 0x80))(piVar1);
  if (iVar2 != 0) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046e6f8,s_nIWebBrowserApp_0046e6e8);
  }
  return;
}


