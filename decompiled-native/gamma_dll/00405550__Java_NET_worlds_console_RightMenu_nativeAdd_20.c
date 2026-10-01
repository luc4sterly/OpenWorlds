// 00405550 _Java_NET_worlds_console_RightMenu_nativeAdd@20 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_RightMenu_nativeAdd_20
               (int *param_1,undefined4 param_2,undefined4 param_3,UINT_PTR param_4,HMENU param_5)

{
  LPCSTR lpNewItem;
  BOOL BVar1;
  
                    /* 0x5550  62  _Java_NET_worlds_console_RightMenu_nativeAdd@20 */
  lpNewItem = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  BVar1 = AppendMenuA(param_5,0,param_4,lpNewItem);
  if (BVar1 == 0) {
    FUN_00402800(s_nRightMenu_0046d7c8,0x20);
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpNewItem);
  return;
}


