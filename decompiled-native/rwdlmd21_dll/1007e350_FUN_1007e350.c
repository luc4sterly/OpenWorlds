// 1007e350 FUN_1007e350 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1007e350(void)

{
  undefined8 uVar1;
  bool bVar2;
  undefined8 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  uint uVar10;
  uint extraout_EDX;
  int iVar11;
  int iVar12;
  uint uVar13;
  ushort uVar14;
  ushort uVar17;
  ulonglong uVar15;
  ushort uVar18;
  ulonglong uVar16;
  ulonglong uVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  
  uVar14 = ((short)DAT_1008d2b8 - (short)DAT_1008d59c) * 2 |
           (ushort)((uint)(DAT_1008d2bc - DAT_1008d59c) >> 5) |
           ((short)DAT_1008d2b4 - (short)DAT_1008d59c) * 0x40;
  uVar15 = CONCAT44(CONCAT22(uVar14,uVar14),CONCAT22(uVar14,uVar14));
  uVar20 = psllw(uVar15,6);
  DAT_1008e1d8 = uVar15 & DAT_1008e258;
  DAT_1008e1e0 = uVar20 & DAT_1008e258;
  DAT_1008e1d0 = CONCAT26(uVar14 >> 5,CONCAT24(uVar14 >> 5,CONCAT22(uVar14 >> 5,uVar14 >> 5))) &
                 DAT_1008e258;
  do {
    iVar11 = DAT_1008d294;
    DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar10 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    fVar4 = _DAT_1008d440 + _DAT_1008d444;
    fVar5 = _DAT_1008d448 + _DAT_1008d44c;
    fVar6 = _DAT_1008d450 + _DAT_1008d454;
    fVar7 = _DAT_1008d458 + _DAT_1008d45c;
    fVar8 = _DAT_1008d460 + _DAT_1008d464;
    fVar9 = _DAT_1008d468 + _DAT_1008d46c;
    if (uVar10 < DAT_1008d284 >> 0x10) {
      FUN_1007d650(uVar10 - (DAT_1008d284 >> 0x10));
      uVar20 = DAT_1008e268;
      uVar15 = DAT_1008e250;
      uVar3 = DAT_1008dbe0;
      uVar13 = iVar11 - 2U & 0xfffffff8;
      iVar11 = (uVar10 & 0xfffffff8) - uVar13;
      do {
        uVar16 = *(ulonglong *)(iVar11 + (extraout_EDX & 0xfffffff8));
        uVar14 = (ushort)(uVar16 >> 0x10);
        uVar17 = (ushort)(uVar16 >> 0x20);
        uVar18 = (ushort)(uVar16 >> 0x30);
        uVar21 = uVar16 & uVar20;
        uVar19 = CONCAT26(uVar18 >> 6,
                          CONCAT24(uVar17 >> 6,CONCAT22(uVar14 >> 6,(ushort)uVar16 >> 6))) & uVar20;
        uVar1 = *(undefined8 *)(iVar11 + (extraout_EDX & 0xfffffff8));
        uVar19 = CONCAT26((short)(uVar19 >> 0x30) * (short)(DAT_1008e1d8 >> 0x30),
                          CONCAT24((short)(uVar19 >> 0x20) * (short)(DAT_1008e1d8 >> 0x20),
                                   CONCAT22((short)(uVar19 >> 0x10) * (short)(DAT_1008e1d8 >> 0x10),
                                            (short)uVar19 * (short)DAT_1008e1d8))) & uVar15;
        uVar22 = CONCAT26(-(ushort)((short)((ulonglong)uVar1 >> 0x30) ==
                                   (short)((ulonglong)DAT_1008e008 >> 0x30)),
                          CONCAT24(-(ushort)((short)((ulonglong)uVar1 >> 0x20) ==
                                            (short)((ulonglong)DAT_1008e008 >> 0x20)),
                                   CONCAT22(-(ushort)((short)((ulonglong)uVar1 >> 0x10) ==
                                                     (short)((ulonglong)DAT_1008e008 >> 0x10)),
                                            -(ushort)((short)uVar1 == (short)DAT_1008e008))));
        uVar16 = CONCAT26((uVar18 >> 0xb) * (short)(DAT_1008e1d0 >> 0x30),
                          CONCAT24((uVar17 >> 0xb) * (short)(DAT_1008e1d0 >> 0x20),
                                   CONCAT22((uVar14 >> 0xb) * (short)(DAT_1008e1d0 >> 0x10),
                                            ((ushort)uVar16 >> 0xb) * (short)DAT_1008e1d0))) &
                 uVar15 | CONCAT26((ushort)((short)(uVar21 >> 0x30) * (short)(DAT_1008e1e0 >> 0x30))
                                   >> 0xb,CONCAT24((ushort)((short)(uVar21 >> 0x20) *
                                                           (short)(DAT_1008e1e0 >> 0x20)) >> 0xb,
                                                   CONCAT22((ushort)((short)(uVar21 >> 0x10) *
                                                                    (short)(DAT_1008e1e0 >> 0x10))
                                                            >> 0xb,(ushort)((short)uVar21 *
                                                                           (short)DAT_1008e1e0) >>
                                                                   0xb))) |
                 CONCAT26((ushort)(uVar19 >> 0x35),
                          CONCAT24((ushort)(uVar19 >> 0x20) >> 5,
                                   CONCAT22((ushort)(uVar19 >> 0x10) >> 5,(ushort)uVar19 >> 5)));
        *(ulonglong *)(iVar11 + uVar13) =
             *(ulonglong *)(iVar11 + uVar13) & uVar22 |
             ~uVar22 & CONCAT26((short)(uVar16 >> 0x30) + (short)((ulonglong)uVar3 >> 0x30),
                                CONCAT24((short)(uVar16 >> 0x20) + (short)((ulonglong)uVar3 >> 0x20)
                                         ,CONCAT22((short)(uVar16 >> 0x10) +
                                                   (short)((ulonglong)uVar3 >> 0x10),
                                                   (short)uVar16 + (short)uVar3)));
        iVar12 = iVar11 + 8;
        bVar2 = iVar11 < -8;
        iVar11 = iVar12;
        fVar4 = _DAT_1008d440;
        fVar5 = _DAT_1008d448;
        fVar6 = _DAT_1008d450;
        fVar7 = _DAT_1008d458;
        fVar8 = _DAT_1008d460;
        fVar9 = _DAT_1008d468;
      } while (iVar12 == 0 || bVar2);
    }
    _DAT_1008d468 = fVar9;
    _DAT_1008d460 = fVar8;
    _DAT_1008d458 = fVar7;
    _DAT_1008d450 = fVar6;
    _DAT_1008d448 = fVar5;
    _DAT_1008d440 = fVar4;
    DAT_1008d294 = DAT_1008d298 + DAT_1008d294;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


