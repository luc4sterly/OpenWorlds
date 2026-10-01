// 0040fc24 FUN_0040fc24 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_0040fc24(undefined4 param_1,undefined4 param_2)

{
  short in_AX;
  short sVar1;
  HGLOBAL hMem;
  int iVar2;
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
  undefined4 uVar3;
  undefined4 extraout_ECX_11;
  undefined4 extraout_ECX_12;
  undefined4 extraout_ECX_13;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  undefined8 uVar4;
  undefined4 *local_28;
  undefined4 *local_24;
  short local_1c;
  
  for (local_28 = DAT_0043d678;
      (local_28 != (undefined4 *)0x0 && (in_AX != *(short *)((int)local_28 + 6)));
      local_28 = (undefined4 *)*local_28) {
  }
  if (local_28 == (undefined4 *)0x0) {
    hMem = GlobalAlloc(0x40,0x10);
    local_28 = GlobalLock(hMem);
    if (local_28 != (undefined4 *)0x0) {
      *local_28 = DAT_0043d678;
      DAT_0043d678 = local_28;
      *(undefined2 *)(local_28 + 1) = 0;
      *(short *)((int)local_28 + 6) = in_AX;
      local_28[3] = 0xffffffff;
      local_28[2] = local_28[3];
    }
  }
  if (local_28 != (undefined4 *)0x0) {
    if (*(short *)(local_28 + 1) == 0) {
      sVar1 = Ordinal_9(*(undefined2 *)((int)local_28 + 6));
      Ordinal_8(0);
      iVar2 = FUN_00429545(sVar1,2);
      local_1c = (short)iVar2;
      if (local_1c == 0) {
        sVar1 = Ordinal_9(*(short *)((int)local_28 + 6) + 1);
        Ordinal_8(0);
        iVar2 = FUN_00429545(sVar1,2);
        local_1c = (short)iVar2;
        if (local_1c == 0) {
          uVar4 = Ordinal_101(local_28[2],DAT_004627d0,0x464,1);
          iVar2 = (int)((ulonglong)uVar4 >> 0x20);
          uVar3 = extraout_ECX_05;
          if ((int)uVar4 != 0) {
            local_1c = Ordinal_111();
            uVar3 = extraout_ECX_06;
            iVar2 = extraout_EDX_01;
          }
          if (local_1c == 0) {
            uVar4 = Ordinal_101(local_28[3],DAT_004627d0,0x467,1);
            iVar2 = (int)((ulonglong)uVar4 >> 0x20);
            uVar3 = extraout_ECX_09;
            if ((int)uVar4 != 0) {
              local_1c = Ordinal_111();
              uVar3 = extraout_ECX_10;
              iVar2 = extraout_EDX_02;
            }
            if (local_1c == 0) {
              FUN_00417943(uVar3,0);
              FUN_00417943(extraout_ECX_13,1);
              goto LAB_0040fecd;
            }
            uVar4 = FUN_00429482(uVar3,iVar2);
            uVar4 = FUN_00429192(extraout_ECX_11,(int)((ulonglong)uVar4 >> 0x20));
            FUN_00429268(extraout_ECX_12,(int)((ulonglong)uVar4 >> 0x20),0x14e,
                         s__GAMMA_speakfre_sfmain_CONNECT_c_00435c48,3,(HWND)0x0,0x10,(LPCSTR)uVar4)
            ;
          }
          else {
            uVar4 = FUN_00429482(uVar3,iVar2);
            uVar4 = FUN_00429192(extraout_ECX_07,(int)((ulonglong)uVar4 >> 0x20));
            FUN_00429268(extraout_ECX_08,(int)((ulonglong)uVar4 >> 0x20),0x144,
                         s__GAMMA_speakfre_sfmain_CONNECT_c_00435c27,3,(HWND)0x0,0x10,(LPCSTR)uVar4)
            ;
          }
        }
        else {
          uVar4 = FUN_00429482(extraout_ECX_02,extraout_EDX_00);
          uVar4 = FUN_00429192(extraout_ECX_03,(int)((ulonglong)uVar4 >> 0x20));
          FUN_00429268(extraout_ECX_04,(int)((ulonglong)uVar4 >> 0x20),0x13a,
                       s__GAMMA_speakfre_sfmain_CONNECT_c_00435c06,3,(HWND)0x0,0x10,(LPCSTR)uVar4);
        }
      }
      else {
        uVar4 = FUN_00429482(extraout_ECX,extraout_EDX);
        uVar4 = FUN_00429192(extraout_ECX_00,(int)((ulonglong)uVar4 >> 0x20));
        FUN_00429268(extraout_ECX_01,(int)((ulonglong)uVar4 >> 0x20),0x133,
                     s__GAMMA_speakfre_sfmain_CONNECT_c_00435be5,3,(HWND)0x0,0x10,(LPCSTR)uVar4);
      }
      if (local_28[2] != -1) {
        Ordinal_3(local_28[2]);
        local_28[2] = 0xffffffff;
      }
      if (local_28[3] != -1) {
        Ordinal_3(local_28[3]);
        local_28[3] = 0xffffffff;
      }
      local_24 = (undefined4 *)0x0;
      goto LAB_0040ff1f;
    }
LAB_0040fecd:
    *(short *)(local_28 + 1) = *(short *)(local_28 + 1) + 1;
  }
  local_24 = local_28;
LAB_0040ff1f:
  return CONCAT44(param_2,local_24);
}


