// 00429b7d FUN_00429b7d [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00429b7d(undefined4 param_1,int param_2)

{
  byte bVar1;
  byte *in_EAX;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_54;
  int local_50;
  uint local_4c;
  int local_48;
  int local_44;
  uint local_40;
  int local_3c;
  undefined *local_38;
  byte *local_34;
  
  uVar2 = (uint)(in_EAX[1] & 0x1f);
  if (((*in_EAX & 0xc0) != 0) || ((in_EAX[1] & 0x60) != 0)) {
    return 0;
  }
  local_34 = in_EAX + (uint)(*in_EAX & 0x3f) * 4 + 8;
  iVar4 = param_2 - ((uint)(*in_EAX & 0x3f) * 4 + 8);
  _DAT_00445b58 = 0x40000000;
  DAT_00445b6c = 0;
  FUN_0042c5c6(param_1,&DAT_00437640);
  bVar1 = (&DAT_0043d950)[uVar2 * 0xc];
  uVar3 = extraout_ECX;
  if (bVar1 < 5) {
    if (bVar1 == 0) {
      DAT_00445b6c = iVar4;
      FUN_004080a4(extraout_ECX,local_34);
      uVar3 = extraout_ECX_00;
      goto LAB_00429f4f;
    }
    if (bVar1 == 3) {
      FUN_004080a4(extraout_ECX,local_34 + 4);
      FUN_004080a4(&DAT_00445b74,local_34);
      DAT_00445b6c = iVar4 + -1;
      uVar3 = extraout_ECX_02;
      if (*(int *)(&DAT_0043d954 + uVar2 * 0xc) == 8000) {
        _DAT_00445b58 = _DAT_00445b58 | 0x200;
      }
      goto LAB_00429f4f;
    }
  }
  else {
    if (bVar1 < 6) {
      DAT_00445b6c = iVar4 + 2;
      FUN_004080a4(extraout_ECX,local_34);
      _DAT_00445b74 = Ordinal_9((iVar4 * 0xa0) / 0x21 & 0xffff);
      _DAT_00445b58 = _DAT_00445b58 | 0x20;
      uVar3 = extraout_ECX_01;
      goto LAB_00429f4f;
    }
    if (6 < bVar1) {
      if (bVar1 < 8) {
        DAT_00445b6c = iVar4 + 2;
        local_38 = &DAT_00445b76;
        for (local_3c = 0; local_3c < iVar4 / 0xe; local_3c = local_3c + 1) {
          FUN_004080a4(uVar3,local_34);
          local_38[3] = 0;
          FUN_004080a4(extraout_ECX_03,local_34 + 3);
          local_34 = local_34 + 0xe;
          local_38 = local_38 + 0xe;
          uVar3 = extraout_ECX_04;
        }
        _DAT_00445b74 = Ordinal_9((iVar4 * 0xa0) / 0xe & 0xffff);
        _DAT_00445b58 = _DAT_00445b58 | 0x1000;
        uVar3 = extraout_ECX_05;
        goto LAB_00429f4f;
      }
      if (bVar1 == 9) {
        iVar5 = iVar4 >> 0x1f;
        if (*(int *)(&DAT_0043d958 + uVar2 * 0xc) == 1) {
          local_40 = 0;
          local_44 = 0;
          for (local_48 = 0; local_48 < (int)((iVar4 + iVar5 * -8) - (uint)(iVar5 << 2 < 0)) >> 3;
              local_48 = local_48 + 1) {
            if (((local_40 & 3) != 2) && (local_48 % 0x244 != 0x243)) {
              (&DAT_00445b74)[local_44] =
                   (&DAT_00427192)[(int)(uint)*(ushort *)(local_34 + local_48 * 8) >> 3];
              local_44 = local_44 + 1;
            }
            local_40 = (int)(local_40 + 1) % 0xb;
          }
          DAT_00445b6c = local_44;
        }
        else if (*(int *)(&DAT_0043d958 + uVar2 * 0xc) == 2) {
          local_4c = 0;
          local_50 = 0;
          for (local_54 = 0; local_54 < (int)((iVar4 + iVar5 * -0x10) - (uint)(iVar5 << 3 < 0)) >> 4
              ; local_54 = local_54 + 1) {
            if (((local_4c & 3) != 2) && (local_54 % 0x244 != 0x243)) {
              (&DAT_00445b74)[local_50] =
                   (&DAT_00427192)
                   [(int)(((uint)*(ushort *)(local_34 + local_54 * 0x10) +
                          (uint)*(ushort *)(local_34 + local_54 * 0x10 + 2)) / 2) >> 3];
              local_50 = local_50 + 1;
            }
            local_4c = (int)(local_4c + 1) % 0xb;
          }
          DAT_00445b6c = local_50;
        }
        goto LAB_00429f4f;
      }
    }
  }
  DAT_00445b6c = 0;
LAB_00429f4f:
  FUN_004080a4(uVar3,&DAT_00445b58);
  return 1;
}


