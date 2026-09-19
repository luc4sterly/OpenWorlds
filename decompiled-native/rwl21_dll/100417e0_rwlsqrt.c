// 100417e0 rwlsqrt [Global]
// programa: RWL21.DLL

/* rwlsqrt */

uint __cdecl rwlsqrt(uint param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
                    /* 0x417e0  540  _rwlsqrt */
  uVar3 = 0;
  if (param_1 != 0) {
    iVar2 = 0x1e;
    uVar3 = param_1;
    if (param_1 >> 0x10 != 0) {
      iVar2 = 0xe;
      uVar3 = param_1 >> 0x10;
    }
    if (uVar3 >> 8 != 0) {
      iVar2 = iVar2 + -8;
      uVar3 = uVar3 >> 8;
    }
    if (uVar3 >> 4 != 0) {
      iVar2 = iVar2 + -4;
      uVar3 = uVar3 >> 4;
    }
    if ((uVar3 & 0xfffffffc) != 0) {
      iVar2 = iVar2 + -2;
    }
    bVar1 = (byte)(iVar2 >> 1);
    uVar3 = (uint)((1 << (bVar1 - 1 & 0x1f)) +
                  *(int *)((((param_1 << ((byte)iVar2 & 0x1f)) + 0xc0080000 & 0xfff3ffff) >> 0x12) +
                          DAT_1005b8c8)) >> (bVar1 & 0x1f);
  }
  return uVar3;
}


