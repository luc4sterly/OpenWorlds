// 00429f80 FUN_00429f80 [Global]
// programa: sfmain.exe

int __fastcall FUN_00429f80(int param_1,undefined4 param_2)

{
  int iVar1;
  byte *in_EAX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 uVar2;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  int local_3c;
  byte *local_38;
  byte local_2c;
  undefined1 local_24;
  int local_14;
  
  DAT_00445b58 = 0;
  if (param_1 == 0) {
    local_2c = 0;
  }
  else {
    local_2c = 0x80;
  }
  DAT_00445b59 = local_2c;
  local_24 = (undefined1)param_2;
  DAT_00445b5a = local_24;
  DAT_00445b5b = (undefined1)((uint)param_2 >> 8);
  DAT_00445b5c = Ordinal_8();
  if ((*in_EAX & 0x20) == 0) {
    if ((in_EAX[1] & 2) == 0) {
      if ((in_EAX[1] & 0x10) == 0) {
        FUN_004080a4(extraout_ECX,in_EAX + 0x1c);
        local_14 = *(int *)(in_EAX + 0x14) + 8;
        uVar2 = extraout_ECX_05;
      }
      else {
        iVar1 = *(int *)(in_EAX + 0x14);
        local_38 = in_EAX + 0x1e;
        DAT_00445b59 = DAT_00445b59 | 0x1c;
        local_14 = 8;
        uVar2 = extraout_ECX;
        for (local_3c = 0; local_3c < (iVar1 + -2) / 0xe; local_3c = local_3c + 1) {
          FUN_004080a4(uVar2,local_38);
          FUN_004080a4(extraout_ECX_03,local_38 + 4);
          local_38 = local_38 + 0xe;
          local_14 = local_14 + 0xe;
          uVar2 = extraout_ECX_04;
        }
      }
    }
    else {
      DAT_00445b59 = DAT_00445b59 | 0x1e;
      FUN_004080a4(extraout_ECX,in_EAX + 0x1c);
      FUN_004080a4(extraout_ECX_01,in_EAX + *(int *)(in_EAX + 0x14) + 0x19);
      DAT_00445b63 = 0;
      local_14 = *(int *)(in_EAX + 0x14) + 9;
      uVar2 = extraout_ECX_02;
    }
  }
  else {
    DAT_00445b59 = DAT_00445b59 | 3;
    FUN_004080a4(extraout_ECX,in_EAX + 0x1e);
    local_14 = *(int *)(in_EAX + 0x14) + 6;
    uVar2 = extraout_ECX_00;
  }
  if (0 < local_14) {
    FUN_004080a4(uVar2,&DAT_00445b58);
  }
  return local_14;
}


