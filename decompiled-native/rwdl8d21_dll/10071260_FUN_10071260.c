// 10071260 FUN_10071260 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10071260(void)

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
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  
  iVar11 = DAT_1007b2b0;
  do {
    fVar8 = _DAT_1007bf64;
    _DAT_1007b468 = _DAT_1007b468 + _DAT_1007b46c;
    _DAT_1007b460 = _DAT_1007b460 + _DAT_1007b464;
    _DAT_1007b458 = _DAT_1007b458 + _DAT_1007b45c;
    _DAT_1007b450 = _DAT_1007b450 + _DAT_1007b454;
    _DAT_1007b448 = _DAT_1007b448 + _DAT_1007b44c;
    _DAT_1007b440 = _DAT_1007b440 + _DAT_1007b444;
    DAT_1007b2c0 = DAT_1007b2c4 + DAT_1007b2c0;
    DAT_1007b280 = DAT_1007b280 + DAT_1007b28c;
    uVar15 = DAT_1007b280 >> 0x10;
    DAT_1007b284 = DAT_1007b284 + DAT_1007b288;
    uVar13 = (DAT_1007b284 >> 0x10) - uVar15;
    if (uVar13 != 0 && uVar15 <= DAT_1007b284 >> 0x10) {
      uVar15 = uVar15 + DAT_1007b294;
      DAT_1007b490 = uVar13;
      if ((int)uVar13 < 0x15) {
        iVar21 = uVar15 + uVar13;
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
        if ((uVar15 & 3) != 0) {
          iVar21 = 4 - (uVar15 & 3);
          DAT_1007b490 = uVar13 - iVar21;
          fVar1 = *(float *)(&DAT_1007bfd8 + iVar21 * 4);
          fVar4 = fVar3 * fVar1 + _DAT_1007b450;
          fVar6 = fVar9 * fVar1 + _DAT_1007b440;
          fVar1 = fVar1 * fVar10 + _DAT_1007b448;
          DAT_1007b4a4 = fVar1 * (_DAT_1007bf64 / fVar6) + _DAT_1007bf74;
          DAT_1007b4a8 = (_DAT_1007bf64 / fVar6) * fVar4 + _DAT_1007bf74;
          uVar13 = (int)DAT_1007b4a4 - (int)fVar7;
          uVar17 = (int)DAT_1007b4a8 - (int)fVar5;
          if (1 < iVar21) {
            if (iVar21 == 2) {
              uVar13 = uVar13 * 0x8000;
              uVar17 = (int)uVar17 >> 3;
            }
            else {
              uVar13 = uVar13 * 0x5000;
              uVar17 = (int)(uVar17 * 5) >> 6;
            }
          }
          uVar14 = (uint)fVar5 >> 2 & 0x3fff | (int)fVar7 << 0x10;
          uVar15 = uVar15 + iVar21;
          iVar21 = -iVar21;
          do {
            uVar18 = uVar14 >> 0x19;
            uVar19 = uVar14 & 0x780;
            uVar14 = uVar14 + (uVar13 & 0xffff0000 | uVar17 & 0x3fff);
            cVar2 = *(char *)((uVar18 & 0xf | uVar19 >> 3) + iVar11);
            if (cVar2 != '\0') {
              *(char *)(iVar21 + uVar15) = cVar2;
            }
            iVar21 = iVar21 + 1;
          } while (iVar21 < 0);
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
          uVar17 = (int)DAT_1007b494 - (int)DAT_1007b4a4;
          uVar18 = (int)DAT_1007b498 - (int)DAT_1007b4a8;
          uVar14 = (int)DAT_1007b4a4 << 0x10 | (uint)DAT_1007b4a8 >> 2 & 0x3fff;
          iVar21 = -0x10;
          uVar15 = uVar15 + 0x10;
          DAT_1007b4a4 = DAT_1007b494;
          DAT_1007b4a8 = DAT_1007b498;
          do {
            uVar19 = uVar14 >> 0x19;
            uVar20 = uVar14 & 0x780;
            uVar14 = uVar14 + ((uVar17 & 0xffff0) << 0xc | uVar18 >> 6 & 0x3fff);
            cVar2 = *(char *)((uVar19 & 0xf | uVar20 >> 3) + iVar11);
            if (cVar2 != '\0') {
              *(char *)(iVar21 + uVar15) = cVar2;
            }
            iVar21 = iVar21 + 1;
          } while (iVar21 < 0);
          uVar13 = uVar13 - 1;
          fVar7 = fVar6;
        } while (uVar13 != 0);
        uVar13 = DAT_1007b490 & 0xf;
        if (uVar13 == 0) goto LAB_100716ee;
        DAT_1007b494 = (float)((uint)DAT_1007b494 & 0x7fffff);
        DAT_1007b498 = (float)((uint)DAT_1007b498 & 0x7fffff);
        fVar8 = (_DAT_1007b460 * (_DAT_1007bf64 / _DAT_1007b458) - (float)(int)DAT_1007b494) *
                *(float *)(&DAT_1007bf78 + uVar13 * 4);
        fVar3 = *(float *)(&DAT_1007bf78 + uVar13 * 4) *
                ((_DAT_1007bf64 / _DAT_1007b458) * _DAT_1007b468 - (float)(int)DAT_1007b498);
        iVar21 = uVar15 + uVar13;
      }
      DAT_1007b4a0 = (uint)ROUND(fVar3);
      DAT_1007b49c = (int)ROUND(fVar8);
      iVar16 = -uVar13;
      uVar13 = ((uint)DAT_1007b498 & 0xffff) >> 2 | (int)DAT_1007b494 << 0x10;
      uVar17 = DAT_1007b49c << 0x10;
      uVar15 = DAT_1007b4a0 & 0xffff;
      do {
        uVar14 = uVar13 >> 0x19;
        uVar18 = uVar13 & 0x780;
        uVar13 = uVar13 + (uVar15 >> 2 | uVar17);
        cVar2 = *(char *)((uVar14 & 0xf | uVar18 >> 3) + iVar11);
        if (cVar2 != '\0') {
          *(char *)(iVar16 + iVar21) = cVar2;
        }
        iVar16 = iVar16 + 1;
      } while (iVar16 < 0);
    }
LAB_100716ee:
    DAT_1007b294 = DAT_1007b298 + DAT_1007b294;
    DAT_1007b290 = DAT_1007b290 + -1;
    if (DAT_1007b290 == 0) {
      return;
    }
  } while( true );
}


