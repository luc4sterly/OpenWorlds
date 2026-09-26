// 00401ced FUN_00401ced [Global]
// programa: gdkup.exe

void FUN_00401ced(void)

{
  int iVar1;
  
  iVar1 = FUN_00402920();
  if (iVar1 == -1) {
    MessageBoxA(DAT_0040b020,s_Error_creating_parent_wait_threa_004080ba,s_Error_004080b4,0);
    CloseHandle(DAT_0040b024);
    DestroyWindow(DAT_0040b020);
  }
  return;
}


