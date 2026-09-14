// 0041f790 _Java_NET_worlds_scape_MCISoundPlayer_shutdown@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_MCISoundPlayer_shutdown_8(int *param_1)

{
  MCIERROR mcierr;
  BOOL BVar1;
  int iVar2;
  void *this;
  byte *pbVar3;
  byte *pbVar4;
  undefined1 local_114 [4];
  byte local_110 [256];
  
                    /* 0x1f790  248  _Java_NET_worlds_scape_MCISoundPlayer_shutdown@8 */
  if (DAT_0049cfe8 != 0) {
    if (DAT_0049cfe0 == 0) {
      mcierr = mciSendCommandA(DAT_0049cfec,0x804,0,(DWORD_PTR)local_114);
      if (mcierr != 0) {
        BVar1 = mciGetErrorStringA(mcierr,(LPSTR)local_110,0x100);
        if (BVar1 == 0) {
          this = (void *)FUN_00403350(0x49eda8,(byte *)s_Unknown_mci_Error__0x_00470e00);
          iVar2 = *(int *)((int)this + 4);
          *(ushort *)(iVar2 + 0x30) = *(ushort *)(iVar2 + 0x30) & 0xffb5;
          *(ushort *)(iVar2 + 0x30) = *(ushort *)(iVar2 + 0x30) | 8;
          pbVar4 = &DAT_00470df0;
          iVar2 = FUN_00405750(this,mcierr);
        }
        else {
          pbVar3 = local_110;
          pbVar4 = &DAT_00470df0;
          iVar2 = FUN_00403350(0x49eda8,(byte *)s_mci_Error__00470df4);
          iVar2 = FUN_00403350(iVar2,pbVar3);
        }
        FUN_00403350(iVar2,pbVar4);
      }
    }
    DAT_0049cfec = 0xffffffff;
    (**(code **)(*param_1 + 0x58))(param_1,DAT_0049cfe8);
    DAT_0049cfe8 = 0;
  }
  return;
}


