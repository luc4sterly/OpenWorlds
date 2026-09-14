// 004125c0 _Java_NET_worlds_scape_Room_nativeInit@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Room_nativeInit_8(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
                    /* 0x125c0  275  _Java_NET_worlds_scape_Room_nativeInit@8 */
  if (DAT_00489388 == 0) {
    uVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_Room_0046f548);
    DAT_00489388 = (**(code **)(*param_1 + 0x54))(param_1,uVar2);
    if (DAT_00489388 == 0) {
      FUN_00402800(s_nRoom_0046f560,0x31);
    }
    DAT_00489394 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489388,s_sceneID_0046f56c,&DAT_0046f568);
    DAT_0048938c = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_00489388,s_aboutToDraw_0046f578,&DAT_0046f574);
    DAT_0049fcc8 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489388,s_skyColor_0046f598,s_Ljava_awt_Color__0046f584);
    DAT_0049fa78 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489388,s_groundColor_0046f5a4,
                              s_Ljava_awt_Color__0046f584);
    DAT_0049fa10 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489388,s_highlightTarget_0046f5cc,
                              s_LNET_worlds_scape_WObject__0046f5b0);
    DAT_0049fa68 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489388,s_infiniteBackground_0046f600,
                              s_LNET_worlds_scape_RoomEnvironmen_0046f5dc);
    DAT_0049ff54 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489388,s_environment_0046f614,
                              s_LNET_worlds_scape_RoomEnvironmen_0046f5dc);
    bVar1 = false;
    if ((DAT_00489394 != 0) && (DAT_0048938c != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nRoom_0046f560,0x3f);
    }
    bVar1 = false;
    if ((DAT_0049fa10 != 0) && (DAT_0049ff54 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nRoom_0046f560,0x40);
    }
    if (DAT_0049fa68 == 0) {
      FUN_00402800(s_nRoom_0046f560,0x41);
    }
    uVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_RoomEnvironment_0046f620);
    DAT_00489390 = (**(code **)(*param_1 + 0x54))(param_1,uVar2);
    if (DAT_00489390 == 0) {
      FUN_00402800(s_nRoom_0046f560,0x45);
    }
    DAT_00489398 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489390,s_sceneID_0046f56c,&DAT_0046f568);
    if (DAT_00489398 == 0) {
      FUN_00402800(s_nRoom_0046f560,0x48);
    }
  }
  return;
}


