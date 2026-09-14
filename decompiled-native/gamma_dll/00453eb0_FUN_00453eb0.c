// 00453eb0 FUN_00453eb0 [Global]
// programa: gamma.dll

void FUN_00453eb0(void)

{
  LPVOID pvVar1;
  
  pvVar1 = FUN_00453ed0();
  if (pvVar1 == (LPVOID)0x0) {
    return;
  }
  TlsSetValue(DAT_00482370,(LPVOID)0x0);
  return;
}


