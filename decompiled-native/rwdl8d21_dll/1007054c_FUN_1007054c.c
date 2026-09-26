// 1007054c FUN_1007054c [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1007054c(void)

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
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  
  iVar15 = DAT_1007b2b0;
  do {
    fVar7 = _DAT_1007bec4;
    iVar11 = DAT_1007b2cc + DAT_1007b2d0;
    _DAT_1007b468 = _DAT_1007b468 + _DAT_1007b46c;
    _DAT_1007b460 = _DAT_1007b460 + _DAT_1007b464;
    _DAT_1007b458 = _DAT_1007b458 + _DAT_1007b45c;
    _DAT_1007b450 = _DAT_1007b450 + _DAT_1007b454;
    _DAT_1007b448 = _DAT_1007b448 + _DAT_1007b44c;
    _DAT_1007b440 = _DAT_1007b440 + _DAT_1007b444;
    DAT_1007b2c0 = DAT_1007b2c4 + DAT_1007b2c0;
    DAT_1007b280 = DAT_1007b280 + DAT_1007b28c;
    uVar13 = DAT_1007b280 >> 0x10;
    DAT_1007b284 = DAT_1007b284 + DAT_1007b288;
    uVar12 = (DAT_1007b284 >> 0x10) - uVar13;
    DAT_1007b2cc = iVar11;
    if (uVar12 != 0 && uVar13 <= DAT_1007b284 >> 0x10) {
      DAT_1007bebc = *(uint *)(DAT_1007b590 + (DAT_1007b280 >> 0x10 & 7) * 4) ^ _DAT_1007b2a4 & 0xff
      ;
      uVar13 = uVar13 + DAT_1007b294;
      DAT_1007b490 = uVar12;
      DAT_1007bec0 = iVar11;
      if ((int)uVar12 < 0x15) {
        iVar11 = uVar13 + uVar12;
        fVar3 = _DAT_1007b448 * (_DAT_1007bec4 / _DAT_1007b440);
        fVar1 = _DAT_1007b450 * (_DAT_1007bec4 / _DAT_1007b440);
        fVar2 = (_DAT_1007b468 * (_DAT_1007bec4 / _DAT_1007b458) - fVar1) *
                *(float *)(&DAT_1007bed8 + uVar12 * 4);
        fVar7 = (_DAT_1007b460 * (_DAT_1007bec4 / _DAT_1007b458) - fVar3) *
                *(float *)(&DAT_1007bed8 + uVar12 * 4);
        DAT_1007b498 = fVar1 + _DAT_1007bed4;
        DAT_1007b494 = fVar3 + _DAT_1007bed4;
      }
      else {
        fVar2 = _DAT_1007becc / (float)(int)uVar12;
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
        if ((uVar13 & 3) != 0) {
          iVar15 = 4 - (uVar13 & 3);
          DAT_1007b490 = uVar12 - iVar15;
          fVar1 = *(float *)(&DAT_1007bf38 + iVar15 * 4);
          fVar3 = fVar2 * fVar1 + _DAT_1007b450;
          fVar5 = fVar8 * fVar1 + _DAT_1007b440;
          fVar1 = fVar1 * fVar9 + _DAT_1007b448;
          DAT_1007b4a4 = fVar1 * (_DAT_1007bec4 / fVar5) + _DAT_1007bed4;
          DAT_1007b4a8 = (_DAT_1007bec4 / fVar5) * fVar3 + _DAT_1007bed4;
          uVar12 = (int)DAT_1007b4a4 - (int)fVar6;
          uVar17 = (int)DAT_1007b4a8 - (int)fVar4;
          if (1 < iVar15) {
            if (iVar15 == 2) {
              uVar12 = uVar12 * 0x8000;
              uVar17 = (int)uVar17 >> 3;
            }
            else {
              uVar12 = uVar12 * 0x5000;
              uVar17 = (int)(uVar17 * 5) >> 6;
            }
          }
          _DAT_1007beb0 = uVar12 & 0xffff0000 | uVar17 & 0x3fff;
          uVar12 = (uint)fVar4 >> 2 & 0x3fff | (int)fVar6 << 0x10;
          uVar13 = uVar13 + iVar15;
          iVar15 = -iVar15;
          do {
            uVar17 = uVar12 >> 0x19;
            uVar18 = uVar12 & 0x3f80;
            uVar12 = uVar12 + _DAT_1007beb0;
            uVar17 = (uint)*(byte *)(DAT_1007b2b0 + (uVar17 | uVar18));
            if (uVar17 != 0) {
              *(undefined1 *)(iVar15 + uVar13) =
                   *(undefined1 *)
                    (uVar17 + ((DAT_1007bebc & 0xff) + iVar11 & 0xff00) + DAT_1007b59c);
            }
            iVar11 = iVar11 + DAT_1007b2d4;
            DAT_1007bebc = DAT_1007bebc >> 6 ^ DAT_1007bebc;
            iVar15 = iVar15 + 1;
            DAT_1007bec0 = iVar11;
          } while (iVar15 < 0);
        }
        fVar7 = fVar7 / (fVar5 + fVar8);
        uVar12 = DAT_1007b490 >> 4;
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
          if ((char)uVar12 != '\x01') {
            fVar5 = fVar6 + fVar8;
            fVar7 = _DAT_1007bec4 / fVar5;
            fVar3 = fVar1;
            fVar10 = fVar8;
            fVar1 = fVar4;
            fVar8 = fVar2;
          }
          fVar2 = fVar8;
          fVar8 = fVar10;
          uVar17 = (int)DAT_1007b4a4 << 0x10 | (uint)DAT_1007b4a8 >> 2 & 0x3fff;
          _DAT_1007beb0 =
               ((int)DAT_1007b494 - (int)DAT_1007b4a4 & 0xffff0U) << 0xc |
               (uint)((int)DAT_1007b498 - (int)DAT_1007b4a8) >> 6 & 0x3fff;
          iVar15 = -0x10;
          uVar13 = uVar13 + 0x10;
          DAT_1007b4a4 = DAT_1007b494;
          DAT_1007b4a8 = DAT_1007b498;
          do {
            uVar18 = uVar17 >> 0x19;
            uVar19 = uVar17 & 0x3f80;
            uVar17 = uVar17 + _DAT_1007beb0;
            uVar18 = (uint)*(byte *)(DAT_1007b2b0 + (uVar18 | uVar19));
            if (uVar18 != 0) {
              *(undefined1 *)(iVar15 + uVar13) =
                   *(undefined1 *)
                    (uVar18 + ((DAT_1007bebc & 0xff) + DAT_1007bec0 & 0xff00) + DAT_1007b59c);
            }
            DAT_1007bec0 = DAT_1007bec0 + DAT_1007b2d4;
            DAT_1007bebc = DAT_1007bebc >> 6 ^ DAT_1007bebc;
            iVar15 = iVar15 + 1;
          } while (iVar15 < 0);
          uVar12 = uVar12 - 1;
          fVar6 = fVar5;
        } while (uVar12 != 0);
        uVar12 = DAT_1007b490 & 0xf;
        iVar15 = DAT_1007b2b0;
        if (uVar12 == 0) goto LAB_10070b1f;
        DAT_1007b494 = (float)((uint)DAT_1007b494 & 0x7fffff);
        DAT_1007b498 = (float)((uint)DAT_1007b498 & 0x7fffff);
        fVar7 = (_DAT_1007b460 * (_DAT_1007bec4 / _DAT_1007b458) - (float)(int)DAT_1007b494) *
                *(float *)(&DAT_1007bed8 + uVar12 * 4);
        fVar2 = *(float *)(&DAT_1007bed8 + uVar12 * 4) *
                ((_DAT_1007bec4 / _DAT_1007b458) * _DAT_1007b468 - (float)(int)DAT_1007b498);
        iVar11 = uVar13 + uVar12;
      }
      DAT_1007b4a0 = (uint)ROUND(fVar2);
      DAT_1007b49c = (int)ROUND(fVar7);
      iVar14 = -uVar12;
      uVar13 = ((uint)DAT_1007b498 & 0xffff) >> 2 | (int)DAT_1007b494 << 0x10;
      _DAT_1007beb0 = (DAT_1007b4a0 & 0xffff) >> 2 | DAT_1007b49c << 0x10;
      iVar16 = DAT_1007bec0;
      do {
        uVar12 = uVar13 >> 0x19;
        uVar17 = uVar13 & 0x3f80;
        uVar13 = uVar13 + _DAT_1007beb0;
        uVar12 = (uint)*(byte *)(iVar15 + (uVar12 | uVar17));
        if (uVar12 != 0) {
          *(undefined1 *)(iVar14 + iVar11) =
               *(undefined1 *)(uVar12 + ((DAT_1007bebc & 0xff) + iVar16 & 0xff00) + DAT_1007b59c);
        }
        iVar16 = iVar16 + DAT_1007b2d4;
        DAT_1007bebc = DAT_1007bebc >> 6 ^ DAT_1007bebc;
        iVar14 = iVar14 + 1;
        iVar15 = DAT_1007b2b0;
      } while (iVar14 < 0);
    }
LAB_10070b1f:
    _DAT_1007b2a4 = _DAT_1007b2a4 ^ _DAT_1007b2a4 >> 6;
    DAT_1007b294 = DAT_1007b298 + DAT_1007b294;
    DAT_1007b290 = DAT_1007b290 + -1;
    if (DAT_1007b290 == 0) {
      return;
    }
  } while( true );
}


