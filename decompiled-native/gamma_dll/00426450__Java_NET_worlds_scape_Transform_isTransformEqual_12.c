// 00426450 _Java_NET_worlds_scape_Transform_isTransformEqual@12 [Global]
// program: gamma.dll

int _Java_NET_worlds_scape_Transform_isTransformEqual_12
              (int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint3 uVar1;
  byte bVar4;
  undefined4 uVar2;
  int iVar3;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float local_8c [16];
  float local_4c [16];
  
                    /* 0x26450  324  _Java_NET_worlds_scape_Transform_isTransformEqual@12 */
  uVar2 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d24c);
  FUN_00419740(uVar2,local_8c);
  uVar2 = (**(code **)(*param_1 + 400))(param_1,param_3,DAT_0049d24c);
  iVar3 = FUN_00419740(uVar2,local_4c);
  iVar8 = 0;
  iVar5 = 0;
  do {
    iVar6 = 0;
    iVar7 = iVar5;
    do {
      bVar4 = (byte)((ushort)((ushort)(NAN(local_8c[iVar7]) || NAN(local_4c[iVar7])) << 10) >> 8) |
              (byte)((ushort)((ushort)(local_8c[iVar7] == local_4c[iVar7]) << 0xe) >> 8);
      uVar1 = CONCAT21((short)((uint)iVar3 >> 0x10),bVar4);
      iVar3 = (uint)uVar1 << 8;
      if (bVar4 != 0x40) {
        return (uint)uVar1 << 8;
      }
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 1;
    } while (iVar6 < 3);
    iVar8 = iVar8 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar8 < 4);
  return CONCAT31(uVar1,1);
}


