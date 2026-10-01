// 1007889c FUN_1007889c [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_1007889c(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  bool bVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  uint extraout_EDX;
  int iVar7;
  int iVar8;
  uint uVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ushort uVar18;
  ushort uVar19;
  ushort uVar20;
  ulonglong uVar17;
  ulonglong uVar21;
  ulonglong uVar22;
  short sVar23;
  short sVar24;
  short sVar25;
  short sVar26;
  ulonglong uVar27;
  
  sVar23 = (ushort)DAT_1008d2a8 * 8;
  uVar10 = ((short)DAT_1008d2b8 - (short)DAT_1008d59c) * 2 |
           (ushort)((uint)(DAT_1008d2bc - DAT_1008d59c) >> 5) |
           ((short)DAT_1008d2b4 - (short)DAT_1008d59c) * 0x40;
  uVar13 = CONCAT26(uVar10 >> 6,CONCAT24(uVar10 >> 6,CONCAT22(uVar10 >> 6,uVar10 >> 6))) &
           DAT_1008e038;
  uVar15 = CONCAT44(CONCAT22(uVar10,uVar10),CONCAT22(uVar10,uVar10)) & DAT_1008e038;
  DAT_1008e1d0 = CONCAT26((ushort)((uVar10 >> 0xb) * sVar23) >> 5,
                          CONCAT24((ushort)((uVar10 >> 0xb) * sVar23) >> 5,
                                   CONCAT22((ushort)((uVar10 >> 0xb) * sVar23) >> 5,
                                            (ushort)((uVar10 >> 0xb) * sVar23) >> 5)));
  DAT_1008e1d8 = CONCAT26((ushort)((short)(uVar13 >> 0x30) * sVar23) >> 5,
                          CONCAT24((ushort)((short)(uVar13 >> 0x20) * sVar23) >> 5,
                                   CONCAT22((ushort)((short)(uVar13 >> 0x10) * sVar23) >> 5,
                                            (ushort)((short)uVar13 * sVar23) >> 5)));
  DAT_1008e1e0 = CONCAT26((ushort)((short)(uVar15 >> 0x30) * sVar23) >> 5,
                          CONCAT24((ushort)((short)(uVar15 >> 0x20) * sVar23) >> 5,
                                   CONCAT22((ushort)((short)(uVar15 >> 0x10) * sVar23) >> 5,
                                            (ushort)((short)uVar15 * sVar23) >> 5)));
  uVar13 = CONCAT44(CONCAT22(sVar23,sVar23),CONCAT22(sVar23,sVar23)) ^ _DAT_1008e018;
  do {
    iVar7 = DAT_1008d294;
    DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0 & 0x7fff7fff;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar6 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    uVar5 = DAT_1008d284 >> 0x10;
    if (uVar6 < uVar5) {
      FUN_100780dd(uVar6 - uVar5);
      uVar9 = iVar7 - 2U & 0xfffffff8;
      iVar7 = (uVar6 & 0xfffffff8) - uVar9;
      uVar15 = DAT_1008e038;
      do {
        uVar4 = DAT_1008e038;
        uVar17 = *(ulonglong *)(iVar7 + (extraout_EDX & 0xfffffff8));
        uVar10 = (ushort)(uVar17 >> 0x10);
        uVar11 = (ushort)(uVar17 >> 0x20);
        uVar12 = (ushort)(uVar17 >> 0x30);
        uVar16 = uVar17 & uVar15;
        uVar14 = CONCAT26(uVar12 >> 6,
                          CONCAT24(uVar11 >> 6,CONCAT22(uVar10 >> 6,(ushort)uVar17 >> 6))) & uVar15;
        uVar1 = *(ulonglong *)(iVar7 + uVar9);
        uVar18 = (ushort)(uVar1 >> 0x10);
        uVar19 = (ushort)(uVar1 >> 0x20);
        uVar20 = (ushort)(uVar1 >> 0x30);
        uVar22 = uVar1 & uVar15;
        sVar23 = (short)uVar13;
        sVar24 = (short)(uVar13 >> 0x10);
        sVar25 = (short)(uVar13 >> 0x20);
        sVar26 = (short)(uVar13 >> 0x30);
        uVar21 = CONCAT26(uVar20 >> 6,CONCAT24(uVar19 >> 6,CONCAT22(uVar18 >> 6,(ushort)uVar1 >> 6))
                         ) & uVar15;
        uVar27 = psllw(uVar15,0xb);
        uVar15 = CONCAT26((short)(uVar14 >> 0x30) * (short)((ulonglong)DAT_1008e1d8 >> 0x30) +
                          (short)(uVar21 >> 0x30) * sVar26,
                          CONCAT24((short)(uVar14 >> 0x20) *
                                   (short)((ulonglong)DAT_1008e1d8 >> 0x20) +
                                   (short)(uVar21 >> 0x20) * sVar25,
                                   CONCAT22((short)(uVar14 >> 0x10) *
                                            (short)((ulonglong)DAT_1008e1d8 >> 0x10) +
                                            (short)(uVar21 >> 0x10) * sVar24,
                                            (short)uVar14 * (short)DAT_1008e1d8 +
                                            (short)uVar21 * sVar23))) & uVar27;
        uVar2 = *(undefined8 *)(iVar7 + (extraout_EDX & 0xfffffff8));
        uVar15 = CONCAT26((uVar12 >> 0xb) * (short)((ulonglong)DAT_1008e1d0 >> 0x30) +
                          (uVar20 >> 0xb) * sVar26,
                          CONCAT24((uVar11 >> 0xb) * (short)((ulonglong)DAT_1008e1d0 >> 0x20) +
                                   (uVar19 >> 0xb) * sVar25,
                                   CONCAT22((uVar10 >> 0xb) *
                                            (short)((ulonglong)DAT_1008e1d0 >> 0x10) +
                                            (uVar18 >> 0xb) * sVar24,
                                            ((ushort)uVar17 >> 0xb) * (short)DAT_1008e1d0 +
                                            ((ushort)uVar1 >> 0xb) * sVar23))) & uVar27 |
                 CONCAT26((ushort)((short)(uVar16 >> 0x30) *
                                   (short)((ulonglong)DAT_1008e1e0 >> 0x30) +
                                  (short)(uVar22 >> 0x30) * sVar26) >> 0xb,
                          CONCAT24((ushort)((short)(uVar16 >> 0x20) *
                                            (short)((ulonglong)DAT_1008e1e0 >> 0x20) +
                                           (short)(uVar22 >> 0x20) * sVar25) >> 0xb,
                                   CONCAT22((ushort)((short)(uVar16 >> 0x10) *
                                                     (short)((ulonglong)DAT_1008e1e0 >> 0x10) +
                                                    (short)(uVar22 >> 0x10) * sVar24) >> 0xb,
                                            (ushort)((short)uVar16 * (short)DAT_1008e1e0 +
                                                    (short)uVar22 * sVar23) >> 0xb))) |
                 CONCAT26((ushort)(uVar15 >> 0x35),
                          CONCAT24((ushort)(uVar15 >> 0x20) >> 5,
                                   CONCAT22((ushort)(uVar15 >> 0x10) >> 5,(ushort)uVar15 >> 5)));
        uVar17 = CONCAT26(-(ushort)((short)((ulonglong)uVar2 >> 0x30) ==
                                   (short)((ulonglong)DAT_1008e008 >> 0x30)),
                          CONCAT24(-(ushort)((short)((ulonglong)uVar2 >> 0x20) ==
                                            (short)((ulonglong)DAT_1008e008 >> 0x20)),
                                   CONCAT22(-(ushort)((short)((ulonglong)uVar2 >> 0x10) ==
                                                     (short)((ulonglong)DAT_1008e008 >> 0x10)),
                                            -(ushort)((short)uVar2 == (short)DAT_1008e008))));
        *(ulonglong *)(iVar7 + uVar9) =
             *(ulonglong *)(iVar7 + uVar9) & uVar17 |
             ~uVar17 & CONCAT26((short)(uVar15 >> 0x30) + (short)((ulonglong)DAT_1008dbe0 >> 0x30),
                                CONCAT24((short)(uVar15 >> 0x20) +
                                         (short)((ulonglong)DAT_1008dbe0 >> 0x20),
                                         CONCAT22((short)(uVar15 >> 0x10) +
                                                  (short)((ulonglong)DAT_1008dbe0 >> 0x10),
                                                  (short)uVar15 + (short)DAT_1008dbe0)));
        iVar8 = iVar7 + 8;
        bVar3 = iVar7 < -8;
        uVar5 = uVar6;
        iVar7 = iVar8;
        uVar15 = uVar4;
      } while (iVar8 == 0 || bVar3);
    }
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return CONCAT44(param_2,uVar5);
}


