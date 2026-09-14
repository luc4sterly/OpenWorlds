// 0044bd00 _Java_NET_worlds_scape_PendingCacheDrone_nativeInit@8 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Java_NET_worlds_scape_PendingCacheDrone_nativeInit_8(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
                    /* 0x4bd00  255  _Java_NET_worlds_scape_PendingCacheDrone_nativeInit@8 */
  _DAT_0049dfb4 = param_1;
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_PendingCacheDro_00480610);
  uVar1 = (**(code **)(*param_1 + 0x54))(param_1,uVar1);
  _DAT_0049dfb8 = uVar1;
  iVar2 = (**(code **)(*param_1 + 0x1c4))
                    (param_1,uVar1,s_downloadSeqFile_0048064c,s__Ljava_lang_String_ZI_V_00480634);
  if (iVar2 == 0) {
    FUN_00458020();
  }
  _DAT_0049dfbc = iVar2;
  iVar2 = (**(code **)(*param_1 + 0x1c4))
                    (param_1,uVar1,s_getAvatarDatPath_00480688,s___Ljava_lang_String__00480670);
  if (iVar2 == 0) {
    FUN_00458020();
  }
  _DAT_0049dfc0 = iVar2;
  return;
}


