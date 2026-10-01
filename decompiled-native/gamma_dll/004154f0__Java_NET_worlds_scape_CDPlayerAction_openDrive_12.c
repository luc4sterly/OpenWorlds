// 004154f0 _Java_NET_worlds_scape_CDPlayerAction_openDrive@12 [Global]
// program: gamma.dll

MCIDEVICEID
_Java_NET_worlds_scape_CDPlayerAction_openDrive_12(int *param_1,undefined4 param_2,int param_3)

{
  MCIDEVICEID mciId;
  MCIERROR MVar1;
  int iVar2;
  undefined1 local_30 [4];
  undefined4 local_2c;
  undefined1 local_24;
  undefined3 uStack_23;
  undefined1 local_20 [4];
  MCIDEVICEID local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  
                    /* 0x154f0  190  _Java_NET_worlds_scape_CDPlayerAction_openDrive@12 */
  _local_24 = CONCAT31((int3)((uint)DAT_0046fdc0 >> 8),(&DAT_0048949d)[param_3]);
  local_14 = &local_24;
  local_18 = 0x204;
  MVar1 = mciSendCommandA(0,0x803,0x3302,(DWORD_PTR)local_20);
  mciId = local_1c;
  if (MVar1 == 0) {
    local_2c = 2;
    MVar1 = mciSendCommandA(local_1c,0x80d,0x400,(DWORD_PTR)local_30);
    if ((MVar1 != 0) && (mciId != 0)) {
      mciSendCommandA(mciId,0x804,0,0);
    }
  }
  else {
    local_1c = 0;
  }
  if (local_1c != 0) {
    return local_1c;
  }
  iVar2 = (**(code **)(*param_1 + 0x18))(param_1,s_java_io_IOException_0046fd9c);
  if (iVar2 == 0) {
    FUN_00402800(s_nCDPlayerAction_0046fdb0,0x1f);
  }
  (**(code **)(*param_1 + 0x38))(param_1,iVar2,s_openDrive_0046fdc4);
  return 0;
}


