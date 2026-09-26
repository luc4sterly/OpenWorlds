// 10078db8 FUN_10078db8 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10078db8(void)

{
  ulonglong uVar1;
  undefined8 uVar2;
  bool bVar3;
  ulonglong uVar4;
  uint uVar5;
  uint extraout_EDX;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  ushort uVar10;
  ushort uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ushort uVar17;
  ushort uVar18;
  ushort uVar19;
  ulonglong uVar16;
  ulonglong uVar20;
  ulonglong uVar21;
  short sVar22;
  short sVar23;
  short sVar24;
  short sVar25;
  ulonglong uVar26;
  
  sVar22 = (ushort)DAT_1008d2a8 * 8;
  uVar9 = ((short)DAT_1008d2b8 - (short)DAT_1008d59c) * 2 |
          (ushort)((uint)(DAT_1008d2bc - DAT_1008d59c) >> 5) |
          ((short)DAT_1008d2b4 - (short)DAT_1008d59c) * 0x40;
  uVar12 = CONCAT26(uVar9 >> 6,CONCAT24(uVar9 >> 6,CONCAT22(uVar9 >> 6,uVar9 >> 6))) & DAT_1008e038;
  uVar14 = CONCAT44(CONCAT22(uVar9,uVar9),CONCAT22(uVar9,uVar9)) & DAT_1008e038;
  DAT_1008e1d0 = CONCAT26((ushort)((uVar9 >> 0xb) * sVar22) >> 5,
                          CONCAT24((ushort)((uVar9 >> 0xb) * sVar22) >> 5,
                                   CONCAT22((ushort)((uVar9 >> 0xb) * sVar22) >> 5,
                                            (ushort)((uVar9 >> 0xb) * sVar22) >> 5)));
  DAT_1008e1d8 = CONCAT26((ushort)((short)(uVar12 >> 0x30) * sVar22) >> 5,
                          CONCAT24((ushort)((short)(uVar12 >> 0x20) * sVar22) >> 5,
                                   CONCAT22((ushort)((short)(uVar12 >> 0x10) * sVar22) >> 5,
                                            (ushort)((short)uVar12 * sVar22) >> 5)));
  DAT_1008e1e0 = CONCAT26((ushort)((short)(uVar14 >> 0x30) * sVar22) >> 5,
                          CONCAT24((ushort)((short)(uVar14 >> 0x20) * sVar22) >> 5,
                                   CONCAT22((ushort)((short)(uVar14 >> 0x10) * sVar22) >> 5,
                                            (ushort)((short)uVar14 * sVar22) >> 5)));
  uVar12 = CONCAT44(CONCAT22(sVar22,sVar22),CONCAT22(sVar22,sVar22)) ^ _DAT_1008e018;
  do {
    iVar6 = DAT_1008d294;
    DAT_1008d2e4 = DAT_1008d2e4 + DAT_1008d2e8;
    DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0 & 0x7fff7fff;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar5 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    if (uVar5 < DAT_1008d284 >> 0x10) {
      FUN_10078140(uVar5 - (DAT_1008d284 >> 0x10));
      uVar8 = iVar6 - 2U & 0xfffffff8;
      iVar6 = (uVar5 & 0xfffffff8) - uVar8;
      uVar14 = DAT_1008e038;
      do {
        uVar4 = DAT_1008e038;
        uVar16 = *(ulonglong *)(iVar6 + (extraout_EDX & 0xfffffff8));
        uVar9 = (ushort)(uVar16 >> 0x10);
        uVar10 = (ushort)(uVar16 >> 0x20);
        uVar11 = (ushort)(uVar16 >> 0x30);
        uVar15 = uVar16 & uVar14;
        uVar13 = CONCAT26(uVar11 >> 6,CONCAT24(uVar10 >> 6,CONCAT22(uVar9 >> 6,(ushort)uVar16 >> 6))
                         ) & uVar14;
        uVar1 = *(ulonglong *)(iVar6 + uVar8);
        uVar17 = (ushort)(uVar1 >> 0x10);
        uVar18 = (ushort)(uVar1 >> 0x20);
        uVar19 = (ushort)(uVar1 >> 0x30);
        uVar21 = uVar1 & uVar14;
        sVar22 = (short)uVar12;
        sVar23 = (short)(uVar12 >> 0x10);
        sVar24 = (short)(uVar12 >> 0x20);
        sVar25 = (short)(uVar12 >> 0x30);
        uVar20 = CONCAT26(uVar19 >> 6,CONCAT24(uVar18 >> 6,CONCAT22(uVar17 >> 6,(ushort)uVar1 >> 6))
                         ) & uVar14;
        uVar26 = psllw(uVar14,0xb);
        uVar14 = CONCAT26((short)(uVar13 >> 0x30) * (short)((ulonglong)DAT_1008e1d8 >> 0x30) +
                          (short)(uVar20 >> 0x30) * sVar25,
                          CONCAT24((short)(uVar13 >> 0x20) *
                                   (short)((ulonglong)DAT_1008e1d8 >> 0x20) +
                                   (short)(uVar20 >> 0x20) * sVar24,
                                   CONCAT22((short)(uVar13 >> 0x10) *
                                            (short)((ulonglong)DAT_1008e1d8 >> 0x10) +
                                            (short)(uVar20 >> 0x10) * sVar23,
                                            (short)uVar13 * (short)DAT_1008e1d8 +
                                            (short)uVar20 * sVar22))) & uVar26;
        uVar2 = *(undefined8 *)(iVar6 + (extraout_EDX & 0xfffffff8));
        uVar14 = CONCAT26((uVar11 >> 0xb) * (short)((ulonglong)DAT_1008e1d0 >> 0x30) +
                          (uVar19 >> 0xb) * sVar25,
                          CONCAT24((uVar10 >> 0xb) * (short)((ulonglong)DAT_1008e1d0 >> 0x20) +
                                   (uVar18 >> 0xb) * sVar24,
                                   CONCAT22((uVar9 >> 0xb) *
                                            (short)((ulonglong)DAT_1008e1d0 >> 0x10) +
                                            (uVar17 >> 0xb) * sVar23,
                                            ((ushort)uVar16 >> 0xb) * (short)DAT_1008e1d0 +
                                            ((ushort)uVar1 >> 0xb) * sVar22))) & uVar26 |
                 CONCAT26((ushort)((short)(uVar15 >> 0x30) *
                                   (short)((ulonglong)DAT_1008e1e0 >> 0x30) +
                                  (short)(uVar21 >> 0x30) * sVar25) >> 0xb,
                          CONCAT24((ushort)((short)(uVar15 >> 0x20) *
                                            (short)((ulonglong)DAT_1008e1e0 >> 0x20) +
                                           (short)(uVar21 >> 0x20) * sVar24) >> 0xb,
                                   CONCAT22((ushort)((short)(uVar15 >> 0x10) *
                                                     (short)((ulonglong)DAT_1008e1e0 >> 0x10) +
                                                    (short)(uVar21 >> 0x10) * sVar23) >> 0xb,
                                            (ushort)((short)uVar15 * (short)DAT_1008e1e0 +
                                                    (short)uVar21 * sVar22) >> 0xb))) |
                 CONCAT26((ushort)(uVar14 >> 0x35),
                          CONCAT24((ushort)(uVar14 >> 0x20) >> 5,
                                   CONCAT22((ushort)(uVar14 >> 0x10) >> 5,(ushort)uVar14 >> 5)));
        uVar16 = CONCAT26(-(ushort)((short)((ulonglong)uVar2 >> 0x30) ==
                                   (short)((ulonglong)DAT_1008e008 >> 0x30)),
                          CONCAT24(-(ushort)((short)((ulonglong)uVar2 >> 0x20) ==
                                            (short)((ulonglong)DAT_1008e008 >> 0x20)),
                                   CONCAT22(-(ushort)((short)((ulonglong)uVar2 >> 0x10) ==
                                                     (short)((ulonglong)DAT_1008e008 >> 0x10)),
                                            -(ushort)((short)uVar2 == (short)DAT_1008e008))));
        *(ulonglong *)(iVar6 + uVar8) =
             *(ulonglong *)(iVar6 + uVar8) & uVar16 |
             ~uVar16 & CONCAT26((short)(uVar14 >> 0x30) + (short)((ulonglong)DAT_1008dbe0 >> 0x30),
                                CONCAT24((short)(uVar14 >> 0x20) +
                                         (short)((ulonglong)DAT_1008dbe0 >> 0x20),
                                         CONCAT22((short)(uVar14 >> 0x10) +
                                                  (short)((ulonglong)DAT_1008dbe0 >> 0x10),
                                                  (short)uVar14 + (short)DAT_1008dbe0)));
        iVar7 = iVar6 + 8;
        bVar3 = iVar6 < -8;
        iVar6 = iVar7;
        uVar14 = uVar4;
      } while (iVar7 == 0 || bVar3);
    }
    DAT_1008d29c = DAT_1008d2a0 + DAT_1008d29c;
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


