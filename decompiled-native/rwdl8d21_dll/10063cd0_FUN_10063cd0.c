// 10063cd0 FUN_10063cd0 [Global]
// program: RWDL8D21.DLL

void FUN_10063cd0(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  uint uVar5;
  uint uVar6;
  int iVar7;
  short sVar8;
  undefined4 *puVar9;
  short sVar4;
  
  uVar1 = (undefined1)DAT_1007b2ac;
  uVar2 = CONCAT11((undefined1)DAT_1007b2ac,(undefined1)DAT_1007b2ac);
  iVar7 = DAT_1007b290;
  do {
    while( true ) {
      DAT_1007b284 = DAT_1007b284 + DAT_1007b288;
      DAT_1007b280 = DAT_1007b280 + DAT_1007b28c;
      sVar4 = (short)((uint)DAT_1007b284 >> 0x10);
      sVar8 = (short)(DAT_1007b280 >> 0x10);
      uVar3 = sVar4 - sVar8;
      uVar5 = (uint)uVar3;
      if (uVar3 != 0 && sVar8 <= sVar4) break;
LAB_10063d27:
      DAT_1007b294 = DAT_1007b294 + DAT_1007b298;
      iVar7 = iVar7 + -1;
      if (iVar7 == 0) {
        return;
      }
    }
    puVar9 = (undefined4 *)((DAT_1007b280 >> 0x10) + DAT_1007b294);
    if ((short)uVar3 < 9) {
      do {
        *(undefined1 *)puVar9 = uVar1;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
      goto LAB_10063d27;
    }
    if (((uint)puVar9 & 1) != 0) {
      *(undefined1 *)puVar9 = uVar1;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
      uVar5 = uVar5 - 1;
    }
    if (((uint)puVar9 & 2) != 0) {
      *(undefined2 *)puVar9 = uVar2;
      uVar5 = uVar5 - 2;
      puVar9 = (undefined4 *)((int)puVar9 + 2);
    }
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar9 = CONCAT22(uVar2,uVar2);
      puVar9 = puVar9 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar9 = uVar1;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    DAT_1007b294 = DAT_1007b294 + DAT_1007b298;
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) {
      return;
    }
  } while( true );
}


