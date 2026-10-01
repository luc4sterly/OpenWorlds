// 10060dd0 __mtinit [Global]
// program: RWDL6D21.DLL

/* Library Function - Single Match
    __mtinit
   
   Library: Visual Studio 1998 Release */

int __cdecl __mtinit(void)

{
  _ptiddata _Ptd;
  BOOL BVar1;
  DWORD DVar2;
  pthreadlocinfo unaff_ESI;
  
  __mtinitlocks();
  DAT_100796d4 = TlsAlloc();
  if (DAT_100796d4 == 0xffffffff) {
    return 0;
  }
  _Ptd = _calloc(1,0x74);
  if (_Ptd != (_ptiddata)0x0) {
    BVar1 = TlsSetValue(DAT_100796d4,_Ptd);
    if (BVar1 != 0) {
      __initptd(_Ptd,unaff_ESI);
      DVar2 = GetCurrentThreadId();
      _Ptd->_tid = DVar2;
      _Ptd->_thandle = 0xffffffff;
      return 1;
    }
  }
  return 0;
}


