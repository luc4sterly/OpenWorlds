// 00424715 FUN_00424715 [Global]
// program: sfmain.exe

undefined4 __fastcall FUN_00424715(undefined4 param_1,int param_2)

{
  DWORD cch;
  HWND in_EAX;
  HMMIO pHVar1;
  MMRESULT MVar2;
  HGLOBAL pvVar3;
  LPVOID pvVar4;
  uint uVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  LPSTR unaff_EBX;
  undefined8 uVar6;
  _MMCKINFO local_50;
  _MMCKINFO local_3c;
  int local_28;
  
  local_28 = param_2;
  pHVar1 = mmioOpenA(unaff_EBX,(LPMMIOINFO)0x0,0x10000);
  *(HMMIO *)(local_28 + 0x644) = pHVar1;
  if (*(int *)(local_28 + 0x644) == 0) {
    uVar6 = FUN_00429192(extraout_ECX,pHVar1);
    FUN_00429268(extraout_ECX_00,(int)((ulonglong)uVar6 >> 0x20),0x16,
                 s__GAMMA_speakfre_sfmain_READWAVE__004372e4,6,in_EAX,0x30,(LPCSTR)uVar6);
  }
  else {
    local_3c.fccType = 0x45564157;
    MVar2 = mmioDescend(*(HMMIO *)(local_28 + 0x644),&local_3c,(MMCKINFO *)0x0,0x20);
    if (MVar2 == 0) {
      local_50.ckid = 0x20746d66;
      MVar2 = mmioDescend(*(HMMIO *)(local_28 + 0x644),&local_50,&local_3c,0x10);
      cch = local_50.cksize;
      if (MVar2 == 0) {
        pvVar3 = GlobalAlloc(0x40,local_50.cksize & 0xffff);
        pvVar4 = GlobalLock(pvVar3);
        *(LPVOID *)(local_28 + 0x648) = pvVar4;
        if (*(int *)(local_28 + 0x648) == 0) {
          FUN_00429192(extraout_ECX_03,pvVar4);
        }
        else {
          uVar5 = mmioRead(*(HMMIO *)(local_28 + 0x644),*(HPSTR *)(local_28 + 0x648),cch);
          if (uVar5 == cch) {
            if (**(short **)(local_28 + 0x648) == 1) {
              mmioAscend(*(HMMIO *)(local_28 + 0x644),&local_50,0);
              local_50.ckid = 0x61746164;
              MVar2 = mmioDescend(*(HMMIO *)(local_28 + 0x644),&local_50,&local_3c,0x10);
              if (MVar2 == 0) {
                *(DWORD *)(local_28 + 0x64c) = local_50.cksize;
                if (*(int *)(local_28 + 0x64c) != 0) {
                  return 1;
                }
                FUN_00429192(extraout_ECX_05,local_28);
              }
              else {
                FUN_00429192(extraout_ECX_05,extraout_EDX_02);
              }
            }
            else {
              FUN_00429192(extraout_ECX_04,extraout_EDX_01);
            }
          }
          else {
            FUN_00429192(extraout_ECX_04,extraout_EDX_01);
          }
          pvVar3 = GlobalHandle(*(LPCVOID *)(local_28 + 0x648));
          GlobalUnlock(pvVar3);
          pvVar3 = GlobalHandle(*(LPCVOID *)(local_28 + 0x648));
          GlobalFree(pvVar3);
        }
      }
      else {
        FUN_00429192(extraout_ECX_02,extraout_EDX_00);
      }
    }
    else {
      FUN_00429192(extraout_ECX_01,extraout_EDX);
    }
    mmioClose(*(HMMIO *)(local_28 + 0x644),0);
    *(undefined4 *)(local_28 + 0x644) = 0;
  }
  return 0;
}


