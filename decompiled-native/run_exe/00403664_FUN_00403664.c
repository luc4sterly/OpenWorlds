// 00403664 FUN_00403664 [Global]
// programa: run.exe

void __cdecl FUN_00403664(short *param_1,short *param_2)

{
  short sVar1;
  
  sVar1 = *param_2;
  *param_1 = sVar1;
  while( true ) {
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    if (sVar1 == 0) break;
    sVar1 = *param_2;
    *param_1 = sVar1;
  }
  return;
}


