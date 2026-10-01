// 00412e00 _Java_NET_worlds_scape_WObject_voidClump@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_WObject_voidClump_8(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x12e00  366  _Java_NET_worlds_scape_WObject_voidClump@8 */
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb90);
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0049fb90,0);
      iVar2 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fba0);
      if (iVar2 != 0) {
        FUN_004190d0(iVar2);
        (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0049fba0,0);
      }
      FUN_00417ac0(iVar1);
      iVar2 = FUN_00419390(iVar1);
      if (iVar2 != 0) {
        FUN_00419d30(iVar1,0);
        (**(code **)(*param_1 + 0x58))(param_1,iVar2);
      }
    }
  }
  if (iVar1 != 0) {
    FUN_004190d0(iVar1);
  }
  return;
}


