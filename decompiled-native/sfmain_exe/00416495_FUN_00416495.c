// 00416495 FUN_00416495 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00416495(void)

{
  HWND in_EAX;
  HWND hWnd;
  int nBar;
  int nPos;
  BOOL bRedraw;
  CHAR local_34 [16];
  double local_24;
  HWND local_1c;
  
  if (DAT_0043d3f4 != DAT_0043d710) {
    bRedraw = 1;
    nBar = 2;
    local_1c = in_EAX;
    nPos = DAT_0043d710;
    hWnd = GetDlgItem(in_EAX,0x41c);
    SetScrollPos(hWnd,nBar,nPos,bRedraw);
    local_24 = _DAT_00436084 - (double)DAT_0043d710 / _DAT_0043607c;
    FUN_0042ca26((int)local_34,(byte *)s__2_2lf_00436075);
    SetDlgItemTextA(local_1c,0x41e,local_34);
    DAT_0043d3f4 = DAT_0043d710;
  }
  return;
}


