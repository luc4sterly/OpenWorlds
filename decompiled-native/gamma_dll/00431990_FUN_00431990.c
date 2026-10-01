// 00431990 FUN_00431990 [Global]
// program: gamma.dll

void __cdecl FUN_00431990(int param_1,int param_2)

{
  undefined4 uVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  
  if (param_1 == 0) {
    return;
  }
  uVar1 = FUN_00419950();
  FUN_00419420(param_1,uVar1);
  fVar2 = FUN_00419700(uVar1,0,0);
  fVar3 = FUN_00419700(uVar1,1,1);
  fVar4 = FUN_00419700(uVar1,2,2);
  FUN_00419f50(uVar1,3,0,(float)fVar2 * *(float *)(param_2 + 4));
  FUN_00419f50(uVar1,3,1,(float)fVar3 * *(float *)(param_2 + 8));
  FUN_00419f50(uVar1,3,2,(float)fVar4 * *(float *)(param_2 + 0xc));
  FUN_00418bc0(param_1,uVar1);
  FUN_004198f0();
  return;
}


