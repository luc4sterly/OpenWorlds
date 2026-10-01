// 10064c00 ___sbh_release_region [Global]
// program: rwdlmd21.dll

/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_1008872c == param_1) {
    PTR_LOOP_1008872c = param_1[1];
  }
  if (param_1 != &PTR_LOOP_10087f18) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_1008b454,0,param_1);
    return;
  }
  DAT_10088728 = 0;
  return;
}


