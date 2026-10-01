// 1002d750 FUN_1002d750 [Global]
// program: RWL21.DLL

undefined8 __fastcall
FUN_1002d750(undefined4 param_1,undefined4 param_2,float *param_3,uint *param_4,float *param_5)

{
  float fVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  uint uVar2;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  undefined8 uVar3;
  float local_c;
  float local_8;
  float local_4;
  
  if (((param_4 == (uint *)0x0) || (param_4[0x11] == 0)) || ((*param_4 & 8) != 0)) {
    param_4 = (uint *)0x0;
  }
  if (param_4 == (uint *)0x0) {
    FUN_1000cba0(0x65);
    return CONCAT44(extraout_EDX,param_3);
  }
  if ((param_4[0x11] != 1) || (uVar2 = param_4[0x12], *(char *)(uVar2 + 0x40) != '\0')) {
    uVar2 = 0;
  }
  if (uVar2 == 0) {
    param_3[1] = 0.0;
    *param_3 = 0.0;
  }
  else {
    uVar3 = RwDotProduct(param_1,param_2);
    local_c = (float)extraout_ST0;
    uVar3 = RwDotProduct(extraout_ECX,(int)((ulonglong)uVar3 >> 0x20));
    local_8 = (float)extraout_ST0_00;
    uVar3 = RwDotProduct(extraout_ECX_00,(int)((ulonglong)uVar3 >> 0x20));
    local_4 = (float)extraout_ST0_01;
    uVar3 = RwDotProduct(extraout_ECX_01,(int)((ulonglong)uVar3 >> 0x20));
    param_2 = (undefined4)((ulonglong)uVar3 >> 0x20);
    param_5 = &local_c;
    *param_3 = (float)extraout_ST0_02;
    param_3[1] = (float)extraout_ST0_02;
  }
  if ((uint)*param_5 < 0x80000001) {
    *param_3 = (float)param_4[7] * *param_5 + *param_3;
    fVar1 = (float)param_4[8];
  }
  else {
    *param_3 = (float)param_4[8] * *param_5 + *param_3;
    fVar1 = (float)param_4[7];
  }
  param_3[1] = fVar1 * *param_5 + param_3[1];
  if ((uint)param_5[1] < 0x80000001) {
    *param_3 = (float)param_4[9] * param_5[1] + *param_3;
    fVar1 = (float)param_4[10];
  }
  else {
    *param_3 = (float)param_4[10] * param_5[1] + *param_3;
    fVar1 = (float)param_4[9];
  }
  param_3[1] = fVar1 * param_5[1] + param_3[1];
  if (0x80000000 < (uint)param_5[2]) {
    *param_3 = (float)param_4[0xc] * param_5[2] + *param_3;
    param_3[1] = (float)param_4[0xb] * param_5[2] + param_3[1];
    return CONCAT44(param_2,param_3);
  }
  *param_3 = (float)param_4[0xb] * param_5[2] + *param_3;
  param_3[1] = (float)param_4[0xc] * param_5[2] + param_3[1];
  return CONCAT44(param_2,param_3);
}


