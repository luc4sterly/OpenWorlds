// 00413160 _Java_NET_worlds_scape_WObject_createClump@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_WObject_createClump_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  
                    /* 0x13160  350  _Java_NET_worlds_scape_WObject_createClump@8 */
  iVar1 = FUN_00418f90();
  if (iVar1 == 0) {
    FUN_00402800(s_nWObject_0046f6a4,0x123);
  }
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0049fb90,iVar1);
  return;
}


