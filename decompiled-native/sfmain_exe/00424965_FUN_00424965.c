// 00424965 FUN_00424965 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_00424965(undefined4 param_1,int param_2)

{
  short sVar1;
  HWND in_EAX;
  HGLOBAL pvVar2;
  byte *pch;
  uint uVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  bool bVar4;
  undefined8 uVar5;
  int local_80;
  byte *local_7c;
  int local_78;
  short local_74;
  int local_70;
  byte *local_6c;
  byte *local_68;
  int local_64;
  byte *local_60;
  byte local_58;
  int local_54;
  byte *local_50;
  byte *local_4c;
  uint local_44;
  int local_40;
  uint local_30;
  uint local_2c;
  uint local_1c;
  int local_18;
  
  if (*(int *)(param_2 + 0x64c) == 0) {
    local_18 = 0;
  }
  else {
    uVar3 = *(uint *)(*(int *)(param_2 + 0x648) + 4);
    if (uVar3 < 0x2528) {
      local_2c = 8000;
    }
    else if (uVar3 < 0x4099) {
      local_2c = 0x2b11;
    }
    else if (uVar3 < 0x8133) {
      local_2c = 0x5622;
    }
    else {
      local_2c = 0xac44;
    }
    if (local_2c == 8000) {
      local_30 = DAT_004627ac * (uint)*(ushort *)(*(int *)(param_2 + 0x648) + 0xc);
    }
    else {
      local_30 = ((local_2c / 0x2b11) *
                 (uint)*(ushort *)(*(int *)(param_2 + 0x648) + 0xc) * DAT_004627ac * 0x2b11) / 8000;
    }
    pvVar2 = GlobalAlloc(0x40,local_30 * 2);
    pch = GlobalLock(pvVar2);
    if (pch == (byte *)0x0) {
      uVar5 = FUN_00429192(extraout_ECX,extraout_EDX);
      FUN_00429268(extraout_ECX_00,(int)((ulonglong)uVar5 >> 0x20),0x8e,
                   s__GAMMA_speakfre_sfmain_READWAVE__00437306,1,in_EAX,0x30,(LPCSTR)uVar5);
      local_18 = 0;
    }
    else {
      local_1c = mmioRead(*(HMMIO *)(param_2 + 0x644),(HPSTR)pch,local_30);
      if (local_1c == 0) {
        pvVar2 = GlobalHandle(pch);
        GlobalUnlock(pvVar2);
        pvVar2 = GlobalHandle(pch);
        GlobalFree(pvVar2);
        local_18 = 0;
      }
      else {
        bVar4 = (uint)*(ushort *)(*(int *)(param_2 + 0x648) + 0xc) /
                (uint)*(ushort *)(*(int *)(param_2 + 0x648) + 2) != 1;
        uVar3 = (uint)*(ushort *)(*(int *)(param_2 + 0x648) + 2);
        if (local_2c == 8000) {
          local_44 = 1;
        }
        else {
          local_44 = local_2c / 0x2b11;
        }
        if (bVar4) {
          local_40 = 2;
        }
        else {
          local_40 = 1;
        }
        local_1c = local_1c / (local_40 * local_44 * uVar3);
        if (((0x2b11 < local_2c) || (*(short *)(*(int *)(param_2 + 0x648) + 2) != 1)) || (bVar4)) {
          if (bVar4) {
            local_6c = pch;
            local_68 = pch;
            for (local_70 = 0; local_70 < (int)local_1c; local_70 = local_70 + 1) {
              local_74 = *(short *)local_68;
              if (1 < uVar3) {
                local_78 = (int)local_74;
                local_7c = local_68;
                for (local_80 = 1; local_7c = local_7c + 2, local_80 < (int)uVar3;
                    local_80 = local_80 + 1) {
                  local_78 = local_78 + *(short *)local_7c;
                }
                local_74 = (short)(local_78 / (int)uVar3);
              }
              *(short *)local_6c = local_74;
              local_68 = local_68 + local_44 * uVar3 * 2;
              local_6c = local_6c + 2;
            }
            local_1c = local_1c << 1;
          }
          else {
            local_50 = pch;
            local_4c = pch;
            for (local_54 = 0; local_54 < (int)local_1c; local_54 = local_54 + 1) {
              local_58 = *local_50;
              if (1 < uVar3) {
                sVar1 = local_58 - 0x80;
                local_60 = local_50;
                for (local_64 = 1; local_60 = local_60 + 1, local_64 < (int)uVar3;
                    local_64 = local_64 + 1) {
                  sVar1 = sVar1 + (*local_60 - 0x80);
                }
                local_58 = (char)((int)sVar1 / (int)uVar3) + 0x80;
              }
              *local_4c = local_58;
              local_50 = local_50 + local_44 * uVar3;
              local_4c = local_4c + 1;
            }
          }
        }
        if (local_2c != 8000) {
          local_2c = 0x2b11;
        }
        _DAT_0043d518 = 1;
        FUN_00413831(local_2c,local_1c & 0xffff);
        FUN_00410412(extraout_ECX_01,param_2);
        pvVar2 = GlobalHandle(pch);
        GlobalUnlock(pvVar2);
        pvVar2 = GlobalHandle(pch);
        GlobalFree(pvVar2);
        local_18 = (int)local_1c / (int)uVar3;
      }
    }
  }
  return local_18;
}


