// 00402360 _Java_NET_worlds_core_RegKey_nativeInit@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_core_RegKey_nativeInit_8(int *param_1)

{
  undefined4 uVar1;
  
                    /* 0x2360  145  _Java_NET_worlds_core_RegKey_nativeInit@8 */
  if (DAT_00489038 == 0) {
    uVar1 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_core_RegKey_0046d280);
    DAT_00489038 = (**(code **)(*param_1 + 0x54))(param_1,uVar1);
    if (DAT_00489038 == 0) {
      FUN_00402800(s_nRegKey_0046d298,0x1d);
    }
    DAT_0048903c = (**(code **)(*param_1 + 0x178))(param_1,DAT_00489038,&DAT_0046d2a4,&DAT_0046d2a0)
    ;
    if (DAT_0048903c == 0) {
      FUN_00402800(s_nRegKey_0046d298,0x20);
    }
  }
  return;
}


