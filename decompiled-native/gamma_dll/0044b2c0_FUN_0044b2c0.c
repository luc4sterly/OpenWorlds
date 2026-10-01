// 0044b2c0 FUN_0044b2c0 [Global]
// program: gamma.dll

short * FUN_0044b2c0(short *param_1,short *param_2,int param_3)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  
  psVar2 = param_1;
  if (param_3 != 0) {
    do {
      param_3 = param_3 + -1;
      psVar3 = psVar2;
      if (param_3 == 0) break;
      sVar1 = *param_2;
      param_2 = param_2 + 1;
      *psVar2 = sVar1;
      psVar3 = psVar2 + 1;
      sVar1 = *psVar2;
      psVar2 = psVar3;
    } while (sVar1 != 0);
    if (param_3 == 0) {
      *psVar3 = 0;
    }
  }
  return param_1;
}


