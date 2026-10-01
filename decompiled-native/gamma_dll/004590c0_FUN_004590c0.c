// 004590c0 FUN_004590c0 [Global]
// program: gamma.dll

void __cdecl FUN_004590c0(int param_1)

{
  int *hMem;
  
  hMem = (int *)(param_1 + -4);
  if (*hMem == 0) {
    hMem = (int *)(param_1 + -8);
  }
  GlobalFree(hMem);
  return;
}


