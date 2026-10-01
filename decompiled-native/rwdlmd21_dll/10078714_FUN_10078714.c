// 10078714 FUN_10078714 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10078714(void)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  bool bVar4;
  ulonglong uVar5;
  uint uVar6;
  uint extraout_EDX;
  int iVar7;
  int iVar8;
  uint uVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ushort uVar16;
  ushort uVar17;
  ushort uVar18;
  ulonglong uVar19;
  short sVar20;
  short sVar21;
  undefined4 uVar22;
  short sVar26;
  short sVar27;
  short sVar28;
  ulonglong uVar23;
  short sVar25;
  short sVar29;
  ulonglong uVar24;
  short sVar30;
  ulonglong uVar31;
  
  uVar22 = CONCAT22((ushort)DAT_1008d2a8 << 3,(ushort)DAT_1008d2a8 << 3);
  uVar23 = CONCAT44(uVar22,uVar22);
  do {
    iVar7 = DAT_1008d294;
    DAT_1008d2e4 = DAT_1008d2e4 + DAT_1008d2e8;
    DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0 & 0x7fff7fff;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar6 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    if (uVar6 < DAT_1008d284 >> 0x10) {
      FUN_10078140(uVar6 - (DAT_1008d284 >> 0x10));
      uVar9 = iVar7 - 2U & 0xfffffff8;
      iVar7 = (uVar6 & 0xfffffff8) - uVar9;
      uVar14 = DAT_1008e038;
      do {
        uVar5 = DAT_1008e038;
        uVar1 = *(ulonglong *)(iVar7 + (extraout_EDX & 0xfffffff8));
        uVar10 = (ushort)(uVar1 >> 0x10);
        uVar11 = (ushort)(uVar1 >> 0x20);
        uVar12 = (ushort)(uVar1 >> 0x30);
        uVar15 = uVar1 & uVar14;
        sVar20 = (short)uVar23;
        sVar25 = (short)(uVar23 >> 0x10);
        sVar27 = (short)(uVar23 >> 0x20);
        sVar29 = (short)(uVar23 >> 0x30);
        uVar13 = CONCAT26(uVar12 >> 6,CONCAT24(uVar11 >> 6,CONCAT22(uVar10 >> 6,(ushort)uVar1 >> 6))
                         ) & uVar14;
        uVar2 = *(ulonglong *)(iVar7 + uVar9);
        uVar24 = uVar23 ^ _DAT_1008e018;
        uVar16 = (ushort)(uVar2 >> 0x10);
        uVar17 = (ushort)(uVar2 >> 0x20);
        uVar18 = (ushort)(uVar2 >> 0x30);
        uVar19 = uVar2 & uVar14;
        sVar21 = (short)uVar24;
        sVar26 = (short)(uVar24 >> 0x10);
        sVar28 = (short)(uVar24 >> 0x20);
        sVar30 = (short)(uVar24 >> 0x30);
        uVar24 = CONCAT26(uVar18 >> 6,CONCAT24(uVar17 >> 6,CONCAT22(uVar16 >> 6,(ushort)uVar2 >> 6))
                         ) & uVar14;
        uVar31 = psllw(uVar14,0xb);
        uVar14 = CONCAT26((short)(uVar13 >> 0x30) * sVar29 + (short)(uVar24 >> 0x30) * sVar30,
                          CONCAT24((short)(uVar13 >> 0x20) * sVar27 +
                                   (short)(uVar24 >> 0x20) * sVar28,
                                   CONCAT22((short)(uVar13 >> 0x10) * sVar25 +
                                            (short)(uVar24 >> 0x10) * sVar26,
                                            (short)uVar13 * sVar20 + (short)uVar24 * sVar21))) &
                 uVar31;
        uVar3 = *(undefined8 *)(iVar7 + (extraout_EDX & 0xfffffff8));
        uVar13 = CONCAT26(-(ushort)((short)((ulonglong)uVar3 >> 0x30) ==
                                   (short)((ulonglong)DAT_1008e008 >> 0x30)),
                          CONCAT24(-(ushort)((short)((ulonglong)uVar3 >> 0x20) ==
                                            (short)((ulonglong)DAT_1008e008 >> 0x20)),
                                   CONCAT22(-(ushort)((short)((ulonglong)uVar3 >> 0x10) ==
                                                     (short)((ulonglong)DAT_1008e008 >> 0x10)),
                                            -(ushort)((short)uVar3 == (short)DAT_1008e008))));
        *(ulonglong *)(iVar7 + uVar9) =
             *(ulonglong *)(iVar7 + uVar9) & uVar13 |
             ~uVar13 & (CONCAT26((uVar12 >> 0xb) * sVar29 + (uVar18 >> 0xb) * sVar30,
                                 CONCAT24((uVar11 >> 0xb) * sVar27 + (uVar17 >> 0xb) * sVar28,
                                          CONCAT22((uVar10 >> 0xb) * sVar25 +
                                                   (uVar16 >> 0xb) * sVar26,
                                                   ((ushort)uVar1 >> 0xb) * sVar20 +
                                                   ((ushort)uVar2 >> 0xb) * sVar21))) & uVar31 |
                        CONCAT26((ushort)((short)(uVar15 >> 0x30) * sVar29 +
                                         (short)(uVar19 >> 0x30) * sVar30) >> 0xb,
                                 CONCAT24((ushort)((short)(uVar15 >> 0x20) * sVar27 +
                                                  (short)(uVar19 >> 0x20) * sVar28) >> 0xb,
                                          CONCAT22((ushort)((short)(uVar15 >> 0x10) * sVar25 +
                                                           (short)(uVar19 >> 0x10) * sVar26) >> 0xb,
                                                   (ushort)((short)uVar15 * sVar20 +
                                                           (short)uVar19 * sVar21) >> 0xb))) |
                       CONCAT26((ushort)(uVar14 >> 0x35),
                                CONCAT24((ushort)(uVar14 >> 0x20) >> 5,
                                         CONCAT22((ushort)(uVar14 >> 0x10) >> 5,(ushort)uVar14 >> 5)
                                        )));
        iVar8 = iVar7 + 8;
        bVar4 = iVar7 < -8;
        iVar7 = iVar8;
        uVar14 = uVar5;
      } while (iVar8 == 0 || bVar4);
    }
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d29c = DAT_1008d2a0 + DAT_1008d29c;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


