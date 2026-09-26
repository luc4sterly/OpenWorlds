// 100619d0 __getptd [Global]
// programa: rwdlmd21.dll

/* Library Function - Single Match
    __getptd
   
   Library: Visual Studio 1998 Release */

_ptiddata __cdecl __getptd(void)

{
  DWORD dwErrCode;
  _ptiddata _Ptd;
  BOOL BVar1;
  DWORD DVar2;
  pthreadlocinfo unaff_EDI;
  
  dwErrCode = GetLastError();
  _Ptd = TlsGetValue(DAT_10087704);
  if (_Ptd == (_ptiddata)0x0) {
    _Ptd = _calloc(1,0x74);
    if (_Ptd != (_ptiddata)0x0) {
      BVar1 = TlsSetValue(DAT_10087704,_Ptd);
      if (BVar1 != 0) {
        __initptd(_Ptd,unaff_EDI);
        DVar2 = GetCurrentThreadId();
        _Ptd->_tid = DVar2;
        _Ptd->_thandle = 0xffffffff;
        goto LAB_10061a33;
      }
    }
    __amsg_exit(0x10);
  }
LAB_10061a33:
  SetLastError(dwErrCode);
  return _Ptd;
}


