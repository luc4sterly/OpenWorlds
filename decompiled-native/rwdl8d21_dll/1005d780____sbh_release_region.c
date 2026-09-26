// 1005d780 ___sbh_release_region [Global]
// programa: RWDL8D21.DLL

/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_100766fc == param_1) {
    PTR_LOOP_100766fc = param_1[1];
  }
  if (param_1 != &PTR_LOOP_10075ee8) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_10079414,0,param_1);
    return;
  }
  DAT_100766f8 = 0;
  return;
}


