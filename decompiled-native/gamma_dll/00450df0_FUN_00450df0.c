// 00450df0 FUN_00450df0 [Global]
// programa: gamma.dll

ushort __cdecl FUN_00450df0(int param_1)

{
  if (*(ushort **)(param_1 + 8) == (ushort *)0x0) {
    return 0;
  }
  return **(ushort **)(param_1 + 8) & 0xff;
}


