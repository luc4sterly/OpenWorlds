// 100640b0 ___sbh_release_region [Global]
// program: RWDL6D21.DLL

/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_1007a6fc == param_1) {
    PTR_LOOP_1007a6fc = param_1[1];
  }
  if (param_1 != &PTR_LOOP_10079ee8) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_1007d414,0,param_1);
    return;
  }
  DAT_1007a6f8 = 0;
  return;
}


