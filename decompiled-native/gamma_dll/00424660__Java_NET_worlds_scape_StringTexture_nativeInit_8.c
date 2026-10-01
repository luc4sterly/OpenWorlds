// 00424660 _Java_NET_worlds_scape_StringTexture_nativeInit@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_StringTexture_nativeInit_8(int *param_1)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  
                    /* 0x24660  298  _Java_NET_worlds_scape_StringTexture_nativeInit@8 */
  if (DAT_0049d200 == 0) {
    uVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_StringTexture_004718a0);
    DAT_0049d200 = (**(code **)(*param_1 + 0x54))(param_1,uVar3);
    uVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_java_awt_Color_004718c0);
    DAT_0049d204 = (**(code **)(*param_1 + 0x54))(param_1,uVar3);
    bVar1 = false;
    if ((DAT_0049d200 != 0) && (DAT_0049d204 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nStringTexture_004718d0,0x43);
    }
    DAT_0049d218 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d200,s__size_004718e4,&DAT_004718e0);
    DAT_0049d21c = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d200,s__length_004718ec,&DAT_004718e0);
    DAT_0049d220 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d200,s_textureID_004718f4,&DAT_004718e0);
    DAT_0049d210 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d200,s__fore_00471914,s_Ljava_awt_Color__00471900);
    DAT_0049d214 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d200,s__back_0047191c,s_Ljava_awt_Color__00471900);
    DAT_0049d208 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d200,s__array_00471928,&DAT_00471924);
    DAT_0049d20c = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d200,s__font_00471944,s_Ljava_lang_String__00471930);
    DAT_0049d224 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_0049d204,s_getRGB_00471950,&DAT_0047194c);
    bVar1 = false;
    bVar2 = false;
    if ((DAT_0049d208 != 0) && (DAT_0049d20c != 0)) {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_0049d224 != 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      FUN_00402800(s_nStringTexture_004718d0,0x51);
    }
    bVar1 = false;
    bVar2 = false;
    if ((DAT_0049d218 != 0) && (DAT_0049d21c != 0)) {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_0049d210 != 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      FUN_00402800(s_nStringTexture_004718d0,0x52);
    }
    bVar1 = false;
    if ((DAT_0049d214 != 0) && (DAT_0049d220 != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nStringTexture_004718d0,0x53);
    }
  }
  return;
}


