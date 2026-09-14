// 00421ce0 _Java_NET_worlds_scape_ImageConverter_nativeInit@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_ImageConverter_nativeInit_8(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
                    /* 0x21ce0  237  _Java_NET_worlds_scape_ImageConverter_nativeInit@8 */
  if (DAT_0049d18c == 0) {
    uVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_ImageConverter_00471434);
    DAT_0049d18c = (**(code **)(*param_1 + 0x54))(param_1,uVar2);
    if (DAT_0049d18c == 0) {
      FUN_00402800(s_nScapePicTexture_004713c4,0x72);
    }
    DAT_0049d1a4 = (**(code **)(*param_1 + 0x178))(param_1,DAT_0049d18c,&DAT_00471454,&DAT_004713d8)
    ;
    DAT_0049d1a8 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d18c,s_pixelPtr_0047145c,&DAT_004713d8);
    DAT_0049d1ac = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d18c,s_width_00471468,&DAT_004713d8);
    DAT_0049d1b0 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d18c,s_height_00471470,&DAT_004713d8);
    DAT_0049d1b8 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d18c,s_urlName_0047148c,s_Ljava_lang_String__00471478)
    ;
    DAT_0049d1b4 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d18c,s_transparentColor_00471494,&DAT_004713d8);
    bVar1 = false;
    if ((DAT_0049d1a4 != 0) && (DAT_0049d1a8 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nScapePicTexture_004713c4,0x7d);
    }
    bVar1 = false;
    if ((DAT_0049d1ac != 0) && (DAT_0049d1b0 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nScapePicTexture_004713c4,0x7e);
    }
    bVar1 = false;
    if ((DAT_0049d1b4 != 0) && (DAT_0049d1b8 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nScapePicTexture_004713c4,0x7f);
    }
  }
  return;
}


