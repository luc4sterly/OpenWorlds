// 0041c570 _Java_NET_worlds_scape_Portal_postrender@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_Portal_postrender_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x1c570  263  _Java_NET_worlds_scape_Portal_postrender@12 */
  uVar1 = FUN_004144e0(param_1,param_3);
  if (((uVar1 & 4) == 0) && (iVar2 = FUN_00412cf0(param_1,param_2), iVar2 != 0)) {
    iVar3 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489600);
    if ((iVar3 == 2) && (uVar1 = FUN_00412d20(param_1,param_2), (uVar1 & 0x40) == 0)) {
      FUN_00419d60(iVar2,0);
      return;
    }
    _Java_NET_worlds_scape_WObject_updateVisible_8(param_1,param_2);
  }
  return;
}


