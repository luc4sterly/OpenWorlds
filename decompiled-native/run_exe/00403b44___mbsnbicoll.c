// 00403b44 __mbsnbicoll [Global]
// programa: run.exe

/* Library Function - Single Match
    __mbsnbicoll
   
   Library: Visual Studio 2003 Release */

int __cdecl __mbsnbicoll(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  int iVar1;
  
  if (_MaxCount == 0) {
    return 0;
  }
  iVar1 = FUN_0040675f(DAT_0040be24,1,_Str1,_MaxCount,_Str2,_MaxCount,DAT_0040bbf4);
  if (iVar1 == 0) {
    return 0x7fffffff;
  }
  return iVar1 + -2;
}


