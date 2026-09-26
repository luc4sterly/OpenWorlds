// 004014d8 FUN_004014d8 [Global]
// programa: sfmain.exe

void __fastcall FUN_004014d8(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float *in_EAX;
  float *pfVar3;
  int iVar4;
  int unaff_EBX;
  float *pfVar5;
  int local_10;
  int local_c;
  
  local_10 = param_2;
  for (local_c = 0; local_c <= unaff_EBX; local_c = local_c + 1) {
    *param_1 = 0.0;
    pfVar5 = in_EAX + local_c;
    pfVar3 = in_EAX;
    for (iVar4 = 0; iVar4 < local_10; iVar4 = iVar4 + 1) {
      fVar1 = *pfVar3;
      fVar2 = *pfVar5;
      pfVar3 = pfVar3 + 1;
      pfVar5 = pfVar5 + 1;
      *param_1 = fVar1 * fVar2 + *param_1;
    }
    param_1 = param_1 + 1;
    local_10 = local_10 + -1;
  }
  return;
}


