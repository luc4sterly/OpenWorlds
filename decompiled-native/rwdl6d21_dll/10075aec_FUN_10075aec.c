// 10075aec FUN_10075aec [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10075aec(void)

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
  int iVar15;
  int iVar16;
  int iVar17;
  ushort uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  
  do {
    fVar8 = _DAT_1007fedc;
    DAT_1007f2e4 = DAT_1007f2e4 + DAT_1007f2e8;
    _DAT_1007f468 = _DAT_1007f468 + _DAT_1007f46c;
    _DAT_1007f460 = _DAT_1007f460 + _DAT_1007f464;
    _DAT_1007f458 = _DAT_1007f458 + _DAT_1007f45c;
    _DAT_1007f450 = _DAT_1007f450 + _DAT_1007f454;
    _DAT_1007f448 = _DAT_1007f448 + _DAT_1007f44c;
    _DAT_1007f440 = _DAT_1007f440 + _DAT_1007f444;
    DAT_1007f2c0 = DAT_1007f2c4 + DAT_1007f2c0;
    DAT_1007f280 = DAT_1007f280 + DAT_1007f28c;
    uVar14 = DAT_1007f280 >> 0x10;
    DAT_1007f284 = DAT_1007f284 + DAT_1007f288;
    uVar13 = (DAT_1007f284 >> 0x10) - uVar14;
    if (uVar13 != 0 && uVar14 <= DAT_1007f284 >> 0x10) {
      DAT_1007fed8 = DAT_1007f29c + uVar14 * 2;
      uVar14 = DAT_1007f294 + uVar14 * 2;
      DAT_1007f490 = uVar13;
      DAT_1007fed4 = DAT_1007f2e4;
      if ((int)uVar13 < 0x15) {
        iVar22 = uVar14 + uVar13 * 2;
        DAT_1007fed8 = DAT_1007fed8 + uVar13 * 2;
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
        if ((uVar14 & 3) != 0) {
          iVar22 = 4 - (uVar14 & 3);
          DAT_1007f490 = uVar13 - iVar22;
          fVar1 = *(float *)(&DAT_1007ff48 + iVar22 * 4);
          fVar4 = fVar3 * fVar1 + _DAT_1007f450;
          fVar6 = fVar9 * fVar1 + _DAT_1007f440;
          fVar1 = fVar1 * fVar10 + _DAT_1007f448;
          DAT_1007f4a4 = fVar1 * (_DAT_1007fedc / fVar6) + _DAT_1007fee4;
          DAT_1007f4a8 = (_DAT_1007fedc / fVar6) * fVar4 + _DAT_1007fee4;
          uVar13 = (int)DAT_1007f4a4 - (int)fVar7;
          uVar19 = (int)DAT_1007f4a8 - (int)fVar5;
          if (1 < iVar22) {
            if (iVar22 == 2) {
              uVar13 = uVar13 * 0x8000;
              uVar19 = (int)uVar19 >> 3;
            }
            else {
              uVar13 = uVar13 * 0x5000;
              uVar19 = (int)(uVar19 * 5) >> 6;
            }
          }
          _DAT_1007fed0 = uVar13 & 0xffff0000 | uVar19 & 0x3fff;
          uVar13 = (uint)fVar5 >> 2 & 0x3fff | (int)fVar7 << 0x10;
          uVar14 = uVar14 + iVar22 * 2;
          DAT_1007fed8 = DAT_1007fed8 + iVar22 * 2;
          iVar22 = -iVar22;
          iVar16 = DAT_1007f2e4;
          do {
            iVar15 = DAT_1007fed8;
            uVar19 = uVar13 >> 0x19;
            uVar20 = uVar13 & 0x3f80;
            uVar13 = uVar13 + _DAT_1007fed0;
            sVar2 = *(short *)(DAT_1007f2b0 + (uVar19 | uVar20) * 2);
            DAT_1007fed4 = iVar16 + DAT_1007f2ec;
            uVar18 = (ushort)((uint)iVar16 >> 0x10);
            if ((*(ushort *)(DAT_1007fed8 + iVar22 * 2) < uVar18) && (sVar2 != 0)) {
              *(short *)(uVar14 + iVar22 * 2) = sVar2;
              *(ushort *)(iVar15 + iVar22 * 2) = uVar18;
            }
            iVar22 = iVar22 + 1;
            iVar16 = DAT_1007fed4;
          } while (iVar22 < 0);
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
          uVar19 = (int)DAT_1007f4a4 << 0x10 | (uint)DAT_1007f4a8 >> 2 & 0x3fff;
          _DAT_1007fed0 =
               ((int)DAT_1007f494 - (int)DAT_1007f4a4 & 0xffff0U) << 0xc |
               (uint)((int)DAT_1007f498 - (int)DAT_1007f4a8) >> 6 & 0x3fff;
          DAT_1007fed8 = DAT_1007fed8 + 0x20;
          iVar16 = -0x10;
          uVar14 = uVar14 + 0x20;
          iVar22 = DAT_1007fed4;
          DAT_1007f4a4 = DAT_1007f494;
          DAT_1007f4a8 = DAT_1007f498;
          do {
            iVar15 = DAT_1007fed8;
            uVar20 = uVar19 >> 0x19;
            uVar21 = uVar19 & 0x3f80;
            uVar19 = uVar19 + _DAT_1007fed0;
            sVar2 = *(short *)(DAT_1007f2b0 + (uVar20 | uVar21) * 2);
            DAT_1007fed4 = iVar22 + DAT_1007f2ec;
            uVar18 = (ushort)((uint)iVar22 >> 0x10);
            if ((*(ushort *)(DAT_1007fed8 + iVar16 * 2) < uVar18) && (sVar2 != 0)) {
              *(short *)(uVar14 + iVar16 * 2) = sVar2;
              *(ushort *)(iVar15 + iVar16 * 2) = uVar18;
            }
            iVar16 = iVar16 + 1;
            iVar22 = DAT_1007fed4;
          } while (iVar16 < 0);
          uVar13 = uVar13 - 1;
          fVar7 = fVar6;
        } while (uVar13 != 0);
        uVar13 = DAT_1007f490 & 0xf;
        if (uVar13 == 0) goto LAB_10076089;
        DAT_1007f494 = (float)((uint)DAT_1007f494 & 0x7fffff);
        DAT_1007f498 = (float)((uint)DAT_1007f498 & 0x7fffff);
        fVar8 = (_DAT_1007f460 * (_DAT_1007fedc / _DAT_1007f458) - (float)(int)DAT_1007f494) *
                *(float *)(&DAT_1007fee8 + uVar13 * 4);
        fVar3 = *(float *)(&DAT_1007fee8 + uVar13 * 4) *
                ((_DAT_1007fedc / _DAT_1007f458) * _DAT_1007f468 - (float)(int)DAT_1007f498);
        iVar22 = uVar14 + uVar13 * 2;
        DAT_1007fed8 = DAT_1007fed8 + uVar13 * 2;
      }
      DAT_1007f4a0 = (uint)ROUND(fVar3);
      DAT_1007f49c = (int)ROUND(fVar8);
      iVar15 = -uVar13;
      uVar13 = ((uint)DAT_1007f498 & 0xffff) >> 2 | (int)DAT_1007f494 << 0x10;
      _DAT_1007fed0 = (DAT_1007f4a0 & 0xffff) >> 2 | DAT_1007f49c << 0x10;
      iVar16 = DAT_1007fed4;
      do {
        iVar11 = DAT_1007fed8;
        uVar14 = uVar13 >> 0x19;
        uVar19 = uVar13 & 0x3f80;
        uVar13 = uVar13 + _DAT_1007fed0;
        sVar2 = *(short *)(DAT_1007f2b0 + (uVar14 | uVar19) * 2);
        iVar17 = iVar16 + DAT_1007f2ec;
        uVar18 = (ushort)((uint)iVar16 >> 0x10);
        if ((*(ushort *)(DAT_1007fed8 + iVar15 * 2) < uVar18) && (sVar2 != 0)) {
          *(short *)(iVar22 + iVar15 * 2) = sVar2;
          *(ushort *)(iVar11 + iVar15 * 2) = uVar18;
        }
        iVar15 = iVar15 + 1;
        iVar16 = iVar17;
      } while (iVar15 < 0);
    }
LAB_10076089:
    DAT_1007f29c = DAT_1007f29c + DAT_1007f2a0;
    DAT_1007f294 = DAT_1007f298 + DAT_1007f294;
    DAT_1007f290 = DAT_1007f290 + -1;
    if (DAT_1007f290 == 0) {
      return;
    }
  } while( true );
}


