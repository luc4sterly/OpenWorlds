// 004202b0 _Java_NET_worlds_scape_Surface_nativeInit@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_Surface_nativeInit_8(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
                    /* 0x202b0  302  _Java_NET_worlds_scape_Surface_nativeInit@8 */
  if (DAT_0049fe08 == 0) {
    uVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_Surface_00471228);
    DAT_0049fe08 = (**(code **)(*param_1 + 0x54))(param_1,uVar2);
    if (DAT_0049fe08 == 0) {
      FUN_00402800(s_nSurface_00471244,0x32);
    }
    DAT_0049ff58 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049fe08,s_polygonIDs_00471254,&DAT_00471250);
    DAT_0049ff34 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049fe08,s_material_0047127c,
                              s_LNET_worlds_scape_Material__00471260);
    bVar1 = false;
    if ((DAT_0049ff58 != 0) && (DAT_0049ff34 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nSurface_00471244,0x37);
    }
  }
  return;
}


