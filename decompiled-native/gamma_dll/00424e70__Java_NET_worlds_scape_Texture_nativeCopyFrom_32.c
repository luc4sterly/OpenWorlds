// 00424e70 _Java_NET_worlds_scape_Texture_nativeCopyFrom@32 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Texture_nativeCopyFrom_32
               (undefined4 param_1,undefined4 param_2,int param_3,HDC param_4,int param_5,
               int param_6,int param_7,int param_8)

{
  int iVar1;
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  BOOL BVar2;
  int iVar3;
  BITMAPINFO *pBVar4;
  BITMAPINFO local_98;
  undefined4 local_6c;
  undefined4 local_68;
  void *local_2c;
  undefined1 local_28 [4];
  int local_24;
  int local_20;
  int local_1c;
  short local_16;
  uint *local_14;
  
                    /* 0x24e70  311  _Java_NET_worlds_scape_Texture_nativeCopyFrom@32 */
  iVar1 = FUN_00417900();
  if (iVar1 != 2) {
    return;
  }
  iVar1 = FUN_00417910();
  hdc = CreateCompatibleDC(param_4);
  if (hdc == (HDC)0x0) {
    FUN_0044d5a0(s_Failed_to_create_texture_copy_dc_00471ab8);
    return;
  }
  pBVar4 = &local_98;
  for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
    (pBVar4->bmiHeader).biSize = 0;
    pBVar4 = (BITMAPINFO *)&(pBVar4->bmiHeader).biWidth;
  }
  local_98.bmiHeader.biSize = 0x6c;
  local_98.bmiHeader.biHeight = -iVar1;
  local_68 = 0x1f;
  local_6c = 0x7e0;
  local_98.bmiHeader.biPlanes = 1;
  local_98.bmiColors[0].rgbBlue = '\0';
  local_98.bmiColors[0].rgbGreen = 0xf8;
  local_98.bmiColors[0].rgbRed = '\0';
  local_98.bmiColors[0].rgbReserved = '\0';
  local_98.bmiHeader.biBitCount = 0x10;
  local_98.bmiHeader.biCompression = 3;
  local_98.bmiHeader.biWidth = iVar1;
  h = CreateDIBSection(hdc,&local_98,0,&local_2c,(HANDLE)0x0,0);
  if (h == (HBITMAP)0x0) {
    FUN_0044d5a0(s_CreateDIBSection_failed_in_nativ_00471adc);
    DeleteObject((HGDIOBJ)0x0);
    DeleteDC(hdc);
    return;
  }
  h_00 = SelectObject(hdc,h);
  if (h_00 == (HGDIOBJ)0x0) {
    FUN_0044d5a0(s_Error_selecting_copy_bitmap_00471b08);
    DeleteObject(h);
    DeleteDC(hdc);
    return;
  }
  BVar2 = StretchBlt(hdc,0,0,iVar1,iVar1,param_4,param_5,param_7,param_6 - param_5,param_8 - param_7
                     ,0xcc0020);
  if (BVar2 == 0) {
    FUN_0044d5a0(s_StretchBlt_failed_in_nativeCopyF_00471b28);
    DeleteObject(h);
    DeleteDC(hdc);
    return;
  }
  iVar3 = GetObjectA(h,0x18,local_28);
  if (iVar3 == 0) {
    FUN_0044d5a0(s_Failed_to_get_bitmap_to_copy_int_00471b50);
    DeleteObject(h);
    DeleteDC(hdc);
    return;
  }
  SelectObject(hdc,h_00);
  if ((((local_14 != (uint *)0x0) && (local_16 == 0x10)) && (local_24 == iVar1)) &&
     ((local_20 == iVar1 && (local_1c == iVar1 * 2)))) {
    iVar1 = FUN_00418490(param_3,local_14);
    if (iVar1 == 0) {
      FUN_00418540(param_3,(int)hdc,(int)h);
    }
  }
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}


