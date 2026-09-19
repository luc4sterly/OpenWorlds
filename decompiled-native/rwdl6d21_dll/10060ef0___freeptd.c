// 10060ef0 __freeptd [Global]
// programa: RWDL6D21.DLL

/* Library Function - Single Match
    __freeptd
   
   Library: Visual Studio 1998 Release */

void __cdecl __freeptd(_ptiddata _Ptd)

{
  if (DAT_100796d4 != 0xffffffff) {
    if ((_Ptd != (_ptiddata)0x0) || (_Ptd = TlsGetValue(DAT_100796d4), _Ptd != (_ptiddata)0x0)) {
      if (_Ptd->_errmsg != (char *)0x0) {
        _free(_Ptd->_errmsg);
      }
      if (_Ptd->_werrmsg != (wchar_t *)0x0) {
        _free(_Ptd->_werrmsg);
      }
      if (_Ptd->_wnamebuf0 != (wchar_t *)0x0) {
        _free(_Ptd->_wnamebuf0);
      }
      if (_Ptd->_wnamebuf1 != (wchar_t *)0x0) {
        _free(_Ptd->_wnamebuf1);
      }
      if (_Ptd->_wasctimebuf != (wchar_t *)0x0) {
        _free(_Ptd->_wasctimebuf);
      }
      if (_Ptd->_gmtimebuf != (void *)0x0) {
        _free(_Ptd->_gmtimebuf);
      }
      _free(_Ptd);
    }
    TlsSetValue(DAT_100796d4,(LPVOID)0x0);
    return;
  }
  return;
}


