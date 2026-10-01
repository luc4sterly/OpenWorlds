// 004317e0 FUN_004317e0 [Global]
// program: gamma.dll

void __cdecl FUN_004317e0(int param_1,int param_2)

{
  undefined4 uVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  
  if (param_1 == 0) {
    *(undefined4 *)(param_2 + 4) = 0;
    *(undefined4 *)(param_2 + 8) = 0;
    *(undefined4 *)(param_2 + 0xc) = 0;
    return;
  }
  uVar1 = FUN_00419950();
  FUN_00419420(param_1,uVar1);
  fVar2 = FUN_00419700(uVar1,3,0);
  fVar3 = FUN_00419700(uVar1,3,1);
  fVar4 = FUN_00419700(uVar1,3,2);
  FUN_004198f0();
  *(float *)(param_2 + 4) = (float)fVar2;
  *(float *)(param_2 + 8) = (float)fVar3;
  *(float *)(param_2 + 0xc) = (float)fVar4;
  return;
}


