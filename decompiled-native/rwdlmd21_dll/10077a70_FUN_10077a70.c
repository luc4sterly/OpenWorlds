// 10077a70 FUN_10077a70 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10077a70(void)

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
    fVar8 = _DAT_1008df6c;
    DAT_1008d2e4 = DAT_1008d2e4 + DAT_1008d2e8;
    _DAT_1008d468 = _DAT_1008d468 + _DAT_1008d46c;
    _DAT_1008d460 = _DAT_1008d460 + _DAT_1008d464;
    _DAT_1008d458 = _DAT_1008d458 + _DAT_1008d45c;
    _DAT_1008d450 = _DAT_1008d450 + _DAT_1008d454;
    _DAT_1008d448 = _DAT_1008d448 + _DAT_1008d44c;
    _DAT_1008d440 = _DAT_1008d440 + _DAT_1008d444;
    DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar14 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    uVar13 = (DAT_1008d284 >> 0x10) - uVar14;
    if (uVar13 != 0 && uVar14 <= DAT_1008d284 >> 0x10) {
      DAT_1008df68 = DAT_1008d29c + uVar14 * 2;
      uVar14 = DAT_1008d294 + uVar14 * 2;
      DAT_1008d490 = uVar13;
      DAT_1008df64 = DAT_1008d2e4;
      if ((int)uVar13 < 0x15) {
        iVar22 = uVar14 + uVar13 * 2;
        DAT_1008df68 = DAT_1008df68 + uVar13 * 2;
        fVar4 = _DAT_1008d448 * (_DAT_1008df6c / _DAT_1008d440);
        fVar1 = _DAT_1008d450 * (_DAT_1008df6c / _DAT_1008d440);
        fVar3 = (_DAT_1008d468 * (_DAT_1008df6c / _DAT_1008d458) - fVar1) *
                *(float *)(&DAT_1008df78 + uVar13 * 4);
        fVar8 = (_DAT_1008d460 * (_DAT_1008df6c / _DAT_1008d458) - fVar4) *
                *(float *)(&DAT_1008df78 + uVar13 * 4);
        DAT_1008d498 = fVar1 + _DAT_1008df74;
        DAT_1008d494 = fVar4 + _DAT_1008df74;
      }
      else {
        fVar3 = _DAT_1008df70 / (float)(int)uVar13;
        fVar10 = (_DAT_1008d460 - _DAT_1008d448) * fVar3;
        fVar9 = (_DAT_1008d458 - _DAT_1008d440) * fVar3;
        fVar3 = fVar3 * (_DAT_1008d468 - _DAT_1008d450);
        fVar7 = _DAT_1008d448 * (_DAT_1008df6c / _DAT_1008d440) + _DAT_1008df74;
        fVar5 = (_DAT_1008df6c / _DAT_1008d440) * _DAT_1008d450 + _DAT_1008df74;
        DAT_1008d4a4 = fVar7;
        DAT_1008d4a8 = fVar5;
        fVar4 = _DAT_1008d450;
        fVar1 = _DAT_1008d448;
        fVar6 = _DAT_1008d440;
        if ((uVar14 & 3) != 0) {
          iVar22 = 4 - (uVar14 & 3);
          DAT_1008d490 = uVar13 - iVar22;
          fVar1 = *(float *)(&DAT_1008dfd8 + iVar22 * 4);
          fVar4 = fVar3 * fVar1 + _DAT_1008d450;
          fVar6 = fVar9 * fVar1 + _DAT_1008d440;
          fVar1 = fVar1 * fVar10 + _DAT_1008d448;
          DAT_1008d4a4 = fVar1 * (_DAT_1008df6c / fVar6) + _DAT_1008df74;
          DAT_1008d4a8 = (_DAT_1008df6c / fVar6) * fVar4 + _DAT_1008df74;
          uVar13 = (int)DAT_1008d4a4 - (int)fVar7;
          uVar19 = (int)DAT_1008d4a8 - (int)fVar5;
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
          _DAT_1008df60 = uVar13 & 0xffff0000 | uVar19 & 0x3fff;
          uVar13 = (uint)fVar5 >> 2 & 0x3fff | (int)fVar7 << 0x10;
          uVar14 = uVar14 + iVar22 * 2;
          DAT_1008df68 = DAT_1008df68 + iVar22 * 2;
          iVar22 = -iVar22;
          iVar16 = DAT_1008d2e4;
          do {
            iVar15 = DAT_1008df68;
            uVar19 = uVar13 >> 0x19;
            uVar20 = uVar13 & 0x780;
            uVar13 = uVar13 + _DAT_1008df60;
            sVar2 = *(short *)(DAT_1008d2b0 + (uVar19 & 0xf | uVar20 >> 3) * 2);
            DAT_1008df64 = iVar16 + DAT_1008d2ec;
            uVar18 = (ushort)((uint)iVar16 >> 0x10);
            if ((*(ushort *)(DAT_1008df68 + iVar22 * 2) < uVar18) && (sVar2 != 0)) {
              *(short *)(uVar14 + iVar22 * 2) = sVar2;
              *(ushort *)(iVar15 + iVar22 * 2) = uVar18;
            }
            iVar22 = iVar22 + 1;
            iVar16 = DAT_1008df64;
          } while (iVar22 < 0);
        }
        fVar8 = fVar8 / (fVar6 + fVar9);
        uVar13 = DAT_1008d490 >> 4;
        fVar7 = fVar6 + fVar9;
        do {
          fVar5 = fVar10 + fVar1;
          fVar1 = fVar3 + fVar4;
          DAT_1008d494 = fVar5 * fVar8 + _DAT_1008df74;
          DAT_1008d498 = fVar8 * fVar1 + _DAT_1008df74;
          fVar4 = fVar3;
          fVar6 = fVar5;
          fVar8 = fVar7;
          fVar12 = fVar10;
          if ((char)uVar13 != '\x01') {
            fVar6 = fVar7 + fVar9;
            fVar8 = _DAT_1008df6c / fVar6;
            fVar4 = fVar1;
            fVar12 = fVar9;
            fVar1 = fVar5;
            fVar9 = fVar3;
          }
          fVar3 = fVar9;
          fVar9 = fVar12;
          uVar19 = (int)DAT_1008d4a4 << 0x10 | (uint)DAT_1008d4a8 >> 2 & 0x3fff;
          _DAT_1008df60 =
               ((int)DAT_1008d494 - (int)DAT_1008d4a4 & 0xffff0U) << 0xc |
               (uint)((int)DAT_1008d498 - (int)DAT_1008d4a8) >> 6 & 0x3fff;
          DAT_1008df68 = DAT_1008df68 + 0x20;
          iVar16 = -0x10;
          uVar14 = uVar14 + 0x20;
          iVar22 = DAT_1008df64;
          DAT_1008d4a4 = DAT_1008d494;
          DAT_1008d4a8 = DAT_1008d498;
          do {
            iVar15 = DAT_1008df68;
            uVar20 = uVar19 >> 0x19;
            uVar21 = uVar19 & 0x780;
            uVar19 = uVar19 + _DAT_1008df60;
            sVar2 = *(short *)(DAT_1008d2b0 + (uVar20 & 0xf | uVar21 >> 3) * 2);
            DAT_1008df64 = iVar22 + DAT_1008d2ec;
            uVar18 = (ushort)((uint)iVar22 >> 0x10);
            if ((*(ushort *)(DAT_1008df68 + iVar16 * 2) < uVar18) && (sVar2 != 0)) {
              *(short *)(uVar14 + iVar16 * 2) = sVar2;
              *(ushort *)(iVar15 + iVar16 * 2) = uVar18;
            }
            iVar16 = iVar16 + 1;
            iVar22 = DAT_1008df64;
          } while (iVar16 < 0);
          uVar13 = uVar13 - 1;
          fVar7 = fVar6;
        } while (uVar13 != 0);
        uVar13 = DAT_1008d490 & 0xf;
        if (uVar13 == 0) goto LAB_1007801f;
        DAT_1008d494 = (float)((uint)DAT_1008d494 & 0x7fffff);
        DAT_1008d498 = (float)((uint)DAT_1008d498 & 0x7fffff);
        fVar8 = (_DAT_1008d460 * (_DAT_1008df6c / _DAT_1008d458) - (float)(int)DAT_1008d494) *
                *(float *)(&DAT_1008df78 + uVar13 * 4);
        fVar3 = *(float *)(&DAT_1008df78 + uVar13 * 4) *
                ((_DAT_1008df6c / _DAT_1008d458) * _DAT_1008d468 - (float)(int)DAT_1008d498);
        iVar22 = uVar14 + uVar13 * 2;
        DAT_1008df68 = DAT_1008df68 + uVar13 * 2;
      }
      DAT_1008d4a0 = (uint)ROUND(fVar3);
      DAT_1008d49c = (int)ROUND(fVar8);
      iVar15 = -uVar13;
      uVar13 = ((uint)DAT_1008d498 & 0xffff) >> 2 | (int)DAT_1008d494 << 0x10;
      _DAT_1008df60 = (DAT_1008d4a0 & 0xffff) >> 2 | DAT_1008d49c << 0x10;
      iVar16 = DAT_1008df64;
      do {
        iVar11 = DAT_1008df68;
        uVar14 = uVar13 >> 0x19;
        uVar19 = uVar13 & 0x780;
        uVar13 = uVar13 + _DAT_1008df60;
        sVar2 = *(short *)(DAT_1008d2b0 + (uVar14 & 0xf | uVar19 >> 3) * 2);
        iVar17 = iVar16 + DAT_1008d2ec;
        uVar18 = (ushort)((uint)iVar16 >> 0x10);
        if ((*(ushort *)(DAT_1008df68 + iVar15 * 2) < uVar18) && (sVar2 != 0)) {
          *(short *)(iVar22 + iVar15 * 2) = sVar2;
          *(ushort *)(iVar11 + iVar15 * 2) = uVar18;
        }
        iVar15 = iVar15 + 1;
        iVar16 = iVar17;
      } while (iVar15 < 0);
    }
LAB_1007801f:
    DAT_1008d29c = DAT_1008d29c + DAT_1008d2a0;
    DAT_1008d294 = DAT_1008d298 + DAT_1008d294;
    DAT_1008d290 = DAT_1008d290 + -1;
    if (DAT_1008d290 == 0) {
      return;
    }
  } while( true );
}


