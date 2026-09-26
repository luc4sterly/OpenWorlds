// 1005b150 __FF_MSGBANNER [Global]
// programa: RWDL8D21.DLL

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_10075580 == 1) || ((DAT_10075580 == 0 && (DAT_10075584 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_100759b8 != (code *)0x0) {
      (*DAT_100759b8)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


