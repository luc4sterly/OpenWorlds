// 00401541 FUN_00401541 [Global]
// program: sfmain.exe

void __fastcall FUN_00401541(float *param_1,int param_2)

{
  float fVar1;
  float *in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int unaff_EBX;
  float *pfVar6;
  float10 extraout_ST0;
  float afStack_8c [12];
  float afStack_5c [13];
  float *local_28;
  float *local_24;
  int local_20;
  float *local_1c;
  float *local_18;
  float local_14;
  float *local_10;
  
  local_20 = param_2;
  local_28 = param_1;
  for (iVar2 = 0; iVar2 <= param_2 * 4; iVar2 = iVar2 + 4) {
    *(undefined4 *)((int)afStack_8c + iVar2 + 4) = 0;
    *(undefined4 *)((int)afStack_5c + iVar2) = *(undefined4 *)((int)afStack_8c + iVar2 + 4);
  }
  local_14 = *in_EAX;
  iVar2 = 4;
  local_1c = (float *)(unaff_EBX + 4);
  local_10 = (float *)0x1;
  local_18 = in_EAX + 1;
  local_24 = in_EAX + -1;
  do {
    pfVar5 = local_10;
    if (local_20 < (int)local_10) {
LAB_00401674:
      if (local_14 < 0.0) {
        local_14 = 0.0;
      }
      afStack_8c[0] = 5.885563e-39;
      FUN_0042b7a8(param_1,pfVar5);
      *local_28 = (float)extraout_ST0;
      return;
    }
    iVar4 = (int)local_10 * 4;
    pfVar6 = (float *)((int)local_24 + iVar2);
    pfVar5 = (float *)(unaff_EBX + iVar2);
    *local_1c = -*local_18;
    for (iVar3 = 4; iVar3 < iVar4; iVar3 = iVar3 + 4) {
      *(undefined4 *)((int)afStack_8c + iVar3 + 4) = *(undefined4 *)((int)afStack_5c + iVar3);
      fVar1 = *pfVar6;
      pfVar6 = pfVar6 + -1;
      *pfVar5 = *pfVar5 - *(float *)((int)afStack_5c + iVar3) * fVar1;
    }
    if (ABS(local_14) == 0.0) {
      param_1 = (float *)0x0;
      local_14 = 0.0;
      goto LAB_00401674;
    }
    fVar1 = *pfVar5;
    param_1 = (float *)((int)local_10 * 4);
    *pfVar5 = fVar1 / local_14;
    *(float *)((int)afStack_5c + iVar2) = fVar1 / local_14;
    iVar3 = iVar2;
    for (iVar4 = 4; iVar4 < (int)param_1; iVar4 = iVar4 + 4) {
      *(float *)((int)afStack_5c + iVar4) =
           *(float *)(unaff_EBX + iVar2) * *(float *)((int)afStack_8c + iVar3) +
           *(float *)((int)afStack_8c + iVar4 + 4);
      iVar3 = iVar3 + -4;
    }
    fVar1 = *(float *)(unaff_EBX + iVar2);
    iVar2 = iVar2 + 4;
    local_1c = local_1c + 1;
    local_18 = local_18 + 1;
    local_10 = (float *)((int)local_10 + 1);
    local_14 = (1.0 - fVar1 * fVar1) * local_14;
  } while( true );
}


