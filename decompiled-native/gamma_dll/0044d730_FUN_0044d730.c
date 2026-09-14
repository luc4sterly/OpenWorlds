// 0044d730 FUN_0044d730 [Global]
// programa: gamma.dll

int __cdecl FUN_0044d730(byte *param_1,byte *param_2)

{
  byte bVar1;
  
  do {
    bVar1 = *param_1;
    if (bVar1 != *param_2) {
      return (uint)bVar1 - (uint)*param_2;
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (bVar1 != 0);
  return 0;
}


