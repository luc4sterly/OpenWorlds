// 10007f50 RwRenderImmediateClump [Global]
// programa: RWL21.DLL

void RwRenderImmediateClump(void)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int *piVar5;
  
                    /* 0x7f50  346  RwRenderImmediateClump */
  puVar3 = PTR_DAT_1005b69c;
  iVar1 = *(int *)(PTR_DAT_1005b69c + 0x33c);
  piVar5 = (int *)(PTR_DAT_1005b69c + 0x2f0);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0xd8) != 0) {
      FUN_1001b050(iVar1);
    }
    if (*(int *)(iVar1 + 0xdc) == 0) {
      puVar4 = &LAB_10027490;
      if (*(int *)(PTR_DAT_1005b69c + 0x348) == 0) {
        puVar4 = &LAB_10027460;
      }
    }
    else if (*(int *)(PTR_DAT_1005b69c + 0x348) == 0) {
      puVar4 = *(undefined **)(PTR_DAT_1005b69c + *(int *)(iVar1 + 0xe0) * 4 + 0x54);
    }
    else {
      puVar4 = *(undefined **)(PTR_DAT_1005b69c + *(int *)(iVar1 + 0xe0) * 4 + 0x154);
    }
    if (*piVar5 != 0) {
      puVar2 = *(undefined **)(puVar3 + 0x2f4);
      FUN_100274c0(puVar4);
      FUN_10032c70(puVar2,iVar1,*(undefined4 *)(puVar3 + 0x344));
      return;
    }
    FUN_10032b50(puVar4,iVar1,*(undefined4 *)(puVar3 + 0x344));
  }
  return;
}


