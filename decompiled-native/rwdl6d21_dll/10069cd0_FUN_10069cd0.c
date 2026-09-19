// 10069cd0 FUN_10069cd0 [Global]
// programa: RWDL6D21.DLL

void FUN_10069cd0(void)

{
  bool bVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  uVar2 = (undefined2)DAT_1007f2ac;
  do {
    while( true ) {
      DAT_1007f280 = DAT_1007f280 + DAT_1007f28c;
      DAT_1007f284 = DAT_1007f284 + DAT_1007f288;
      iVar5 = DAT_1007f280 >> 0x10;
      uVar3 = (DAT_1007f284 >> 0x10) - iVar5;
      if (uVar3 != 0 && iVar5 <= DAT_1007f284 >> 0x10) break;
LAB_10069d4d:
      DAT_1007f294 = DAT_1007f294 + DAT_1007f298;
      DAT_1007f290 = DAT_1007f290 + -1;
      if (DAT_1007f290 == 0) {
        return;
      }
    }
    puVar6 = (undefined4 *)(DAT_1007f294 + iVar5 * 2);
    if (6 < (int)uVar3) {
      if (((uint)puVar6 & 2) != 0) {
        *(undefined2 *)puVar6 = uVar2;
        uVar3 = uVar3 - 1;
        puVar6 = (undefined4 *)((int)puVar6 + 2);
      }
      for (uVar4 = uVar3 >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar6 = CONCAT22(uVar2,uVar2);
        puVar6 = puVar6 + 1;
      }
      if ((uVar3 & 1) != 0) {
        *(undefined2 *)puVar6 = uVar2;
      }
      goto LAB_10069d4d;
    }
    iVar5 = -uVar3;
    do {
      *(undefined2 *)((int)puVar6 + iVar5 * 2 + uVar3 * 2) = uVar2;
      bVar1 = iVar5 < -1;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    DAT_1007f294 = DAT_1007f294 + DAT_1007f298;
    DAT_1007f290 = DAT_1007f290 + -1;
    if (DAT_1007f290 == 0) {
      return;
    }
  } while( true );
}


