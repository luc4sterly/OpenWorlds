// 100625d0 __FF_MSGBANNER [Global]
// programa: rwdlmd21.dll

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Release */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_100875b0 == 1) || ((DAT_100875b0 == 0 && (DAT_100875b4 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_100879e8 != (code *)0x0) {
      (*DAT_100879e8)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


