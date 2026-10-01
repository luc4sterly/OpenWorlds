// 004280b0 FUN_004280b0 [Global]
// program: gamma.dll

void __cdecl FUN_004280b0(byte *param_1,byte *param_2)

{
  byte bVar1;
  
  for (; bVar1 = *param_2, bVar1 != 0; param_2 = param_2 + 1) {
    if ((((&DAT_00482718)[bVar1] & 0xc0) != 0) && (((&DAT_00482718)[bVar1] & 0x80) != 0)) {
      if (bVar1 == 0xff) {
        bVar1 = 0xff;
      }
      else {
        bVar1 = (&DAT_00482818)[bVar1];
      }
    }
    *param_1 = bVar1;
    param_1 = param_1 + 1;
  }
  *param_1 = 0;
  return;
}


