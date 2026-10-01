// 00413060 _Java_NET_worlds_scape_WObject_initClumpData@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_WObject_initClumpData_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x13060  360  _Java_NET_worlds_scape_WObject_initClumpData@8 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb90);
  if (iVar1 == 0) {
    FUN_00402800(s_nWObject_0046f6a4,0xfe);
  }
  uVar2 = (**(code **)(*param_1 + 0x54))(param_1,param_2);
  FUN_00419d30(iVar1,uVar2);
  return;
}


