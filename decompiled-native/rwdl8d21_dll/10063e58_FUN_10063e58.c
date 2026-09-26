// 10063e58 FUN_10063e58 [Global]
// programa: RWDL8D21.DLL

void FUN_10063e58(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar2 = DAT_1007b2c8;
  iVar1 = DAT_1007b2b0;
  do {
    DAT_1007b280 = DAT_1007b280 + DAT_1007b28c;
    DAT_1007b284 = DAT_1007b284 + DAT_1007b288;
    uVar3 = DAT_1007b284 >> 0x10;
    DAT_1007b2c0 = DAT_1007b2c0 + DAT_1007b2c4 & 0x7fff7fff;
    iVar4 = (DAT_1007b280 >> 0x10) - uVar3;
    if (DAT_1007b280 >> 0x10 < uVar3) {
      iVar8 = DAT_1007b294 + uVar3;
      uVar3 = DAT_1007b2c0 >> 0x11 & 0xffffff80;
      iVar6 = CONCAT31((int3)(uVar3 >> 8),(byte)uVar3 | (byte)(DAT_1007b2c0 >> 8));
      uVar3 = DAT_1007b2c0 + iVar2 & 0x7fff7fff;
      do {
        while( true ) {
          bVar5 = (byte)(uVar3 >> 8);
          if (*(char *)(iVar6 + iVar1) == '\0') break;
          *(char *)(iVar4 + iVar8) = *(char *)(iVar6 + iVar1);
          uVar7 = uVar3 >> 0x11 & 0xffffff80;
          iVar6 = CONCAT31((int3)(uVar7 >> 8),(byte)uVar7 | bVar5);
          uVar3 = uVar3 + iVar2 & 0x7fff7fff;
          iVar4 = iVar4 + 1;
          if (-1 < iVar4) goto LAB_10063f01;
        }
        uVar7 = uVar3 >> 0x11 & 0xffffff80;
        iVar6 = CONCAT31((int3)(uVar7 >> 8),(byte)uVar7 | bVar5);
        uVar3 = uVar3 + iVar2 & 0x7fff7fff;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0);
    }
LAB_10063f01:
    DAT_1007b294 = DAT_1007b298 + DAT_1007b294;
    DAT_1007b290 = DAT_1007b290 + -1;
    if (DAT_1007b290 == 0) {
      return;
    }
  } while( true );
}


