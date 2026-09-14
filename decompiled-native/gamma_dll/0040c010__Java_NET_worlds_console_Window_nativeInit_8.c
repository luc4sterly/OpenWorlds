// 0040c010 _Java_NET_worlds_console_Window_nativeInit@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_Window_nativeInit_8(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
                    /* 0xc010  106  _Java_NET_worlds_console_Window_nativeInit@8 */
  if (DAT_004891a8 == 0) {
    uVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_console_Window_0046e8a8);
    DAT_004891a8 = (**(code **)(*param_1 + 0x54))(param_1,uVar2);
    if (DAT_004891a8 == 0) {
      FUN_00402800(s_nWindow_0046e8c4,0x106);
    }
    DAT_004891ac = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004891a8,s_windowInstancePtr_0046e8d0,&DAT_0046e8cc);
    DAT_004891b0 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004891a8,s_hWndGamma_0046e8e4,&DAT_0046e8cc);
    DAT_004891b4 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004891a8,s_hWndFrame_0046e8f0,&DAT_0046e8cc);
    if (DAT_004891ac == 0) {
      FUN_00402800(s_nWindow_0046e8c4,0x10c);
    }
    bVar1 = false;
    if ((DAT_004891b0 != 0) && (DAT_004891b4 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nWindow_0046e8c4,0x10d);
    }
  }
  return;
}


