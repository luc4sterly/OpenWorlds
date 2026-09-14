// 00412eb0 _Java_NET_worlds_scape_WObject_getRoomFromClump@8 [Global]
// programa: gamma.dll

undefined4 _Java_NET_worlds_scape_WObject_getRoomFromClump_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x12eb0  358  _Java_NET_worlds_scape_WObject_getRoomFromClump@8 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb90);
  if (iVar1 == 0) {
    FUN_00402800(s_nWObject_0046f6a4,0xb6);
  }
  iVar1 = FUN_00419510(iVar1);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_00419830(iVar1);
  return uVar2;
}


