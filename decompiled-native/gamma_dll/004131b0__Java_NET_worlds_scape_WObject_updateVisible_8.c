// 004131b0 _Java_NET_worlds_scape_WObject_updateVisible@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_WObject_updateVisible_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
                    /* 0x131b0  365  _Java_NET_worlds_scape_WObject_updateVisible@8 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb90);
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049f964);
    if ((uVar2 & 1) == 0) {
      FUN_00418860(iVar1);
    }
    else {
      FUN_00418820(iVar1);
    }
  }
  return;
}


