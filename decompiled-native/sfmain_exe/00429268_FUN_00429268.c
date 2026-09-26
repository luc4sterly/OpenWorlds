// 00429268 FUN_00429268 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall
FUN_00429268(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            WPARAM param_5,HWND param_6,UINT param_7,LPCSTR param_8)

{
  int iVar1;
  DWORD DVar2;
  undefined4 extraout_ECX;
  char *pcVar3;
  DWORD *pDVar4;
  LPOVERLAPPED p_Var5;
  CHAR local_424 [1024];
  va_list local_24;
  DWORD local_20;
  int local_1c;
  
  local_24 = &stack0x0000001c;
  wvsprintfA(local_424,param_8,local_24);
  local_24 = (va_list)0x0;
  if (DAT_0043d6d8 != (HANDLE)0xffffffff) {
    pcVar3 = s__GPE__d___d_of__s__0043744d;
    iVar1 = FUN_0042c5ad();
    FUN_0042ca26((int)(local_424 + iVar1),(byte *)pcVar3);
    p_Var5 = (LPOVERLAPPED)0x0;
    pDVar4 = &local_20;
    DVar2 = FUN_0042c5ad();
    WriteFile(DAT_0043d6d8,local_424,DVar2,pDVar4,p_Var5);
    if (_DAT_004b2c6c != 0) {
      local_1c = 0;
      goto LAB_0042940d;
    }
  }
  if (_DAT_004b2c6c == 0) {
    FUN_0042c5ad();
    FUN_0042b0bf(extraout_ECX,param_5);
    if (DAT_0043d6d8 != (HANDLE)0xffffffff) {
      if (DAT_004623b0 == 0) {
        FUN_0042ca26((int)local_424,(byte *)s_sendGammaMessage_failed____g_is_N_00437462);
        p_Var5 = (LPOVERLAPPED)0x0;
        pDVar4 = &local_20;
        DVar2 = FUN_0042c5ad();
        WriteFile(DAT_0043d6d8,local_424,DVar2,pDVar4,p_Var5);
      }
      else {
        FUN_0042ca26((int)local_424,(byte *)s_sendGammaMessage__d__00437488);
        p_Var5 = (LPOVERLAPPED)0x0;
        pDVar4 = &local_20;
        DVar2 = FUN_0042c5ad();
        WriteFile(DAT_0043d6d8,local_424,DVar2,pDVar4,p_Var5);
      }
    }
    local_1c = 0;
  }
  else {
    local_1c = MessageBoxA(param_6,local_424,DAT_004627c0,param_7);
  }
LAB_0042940d:
  return CONCAT44(param_2,local_1c);
}


