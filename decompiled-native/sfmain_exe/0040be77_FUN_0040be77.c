// 0040be77 FUN_0040be77 [Global]
// programa: sfmain.exe

void FUN_0040be77(float *param_1,int *param_2,int *param_3)

{
  float fVar1;
  int in_EAX;
  int extraout_EAX;
  int *extraout_ECX;
  int iVar2;
  int unaff_EBX;
  float *pfVar3;
  int iVar4;
  float10 fVar5;
  float *local_1c;
  int local_18;
  float local_14;
  
  *param_2 = 1;
  *param_3 = 1;
  local_1c = param_1;
  for (local_18 = 1; local_1c = local_1c + 1, local_18 <= unaff_EBX; local_18 = local_18 + 1) {
    local_14 = 0.0;
    fVar5 = FUN_0042b8ce();
    iVar2 = (int)ROUND(fVar5);
    iVar4 = iVar2 + 0x9b;
    pfVar3 = (float *)(iVar2 * 4 + in_EAX);
    for (; iVar2 <= iVar4; iVar2 = iVar2 + 4) {
      fVar1 = *pfVar3;
      pfVar3 = pfVar3 + 4;
      local_14 = ABS(fVar1 - *(float *)(in_EAX + (*extraout_ECX + iVar2) * 4)) + local_14;
    }
    *(float *)((int)param_1 + extraout_EAX) = local_14;
    if (*(float *)((int)param_1 + extraout_EAX) < param_1[*param_2]) {
      *param_2 = local_18;
    }
    if (param_1[*param_3] < *local_1c) {
      *param_3 = local_18;
    }
  }
  return;
}


