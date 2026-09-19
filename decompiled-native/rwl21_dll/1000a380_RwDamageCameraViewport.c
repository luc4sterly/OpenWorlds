// 1000a380 RwDamageCameraViewport [Global]
// programa: RWL21.DLL

int RwDamageCameraViewport(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  bool bVar8;
  int local_8;
  uint local_4;
  
                    /* 0xa380  55  RwDamageCameraViewport */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    param_1 = 0;
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x114);
    uVar7 = param_2 >> (bVar1 & 0x1f);
    uVar5 = param_3 >> (bVar1 & 0x1f);
    iVar3 = param_4 >> (bVar1 & 0x1f);
    iVar4 = param_5 >> (bVar1 & 0x1f);
    local_4 = uVar7;
    if ((int)uVar7 < 0) {
      local_4 = 0;
      iVar3 = iVar3 + uVar7;
    }
    if (*(int *)(param_1 + 0x5c) < (int)(local_4 + iVar3)) {
      iVar3 = *(int *)(param_1 + 0x5c) - local_4;
    }
    if ((int)uVar5 < 0) {
      iVar4 = iVar4 + uVar5;
      uVar5 = 0;
    }
    if (*(int *)(param_1 + 0x60) < (int)(uVar5 + iVar4)) {
      iVar4 = *(int *)(param_1 + 0x60) - uVar5;
    }
    uVar7 = 0;
    if ((0 < iVar3) && (0 < iVar4)) {
      local_8 = 0;
      if (0 < iVar3) {
        uVar2 = iVar3 + 0x1fU >> 5;
        local_8 = uVar2 << 5;
        do {
          uVar7 = uVar7 * 2 | 1;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      if (local_8 - iVar3 < (int)(local_4 & 0x1f)) {
        uVar7 = uVar7 * 2 | 1;
      }
      uVar7 = uVar7 << ((byte)((int)local_4 >> 5) & 0x1f);
      iVar3 = iVar4 + 0x1f >> 5;
      if (iVar3 * 0x20 - iVar4 < (int)(uVar5 & 0x1f)) {
        iVar3 = iVar3 + 1;
      }
      if (iVar3 != 0) {
        puVar6 = (uint *)(((int)(uVar5 & 0xffffffe7) >> 3) + (iVar3 + -1) * 4 + 0x118 + param_1);
        iVar3 = iVar3 + -1;
        do {
          *puVar6 = *puVar6 | uVar7;
          if ((*(uint *)(param_1 + 0x228) & 1) != 0) {
            puVar6[0x20] = puVar6[0x20] | uVar7;
          }
          puVar6 = puVar6 + -1;
          bVar8 = iVar3 != 0;
          iVar3 = iVar3 + -1;
        } while (bVar8);
        return param_1;
      }
    }
  }
  return param_1;
}


