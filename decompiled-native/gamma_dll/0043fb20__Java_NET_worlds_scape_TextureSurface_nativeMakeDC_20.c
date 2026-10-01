// 0043fb20 _Java_NET_worlds_scape_TextureSurface_nativeMakeDC@20 [Global]
// program: gamma.dll

HDC _Java_NET_worlds_scape_TextureSurface_nativeMakeDC_20
              (int *param_1,undefined4 param_2,HWND param_3,LONG param_4,LONG param_5)

{
  HDC hdc;
  HDC hdc_00;
  HBITMAP h;
  HGDIOBJ pvVar1;
  undefined4 uVar2;
  int iVar3;
  BITMAPINFO *pBVar4;
  BITMAPINFO local_80;
  undefined4 local_54;
  undefined4 local_50;
  void *local_14;
  
                    /* 0x3fb20  309  _Java_NET_worlds_scape_TextureSurface_nativeMakeDC@20 */
  hdc = GetDC(param_3);
  hdc_00 = CreateCompatibleDC(hdc);
  ReleaseDC(param_3,hdc);
  pBVar4 = &local_80;
  for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
    (pBVar4->bmiHeader).biSize = 0;
    pBVar4 = (BITMAPINFO *)&(pBVar4->bmiHeader).biWidth;
  }
  local_80.bmiHeader.biSize = 0x6c;
  local_80.bmiHeader.biHeight = param_5;
  local_80.bmiHeader.biPlanes = 1;
  local_50 = 0x1f;
  local_80.bmiHeader.biWidth = param_4;
  local_54 = 0x7e0;
  local_80.bmiHeader.biBitCount = 0x10;
  local_80.bmiColors[0].rgbBlue = '\0';
  local_80.bmiColors[0].rgbGreen = 0xf8;
  local_80.bmiColors[0].rgbRed = '\0';
  local_80.bmiColors[0].rgbReserved = '\0';
  local_80.bmiHeader.biCompression = 3;
  h = CreateDIBSection(hdc_00,&local_80,0,&local_14,(HANDLE)0x0,0);
  if (h == (HBITMAP)0x0) {
    FUN_0044d5a0(s_CreateDIBSection_failed_in_nativ_00477ef0);
  }
  pvVar1 = SelectObject(hdc_00,h);
  uVar2 = (**(code **)(*param_1 + 0x7c))(param_1,param_2);
  iVar3 = (**(code **)(*param_1 + 0x178))(param_1,uVar2,s__oldObject_00477f20,&DAT_00477f1c);
  if (iVar3 == 0) {
    FUN_00402800(s_nTexSurface_00477ee0,0x7c);
  }
  (**(code **)(*param_1 + 0x1b4))(param_1,param_2,iVar3,pvVar1);
  return hdc_00;
}


