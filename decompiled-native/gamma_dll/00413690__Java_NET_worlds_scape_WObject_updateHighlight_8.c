// 00413690 _Java_NET_worlds_scape_WObject_updateHighlight@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_WObject_updateHighlight_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
                    /* 0x13690  364  _Java_NET_worlds_scape_WObject_updateHighlight@8 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb90);
  if (iVar1 == 0) {
    return;
  }
  iVar2 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fba0);
  uVar3 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049f964);
  if (iVar2 != 0) {
    FUN_004190d0(iVar2);
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0049fba0,0);
  }
  if ((uVar3 & 0x80) != 0) {
    iVar2 = FUN_00413550(iVar1);
    if (iVar2 != 0) {
      iVar4 = FUN_00417b10(DAT_0046f724,DAT_0046f718,DAT_0046f718);
      if (iVar4 != 0) {
        FUN_00418da0(iVar2,iVar4);
      }
      FUN_00418da0(iVar1,iVar2);
      (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0049fba0,iVar2);
    }
  }
  return;
}


