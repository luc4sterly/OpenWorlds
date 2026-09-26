// 10078200 FUN_10078200 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10078200(void)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  ulonglong *puVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  ushort uVar8;
  short sVar9;
  short sVar11;
  short sVar12;
  undefined8 uVar10;
  short sVar13;
  short sVar14;
  short sVar16;
  short sVar17;
  undefined8 uVar15;
  short sVar18;
  short sVar19;
  short sVar21;
  short sVar22;
  undefined8 uVar20;
  short sVar23;
  undefined8 uVar24;
  ulonglong uVar25;
  ushort uVar29;
  ushort uVar30;
  ushort uVar31;
  undefined8 uVar26;
  ulonglong uVar27;
  ulonglong uVar28;
  undefined8 uVar32;
  
  uVar6 = CONCAT22((ushort)DAT_1008d2a8 << 7,(ushort)DAT_1008d2a8 << 7);
  uVar7 = CONCAT44(uVar6,uVar6);
  uVar8 = (ushort)_DAT_1008d2ac;
  uVar10 = pmulhw(CONCAT26(uVar8 >> 10,CONCAT24(uVar8 >> 10,CONCAT22(uVar8 >> 10,uVar8 >> 10))) &
                  DAT_1008e028,uVar7);
  uVar15 = pmulhw(CONCAT26(uVar8 >> 5,CONCAT24(uVar8 >> 5,CONCAT22(uVar8 >> 5,uVar8 >> 5))) &
                  DAT_1008e028,uVar7);
  uVar20 = pmulhw(CONCAT26(uVar8 * 2,CONCAT24(uVar8 * 2,CONCAT22(uVar8 * 2,uVar8 * 2))) &
                  DAT_1008e028,uVar7);
  uVar7 = uVar7 ^ _DAT_1008e010;
  uVar25 = DAT_1008e028;
  do {
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    if (DAT_1008d280 >> 0x10 < DAT_1008d284 >> 0x10) {
      uVar1 = DAT_1008d294 + (DAT_1008d280 >> 0x10) * 2;
      uVar2 = DAT_1008d294 + -2 + (DAT_1008d284 >> 0x10) * 2;
      puVar5 = (ulonglong *)(uVar2 & 0xfffffff8);
      iVar4 = (uVar1 & 0xfffffff8) - (int)puVar5;
      sVar14 = (short)uVar15;
      sVar16 = (short)((ulonglong)uVar15 >> 0x10);
      sVar17 = (short)((ulonglong)uVar15 >> 0x20);
      sVar18 = (short)((ulonglong)uVar15 >> 0x30);
      sVar19 = (short)uVar20;
      sVar21 = (short)((ulonglong)uVar20 >> 0x10);
      sVar22 = (short)((ulonglong)uVar20 >> 0x20);
      sVar23 = (short)((ulonglong)uVar20 >> 0x30);
      sVar9 = (short)uVar10;
      sVar11 = (short)((ulonglong)uVar10 >> 0x10);
      sVar12 = (short)((ulonglong)uVar10 >> 0x20);
      sVar13 = (short)((ulonglong)uVar10 >> 0x30);
      if (iVar4 == 0) {
        uVar27 = *puVar5;
        uVar8 = (ushort)uVar27;
        uVar29 = (ushort)(uVar27 >> 0x10);
        uVar30 = (ushort)(uVar27 >> 0x20);
        uVar31 = (ushort)(uVar27 >> 0x30);
        uVar26 = pmulhw(CONCAT26(uVar31 >> 5,CONCAT24(uVar30 >> 5,CONCAT22(uVar29 >> 5,uVar8 >> 5)))
                        & uVar25,uVar7);
        uVar32 = pmulhw(CONCAT26(uVar31 * 2,CONCAT24(uVar30 * 2,CONCAT22(uVar29 * 2,uVar8 * 2))) &
                        uVar25,uVar7);
        uVar24 = pmulhw(CONCAT26(uVar31 >> 10,
                                 CONCAT24(uVar30 >> 10,CONCAT22(uVar29 >> 10,uVar8 >> 10))) & uVar25
                        ,uVar7);
        uVar27 = psllw(CONCAT26((short)((ulonglong)uVar26 >> 0x30) + sVar18,
                                CONCAT24((short)((ulonglong)uVar26 >> 0x20) + sVar17,
                                         CONCAT22((short)((ulonglong)uVar26 >> 0x10) + sVar16,
                                                  (short)uVar26 + sVar14))),6);
        uVar25 = psllw(CONCAT26((short)((ulonglong)uVar24 >> 0x30) + sVar13,
                                CONCAT24((short)((ulonglong)uVar24 >> 0x20) + sVar12,
                                         CONCAT22((short)((ulonglong)uVar24 >> 0x10) + sVar11,
                                                  (short)uVar24 + sVar9))),0xb);
        *puVar5 = *puVar5 & *(ulonglong *)(&DAT_1008e040 + ((uVar1 & 6) << 2 | uVar2 - uVar1) * 4) |
                  ~*(ulonglong *)(&DAT_1008e040 + ((uVar1 & 6) << 2 | uVar2 - uVar1) * 4) &
                  (uVar27 | CONCAT26((short)((ulonglong)uVar32 >> 0x30) + sVar23,
                                     CONCAT24((short)((ulonglong)uVar32 >> 0x20) + sVar22,
                                              CONCAT22((short)((ulonglong)uVar32 >> 0x10) + sVar21,
                                                       (short)uVar32 + sVar19))) | uVar25);
        uVar25 = DAT_1008e028;
      }
      else {
        uVar24 = *(undefined8 *)(iVar4 + (int)puVar5);
        uVar8 = (ushort)uVar24;
        uVar29 = (ushort)((ulonglong)uVar24 >> 0x10);
        uVar30 = (ushort)((ulonglong)uVar24 >> 0x20);
        uVar31 = (ushort)((ulonglong)uVar24 >> 0x30);
        uVar26 = pmulhw(CONCAT26(uVar31 >> 5,CONCAT24(uVar30 >> 5,CONCAT22(uVar29 >> 5,uVar8 >> 5)))
                        & uVar25,uVar7);
        uVar32 = pmulhw(CONCAT26(uVar31 * 2,CONCAT24(uVar30 * 2,CONCAT22(uVar29 * 2,uVar8 * 2))) &
                        uVar25,uVar7);
        uVar24 = pmulhw(CONCAT26(uVar31 >> 10,
                                 CONCAT24(uVar30 >> 10,CONCAT22(uVar29 >> 10,uVar8 >> 10))) & uVar25
                        ,uVar7);
        uVar27 = psllw(CONCAT26((short)((ulonglong)uVar26 >> 0x30) + sVar18,
                                CONCAT24((short)((ulonglong)uVar26 >> 0x20) + sVar17,
                                         CONCAT22((short)((ulonglong)uVar26 >> 0x10) + sVar16,
                                                  (short)uVar26 + sVar14))),6);
        uVar25 = psllw(CONCAT26((short)((ulonglong)uVar24 >> 0x30) + sVar13,
                                CONCAT24((short)((ulonglong)uVar24 >> 0x20) + sVar12,
                                         CONCAT22((short)((ulonglong)uVar24 >> 0x10) + sVar11,
                                                  (short)uVar24 + sVar9))),0xb);
        *(ulonglong *)(iVar4 + (int)puVar5) =
             *(ulonglong *)(iVar4 + (int)puVar5) & *(ulonglong *)(&DAT_1008e0c0 + (uVar1 & 7) * 4) |
             ~*(ulonglong *)(&DAT_1008e0c0 + (uVar1 & 7) * 4) &
             (uVar27 | CONCAT26((short)((ulonglong)uVar32 >> 0x30) + sVar23,
                                CONCAT24((short)((ulonglong)uVar32 >> 0x20) + sVar22,
                                         CONCAT22((short)((ulonglong)uVar32 >> 0x10) + sVar21,
                                                  (short)uVar32 + sVar19))) | uVar25);
        uVar25 = DAT_1008e028;
        while (bVar3 = iVar4 < -8, iVar4 = iVar4 + 8, bVar3) {
          uVar24 = *(undefined8 *)(iVar4 + (int)puVar5);
          uVar8 = (ushort)uVar24;
          uVar29 = (ushort)((ulonglong)uVar24 >> 0x10);
          uVar30 = (ushort)((ulonglong)uVar24 >> 0x20);
          uVar31 = (ushort)((ulonglong)uVar24 >> 0x30);
          uVar26 = pmulhw(CONCAT26(uVar31 >> 5,
                                   CONCAT24(uVar30 >> 5,CONCAT22(uVar29 >> 5,uVar8 >> 5))) & uVar25,
                          uVar7);
          uVar32 = pmulhw(CONCAT26(uVar31 * 2,CONCAT24(uVar30 * 2,CONCAT22(uVar29 * 2,uVar8 * 2))) &
                          uVar25,uVar7);
          uVar24 = pmulhw(CONCAT26(uVar31 >> 10,
                                   CONCAT24(uVar30 >> 10,CONCAT22(uVar29 >> 10,uVar8 >> 10))) &
                          uVar25,uVar7);
          uVar28 = psllw(CONCAT26((short)((ulonglong)uVar26 >> 0x30) + sVar18,
                                  CONCAT24((short)((ulonglong)uVar26 >> 0x20) + sVar17,
                                           CONCAT22((short)((ulonglong)uVar26 >> 0x10) + sVar16,
                                                    (short)uVar26 + sVar14))),6);
          uVar27 = psllw(CONCAT26((short)((ulonglong)uVar24 >> 0x30) + sVar13,
                                  CONCAT24((short)((ulonglong)uVar24 >> 0x20) + sVar12,
                                           CONCAT22((short)((ulonglong)uVar24 >> 0x10) + sVar11,
                                                    (short)uVar24 + sVar9))),0xb);
          *(ulonglong *)(iVar4 + (int)puVar5) =
               uVar28 | CONCAT26((short)((ulonglong)uVar32 >> 0x30) + sVar23,
                                 CONCAT24((short)((ulonglong)uVar32 >> 0x20) + sVar22,
                                          CONCAT22((short)((ulonglong)uVar32 >> 0x10) + sVar21,
                                                   (short)uVar32 + sVar19))) | uVar27;
        }
        uVar24 = *(undefined8 *)(iVar4 + (int)puVar5);
        uVar8 = (ushort)uVar24;
        uVar29 = (ushort)((ulonglong)uVar24 >> 0x10);
        uVar30 = (ushort)((ulonglong)uVar24 >> 0x20);
        uVar31 = (ushort)((ulonglong)uVar24 >> 0x30);
        uVar26 = pmulhw(CONCAT26(uVar31 >> 5,CONCAT24(uVar30 >> 5,CONCAT22(uVar29 >> 5,uVar8 >> 5)))
                        & uVar25,uVar7);
        uVar32 = pmulhw(CONCAT26(uVar31 * 2,CONCAT24(uVar30 * 2,CONCAT22(uVar29 * 2,uVar8 * 2))) &
                        uVar25,uVar7);
        uVar24 = pmulhw(CONCAT26(uVar31 >> 10,
                                 CONCAT24(uVar30 >> 10,CONCAT22(uVar29 >> 10,uVar8 >> 10))) & uVar25
                        ,uVar7);
        uVar27 = psllw(CONCAT26((short)((ulonglong)uVar26 >> 0x30) + sVar18,
                                CONCAT24((short)((ulonglong)uVar26 >> 0x20) + sVar17,
                                         CONCAT22((short)((ulonglong)uVar26 >> 0x10) + sVar16,
                                                  (short)uVar26 + sVar14))),6);
        uVar25 = psllw(CONCAT26((short)((ulonglong)uVar24 >> 0x30) + sVar13,
                                CONCAT24((short)((ulonglong)uVar24 >> 0x20) + sVar12,
                                         CONCAT22((short)((ulonglong)uVar24 >> 0x10) + sVar11,
                                                  (short)uVar24 + sVar9))),0xb);
        *(ulonglong *)(iVar4 + (int)puVar5) =
             *(ulonglong *)(iVar4 + (int)puVar5) & *(ulonglong *)(&DAT_1008e040 + (uVar2 & 7) * 4) |
             ~*(ulonglong *)(&DAT_1008e040 + (uVar2 & 7) * 4) &
             (uVar27 | CONCAT26((short)((ulonglong)uVar32 >> 0x30) + sVar23,
                                CONCAT24((short)((ulonglong)uVar32 >> 0x20) + sVar22,
                                         CONCAT22((short)((ulonglong)uVar32 >> 0x10) + sVar21,
                                                  (short)uVar32 + sVar19))) | uVar25);
        uVar25 = DAT_1008e028;
      }
    }
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


