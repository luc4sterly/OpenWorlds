// 00401650 _Java_NET_worlds_core_FastDataInput_nativeInit@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_core_FastDataInput_nativeInit_8(int *param_1)

{
  undefined4 uVar1;
  
                    /* 0x1650  120  _Java_NET_worlds_core_FastDataInput_nativeInit@8 */
  if (DAT_00489020 == 0) {
    uVar1 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_core_FastDataInput_0046d1e4);
    DAT_00489020 = (**(code **)(*param_1 + 0x54))(param_1,uVar1);
    if (DAT_00489020 == 0) {
      FUN_00402800(s_nFastDataInput_0046d204,0x110);
    }
    DAT_00489024 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489020,s_nativeInfo_0046d218,&DAT_0046d214);
    if (DAT_00489024 == 0) {
      FUN_00402800(s_nFastDataInput_0046d204,0x114);
    }
  }
  return;
}


