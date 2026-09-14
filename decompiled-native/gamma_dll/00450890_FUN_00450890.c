// 00450890 FUN_00450890 [Global]
// programa: gamma.dll

byte * __cdecl FUN_00450890(byte *param_1)

{
  byte bVar1;
  byte *pbVar2;
  
  for (pbVar2 = param_1; bVar1 = *pbVar2, bVar1 != 0; pbVar2 = pbVar2 + 1) {
    if (bVar1 == 0xff) {
      bVar1 = 0xff;
    }
    else {
      bVar1 = (&DAT_00482818)[bVar1];
    }
    *pbVar2 = bVar1;
  }
  return param_1;
}


