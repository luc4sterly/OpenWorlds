// 00413b30 _Java_NET_worlds_scape_Hologram_nativeInit@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_Hologram_nativeInit_8(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
                    /* 0x13b30  232  _Java_NET_worlds_scape_Hologram_nativeInit@8 */
  if (DAT_00489448 == 0) {
    uVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_Hologram_0046fae0);
    DAT_00489448 = (**(code **)(*param_1 + 0x54))(param_1,uVar2);
    if (DAT_00489448 == 0) {
      FUN_00402800(s_nHologram_0046fafc,0x39);
    }
    DAT_0048944c = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489448,s_scaleDist_0046fb0c,&DAT_0046fb08);
    DAT_00489450 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489448,s_origTransformID_0046fb1c,&DAT_0046fb18);
    DAT_00489454 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_00489448,s_getNumSides_0046fb30,&DAT_0046fb2c);
    DAT_00489458 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_00489448,s_setActiveSide_0046fb44,&DAT_0046fb3c);
    bVar1 = false;
    if ((DAT_0048944c != 0) && (DAT_00489450 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nHologram_0046fafc,0x42);
    }
    bVar1 = false;
    if ((DAT_00489454 != 0) && (DAT_00489458 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nHologram_0046fafc,0x43);
    }
  }
  return;
}


