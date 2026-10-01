// 1001f160 FUN_1001f160 [Global]
// program: RWL21.DLL

float * FUN_1001f160(uint param_1)

{
  float fVar1;
  int *piVar2;
  uint uVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  float *pfVar11;
  int iVar12;
  float *pfVar13;
  float *pfStack_24;
  float *pfStack_1c;
  int iStack_18;
  
  uVar3 = param_1 * param_1;
  pfVar4 = (float *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(uVar3 * 4);
  if (pfVar4 == (float *)0x0) {
    FUN_1000cba0(3);
    return (float *)0x0;
  }
  pfVar11 = pfVar4;
  for (uVar7 = uVar3 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pfVar11 = 0.0;
    pfVar11 = pfVar11 + 1;
  }
  for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
    *(undefined1 *)pfVar11 = 0;
    pfVar11 = (float *)((int)pfVar11 + 1);
  }
  iVar8 = param_1 - 1;
  puVar5 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(iVar8 * 4);
  if (puVar5 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
    puVar5 = (undefined4 *)0x0;
  }
  else {
    *puVar5 = 1;
    puVar5[1] = 4;
    if (2 < iVar8) {
      iVar12 = param_1 - 3;
      piVar6 = puVar5 + 2;
      do {
        iVar12 = iVar12 + -1;
        *piVar6 = piVar6[-1] * 4 - piVar6[-2];
        piVar6 = piVar6 + 1;
      } while (iVar12 != 0);
    }
  }
  if (puVar5 != (undefined4 *)0x0) {
    iVar12 = puVar5[param_1 - 2];
    (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar5);
    piVar6 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(param_1 << 2);
    if (piVar6 == (int *)0x0) {
      FUN_1000cba0(3);
      piVar6 = (int *)0x0;
    }
    else {
      *piVar6 = 1;
      piVar6[1] = 2;
      if (2 < (int)param_1) {
        iVar10 = param_1 - 2;
        piVar9 = piVar6 + 2;
        do {
          iVar10 = iVar10 + -1;
          *piVar9 = piVar9[-1] * 4 - piVar9[-2];
          piVar9 = piVar9 + 1;
        } while (iVar10 != 0);
      }
    }
    if (piVar6 != (int *)0x0) {
      if (-1 < (int)(param_1 - 2)) {
        uVar7 = param_1 >> 1;
        piVar9 = piVar6 + (param_1 - 2);
        do {
          uVar7 = uVar7 - 1;
          *piVar9 = -*piVar9;
          piVar9 = piVar9 + -2;
        } while (uVar7 != 0);
      }
      iStack_18 = 0;
      if (0 < (int)param_1) {
        piVar9 = piVar6 + (param_1 - 1);
        pfVar11 = pfVar4;
        do {
          *pfVar11 = (float)*piVar9 / (float)iVar12;
          iVar10 = iStack_18;
          piVar2 = piVar6;
          pfVar13 = pfVar11;
          if (0 < iStack_18) {
            while( true ) {
              pfVar13 = pfVar13 + 1;
              fVar1 = (float)(int)(*piVar9 * piVar2[1] *
                                  ((-(uint)((param_1 & 1) == 0) & 0xfffffffc) + 2)) / (float)iVar12;
              if (iVar10 + -1 == 0) break;
              *pfVar13 = fVar1;
              iVar10 = iVar10 + -1;
              piVar2 = piVar2 + 1;
            }
            *pfVar13 = fVar1;
          }
          piVar9 = piVar9 + -1;
          pfVar11 = pfVar11 + param_1;
          iStack_18 = iStack_18 + 1;
        } while (iStack_18 < (int)param_1);
      }
      iVar12 = 0;
      pfVar4[uVar3 - 1] = *pfVar4;
      if (0 < (int)param_1) {
        pfStack_24 = pfVar4 + iVar8;
        pfStack_1c = pfVar4 + (uVar3 - iVar8) + -1;
        do {
          if (iVar12 < iVar8) {
            iVar10 = iVar8 - iVar12;
            pfVar11 = pfStack_24;
            pfVar13 = pfStack_1c;
            do {
              fVar1 = *pfVar13;
              pfVar13 = pfVar13 + 1;
              *pfVar11 = fVar1;
              pfVar11 = pfVar11 + -1;
              iVar10 = iVar10 + -1;
            } while (iVar10 != 0);
          }
          pfStack_24 = pfStack_24 + param_1;
          pfStack_1c = pfStack_1c + -param_1;
          iVar12 = iVar12 + 1;
        } while (iVar12 < (int)param_1);
      }
      (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar6);
      return pfVar4;
    }
    (**(code **)(PTR_DAT_1005b69c + 0x358))(pfVar4);
    return (float *)0x0;
  }
  (**(code **)(PTR_DAT_1005b69c + 0x358))(pfVar4);
  return (float *)0x0;
}


