// 0040718f FUN_0040718f [Global]
// programa: sfmain.exe

undefined4 __fastcall FUN_0040718f(undefined4 param_1,byte *param_2)

{
  undefined4 uVar1;
  byte *pbVar2;
  byte *pbVar3;
  undefined1 auStack_38 [2];
  ushort local_36;
  undefined2 local_34;
  ushort uStack_32;
  uint local_30;
  ushort local_2c;
  ushort local_2a;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  ushort local_20;
  ushort local_1e;
  ushort local_1c;
  ushort local_1a;
  ushort uStack_18;
  ushort local_16;
  ushort uStack_14;
  ushort local_12;
  ushort uStack_10;
  ushort local_e;
  ushort uStack_c;
  ushort local_a;
  
  if ((int)(uint)*param_2 >> 4 == 0xd) {
    local_36 = (ushort)(param_2[1] & 0x3f);
    pbVar2 = param_2 + 3;
    _local_34 = CONCAT22((ushort)(param_2[2] & 7) << 2 | (ushort)((int)(uint)*pbVar2 >> 6),
                         (short)((int)(uint)param_2[2] >> 3));
    pbVar3 = param_2 + 4;
    local_30 = CONCAT22((ushort)(*pbVar2 & 3) << 2 | (ushort)((int)(uint)*pbVar3 >> 6),
                        (short)((int)(uint)*pbVar2 >> 2)) & 0xffff000f;
    local_2c = (ushort)((int)(uint)*pbVar3 >> 3) & 7;
    local_2a = (ushort)(*pbVar3 & 7);
    local_28 = (undefined2)((int)(uint)param_2[5] >> 1);
    pbVar2 = param_2 + 6;
    uStack_18 = (ushort)(param_2[5] & 1) * 2 | (ushort)((int)(uint)*pbVar2 >> 7);
    local_20 = (ushort)((int)(uint)*pbVar2 >> 5) & 3;
    uStack_10 = (ushort)(*pbVar2 & 0x1f) * 2 | (ushort)((int)(uint)param_2[7] >> 7);
    local_26 = (undefined2)((int)(uint)param_2[0xc] >> 1);
    pbVar2 = param_2 + 0xd;
    local_16 = (ushort)(param_2[0xc] & 1) * 2 | (ushort)((int)(uint)*pbVar2 >> 7);
    local_1e = (ushort)((int)(uint)*pbVar2 >> 5) & 3;
    local_e = (ushort)(*pbVar2 & 0x1f) * 2 | (ushort)((int)(uint)param_2[0xe] >> 7);
    local_24 = (undefined2)((int)(uint)param_2[0x13] >> 1);
    pbVar2 = param_2 + 0x14;
    uStack_14 = (ushort)(param_2[0x13] & 1) * 2 | (ushort)((int)(uint)*pbVar2 >> 7);
    local_1c = (ushort)((int)(uint)*pbVar2 >> 5) & 3;
    uStack_c = (ushort)(*pbVar2 & 0x1f) * 2 | (ushort)((int)(uint)param_2[0x15] >> 7);
    local_22 = (undefined2)((int)(uint)param_2[0x1a] >> 1);
    pbVar2 = param_2 + 0x1b;
    local_12 = (ushort)(param_2[0x1a] & 1) * 2 | (ushort)((int)(uint)*pbVar2 >> 7);
    local_1a = (ushort)((int)(uint)*pbVar2 >> 5) & 3;
    local_a = (ushort)(*pbVar2 & 0x1f) * 2 | (ushort)((int)(uint)param_2[0x1c] >> 7);
    FUN_00407981(&uStack_18,auStack_38);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


