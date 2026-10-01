// 10004010 FUN_10004010 [Global]
// program: RWDL6D21.DLL

char FUN_10004010(HDC param_1)

{
  HDC hdc;
  HBITMAP hbit;
  HGDIOBJ h;
  COLORREF CVar1;
  LONG LVar2;
  short local_2;
  
  hdc = CreateCompatibleDC(param_1);
  if (hdc == (HDC)0x0) {
    return '\x10';
  }
  hbit = CreateBitmap(1,1,1,0x10,(void *)0x0);
  if (hbit == (HBITMAP)0x0) {
    DeleteDC(hdc);
    return '\x10';
  }
  h = SelectObject(hdc,hbit);
  CVar1 = SetPixel(hdc,0,0,0xffffff);
  if (CVar1 == 0xffffffff) {
    SelectObject(hdc,h);
    DeleteObject(hbit);
    DeleteDC(hdc);
    return '\x10';
  }
  LVar2 = GetBitmapBits(hbit,2,&local_2);
  if (LVar2 == 0) {
    SelectObject(hdc,h);
    DeleteObject(hbit);
    DeleteDC(hdc);
    return '\x10';
  }
  SelectObject(hdc,h);
  DeleteObject(hbit);
  DeleteDC(hdc);
  return (local_2 == -1) + '\x0f';
}


