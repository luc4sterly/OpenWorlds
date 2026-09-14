// 00412f90 _Java_NET_worlds_scape_WObject_addChildToClump@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_WObject_addChildToClump_12
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
                    /* 0x12f90  349  _Java_NET_worlds_scape_WObject_addChildToClump@12 */
  uVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb90);
  uVar2 = (**(code **)(*param_1 + 400))(param_1,param_3,DAT_0049fb90);
  uVar3 = FUN_004195b0(uVar1);
  if ((uVar3 != 0) && ((int)uVar3 < 0x8000000)) {
    iVar4 = FUN_00419190(uVar2,uVar3 | 0x8000000);
    if (iVar4 != 0) {
      FUN_00418da0(iVar4,uVar1);
      return;
    }
  }
  FUN_00418da0(uVar2,uVar1);
  return;
}


