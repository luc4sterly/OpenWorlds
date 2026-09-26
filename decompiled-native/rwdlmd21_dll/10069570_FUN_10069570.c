// 10069570 FUN_10069570 [Global]
// programa: rwdlmd21.dll

void __cdecl FUN_10069570(char *param_1)

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


