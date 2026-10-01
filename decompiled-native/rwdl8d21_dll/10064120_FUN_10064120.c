// 10064120 FUN_10064120 [Global]
// program: RWDL8D21.DLL

void FUN_10064120(void)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  ushort uVar9;
  
  do {
    uVar7 = DAT_1007b2c0 + DAT_1007b2c4 & 0x7fff7fff;
    DAT_1007b280 = DAT_1007b280 + DAT_1007b28c;
    DAT_1007b284 = DAT_1007b284 + DAT_1007b288;
    uVar5 = DAT_1007b284 >> 0x10;
    iVar8 = DAT_1007b2e4 + DAT_1007b2e8;
    iVar6 = (DAT_1007b280 >> 0x10) - uVar5;
    DAT_1007b2c0 = uVar7;
    DAT_1007b2e4 = iVar8;
    if (DAT_1007b280 >> 0x10 < uVar5) {
      DAT_1007b4dc = DAT_1007b294 + uVar5;
      iVar1 = DAT_1007b29c + uVar5 * 2;
      do {
        iVar4 = DAT_1007b4dc;
        uVar5 = uVar7 >> 0x11 & 0xffffff80;
        uVar9 = (ushort)((uint)iVar8 >> 0x10);
        cVar2 = *(char *)(CONCAT31((int3)(uVar5 >> 8),(byte)uVar5 | (byte)(uVar7 >> 8)) +
                         DAT_1007b2b0);
        if ((*(ushort *)(iVar1 + iVar6 * 2) <= uVar9) && (cVar2 != '\0')) {
          uVar3 = *(undefined1 *)CONCAT31((int3)((uint)DAT_1007b2b4 >> 8),cVar2);
          *(ushort *)(iVar1 + iVar6 * 2) = uVar9;
          *(undefined1 *)(iVar6 + iVar4) = uVar3;
        }
        iVar8 = iVar8 + DAT_1007b2ec;
        uVar7 = uVar7 + DAT_1007b2c8 & 0x7fff7fff;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0);
    }
    DAT_1007b294 = DAT_1007b298 + DAT_1007b294;
    DAT_1007b29c = DAT_1007b29c + DAT_1007b2a0;
    DAT_1007b290 = DAT_1007b290 + -1;
  } while (DAT_1007b290 != 0);
  return;
}


