// 10060e60 __initptd [Global]
// program: RWDL6D21.DLL

/* Library Function - Single Match
    __initptd
   
   Library: Visual Studio 1998 Release */

void __cdecl __initptd(_ptiddata _Ptd,pthreadlocinfo _Locale)

{
  *(undefined **)(_Ptd->_con_ch_buf + 4) = &DAT_10079e60;
  _Ptd->_holdrand = 1;
  return;
}


