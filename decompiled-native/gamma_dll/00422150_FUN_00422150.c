// 00422150 FUN_00422150 [Global]
// programa: gamma.dll

HBITMAP __cdecl
FUN_00422150(HDC param_1,LONG param_2,int param_3,undefined4 *param_4,void **param_5,int param_6,
            uint param_7)

{
  uint uVar1;
  HBITMAP pHVar2;
  int iVar3;
  BITMAPINFO *pBVar4;
  bool bVar5;
  BITMAPINFO local_434;
  undefined4 local_408;
  undefined4 local_404;
  
  bVar5 = (param_7 & 1) == 0;
  pBVar4 = &local_434;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    (pBVar4->bmiHeader).biSize = 0;
    pBVar4 = (BITMAPINFO *)&(pBVar4->bmiHeader).biWidth;
  }
  local_434.bmiHeader.biSize = 0x28;
  local_434.bmiHeader.biWidth = param_2;
  local_434.bmiHeader.biHeight = -param_3;
  local_434.bmiHeader.biPlanes = 1;
  local_434.bmiHeader.biBitCount = (short)param_6 * 8;
  if (param_6 == 1) {
    local_434.bmiHeader.biClrUsed = 0x100;
  }
  else {
    local_434.bmiHeader.biClrUsed = 0;
  }
  local_434.bmiHeader.biClrImportant = 0;
  local_434.bmiHeader.biCompression = 0;
  if (param_6 == 1) {
    if (bVar5) {
      uVar1 = 0x400;
    }
    else {
      uVar1 = 0x200;
    }
    FUN_0044df50(local_434.bmiColors,param_4,uVar1);
  }
  else if (param_6 == 2) {
    local_434.bmiHeader.biCompression = 3;
    local_434.bmiColors[0].rgbBlue = '\0';
    local_434.bmiColors[0].rgbGreen = 0xf8;
    local_434.bmiColors[0].rgbRed = '\0';
    local_434.bmiColors[0].rgbReserved = '\0';
    local_408 = 0x7e0;
    local_404 = 0x1f;
  }
  pHVar2 = CreateDIBSection(param_1,&local_434,(uint)!bVar5,param_5,(HANDLE)0x0,0);
  if (pHVar2 == (HBITMAP)0x0) {
    FUN_004028c0((byte *)s_Out_of_virtual_memory_004714b0,(byte *)s_makeDIB_004714c8);
  }
  return pHVar2;
}


