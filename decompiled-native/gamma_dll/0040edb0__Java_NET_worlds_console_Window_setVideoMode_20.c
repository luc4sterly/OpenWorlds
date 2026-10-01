// 0040edb0 _Java_NET_worlds_console_Window_setVideoMode@20 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_Window_setVideoMode_20
               (undefined4 param_1,undefined4 param_2,HWND param_3,uint param_4,uint param_5)

{
  char cVar1;
  char cVar2;
  HINSTANCE hInstance;
  LONG LVar3;
  HICON lParam;
  HWND pHVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  CHAR local_110 [256];
  
                    /* 0xedb0  116  _Java_NET_worlds_console_Window_setVideoMode@20 */
  if (DAT_004891c0 != (HWND)0x0) goto LAB_0040ef24;
  DAT_004891c0 = param_3;
  LVar3 = GetWindowLongA(param_3,-4);
  iVar6 = DAT_00489248;
  iVar5 = 0;
  if (0 < DAT_00489248) {
    do {
      if ((&DAT_00489254)[iVar5] == LVar3) break;
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_00489248);
  }
  if (iVar5 == DAT_00489248) {
    if (DAT_00489248 < 8) {
      DAT_00489248 = DAT_00489248 + 1;
      (&DAT_00489254)[iVar6] = LVar3;
      goto LAB_0040ee33;
    }
    FUN_00403350(0x49eda8,(byte *)s_No_more_window_procedures_for_su_0046e920);
  }
  else {
LAB_0040ee33:
    SetWindowLongA(param_3,-4,(LONG)(&PTR_LAB_0046e900)[iVar5]);
  }
  EnumChildWindows(param_3,(WNDENUMPROC)&LAB_0040dad0,0);
  FUN_00409ce0(DAT_004891c0);
  hInstance = DAT_004891bc;
  GetPrivateProfileStringA
            (s_Runtime_0046ea94,s_GAMMAICON_0046ea88,s_default_0046ea80,local_110,0x100,
             s___override_ini_0046ea70);
  iVar6 = 8;
  pcVar7 = local_110;
  pcVar9 = s_default_0046ea80;
  do {
    pcVar8 = pcVar7;
    pcVar10 = pcVar9;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar10 = pcVar9 + 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar9;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
    pcVar9 = pcVar10;
  } while (cVar1 == cVar2);
  if (pcVar8[-1] == pcVar10[-1]) {
    lParam = LoadIconA(DAT_004891bc,(LPCSTR)0x1);
  }
  else {
    lParam = LoadImageA(DAT_004891bc,local_110,1,0,0,0x50);
  }
  if (lParam == (HICON)0x0) {
    lParam = LoadIconA(hInstance,&DAT_0046e9c4);
  }
  if (lParam != (HICON)0x0) {
    SendMessageA(param_3,0x80,0,(LPARAM)lParam);
    SendMessageA(param_3,0x80,1,(LPARAM)lParam);
  }
  ShowWindow(param_3,9);
  UpdateWindow(param_3);
LAB_0040ef24:
  DAT_0048923c = FUN_0044e010(0x94);
  DAT_0048923c[0x1b] = param_4;
  DAT_0048923c[0x1c] = param_5;
  *(undefined2 *)(DAT_0048923c + 9) = 0x94;
  DAT_0048923c[10] = 0x180000;
  pHVar4 = GetForegroundWindow();
  if (pHVar4 == param_3) {
    FUN_0040ef80(1,0);
  }
  return;
}


