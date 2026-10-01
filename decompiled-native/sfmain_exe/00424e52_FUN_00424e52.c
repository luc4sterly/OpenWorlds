// 00424e52 FUN_00424e52 [Global]
// program: sfmain.exe

undefined4 __fastcall FUN_00424e52(undefined4 param_1,int param_2)

{
  byte *in_EAX;
  uint uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 uVar3;
  undefined4 extraout_ECX_08;
  undefined4 extraout_ECX_09;
  undefined2 *extraout_EDX;
  undefined2 *puVar4;
  undefined8 uVar5;
  int local_4014;
  int local_4010;
  uint local_400c;
  int local_4008;
  int local_4004;
  uint local_4000;
  int local_3ffc;
  undefined1 *local_3ff8;
  byte *local_3ff4;
  int local_3fec;
  undefined2 *local_3fe8;
  undefined2 *local_3fe4;
  int local_3fdc;
  undefined2 *local_3fd8;
  uint local_3fd4 [5];
  int local_3fc0;
  undefined2 local_3fb8;
  undefined1 local_3fb6 [16198];
  int local_70;
  uint local_6c;
  byte *local_68;
  int local_64;
  int local_60;
  byte local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  byte *local_40;
  int local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_38 = (int)(uint)*in_EAX >> 6;
  local_58 = (uint)((*in_EAX & 0x20) != 0);
  local_54 = (uint)(local_58 != 0);
  local_34 = local_54;
  local_50 = (uint)((*in_EAX & 0x10) != 0);
  local_4c = (uint)(local_50 != 0);
  local_30 = local_4c;
  local_2c = (uint)(*in_EAX & 0xf);
  local_48 = (uint)((in_EAX[1] & 0x80) != 0);
  local_44 = (uint)(local_48 != 0);
  local_28 = local_44;
  local_24 = (uint)(in_EAX[1] & 0x1f);
  local_40 = in_EAX;
  local_3c = param_2;
  local_20 = Ordinal_15(*(undefined2 *)(in_EAX + 2));
  local_20 = local_20 & 0xffff;
  local_1c = Ordinal_14(*(undefined4 *)(local_40 + 4));
  if ((((local_38 == 2) && (local_24 < 0xd)) && (*(int *)(&DAT_0043d7ec + local_24 * 0xc) != 0)) &&
     ((local_34 == 0 || ((uint)local_40[local_3c + -1] < local_3c - (local_2c * 4 + 0xc))))) {
    if (local_30 == 0) {
      local_60 = 0;
      uVar3 = extraout_ECX;
    }
    else {
      uVar1 = Ordinal_15(*(undefined2 *)(local_40 + local_2c * 4 + 0xe));
      local_60 = (uVar1 & 0xffff) * 4 + 4;
      uVar3 = extraout_ECX_00;
    }
    local_64 = local_60;
    local_68 = local_40 + local_60 + local_2c * 4 + 0xc;
    if (local_34 == 0) {
      local_6c = 0;
    }
    else {
      local_6c = (uint)local_40[local_3c + -1];
    }
    local_70 = local_3c - (local_2c * 4 + 0xc + local_60 + local_6c);
    local_3fd4[0] = 0x40000000;
    local_3fc0 = 0;
    FUN_0042c5c6(uVar3,&DAT_00437328);
    local_5c = (&DAT_0043d7e8)[local_24 * 0xc];
    uVar3 = extraout_ECX_01;
    if (local_5c < 3) {
      if (local_5c == 0) {
        local_3fc0 = local_70;
        FUN_004080a4(extraout_ECX_01,local_68);
        uVar3 = extraout_ECX_02;
      }
      else if (local_5c == 1) {
        local_3fc0 = local_70;
        puVar4 = extraout_EDX;
        local_3fd8 = &local_3fb8;
        for (local_3fdc = 0; local_3fdc < local_70; local_3fdc = local_3fdc + 1) {
          local_68 = local_68 + 1;
          uVar5 = FUN_00420690(uVar3,puVar4);
          *(char *)local_3fd8 = (char)uVar5;
          uVar3 = extraout_ECX_03;
          puVar4 = local_3fd8;
          local_3fd8 = (undefined2 *)((int)local_3fd8 + 1);
        }
      }
    }
    else if (local_5c < 4) {
      FUN_004080a4(extraout_ECX_01,local_68 + 4);
      FUN_004080a4(&local_3fb8,local_68);
      local_3fc0 = local_70 + -1;
      if (*(int *)(&DAT_0043d7ec + local_24 * 0xc) == 8000) {
        local_3fd4[0] = local_3fd4[0] | 0x200;
        uVar3 = extraout_ECX_05;
      }
      else {
        uVar1 = *(uint *)(&DAT_0043d7ec + local_24 * 0xc) / 8000;
        local_3fe4 = &local_3fb8;
        FUN_004262fe();
        local_3fe8 = &local_3fb8;
        for (local_3fec = 0; local_3fec < (local_70 + -4) / (int)uVar1; local_3fec = local_3fec + 1)
        {
          *(undefined1 *)local_3fe8 = *(undefined1 *)local_3fe4;
          local_3fe4 = (undefined2 *)((int)local_3fe4 + uVar1);
          local_3fe8 = (undefined2 *)((int)local_3fe8 + 1);
        }
        local_3fc0 = local_3fc0 / (int)uVar1;
        uVar3 = extraout_ECX_06;
      }
    }
    else if (local_5c < 7) {
      if (local_5c == 5) {
        local_3fc0 = local_70 + 2;
        FUN_004080a4(extraout_ECX_01,local_68);
        local_3fb8 = Ordinal_9((local_70 * 0xa0) / 0x21 & 0xffff);
        local_3fd4[0] = local_3fd4[0] | 0x20;
        uVar3 = extraout_ECX_04;
      }
    }
    else if (local_5c < 8) {
      iVar2 = local_70 / 0xe;
      local_3ff4 = local_68;
      local_3ff8 = local_3fb6;
      local_3fb8 = Ordinal_9(iVar2 * 0xa0 & 0xffff);
      uVar3 = extraout_ECX_07;
      for (local_3ffc = 0; local_3ffc < iVar2; local_3ffc = local_3ffc + 1) {
        FUN_004080a4(uVar3,local_3ff4);
        local_3ff8[3] = 0;
        FUN_004080a4(extraout_ECX_08,local_3ff4 + 3);
        local_3ff4 = local_3ff4 + 0xe;
        local_3ff8 = local_3ff8 + 0xe;
        uVar3 = extraout_ECX_09;
      }
      local_3fc0 = local_70 + 2;
      local_3fd4[0] = local_3fd4[0] | 0x1000;
    }
    else if (local_5c == 9) {
      iVar2 = local_70 >> 0x1f;
      if (*(int *)(&DAT_0043d7f0 + local_24 * 0xc) == 1) {
        local_4000 = 0;
        local_4004 = 0;
        for (local_4008 = 0;
            local_4008 < (int)((local_70 + iVar2 * -8) - (uint)(iVar2 << 2 < 0)) >> 3;
            local_4008 = local_4008 + 1) {
          if (((local_4000 & 3) != 2) && (local_4008 % 0x244 != 0x243)) {
            local_3fb6[local_4004 + -2] =
                 (&DAT_00427192)[(int)(uint)*(ushort *)(local_68 + local_4008 * 8) >> 3];
            local_4004 = local_4004 + 1;
          }
          local_4000 = (int)(local_4000 + 1) % 0xb;
        }
        local_3fc0 = local_4004;
      }
      else if (*(int *)(&DAT_0043d7f0 + local_24 * 0xc) == 2) {
        local_400c = 0;
        local_4010 = 0;
        for (local_4014 = 0;
            local_4014 < (int)((local_70 + iVar2 * -0x10) - (uint)(iVar2 << 3 < 0)) >> 4;
            local_4014 = local_4014 + 1) {
          if (((local_400c & 3) != 2) && (local_4014 % 0x244 != 0x243)) {
            local_3fb6[local_4010 + -2] =
                 (&DAT_00427192)
                 [(int)(((uint)*(ushort *)(local_68 + local_4014 * 0x10) +
                        (uint)*(ushort *)(local_68 + local_4014 * 0x10 + 2)) / 2) >> 3];
            local_4010 = local_4010 + 1;
          }
          local_400c = (int)(local_400c + 1) % 0xb;
        }
        local_3fc0 = local_4010;
      }
    }
    if (0 < local_3fc0) {
      FUN_004080a4(uVar3,(undefined1 *)local_3fd4);
    }
    local_18 = 1;
  }
  else {
    local_18 = 0;
  }
  return local_18;
}


