// 00407993 FUN_00407993 [Global]
// programa: run.exe

int __cdecl FUN_00407993(short *param_1,int param_2)

{
  short *psVar1;
  int iVar2;
  
  iVar2 = param_2;
  for (psVar1 = param_1; (iVar2 != 0 && (iVar2 = iVar2 + -1, *psVar1 != 0)); psVar1 = psVar1 + 1) {
  }
  if (*psVar1 != 0) {
    return param_2;
  }
  return (int)psVar1 - (int)param_1 >> 1;
}


