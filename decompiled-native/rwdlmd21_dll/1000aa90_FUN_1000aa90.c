// 1000aa90 FUN_1000aa90 [Global]
// programa: rwdlmd21.dll

void FUN_1000aa90(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  iVar1 = DAT_10089ddc;
  if (DAT_10089b7c != 8) {
    param_3 = param_3 * 2;
  }
  puVar4 = (undefined4 *)(param_3 + *(int *)(DAT_10087240 + param_4 * 4));
  iVar6 = *param_2;
  if (DAT_10089b7c != 8) {
    iVar6 = iVar6 * 2;
  }
  puVar5 = (undefined4 *)
           (param_2[1] * *(int *)(*(int *)(param_1 + 0xa0) + 0x28) +
            *(int *)(*(int *)(param_1 + 0xa0) + 0x18) + iVar6);
  uVar2 = param_2[2];
  if (DAT_10089b7c != 8) {
    uVar2 = uVar2 * 2;
  }
  iVar6 = param_2[3];
  while (iVar6 != 0) {
    iVar6 = iVar6 + -1;
    puVar7 = puVar5;
    puVar8 = puVar4;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar8 = (undefined4 *)((int)puVar8 + 1);
    }
    puVar4 = (undefined4 *)((int)puVar4 + iVar1);
    puVar5 = (undefined4 *)((int)puVar5 + *(int *)(*(int *)(param_1 + 0xa0) + 0x28));
  }
  return;
}


