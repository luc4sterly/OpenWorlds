// 00413ce0 _Java_NET_worlds_scape_Hologram_prerender@12 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Java_NET_worlds_scape_Hologram_prerender_12
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  byte bVar12;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  LPVOID pvVar11;
  int iVar13;
  float10 fVar14;
  float local_60;
  float local_5c;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  
                    /* 0x13ce0  234  _Java_NET_worlds_scape_Hologram_prerender@12 */
  uVar3 = FUN_004144b0(param_1,param_3);
  uVar4 = FUN_00412cf0(param_1,param_2);
  iVar5 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489450);
  if (iVar5 != 0) {
    FUN_00402800(s_nHologram_0046fafc,0x86);
  }
  uVar6 = FUN_00419040();
  FUN_00419420(uVar4,uVar6);
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_00489450,uVar6);
  FUN_004194e0(uVar4,&local_40);
  FUN_00419260(uVar3,&local_34);
  local_34 = local_34 - local_40;
  local_30 = local_30 - local_3c;
  local_2c = local_2c - local_38;
  uVar7 = FUN_00419950();
  uVar8 = FUN_00419950();
  FUN_004193c0(uVar4,uVar7);
  FUN_00425280(param_1,param_2,&local_28);
  FUN_00418b10(uVar7,DAT_0046fb54 / local_28,DAT_0046fb54 / local_24,DAT_0046fb54 / local_20);
  FUN_00419860(uVar7,uVar8);
  FUN_0041a0b0(&local_34,uVar8);
  local_60 = DAT_0046fb58;
  if (((byte)((byte)((ushort)((ushort)(NAN(DAT_0046fb58) || NAN(local_34)) << 10) >> 8) |
             (byte)((ushort)((ushort)(DAT_0046fb58 == local_34) << 0xe) >> 8)) != 0x40) ||
     ((byte)((byte)((ushort)((ushort)(NAN(DAT_0046fb58) || NAN(local_30)) << 10) >> 8) |
            (byte)((ushort)((ushort)(DAT_0046fb58 == local_30) << 0xe) >> 8)) != 0x40)) {
    fVar14 = (float10)fpatan((float10)local_30,(float10)local_34);
    local_60 = (float)fVar14 * _DAT_0046fb5c * (float)_DAT_0046fb60 - (float)_DAT_0046fb68;
    if ((_DAT_0046fb70 < local_60) ||
       ((byte)(local_60 < _DAT_0046fb74 |
              (byte)((ushort)((ushort)(NAN(local_60) || NAN(_DAT_0046fb74)) << 10) >> 8)) == 1)) {
      local_60 = DAT_0046fb58;
    }
  }
  iVar5 = FUN_00414240(param_1,param_2,DAT_00489454);
  iVar9 = (**(code **)(*param_1 + 0x3c))(param_1);
  if (iVar9 != 0) {
    FUN_004198f0();
    FUN_004198f0();
    return;
  }
  if (iVar5 < 1) {
    FUN_00402800(s_nHologram_0046fafc,0xb8);
  }
  iVar9 = iVar5 * 2;
  fVar1 = (float)iVar5 * local_60 * _DAT_0046fb78 + DAT_0046fb54;
  if ((float)iVar9 <= fVar1) {
    do {
      do {
        fVar1 = fVar1 - (float)iVar9;
        fVar2 = (float)iVar9;
        bVar12 = fVar2 < fVar1 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar1)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(fVar2 == fVar1) << 0xe) >> 8);
      } while (bVar12 == 1);
    } while (bVar12 == 0x40);
  }
  bVar12 = fVar1 < DAT_0046fb58 |
           (byte)((ushort)((ushort)(NAN(fVar1) || NAN(DAT_0046fb58)) << 10) >> 8);
  while (bVar12 == 1) {
    fVar1 = fVar1 + (float)iVar9;
    bVar12 = fVar1 < DAT_0046fb58 |
             (byte)((ushort)((ushort)(NAN(fVar1) || NAN(DAT_0046fb58)) << 10) >> 8);
  }
  iVar13 = (int)ROUND(fVar1) >> 1;
  if ((iVar13 < 0) || (iVar9 <= iVar13)) {
    iVar13 = 0;
  }
  FUN_00412800(param_1,param_2,DAT_00489458);
  iVar9 = (**(code **)(*param_1 + 0x3c))(param_1);
  if (iVar9 == 0) {
    uVar10 = FUN_00412d20(param_1,param_2);
    if ((uVar10 & 4) != 0) {
      local_60 = ((float)iVar13 * (float)_DAT_0046fb80) / (float)iVar5;
    }
    if ((uVar10 & 0x40000) != 0) {
      FUN_00419200(uVar3,&local_1c);
      FUN_0041a0b0(&local_1c,uVar8);
      local_60 = DAT_0046fb58;
      if (((byte)((byte)((ushort)((ushort)(NAN(DAT_0046fb58) || NAN(local_1c)) << 10) >> 8) |
                 (byte)((ushort)((ushort)(DAT_0046fb58 == local_1c) << 0xe) >> 8)) != 0x40) ||
         ((byte)((byte)((ushort)((ushort)(NAN(DAT_0046fb58) || NAN(local_18)) << 10) >> 8) |
                (byte)((ushort)((ushort)(DAT_0046fb58 == local_18) << 0xe) >> 8)) != 0x40)) {
        fVar14 = (float10)fpatan(-(float10)local_18,-(float10)local_1c);
        local_60 = (float)fVar14 * _DAT_0046fb5c * (float)_DAT_0046fb60 - (float)_DAT_0046fb68;
        if ((_DAT_0046fb70 < local_60) ||
           ((byte)(local_60 < _DAT_0046fb74 |
                  (byte)((ushort)((ushort)(NAN(local_60) || NAN(_DAT_0046fb74)) << 10) >> 8)) == 1))
        {
          local_60 = DAT_0046fb58;
        }
      }
    }
    FUN_00418f00(uVar6,uVar7);
    FUN_00418b10(uVar7,DAT_0046fb54 / local_28,DAT_0046fb54 / local_24,DAT_0046fb54 / local_20);
    FUN_00418a90(uVar7,local_60,DAT_0046fb58,DAT_0046fb58,DAT_0046fb54);
    FUN_00418b10(uVar7,local_28,local_24,local_20);
    fVar14 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0048944c);
    local_5c = (float)fVar14;
    if (DAT_0046fb58 < local_5c) {
      if (DAT_0046fb58 < (float)DAT_0049fcbc) {
        local_5c = (float)DAT_0049fcbc * _DAT_0046fb88 * local_5c;
      }
      fVar1 = (local_34 * local_34 + local_30 * local_30) / (local_5c * local_5c);
      if (DAT_0046fb54 < fVar1) {
        if (fVar1 < (float)_DAT_0046fb90) {
          pvVar11 = FUN_00453ed0();
          *(undefined4 *)((int)pvVar11 + 4) = 0x21;
          fVar1 = _DAT_004823b0;
        }
        else {
          fVar1 = SQRT(fVar1);
        }
        FUN_00418b10(uVar7,fVar1,fVar1,fVar1);
      }
    }
    FUN_00418bc0(uVar4,uVar7);
    FUN_004198f0();
    FUN_004198f0();
    return;
  }
  FUN_004198f0();
  FUN_004198f0();
  return;
}


