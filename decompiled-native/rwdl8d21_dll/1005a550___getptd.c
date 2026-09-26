// 1005a550 __getptd [Global]
// programa: RWDL8D21.DLL

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
  _Ptd = TlsGetValue(DAT_100756d4);
  if (_Ptd == (_ptiddata)0x0) {
    _Ptd = _calloc(1,0x74);
    if (_Ptd != (_ptiddata)0x0) {
      BVar1 = TlsSetValue(DAT_100756d4,_Ptd);
      if (BVar1 != 0) {
        __initptd(_Ptd,unaff_EDI);
        DVar2 = GetCurrentThreadId();
        _Ptd->_tid = DVar2;
        _Ptd->_thandle = 0xffffffff;
        goto LAB_1005a5b3;
      }
    }
    __amsg_exit(0x10);
  }
LAB_1005a5b3:
  SetLastError(dwErrCode);
  return _Ptd;
}


