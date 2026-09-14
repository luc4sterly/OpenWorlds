// 004259c0 _Java_NET_worlds_scape_Transform_pre@12 [Global]
// programa: gamma.dll

undefined4
_Java_NET_worlds_scape_Transform_pre_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  
                    /* 0x259c0  333  _Java_NET_worlds_scape_Transform_pre@12 */
  fVar7 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d250);
  fVar1 = (float)fVar7;
  fVar7 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d254);
  fVar2 = (float)fVar7;
  fVar7 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d258);
  fVar3 = (float)fVar7;
  fVar7 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_3,DAT_0049d250);
  fVar8 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_3,DAT_0049d254);
  fVar9 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_3,DAT_0049d258);
  uVar5 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d24c);
  uVar6 = (**(code **)(*param_1 + 400))(param_1,param_3,DAT_0049d24c);
  bVar4 = true;
  if (((byte)((byte)((ushort)((ushort)(NAN(fVar1) || NAN(fVar2)) << 10) >> 8) |
             (byte)((ushort)((ushort)(fVar1 == fVar2) << 0xe) >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
            (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8)) == 0x40)) {
    bVar4 = false;
  }
  if (bVar4) {
    FUN_00418b10(uVar5,DAT_00471bf4 / fVar1,DAT_00471bf4 / fVar2,DAT_00471bf4 / fVar3);
  }
  FUN_00418c80(uVar5,uVar6);
  if (bVar4) {
    FUN_00418b10(uVar5,fVar1,fVar2,fVar3);
  }
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_0049d250,fVar1 * (float)fVar7);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_0049d254,fVar2 * (float)fVar8);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_0049d258,fVar3 * (float)fVar9);
  FUN_00412800(param_1,param_2,DAT_0049d25c);
  return param_2;
}


