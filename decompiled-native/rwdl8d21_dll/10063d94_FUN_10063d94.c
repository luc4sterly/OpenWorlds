// 10063d94 FUN_10063d94 [Global]
// programa: RWDL8D21.DLL

void FUN_10063d94(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  int iVar7;
  
  do {
    iVar3 = DAT_1007b2ec;
    uVar2 = DAT_1007b2ac;
    DAT_1007b284 = DAT_1007b284 + DAT_1007b288;
    DAT_1007b280 = DAT_1007b280 + DAT_1007b28c;
    uVar5 = DAT_1007b284 >> 0x10;
    DAT_1007b2e4 = DAT_1007b2e4 + DAT_1007b2e8;
    iVar4 = (DAT_1007b280 >> 0x10) - uVar5;
    if (DAT_1007b280 >> 0x10 < uVar5) {
      iVar1 = DAT_1007b29c + uVar5 * 2;
      iVar7 = DAT_1007b2e4;
      do {
        while( true ) {
          uVar6 = (ushort)((uint)iVar7 >> 0x10);
          if (uVar6 < *(ushort *)(iVar1 + iVar4 * 2)) break;
          *(ushort *)(iVar1 + iVar4 * 2) = uVar6;
          *(char *)(iVar4 + uVar5 + DAT_1007b294) = (char)uVar2;
          iVar4 = iVar4 + 1;
          iVar7 = iVar7 + iVar3;
          if (-1 < iVar4) goto LAB_10063e25;
        }
        iVar4 = iVar4 + 1;
        iVar7 = iVar7 + iVar3;
      } while (iVar4 < 0);
    }
LAB_10063e25:
    DAT_1007b294 = DAT_1007b294 + DAT_1007b298;
    DAT_1007b29c = DAT_1007b29c + DAT_1007b2a0;
    DAT_1007b290 = DAT_1007b290 + -1;
    if (DAT_1007b290 == 0) {
      return;
    }
  } while( true );
}


