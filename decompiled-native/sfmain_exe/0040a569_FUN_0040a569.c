// 0040a569 FUN_0040a569 [Global]
// programa: sfmain.exe

void __fastcall FUN_0040a569(int param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int in_EAX;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  float *unaff_EBX;
  float *pfVar9;
  float *pfVar10;
  int iVar11;
  float *local_24;
  float *local_20;
  float *local_1c;
  float *local_18;
  int local_10;
  
  iVar11 = 1;
  pfVar4 = unaff_EBX;
  do {
    *pfVar4 = 0.0;
    pfVar9 = (float *)(iVar11 * -4 + param_2 + 0x2c);
    iVar7 = param_2 + 0x2c;
    for (iVar6 = 0xb; iVar6 <= in_EAX; iVar6 = iVar6 + 1) {
      pfVar8 = (float *)(iVar7 + -4);
      fVar3 = *pfVar9;
      iVar7 = iVar7 + 4;
      pfVar9 = pfVar9 + 1;
      *pfVar4 = *pfVar8 * fVar3 + *pfVar4;
    }
    iVar11 = iVar11 + 1;
    pfVar4 = pfVar4 + 10;
  } while (iVar11 < 0xb);
  *(undefined4 *)(param_1 + 0x28) = 0;
  pfVar4 = (float *)(param_2 + 0x2c);
  for (iVar11 = 0xb; iVar11 <= in_EAX; iVar11 = iVar11 + 1) {
    fVar3 = *pfVar4;
    pfVar9 = pfVar4 + -10;
    pfVar4 = pfVar4 + 1;
    *(float *)(param_1 + 0x28) = fVar3 * *pfVar9 + *(float *)(param_1 + 0x28);
  }
  local_10 = 2;
  pfVar9 = (float *)(param_2 + -8 + (in_EAX + 1) * 4);
  local_24 = pfVar9;
  local_20 = (float *)(param_2 + 0x24);
  local_1c = unaff_EBX;
  pfVar4 = unaff_EBX;
  do {
    local_18 = pfVar4 + 10;
    pfVar5 = local_1c + 2;
    pfVar4 = pfVar4 + 0xc;
    pfVar8 = (float *)(param_2 + 0x24);
    pfVar10 = pfVar9;
    for (iVar11 = 2; iVar11 <= local_10; iVar11 = iVar11 + 1) {
      fVar3 = *pfVar10;
      pfVar1 = pfVar5 + -2;
      fVar2 = *pfVar8;
      pfVar5 = pfVar5 + 1;
      pfVar10 = pfVar10 + -1;
      pfVar8 = pfVar8 + -1;
      pfVar4[-1] = *local_20 * fVar2 + (*pfVar1 - *local_24 * fVar3);
      pfVar4 = pfVar4 + 1;
    }
    local_10 = local_10 + 1;
    local_20 = local_20 + -1;
    local_1c = local_1c + 10;
    local_24 = local_24 + -1;
    pfVar4 = local_18;
  } while (local_10 < 0xb);
  pfVar4 = (float *)(param_2 + -4 + in_EAX * 4);
  pfVar8 = (float *)(param_2 + 0x24);
  pfVar9 = (float *)(param_1 + 4);
  do {
    unaff_EBX = unaff_EBX + 10;
    fVar3 = *pfVar8;
    pfVar8 = pfVar8 + -1;
    *pfVar9 = *(float *)(in_EAX * 4 + param_2) * *pfVar4 +
              (*unaff_EBX - *(float *)(param_2 + 0x28) * fVar3);
    pfVar9 = pfVar9 + 1;
    pfVar4 = pfVar4 + -1;
  } while (pfVar9 != (float *)(param_1 + 0x28));
  return;
}


