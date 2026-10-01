// 10005510 FUN_10005510 [Global]
// program: RWDL8D21.DLL

undefined4 FUN_10005510(int param_1)

{
  UINT uMode;
  FARPROC pFVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  bool bVar5;
  undefined4 auStack_6c [19];
  uint uStack_20;
  int iStack_18;
  
  uMode = SetErrorMode(0x8000);
  DAT_1007518c = LoadLibraryA(s_ddraw_dll_100751c0);
  SetErrorMode(uMode);
  pcVar3 = FreeLibrary_exref;
  pFVar1 = DAT_10075190;
  if (((DAT_1007518c != (HMODULE)0x0) &&
      (pFVar1 = GetProcAddress(DAT_1007518c,s_DirectDrawCreate_100751ac), pcVar3 = FreeLibrary_exref
      , pFVar1 == (FARPROC)0x0)) && (pFVar1 = DAT_10075190, DAT_1007518c != (HMODULE)0x0)) {
    DAT_10075190 = (FARPROC)0x0;
    FreeLibrary(DAT_1007518c);
    DAT_1007518c = (HMODULE)0x0;
    pFVar1 = DAT_10075190;
  }
  DAT_10075190 = pFVar1;
  bVar5 = false;
  if (DAT_10075190 != (FARPROC)0x0) {
    iVar2 = (*DAT_10075190)(0,&DAT_10075174,0);
    bVar5 = iVar2 == 0;
  }
  if (bVar5) {
    if (DAT_10075174 != (int *)0x0) {
      (**(code **)(*DAT_10075174 + 8))(DAT_10075174);
      DAT_10075174 = (int *)0x0;
    }
    if (DAT_1007515c == 0) {
      bVar5 = false;
      if (DAT_10075190 != (FARPROC)0x0) {
        iVar2 = (*DAT_10075190)(0,&DAT_10075174,0);
        bVar5 = iVar2 == 0;
      }
      if (bVar5) {
        puVar4 = auStack_6c;
        for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        auStack_6c[0] = 0x6c;
        iVar2 = (**(code **)(*DAT_10075174 + 0x30))(DAT_10075174,auStack_6c);
        if (((iVar2 == 0) && (iStack_18 == 8)) &&
           (((uStack_20 & 0x20) != 0 &&
            (iVar2 = (**(code **)(DAT_10077da8 + 0x354))(DAT_1007515c,(DAT_10075160 * 4 + 4) * 5),
            iVar2 != 0)))) {
          DAT_1007515c = iVar2;
          *(undefined4 *)(DAT_10075160 * 0x14 + iVar2) = auStack_6c[3];
          *(undefined4 *)(DAT_10075160 * 0x14 + 4 + DAT_1007515c) = auStack_6c[2];
          *(undefined4 *)(DAT_10075160 * 0x14 + 8 + DAT_1007515c) = 8;
          *(undefined4 *)(DAT_10075160 * 0x14 + 0xc + DAT_1007515c) = 1;
          *(undefined4 *)(DAT_10075160 * 0x14 + 0x10 + DAT_1007515c) = 2;
          DAT_10075160 = DAT_10075160 + 1;
        }
        if ((DAT_10075160 != 0) || (param_1 != 0)) {
          (**(code **)(*DAT_10075174 + 0x20))(DAT_10075174,0,0,0,&LAB_10005800);
        }
        if (DAT_10075174 != (int *)0x0) {
          (**(code **)(*DAT_10075174 + 8))(DAT_10075174);
          DAT_10075174 = (int *)0x0;
        }
      }
      if ((DAT_1007515c == 0) || (DAT_10075160 == 0)) {
        if (DAT_1007518c != (HMODULE)0x0) {
          DAT_10075190 = (FARPROC)0x0;
          (*pcVar3)(DAT_1007518c);
          DAT_1007518c = (HMODULE)0x0;
        }
        return 0;
      }
    }
    if (((*(uint *)(DAT_1007515c + 0x10) & 2) == 0) && (param_1 == 0)) {
      (**(code **)(DAT_10077da8 + 0x358))(DAT_1007515c);
      DAT_1007515c = 0;
      if (DAT_1007518c != (HMODULE)0x0) {
        DAT_10075190 = (FARPROC)0x0;
        (*pcVar3)(DAT_1007518c);
        DAT_1007518c = (HMODULE)0x0;
      }
      return 0;
    }
    DAT_10075164 = 0;
    return 1;
  }
  if (DAT_1007518c != (HMODULE)0x0) {
    DAT_10075190 = (FARPROC)0x0;
    (*pcVar3)(DAT_1007518c);
    DAT_1007518c = (HMODULE)0x0;
  }
  return 0;
}


