// 00415ea0 _Java_NET_worlds_scape_CDPlayerAction_launchVolumeControlApp@8 [Global]
// program: gamma.dll

undefined1 _Java_NET_worlds_scape_CDPlayerAction_launchVolumeControlApp_8(void)

{
  HWND hWnd;
  BOOL BVar1;
  int iVar2;
  undefined1 uVar3;
  SHELLEXECUTEINFOA *pSVar4;
  SHELLEXECUTEINFOA local_48;
  
                    /* 0x15ea0  189  _Java_NET_worlds_scape_CDPlayerAction_launchVolumeControlApp@8
                        */
  hWnd = FindWindowA(s_Volume_Control_0046fe88,(LPCSTR)0x0);
  if (hWnd != (HWND)0x0) {
    BVar1 = IsIconic(hWnd);
    if (BVar1 == 0) {
      SetForegroundWindow(hWnd);
    }
    else {
      ShowWindow(hWnd,9);
    }
    return 1;
  }
  uVar3 = 0;
  pSVar4 = &local_48;
  for (iVar2 = 0xf; iVar2 != 0; iVar2 = iVar2 + -1) {
    pSVar4->cbSize = 0;
    pSVar4 = (SHELLEXECUTEINFOA *)&pSVar4->fMask;
  }
  local_48.cbSize = 0x3c;
  local_48.fMask = 0x440;
  local_48.nShow = 10;
  local_48.lpFile = s_sndvol32_exe_0046fe98;
  BVar1 = ShellExecuteExA(&local_48);
  if ((BVar1 != 0) && ((HINSTANCE)0x20 < local_48.hInstApp)) {
    uVar3 = 1;
  }
  return uVar3;
}


