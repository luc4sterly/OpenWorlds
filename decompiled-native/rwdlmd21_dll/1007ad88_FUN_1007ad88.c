// 1007ad88 FUN_1007ad88 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1007ad88(void)

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
  short sVar15;
  short sVar16;
  undefined4 uVar17;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar18;
  short sVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  ushort uVar22;
  ushort uVar23;
  ushort uVar24;
  ushort uVar25;
  
  iVar4 = DAT_1008d2c8 + (DAT_1008d2c8 & 0x8000) * 2;
  sVar15 = (short)((uint)iVar4 >> 0x10);
  sVar11 = (short)iVar4;
  uVar17 = (undefined4)(CONCAT26(sVar15,CONCAT24(sVar15,iVar4)) >> 0x20);
  sVar19 = (short)DAT_1008d2d4;
  DAT_1008e218 = psllw(CONCAT44(uVar17,uVar17),5);
  DAT_1008e228 = psllw(CONCAT44(CONCAT22(sVar19,sVar19),CONCAT22(sVar19,sVar19)),5);
  sVar8 = (short)DAT_1008e188;
  sVar12 = (short)((ulonglong)DAT_1008e188 >> 0x10);
  sVar16 = (short)((ulonglong)DAT_1008e188 >> 0x20);
  sVar3 = (short)((ulonglong)DAT_1008e188 >> 0x30);
  DAT_1008e200 = CONCAT26(sVar15 * sVar3,
                          CONCAT24(sVar15 * sVar16,CONCAT22(sVar15 * sVar12,sVar15 * sVar8)));
  DAT_1008e210 = CONCAT26(sVar19 * sVar3,
                          CONCAT24(sVar19 * sVar16,CONCAT22(sVar19 * sVar12,sVar19 * sVar8)));
  DAT_1008e208 = CONCAT26(sVar11 * sVar3,
                          CONCAT24(sVar11 * sVar16,CONCAT22(sVar11 * sVar12,sVar11 * sVar8)));
  DAT_1008e220 = psllw(CONCAT44(CONCAT22(sVar11,sVar11),CONCAT22(sVar11,sVar11)),5);
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
      sVar16 = (short)((uint)iVar5 >> 0x10);
      sVar12 = (short)iVar5;
      uVar13 = psllw(CONCAT26(sVar16 + (short)((ulonglong)DAT_1008e200 >> 0x30),
                              CONCAT24(sVar16 + (short)((ulonglong)DAT_1008e200 >> 0x20),
                                       CONCAT22(sVar16 + (short)((ulonglong)DAT_1008e200 >> 0x10),
                                                sVar16 + (short)DAT_1008e200))),3);
      uVar18 = psllw(CONCAT26(sVar12 + (short)((ulonglong)DAT_1008e208 >> 0x30),
                              CONCAT24(sVar12 + (short)((ulonglong)DAT_1008e208 >> 0x20),
                                       CONCAT22(sVar12 + (short)((ulonglong)DAT_1008e208 >> 0x10),
                                                sVar12 + (short)DAT_1008e208))),3);
      uVar20 = psllw(CONCAT26(sVar8 + (short)((ulonglong)DAT_1008e210 >> 0x30),
                              CONCAT24(sVar8 + (short)((ulonglong)DAT_1008e210 >> 0x20),
                                       CONCAT22(sVar8 + (short)((ulonglong)DAT_1008e210 >> 0x10),
                                                sVar8 + (short)DAT_1008e210))),3);
      puVar10 = (ulonglong *)(iVar4 - 2U & 0xfffffff8);
      iVar5 = (uVar1 & 0xfffffff8) - (int)puVar10;
      uVar22 = (ushort)uVar20;
      uVar23 = (ushort)((ulonglong)uVar20 >> 0x10);
      uVar24 = (ushort)((ulonglong)uVar20 >> 0x20);
      uVar25 = (ushort)((ulonglong)uVar20 >> 0x30);
      if (iVar5 == 0) {
        uVar18 = uVar18 & _DAT_1008e248;
        *puVar10 = ~*(ulonglong *)(&DAT_1008e100 + ((uVar1 & 6) << 2 | (iVar4 - uVar1) - 2) * 4) &
                   *puVar10 |
                   (uVar13 & DAT_1008e250 |
                   CONCAT26((ushort)(uVar18 >> 0x35),
                            CONCAT24((ushort)(uVar18 >> 0x20) >> 5,
                                     CONCAT22((ushort)(uVar18 >> 0x10) >> 5,(ushort)uVar18 >> 5))) |
                   CONCAT26(uVar25 >> 0xb,
                            CONCAT24(uVar24 >> 0xb,CONCAT22(uVar23 >> 0xb,uVar22 >> 0xb)))) &
                   *(ulonglong *)(&DAT_1008e100 + ((uVar1 & 6) << 2 | (iVar4 - uVar1) - 2) * 4);
      }
      else {
        uVar21 = uVar18 & _DAT_1008e248;
        uVar14 = CONCAT26((short)(uVar13 >> 0x30) + (short)((ulonglong)DAT_1008e218 >> 0x30),
                          CONCAT24((short)(uVar13 >> 0x20) +
                                   (short)((ulonglong)DAT_1008e218 >> 0x20),
                                   CONCAT22((short)(uVar13 >> 0x10) +
                                            (short)((ulonglong)DAT_1008e218 >> 0x10),
                                            (short)uVar13 + (short)DAT_1008e218)));
        uVar18 = CONCAT26((short)(uVar18 >> 0x30) + (short)((ulonglong)DAT_1008e220 >> 0x30),
                          CONCAT24((short)(uVar18 >> 0x20) +
                                   (short)((ulonglong)DAT_1008e220 >> 0x20),
                                   CONCAT22((short)(uVar18 >> 0x10) +
                                            (short)((ulonglong)DAT_1008e220 >> 0x10),
                                            (short)uVar18 + (short)DAT_1008e220)));
        uVar20 = CONCAT26(uVar25 + (short)((ulonglong)DAT_1008e228 >> 0x30),
                          CONCAT24(uVar24 + (short)((ulonglong)DAT_1008e228 >> 0x20),
                                   CONCAT22(uVar23 + (short)((ulonglong)DAT_1008e228 >> 0x10),
                                            uVar22 + (short)DAT_1008e228)));
        *(ulonglong *)(iVar5 + (int)puVar10) =
             ~*(ulonglong *)(&DAT_1008e0e0 + (uVar1 & 6) * 4) & *(ulonglong *)(iVar5 + (int)puVar10)
             | (uVar13 & DAT_1008e250 |
               CONCAT26((ushort)(uVar21 >> 0x35),
                        CONCAT24((ushort)(uVar21 >> 0x20) >> 5,
                                 CONCAT22((ushort)(uVar21 >> 0x10) >> 5,(ushort)uVar21 >> 5))) |
               CONCAT26(uVar25 >> 0xb,CONCAT24(uVar24 >> 0xb,CONCAT22(uVar23 >> 0xb,uVar22 >> 0xb)))
               ) & *(ulonglong *)(&DAT_1008e0e0 + (uVar1 & 6) * 4);
        iVar9 = 0;
        iVar7 = iVar5 + 8;
        uVar13 = uVar14;
        if (iVar5 + 8 != 0) {
          do {
            uVar21 = uVar18 & _DAT_1008e248;
            uVar14 = CONCAT26((short)(uVar13 >> 0x30) + (short)((ulonglong)DAT_1008e218 >> 0x30),
                              CONCAT24((short)(uVar13 >> 0x20) +
                                       (short)((ulonglong)DAT_1008e218 >> 0x20),
                                       CONCAT22((short)(uVar13 >> 0x10) +
                                                (short)((ulonglong)DAT_1008e218 >> 0x10),
                                                (short)uVar13 + (short)DAT_1008e218)));
            uVar22 = (ushort)uVar20;
            uVar23 = (ushort)((ulonglong)uVar20 >> 0x10);
            uVar24 = (ushort)((ulonglong)uVar20 >> 0x20);
            uVar25 = (ushort)((ulonglong)uVar20 >> 0x30);
            uVar18 = CONCAT26((short)(uVar18 >> 0x30) + (short)((ulonglong)DAT_1008e220 >> 0x30),
                              CONCAT24((short)(uVar18 >> 0x20) +
                                       (short)((ulonglong)DAT_1008e220 >> 0x20),
                                       CONCAT22((short)(uVar18 >> 0x10) +
                                                (short)((ulonglong)DAT_1008e220 >> 0x10),
                                                (short)uVar18 + (short)DAT_1008e220)));
            uVar20 = CONCAT26(uVar25 + (short)((ulonglong)DAT_1008e228 >> 0x30),
                              CONCAT24(uVar24 + (short)((ulonglong)DAT_1008e228 >> 0x20),
                                       CONCAT22(uVar23 + (short)((ulonglong)DAT_1008e228 >> 0x10),
                                                uVar22 + (short)DAT_1008e228)));
            *(ulonglong *)(iVar7 + (int)puVar10) =
                 uVar13 & DAT_1008e250 |
                 CONCAT26((ushort)(uVar21 >> 0x35),
                          CONCAT24((ushort)(uVar21 >> 0x20) >> 5,
                                   CONCAT22((ushort)(uVar21 >> 0x10) >> 5,(ushort)uVar21 >> 5))) |
                 CONCAT26(uVar25 >> 0xb,
                          CONCAT24(uVar24 >> 0xb,CONCAT22(uVar23 >> 0xb,uVar22 >> 0xb)));
            iVar9 = iVar7 + 8;
            bVar2 = iVar7 < -8;
            iVar7 = iVar9;
            uVar13 = uVar14;
          } while (bVar2);
        }
        uVar18 = uVar18 & _DAT_1008e248;
        *(ulonglong *)(iVar9 + (int)puVar10) =
             ~*(ulonglong *)(&DAT_1008e100 + (iVar4 - 2U & 6) * 4) &
             *(ulonglong *)(iVar9 + (int)puVar10) |
             (uVar14 & DAT_1008e250 |
             CONCAT26((ushort)(uVar18 >> 0x35),
                      CONCAT24((ushort)(uVar18 >> 0x20) >> 5,
                               CONCAT22((ushort)(uVar18 >> 0x10) >> 5,(ushort)uVar18 >> 5))) |
             CONCAT26((ushort)((ulonglong)uVar20 >> 0x3b),
                      CONCAT24((ushort)((ulonglong)uVar20 >> 0x20) >> 0xb,
                               CONCAT22((ushort)((ulonglong)uVar20 >> 0x10) >> 0xb,
                                        (ushort)uVar20 >> 0xb)))) &
             *(ulonglong *)(&DAT_1008e100 + (iVar4 - 2U & 6) * 4);
      }
    }
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


