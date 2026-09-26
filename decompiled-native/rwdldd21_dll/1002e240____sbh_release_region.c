// 1002e240 ___sbh_release_region [Global]
// programa: RWDLDD21.DLL

/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Release */

void __cdecl ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_1003787c == param_1) {
    PTR_LOOP_1003787c = param_1[1];
  }
  if (param_1 != &PTR_LOOP_10037068) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_10043564,0,param_1);
    return;
  }
  DAT_10037878 = 0;
  return;
}


