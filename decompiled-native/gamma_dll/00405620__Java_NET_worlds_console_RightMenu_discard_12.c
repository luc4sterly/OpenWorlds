// 00405620 _Java_NET_worlds_console_RightMenu_discard@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_RightMenu_discard_12
               (undefined4 param_1,undefined4 param_2,HMENU param_3)

{
  BOOL BVar1;
  
                    /* 0x5620  61  _Java_NET_worlds_console_RightMenu_discard@12 */
  if (param_3 != (HMENU)0x0) {
    BVar1 = DestroyMenu(param_3);
    if (BVar1 == 0) {
      FUN_00402800(s_nRightMenu_0046d7c8,0x3c);
    }
  }
  return;
}


