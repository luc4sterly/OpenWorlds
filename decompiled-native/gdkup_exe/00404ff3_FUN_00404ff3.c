// 00404ff3 FUN_00404ff3 [Global]
// program: gdkup.exe

void FUN_00404ff3(void)

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


