// 00401120 FUN_00401120 [Global]
// programa: gamma.dll

LPSTR __cdecl FUN_00401120(LPCSTR param_1,LPCSTR param_2,LPSTR param_3,DWORD param_4)

{
  GetPrivateProfileStringA(s_Gamma_0046d14c,param_1,param_2,param_3,param_4,s___worlds_ini_0046d048)
  ;
  return param_3;
}


