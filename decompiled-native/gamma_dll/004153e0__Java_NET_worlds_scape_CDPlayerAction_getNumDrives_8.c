// 004153e0 _Java_NET_worlds_scape_CDPlayerAction_getNumDrives@8 [Global]
// program: gamma.dll

int _Java_NET_worlds_scape_CDPlayerAction_getNumDrives_8(void)

{
  int iVar1;
  MCIDEVICEID mciId;
  MCIERROR MVar2;
  MCIDEVICEID mciId_00;
  char cVar3;
  undefined1 local_34 [4];
  undefined4 local_30;
  char local_28;
  undefined3 uStack_27;
  undefined1 local_24 [4];
  MCIDEVICEID local_20;
  undefined4 local_1c;
  char *local_18;
  
                    /* 0x153e0  186  _Java_NET_worlds_scape_CDPlayerAction_getNumDrives@8 */
  if (DAT_0046fd98 == -1) {
    DAT_0046fd98 = 0;
    cVar3 = 'C';
    do {
      _local_28 = CONCAT31((int3)((uint)DAT_0046fdc0 >> 8),cVar3);
      local_18 = &local_28;
      local_1c = 0x204;
      MVar2 = mciSendCommandA(0,0x803,0x3302,(DWORD_PTR)local_24);
      mciId = local_20;
      if (MVar2 == 0) {
        local_30 = 2;
        MVar2 = mciSendCommandA(local_20,0x80d,0x400,(DWORD_PTR)local_34);
        mciId_00 = local_20;
        if ((MVar2 != 0) && (mciId != 0)) {
          mciSendCommandA(mciId,0x804,0,0);
          mciId_00 = local_20;
        }
      }
      else {
        mciId_00 = 0;
      }
      iVar1 = DAT_0046fd98;
      if (mciId_00 != 0) {
        DAT_0046fd98 = DAT_0046fd98 + 1;
        (&DAT_0048949d)[iVar1] = cVar3;
        mciSendCommandA(mciId_00,0x804,0,0);
      }
      cVar3 = cVar3 + '\x01';
    } while (cVar3 < '[');
  }
  return DAT_0046fd98;
}


