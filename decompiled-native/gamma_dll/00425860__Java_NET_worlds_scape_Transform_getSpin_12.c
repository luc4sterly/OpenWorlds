// 00425860 _Java_NET_worlds_scape_Transform_getSpin@12 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 _Java_NET_worlds_scape_Transform_getSpin_12
                  (int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined1 local_1c [12];
  
                    /* 0x25860  318  _Java_NET_worlds_scape_Transform_getSpin@12 */
  FUN_0041aa90(param_1,param_3,&local_2c);
  uVar1 = FUN_00419950();
  uVar2 = FUN_00419950();
  uVar3 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d24c);
  FUN_00418f00(uVar3,uVar2);
  fVar4 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d250);
  fVar5 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d254);
  fVar6 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d258);
  FUN_00418b10(uVar2,DAT_00471bf4 / (float)fVar4,DAT_00471bf4 / (float)fVar5,
               DAT_00471bf4 / (float)fVar6);
  FUN_00419890(uVar2,uVar1);
  FUN_004198f0();
  FUN_004198f0();
  FUN_00419980(uVar1,&local_2c,&local_20,local_1c);
  if (DAT_00471c10 < local_24) {
    local_20 = _DAT_00471c2c - local_20;
    local_2c = -local_2c;
    local_28 = -local_28;
    local_24 = -local_24;
  }
  if ((byte)((byte)((ushort)((ushort)(NAN(DAT_00471c10) || NAN(local_20)) << 10) >> 8) |
            (byte)((ushort)((ushort)(DAT_00471c10 == local_20) << 0xe) >> 8)) == 0x40) {
    local_24 = -1.0;
    local_2c = 0.0;
    local_28 = 0.0;
  }
  FUN_0041ab00(param_1,param_3,&local_2c);
  return (float10)local_20;
}


