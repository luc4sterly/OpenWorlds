// 0040f8f4 FUN_0040f8f4 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_0040f8f4(undefined4 param_1,int param_2)

{
  int in_EAX;
  DWORD DVar1;
  undefined4 extraout_ECX;
  int local_1c;
  
  local_1c = param_2;
  if (((*(byte *)(in_EAX + 2) & 2) != 0) && (0x10 < *(int *)(in_EAX + 0x14))) {
    FUN_004080a4(param_1,(undefined1 *)(param_2 + -0x10 + in_EAX));
    local_1c = param_2 + -0x10;
    if (1 < (int)DAT_0043d578) {
      *(byte *)(in_EAX + 2) = *(byte *)(in_EAX + 2) | 4;
    }
  }
  if ((0xfff < *(int *)(in_EAX + 0x14)) || (*(int *)(in_EAX + 0x14) < 0)) {
    FUN_004296b9(s_Incorrect_buffer_len_____d_00435bb4);
    if (*(int *)(in_EAX + 0x14) < 0) {
      *(undefined4 *)(in_EAX + 0x14) = 0;
    }
    else {
      *(uint *)(in_EAX + 0x14) = *(uint *)(in_EAX + 0x14) & 0xfff;
    }
    FUN_004296b9(s_truncated_to__d_00435bd0);
  }
  *(uint *)(in_EAX + 0x14) = *(uint *)(in_EAX + 0x14) | (DAT_0043d6e8 & 0xfff) << 0xc;
  *(uint *)(in_EAX + 0x14) = *(uint *)(in_EAX + 0x14) | DAT_004623c8 << 0x18;
  DAT_004623d8 = DAT_0043d578;
  DVar1 = GetTickCount();
  DAT_004623c0 = (DVar1 - _DAT_004623e0) / 100;
  *(uint *)(in_EAX + 0x18) =
       (DAT_004623d0 & 0x3f) << 0x19 | (DAT_004623e8 & 0x1f) << 0x14 | (DAT_004623d8 & 0xf) << 0x10
       | DAT_004623c0 & 0xffff;
  DAT_0043d6e8 = DAT_0043d6e8 + 1 & 0xfff;
  FUN_004173ab(extraout_ECX,DAT_0043d6e8);
  return local_1c;
}


