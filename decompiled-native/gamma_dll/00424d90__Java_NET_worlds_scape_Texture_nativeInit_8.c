// 00424d90 _Java_NET_worlds_scape_Texture_nativeInit@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_Texture_nativeInit_8(int *param_1)

{
  undefined4 uVar1;
  
                    /* 0x24d90  314  _Java_NET_worlds_scape_Texture_nativeInit@8 */
  if (DAT_0049d240 == 0) {
    uVar1 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_Texture_00471a80);
    DAT_0049d240 = (**(code **)(*param_1 + 0x54))(param_1,uVar1);
    if (DAT_0049d240 == 0) {
      FUN_00402800(s_nTexture_00471a9c,0x29);
    }
    DAT_0049d244 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d240,s_textureID_00471aac,&DAT_00471aa8);
  }
  return;
}


