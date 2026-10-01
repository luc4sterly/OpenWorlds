// 00418c25 FUN_00418c25 [Global]
// program: sfmain.exe

HWND __fastcall FUN_00418c25(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  HWND in_EAX;
  INT_PTR IVar2;
  BOOL BVar3;
  HWND pHVar4;
  HGLOBAL pvVar5;
  undefined4 *pMem;
  DWORD DVar6;
  int iVar7;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar8;
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
  int extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  char *unaff_EBX;
  undefined8 uVar9;
  uint local_54;
  undefined1 *local_3c;
  int local_34;
  uint local_14;
  
  if (param_2 == 0) {
    if (unaff_EBX == (char *)0x0) {
      IVar2 = FUN_004161bd(&local_14,&DAT_00462c26);
      if (IVar2 == 0) {
        return (HWND)0x0;
      }
    }
    else {
      FUN_0042c5c6(param_1,unaff_EBX);
      uVar9 = FUN_0042cbb3(extraout_ECX,'/');
      uVar8 = extraout_ECX_00;
      if (((int)uVar9 == 0) &&
         (uVar9 = FUN_0042cbb3(extraout_ECX_00,':'), uVar8 = extraout_ECX_01, (int)uVar9 == 0)) {
        local_14 = 0x81e;
        local_3c = (undefined1 *)0x0;
      }
      else {
        local_3c = (undefined1 *)uVar9;
        uVar9 = FUN_0042cbc7(uVar8,(int)((ulonglong)uVar9 >> 0x20));
        local_14 = (uint)uVar9;
        if ((int)local_14 < 1) {
          uVar9 = FUN_00429192(extraout_ECX_02,(int)((ulonglong)uVar9 >> 0x20));
          uVar9 = FUN_00429268(extraout_ECX_03,(int)((ulonglong)uVar9 >> 0x20),0x58b,
                               s__GAMMA_speakfre_sfmain_FRAME_c_00436328,0xd,in_EAX,0x10,
                               (LPCSTR)uVar9);
          return (HWND)uVar9;
        }
        *local_3c = 0;
      }
      local_34 = Ordinal_10(&DAT_00462d26);
      if (local_34 == -1) {
        iVar7 = Ordinal_52(local_3c);
        if (iVar7 == 0) {
          Ordinal_111();
          uVar9 = FUN_00429482(extraout_ECX_05,extraout_EDX);
          uVar9 = FUN_00429192(extraout_ECX_06,(int)((ulonglong)uVar9 >> 0x20));
          uVar9 = FUN_00429268(extraout_ECX_07,(int)((ulonglong)uVar9 >> 0x20),0x5a1,
                               s__GAMMA_speakfre_sfmain_FRAME_c_00436347,5,in_EAX,0x10,(LPCSTR)uVar9
                              );
          return (HWND)uVar9;
        }
        FUN_004080a4(extraout_ECX_04,(undefined1 *)**(undefined4 **)(iVar7 + 0xc));
        FUN_0042c5c6(extraout_ECX_08,&DAT_00462d26);
      }
      else {
        wsprintfA(&DAT_00462c26,&DAT_00436366,&DAT_00462d26);
      }
    }
  }
  uVar1 = Ordinal_9(local_14 & 0xffff);
  uVar9 = FUN_00417400(extraout_ECX_09,extraout_EDX_00);
  pHVar4 = (HWND)uVar9;
  if (pHVar4 == (HWND)0x0) {
    pvVar5 = GlobalAlloc(0x40,0x4f7c);
    pMem = GlobalLock(pvVar5);
    if (pMem == (undefined4 *)0x0) {
      uVar9 = FUN_00429268(extraout_ECX_10,extraout_EDX_01,0x61f,
                           s__GAMMA_speakfre_sfmain_FRAME_c_004363ba,1,(HWND)0x0,0x30,
                           s_Out_of_memory___line__d__004363a1);
      pHVar4 = (HWND)uVar9;
    }
    else {
      FUN_00408098(extraout_ECX_10,0);
      *pMem = 1;
      pMem[0x195] = 0;
      DVar6 = GetTickCount();
      pMem[0x197] = DVar6;
      pMem[0x198] = 0;
      *(undefined1 *)(pMem + 1) = 0;
      pMem[3] = 0xffffffff;
      pMem[2] = pMem[3];
      pMem[4] = 0xffffffff;
      pMem[0x1394] = 0;
      pMem[0x1395] = 0;
      pMem[6] = local_34;
      iVar7 = Ordinal_14(local_34);
      *(ushort *)((int)pMem + 0x4e42) = (ushort)(iVar7 == 0x7f000001);
      local_54 = (uint)(local_34 == 0);
      pMem[400] = local_54;
      pMem[0x4b] = 0xffffffff;
      pMem[0x130e] = 1;
      *(undefined1 *)(pMem + 0x4e) = 0;
      pMem[0x13d7] = 0;
      *(undefined2 *)(pMem + 0x1390) = 4;
      pMem[0x1392] = 0;
      pMem[0x1391] = pMem[0x1392];
      pMem[0x1396] = 0;
      *(undefined1 *)(pMem + 0x1397) = 0;
      uVar1 = Ordinal_15(uVar1);
      *(undefined2 *)(pMem + 9) = uVar1;
      pMem[10] = 0;
      FUN_004080a4(extraout_ECX_11,&DAT_0043636b);
      pMem[0x13db] = 0;
      FUN_0042c5c6(extraout_ECX_12,&DAT_00462c26);
      Ordinal_11(pMem[6],*(undefined2 *)(pMem + 9));
      FUN_004296b9(s_newConnection____Set_up_connecti_00436370);
      FUN_004296b9(s_createNewConnection_FALSE___d__s_004363f8);
      pHVar4 = FUN_0041093b(extraout_ECX_13,0);
      if (pHVar4 == (HWND)0x0) {
        pvVar5 = GlobalHandle(pMem);
        GlobalUnlock(pvVar5);
        pvVar5 = GlobalHandle(pMem);
        pHVar4 = GlobalFree(pvVar5);
        if (DAT_004623b0 != 0) {
          pHVar4 = (HWND)FUN_0042b0bf(extraout_ECX_14,1);
        }
      }
    }
  }
  else {
    BVar3 = IsIconic(pHVar4);
    if (BVar3 != 0) {
      SendMessageA(DAT_004627c8,0x223,(WPARAM)pHVar4,0);
    }
    BringWindowToTop(pHVar4);
    pHVar4 = (HWND)GetWindowLongA(pHVar4,0);
  }
  return pHVar4;
}


