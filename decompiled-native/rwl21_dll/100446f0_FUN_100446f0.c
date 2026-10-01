// 100446f0 FUN_100446f0 [Global]
// program: RWL21.DLL

FARPROC FUN_100446f0(undefined4 *param_1,LPCSTR param_2)

{
  FARPROC pFVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    pFVar1 = GetProcAddress((HMODULE)*param_1,param_2);
    return pFVar1;
  }
  return (FARPROC)0x0;
}


