// 0042638b FUN_0042638b [Global]
// programa: sfmain.exe

void FUN_0042638b(void)

{
  int in_EAX;
  undefined4 extraout_ECX;
  undefined4 uVar1;
  undefined4 extraout_ECX_00;
  undefined4 local_24;
  undefined4 local_20;
  undefined2 local_18;
  
  local_20 = 0;
  local_18 = Ordinal_15(*(undefined2 *)(in_EAX + 0x1c));
  if ((local_18 < 1) || (0x640 < local_18)) {
    local_18 = 0x640;
  }
  local_24 = 0;
  uVar1 = extraout_ECX;
  for (; local_20 < local_18; local_20 = local_20 + 0xa0) {
    FUN_00401c27(uVar1,(ushort *)(in_EAX + 0x1e + local_24));
    local_24 = local_24 + 0xe;
    uVar1 = extraout_ECX_00;
  }
  FUN_004080a4(uVar1,(undefined1 *)0x4b7100);
  *(int *)(in_EAX + 0x14) = (int)local_18;
  return;
}


