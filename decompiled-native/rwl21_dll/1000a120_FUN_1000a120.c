// 1000a120 FUN_1000a120 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_1000a120(int param_1,int param_2,int param_3,float *param_4,float *param_5)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float local_1c;
  float local_18 [3];
  float local_c [3];
  
  pfVar4 = (float *)(param_1 + 4);
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    pfVar1 = (float *)FUN_1001d000(pfVar4,local_c);
    *pfVar1 = -*pfVar1;
    pfVar1[1] = -pfVar1[1];
    pfVar1[2] = -pfVar1[2];
  }
  pfVar1 = param_4;
  pfVar5 = param_4;
  pfVar2 = (float *)RwScaleVector((float *)(param_1 + 0x14),*(float *)(param_1 + 0x4c),local_18);
  pfVar3 = (float *)RwScaleVector(pfVar4,-*(float *)(param_1 + 0x48),param_4);
  pfVar1 = (float *)RwAddVector(pfVar3,pfVar2,pfVar1);
  RwAddVector((float *)(param_1 + 0x34),pfVar1,pfVar5);
  pfVar1 = param_4;
  pfVar5 = param_5;
  pfVar2 = (float *)RwAddVector((float *)(param_1 + 0x34),(float *)(param_1 + 0x24),param_5);
  RwSubtractVector(pfVar2,pfVar1,pfVar5);
  local_1c = (float)*(int *)(param_1 + 0x60) * *(float *)(param_1 + 0x94);
  if (_DAT_1005209c < local_1c) {
    local_1c = (float)(*(int *)(param_1 + 0x60) + param_3 * -2 + -1) / local_1c;
  }
  RwScaleVector((float *)(param_1 + 0x14),local_1c,local_18);
  local_1c = (float)*(int *)(param_1 + 0x5c) * *(float *)(param_1 + 0x90);
  if (_DAT_1005209c < local_1c) {
    local_1c = (float)((param_2 * 2 - *(int *)(param_1 + 0x5c)) + 1) / local_1c;
  }
  pfVar1 = local_18;
  pfVar4 = (float *)RwScaleVector(pfVar4,-local_1c,local_c);
  RwAddVector(local_18,pfVar4,pfVar1);
  pfVar4 = param_5;
  if ((*(int *)(param_1 + 0x218) != 1) && (pfVar4 = param_4, *(int *)(param_1 + 0x218) != 2)) {
    FUN_1000cba0(0x67);
    return (float *)0x0;
  }
  RwAddVector(pfVar4,local_18,pfVar4);
  return param_5;
}


