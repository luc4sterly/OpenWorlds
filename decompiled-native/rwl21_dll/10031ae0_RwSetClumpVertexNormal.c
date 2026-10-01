// 10031ae0 RwSetClumpVertexNormal [Global]
// program: RWL21.DLL

int RwSetClumpVertexNormal(int param_1,int param_2,float *param_3)

{
  int iVar1;
  float local_c;
  float local_8;
  float local_4;
  
                    /* 0x31ae0  392  RwSetClumpVertexNormal */
  if ((param_1 == 0) || (param_3 == (float *)0x0)) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((0 < param_2) && (param_2 < *(int *)(*(int *)(param_1 + 0x88) + 8) + -7)) {
    local_c = *param_3;
    local_8 = param_3[1];
    local_4 = param_3[2];
    RwNormalize(&local_c);
    if (((ABS(local_c) == 0.0) && (ABS(local_8) == 0.0)) && (ABS(local_4) == 0.0)) {
      FUN_1000cba0(0x20);
      return 0;
    }
    iVar1 = FUN_10041c90(*(int *)(param_1 + 0x88),param_2);
    *(float *)(iVar1 + 0x4c) = local_c;
    *(float *)(iVar1 + 0x50) = local_8;
    *(float *)(iVar1 + 0x54) = local_4;
    *(byte *)(iVar1 + 0x48) = *(byte *)(iVar1 + 0x48) | 0x40;
    *(undefined4 *)(param_1 + 0xc0) = 0;
    return param_1;
  }
  FUN_1000cba0(0x19);
  return 0;
}


