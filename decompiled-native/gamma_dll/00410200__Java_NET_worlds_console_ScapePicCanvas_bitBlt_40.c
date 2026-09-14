// 00410200 _Java_NET_worlds_console_ScapePicCanvas_bitBlt@40 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_ScapePicCanvas_bitBlt_40
               (undefined4 param_1,undefined4 param_2,HWND param_3,HGDIOBJ param_4,int param_5,
               int param_6,int param_7,int param_8,int param_9,int param_10)

{
  HDC hdc;
  HDC hdc_00;
  HGDIOBJ h;
  HPALETTE hPal;
  HPALETTE hPal_00;
  
                    /* 0x10200  64  _Java_NET_worlds_console_ScapePicCanvas_bitBlt@40 */
  if ((param_3 != (HWND)0x0) && (param_4 != (HGDIOBJ)0x0)) {
    hdc = GetDC(param_3);
    hdc_00 = CreateCompatibleDC(hdc);
    h = SelectObject(hdc_00,param_4);
    hPal_00 = (HPALETTE)0x0;
    hPal = FUN_0040d7a0();
    if (hPal != (HPALETTE)0x0) {
      hPal_00 = SelectPalette(hdc,hPal,0);
      RealizePalette(hdc);
    }
    BitBlt(hdc,param_5,param_6,param_9,param_10,hdc_00,param_7,param_8,0xcc0020);
    if (hPal != (HPALETTE)0x0) {
      SelectPalette(hdc,hPal_00,0);
    }
    SelectObject(hdc_00,h);
    DeleteDC(hdc_00);
    ReleaseDC(param_3,hdc);
  }
  return;
}


