// 10064240 FUN_10064240 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10064240(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined3 uVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  
  do {
    iVar2 = DAT_1007b2c8;
    DAT_1007b280 = DAT_1007b280 + DAT_1007b28c;
    DAT_1007b284 = DAT_1007b284 + DAT_1007b288;
    uVar3 = DAT_1007b284 >> 0x10;
    iVar7 = DAT_1007b2c0 + DAT_1007b2c4;
    iVar4 = (DAT_1007b280 >> 0x10) - uVar3;
    DAT_1007b2c0 = iVar7;
    if (DAT_1007b280 >> 0x10 < uVar3) {
      iVar8 = DAT_1007b294 + uVar3;
      uVar1 = *(undefined4 *)(((DAT_1007b280 & 0x70000) >> 0xe) + DAT_1007b590);
      bVar6 = (byte)uVar1 ^ DAT_1007b2a4;
      uVar3 = CONCAT31((int3)((uint)uVar1 >> 8),bVar6);
      uVar5 = (undefined3)((uint)DAT_1007b2b4 >> 8);
      *(undefined1 *)(iVar4 + iVar8) =
           *(undefined1 *)CONCAT31(uVar5,(char)((uint)bVar6 + iVar7 >> 8));
      while (iVar4 = iVar4 + 1, iVar4 < 0) {
        uVar3 = uVar3 ^ uVar3 >> 6;
        iVar7 = iVar7 + iVar2;
        *(undefined1 *)(iVar4 + iVar8) =
             *(undefined1 *)CONCAT31(uVar5,(char)((uVar3 & 0xff) + iVar7 >> 8));
      }
    }
    DAT_1007b294 = DAT_1007b294 + DAT_1007b298;
    _DAT_1007b2a4 = _DAT_1007b2a4 >> 6 ^ _DAT_1007b2a4;
    DAT_1007b290 = DAT_1007b290 + -1;
  } while (DAT_1007b290 != 0);
  return;
}


