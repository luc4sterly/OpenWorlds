// 00424870 FUN_00424870 [Global]
// programa: gamma.dll

HBITMAP __cdecl
FUN_00424870(int *param_1,COLORREF param_2,COLORREF param_3,HDC param_4,int param_5,LPCSTR param_6,
            LPCWSTR param_7,int *param_8,int *param_9,DWORD param_10,UINT param_11)

{
  char cVar1;
  HBITMAP h;
  HGDIOBJ h_00;
  int iVar2;
  LPCSTR pCVar3;
  uint uVar4;
  HFONT local_488;
  HGDIOBJ local_484;
  tagSIZE local_480;
  undefined1 local_478 [100];
  void *local_414;
  undefined4 local_410 [256];
  
  if (param_11 == 0) {
    param_11 = 1;
    param_7 = (LPCWSTR)&DAT_00471958;
  }
  iVar2 = -1;
  local_488 = (HFONT)0x0;
  pCVar3 = param_6;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pCVar3;
    pCVar3 = pCVar3 + 1;
  } while (cVar1 != '\0');
  if (-iVar2 - 2U < 0x21) {
    local_488 = CreateFontA(param_5,0,0,0,400,0,0,0,param_10,0,0,2,0,param_6);
  }
  local_484 = (HGDIOBJ)0x0;
  local_480.cy = DAT_0049d22c;
  local_480.cx = DAT_0049d228;
  if (local_488 == (HFONT)0x0) {
    FUN_0044d650((int)local_478,s_Warning__font__s_is_unavailable__0047195c);
    FUN_0040b740(param_1,local_478);
  }
  else {
    local_484 = SelectObject(param_4,local_488);
  }
  GetTextExtentPoint32W(param_4,param_7,param_11,&local_480);
  if (0xfffff < local_480.cx * local_480.cy) {
    local_480.cx = (int)(local_480.cy + (local_480.cy >> 0x1f & 0xfffffU)) >> 0x14;
    FUN_0040b740(param_1,s_Warning__your_font_size_and_stri_00471994);
  }
  if ((local_480.cx == 0) || (local_480.cy == 0)) {
    local_480.cy = 8;
    local_480.cx = 8;
  }
  if (param_8 != (int *)0x0) {
    *param_8 = local_480.cx;
  }
  if (param_9 != (int *)0x0) {
    *param_9 = local_480.cy;
  }
  iVar2 = FUN_00417900();
  if (iVar2 == 1) {
    FUN_00421ff0((int)local_410);
  }
  uVar4 = 0;
  iVar2 = FUN_00417900();
  h = FUN_00422150(param_4,local_480.cx,local_480.cy,local_410,&local_414,iVar2,uVar4);
  if (h == (HBITMAP)0x0) {
    FUN_00402800(s_nStringTexture_004718d0,0xa7);
  }
  h_00 = SelectObject(param_4,h);
  iVar2 = FUN_00417900();
  if (iVar2 != 1) {
    if (param_2 == 0) {
      param_2 = 0x80808;
    }
    if (param_3 == 0xfefefe) {
      param_3 = 0;
    }
    else if (param_3 == 0) {
      param_3 = 0x80808;
    }
  }
  SetTextColor(param_4,param_2);
  SetBkColor(param_4,param_3);
  SetTextAlign(param_4,0);
  ExtTextOutW(param_4,0,0,0,(RECT *)0x0,param_7,param_11,(INT *)0x0);
  SelectObject(param_4,h_00);
  if (local_484 != (HGDIOBJ)0x0) {
    SelectObject(param_4,local_484);
  }
  if (local_488 != (HFONT)0x0) {
    DeleteObject(local_488);
  }
  return h;
}


