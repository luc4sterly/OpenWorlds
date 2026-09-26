// 0041093b FUN_0041093b [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HWND __fastcall FUN_0041093b(undefined4 param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
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
  undefined4 extraout_ECX_20;
  undefined4 extraout_ECX_21;
  undefined4 extraout_ECX_22;
  undefined4 extraout_ECX_23;
  undefined4 extraout_ECX_24;
  undefined4 extraout_ECX_25;
  undefined4 extraout_ECX_26;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  int extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined8 uVar6;
  undefined8 uVar7;
  LPCSTR local_60;
  int local_54;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  int local_2c;
  int local_28;
  HWND local_24;
  int local_20;
  int local_1c;
  
  local_20 = 0;
  local_2c = param_2;
  local_28 = in_EAX;
  iVar1 = GetSystemMetrics(0x21);
  iVar2 = GetSystemMetrics(4);
  local_1c = iVar2 + iVar1 * 2 + -1;
  local_50 = _DAT_004b2be4;
  if (*(short *)(local_28 + 0x4e42) == 0) {
    local_54 = local_28 + 0x2c;
  }
  else {
    uVar6 = FUN_00429192(extraout_ECX,extraout_EDX);
    local_54 = (int)uVar6;
  }
  local_4c = local_54;
  local_48 = DAT_004627bc;
  local_44 = 0x80000000;
  local_40 = 0x80000000;
  local_3c = DAT_004627b4 * 0x23;
  local_38 = local_1c + DAT_004627c4 * 4 + 5;
  local_34 = 0;
  local_24 = (HWND)SendMessageA(DAT_004627c8,0x220,0,(LPARAM)&local_50);
  if (local_24 == (HWND)0x0) {
    return (HWND)0x0;
  }
  *(undefined1 *)(local_28 + 4) = 1;
  SetWindowLongA(local_24,0,local_28);
  uVar6 = CONCAT44(extraout_EDX_00,local_20);
  uVar3 = extraout_ECX_00;
  if (*(int *)(local_28 + 0x640) == 0) {
    if (local_2c == 0) {
      FUN_004138b3(extraout_ECX_00,extraout_EDX_00);
    }
    Ordinal_8(0);
    local_20 = FUN_00429545(0,2);
    uVar6 = CONCAT44(extraout_EDX_01,local_20);
    uVar3 = extraout_ECX_01;
    if (local_20 == 0) {
      uVar7 = Ordinal_101(*(undefined4 *)(local_28 + 8),local_24,0x464,2);
      uVar6 = CONCAT44((int)((ulonglong)uVar7 >> 0x20),local_20);
      uVar3 = extraout_ECX_02;
      if ((int)uVar7 != 0) {
        uVar6 = Ordinal_111();
        uVar3 = extraout_ECX_03;
      }
      local_20 = (int)uVar6;
      if (local_20 == 0) {
        *(undefined2 *)(local_28 + 0x664) = 2;
        *(undefined4 *)(local_28 + 0x668) = *(undefined4 *)(local_28 + 0x18);
        uVar3 = Ordinal_9(*(undefined2 *)(local_28 + 0x24));
        uVar6 = CONCAT44(uVar3,local_20);
        *(short *)(local_28 + 0x666) = (short)uVar3;
        uVar3 = extraout_ECX_04;
        if (DAT_0043d594 == 0) {
          uVar7 = Ordinal_4(*(undefined4 *)(local_28 + 8),local_28 + 0x664,0x10);
          uVar6 = CONCAT44((int)((ulonglong)uVar7 >> 0x20),local_20);
          uVar3 = extraout_ECX_05;
          if ((int)uVar7 != 0) {
            uVar6 = Ordinal_111();
            uVar3 = extraout_ECX_06;
          }
        }
      }
    }
    local_20 = (int)uVar6;
    if (local_20 != 0) {
      uVar6 = FUN_00429482(uVar3,(int)((ulonglong)uVar6 >> 0x20));
      uVar6 = FUN_00429192(extraout_ECX_07,(int)((ulonglong)uVar6 >> 0x20));
      FUN_00429268(extraout_ECX_08,(int)((ulonglong)uVar6 >> 0x20),0x3d7,
                   s__GAMMA_speakfre_sfmain_CONNECT_c_00435d69,3,local_24,0x10,(LPCSTR)uVar6);
      return (HWND)0x0;
    }
    Ordinal_8(0);
    local_20 = FUN_00429545(0,2);
    uVar6 = CONCAT44(extraout_EDX_02,local_20);
    uVar3 = extraout_ECX_09;
    if (local_20 == 0) {
      uVar7 = Ordinal_101(*(undefined4 *)(local_28 + 8),local_24,0x467,2);
      uVar6 = CONCAT44((int)((ulonglong)uVar7 >> 0x20),local_20);
      uVar3 = extraout_ECX_10;
      if ((int)uVar7 != 0) {
        uVar6 = Ordinal_111();
        uVar3 = extraout_ECX_11;
      }
      local_20 = (int)uVar6;
      if (local_20 == 0) {
        *(undefined2 *)(local_28 + 0x674) = 2;
        *(undefined4 *)(local_28 + 0x678) = *(undefined4 *)(local_28 + 0x18);
        uVar3 = Ordinal_9(*(short *)(local_28 + 0x24) + 1);
        uVar6 = CONCAT44(uVar3,local_20);
        *(short *)(local_28 + 0x676) = (short)uVar3;
        uVar3 = extraout_ECX_12;
        if (DAT_0043d594 == 0) {
          uVar7 = Ordinal_4(*(undefined4 *)(local_28 + 0xc),local_28 + 0x674,0x10);
          uVar6 = CONCAT44((int)((ulonglong)uVar7 >> 0x20),local_20);
          uVar3 = extraout_ECX_13;
          if ((int)uVar7 != 0) {
            uVar6 = Ordinal_111();
            uVar3 = extraout_ECX_14;
          }
        }
      }
    }
    iVar1 = (int)((ulonglong)uVar6 >> 0x20);
    local_20 = (int)uVar6;
    if (local_20 != 0) {
      uVar6 = FUN_00429482(uVar3,iVar1);
      uVar6 = FUN_00429192(extraout_ECX_15,(int)((ulonglong)uVar6 >> 0x20));
      FUN_00429268(extraout_ECX_16,(int)((ulonglong)uVar6 >> 0x20),0x3f9,
                   s__GAMMA_speakfre_sfmain_CONNECT_c_00435d8a,3,local_24,0x10,(LPCSTR)uVar6);
      return (HWND)0x0;
    }
    if (*(short *)(local_28 + 0x24) != 0x81e) {
      uVar7 = FUN_0040fc24(uVar3,iVar1);
      uVar6 = CONCAT44((int)uVar7,local_20);
      *(int *)(local_28 + 0x28) = (int)uVar7;
      uVar3 = extraout_ECX_17;
    }
  }
  local_20 = (int)uVar6;
  uVar6 = FUN_004078ca(uVar3,(int)((ulonglong)uVar6 >> 0x20));
  *(int *)(local_28 + 0x4d58) = (int)uVar6;
  *(undefined4 *)(local_28 + 0x4e3c) = 0xffffffff;
  Ordinal_57(&DAT_00459a55,0x100);
  uVar4 = FUN_0042c5ad();
  if (0xf < uVar4) {
    DAT_00459a64 = 0;
  }
  FUN_0042c5c6(extraout_ECX_18,&DAT_00459a55);
  FUN_0042c5c6(extraout_ECX_19,&DAT_00445b40);
  if ((*(char *)(local_28 + 0x2c) == '(') && (*(short *)(local_28 + 0x4e42) == 0)) {
    if (DAT_0043d5ac == 0) {
      uVar3 = Ordinal_102(local_24,0x465,local_28 + 0x18,4,2,local_28 + 0x240,0x400);
      *(undefined4 *)(local_28 + 0x23c) = uVar3;
      if (*(int *)(local_28 + 0x23c) == 0) {
        Ordinal_111();
        uVar6 = FUN_00429482(extraout_ECX_20,extraout_EDX_03);
        uVar6 = FUN_00429192(extraout_ECX_21,(int)((ulonglong)uVar6 >> 0x20));
        FUN_00429268(extraout_ECX_22,(int)((ulonglong)uVar6 >> 0x20),0x43f,
                     s__GAMMA_speakfre_sfmain_CONNECT_c_00435dab,5,local_24,0x10,(LPCSTR)uVar6);
      }
    }
    else {
      puVar5 = (undefined4 *)Ordinal_51(local_28 + 0x18,4,2);
      if (puVar5 != (undefined4 *)0x0) {
        FUN_0042c5c6(extraout_ECX_23,(char *)*puVar5);
        if (*(short *)(local_28 + 0x4e42) == 0) {
          local_60 = (LPCSTR)(local_28 + 0x2c);
        }
        else {
          uVar6 = FUN_00429192(extraout_ECX_24,extraout_EDX_04);
          local_60 = (LPCSTR)uVar6;
        }
        SetWindowTextA(local_24,local_60);
        FUN_004102eb(extraout_ECX_25,local_28);
      }
      *(undefined4 *)(local_28 + 0x23c) = 0;
    }
  }
  DragAcceptFiles(local_24,1);
  ShowWindow(local_24,5);
  DAT_0043d528 = DAT_0043d528 + 1;
  FUN_004152eb(extraout_ECX_26,extraout_EDX_05);
  SendMessageA(local_24,0x102,0x20,0);
  return local_24;
}


