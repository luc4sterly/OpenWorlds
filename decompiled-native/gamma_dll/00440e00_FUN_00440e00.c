// 00440e00 FUN_00440e00 [Global]
// program: gamma.dll

undefined4 __thiscall FUN_00440e00(int param_1,int *param_2)

{
  HBITMAP pHVar1;
  int iVar2;
  BITMAPINFO *pBVar3;
  undefined4 *puVar4;
  undefined4 *puStack_5c;
  undefined4 *puStack_58;
  BITMAPINFO BStack_54;
  undefined1 auStack_28 [12];
  undefined4 uStack_1c;
  
  if ((*(int *)(param_1 + 0x150) == 0) || (*(int *)(param_1 + 0x14c) == 0)) {
    return 0x80004005;
  }
  (**(code **)(*param_2 + 0xc))(param_2,&puStack_58);
  if (*(int *)(param_1 + 0x140) == 0) {
    pBVar3 = &BStack_54;
    for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
      (pBVar3->bmiHeader).biSize = 0;
      pBVar3 = (BITMAPINFO *)&(pBVar3->bmiHeader).biWidth;
    }
    BStack_54.bmiHeader.biSize = 0x28;
    BStack_54.bmiHeader.biWidth = *(LONG *)(param_1 + 0x134);
    BStack_54.bmiHeader.biHeight = *(LONG *)(param_1 + 0x138);
    BStack_54.bmiHeader.biCompression = 0;
    BStack_54.bmiHeader.biBitCount = 0x18;
    BStack_54.bmiHeader.biPlanes = 1;
    pHVar1 = CreateDIBSection(*(HDC *)(param_1 + 0x150),&BStack_54,0,(void **)(param_1 + 0x148),
                              (HANDLE)0x0,0);
    *(HBITMAP *)(param_1 + 0x140) = pHVar1;
    if (*(HANDLE *)(param_1 + 0x140) == (HANDLE)0x0) {
      FUN_0044d5a0(s_Could_not_create_dib_section_for_004782fc);
      FUN_0044d5a0(&DAT_004780c8);
      return 0x80004005;
    }
    iVar2 = GetObjectA(*(HANDLE *)(param_1 + 0x140),0x18,auStack_28);
    if (iVar2 == 0) {
      FUN_0044d5a0(s_Odd__couldn_t_retrieve_bitmap_ob_00478324);
      FUN_0044d5a0(&DAT_004780c8);
      uStack_1c = *(undefined4 *)(param_1 + 0x13c);
    }
    *(undefined4 *)(param_1 + 0x144) = uStack_1c;
  }
  puStack_5c = puStack_58;
  puVar4 = *(undefined4 **)(param_1 + 0x148);
  for (iVar2 = 0; iVar2 < *(int *)(param_1 + 0x138); iVar2 = iVar2 + 1) {
    FUN_0044df50(puVar4,puStack_5c,*(uint *)(param_1 + 0x13c));
    puStack_5c = (undefined4 *)((int)puStack_5c + *(int *)(param_1 + 0x13c));
    puVar4 = (undefined4 *)((int)puVar4 + *(int *)(param_1 + 0x144));
  }
  return 0;
}


