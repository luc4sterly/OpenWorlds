// 10029e80 __amsg_exit [Global]
// programa: RWDLDD21.DLL

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_1003646c == 1) || ((DAT_1003646c == 0 && (DAT_10036470 == 1)))) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_10036468)(0xff);
  return;
}


