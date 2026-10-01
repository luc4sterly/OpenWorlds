// 0041f670 Java_NET_worlds_scape_ASFSoundPlayer_nativePlay [Global]
// program: gamma.dll

/* unsigned char __stdcall Java_NET_worlds_scape_ASFSoundPlayer_nativePlay(struct JNIEnv_ *,class
   _jclass *,class _jstring *) */

uchar Java_NET_worlds_scape_ASFSoundPlayer_nativePlay
                (JNIEnv_ *param_1,_jclass *param_2,_jstring *param_3)

{
  char *pcVar1;
  BOOL BVar2;
  int iVar3;
  _STARTUPINFOA *p_Var4;
  CHAR local_26c [512];
  LPSTR local_6c;
  _PROCESS_INFORMATION local_68;
  _STARTUPINFOA local_58;
  DWORD local_14;
  
                    /* 0x1f670  4
                       ?Java_NET_worlds_scape_ASFSoundPlayer_nativePlay@@YGEPAUJNIEnv_@@PAV_jclass@@PAV_jstring@@@Z
                        */
  if (DAT_0049cfe4 != 0) {
    return '\x01';
  }
  pcVar1 = (char *)(**(code **)(*(int *)param_1 + 0x2a4))(param_1,param_3,0);
  GetFullPathNameA(s_bin_playfile_exe_00470dd8,0x200,local_26c,&local_6c);
  FUN_0044d700(local_26c,&DAT_00470dec);
  FUN_0044d700(local_26c,pcVar1);
  (**(code **)(*(int *)param_1 + 0x2a8))(param_1,param_3,pcVar1);
  p_Var4 = &local_58;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    p_Var4->cb = 0;
    p_Var4 = (_STARTUPINFOA *)&p_Var4->lpReserved;
  }
  local_58.cb = 0x44;
  local_68.hProcess = (HANDLE)0x0;
  local_68.hThread = (HANDLE)0x0;
  local_68.dwProcessId = 0;
  local_68.dwThreadId = 0;
  BVar2 = CreateProcessA((LPCSTR)0x0,local_26c,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0
                         ,0,0,(LPVOID)0x0,(LPCSTR)0x0,&local_58,&local_68);
  if (BVar2 == 0) {
    return '\0';
  }
  CloseHandle(local_68.hThread);
  WaitForSingleObject(local_68.hProcess,0xffffffff);
  GetExitCodeProcess(local_68.hProcess,&local_14);
  CloseHandle(local_68.hProcess);
  return '\x01';
}


