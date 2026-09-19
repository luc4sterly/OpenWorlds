// 10001100 FUN_10001100 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_10001100(int param_1,float *param_2,float *param_3)

{
  undefined4 *puVar1;
  float *pfVar2;
  uint uVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  undefined4 *puVar8;
  float10 fVar9;
  float *pfVar10;
  float *pfVar11;
  float local_c1c;
  float local_c10;
  float local_c0c [6];
  float local_bf4 [765];
  
  local_c10 = -1.0;
  uVar3 = (uint)*(byte *)(param_1 + 0x3a);
  pfVar2 = *(float **)(param_1 + 0x3c);
  iVar5 = param_1 + 0x3c;
  if (param_2 != (float *)0x0) {
    *param_2 = *pfVar2;
    iVar6 = uVar3 - 1;
    param_2[1] = pfVar2[1];
    param_2[2] = pfVar2[2];
    if (0 < iVar6) {
      do {
        puVar8 = (undefined4 *)(iVar5 + 4);
        iVar5 = iVar5 + 4;
        RwAddVector((float *)*puVar8,param_2,param_2);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    if (uVar3 == 0) {
      local_c1c = 0.0;
    }
    else {
      local_c1c = _DAT_10052004 / (float)uVar3;
    }
    RwScaleVector(param_2,local_c1c,param_2);
  }
  if (param_3 != (float *)0x0) {
    puVar8 = (undefined4 *)(param_1 + 0x40);
    *param_3 = 0.0;
    param_3[1] = 0.0;
    param_3[2] = 0.0;
    RwSubtractVector((float *)*puVar8,pfVar2,local_bf4);
    local_c1c = (float)(uVar3 - 2);
    pfVar4 = local_bf4;
    if (0 < (int)local_c1c) {
      do {
        puVar1 = puVar8 + 1;
        pfVar7 = pfVar4 + 3;
        puVar8 = puVar8 + 1;
        RwSubtractVector((float *)*puVar1,pfVar2,pfVar7);
        pfVar10 = param_3;
        pfVar11 = param_3;
        pfVar4 = (float *)RwCrossProduct(pfVar4,pfVar7,local_c0c);
        RwAddVector(pfVar4,pfVar10,pfVar11);
        local_c1c = (float)((int)local_c1c + -1);
        pfVar4 = pfVar7;
      } while (local_c1c != 0.0);
    }
    fVar9 = rwLengthNormaliseVector(param_3,param_3);
    local_c10 = (float)fVar9;
  }
  return (float10)local_c10;
}


