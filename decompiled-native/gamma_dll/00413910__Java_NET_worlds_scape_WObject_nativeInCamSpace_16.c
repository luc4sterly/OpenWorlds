// 00413910 _Java_NET_worlds_scape_WObject_nativeInCamSpace@16 [Global]
// program: gamma.dll

uint _Java_NET_worlds_scape_WObject_nativeInCamSpace_16
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint3 extraout_var;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_1c [3];
  
                    /* 0x13910  361  _Java_NET_worlds_scape_WObject_nativeInCamSpace@16 */
  iVar2 = FUN_004144b0(param_1,param_3);
  uVar3 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb90);
  if ((iVar2 != 0) && (uVar3 != 0)) {
    bVar1 = FUN_00419570(uVar3);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      return (uint)extraout_var << 8;
    }
    uVar4 = FUN_00419950();
    uVar5 = FUN_00419950();
    FUN_004191d0(iVar2,uVar4);
    FUN_00419860(uVar4,uVar5);
    FUN_004194e0(uVar3,local_1c);
    FUN_0041a080(local_1c,uVar5);
    FUN_004198f0();
    FUN_004198f0();
    uVar4 = FUN_0041ab00(param_1,param_4,local_1c);
    return CONCAT31((int3)((uint)uVar4 >> 8),1);
  }
  return uVar3 & 0xffffff00;
}


