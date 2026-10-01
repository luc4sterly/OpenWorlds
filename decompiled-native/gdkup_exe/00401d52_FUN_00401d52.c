// 00401d52 FUN_00401d52 [Global]
// program: gdkup.exe

void __fastcall FUN_00401d52(undefined4 param_1)

{
  int iVar1;
  BOOL BVar2;
  CHAR local_270 [512];
  _STARTUPINFOA local_70;
  _PROCESS_INFORMATION local_2c;
  DWORD local_1c;
  
  local_1c = 8;
  FUN_00402980(param_1,0);
  iVar1 = DAT_0040b02c;
  local_70.cb = 0x44;
  if (DAT_0040b02c + 1 == DAT_0040b028) {
    local_1c = 0x10;
  }
  DAT_0040b02c = DAT_0040b02c + 1;
  BVar2 = CreateProcessA((LPCSTR)0x0,*(LPSTR *)(iVar1 * 4 + DAT_0040b030),(LPSECURITY_ATTRIBUTES)0x0
                         ,(LPSECURITY_ATTRIBUTES)0x0,0,local_1c,(LPVOID)0x0,(LPCSTR)0x0,&local_70,
                         &local_2c);
  if (BVar2 == 0) {
    wsprintfA(local_270,s_Internal_error___can_t_execute___004080dc,
              *(undefined4 *)(DAT_0040b02c * 4 + DAT_0040b030 + -4));
    MessageBoxA(DAT_0040b020,local_270,s_Error_004080fe,0);
    DestroyWindow(DAT_0040b020);
  }
  DAT_0040b024 = local_2c.hProcess;
  CloseHandle(local_2c.hThread);
  wsprintfA(local_270,&DAT_00408104,DAT_0040b028 - DAT_0040b02c);
  SetDlgItemTextA(DAT_0040b020,0x68,local_270);
  return;
}


