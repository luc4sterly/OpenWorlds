// 004508c0 FUN_004508c0 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_004508c0(byte *param_1,byte *param_2)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    if (bVar1 == 0xff) {
      cVar3 = -1;
    }
    else {
      cVar3 = (&DAT_00482818)[bVar1];
    }
    bVar1 = *param_2;
    param_2 = param_2 + 1;
    if (bVar1 == 0xff) {
      cVar2 = -1;
    }
    else {
      cVar2 = (&DAT_00482818)[bVar1];
    }
    if (cVar3 < cVar2) {
      return 0xffffffff;
    }
    if (cVar2 < cVar3) {
      return 1;
    }
  } while (cVar3 != '\0');
  return 0;
}


