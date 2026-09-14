// 004155e0 _Java_NET_worlds_scape_CDPlayerAction_closeDrive@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_CDPlayerAction_closeDrive_12
               (int *param_1,undefined4 param_2,MCIDEVICEID param_3)

{
  MCIERROR MVar1;
  int iVar2;
  
                    /* 0x155e0  183  _Java_NET_worlds_scape_CDPlayerAction_closeDrive@12 */
  MVar1 = mciSendCommandA(param_3,0x804,0,0);
  if (MVar1 != 0) {
    iVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_java_io_IOException_0046fd9c);
    if (iVar2 == 0) {
      FUN_00402800(s_nCDPlayerAction_0046fdb0,0x1f);
    }
    (**(code **)(*param_1 + 0x38))(param_1,iVar2,s_closeDrive_0046fdd0);
  }
  return;
}


