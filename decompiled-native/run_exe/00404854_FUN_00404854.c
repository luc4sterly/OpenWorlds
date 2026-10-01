// 00404854 FUN_00404854 [Global]
// program: run.exe

void __cdecl FUN_00404854(undefined **param_1)

{
  VirtualFree(param_1[4],0,0x8000);
  if ((undefined **)PTR_LOOP_0040b310 == param_1) {
    PTR_LOOP_0040b310 = param_1[1];
  }
  if (param_1 != &PTR_LOOP_004092f0) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_0040ce60,0,param_1);
    return;
  }
  DAT_00409300 = 0xffffffff;
  return;
}


