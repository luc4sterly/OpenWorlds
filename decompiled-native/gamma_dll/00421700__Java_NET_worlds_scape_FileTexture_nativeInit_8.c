// 00421700 _Java_NET_worlds_scape_FileTexture_nativeInit@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_FileTexture_nativeInit_8(int *param_1)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  
                    /* 0x21700  230  _Java_NET_worlds_scape_FileTexture_nativeInit@8 */
  if (DAT_0049d168 == 0) {
    uVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_FileTexture_00471310);
    DAT_0049d168 = (**(code **)(*param_1 + 0x54))(param_1,uVar3);
    if (DAT_0049d168 == 0) {
      FUN_00402800(s_nFileTexture_00471330,0x26);
    }
    DAT_0049d16c = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d168,s__urlName_00471354,s_Ljava_lang_String__00471340
                             );
    DAT_0049d170 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d168,s_textureID_00471364,&DAT_00471360);
    DAT_0049d174 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_0049d168,s_<init>_00471374,&DAT_00471370);
    bVar1 = false;
    bVar2 = false;
    if ((DAT_0049d16c != 0) && (DAT_0049d170 != 0)) {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_0049d174 != 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      FUN_00402800(s_nFileTexture_00471330,0x2c);
    }
  }
  return;
}


