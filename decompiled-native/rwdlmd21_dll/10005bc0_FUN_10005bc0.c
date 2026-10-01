// 10005bc0 FUN_10005bc0 [Global]
// program: rwdlmd21.dll

undefined4 FUN_10005bc0(int param_1)

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
  DAT_10087194 = LoadLibraryA(s_ddraw_dll_100871c8);
  SetErrorMode(uMode);
  pcVar3 = FreeLibrary_exref;
  pFVar1 = DAT_10087198;
  if (((DAT_10087194 != (HMODULE)0x0) &&
      (pFVar1 = GetProcAddress(DAT_10087194,s_DirectDrawCreate_100871b4), pcVar3 = FreeLibrary_exref
      , pFVar1 == (FARPROC)0x0)) && (pFVar1 = DAT_10087198, DAT_10087194 != (HMODULE)0x0)) {
    DAT_10087198 = (FARPROC)0x0;
    FreeLibrary(DAT_10087194);
    DAT_10087194 = (HMODULE)0x0;
    pFVar1 = DAT_10087198;
  }
  DAT_10087198 = pFVar1;
  bVar5 = false;
  if (DAT_10087198 != (FARPROC)0x0) {
    iVar2 = (*DAT_10087198)(0,&DAT_1008717c,0);
    bVar5 = iVar2 == 0;
  }
  if (bVar5) {
    if (DAT_1008717c != (int *)0x0) {
      (**(code **)(*DAT_1008717c + 8))(DAT_1008717c);
      DAT_1008717c = (int *)0x0;
    }
    if (DAT_10087164 == 0) {
      bVar5 = false;
      if (DAT_10087198 != (FARPROC)0x0) {
        iVar2 = (*DAT_10087198)(0,&DAT_1008717c,0);
        bVar5 = iVar2 == 0;
      }
      if (bVar5) {
        puVar4 = auStack_6c;
        for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar4 = 0;
          puVar4 = puVar4 + 1;
        }
        auStack_6c[0] = 0x6c;
        iVar2 = (**(code **)(*DAT_1008717c + 0x30))(DAT_1008717c,auStack_6c);
        if ((((iVar2 == 0) && (iStack_18 == 0x10)) &&
            ((iStack_14 == 0xf800 && ((iStack_10 == 0x7e0 && (iStack_c == 0x1f)))))) &&
           (iVar2 = (**(code **)(DAT_10089de0 + 0x354))(DAT_10087164,(DAT_10087168 * 4 + 4) * 5),
           iVar2 != 0)) {
          DAT_10087164 = iVar2;
          *(undefined4 *)(DAT_10087168 * 0x14 + iVar2) = auStack_6c[3];
          *(undefined4 *)(DAT_10087168 * 0x14 + 4 + DAT_10087164) = auStack_6c[2];
          *(undefined4 *)(DAT_10087168 * 0x14 + 8 + DAT_10087164) = 0x10;
          *(undefined4 *)(DAT_10087168 * 0x14 + 0xc + DAT_10087164) = 1;
          *(undefined4 *)(DAT_10087168 * 0x14 + 0x10 + DAT_10087164) = 2;
          DAT_10087168 = DAT_10087168 + 1;
        }
        if ((DAT_10087168 != 0) || (param_1 != 0)) {
          (**(code **)(*DAT_1008717c + 0x20))(DAT_1008717c,0,0,0,&LAB_10005ed0);
        }
        if (DAT_1008717c != (int *)0x0) {
          (**(code **)(*DAT_1008717c + 8))(DAT_1008717c);
          DAT_1008717c = (int *)0x0;
        }
      }
      if ((DAT_10087164 == 0) || (DAT_10087168 == 0)) {
        if (DAT_10087194 != (HMODULE)0x0) {
          DAT_10087198 = (FARPROC)0x0;
          (*pcVar3)(DAT_10087194);
          DAT_10087194 = (HMODULE)0x0;
        }
        return 0;
      }
    }
    if (((*(uint *)(DAT_10087164 + 0x10) & 2) == 0) && (param_1 == 0)) {
      (**(code **)(DAT_10089de0 + 0x358))(DAT_10087164);
      DAT_10087164 = 0;
      if (DAT_10087194 != (HMODULE)0x0) {
        DAT_10087198 = (FARPROC)0x0;
        (*pcVar3)(DAT_10087194);
        DAT_10087194 = (HMODULE)0x0;
      }
      return 0;
    }
    DAT_1008716c = 0;
    return 1;
  }
  if (DAT_10087194 != (HMODULE)0x0) {
    DAT_10087198 = (FARPROC)0x0;
    (*pcVar3)(DAT_10087194);
    DAT_10087194 = (HMODULE)0x0;
  }
  return 0;
}


