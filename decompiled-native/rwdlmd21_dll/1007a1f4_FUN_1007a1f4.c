// 1007a1f4 FUN_1007a1f4 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1007a1f4(void)

{
  ulonglong uVar1;
  bool bVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  short sVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint extraout_EDX;
  uint extraout_EDX_00;
  int iVar18;
  int iVar19;
  short sVar20;
  ushort uVar21;
  short sVar22;
  ushort uVar23;
  ushort uVar24;
  ushort uVar25;
  ulonglong uVar26;
  ulonglong uVar27;
  short sVar28;
  short sVar30;
  ulonglong uVar29;
  short sVar31;
  short sVar32;
  short sVar34;
  ushort uVar35;
  ushort uVar36;
  undefined8 uVar33;
  ushort uVar37;
  ulonglong uVar38;
  undefined8 uVar39;
  short sVar42;
  ulonglong uVar40;
  undefined8 uVar41;
  undefined4 uVar43;
  ulonglong uVar44;
  ulonglong uVar45;
  
  sVar32 = (short)DAT_1008e188;
  sVar31 = (short)((ulonglong)DAT_1008e188 >> 0x10);
  sVar34 = (short)((ulonglong)DAT_1008e188 >> 0x20);
  sVar42 = (short)((ulonglong)DAT_1008e188 >> 0x30);
  if ((int)DAT_1008dbe0 != 0) {
    uVar43 = CONCAT22((ushort)DAT_1008d2a8 << 3,(ushort)DAT_1008d2a8 << 3);
    uVar27 = CONCAT44(uVar43,uVar43);
    DAT_1008e1c8 = uVar27 ^ _DAT_1008e018;
    _DAT_1008e1c0 = psllw(uVar27,4);
    iVar15 = DAT_1008d2d4 + (DAT_1008d2d4 & 0x8000) * 2;
    iVar18 = DAT_1008d2e0 + (DAT_1008d2e0 & 0x8000) * 2;
    sVar22 = (short)((uint)iVar15 >> 0x10);
    sVar20 = (short)iVar15;
    sVar30 = (short)((uint)iVar18 >> 0x10);
    sVar28 = (short)iVar18;
    DAT_1008e200 = CONCAT26(sVar22 * sVar42,
                            CONCAT24(sVar22 * sVar34,CONCAT22(sVar22 * sVar31,sVar22 * sVar32)));
    DAT_1008e210 = CONCAT26(sVar28 * sVar42,
                            CONCAT24(sVar28 * sVar34,CONCAT22(sVar28 * sVar31,sVar28 * sVar32)));
    DAT_1008e208 = CONCAT26(sVar20 * sVar42,
                            CONCAT24(sVar20 * sVar34,CONCAT22(sVar20 * sVar31,sVar20 * sVar32)));
    DAT_1008e238 = CONCAT26(sVar30 * sVar42,
                            CONCAT24(sVar30 * sVar34,CONCAT22(sVar30 * sVar31,sVar30 * sVar32)));
    DAT_1008e218 = pmulhw(CONCAT26(sVar22 * 2,CONCAT24(sVar22 * 2,CONCAT22(sVar22 * 2,sVar22 * 2))),
                          _DAT_1008e1c0);
    DAT_1008e220 = pmulhw(CONCAT26(sVar20 * 2,CONCAT24(sVar20 * 2,CONCAT22(sVar20 * 2,sVar20 * 2))),
                          _DAT_1008e1c0);
    DAT_1008e228 = pmulhw(CONCAT26(sVar28 * 2,CONCAT24(sVar28 * 2,CONCAT22(sVar28 * 2,sVar28 * 2))),
                          _DAT_1008e1c0);
    DAT_1008e240 = pmulhw(CONCAT26(sVar30 * 2,CONCAT24(sVar30 * 2,CONCAT22(sVar30 * 2,sVar30 * 2))),
                          _DAT_1008e1c0);
    do {
      iVar15 = DAT_1008d294;
      DAT_1008d2e4 = DAT_1008d2e4 + DAT_1008d2e8;
      DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0 & 0x7fff7fff;
      DAT_1008d2cc = DAT_1008d2cc + DAT_1008d2d0;
      DAT_1008d2d8 = DAT_1008d2d8 + DAT_1008d2dc;
      DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
      uVar16 = DAT_1008d280 >> 0x10;
      DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
      if (uVar16 < DAT_1008d284 >> 0x10) {
        FUN_10078140(uVar16 - (DAT_1008d284 >> 0x10));
        iVar18 = DAT_1008d2cc;
        iVar19 = DAT_1008d2d8;
        for (uVar17 = uVar16 & 6; uVar17 != 0; uVar17 = uVar17 - 2) {
          iVar18 = iVar18 - DAT_1008d2d4;
          iVar19 = iVar19 - DAT_1008d2e0;
        }
        sVar31 = (short)((uint)iVar18 >> 0x10);
        sVar32 = (short)iVar18;
        sVar42 = (short)((uint)iVar19 >> 0x10);
        sVar34 = (short)iVar19;
        uVar33 = psraw(CONCAT26(sVar31 + (short)((ulonglong)DAT_1008e200 >> 0x30),
                                CONCAT24(sVar31 + (short)((ulonglong)DAT_1008e200 >> 0x20),
                                         CONCAT22(sVar31 + (short)((ulonglong)DAT_1008e200 >> 0x10),
                                                  sVar31 + (short)DAT_1008e200))),1);
        uVar39 = psraw(CONCAT26(sVar32 + (short)((ulonglong)DAT_1008e208 >> 0x30),
                                CONCAT24(sVar32 + (short)((ulonglong)DAT_1008e208 >> 0x20),
                                         CONCAT22(sVar32 + (short)((ulonglong)DAT_1008e208 >> 0x10),
                                                  sVar32 + (short)DAT_1008e208))),1);
        DAT_1008dff0 = pmulhw(uVar33,_DAT_1008e1c0);
        uVar41 = psraw(CONCAT26(sVar34 + (short)((ulonglong)DAT_1008e210 >> 0x30),
                                CONCAT24(sVar34 + (short)((ulonglong)DAT_1008e210 >> 0x20),
                                         CONCAT22(sVar34 + (short)((ulonglong)DAT_1008e210 >> 0x10),
                                                  sVar34 + (short)DAT_1008e210))),1);
        DAT_1008dff8 = pmulhw(uVar39,_DAT_1008e1c0);
        uVar33 = psraw(CONCAT26(sVar42 + (short)((ulonglong)DAT_1008e238 >> 0x30),
                                CONCAT24(sVar42 + (short)((ulonglong)DAT_1008e238 >> 0x20),
                                         CONCAT22(sVar42 + (short)((ulonglong)DAT_1008e238 >> 0x10),
                                                  sVar42 + (short)DAT_1008e238))),1);
        DAT_1008e000 = pmulhw(uVar41,_DAT_1008e1c0);
        DAT_1008e230 = pmulhw(uVar33,_DAT_1008e1c0);
        uVar17 = iVar15 - 2U & 0xfffffff8;
        iVar15 = (uVar16 & 0xfffffff8) - uVar17;
        uVar27 = DAT_1008e038;
        do {
          uVar29 = *(ulonglong *)(iVar15 + (extraout_EDX_00 & 0xfffffff8));
          uVar1 = *(ulonglong *)(iVar15 + uVar17);
          uVar35 = (ushort)(uVar1 >> 0x10);
          uVar36 = (ushort)(uVar1 >> 0x20);
          uVar37 = (ushort)(uVar1 >> 0x30);
          uVar40 = uVar1 & uVar27;
          sVar32 = (short)DAT_1008e1c8;
          sVar22 = (short)(DAT_1008e1c8 >> 0x10);
          sVar5 = (short)(DAT_1008e1c8 >> 0x20);
          sVar10 = (short)(DAT_1008e1c8 >> 0x30);
          uVar38 = CONCAT26(uVar37 >> 6,
                            CONCAT24(uVar36 >> 6,CONCAT22(uVar35 >> 6,(ushort)uVar1 >> 6))) & uVar27
          ;
          uVar21 = (ushort)uVar29;
          uVar23 = (ushort)(uVar29 >> 0x10);
          uVar24 = (ushort)(uVar29 >> 0x20);
          uVar25 = (ushort)(uVar29 >> 0x30);
          sVar31 = (short)DAT_1008e230;
          sVar28 = (short)((ulonglong)DAT_1008e230 >> 0x10);
          sVar6 = (short)((ulonglong)DAT_1008e230 >> 0x20);
          sVar11 = (short)((ulonglong)DAT_1008e230 >> 0x30);
          sVar34 = (short)DAT_1008dff0;
          sVar30 = (short)((ulonglong)DAT_1008dff0 >> 0x10);
          sVar7 = (short)((ulonglong)DAT_1008dff0 >> 0x20);
          sVar12 = (short)((ulonglong)DAT_1008dff0 >> 0x30);
          uVar29 = uVar29 & uVar27;
          uVar44 = CONCAT26(-(ushort)(uVar25 == (ushort)((ulonglong)DAT_1008e008 >> 0x30)),
                            CONCAT24(-(ushort)(uVar24 == (ushort)((ulonglong)DAT_1008e008 >> 0x20)),
                                     CONCAT22(-(ushort)(uVar23 ==
                                                       (ushort)((ulonglong)DAT_1008e008 >> 0x10)),
                                              -(ushort)(uVar21 == (ushort)DAT_1008e008))));
          sVar42 = (short)DAT_1008e000;
          sVar3 = (short)((ulonglong)DAT_1008e000 >> 0x10);
          sVar8 = (short)((ulonglong)DAT_1008e000 >> 0x20);
          sVar13 = (short)((ulonglong)DAT_1008e000 >> 0x30);
          uVar26 = CONCAT26(uVar25 >> 6,CONCAT24(uVar24 >> 6,CONCAT22(uVar23 >> 6,uVar21 >> 6))) &
                   uVar27;
          sVar20 = (short)DAT_1008dff8;
          sVar4 = (short)((ulonglong)DAT_1008dff8 >> 0x10);
          sVar9 = (short)((ulonglong)DAT_1008dff8 >> 0x20);
          sVar14 = (short)((ulonglong)DAT_1008dff8 >> 0x30);
          uVar45 = psllw(uVar27,0xb);
          DAT_1008dff0 = CONCAT26(sVar12 + (short)((ulonglong)DAT_1008e218 >> 0x30),
                                  CONCAT24(sVar7 + (short)((ulonglong)DAT_1008e218 >> 0x20),
                                           CONCAT22(sVar30 + (short)((ulonglong)DAT_1008e218 >> 0x10
                                                                    ),sVar34 + (short)DAT_1008e218))
                                 );
          DAT_1008dff8 = CONCAT26(sVar14 + (short)((ulonglong)DAT_1008e220 >> 0x30),
                                  CONCAT24(sVar9 + (short)((ulonglong)DAT_1008e220 >> 0x20),
                                           CONCAT22(sVar4 + (short)((ulonglong)DAT_1008e220 >> 0x10)
                                                    ,sVar20 + (short)DAT_1008e220)));
          uVar27 = CONCAT26((short)(uVar26 >> 0x30) * sVar14 + (short)(uVar38 >> 0x30) * sVar10 +
                            (short)((ulonglong)DAT_1008dbf0 >> 0x30) * sVar11,
                            CONCAT24((short)(uVar26 >> 0x20) * sVar9 +
                                     (short)(uVar38 >> 0x20) * sVar5 +
                                     (short)((ulonglong)DAT_1008dbf0 >> 0x20) * sVar6,
                                     CONCAT22((short)(uVar26 >> 0x10) * sVar4 +
                                              (short)(uVar38 >> 0x10) * sVar22 +
                                              (short)((ulonglong)DAT_1008dbf0 >> 0x10) * sVar28,
                                              (short)uVar26 * sVar20 + (short)uVar38 * sVar32 +
                                              (short)DAT_1008dbf0 * sVar31))) & uVar45;
          DAT_1008e230 = CONCAT26(sVar11 + (short)((ulonglong)DAT_1008e240 >> 0x30),
                                  CONCAT24(sVar6 + (short)((ulonglong)DAT_1008e240 >> 0x20),
                                           CONCAT22(sVar28 + (short)((ulonglong)DAT_1008e240 >> 0x10
                                                                    ),sVar31 + (short)DAT_1008e240))
                                 );
          DAT_1008e000 = CONCAT26(sVar13 + (short)((ulonglong)DAT_1008e228 >> 0x30),
                                  CONCAT24(sVar8 + (short)((ulonglong)DAT_1008e228 >> 0x20),
                                           CONCAT22(sVar3 + (short)((ulonglong)DAT_1008e228 >> 0x10)
                                                    ,sVar42 + (short)DAT_1008e228)));
          *(ulonglong *)(iVar15 + uVar17) =
               *(ulonglong *)(iVar15 + uVar17) & uVar44 |
               ~uVar44 & (CONCAT26((uVar25 >> 0xb) * sVar12 +
                                   (short)((ulonglong)DAT_1008dbe8 >> 0x30) * sVar11 +
                                   (uVar37 >> 0xb) * sVar10,
                                   CONCAT24((uVar24 >> 0xb) * sVar7 +
                                            (short)((ulonglong)DAT_1008dbe8 >> 0x20) * sVar6 +
                                            (uVar36 >> 0xb) * sVar5,
                                            CONCAT22((uVar23 >> 0xb) * sVar30 +
                                                     (short)((ulonglong)DAT_1008dbe8 >> 0x10) *
                                                     sVar28 + (uVar35 >> 0xb) * sVar22,
                                                     (uVar21 >> 0xb) * sVar34 +
                                                     (short)DAT_1008dbe8 * sVar31 +
                                                     ((ushort)uVar1 >> 0xb) * sVar32))) & uVar45 |
                          CONCAT26((ushort)((short)(uVar29 >> 0x30) * sVar13 +
                                            (short)(uVar40 >> 0x30) * sVar10 +
                                           (short)((ulonglong)DAT_1008dbf8 >> 0x30) * sVar11) >> 0xb
                                   ,CONCAT24((ushort)((short)(uVar29 >> 0x20) * sVar8 +
                                                      (short)(uVar40 >> 0x20) * sVar5 +
                                                     (short)((ulonglong)DAT_1008dbf8 >> 0x20) *
                                                     sVar6) >> 0xb,
                                             CONCAT22((ushort)((short)(uVar29 >> 0x10) * sVar3 +
                                                               (short)(uVar40 >> 0x10) * sVar22 +
                                                              (short)((ulonglong)DAT_1008dbf8 >>
                                                                     0x10) * sVar28) >> 0xb,
                                                      (ushort)((short)uVar29 * sVar42 +
                                                               (short)uVar40 * sVar32 +
                                                              (short)DAT_1008dbf8 * sVar31) >> 0xb))
                                  ) |
                         CONCAT26((ushort)(uVar27 >> 0x35),
                                  CONCAT24((ushort)(uVar27 >> 0x20) >> 5,
                                           CONCAT22((ushort)(uVar27 >> 0x10) >> 5,
                                                    (ushort)uVar27 >> 5))));
          uVar27 = CONCAT26((ushort)(uVar45 >> 0x3b),
                            CONCAT24((ushort)(uVar45 >> 0x20) >> 0xb,
                                     CONCAT22((ushort)(uVar45 >> 0x10) >> 0xb,(ushort)uVar45 >> 0xb)
                                    ));
          iVar18 = iVar15 + 8;
          bVar2 = iVar15 < -8;
          iVar15 = iVar18;
        } while (iVar18 == 0 || bVar2);
      }
      DAT_1008d29c = DAT_1008d2a0 + DAT_1008d29c;
      DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
      DAT_1008d290 = DAT_1008d290 + -1;
    } while (DAT_1008d290 != 0);
    return;
  }
  uVar43 = CONCAT22((ushort)DAT_1008d2a8 << 3,(ushort)DAT_1008d2a8 << 3);
  uVar27 = CONCAT44(uVar43,uVar43);
  DAT_1008e1c8 = uVar27 ^ _DAT_1008e018;
  _DAT_1008e1c0 = psllw(uVar27,4);
  iVar15 = DAT_1008d2d4 + (DAT_1008d2d4 & 0x8000) * 2;
  sVar22 = (short)((uint)iVar15 >> 0x10);
  sVar20 = (short)iVar15;
  sVar28 = (short)DAT_1008d2e0;
  DAT_1008e200 = CONCAT26(sVar22 * sVar42,
                          CONCAT24(sVar22 * sVar34,CONCAT22(sVar22 * sVar31,sVar22 * sVar32)));
  DAT_1008e210 = CONCAT26(sVar28 * sVar42,
                          CONCAT24(sVar28 * sVar34,CONCAT22(sVar28 * sVar31,sVar28 * sVar32)));
  DAT_1008e208 = CONCAT26(sVar20 * sVar42,
                          CONCAT24(sVar20 * sVar34,CONCAT22(sVar20 * sVar31,sVar20 * sVar32)));
  DAT_1008e218 = pmulhw(CONCAT26(sVar22 * 2,CONCAT24(sVar22 * 2,CONCAT22(sVar22 * 2,sVar22 * 2))),
                        _DAT_1008e1c0);
  DAT_1008e220 = pmulhw(CONCAT26(sVar20 * 2,CONCAT24(sVar20 * 2,CONCAT22(sVar20 * 2,sVar20 * 2))),
                        _DAT_1008e1c0);
  DAT_1008e228 = pmulhw(CONCAT26(sVar28 * 2,CONCAT24(sVar28 * 2,CONCAT22(sVar28 * 2,sVar28 * 2))),
                        _DAT_1008e1c0);
  do {
    iVar15 = DAT_1008d294;
    DAT_1008d2e4 = DAT_1008d2e4 + DAT_1008d2e8;
    DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0 & 0x7fff7fff;
    DAT_1008d2cc = DAT_1008d2cc + DAT_1008d2d0;
    DAT_1008d2d8 = DAT_1008d2d8 + DAT_1008d2dc;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar16 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    if (uVar16 < DAT_1008d284 >> 0x10) {
      FUN_10078140(uVar16 - (DAT_1008d284 >> 0x10));
      sVar32 = (short)DAT_1008d2d8;
      iVar18 = DAT_1008d2cc;
      iVar19 = DAT_1008d2d8;
      for (uVar17 = uVar16 & 6; uVar17 != 0; uVar17 = uVar17 - 2) {
        sVar32 = (short)(iVar19 - DAT_1008d2e0);
        iVar18 = iVar18 - DAT_1008d2d4;
        iVar19 = iVar19 - DAT_1008d2e0;
      }
      sVar34 = (short)((uint)iVar18 >> 0x10);
      sVar31 = (short)iVar18;
      uVar33 = psraw(CONCAT26(sVar34 + (short)((ulonglong)DAT_1008e200 >> 0x30),
                              CONCAT24(sVar34 + (short)((ulonglong)DAT_1008e200 >> 0x20),
                                       CONCAT22(sVar34 + (short)((ulonglong)DAT_1008e200 >> 0x10),
                                                sVar34 + (short)DAT_1008e200))),1);
      DAT_1008dff0 = pmulhw(uVar33,_DAT_1008e1c0);
      uVar33 = psraw(CONCAT26(sVar31 + (short)((ulonglong)DAT_1008e208 >> 0x30),
                              CONCAT24(sVar31 + (short)((ulonglong)DAT_1008e208 >> 0x20),
                                       CONCAT22(sVar31 + (short)((ulonglong)DAT_1008e208 >> 0x10),
                                                sVar31 + (short)DAT_1008e208))),1);
      DAT_1008dff8 = pmulhw(uVar33,_DAT_1008e1c0);
      uVar33 = psraw(CONCAT26(sVar32 + (short)((ulonglong)DAT_1008e210 >> 0x30),
                              CONCAT24(sVar32 + (short)((ulonglong)DAT_1008e210 >> 0x20),
                                       CONCAT22(sVar32 + (short)((ulonglong)DAT_1008e210 >> 0x10),
                                                sVar32 + (short)DAT_1008e210))),1);
      DAT_1008e000 = pmulhw(uVar33,_DAT_1008e1c0);
      uVar17 = iVar15 - 2U & 0xfffffff8;
      iVar15 = (uVar16 & 0xfffffff8) - uVar17;
      uVar27 = DAT_1008e038;
      do {
        uVar29 = *(ulonglong *)(iVar15 + (extraout_EDX & 0xfffffff8));
        uVar1 = *(ulonglong *)(iVar15 + uVar17);
        uVar35 = (ushort)(uVar1 >> 0x10);
        uVar36 = (ushort)(uVar1 >> 0x20);
        uVar37 = (ushort)(uVar1 >> 0x30);
        uVar40 = uVar1 & uVar27;
        sVar32 = (short)DAT_1008e1c8;
        sVar20 = (short)(DAT_1008e1c8 >> 0x10);
        sVar3 = (short)(DAT_1008e1c8 >> 0x20);
        sVar7 = (short)(DAT_1008e1c8 >> 0x30);
        uVar38 = CONCAT26(uVar37 >> 6,CONCAT24(uVar36 >> 6,CONCAT22(uVar35 >> 6,(ushort)uVar1 >> 6))
                         ) & uVar27;
        uVar21 = (ushort)uVar29;
        uVar23 = (ushort)(uVar29 >> 0x10);
        uVar24 = (ushort)(uVar29 >> 0x20);
        uVar25 = (ushort)(uVar29 >> 0x30);
        uVar29 = uVar29 & uVar27;
        sVar31 = (short)DAT_1008dff0;
        sVar22 = (short)((ulonglong)DAT_1008dff0 >> 0x10);
        sVar4 = (short)((ulonglong)DAT_1008dff0 >> 0x20);
        sVar8 = (short)((ulonglong)DAT_1008dff0 >> 0x30);
        uVar44 = CONCAT26(-(ushort)(uVar25 == (ushort)((ulonglong)DAT_1008e008 >> 0x30)),
                          CONCAT24(-(ushort)(uVar24 == (ushort)((ulonglong)DAT_1008e008 >> 0x20)),
                                   CONCAT22(-(ushort)(uVar23 ==
                                                     (ushort)((ulonglong)DAT_1008e008 >> 0x10)),
                                            -(ushort)(uVar21 == (ushort)DAT_1008e008))));
        sVar34 = (short)DAT_1008e000;
        sVar28 = (short)((ulonglong)DAT_1008e000 >> 0x10);
        sVar5 = (short)((ulonglong)DAT_1008e000 >> 0x20);
        sVar9 = (short)((ulonglong)DAT_1008e000 >> 0x30);
        uVar26 = CONCAT26(uVar25 >> 6,CONCAT24(uVar24 >> 6,CONCAT22(uVar23 >> 6,uVar21 >> 6))) &
                 uVar27;
        sVar42 = (short)DAT_1008dff8;
        sVar30 = (short)((ulonglong)DAT_1008dff8 >> 0x10);
        sVar6 = (short)((ulonglong)DAT_1008dff8 >> 0x20);
        sVar10 = (short)((ulonglong)DAT_1008dff8 >> 0x30);
        uVar45 = psllw(uVar27,0xb);
        DAT_1008dff0 = CONCAT26(sVar8 + (short)((ulonglong)DAT_1008e218 >> 0x30),
                                CONCAT24(sVar4 + (short)((ulonglong)DAT_1008e218 >> 0x20),
                                         CONCAT22(sVar22 + (short)((ulonglong)DAT_1008e218 >> 0x10),
                                                  sVar31 + (short)DAT_1008e218)));
        DAT_1008dff8 = CONCAT26(sVar10 + (short)((ulonglong)DAT_1008e220 >> 0x30),
                                CONCAT24(sVar6 + (short)((ulonglong)DAT_1008e220 >> 0x20),
                                         CONCAT22(sVar30 + (short)((ulonglong)DAT_1008e220 >> 0x10),
                                                  sVar42 + (short)DAT_1008e220)));
        uVar27 = CONCAT26((short)(uVar26 >> 0x30) * sVar10 + (short)(uVar38 >> 0x30) * sVar7,
                          CONCAT24((short)(uVar26 >> 0x20) * sVar6 + (short)(uVar38 >> 0x20) * sVar3
                                   ,CONCAT22((short)(uVar26 >> 0x10) * sVar30 +
                                             (short)(uVar38 >> 0x10) * sVar20,
                                             (short)uVar26 * sVar42 + (short)uVar38 * sVar32))) &
                 uVar45;
        DAT_1008e000 = CONCAT26(sVar9 + (short)((ulonglong)DAT_1008e228 >> 0x30),
                                CONCAT24(sVar5 + (short)((ulonglong)DAT_1008e228 >> 0x20),
                                         CONCAT22(sVar28 + (short)((ulonglong)DAT_1008e228 >> 0x10),
                                                  sVar34 + (short)DAT_1008e228)));
        *(ulonglong *)(iVar15 + uVar17) =
             *(ulonglong *)(iVar15 + uVar17) & uVar44 |
             ~uVar44 & (CONCAT26((uVar25 >> 0xb) * sVar8 + (uVar37 >> 0xb) * sVar7,
                                 CONCAT24((uVar24 >> 0xb) * sVar4 + (uVar36 >> 0xb) * sVar3,
                                          CONCAT22((uVar23 >> 0xb) * sVar22 +
                                                   (uVar35 >> 0xb) * sVar20,
                                                   (uVar21 >> 0xb) * sVar31 +
                                                   ((ushort)uVar1 >> 0xb) * sVar32))) & uVar45 |
                        CONCAT26((ushort)((short)(uVar29 >> 0x30) * sVar9 +
                                         (short)(uVar40 >> 0x30) * sVar7) >> 0xb,
                                 CONCAT24((ushort)((short)(uVar29 >> 0x20) * sVar5 +
                                                  (short)(uVar40 >> 0x20) * sVar3) >> 0xb,
                                          CONCAT22((ushort)((short)(uVar29 >> 0x10) * sVar28 +
                                                           (short)(uVar40 >> 0x10) * sVar20) >> 0xb,
                                                   (ushort)((short)uVar29 * sVar34 +
                                                           (short)uVar40 * sVar32) >> 0xb))) |
                       CONCAT26((ushort)(uVar27 >> 0x35),
                                CONCAT24((ushort)(uVar27 >> 0x20) >> 5,
                                         CONCAT22((ushort)(uVar27 >> 0x10) >> 5,(ushort)uVar27 >> 5)
                                        )));
        uVar27 = CONCAT26((ushort)(uVar45 >> 0x3b),
                          CONCAT24((ushort)(uVar45 >> 0x20) >> 0xb,
                                   CONCAT22((ushort)(uVar45 >> 0x10) >> 0xb,(ushort)uVar45 >> 0xb)))
        ;
        iVar18 = iVar15 + 8;
        bVar2 = iVar15 < -8;
        iVar15 = iVar18;
      } while (iVar18 == 0 || bVar2);
    }
    DAT_1008d29c = DAT_1008d2a0 + DAT_1008d29c;
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


