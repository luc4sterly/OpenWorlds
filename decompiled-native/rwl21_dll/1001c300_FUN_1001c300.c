// 1001c300 FUN_1001c300 [Global]
// program: RWL21.DLL

undefined8 FUN_1001c300(float *param_1,float *param_2,float *param_3)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0x10) != '\0') {
    uVar1 = FUN_100510e0(param_1,param_2,param_2,param_3);
    return uVar1;
  }
  if (*(char *)(param_2 + 0x10) != '\0') {
    uVar1 = FUN_100510e0(param_1,param_2,param_1,param_3);
    return uVar1;
  }
  *param_3 = param_1[2] * param_2[8] + param_1[1] * param_2[4] + *param_2 * *param_1;
  param_3[1] = param_2[9] * param_1[2] + param_2[1] * *param_1 + param_2[5] * param_1[1];
  param_3[2] = param_1[2] * param_2[10] + param_2[2] * *param_1 + param_1[1] * param_2[6];
  param_3[4] = param_1[6] * param_2[8] + param_1[5] * param_2[4] + *param_2 * param_1[4];
  param_3[5] = param_2[9] * param_1[6] + param_2[1] * param_1[4] + param_2[5] * param_1[5];
  param_3[6] = param_1[6] * param_2[10] + param_2[2] * param_1[4] + param_1[5] * param_2[6];
  param_3[8] = param_1[10] * param_2[8] + param_1[9] * param_2[4] + *param_2 * param_1[8];
  param_3[9] = param_2[9] * param_1[10] + param_2[1] * param_1[8] + param_1[9] * param_2[5];
  param_3[10] = param_1[10] * param_2[10] + param_2[2] * param_1[8] + param_1[9] * param_2[6];
  *(undefined1 *)((int)param_3 + 0x41) = 1;
  *(undefined1 *)(param_3 + 0x10) = 0;
  return CONCAT44(param_2,param_3);
}


