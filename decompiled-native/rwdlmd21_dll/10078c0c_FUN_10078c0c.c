// 10078c0c FUN_10078c0c [Global]
// programa: rwdlmd21.dll

void FUN_10078c0c(void)

{
  undefined8 uVar1;
  bool bVar2;
  undefined8 uVar3;
  uint uVar4;
  uint extraout_EDX;
  int iVar5;
  int iVar6;
  uint uVar7;
  ushort uVar8;
  ushort uVar11;
  ulonglong uVar9;
  ushort uVar12;
  ulonglong uVar10;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  
  uVar8 = ((short)DAT_1008d2b8 - (short)DAT_1008d59c) * 2 |
          (ushort)((uint)(DAT_1008d2bc - DAT_1008d59c) >> 5) |
          ((short)DAT_1008d2b4 - (short)DAT_1008d59c) * 0x40;
  uVar9 = CONCAT44(CONCAT22(uVar8,uVar8),CONCAT22(uVar8,uVar8));
  uVar14 = psllw(uVar9,6);
  DAT_1008e1d8 = uVar9 & DAT_1008e258;
  DAT_1008e1e0 = uVar14 & DAT_1008e258;
  DAT_1008e1d0 = CONCAT26(uVar8 >> 5,CONCAT24(uVar8 >> 5,CONCAT22(uVar8 >> 5,uVar8 >> 5))) &
                 DAT_1008e258;
  do {
    iVar5 = DAT_1008d294;
    DAT_1008d2c0 = DAT_1008d2c4 + DAT_1008d2c0 & 0x7fff7fff;
    DAT_1008d2e4 = DAT_1008d2e8 + DAT_1008d2e4;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar4 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    if (uVar4 < DAT_1008d284 >> 0x10) {
      FUN_10078140(uVar4 - (DAT_1008d284 >> 0x10));
      uVar14 = DAT_1008e268;
      uVar9 = DAT_1008e250;
      uVar3 = DAT_1008dbe0;
      uVar7 = iVar5 - 2U & 0xfffffff8;
      iVar5 = (uVar4 & 0xfffffff8) - uVar7;
      do {
        uVar10 = *(ulonglong *)(iVar5 + (extraout_EDX & 0xfffffff8));
        uVar8 = (ushort)(uVar10 >> 0x10);
        uVar11 = (ushort)(uVar10 >> 0x20);
        uVar12 = (ushort)(uVar10 >> 0x30);
        uVar15 = uVar10 & uVar14;
        uVar13 = CONCAT26(uVar12 >> 6,CONCAT24(uVar11 >> 6,CONCAT22(uVar8 >> 6,(ushort)uVar10 >> 6))
                         ) & uVar14;
        uVar1 = *(undefined8 *)(iVar5 + (extraout_EDX & 0xfffffff8));
        uVar13 = CONCAT26((short)(uVar13 >> 0x30) * (short)(DAT_1008e1d8 >> 0x30),
                          CONCAT24((short)(uVar13 >> 0x20) * (short)(DAT_1008e1d8 >> 0x20),
                                   CONCAT22((short)(uVar13 >> 0x10) * (short)(DAT_1008e1d8 >> 0x10),
                                            (short)uVar13 * (short)DAT_1008e1d8))) & uVar9;
        uVar16 = CONCAT26(-(ushort)((short)((ulonglong)uVar1 >> 0x30) ==
                                   (short)((ulonglong)DAT_1008e008 >> 0x30)),
                          CONCAT24(-(ushort)((short)((ulonglong)uVar1 >> 0x20) ==
                                            (short)((ulonglong)DAT_1008e008 >> 0x20)),
                                   CONCAT22(-(ushort)((short)((ulonglong)uVar1 >> 0x10) ==
                                                     (short)((ulonglong)DAT_1008e008 >> 0x10)),
                                            -(ushort)((short)uVar1 == (short)DAT_1008e008))));
        uVar10 = CONCAT26((uVar12 >> 0xb) * (short)(DAT_1008e1d0 >> 0x30),
                          CONCAT24((uVar11 >> 0xb) * (short)(DAT_1008e1d0 >> 0x20),
                                   CONCAT22((uVar8 >> 0xb) * (short)(DAT_1008e1d0 >> 0x10),
                                            ((ushort)uVar10 >> 0xb) * (short)DAT_1008e1d0))) & uVar9
                 | CONCAT26((ushort)((short)(uVar15 >> 0x30) * (short)(DAT_1008e1e0 >> 0x30)) >> 0xb
                            ,CONCAT24((ushort)((short)(uVar15 >> 0x20) *
                                              (short)(DAT_1008e1e0 >> 0x20)) >> 0xb,
                                      CONCAT22((ushort)((short)(uVar15 >> 0x10) *
                                                       (short)(DAT_1008e1e0 >> 0x10)) >> 0xb,
                                               (ushort)((short)uVar15 * (short)DAT_1008e1e0) >> 0xb)
                                     )) |
                 CONCAT26((ushort)(uVar13 >> 0x35),
                          CONCAT24((ushort)(uVar13 >> 0x20) >> 5,
                                   CONCAT22((ushort)(uVar13 >> 0x10) >> 5,(ushort)uVar13 >> 5)));
        *(ulonglong *)(iVar5 + uVar7) =
             *(ulonglong *)(iVar5 + uVar7) & uVar16 |
             ~uVar16 & CONCAT26((short)(uVar10 >> 0x30) + (short)((ulonglong)uVar3 >> 0x30),
                                CONCAT24((short)(uVar10 >> 0x20) + (short)((ulonglong)uVar3 >> 0x20)
                                         ,CONCAT22((short)(uVar10 >> 0x10) +
                                                   (short)((ulonglong)uVar3 >> 0x10),
                                                   (short)uVar10 + (short)uVar3)));
        iVar6 = iVar5 + 8;
        bVar2 = iVar5 < -8;
        iVar5 = iVar6;
      } while (iVar6 == 0 || bVar2);
    }
    DAT_1008d29c = DAT_1008d2a0 + DAT_1008d29c;
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return;
}


