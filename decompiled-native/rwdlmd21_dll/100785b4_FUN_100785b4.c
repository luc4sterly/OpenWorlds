// 100785b4 FUN_100785b4 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_100785b4(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  bool bVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  uint extraout_EDX;
  int iVar8;
  int iVar9;
  uint uVar10;
  ushort uVar11;
  ushort uVar12;
  ushort uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ushort uVar17;
  ushort uVar18;
  ushort uVar19;
  ulonglong uVar20;
  short sVar21;
  short sVar22;
  undefined4 uVar23;
  short sVar27;
  short sVar28;
  short sVar29;
  ulonglong uVar24;
  short sVar26;
  short sVar30;
  ulonglong uVar25;
  short sVar31;
  ulonglong uVar32;
  
  uVar23 = CONCAT22((ushort)DAT_1008d2a8 << 3,(ushort)DAT_1008d2a8 << 3);
  uVar24 = CONCAT44(uVar23,uVar23);
  do {
    iVar8 = DAT_1008d294;
    DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0 & 0x7fff7fff;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar7 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    uVar6 = DAT_1008d284 >> 0x10;
    if (uVar7 < uVar6) {
      FUN_100780dd(uVar7 - uVar6);
      uVar10 = iVar8 - 2U & 0xfffffff8;
      iVar8 = (uVar7 & 0xfffffff8) - uVar10;
      uVar15 = DAT_1008e038;
      do {
        uVar5 = DAT_1008e038;
        uVar1 = *(ulonglong *)(iVar8 + (extraout_EDX & 0xfffffff8));
        uVar11 = (ushort)(uVar1 >> 0x10);
        uVar12 = (ushort)(uVar1 >> 0x20);
        uVar13 = (ushort)(uVar1 >> 0x30);
        uVar16 = uVar1 & uVar15;
        sVar21 = (short)uVar24;
        sVar26 = (short)(uVar24 >> 0x10);
        sVar28 = (short)(uVar24 >> 0x20);
        sVar30 = (short)(uVar24 >> 0x30);
        uVar14 = CONCAT26(uVar13 >> 6,CONCAT24(uVar12 >> 6,CONCAT22(uVar11 >> 6,(ushort)uVar1 >> 6))
                         ) & uVar15;
        uVar2 = *(ulonglong *)(iVar8 + uVar10);
        uVar25 = uVar24 ^ _DAT_1008e018;
        uVar17 = (ushort)(uVar2 >> 0x10);
        uVar18 = (ushort)(uVar2 >> 0x20);
        uVar19 = (ushort)(uVar2 >> 0x30);
        uVar20 = uVar2 & uVar15;
        sVar22 = (short)uVar25;
        sVar27 = (short)(uVar25 >> 0x10);
        sVar29 = (short)(uVar25 >> 0x20);
        sVar31 = (short)(uVar25 >> 0x30);
        uVar25 = CONCAT26(uVar19 >> 6,CONCAT24(uVar18 >> 6,CONCAT22(uVar17 >> 6,(ushort)uVar2 >> 6))
                         ) & uVar15;
        uVar32 = psllw(uVar15,0xb);
        uVar15 = CONCAT26((short)(uVar14 >> 0x30) * sVar30 + (short)(uVar25 >> 0x30) * sVar31,
                          CONCAT24((short)(uVar14 >> 0x20) * sVar28 +
                                   (short)(uVar25 >> 0x20) * sVar29,
                                   CONCAT22((short)(uVar14 >> 0x10) * sVar26 +
                                            (short)(uVar25 >> 0x10) * sVar27,
                                            (short)uVar14 * sVar21 + (short)uVar25 * sVar22))) &
                 uVar32;
        uVar3 = *(undefined8 *)(iVar8 + (extraout_EDX & 0xfffffff8));
        uVar14 = CONCAT26(-(ushort)((short)((ulonglong)uVar3 >> 0x30) ==
                                   (short)((ulonglong)DAT_1008e008 >> 0x30)),
                          CONCAT24(-(ushort)((short)((ulonglong)uVar3 >> 0x20) ==
                                            (short)((ulonglong)DAT_1008e008 >> 0x20)),
                                   CONCAT22(-(ushort)((short)((ulonglong)uVar3 >> 0x10) ==
                                                     (short)((ulonglong)DAT_1008e008 >> 0x10)),
                                            -(ushort)((short)uVar3 == (short)DAT_1008e008))));
        *(ulonglong *)(iVar8 + uVar10) =
             *(ulonglong *)(iVar8 + uVar10) & uVar14 |
             ~uVar14 & (CONCAT26((uVar13 >> 0xb) * sVar30 + (uVar19 >> 0xb) * sVar31,
                                 CONCAT24((uVar12 >> 0xb) * sVar28 + (uVar18 >> 0xb) * sVar29,
                                          CONCAT22((uVar11 >> 0xb) * sVar26 +
                                                   (uVar17 >> 0xb) * sVar27,
                                                   ((ushort)uVar1 >> 0xb) * sVar21 +
                                                   ((ushort)uVar2 >> 0xb) * sVar22))) & uVar32 |
                        CONCAT26((ushort)((short)(uVar16 >> 0x30) * sVar30 +
                                         (short)(uVar20 >> 0x30) * sVar31) >> 0xb,
                                 CONCAT24((ushort)((short)(uVar16 >> 0x20) * sVar28 +
                                                  (short)(uVar20 >> 0x20) * sVar29) >> 0xb,
                                          CONCAT22((ushort)((short)(uVar16 >> 0x10) * sVar26 +
                                                           (short)(uVar20 >> 0x10) * sVar27) >> 0xb,
                                                   (ushort)((short)uVar16 * sVar21 +
                                                           (short)uVar20 * sVar22) >> 0xb))) |
                       CONCAT26((ushort)(uVar15 >> 0x35),
                                CONCAT24((ushort)(uVar15 >> 0x20) >> 5,
                                         CONCAT22((ushort)(uVar15 >> 0x10) >> 5,(ushort)uVar15 >> 5)
                                        )));
        iVar9 = iVar8 + 8;
        bVar4 = iVar8 < -8;
        uVar6 = uVar7;
        iVar8 = iVar9;
        uVar15 = uVar5;
      } while (iVar9 == 0 || bVar4);
    }
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return CONCAT44(param_2,uVar6);
}


