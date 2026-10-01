// 100015e0 FUN_100015e0 [Global]
// program: rwdlmd21.dll

undefined4 FUN_100015e0(undefined4 *param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
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
    puVar2[1] = FUN_100134d0;
    puVar3 = param_1;
    puVar7 = puVar2 + 2;
    for (uVar4 = uVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar7 = puVar7 + 1;
    }
    uVar4 = 0;
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar3;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    if (*(char *)((int)param_1 + 0x3a) != '\0') {
      puVar3 = param_1 + 0xf;
      puVar2 = (undefined4 *)((int)(puVar2 + 2) + uVar6);
      do {
        puVar7 = (undefined4 *)*puVar3;
        puVar8 = puVar2;
        for (iVar5 = 0x1d; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        puVar3 = puVar3 + 1;
        uVar4 = uVar4 + 1;
        puVar2 = puVar2 + 0x1d;
      } while (uVar4 < *(byte *)((int)param_1 + 0x3a));
    }
    DAT_10087084 = 1;
  }
  return 0;
}


