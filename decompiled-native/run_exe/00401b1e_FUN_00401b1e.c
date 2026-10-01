// 00401b1e FUN_00401b1e [Global]
// program: run.exe

void __cdecl FUN_00401b1e(uint *param_1)

{
  int *piVar1;
  uint dwBytes;
  
  if (DAT_0040ce64 == 3) {
    if ((param_1 <= DAT_0040ce5c) && (piVar1 = FUN_00403f65(param_1), piVar1 != (int *)0x0)) {
      return;
    }
  }
  else if (DAT_0040ce64 == 2) {
    if (param_1 == (uint *)0x0) {
      dwBytes = 0x10;
    }
    else {
      dwBytes = (int)param_1 + 0xfU & 0xfffffff0;
    }
    if ((dwBytes <= DAT_0040b314) && (piVar1 = FUN_00404a08(dwBytes >> 4), piVar1 != (int *)0x0)) {
      return;
    }
    goto LAB_00401b81;
  }
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)0x1;
  }
  dwBytes = (int)param_1 + 0xfU & 0xfffffff0;
LAB_00401b81:
  HeapAlloc(DAT_0040ce60,0,dwBytes);
  return;
}


