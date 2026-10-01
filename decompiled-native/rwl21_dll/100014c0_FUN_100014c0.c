// 100014c0 FUN_100014c0 [Global]
// program: RWL21.DLL

float * FUN_100014c0(int param_1,float *param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  float *pfVar3;
  float10 extraout_ST0;
  float local_c [3];
  
  FUN_10001100(param_1,local_c,param_2);
  pfVar3 = (float *)(-(uint)(*(char *)(*(uint *)(param_1 + 0x34) + 0x40) == '\0') &
                    *(uint *)(param_1 + 0x34));
  uVar1 = extraout_ECX;
  uVar2 = extraout_EDX;
  if (pfVar3 != (float *)0x0) {
    FUN_1001e660(param_2,param_2,pfVar3);
    RwTransformPoint(local_c,pfVar3);
    uVar1 = extraout_ECX_00;
    uVar2 = extraout_EDX_00;
  }
  RwDotProduct(uVar1,uVar2);
  param_2[3] = (float)-extraout_ST0;
  return param_2;
}


