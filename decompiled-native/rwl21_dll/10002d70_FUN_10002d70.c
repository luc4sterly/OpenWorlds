// 10002d70 FUN_10002d70 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_10002d70(int param_1)

{
  uint *puVar1;
  int iVar2;
  float fVar3;
  int *piVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined4 extraout_ECX;
  int extraout_EDX;
  int extraout_EDX_00;
  int iVar11;
  uint *puVar12;
  int iVar13;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 fVar14;
  undefined8 uVar15;
  int iStack_38;
  uint *puStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  float local_18 [3];
  float local_c [3];
  
  uVar7 = (uint)*(byte *)(param_1 + 0x3a);
  if (*(byte *)(param_1 + 0x3a) < 4) {
    return param_1;
  }
  iVar13 = 0;
  bVar5 = false;
  if (DAT_1005805c == (uint *)0x0) {
    puVar8 = (uint *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(uVar7 * 0x34);
  }
  else {
    puVar8 = DAT_1005805c;
    puVar1 = DAT_1005805c;
    uVar6 = DAT_10058060;
    if ((int)uVar7 <= (int)DAT_10058060) goto LAB_10002e0f;
    puVar8 = (uint *)(**(code **)(PTR_DAT_1005b69c + 0x354))(DAT_1005805c,uVar7 * 0x34);
  }
  puVar1 = puVar8;
  uVar6 = uVar7;
  if (puVar8 == (uint *)0x0) {
    FUN_1000cba0(3);
    puVar1 = DAT_1005805c;
    uVar6 = DAT_10058060;
  }
LAB_10002e0f:
  DAT_10058060 = uVar6;
  DAT_1005805c = puVar1;
  if (puVar8 != (uint *)0x0) {
    FUN_10001100(param_1,local_c,local_18);
    RwDotProduct(local_18,local_c);
    puVar1 = (uint *)(param_1 + 0x3c);
    fVar3 = (float)-extraout_ST0;
    iVar11 = uVar7 - 1;
    iVar2 = iVar11 + (uVar7 * 3 + -3) * 4;
    puVar12 = puVar8 + iVar2;
    puVar12[1] = (uint)(puVar8 + iVar2 + -0xd);
    *puVar12 = (uint)puVar8;
    puVar12[2] = puVar1[iVar11];
    RwDotProduct(local_18,iVar11);
    if ((extraout_ST0_00 + (float10)fVar3 < (float10)_DAT_1005207c) ||
       (0x3a83126f < (int)(float)(extraout_ST0_00 + (float10)fVar3))) {
      iVar13 = 1;
    }
    iStack_38 = uVar7 - 2;
    if (0 < iStack_38) {
      puStack_24 = puVar1 + iStack_38;
      puVar12 = puVar8 + iStack_38 * 0xd + 2;
      do {
        puVar12[-1] = (uint)(puVar12 + -0xf);
        puVar12[-2] = (uint)(puVar12 + 0xb);
        *puVar12 = *puStack_24;
        RwDotProduct(local_18,puStack_24);
        if ((extraout_ST0_01 + (float10)fVar3 < (float10)_DAT_1005207c) ||
           (0x3a83126f < (int)(float)(extraout_ST0_01 + (float10)fVar3))) {
          iVar13 = 1;
        }
        puVar12 = puVar12 + -0xd;
        puStack_24 = puStack_24 + -1;
        iStack_38 = iStack_38 + -1;
      } while (iStack_38 != 0);
    }
    puVar8[1] = (uint)(puVar8 + uVar7 * 0xd + -0xd);
    *puVar8 = (uint)(puVar8 + 0xd);
    puVar8[2] = *puVar1;
    RwDotProduct(local_18,puVar1);
    if ((extraout_ST0_02 + (float10)fVar3 < (float10)_DAT_1005207c) ||
       (0x3a83126f < (int)(float)(extraout_ST0_02 + (float10)fVar3))) {
      iVar13 = 1;
    }
    do {
      puStack_24 = puVar8;
      fVar14 = FUN_100030a0((int *)puVar8,param_1,local_18,iVar13);
      puVar8 = (uint *)*puVar8;
      bVar5 = (bool)(bVar5 | fVar14 < (float10)_DAT_10052084);
    } while (puStack_24 < puVar8);
    if (((*(int *)(PTR_DAT_1005b69c + 0x1c) < (int)uVar7) || (iVar13 != 0)) || (bVar5)) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
    }
    if (!bVar5) {
      uVar15 = FUN_10003460(uVar7,extraout_EDX,puStack_24);
      piVar9 = (int *)uVar15;
      while (piVar9 != (int *)0x0) {
        puStack_24 = (uint *)piVar9[2];
        iStack_20 = ((int *)*piVar9)[2];
        uStack_1c = *(undefined4 *)(*(int *)*piVar9 + 8);
        puVar10 = FUN_100013f0(&puStack_24,(float *)(-(uint)(iVar13 == 0) & (uint)local_18));
        if (puVar10 == (undefined4 *)0x0) {
          return param_1;
        }
        puVar10[0xc] = *(undefined4 *)(param_1 + 0x30);
        *(undefined4 **)(param_1 + 0x30) = puVar10;
        puVar10[0xb] = param_1;
        piVar4 = (int *)*piVar9;
        iVar2 = *piVar4;
        *piVar9 = iVar2;
        *(int **)(iVar2 + 4) = piVar9;
        *piVar4 = 0;
        piVar4[1] = 0;
        if (piVar9[1] == *piVar9) {
          return param_1;
        }
        FUN_100030a0(piVar9,param_1,local_18,iVar13);
        piVar9 = (int *)piVar9[1];
        FUN_100030a0(piVar9,param_1,local_18,iVar13);
        uVar15 = FUN_10003460(extraout_ECX,extraout_EDX_00,piVar9);
        piVar9 = (int *)uVar15;
      }
    }
  }
  return param_1;
}


