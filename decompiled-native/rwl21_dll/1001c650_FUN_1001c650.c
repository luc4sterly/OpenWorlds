// 1001c650 FUN_1001c650 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_1001c650(float *param_1,float *param_2)

{
  float fVar1;
  undefined8 uVar2;
  
  if (*(char *)(param_1 + 0x10) != '\0') {
    uVar2 = FUN_100510e0(param_1,param_2,param_1,param_2);
    return (float *)uVar2;
  }
  *param_2 = param_1[5] * param_1[10] - param_1[9] * param_1[6];
  param_2[1] = param_1[9] * param_1[2] - param_1[1] * param_1[10];
  param_2[2] = param_1[1] * param_1[6] - param_1[5] * param_1[2];
  param_2[3] = 0.0;
  param_2[4] = param_1[6] * param_1[8] - param_1[10] * param_1[4];
  param_2[5] = *param_1 * param_1[10] - param_1[2] * param_1[8];
  param_2[6] = param_1[2] * param_1[4] - *param_1 * param_1[6];
  param_2[7] = 0.0;
  param_2[8] = param_1[9] * param_1[4] - param_1[5] * param_1[8];
  param_2[9] = param_1[1] * param_1[8] - *param_1 * param_1[9];
  param_2[10] = *param_1 * param_1[5] - param_1[1] * param_1[4];
  param_2[0xb] = 0.0;
  fVar1 = param_1[2] * param_2[8] + param_1[1] * param_2[4] + *param_2 * *param_1;
  if (fVar1 != _DAT_10052180) {
    if ((int)fVar1 < 1) {
      fVar1 = -fVar1;
    }
    fVar1 = _DAT_10052184 / fVar1;
    *param_2 = *param_2 * fVar1;
    param_2[1] = param_2[1] * fVar1;
    param_2[2] = param_2[2] * fVar1;
    param_2[4] = param_2[4] * fVar1;
    param_2[5] = param_2[5] * fVar1;
    param_2[6] = param_2[6] * fVar1;
    param_2[8] = param_2[8] * fVar1;
    param_2[9] = param_2[9] * fVar1;
    param_2[10] = param_2[10] * fVar1;
  }
  param_2[0xc] = -(param_1[0xe] * param_2[8] + param_2[4] * param_1[0xd] + *param_2 * param_1[0xc]);
  param_2[0xd] = -(param_2[9] * param_1[0xe] + param_2[5] * param_1[0xd] + param_2[1] * param_1[0xc]
                  );
  param_2[0xe] = -(param_1[0xe] * param_2[10] +
                  param_2[6] * param_1[0xd] + param_2[2] * param_1[0xc]);
  param_2[0xf] = 1.0;
  *(undefined1 *)((int)param_2 + 0x41) = 1;
  *(undefined1 *)(param_2 + 0x10) = 0;
  return param_2;
}


