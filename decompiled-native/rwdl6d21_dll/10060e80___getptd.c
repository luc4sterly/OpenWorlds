// 10060e80 __getptd [Global]
// programa: RWDL6D21.DLL

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
  _Ptd = TlsGetValue(DAT_100796d4);
  if (_Ptd == (_ptiddata)0x0) {
    _Ptd = _calloc(1,0x74);
    if (_Ptd != (_ptiddata)0x0) {
      BVar1 = TlsSetValue(DAT_100796d4,_Ptd);
      if (BVar1 != 0) {
        __initptd(_Ptd,unaff_EDI);
        DVar2 = GetCurrentThreadId();
        _Ptd->_tid = DVar2;
        _Ptd->_thandle = 0xffffffff;
        goto LAB_10060ee3;
      }
    }
    __amsg_exit(0x10);
  }
LAB_10060ee3:
  SetLastError(dwErrCode);
  return _Ptd;
}


