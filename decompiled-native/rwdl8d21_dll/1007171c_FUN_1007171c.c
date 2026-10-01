// 1007171c FUN_1007171c [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1007171c(void)

{
  float fVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  float fVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  ushort uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  
  iVar17 = DAT_1007b2b0;
  do {
    fVar8 = _DAT_1007bf64;
    DAT_1007b2e4 = DAT_1007b2e4 + DAT_1007b2e8;
    _DAT_1007b468 = _DAT_1007b468 + _DAT_1007b46c;
    _DAT_1007b460 = _DAT_1007b460 + _DAT_1007b464;
    _DAT_1007b458 = _DAT_1007b458 + _DAT_1007b45c;
    _DAT_1007b450 = _DAT_1007b450 + _DAT_1007b454;
    _DAT_1007b448 = _DAT_1007b448 + _DAT_1007b44c;
    _DAT_1007b440 = _DAT_1007b440 + _DAT_1007b444;
    DAT_1007b2c0 = DAT_1007b2c4 + DAT_1007b2c0;
    DAT_1007b280 = DAT_1007b280 + DAT_1007b28c;
    uVar14 = DAT_1007b280 >> 0x10;
    DAT_1007b284 = DAT_1007b284 + DAT_1007b288;
    uVar13 = (DAT_1007b284 >> 0x10) - uVar14;
    if (uVar13 != 0 && uVar14 <= DAT_1007b284 >> 0x10) {
      DAT_1007bf58 = DAT_1007b29c + uVar14 * 2;
      uVar14 = uVar14 + DAT_1007b294;
      DAT_1007b490 = uVar13;
      DAT_1007bf54 = DAT_1007b2e4;
      if ((int)uVar13 < 0x15) {
        iVar22 = uVar14 + uVar13;
        DAT_1007bf58 = DAT_1007bf58 + uVar13 * 2;
        fVar4 = _DAT_1007b448 * (_DAT_1007bf64 / _DAT_1007b440);
        fVar1 = _DAT_1007b450 * (_DAT_1007bf64 / _DAT_1007b440);
        fVar3 = (_DAT_1007b468 * (_DAT_1007bf64 / _DAT_1007b458) - fVar1) *
                *(float *)(&DAT_1007bf78 + uVar13 * 4);
        fVar8 = (_DAT_1007b460 * (_DAT_1007bf64 / _DAT_1007b458) - fVar4) *
                *(float *)(&DAT_1007bf78 + uVar13 * 4);
        DAT_1007b498 = fVar1 + _DAT_1007bf74;
        DAT_1007b494 = fVar4 + _DAT_1007bf74;
      }
      else {
        fVar3 = _DAT_1007bf6c / (float)(int)uVar13;
        fVar10 = (_DAT_1007b460 - _DAT_1007b448) * fVar3;
        fVar9 = (_DAT_1007b458 - _DAT_1007b440) * fVar3;
        fVar3 = fVar3 * (_DAT_1007b468 - _DAT_1007b450);
        fVar7 = _DAT_1007b448 * (_DAT_1007bf64 / _DAT_1007b440) + _DAT_1007bf74;
        fVar5 = (_DAT_1007bf64 / _DAT_1007b440) * _DAT_1007b450 + _DAT_1007bf74;
        DAT_1007b4a4 = fVar7;
        DAT_1007b4a8 = fVar5;
        fVar4 = _DAT_1007b450;
        fVar1 = _DAT_1007b448;
        fVar6 = _DAT_1007b440;
        if ((uVar14 & 3) != 0) {
          iVar17 = 4 - (uVar14 & 3);
          DAT_1007b490 = uVar13 - iVar17;
          fVar1 = *(float *)(&DAT_1007bfd8 + iVar17 * 4);
          fVar4 = fVar3 * fVar1 + _DAT_1007b450;
          fVar6 = fVar9 * fVar1 + _DAT_1007b440;
          fVar1 = fVar1 * fVar10 + _DAT_1007b448;
          DAT_1007b4a4 = fVar1 * (_DAT_1007bf64 / fVar6) + _DAT_1007bf74;
          DAT_1007b4a8 = (_DAT_1007bf64 / fVar6) * fVar4 + _DAT_1007bf74;
          uVar13 = (int)DAT_1007b4a4 - (int)fVar7;
          uVar19 = (int)DAT_1007b4a8 - (int)fVar5;
          if (1 < iVar17) {
            if (iVar17 == 2) {
              uVar13 = uVar13 * 0x8000;
              uVar19 = (int)uVar19 >> 3;
            }
            else {
              uVar13 = uVar13 * 0x5000;
              uVar19 = (int)(uVar19 * 5) >> 6;
            }
          }
          _DAT_1007bf50 = uVar13 & 0xffff0000 | uVar19 & 0x3fff;
          uVar13 = (uint)fVar5 >> 2 & 0x3fff | (int)fVar7 << 0x10;
          DAT_1007bf58 = DAT_1007bf58 + iVar17 * 2;
          uVar14 = uVar14 + iVar17;
          iVar17 = -iVar17;
          iVar22 = DAT_1007b2e4;
          do {
            iVar16 = DAT_1007bf58;
            uVar19 = uVar13 >> 0x19;
            uVar20 = uVar13 & 0x780;
            uVar13 = uVar13 + _DAT_1007bf50;
            cVar2 = *(char *)((uVar19 & 0xf | uVar20 >> 3) + DAT_1007b2b0);
            DAT_1007bf54 = iVar22 + DAT_1007b2ec;
            uVar18 = (ushort)((uint)iVar22 >> 0x10);
            if ((*(ushort *)(DAT_1007bf58 + iVar17 * 2) < uVar18) && (cVar2 != '\0')) {
              *(char *)(iVar17 + uVar14) = cVar2;
              *(ushort *)(iVar16 + iVar17 * 2) = uVar18;
            }
            iVar17 = iVar17 + 1;
            iVar22 = DAT_1007bf54;
          } while (iVar17 < 0);
        }
        fVar8 = fVar8 / (fVar6 + fVar9);
        uVar13 = DAT_1007b490 >> 4;
        fVar7 = fVar6 + fVar9;
        do {
          fVar5 = fVar10 + fVar1;
          fVar1 = fVar3 + fVar4;
          DAT_1007b494 = fVar5 * fVar8 + _DAT_1007bf74;
          DAT_1007b498 = fVar8 * fVar1 + _DAT_1007bf74;
          fVar4 = fVar3;
          fVar6 = fVar5;
          fVar8 = fVar7;
          fVar12 = fVar10;
          if ((char)uVar13 != '\x01') {
            fVar6 = fVar7 + fVar9;
            fVar8 = _DAT_1007bf64 / fVar6;
            fVar4 = fVar1;
            fVar12 = fVar9;
            fVar1 = fVar5;
            fVar9 = fVar3;
          }
          fVar3 = fVar9;
          fVar9 = fVar12;
          uVar19 = (int)DAT_1007b4a4 << 0x10 | (uint)DAT_1007b4a8 >> 2 & 0x3fff;
          _DAT_1007bf50 =
               ((int)DAT_1007b494 - (int)DAT_1007b4a4 & 0xffff0U) << 0xc |
               (uint)((int)DAT_1007b498 - (int)DAT_1007b4a8) >> 6 & 0x3fff;
          DAT_1007bf58 = DAT_1007bf58 + 0x20;
          iVar22 = -0x10;
          uVar14 = uVar14 + 0x10;
          iVar17 = DAT_1007bf54;
          DAT_1007b4a4 = DAT_1007b494;
          DAT_1007b4a8 = DAT_1007b498;
          do {
            iVar16 = DAT_1007bf58;
            uVar20 = uVar19 >> 0x19;
            uVar21 = uVar19 & 0x780;
            uVar19 = uVar19 + _DAT_1007bf50;
            cVar2 = *(char *)((uVar20 & 0xf | uVar21 >> 3) + DAT_1007b2b0);
            DAT_1007bf54 = iVar17 + DAT_1007b2ec;
            uVar18 = (ushort)((uint)iVar17 >> 0x10);
            if ((*(ushort *)(DAT_1007bf58 + iVar22 * 2) < uVar18) && (cVar2 != '\0')) {
              *(char *)(iVar22 + uVar14) = cVar2;
              *(ushort *)(iVar16 + iVar22 * 2) = uVar18;
            }
            iVar22 = iVar22 + 1;
            iVar17 = DAT_1007bf54;
          } while (iVar22 < 0);
          uVar13 = uVar13 - 1;
          fVar7 = fVar6;
        } while (uVar13 != 0);
        uVar13 = DAT_1007b490 & 0xf;
        iVar17 = DAT_1007b2b0;
        if (uVar13 == 0) goto LAB_10071cb8;
        DAT_1007b494 = (float)((uint)DAT_1007b494 & 0x7fffff);
        DAT_1007b498 = (float)((uint)DAT_1007b498 & 0x7fffff);
        fVar8 = (_DAT_1007b460 * (_DAT_1007bf64 / _DAT_1007b458) - (float)(int)DAT_1007b494) *
                *(float *)(&DAT_1007bf78 + uVar13 * 4);
        fVar3 = *(float *)(&DAT_1007bf78 + uVar13 * 4) *
                ((_DAT_1007bf64 / _DAT_1007b458) * _DAT_1007b468 - (float)(int)DAT_1007b498);
        iVar22 = uVar14 + uVar13;
        DAT_1007bf58 = DAT_1007bf58 + uVar13 * 2;
      }
      DAT_1007b4a0 = (uint)ROUND(fVar3);
      DAT_1007b49c = (int)ROUND(fVar8);
      iVar15 = -uVar13;
      uVar14 = ((uint)DAT_1007b498 & 0xffff) >> 2 | (int)DAT_1007b494 << 0x10;
      _DAT_1007bf50 = (DAT_1007b4a0 & 0xffff) >> 2 | DAT_1007b49c << 0x10;
      iVar16 = DAT_1007bf54;
      do {
        iVar11 = DAT_1007bf58;
        uVar13 = uVar14 >> 0x19;
        uVar19 = uVar14 & 0x780;
        uVar14 = uVar14 + _DAT_1007bf50;
        cVar2 = *(char *)((uVar13 & 0xf | uVar19 >> 3) + iVar17);
        iVar17 = iVar16 + DAT_1007b2ec;
        uVar18 = (ushort)((uint)iVar16 >> 0x10);
        if ((*(ushort *)(DAT_1007bf58 + iVar15 * 2) < uVar18) && (cVar2 != '\0')) {
          *(char *)(iVar15 + iVar22) = cVar2;
          *(ushort *)(iVar11 + iVar15 * 2) = uVar18;
        }
        iVar15 = iVar15 + 1;
        iVar16 = iVar17;
        iVar17 = DAT_1007b2b0;
      } while (iVar15 < 0);
    }
LAB_10071cb8:
    DAT_1007b29c = DAT_1007b29c + DAT_1007b2a0;
    DAT_1007b294 = DAT_1007b298 + DAT_1007b294;
    DAT_1007b290 = DAT_1007b290 + -1;
    if (DAT_1007b290 == 0) {
      return;
    }
  } while( true );
}


