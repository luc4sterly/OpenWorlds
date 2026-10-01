// 100494a0 __mbsnbicoll [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __mbsnbicoll
   
   Library: Visual Studio 1998 Release */

int __cdecl __mbsnbicoll(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  int iVar1;
  int unaff_retaddr;
  
  if (_MaxCount == 0) {
    return 0;
  }
  iVar1 = ___crtCompareStringA
                    (DAT_1005c838,(LPCWSTR)0x1,(DWORD)_Str1,(LPCSTR)_MaxCount,(int)_Str2,
                     (LPCSTR)_MaxCount,DAT_1005c834,unaff_retaddr);
  if (iVar1 == 0) {
    return 0x7fffffff;
  }
  return iVar1 + -2;
}


