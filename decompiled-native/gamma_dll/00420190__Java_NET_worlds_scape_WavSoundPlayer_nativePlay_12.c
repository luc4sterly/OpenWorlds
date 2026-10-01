// 00420190 _Java_NET_worlds_scape_WavSoundPlayer_nativePlay@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_WavSoundPlayer_nativePlay_12
               (int *param_1,undefined4 param_2,char param_3)

{
  undefined4 uVar1;
  LPCSTR pszSound;
  uint uVar2;
  
                    /* 0x20190  368  _Java_NET_worlds_scape_WavSoundPlayer_nativePlay@12 */
  uVar1 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_0049d110);
  pszSound = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,uVar1,0);
  if (param_3 == '\0') {
    uVar2 = 0;
  }
  else {
    uVar2 = 9;
  }
  if (DAT_0049d108 == 0) {
    PlaySoundA(pszSound,(HMODULE)0x0,uVar2 | 0x20002);
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,uVar1,pszSound);
  return;
}


