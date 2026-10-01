// 0040f150 _Java_NET_worlds_console_Window_isVideoPlaying@12 [Global]
// program: gamma.dll

undefined4
_Java_NET_worlds_console_Window_isVideoPlaying_12
          (undefined4 param_1,undefined4 param_2,MCIDEVICEID param_3)

{
  MCIERROR MVar1;
  undefined1 local_18 [4];
  int local_14;
  undefined4 local_10;
  
                    /* 0xf150  100  _Java_NET_worlds_console_Window_isVideoPlaying@12 */
  local_10 = 4;
  MVar1 = mciSendCommandA(param_3,0x814,0x100,(DWORD_PTR)local_18);
  if (local_14 == 0x20e) {
    return CONCAT31((int3)(MVar1 >> 8),1);
  }
  MVar1 = mciSendCommandA(param_3,0x804,0,0);
  return MVar1 & 0xffffff00;
}


