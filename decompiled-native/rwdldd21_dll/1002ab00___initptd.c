// 1002ab00 __initptd [Global]
// program: RWDLDD21.DLL

/* Library Function - Single Match
    __initptd
   
   Library: Visual Studio 1998 Release */

void __cdecl __initptd(_ptiddata _Ptd,pthreadlocinfo _Locale)

{
  *(undefined **)(_Ptd->_con_ch_buf + 4) = &DAT_10036fe0;
  _Ptd->_holdrand = 1;
  return;
}


