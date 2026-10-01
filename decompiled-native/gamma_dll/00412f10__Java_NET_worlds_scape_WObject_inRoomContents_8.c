// 00412f10 _Java_NET_worlds_scape_WObject_inRoomContents@8 [Global]
// program: gamma.dll

undefined4 _Java_NET_worlds_scape_WObject_inRoomContents_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint3 uVar4;
  
                    /* 0x12f10  359  _Java_NET_worlds_scape_WObject_inRoomContents@8 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb90);
  if (iVar1 == 0) {
    FUN_00402800(s_nWObject_0046f6a4,199);
  }
  iVar1 = FUN_00419510(iVar1);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_00419830(iVar1);
  iVar3 = FUN_00412840(param_1,uVar2);
  uVar4 = (uint3)((uint)iVar3 >> 8);
  if (iVar1 == iVar3) {
    return CONCAT31(uVar4,1);
  }
  return (uint)uVar4 << 8;
}


