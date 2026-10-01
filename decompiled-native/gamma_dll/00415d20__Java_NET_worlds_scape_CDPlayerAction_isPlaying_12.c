// 00415d20 _Java_NET_worlds_scape_CDPlayerAction_isPlaying@12 [Global]
// program: gamma.dll

uint _Java_NET_worlds_scape_CDPlayerAction_isPlaying_12
               (int *param_1,undefined4 param_2,MCIDEVICEID param_3)

{
  bool bVar1;
  MCIERROR MVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_1c [4];
  int local_18;
  undefined4 local_14;
  
                    /* 0x15d20  188  _Java_NET_worlds_scape_CDPlayerAction_isPlaying@12 */
  local_14 = 4;
  MVar2 = mciSendCommandA(param_3,0x814,0x100,(DWORD_PTR)local_1c);
  if (MVar2 == 0) {
    bVar1 = true;
  }
  else {
    if (param_3 != 0) {
      mciSendCommandA(param_3,0x804,0,0);
    }
    bVar1 = false;
  }
  if (bVar1) {
    return (uint)(local_18 == 0x20e);
  }
  iVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_java_io_IOException_0046fd9c);
  if (iVar3 == 0) {
    FUN_00402800(s_nCDPlayerAction_0046fdb0,0x1f);
  }
  uVar4 = (**(code **)(*param_1 + 0x38))(param_1,iVar3,s_isPlaying_0046fe70);
  return uVar4 & 0xffffff00;
}


