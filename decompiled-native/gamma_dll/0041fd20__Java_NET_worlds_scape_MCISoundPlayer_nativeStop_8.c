// 0041fd20 _Java_NET_worlds_scape_MCISoundPlayer_nativeStop@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_MCISoundPlayer_nativeStop_8(int *param_1,undefined4 param_2)

{
  char cVar1;
  MCIERROR mcierr;
  BOOL BVar2;
  int iVar3;
  void *this;
  byte *pbVar4;
  byte *pbVar5;
  undefined1 local_114 [4];
  byte local_110 [256];
  
                    /* 0x1fd20  246  _Java_NET_worlds_scape_MCISoundPlayer_nativeStop@8 */
  cVar1 = (**(code **)(*param_1 + 0x60))(param_1,param_2,DAT_0049cfe8);
  if (cVar1 != '\0') {
    if (DAT_0049cfe0 == 0) {
      mcierr = mciSendCommandA(DAT_0049cfec,0x804,0,(DWORD_PTR)local_114);
      if (mcierr != 0) {
        BVar2 = mciGetErrorStringA(mcierr,(LPSTR)local_110,0x100);
        if (BVar2 == 0) {
          this = (void *)FUN_00403350(0x49eda8,(byte *)s_Unknown_mci_Error__0x_00470e00);
          iVar3 = *(int *)((int)this + 4);
          *(ushort *)(iVar3 + 0x30) = *(ushort *)(iVar3 + 0x30) & 0xffb5;
          *(ushort *)(iVar3 + 0x30) = *(ushort *)(iVar3 + 0x30) | 8;
          pbVar5 = &DAT_00470df0;
          iVar3 = FUN_00405750(this,mcierr);
        }
        else {
          pbVar4 = local_110;
          pbVar5 = &DAT_00470df0;
          iVar3 = FUN_00403350(0x49eda8,(byte *)s_mci_Error__00470df4);
          iVar3 = FUN_00403350(iVar3,pbVar4);
        }
        FUN_00403350(iVar3,pbVar5);
      }
    }
    DAT_0049cfec = 0xffffffff;
    (**(code **)(*param_1 + 0x58))(param_1,DAT_0049cfe8);
    DAT_0049cfe8 = 0;
  }
  return;
}


