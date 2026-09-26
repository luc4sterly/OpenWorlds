// 0040f804 FUN_0040f804 [Global]
// programa: sfmain.exe

void __fastcall FUN_0040f804(undefined4 param_1)

{
  int in_EAX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined2 local_3c [8];
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  local_1c = 0;
  local_24 = in_EAX + 0x1e;
  local_20 = in_EAX + 0x1c;
  *(byte *)(in_EAX + 1) = *(byte *)(in_EAX + 1) | 0x10;
  local_28 = in_EAX;
  for (local_2c = 0; local_2c < *(int *)(local_28 + 0x14); local_2c = local_2c + 0xa0) {
    FUN_00401a6a(param_1,local_3c);
    FUN_004080a4(extraout_ECX,(undefined1 *)local_3c);
    local_24 = local_24 + 0xe;
    local_1c = local_1c + 0xe;
    param_1 = extraout_ECX_00;
  }
  *(undefined2 *)(local_28 + 0x1c) = *(undefined2 *)(local_28 + 0x14);
  FUN_00429618();
  *(int *)(local_28 + 0x14) = local_1c + 2;
  return;
}


