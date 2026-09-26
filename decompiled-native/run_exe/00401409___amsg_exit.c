// 00401409 __amsg_exit [Global]
// programa: run.exe

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_0040ba34 == 1) {
    FUN_004034d8();
  }
  FUN_00403511((undefined *)param_1);
  (*(code *)PTR___exit_004091a4)(0xff);
  return;
}


