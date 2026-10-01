// 1006e670 FUN_1006e670 [Global]
// program: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1006e670(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  
  DAT_1007f544 = &PTR_DAT_1007fe9c;
  while( true ) {
    iVar6 = DAT_1007f290;
    DAT_1007f290 = DAT_1007f290 + -1;
    if (iVar6 < 1) {
      return;
    }
    DAT_1007f2c0 = DAT_1007f2c0 + DAT_1007f2c4;
    DAT_1007f2e4 = DAT_1007f2e4 + DAT_1007f2e8;
    DAT_1007f4d8 = DAT_1007f2e4 - DAT_1007f2ec;
    DAT_1007f3c0 = DAT_1007f3c0 + DAT_1007f3c4;
    uVar13 = DAT_1007f3c0 >> 0x10;
    if (uVar13 == 0) {
      uVar13 = 1;
    }
    DAT_1007f39c = DAT_1007f39c + DAT_1007f3a0;
    DAT_1007f3a4 = DAT_1007f3a4 + DAT_1007f3a8;
    DAT_1007f3d0 = (DAT_1007f39c / uVar13 & 0xffff) << (DAT_1007f3c8 & 0x1f);
    DAT_1007f3cc = (DAT_1007f3a4 / uVar13 & 0xffff) << (DAT_1007f3c8 & 0x1f);
    DAT_1007f3ac = DAT_1007f3ac + DAT_1007f3b0;
    uVar13 = DAT_1007f3ac >> 0x10;
    if (uVar13 == 0) {
      uVar13 = 1;
    }
    DAT_1007f38c = DAT_1007f38c + DAT_1007f390;
    DAT_1007f394 = DAT_1007f394 + DAT_1007f398;
    iVar6 = (DAT_1007f38c / uVar13 & 0xffff) << (DAT_1007f3b4 & 0x1f);
    iVar7 = (DAT_1007f394 / uVar13 & 0xffff) << (DAT_1007f3b4 & 0x1f);
    DAT_1007f284 = DAT_1007f284 + DAT_1007f288;
    DAT_1007f280 = DAT_1007f280 + DAT_1007f28c;
    iVar10 = (DAT_1007f280 >> 0x10) - (DAT_1007f284 >> 0x10);
    DAT_1007f3b8 = iVar7;
    DAT_1007f3bc = iVar6;
    _DAT_1007f548 = DAT_1007f2c0;
    if (DAT_1007f280 >> 0x10 < DAT_1007f284 >> 0x10) break;
    DAT_1007f2a4 = DAT_1007f2a4 >> 6 ^ DAT_1007f2a4;
    DAT_1007f29c = DAT_1007f2a0 + DAT_1007f29c;
    DAT_1007f294 = DAT_1007f294 + DAT_1007f298;
  }
  if (DAT_1007f43c == 0) {
    uVar11 = DAT_1007f3ac - DAT_1007f3c0;
    DAT_1007f514 = DAT_1007f3ac;
    uVar13 = DAT_1007f3c0;
    if ((int)DAT_1007f3ac < (int)DAT_1007f3c0) goto LAB_10073e7a;
  }
  else {
    uVar11 = DAT_1007f3c0 - DAT_1007f3ac;
    DAT_1007f514 = DAT_1007f3c0;
    uVar13 = DAT_1007f3ac;
    DAT_1007f3b8 = DAT_1007f3cc;
    DAT_1007f3bc = DAT_1007f3d0;
    DAT_1007f3cc = iVar7;
    DAT_1007f3d0 = iVar6;
    if (uVar11 == 0 || (int)DAT_1007f3c0 < (int)DAT_1007f3ac) goto LAB_10073e7a;
  }
  if ((uVar11 & 0xff800000) != 0) {
    _DAT_1007f51c = -iVar10;
    fVar3 = (float)(int)(DAT_1007f514 - uVar13);
    fVar3 = fVar3 * fVar3;
    fVar3 = fVar3 + fVar3;
    fVar4 = (float)_DAT_1007f51c * (float)(int)DAT_1007f514;
    fVar2 = (float)(int)-(DAT_1007f514 - uVar13) * fVar4;
    fVar1 = fVar4 * fVar4 + fVar2;
    fVar2 = fVar2 + fVar2 + fVar3;
    iVar6 = DAT_1007f3cc - DAT_1007f3b8;
    if (iVar6 == 0) {
      iVar6 = 1;
    }
    uVar11 = DAT_1007f43c;
    if (iVar6 < 0) {
      uVar11 = DAT_1007f43c | 2;
      iVar6 = -iVar6;
    }
    fVar5 = (float)iVar6 * (float)(int)uVar13 * fVar4;
    uVar8 = (uint)fVar5 >> 0xf;
    iVar6 = DAT_1007f3d0 - DAT_1007f3bc;
    if (iVar6 == 0) {
      iVar6 = 1;
    }
    if (iVar6 < 0) {
      uVar11 = uVar11 | 4;
      iVar6 = -iVar6;
    }
    DAT_1007f510 = (float)iVar6 * (float)(int)uVar13 * fVar4;
    DAT_1007f4fc = DAT_1007f3b8 << 0x10;
    DAT_1007f500 = DAT_1007f3bc << 0x10;
    DAT_1007f504 = (int)fVar1 << 8 | 0x80000000;
    bVar12 = (char)((uint)fVar1 >> 0x17) + 0x81;
    uVar14 = (int)fVar2 << 8 | 0x80000000;
    bVar9 = bVar12 - ((char)((uint)fVar2 >> 0x17) + -0x7f);
    if ('\x1f' < (char)bVar9) {
      uVar14 = 0;
    }
    DAT_1007f508 = uVar14 >> (bVar9 & 0x1f);
    uVar14 = (int)fVar3 << 8 | 0x80000000;
    bVar9 = bVar12 - ((char)((uint)fVar3 >> 0x17) + -0x7f);
    if ('\x1f' < (char)bVar9) {
      uVar14 = 0;
    }
    DAT_1007f50c = uVar14 >> (bVar9 & 0x1f);
    iVar6 = (bVar12 - 1) * 0x400;
    DAT_1007f520 = DAT_1007f7c0 +
                   (CONCAT31(CONCAT21((ushort)((uint)fVar5 >> 0x1f),(char)(uVar8 >> 8) + -0x7f),
                             (&DAT_1007f6c0)[uVar8 & 0xff]) + -0x800) * -4 + iVar6;
    DAT_1007f524 = DAT_1007f7c0 +
                   (CONCAT31(CONCAT21((ushort)((uint)DAT_1007f510 >> 0x1f),
                                      (char)(((uint)DAT_1007f510 >> 0xf) >> 8) + -0x7f),
                             (&DAT_1007f6c0)[(uint)DAT_1007f510 >> 0xf & 0xff]) + -0x800) * -4 +
                   iVar6;
                    /* WARNING: Could not recover jumptable at 0x10074324. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    DAT_1007f494 = iVar10;
    _DAT_1007f528 = uVar13;
    (*(code *)(&PTR_DAT_1007fe9c)[uVar11])();
    return;
  }
LAB_10073e7a:
  DAT_1007f510 = (float)(((DAT_1007f3cc - DAT_1007f3b8) * 0x100) / -iVar10 << 8);
  DAT_1007f514 = ((DAT_1007f3d0 - DAT_1007f3bc) * 0x100) / -iVar10 << 8;
                    /* WARNING: Could not recover jumptable at 0x10073ee6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&PTR_DAT_1007febc)[DAT_1007f43c])();
  return;
}


