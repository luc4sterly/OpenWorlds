// 00415ba0 _Java_NET_worlds_scape_CDPlayerAction_stopAudio@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_CDPlayerAction_stopAudio_12
               (int *param_1,undefined4 param_2,MCIDEVICEID param_3)

{
  bool bVar1;
  MCIERROR MVar2;
  int iVar3;
  
                    /* 0x15ba0  195  _Java_NET_worlds_scape_CDPlayerAction_stopAudio@12 */
  MVar2 = mciSendCommandA(param_3,0x808,0,0);
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
    (**(code **)(*param_1 + 0x38))(param_1,iVar3,s_stopAudio_0046fe58);
  }
  return;
}


