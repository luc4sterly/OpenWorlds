// 100619b0 __initptd [Global]
// programa: rwdlmd21.dll

/* Library Function - Single Match
    __initptd
   
   Library: Visual Studio 1998 Release */

void __cdecl __initptd(_ptiddata _Ptd,pthreadlocinfo _Locale)

{
  *(undefined **)(_Ptd->_con_ch_buf + 4) = &DAT_10087e90;
  _Ptd->_holdrand = 1;
  return;
}


