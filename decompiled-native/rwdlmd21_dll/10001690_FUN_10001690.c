// 10001690 FUN_10001690 [Global]
// program: rwdlmd21.dll

undefined4 FUN_10001690(undefined4 *param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar6 = 0x44;
  bVar1 = *(byte *)((int)param_1 + 0x3a);
  if (2 < bVar1) {
    uVar6 = (uint)bVar1 * 4 + 0x3c;
  }
  puVar2 = FUN_1000c870(uVar6 + 8 + (uint)bVar1 * 0x74,&LAB_100014d0);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = param_2;
    puVar2[1] = FUN_1001a630;
    puVar5 = param_1;
    puVar7 = puVar2 + 2;
    for (uVar3 = uVar6 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    uVar3 = 0;
    if (*(char *)((int)param_1 + 0x3a) != '\0') {
      puVar5 = param_1 + 0xf;
      puVar2 = (undefined4 *)(uVar6 + (int)(puVar2 + 2));
      do {
        puVar7 = (undefined4 *)*puVar5;
        puVar8 = puVar2;
        for (iVar4 = 0x1d; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        puVar5 = puVar5 + 1;
        uVar3 = uVar3 + 1;
        puVar2 = puVar2 + 0x1d;
      } while (uVar3 < *(byte *)((int)param_1 + 0x3a));
    }
    DAT_10087084 = 1;
  }
  return 0;
}


