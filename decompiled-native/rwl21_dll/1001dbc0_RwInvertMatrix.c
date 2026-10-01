// 1001dbc0 RwInvertMatrix [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong __fastcall
RwInvertMatrix(undefined4 param_1,undefined4 param_2,float *param_3,float *param_4)

{
  float fVar1;
  uint extraout_EDX;
  longlong lVar2;
  
                    /* 0x1dbc0  284  RwInvertMatrix */
  if ((param_3 != (float *)0x0) && (param_4 != (float *)0x0)) {
    if (*(char *)(param_3 + 0x10) == '\0') {
      *param_4 = param_3[5] * param_3[10] - param_3[9] * param_3[6];
      param_4[4] = param_3[6] * param_3[8] - param_3[10] * param_3[4];
      param_4[8] = param_3[9] * param_3[4] - param_3[5] * param_3[8];
      param_4[1] = param_3[9] * param_3[2] - param_3[10] * param_3[1];
      param_4[5] = param_3[10] * *param_3 - param_3[2] * param_3[8];
      param_4[9] = param_3[8] * param_3[1] - param_3[9] * *param_3;
      param_4[2] = param_3[6] * param_3[1] - param_3[5] * param_3[2];
      param_4[6] = param_3[2] * param_3[4] - param_3[6] * *param_3;
      param_4[10] = param_3[5] * *param_3 - param_3[4] * param_3[1];
      param_4[3] = 0.0;
      param_4[7] = 0.0;
      param_4[0xb] = 0.0;
      fVar1 = param_3[2] * param_4[8] + *param_4 * *param_3 + param_4[4] * param_3[1];
      if (fVar1 != _DAT_10052180) {
        fVar1 = _DAT_10052184 / fVar1;
        *param_4 = *param_4 * fVar1;
        param_4[1] = param_4[1] * fVar1;
        param_4[2] = param_4[2] * fVar1;
        param_4[4] = param_4[4] * fVar1;
        param_4[5] = param_4[5] * fVar1;
        param_4[6] = param_4[6] * fVar1;
        param_4[8] = param_4[8] * fVar1;
        param_4[9] = param_4[9] * fVar1;
        param_4[10] = fVar1 * param_4[10];
      }
      param_4[0xc] = -(param_3[0xe] * param_4[8] +
                      param_3[0xc] * *param_4 + param_4[4] * param_3[0xd]);
      param_4[0xd] = -(param_4[9] * param_3[0xe] +
                      param_4[5] * param_3[0xd] + param_4[1] * param_3[0xc]);
      param_4[0xe] = -(param_3[0xe] * param_4[10] +
                      param_4[6] * param_3[0xd] + param_4[2] * param_3[0xc]);
      param_4[0xf] = 1.0;
      *(undefined1 *)((int)param_4 + 0x41) = 1;
      *(undefined1 *)(param_4 + 0x10) = 0;
      return CONCAT44(param_2,param_4);
    }
    lVar2 = FUN_100510e0(param_3,param_2,param_3,param_4);
    return lVar2;
  }
  FUN_1000cba0(1);
  return (ulonglong)extraout_EDX << 0x20;
}


