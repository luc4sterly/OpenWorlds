// 1002b720 __FF_MSGBANNER [Global]
// programa: RWDLDD21.DLL

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_1003646c == 1) || ((DAT_1003646c == 0 && (DAT_10036470 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_100368b0 != (code *)0x0) {
      (*DAT_100368b0)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


