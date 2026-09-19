// 1004cf70 findenv [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    _findenv
   
   Library: Visual Studio 1998 Release */

int __cdecl findenv(uchar *param_1,size_t param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *DAT_1005beb8;
  piVar2 = DAT_1005beb8;
  while( true ) {
    if (iVar1 == 0) {
      return -((int)piVar2 - (int)DAT_1005beb8 >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,(uchar *)*piVar2,param_2);
    if ((iVar1 == 0) &&
       ((*(char *)(*piVar2 + param_2) == '=' || (*(char *)(*piVar2 + param_2) == '\0')))) break;
    piVar2 = piVar2 + 1;
    iVar1 = *piVar2;
  }
  return (int)piVar2 - (int)DAT_1005beb8 >> 2;
}


