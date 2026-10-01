// 1002d500 FUN_1002d500 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * FUN_1002d500(uint *param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  float fVar7;
  float10 extraout_ST0;
  float10 fVar8;
  float local_4;
  
  if ((param_1 == (uint *)0x0) || (param_1[0x11] != 1)) {
    param_1 = (uint *)0x0;
  }
  if (param_1 == (uint *)0x0) {
    FUN_1000cba0(0x65);
  }
  else {
    iVar3 = *(int *)(param_1[0x12] + 0x88);
    if ((((iVar3 == 0) || (*(int *)(iVar3 + 8) < 9)) ||
        (piVar4 = *(int **)(param_1[0x12] + 0x98), piVar4 == (int *)0x0)) || (*piVar4 < 0)) {
      *param_1 = *param_1 | 8;
      param_1[0x10] = 0xbf800000;
    }
    else {
      pfVar1 = (float *)(param_1 + 7);
      *pfVar1 = *(float *)(iVar3 + 0x2c4);
      param_1[8] = *(uint *)(iVar3 + 0x80);
      param_1[9] = *(uint *)(iVar3 + 0x2c8);
      param_1[10] = *(uint *)(iVar3 + 0x84);
      uVar5 = *(uint *)(iVar3 + 0x2cc);
      param_1[0xb] = uVar5;
      uVar6 = *(uint *)(iVar3 + 0x88);
      param_1[0xc] = uVar6;
      param_1[0xd] = (uint)((float)param_1[8] - *pfVar1);
      param_1[0xe] = (uint)((float)param_1[10] - (float)param_1[9]);
      param_1[0xf] = (uint)((float)param_1[0xc] - (float)param_1[0xb]);
      if (*(int *)(param_1[0x12] + 0x18c) != 1) {
        RwDotProduct(uVar6,uVar5);
        local_4 = (float)extraout_ST0;
        fVar8 = FUN_10041770((int *)&local_4);
        fVar2 = (float)fVar8;
        param_1[0xd] = (uint)(float)fVar8;
        param_1[0xe] = (uint)fVar2;
        param_1[0xf] = (uint)fVar2;
        fVar2 = fVar2 * _DAT_10052238;
        fVar7 = (*pfVar1 + (float)param_1[8]) * _DAT_10052238;
        *pfVar1 = fVar7 - fVar2;
        param_1[8] = (uint)(fVar7 + fVar2);
        fVar7 = ((float)param_1[9] + (float)param_1[10]) * _DAT_10052238;
        param_1[9] = (uint)(fVar7 - fVar2);
        param_1[10] = (uint)(fVar7 + fVar2);
        fVar7 = ((float)param_1[0xc] + (float)param_1[0xb]) * _DAT_10052238;
        param_1[0xb] = (uint)(fVar7 - fVar2);
        param_1[0xc] = (uint)(fVar7 + fVar2);
      }
      *param_1 = *param_1 & 0xfffffff7;
    }
  }
  return param_1;
}


