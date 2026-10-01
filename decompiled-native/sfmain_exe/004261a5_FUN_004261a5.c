// 004261a5 FUN_004261a5 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004261a5(void)

{
  int in_EAX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar1;
  undefined4 extraout_ECX_01;
  int local_28;
  int local_24;
  int local_20;
  byte *local_1c;
  short local_18;
  
  local_20 = 0;
  if (_DAT_004b6cfc == 0) {
    _DAT_004b6cfc = 1;
    local_1c = (byte *)(in_EAX + 0x1e);
    local_18 = Ordinal_15(*(undefined2 *)(in_EAX + 0x1c));
    if (((local_18 < 1) || ((int)local_18 % 0xa0 != 0)) || (uVar1 = extraout_ECX, 0x3f48 < local_18)
       ) {
      FUN_004296b9(s_Bad_declen___d_Changed_to__d_0043734e);
      local_18 = (short)DAT_0043d700 * 0xa0;
      uVar1 = extraout_ECX_00;
    }
    for (local_28 = 0; local_28 < *(int *)(in_EAX + 0x14) + -2; local_28 = local_28 + 0x21) {
      FUN_0040718f(uVar1,local_1c);
      local_1c = local_1c + 0x21;
      for (local_24 = 0; local_24 < 0xa0; local_24 = local_24 + 1) {
        *(undefined1 *)(local_20 + 0x4b2db4) =
             (&DAT_00427192)[(int)(uint)*(ushort *)(local_24 * 2 + 0x4b2c74) >> 3];
        local_20 = local_20 + 1;
      }
      uVar1 = extraout_ECX_01;
    }
    FUN_004080a4(uVar1,(undefined1 *)0x4b2db4);
    *(int *)(in_EAX + 0x14) = (int)local_18;
    _DAT_004b6cfc = 0;
  }
  else {
    FUN_004296b9(s_Tried_to_re_enter_gsmdecomp__00437330);
    *(undefined4 *)(in_EAX + 0x14) = 0;
  }
  return;
}


