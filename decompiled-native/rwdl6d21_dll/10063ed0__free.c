// 10063ed0 _free [Global]
// program: RWDL6D21.DLL

/* Library Function - Single Match
    _free
   
   Library: Visual Studio 1998 Release */

void __cdecl _free(void *_Memory)

{
  char *pcVar1;
  uint local_8;
  int local_4;
  
  if (_Memory != (void *)0x0) {
    __lock(9);
    pcVar1 = (char *)___sbh_find_block(_Memory,&local_4,&local_8);
    if (pcVar1 != (char *)0x0) {
      ___sbh_free_block(local_4,local_8,pcVar1);
      FUN_10063d20(9);
      return;
    }
    FUN_10063d20(9);
    HeapFree(DAT_1007d414,0,_Memory);
  }
  return;
}


