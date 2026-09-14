// 00420200 _Java_NET_worlds_scape_WavSoundPlayer_nativeStop@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_WavSoundPlayer_nativeStop_8(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  LPCSTR pszSound;
  
                    /* 0x20200  369  _Java_NET_worlds_scape_WavSoundPlayer_nativeStop@8 */
  uVar1 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_0049d110);
  pszSound = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,uVar1,0);
  if (DAT_0049d108 == 0) {
    PlaySoundA(pszSound,(HMODULE)0x0,0x40);
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,uVar1,pszSound);
  return;
}


