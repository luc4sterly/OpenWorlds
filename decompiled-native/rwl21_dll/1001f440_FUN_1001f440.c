// 1001f440 FUN_1001f440 [Global]
// programa: RWL21.DLL

int * FUN_1001f440(int *param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int local_38;
  float *local_34;
  uint local_30;
  int local_2c;
  float *local_20;
  float *local_1c;
  float local_18;
  float local_14;
  float local_10;
  float *local_c;
  float *local_8;
  int local_4;
  
  if (param_1 == (int *)0x0) {
    iVar13 = 1;
  }
  else {
    if (param_1[1] == 1) {
      local_30 = *param_1 - 2;
      goto LAB_1001f491;
    }
    if (param_1[1] == 2) {
      local_30 = *param_1 - 3;
      goto LAB_1001f491;
    }
    iVar13 = 0x11;
  }
  FUN_1000cba0(iVar13);
  local_30 = 0;
LAB_1001f491:
  piVar3 = param_1 + 4;
  if (param_1[1] == 1) {
    uVar12 = local_30;
    if (9 < (int)local_30) {
      uVar12 = 10;
    }
    pfVar1 = *(float **)(&DAT_1005dfe0 + uVar12 * 4);
    if (pfVar1 == (float *)0x0) {
      return (int *)0x0;
    }
    local_4 = 0;
    if (0 < (int)local_30) {
      local_20 = pfVar1 + (uVar12 - local_30) * uVar12;
      iVar13 = (int)uVar12 / 2;
      local_8 = param_2 + iVar13 * -3;
      local_34 = (float *)(param_1 + 7);
      local_c = pfVar1;
      do {
        local_18 = 0.0;
        local_14 = 0.0;
        local_10 = 0.0;
        if (local_4 < iVar13) {
          pfVar10 = local_c;
          pfVar9 = param_2;
          uVar6 = uVar12;
          if (0 < (int)uVar12) {
            do {
              FUN_100428a0(&local_18,pfVar9,*pfVar10,&local_18);
              uVar6 = uVar6 - 1;
              pfVar10 = pfVar10 + 1;
              pfVar9 = pfVar9 + 3;
            } while (uVar6 != 0);
          }
        }
        else if (local_4 < (int)(local_30 - iVar13)) {
          if (0 < (int)uVar12) {
            pfVar10 = pfVar1 + uVar12 * iVar13;
            pfVar9 = local_8;
            uVar6 = uVar12;
            do {
              fVar2 = *pfVar10;
              pfVar10 = pfVar10 + 1;
              FUN_100428a0(&local_18,pfVar9,fVar2,&local_18);
              uVar6 = uVar6 - 1;
              pfVar9 = pfVar9 + 3;
            } while (uVar6 != 0);
          }
        }
        else if (0 < (int)uVar12) {
          pfVar10 = param_2 + (local_30 - uVar12) * 3;
          uVar6 = uVar12;
          pfVar9 = local_20;
          do {
            fVar2 = *pfVar9;
            pfVar9 = pfVar9 + 1;
            FUN_100428a0(&local_18,pfVar10,fVar2,&local_18);
            uVar6 = uVar6 - 1;
            pfVar10 = pfVar10 + 3;
          } while (uVar6 != 0);
        }
        *local_34 = local_18;
        local_8 = local_8 + 3;
        local_34[1] = local_14;
        local_34[2] = local_10;
        local_20 = local_20 + uVar12;
        local_c = local_c + uVar12;
        local_4 = local_4 + 1;
        local_34 = local_34 + 3;
      } while (local_4 < (int)local_30);
    }
    *piVar3 = param_1[10];
    param_1[5] = param_1[0xb];
    param_1[6] = param_1[0xc];
    piVar3[local_30 * 3 + 3] = param_1[local_30 * 3 + 1];
    piVar3[local_30 * 3 + 4] = piVar3[local_30 * 3 + -2];
    piVar3[local_30 * 3 + 5] = piVar3[local_30 * 3 + -1];
  }
  else {
    if (param_1[1] != 2) {
      FUN_1000cba0(0x11);
      return (int *)0x0;
    }
    uVar12 = local_30;
    if (9 < (int)local_30) {
      uVar12 = 10;
    }
    uVar6 = (int)uVar12 >> 0x1f;
    if (((uVar12 ^ uVar6) - uVar6 & 1 ^ uVar6) == uVar6) {
      iVar13 = (int)uVar12 / 2;
      puVar4 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(iVar13 * 4);
      if (puVar4 == (undefined4 *)0x0) {
        FUN_1000cba0(3);
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = 1;
        puVar4[1] = 4;
        if (2 < iVar13) {
          iVar7 = iVar13 + -2;
          piVar5 = puVar4 + 2;
          do {
            iVar7 = iVar7 + -1;
            *piVar5 = piVar5[-1] * 4 - piVar5[-2];
            piVar5 = piVar5 + 1;
          } while (iVar7 != 0);
        }
      }
      if (puVar4 == (undefined4 *)0x0) {
        return (int *)0x0;
      }
      local_38 = puVar4[iVar13 + -1];
      (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar4);
      local_2c = iVar13 + 1;
      puVar4 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(local_2c * 4);
      if (puVar4 == (undefined4 *)0x0) {
        FUN_1000cba0(3);
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = 1;
        puVar4[1] = 2;
        if (2 < local_2c) {
          iVar13 = iVar13 + -1;
          piVar5 = puVar4 + 2;
          do {
            iVar13 = iVar13 + -1;
            *piVar5 = piVar5[-1] * 4 - piVar5[-2];
            piVar5 = piVar5 + 1;
          } while (iVar13 != 0);
        }
      }
      if (puVar4 == (undefined4 *)0x0) {
        return (int *)0x0;
      }
    }
    else {
      iVar13 = (int)uVar12 / 2;
      local_2c = iVar13 + 1;
      puVar4 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(local_2c * 4);
      if (puVar4 == (undefined4 *)0x0) {
        FUN_1000cba0(3);
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = 1;
        puVar4[1] = 3;
        if (2 < local_2c) {
          iVar7 = iVar13 + -1;
          piVar5 = puVar4 + 2;
          do {
            iVar7 = iVar7 + -1;
            *piVar5 = piVar5[-1] * 4 - piVar5[-2];
            piVar5 = piVar5 + 1;
          } while (iVar7 != 0);
        }
      }
      if (puVar4 == (undefined4 *)0x0) {
        return (int *)0x0;
      }
      local_38 = puVar4[iVar13];
      (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar4);
      puVar4 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(local_2c * 4);
      if (puVar4 == (undefined4 *)0x0) {
        FUN_1000cba0(3);
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = 1;
        puVar4[1] = 5;
        if (2 < local_2c) {
          iVar13 = iVar13 + -1;
          piVar5 = puVar4 + 2;
          do {
            iVar13 = iVar13 + -1;
            *piVar5 = piVar5[-1] * 4 - piVar5[-2];
            piVar5 = piVar5 + 1;
          } while (iVar13 != 0);
        }
      }
      if (puVar4 == (undefined4 *)0x0) {
        return (int *)0x0;
      }
    }
    local_34 = (float *)((int)uVar12 / 2);
    if (-1 < (int)local_34 + -1) {
      uVar6 = (int)local_34 + 1U >> 1;
      piVar5 = puVar4 + (int)local_34 + -1;
      do {
        uVar6 = uVar6 - 1;
        *piVar5 = -*piVar5;
        piVar5 = piVar5 + -2;
      } while (uVar6 != 0);
    }
    iVar13 = 0;
    if (0 < (int)local_30) {
      local_c = (float *)(puVar4 + (int)local_34);
      local_8 = (float *)((int)(uVar12 + 1) / 2);
      fVar2 = (float)local_38;
      local_1c = (float *)(param_1 + 7);
      while( true ) {
        iVar7 = iVar13 % (int)local_30;
        local_18 = (float)(int)*local_c * param_2[iVar7 * 3];
        local_14 = (float)(int)*local_c * param_2[iVar7 * 3 + 1];
        iVar11 = 1;
        local_10 = (float)(int)*local_c * param_2[iVar7 * 3 + 2];
        if (1 < local_2c) {
          do {
            iVar7 = (int)local_34 - iVar11;
            iVar11 = iVar11 + 1;
            iVar8 = (iVar13 + -1 + iVar11) % (int)local_30;
            local_18 = (float)(int)puVar4[iVar7] * param_2[iVar8 * 3] + local_18;
            local_14 = (float)(int)puVar4[iVar7] * param_2[iVar8 * 3 + 1] + local_14;
            local_10 = (float)(int)puVar4[iVar7] * param_2[iVar8 * 3 + 2] + local_10;
          } while (iVar11 < local_2c);
        }
        iVar7 = 1;
        if (1 < (int)local_8) {
          do {
            pfVar1 = param_2 + ((int)(local_30 + (iVar13 - iVar7)) % (int)local_30) * 3;
            iVar11 = (int)local_34 - iVar7;
            iVar7 = iVar7 + 1;
            local_18 = (float)(int)puVar4[iVar11] * *pfVar1 + local_18;
            local_14 = (float)(int)puVar4[iVar11] * pfVar1[1] + local_14;
            local_10 = (float)(int)puVar4[iVar11] * pfVar1[2] + local_10;
          } while (iVar7 < (int)local_8);
        }
        iVar13 = iVar13 + 1;
        *local_1c = local_18 / fVar2;
        local_1c[1] = local_14 / fVar2;
        if ((int)local_30 <= iVar13) break;
        local_1c[2] = local_10 / fVar2;
        local_1c = local_1c + 3;
      }
      local_1c[2] = local_10 / fVar2;
    }
    *piVar3 = piVar3[local_30 * 3];
    param_1[5] = piVar3[local_30 * 3 + 1];
    param_1[6] = piVar3[local_30 * 3 + 2];
    piVar3[local_30 * 3 + 3] = param_1[7];
    piVar3[local_30 * 3 + 4] = param_1[8];
    piVar3[local_30 * 3 + 5] = param_1[9];
    piVar3[local_30 * 3 + 6] = param_1[10];
    piVar3[local_30 * 3 + 7] = param_1[0xb];
    piVar3[local_30 * 3 + 8] = param_1[0xc];
    (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar4);
  }
  return param_1;
}


