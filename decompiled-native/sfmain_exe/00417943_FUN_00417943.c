// 00417943 FUN_00417943 [Global]
// programa: sfmain.exe

void __fastcall FUN_00417943(undefined4 param_1,int param_2)

{
  HWND in_EAX;
  int iVar1;
  HGLOBAL pvVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 uVar3;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 local_5c;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44 [4];
  int local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  HWND local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 *local_18;
  
  if (DAT_0043d728 < 1) {
    DAT_0043d728 = DAT_0043d728 + 1;
    local_28 = in_EAX;
    local_1c = param_2;
    if (param_2 != 0) {
      if (DAT_0043d59c == 0) {
        local_3c = DAT_0043d654;
        local_34 = Ordinal_21(DAT_0043d66c,0,4,&local_3c,4);
        if (local_34 != -1) {
          local_34 = Ordinal_21(DAT_0043d670,0,4,&local_3c,4);
        }
      }
      else {
        local_38[0] = (undefined1)DAT_0043d654;
        local_34 = Ordinal_21(DAT_0043d66c,0,4,local_38,1);
        if (local_34 != -1) {
          local_34 = Ordinal_21(DAT_0043d670,0,4,local_38,1);
        }
      }
      if ((local_34 == -1) && (local_40 = Ordinal_111(), local_40 == 0x273a)) {
        DAT_0043d658 = 1;
      }
      for (local_18 = DAT_0043d678; local_18 != (undefined4 *)0x0;
          local_18 = (undefined4 *)*local_18) {
        if (0 < *(short *)(local_18 + 1)) {
          if (DAT_0043d59c == 0) {
            local_48 = DAT_0043d654;
            local_34 = Ordinal_21(local_18[2],0,4,&local_48,4);
            if (local_34 != -1) {
              local_34 = Ordinal_21(local_18[3],0,4,&local_48,4);
            }
          }
          else {
            local_44[0] = (undefined1)DAT_0043d654;
            local_34 = Ordinal_21(local_18[2],0,4,local_44,1);
            if (local_34 != -1) {
              local_34 = Ordinal_21(local_18[3],0,4,local_44,1);
            }
          }
          if (local_34 != -1) {
            if (local_1c == 0) {
              local_4c = 6;
            }
            else {
              local_4c = 5;
            }
            local_20 = local_4c;
            local_2c = Ordinal_8(0);
            for (local_24 = 0; local_24 < DAT_0043d650; local_24 = local_24 + 1) {
              local_30 = *(undefined4 *)(&DAT_0045e3c0 + local_24 * 4);
              iVar1 = Ordinal_21(local_18[2],0,local_20,&local_30,8);
              if (iVar1 == -1) {
                uVar4 = Ordinal_111();
                uVar5 = FUN_00429482(extraout_ECX,(int)((ulonglong)uVar4 >> 0x20));
                Ordinal_11(*(undefined4 *)(&DAT_0045e3c0 + local_24 * 4),(int)uVar4,(int)uVar5);
                if (local_1c == 0) {
                  uVar4 = FUN_00429192(extraout_ECX_00,extraout_EDX);
                  uVar3 = extraout_ECX_02;
                }
                else {
                  uVar4 = FUN_00429192(extraout_ECX_00,extraout_EDX);
                  uVar3 = extraout_ECX_01;
                }
                uVar4 = FUN_00429192(uVar3,(int)((ulonglong)uVar4 >> 0x20));
                FUN_00429268(extraout_ECX_03,(int)((ulonglong)uVar4 >> 0x20),0x2d0,
                             s__GAMMA_speakfre_sfmain_FRAME_c_004361a9,8,local_28,0x10,(LPCSTR)uVar4
                            );
              }
              else {
                Ordinal_21(local_18[3],0,local_20,&local_30,8);
              }
            }
          }
        }
      }
    }
    if (local_1c == 0) {
      local_5c = 6;
    }
    else {
      local_5c = 5;
    }
    local_20 = local_5c;
    local_2c = Ordinal_8(0);
    for (local_24 = 0; local_24 < DAT_0043d650; local_24 = local_24 + 1) {
      local_30 = *(undefined4 *)(&DAT_0045e3c0 + local_24 * 4);
      iVar1 = Ordinal_21(DAT_0043d66c,0,local_20,&local_30,8);
      if (iVar1 == -1) {
        uVar4 = Ordinal_111();
        uVar5 = FUN_00429482(extraout_ECX_04,(int)((ulonglong)uVar4 >> 0x20));
        Ordinal_11(*(undefined4 *)(&DAT_0045e3c0 + local_24 * 4),(int)uVar4,(int)uVar5);
        if (local_1c == 0) {
          uVar4 = FUN_00429192(extraout_ECX_05,extraout_EDX_00);
          uVar3 = extraout_ECX_07;
        }
        else {
          uVar4 = FUN_00429192(extraout_ECX_05,extraout_EDX_00);
          uVar3 = extraout_ECX_06;
        }
        uVar4 = FUN_00429192(uVar3,(int)((ulonglong)uVar4 >> 0x20));
        FUN_00429268(extraout_ECX_08,(int)((ulonglong)uVar4 >> 0x20),0x2e8,
                     s__GAMMA_speakfre_sfmain_FRAME_c_004361c8,8,local_28,0x10,(LPCSTR)uVar4);
      }
      else {
        Ordinal_21(DAT_0043d670,0,local_20,&local_30,8);
      }
      if ((local_1c == 0) && (*(int *)(&DAT_0045e370 + local_24 * 4) != 0)) {
        pvVar2 = GlobalHandle(*(LPCVOID *)(&DAT_0045e370 + local_24 * 4));
        GlobalUnlock(pvVar2);
        pvVar2 = GlobalHandle(*(LPCVOID *)(&DAT_0045e370 + local_24 * 4));
        GlobalFree(pvVar2);
        *(undefined4 *)(&DAT_0045e370 + local_24 * 4) = 0;
      }
    }
    DAT_0043d728 = DAT_0043d728 + -1;
  }
  return;
}


