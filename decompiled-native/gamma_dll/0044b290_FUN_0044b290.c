// 0044b290 FUN_0044b290 [Global]
// program: gamma.dll

short * FUN_0044b290(short *param_1,short *param_2)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = param_1;
  do {
    sVar1 = *param_2;
    param_2 = param_2 + 1;
    *psVar2 = sVar1;
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  return param_1;
}


