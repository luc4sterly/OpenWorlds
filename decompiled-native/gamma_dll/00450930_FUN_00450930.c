// 00450930 FUN_00450930 [Global]
// program: gamma.dll

undefined4 __cdecl FUN_00450930(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < param_3) {
    do {
      bVar1 = *param_1;
      param_1 = param_1 + 1;
      if (bVar1 == 0xff) {
        cVar2 = -1;
      }
      else {
        cVar2 = (&DAT_00482818)[bVar1];
      }
      bVar1 = *param_2;
      param_2 = param_2 + 1;
      if (bVar1 == 0xff) {
        cVar3 = -1;
      }
      else {
        cVar3 = (&DAT_00482818)[bVar1];
      }
      if (cVar2 < cVar3) {
        return 0xffffffff;
      }
      if (cVar3 < cVar2) {
        return 1;
      }
      if (cVar2 == '\0') {
        return 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_3);
  }
  return 0;
}


