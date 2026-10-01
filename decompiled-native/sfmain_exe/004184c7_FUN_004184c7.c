// 004184c7 FUN_004184c7 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_004184c7(undefined4 param_1,undefined4 param_2)

{
  HWND in_EAX;
  MMRESULT mmrError;
  HGLOBAL pvVar1;
  LPVOID pvVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined4 extraout_ECX_09;
  undefined4 extraout_ECX_10;
  undefined4 extraout_ECX_11;
  undefined4 extraout_ECX_12;
  undefined4 extraout_ECX_13;
  undefined4 extraout_ECX_14;
  undefined4 extraout_ECX_15;
  undefined4 extraout_ECX_16;
  undefined4 extraout_ECX_17;
  undefined4 extraout_ECX_18;
  undefined4 extraout_ECX_19;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar3;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  int iVar4;
  int extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 uVar5;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined8 uVar6;
  int local_40;
  int local_3c;
  uint local_38;
  MMRESULT local_24;
  undefined4 local_1c;
  
  if (DAT_0043d520 == 0) {
    while( true ) {
      local_24 = FUN_004175c0(0,DAT_0043d5f0,0,1);
      if ((8 < _DAT_0043d6a8) && (local_24 == 0x20)) {
        DAT_0043d5fc = 1;
      }
      uVar3 = extraout_ECX;
      uVar5 = extraout_EDX;
      if (((DAT_0043d600 != 0) || (local_24 == 0x20)) && (8 < _DAT_0043d6a8)) {
        _DAT_0043d6a8 = _DAT_0043d6a8 / 2;
        DAT_0043d6a4 = DAT_0043d6a4 / 2;
        DAT_0043d6a0 = DAT_0043d6a0 / 2;
        local_24 = FUN_004175c0(0,DAT_0043d5f0,0,1);
        uVar3 = extraout_ECX_00;
        uVar5 = extraout_EDX_00;
      }
      if ((local_24 != 0x20) || (DAT_0043d69c != 8000)) break;
      DAT_0043d69c = 0x2b11;
      _DAT_0043d6a8 = 0x10;
      DAT_0043d6a4 = 2;
      DAT_0043d6a0 = 0x5622;
    }
    if (local_24 != 0) {
      uVar6 = FUN_00429192(uVar3,uVar5);
      FUN_00429268(extraout_ECX_01,(int)((ulonglong)uVar6 >> 0x20),0x470,
                   s__GAMMA_speakfre_sfmain_FRAME_c_00436280,9,in_EAX,0x30,s_1___s___d__00436275);
      local_1c = 0;
      goto LAB_00418bab;
    }
    local_38 = 0;
    while ((local_38 < 2 &&
           (mmrError = FUN_004175c0(DAT_004627d0,DAT_0043d5f0,0,0x10000), uVar3 = extraout_ECX_02,
           uVar5 = extraout_EDX_01, mmrError != 0))) {
      if (((local_38 != 0) || (DAT_0043d51c == 0)) || ((mmrError != 4 && (mmrError != 8)))) {
        waveInGetErrorTextA(mmrError,&DAT_00462b26,0x100);
        uVar6 = FUN_00429192(extraout_ECX_06,extraout_EDX_03);
        FUN_00429268(extraout_ECX_07,(int)((ulonglong)uVar6 >> 0x20),0x49a,
                     s__GAMMA_speakfre_sfmain_FRAME_c_0043629f,10,in_EAX,0x30,s__s___s_00436211);
        local_1c = 0;
        goto LAB_00418bab;
      }
      uVar6 = FUN_004176dc(extraout_ECX_02,extraout_EDX_01);
      uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
      DAT_0043d5f8 = 1;
      if (DAT_0043d538 != 0) {
        DAT_0043d540 = 1;
        FUN_004152eb(extraout_ECX_03,uVar3);
        local_1c = 1;
        goto LAB_00418bab;
      }
      uVar6 = FUN_004176a3(extraout_ECX_03,uVar3);
      DAT_0043d51c = 0;
      FUN_004152eb(extraout_ECX_04,(int)((ulonglong)uVar6 >> 0x20));
      local_38 = 1;
      uVar3 = extraout_ECX_05;
      uVar5 = extraout_EDX_02;
    }
    uVar6 = FUN_0041848a(uVar3,uVar5);
    DAT_0046239c = (int)uVar6;
    uVar6 = FUN_004182e8(extraout_ECX_08,(int)((ulonglong)uVar6 >> 0x20));
    DAT_004627ac = (undefined4)uVar6;
    DAT_00462398 = DAT_0046239c;
    for (local_38 = 0; (int)local_38 < 8; local_38 = local_38 + 1) {
      *(undefined4 *)(&DAT_0045a200 + local_38 * 4) = 0;
    }
    for (local_38 = 0; (int)local_38 < 8; local_38 = local_38 + 1) {
      pvVar1 = GlobalAlloc(0x2002,0x20);
      pvVar2 = GlobalLock(pvVar1);
      iVar4 = local_38 * 4;
      *(LPVOID *)(&DAT_0045a200 + iVar4) = pvVar2;
      uVar3 = extraout_ECX_09;
      local_3c = local_38;
      if (*(int *)(&DAT_0045a200 + local_38 * 4) == 0) goto LAB_0041882c;
      DAT_00462394 = 0x5735;
      pvVar1 = GlobalAlloc(0x2002,0x5735);
      pvVar2 = GlobalLock(pvVar1);
      **(undefined4 **)(&DAT_0045a200 + local_38 * 4) = pvVar2;
      if (**(int **)(&DAT_0045a200 + local_38 * 4) == 0) {
        pvVar1 = GlobalHandle(*(LPCVOID *)(&DAT_0045a200 + local_38 * 4));
        GlobalUnlock(pvVar1);
        pvVar1 = GlobalHandle(*(LPCVOID *)(&DAT_0045a200 + local_38 * 4));
        GlobalFree(pvVar1);
        *(undefined4 *)(&DAT_0045a200 + local_38 * 4) = 0;
        uVar3 = extraout_ECX_14;
        uVar5 = extraout_EDX_05;
        while (local_40 = local_38 + -1, -1 < local_40) {
          FUN_0041757d(uVar3,*(LPWAVEHDR *)(&DAT_0045a200 + local_40 * 4));
          pvVar1 = GlobalHandle((LPCVOID)**(undefined4 **)(&DAT_0045a200 + local_40 * 4));
          GlobalUnlock(pvVar1);
          pvVar1 = GlobalHandle((LPCVOID)**(undefined4 **)(&DAT_0045a200 + local_40 * 4));
          GlobalFree(pvVar1);
          pvVar1 = GlobalHandle(*(LPCVOID *)(&DAT_0045a200 + local_40 * 4));
          GlobalUnlock(pvVar1);
          pvVar1 = GlobalHandle(*(LPCVOID *)(&DAT_0045a200 + local_40 * 4));
          GlobalFree(pvVar1);
          *(undefined4 *)(&DAT_0045a200 + local_40 * 4) = 0;
          uVar3 = extraout_ECX_15;
          uVar5 = extraout_EDX_06;
          local_38 = local_40;
        }
        uVar6 = FUN_00429192(uVar3,uVar5);
        uVar6 = FUN_00429268(extraout_ECX_16,(int)((ulonglong)uVar6 >> 0x20),0x4db,
                             s__GAMMA_speakfre_sfmain_FRAME_c_004362dd,1,in_EAX,0x30,(LPCSTR)uVar6);
        FUN_00417664(extraout_ECX_17,(int)((ulonglong)uVar6 >> 0x20));
        local_1c = 0;
        goto LAB_00418bab;
      }
      uVar3 = extraout_ECX_13;
      if (DAT_00462394 < DAT_0046239c) {
        FUN_004296b9(s_currentInputLength__d_too_high__S_004362fc);
        DAT_0046239c = DAT_00462394;
        uVar3 = extraout_ECX_18;
      }
      *(int *)(*(int *)(&DAT_0045a200 + local_38 * 4) + 4) = DAT_0046239c;
      *(undefined4 *)(*(int *)(&DAT_0045a200 + local_38 * 4) + 0x10) = 0;
      *(undefined4 *)(*(int *)(&DAT_0045a200 + local_38 * 4) + 0x14) = 0;
      FUN_0041753a(uVar3,*(LPWAVEHDR *)(&DAT_0045a200 + local_38 * 4));
    }
    DAT_0043d67c = 8;
    for (local_38 = 0; (int)local_38 < 8; local_38 = local_38 + 1) {
      waveInAddBuffer(DAT_0043d514,*(LPWAVEHDR *)(&DAT_0045a200 + local_38 * 4),0x20);
    }
    DAT_0043d684 = 0;
    waveInStart(DAT_0043d514);
    DAT_0043d520 = 1;
    DAT_0043d6ac = DAT_0043d69c;
    DAT_004627a8 = _DAT_0043d6a8;
    FUN_004152eb(extraout_ECX_19,extraout_EDX_07);
  }
  local_1c = 1;
  goto LAB_00418bab;
LAB_0041882c:
  while (local_3c = local_3c + -1, -1 < local_3c) {
    FUN_0041757d(uVar3,*(LPWAVEHDR *)(&DAT_0045a200 + local_3c * 4));
    pvVar1 = GlobalHandle((LPCVOID)**(undefined4 **)(&DAT_0045a200 + local_3c * 4));
    GlobalUnlock(pvVar1);
    pvVar1 = GlobalHandle((LPCVOID)**(undefined4 **)(&DAT_0045a200 + local_3c * 4));
    GlobalFree(pvVar1);
    pvVar1 = GlobalHandle(*(LPCVOID *)(&DAT_0045a200 + local_3c * 4));
    GlobalUnlock(pvVar1);
    pvVar1 = GlobalHandle(*(LPCVOID *)(&DAT_0045a200 + local_3c * 4));
    GlobalFree(pvVar1);
    *(undefined4 *)(&DAT_0045a200 + local_3c * 4) = 0;
    uVar3 = extraout_ECX_10;
    iVar4 = extraout_EDX_04;
  }
  uVar6 = FUN_00429192(uVar3,iVar4);
  uVar6 = FUN_00429268(extraout_ECX_11,(int)((ulonglong)uVar6 >> 0x20),0x4b8,
                       s__GAMMA_speakfre_sfmain_FRAME_c_004362be,1,in_EAX,0x30,(LPCSTR)uVar6);
  FUN_00417664(extraout_ECX_12,(int)((ulonglong)uVar6 >> 0x20));
  local_1c = 0;
LAB_00418bab:
  return CONCAT44(param_2,local_1c);
}


