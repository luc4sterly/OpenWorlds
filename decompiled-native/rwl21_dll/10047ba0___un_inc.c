// 10047ba0 __un_inc [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __un_inc
   
   Library: Visual Studio 1998 Release */

void __cdecl __un_inc(uint param_1,FILE *param_2)

{
  if (param_1 != 0xffffffff) {
    __ungetc_lk(param_1,param_2);
  }
  return;
}


