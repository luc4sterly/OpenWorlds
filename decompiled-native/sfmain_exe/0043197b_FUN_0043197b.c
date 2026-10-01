// 0043197b FUN_0043197b [Global]
// program: sfmain.exe

void FUN_0043197b(void)

{
  undefined4 *in_EAX;
  DWORD DVar1;
  HANDLE pvVar2;
  LPSECURITY_ATTRIBUTES lpMutexAttributes;
  
  DVar1 = GetCurrentThreadId();
  if (DVar1 != in_EAX[2]) {
    if (in_EAX[1] == 0) {
      FUN_0043197b();
      if (in_EAX[1] == 0) {
        pvVar2 = CreateMutexA(lpMutexAttributes,(BOOL)lpMutexAttributes,(LPCSTR)lpMutexAttributes);
        in_EAX[1] = 1;
        *in_EAX = pvVar2;
      }
      FUN_004319dd();
    }
    WaitForSingleObject((HANDLE)*in_EAX,0xffffffff);
    in_EAX[2] = DVar1;
  }
  in_EAX[3] = in_EAX[3] + 1;
  return;
}


