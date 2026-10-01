// 1007a8c8 FUN_1007a8c8 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1007a8c8(void)

{
  ulonglong uVar1;
  bool bVar2;
  short sVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  int iVar7;
  uint uVar8;
  uint extraout_EDX;
  int iVar9;
  uint uVar10;
  short sVar11;
  int iVar12;
  short sVar13;
  short sVar14;
  short sVar16;
  short sVar17;
  undefined4 uVar18;
  ulonglong uVar15;
  ulonglong uVar19;
  short sVar20;
  undefined8 uVar21;
  ulonglong uVar22;
  ushort uVar23;
  ushort uVar24;
  ushort uVar25;
  ushort uVar26;
  
  iVar7 = DAT_1008d2c8 + (DAT_1008d2c8 & 0x8000) * 2;
  sVar16 = (short)((uint)iVar7 >> 0x10);
  sVar13 = (short)iVar7;
  uVar18 = (undefined4)(CONCAT26(sVar16,CONCAT24(sVar16,iVar7)) >> 0x20);
  sVar20 = (short)DAT_1008d2d4;
  DAT_1008e218 = psllw(CONCAT44(uVar18,uVar18),5);
  DAT_1008e228 = psllw(CONCAT44(CONCAT22(sVar20,sVar20),CONCAT22(sVar20,sVar20)),5);
  sVar11 = (short)DAT_1008e188;
  sVar14 = (short)((ulonglong)DAT_1008e188 >> 0x10);
  sVar17 = (short)((ulonglong)DAT_1008e188 >> 0x20);
  sVar3 = (short)((ulonglong)DAT_1008e188 >> 0x30);
  DAT_1008e200 = CONCAT26(sVar16 * sVar3,
                          CONCAT24(sVar16 * sVar17,CONCAT22(sVar16 * sVar14,sVar16 * sVar11)));
  DAT_1008e210 = CONCAT26(sVar20 * sVar3,
                          CONCAT24(sVar20 * sVar17,CONCAT22(sVar20 * sVar14,sVar20 * sVar11)));
  DAT_1008e208 = CONCAT26(sVar13 * sVar3,
                          CONCAT24(sVar13 * sVar17,CONCAT22(sVar13 * sVar14,sVar13 * sVar11)));
  DAT_1008e220 = psllw(CONCAT44(CONCAT22(sVar13,sVar13),CONCAT22(sVar13,sVar13)),5);
  do {
    iVar7 = DAT_1008d294;
    DAT_1008d2c0 = DAT_1008d2c0 + DAT_1008d2c4;
    DAT_1008d2cc = DAT_1008d2cc + DAT_1008d2d0;
    DAT_1008d2e4 = DAT_1008d2e4 + DAT_1008d2e8;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar8 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    if (uVar8 < DAT_1008d284 >> 0x10) {
      FUN_10078060(uVar8 - (DAT_1008d284 >> 0x10));
      sVar11 = (short)DAT_1008d2cc;
      iVar9 = DAT_1008d2c0;
      iVar12 = DAT_1008d2cc;
      for (uVar10 = uVar8 & 6; uVar10 != 0; uVar10 = uVar10 - 2) {
        iVar9 = iVar9 - DAT_1008d2c8;
        iVar12 = iVar12 - DAT_1008d2d4;
        sVar11 = (short)iVar12;
      }
      sVar17 = (short)((uint)iVar9 >> 0x10);
      sVar14 = (short)iVar9;
      uVar15 = psllw(CONCAT26(sVar17 + (short)((ulonglong)DAT_1008e200 >> 0x30),
                              CONCAT24(sVar17 + (short)((ulonglong)DAT_1008e200 >> 0x20),
                                       CONCAT22(sVar17 + (short)((ulonglong)DAT_1008e200 >> 0x10),
                                                sVar17 + (short)DAT_1008e200))),3);
      uVar19 = psllw(CONCAT26(sVar14 + (short)((ulonglong)DAT_1008e208 >> 0x30),
                              CONCAT24(sVar14 + (short)((ulonglong)DAT_1008e208 >> 0x20),
                                       CONCAT22(sVar14 + (short)((ulonglong)DAT_1008e208 >> 0x10),
                                                sVar14 + (short)DAT_1008e208))),3);
      uVar21 = psllw(CONCAT26(sVar11 + (short)((ulonglong)DAT_1008e210 >> 0x30),
                              CONCAT24(sVar11 + (short)((ulonglong)DAT_1008e210 >> 0x20),
                                       CONCAT22(sVar11 + (short)((ulonglong)DAT_1008e210 >> 0x10),
                                                sVar11 + (short)DAT_1008e210))),3);
      uVar10 = iVar7 - 2U & 0xfffffff8;
      iVar7 = (uVar8 & 0xfffffff8) - uVar10;
      do {
        uVar22 = uVar19 & _DAT_1008e248;
        sVar11 = (short)DAT_1008e218;
        uVar4 = (ulonglong)DAT_1008e218 >> 0x10;
        uVar5 = (ulonglong)DAT_1008e218 >> 0x20;
        uVar6 = (ulonglong)DAT_1008e218 >> 0x30;
        uVar23 = (ushort)uVar21;
        uVar24 = (ushort)((ulonglong)uVar21 >> 0x10);
        uVar25 = (ushort)((ulonglong)uVar21 >> 0x20);
        uVar26 = (ushort)((ulonglong)uVar21 >> 0x30);
        uVar19 = CONCAT26((short)(uVar19 >> 0x30) + (short)((ulonglong)DAT_1008e220 >> 0x30),
                          CONCAT24((short)(uVar19 >> 0x20) +
                                   (short)((ulonglong)DAT_1008e220 >> 0x20),
                                   CONCAT22((short)(uVar19 >> 0x10) +
                                            (short)((ulonglong)DAT_1008e220 >> 0x10),
                                            (short)uVar19 + (short)DAT_1008e220)));
        uVar21 = CONCAT26(uVar26 + (short)((ulonglong)DAT_1008e228 >> 0x30),
                          CONCAT24(uVar25 + (short)((ulonglong)DAT_1008e228 >> 0x20),
                                   CONCAT22(uVar24 + (short)((ulonglong)DAT_1008e228 >> 0x10),
                                            uVar23 + (short)DAT_1008e228)));
        uVar1 = *(ulonglong *)(iVar7 + (extraout_EDX & 0xfffffff8));
        *(ulonglong *)(iVar7 + uVar10) =
             ~uVar1 & *(ulonglong *)(iVar7 + uVar10) |
             (uVar15 & DAT_1008e250 |
             CONCAT26((ushort)(uVar22 >> 0x35),
                      CONCAT24((ushort)(uVar22 >> 0x20) >> 5,
                               CONCAT22((ushort)(uVar22 >> 0x10) >> 5,(ushort)uVar22 >> 5))) |
             CONCAT26(uVar26 >> 0xb,CONCAT24(uVar25 >> 0xb,CONCAT22(uVar24 >> 0xb,uVar23 >> 0xb))))
             & uVar1;
        iVar9 = iVar7 + 8;
        bVar2 = iVar7 < -8;
        iVar7 = iVar9;
        uVar15 = CONCAT26((short)(uVar15 >> 0x30) + (short)uVar6,
                          CONCAT24((short)(uVar15 >> 0x20) + (short)uVar5,
                                   CONCAT22((short)(uVar15 >> 0x10) + (short)uVar4,
                                            (short)uVar15 + sVar11)));
      } while (iVar9 == 0 || bVar2);
    }
    DAT_1008d29c = DAT_1008d2a0 + DAT_1008d29c;
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


