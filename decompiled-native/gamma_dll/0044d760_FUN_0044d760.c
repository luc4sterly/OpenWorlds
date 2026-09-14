// 0044d760 FUN_0044d760 [Global]
// programa: gamma.dll

int __cdecl FUN_0044d760(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    bVar1 = *param_1;
    if ((bVar1 != *param_2) || (bVar1 == 0)) break;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    param_3 = param_3 + -1;
  }
  return (uint)bVar1 - (uint)*param_2;
}


