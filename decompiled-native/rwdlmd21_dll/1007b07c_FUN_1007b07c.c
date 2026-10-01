// 1007b07c FUN_1007b07c [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1007b07c(void)

{
  uint uVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  ulonglong *puVar10;
  short sVar11;
  short sVar12;
  short sVar14;
  short sVar15;
  short sVar16;
  undefined4 uVar17;
  undefined8 uVar13;
  short sVar18;
  short sVar19;
  short sVar20;
  short sVar21;
  short sVar22;
  short sVar24;
  short sVar25;
  undefined8 uVar23;
  short sVar26;
  short sVar27;
  ushort uVar28;
  ushort uVar29;
  ushort uVar30;
  ulonglong uVar31;
  ulonglong uVar32;
  ulonglong uVar33;
  undefined8 uVar34;
  
  uVar17 = CONCAT22((ushort)DAT_1008d2a8 << 3,(ushort)DAT_1008d2a8 << 3);
  uVar33 = CONCAT44(uVar17,uVar17);
  DAT_1008e1c8 = uVar33 ^ _DAT_1008e018;
  _DAT_1008e1c0 = psllw(uVar33,4);
  iVar4 = DAT_1008d2c8 + (DAT_1008d2c8 & 0x8000) * 2;
  sVar14 = (short)((uint)iVar4 >> 0x10);
  sVar11 = (short)iVar4;
  uVar17 = (undefined4)(CONCAT26(sVar14,CONCAT24(sVar14,iVar4)) >> 0x20);
  sVar16 = (short)DAT_1008d2d4;
  uVar13 = CONCAT44(uVar17,uVar17);
  uVar34 = psraw(uVar13,0xf);
  uVar13 = pmulhw(uVar13,_DAT_1008e1c0);
  DAT_1008e218 = psllw(CONCAT26((short)((ulonglong)uVar13 >> 0x30) -
                                (short)((ulonglong)uVar34 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar13 >> 0x20) -
                                         (short)((ulonglong)uVar34 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar13 >> 0x10) -
                                                  (short)((ulonglong)uVar34 >> 0x10),
                                                  (short)uVar13 - (short)uVar34))),6);
  uVar13 = CONCAT44(CONCAT22(sVar16,sVar16),CONCAT22(sVar16,sVar16));
  uVar34 = psraw(uVar13,0xf);
  uVar13 = pmulhw(uVar13,_DAT_1008e1c0);
  DAT_1008e228 = psllw(CONCAT26((short)((ulonglong)uVar13 >> 0x30) -
                                (short)((ulonglong)uVar34 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar13 >> 0x20) -
                                         (short)((ulonglong)uVar34 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar13 >> 0x10) -
                                                  (short)((ulonglong)uVar34 >> 0x10),
                                                  (short)uVar13 - (short)uVar34))),6);
  sVar8 = (short)DAT_1008e188;
  sVar12 = (short)((ulonglong)DAT_1008e188 >> 0x10);
  sVar15 = (short)((ulonglong)DAT_1008e188 >> 0x20);
  sVar3 = (short)((ulonglong)DAT_1008e188 >> 0x30);
  DAT_1008e200 = CONCAT26(sVar14 * sVar3,
                          CONCAT24(sVar14 * sVar15,CONCAT22(sVar14 * sVar12,sVar14 * sVar8)));
  uVar13 = CONCAT44(CONCAT22(sVar11,sVar11),CONCAT22(sVar11,sVar11));
  uVar34 = psraw(uVar13,0xf);
  uVar13 = pmulhw(uVar13,_DAT_1008e1c0);
  DAT_1008e210 = CONCAT26(sVar16 * sVar3,
                          CONCAT24(sVar16 * sVar15,CONCAT22(sVar16 * sVar12,sVar16 * sVar8)));
  DAT_1008e208 = CONCAT26(sVar11 * sVar3,
                          CONCAT24(sVar11 * sVar15,CONCAT22(sVar11 * sVar12,sVar11 * sVar8)));
  DAT_1008e220 = psllw(CONCAT26((short)((ulonglong)uVar13 >> 0x30) -
                                (short)((ulonglong)uVar34 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar13 >> 0x20) -
                                         (short)((ulonglong)uVar34 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar13 >> 0x10) -
                                                  (short)((ulonglong)uVar34 >> 0x10),
                                                  (short)uVar13 - (short)uVar34))),6);
  do {
    DAT_1008d2c0 = DAT_1008d2c0 + DAT_1008d2c4;
    DAT_1008d2cc = DAT_1008d2cc + DAT_1008d2d0;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    if (DAT_1008d280 >> 0x10 < DAT_1008d284 >> 0x10) {
      uVar1 = DAT_1008d294 + (DAT_1008d280 >> 0x10) * 2;
      iVar4 = DAT_1008d294 + (DAT_1008d284 >> 0x10) * 2;
      sVar8 = (short)DAT_1008d2cc;
      iVar5 = DAT_1008d2c0;
      iVar9 = DAT_1008d2cc;
      for (uVar6 = uVar1 & 6; uVar6 != 0; uVar6 = uVar6 - 2) {
        iVar5 = iVar5 - DAT_1008d2c8;
        iVar9 = iVar9 - DAT_1008d2d4;
        sVar8 = (short)iVar9;
      }
      sVar15 = (short)((uint)iVar5 >> 0x10);
      sVar12 = (short)iVar5;
      uVar13 = pmulhw(CONCAT26(sVar15 + (short)((ulonglong)DAT_1008e200 >> 0x30),
                               CONCAT24(sVar15 + (short)((ulonglong)DAT_1008e200 >> 0x20),
                                        CONCAT22(sVar15 + (short)((ulonglong)DAT_1008e200 >> 0x10),
                                                 sVar15 + (short)DAT_1008e200))),_DAT_1008e1c0);
      uVar34 = pmulhw(CONCAT26(sVar12 + (short)((ulonglong)DAT_1008e208 >> 0x30),
                               CONCAT24(sVar12 + (short)((ulonglong)DAT_1008e208 >> 0x20),
                                        CONCAT22(sVar12 + (short)((ulonglong)DAT_1008e208 >> 0x10),
                                                 sVar12 + (short)DAT_1008e208))),_DAT_1008e1c0);
      uVar23 = pmulhw(CONCAT26(sVar8 + (short)((ulonglong)DAT_1008e210 >> 0x30),
                               CONCAT24(sVar8 + (short)((ulonglong)DAT_1008e210 >> 0x20),
                                        CONCAT22(sVar8 + (short)((ulonglong)DAT_1008e210 >> 0x10),
                                                 sVar8 + (short)DAT_1008e210))),_DAT_1008e1c0);
      uVar13 = psllw(uVar13,4);
      uVar34 = psllw(uVar34,4);
      uVar23 = psllw(uVar23,4);
      puVar10 = (ulonglong *)(iVar4 - 2U & 0xfffffff8);
      iVar5 = (uVar1 & 0xfffffff8) - (int)puVar10;
      sVar14 = (short)((ulonglong)uVar13 >> 0x10);
      sVar16 = (short)((ulonglong)uVar13 >> 0x20);
      sVar18 = (short)((ulonglong)uVar13 >> 0x30);
      sVar25 = (short)((ulonglong)uVar23 >> 0x10);
      sVar27 = (short)((ulonglong)uVar23 >> 0x20);
      sVar26 = (short)((ulonglong)uVar23 >> 0x30);
      sVar20 = (short)((ulonglong)uVar34 >> 0x10);
      sVar21 = (short)((ulonglong)uVar34 >> 0x20);
      sVar22 = (short)((ulonglong)uVar34 >> 0x30);
      sVar11 = (short)uVar13;
      sVar24 = (short)uVar23;
      sVar19 = (short)uVar34;
      sVar8 = (short)DAT_1008e1c8;
      sVar12 = (short)(DAT_1008e1c8 >> 0x10);
      sVar15 = (short)(DAT_1008e1c8 >> 0x20);
      sVar3 = (short)(DAT_1008e1c8 >> 0x30);
      if (iVar5 == 0) {
        uVar33 = *puVar10;
        uVar28 = (ushort)(uVar33 >> 0x10);
        uVar29 = (ushort)(uVar33 >> 0x20);
        uVar30 = (ushort)(uVar33 >> 0x30);
        uVar32 = uVar33 & DAT_1008e268;
        uVar31 = CONCAT26(uVar30 >> 6,
                          CONCAT24(uVar29 >> 6,CONCAT22(uVar28 >> 6,(ushort)uVar33 >> 6))) &
                 DAT_1008e268;
        uVar31 = CONCAT26((short)(uVar31 >> 0x30) * sVar3 + sVar22,
                          CONCAT24((short)(uVar31 >> 0x20) * sVar15 + sVar21,
                                   CONCAT22((short)(uVar31 >> 0x10) * sVar12 + sVar20,
                                            (short)uVar31 * sVar8 + sVar19))) & DAT_1008e250;
        *puVar10 = (CONCAT26((uVar30 >> 0xb) * sVar3 + sVar18,
                             CONCAT24((uVar29 >> 0xb) * sVar15 + sVar16,
                                      CONCAT22((uVar28 >> 0xb) * sVar12 + sVar14,
                                               ((ushort)uVar33 >> 0xb) * sVar8 + sVar11))) &
                    DAT_1008e250 |
                    CONCAT26((ushort)(uVar31 >> 0x35),
                             CONCAT24((ushort)(uVar31 >> 0x20) >> 5,
                                      CONCAT22((ushort)(uVar31 >> 0x10) >> 5,(ushort)uVar31 >> 5)))
                   | CONCAT26((ushort)((short)(uVar32 >> 0x30) * sVar3 + sVar26) >> 0xb,
                              CONCAT24((ushort)((short)(uVar32 >> 0x20) * sVar15 + sVar27) >> 0xb,
                                       CONCAT22((ushort)((short)(uVar32 >> 0x10) * sVar12 + sVar25)
                                                >> 0xb,(ushort)((short)uVar32 * sVar8 + sVar24) >>
                                                       0xb)))) &
                   *(ulonglong *)(&DAT_1008e100 + ((uVar1 & 6) << 2 | (iVar4 - uVar1) - 2) * 4) |
                   ~*(ulonglong *)(&DAT_1008e100 + ((uVar1 & 6) << 2 | (iVar4 - uVar1) - 2) * 4) &
                   *puVar10;
      }
      else {
        uVar33 = *(ulonglong *)(iVar5 + (int)puVar10);
        uVar28 = (ushort)(uVar33 >> 0x10);
        uVar29 = (ushort)(uVar33 >> 0x20);
        uVar30 = (ushort)(uVar33 >> 0x30);
        uVar32 = uVar33 & DAT_1008e268;
        uVar31 = CONCAT26(uVar30 >> 6,
                          CONCAT24(uVar29 >> 6,CONCAT22(uVar28 >> 6,(ushort)uVar33 >> 6))) &
                 DAT_1008e268;
        uVar31 = CONCAT26((short)(uVar31 >> 0x30) * sVar3 + sVar22,
                          CONCAT24((short)(uVar31 >> 0x20) * sVar15 + sVar21,
                                   CONCAT22((short)(uVar31 >> 0x10) * sVar12 + sVar20,
                                            (short)uVar31 * sVar8 + sVar19))) & DAT_1008e250;
        uVar13 = CONCAT26(sVar18 + (short)((ulonglong)DAT_1008e218 >> 0x30),
                          CONCAT24(sVar16 + (short)((ulonglong)DAT_1008e218 >> 0x20),
                                   CONCAT22(sVar14 + (short)((ulonglong)DAT_1008e218 >> 0x10),
                                            sVar11 + (short)DAT_1008e218)));
        uVar34 = CONCAT26(sVar22 + (short)((ulonglong)DAT_1008e220 >> 0x30),
                          CONCAT24(sVar21 + (short)((ulonglong)DAT_1008e220 >> 0x20),
                                   CONCAT22(sVar20 + (short)((ulonglong)DAT_1008e220 >> 0x10),
                                            sVar19 + (short)DAT_1008e220)));
        uVar23 = CONCAT26(sVar26 + (short)((ulonglong)DAT_1008e228 >> 0x30),
                          CONCAT24(sVar27 + (short)((ulonglong)DAT_1008e228 >> 0x20),
                                   CONCAT22(sVar25 + (short)((ulonglong)DAT_1008e228 >> 0x10),
                                            sVar24 + (short)DAT_1008e228)));
        *(ulonglong *)(iVar5 + (int)puVar10) =
             (CONCAT26((uVar30 >> 0xb) * sVar3 + sVar18,
                       CONCAT24((uVar29 >> 0xb) * sVar15 + sVar16,
                                CONCAT22((uVar28 >> 0xb) * sVar12 + sVar14,
                                         ((ushort)uVar33 >> 0xb) * sVar8 + sVar11))) & DAT_1008e250
              | CONCAT26((ushort)(uVar31 >> 0x35),
                         CONCAT24((ushort)(uVar31 >> 0x20) >> 5,
                                  CONCAT22((ushort)(uVar31 >> 0x10) >> 5,(ushort)uVar31 >> 5))) |
             CONCAT26((ushort)((short)(uVar32 >> 0x30) * sVar3 + sVar26) >> 0xb,
                      CONCAT24((ushort)((short)(uVar32 >> 0x20) * sVar15 + sVar27) >> 0xb,
                               CONCAT22((ushort)((short)(uVar32 >> 0x10) * sVar12 + sVar25) >> 0xb,
                                        (ushort)((short)uVar32 * sVar8 + sVar24) >> 0xb)))) &
             *(ulonglong *)(&DAT_1008e0e0 + (uVar1 & 6) * 4) |
             ~*(ulonglong *)(&DAT_1008e0e0 + (uVar1 & 6) * 4) & *(ulonglong *)(iVar5 + (int)puVar10)
        ;
        iVar9 = 0;
        iVar7 = iVar5 + 8;
        if (iVar5 + 8 != 0) {
          do {
            uVar33 = *(ulonglong *)(iVar7 + (int)puVar10);
            uVar28 = (ushort)(uVar33 >> 0x10);
            uVar29 = (ushort)(uVar33 >> 0x20);
            uVar30 = (ushort)(uVar33 >> 0x30);
            sVar8 = (short)DAT_1008e1c8;
            sVar12 = (short)(DAT_1008e1c8 >> 0x10);
            sVar15 = (short)(DAT_1008e1c8 >> 0x20);
            sVar3 = (short)(DAT_1008e1c8 >> 0x30);
            uVar32 = uVar33 & DAT_1008e268;
            uVar31 = CONCAT26(uVar30 >> 6,
                              CONCAT24(uVar29 >> 6,CONCAT22(uVar28 >> 6,(ushort)uVar33 >> 6))) &
                     DAT_1008e268;
            sVar11 = (short)uVar13;
            sVar14 = (short)((ulonglong)uVar13 >> 0x10);
            sVar16 = (short)((ulonglong)uVar13 >> 0x20);
            sVar18 = (short)((ulonglong)uVar13 >> 0x30);
            sVar22 = (short)uVar23;
            sVar24 = (short)((ulonglong)uVar23 >> 0x10);
            sVar25 = (short)((ulonglong)uVar23 >> 0x20);
            sVar27 = (short)((ulonglong)uVar23 >> 0x30);
            sVar19 = (short)((ulonglong)uVar34 >> 0x10);
            sVar20 = (short)((ulonglong)uVar34 >> 0x20);
            sVar21 = (short)((ulonglong)uVar34 >> 0x30);
            uVar31 = CONCAT26((short)(uVar31 >> 0x30) * sVar3 + sVar21,
                              CONCAT24((short)(uVar31 >> 0x20) * sVar15 + sVar20,
                                       CONCAT22((short)(uVar31 >> 0x10) * sVar12 + sVar19,
                                                (short)uVar31 * sVar8 + (short)uVar34))) &
                     DAT_1008e250;
            uVar13 = CONCAT26(sVar18 + (short)((ulonglong)DAT_1008e218 >> 0x30),
                              CONCAT24(sVar16 + (short)((ulonglong)DAT_1008e218 >> 0x20),
                                       CONCAT22(sVar14 + (short)((ulonglong)DAT_1008e218 >> 0x10),
                                                sVar11 + (short)DAT_1008e218)));
            uVar34 = CONCAT26(sVar21 + (short)((ulonglong)DAT_1008e220 >> 0x30),
                              CONCAT24(sVar20 + (short)((ulonglong)DAT_1008e220 >> 0x20),
                                       CONCAT22(sVar19 + (short)((ulonglong)DAT_1008e220 >> 0x10),
                                                (short)uVar34 + (short)DAT_1008e220)));
            uVar23 = CONCAT26(sVar27 + (short)((ulonglong)DAT_1008e228 >> 0x30),
                              CONCAT24(sVar25 + (short)((ulonglong)DAT_1008e228 >> 0x20),
                                       CONCAT22(sVar24 + (short)((ulonglong)DAT_1008e228 >> 0x10),
                                                sVar22 + (short)DAT_1008e228)));
            *(ulonglong *)(iVar7 + (int)puVar10) =
                 CONCAT26((uVar30 >> 0xb) * sVar3 + sVar18,
                          CONCAT24((uVar29 >> 0xb) * sVar15 + sVar16,
                                   CONCAT22((uVar28 >> 0xb) * sVar12 + sVar14,
                                            ((ushort)uVar33 >> 0xb) * sVar8 + sVar11))) &
                 DAT_1008e250 |
                 CONCAT26((ushort)(uVar31 >> 0x35),
                          CONCAT24((ushort)(uVar31 >> 0x20) >> 5,
                                   CONCAT22((ushort)(uVar31 >> 0x10) >> 5,(ushort)uVar31 >> 5))) |
                 CONCAT26((ushort)((short)(uVar32 >> 0x30) * sVar3 + sVar27) >> 0xb,
                          CONCAT24((ushort)((short)(uVar32 >> 0x20) * sVar15 + sVar25) >> 0xb,
                                   CONCAT22((ushort)((short)(uVar32 >> 0x10) * sVar12 + sVar24) >>
                                            0xb,(ushort)((short)uVar32 * sVar8 + sVar22) >> 0xb)));
            iVar9 = iVar7 + 8;
            bVar2 = iVar7 < -8;
            iVar7 = iVar9;
          } while (bVar2);
        }
        uVar33 = *(ulonglong *)(iVar9 + (int)puVar10);
        uVar28 = (ushort)(uVar33 >> 0x10);
        uVar29 = (ushort)(uVar33 >> 0x20);
        uVar30 = (ushort)(uVar33 >> 0x30);
        sVar8 = (short)DAT_1008e1c8;
        sVar12 = (short)(DAT_1008e1c8 >> 0x10);
        sVar15 = (short)(DAT_1008e1c8 >> 0x20);
        sVar3 = (short)(DAT_1008e1c8 >> 0x30);
        uVar32 = uVar33 & DAT_1008e268;
        uVar31 = CONCAT26(uVar30 >> 6,
                          CONCAT24(uVar29 >> 6,CONCAT22(uVar28 >> 6,(ushort)uVar33 >> 6))) &
                 DAT_1008e268;
        uVar31 = CONCAT26((short)(uVar31 >> 0x30) * sVar3 + (short)((ulonglong)uVar34 >> 0x30),
                          CONCAT24((short)(uVar31 >> 0x20) * sVar15 +
                                   (short)((ulonglong)uVar34 >> 0x20),
                                   CONCAT22((short)(uVar31 >> 0x10) * sVar12 +
                                            (short)((ulonglong)uVar34 >> 0x10),
                                            (short)uVar31 * sVar8 + (short)uVar34))) & DAT_1008e250;
        *(ulonglong *)(iVar9 + (int)puVar10) =
             (CONCAT26((uVar30 >> 0xb) * sVar3 + (short)((ulonglong)uVar13 >> 0x30),
                       CONCAT24((uVar29 >> 0xb) * sVar15 + (short)((ulonglong)uVar13 >> 0x20),
                                CONCAT22((uVar28 >> 0xb) * sVar12 +
                                         (short)((ulonglong)uVar13 >> 0x10),
                                         ((ushort)uVar33 >> 0xb) * sVar8 + (short)uVar13))) &
              DAT_1008e250 |
              CONCAT26((ushort)(uVar31 >> 0x35),
                       CONCAT24((ushort)(uVar31 >> 0x20) >> 5,
                                CONCAT22((ushort)(uVar31 >> 0x10) >> 5,(ushort)uVar31 >> 5))) |
             CONCAT26((ushort)((short)(uVar32 >> 0x30) * sVar3 + (short)((ulonglong)uVar23 >> 0x30))
                      >> 0xb,CONCAT24((ushort)((short)(uVar32 >> 0x20) * sVar15 +
                                              (short)((ulonglong)uVar23 >> 0x20)) >> 0xb,
                                      CONCAT22((ushort)((short)(uVar32 >> 0x10) * sVar12 +
                                                       (short)((ulonglong)uVar23 >> 0x10)) >> 0xb,
                                               (ushort)((short)uVar32 * sVar8 + (short)uVar23) >>
                                               0xb)))) &
             *(ulonglong *)(&DAT_1008e100 + (iVar4 - 2U & 6) * 4) |
             ~*(ulonglong *)(&DAT_1008e100 + (iVar4 - 2U & 6) * 4) &
             *(ulonglong *)(iVar9 + (int)puVar10);
      }
    }
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


