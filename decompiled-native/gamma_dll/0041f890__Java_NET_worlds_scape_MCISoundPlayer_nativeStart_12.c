// 0041f890 _Java_NET_worlds_scape_MCISoundPlayer_nativeStart@12 [Global]
// programa: gamma.dll

undefined4
_Java_NET_worlds_scape_MCISoundPlayer_nativeStart_12
          (int *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  byte *pbVar2;
  undefined4 uVar3;
  MCIERROR MVar4;
  BOOL BVar5;
  uint uVar6;
  void *pvVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  undefined1 local_438 [4];
  MCIDEVICEID local_434;
  char *local_430;
  byte *local_42c;
  undefined1 local_424 [12];
  undefined1 local_418 [4];
  byte local_414 [256];
  byte local_314 [256];
  undefined1 local_214 [4];
  byte local_210 [256];
  byte local_110 [256];
  
                    /* 0x1f890  245  _Java_NET_worlds_scape_MCISoundPlayer_nativeStart@12 */
  pbVar2 = (byte *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  iVar8 = -1;
  pbVar10 = pbVar2;
  do {
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    bVar1 = *pbVar10;
    pbVar10 = pbVar10 + 1;
  } while (bVar1 != 0);
  local_42c = pbVar2;
  if (3 < -iVar8 + -2) {
    iVar8 = FUN_004508c0(pbVar2 + -iVar8 + -6,&DAT_00470e18);
    if (iVar8 == 0) {
      DAT_0049d0f0 = 1;
      goto LAB_0041f900;
    }
  }
  DAT_0049d0f0 = 0;
LAB_0041f900:
  if (DAT_0049cfe8 != 0) {
    iVar8 = FUN_004508c0(pbVar2,&DAT_0049cff0);
    if (iVar8 == 0) {
      (**(code **)(*param_1 + 0x58))(param_1,DAT_0049cfe8);
      DAT_0049cfe8 = (**(code **)(*param_1 + 0x54))(param_1,param_2);
      uVar3 = (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pbVar2);
      return CONCAT31((int3)((uint)uVar3 >> 8),1);
    }
    if (DAT_0049cfe0 == 0) {
      MVar4 = mciSendCommandA(DAT_0049cfec,0x804,0,(DWORD_PTR)local_418);
      if (MVar4 != 0) {
        BVar5 = mciGetErrorStringA(MVar4,(LPSTR)local_210,0x100);
        if (BVar5 == 0) {
          pvVar7 = (void *)FUN_00403350(0x49eda8,(byte *)s_Unknown_mci_Error__0x_00470e00);
          iVar8 = *(int *)((int)pvVar7 + 4);
          *(ushort *)(iVar8 + 0x30) = *(ushort *)(iVar8 + 0x30) & 0xffb5;
          *(ushort *)(iVar8 + 0x30) = *(ushort *)(iVar8 + 0x30) | 8;
          pbVar10 = &DAT_00470df0;
          iVar8 = FUN_00405750(pvVar7,MVar4);
        }
        else {
          pbVar9 = local_210;
          pbVar10 = &DAT_00470df0;
          iVar8 = FUN_00403350(0x49eda8,(byte *)s_mci_Error__00470df4);
          iVar8 = FUN_00403350(iVar8,pbVar9);
        }
        FUN_00403350(iVar8,pbVar10);
      }
    }
    DAT_0049cfec = 0xffffffff;
    (**(code **)(*param_1 + 0x58))(param_1,DAT_0049cfe8);
    DAT_0049cfe8 = 0;
  }
  FUN_0044d6b0(&DAT_0049cff0,(char *)pbVar2);
  if (DAT_0049d0f0 == 0) {
    local_430 = s_waveaudio_00470e20;
  }
  else {
    local_430 = s_sequencer_00470e2c;
  }
  if (DAT_0049cfe0 == 0) {
    MVar4 = mciSendCommandA(0,0x803,0x2200,(DWORD_PTR)local_438);
    if (MVar4 != 0) {
      BVar5 = mciGetErrorStringA(MVar4,(LPSTR)local_414,0x100);
      if (BVar5 == 0) {
        pvVar7 = (void *)FUN_00403350(0x49eda8,(byte *)s_Unknown_mci_Error__0x_00470e00);
        iVar8 = *(int *)((int)pvVar7 + 4);
        *(ushort *)(iVar8 + 0x30) = *(ushort *)(iVar8 + 0x30) & 0xffb5;
        *(ushort *)(iVar8 + 0x30) = *(ushort *)(iVar8 + 0x30) | 8;
        pbVar10 = &DAT_00470df0;
        iVar8 = FUN_00405750(pvVar7,MVar4);
      }
      else {
        pbVar9 = local_414;
        pbVar10 = &DAT_00470df0;
        iVar8 = FUN_00403350(0x49eda8,(byte *)s_mci_Error__00470df4);
        iVar8 = FUN_00403350(iVar8,pbVar9);
      }
      FUN_00403350(iVar8,pbVar10);
    }
  }
  else {
    MVar4 = 1;
  }
  if (MVar4 != 0) {
    uVar6 = (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pbVar2);
    return uVar6 & 0xffffff00;
  }
  DAT_0049cfe8 = (**(code **)(*param_1 + 0x54))(param_1,param_2);
  DAT_0049cfec = local_434;
  if (DAT_0049cfe0 == 0) {
    MVar4 = mciSendCommandA(local_434,0x806,0,(DWORD_PTR)local_424);
    if (MVar4 != 0) {
      BVar5 = mciGetErrorStringA(MVar4,(LPSTR)local_314,0x100);
      if (BVar5 == 0) {
        pvVar7 = (void *)FUN_00403350(0x49eda8,(byte *)s_Unknown_mci_Error__0x_00470e00);
        iVar8 = *(int *)((int)pvVar7 + 4);
        *(ushort *)(iVar8 + 0x30) = *(ushort *)(iVar8 + 0x30) & 0xffb5;
        *(ushort *)(iVar8 + 0x30) = *(ushort *)(iVar8 + 0x30) | 8;
        pbVar10 = &DAT_00470df0;
        iVar8 = FUN_00405750(pvVar7,MVar4);
      }
      else {
        pbVar9 = local_314;
        pbVar10 = &DAT_00470df0;
        iVar8 = FUN_00403350(0x49eda8,(byte *)s_mci_Error__00470df4);
        iVar8 = FUN_00403350(iVar8,pbVar9);
      }
      FUN_00403350(iVar8,pbVar10);
    }
  }
  else {
    MVar4 = 1;
  }
  if (MVar4 != 0) {
    if (DAT_0049cfe0 == 0) {
      MVar4 = mciSendCommandA(DAT_0049cfec,0x804,0,(DWORD_PTR)local_214);
      if (MVar4 != 0) {
        BVar5 = mciGetErrorStringA(MVar4,(LPSTR)local_110,0x100);
        if (BVar5 == 0) {
          pvVar7 = (void *)FUN_00403350(0x49eda8,(byte *)s_Unknown_mci_Error__0x_00470e00);
          iVar8 = *(int *)((int)pvVar7 + 4);
          *(ushort *)(iVar8 + 0x30) = *(ushort *)(iVar8 + 0x30) & 0xffb5;
          *(ushort *)(iVar8 + 0x30) = *(ushort *)(iVar8 + 0x30) | 8;
          pbVar10 = &DAT_00470df0;
          iVar8 = FUN_00405750(pvVar7,MVar4);
        }
        else {
          pbVar9 = local_110;
          pbVar10 = &DAT_00470df0;
          iVar8 = FUN_00403350(0x49eda8,(byte *)s_mci_Error__00470df4);
          iVar8 = FUN_00403350(iVar8,pbVar9);
        }
        FUN_00403350(iVar8,pbVar10);
      }
    }
    DAT_0049cfec = 0xffffffff;
    (**(code **)(*param_1 + 0x58))(param_1,DAT_0049cfe8);
    DAT_0049cfe8 = 0;
    uVar6 = (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pbVar2);
    return uVar6 & 0xffffff00;
  }
  uVar3 = (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pbVar2);
  return CONCAT31((int3)((uint)uVar3 >> 8),1);
}


