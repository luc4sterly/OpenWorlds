// 1000a510 RwUndamageCameraViewport [Global]
// program: RWL21.DLL

int RwUndamageCameraViewport(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  
                    /* 0xa510  521  RwUndamageCameraViewport */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    param_1 = 0;
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x114);
    iVar3 = param_2 >> (bVar1 & 0x1f);
    iVar8 = param_3 >> (bVar1 & 0x1f);
    uVar5 = iVar8 + 0x1fU & 0xffffffe0;
    uVar2 = iVar3 + 0x1fU & 0xffffffe0;
    uVar7 = ((param_5 >> (bVar1 & 0x1f)) - uVar5) + iVar8 & 0xffffffe0;
    uVar6 = ((param_4 >> (bVar1 & 0x1f)) - uVar2) + iVar3 & 0xffffffe0;
    if ((int)uVar2 < 0) {
      uVar6 = uVar6 + uVar2;
      uVar2 = 0;
    }
    if (*(int *)(param_1 + 0x5c) < (int)(uVar2 + uVar6)) {
      uVar6 = *(int *)(param_1 + 0x5c) - uVar2;
    }
    if ((int)uVar5 < 0) {
      uVar7 = uVar7 + uVar5;
      uVar5 = 0;
    }
    if (*(int *)(param_1 + 0x60) < (int)(uVar5 + uVar7)) {
      uVar7 = (*(int *)(param_1 + 0x60) + 0x1fU & 0xffffffe0) - uVar5;
    }
    if ((0 < (int)uVar6) && (0 < (int)uVar7)) {
      uVar9 = 0;
      if (0 < (int)uVar6) {
        uVar6 = uVar6 + 0x1f >> 5;
        do {
          uVar9 = uVar9 * 2 | 1;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
      iVar3 = ((int)uVar7 >> 5) + -1;
      if ((int)uVar7 >> 5 != 0) {
        uVar2 = ~(uVar9 << ((byte)((int)uVar2 >> 5) & 0x1f));
        puVar4 = (uint *)(((int)uVar5 >> 3) + iVar3 * 4 + 0x118 + param_1);
        do {
          *puVar4 = *puVar4 & uVar2;
          if ((*(uint *)(param_1 + 0x228) & 1) == 0) {
            puVar4[0x20] = puVar4[0x20] & uVar2;
          }
          puVar4 = puVar4 + -1;
          bVar10 = iVar3 != 0;
          iVar3 = iVar3 + -1;
        } while (bVar10);
        return param_1;
      }
    }
  }
  return param_1;
}


