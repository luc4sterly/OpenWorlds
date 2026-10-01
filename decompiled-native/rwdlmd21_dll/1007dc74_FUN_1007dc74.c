// 1007dc74 FUN_1007dc74 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1007dc74(void)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  bool bVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  uint uVar13;
  int iVar14;
  uint extraout_EDX;
  int iVar15;
  uint uVar16;
  ushort uVar17;
  ushort uVar18;
  ushort uVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  ushort uVar23;
  ushort uVar24;
  ushort uVar25;
  ulonglong uVar26;
  short sVar27;
  short sVar28;
  undefined4 uVar29;
  short sVar31;
  short sVar32;
  short sVar33;
  short sVar34;
  short sVar35;
  ulonglong uVar30;
  short sVar36;
  ulonglong uVar37;
  
  uVar29 = CONCAT22((ushort)DAT_1008d2a8 << 3,(ushort)DAT_1008d2a8 << 3);
  DAT_1008f3b0 = CONCAT44(uVar29,uVar29);
  do {
    iVar15 = DAT_1008d294;
    DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar13 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    iVar14 = uVar13 - (DAT_1008d284 >> 0x10);
    fVar7 = _DAT_1008d440 + _DAT_1008d444;
    fVar8 = _DAT_1008d448 + _DAT_1008d44c;
    fVar9 = _DAT_1008d450 + _DAT_1008d454;
    fVar10 = _DAT_1008d458 + _DAT_1008d45c;
    fVar11 = _DAT_1008d460 + _DAT_1008d464;
    fVar12 = _DAT_1008d468 + _DAT_1008d46c;
    if (uVar13 < DAT_1008d284 >> 0x10) {
      FUN_1007d650(iVar14);
      FUN_1007da2f(iVar14);
      uVar6 = DAT_1008f3b0;
      uVar16 = iVar15 - 2U & 0xfffffff8;
      iVar15 = (uVar13 & 0xfffffff8) - uVar16;
      uVar21 = DAT_1008e038;
      do {
        uVar5 = DAT_1008e038;
        uVar1 = *(ulonglong *)(iVar15 + (extraout_EDX & 0xfffffff8));
        uVar17 = (ushort)(uVar1 >> 0x10);
        uVar18 = (ushort)(uVar1 >> 0x20);
        uVar19 = (ushort)(uVar1 >> 0x30);
        uVar22 = uVar1 & uVar21;
        sVar27 = (short)uVar6;
        sVar31 = (short)(uVar6 >> 0x10);
        sVar33 = (short)(uVar6 >> 0x20);
        sVar35 = (short)(uVar6 >> 0x30);
        uVar20 = CONCAT26(uVar19 >> 6,CONCAT24(uVar18 >> 6,CONCAT22(uVar17 >> 6,(ushort)uVar1 >> 6))
                         ) & uVar21;
        uVar2 = *(ulonglong *)(iVar15 + uVar16);
        uVar30 = uVar6 ^ _DAT_1008e018;
        uVar23 = (ushort)(uVar2 >> 0x10);
        uVar24 = (ushort)(uVar2 >> 0x20);
        uVar25 = (ushort)(uVar2 >> 0x30);
        uVar26 = uVar2 & uVar21;
        sVar28 = (short)uVar30;
        sVar32 = (short)(uVar30 >> 0x10);
        sVar34 = (short)(uVar30 >> 0x20);
        sVar36 = (short)(uVar30 >> 0x30);
        uVar30 = CONCAT26(uVar25 >> 6,CONCAT24(uVar24 >> 6,CONCAT22(uVar23 >> 6,(ushort)uVar2 >> 6))
                         ) & uVar21;
        uVar37 = psllw(uVar21,0xb);
        uVar21 = CONCAT26((short)(uVar20 >> 0x30) * sVar35 + (short)(uVar30 >> 0x30) * sVar36,
                          CONCAT24((short)(uVar20 >> 0x20) * sVar33 +
                                   (short)(uVar30 >> 0x20) * sVar34,
                                   CONCAT22((short)(uVar20 >> 0x10) * sVar31 +
                                            (short)(uVar30 >> 0x10) * sVar32,
                                            (short)uVar20 * sVar27 + (short)uVar30 * sVar28))) &
                 uVar37;
        uVar3 = *(undefined8 *)(iVar15 + (extraout_EDX & 0xfffffff8));
        uVar20 = CONCAT26(-(ushort)((short)((ulonglong)uVar3 >> 0x30) ==
                                   (short)((ulonglong)DAT_1008e008 >> 0x30)),
                          CONCAT24(-(ushort)((short)((ulonglong)uVar3 >> 0x20) ==
                                            (short)((ulonglong)DAT_1008e008 >> 0x20)),
                                   CONCAT22(-(ushort)((short)((ulonglong)uVar3 >> 0x10) ==
                                                     (short)((ulonglong)DAT_1008e008 >> 0x10)),
                                            -(ushort)((short)uVar3 == (short)DAT_1008e008))));
        *(ulonglong *)(iVar15 + uVar16) =
             *(ulonglong *)(iVar15 + uVar16) & uVar20 |
             ~uVar20 & (CONCAT26((uVar19 >> 0xb) * sVar35 + (uVar25 >> 0xb) * sVar36,
                                 CONCAT24((uVar18 >> 0xb) * sVar33 + (uVar24 >> 0xb) * sVar34,
                                          CONCAT22((uVar17 >> 0xb) * sVar31 +
                                                   (uVar23 >> 0xb) * sVar32,
                                                   ((ushort)uVar1 >> 0xb) * sVar27 +
                                                   ((ushort)uVar2 >> 0xb) * sVar28))) & uVar37 |
                        CONCAT26((ushort)((short)(uVar22 >> 0x30) * sVar35 +
                                         (short)(uVar26 >> 0x30) * sVar36) >> 0xb,
                                 CONCAT24((ushort)((short)(uVar22 >> 0x20) * sVar33 +
                                                  (short)(uVar26 >> 0x20) * sVar34) >> 0xb,
                                          CONCAT22((ushort)((short)(uVar22 >> 0x10) * sVar31 +
                                                           (short)(uVar26 >> 0x10) * sVar32) >> 0xb,
                                                   (ushort)((short)uVar22 * sVar27 +
                                                           (short)uVar26 * sVar28) >> 0xb))) |
                       CONCAT26((ushort)(uVar21 >> 0x35),
                                CONCAT24((ushort)(uVar21 >> 0x20) >> 5,
                                         CONCAT22((ushort)(uVar21 >> 0x10) >> 5,(ushort)uVar21 >> 5)
                                        )));
        iVar14 = iVar15 + 8;
        bVar4 = iVar15 < -8;
        iVar15 = iVar14;
        uVar21 = uVar5;
        fVar7 = _DAT_1008d440;
        fVar8 = _DAT_1008d448;
        fVar9 = _DAT_1008d450;
        fVar10 = _DAT_1008d458;
        fVar11 = _DAT_1008d460;
        fVar12 = _DAT_1008d468;
      } while (iVar14 == 0 || bVar4);
    }
    _DAT_1008d468 = fVar12;
    _DAT_1008d460 = fVar11;
    _DAT_1008d458 = fVar10;
    _DAT_1008d450 = fVar9;
    _DAT_1008d448 = fVar8;
    _DAT_1008d440 = fVar7;
    DAT_1008d29c = DAT_1008d29c + DAT_1008d2a0;
    DAT_1008d294 = DAT_1008d298 + DAT_1008d294;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


