// 004066c9 FUN_004066c9 [Global]
// program: run.exe

uint __cdecl FUN_004066c9(ushort *param_1,ushort *param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  if (param_3 != 0) {
    if (DAT_0040bbc4 == 0) {
      do {
        uVar1 = *param_1;
        if ((0x5a < uVar1) || (uVar3 = uVar1 + 0x20, uVar1 < 0x41)) {
          uVar3 = (uint)uVar1;
        }
        uVar1 = *param_2;
        uVar2 = (uint)uVar1;
        if ((uVar1 < 0x5b) && (0x40 < uVar1)) {
          uVar2 = uVar2 + 0x20;
        }
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        param_3 = param_3 + -1;
      } while (((param_3 != 0) && ((short)uVar3 != 0)) && ((short)uVar3 == (short)uVar2));
    }
    else {
      do {
        uVar1 = *param_1;
        param_1 = param_1 + 1;
        uVar3 = FUN_0040769f(CONCAT22((short)(uVar2 >> 0x10),uVar1));
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        uVar2 = FUN_0040769f(CONCAT22((short)(uVar3 >> 0x10),uVar1));
        param_3 = param_3 + -1;
        if ((param_3 == 0) || ((short)uVar3 == 0)) break;
      } while ((short)uVar3 == (short)uVar2);
    }
    uVar2 = (uVar3 & 0xffff) - (uVar2 & 0xffff);
  }
  return uVar2;
}


