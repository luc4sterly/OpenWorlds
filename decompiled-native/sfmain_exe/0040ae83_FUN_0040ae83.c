// 0040ae83 FUN_0040ae83 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040ae83(undefined4 param_1,int param_2)

{
  float fVar1;
  double dVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  int unaff_EBX;
  int iVar8;
  int local_34;
  int local_30;
  int local_18;
  
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  iVar4 = unaff_EBX;
  do {
    iVar8 = in_EAX;
    for (iVar5 = 0; iVar5 < local_18 << 2; iVar5 = iVar5 + 4) {
      _DAT_004452c4 = *(float *)(iVar5 + local_34 + in_EAX) * *(float *)(iVar5 + iVar8);
      pfVar7 = (float *)(local_18 * 0x28 + iVar5 + in_EAX);
      pfVar6 = (float *)(local_18 * 0x28 + local_30 + in_EAX);
      for (iVar3 = local_18; iVar3 < 10; iVar3 = iVar3 + 1) {
        fVar1 = *pfVar7;
        pfVar7 = pfVar7 + 10;
        *pfVar6 = *pfVar6 - fVar1 * _DAT_004452c4;
        pfVar6 = pfVar6 + 10;
      }
      iVar8 = iVar8 + 0x28;
    }
    if (ABS(*(float *)(local_34 + in_EAX + local_30)) < _DAT_004386e4) break;
    *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(param_2 + local_30);
    iVar5 = 0;
    iVar8 = unaff_EBX;
    while( true ) {
      iVar3 = unaff_EBX + local_18 * 0xc;
      if (local_18 * 4 <= iVar5) break;
      pfVar6 = (float *)(iVar8 + 8);
      pfVar7 = (float *)(local_34 + in_EAX + iVar5);
      iVar8 = iVar8 + 0xc;
      iVar5 = iVar5 + 4;
      *(float *)(iVar3 + 8) = *(float *)(iVar3 + 8) - *pfVar6 * *pfVar7;
    }
    pfVar6 = (float *)(local_34 + in_EAX + local_30);
    *pfVar6 = 1.0 / *pfVar6;
    fVar1 = *(float *)(iVar3 + 8) * *pfVar6;
    *(float *)(iVar3 + 8) = fVar1;
    dVar2 = (double)fVar1;
    if ((float)_DAT_00435890 <= fVar1) {
      dVar2 = 0.999;
    }
    if (dVar2 <= _DAT_00435898) {
      fVar1 = -0.999;
    }
    else {
      fVar1 = *(float *)(iVar4 + 8);
      if ((float)_DAT_00435890 <= fVar1) {
        fVar1 = 0.999;
      }
    }
    *(float *)(iVar4 + 8) = fVar1;
    local_34 = local_34 + 0x28;
    local_30 = local_30 + 4;
    local_18 = local_18 + 1;
    iVar4 = iVar4 + 0xc;
  } while (local_18 < 10);
  if (ABS(*(float *)(in_EAX + local_18 * 0x2c)) < _DAT_004386e4) {
    iVar4 = local_18 * 0xc + unaff_EBX;
    for (; local_18 < 10; local_18 = local_18 + 1) {
      *(undefined4 *)(iVar4 + 8) = 0;
      iVar4 = iVar4 + 0xc;
    }
  }
  return;
}


