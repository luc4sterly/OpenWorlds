// 10063f30 FUN_10063f30 [Global]
// program: RWDL8D21.DLL

void FUN_10063f30(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ushort uVar8;
  
  do {
    uVar6 = DAT_1007b2c0 + DAT_1007b2c4 & 0x7fff7fff;
    DAT_1007b280 = DAT_1007b280 + DAT_1007b28c;
    DAT_1007b284 = DAT_1007b284 + DAT_1007b288;
    uVar4 = DAT_1007b284 >> 0x10;
    iVar7 = DAT_1007b2e4 + DAT_1007b2e8;
    iVar5 = (DAT_1007b280 >> 0x10) - uVar4;
    DAT_1007b2c0 = uVar6;
    DAT_1007b2e4 = iVar7;
    if (DAT_1007b280 >> 0x10 < uVar4) {
      DAT_1007b4dc = DAT_1007b294 + uVar4;
      iVar1 = DAT_1007b29c + uVar4 * 2;
      do {
        iVar3 = DAT_1007b4dc;
        uVar4 = uVar6 >> 0x11 & 0xffffff80;
        uVar8 = (ushort)((uint)iVar7 >> 0x10);
        cVar2 = *(char *)(CONCAT31((int3)(uVar4 >> 8),(byte)uVar4 | (byte)(uVar6 >> 8)) +
                         DAT_1007b2b0);
        if ((*(ushort *)(iVar1 + iVar5 * 2) <= uVar8) && (cVar2 != '\0')) {
          *(ushort *)(iVar1 + iVar5 * 2) = uVar8;
          *(char *)(iVar5 + iVar3) = cVar2;
        }
        iVar7 = iVar7 + DAT_1007b2ec;
        uVar6 = uVar6 + DAT_1007b2c8 & 0x7fff7fff;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0);
    }
    DAT_1007b294 = DAT_1007b298 + DAT_1007b294;
    DAT_1007b29c = DAT_1007b29c + DAT_1007b2a0;
    DAT_1007b290 = DAT_1007b290 + -1;
  } while (DAT_1007b290 != 0);
  return;
}


