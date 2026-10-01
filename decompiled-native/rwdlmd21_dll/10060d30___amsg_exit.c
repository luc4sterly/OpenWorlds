// 10060d30 __amsg_exit [Global]
// program: rwdlmd21.dll

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_100875b0 == 1) || ((DAT_100875b0 == 0 && (DAT_100875b4 == 1)))) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_100875ac)(0xff);
  return;
}


