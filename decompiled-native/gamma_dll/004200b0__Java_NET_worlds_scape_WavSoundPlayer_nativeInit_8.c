// 004200b0 _Java_NET_worlds_scape_WavSoundPlayer_nativeInit@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_WavSoundPlayer_nativeInit_8(int *param_1)

{
  undefined4 uVar1;
  
                    /* 0x200b0  367  _Java_NET_worlds_scape_WavSoundPlayer_nativeInit@8 */
  if (DAT_0049d10c == 0) {
    uVar1 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_WavSoundPlayer_004711a0);
    DAT_0049d10c = (**(code **)(*param_1 + 0x54))(param_1,uVar1);
    if (DAT_0049d10c == 0) {
      FUN_00402800(s_nWavSoundPlayer_004711c0,0x20);
    }
    DAT_0049d110 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d10c,s_playingSoundFile_004711e4,
                              s_Ljava_lang_String__004711d0);
  }
  return;
}


