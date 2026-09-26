// 100598b0 __amsg_exit [Global]
// programa: RWDL8D21.DLL

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_10075580 == 1) || ((DAT_10075580 == 0 && (DAT_10075584 == 1)))) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_1007557c)(0xff);
  return;
}


