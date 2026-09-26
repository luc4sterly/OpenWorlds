// 0040adb7 FUN_0040adb7 [Global]
// programa: sfmain.exe

void __fastcall
FUN_0040adb7(undefined4 param_1,float *param_2,float param_3,float *param_4,int param_5)

{
  float *pfVar1;
  float fVar2;
  int in_EAX;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  int extraout_ECX;
  float *pfVar6;
  int iVar7;
  float10 extraout_ST0;
  undefined8 uVar8;
  float afStack_48 [11];
  float *local_1c;
  float *local_18;
  
  iVar7 = param_5 * 4;
  pfVar3 = (float *)(in_EAX + iVar7);
  *param_4 = 1.0;
  do {
    fVar2 = *pfVar3;
    pfVar3 = pfVar3 + 0xb;
    *param_4 = (1.0 - fVar2 * fVar2) * *param_4;
  } while (pfVar3 != (float *)(iVar7 + 0x1b8 + in_EAX));
  afStack_48[0] = 5.939883e-39;
  local_18 = param_2;
  uVar8 = FUN_0042b7a8(in_EAX,param_4);
  pfVar3 = (float *)(param_5 * 4 + 0x2c + extraout_ECX);
  *(float *)((ulonglong)uVar8 >> 0x20) = (float)(extraout_ST0 * (float10)param_3);
  *local_18 = *(float *)(extraout_ECX + iVar7);
  iVar7 = 1;
  local_1c = local_18 + 1;
  do {
    iVar4 = 0;
    pfVar6 = local_18 + iVar7;
    pfVar5 = local_18;
    while (iVar4 < iVar7) {
      pfVar1 = pfVar6 + -1;
      iVar4 = iVar4 + 1;
      pfVar6 = pfVar6 + -1;
      afStack_48[iVar4] = *pfVar5 - *pfVar3 * *pfVar1;
      pfVar5 = pfVar5 + 1;
    }
    pfVar5 = local_18;
    for (iVar4 = 0; iVar4 < iVar7; iVar4 = iVar4 + 1) {
      *pfVar5 = afStack_48[iVar4 + 1];
      pfVar5 = pfVar5 + 1;
    }
    fVar2 = *pfVar3;
    iVar7 = iVar7 + 1;
    pfVar3 = pfVar3 + 0xb;
    *local_1c = fVar2;
    local_1c = local_1c + 1;
  } while (iVar7 < 10);
  return;
}


