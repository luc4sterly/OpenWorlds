// 00403689 FUN_00403689 [Global]
// programa: run.exe

int __cdecl FUN_00403689(short *param_1)

{
  short sVar1;
  short *psVar2;
  
  sVar1 = *param_1;
  psVar2 = param_1;
  while (psVar2 = psVar2 + 1, sVar1 != 0) {
    sVar1 = *psVar2;
  }
  return ((int)psVar2 - (int)param_1 >> 1) + -1;
}


