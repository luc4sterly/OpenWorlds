// 1007e0d0 FUN_1007e0d0 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1007e0d0(void)

{
  ulonglong uVar1;
  undefined8 uVar2;
  bool bVar3;
  ulonglong uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  uint uVar11;
  int iVar12;
  uint extraout_EDX;
  int iVar13;
  uint uVar14;
  ushort uVar15;
  ushort uVar16;
  ushort uVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  ushort uVar23;
  ushort uVar24;
  ushort uVar25;
  ulonglong uVar22;
  ulonglong uVar26;
  ulonglong uVar27;
  short sVar28;
  short sVar29;
  short sVar30;
  short sVar31;
  ulonglong uVar32;
  
  sVar28 = (ushort)DAT_1008d2a8 * 8;
  uVar15 = ((short)DAT_1008d2b8 - (short)DAT_1008d59c) * 2 |
           (ushort)((uint)(DAT_1008d2bc - DAT_1008d59c) >> 5) |
           ((short)DAT_1008d2b4 - (short)DAT_1008d59c) * 0x40;
  uVar18 = CONCAT26(uVar15 >> 6,CONCAT24(uVar15 >> 6,CONCAT22(uVar15 >> 6,uVar15 >> 6))) &
           DAT_1008e038;
  uVar20 = CONCAT44(CONCAT22(uVar15,uVar15),CONCAT22(uVar15,uVar15)) & DAT_1008e038;
  DAT_1008e1d0 = CONCAT26((ushort)((uVar15 >> 0xb) * sVar28) >> 5,
                          CONCAT24((ushort)((uVar15 >> 0xb) * sVar28) >> 5,
                                   CONCAT22((ushort)((uVar15 >> 0xb) * sVar28) >> 5,
                                            (ushort)((uVar15 >> 0xb) * sVar28) >> 5)));
  DAT_1008e1d8 = CONCAT26((ushort)((short)(uVar18 >> 0x30) * sVar28) >> 5,
                          CONCAT24((ushort)((short)(uVar18 >> 0x20) * sVar28) >> 5,
                                   CONCAT22((ushort)((short)(uVar18 >> 0x10) * sVar28) >> 5,
                                            (ushort)((short)uVar18 * sVar28) >> 5)));
  DAT_1008e1e0 = CONCAT26((ushort)((short)(uVar20 >> 0x30) * sVar28) >> 5,
                          CONCAT24((ushort)((short)(uVar20 >> 0x20) * sVar28) >> 5,
                                   CONCAT22((ushort)((short)(uVar20 >> 0x10) * sVar28) >> 5,
                                            (ushort)((short)uVar20 * sVar28) >> 5)));
  DAT_1008f3b0 = CONCAT44(CONCAT22(sVar28,sVar28),CONCAT22(sVar28,sVar28)) ^ _DAT_1008e018;
  do {
    iVar13 = DAT_1008d294;
    DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar11 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    iVar12 = uVar11 - (DAT_1008d284 >> 0x10);
    fVar5 = _DAT_1008d440 + _DAT_1008d444;
    fVar6 = _DAT_1008d448 + _DAT_1008d44c;
    fVar7 = _DAT_1008d450 + _DAT_1008d454;
    fVar8 = _DAT_1008d458 + _DAT_1008d45c;
    fVar9 = _DAT_1008d460 + _DAT_1008d464;
    fVar10 = _DAT_1008d468 + _DAT_1008d46c;
    if (uVar11 < DAT_1008d284 >> 0x10) {
      FUN_1007d650(iVar12);
      FUN_1007da2f(iVar12);
      uVar18 = DAT_1008f3b0;
      uVar14 = iVar13 - 2U & 0xfffffff8;
      iVar13 = (uVar11 & 0xfffffff8) - uVar14;
      uVar20 = DAT_1008e038;
      do {
        uVar4 = DAT_1008e038;
        uVar22 = *(ulonglong *)(iVar13 + (extraout_EDX & 0xfffffff8));
        uVar15 = (ushort)(uVar22 >> 0x10);
        uVar16 = (ushort)(uVar22 >> 0x20);
        uVar17 = (ushort)(uVar22 >> 0x30);
        uVar21 = uVar22 & uVar20;
        uVar19 = CONCAT26(uVar17 >> 6,
                          CONCAT24(uVar16 >> 6,CONCAT22(uVar15 >> 6,(ushort)uVar22 >> 6))) & uVar20;
        uVar1 = *(ulonglong *)(iVar13 + uVar14);
        uVar23 = (ushort)(uVar1 >> 0x10);
        uVar24 = (ushort)(uVar1 >> 0x20);
        uVar25 = (ushort)(uVar1 >> 0x30);
        uVar27 = uVar1 & uVar20;
        sVar28 = (short)uVar18;
        sVar29 = (short)(uVar18 >> 0x10);
        sVar30 = (short)(uVar18 >> 0x20);
        sVar31 = (short)(uVar18 >> 0x30);
        uVar26 = CONCAT26(uVar25 >> 6,CONCAT24(uVar24 >> 6,CONCAT22(uVar23 >> 6,(ushort)uVar1 >> 6))
                         ) & uVar20;
        uVar32 = psllw(uVar20,0xb);
        uVar20 = CONCAT26((short)(uVar19 >> 0x30) * (short)((ulonglong)DAT_1008e1d8 >> 0x30) +
                          (short)(uVar26 >> 0x30) * sVar31,
                          CONCAT24((short)(uVar19 >> 0x20) *
                                   (short)((ulonglong)DAT_1008e1d8 >> 0x20) +
                                   (short)(uVar26 >> 0x20) * sVar30,
                                   CONCAT22((short)(uVar19 >> 0x10) *
                                            (short)((ulonglong)DAT_1008e1d8 >> 0x10) +
                                            (short)(uVar26 >> 0x10) * sVar29,
                                            (short)uVar19 * (short)DAT_1008e1d8 +
                                            (short)uVar26 * sVar28))) & uVar32;
        uVar2 = *(undefined8 *)(iVar13 + (extraout_EDX & 0xfffffff8));
        uVar20 = CONCAT26((uVar17 >> 0xb) * (short)((ulonglong)DAT_1008e1d0 >> 0x30) +
                          (uVar25 >> 0xb) * sVar31,
                          CONCAT24((uVar16 >> 0xb) * (short)((ulonglong)DAT_1008e1d0 >> 0x20) +
                                   (uVar24 >> 0xb) * sVar30,
                                   CONCAT22((uVar15 >> 0xb) *
                                            (short)((ulonglong)DAT_1008e1d0 >> 0x10) +
                                            (uVar23 >> 0xb) * sVar29,
                                            ((ushort)uVar22 >> 0xb) * (short)DAT_1008e1d0 +
                                            ((ushort)uVar1 >> 0xb) * sVar28))) & uVar32 |
                 CONCAT26((ushort)((short)(uVar21 >> 0x30) *
                                   (short)((ulonglong)DAT_1008e1e0 >> 0x30) +
                                  (short)(uVar27 >> 0x30) * sVar31) >> 0xb,
                          CONCAT24((ushort)((short)(uVar21 >> 0x20) *
                                            (short)((ulonglong)DAT_1008e1e0 >> 0x20) +
                                           (short)(uVar27 >> 0x20) * sVar30) >> 0xb,
                                   CONCAT22((ushort)((short)(uVar21 >> 0x10) *
                                                     (short)((ulonglong)DAT_1008e1e0 >> 0x10) +
                                                    (short)(uVar27 >> 0x10) * sVar29) >> 0xb,
                                            (ushort)((short)uVar21 * (short)DAT_1008e1e0 +
                                                    (short)uVar27 * sVar28) >> 0xb))) |
                 CONCAT26((ushort)(uVar20 >> 0x35),
                          CONCAT24((ushort)(uVar20 >> 0x20) >> 5,
                                   CONCAT22((ushort)(uVar20 >> 0x10) >> 5,(ushort)uVar20 >> 5)));
        uVar22 = CONCAT26(-(ushort)((short)((ulonglong)uVar2 >> 0x30) ==
                                   (short)((ulonglong)DAT_1008e008 >> 0x30)),
                          CONCAT24(-(ushort)((short)((ulonglong)uVar2 >> 0x20) ==
                                            (short)((ulonglong)DAT_1008e008 >> 0x20)),
                                   CONCAT22(-(ushort)((short)((ulonglong)uVar2 >> 0x10) ==
                                                     (short)((ulonglong)DAT_1008e008 >> 0x10)),
                                            -(ushort)((short)uVar2 == (short)DAT_1008e008))));
        *(ulonglong *)(iVar13 + uVar14) =
             *(ulonglong *)(iVar13 + uVar14) & uVar22 |
             ~uVar22 & CONCAT26((short)(uVar20 >> 0x30) + (short)((ulonglong)DAT_1008dbe0 >> 0x30),
                                CONCAT24((short)(uVar20 >> 0x20) +
                                         (short)((ulonglong)DAT_1008dbe0 >> 0x20),
                                         CONCAT22((short)(uVar20 >> 0x10) +
                                                  (short)((ulonglong)DAT_1008dbe0 >> 0x10),
                                                  (short)uVar20 + (short)DAT_1008dbe0)));
        iVar12 = iVar13 + 8;
        bVar3 = iVar13 < -8;
        iVar13 = iVar12;
        uVar20 = uVar4;
        fVar5 = _DAT_1008d440;
        fVar6 = _DAT_1008d448;
        fVar7 = _DAT_1008d450;
        fVar8 = _DAT_1008d458;
        fVar9 = _DAT_1008d460;
        fVar10 = _DAT_1008d468;
      } while (iVar12 == 0 || bVar3);
    }
    _DAT_1008d468 = fVar10;
    _DAT_1008d460 = fVar9;
    _DAT_1008d458 = fVar8;
    _DAT_1008d450 = fVar7;
    _DAT_1008d448 = fVar6;
    _DAT_1008d440 = fVar5;
    DAT_1008d29c = DAT_1008d29c + DAT_1008d2a0;
    DAT_1008d294 = DAT_1008d298 + DAT_1008d294;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


