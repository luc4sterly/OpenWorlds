// 10032eb0 FUN_10032eb0 [Global]
// program: RWL21.DLL

uint FUN_10032eb0(undefined4 *param_1)

{
  int iVar1;
  ushort uVar2;
  undefined2 extraout_var;
  byte bVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  int *piVar9;
  int *piVar10;
  uint *puVar11;
  undefined4 *puVar12;
  int iVar13;
  int **ppiVar14;
  undefined8 uVar15;
  byte bStack_f65;
  uint local_f64;
  uint local_f60;
  int iStack_f5c;
  int *local_f54;
  int local_f48;
  int *local_f44 [11];
  undefined4 local_f18;
  undefined4 local_f14;
  undefined4 local_f10;
  undefined1 local_f0a;
  int local_f08 [34];
  uint local_e80 [928];
  
  local_f54 = param_1 + 0xf;
  piVar10 = param_1 + 0x10;
  bVar8 = 4;
  if (-1 < (int)(*(int *)(*local_f54 + 0x1c) - DAT_1005e05c)) {
    bVar8 = (-1 < (int)(DAT_1005e060 - *(int *)(*local_f54 + 0x1c))) - 1U & 8;
  }
  local_f48 = *(byte *)((int)param_1 + 0x3a) - 1;
  iVar13 = local_f48;
  bVar5 = bVar8;
  if (0 < local_f48) {
    do {
      iVar1 = *piVar10;
      piVar10 = piVar10 + 1;
      bVar3 = 4;
      if (-1 < (int)(*(int *)(iVar1 + 0x1c) - DAT_1005e05c)) {
        bVar3 = (-1 < (int)(DAT_1005e060 - *(int *)(iVar1 + 0x1c))) - 1U & 8;
      }
      bVar8 = bVar8 & bVar3;
      bVar5 = bVar5 | bVar3;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  local_e80[0] = (uint)bVar5;
  uVar4 = (uint)CONCAT11(bVar8,bVar5);
  if (bVar8 == 0) {
    puVar11 = local_e80;
    local_f44[0] = local_f54;
    if (bVar5 == 0) {
      piVar10 = local_f08;
      for (; -1 < local_f48; local_f48 = local_f48 + -1) {
        iVar13 = *local_f54;
        puVar11[6] = *(uint *)(iVar13 + 0x18);
        puVar11[7] = *(uint *)(iVar13 + 0x1c);
        puVar11[8] = *(uint *)(iVar13 + 0x20);
        *piVar10 = (int)puVar11;
        puVar11 = puVar11 + 0x1d;
        local_f54 = local_f54 + 1;
        piVar10 = piVar10 + 1;
      }
      puVar12 = param_1;
      ppiVar14 = local_f44;
      for (iVar13 = 10; iVar13 != 0; iVar13 = iVar13 + -1) {
        *ppiVar14 = (int *)*puVar12;
        puVar12 = puVar12 + 1;
        ppiVar14 = ppiVar14 + 1;
      }
      local_f0a = (undefined1)((int)piVar10 - (int)local_f08 >> 2);
    }
    else {
      piVar10 = local_f08;
      iVar13 = local_f54[local_f48];
      local_f64 = *(int *)(iVar13 + 0x1c) - DAT_1005e05c;
      local_f60 = DAT_1005e060 - *(int *)(iVar13 + 0x1c);
      if ((int)local_f64 < 0) {
        bStack_f65 = 4;
      }
      else {
        bStack_f65 = (-1 < (int)local_f60) - 1U & 8;
      }
      do {
        bVar8 = bStack_f65;
        iVar1 = *local_f54;
        local_f54 = local_f54 + 1;
        uVar6 = *(int *)(iVar1 + 0x1c) - DAT_1005e05c;
        uVar7 = DAT_1005e060 - *(int *)(iVar1 + 0x1c);
        if ((int)uVar6 < 0) {
          bStack_f65 = 4;
        }
        else {
          bStack_f65 = (-1 < (int)uVar7) - 1U & 8;
        }
        if ((bStack_f65 & bVar8) == 0) {
          piVar9 = piVar10;
          if (bVar8 != 0) {
            if ((bVar8 & 4) == 0) {
              uVar15 = rwFixDiv(uVar7,uVar7 - local_f60);
              iStack_f5c = (int)uVar15;
              puVar11[7] = DAT_1005e060;
              bVar8 = *(byte *)(iVar13 + 0x48) & 0xfb | 8;
            }
            else {
              uVar15 = rwFixDiv(uVar6,uVar6 - local_f64);
              iStack_f5c = (int)uVar15;
              puVar11[7] = DAT_1005e05c;
              bVar8 = *(byte *)(iVar13 + 0x48) & 0xf7 | 4;
            }
            piVar9 = piVar10 + 1;
            *(byte *)(puVar11 + 0x12) = bVar8;
            uVar15 = rwFixMul(iStack_f5c,*(int *)(iVar13 + 0x18) - *(int *)(iVar1 + 0x18));
            puVar11[6] = *(int *)(iVar1 + 0x18) + (int)uVar15;
            uVar15 = rwFixMul(iStack_f5c,*(int *)(iVar13 + 0x20) - *(int *)(iVar1 + 0x20));
            puVar11[8] = *(int *)(iVar1 + 0x20) + (int)uVar15;
            *piVar10 = (int)puVar11;
            puVar11 = puVar11 + 0x1d;
          }
          if (bStack_f65 == 0) {
            *piVar9 = iVar1;
          }
          else {
            if ((bStack_f65 & 4) == 0) {
              uVar15 = rwFixDiv(local_f60,local_f60 - uVar7);
              iStack_f5c = (int)uVar15;
              puVar11[7] = DAT_1005e060;
              bVar8 = *(byte *)(iVar1 + 0x48) & 0xfb | 8;
            }
            else {
              uVar15 = rwFixDiv(local_f64,local_f64 - uVar6);
              iStack_f5c = (int)uVar15;
              puVar11[7] = DAT_1005e05c;
              bVar8 = *(byte *)(iVar1 + 0x48) & 0xf7 | 4;
            }
            *(byte *)(puVar11 + 0x12) = bVar8;
            uVar15 = rwFixMul(iStack_f5c,*(int *)(iVar1 + 0x18) - *(int *)(iVar13 + 0x18));
            puVar11[6] = *(int *)(iVar13 + 0x18) + (int)uVar15;
            iVar13 = *(int *)(iVar13 + 0x20);
            uVar15 = rwFixMul(iStack_f5c,*(int *)(iVar1 + 0x20) - iVar13);
            puVar11[8] = (int)uVar15 + iVar13;
            *piVar9 = (int)puVar11;
            puVar11 = puVar11 + 0x1d;
          }
          piVar10 = piVar9 + 1;
        }
        local_f48 = local_f48 + -1;
        iVar13 = iVar1;
        local_f64 = uVar6;
        local_f60 = uVar7;
      } while (-1 < local_f48);
      puVar12 = param_1;
      ppiVar14 = local_f44;
      for (iVar13 = 10; iVar13 != 0; iVar13 = iVar13 + -1) {
        *ppiVar14 = (int *)*puVar12;
        puVar12 = puVar12 + 1;
        ppiVar14 = ppiVar14 + 1;
      }
      local_f0a = (undefined1)((int)piVar10 - (int)local_f08 >> 2);
    }
    local_f18 = param_1[0xb];
    local_f14 = 0;
    local_f10 = param_1[0xd];
    uVar2 = FUN_10033250(local_f44);
    uVar4 = uVar4 | CONCAT22(extraout_var,uVar2);
  }
  return uVar4;
}


