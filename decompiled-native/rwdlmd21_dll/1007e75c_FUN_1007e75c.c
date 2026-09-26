// 1007e75c FUN_1007e75c [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1007e75c(void)

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
  ulonglong uVar8;
  ushort uVar12;
  ushort uVar13;
  ushort uVar15;
  unkbyte10 in_ST0;
  undefined4 uVar14;
  undefined2 uVar16;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  ulonglong uVar17;
  ulonglong uVar18;
  unkbyte10 in_ST2;
  short sVar19;
  short sVar22;
  short sVar23;
  short sVar24;
  undefined8 uVar20;
  short sVar25;
  short sVar27;
  short sVar28;
  short sVar29;
  unkbyte10 Var26;
  short sVar30;
  short sVar32;
  short sVar33;
  short sVar34;
  short sVar35;
  unkbyte10 Var31;
  short sVar36;
  short sVar37;
  short sVar38;
  ulonglong uVar39;
  ulonglong uVar40;
  ulonglong uVar41;
  unkbyte10 Var21;
  
  uVar16 = (undefined2)((unkuint10)in_ST0 >> 0x40);
  sVar29 = (short)DAT_1008e188;
  sVar24 = (short)((ulonglong)DAT_1008e188 >> 0x10);
  sVar19 = (short)((ulonglong)DAT_1008e188 >> 0x20);
  sVar22 = (short)((ulonglong)DAT_1008e188 >> 0x30);
  if ((int)DAT_1008dbe0 == 0) {
    iVar2 = DAT_1008d2d4 + (DAT_1008d2d4 & 0x8000) * 2;
    sVar25 = (short)((uint)iVar2 >> 0x10);
    sVar23 = (short)iVar2;
    sVar27 = (short)DAT_1008d2e0;
    uVar14 = (undefined4)(CONCAT46(CONCAT22(uVar16,sVar25),CONCAT24(sVar25,iVar2)) >> 0x20);
    DAT_1008e218 = CONCAT44(uVar14,uVar14);
    DAT_1008e228 = CONCAT44(CONCAT22(sVar27,sVar27),CONCAT22(sVar27,sVar27));
    DAT_1008e200 = CONCAT26(sVar25 * sVar22,
                            CONCAT24(sVar25 * sVar19,CONCAT22(sVar25 * sVar24,sVar25 * sVar29)));
    DAT_1008e220 = CONCAT44(CONCAT22(sVar23,sVar23),CONCAT22(sVar23,sVar23));
    DAT_1008e210 = CONCAT26(sVar27 * sVar22,
                            CONCAT24(sVar27 * sVar19,CONCAT22(sVar27 * sVar24,sVar27 * sVar29)));
    DAT_1008e208 = CONCAT26(sVar23 * sVar22,
                            CONCAT24(sVar23 * sVar19,CONCAT22(sVar23 * sVar24,sVar23 * sVar29)));
    do {
      iVar2 = DAT_1008d294;
      DAT_1008d2cc = DAT_1008d2cc + DAT_1008d2d0;
      DAT_1008d2d8 = DAT_1008d2d8 + DAT_1008d2dc;
      fVar9 = (float10)_DAT_1008d468 + (float10)_DAT_1008d46c;
      fVar10 = (float10)_DAT_1008d460 + (float10)_DAT_1008d464;
      fVar11 = (float10)_DAT_1008d458 + (float10)_DAT_1008d45c;
      DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0;
      DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
      uVar3 = DAT_1008d280 >> 0x10;
      DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
      if (uVar3 < DAT_1008d284 >> 0x10) {
        FUN_1007d650(uVar3 - (DAT_1008d284 >> 0x10));
        uVar4 = uVar3 & 6;
        uVar6 = DAT_1008d2cc;
        iVar5 = DAT_1008d2d8;
        while( true ) {
          sVar29 = (short)uVar6;
          sVar24 = (short)(uVar6 >> 0x10);
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 2;
          uVar6 = (uint)(ushort)(sVar29 - (short)DAT_1008d2d4) |
                  CONCAT22(sVar29 - (short)DAT_1008d2d4,sVar24 - DAT_1008d2d4._2_2_) << 0x10;
          iVar5 = iVar5 - DAT_1008d2e0;
        }
        sVar35 = (short)iVar5;
        sVar19 = sVar24 + (short)DAT_1008e200;
        sVar22 = sVar24 + (short)((ulonglong)DAT_1008e200 >> 0x10);
        sVar23 = sVar24 + (short)((ulonglong)DAT_1008e200 >> 0x20);
        sVar24 = sVar24 + (short)((ulonglong)DAT_1008e200 >> 0x30);
        sVar25 = sVar29 + (short)DAT_1008e208;
        sVar27 = sVar29 + (short)((ulonglong)DAT_1008e208 >> 0x10);
        sVar28 = sVar29 + (short)((ulonglong)DAT_1008e208 >> 0x20);
        sVar29 = sVar29 + (short)((ulonglong)DAT_1008e208 >> 0x30);
        sVar30 = sVar35 + (short)DAT_1008e210;
        sVar32 = sVar35 + (short)((ulonglong)DAT_1008e210 >> 0x10);
        sVar33 = sVar35 + (short)((ulonglong)DAT_1008e210 >> 0x20);
        sVar35 = sVar35 + (short)((ulonglong)DAT_1008e210 >> 0x30);
        uVar8 = psraw(CONCAT26(sVar24,CONCAT24(sVar23,CONCAT22(sVar22,sVar19))),0xf);
        uVar8 = uVar8 & _DAT_1008e030;
        uVar17 = psraw(CONCAT26(sVar29,CONCAT24(sVar28,CONCAT22(sVar27,sVar25))),0xf);
        uVar17 = uVar17 & _DAT_1008e030;
        uVar18 = psraw(CONCAT26(sVar35,CONCAT24(sVar33,CONCAT22(sVar32,sVar30))),0xf);
        uVar18 = uVar18 & _DAT_1008e030;
        uVar20 = psraw(CONCAT26(sVar24 + (short)(uVar8 >> 0x30),
                                CONCAT24(sVar23 + (short)(uVar8 >> 0x20),
                                         CONCAT22(sVar22 + (short)(uVar8 >> 0x10),
                                                  sVar19 + (short)uVar8))),2);
        Var21 = CONCAT28((short)((unkuint10)fVar11 >> 0x40),uVar20);
        uVar20 = psraw(CONCAT26(sVar29 + (short)(uVar17 >> 0x30),
                                CONCAT24(sVar28 + (short)(uVar17 >> 0x20),
                                         CONCAT22(sVar27 + (short)(uVar17 >> 0x10),
                                                  sVar25 + (short)uVar17))),2);
        Var26 = CONCAT28((short)((unkuint10)fVar10 >> 0x40),uVar20);
        uVar20 = psraw(CONCAT26(sVar35 + (short)(uVar18 >> 0x30),
                                CONCAT24(sVar33 + (short)(uVar18 >> 0x20),
                                         CONCAT22(sVar32 + (short)(uVar18 >> 0x10),
                                                  sVar30 + (short)uVar18))),2);
        Var31 = CONCAT28((short)((unkuint10)fVar9 >> 0x40),uVar20);
        uVar6 = iVar2 - 2U & 0xfffffff8;
        iVar2 = (uVar3 & 0xfffffff8) - uVar6;
        uVar8 = DAT_1008e038;
        do {
          uVar17 = *(ulonglong *)(iVar2 + (extraout_EDX & 0xfffffff8));
          uVar7 = (ushort)uVar17;
          uVar12 = (ushort)(uVar17 >> 0x10);
          uVar13 = (ushort)(uVar17 >> 0x20);
          uVar15 = (ushort)(uVar17 >> 0x30);
          uVar17 = uVar17 & uVar8;
          sVar29 = (short)Var21;
          sVar24 = (short)((unkuint10)Var21 >> 0x10);
          sVar19 = (short)((unkuint10)Var21 >> 0x20);
          sVar22 = (short)((unkuint10)Var21 >> 0x30);
          uVar40 = CONCAT26(-(ushort)(uVar15 == (ushort)((ulonglong)DAT_1008e008 >> 0x30)),
                            CONCAT24(-(ushort)(uVar13 == (ushort)((ulonglong)DAT_1008e008 >> 0x20)),
                                     CONCAT22(-(ushort)(uVar12 ==
                                                       (ushort)((ulonglong)DAT_1008e008 >> 0x10)),
                                              -(ushort)(uVar7 == (ushort)DAT_1008e008))));
          sVar35 = (short)Var31;
          sVar30 = (short)((unkuint10)Var31 >> 0x10);
          sVar32 = (short)((unkuint10)Var31 >> 0x20);
          sVar33 = (short)((unkuint10)Var31 >> 0x30);
          uVar18 = CONCAT26(uVar15 >> 6,CONCAT24(uVar13 >> 6,CONCAT22(uVar12 >> 6,uVar7 >> 6))) &
                   uVar8;
          Var21 = CONCAT28((short)((unkuint10)Var21 >> 0x40),
                           CONCAT26(sVar22 + (short)((ulonglong)DAT_1008e218 >> 0x30),
                                    CONCAT24(sVar19 + (short)((ulonglong)DAT_1008e218 >> 0x20),
                                             CONCAT22(sVar24 + (short)((ulonglong)DAT_1008e218 >>
                                                                      0x10),
                                                      sVar29 + (short)DAT_1008e218))));
          sVar23 = (short)Var26;
          sVar25 = (short)((unkuint10)Var26 >> 0x10);
          sVar27 = (short)((unkuint10)Var26 >> 0x20);
          sVar28 = (short)((unkuint10)Var26 >> 0x30);
          Var26 = CONCAT28((short)((unkuint10)Var26 >> 0x40),
                           CONCAT26(sVar28 + (short)((ulonglong)DAT_1008e220 >> 0x30),
                                    CONCAT24(sVar27 + (short)((ulonglong)DAT_1008e220 >> 0x20),
                                             CONCAT22(sVar25 + (short)((ulonglong)DAT_1008e220 >>
                                                                      0x10),
                                                      sVar23 + (short)DAT_1008e220))));
          uVar39 = psllw(uVar8,0xb);
          Var31 = CONCAT28((short)((unkuint10)Var31 >> 0x40),
                           CONCAT26(sVar33 + (short)((ulonglong)DAT_1008e228 >> 0x30),
                                    CONCAT24(sVar32 + (short)((ulonglong)DAT_1008e228 >> 0x20),
                                             CONCAT22(sVar30 + (short)((ulonglong)DAT_1008e228 >>
                                                                      0x10),
                                                      sVar35 + (short)DAT_1008e228))));
          uVar18 = CONCAT26((short)(uVar18 >> 0x30) * sVar28,
                            CONCAT24((short)(uVar18 >> 0x20) * sVar27,
                                     CONCAT22((short)(uVar18 >> 0x10) * sVar25,
                                              (short)uVar18 * sVar23))) & uVar39;
          uVar8 = CONCAT26((ushort)(uVar39 >> 0x3b),
                           CONCAT24((ushort)(uVar39 >> 0x20) >> 0xb,
                                    CONCAT22((ushort)(uVar39 >> 0x10) >> 0xb,(ushort)uVar39 >> 0xb))
                          );
          *(ulonglong *)(iVar2 + uVar6) =
               *(ulonglong *)(iVar2 + uVar6) & uVar40 |
               ~uVar40 & (CONCAT26((uVar15 >> 0xb) * sVar22,
                                   CONCAT24((uVar13 >> 0xb) * sVar19,
                                            CONCAT22((uVar12 >> 0xb) * sVar24,
                                                     (uVar7 >> 0xb) * sVar29))) & uVar39 |
                          CONCAT26((ushort)((short)(uVar17 >> 0x30) * sVar33) >> 0xb,
                                   CONCAT24((ushort)((short)(uVar17 >> 0x20) * sVar32) >> 0xb,
                                            CONCAT22((ushort)((short)(uVar17 >> 0x10) * sVar30) >>
                                                     0xb,(ushort)((short)uVar17 * sVar35) >> 0xb)))
                         | CONCAT26((ushort)(uVar18 >> 0x35),
                                    CONCAT24((ushort)(uVar18 >> 0x20) >> 5,
                                             CONCAT22((ushort)(uVar18 >> 0x10) >> 5,
                                                      (ushort)uVar18 >> 5))));
          iVar5 = iVar2 + 8;
          bVar1 = iVar2 < -8;
          iVar2 = iVar5;
        } while (iVar5 == 0 || bVar1);
      }
      else {
        _DAT_1008d458 = (float)fVar11;
        _DAT_1008d460 = (float)fVar10;
        _DAT_1008d468 = (float)fVar9;
        _DAT_1008d440 = _DAT_1008d440 + _DAT_1008d444;
        _DAT_1008d448 = _DAT_1008d448 + _DAT_1008d44c;
        _DAT_1008d450 = _DAT_1008d450 + _DAT_1008d454;
      }
      DAT_1008d294 = DAT_1008d298 + DAT_1008d294;
      DAT_1008d290 = DAT_1008d290 + -1;
    } while (DAT_1008d290 != 0);
    return;
  }
  iVar2 = DAT_1008d2d4 + (DAT_1008d2d4 & 0x8000) * 2;
  iVar5 = DAT_1008d2e0 + (DAT_1008d2e0 & 0x8000) * 2;
  sVar25 = (short)((uint)iVar2 >> 0x10);
  sVar23 = (short)iVar2;
  sVar28 = (short)((uint)iVar5 >> 0x10);
  sVar27 = (short)iVar5;
  uVar14 = (undefined4)(CONCAT46(CONCAT22(uVar16,sVar25),CONCAT24(sVar25,iVar2)) >> 0x20);
  DAT_1008e218 = CONCAT44(uVar14,uVar14);
  DAT_1008e228 = CONCAT44(CONCAT22(sVar27,sVar27),CONCAT22(sVar27,sVar27));
  uVar14 = (undefined4)
           (CONCAT46(CONCAT22((short)((unkuint10)in_ST2 >> 0x40),sVar28),CONCAT24(sVar28,iVar5)) >>
           0x20);
  DAT_1008e240 = CONCAT44(uVar14,uVar14);
  DAT_1008e200 = CONCAT26(sVar25 * sVar22,
                          CONCAT24(sVar25 * sVar19,CONCAT22(sVar25 * sVar24,sVar25 * sVar29)));
  DAT_1008e220 = CONCAT44(CONCAT22(sVar23,sVar23),CONCAT22(sVar23,sVar23));
  DAT_1008e210 = CONCAT26(sVar27 * sVar22,
                          CONCAT24(sVar27 * sVar19,CONCAT22(sVar27 * sVar24,sVar27 * sVar29)));
  DAT_1008e208 = CONCAT26(sVar23 * sVar22,
                          CONCAT24(sVar23 * sVar19,CONCAT22(sVar23 * sVar24,sVar23 * sVar29)));
  DAT_1008e238 = CONCAT26(sVar28 * sVar22,
                          CONCAT24(sVar28 * sVar19,CONCAT22(sVar28 * sVar24,sVar28 * sVar29)));
  do {
    iVar2 = DAT_1008d294;
    DAT_1008d2cc = DAT_1008d2cc + DAT_1008d2d0;
    DAT_1008d2d8 = DAT_1008d2d8 + DAT_1008d2dc;
    fVar9 = (float10)_DAT_1008d468 + (float10)_DAT_1008d46c;
    fVar10 = (float10)_DAT_1008d460 + (float10)_DAT_1008d464;
    fVar11 = (float10)_DAT_1008d458 + (float10)_DAT_1008d45c;
    DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar3 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    if (uVar3 < DAT_1008d284 >> 0x10) {
      FUN_1007d650(uVar3 - (DAT_1008d284 >> 0x10));
      uVar6 = uVar3 & 6;
      uVar4 = DAT_1008d2cc;
      iVar5 = DAT_1008d2d8;
      while( true ) {
        sVar29 = (short)uVar4;
        sVar24 = (short)(uVar4 >> 0x10);
        if (uVar6 == 0) break;
        uVar4 = (uint)(ushort)(sVar29 - (short)DAT_1008d2d4) |
                CONCAT22(sVar29 - (short)DAT_1008d2d4,sVar24 - DAT_1008d2d4._2_2_) << 0x10;
        iVar5 = iVar5 - DAT_1008d2e0;
        uVar6 = uVar6 - 2;
      }
      sVar32 = (short)((uint)iVar5 >> 0x10);
      sVar35 = (short)iVar5;
      sVar19 = sVar24 + (short)DAT_1008e200;
      sVar22 = sVar24 + (short)((ulonglong)DAT_1008e200 >> 0x10);
      sVar23 = sVar24 + (short)((ulonglong)DAT_1008e200 >> 0x20);
      sVar24 = sVar24 + (short)((ulonglong)DAT_1008e200 >> 0x30);
      sVar25 = sVar29 + (short)DAT_1008e208;
      sVar27 = sVar29 + (short)((ulonglong)DAT_1008e208 >> 0x10);
      sVar28 = sVar29 + (short)((ulonglong)DAT_1008e208 >> 0x20);
      sVar29 = sVar29 + (short)((ulonglong)DAT_1008e208 >> 0x30);
      sVar30 = sVar35 + (short)DAT_1008e210;
      sVar33 = sVar35 + (short)((ulonglong)DAT_1008e210 >> 0x10);
      sVar34 = sVar35 + (short)((ulonglong)DAT_1008e210 >> 0x20);
      sVar35 = sVar35 + (short)((ulonglong)DAT_1008e210 >> 0x30);
      sVar36 = sVar32 + (short)DAT_1008e238;
      sVar37 = sVar32 + (short)((ulonglong)DAT_1008e238 >> 0x10);
      sVar38 = sVar32 + (short)((ulonglong)DAT_1008e238 >> 0x20);
      sVar32 = sVar32 + (short)((ulonglong)DAT_1008e238 >> 0x30);
      uVar8 = psraw(CONCAT26(sVar24,CONCAT24(sVar23,CONCAT22(sVar22,sVar19))),0xf);
      uVar8 = uVar8 & _DAT_1008e030;
      uVar17 = psraw(CONCAT26(sVar29,CONCAT24(sVar28,CONCAT22(sVar27,sVar25))),0xf);
      uVar17 = uVar17 & _DAT_1008e030;
      uVar18 = psraw(CONCAT26(sVar35,CONCAT24(sVar34,CONCAT22(sVar33,sVar30))),0xf);
      uVar18 = uVar18 & _DAT_1008e030;
      uVar40 = psraw(CONCAT26(sVar32,CONCAT24(sVar38,CONCAT22(sVar37,sVar36))),0xf);
      uVar20 = psraw(CONCAT26(sVar24 + (short)(uVar8 >> 0x30),
                              CONCAT24(sVar23 + (short)(uVar8 >> 0x20),
                                       CONCAT22(sVar22 + (short)(uVar8 >> 0x10),
                                                sVar19 + (short)uVar8))),2);
      Var21 = CONCAT28((short)((unkuint10)fVar11 >> 0x40),uVar20);
      uVar40 = uVar40 & _DAT_1008e030;
      uVar20 = psraw(CONCAT26(sVar29 + (short)(uVar17 >> 0x30),
                              CONCAT24(sVar28 + (short)(uVar17 >> 0x20),
                                       CONCAT22(sVar27 + (short)(uVar17 >> 0x10),
                                                sVar25 + (short)uVar17))),2);
      Var26 = CONCAT28((short)((unkuint10)fVar10 >> 0x40),uVar20);
      DAT_1008e230 = psraw(CONCAT26(sVar32 + (short)(uVar40 >> 0x30),
                                    CONCAT24(sVar38 + (short)(uVar40 >> 0x20),
                                             CONCAT22(sVar37 + (short)(uVar40 >> 0x10),
                                                      sVar36 + (short)uVar40))),2);
      uVar20 = psraw(CONCAT26(sVar35 + (short)(uVar18 >> 0x30),
                              CONCAT24(sVar34 + (short)(uVar18 >> 0x20),
                                       CONCAT22(sVar33 + (short)(uVar18 >> 0x10),
                                                sVar30 + (short)uVar18))),2);
      Var31 = CONCAT28((short)((unkuint10)fVar9 >> 0x40),uVar20);
      uVar6 = iVar2 - 2U & 0xfffffff8;
      iVar2 = (uVar3 & 0xfffffff8) - uVar6;
      uVar8 = DAT_1008e038;
      do {
        uVar18 = DAT_1008e038;
        uVar17 = *(ulonglong *)(iVar2 + (extraout_EDX_00 & 0xfffffff8));
        uVar7 = (ushort)uVar17;
        uVar12 = (ushort)(uVar17 >> 0x10);
        uVar13 = (ushort)(uVar17 >> 0x20);
        uVar15 = (ushort)(uVar17 >> 0x30);
        uVar17 = uVar17 & uVar8;
        sVar29 = (short)Var21;
        sVar24 = (short)((unkuint10)Var21 >> 0x10);
        sVar19 = (short)((unkuint10)Var21 >> 0x20);
        sVar22 = (short)((unkuint10)Var21 >> 0x30);
        uVar39 = CONCAT26(-(ushort)(uVar15 == (ushort)((ulonglong)DAT_1008e008 >> 0x30)),
                          CONCAT24(-(ushort)(uVar13 == (ushort)((ulonglong)DAT_1008e008 >> 0x20)),
                                   CONCAT22(-(ushort)(uVar12 ==
                                                     (ushort)((ulonglong)DAT_1008e008 >> 0x10)),
                                            -(ushort)(uVar7 == (ushort)DAT_1008e008))));
        sVar35 = (short)Var31;
        sVar30 = (short)((unkuint10)Var31 >> 0x10);
        sVar32 = (short)((unkuint10)Var31 >> 0x20);
        sVar33 = (short)((unkuint10)Var31 >> 0x30);
        uVar40 = CONCAT26(uVar15 >> 6,CONCAT24(uVar13 >> 6,CONCAT22(uVar12 >> 6,uVar7 >> 6))) &
                 uVar8;
        Var21 = CONCAT28((short)((unkuint10)Var21 >> 0x40),
                         CONCAT26(sVar22 + (short)((ulonglong)DAT_1008e218 >> 0x30),
                                  CONCAT24(sVar19 + (short)((ulonglong)DAT_1008e218 >> 0x20),
                                           CONCAT22(sVar24 + (short)((ulonglong)DAT_1008e218 >> 0x10
                                                                    ),sVar29 + (short)DAT_1008e218))
                                 ));
        sVar23 = (short)Var26;
        sVar25 = (short)((unkuint10)Var26 >> 0x10);
        sVar27 = (short)((unkuint10)Var26 >> 0x20);
        sVar28 = (short)((unkuint10)Var26 >> 0x30);
        Var26 = CONCAT28((short)((unkuint10)Var26 >> 0x40),
                         CONCAT26(sVar28 + (short)((ulonglong)DAT_1008e220 >> 0x30),
                                  CONCAT24(sVar27 + (short)((ulonglong)DAT_1008e220 >> 0x20),
                                           CONCAT22(sVar25 + (short)((ulonglong)DAT_1008e220 >> 0x10
                                                                    ),sVar23 + (short)DAT_1008e220))
                                 ));
        uVar41 = psllw(uVar8,0xb);
        Var31 = CONCAT28((short)((unkuint10)Var31 >> 0x40),
                         CONCAT26(sVar33 + (short)((ulonglong)DAT_1008e228 >> 0x30),
                                  CONCAT24(sVar32 + (short)((ulonglong)DAT_1008e228 >> 0x20),
                                           CONCAT22(sVar30 + (short)((ulonglong)DAT_1008e228 >> 0x10
                                                                    ),sVar35 + (short)DAT_1008e228))
                                 ));
        uVar8 = CONCAT26((short)(uVar40 >> 0x30) * sVar28,
                         CONCAT24((short)(uVar40 >> 0x20) * sVar27,
                                  CONCAT22((short)(uVar40 >> 0x10) * sVar25,(short)uVar40 * sVar23))
                        ) & uVar41;
        uVar8 = CONCAT26((uVar15 >> 0xb) * sVar22,
                         CONCAT24((uVar13 >> 0xb) * sVar19,
                                  CONCAT22((uVar12 >> 0xb) * sVar24,(uVar7 >> 0xb) * sVar29))) &
                uVar41 | CONCAT26((ushort)((short)(uVar17 >> 0x30) * sVar33) >> 0xb,
                                  CONCAT24((ushort)((short)(uVar17 >> 0x20) * sVar32) >> 0xb,
                                           CONCAT22((ushort)((short)(uVar17 >> 0x10) * sVar30) >>
                                                    0xb,(ushort)((short)uVar17 * sVar35) >> 0xb))) |
                CONCAT26((ushort)(uVar8 >> 0x35),
                         CONCAT24((ushort)(uVar8 >> 0x20) >> 5,
                                  CONCAT22((ushort)(uVar8 >> 0x10) >> 5,(ushort)uVar8 >> 5)));
        sVar29 = (short)DAT_1008e230;
        sVar24 = (short)((ulonglong)DAT_1008e230 >> 0x10);
        sVar19 = (short)((ulonglong)DAT_1008e230 >> 0x20);
        sVar22 = (short)((ulonglong)DAT_1008e230 >> 0x30);
        uVar40 = CONCAT26((short)((ulonglong)DAT_1008dbe8 >> 0x30) * sVar22,
                          CONCAT24((short)((ulonglong)DAT_1008dbe8 >> 0x20) * sVar19,
                                   CONCAT22((short)((ulonglong)DAT_1008dbe8 >> 0x10) * sVar24,
                                            (short)DAT_1008dbe8 * sVar29))) & DAT_1008e250;
        uVar17 = CONCAT26((short)((ulonglong)DAT_1008dbf0 >> 0x30) * sVar22,
                          CONCAT24((short)((ulonglong)DAT_1008dbf0 >> 0x20) * sVar19,
                                   CONCAT22((short)((ulonglong)DAT_1008dbf0 >> 0x10) * sVar24,
                                            (short)DAT_1008dbf0 * sVar29))) & DAT_1008e250;
        DAT_1008e230 = CONCAT26(sVar22 + (short)((ulonglong)DAT_1008e240 >> 0x30),
                                CONCAT24(sVar19 + (short)((ulonglong)DAT_1008e240 >> 0x20),
                                         CONCAT22(sVar24 + (short)((ulonglong)DAT_1008e240 >> 0x10),
                                                  sVar29 + (short)DAT_1008e240)));
        *(ulonglong *)(iVar2 + uVar6) =
             *(ulonglong *)(iVar2 + uVar6) & uVar39 |
             ~uVar39 & CONCAT26((short)(uVar8 >> 0x30) + (short)(uVar40 >> 0x30) +
                                (ushort)(uVar17 >> 0x35) +
                                ((ushort)((short)((ulonglong)DAT_1008dbf8 >> 0x30) * sVar22) >> 0xb)
                                ,CONCAT24((short)(uVar8 >> 0x20) + (short)(uVar40 >> 0x20) +
                                          ((ushort)(uVar17 >> 0x20) >> 5) +
                                          ((ushort)((short)((ulonglong)DAT_1008dbf8 >> 0x20) *
                                                   sVar19) >> 0xb),
                                          CONCAT22((short)(uVar8 >> 0x10) + (short)(uVar40 >> 0x10)
                                                   + ((ushort)(uVar17 >> 0x10) >> 5) +
                                                   ((ushort)((short)((ulonglong)DAT_1008dbf8 >> 0x10
                                                                    ) * sVar24) >> 0xb),
                                                   (short)uVar8 + (short)uVar40 +
                                                   ((ushort)uVar17 >> 5) +
                                                   ((ushort)((short)DAT_1008dbf8 * sVar29) >> 0xb)))
                               );
        iVar5 = iVar2 + 8;
        bVar1 = iVar2 < -8;
        iVar2 = iVar5;
        uVar8 = uVar18;
      } while (iVar5 == 0 || bVar1);
    }
    else {
      _DAT_1008d458 = (float)fVar11;
      _DAT_1008d460 = (float)fVar10;
      _DAT_1008d468 = (float)fVar9;
      _DAT_1008d440 = _DAT_1008d440 + _DAT_1008d444;
      _DAT_1008d448 = _DAT_1008d448 + _DAT_1008d44c;
      _DAT_1008d450 = _DAT_1008d450 + _DAT_1008d454;
    }
    DAT_1008d294 = DAT_1008d298 + DAT_1008d294;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


