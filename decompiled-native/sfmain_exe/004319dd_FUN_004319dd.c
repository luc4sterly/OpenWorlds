// 004319dd FUN_004319dd [Global]
// programa: sfmain.exe

void FUN_004319dd(void)

{
  int iVar1;
  undefined4 *in_EAX;
  
  if (in_EAX[3] != 0) {
    iVar1 = in_EAX[3] + -1;
    in_EAX[3] = iVar1;
    if (iVar1 == 0) {
      in_EAX[2] = 0;
      ReleaseMutex((HANDLE)*in_EAX);
    }
  }
  return;
}


