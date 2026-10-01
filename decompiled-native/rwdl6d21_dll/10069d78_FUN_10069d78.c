// 10069d78 FUN_10069d78 [Global]
// program: RWDL6D21.DLL

void FUN_10069d78(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  do {
    iVar2 = DAT_1007f2ec;
    uVar1 = DAT_1007f2ac;
    DAT_1007f280 = DAT_1007f28c + DAT_1007f280;
    DAT_1007f284 = DAT_1007f284 + DAT_1007f288;
    uVar3 = DAT_1007f284 >> 0x10;
    uVar5 = DAT_1007f2e4 + DAT_1007f2e8;
    iVar4 = (DAT_1007f280 >> 0x10) - uVar3;
    DAT_1007f2e4 = uVar5;
    if (DAT_1007f280 >> 0x10 < uVar3) {
      uVar6 = uVar5 >> 0x10;
      iVar7 = DAT_1007f29c + uVar3 * 2;
      iVar8 = DAT_1007f294 + uVar3 * 2;
      do {
        while ((ushort)uVar6 < *(ushort *)(iVar7 + iVar4 * 2)) {
          uVar5 = uVar5 + iVar2;
          uVar6 = uVar5 >> 0x10;
          iVar4 = iVar4 + 1;
          if (-1 < iVar4) goto LAB_10069e07;
        }
        *(ushort *)(iVar7 + iVar4 * 2) = (ushort)uVar6;
        uVar5 = uVar5 + iVar2;
        *(short *)(iVar8 + iVar4 * 2) = (short)uVar1;
        uVar6 = uVar5 >> 0x10;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0);
    }
LAB_10069e07:
    DAT_1007f294 = DAT_1007f298 + DAT_1007f294;
    DAT_1007f29c = DAT_1007f29c + DAT_1007f2a0;
    DAT_1007f290 = DAT_1007f290 + -1;
    if (DAT_1007f290 == 0) {
      return;
    }
  } while( true );
}


