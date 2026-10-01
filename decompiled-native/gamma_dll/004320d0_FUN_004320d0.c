// 004320d0 FUN_004320d0 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004320d0(int param_1)

{
  LPVOID pvVar1;
  undefined *puVar2;
  float10 fVar3;
  float fVar4;
  float fVar5;
  undefined **local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined **local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined **local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined **local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined **local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined **local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined **local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined **local_8c [4];
  undefined **local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined **local_6c [4];
  undefined **local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined **local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined **local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined **local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined **local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  FUN_00428d70(&local_ac,param_1 + 8,param_1 + 0x54);
  local_f8 = local_a8;
  local_f0 = local_a0;
  local_fc = &PTR_LAB_004732e8;
  local_ac = &PTR_LAB_004732e8;
  local_f4 = local_a4;
  fVar3 = FUN_004295e0((int)&local_fc,(int)&local_fc);
  if (fVar3 < (float10)_DAT_00475190) {
    pvVar1 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar1 + 4) = 0x21;
    fVar5 = _DAT_004823b0;
  }
  else {
    fVar5 = SQRT((float)fVar3);
  }
  if ((byte)(fVar5 < DAT_0047519c |
            (byte)((ushort)((ushort)(NAN(fVar5) || NAN(DAT_0047519c)) << 10) >> 8)) != 1) {
    *(undefined4 *)(param_1 + 0x50) = 2;
    fVar4 = fVar5;
    puVar2 = FUN_0042fa20();
    FUN_00429520(local_8c,(int)puVar2,fVar4);
    FUN_00429230(&local_7c,param_1 + 100,(int)local_8c);
    local_d8 = local_78;
    local_dc = &PTR_LAB_004732e8;
    local_8c[0] = &PTR_LAB_004732e8;
    local_d4 = local_74;
    local_7c = &PTR_LAB_004732e8;
    local_d0 = local_70;
    puVar2 = FUN_0042fa20();
    FUN_00429520(local_6c,(int)puVar2,fVar5);
    FUN_00429230(&local_5c,param_1 + 0x1c,(int)local_6c);
    local_c8 = local_58;
    local_6c[0] = &PTR_LAB_004732e8;
    local_5c = &PTR_LAB_004732e8;
    local_cc = &PTR_LAB_004732e8;
    local_c0 = local_50;
    local_c4 = local_54;
    FUN_00428d70(&local_4c,param_1 + 8,param_1 + 0x54);
    local_b8 = local_48;
    local_b0 = local_40;
    local_bc = &PTR_LAB_004732e8;
    local_b4 = local_44;
    local_4c = &PTR_LAB_004732e8;
    fVar3 = FUN_004295e0((int)&local_dc,(int)&local_bc);
    if (((byte)(fVar3 < (float10)DAT_004751a0 |
               (byte)((ushort)((ushort)(NAN(fVar3) || NAN((float10)DAT_004751a0)) << 10) >> 8)) == 1
        ) && (fVar3 = FUN_004295e0((int)&local_cc,(int)&local_bc),
             (byte)(fVar3 < (float10)DAT_004751a0 |
                   (byte)((ushort)((ushort)(NAN(fVar3) || NAN((float10)DAT_004751a0)) << 10) >> 8))
             == 1)) {
      *(undefined4 *)(param_1 + 0x84) = 2;
      FUN_00429520(&local_3c,(int)&local_dc,DAT_00475198);
      local_d8 = local_38;
      local_d0 = local_30;
      local_3c = &PTR_LAB_004732e8;
      local_d4 = local_34;
      FUN_00429520(&local_2c,(int)&local_cc,DAT_00475198);
      local_c8 = local_28;
      local_c4 = local_24;
      local_2c = &PTR_LAB_004732e8;
      local_c0 = local_20;
    }
    else {
      *(undefined4 *)(param_1 + 0x84) = 1;
    }
    FUN_00431b70((void *)(param_1 + 0xe0),param_1 + 0x54,(int)&local_dc,param_1 + 8,(int)&local_cc,
                 (uint)(*(int *)(param_1 + 0x84) == 2));
    *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x120);
    return;
  }
  *(undefined4 *)(param_1 + 0x50) = 1;
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0x60);
  FUN_00428d70(&local_1c,param_1 + 8,param_1 + 0x54);
  *(undefined4 *)(param_1 + 0xac) = local_18;
  *(undefined4 *)(param_1 + 0xb0) = local_14;
  *(undefined4 *)(param_1 + 0xb4) = local_10;
  local_1c = &PTR_LAB_004732e8;
  FUN_00428e20((void *)(param_1 + 0xb8),param_1 + 100);
  FUN_00428e20((void *)(param_1 + 0xcc),param_1 + 0x1c);
  FUN_004292a0((void *)(param_1 + 0xb8),param_1 + 0xcc);
  *(undefined4 *)(param_1 + 0x84) = 1;
  FUN_00428d70(&local_9c,param_1 + 8,param_1 + 0x54);
  local_e8 = local_98;
  local_e0 = local_90;
  local_ec = &PTR_LAB_004732e8;
  local_e4 = local_94;
  local_9c = &PTR_LAB_004732e8;
  fVar3 = FUN_004295e0((int)&local_ec,(int)&local_ec);
  if (fVar3 < (float10)_DAT_00475190) {
    pvVar1 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar1 + 4) = 0x21;
    fVar5 = _DAT_004823b0;
  }
  else {
    fVar5 = SQRT((float)fVar3);
  }
  *(float *)(param_1 + 0x88) = fVar5;
  return;
}


