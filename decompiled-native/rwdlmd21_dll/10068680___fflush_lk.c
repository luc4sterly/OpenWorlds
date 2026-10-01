// 10068680 __fflush_lk [Global]
// program: rwdlmd21.dll

/* Library Function - Single Match
    __fflush_lk
   
   Library: Visual Studio 1998 Release */

int __cdecl __fflush_lk(FILE *param_1)

{
  int iVar1;
  
  iVar1 = __flush(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((param_1->_flag & 0x4000) != 0) {
    iVar1 = __commit(param_1->_file);
    return (iVar1 == 0) - 1;
  }
  return 0;
}


