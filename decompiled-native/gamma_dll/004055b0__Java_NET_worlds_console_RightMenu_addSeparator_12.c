// 004055b0 _Java_NET_worlds_console_RightMenu_addSeparator@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_RightMenu_addSeparator_12
               (undefined4 param_1,undefined4 param_2,HMENU param_3)

{
  BOOL BVar1;
  
                    /* 0x55b0  58  _Java_NET_worlds_console_RightMenu_addSeparator@12 */
  BVar1 = AppendMenuA(param_3,0x800,0,(LPCSTR)0x0);
  if (BVar1 == 0) {
    FUN_00402800(s_nRightMenu_0046d7c8,0x27);
  }
  return;
}


