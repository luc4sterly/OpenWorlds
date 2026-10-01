// 10078a84 FUN_10078a84 [Global]
// program: rwdlmd21.dll

undefined8 __fastcall FUN_10078a84(undefined4 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  bool bVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  uint extraout_EDX;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  ushort uVar12;
  ulonglong uVar10;
  ushort uVar13;
  ulonglong uVar11;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  
  uVar9 = ((short)DAT_1008d2b8 - (short)DAT_1008d59c) * 2 |
          (ushort)((uint)(DAT_1008d2bc - DAT_1008d59c) >> 5) |
          ((short)DAT_1008d2b4 - (short)DAT_1008d59c) * 0x40;
  uVar10 = CONCAT44(CONCAT22(uVar9,uVar9),CONCAT22(uVar9,uVar9));
  uVar15 = psllw(uVar10,6);
  DAT_1008e1d8 = uVar10 & DAT_1008e258;
  DAT_1008e1e0 = uVar15 & DAT_1008e258;
  DAT_1008e1d0 = CONCAT26(uVar9 >> 5,CONCAT24(uVar9 >> 5,CONCAT22(uVar9 >> 5,uVar9 >> 5))) &
                 DAT_1008e258;
  do {
    iVar6 = DAT_1008d294;
    DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0 & 0x7fff7fff;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar5 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    uVar4 = DAT_1008d284 >> 0x10;
    if (uVar5 < uVar4) {
      FUN_100780dd(uVar5 - uVar4);
      uVar15 = DAT_1008e268;
      uVar10 = DAT_1008e250;
      uVar3 = DAT_1008dbe0;
      uVar8 = iVar6 - 2U & 0xfffffff8;
      iVar6 = (uVar5 & 0xfffffff8) - uVar8;
      do {
        uVar11 = *(ulonglong *)(iVar6 + (extraout_EDX & 0xfffffff8));
        uVar9 = (ushort)(uVar11 >> 0x10);
        uVar12 = (ushort)(uVar11 >> 0x20);
        uVar13 = (ushort)(uVar11 >> 0x30);
        uVar16 = uVar11 & uVar15;
        uVar14 = CONCAT26(uVar13 >> 6,CONCAT24(uVar12 >> 6,CONCAT22(uVar9 >> 6,(ushort)uVar11 >> 6))
                         ) & uVar15;
        uVar1 = *(undefined8 *)(iVar6 + (extraout_EDX & 0xfffffff8));
        uVar14 = CONCAT26((short)(uVar14 >> 0x30) * (short)(DAT_1008e1d8 >> 0x30),
                          CONCAT24((short)(uVar14 >> 0x20) * (short)(DAT_1008e1d8 >> 0x20),
                                   CONCAT22((short)(uVar14 >> 0x10) * (short)(DAT_1008e1d8 >> 0x10),
                                            (short)uVar14 * (short)DAT_1008e1d8))) & uVar10;
        uVar17 = CONCAT26(-(ushort)((short)((ulonglong)uVar1 >> 0x30) ==
                                   (short)((ulonglong)DAT_1008e008 >> 0x30)),
                          CONCAT24(-(ushort)((short)((ulonglong)uVar1 >> 0x20) ==
                                            (short)((ulonglong)DAT_1008e008 >> 0x20)),
                                   CONCAT22(-(ushort)((short)((ulonglong)uVar1 >> 0x10) ==
                                                     (short)((ulonglong)DAT_1008e008 >> 0x10)),
                                            -(ushort)((short)uVar1 == (short)DAT_1008e008))));
        uVar11 = CONCAT26((uVar13 >> 0xb) * (short)(DAT_1008e1d0 >> 0x30),
                          CONCAT24((uVar12 >> 0xb) * (short)(DAT_1008e1d0 >> 0x20),
                                   CONCAT22((uVar9 >> 0xb) * (short)(DAT_1008e1d0 >> 0x10),
                                            ((ushort)uVar11 >> 0xb) * (short)DAT_1008e1d0))) &
                 uVar10 | CONCAT26((ushort)((short)(uVar16 >> 0x30) * (short)(DAT_1008e1e0 >> 0x30))
                                   >> 0xb,CONCAT24((ushort)((short)(uVar16 >> 0x20) *
                                                           (short)(DAT_1008e1e0 >> 0x20)) >> 0xb,
                                                   CONCAT22((ushort)((short)(uVar16 >> 0x10) *
                                                                    (short)(DAT_1008e1e0 >> 0x10))
                                                            >> 0xb,(ushort)((short)uVar16 *
                                                                           (short)DAT_1008e1e0) >>
                                                                   0xb))) |
                 CONCAT26((ushort)(uVar14 >> 0x35),
                          CONCAT24((ushort)(uVar14 >> 0x20) >> 5,
                                   CONCAT22((ushort)(uVar14 >> 0x10) >> 5,(ushort)uVar14 >> 5)));
        *(ulonglong *)(iVar6 + uVar8) =
             *(ulonglong *)(iVar6 + uVar8) & uVar17 |
             ~uVar17 & CONCAT26((short)(uVar11 >> 0x30) + (short)((ulonglong)uVar3 >> 0x30),
                                CONCAT24((short)(uVar11 >> 0x20) + (short)((ulonglong)uVar3 >> 0x20)
                                         ,CONCAT22((short)(uVar11 >> 0x10) +
                                                   (short)((ulonglong)uVar3 >> 0x10),
                                                   (short)uVar11 + (short)uVar3)));
        iVar7 = iVar6 + 8;
        bVar2 = iVar6 < -8;
        uVar4 = uVar5;
        iVar6 = iVar7;
      } while (iVar7 == 0 || bVar2);
    }
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return CONCAT44(param_2,uVar4);
}


