// 00401931 FUN_00401931 [Global]
// program: run.exe

int __cdecl FUN_00401931(uchar *param_1,size_t param_2)

{
  uchar *_Str2;
  int iVar1;
  int *piVar2;
  
  _Str2 = (uchar *)*DAT_0040ba60;
  piVar2 = DAT_0040ba60;
  while( true ) {
    if (_Str2 == (uchar *)0x0) {
      return -((int)piVar2 - (int)DAT_0040ba60 >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,_Str2,param_2);
    if ((iVar1 == 0) &&
       ((*(char *)(*piVar2 + param_2) == '=' || (*(char *)(*piVar2 + param_2) == '\0')))) break;
    _Str2 = (uchar *)piVar2[1];
    piVar2 = piVar2 + 1;
  }
  return (int)piVar2 - (int)DAT_0040ba60 >> 2;
}


