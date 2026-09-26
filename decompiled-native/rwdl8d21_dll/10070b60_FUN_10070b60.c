// 10070b60 FUN_10070b60 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10070b60(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ushort uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  
  iVar15 = DAT_1007b2b0;
  do {
    fVar7 = _DAT_1007bec4;
    DAT_1007b2cc = DAT_1007b2cc + DAT_1007b2d0;
    _DAT_1007b468 = _DAT_1007b468 + _DAT_1007b46c;
    _DAT_1007b460 = _DAT_1007b460 + _DAT_1007b464;
    DAT_1007b2e4 = DAT_1007b2e4 + DAT_1007b2e8;
    _DAT_1007b458 = _DAT_1007b458 + _DAT_1007b45c;
    _DAT_1007b450 = _DAT_1007b450 + _DAT_1007b454;
    _DAT_1007b448 = _DAT_1007b448 + _DAT_1007b44c;
    _DAT_1007b440 = _DAT_1007b440 + _DAT_1007b444;
    DAT_1007b2c0 = DAT_1007b2c4 + DAT_1007b2c0;
    DAT_1007b280 = DAT_1007b280 + DAT_1007b28c;
    uVar12 = DAT_1007b280 >> 0x10;
    DAT_1007b284 = DAT_1007b284 + DAT_1007b288;
    uVar11 = (DAT_1007b284 >> 0x10) - uVar12;
    if (uVar11 != 0 && uVar12 <= DAT_1007b284 >> 0x10) {
      DAT_1007bebc = *(uint *)(DAT_1007b590 + (DAT_1007b280 >> 0x10 & 7) * 4) ^ _DAT_1007b2a4 & 0xff
      ;
      uVar17 = uVar12 + DAT_1007b294;
      DAT_1007beb8 = DAT_1007b29c + uVar12 * 2;
      DAT_1007b490 = uVar11;
      DAT_1007beb4 = DAT_1007b2e4;
      DAT_1007bec0 = DAT_1007b2cc;
      if ((int)uVar11 < 0x15) {
        iVar20 = uVar17 + uVar11;
        DAT_1007beb8 = DAT_1007beb8 + uVar11 * 2;
        fVar3 = _DAT_1007b448 * (_DAT_1007bec4 / _DAT_1007b440);
        fVar1 = _DAT_1007b450 * (_DAT_1007bec4 / _DAT_1007b440);
        fVar2 = (_DAT_1007b468 * (_DAT_1007bec4 / _DAT_1007b458) - fVar1) *
                *(float *)(&DAT_1007bed8 + uVar11 * 4);
        fVar7 = (_DAT_1007b460 * (_DAT_1007bec4 / _DAT_1007b458) - fVar3) *
                *(float *)(&DAT_1007bed8 + uVar11 * 4);
        DAT_1007b498 = fVar1 + _DAT_1007bed4;
        DAT_1007b494 = fVar3 + _DAT_1007bed4;
      }
      else {
        fVar2 = _DAT_1007becc / (float)(int)uVar11;
        fVar9 = (_DAT_1007b460 - _DAT_1007b448) * fVar2;
        fVar8 = (_DAT_1007b458 - _DAT_1007b440) * fVar2;
        fVar2 = fVar2 * (_DAT_1007b468 - _DAT_1007b450);
        fVar6 = _DAT_1007b448 * (_DAT_1007bec4 / _DAT_1007b440) + _DAT_1007bed4;
        fVar4 = (_DAT_1007bec4 / _DAT_1007b440) * _DAT_1007b450 + _DAT_1007bed4;
        DAT_1007b4a4 = fVar6;
        DAT_1007b4a8 = fVar4;
        fVar3 = _DAT_1007b450;
        fVar1 = _DAT_1007b448;
        fVar5 = _DAT_1007b440;
        if ((uVar17 & 3) != 0) {
          iVar15 = 4 - (uVar17 & 3);
          DAT_1007b490 = uVar11 - iVar15;
          fVar1 = *(float *)(&DAT_1007bf38 + iVar15 * 4);
          fVar3 = fVar2 * fVar1 + _DAT_1007b450;
          fVar5 = fVar8 * fVar1 + _DAT_1007b440;
          fVar1 = fVar1 * fVar9 + _DAT_1007b448;
          DAT_1007b4a4 = fVar1 * (_DAT_1007bec4 / fVar5) + _DAT_1007bed4;
          DAT_1007b4a8 = (_DAT_1007bec4 / fVar5) * fVar3 + _DAT_1007bed4;
          uVar11 = (int)DAT_1007b4a4 - (int)fVar6;
          uVar12 = (int)DAT_1007b4a8 - (int)fVar4;
          if (1 < iVar15) {
            if (iVar15 == 2) {
              uVar11 = uVar11 * 0x8000;
              uVar12 = (int)uVar12 >> 3;
            }
            else {
              uVar11 = uVar11 * 0x5000;
              uVar12 = (int)(uVar12 * 5) >> 6;
            }
          }
          _DAT_1007beb0 = uVar11 & 0xffff0000 | uVar12 & 0x3fff;
          uVar11 = (uint)fVar4 >> 2 & 0x3fff | (int)fVar6 << 0x10;
          DAT_1007beb8 = DAT_1007beb8 + iVar15 * 2;
          uVar17 = uVar17 + iVar15;
          iVar15 = -iVar15;
          iVar20 = DAT_1007b2e4;
          do {
            uVar12 = uVar11 >> 0x19;
            uVar18 = uVar11 & 0x3f80;
            uVar11 = uVar11 + _DAT_1007beb0;
            uVar12 = (uint)*(byte *)(DAT_1007b2b0 + (uVar12 | uVar18));
            DAT_1007beb4 = iVar20 + DAT_1007b2ec;
            uVar16 = (ushort)((uint)iVar20 >> 0x10);
            if ((*(ushort *)(DAT_1007beb8 + iVar15 * 2) < uVar16) && (uVar12 != 0)) {
              *(ushort *)(DAT_1007beb8 + iVar15 * 2) = uVar16;
              *(undefined1 *)(iVar15 + uVar17) =
                   *(undefined1 *)
                    (uVar12 + ((DAT_1007bebc & 0xff) + DAT_1007bec0 & 0xff00) + DAT_1007b59c);
            }
            DAT_1007bec0 = DAT_1007b2d4 + DAT_1007bec0;
            DAT_1007bebc = DAT_1007bebc >> 6 ^ DAT_1007bebc;
            iVar15 = iVar15 + 1;
            iVar20 = DAT_1007beb4;
          } while (iVar15 < 0);
        }
        fVar7 = fVar7 / (fVar5 + fVar8);
        uVar11 = DAT_1007b490 >> 4;
        fVar6 = fVar5 + fVar8;
        do {
          fVar4 = fVar9 + fVar1;
          fVar1 = fVar2 + fVar3;
          DAT_1007b494 = fVar4 * fVar7 + _DAT_1007bed4;
          DAT_1007b498 = fVar7 * fVar1 + _DAT_1007bed4;
          fVar3 = fVar2;
          fVar5 = fVar4;
          fVar7 = fVar6;
          fVar10 = fVar9;
          if ((char)uVar11 != '\x01') {
            fVar5 = fVar6 + fVar8;
            fVar7 = _DAT_1007bec4 / fVar5;
            fVar3 = fVar1;
            fVar10 = fVar8;
            fVar1 = fVar4;
            fVar8 = fVar2;
          }
          fVar2 = fVar8;
          fVar8 = fVar10;
          uVar12 = (int)DAT_1007b4a4 << 0x10 | (uint)DAT_1007b4a8 >> 2 & 0x3fff;
          _DAT_1007beb0 =
               ((int)DAT_1007b494 - (int)DAT_1007b4a4 & 0xffff0U) << 0xc |
               (uint)((int)DAT_1007b498 - (int)DAT_1007b4a8) >> 6 & 0x3fff;
          DAT_1007beb8 = DAT_1007beb8 + 0x20;
          iVar20 = -0x10;
          uVar17 = uVar17 + 0x10;
          iVar15 = DAT_1007beb4;
          DAT_1007b4a4 = DAT_1007b494;
          DAT_1007b4a8 = DAT_1007b498;
          do {
            uVar18 = uVar12 >> 0x19;
            uVar19 = uVar12 & 0x3f80;
            uVar12 = uVar12 + _DAT_1007beb0;
            uVar18 = (uint)*(byte *)(DAT_1007b2b0 + (uVar18 | uVar19));
            DAT_1007beb4 = iVar15 + DAT_1007b2ec;
            uVar16 = (ushort)((uint)iVar15 >> 0x10);
            if ((*(ushort *)(DAT_1007beb8 + iVar20 * 2) < uVar16) && (uVar18 != 0)) {
              *(ushort *)(DAT_1007beb8 + iVar20 * 2) = uVar16;
              *(undefined1 *)(iVar20 + uVar17) =
                   *(undefined1 *)
                    (uVar18 + ((DAT_1007bebc & 0xff) + DAT_1007bec0 & 0xff00) + DAT_1007b59c);
            }
            DAT_1007bec0 = DAT_1007b2d4 + DAT_1007bec0;
            DAT_1007bebc = DAT_1007bebc >> 6 ^ DAT_1007bebc;
            iVar20 = iVar20 + 1;
            iVar15 = DAT_1007beb4;
          } while (iVar20 < 0);
          uVar11 = uVar11 - 1;
          fVar6 = fVar5;
        } while (uVar11 != 0);
        uVar11 = DAT_1007b490 & 0xf;
        iVar15 = DAT_1007b2b0;
        if (uVar11 == 0) goto LAB_10071211;
        DAT_1007b494 = (float)((uint)DAT_1007b494 & 0x7fffff);
        DAT_1007b498 = (float)((uint)DAT_1007b498 & 0x7fffff);
        fVar7 = (_DAT_1007b460 * (_DAT_1007bec4 / _DAT_1007b458) - (float)(int)DAT_1007b494) *
                *(float *)(&DAT_1007bed8 + uVar11 * 4);
        fVar2 = *(float *)(&DAT_1007bed8 + uVar11 * 4) *
                ((_DAT_1007bec4 / _DAT_1007b458) * _DAT_1007b468 - (float)(int)DAT_1007b498);
        iVar20 = uVar17 + uVar11;
        DAT_1007beb8 = DAT_1007beb8 + uVar11 * 2;
      }
      DAT_1007b4a0 = (uint)ROUND(fVar2);
      DAT_1007b49c = (int)ROUND(fVar7);
      iVar13 = -uVar11;
      uVar11 = ((uint)DAT_1007b498 & 0xffff) >> 2 | (int)DAT_1007b494 << 0x10;
      _DAT_1007beb0 = (DAT_1007b4a0 & 0xffff) >> 2 | DAT_1007b49c << 0x10;
      iVar14 = DAT_1007beb4;
      do {
        uVar12 = uVar11 >> 0x19;
        uVar17 = uVar11 & 0x3f80;
        uVar11 = uVar11 + _DAT_1007beb0;
        uVar12 = (uint)*(byte *)(iVar15 + (uVar12 | uVar17));
        iVar15 = iVar14 + DAT_1007b2ec;
        uVar16 = (ushort)((uint)iVar14 >> 0x10);
        if ((*(ushort *)(DAT_1007beb8 + iVar13 * 2) < uVar16) && (uVar12 != 0)) {
          *(ushort *)(DAT_1007beb8 + iVar13 * 2) = uVar16;
          *(undefined1 *)(iVar13 + iVar20) =
               *(undefined1 *)
                (uVar12 + ((DAT_1007bebc & 0xff) + DAT_1007bec0 & 0xff00) + DAT_1007b59c);
        }
        DAT_1007bec0 = DAT_1007b2d4 + DAT_1007bec0;
        DAT_1007bebc = DAT_1007bebc >> 6 ^ DAT_1007bebc;
        iVar13 = iVar13 + 1;
        iVar14 = iVar15;
        iVar15 = DAT_1007b2b0;
      } while (iVar13 < 0);
    }
LAB_10071211:
    _DAT_1007b2a4 = _DAT_1007b2a4 ^ _DAT_1007b2a4 >> 6;
    DAT_1007b29c = DAT_1007b29c + DAT_1007b2a0;
    DAT_1007b294 = DAT_1007b298 + DAT_1007b294;
    DAT_1007b290 = DAT_1007b290 + -1;
    if (DAT_1007b290 == 0) {
      return;
    }
  } while( true );
}


