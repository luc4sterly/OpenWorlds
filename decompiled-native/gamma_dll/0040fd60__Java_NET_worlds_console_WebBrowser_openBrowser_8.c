// 0040fd60 _Java_NET_worlds_console_WebBrowser_openBrowser@8 [Global]
// programa: gamma.dll

int * _Java_NET_worlds_console_WebBrowser_openBrowser_8(int *param_1,undefined4 param_2)

{
  char cVar1;
  HRESULT HVar2;
  undefined4 uVar3;
  int *local_1c;
  HWND local_18;
  HWND local_14;
  
                    /* 0xfd60  76  _Java_NET_worlds_console_WebBrowser_openBrowser@8 */
  local_1c = (int *)0x0;
  HVar2 = CoCreateInstance((IID *)&DAT_00466e60,(LPUNKNOWN)0x0,5,(IID *)&DAT_00466e90,&local_1c);
  if (HVar2 == 0) {
    (**(code **)(*local_1c + 0xac))(local_1c,0);
    (**(code **)(*local_1c + 0xb4))(local_1c,0);
    (**(code **)(*local_1c + 0xc4))(local_1c,0);
    uVar3 = (**(code **)(*param_1 + 0x240))(param_1,param_2,s_toolbarON_0046ef8c,&DAT_0046ef88);
    cVar1 = (**(code **)(*param_1 + 0x248))(param_1,param_2,uVar3);
    if (cVar1 == '\0') {
      uVar3 = 0;
    }
    else {
      uVar3 = 0xffffffff;
    }
    (**(code **)(*local_1c + 0xbc))(local_1c,uVar3);
    uVar3 = (**(code **)(*param_1 + 0x240))(param_1,param_2,s_windowFrameON_0046ef98,&DAT_0046ef88);
    cVar1 = (**(code **)(*param_1 + 0x248))(param_1,param_2,uVar3);
    if (cVar1 == '\0') {
      (**(code **)(*local_1c + 0x94))(local_1c,&local_18);
      SetWindowLongA(local_18,-0x10,0x10000000);
      SetWindowPos(local_18,(HWND)0xffffffff,0,0,0,0,3);
    }
    uVar3 = (**(code **)(*param_1 + 0x240))(param_1,param_2,s__stayMinimized_0046efa8,&DAT_0046ef88)
    ;
    cVar1 = (**(code **)(*param_1 + 0x248))(param_1,param_2,uVar3);
    if (cVar1 != '\0') {
      (**(code **)(*local_1c + 0x94))(local_1c,&local_14);
      ShowWindow(local_14,6);
    }
    return local_1c;
  }
  FUN_00402930(param_1,(byte *)s_java_io_IOException_0046ef74,s_nWebBrowser_0046ef68);
  return (int *)0x0;
}


