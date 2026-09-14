// 00413020 _Java_NET_worlds_scape_WObject_setClumpMatrix@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_WObject_setClumpMatrix_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x13020  363  _Java_NET_worlds_scape_WObject_setClumpMatrix@8 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb90);
  if (iVar1 != 0) {
    uVar2 = FUN_00425380(param_1,param_2);
    FUN_00418bc0(iVar1,uVar2);
  }
  return;
}


