// 004142b0 _Java_NET_worlds_scape_Camera_cameraNativeInit@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Camera_cameraNativeInit_8(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
                    /* 0x142b0  196  _Java_NET_worlds_scape_Camera_cameraNativeInit@8 */
  if (DAT_00489470 == 0) {
    uVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_Camera_0046fbb8);
    DAT_00489470 = (**(code **)(*param_1 + 0x54))(param_1,uVar2);
    if (DAT_00489470 == 0) {
      FUN_00402800(s_nCamera_0046fbd0,0x72);
    }
    DAT_00489478 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489470,s_cameraMode_0046fbdc,&DAT_0046fbd8);
    DAT_0048947c = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489470,s_unpickSpot_0046fc08,
                              s_LNET_worlds_scape_Point3Temp__0046fbe8);
    bVar1 = false;
    if ((DAT_00489478 != 0) && (DAT_0048947c != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nCamera_0046fbd0,0x77);
    }
    DAT_0049fe14 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489470,s_xPick_0046fc18,&DAT_0046fc14);
    DAT_0049ff30 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489470,s_yPick_0046fc20,&DAT_0046fc14);
    bVar1 = false;
    if ((DAT_0049fe14 != 0) && (DAT_0049ff30 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nCamera_0046fbd0,0x7b);
    }
    DAT_00489480 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489470,s_cameraID_0046fc28,&DAT_0046fbd8);
    if (DAT_00489480 == 0) {
      FUN_00402800(s_nCamera_0046fbd0,0x7e);
    }
    DAT_00489484 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489470,s_lookAround_0046fc54,
                              s_LNET_worlds_scape_Transform__0046fc34);
    if (DAT_00489484 == 0) {
      FUN_00402800(s_nCamera_0046fbd0,0x82);
    }
    DAT_00489488 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489470,s_pickedObj_0046fc7c,
                              s_LNET_worlds_scape_WObject__0046fc60);
    if (DAT_00489488 == 0) {
      FUN_00402800(s_nCamera_0046fbd0,0x86);
    }
    DAT_00489474 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489470,s_alwaysClearBackground_0046fc8c,&DAT_0046fc88);
    if (DAT_00489474 == 0) {
      FUN_00402800(s_nCamera_0046fbd0,0x8a);
    }
  }
  return;
}


