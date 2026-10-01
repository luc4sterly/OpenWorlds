// 004582d0 FUN_004582d0 [Global]
// program: gamma.dll

void __cdecl FUN_004582d0(byte *param_1)

{
  int iVar1;
  ushort in_FPUControlWord;
  unkbyte9 local_1c;
  byte bStack_13;
  ushort local_12;
  
  iVar1 = 0;
  do {
    (&bStack_13)[-(iVar1 + 1)] = param_1[iVar1 * 2 + 5] << 4 | param_1[iVar1 * 2 + 6] & 0xf;
    (&bStack_13)[-(iVar1 + 2)] = param_1[iVar1 * 2 + 7] << 4 | param_1[iVar1 * 2 + 8] & 0xf;
    (&bStack_13)[-(iVar1 + 3)] = param_1[iVar1 * 2 + 9] << 4 | param_1[iVar1 * 2 + 10] & 0xf;
    iVar1 = iVar1 + 3;
  } while (iVar1 < 9);
  bStack_13 = *param_1;
  DAT_0049eb70 = 0;
  local_12 = in_FPUControlWord | 0x300;
  from_bcd(CONCAT19(bStack_13,local_1c));
  FUN_00458260();
  return;
}


