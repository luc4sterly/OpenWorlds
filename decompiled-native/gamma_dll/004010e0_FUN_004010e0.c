// 004010e0 FUN_004010e0 [Global]
// program: gamma.dll

void __cdecl FUN_004010e0(LPCSTR param_1)

{
  CHAR local_108 [260];
  
  FUN_0044d650((int)local_108,&DAT_0046d154);
  WritePrivateProfileStringA(s_Gamma_0046d14c,param_1,local_108,s___worlds_ini_0046d048);
  return;
}


