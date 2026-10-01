// 1004abf0 __FF_MSGBANNER [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_1005bb70 == 1) || ((DAT_1005bb70 == 0 && (DAT_1005bb74 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_1005c9e0 != (code *)0x0) {
      (*DAT_1005c9e0)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


