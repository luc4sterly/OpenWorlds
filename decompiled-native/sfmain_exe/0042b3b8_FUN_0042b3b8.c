// 0042b3b8 FUN_0042b3b8 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall
FUN_0042b3b8(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,float param_7)

{
  int *piVar1;
  undefined4 *puVar2;
  float *pfVar3;
  float fVar4;
  int in_EAX;
  float *pfVar5;
  float *pfVar6;
  int unaff_EBX;
  int local_28;
  int local_24;
  int local_20;
  
  for (local_24 = 0; local_24 < param_1; local_24 = local_24 + 1) {
    piVar1 = *(int **)(local_24 * 4 + param_2);
    pfVar6 = *(float **)(local_24 * 4 + in_EAX);
    puVar2 = *(undefined4 **)(local_24 * 4 + param_6);
    pfVar3 = *(float **)(local_24 * 4 + param_5);
    fVar4 = *pfVar6;
    for (local_28 = 0; local_28 < param_4; local_28 = local_28 + 1) {
      *pfVar3 = *(float *)(local_28 * 4 + param_3);
      if (fVar4 != 1.0) {
        *(float *)(local_28 * 4 + param_3) = *pfVar6 * *pfVar3;
      }
      if (*piVar1 != 0x3f800000) {
        if (_DAT_004e57a0 == 0) {
          FUN_004296b9(s_Filter_irregularity__004377c8);
        }
        _DAT_004e57a0 = 1;
      }
      for (local_20 = 1; local_20 <= unaff_EBX; local_20 = local_20 + 1) {
        pfVar5 = (float *)(local_28 * 4 + param_3);
        *pfVar5 = (pfVar6[local_20] * pfVar3[local_20] -
                  (float)piVar1[local_20] * (float)puVar2[local_20]) + *pfVar5;
      }
      *puVar2 = *(undefined4 *)(local_28 * 4 + param_3);
      for (local_20 = unaff_EBX; 0 < local_20; local_20 = local_20 + -1) {
        pfVar3[local_20] = pfVar3[local_20 + -1];
        puVar2[local_20] = puVar2[local_20 + -1];
      }
    }
  }
  if (param_7 != 1.0) {
    for (local_28 = 0; local_28 < param_4; local_28 = local_28 + 1) {
      pfVar6 = (float *)(local_28 * 4 + param_3);
      *pfVar6 = *pfVar6 * param_7;
    }
  }
  return;
}


