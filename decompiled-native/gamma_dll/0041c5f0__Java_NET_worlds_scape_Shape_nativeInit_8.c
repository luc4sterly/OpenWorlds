// 0041c5f0 _Java_NET_worlds_scape_Shape_nativeInit@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_Shape_nativeInit_8(int *param_1)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  
                    /* 0x1c5f0  294  _Java_NET_worlds_scape_Shape_nativeInit@8 */
  if (DAT_00489640 == 0) {
    uVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_Shape_00470900);
    DAT_00489640 = (**(code **)(*param_1 + 0x54))(param_1,uVar3);
    uVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_ShapeLoader_00470918);
    DAT_00489644 = (**(code **)(*param_1 + 0x54))(param_1,uVar3);
    uVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_Rect_00470938);
    DAT_00489648 = (**(code **)(*param_1 + 0x54))(param_1,uVar3);
    uVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_TwoWayPortal_00470950);
    DAT_0048964c = (**(code **)(*param_1 + 0x54))(param_1,uVar3);
    bVar1 = false;
    bVar2 = false;
    if ((DAT_00489640 != 0) && (DAT_00489644 != 0)) {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_00489648 != 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      FUN_00402800(s_nShape_00470970,0x73);
    }
    if (DAT_0048964c == 0) {
      FUN_00402800(s_nShape_00470970,0x74);
    }
    DAT_00489660 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489644,s_shape_00470994,
                              s_LNET_worlds_scape_Shape__00470978);
    DAT_00489664 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489640,s_animatableClumpID_004709a0,&DAT_0047099c);
    DAT_0048965c = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_00489640,s_pendingShape_004709b4,&DAT_0047099c);
    DAT_00489650 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_00489644,s_startTextureLoad_004709f4,
                              s__Ljava_lang_String_LNET_worlds_n_004709c4);
    bVar1 = false;
    if ((DAT_0048965c != 0) && (DAT_00489650 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nShape_00470970,0x7e);
    }
    bVar1 = false;
    if ((DAT_00489660 != 0) && (DAT_00489664 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nShape_00470970,0x7f);
    }
    DAT_00489654 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_00489648,s_<init>_00470a30,
                              s__FFFFFFLNET_worlds_scape_Materia_00470a08);
    DAT_00489658 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_0048964c,s_<init>_00470a30,
                              s__Ljava_lang_String_FFFFFF_V_00470a38);
    bVar1 = false;
    if ((DAT_00489654 != 0) && (DAT_00489658 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nShape_00470970,0x85);
    }
  }
  return;
}


