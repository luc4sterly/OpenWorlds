// 0040f250 FUN_0040f250 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_0040f250(void *this,undefined4 param_1,HWND param_2,int param_3)

{
  char cVar1;
  char cVar2;
  HINSTANCE hInstance;
  void *pvVar3;
  LONG LVar4;
  HICON lParam;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  CHAR local_110 [256];
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined1 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  pvVar3 = DAT_0049ff1c;
  if ((param_3 != 0) && (pvVar3 = this, DAT_0049ff1c != (void *)0x0)) {
    FUN_00402800(s_nWindow_0046e8c4,0x8e0);
    pvVar3 = this;
  }
  DAT_0049ff1c = pvVar3;
  *(undefined4 *)this = param_1;
  if (DAT_004891c0 != (HWND)0x0) goto LAB_0040f42d;
  DAT_004891c0 = param_2;
  LVar4 = GetWindowLongA(param_2,-4);
  iVar5 = DAT_00489248;
  iVar8 = 0;
  if (0 < DAT_00489248) {
    do {
      if ((&DAT_00489254)[iVar8] == LVar4) break;
      iVar8 = iVar8 + 1;
    } while (iVar8 < DAT_00489248);
  }
  if (iVar8 == DAT_00489248) {
    if (DAT_00489248 < 8) {
      DAT_00489248 = DAT_00489248 + 1;
      (&DAT_00489254)[iVar5] = LVar4;
      goto LAB_0040f333;
    }
    FUN_00403350(0x49eda8,(byte *)s_No_more_window_procedures_for_su_0046e920);
  }
  else {
LAB_0040f333:
    SetWindowLongA(param_2,-4,(LONG)(&PTR_LAB_0046e900)[iVar8]);
  }
  EnumChildWindows(param_2,(WNDENUMPROC)&LAB_0040dad0,0);
  FUN_00409ce0(DAT_004891c0);
  hInstance = DAT_004891bc;
  GetPrivateProfileStringA
            (s_Runtime_0046ea94,s_GAMMAICON_0046ea88,s_default_0046ea80,local_110,0x100,
             s___override_ini_0046ea70);
  iVar5 = 8;
  pcVar6 = local_110;
  pcVar9 = s_default_0046ea80;
  do {
    pcVar7 = pcVar6;
    pcVar10 = pcVar9;
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    pcVar10 = pcVar9 + 1;
    pcVar7 = pcVar6 + 1;
    cVar2 = *pcVar9;
    cVar1 = *pcVar6;
    pcVar6 = pcVar7;
    pcVar9 = pcVar10;
  } while (cVar1 == cVar2);
  if (pcVar7[-1] == pcVar10[-1]) {
    lParam = LoadIconA(DAT_004891bc,(LPCSTR)0x1);
  }
  else {
    lParam = LoadImageA(DAT_004891bc,local_110,1,0,0,0x50);
  }
  if (lParam == (HICON)0x0) {
    lParam = LoadIconA(hInstance,&DAT_0046e9c4);
  }
  if (lParam != (HICON)0x0) {
    SendMessageA(param_2,0x80,0,(LPARAM)lParam);
    SendMessageA(param_2,0x80,1,(LPARAM)lParam);
  }
  ShowWindow(param_2,9);
  UpdateWindow(param_2);
LAB_0040f42d:
  InitializeCriticalSection((LPCRITICAL_SECTION)((int)this + 4));
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004891d0);
  iVar5 = 0;
  do {
    if ((&DAT_0049fccc)[iVar5] == 0) {
      (&DAT_0049fccc)[iVar5] = this;
      break;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 5);
  if (4 < iVar5) {
    FUN_00402800(s_nWindow_0046e8c4,0x8f2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004891d0);
  return this;
}


