// 10078fc4 FUN_10078fc4 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10078fc4(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint extraout_EDX;
  uint extraout_EDX_00;
  int iVar5;
  uint uVar6;
  ushort uVar7;
  ushort uVar9;
  ushort uVar10;
  undefined4 uVar11;
  ulonglong uVar8;
  ushort uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined4 uVar15;
  short sVar16;
  short sVar18;
  short sVar19;
  short sVar20;
  undefined8 uVar17;
  short sVar21;
  short sVar23;
  short sVar24;
  short sVar25;
  undefined8 uVar22;
  short sVar26;
  short sVar28;
  short sVar29;
  short sVar30;
  short sVar31;
  undefined8 uVar27;
  short sVar32;
  short sVar33;
  short sVar34;
  ulonglong uVar35;
  ulonglong uVar36;
  ulonglong uVar37;
  
  sVar31 = (short)DAT_1008e188;
  sVar25 = (short)((ulonglong)DAT_1008e188 >> 0x10);
  sVar20 = (short)((ulonglong)DAT_1008e188 >> 0x20);
  sVar16 = (short)((ulonglong)DAT_1008e188 >> 0x30);
  if ((int)DAT_1008dbe0 != 0) {
    iVar2 = DAT_1008d2d4 + (DAT_1008d2d4 & 0x8000) * 2;
    iVar5 = DAT_1008d2e0 + (DAT_1008d2e0 & 0x8000) * 2;
    sVar19 = (short)((uint)iVar2 >> 0x10);
    sVar18 = (short)iVar2;
    uVar11 = (undefined4)(CONCAT26(sVar19,CONCAT24(sVar19,iVar2)) >> 0x20);
    sVar23 = (short)((uint)iVar5 >> 0x10);
    sVar21 = (short)iVar5;
    uVar15 = (undefined4)(CONCAT26(sVar23,CONCAT24(sVar23,iVar5)) >> 0x20);
    DAT_1008e218 = CONCAT44(uVar11,uVar11);
    DAT_1008e228 = CONCAT44(CONCAT22(sVar21,sVar21),CONCAT22(sVar21,sVar21));
    DAT_1008e240 = CONCAT44(uVar15,uVar15);
    DAT_1008e200 = CONCAT26(sVar19 * sVar16,
                            CONCAT24(sVar19 * sVar20,CONCAT22(sVar19 * sVar25,sVar19 * sVar31)));
    DAT_1008e220 = CONCAT44(CONCAT22(sVar18,sVar18),CONCAT22(sVar18,sVar18));
    DAT_1008e210 = CONCAT26(sVar21 * sVar16,
                            CONCAT24(sVar21 * sVar20,CONCAT22(sVar21 * sVar25,sVar21 * sVar31)));
    DAT_1008e208 = CONCAT26(sVar18 * sVar16,
                            CONCAT24(sVar18 * sVar20,CONCAT22(sVar18 * sVar25,sVar18 * sVar31)));
    DAT_1008e238 = CONCAT26(sVar23 * sVar16,
                            CONCAT24(sVar23 * sVar20,CONCAT22(sVar23 * sVar25,sVar23 * sVar31)));
    do {
      iVar2 = DAT_1008d294;
      DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0 & 0x7fff7fff;
      DAT_1008d2cc = DAT_1008d2cc + DAT_1008d2d0;
      DAT_1008d2d8 = DAT_1008d2d8 + DAT_1008d2dc;
      DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
      uVar3 = DAT_1008d280 >> 0x10;
      DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
      if (uVar3 < DAT_1008d284 >> 0x10) {
        FUN_100780dd(uVar3 - (DAT_1008d284 >> 0x10));
        uVar6 = uVar3 & 6;
        uVar4 = DAT_1008d2cc;
        iVar5 = DAT_1008d2d8;
        while( true ) {
          sVar31 = (short)uVar4;
          sVar25 = (short)(uVar4 >> 0x10);
          if (uVar6 == 0) break;
          uVar4 = (uint)(ushort)(sVar31 - (short)DAT_1008d2d4) |
                  CONCAT22(sVar31 - (short)DAT_1008d2d4,sVar25 - DAT_1008d2d4._2_2_) << 0x10;
          iVar5 = iVar5 - DAT_1008d2e0;
          uVar6 = uVar6 - 2;
        }
        sVar28 = (short)((uint)iVar5 >> 0x10);
        sVar24 = (short)iVar5;
        sVar20 = sVar25 + (short)DAT_1008e200;
        sVar16 = sVar25 + (short)((ulonglong)DAT_1008e200 >> 0x10);
        sVar18 = sVar25 + (short)((ulonglong)DAT_1008e200 >> 0x20);
        sVar25 = sVar25 + (short)((ulonglong)DAT_1008e200 >> 0x30);
        sVar19 = sVar31 + (short)DAT_1008e208;
        sVar21 = sVar31 + (short)((ulonglong)DAT_1008e208 >> 0x10);
        sVar23 = sVar31 + (short)((ulonglong)DAT_1008e208 >> 0x20);
        sVar31 = sVar31 + (short)((ulonglong)DAT_1008e208 >> 0x30);
        sVar26 = sVar24 + (short)DAT_1008e210;
        sVar29 = sVar24 + (short)((ulonglong)DAT_1008e210 >> 0x10);
        sVar30 = sVar24 + (short)((ulonglong)DAT_1008e210 >> 0x20);
        sVar24 = sVar24 + (short)((ulonglong)DAT_1008e210 >> 0x30);
        sVar32 = sVar28 + (short)DAT_1008e238;
        sVar33 = sVar28 + (short)((ulonglong)DAT_1008e238 >> 0x10);
        sVar34 = sVar28 + (short)((ulonglong)DAT_1008e238 >> 0x20);
        sVar28 = sVar28 + (short)((ulonglong)DAT_1008e238 >> 0x30);
        uVar8 = psraw(CONCAT26(sVar25,CONCAT24(sVar18,CONCAT22(sVar16,sVar20))),0xf);
        uVar8 = uVar8 & _DAT_1008e030;
        uVar13 = psraw(CONCAT26(sVar31,CONCAT24(sVar23,CONCAT22(sVar21,sVar19))),0xf);
        uVar13 = uVar13 & _DAT_1008e030;
        uVar14 = psraw(CONCAT26(sVar24,CONCAT24(sVar30,CONCAT22(sVar29,sVar26))),0xf);
        uVar14 = uVar14 & _DAT_1008e030;
        uVar36 = psraw(CONCAT26(sVar28,CONCAT24(sVar34,CONCAT22(sVar33,sVar32))),0xf);
        uVar17 = psraw(CONCAT26(sVar25 + (short)(uVar8 >> 0x30),
                                CONCAT24(sVar18 + (short)(uVar8 >> 0x20),
                                         CONCAT22(sVar16 + (short)(uVar8 >> 0x10),
                                                  sVar20 + (short)uVar8))),2);
        uVar36 = uVar36 & _DAT_1008e030;
        uVar22 = psraw(CONCAT26(sVar31 + (short)(uVar13 >> 0x30),
                                CONCAT24(sVar23 + (short)(uVar13 >> 0x20),
                                         CONCAT22(sVar21 + (short)(uVar13 >> 0x10),
                                                  sVar19 + (short)uVar13))),2);
        DAT_1008e230 = psraw(CONCAT26(sVar28 + (short)(uVar36 >> 0x30),
                                      CONCAT24(sVar34 + (short)(uVar36 >> 0x20),
                                               CONCAT22(sVar33 + (short)(uVar36 >> 0x10),
                                                        sVar32 + (short)uVar36))),2);
        uVar27 = psraw(CONCAT26(sVar24 + (short)(uVar14 >> 0x30),
                                CONCAT24(sVar30 + (short)(uVar14 >> 0x20),
                                         CONCAT22(sVar29 + (short)(uVar14 >> 0x10),
                                                  sVar26 + (short)uVar14))),2);
        uVar6 = iVar2 - 2U & 0xfffffff8;
        iVar2 = (uVar3 & 0xfffffff8) - uVar6;
        uVar8 = DAT_1008e038;
        do {
          uVar14 = DAT_1008e038;
          uVar13 = *(ulonglong *)(iVar2 + (extraout_EDX_00 & 0xfffffff8));
          uVar7 = (ushort)uVar13;
          uVar9 = (ushort)(uVar13 >> 0x10);
          uVar10 = (ushort)(uVar13 >> 0x20);
          uVar12 = (ushort)(uVar13 >> 0x30);
          uVar13 = uVar13 & uVar8;
          sVar31 = (short)uVar17;
          sVar25 = (short)((ulonglong)uVar17 >> 0x10);
          sVar20 = (short)((ulonglong)uVar17 >> 0x20);
          sVar16 = (short)((ulonglong)uVar17 >> 0x30);
          uVar35 = CONCAT26(-(ushort)(uVar12 == (ushort)((ulonglong)DAT_1008e008 >> 0x30)),
                            CONCAT24(-(ushort)(uVar10 == (ushort)((ulonglong)DAT_1008e008 >> 0x20)),
                                     CONCAT22(-(ushort)(uVar9 == (ushort)((ulonglong)DAT_1008e008 >>
                                                                         0x10)),
                                              -(ushort)(uVar7 == (ushort)DAT_1008e008))));
          sVar24 = (short)uVar27;
          sVar26 = (short)((ulonglong)uVar27 >> 0x10);
          sVar28 = (short)((ulonglong)uVar27 >> 0x20);
          sVar29 = (short)((ulonglong)uVar27 >> 0x30);
          uVar36 = CONCAT26(uVar12 >> 6,CONCAT24(uVar10 >> 6,CONCAT22(uVar9 >> 6,uVar7 >> 6))) &
                   uVar8;
          uVar17 = CONCAT26(sVar16 + (short)((ulonglong)DAT_1008e218 >> 0x30),
                            CONCAT24(sVar20 + (short)((ulonglong)DAT_1008e218 >> 0x20),
                                     CONCAT22(sVar25 + (short)((ulonglong)DAT_1008e218 >> 0x10),
                                              sVar31 + (short)DAT_1008e218)));
          sVar18 = (short)uVar22;
          sVar19 = (short)((ulonglong)uVar22 >> 0x10);
          sVar21 = (short)((ulonglong)uVar22 >> 0x20);
          sVar23 = (short)((ulonglong)uVar22 >> 0x30);
          uVar22 = CONCAT26(sVar23 + (short)((ulonglong)DAT_1008e220 >> 0x30),
                            CONCAT24(sVar21 + (short)((ulonglong)DAT_1008e220 >> 0x20),
                                     CONCAT22(sVar19 + (short)((ulonglong)DAT_1008e220 >> 0x10),
                                              sVar18 + (short)DAT_1008e220)));
          uVar37 = psllw(uVar8,0xb);
          uVar27 = CONCAT26(sVar29 + (short)((ulonglong)DAT_1008e228 >> 0x30),
                            CONCAT24(sVar28 + (short)((ulonglong)DAT_1008e228 >> 0x20),
                                     CONCAT22(sVar26 + (short)((ulonglong)DAT_1008e228 >> 0x10),
                                              sVar24 + (short)DAT_1008e228)));
          uVar8 = CONCAT26((short)(uVar36 >> 0x30) * sVar23,
                           CONCAT24((short)(uVar36 >> 0x20) * sVar21,
                                    CONCAT22((short)(uVar36 >> 0x10) * sVar19,(short)uVar36 * sVar18
                                            ))) & uVar37;
          uVar8 = CONCAT26((uVar12 >> 0xb) * sVar16,
                           CONCAT24((uVar10 >> 0xb) * sVar20,
                                    CONCAT22((uVar9 >> 0xb) * sVar25,(uVar7 >> 0xb) * sVar31))) &
                  uVar37 | CONCAT26((ushort)((short)(uVar13 >> 0x30) * sVar29) >> 0xb,
                                    CONCAT24((ushort)((short)(uVar13 >> 0x20) * sVar28) >> 0xb,
                                             CONCAT22((ushort)((short)(uVar13 >> 0x10) * sVar26) >>
                                                      0xb,(ushort)((short)uVar13 * sVar24) >> 0xb)))
                  | CONCAT26((ushort)(uVar8 >> 0x35),
                             CONCAT24((ushort)(uVar8 >> 0x20) >> 5,
                                      CONCAT22((ushort)(uVar8 >> 0x10) >> 5,(ushort)uVar8 >> 5)));
          sVar31 = (short)DAT_1008e230;
          sVar25 = (short)((ulonglong)DAT_1008e230 >> 0x10);
          sVar20 = (short)((ulonglong)DAT_1008e230 >> 0x20);
          sVar16 = (short)((ulonglong)DAT_1008e230 >> 0x30);
          uVar36 = CONCAT26((short)((ulonglong)DAT_1008dbe8 >> 0x30) * sVar16,
                            CONCAT24((short)((ulonglong)DAT_1008dbe8 >> 0x20) * sVar20,
                                     CONCAT22((short)((ulonglong)DAT_1008dbe8 >> 0x10) * sVar25,
                                              (short)DAT_1008dbe8 * sVar31))) & DAT_1008e250;
          uVar13 = CONCAT26((short)((ulonglong)DAT_1008dbf0 >> 0x30) * sVar16,
                            CONCAT24((short)((ulonglong)DAT_1008dbf0 >> 0x20) * sVar20,
                                     CONCAT22((short)((ulonglong)DAT_1008dbf0 >> 0x10) * sVar25,
                                              (short)DAT_1008dbf0 * sVar31))) & DAT_1008e250;
          DAT_1008e230 = CONCAT26(sVar16 + (short)((ulonglong)DAT_1008e240 >> 0x30),
                                  CONCAT24(sVar20 + (short)((ulonglong)DAT_1008e240 >> 0x20),
                                           CONCAT22(sVar25 + (short)((ulonglong)DAT_1008e240 >> 0x10
                                                                    ),sVar31 + (short)DAT_1008e240))
                                 );
          *(ulonglong *)(iVar2 + uVar6) =
               *(ulonglong *)(iVar2 + uVar6) & uVar35 |
               ~uVar35 & CONCAT26((short)(uVar8 >> 0x30) + (short)(uVar36 >> 0x30) +
                                  (ushort)(uVar13 >> 0x35) +
                                  ((ushort)((short)((ulonglong)DAT_1008dbf8 >> 0x30) * sVar16) >>
                                  0xb),CONCAT24((short)(uVar8 >> 0x20) + (short)(uVar36 >> 0x20) +
                                                ((ushort)(uVar13 >> 0x20) >> 5) +
                                                ((ushort)((short)((ulonglong)DAT_1008dbf8 >> 0x20) *
                                                         sVar20) >> 0xb),
                                                CONCAT22((short)(uVar8 >> 0x10) +
                                                         (short)(uVar36 >> 0x10) +
                                                         ((ushort)(uVar13 >> 0x10) >> 5) +
                                                         ((ushort)((short)((ulonglong)DAT_1008dbf8
                                                                          >> 0x10) * sVar25) >> 0xb)
                                                         ,(short)uVar8 + (short)uVar36 +
                                                          ((ushort)uVar13 >> 5) +
                                                          ((ushort)((short)DAT_1008dbf8 * sVar31) >>
                                                          0xb))));
          iVar5 = iVar2 + 8;
          bVar1 = iVar2 < -8;
          iVar2 = iVar5;
          uVar8 = uVar14;
        } while (iVar5 == 0 || bVar1);
      }
      DAT_1008d29c = DAT_1008d2a0 + DAT_1008d29c;
      DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
      DAT_1008d290 = DAT_1008d290 + -1;
    } while (DAT_1008d290 != 0);
    return;
  }
  iVar2 = DAT_1008d2d4 + (DAT_1008d2d4 & 0x8000) * 2;
  sVar19 = (short)((uint)iVar2 >> 0x10);
  sVar18 = (short)iVar2;
  uVar11 = (undefined4)(CONCAT26(sVar19,CONCAT24(sVar19,iVar2)) >> 0x20);
  sVar21 = (short)DAT_1008d2e0;
  DAT_1008e218 = CONCAT44(uVar11,uVar11);
  DAT_1008e228 = CONCAT44(CONCAT22(sVar21,sVar21),CONCAT22(sVar21,sVar21));
  DAT_1008e200 = CONCAT26(sVar19 * sVar16,
                          CONCAT24(sVar19 * sVar20,CONCAT22(sVar19 * sVar25,sVar19 * sVar31)));
  DAT_1008e220 = CONCAT44(CONCAT22(sVar18,sVar18),CONCAT22(sVar18,sVar18));
  DAT_1008e210 = CONCAT26(sVar21 * sVar16,
                          CONCAT24(sVar21 * sVar20,CONCAT22(sVar21 * sVar25,sVar21 * sVar31)));
  DAT_1008e208 = CONCAT26(sVar18 * sVar16,
                          CONCAT24(sVar18 * sVar20,CONCAT22(sVar18 * sVar25,sVar18 * sVar31)));
  do {
    iVar2 = DAT_1008d294;
    DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0 & 0x7fff7fff;
    DAT_1008d2cc = DAT_1008d2cc + DAT_1008d2d0;
    DAT_1008d2d8 = DAT_1008d2d8 + DAT_1008d2dc;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar3 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    if (uVar3 < DAT_1008d284 >> 0x10) {
      FUN_100780dd(uVar3 - (DAT_1008d284 >> 0x10));
      sVar31 = (short)DAT_1008d2d8;
      uVar4 = uVar3 & 6;
      uVar6 = DAT_1008d2cc;
      iVar5 = DAT_1008d2d8;
      while( true ) {
        sVar25 = (short)uVar6;
        sVar20 = (short)(uVar6 >> 0x10);
        if (uVar4 == 0) break;
        sVar31 = (short)(iVar5 - DAT_1008d2e0);
        uVar4 = uVar4 - 2;
        uVar6 = (uint)(ushort)(sVar25 - (short)DAT_1008d2d4) |
                CONCAT22(sVar25 - (short)DAT_1008d2d4,sVar20 - DAT_1008d2d4._2_2_) << 0x10;
        iVar5 = iVar5 - DAT_1008d2e0;
      }
      sVar16 = sVar20 + (short)DAT_1008e200;
      sVar18 = sVar20 + (short)((ulonglong)DAT_1008e200 >> 0x10);
      sVar19 = sVar20 + (short)((ulonglong)DAT_1008e200 >> 0x20);
      sVar20 = sVar20 + (short)((ulonglong)DAT_1008e200 >> 0x30);
      sVar21 = sVar25 + (short)DAT_1008e208;
      sVar23 = sVar25 + (short)((ulonglong)DAT_1008e208 >> 0x10);
      sVar24 = sVar25 + (short)((ulonglong)DAT_1008e208 >> 0x20);
      sVar25 = sVar25 + (short)((ulonglong)DAT_1008e208 >> 0x30);
      sVar26 = sVar31 + (short)DAT_1008e210;
      sVar28 = sVar31 + (short)((ulonglong)DAT_1008e210 >> 0x10);
      sVar29 = sVar31 + (short)((ulonglong)DAT_1008e210 >> 0x20);
      sVar31 = sVar31 + (short)((ulonglong)DAT_1008e210 >> 0x30);
      uVar8 = psraw(CONCAT26(sVar20,CONCAT24(sVar19,CONCAT22(sVar18,sVar16))),0xf);
      uVar8 = uVar8 & _DAT_1008e030;
      uVar13 = psraw(CONCAT26(sVar25,CONCAT24(sVar24,CONCAT22(sVar23,sVar21))),0xf);
      uVar13 = uVar13 & _DAT_1008e030;
      uVar14 = psraw(CONCAT26(sVar31,CONCAT24(sVar29,CONCAT22(sVar28,sVar26))),0xf);
      uVar14 = uVar14 & _DAT_1008e030;
      uVar17 = psraw(CONCAT26(sVar20 + (short)(uVar8 >> 0x30),
                              CONCAT24(sVar19 + (short)(uVar8 >> 0x20),
                                       CONCAT22(sVar18 + (short)(uVar8 >> 0x10),
                                                sVar16 + (short)uVar8))),2);
      uVar22 = psraw(CONCAT26(sVar25 + (short)(uVar13 >> 0x30),
                              CONCAT24(sVar24 + (short)(uVar13 >> 0x20),
                                       CONCAT22(sVar23 + (short)(uVar13 >> 0x10),
                                                sVar21 + (short)uVar13))),2);
      uVar27 = psraw(CONCAT26(sVar31 + (short)(uVar14 >> 0x30),
                              CONCAT24(sVar29 + (short)(uVar14 >> 0x20),
                                       CONCAT22(sVar28 + (short)(uVar14 >> 0x10),
                                                sVar26 + (short)uVar14))),2);
      uVar6 = iVar2 - 2U & 0xfffffff8;
      iVar2 = (uVar3 & 0xfffffff8) - uVar6;
      uVar8 = DAT_1008e038;
      do {
        uVar13 = *(ulonglong *)(iVar2 + (extraout_EDX & 0xfffffff8));
        uVar7 = (ushort)uVar13;
        uVar9 = (ushort)(uVar13 >> 0x10);
        uVar10 = (ushort)(uVar13 >> 0x20);
        uVar12 = (ushort)(uVar13 >> 0x30);
        uVar13 = uVar13 & uVar8;
        sVar31 = (short)uVar17;
        sVar25 = (short)((ulonglong)uVar17 >> 0x10);
        sVar20 = (short)((ulonglong)uVar17 >> 0x20);
        sVar16 = (short)((ulonglong)uVar17 >> 0x30);
        uVar36 = CONCAT26(-(ushort)(uVar12 == (ushort)((ulonglong)DAT_1008e008 >> 0x30)),
                          CONCAT24(-(ushort)(uVar10 == (ushort)((ulonglong)DAT_1008e008 >> 0x20)),
                                   CONCAT22(-(ushort)(uVar9 == (ushort)((ulonglong)DAT_1008e008 >>
                                                                       0x10)),
                                            -(ushort)(uVar7 == (ushort)DAT_1008e008))));
        sVar24 = (short)uVar27;
        sVar26 = (short)((ulonglong)uVar27 >> 0x10);
        sVar28 = (short)((ulonglong)uVar27 >> 0x20);
        sVar29 = (short)((ulonglong)uVar27 >> 0x30);
        uVar14 = CONCAT26(uVar12 >> 6,CONCAT24(uVar10 >> 6,CONCAT22(uVar9 >> 6,uVar7 >> 6))) & uVar8
        ;
        uVar17 = CONCAT26(sVar16 + (short)((ulonglong)DAT_1008e218 >> 0x30),
                          CONCAT24(sVar20 + (short)((ulonglong)DAT_1008e218 >> 0x20),
                                   CONCAT22(sVar25 + (short)((ulonglong)DAT_1008e218 >> 0x10),
                                            sVar31 + (short)DAT_1008e218)));
        sVar18 = (short)uVar22;
        sVar19 = (short)((ulonglong)uVar22 >> 0x10);
        sVar21 = (short)((ulonglong)uVar22 >> 0x20);
        sVar23 = (short)((ulonglong)uVar22 >> 0x30);
        uVar22 = CONCAT26(sVar23 + (short)((ulonglong)DAT_1008e220 >> 0x30),
                          CONCAT24(sVar21 + (short)((ulonglong)DAT_1008e220 >> 0x20),
                                   CONCAT22(sVar19 + (short)((ulonglong)DAT_1008e220 >> 0x10),
                                            sVar18 + (short)DAT_1008e220)));
        uVar35 = psllw(uVar8,0xb);
        uVar27 = CONCAT26(sVar29 + (short)((ulonglong)DAT_1008e228 >> 0x30),
                          CONCAT24(sVar28 + (short)((ulonglong)DAT_1008e228 >> 0x20),
                                   CONCAT22(sVar26 + (short)((ulonglong)DAT_1008e228 >> 0x10),
                                            sVar24 + (short)DAT_1008e228)));
        uVar14 = CONCAT26((short)(uVar14 >> 0x30) * sVar23,
                          CONCAT24((short)(uVar14 >> 0x20) * sVar21,
                                   CONCAT22((short)(uVar14 >> 0x10) * sVar19,(short)uVar14 * sVar18)
                                  )) & uVar35;
        uVar8 = CONCAT26((ushort)(uVar35 >> 0x3b),
                         CONCAT24((ushort)(uVar35 >> 0x20) >> 0xb,
                                  CONCAT22((ushort)(uVar35 >> 0x10) >> 0xb,(ushort)uVar35 >> 0xb)));
        *(ulonglong *)(iVar2 + uVar6) =
             *(ulonglong *)(iVar2 + uVar6) & uVar36 |
             ~uVar36 & (CONCAT26((uVar12 >> 0xb) * sVar16,
                                 CONCAT24((uVar10 >> 0xb) * sVar20,
                                          CONCAT22((uVar9 >> 0xb) * sVar25,(uVar7 >> 0xb) * sVar31))
                                ) & uVar35 |
                        CONCAT26((ushort)((short)(uVar13 >> 0x30) * sVar29) >> 0xb,
                                 CONCAT24((ushort)((short)(uVar13 >> 0x20) * sVar28) >> 0xb,
                                          CONCAT22((ushort)((short)(uVar13 >> 0x10) * sVar26) >> 0xb
                                                   ,(ushort)((short)uVar13 * sVar24) >> 0xb))) |
                       CONCAT26((ushort)(uVar14 >> 0x35),
                                CONCAT24((ushort)(uVar14 >> 0x20) >> 5,
                                         CONCAT22((ushort)(uVar14 >> 0x10) >> 5,(ushort)uVar14 >> 5)
                                        )));
        iVar5 = iVar2 + 8;
        bVar1 = iVar2 < -8;
        iVar2 = iVar5;
      } while (iVar5 == 0 || bVar1);
    }
    DAT_1008d29c = DAT_1008d2a0 + DAT_1008d29c;
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


