// 00401c56 FUN_00401c56 [Global]
// program: gdkup.exe

void FUN_00401c56(void)

{
  int iVar1;
  
  if ((DAT_0040b01c == 0) && (DAT_0040b02c != DAT_0040b028)) {
    iVar1 = FUN_00402920();
    if (iVar1 == -1) {
      MessageBoxA(DAT_0040b020,s_Error_creating_child_wait_thread_00408093,s_Error_0040808d,0);
      CloseHandle(DAT_0040b024);
      DestroyWindow(DAT_0040b020);
    }
  }
  else {
    CloseHandle(DAT_0040b024);
    DestroyWindow(DAT_0040b020);
  }
  return;
}


