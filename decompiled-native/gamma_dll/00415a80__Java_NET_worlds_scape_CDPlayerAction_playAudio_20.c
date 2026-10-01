// 00415a80 _Java_NET_worlds_scape_CDPlayerAction_playAudio@20 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_CDPlayerAction_playAudio_20
               (int *param_1,undefined4 param_2,MCIDEVICEID param_3,uint param_4,uint param_5)

{
  bool bVar1;
  MCIERROR MVar2;
  int iVar3;
  undefined1 local_18 [4];
  uint local_14;
  uint local_10;
  
                    /* 0x15a80  192  _Java_NET_worlds_scape_CDPlayerAction_playAudio@20 */
  local_14 = (param_4 % 0x1194) % 0x4b << 0x10 |
             (param_4 % 0x1194) / 0x4b << 8 | param_4 / 0x1194 & 0xff;
  local_10 = (param_5 % 0x1194) % 0x4b << 0x10 |
             (param_5 % 0x1194) / 0x4b << 8 | param_5 / 0x1194 & 0xff;
  MVar2 = mciSendCommandA(param_3,0x806,0xc,(DWORD_PTR)local_18);
  if (MVar2 == 0) {
    bVar1 = true;
  }
  else {
    if (param_3 != 0) {
      mciSendCommandA(param_3,0x804,0,0);
    }
    bVar1 = false;
  }
  if (!bVar1) {
    iVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_java_io_IOException_0046fd9c);
    if (iVar3 == 0) {
      FUN_00402800(s_nCDPlayerAction_0046fdb0,0x1f);
    }
    (**(code **)(*param_1 + 0x38))(param_1,iVar3,s_playAudio_0046fe4c);
  }
  return;
}


