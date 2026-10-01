// 10045c70 __amsg_exit [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Release */

void __cdecl __amsg_exit(int param_1)

{
  if ((DAT_1005bb70 == 1) || ((DAT_1005bb70 == 0 && (DAT_1005bb74 == 1)))) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_1005bb6c)(0xff);
  return;
}


