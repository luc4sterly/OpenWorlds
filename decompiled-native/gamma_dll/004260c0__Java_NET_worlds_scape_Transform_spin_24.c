// 004260c0 _Java_NET_worlds_scape_Transform_spin@24 [Global]
// program: gamma.dll

undefined4
_Java_NET_worlds_scape_Transform_spin_24
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  undefined4 uVar5;
  float10 fVar6;
  
                    /* 0x260c0  338  _Java_NET_worlds_scape_Transform_spin@24 */
  uVar5 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d24c);
  fVar6 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d250);
  fVar1 = (float)fVar6;
  fVar6 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d254);
  fVar2 = (float)fVar6;
  fVar6 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d258);
  fVar3 = (float)fVar6;
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
  FUN_00418a90(uVar5,param_6,param_3,param_4,param_5);
  if (bVar4) {
    FUN_00418b10(uVar5,fVar1,fVar2,fVar3);
  }
  FUN_00412800(param_1,param_2,DAT_0049d25c);
  return param_2;
}


