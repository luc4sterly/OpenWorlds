// 1006db2e FUN_1006db2e [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1006db2e(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int in_EAX;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  
  DAT_1007b544 = in_EAX;
  while( true ) {
    iVar6 = DAT_1007b290;
    DAT_1007b290 = DAT_1007b290 + -1;
    if (iVar6 < 1) {
      return;
    }
    DAT_1007b2c0 = DAT_1007b2c0 + DAT_1007b2c4;
    DAT_1007b2e4 = DAT_1007b2e4 + DAT_1007b2e8;
    DAT_1007b4d8 = DAT_1007b2e4 - DAT_1007b2ec;
    DAT_1007b3c0 = DAT_1007b3c0 + DAT_1007b3c4;
    uVar13 = DAT_1007b3c0 >> 0x10;
    if (uVar13 == 0) {
      uVar13 = 1;
    }
    DAT_1007b39c = DAT_1007b39c + DAT_1007b3a0;
    DAT_1007b3a4 = DAT_1007b3a4 + DAT_1007b3a8;
    DAT_1007b3d0 = (DAT_1007b39c / uVar13 & 0xffff) << (DAT_1007b3c8 & 0x1f);
    DAT_1007b3cc = (DAT_1007b3a4 / uVar13 & 0xffff) << (DAT_1007b3c8 & 0x1f);
    DAT_1007b3ac = DAT_1007b3ac + DAT_1007b3b0;
    uVar13 = DAT_1007b3ac >> 0x10;
    if (uVar13 == 0) {
      uVar13 = 1;
    }
    DAT_1007b38c = DAT_1007b38c + DAT_1007b390;
    DAT_1007b394 = DAT_1007b394 + DAT_1007b398;
    iVar6 = (DAT_1007b38c / uVar13 & 0xffff) << (DAT_1007b3b4 & 0x1f);
    iVar7 = (DAT_1007b394 / uVar13 & 0xffff) << (DAT_1007b3b4 & 0x1f);
    DAT_1007b284 = DAT_1007b284 + DAT_1007b288;
    DAT_1007b280 = DAT_1007b280 + DAT_1007b28c;
    iVar10 = (DAT_1007b280 >> 0x10) - (DAT_1007b284 >> 0x10);
    DAT_1007b3b8 = iVar7;
    DAT_1007b3bc = iVar6;
    DAT_1007b548 = DAT_1007b2c0;
    if (DAT_1007b280 >> 0x10 < DAT_1007b284 >> 0x10) break;
    _DAT_1007b2a4 = _DAT_1007b2a4 >> 6 ^ _DAT_1007b2a4;
    DAT_1007b29c = DAT_1007b2a0 + DAT_1007b29c;
    DAT_1007b294 = DAT_1007b294 + DAT_1007b298;
  }
  if (DAT_1007b43c == 0) {
    uVar11 = DAT_1007b3ac - DAT_1007b3c0;
    DAT_1007b514 = DAT_1007b3ac;
    uVar13 = DAT_1007b3c0;
    if ((int)DAT_1007b3ac < (int)DAT_1007b3c0) goto LAB_1006dcfa;
  }
  else {
    uVar11 = DAT_1007b3c0 - DAT_1007b3ac;
    DAT_1007b514 = DAT_1007b3c0;
    uVar13 = DAT_1007b3ac;
    DAT_1007b3b8 = DAT_1007b3cc;
    DAT_1007b3bc = DAT_1007b3d0;
    DAT_1007b3cc = iVar7;
    DAT_1007b3d0 = iVar6;
    if (uVar11 == 0 || (int)DAT_1007b3c0 < (int)DAT_1007b3ac) goto LAB_1006dcfa;
  }
  if ((uVar11 & 0xff800000) != 0) {
    _DAT_1007b51c = -iVar10;
    fVar3 = (float)(int)(DAT_1007b514 - uVar13);
    fVar3 = fVar3 * fVar3;
    fVar3 = fVar3 + fVar3;
    fVar4 = (float)_DAT_1007b51c * (float)(int)DAT_1007b514;
    fVar2 = (float)(int)-(DAT_1007b514 - uVar13) * fVar4;
    fVar1 = fVar4 * fVar4 + fVar2;
    fVar2 = fVar2 + fVar2 + fVar3;
    iVar6 = DAT_1007b3cc - DAT_1007b3b8;
    if (iVar6 == 0) {
      iVar6 = 1;
    }
    uVar11 = DAT_1007b43c;
    if (iVar6 < 0) {
      uVar11 = DAT_1007b43c | 2;
      iVar6 = -iVar6;
    }
    fVar5 = (float)iVar6 * (float)(int)uVar13 * fVar4;
    uVar8 = (uint)fVar5 >> 0xf;
    iVar6 = DAT_1007b3d0 - DAT_1007b3bc;
    if (iVar6 == 0) {
      iVar6 = 1;
    }
    if (iVar6 < 0) {
      uVar11 = uVar11 | 4;
      iVar6 = -iVar6;
    }
    DAT_1007b510 = (float)iVar6 * (float)(int)uVar13 * fVar4;
    DAT_1007b4fc = DAT_1007b3b8 << 0x10;
    DAT_1007b500 = DAT_1007b3bc << 0x10;
    DAT_1007b504 = (int)fVar1 << 8 | 0x80000000;
    bVar12 = (char)((uint)fVar1 >> 0x17) + 0x81;
    uVar14 = (int)fVar2 << 8 | 0x80000000;
    bVar9 = bVar12 - ((char)((uint)fVar2 >> 0x17) + -0x7f);
    if ('\x1f' < (char)bVar9) {
      uVar14 = 0;
    }
    DAT_1007b508 = uVar14 >> (bVar9 & 0x1f);
    uVar14 = (int)fVar3 << 8 | 0x80000000;
    bVar9 = bVar12 - ((char)((uint)fVar3 >> 0x17) + -0x7f);
    if ('\x1f' < (char)bVar9) {
      uVar14 = 0;
    }
    DAT_1007b50c = uVar14 >> (bVar9 & 0x1f);
    iVar6 = (bVar12 - 1) * 0x400;
    DAT_1007b520 = DAT_1007b7c0 +
                   (CONCAT31(CONCAT21((ushort)((uint)fVar5 >> 0x1f),(char)(uVar8 >> 8) + -0x7f),
                             (&DAT_1007b6c0)[uVar8 & 0xff]) + -0x800) * -4 + iVar6;
    DAT_1007b524 = DAT_1007b7c0 +
                   (CONCAT31(CONCAT21((ushort)((uint)DAT_1007b510 >> 0x1f),
                                      (char)(((uint)DAT_1007b510 >> 0xf) >> 8) + -0x7f),
                             (&DAT_1007b6c0)[(uint)DAT_1007b510 >> 0xf & 0xff]) + -0x800) * -4 +
                   iVar6;
                    /* WARNING: Could not recover jumptable at 0x1006e1a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    DAT_1007b494 = iVar10;
    _DAT_1007b528 = uVar13;
    (**(code **)(in_EAX + uVar11 * 4))();
    return;
  }
LAB_1006dcfa:
  DAT_1007b510 = (float)(((DAT_1007b3cc - DAT_1007b3b8) * 0x100) / -iVar10 << 8);
  DAT_1007b514 = ((DAT_1007b3d0 - DAT_1007b3bc) * 0x100) / -iVar10 << 8;
                    /* WARNING: Could not recover jumptable at 0x1006dd66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(in_EAX + 0x20 + DAT_1007b43c * 4))();
  return;
}


