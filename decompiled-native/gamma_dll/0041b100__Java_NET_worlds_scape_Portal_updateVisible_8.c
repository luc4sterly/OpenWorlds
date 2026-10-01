// 0041b100 _Java_NET_worlds_scape_Portal_updateVisible@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_Portal_updateVisible_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
                    /* 0x1b100  266  _Java_NET_worlds_scape_Portal_updateVisible@8 */
  iVar1 = FUN_00412cf0(param_1,param_2);
  if (iVar1 == 0) {
    return;
  }
  iVar2 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489600);
  if ((iVar2 == 2) && (uVar3 = FUN_00412d20(param_1,param_2), (uVar3 & 0x40) == 0)) {
    FUN_00419d60(iVar1,0);
    return;
  }
  _Java_NET_worlds_scape_WObject_updateVisible_8(param_1,param_2);
  return;
}


