// 1001ecc0 RwCreateSpline [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * RwCreateSpline(int param_1,int param_2,float *param_3)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float *pfVar15;
  int *piVar16;
  int *piVar17;
  int iVar18;
  int iVar19;
  undefined4 *puVar20;
  uint uVar21;
  
                    /* 0x1ecc0  45  RwCreateSpline */
  iVar19 = 0;
  if (DAT_1005ac88 == 0) {
    DAT_1005ac90 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x3030);
    if (DAT_1005ac90 == 0) {
      FUN_1000cba0(3);
    }
    else {
      DAT_1005ac94 = DAT_1005ac90 + 0x404;
      DAT_1005ac98 = DAT_1005ac90 + 0x808;
      DAT_1005ac9c = DAT_1005ac90 + 0xc0c;
      DAT_1005aca0 = DAT_1005ac90 + 0x1010;
      DAT_1005aca4 = DAT_1005ac90 + 0x1414;
      DAT_1005aca8 = DAT_1005ac90 + 0x1818;
      DAT_1005acac = DAT_1005ac90 + 0x1c1c;
      DAT_1005acb0 = DAT_1005ac90 + 0x2020;
      DAT_1005acb4 = DAT_1005ac90 + 0x2424;
      iVar18 = 0;
      DAT_1005acb8 = DAT_1005ac90 + 0x2828;
      DAT_1005acbc = DAT_1005ac90 + 0x2c2c;
      do {
        fVar2 = (float)iVar19 * _DAT_100521a0;
        fVar14 = (float)_DAT_100521e0;
        fVar13 = (float)_DAT_100521b0;
        fVar12 = (float)_DAT_100521b0;
        fVar3 = (float)_DAT_100521b8 * fVar2;
        *(float *)(DAT_1005ac90 + iVar18) =
             fVar2 * fVar2 * fVar2 * (float)_DAT_100521a8 * (float)_DAT_100521b0;
        fVar6 = (float)_DAT_100521d0;
        fVar4 = (float)_DAT_100521c0 * fVar2;
        fVar5 = (float)_DAT_100521d8;
        *(float *)(DAT_1005ac94 + iVar18) =
             ((((float)_DAT_100521c0 + fVar3) * fVar2 + (float)_DAT_100521c0) * fVar2 +
             (float)_DAT_100521c8) * (float)_DAT_100521a8 * (float)_DAT_100521b0;
        fVar9 = (float)_DAT_100521c0;
        *(float *)(DAT_1005ac98 + iVar18) =
             ((fVar4 - fVar6) * fVar2 * fVar2 + fVar5) * (float)_DAT_100521a8 * (float)_DAT_100521b0
        ;
        fVar8 = (float)_DAT_100521e8;
        fVar11 = (float)_DAT_100521c8;
        fVar10 = (float)_DAT_100521b0;
        fVar7 = (float)_DAT_100521c8;
        fVar6 = (float)_DAT_100521e0;
        fVar5 = (float)_DAT_100521b0;
        *(float *)(DAT_1005ac9c + iVar18) =
             (((fVar9 - fVar2) * fVar2 - (float)_DAT_100521c0) * fVar2 + (float)_DAT_100521c8) *
             (float)_DAT_100521a8 * (float)_DAT_100521b0;
        *(float *)(DAT_1005aca0 + iVar18) = fVar2 * fVar2 * fVar14 * fVar13;
        *(float *)(DAT_1005aca4 + iVar18) = ((fVar8 + fVar3) * fVar2 + fVar7) * fVar6 * fVar5;
        fVar6 = (float)_DAT_100521e8;
        fVar5 = (float)_DAT_100521b0;
        fVar9 = (float)_DAT_100521e8;
        fVar8 = (float)_DAT_100521c8;
        *(float *)(DAT_1005aca8 + iVar18) =
             (fVar4 - (float)_DAT_100521d8) * fVar2 * (float)_DAT_100521e0 * (float)_DAT_100521b0;
        fVar7 = (float)_DAT_100521b0;
        *(float *)(DAT_1005acac + iVar18) =
             ((fVar9 - fVar2) * fVar2 - (float)_DAT_100521c8) * (float)_DAT_100521e0 *
             (float)_DAT_100521b0;
        *(float *)(DAT_1005acb0 + iVar18) = fVar2 * fVar12;
        *(float *)(DAT_1005acb4 + iVar18) = (fVar3 + fVar11) * fVar10;
        *(float *)(DAT_1005acb8 + iVar18) = (fVar4 - fVar6) * fVar5;
        *(float *)(DAT_1005acbc + iVar18) = (fVar8 - fVar2) * fVar7;
        iVar18 = iVar18 + 4;
        iVar19 = iVar19 + 1;
      } while (iVar18 < 0x401);
    }
    if (DAT_1005ac90 == 0) {
      return (int *)0x0;
    }
    DAT_1005ac88 = 1;
  }
  if (param_3 == (float *)0x0) {
    FUN_1000cba0(1);
    return (int *)0x0;
  }
  if (DAT_1005ac8c == 0) {
    uVar21 = 4;
    do {
      pfVar15 = FUN_1001f160(uVar21);
      *(float **)(&DAT_1005dfe0 + uVar21 * 4) = pfVar15;
      if (pfVar15 == (float *)0x0) {
        if (3 < (int)(uVar21 - 1)) {
          puVar20 = (undefined4 *)(&DAT_1005dfe0 + (uVar21 - 1) * 4);
          do {
            uVar1 = *puVar20;
            puVar20 = puVar20 + -1;
            (**(code **)(PTR_DAT_1005b69c + 0x358))(uVar1);
          } while ((undefined4 *)((int)&DAT_1005dfec + 3) < puVar20);
        }
        return (int *)0x0;
      }
      uVar21 = uVar21 + 1;
    } while ((int)uVar21 < 0xb);
    DAT_1005ac8c = 1;
  }
  if (param_1 < 4) {
    FUN_1000cba0(0xb);
    return (int *)0x0;
  }
  if (param_2 == 1) {
    piVar16 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(param_1 * 0xc + 0x28);
    if (piVar16 == (int *)0x0) {
      FUN_1000cba0(3);
      return (int *)0x0;
    }
    iVar19 = param_1 + 2;
  }
  else {
    if (param_2 != 2) {
      FUN_1000cba0(0x11);
      return (int *)0x0;
    }
    piVar16 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(param_1 * 0xc + 0x34);
    if (piVar16 == (int *)0x0) {
      FUN_1000cba0(3);
      return (int *)0x0;
    }
    iVar19 = param_1 + 3;
  }
  *piVar16 = iVar19;
  piVar16[1] = param_2;
  piVar17 = FUN_1001f440(piVar16,param_3);
  if (piVar17 == (int *)0x0) {
    (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar16);
    return (int *)0x0;
  }
  pfVar15 = (float *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(param_1 * 0xc);
  piVar16[3] = (int)pfVar15;
  if (pfVar15 == (float *)0x0) {
    FUN_1000cba0(3);
    (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar16);
    return (int *)0x0;
  }
  for (uVar21 = (uint)(param_1 * 0xc) >> 2; uVar21 != 0; uVar21 = uVar21 - 1) {
    *pfVar15 = *param_3;
    param_3 = param_3 + 1;
    pfVar15 = pfVar15 + 1;
  }
  for (iVar19 = 0; iVar19 != 0; iVar19 = iVar19 + -1) {
    *(undefined1 *)pfVar15 = *(undefined1 *)param_3;
    param_3 = (float *)((int)param_3 + 1);
    pfVar15 = (float *)((int)pfVar15 + 1);
  }
  return piVar16;
}


