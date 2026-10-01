// 004318c8 FUN_004318c8 [Global]
// program: sfmain.exe

void FUN_004318c8(void)

{
  undefined4 *in_EAX;
  
  if (in_EAX[1] != 0) {
    CloseHandle((HANDLE)*in_EAX);
  }
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  return;
}


