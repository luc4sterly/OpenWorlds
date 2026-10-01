// 10064040 FUN_10064040 [Global]
// program: RWDL8D21.DLL

void FUN_10064040(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined3 uVar6;
  
  iVar3 = DAT_1007b2c8;
  iVar2 = DAT_1007b2b0;
  do {
    DAT_1007b280 = DAT_1007b280 + DAT_1007b28c;
    DAT_1007b284 = DAT_1007b284 + DAT_1007b288;
    uVar4 = DAT_1007b284 >> 0x10;
    DAT_1007b2c0 = DAT_1007b2c0 + DAT_1007b2c4 & 0x7fff7fff;
    iVar7 = (DAT_1007b280 >> 0x10) - uVar4;
    if (DAT_1007b280 >> 0x10 < uVar4) {
      iVar11 = DAT_1007b294 + uVar4;
      uVar4 = DAT_1007b2c0 >> 0x11 & 0xffffff80;
      iVar9 = CONCAT31((int3)(uVar4 >> 8),(byte)uVar4 | (byte)(DAT_1007b2c0 >> 8));
      uVar4 = DAT_1007b2c0 + iVar3 & 0x7fff7fff;
      puVar5 = DAT_1007b2b4;
      do {
        while( true ) {
          uVar6 = (undefined3)((uint)puVar5 >> 8);
          puVar5 = (undefined1 *)CONCAT31(uVar6,*(char *)(iVar9 + iVar2));
          bVar8 = (byte)(uVar4 >> 8);
          if (*(char *)(iVar9 + iVar2) == '\0') break;
          uVar1 = *puVar5;
          puVar5 = (undefined1 *)CONCAT31(uVar6,uVar1);
          uVar10 = uVar4 >> 0x11 & 0xffffff80;
          *(undefined1 *)(iVar7 + iVar11) = uVar1;
          iVar9 = CONCAT31((int3)(uVar10 >> 8),(byte)uVar10 | bVar8);
          uVar4 = uVar4 + iVar3 & 0x7fff7fff;
          iVar7 = iVar7 + 1;
          if (-1 < iVar7) goto LAB_100640f0;
        }
        uVar10 = uVar4 >> 0x11 & 0xffffff80;
        iVar9 = CONCAT31((int3)(uVar10 >> 8),(byte)uVar10 | bVar8);
        uVar4 = uVar4 + iVar3 & 0x7fff7fff;
        iVar7 = iVar7 + 1;
      } while (iVar7 < 0);
    }
LAB_100640f0:
    DAT_1007b294 = DAT_1007b298 + DAT_1007b294;
    DAT_1007b290 = DAT_1007b290 + -1;
    if (DAT_1007b290 == 0) {
      return;
    }
  } while( true );
}


