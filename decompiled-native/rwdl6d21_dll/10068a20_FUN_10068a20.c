// 10068a20 FUN_10068a20 [Global]
// program: RWDL6D21.DLL

void __cdecl FUN_10068a20(char *param_1)

{
  size_t sVar1;
  char *_Dest;
  
  sVar1 = _strlen(param_1);
  _Dest = _malloc(sVar1 + 1);
  if (_Dest != (char *)0x0) {
    FID_conflict___mbscpy(_Dest,param_1);
  }
  return;
}


