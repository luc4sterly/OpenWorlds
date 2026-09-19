// 10033250 FUN_10033250 [Global]
// programa: RWL21.DLL

ushort FUN_10033250(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  ushort uVar7;
  int *piVar8;
  int *piVar9;
  uint *puVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined8 uVar14;
  byte local_f65;
  uint local_f64;
  uint local_f60;
  int iStack_f5c;
  int local_f54;
  int *local_f50;
  undefined4 local_f44 [15];
  int local_f08 [34];
  uint local_e80 [928];
  
  piVar9 = param_1 + 0x10;
  local_f50 = param_1 + 0xf;
  bVar6 = 1;
  if (-1 < (int)(*(int *)(param_1[0xf] + 0x18) - DAT_1005e068)) {
    bVar6 = (-1 < (int)(DAT_1005e054 - *(int *)(param_1[0xf] + 0x18))) - 1U & 2;
  }
  iVar2 = *(byte *)((int)param_1 + 0x3a) - 1;
  bVar3 = bVar6;
  local_f54 = iVar2;
  if (0 < iVar2) {
    do {
      iVar12 = *piVar9;
      piVar9 = piVar9 + 1;
      bVar1 = 1;
      if (-1 < (int)(*(int *)(iVar12 + 0x18) - DAT_1005e068)) {
        bVar1 = (-1 < (int)(DAT_1005e054 - *(int *)(iVar12 + 0x18))) - 1U & 2;
      }
      bVar3 = bVar3 & bVar1;
      bVar6 = bVar6 | bVar1;
      local_f54 = local_f54 + -1;
    } while (local_f54 != 0);
  }
  local_e80[0] = (uint)bVar6;
  uVar7 = CONCAT11(bVar3,bVar6);
  if (bVar3 == 0) {
    if (bVar6 == 0) {
      uVar7 = uVar7 | 1;
      DAT_1005e064 = param_1[0xb];
      DAT_1005e058 = *(undefined4 *)(*local_f50 + 0x20);
    }
    else {
      puVar10 = local_e80;
      piVar9 = local_f08;
      iVar12 = local_f50[iVar2];
      local_f64 = *(int *)(iVar12 + 0x18) - DAT_1005e068;
      local_f60 = DAT_1005e054 - *(int *)(iVar12 + 0x18);
      if ((int)local_f64 < 0) {
        local_f65 = 1;
        local_f54 = iVar2;
      }
      else {
        local_f65 = (-1 < (int)local_f60) - 1U & 2;
        local_f54 = iVar2;
      }
      do {
        bVar6 = local_f65;
        iVar2 = *local_f50;
        uVar4 = *(int *)(iVar2 + 0x18) - DAT_1005e068;
        uVar5 = DAT_1005e054 - *(int *)(iVar2 + 0x18);
        if ((int)uVar4 < 0) {
          local_f65 = 1;
        }
        else {
          local_f65 = (-1 < (int)uVar5) - 1U & 2;
        }
        if ((bVar6 & local_f65) == 0) {
          piVar8 = piVar9;
          if (bVar6 != 0) {
            if ((bVar6 & 1) == 0) {
              uVar14 = rwFixDiv(uVar5,uVar5 - local_f60);
              iStack_f5c = (int)uVar14;
              puVar10[6] = DAT_1005e054;
              bVar6 = *(byte *)(iVar12 + 0x48) & 0xfe | 2;
            }
            else {
              uVar14 = rwFixDiv(uVar4,uVar4 - local_f64);
              iStack_f5c = (int)uVar14;
              puVar10[6] = DAT_1005e068;
              bVar6 = *(byte *)(iVar12 + 0x48) & 0xfd | 1;
            }
            piVar8 = piVar9 + 1;
            *(byte *)(puVar10 + 0x12) = bVar6;
            uVar14 = rwFixMul(iStack_f5c,*(int *)(iVar12 + 0x1c) - *(int *)(iVar2 + 0x1c));
            puVar10[7] = *(int *)(iVar2 + 0x1c) + (int)uVar14;
            uVar14 = rwFixMul(iStack_f5c,*(int *)(iVar12 + 0x20) - *(int *)(iVar2 + 0x20));
            puVar10[8] = *(int *)(iVar2 + 0x20) + (int)uVar14;
            *piVar9 = (int)puVar10;
            puVar10 = puVar10 + 0x1d;
          }
          if (local_f65 == 0) {
            *piVar8 = iVar2;
          }
          else {
            if ((local_f65 & 1) == 0) {
              uVar14 = rwFixDiv(local_f60,local_f60 - uVar5);
              iStack_f5c = (int)uVar14;
              puVar10[6] = DAT_1005e054;
              bVar6 = *(byte *)(iVar2 + 0x48) & 0xfe | 2;
            }
            else {
              uVar14 = rwFixDiv(local_f64,local_f64 - uVar4);
              iStack_f5c = (int)uVar14;
              puVar10[6] = DAT_1005e068;
              bVar6 = *(byte *)(iVar2 + 0x48) & 0xfd | 1;
            }
            *(byte *)(puVar10 + 0x12) = bVar6;
            uVar14 = rwFixMul(iStack_f5c,*(int *)(iVar2 + 0x1c) - *(int *)(iVar12 + 0x1c));
            puVar10[7] = *(int *)(iVar12 + 0x1c) + (int)uVar14;
            iVar12 = *(int *)(iVar12 + 0x20);
            uVar14 = rwFixMul(iStack_f5c,*(int *)(iVar2 + 0x20) - iVar12);
            puVar10[8] = (int)uVar14 + iVar12;
            *piVar8 = (int)puVar10;
            puVar10 = puVar10 + 0x1d;
          }
          piVar9 = piVar8 + 1;
        }
        local_f54 = local_f54 + -1;
        iVar12 = iVar2;
        local_f64 = uVar4;
        local_f60 = uVar5;
        local_f50 = local_f50 + 1;
      } while (-1 < local_f54);
      puVar11 = param_1;
      puVar13 = local_f44;
      for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar13 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar13 = puVar13 + 1;
      }
      DAT_1005e064 = param_1[0xb];
      uVar7 = uVar7 | 1;
      DAT_1005e058 = *(undefined4 *)(local_f08[0] + 0x20);
    }
  }
  return uVar7;
}


