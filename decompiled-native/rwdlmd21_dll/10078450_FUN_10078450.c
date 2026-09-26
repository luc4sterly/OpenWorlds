// 10078450 FUN_10078450 [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_10078450(void)

{
  ulonglong uVar1;
  bool bVar2;
  uint uVar3;
  uint extraout_EDX;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  ushort uVar9;
  undefined8 extraout_MM1;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  ushort uVar16;
  ushort uVar17;
  ushort uVar18;
  undefined8 uVar14;
  ulonglong uVar15;
  undefined8 uVar19;
  
  uVar7 = CONCAT22((ushort)DAT_1008d2a8 << 7,(ushort)DAT_1008d2a8 << 7);
  uVar8 = CONCAT44(uVar7,uVar7);
  uVar9 = (ushort)_DAT_1008d2ac;
  pmulhw(CONCAT26(uVar9 >> 10,CONCAT24(uVar9 >> 10,CONCAT22(uVar9 >> 10,uVar9 >> 10))) &
         DAT_1008e028,uVar8);
  uVar10 = pmulhw(CONCAT26(uVar9 >> 5,CONCAT24(uVar9 >> 5,CONCAT22(uVar9 >> 5,uVar9 >> 5))) &
                  DAT_1008e028,uVar8);
  uVar11 = pmulhw(CONCAT26(uVar9 * 2,CONCAT24(uVar9 * 2,CONCAT22(uVar9 * 2,uVar9 * 2))) &
                  DAT_1008e028,uVar8);
  uVar8 = uVar8 ^ _DAT_1008e010;
  do {
    iVar4 = DAT_1008d294;
    DAT_1008d2e4 = DAT_1008d2e4 + DAT_1008d2e8;
    DAT_1008d280 = DAT_1008d280 + DAT_1008d28c;
    uVar3 = DAT_1008d280 >> 0x10;
    DAT_1008d284 = DAT_1008d284 + DAT_1008d288;
    if (uVar3 < DAT_1008d284 >> 0x10) {
      uVar8 = FUN_10078060(uVar3 - (DAT_1008d284 >> 0x10));
      uVar6 = iVar4 - 2U & 0xfffffff8;
      iVar4 = (uVar3 & 0xfffffff8) - uVar6;
      do {
        uVar12 = *(undefined8 *)(iVar4 + uVar6);
        uVar9 = (ushort)uVar12;
        uVar16 = (ushort)((ulonglong)uVar12 >> 0x10);
        uVar17 = (ushort)((ulonglong)uVar12 >> 0x20);
        uVar18 = (ushort)((ulonglong)uVar12 >> 0x30);
        uVar14 = pmulhw(CONCAT26(uVar18 >> 5,CONCAT24(uVar17 >> 5,CONCAT22(uVar16 >> 5,uVar9 >> 5)))
                        & DAT_1008e028,uVar8);
        uVar19 = pmulhw(CONCAT26(uVar18 * 2,CONCAT24(uVar17 * 2,CONCAT22(uVar16 * 2,uVar9 * 2))) &
                        DAT_1008e028,uVar8);
        uVar1 = *(ulonglong *)(iVar4 + (extraout_EDX & 0xfffffff8));
        uVar12 = pmulhw(CONCAT26(uVar18 >> 10,
                                 CONCAT24(uVar17 >> 10,CONCAT22(uVar16 >> 10,uVar9 >> 10))) &
                        DAT_1008e028,uVar8);
        uVar15 = psllw(CONCAT26((short)((ulonglong)uVar14 >> 0x30) +
                                (short)((ulonglong)uVar10 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar14 >> 0x20) +
                                         (short)((ulonglong)uVar10 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar14 >> 0x10) +
                                                  (short)((ulonglong)uVar10 >> 0x10),
                                                  (short)uVar14 + (short)uVar10))),6);
        uVar13 = psllw(CONCAT26((short)((ulonglong)uVar12 >> 0x30) +
                                (short)((ulonglong)extraout_MM1 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar12 >> 0x20) +
                                         (short)((ulonglong)extraout_MM1 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar12 >> 0x10) +
                                                  (short)((ulonglong)extraout_MM1 >> 0x10),
                                                  (short)uVar12 + (short)extraout_MM1))),0xb);
        *(ulonglong *)(iVar4 + uVar6) =
             (uVar15 | CONCAT26((short)((ulonglong)uVar19 >> 0x30) +
                                (short)((ulonglong)uVar11 >> 0x30),
                                CONCAT24((short)((ulonglong)uVar19 >> 0x20) +
                                         (short)((ulonglong)uVar11 >> 0x20),
                                         CONCAT22((short)((ulonglong)uVar19 >> 0x10) +
                                                  (short)((ulonglong)uVar11 >> 0x10),
                                                  (short)uVar19 + (short)uVar11))) | uVar13) & uVar1
             | ~uVar1 & *(ulonglong *)(iVar4 + uVar6);
        iVar5 = iVar4 + 8;
        bVar2 = iVar4 < -8;
        iVar4 = iVar5;
      } while (iVar5 == 0 || bVar2);
    }
    DAT_1008d29c = DAT_1008d2a0 + DAT_1008d29c;
    DAT_1008d294 = DAT_1008d294 + DAT_1008d298;
    DAT_1008d290 = DAT_1008d290 + -1;
  } while (DAT_1008d290 != 0);
  return uVar8;
}


