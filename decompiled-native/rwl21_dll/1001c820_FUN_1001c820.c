// 1001c820 FUN_1001c820 [Global]
// program: RWL21.DLL

void FUN_1001c820(float *param_1,float param_2,float param_3,float param_4,int param_5)

{
  float fVar1;
  
  if (param_5 == 1) {
    param_1[0xf] = 1.0;
    param_1[10] = 1.0;
    param_1[5] = 1.0;
    *param_1 = 1.0;
    param_1[0xe] = 0.0;
    param_1[0xd] = 0.0;
    param_1[0xc] = 0.0;
    param_1[0xb] = 0.0;
    param_1[9] = 0.0;
    param_1[8] = 0.0;
    param_1[7] = 0.0;
    param_1[6] = 0.0;
    param_1[4] = 0.0;
    param_1[3] = 0.0;
    param_1[2] = 0.0;
    param_1[1] = 0.0;
    *(undefined1 *)((int)param_1 + 0x41) = 1;
    *(undefined1 *)(param_1 + 0x10) = 1;
    param_1[0xc] = param_2;
    param_1[0xd] = param_3;
    param_1[0xe] = param_4;
  }
  else {
    if (param_5 == 2) {
      param_1[0xc] = param_1[8] * param_4 + *param_1 * param_2 + param_1[4] * param_3 + param_1[0xc]
      ;
      param_1[0xd] = param_1[9] * param_4 + param_1[1] * param_2 + param_1[5] * param_3 +
                     param_1[0xd];
      fVar1 = param_1[10] * param_4 + param_1[6] * param_3 + param_1[2] * param_2 + param_1[0xe];
    }
    else {
      if (param_5 != 3) {
        FUN_1000cba0(2);
        param_1 = (float *)0x0;
        goto LAB_1001c92f;
      }
      param_1[0xc] = param_1[0xc] + param_2;
      param_1[0xd] = param_1[0xd] + param_3;
      fVar1 = param_1[0xe] + param_4;
    }
    param_1[0xe] = fVar1;
  }
LAB_1001c92f:
  if (param_1 != (float *)0x0) {
    *(undefined1 *)((int)param_1 + 0x41) = 1;
    *(undefined1 *)(param_1 + 0x10) = 0;
  }
  return;
}


