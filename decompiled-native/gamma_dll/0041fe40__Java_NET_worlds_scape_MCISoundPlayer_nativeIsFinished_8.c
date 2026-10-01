// 0041fe40 _Java_NET_worlds_scape_MCISoundPlayer_nativeIsFinished@8 [Global]
// program: gamma.dll

undefined4 _Java_NET_worlds_scape_MCISoundPlayer_nativeIsFinished_8(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  BOOL BVar2;
  int iVar3;
  void *pvVar4;
  MCIERROR MVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined1 local_224 [4];
  uint local_220;
  undefined4 local_21c;
  byte local_214 [256];
  undefined1 local_114 [4];
  byte local_110 [256];
  
                    /* 0x1fe40  244  _Java_NET_worlds_scape_MCISoundPlayer_nativeIsFinished@8 */
  uVar1 = (**(code **)(*param_1 + 0x60))(param_1,param_2,DAT_0049cfe8);
  if ((char)uVar1 == '\0') {
    return CONCAT31((int3)((uint)uVar1 >> 8),1);
  }
  local_21c = 4;
  if (DAT_0049cfe0 == 0) {
    MVar5 = mciSendCommandA(DAT_0049cfec,0x814,0x102,(DWORD_PTR)local_224);
    if (MVar5 != 0) {
      BVar2 = mciGetErrorStringA(MVar5,(LPSTR)local_214,0x100);
      if (BVar2 == 0) {
        pvVar4 = (void *)FUN_00403350(0x49eda8,(byte *)s_Unknown_mci_Error__0x_00470e00);
        iVar3 = *(int *)((int)pvVar4 + 4);
        *(ushort *)(iVar3 + 0x30) = *(ushort *)(iVar3 + 0x30) & 0xffb5;
        *(ushort *)(iVar3 + 0x30) = *(ushort *)(iVar3 + 0x30) | 8;
        pbVar7 = &DAT_00470df0;
        iVar3 = FUN_00405750(pvVar4,MVar5);
      }
      else {
        pbVar6 = local_214;
        pbVar7 = &DAT_00470df0;
        iVar3 = FUN_00403350(0x49eda8,(byte *)s_mci_Error__00470df4);
        iVar3 = FUN_00403350(iVar3,pbVar6);
      }
      FUN_00403350(iVar3,pbVar7);
    }
  }
  else {
    MVar5 = 1;
  }
  if (((MVar5 == 0) && (local_220 != 0x20d)) && (local_220 != 0x212)) {
    return local_220 & 0xffffff00;
  }
  if (DAT_0049cfe0 == 0) {
    MVar5 = mciSendCommandA(DAT_0049cfec,0x804,0,(DWORD_PTR)local_114);
    if (MVar5 != 0) {
      BVar2 = mciGetErrorStringA(MVar5,(LPSTR)local_110,0x100);
      if (BVar2 == 0) {
        pvVar4 = (void *)FUN_00403350(0x49eda8,(byte *)s_Unknown_mci_Error__0x_00470e00);
        iVar3 = *(int *)((int)pvVar4 + 4);
        *(ushort *)(iVar3 + 0x30) = *(ushort *)(iVar3 + 0x30) & 0xffb5;
        *(ushort *)(iVar3 + 0x30) = *(ushort *)(iVar3 + 0x30) | 8;
        pbVar7 = &DAT_00470df0;
        iVar3 = FUN_00405750(pvVar4,MVar5);
      }
      else {
        pbVar6 = local_110;
        pbVar7 = &DAT_00470df0;
        iVar3 = FUN_00403350(0x49eda8,(byte *)s_mci_Error__00470df4);
        iVar3 = FUN_00403350(iVar3,pbVar6);
      }
      FUN_00403350(iVar3,pbVar7);
    }
  }
  DAT_0049cfec = 0xffffffff;
  uVar1 = (**(code **)(*param_1 + 0x58))(param_1,DAT_0049cfe8);
  DAT_0049cfe8 = 0;
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}


