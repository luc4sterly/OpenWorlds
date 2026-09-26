// 1007f404 FUN_1007f404 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1007f404(void)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  uint uVar9;
  uint extraout_EDX;
  uint extraout_EDX_00;
  uint uVar10;
  int iVar11;
  int iVar12;
  short sVar13;
  short sVar14;
  undefined4 uVar18;
  undefined8 uVar15;
  short sVar16;
  short sVar17;
  unkbyte10 in_ST0;
  undefined2 uVar19;
  ulonglong uVar20;
  unkbyte10 in_ST1;
  undefined2 uVar21;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  short sVar22;
  short sVar23;
  undefined8 uVar24;
  ulonglong uVar25;
  undefined8 uVar26;
  ulonglong uVar27;
  short sVar28;
  short sVar29;
  unkbyte10 in_ST2;
  undefined8 uVar30;
  ulonglong uVar31;
  undefined8 uVar32;
  undefined8 uVar33;
  undefined8 uVar34;
  undefined8 uVar35;
  undefined8 uVar36;
  ushort uVar37;
  ushort uVar39;
  ushort uVar40;
  ushort uVar41;
  unkbyte10 Var38;
  
  uVar19 = (undefined2)((unkuint10)in_ST0 >> 0x40);
  uVar21 = (undefined2)((unkuint10)in_ST1 >> 0x40);
  sVar14 = (short)DAT_1008e188;
  sVar17 = (short)((ulonglong)DAT_1008e188 >> 0x10);
  sVar23 = (short)((ulonglong)DAT_1008e188 >> 0x20);
  sVar29 = (short)((ulonglong)DAT_1008e188 >> 0x30);
  if ((int)DAT_1008dbe0 == 0) {
    uVar18 = CONCAT22((ushort)DAT_1008d2a8 << 3,(ushort)DAT_1008d2a8 << 3);
    uVar20 = CONCAT44(uVar18,uVar18);
    _DAT_1008e1c0 = psllw(uVar20,4);
    DAT_1008e1c8 = psllw(uVar20 ^ _DAT_1008e018,4);
    iVar8 = DAT_1008d2d4 + (DAT_1008d2d4 & 0x8000) * 2;
    sVar16 = (short)((uint)iVar8 >> 0x10);
    sVar13 = (short)iVar8;
    sVar22 = (short)DAT_1008d2e0;
    uVar18 = (undefined4)(CONCAT46(CONCAT22(uVar19,sVar16),CONCAT24(sVar16,iVar8)) >> 0x20);
    uVar15 = CONCAT44(uVar18,uVar18);
    uVar33 = psraw(uVar15,0xf);
    uVar15 = pmulhw(uVar15,_DAT_1008e1c0);
    DAT_1008e218 = psllw(CONCAT26((short)((ulonglong)uVar15 >> 0x30) -
                                  (short)((ulonglong)uVar33 >> 0x30),
                                  CONCAT24((short)((ulonglong)uVar15 >> 0x20) -
                                           (short)((ulonglong)uVar33 >> 0x20),
                                           CONCAT22((short)((ulonglong)uVar15 >> 0x10) -
                                                    (short)((ulonglong)uVar33 >> 0x10),
                                                    (short)uVar15 - (short)uVar33))),5);
    uVar15 = CONCAT44(CONCAT22(sVar22,sVar22),CONCAT22(sVar22,sVar22));
    uVar33 = psraw(uVar15,0xf);
    uVar15 = pmulhw(uVar15,_DAT_1008e1c0);
    DAT_1008e228 = psllw(CONCAT26((short)((ulonglong)uVar15 >> 0x30) -
                                  (short)((ulonglong)uVar33 >> 0x30),
                                  CONCAT24((short)((ulonglong)uVar15 >> 0x20) -
                                           (short)((ulonglong)uVar33 >> 0x20),
                                           CONCAT22((short)((ulonglong)uVar15 >> 0x10) -
                                                    (short)((ulonglong)uVar33 >> 0x10),
                                                    (short)uVar15 - (short)uVar33))),5);
    DAT_1008e200 = CONCAT26(sVar16 * sVar29,
                            CONCAT24(sVar16 * sVar23,CONCAT22(sVar16 * sVar17,sVar16 * sVar14)));
    uVar15 = CONCAT44(CONCAT22(sVar13,sVar13),CONCAT22(sVar13,sVar13));
    DAT_1008e210 = CONCAT26(sVar22 * sVar29,
                            CONCAT24(sVar22 * sVar23,CONCAT22(sVar22 * sVar17,sVar22 * sVar14)));
    DAT_1008e208 = CONCAT26(sVar13 * sVar29,
                            CONCAT24(sVar13 * sVar23,CONCAT22(sVar13 * sVar17,sVar13 * sVar14)));
    uVar33 = psraw(uVar15,0xf);
    uVar15 = pmulhw(uVar15,_DAT_1008e1c0);
    DAT_1008e220 = psllw(CONCAT26((short)((ulonglong)uVar15 >> 0x30) -
                                  (short)((ulonglong)uVar33 >> 0x30),
                                  CONCAT24((short)((ulonglong)uVar15 >> 0x20) -
                                           (short)((ulonglong)uVar33 >> 0x20),
                                           CONCAT22((short)((ulonglong)uVar15 >> 0x10) -
                                                    (short)((ulonglong)uVar33 >> 0x10),
                                                    (short)uVar15 - (short)uVar33))),5);
    do {
      iVar8 = DAT_1008d294;
      DAT_1008d2cc = DAT_1008d2cc + DAT_1008d2d0;
      DAT_1008d2d8 = DAT_1008d2d8 + DAT_1008d2dc;
      DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0;
      DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
      uVar9 = DAT_1008d280 >> 0x10;
      DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
      fVar2 = _DAT_1008d440 + _DAT_1008d444;
      fVar3 = _DAT_1008d448 + _DAT_1008d44c;
      fVar4 = _DAT_1008d450 + _DAT_1008d454;
      fVar5 = _DAT_1008d458 + _DAT_1008d45c;
      fVar6 = _DAT_1008d460 + _DAT_1008d464;
      fVar7 = _DAT_1008d468 + _DAT_1008d46c;
      if (uVar9 < DAT_1008d284 >> 0x10) {
        FUN_1007d650(uVar9 - (DAT_1008d284 >> 0x10));
        iVar11 = DAT_1008d2cc;
        iVar12 = DAT_1008d2d8;
        for (uVar10 = uVar9 & 6; uVar10 != 0; uVar10 = uVar10 - 2) {
          iVar11 = iVar11 - DAT_1008d2d4;
          iVar12 = iVar12 - DAT_1008d2e0;
        }
        sVar17 = (short)((uint)iVar11 >> 0x10);
        sVar14 = (short)iVar11;
        sVar23 = (short)iVar12;
        uVar15 = pmulhw(CONCAT26(sVar17 + (short)((ulonglong)DAT_1008e200 >> 0x30),
                                 CONCAT24(sVar17 + (short)((ulonglong)DAT_1008e200 >> 0x20),
                                          CONCAT22(sVar17 + (short)((ulonglong)DAT_1008e200 >> 0x10)
                                                   ,sVar17 + (short)DAT_1008e200))),_DAT_1008e1c0);
        uVar33 = pmulhw(CONCAT26(sVar14 + (short)((ulonglong)DAT_1008e208 >> 0x30),
                                 CONCAT24(sVar14 + (short)((ulonglong)DAT_1008e208 >> 0x20),
                                          CONCAT22(sVar14 + (short)((ulonglong)DAT_1008e208 >> 0x10)
                                                   ,sVar14 + (short)DAT_1008e208))),_DAT_1008e1c0);
        uVar24 = pmulhw(CONCAT26(sVar23 + (short)((ulonglong)DAT_1008e210 >> 0x30),
                                 CONCAT24(sVar23 + (short)((ulonglong)DAT_1008e210 >> 0x20),
                                          CONCAT22(sVar23 + (short)((ulonglong)DAT_1008e210 >> 0x10)
                                                   ,sVar23 + (short)DAT_1008e210))),_DAT_1008e1c0);
        DAT_1008dff0 = psllw(uVar15,3);
        DAT_1008dff8 = psllw(uVar33,3);
        DAT_1008e000 = psllw(uVar24,3);
        uVar10 = iVar8 - 2U & 0xfffffff8;
        Var38 = CONCAT28(uVar21,DAT_1008e260);
        iVar8 = (uVar9 & 0xfffffff8) - uVar10;
        do {
          uVar15 = *(undefined8 *)(iVar8 + uVar10);
          uVar27 = (ulonglong)Var38;
          uVar33 = pmulhw(CONCAT26((ushort)((ulonglong)uVar15 >> 0x31),
                                   CONCAT24((ushort)((ulonglong)uVar15 >> 0x20) >> 1,
                                            CONCAT22((ushort)((ulonglong)uVar15 >> 0x10) >> 1,
                                                     (ushort)uVar15 >> 1))) & uVar27,DAT_1008e1c8);
          uVar25 = psllw(uVar15,10);
          uVar20 = psllw(uVar15,4);
          uVar26 = pmulhw(uVar25 & uVar27,DAT_1008e1c8);
          uVar24 = pmulhw(uVar20 & uVar27,DAT_1008e1c8);
          uVar15 = *(undefined8 *)(iVar8 + (extraout_EDX & 0xfffffff8));
          uVar30 = pmulhw(CONCAT26((ushort)((ulonglong)uVar15 >> 0x31),
                                   CONCAT24((ushort)((ulonglong)uVar15 >> 0x20) >> 1,
                                            CONCAT22((ushort)((ulonglong)uVar15 >> 0x10) >> 1,
                                                     (ushort)uVar15 >> 1))) & uVar27,DAT_1008dff0);
          uVar25 = psllw(uVar15,10);
          uVar20 = psllw(uVar15,4);
          uVar32 = pmulhw(uVar25 & uVar27,DAT_1008e000);
          uVar15 = pmulhw(uVar20 & uVar27,DAT_1008dff8);
          uVar37 = (ushort)Var38 >> 1;
          uVar39 = (ushort)((unkuint10)Var38 >> 0x10) >> 1;
          uVar40 = (ushort)((unkuint10)Var38 >> 0x20) >> 1;
          uVar41 = (ushort)((unkuint10)Var38 >> 0x30) >> 1;
          uVar20 = CONCAT26(uVar41,CONCAT24(uVar40,CONCAT22(uVar39,uVar37)));
          DAT_1008dff0 = CONCAT26((short)((ulonglong)DAT_1008dff0 >> 0x30) +
                                  (short)((ulonglong)DAT_1008e218 >> 0x30),
                                  CONCAT24((short)((ulonglong)DAT_1008dff0 >> 0x20) +
                                           (short)((ulonglong)DAT_1008e218 >> 0x20),
                                           CONCAT22((short)((ulonglong)DAT_1008dff0 >> 0x10) +
                                                    (short)((ulonglong)DAT_1008e218 >> 0x10),
                                                    (short)DAT_1008dff0 + (short)DAT_1008e218)));
          DAT_1008dff8 = CONCAT26((short)((ulonglong)DAT_1008dff8 >> 0x30) +
                                  (short)((ulonglong)DAT_1008e220 >> 0x30),
                                  CONCAT24((short)((ulonglong)DAT_1008dff8 >> 0x20) +
                                           (short)((ulonglong)DAT_1008e220 >> 0x20),
                                           CONCAT22((short)((ulonglong)DAT_1008dff8 >> 0x10) +
                                                    (short)((ulonglong)DAT_1008e220 >> 0x10),
                                                    (short)DAT_1008dff8 + (short)DAT_1008e220)));
          uVar25 = CONCAT26((short)((ulonglong)uVar24 >> 0x30) + (short)((ulonglong)uVar15 >> 0x30),
                            CONCAT24((short)((ulonglong)uVar24 >> 0x20) +
                                     (short)((ulonglong)uVar15 >> 0x20),
                                     CONCAT22((short)((ulonglong)uVar24 >> 0x10) +
                                              (short)((ulonglong)uVar15 >> 0x10),
                                              (short)uVar24 + (short)uVar15))) & uVar20;
          uVar27 = CONCAT26((short)((ulonglong)uVar26 >> 0x30) + (short)((ulonglong)uVar32 >> 0x30),
                            CONCAT24((short)((ulonglong)uVar26 >> 0x20) +
                                     (short)((ulonglong)uVar32 >> 0x20),
                                     CONCAT22((short)((ulonglong)uVar26 >> 0x10) +
                                              (short)((ulonglong)uVar32 >> 0x10),
                                              (short)uVar26 + (short)uVar32))) & uVar20;
          uVar20 = psllw(CONCAT26((short)((ulonglong)uVar33 >> 0x30) +
                                  (short)((ulonglong)uVar30 >> 0x30),
                                  CONCAT24((short)((ulonglong)uVar33 >> 0x20) +
                                           (short)((ulonglong)uVar30 >> 0x20),
                                           CONCAT22((short)((ulonglong)uVar33 >> 0x10) +
                                                    (short)((ulonglong)uVar30 >> 0x10),
                                                    (short)uVar33 + (short)uVar30))) & uVar20,2);
          DAT_1008e000 = CONCAT26((short)((ulonglong)DAT_1008e000 >> 0x30) +
                                  (short)((ulonglong)DAT_1008e228 >> 0x30),
                                  CONCAT24((short)((ulonglong)DAT_1008e000 >> 0x20) +
                                           (short)((ulonglong)DAT_1008e228 >> 0x20),
                                           CONCAT22((short)((ulonglong)DAT_1008e000 >> 0x10) +
                                                    (short)((ulonglong)DAT_1008e228 >> 0x10),
                                                    (short)DAT_1008e000 + (short)DAT_1008e228)));
          Var38 = CONCAT28((short)((unkuint10)Var38 >> 0x40),
                           CONCAT26(uVar41 * 2,CONCAT24(uVar40 * 2,CONCAT22(uVar39 * 2,uVar37 * 2)))
                          );
          uVar15 = *(undefined8 *)(iVar8 + (extraout_EDX & 0xfffffff8));
          uVar31 = CONCAT26(-(ushort)((short)((ulonglong)uVar15 >> 0x30) == 0),
                            CONCAT24(-(ushort)((short)((ulonglong)uVar15 >> 0x20) == 0),
                                     CONCAT22(-(ushort)((short)((ulonglong)uVar15 >> 0x10) == 0),
                                              -(ushort)((short)uVar15 == 0))));
          *(ulonglong *)(iVar8 + uVar10) =
               *(ulonglong *)(iVar8 + uVar10) & uVar31 |
               ~uVar31 & (uVar20 | CONCAT26((ushort)(uVar25 >> 0x33),
                                            CONCAT24((ushort)(uVar25 >> 0x20) >> 3,
                                                     CONCAT22((ushort)(uVar25 >> 0x10) >> 3,
                                                              (ushort)uVar25 >> 3))) |
                         CONCAT26((ushort)(uVar27 >> 0x39),
                                  CONCAT24((ushort)(uVar27 >> 0x20) >> 9,
                                           CONCAT22((ushort)(uVar27 >> 0x10) >> 9,
                                                    (ushort)uVar27 >> 9))));
          iVar11 = iVar8 + 8;
          bVar1 = iVar8 < -8;
          iVar8 = iVar11;
          uVar21 = (short)((unkuint10)extraout_ST1 >> 0x40);
          fVar2 = _DAT_1008d440;
          fVar3 = _DAT_1008d448;
          fVar4 = _DAT_1008d450;
          fVar5 = _DAT_1008d458;
          fVar6 = _DAT_1008d460;
          fVar7 = _DAT_1008d468;
        } while (iVar11 == 0 || bVar1);
      }
      _DAT_1008d468 = fVar7;
      _DAT_1008d460 = fVar6;
      _DAT_1008d458 = fVar5;
      _DAT_1008d450 = fVar4;
      _DAT_1008d448 = fVar3;
      _DAT_1008d440 = fVar2;
      DAT_1008d294 = DAT_1008d298 + DAT_1008d294;
      DAT_1008d290 = DAT_1008d290 + -1;
    } while (DAT_1008d290 != 0);
    return;
  }
  uVar18 = CONCAT22((ushort)DAT_1008d2a8 << 3,(ushort)DAT_1008d2a8 << 3);
  uVar20 = CONCAT44(uVar18,uVar18);
  _DAT_1008e1c0 = psllw(uVar20,4);
  DAT_1008e1c8 = psllw(uVar20 ^ _DAT_1008e018,4);
  iVar8 = DAT_1008d2d4 + (DAT_1008d2d4 & 0x8000) * 2;
  iVar11 = DAT_1008d2e0 + (DAT_1008d2e0 & 0x8000) * 2;
  sVar16 = (short)((uint)iVar8 >> 0x10);
  sVar13 = (short)iVar8;
  sVar28 = (short)((uint)iVar11 >> 0x10);
  sVar22 = (short)iVar11;
  uVar18 = (undefined4)(CONCAT46(CONCAT22(uVar19,sVar16),CONCAT24(sVar16,iVar8)) >> 0x20);
  uVar15 = CONCAT44(uVar18,uVar18);
  uVar18 = (undefined4)
           (CONCAT46(CONCAT22((short)((unkuint10)in_ST2 >> 0x40),sVar28),CONCAT24(sVar28,iVar11)) >>
           0x20);
  uVar24 = CONCAT44(uVar18,uVar18);
  uVar33 = psraw(uVar15,0xf);
  uVar15 = pmulhw(uVar15,_DAT_1008e1c0);
  DAT_1008e218 = psllw(CONCAT26((short)((ulonglong)uVar15 >> 0x30) -
                                (short)((ulonglong)uVar33 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar15 >> 0x20) -
                                         (short)((ulonglong)uVar33 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar15 >> 0x10) -
                                                  (short)((ulonglong)uVar33 >> 0x10),
                                                  (short)uVar15 - (short)uVar33))),5);
  uVar15 = CONCAT44(CONCAT22(sVar22,sVar22),CONCAT22(sVar22,sVar22));
  uVar33 = psraw(uVar15,0xf);
  uVar15 = pmulhw(uVar15,_DAT_1008e1c0);
  DAT_1008e228 = psllw(CONCAT26((short)((ulonglong)uVar15 >> 0x30) -
                                (short)((ulonglong)uVar33 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar15 >> 0x20) -
                                         (short)((ulonglong)uVar33 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar15 >> 0x10) -
                                                  (short)((ulonglong)uVar33 >> 0x10),
                                                  (short)uVar15 - (short)uVar33))),5);
  DAT_1008e200 = CONCAT26(sVar16 * sVar29,
                          CONCAT24(sVar16 * sVar23,CONCAT22(sVar16 * sVar17,sVar16 * sVar14)));
  uVar33 = psraw(uVar24,0xf);
  uVar15 = CONCAT44(CONCAT22(sVar13,sVar13),CONCAT22(sVar13,sVar13));
  uVar24 = pmulhw(uVar24,_DAT_1008e1c0);
  DAT_1008e210 = CONCAT26(sVar22 * sVar29,
                          CONCAT24(sVar22 * sVar23,CONCAT22(sVar22 * sVar17,sVar22 * sVar14)));
  DAT_1008e240 = psllw(CONCAT26((short)((ulonglong)uVar24 >> 0x30) -
                                (short)((ulonglong)uVar33 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar24 >> 0x20) -
                                         (short)((ulonglong)uVar33 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar24 >> 0x10) -
                                                  (short)((ulonglong)uVar33 >> 0x10),
                                                  (short)uVar24 - (short)uVar33))),5);
  DAT_1008e208 = CONCAT26(sVar13 * sVar29,
                          CONCAT24(sVar13 * sVar23,CONCAT22(sVar13 * sVar17,sVar13 * sVar14)));
  DAT_1008e238 = CONCAT26(sVar28 * sVar29,
                          CONCAT24(sVar28 * sVar23,CONCAT22(sVar28 * sVar17,sVar28 * sVar14)));
  uVar33 = psraw(uVar15,0xf);
  uVar15 = pmulhw(uVar15,_DAT_1008e1c0);
  DAT_1008e220 = psllw(CONCAT26((short)((ulonglong)uVar15 >> 0x30) -
                                (short)((ulonglong)uVar33 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar15 >> 0x20) -
                                         (short)((ulonglong)uVar33 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar15 >> 0x10) -
                                                  (short)((ulonglong)uVar33 >> 0x10),
                                                  (short)uVar15 - (short)uVar33))),5);
  do {
    iVar8 = DAT_1008d294;
    DAT_1008d2cc = DAT_1008d2cc + DAT_1008d2d0;
    DAT_1008d2d8 = DAT_1008d2d8 + DAT_1008d2dc;
    DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar9 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    fVar2 = _DAT_1008d440 + _DAT_1008d444;
    fVar3 = _DAT_1008d448 + _DAT_1008d44c;
    fVar4 = _DAT_1008d450 + _DAT_1008d454;
    fVar5 = _DAT_1008d458 + _DAT_1008d45c;
    fVar6 = _DAT_1008d460 + _DAT_1008d464;
    fVar7 = _DAT_1008d468 + _DAT_1008d46c;
    if (uVar9 < DAT_1008d284 >> 0x10) {
      FUN_1007d650(uVar9 - (DAT_1008d284 >> 0x10));
      iVar11 = DAT_1008d2cc;
      iVar12 = DAT_1008d2d8;
      for (uVar10 = uVar9 & 6; uVar10 != 0; uVar10 = uVar10 - 2) {
        iVar11 = iVar11 - DAT_1008d2d4;
        iVar12 = iVar12 - DAT_1008d2e0;
      }
      sVar17 = (short)((uint)iVar11 >> 0x10);
      sVar14 = (short)iVar11;
      sVar29 = (short)((uint)iVar12 >> 0x10);
      sVar23 = (short)iVar12;
      uVar15 = pmulhw(CONCAT26(sVar17 + (short)((ulonglong)DAT_1008e200 >> 0x30),
                               CONCAT24(sVar17 + (short)((ulonglong)DAT_1008e200 >> 0x20),
                                        CONCAT22(sVar17 + (short)((ulonglong)DAT_1008e200 >> 0x10),
                                                 sVar17 + (short)DAT_1008e200))),_DAT_1008e1c0);
      uVar33 = pmulhw(CONCAT26(sVar14 + (short)((ulonglong)DAT_1008e208 >> 0x30),
                               CONCAT24(sVar14 + (short)((ulonglong)DAT_1008e208 >> 0x20),
                                        CONCAT22(sVar14 + (short)((ulonglong)DAT_1008e208 >> 0x10),
                                                 sVar14 + (short)DAT_1008e208))),_DAT_1008e1c0);
      uVar24 = pmulhw(CONCAT26(sVar23 + (short)((ulonglong)DAT_1008e210 >> 0x30),
                               CONCAT24(sVar23 + (short)((ulonglong)DAT_1008e210 >> 0x20),
                                        CONCAT22(sVar23 + (short)((ulonglong)DAT_1008e210 >> 0x10),
                                                 sVar23 + (short)DAT_1008e210))),_DAT_1008e1c0);
      uVar26 = pmulhw(CONCAT26(sVar29 + (short)((ulonglong)DAT_1008e238 >> 0x30),
                               CONCAT24(sVar29 + (short)((ulonglong)DAT_1008e238 >> 0x20),
                                        CONCAT22(sVar29 + (short)((ulonglong)DAT_1008e238 >> 0x10),
                                                 sVar29 + (short)DAT_1008e238))),_DAT_1008e1c0);
      DAT_1008dff0 = psllw(uVar15,3);
      DAT_1008dff8 = psllw(uVar33,3);
      DAT_1008e000 = psllw(uVar24,3);
      DAT_1008e230 = psllw(uVar26,3);
      uVar10 = iVar8 - 2U & 0xfffffff8;
      Var38 = CONCAT28(uVar21,DAT_1008e260);
      iVar8 = (uVar9 & 0xfffffff8) - uVar10;
      do {
        uVar15 = *(undefined8 *)(iVar8 + uVar10);
        uVar27 = (ulonglong)Var38;
        uVar33 = pmulhw(CONCAT26((ushort)((ulonglong)uVar15 >> 0x31),
                                 CONCAT24((ushort)((ulonglong)uVar15 >> 0x20) >> 1,
                                          CONCAT22((ushort)((ulonglong)uVar15 >> 0x10) >> 1,
                                                   (ushort)uVar15 >> 1))) & uVar27,DAT_1008e1c8);
        uVar25 = psllw(uVar15,10);
        uVar20 = psllw(uVar15,4);
        uVar26 = pmulhw(uVar25 & uVar27,DAT_1008e1c8);
        uVar24 = pmulhw(uVar20 & uVar27,DAT_1008e1c8);
        uVar15 = *(undefined8 *)(iVar8 + (extraout_EDX_00 & 0xfffffff8));
        uVar30 = psllw(DAT_1008dbe8,10);
        uVar34 = pmulhw(uVar30,DAT_1008e230);
        uVar30 = pmulhw(CONCAT26((ushort)((ulonglong)uVar15 >> 0x31),
                                 CONCAT24((ushort)((ulonglong)uVar15 >> 0x20) >> 1,
                                          CONCAT22((ushort)((ulonglong)uVar15 >> 0x10) >> 1,
                                                   (ushort)uVar15 >> 1))) & uVar27,DAT_1008dff0);
        uVar25 = psllw(uVar15,10);
        uVar32 = psllw(DAT_1008dbf8,10);
        uVar20 = psllw(uVar15,4);
        uVar35 = pmulhw(uVar32,DAT_1008e230);
        uVar32 = pmulhw(uVar25 & uVar27,DAT_1008e000);
        uVar15 = pmulhw(uVar20 & uVar27,DAT_1008dff8);
        uVar37 = (ushort)Var38 >> 1;
        uVar39 = (ushort)((unkuint10)Var38 >> 0x10) >> 1;
        uVar40 = (ushort)((unkuint10)Var38 >> 0x20) >> 1;
        uVar41 = (ushort)((unkuint10)Var38 >> 0x30) >> 1;
        uVar20 = CONCAT26(uVar41,CONCAT24(uVar40,CONCAT22(uVar39,uVar37)));
        uVar36 = psllw(DAT_1008dbf0,10);
        uVar36 = pmulhw(uVar36,DAT_1008e230);
        DAT_1008dff0 = CONCAT26((short)((ulonglong)DAT_1008dff0 >> 0x30) +
                                (short)((ulonglong)DAT_1008e218 >> 0x30),
                                CONCAT24((short)((ulonglong)DAT_1008dff0 >> 0x20) +
                                         (short)((ulonglong)DAT_1008e218 >> 0x20),
                                         CONCAT22((short)((ulonglong)DAT_1008dff0 >> 0x10) +
                                                  (short)((ulonglong)DAT_1008e218 >> 0x10),
                                                  (short)DAT_1008dff0 + (short)DAT_1008e218)));
        DAT_1008dff8 = CONCAT26((short)((ulonglong)DAT_1008dff8 >> 0x30) +
                                (short)((ulonglong)DAT_1008e220 >> 0x30),
                                CONCAT24((short)((ulonglong)DAT_1008dff8 >> 0x20) +
                                         (short)((ulonglong)DAT_1008e220 >> 0x20),
                                         CONCAT22((short)((ulonglong)DAT_1008dff8 >> 0x10) +
                                                  (short)((ulonglong)DAT_1008e220 >> 0x10),
                                                  (short)DAT_1008dff8 + (short)DAT_1008e220)));
        uVar25 = CONCAT26((short)((ulonglong)uVar24 >> 0x30) +
                          (short)((ulonglong)uVar15 >> 0x30) + (short)((ulonglong)uVar36 >> 0x30),
                          CONCAT24((short)((ulonglong)uVar24 >> 0x20) +
                                   (short)((ulonglong)uVar15 >> 0x20) +
                                   (short)((ulonglong)uVar36 >> 0x20),
                                   CONCAT22((short)((ulonglong)uVar24 >> 0x10) +
                                            (short)((ulonglong)uVar15 >> 0x10) +
                                            (short)((ulonglong)uVar36 >> 0x10),
                                            (short)uVar24 + (short)uVar15 + (short)uVar36))) &
                 uVar20;
        uVar27 = CONCAT26((short)((ulonglong)uVar26 >> 0x30) +
                          (short)((ulonglong)uVar32 >> 0x30) + (short)((ulonglong)uVar35 >> 0x30),
                          CONCAT24((short)((ulonglong)uVar26 >> 0x20) +
                                   (short)((ulonglong)uVar32 >> 0x20) +
                                   (short)((ulonglong)uVar35 >> 0x20),
                                   CONCAT22((short)((ulonglong)uVar26 >> 0x10) +
                                            (short)((ulonglong)uVar32 >> 0x10) +
                                            (short)((ulonglong)uVar35 >> 0x10),
                                            (short)uVar26 + (short)uVar32 + (short)uVar35))) &
                 uVar20;
        uVar20 = psllw(CONCAT26((short)((ulonglong)uVar33 >> 0x30) +
                                (short)((ulonglong)uVar30 >> 0x30) +
                                (short)((ulonglong)uVar34 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar33 >> 0x20) +
                                         (short)((ulonglong)uVar30 >> 0x20) +
                                         (short)((ulonglong)uVar34 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar33 >> 0x10) +
                                                  (short)((ulonglong)uVar30 >> 0x10) +
                                                  (short)((ulonglong)uVar34 >> 0x10),
                                                  (short)uVar33 + (short)uVar30 + (short)uVar34))) &
                       uVar20,2);
        DAT_1008e000 = CONCAT26((short)((ulonglong)DAT_1008e000 >> 0x30) +
                                (short)((ulonglong)DAT_1008e228 >> 0x30),
                                CONCAT24((short)((ulonglong)DAT_1008e000 >> 0x20) +
                                         (short)((ulonglong)DAT_1008e228 >> 0x20),
                                         CONCAT22((short)((ulonglong)DAT_1008e000 >> 0x10) +
                                                  (short)((ulonglong)DAT_1008e228 >> 0x10),
                                                  (short)DAT_1008e000 + (short)DAT_1008e228)));
        DAT_1008e230 = CONCAT26((short)((ulonglong)DAT_1008e230 >> 0x30) +
                                (short)((ulonglong)DAT_1008e240 >> 0x30),
                                CONCAT24((short)((ulonglong)DAT_1008e230 >> 0x20) +
                                         (short)((ulonglong)DAT_1008e240 >> 0x20),
                                         CONCAT22((short)((ulonglong)DAT_1008e230 >> 0x10) +
                                                  (short)((ulonglong)DAT_1008e240 >> 0x10),
                                                  (short)DAT_1008e230 + (short)DAT_1008e240)));
        Var38 = CONCAT28((short)((unkuint10)Var38 >> 0x40),
                         CONCAT26(uVar41 * 2,CONCAT24(uVar40 * 2,CONCAT22(uVar39 * 2,uVar37 * 2))));
        uVar15 = *(undefined8 *)(iVar8 + (extraout_EDX_00 & 0xfffffff8));
        uVar31 = CONCAT26(-(ushort)((short)((ulonglong)uVar15 >> 0x30) == 0),
                          CONCAT24(-(ushort)((short)((ulonglong)uVar15 >> 0x20) == 0),
                                   CONCAT22(-(ushort)((short)((ulonglong)uVar15 >> 0x10) == 0),
                                            -(ushort)((short)uVar15 == 0))));
        *(ulonglong *)(iVar8 + uVar10) =
             *(ulonglong *)(iVar8 + uVar10) & uVar31 |
             ~uVar31 & (uVar20 | CONCAT26((ushort)(uVar25 >> 0x33),
                                          CONCAT24((ushort)(uVar25 >> 0x20) >> 3,
                                                   CONCAT22((ushort)(uVar25 >> 0x10) >> 3,
                                                            (ushort)uVar25 >> 3))) |
                       CONCAT26((ushort)(uVar27 >> 0x39),
                                CONCAT24((ushort)(uVar27 >> 0x20) >> 9,
                                         CONCAT22((ushort)(uVar27 >> 0x10) >> 9,(ushort)uVar27 >> 9)
                                        )));
        iVar11 = iVar8 + 8;
        bVar1 = iVar8 < -8;
        iVar8 = iVar11;
        uVar21 = (short)((unkuint10)extraout_ST1_00 >> 0x40);
        fVar2 = _DAT_1008d440;
        fVar3 = _DAT_1008d448;
        fVar4 = _DAT_1008d450;
        fVar5 = _DAT_1008d458;
        fVar6 = _DAT_1008d460;
        fVar7 = _DAT_1008d468;
      } while (iVar11 == 0 || bVar1);
    }
    _DAT_1008d468 = fVar7;
    _DAT_1008d460 = fVar6;
    _DAT_1008d458 = fVar5;
    _DAT_1008d450 = fVar4;
    _DAT_1008d448 = fVar3;
    _DAT_1008d440 = fVar2;
    DAT_1008d294 = DAT_1008d298 + DAT_1008d294;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


