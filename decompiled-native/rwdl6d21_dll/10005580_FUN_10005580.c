// 10005580 FUN_10005580 [Global]
// program: RWDL6D21.DLL

undefined4 FUN_10005580(int param_1)

{
  UINT uMode;
  FARPROC pFVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  bool bVar5;
  undefined4 auStack_6c [21];
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  
  uMode = SetErrorMode(0x8000);
  DAT_1007918c = LoadLibraryA(s_ddraw_dll_100791c0);
  SetErrorMode(uMode);
  pcVar3 = FreeLibrary_exref;
  pFVar1 = DAT_10079190;
  if (((DAT_1007918c != (HMODULE)0x0) &&
      (pFVar1 = GetProcAddress(DAT_1007918c,s_DirectDrawCreate_100791ac), pcVar3 = FreeLibrary_exref
      , pFVar1 == (FARPROC)0x0)) && (pFVar1 = DAT_10079190, DAT_1007918c != (HMODULE)0x0)) {
    DAT_10079190 = (FARPROC)0x0;
    FreeLibrary(DAT_1007918c);
    DAT_1007918c = (HMODULE)0x0;
    pFVar1 = DAT_10079190;
  }
  DAT_10079190 = pFVar1;
  bVar5 = false;
  if (DAT_10079190 != (FARPROC)0x0) {
    iVar2 = (*DAT_10079190)(0,&DAT_10079174,0);
    bVar5 = iVar2 == 0;
  }
  if (bVar5) {
    if (DAT_10079174 != (int *)0x0) {
      (**(code **)(*DAT_10079174 + 8))(DAT_10079174);
      DAT_10079174 = (int *)0x0;
    }
    if (DAT_1007915c == 0) {
      bVar5 = false;
      if (DAT_10079190 != (FARPROC)0x0) {
        iVar2 = (*DAT_10079190)(0,&DAT_10079174,0);
        bVar5 = iVar2 == 0;
      }
      if (bVar5) {
        puVar4 = auStack_6c;
        for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        auStack_6c[0] = 0x6c;
        iVar2 = (**(code **)(*DAT_10079174 + 0x30))(DAT_10079174,auStack_6c);
        if ((((iVar2 == 0) && (iStack_18 == 0x10)) &&
            ((iStack_14 == 0xf800 && ((iStack_10 == 0x7e0 && (iStack_c == 0x1f)))))) &&
           (iVar2 = (**(code **)(DAT_1007bda8 + 0x354))(DAT_1007915c,(DAT_10079160 * 4 + 4) * 5),
           iVar2 != 0)) {
          DAT_1007915c = iVar2;
          *(undefined4 *)(DAT_10079160 * 0x14 + iVar2) = auStack_6c[3];
          *(undefined4 *)(DAT_10079160 * 0x14 + 4 + DAT_1007915c) = auStack_6c[2];
          *(undefined4 *)(DAT_10079160 * 0x14 + 8 + DAT_1007915c) = 0x10;
          *(undefined4 *)(DAT_10079160 * 0x14 + 0xc + DAT_1007915c) = 1;
          *(undefined4 *)(DAT_10079160 * 0x14 + 0x10 + DAT_1007915c) = 2;
          DAT_10079160 = DAT_10079160 + 1;
        }
        if ((DAT_10079160 != 0) || (param_1 != 0)) {
          (**(code **)(*DAT_10079174 + 0x20))(DAT_10079174,0,0,0,&LAB_10005890);
        }
        if (DAT_10079174 != (int *)0x0) {
          (**(code **)(*DAT_10079174 + 8))(DAT_10079174);
          DAT_10079174 = (int *)0x0;
        }
      }
      if ((DAT_1007915c == 0) || (DAT_10079160 == 0)) {
        if (DAT_1007918c != (HMODULE)0x0) {
          DAT_10079190 = (FARPROC)0x0;
          (*pcVar3)(DAT_1007918c);
          DAT_1007918c = (HMODULE)0x0;
        }
        return 0;
      }
    }
    if (((*(uint *)(DAT_1007915c + 0x10) & 2) == 0) && (param_1 == 0)) {
      (**(code **)(DAT_1007bda8 + 0x358))(DAT_1007915c);
      DAT_1007915c = 0;
      if (DAT_1007918c != (HMODULE)0x0) {
        DAT_10079190 = (FARPROC)0x0;
        (*pcVar3)(DAT_1007918c);
        DAT_1007918c = (HMODULE)0x0;
      }
      return 0;
    }
    DAT_10079164 = 0;
    return 1;
  }
  if (DAT_1007918c != (HMODULE)0x0) {
    DAT_10079190 = (FARPROC)0x0;
    (*pcVar3)(DAT_1007918c);
    DAT_1007918c = (HMODULE)0x0;
  }
  return 0;
}


