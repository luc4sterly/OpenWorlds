// 0042a16d FUN_0042a16d [Global]
// programa: sfmain.exe

int __fastcall FUN_0042a16d(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_EAX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined8 uVar1;
  undefined1 local_22c [256];
  char local_12c [256];
  undefined4 local_2c;
  undefined4 *local_28;
  int local_24;
  undefined1 *local_20;
  char *local_1c;
  
  local_24 = 0;
  local_1c = &DAT_0045e230;
  if (DAT_0045e230 == '\0') {
    local_1c = &DAT_0045e280;
  }
  local_2c = param_2;
  local_28 = in_EAX;
  if (*local_1c == '\0') {
    local_1c = local_12c;
    Ordinal_57(local_22c,0x100);
    FUN_0042ca26((int)local_12c,(byte *)s_someuser__s_00437645);
  }
  if (local_1c != (char *)0x0) {
    FUN_0042c5ad();
    uVar1 = FUN_0042ba46(extraout_ECX,extraout_EDX);
    local_20 = (undefined1 *)uVar1;
    if (local_20 != (undefined1 *)0x0) {
      *local_20 = 0;
      local_20[1] = 1;
      local_20[2] = (undefined1)local_2c;
      local_20[3] = (char)((uint)local_2c >> 8);
      FUN_0042c5c6(extraout_ECX_00,local_1c);
      local_24 = FUN_0042c5ad();
      local_24 = local_24 + 5;
    }
  }
  *local_28 = local_20;
  return local_24;
}


