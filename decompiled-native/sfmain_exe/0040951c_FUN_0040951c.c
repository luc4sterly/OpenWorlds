// 0040951c FUN_0040951c [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040951c(int *param_1,int param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *extraout_EAX;
  int iVar3;
  int iVar4;
  int extraout_EDX;
  float *unaff_EBX;
  int iVar5;
  float *pfVar6;
  float10 fVar7;
  int local_2c;
  float local_28 [2];
  uint local_20;
  int local_1c;
  int local_10;
  
  FUN_0040be77(unaff_EBX,param_1,param_3);
  local_10 = 0;
  *param_4 = *(int *)(param_2 + *param_1 * 4);
  iVar5 = *param_4 + -3;
  fVar7 = FUN_0042b8ce();
  local_1c = (int)ROUND(fVar7);
  if (iVar5 < 0x2a) {
    iVar5 = 0x29;
  }
  iVar4 = 0;
  iVar3 = extraout_EDX;
  while( true ) {
    iVar2 = *param_4 + 3;
    if (*(int *)(param_2 + 0xf0) <= *param_4 + 3) {
      iVar2 = *(int *)(param_2 + 0xf0);
    }
    if (iVar2 < iVar5) break;
    for (piVar1 = (int *)(iVar3 * 4 + param_2); *piVar1 < iVar5; piVar1 = piVar1 + 1) {
      iVar3 = iVar3 + 1;
    }
    if (iVar5 != *piVar1) {
      *(int *)(&DAT_0043fe70 + iVar4) = iVar5;
      local_10 = local_10 + 1;
      iVar4 = iVar4 + 4;
    }
    iVar5 = iVar5 + 1;
  }
  if (0 < local_10) {
    FUN_0040be77((float *)&stack0xffffffb8,(int *)local_28,&local_2c);
    if (local_28[(int)local_28[0] + -8] < (float)local_1c) {
      *param_4 = *(int *)(&DAT_0043fe6c + (int)local_28[0] * 4);
      fVar7 = FUN_0042b8ce();
      local_1c = (int)ROUND(fVar7);
    }
  }
  if (0x4f < *param_4) {
    fVar7 = FUN_0042b8ce();
    local_20 = (uint)ROUND(fVar7);
    _DAT_0043fe70 = local_20;
    if ((local_20 & 1) == 0) {
      _DAT_0043fe74 = local_20 + 1;
      _DAT_0043fe70 = local_20 - 1;
    }
    FUN_0040be77((float *)&stack0xffffffb8,(int *)local_28,&local_2c);
    if (local_28[(int)local_28[0] + -8] < (float)local_1c) {
      *param_4 = *(int *)(&DAT_0043fe6c + (int)local_28[0] * 4);
      iVar5 = *param_1;
      fVar7 = FUN_0042b8ce();
      local_1c = (int)ROUND(fVar7);
      *extraout_EAX = iVar5 + -0x14;
    }
  }
  unaff_EBX[*param_1] = (float)local_1c;
  iVar5 = *param_1 + -5;
  if (iVar5 < 2) {
    iVar5 = 1;
  }
  *param_3 = iVar5;
  iVar5 = iVar5 + 1;
  pfVar6 = unaff_EBX + iVar5;
  while( true ) {
    iVar3 = *param_1 + 5;
    if (0x3b < iVar3) {
      iVar3 = 0x3c;
    }
    if (iVar3 < iVar5) break;
    if (unaff_EBX[*param_3] < *pfVar6) {
      *param_3 = iVar5;
    }
    pfVar6 = pfVar6 + 1;
    iVar5 = iVar5 + 1;
  }
  return;
}


