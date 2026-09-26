// 0040acc0 FUN_0040acc0 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040acc0(undefined4 param_1,int param_2)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  float *pfVar5;
  int iVar6;
  int unaff_EBX;
  int iVar7;
  float *pfVar8;
  float local_28 [4];
  float local_18;
  float local_14;
  
  iVar7 = 0;
  do {
    iVar6 = iVar7 + 0x88;
    *(undefined4 *)((int)local_28 + iVar7) = 0;
    pfVar8 = (float *)(iVar6 * 4 + in_EAX);
    pfVar5 = pfVar8 + -iVar7;
    for (; iVar6 < 0x139; iVar6 = iVar6 + 2) {
      fVar4 = *pfVar8;
      fVar3 = *pfVar5;
      pfVar8 = pfVar8 + 2;
      pfVar5 = pfVar5 + 2;
      *(float *)((int)local_28 + iVar7) = fVar4 * fVar3 + *(float *)((int)local_28 + iVar7);
    }
    iVar7 = iVar7 + 4;
  } while (iVar7 != 0xc);
  *(undefined4 *)(unaff_EBX + 4) = 0;
  local_14 = 0.0;
  *(undefined4 *)(unaff_EBX + 8) = 0;
  local_18 = 0.0;
  if ((float)_DAT_00435888 < local_28[0]) {
    *(float *)(unaff_EBX + 4) = local_28[1] / local_28[0];
    fVar4 = (local_28[1] / local_28[0]) * local_28[1];
    *(float *)(unaff_EBX + 8) = (local_28[2] - fVar4) / (local_28[0] - fVar4);
    local_18 = *(float *)(unaff_EBX + 8);
    local_14 = *(float *)(unaff_EBX + 4) - *(float *)(unaff_EBX + 4) * *(float *)(unaff_EBX + 8);
  }
  pfVar8 = (float *)(param_2 + 0x214);
  pfVar5 = (float *)(in_EAX + 0x214);
  do {
    pfVar1 = pfVar5 + -4;
    fVar4 = *pfVar5;
    pfVar2 = pfVar5 + -8;
    pfVar5 = pfVar5 + 1;
    *pfVar8 = (fVar4 - local_14 * *pfVar1) - local_18 * *pfVar2;
    pfVar8 = pfVar8 + 1;
  } while (pfVar5 != (float *)(in_EAX + 0x4e4));
  return;
}


