// 1007aad8 FUN_1007aad8 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1007aad8(void)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint extraout_EDX;
  int iVar5;
  uint uVar6;
  short sVar7;
  int iVar8;
  short sVar9;
  short sVar10;
  short sVar12;
  short sVar13;
  short sVar14;
  undefined4 uVar15;
  undefined8 uVar11;
  short sVar16;
  short sVar17;
  short sVar18;
  short sVar19;
  short sVar20;
  short sVar22;
  short sVar23;
  undefined8 uVar21;
  short sVar24;
  ushort uVar25;
  ushort uVar26;
  ushort uVar27;
  ulonglong uVar28;
  ulonglong uVar29;
  ulonglong uVar30;
  ulonglong uVar31;
  undefined8 uVar32;
  
  uVar15 = CONCAT22((ushort)DAT_1008d2a8 << 3,(ushort)DAT_1008d2a8 << 3);
  uVar31 = CONCAT44(uVar15,uVar15);
  DAT_1008e1c8 = uVar31 ^ _DAT_1008e018;
  _DAT_1008e1c0 = psllw(uVar31,4);
  iVar3 = DAT_1008d2c8 + (DAT_1008d2c8 & 0x8000) * 2;
  sVar12 = (short)((uint)iVar3 >> 0x10);
  sVar9 = (short)iVar3;
  uVar15 = (undefined4)(CONCAT26(sVar12,CONCAT24(sVar12,iVar3)) >> 0x20);
  sVar14 = (short)DAT_1008d2d4;
  uVar11 = CONCAT44(uVar15,uVar15);
  uVar32 = psraw(uVar11,0xf);
  uVar11 = pmulhw(uVar11,_DAT_1008e1c0);
  DAT_1008e218 = psllw(CONCAT26((short)((ulonglong)uVar11 >> 0x30) -
                                (short)((ulonglong)uVar32 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar11 >> 0x20) -
                                         (short)((ulonglong)uVar32 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar11 >> 0x10) -
                                                  (short)((ulonglong)uVar32 >> 0x10),
                                                  (short)uVar11 - (short)uVar32))),6);
  uVar11 = CONCAT44(CONCAT22(sVar14,sVar14),CONCAT22(sVar14,sVar14));
  uVar32 = psraw(uVar11,0xf);
  uVar11 = pmulhw(uVar11,_DAT_1008e1c0);
  DAT_1008e228 = psllw(CONCAT26((short)((ulonglong)uVar11 >> 0x30) -
                                (short)((ulonglong)uVar32 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar11 >> 0x20) -
                                         (short)((ulonglong)uVar32 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar11 >> 0x10) -
                                                  (short)((ulonglong)uVar32 >> 0x10),
                                                  (short)uVar11 - (short)uVar32))),6);
  sVar7 = (short)DAT_1008e188;
  sVar10 = (short)((ulonglong)DAT_1008e188 >> 0x10);
  sVar13 = (short)((ulonglong)DAT_1008e188 >> 0x20);
  sVar2 = (short)((ulonglong)DAT_1008e188 >> 0x30);
  DAT_1008e200 = CONCAT26(sVar12 * sVar2,
                          CONCAT24(sVar12 * sVar13,CONCAT22(sVar12 * sVar10,sVar12 * sVar7)));
  uVar11 = CONCAT44(CONCAT22(sVar9,sVar9),CONCAT22(sVar9,sVar9));
  uVar32 = psraw(uVar11,0xf);
  uVar11 = pmulhw(uVar11,_DAT_1008e1c0);
  DAT_1008e210 = CONCAT26(sVar14 * sVar2,
                          CONCAT24(sVar14 * sVar13,CONCAT22(sVar14 * sVar10,sVar14 * sVar7)));
  DAT_1008e208 = CONCAT26(sVar9 * sVar2,
                          CONCAT24(sVar9 * sVar13,CONCAT22(sVar9 * sVar10,sVar9 * sVar7)));
  DAT_1008e220 = psllw(CONCAT26((short)((ulonglong)uVar11 >> 0x30) -
                                (short)((ulonglong)uVar32 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar11 >> 0x20) -
                                         (short)((ulonglong)uVar32 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar11 >> 0x10) -
                                                  (short)((ulonglong)uVar32 >> 0x10),
                                                  (short)uVar11 - (short)uVar32))),6);
  do {
    iVar3 = DAT_1008d294;
    DAT_1008d2e4 = DAT_1008d2e4 + DAT_1008d2e8;
    DAT_1008d2c0 = DAT_1008d2c0 + DAT_1008d2c4;
    DAT_1008d2cc = DAT_1008d2cc + DAT_1008d2d0;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar4 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    if (uVar4 < DAT_1008d284 >> 0x10) {
      FUN_10078060(uVar4 - (DAT_1008d284 >> 0x10));
      sVar7 = (short)DAT_1008d2cc;
      iVar5 = DAT_1008d2c0;
      iVar8 = DAT_1008d2cc;
      for (uVar6 = uVar4 & 6; uVar6 != 0; uVar6 = uVar6 - 2) {
        iVar5 = iVar5 - DAT_1008d2c8;
        iVar8 = iVar8 - DAT_1008d2d4;
        sVar7 = (short)iVar8;
      }
      sVar13 = (short)((uint)iVar5 >> 0x10);
      sVar10 = (short)iVar5;
      uVar11 = pmulhw(CONCAT26(sVar13 + (short)((ulonglong)DAT_1008e200 >> 0x30),
                               CONCAT24(sVar13 + (short)((ulonglong)DAT_1008e200 >> 0x20),
                                        CONCAT22(sVar13 + (short)((ulonglong)DAT_1008e200 >> 0x10),
                                                 sVar13 + (short)DAT_1008e200))),_DAT_1008e1c0);
      uVar32 = pmulhw(CONCAT26(sVar10 + (short)((ulonglong)DAT_1008e208 >> 0x30),
                               CONCAT24(sVar10 + (short)((ulonglong)DAT_1008e208 >> 0x20),
                                        CONCAT22(sVar10 + (short)((ulonglong)DAT_1008e208 >> 0x10),
                                                 sVar10 + (short)DAT_1008e208))),_DAT_1008e1c0);
      uVar21 = pmulhw(CONCAT26(sVar7 + (short)((ulonglong)DAT_1008e210 >> 0x30),
                               CONCAT24(sVar7 + (short)((ulonglong)DAT_1008e210 >> 0x20),
                                        CONCAT22(sVar7 + (short)((ulonglong)DAT_1008e210 >> 0x10),
                                                 sVar7 + (short)DAT_1008e210))),_DAT_1008e1c0);
      uVar11 = psllw(uVar11,4);
      uVar32 = psllw(uVar32,4);
      uVar21 = psllw(uVar21,4);
      uVar6 = iVar3 - 2U & 0xfffffff8;
      iVar3 = (uVar4 & 0xfffffff8) - uVar6;
      do {
        uVar31 = *(ulonglong *)(iVar3 + uVar6);
        uVar25 = (ushort)(uVar31 >> 0x10);
        uVar26 = (ushort)(uVar31 >> 0x20);
        uVar27 = (ushort)(uVar31 >> 0x30);
        sVar7 = (short)DAT_1008e1c8;
        sVar10 = (short)(DAT_1008e1c8 >> 0x10);
        sVar13 = (short)(DAT_1008e1c8 >> 0x20);
        sVar2 = (short)(DAT_1008e1c8 >> 0x30);
        uVar30 = uVar31 & DAT_1008e268;
        uVar28 = CONCAT26(uVar27 >> 6,
                          CONCAT24(uVar26 >> 6,CONCAT22(uVar25 >> 6,(ushort)uVar31 >> 6))) &
                 DAT_1008e268;
        sVar9 = (short)uVar11;
        sVar12 = (short)((ulonglong)uVar11 >> 0x10);
        sVar14 = (short)((ulonglong)uVar11 >> 0x20);
        sVar16 = (short)((ulonglong)uVar11 >> 0x30);
        sVar20 = (short)uVar21;
        sVar22 = (short)((ulonglong)uVar21 >> 0x10);
        sVar23 = (short)((ulonglong)uVar21 >> 0x20);
        sVar24 = (short)((ulonglong)uVar21 >> 0x30);
        sVar17 = (short)((ulonglong)uVar32 >> 0x10);
        sVar18 = (short)((ulonglong)uVar32 >> 0x20);
        sVar19 = (short)((ulonglong)uVar32 >> 0x30);
        uVar29 = CONCAT26((short)(uVar28 >> 0x30) * sVar2 + sVar19,
                          CONCAT24((short)(uVar28 >> 0x20) * sVar13 + sVar18,
                                   CONCAT22((short)(uVar28 >> 0x10) * sVar10 + sVar17,
                                            (short)uVar28 * sVar7 + (short)uVar32))) & DAT_1008e250;
        uVar28 = *(ulonglong *)(iVar3 + (extraout_EDX & 0xfffffff8));
        uVar11 = CONCAT26(sVar16 + (short)((ulonglong)DAT_1008e218 >> 0x30),
                          CONCAT24(sVar14 + (short)((ulonglong)DAT_1008e218 >> 0x20),
                                   CONCAT22(sVar12 + (short)((ulonglong)DAT_1008e218 >> 0x10),
                                            sVar9 + (short)DAT_1008e218)));
        uVar32 = CONCAT26(sVar19 + (short)((ulonglong)DAT_1008e220 >> 0x30),
                          CONCAT24(sVar18 + (short)((ulonglong)DAT_1008e220 >> 0x20),
                                   CONCAT22(sVar17 + (short)((ulonglong)DAT_1008e220 >> 0x10),
                                            (short)uVar32 + (short)DAT_1008e220)));
        uVar21 = CONCAT26(sVar24 + (short)((ulonglong)DAT_1008e228 >> 0x30),
                          CONCAT24(sVar23 + (short)((ulonglong)DAT_1008e228 >> 0x20),
                                   CONCAT22(sVar22 + (short)((ulonglong)DAT_1008e228 >> 0x10),
                                            sVar20 + (short)DAT_1008e228)));
        *(ulonglong *)(iVar3 + uVar6) =
             (CONCAT26((uVar27 >> 0xb) * sVar2 + sVar16,
                       CONCAT24((uVar26 >> 0xb) * sVar13 + sVar14,
                                CONCAT22((uVar25 >> 0xb) * sVar10 + sVar12,
                                         ((ushort)uVar31 >> 0xb) * sVar7 + sVar9))) & DAT_1008e250 |
              CONCAT26((ushort)(uVar29 >> 0x35),
                       CONCAT24((ushort)(uVar29 >> 0x20) >> 5,
                                CONCAT22((ushort)(uVar29 >> 0x10) >> 5,(ushort)uVar29 >> 5))) |
             CONCAT26((ushort)((short)(uVar30 >> 0x30) * sVar2 + sVar24) >> 0xb,
                      CONCAT24((ushort)((short)(uVar30 >> 0x20) * sVar13 + sVar23) >> 0xb,
                               CONCAT22((ushort)((short)(uVar30 >> 0x10) * sVar10 + sVar22) >> 0xb,
                                        (ushort)((short)uVar30 * sVar7 + sVar20) >> 0xb)))) & uVar28
             | ~uVar28 & *(ulonglong *)(iVar3 + uVar6);
        iVar5 = iVar3 + 8;
        bVar1 = iVar3 < -8;
        iVar3 = iVar5;
      } while (iVar5 == 0 || bVar1);
    }
    DAT_1008d29c = DAT_1008d2a0 + DAT_1008d29c;
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


