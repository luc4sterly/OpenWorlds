// 00412b60 _Java_NET_worlds_scape_WObject_nativeInit@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_WObject_nativeInit_8(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
                    /* 0x12b60  362  _Java_NET_worlds_scape_WObject_nativeInit@8 */
  if (DAT_004893c0 == 0) {
    uVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_WObject_0046f688);
    DAT_004893c0 = (**(code **)(*param_1 + 0x54))(param_1,uVar2);
    if (DAT_004893c0 == 0) {
      FUN_00402800(s_nWObject_0046f6a4,0x57);
    }
    DAT_0049fba0 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004893c0,s_highlightID_0046f6b4,&DAT_0046f6b0);
    DAT_0049fb90 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004893c0,s_clumpID_0046f6c0,&DAT_0046f6b0);
    DAT_0049f964 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004893c0,s_flags_0046f6c8,&DAT_0046f6b0);
    DAT_004a0428 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_004893c0,s_setVisible_0046f6d8,&DAT_0046f6d0);
    DAT_0049fa74 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_004893c0,s_setAutobuilt_0046f6e4,&DAT_0046f6d0);
    DAT_0049fcf0 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_004893c0,&DAT_0046f714,
                              s__LNET_worlds_scape_WObject__V_0046f6f4);
    bVar1 = false;
    if ((DAT_0049fba0 != 0) && (DAT_0049fb90 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nWObject_0046f6a4,100);
    }
    bVar1 = false;
    if ((DAT_0049f964 != 0) && (DAT_004a0428 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nWObject_0046f6a4,0x65);
    }
    bVar1 = false;
    if ((DAT_0049fa74 != 0) && (DAT_0049fcf0 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nWObject_0046f6a4,0x66);
    }
  }
  return;
}


