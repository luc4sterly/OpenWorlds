// 00413405 FUN_00413405 [Global]
// programa: sfmain.exe

void __fastcall FUN_00413405(undefined4 param_1,uint *param_2)

{
  int in_EAX;
  uint uVar1;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  undefined1 local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  
  uVar1 = *param_2 / DAT_0043d6a4;
  if ((DAT_0043d5d4 == 0) && (DAT_0043d69c == 0x2b11)) {
    local_24 = 0;
    local_28 = 0;
    for (local_2c = 0; local_2c < (int)uVar1; local_2c = local_2c + 1) {
      if (((local_24 & 3) != 2) && (local_2c % 0x1b9 != 0x1b8)) {
        if (DAT_0043d6a4 == 2) {
          local_30 = (&DAT_00427192)[(int)(uint)*(ushort *)(local_2c * 2 + in_EAX) >> 3];
        }
        else {
          local_30 = (&DAT_004271a1)
                     [(short)(ushort)(byte)(*(char *)(in_EAX + local_2c) + 0x80) * 0x20];
        }
        (&DAT_004393e0)[local_28] = local_30;
        local_28 = local_28 + 1;
      }
      local_24 = (int)(local_24 + 1) % 0xb;
    }
    DAT_004393d8 = local_28;
  }
  else {
    DAT_004393d8 = uVar1;
    if (DAT_0043d6a4 == 2) {
      local_34 = 0;
      for (local_38 = 0; local_38 < (int)uVar1; local_38 = local_38 + 1) {
        (&DAT_004393e0)[local_34] =
             (&DAT_00427192)[(int)(uint)*(ushort *)(local_38 * 2 + in_EAX) >> 3];
        local_34 = local_34 + 1;
      }
    }
    else {
      local_3c = 0;
      for (local_40 = 0; local_40 < (int)uVar1; local_40 = local_40 + 1) {
        (&DAT_004393e0)[local_3c] =
             (&DAT_004271a1)[(short)(ushort)(byte)(*(char *)(in_EAX + local_40) + 0x80) * 0x20];
        local_3c = local_3c + 1;
      }
    }
  }
  *param_2 = uVar1;
  FUN_004080a4(param_1,&DAT_004393e0);
  return;
}


