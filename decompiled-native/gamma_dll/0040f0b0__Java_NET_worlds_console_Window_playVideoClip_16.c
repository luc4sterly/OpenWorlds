// 0040f0b0 _Java_NET_worlds_console_Window_playVideoClip@16 [Global]
// program: gamma.dll

MCIDEVICEID
_Java_NET_worlds_console_Window_playVideoClip_16
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  MCIERROR MVar2;
  undefined1 local_48 [4];
  MCIDEVICEID local_44;
  undefined4 local_3c;
  undefined1 local_2c [4];
  undefined4 local_28;
  undefined1 local_1c [12];
  
                    /* 0xf0b0  109  _Java_NET_worlds_console_Window_playVideoClip@16 */
  uVar1 = (**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  local_3c = uVar1;
  MVar2 = mciSendCommandA(0,0x803,0x200,(DWORD_PTR)local_48);
  if (MVar2 == 0) {
    local_28 = param_4;
    mciSendCommandA(local_44,0x841,0x10000,(DWORD_PTR)local_2c);
    mciSendCommandA(local_44,0x806,0,(DWORD_PTR)local_1c);
    (**(code **)(*param_1 + 0x2a8))(param_1,param_3,uVar1);
    return local_44;
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,uVar1);
  return 0xffffffff;
}


