// 00404290 _Java_NET_worlds_network_DDEMLClass_nativeInit@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_network_DDEMLClass_nativeInit_8(int *param_1)

{
  undefined4 uVar1;
  
                    /* 0x4290  179  _Java_NET_worlds_network_DDEMLClass_nativeInit@8 */
  if (DAT_00489078 == 0) {
    uVar1 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_network_DDEMLClass_0046d59c);
    DAT_00489078 = (**(code **)(*param_1 + 0x54))(param_1,uVar1);
    if (DAT_00489078 == 0) {
      FUN_00402800(s_nDDEMLClass_0046d590,0x11d);
    }
    DAT_0048907c = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489078,s_DDEMLptr_0046d5c0,&DAT_0046d5bc);
    if (DAT_0048907c == 0) {
      FUN_00402800(s_nDDEMLClass_0046d590,0x120);
    }
  }
  return;
}


