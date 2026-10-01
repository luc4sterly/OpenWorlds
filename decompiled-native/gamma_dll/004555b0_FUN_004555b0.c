// 004555b0 FUN_004555b0 [Global]
// program: gamma.dll

uint __cdecl FUN_004555b0(uint param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(param_2 + 8) & 7;
  iVar1 = FUN_004553d0(param_2,-1);
  if (-1 < iVar1) {
    return 0xffffffff;
  }
  if (((bVar2 != 1) && (bVar2 != 4)) && (param_1 != 0xffffffff)) {
    if (bVar2 < 3) {
      *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_2 + 0x2c);
      *(undefined4 *)(param_2 + 0x2c) = 0;
      *(byte *)(param_2 + 8) = *(byte *)(param_2 + 8) & 0xf8 | 3;
      bVar2 = 3;
    }
    else {
      bVar2 = (*(byte *)(param_2 + 8) & 7) + 1 & 7;
      *(byte *)(param_2 + 8) = *(byte *)(param_2 + 8) & 0xf8 | bVar2;
    }
    *(undefined1 *)(param_2 + bVar2 + 0x10) = (undefined1)param_1;
    *(undefined1 *)(param_2 + 0xc) = 0;
    return param_1 & 0xff;
  }
  return 0xffffffff;
}


