// 10001530 FUN_10001530 [Global]
// programa: rwdlmd21.dll

undefined4 FUN_10001530(undefined4 *param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar5 = 0x44;
  bVar1 = *(byte *)((int)param_1 + 0x3a);
  if (2 < bVar1) {
    uVar5 = (uint)bVar1 * 4 + 0x3c;
  }
  puVar2 = FUN_1000c870(uVar5 + 8 + (uint)bVar1 * 0x74,&LAB_100014d0);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = param_2;
    puVar2[1] = FUN_1002c580;
    puVar6 = param_1;
    puVar7 = puVar2 + 2;
    for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    uVar3 = 0;
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    puVar2 = (undefined4 *)((int)(puVar2 + 2) + uVar5);
    if (*(char *)((int)param_1 + 0x3a) != '\0') {
      puVar6 = param_1 + 0xf;
      do {
        puVar7 = (undefined4 *)*puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar2;
        for (iVar4 = 0x1d; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        puVar2 = puVar2 + 0x1d;
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(byte *)((int)param_1 + 0x3a));
    }
    DAT_10087084 = 1;
  }
  return 0;
}


