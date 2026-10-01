// 10064328 FUN_10064328 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10064328(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  
  do {
    iVar9 = DAT_1007b2e4 + DAT_1007b2e8;
    DAT_1007b280 = DAT_1007b280 + DAT_1007b28c;
    DAT_1007b284 = DAT_1007b284 + DAT_1007b288;
    uVar4 = DAT_1007b284 >> 0x10;
    DAT_1007b2c0 = DAT_1007b2c0 + DAT_1007b2c4;
    iVar6 = (DAT_1007b280 >> 0x10) - uVar4;
    DAT_1007b2e4 = iVar9;
    if (DAT_1007b280 >> 0x10 < uVar4) {
      DAT_1007b4dc = DAT_1007b294 + uVar4;
      DAT_1007b4e0 = DAT_1007b29c + uVar4 * 2;
      uVar2 = *(undefined4 *)(((DAT_1007b280 & 0x70000) >> 0xe) + DAT_1007b590);
      bVar8 = (byte)uVar2 ^ DAT_1007b2a4;
      uVar4 = CONCAT31((int3)((uint)uVar2 >> 8),bVar8);
      iVar10 = DAT_1007b2c0 + DAT_1007b2c8;
      puVar7 = (undefined1 *)
               CONCAT31((int3)((uint)DAT_1007b2b4 >> 8),(char)((uint)bVar8 + DAT_1007b2c0 >> 8));
      do {
        uVar3 = (ushort)((uint)iVar9 >> 0x10);
        if (*(ushort *)(DAT_1007b4e0 + iVar6 * 2) <= uVar3) {
          *(ushort *)(DAT_1007b4e0 + iVar6 * 2) = uVar3;
          uVar1 = *puVar7;
          puVar7 = (undefined1 *)CONCAT31((int3)((uint)puVar7 >> 8),uVar1);
          *(undefined1 *)(iVar6 + DAT_1007b4dc) = uVar1;
        }
        iVar9 = iVar9 + DAT_1007b2ec;
        uVar4 = uVar4 ^ uVar4 >> 6;
        iVar5 = (uVar4 & 0xff) + iVar10;
        iVar10 = iVar10 + DAT_1007b2c8;
        puVar7 = (undefined1 *)CONCAT31((int3)((uint)puVar7 >> 8),(char)((uint)iVar5 >> 8));
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0);
    }
    DAT_1007b294 = DAT_1007b294 + DAT_1007b298;
    _DAT_1007b2a4 = _DAT_1007b2a4 >> 6 ^ _DAT_1007b2a4;
    DAT_1007b29c = DAT_1007b29c + DAT_1007b2a0;
    DAT_1007b290 = DAT_1007b290 + -1;
  } while (DAT_1007b290 != 0);
  return;
}


