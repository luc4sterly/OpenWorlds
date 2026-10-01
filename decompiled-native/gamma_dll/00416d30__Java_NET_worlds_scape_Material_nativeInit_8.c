// 00416d30 _Java_NET_worlds_scape_Material_nativeInit@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_Material_nativeInit_8(int *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  
                    /* 0x16d30  252  _Java_NET_worlds_scape_Material_nativeInit@8 */
  if (DAT_004a000c == 0) {
    uVar4 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_Material_00470110);
    DAT_004a000c = (**(code **)(*param_1 + 0x54))(param_1,uVar4);
    uVar4 = (**(code **)(*param_1 + 0x18))(param_1,s_java_awt_Color_0047012c);
    DAT_00489540 = (**(code **)(*param_1 + 0x54))(param_1,uVar4);
    bVar1 = false;
    if ((DAT_004a000c != 0) && (DAT_00489540 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nMaterial_0047013c,0x32);
    }
    DAT_0049fa08 = (**(code **)(*param_1 + 0x178))(param_1,DAT_004a000c,&DAT_0047014c,&DAT_00470148)
    ;
    DAT_004a031c = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004a000c,s_textures_0047016c,
                              s__LNET_worlds_scape_Texture__00470150);
    DAT_0049fce8 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004a000c,s_ambient_0047017c,&DAT_00470178);
    DAT_0049fa00 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004a000c,s_diffuse_00470184,&DAT_00470178);
    DAT_0049fce4 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004a000c,s_specular_0047018c,&DAT_00470178);
    DAT_0049ff48 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004a000c,s_opacity_00470198,&DAT_00470178);
    DAT_0049fb8c = (**(code **)(*param_1 + 0x178))(param_1,DAT_004a000c,&DAT_004701a4,&DAT_004701a0)
    ;
    DAT_0049fb94 = (**(code **)(*param_1 + 0x178))(param_1,DAT_004a000c,&DAT_004701a8,&DAT_004701a0)
    ;
    DAT_0049fb9c = (**(code **)(*param_1 + 0x178))(param_1,DAT_004a000c,&DAT_004701ac,&DAT_004701a0)
    ;
    DAT_0049ff5c = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_004a000c,s_smooth_004701b4,&DAT_004701b0);
    DAT_00489544 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_00489540,s_<init>_004701c4,s__III_V_004701bc);
    bVar1 = false;
    if ((DAT_0049fa08 != 0) && (DAT_004a031c != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nMaterial_0047013c,0x41);
    }
    bVar1 = false;
    bVar2 = false;
    if ((DAT_0049fce8 != 0) && (DAT_0049fa00 != 0)) {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_0049fce4 != 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      FUN_00402800(s_nMaterial_0047013c,0x42);
    }
    bVar1 = false;
    bVar3 = false;
    bVar2 = false;
    if ((DAT_0049ff48 != 0) && (DAT_0049fb8c != 0)) {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_0049fb94 != 0)) {
      bVar2 = true;
    }
    if ((bVar2) && (DAT_0049fb9c != 0)) {
      bVar3 = true;
    }
    if (!bVar3) {
      FUN_00402800(s_nMaterial_0047013c,0x43);
    }
    bVar1 = false;
    if ((DAT_0049ff5c != 0) && (DAT_00489544 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nMaterial_0047013c,0x44);
    }
  }
  return;
}


