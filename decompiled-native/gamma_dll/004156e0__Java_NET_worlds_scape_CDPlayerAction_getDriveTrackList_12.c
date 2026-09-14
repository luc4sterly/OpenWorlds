// 004156e0 _Java_NET_worlds_scape_CDPlayerAction_getDriveTrackList@12 [Global]
// programa: gamma.dll

int _Java_NET_worlds_scape_CDPlayerAction_getDriveTrackList_12
              (int *param_1,undefined4 param_2,MCIDEVICEID param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  MCIERROR MVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  undefined1 local_20 [4];
  uint local_1c;
  undefined4 local_18;
  int local_14;
  
                    /* 0x156e0  185  _Java_NET_worlds_scape_CDPlayerAction_getDriveTrackList@12 */
  local_18 = 3;
  MVar4 = mciSendCommandA(param_3,0x814,0x100,(DWORD_PTR)local_20);
  if (MVar4 == 0) {
    bVar1 = true;
  }
  else {
    if (param_3 != 0) {
      mciSendCommandA(param_3,0x804,0,0);
    }
    bVar1 = false;
  }
  uVar3 = local_1c;
  if (bVar1) {
    if (DAT_004894b8 == 0) {
      uVar5 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_CDTrackInfo_0046fde8);
      DAT_004894b8 = (**(code **)(*param_1 + 0x54))(param_1,uVar5);
      if (DAT_004894b8 == 0) {
        FUN_00402800(s_nCDPlayerAction_0046fdb0,0x7f);
      }
      DAT_004894bc = (**(code **)(*param_1 + 0x84))
                               (param_1,DAT_004894b8,s_<init>_0046fe10,&DAT_0046fe08);
      DAT_004894c0 = (**(code **)(*param_1 + 0x178))
                               (param_1,DAT_004894b8,&DAT_0046fe1c,&DAT_0046fe18);
      DAT_004894c4 = (**(code **)(*param_1 + 0x178))
                               (param_1,DAT_004894b8,&DAT_0046fe20,&DAT_0046fe18);
      bVar1 = false;
      bVar2 = false;
      if ((DAT_004894bc != 0) && (DAT_004894c0 != 0)) {
        bVar1 = true;
      }
      if ((bVar1) && (DAT_004894c4 != 0)) {
        bVar2 = true;
      }
      if (!bVar2) {
        FUN_00402800(s_nCDPlayerAction_0046fdb0,0x86);
      }
    }
    iVar6 = FUN_00415a40(param_1,DAT_004894b8,DAT_004894bc);
    if (iVar6 != 0) {
      uVar5 = (**(code **)(*param_1 + 0x17c))(param_1,iVar6,DAT_004894c0);
      iVar7 = (**(code **)(*param_1 + 0x2ec))(param_1,uVar5,0);
      uVar8 = (**(code **)(*param_1 + 0x17c))(param_1,iVar6,DAT_004894c4);
      iVar9 = (**(code **)(*param_1 + 0x2ec))(param_1,uVar8,0);
      uVar10 = 0;
      if (uVar3 != 0) {
        do {
          local_18 = 2;
          local_14 = uVar10 + 1;
          MVar4 = mciSendCommandA(param_3,0x814,0x110,(DWORD_PTR)local_20);
          if (MVar4 == 0) {
            bVar1 = true;
          }
          else {
            if (param_3 != 0) {
              mciSendCommandA(param_3,0x804,0,0);
            }
            bVar1 = false;
          }
          if (!bVar1) break;
          *(uint *)(iVar7 + uVar10 * 4) = local_1c;
          local_14 = uVar10 + 1;
          local_18 = 1;
          MVar4 = mciSendCommandA(param_3,0x814,0x110,(DWORD_PTR)local_20);
          if (MVar4 == 0) {
            bVar1 = true;
          }
          else {
            if (param_3 != 0) {
              mciSendCommandA(param_3,0x804,0,0);
            }
            bVar1 = false;
          }
          if (!bVar1) break;
          *(uint *)(iVar9 + uVar10 * 4) = local_1c;
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar3);
      }
      (**(code **)(*param_1 + 0x30c))(param_1,uVar5,iVar7,0);
      (**(code **)(*param_1 + 0x30c))(param_1,uVar8,iVar9,0);
      if (uVar10 == uVar3) {
        return iVar6;
      }
      iVar6 = (**(code **)(*param_1 + 0x18))(param_1,s_java_io_IOException_0046fd9c);
      if (iVar6 == 0) {
        FUN_00402800(s_nCDPlayerAction_0046fdb0,0x1f);
      }
      (**(code **)(*param_1 + 0x38))(param_1,iVar6,s_getDriveTrackList_0046fe24);
      return 0;
    }
  }
  iVar6 = (**(code **)(*param_1 + 0x18))(param_1,s_java_io_IOException_0046fd9c);
  if (iVar6 == 0) {
    FUN_00402800(s_nCDPlayerAction_0046fdb0,0x1f);
  }
  (**(code **)(*param_1 + 0x38))(param_1,iVar6,s_getDriveTrackList2_0046fe38);
  return 0;
}


