// 004050a6 FUN_004050a6 [Global]
// programa: gdkup.exe

void FUN_004050a6(void)

{
  undefined4 *in_EAX;
  DWORD DVar1;
  HANDLE pvVar2;
  LPSECURITY_ATTRIBUTES lpMutexAttributes;
  
  DVar1 = GetCurrentThreadId();
  if (DVar1 != in_EAX[2]) {
    if (in_EAX[1] == 0) {
      FUN_004050a6();
      if (in_EAX[1] == 0) {
        pvVar2 = CreateMutexA(lpMutexAttributes,(BOOL)lpMutexAttributes,(LPCSTR)lpMutexAttributes);
        in_EAX[1] = 1;
        *in_EAX = pvVar2;
      }
      FUN_00405108();
    }
    WaitForSingleObject((HANDLE)*in_EAX,0xffffffff);
    in_EAX[2] = DVar1;
  }
  in_EAX[3] = in_EAX[3] + 1;
  return;
}


