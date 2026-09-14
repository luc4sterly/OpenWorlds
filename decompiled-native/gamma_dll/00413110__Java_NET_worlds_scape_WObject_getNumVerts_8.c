// 00413110 _Java_NET_worlds_scape_WObject_getNumVerts@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_WObject_getNumVerts_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  
                    /* 0x13110  356  _Java_NET_worlds_scape_WObject_getNumVerts@8 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb90);
  if (iVar1 == 0) {
    FUN_00402800(s_nWObject_0046f6a4,0x115);
  }
  FUN_004194b0(iVar1);
  return;
}


