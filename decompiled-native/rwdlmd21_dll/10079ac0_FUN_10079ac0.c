// 10079ac0 FUN_10079ac0 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_10079ac0(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint extraout_EDX;
  uint extraout_EDX_00;
  int iVar5;
  int iVar6;
  uint uVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar12;
  short sVar13;
  undefined4 uVar14;
  undefined8 uVar11;
  ulonglong uVar15;
  short sVar16;
  short sVar21;
  short sVar22;
  undefined8 uVar17;
  ulonglong uVar18;
  undefined8 uVar19;
  ulonglong uVar20;
  undefined4 uVar23;
  undefined8 uVar24;
  ulonglong uVar25;
  undefined8 uVar26;
  ulonglong uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  undefined8 uVar31;
  ushort uVar32;
  ushort uVar33;
  ushort uVar34;
  ushort uVar35;
  
  sVar10 = (short)DAT_1008e188;
  sVar9 = (short)((ulonglong)DAT_1008e188 >> 0x10);
  sVar13 = (short)((ulonglong)DAT_1008e188 >> 0x20);
  sVar22 = (short)((ulonglong)DAT_1008e188 >> 0x30);
  if ((int)DAT_1008dbe0 != 0) {
    uVar14 = CONCAT22((ushort)DAT_1008d2a8 << 3,(ushort)DAT_1008d2a8 << 3);
    uVar27 = CONCAT44(uVar14,uVar14);
    _DAT_1008e1c0 = psllw(uVar27,4);
    DAT_1008e1c8 = psllw(uVar27 ^ _DAT_1008e018,4);
    iVar2 = DAT_1008d2d4 + (DAT_1008d2d4 & 0x8000) * 2;
    iVar5 = DAT_1008d2e0 + (DAT_1008d2e0 & 0x8000) * 2;
    sVar12 = (short)((uint)iVar2 >> 0x10);
    sVar8 = (short)iVar2;
    uVar14 = (undefined4)(CONCAT26(sVar12,CONCAT24(sVar12,iVar2)) >> 0x20);
    sVar21 = (short)((uint)iVar5 >> 0x10);
    sVar16 = (short)iVar5;
    uVar23 = (undefined4)(CONCAT26(sVar21,CONCAT24(sVar21,iVar5)) >> 0x20);
    uVar11 = CONCAT44(uVar14,uVar14);
    uVar17 = CONCAT44(uVar23,uVar23);
    uVar28 = psraw(uVar11,0xf);
    uVar11 = pmulhw(uVar11,_DAT_1008e1c0);
    DAT_1008e218 = psllw(CONCAT26((short)((ulonglong)uVar11 >> 0x30) -
                                  (short)((ulonglong)uVar28 >> 0x30),
                                  CONCAT24((short)((ulonglong)uVar11 >> 0x20) -
                                           (short)((ulonglong)uVar28 >> 0x20),
                                           CONCAT22((short)((ulonglong)uVar11 >> 0x10) -
                                                    (short)((ulonglong)uVar28 >> 0x10),
                                                    (short)uVar11 - (short)uVar28))),5);
    uVar11 = CONCAT44(CONCAT22(sVar16,sVar16),CONCAT22(sVar16,sVar16));
    uVar28 = psraw(uVar11,0xf);
    uVar11 = pmulhw(uVar11,_DAT_1008e1c0);
    DAT_1008e228 = psllw(CONCAT26((short)((ulonglong)uVar11 >> 0x30) -
                                  (short)((ulonglong)uVar28 >> 0x30),
                                  CONCAT24((short)((ulonglong)uVar11 >> 0x20) -
                                           (short)((ulonglong)uVar28 >> 0x20),
                                           CONCAT22((short)((ulonglong)uVar11 >> 0x10) -
                                                    (short)((ulonglong)uVar28 >> 0x10),
                                                    (short)uVar11 - (short)uVar28))),5);
    DAT_1008e200 = CONCAT26(sVar12 * sVar22,
                            CONCAT24(sVar12 * sVar13,CONCAT22(sVar12 * sVar9,sVar12 * sVar10)));
    uVar28 = psraw(uVar17,0xf);
    uVar11 = CONCAT44(CONCAT22(sVar8,sVar8),CONCAT22(sVar8,sVar8));
    uVar17 = pmulhw(uVar17,_DAT_1008e1c0);
    DAT_1008e210 = CONCAT26(sVar16 * sVar22,
                            CONCAT24(sVar16 * sVar13,CONCAT22(sVar16 * sVar9,sVar16 * sVar10)));
    DAT_1008e240 = psllw(CONCAT26((short)((ulonglong)uVar17 >> 0x30) -
                                  (short)((ulonglong)uVar28 >> 0x30),
                                  CONCAT24((short)((ulonglong)uVar17 >> 0x20) -
                                           (short)((ulonglong)uVar28 >> 0x20),
                                           CONCAT22((short)((ulonglong)uVar17 >> 0x10) -
                                                    (short)((ulonglong)uVar28 >> 0x10),
                                                    (short)uVar17 - (short)uVar28))),5);
    DAT_1008e208 = CONCAT26(sVar8 * sVar22,
                            CONCAT24(sVar8 * sVar13,CONCAT22(sVar8 * sVar9,sVar8 * sVar10)));
    DAT_1008e238 = CONCAT26(sVar21 * sVar22,
                            CONCAT24(sVar21 * sVar13,CONCAT22(sVar21 * sVar9,sVar21 * sVar10)));
    uVar28 = psraw(uVar11,0xf);
    uVar11 = pmulhw(uVar11,_DAT_1008e1c0);
    DAT_1008e220 = psllw(CONCAT26((short)((ulonglong)uVar11 >> 0x30) -
                                  (short)((ulonglong)uVar28 >> 0x30),
                                  CONCAT24((short)((ulonglong)uVar11 >> 0x20) -
                                           (short)((ulonglong)uVar28 >> 0x20),
                                           CONCAT22((short)((ulonglong)uVar11 >> 0x10) -
                                                    (short)((ulonglong)uVar28 >> 0x10),
                                                    (short)uVar11 - (short)uVar28))),5);
    do {
      iVar2 = DAT_1008d294;
      DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0 & 0x7fff7fff;
      DAT_1008d2cc = DAT_1008d2cc + DAT_1008d2d0;
      DAT_1008d2d8 = DAT_1008d2d8 + DAT_1008d2dc;
      DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
      uVar4 = DAT_1008d280 >> 0x10;
      DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
      uVar3 = DAT_1008d284 >> 0x10;
      if (uVar4 < uVar3) {
        FUN_100780dd(uVar4 - uVar3);
        iVar5 = DAT_1008d2cc;
        iVar6 = DAT_1008d2d8;
        for (uVar3 = uVar4 & 6; uVar3 != 0; uVar3 = uVar3 - 2) {
          iVar5 = iVar5 - DAT_1008d2d4;
          iVar6 = iVar6 - DAT_1008d2e0;
        }
        sVar9 = (short)((uint)iVar5 >> 0x10);
        sVar10 = (short)iVar5;
        sVar22 = (short)((uint)iVar6 >> 0x10);
        sVar13 = (short)iVar6;
        uVar11 = pmulhw(CONCAT26(sVar9 + (short)((ulonglong)DAT_1008e200 >> 0x30),
                                 CONCAT24(sVar9 + (short)((ulonglong)DAT_1008e200 >> 0x20),
                                          CONCAT22(sVar9 + (short)((ulonglong)DAT_1008e200 >> 0x10),
                                                   sVar9 + (short)DAT_1008e200))),_DAT_1008e1c0);
        uVar28 = pmulhw(CONCAT26(sVar10 + (short)((ulonglong)DAT_1008e208 >> 0x30),
                                 CONCAT24(sVar10 + (short)((ulonglong)DAT_1008e208 >> 0x20),
                                          CONCAT22(sVar10 + (short)((ulonglong)DAT_1008e208 >> 0x10)
                                                   ,sVar10 + (short)DAT_1008e208))),_DAT_1008e1c0);
        uVar17 = pmulhw(CONCAT26(sVar13 + (short)((ulonglong)DAT_1008e210 >> 0x30),
                                 CONCAT24(sVar13 + (short)((ulonglong)DAT_1008e210 >> 0x20),
                                          CONCAT22(sVar13 + (short)((ulonglong)DAT_1008e210 >> 0x10)
                                                   ,sVar13 + (short)DAT_1008e210))),_DAT_1008e1c0);
        uVar19 = pmulhw(CONCAT26(sVar22 + (short)((ulonglong)DAT_1008e238 >> 0x30),
                                 CONCAT24(sVar22 + (short)((ulonglong)DAT_1008e238 >> 0x20),
                                          CONCAT22(sVar22 + (short)((ulonglong)DAT_1008e238 >> 0x10)
                                                   ,sVar22 + (short)DAT_1008e238))),_DAT_1008e1c0);
        DAT_1008dff0 = psllw(uVar11,3);
        DAT_1008dff8 = psllw(uVar28,3);
        DAT_1008e000 = psllw(uVar17,3);
        DAT_1008e230 = psllw(uVar19,3);
        uVar7 = iVar2 - 2U & 0xfffffff8;
        iVar2 = (uVar4 & 0xfffffff8) - uVar7;
        uVar27 = DAT_1008e260;
        do {
          uVar11 = *(undefined8 *)(iVar2 + uVar7);
          uVar28 = pmulhw(CONCAT26((ushort)((ulonglong)uVar11 >> 0x31),
                                   CONCAT24((ushort)((ulonglong)uVar11 >> 0x20) >> 1,
                                            CONCAT22((ushort)((ulonglong)uVar11 >> 0x10) >> 1,
                                                     (ushort)uVar11 >> 1))) & uVar27,DAT_1008e1c8);
          uVar18 = psllw(uVar11,10);
          uVar15 = psllw(uVar11,4);
          uVar19 = pmulhw(uVar18 & uVar27,DAT_1008e1c8);
          uVar17 = pmulhw(uVar15 & uVar27,DAT_1008e1c8);
          uVar11 = *(undefined8 *)(iVar2 + (extraout_EDX_00 & 0xfffffff8));
          uVar24 = psllw(DAT_1008dbe8,10);
          uVar29 = pmulhw(uVar24,DAT_1008e230);
          uVar24 = pmulhw(CONCAT26((ushort)((ulonglong)uVar11 >> 0x31),
                                   CONCAT24((ushort)((ulonglong)uVar11 >> 0x20) >> 1,
                                            CONCAT22((ushort)((ulonglong)uVar11 >> 0x10) >> 1,
                                                     (ushort)uVar11 >> 1))) & uVar27,DAT_1008dff0);
          uVar18 = psllw(uVar11,10);
          uVar26 = psllw(DAT_1008dbf8,10);
          uVar15 = psllw(uVar11,4);
          uVar30 = pmulhw(uVar26,DAT_1008e230);
          uVar26 = pmulhw(uVar18 & uVar27,DAT_1008e000);
          uVar11 = pmulhw(uVar15 & uVar27,DAT_1008dff8);
          uVar32 = (ushort)uVar27 >> 1;
          uVar33 = (ushort)(uVar27 >> 0x10) >> 1;
          uVar34 = (ushort)(uVar27 >> 0x20) >> 1;
          uVar35 = (ushort)(uVar27 >> 0x31);
          uVar27 = CONCAT26(uVar35,CONCAT24(uVar34,CONCAT22(uVar33,uVar32)));
          uVar31 = psllw(DAT_1008dbf0,10);
          uVar31 = pmulhw(uVar31,DAT_1008e230);
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
          uVar18 = CONCAT26((short)((ulonglong)uVar17 >> 0x30) +
                            (short)((ulonglong)uVar11 >> 0x30) + (short)((ulonglong)uVar31 >> 0x30),
                            CONCAT24((short)((ulonglong)uVar17 >> 0x20) +
                                     (short)((ulonglong)uVar11 >> 0x20) +
                                     (short)((ulonglong)uVar31 >> 0x20),
                                     CONCAT22((short)((ulonglong)uVar17 >> 0x10) +
                                              (short)((ulonglong)uVar11 >> 0x10) +
                                              (short)((ulonglong)uVar31 >> 0x10),
                                              (short)uVar17 + (short)uVar11 + (short)uVar31))) &
                   uVar27;
          uVar20 = CONCAT26((short)((ulonglong)uVar19 >> 0x30) +
                            (short)((ulonglong)uVar26 >> 0x30) + (short)((ulonglong)uVar30 >> 0x30),
                            CONCAT24((short)((ulonglong)uVar19 >> 0x20) +
                                     (short)((ulonglong)uVar26 >> 0x20) +
                                     (short)((ulonglong)uVar30 >> 0x20),
                                     CONCAT22((short)((ulonglong)uVar19 >> 0x10) +
                                              (short)((ulonglong)uVar26 >> 0x10) +
                                              (short)((ulonglong)uVar30 >> 0x10),
                                              (short)uVar19 + (short)uVar26 + (short)uVar30))) &
                   uVar27;
          uVar15 = psllw(CONCAT26((short)((ulonglong)uVar28 >> 0x30) +
                                  (short)((ulonglong)uVar24 >> 0x30) +
                                  (short)((ulonglong)uVar29 >> 0x30),
                                  CONCAT24((short)((ulonglong)uVar28 >> 0x20) +
                                           (short)((ulonglong)uVar24 >> 0x20) +
                                           (short)((ulonglong)uVar29 >> 0x20),
                                           CONCAT22((short)((ulonglong)uVar28 >> 0x10) +
                                                    (short)((ulonglong)uVar24 >> 0x10) +
                                                    (short)((ulonglong)uVar29 >> 0x10),
                                                    (short)uVar28 + (short)uVar24 + (short)uVar29)))
                         & uVar27,2);
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
          uVar27 = CONCAT26(uVar35 * 2,CONCAT24(uVar34 * 2,CONCAT22(uVar33 * 2,uVar32 * 2)));
          uVar11 = *(undefined8 *)(iVar2 + (extraout_EDX_00 & 0xfffffff8));
          uVar25 = CONCAT26(-(ushort)((short)((ulonglong)uVar11 >> 0x30) == 0),
                            CONCAT24(-(ushort)((short)((ulonglong)uVar11 >> 0x20) == 0),
                                     CONCAT22(-(ushort)((short)((ulonglong)uVar11 >> 0x10) == 0),
                                              -(ushort)((short)uVar11 == 0))));
          *(ulonglong *)(iVar2 + uVar7) =
               *(ulonglong *)(iVar2 + uVar7) & uVar25 |
               ~uVar25 & (uVar15 | CONCAT26((ushort)(uVar18 >> 0x33),
                                            CONCAT24((ushort)(uVar18 >> 0x20) >> 3,
                                                     CONCAT22((ushort)(uVar18 >> 0x10) >> 3,
                                                              (ushort)uVar18 >> 3))) |
                         CONCAT26((ushort)(uVar20 >> 0x39),
                                  CONCAT24((ushort)(uVar20 >> 0x20) >> 9,
                                           CONCAT22((ushort)(uVar20 >> 0x10) >> 9,
                                                    (ushort)uVar20 >> 9))));
          iVar5 = iVar2 + 8;
          bVar1 = iVar2 < -8;
          uVar3 = uVar4;
          iVar2 = iVar5;
        } while (iVar5 == 0 || bVar1);
      }
      DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
      DAT_1008d290 = DAT_1008d290 + -1;
    } while (DAT_1008d290 != 0);
    return CONCAT44(param_2,uVar3);
  }
  uVar14 = CONCAT22((ushort)DAT_1008d2a8 << 3,(ushort)DAT_1008d2a8 << 3);
  uVar27 = CONCAT44(uVar14,uVar14);
  _DAT_1008e1c0 = psllw(uVar27,4);
  DAT_1008e1c8 = psllw(uVar27 ^ _DAT_1008e018,4);
  iVar2 = DAT_1008d2d4 + (DAT_1008d2d4 & 0x8000) * 2;
  sVar12 = (short)((uint)iVar2 >> 0x10);
  sVar8 = (short)iVar2;
  uVar14 = (undefined4)(CONCAT26(sVar12,CONCAT24(sVar12,iVar2)) >> 0x20);
  sVar16 = (short)DAT_1008d2e0;
  uVar11 = CONCAT44(uVar14,uVar14);
  uVar28 = psraw(uVar11,0xf);
  uVar11 = pmulhw(uVar11,_DAT_1008e1c0);
  DAT_1008e218 = psllw(CONCAT26((short)((ulonglong)uVar11 >> 0x30) -
                                (short)((ulonglong)uVar28 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar11 >> 0x20) -
                                         (short)((ulonglong)uVar28 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar11 >> 0x10) -
                                                  (short)((ulonglong)uVar28 >> 0x10),
                                                  (short)uVar11 - (short)uVar28))),5);
  uVar11 = CONCAT44(CONCAT22(sVar16,sVar16),CONCAT22(sVar16,sVar16));
  uVar28 = psraw(uVar11,0xf);
  uVar11 = pmulhw(uVar11,_DAT_1008e1c0);
  DAT_1008e228 = psllw(CONCAT26((short)((ulonglong)uVar11 >> 0x30) -
                                (short)((ulonglong)uVar28 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar11 >> 0x20) -
                                         (short)((ulonglong)uVar28 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar11 >> 0x10) -
                                                  (short)((ulonglong)uVar28 >> 0x10),
                                                  (short)uVar11 - (short)uVar28))),5);
  DAT_1008e200 = CONCAT26(sVar12 * sVar22,
                          CONCAT24(sVar12 * sVar13,CONCAT22(sVar12 * sVar9,sVar12 * sVar10)));
  uVar11 = CONCAT44(CONCAT22(sVar8,sVar8),CONCAT22(sVar8,sVar8));
  DAT_1008e210 = CONCAT26(sVar16 * sVar22,
                          CONCAT24(sVar16 * sVar13,CONCAT22(sVar16 * sVar9,sVar16 * sVar10)));
  DAT_1008e208 = CONCAT26(sVar8 * sVar22,
                          CONCAT24(sVar8 * sVar13,CONCAT22(sVar8 * sVar9,sVar8 * sVar10)));
  uVar28 = psraw(uVar11,0xf);
  uVar11 = pmulhw(uVar11,_DAT_1008e1c0);
  DAT_1008e220 = psllw(CONCAT26((short)((ulonglong)uVar11 >> 0x30) -
                                (short)((ulonglong)uVar28 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar11 >> 0x20) -
                                         (short)((ulonglong)uVar28 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar11 >> 0x10) -
                                                  (short)((ulonglong)uVar28 >> 0x10),
                                                  (short)uVar11 - (short)uVar28))),5);
  do {
    iVar2 = DAT_1008d294;
    DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0 & 0x7fff7fff;
    DAT_1008d2cc = DAT_1008d2cc + DAT_1008d2d0;
    DAT_1008d2d8 = DAT_1008d2d8 + DAT_1008d2dc;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar4 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    uVar3 = DAT_1008d284 >> 0x10;
    if (uVar4 < uVar3) {
      FUN_100780dd(uVar4 - uVar3);
      sVar10 = (short)DAT_1008d2d8;
      iVar5 = DAT_1008d2cc;
      iVar6 = DAT_1008d2d8;
      for (uVar3 = uVar4 & 6; uVar3 != 0; uVar3 = uVar3 - 2) {
        sVar10 = (short)(iVar6 - DAT_1008d2e0);
        iVar5 = iVar5 - DAT_1008d2d4;
        iVar6 = iVar6 - DAT_1008d2e0;
      }
      sVar13 = (short)((uint)iVar5 >> 0x10);
      sVar9 = (short)iVar5;
      uVar11 = pmulhw(CONCAT26(sVar13 + (short)((ulonglong)DAT_1008e200 >> 0x30),
                               CONCAT24(sVar13 + (short)((ulonglong)DAT_1008e200 >> 0x20),
                                        CONCAT22(sVar13 + (short)((ulonglong)DAT_1008e200 >> 0x10),
                                                 sVar13 + (short)DAT_1008e200))),_DAT_1008e1c0);
      uVar28 = pmulhw(CONCAT26(sVar9 + (short)((ulonglong)DAT_1008e208 >> 0x30),
                               CONCAT24(sVar9 + (short)((ulonglong)DAT_1008e208 >> 0x20),
                                        CONCAT22(sVar9 + (short)((ulonglong)DAT_1008e208 >> 0x10),
                                                 sVar9 + (short)DAT_1008e208))),_DAT_1008e1c0);
      uVar17 = pmulhw(CONCAT26(sVar10 + (short)((ulonglong)DAT_1008e210 >> 0x30),
                               CONCAT24(sVar10 + (short)((ulonglong)DAT_1008e210 >> 0x20),
                                        CONCAT22(sVar10 + (short)((ulonglong)DAT_1008e210 >> 0x10),
                                                 sVar10 + (short)DAT_1008e210))),_DAT_1008e1c0);
      DAT_1008dff0 = psllw(uVar11,3);
      DAT_1008dff8 = psllw(uVar28,3);
      DAT_1008e000 = psllw(uVar17,3);
      uVar7 = iVar2 - 2U & 0xfffffff8;
      iVar2 = (uVar4 & 0xfffffff8) - uVar7;
      uVar27 = DAT_1008e260;
      do {
        uVar11 = *(undefined8 *)(iVar2 + uVar7);
        uVar28 = pmulhw(CONCAT26((ushort)((ulonglong)uVar11 >> 0x31),
                                 CONCAT24((ushort)((ulonglong)uVar11 >> 0x20) >> 1,
                                          CONCAT22((ushort)((ulonglong)uVar11 >> 0x10) >> 1,
                                                   (ushort)uVar11 >> 1))) & uVar27,DAT_1008e1c8);
        uVar18 = psllw(uVar11,10);
        uVar15 = psllw(uVar11,4);
        uVar19 = pmulhw(uVar18 & uVar27,DAT_1008e1c8);
        uVar17 = pmulhw(uVar15 & uVar27,DAT_1008e1c8);
        uVar11 = *(undefined8 *)(iVar2 + (extraout_EDX & 0xfffffff8));
        uVar24 = pmulhw(CONCAT26((ushort)((ulonglong)uVar11 >> 0x31),
                                 CONCAT24((ushort)((ulonglong)uVar11 >> 0x20) >> 1,
                                          CONCAT22((ushort)((ulonglong)uVar11 >> 0x10) >> 1,
                                                   (ushort)uVar11 >> 1))) & uVar27,DAT_1008dff0);
        uVar18 = psllw(uVar11,10);
        uVar15 = psllw(uVar11,4);
        uVar26 = pmulhw(uVar18 & uVar27,DAT_1008e000);
        uVar11 = pmulhw(uVar15 & uVar27,DAT_1008dff8);
        uVar32 = (ushort)uVar27 >> 1;
        uVar33 = (ushort)(uVar27 >> 0x10) >> 1;
        uVar34 = (ushort)(uVar27 >> 0x20) >> 1;
        uVar35 = (ushort)(uVar27 >> 0x31);
        uVar27 = CONCAT26(uVar35,CONCAT24(uVar34,CONCAT22(uVar33,uVar32)));
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
        uVar18 = CONCAT26((short)((ulonglong)uVar17 >> 0x30) + (short)((ulonglong)uVar11 >> 0x30),
                          CONCAT24((short)((ulonglong)uVar17 >> 0x20) +
                                   (short)((ulonglong)uVar11 >> 0x20),
                                   CONCAT22((short)((ulonglong)uVar17 >> 0x10) +
                                            (short)((ulonglong)uVar11 >> 0x10),
                                            (short)uVar17 + (short)uVar11))) & uVar27;
        uVar20 = CONCAT26((short)((ulonglong)uVar19 >> 0x30) + (short)((ulonglong)uVar26 >> 0x30),
                          CONCAT24((short)((ulonglong)uVar19 >> 0x20) +
                                   (short)((ulonglong)uVar26 >> 0x20),
                                   CONCAT22((short)((ulonglong)uVar19 >> 0x10) +
                                            (short)((ulonglong)uVar26 >> 0x10),
                                            (short)uVar19 + (short)uVar26))) & uVar27;
        uVar15 = psllw(CONCAT26((short)((ulonglong)uVar28 >> 0x30) +
                                (short)((ulonglong)uVar24 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar28 >> 0x20) +
                                         (short)((ulonglong)uVar24 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar28 >> 0x10) +
                                                  (short)((ulonglong)uVar24 >> 0x10),
                                                  (short)uVar28 + (short)uVar24))) & uVar27,2);
        DAT_1008e000 = CONCAT26((short)((ulonglong)DAT_1008e000 >> 0x30) +
                                (short)((ulonglong)DAT_1008e228 >> 0x30),
                                CONCAT24((short)((ulonglong)DAT_1008e000 >> 0x20) +
                                         (short)((ulonglong)DAT_1008e228 >> 0x20),
                                         CONCAT22((short)((ulonglong)DAT_1008e000 >> 0x10) +
                                                  (short)((ulonglong)DAT_1008e228 >> 0x10),
                                                  (short)DAT_1008e000 + (short)DAT_1008e228)));
        uVar27 = CONCAT26(uVar35 * 2,CONCAT24(uVar34 * 2,CONCAT22(uVar33 * 2,uVar32 * 2)));
        uVar11 = *(undefined8 *)(iVar2 + (extraout_EDX & 0xfffffff8));
        uVar25 = CONCAT26(-(ushort)((short)((ulonglong)uVar11 >> 0x30) == 0),
                          CONCAT24(-(ushort)((short)((ulonglong)uVar11 >> 0x20) == 0),
                                   CONCAT22(-(ushort)((short)((ulonglong)uVar11 >> 0x10) == 0),
                                            -(ushort)((short)uVar11 == 0))));
        *(ulonglong *)(iVar2 + uVar7) =
             *(ulonglong *)(iVar2 + uVar7) & uVar25 |
             ~uVar25 & (uVar15 | CONCAT26((ushort)(uVar18 >> 0x33),
                                          CONCAT24((ushort)(uVar18 >> 0x20) >> 3,
                                                   CONCAT22((ushort)(uVar18 >> 0x10) >> 3,
                                                            (ushort)uVar18 >> 3))) |
                       CONCAT26((ushort)(uVar20 >> 0x39),
                                CONCAT24((ushort)(uVar20 >> 0x20) >> 9,
                                         CONCAT22((ushort)(uVar20 >> 0x10) >> 9,(ushort)uVar20 >> 9)
                                        )));
        iVar5 = iVar2 + 8;
        bVar1 = iVar2 < -8;
        uVar3 = uVar4;
        iVar2 = iVar5;
      } while (iVar5 == 0 || bVar1);
    }
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return CONCAT44(param_2,uVar3);
}


