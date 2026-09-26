// 004264cf FUN_004264cf [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004264cf(int param_1,int param_2,int param_3)

{
  undefined2 *puVar1;
  char *pcVar2;
  byte *pbVar3;
  HGLOBAL pvVar4;
  LPWAVEHDR pwh;
  LPSTR pCVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 uVar6;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined4 extraout_ECX_09;
  undefined4 extraout_ECX_10;
  undefined4 extraout_ECX_11;
  undefined4 extraout_ECX_12;
  undefined4 extraout_ECX_13;
  undefined4 extraout_ECX_14;
  undefined4 extraout_ECX_15;
  int iVar7;
  undefined4 extraout_EDX;
  byte *unaff_EBX;
  char *local_60;
  char *local_58;
  int local_48;
  undefined2 *local_44;
  undefined2 local_40;
  int local_3c;
  undefined2 *local_38;
  LPSTR local_20;
  byte *local_1c;
  uint local_18;
  SIZE_T local_14;
  byte *local_10;
  
  iVar7 = DAT_0043d6cc * 3 >> 0x1f;
  if (DAT_0043d538 < (int)((DAT_0043d6cc * 3 + iVar7 * -4) - (uint)(iVar7 << 1 < 0)) >> 2) {
    if ((DAT_0043d668 < 1) || (DAT_0043d538 <= DAT_0043d668)) {
      pvVar4 = GlobalAlloc(0x2002,0x20);
      pwh = GlobalLock(pvVar4);
      if (pwh != (LPWAVEHDR)0x0) {
        local_14 = *(SIZE_T *)(unaff_EBX + 0x14);
        local_10 = unaff_EBX + 0x1c;
        uVar6 = extraout_ECX;
        if (((DAT_0043d5ec != 0) && ((*unaff_EBX & 4) != 0)) && ((*unaff_EBX & 8) == 0)) {
          waveOutSetVolume(DAT_0043d510,0xffffffff);
          uVar6 = extraout_ECX_00;
        }
        if ((*unaff_EBX & 0x20) != 0) {
          FUN_004261a5();
          local_14 = *(SIZE_T *)(unaff_EBX + 0x14);
          uVar6 = extraout_ECX_01;
        }
        if ((unaff_EBX[1] & 2) != 0) {
          FUN_004262fe();
          local_14 = *(SIZE_T *)(unaff_EBX + 0x14);
          uVar6 = extraout_ECX_02;
        }
        if ((unaff_EBX[1] & 0x10) != 0) {
          FUN_0042638b();
          local_14 = *(SIZE_T *)(unaff_EBX + 0x14);
          uVar6 = extraout_ECX_03;
        }
        if ((unaff_EBX[2] & 2) != 0) {
          FUN_00426442(uVar6);
          local_14 = *(SIZE_T *)(unaff_EBX + 0x14);
          uVar6 = extraout_ECX_04;
        }
        if ((*unaff_EBX & 1) != 0) {
          local_38 = (undefined2 *)&DAT_004bf5d6;
          for (local_3c = 0; local_3c < (int)local_14; local_3c = local_3c + 1) {
            if (local_3c == 0) {
              local_40 = (undefined2)((uint)*(undefined4 *)((uint)*local_10 * 2 + 0x426f90) >> 0x10)
              ;
            }
            else {
              local_40 = (undefined2)
                         (((*(int *)((uint)*local_10 * 2 + 0x426f90) >> 0x10) +
                          (*(int *)((uint)local_10[-1] * 2 + 0x426f90) >> 0x10)) / 2);
            }
            puVar1 = local_38 + 1;
            *local_38 = local_40;
            local_38 = local_38 + 2;
            *puVar1 = *(undefined2 *)(&DAT_00426f92 + (uint)*local_10 * 2);
            local_10 = local_10 + 1;
          }
          local_14 = local_14 << 1;
          FUN_0042b6f6(uVar6);
          for (local_3c = 0; local_3c < (int)local_14; local_3c = local_3c + 1) {
            *(undefined1 *)(local_3c + 0x4bb68c) =
                 (&DAT_00427192)[(int)(uint)*(ushort *)(&DAT_004bf5d6 + local_3c * 2) >> 3];
          }
          FUN_004080a4(extraout_ECX_05,(undefined1 *)0x4bb68c);
          *(SIZE_T *)(unaff_EBX + 0x14) = local_14;
          uVar6 = extraout_ECX_06;
        }
        if ((unaff_EBX[2] & 8) != 0) {
          _DAT_004bf5d6 = *(undefined2 *)(&DAT_00426f92 + (uint)*local_10 * 2);
          _DAT_004bf5d8 = *(undefined2 *)(&DAT_00426f92 + (uint)*local_10 * 2);
          local_44 = (undefined2 *)&DAT_004bf5dc;
          _DAT_004bf5da = *(undefined2 *)(&DAT_00426f92 + (uint)*local_10 * 2);
          pbVar3 = local_10;
          for (local_48 = 1; local_10 = pbVar3 + 1, local_48 < (int)local_14;
              local_48 = local_48 + 1) {
            *local_44 = (short)(((*(int *)((uint)*pbVar3 * 2 + 0x426f90) >> 0x10) * 2 +
                                (*(int *)((uint)*local_10 * 2 + 0x426f90) >> 0x10)) / 3);
            puVar1 = local_44 + 2;
            local_44[1] = (short)(((*(int *)((uint)*local_10 * 2 + 0x426f90) >> 0x10) * 2 +
                                  (*(int *)((uint)*pbVar3 * 2 + 0x426f90) >> 0x10)) / 3);
            local_44 = local_44 + 3;
            *puVar1 = *(undefined2 *)(&DAT_00426f92 + (uint)*local_10 * 2);
            pbVar3 = local_10;
          }
          local_14 = local_14 * 3;
          FUN_0042b74c(uVar6);
          for (local_48 = 0; local_48 < (int)local_14; local_48 = local_48 + 1) {
            local_10[local_48] =
                 (&DAT_00427192)[(int)(uint)*(ushort *)(&DAT_004bf5d6 + local_48 * 2) >> 3];
          }
          *(SIZE_T *)(unaff_EBX + 0x14) = local_14;
          uVar6 = extraout_ECX_07;
        }
        FUN_004135f9(uVar6,local_14);
        uVar6 = extraout_ECX_08;
        if ((DAT_0043d5d4 == 0) && (param_3 == 0x2b11)) {
          if (param_1 == 0x10) {
            pvVar4 = GlobalAlloc(0x2002,0xbdd8);
            pCVar5 = GlobalLock(pvVar4);
            pwh->lpData = pCVar5;
            if (pwh->lpData == (LPSTR)0x0) {
              pvVar4 = GlobalHandle(pwh);
              GlobalUnlock(pvVar4);
              pvVar4 = GlobalHandle(pwh);
              GlobalFree(pvVar4);
              return;
            }
            local_20 = pwh->lpData;
            local_1c = local_10;
            for (local_18 = 0; (int)local_18 < (int)local_14; local_18 = local_18 + 1) {
              pCVar5 = local_20 + 2;
              *(undefined2 *)local_20 = *(undefined2 *)(&DAT_00426f92 + (uint)*local_1c * 2);
              if (((local_18 & 7) == 0) || ((local_18 & 1) != 0)) {
                if ((int)local_18 % 0x140 == 0x13f) {
                  *(undefined2 *)pCVar5 = *(undefined2 *)(&DAT_00426f92 + (uint)*local_1c * 2);
                  pCVar5 = local_20 + 4;
                }
              }
              else {
                *(undefined2 *)pCVar5 = *(undefined2 *)(&DAT_00426f92 + (uint)*local_1c * 2);
                pCVar5 = local_20 + 4;
              }
              local_20 = pCVar5;
              local_1c = local_1c + 1;
            }
            pwh->dwBytesRecorded = (int)local_20 - (int)pwh->lpData;
            pwh->dwBufferLength = pwh->dwBytesRecorded;
            uVar6 = extraout_ECX_09;
            if (0xbdd8 < pwh->dwBufferLength) {
              FUN_00429268(extraout_ECX_09,pwh->dwBytesRecorded,0x185,
                           s__GAMMA_speakfre_sfmain_SPEAKER_c_0043739d,2,(HWND)0x0,0,
                           s_Program_error__0043738e);
              uVar6 = extraout_ECX_10;
            }
          }
          else if (param_1 == 8) {
            pvVar4 = GlobalAlloc(0x2002,0x5eec);
            pCVar5 = GlobalLock(pvVar4);
            pwh->lpData = pCVar5;
            if (pwh->lpData == (LPSTR)0x0) {
              pvVar4 = GlobalHandle(pwh);
              GlobalUnlock(pvVar4);
              pvVar4 = GlobalHandle(pwh);
              GlobalFree(pvVar4);
              return;
            }
            local_58 = pwh->lpData;
            local_1c = local_10;
            for (local_18 = 0; (int)local_18 < (int)local_14; local_18 = local_18 + 1) {
              pcVar2 = local_58 + 1;
              *local_58 = (char)((ushort)*(undefined2 *)(&DAT_00426f92 + (uint)*local_1c * 2) >> 8)
                          + -0x80;
              if (((local_18 & 7) == 0) || ((local_18 & 1) != 0)) {
                if ((int)local_18 % 0x140 == 0x13f) {
                  *pcVar2 = (char)((ushort)*(undefined2 *)(&DAT_00426f92 + (uint)*local_1c * 2) >> 8
                                  ) + -0x80;
                  pcVar2 = local_58 + 2;
                }
              }
              else {
                *pcVar2 = (char)((ushort)*(undefined2 *)(&DAT_00426f92 + (uint)*local_1c * 2) >> 8)
                          + -0x80;
                pcVar2 = local_58 + 2;
              }
              local_58 = pcVar2;
              local_1c = local_1c + 1;
            }
            pwh->dwBytesRecorded = (int)local_58 - (int)pwh->lpData;
            pwh->dwBufferLength = pwh->dwBytesRecorded;
            uVar6 = extraout_ECX_11;
            if (0x5eec < pwh->dwBufferLength) {
              FUN_00429268(extraout_ECX_11,pwh->dwBytesRecorded,0x1a6,
                           s__GAMMA_speakfre_sfmain_SPEAKER_c_004373be,2,(HWND)0x0,0,
                           s_Program_error__0043738e);
              uVar6 = extraout_ECX_12;
            }
          }
        }
        else if (param_1 == 0x10) {
          pvVar4 = GlobalAlloc(0x2002,local_14 * 2);
          pCVar5 = GlobalLock(pvVar4);
          pwh->lpData = pCVar5;
          if (pwh->lpData == (LPSTR)0x0) {
            pvVar4 = GlobalHandle(pwh);
            GlobalUnlock(pvVar4);
            pvVar4 = GlobalHandle(pwh);
            GlobalFree(pvVar4);
            return;
          }
          local_1c = local_10;
          local_20 = pwh->lpData;
          for (local_18 = 0; (int)local_18 < (int)local_14; local_18 = local_18 + 1) {
            *(undefined2 *)local_20 = *(undefined2 *)(&DAT_00426f92 + (uint)*local_1c * 2);
            local_20 = local_20 + 2;
            local_1c = local_1c + 1;
          }
          pwh->dwBytesRecorded = (int)local_20 - (int)pwh->lpData;
          pwh->dwBufferLength = pwh->dwBytesRecorded;
          uVar6 = extraout_ECX_13;
        }
        else if (param_1 == 8) {
          pvVar4 = GlobalAlloc(0x2002,local_14);
          pCVar5 = GlobalLock(pvVar4);
          pwh->lpData = pCVar5;
          if (pwh->lpData == (LPSTR)0x0) {
            pvVar4 = GlobalHandle(pwh);
            GlobalUnlock(pvVar4);
            pvVar4 = GlobalHandle(pwh);
            GlobalFree(pvVar4);
            return;
          }
          local_1c = local_10;
          local_60 = pwh->lpData;
          for (local_18 = 0; (int)local_18 < (int)local_14; local_18 = local_18 + 1) {
            *local_60 = (char)((ushort)*(undefined2 *)(&DAT_00426f92 + (uint)*local_1c * 2) >> 8) +
                        -0x80;
            local_60 = local_60 + 1;
            local_1c = local_1c + 1;
          }
          pwh->dwBytesRecorded = (int)local_60 - (int)pwh->lpData;
          pwh->dwBufferLength = pwh->dwBytesRecorded;
          uVar6 = extraout_ECX_14;
        }
        if ((unaff_EBX[3] & 2) == 0) {
          FUN_0040d86b(uVar6,(LPCSTR)(param_2 + 0x2c));
        }
        pwh->dwFlags = 0;
        pwh->dwLoops = 0;
        waveOutPrepareHeader(DAT_0043d510,pwh,0x20);
        if ((((DAT_0043d660 != 0) && (2 < DAT_0043d668)) && (DAT_0043d668 + -2 <= DAT_0043d538)) ||
           (DAT_0043d6cc / 2 <= DAT_0043d538)) {
          FUN_004296b9(s_Restarting_output_early____outpu_004373df);
          DAT_0043d660 = 0;
          FUN_00417787(extraout_ECX_15,extraout_EDX);
        }
        FUN_00426e75(0,pwh);
      }
    }
    else {
      DAT_0043d53c = DAT_0043d53c + 1;
      FUN_004173ab(param_1,DAT_0043d53c);
    }
  }
  else {
    DAT_0043d53c = DAT_0043d53c + 1;
    FUN_004173ab(param_1,DAT_0043d53c);
  }
  return;
}


