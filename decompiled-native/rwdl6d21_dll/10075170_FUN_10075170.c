// 10075170 FUN_10075170 [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10075170(void)

{
  float fVar1;
  short sVar2;
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
  
  iVar11 = DAT_1007f2b0;
  do {
    fVar8 = _DAT_1007fedc;
    _DAT_1007f468 = _DAT_1007f468 + _DAT_1007f46c;
    _DAT_1007f460 = _DAT_1007f460 + _DAT_1007f464;
    _DAT_1007f458 = _DAT_1007f458 + _DAT_1007f45c;
    _DAT_1007f450 = _DAT_1007f450 + _DAT_1007f454;
    _DAT_1007f448 = _DAT_1007f448 + _DAT_1007f44c;
    _DAT_1007f440 = _DAT_1007f440 + _DAT_1007f444;
    DAT_1007f2c0 = DAT_1007f2c4 + DAT_1007f2c0;
    DAT_1007f280 = DAT_1007f280 + DAT_1007f28c;
    uVar15 = DAT_1007f280 >> 0x10;
    DAT_1007f284 = DAT_1007f284 + DAT_1007f288;
    uVar13 = (DAT_1007f284 >> 0x10) - uVar15;
    if (uVar13 != 0 && uVar15 <= DAT_1007f284 >> 0x10) {
      uVar15 = DAT_1007f294 + uVar15 * 2;
      DAT_1007f490 = uVar13;
      if ((int)uVar13 < 0x15) {
        iVar21 = uVar15 + uVar13 * 2;
        fVar4 = _DAT_1007f448 * (_DAT_1007fedc / _DAT_1007f440);
        fVar1 = _DAT_1007f450 * (_DAT_1007fedc / _DAT_1007f440);
        fVar3 = (_DAT_1007f468 * (_DAT_1007fedc / _DAT_1007f458) - fVar1) *
                *(float *)(&DAT_1007fee8 + uVar13 * 4);
        fVar8 = (_DAT_1007f460 * (_DAT_1007fedc / _DAT_1007f458) - fVar4) *
                *(float *)(&DAT_1007fee8 + uVar13 * 4);
        DAT_1007f498 = fVar1 + _DAT_1007fee4;
        DAT_1007f494 = fVar4 + _DAT_1007fee4;
      }
      else {
        fVar3 = _DAT_1007fee0 / (float)(int)uVar13;
        fVar10 = (_DAT_1007f460 - _DAT_1007f448) * fVar3;
        fVar9 = (_DAT_1007f458 - _DAT_1007f440) * fVar3;
        fVar3 = fVar3 * (_DAT_1007f468 - _DAT_1007f450);
        fVar7 = _DAT_1007f448 * (_DAT_1007fedc / _DAT_1007f440) + _DAT_1007fee4;
        fVar5 = (_DAT_1007fedc / _DAT_1007f440) * _DAT_1007f450 + _DAT_1007fee4;
        DAT_1007f4a4 = fVar7;
        DAT_1007f4a8 = fVar5;
        fVar4 = _DAT_1007f450;
        fVar1 = _DAT_1007f448;
        fVar6 = _DAT_1007f440;
        if ((uVar15 & 3) != 0) {
          iVar21 = 4 - (uVar15 & 3);
          DAT_1007f490 = uVar13 - iVar21;
          fVar1 = *(float *)(&DAT_1007ff48 + iVar21 * 4);
          fVar4 = fVar3 * fVar1 + _DAT_1007f450;
          fVar6 = fVar9 * fVar1 + _DAT_1007f440;
          fVar1 = fVar1 * fVar10 + _DAT_1007f448;
          DAT_1007f4a4 = fVar1 * (_DAT_1007fedc / fVar6) + _DAT_1007fee4;
          DAT_1007f4a8 = (_DAT_1007fedc / fVar6) * fVar4 + _DAT_1007fee4;
          uVar13 = (int)DAT_1007f4a4 - (int)fVar7;
          uVar17 = (int)DAT_1007f4a8 - (int)fVar5;
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
          uVar15 = uVar15 + iVar21 * 2;
          iVar21 = -iVar21;
          do {
            uVar18 = uVar14 >> 0x19;
            uVar19 = uVar14 & 0x3f80;
            uVar14 = uVar14 + (uVar13 & 0xffff0000 | uVar17 & 0x3fff);
            sVar2 = *(short *)(iVar11 + (uVar18 | uVar19) * 2);
            if (sVar2 != 0) {
              *(short *)(uVar15 + iVar21 * 2) = sVar2;
            }
            iVar21 = iVar21 + 1;
          } while (iVar21 < 0);
        }
        fVar8 = fVar8 / (fVar6 + fVar9);
        uVar13 = DAT_1007f490 >> 4;
        fVar7 = fVar6 + fVar9;
        do {
          fVar5 = fVar10 + fVar1;
          fVar1 = fVar3 + fVar4;
          DAT_1007f494 = fVar5 * fVar8 + _DAT_1007fee4;
          DAT_1007f498 = fVar8 * fVar1 + _DAT_1007fee4;
          fVar4 = fVar3;
          fVar6 = fVar5;
          fVar8 = fVar7;
          fVar12 = fVar10;
          if ((char)uVar13 != '\x01') {
            fVar6 = fVar7 + fVar9;
            fVar8 = _DAT_1007fedc / fVar6;
            fVar4 = fVar1;
            fVar12 = fVar9;
            fVar1 = fVar5;
            fVar9 = fVar3;
          }
          fVar3 = fVar9;
          fVar9 = fVar12;
          uVar17 = (int)DAT_1007f494 - (int)DAT_1007f4a4;
          uVar18 = (int)DAT_1007f498 - (int)DAT_1007f4a8;
          uVar14 = (int)DAT_1007f4a4 << 0x10 | (uint)DAT_1007f4a8 >> 2 & 0x3fff;
          iVar21 = -0x10;
          uVar15 = uVar15 + 0x20;
          DAT_1007f4a4 = DAT_1007f494;
          DAT_1007f4a8 = DAT_1007f498;
          do {
            uVar19 = uVar14 >> 0x19;
            uVar20 = uVar14 & 0x3f80;
            uVar14 = uVar14 + ((uVar17 & 0xffff0) << 0xc | uVar18 >> 6 & 0x3fff);
            sVar2 = *(short *)(iVar11 + (uVar19 | uVar20) * 2);
            if (sVar2 != 0) {
              *(short *)(uVar15 + iVar21 * 2) = sVar2;
            }
            iVar21 = iVar21 + 1;
          } while (iVar21 < 0);
          uVar13 = uVar13 - 1;
          fVar7 = fVar6;
        } while (uVar13 != 0);
        uVar13 = DAT_1007f490 & 0xf;
        if (uVar13 == 0) goto LAB_100755fb;
        DAT_1007f494 = (float)((uint)DAT_1007f494 & 0x7fffff);
        DAT_1007f498 = (float)((uint)DAT_1007f498 & 0x7fffff);
        fVar8 = (_DAT_1007f460 * (_DAT_1007fedc / _DAT_1007f458) - (float)(int)DAT_1007f494) *
                *(float *)(&DAT_1007fee8 + uVar13 * 4);
        fVar3 = *(float *)(&DAT_1007fee8 + uVar13 * 4) *
                ((_DAT_1007fedc / _DAT_1007f458) * _DAT_1007f468 - (float)(int)DAT_1007f498);
        iVar21 = uVar15 + uVar13 * 2;
      }
      DAT_1007f4a0 = (uint)ROUND(fVar3);
      DAT_1007f49c = (int)ROUND(fVar8);
      iVar16 = -uVar13;
      uVar15 = ((uint)DAT_1007f498 & 0xffff) >> 2 | (int)DAT_1007f494 << 0x10;
      uVar17 = DAT_1007f49c << 0x10;
      uVar13 = DAT_1007f4a0 & 0xffff;
      do {
        uVar14 = uVar15 >> 0x19;
        uVar18 = uVar15 & 0x3f80;
        uVar15 = uVar15 + (uVar13 >> 2 | uVar17);
        sVar2 = *(short *)(iVar11 + (uVar14 | uVar18) * 2);
        if (sVar2 != 0) {
          *(short *)(iVar21 + iVar16 * 2) = sVar2;
        }
        iVar16 = iVar16 + 1;
      } while (iVar16 < 0);
    }
LAB_100755fb:
    DAT_1007f294 = DAT_1007f298 + DAT_1007f294;
    DAT_1007f290 = DAT_1007f290 + -1;
    if (DAT_1007f290 == 0) {
      return;
    }
  } while( true );
}


