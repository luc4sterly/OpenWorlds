// 00403bc9 FUN_00403bc9 [Global]
// program: run.exe

undefined4 __cdecl FUN_00403bc9(undefined4 param_1)

{
  DAT_0040ce58 = HeapAlloc(DAT_0040ce60,0,0x140);
  if (DAT_0040ce58 == (LPVOID)0x0) {
    return 0;
  }
  DAT_0040ce50 = 0;
  DAT_0040ce54 = 0;
  DAT_0040ce4c = DAT_0040ce58;
  DAT_0040ce5c = param_1;
  DAT_0040ce44 = 0x10;
  return 1;
}


