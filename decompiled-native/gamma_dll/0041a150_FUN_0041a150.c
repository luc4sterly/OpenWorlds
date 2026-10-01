// 0041a150 FUN_0041a150 [Global]
// program: gamma.dll

void FUN_0041a150(void)

{
  byte bVar1;
  HMODULE pHVar2;
  int iVar3;
  HDC hdc;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  byte *pbVar8;
  void *this;
  int *piVar9;
  byte *pbVar10;
  undefined4 uVar11;
  char *extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  bool bVar12;
  undefined8 uVar13;
  byte *pbVar14;
  undefined4 uVar15;
  char *pcVar16;
  byte *pbVar17;
  int local_8bc;
  int local_8b8;
  int local_8b0;
  byte local_8ac [4];
  char local_8a8;
  int local_85c;
  undefined4 *local_858;
  char local_854 [1024];
  char local_454 [1024];
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34 [2];
  undefined1 local_29;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  pHVar2 = LoadLibraryA(s_RWL21_DLL_00470418);
  if (pHVar2 == (HMODULE)0x0) {
    FUN_00402800(s_tsrwlib_00470424,0x741);
  }
  RwInitialize(0);
  iVar3 = FUN_004010c0(s_debugRenderWare_0047042c,0);
  if (iVar3 == 0) {
    uVar15 = 1;
  }
  else {
    RwSetDebugOutputState(1);
    RwOpenDebugStream(s___rw_log_0047043c);
    if (iVar3 == 1) {
      uVar15 = 3;
    }
    else if (iVar3 == 2) {
      uVar15 = 2;
    }
    else {
      uVar15 = 1;
    }
    RwSetDebugSeverity(uVar15);
    uVar15 = 2;
  }
  RwSetDebugOutputState(uVar15);
  local_8b0 = 0x10;
  hdc = GetDC((HWND)0x0);
  if (hdc != (HDC)0x0) {
    iVar3 = GetDeviceCaps(hdc,0xe);
    if ((iVar3 == 1) && (uVar4 = GetDeviceCaps(hdc,0x26), (uVar4 & 0x100) != 0)) {
      local_8b0 = 8;
    }
    ReleaseDC((HWND)0x0,hdc);
  }
  iVar3 = FUN_00417870();
  pcVar16 = extraout_ECX;
  uVar15 = extraout_EDX;
  if (iVar3 != 0) {
    pcVar16 = s_Hardware_rendering_is_not_availa_00470448;
    FUN_0044d5a0(s_Hardware_rendering_is_not_availa_00470448);
    uVar15 = extraout_EDX_00;
  }
  uVar13 = FUN_0041a0e0(pcVar16,uVar15);
  iVar5 = (int)uVar13;
  if (iVar5 == 0) {
    FUN_00402800(s_tsrwlib_00470424,0x77a);
  }
  local_8b8 = 0;
  if ((iVar3 == 0) && (iVar3 = FUN_004010c0(s_DisableHardwareAcceleration_00470484,0), iVar3 == 0))
  {
    local_8bc = 1;
    iVar3 = RwExtract(iVar5,1,local_8ac,0x50);
    while (iVar3 != 0) {
      iVar3 = FUN_00450930(local_8ac,(byte *)s_rwdld_004704a0,5);
      if (iVar3 == 0) {
        FUN_0043c8f0((byte *)s_IDS_EVALUATING_HARDWARE_004704a8);
        FUN_0044d5a0(s__s__s_004704c0);
        uVar13 = FUN_0041a110(extraout_ECX_00,extraout_EDX_01,local_8ac);
        iVar3 = (int)uVar13;
        if (iVar3 == 0) {
          FUN_0043c8f0((byte *)s_IDS_ERROR_DISPLAY_DEVICE_004704c8);
          FUN_0044d5a0(&DAT_004704e4);
        }
        else {
          local_85c = 0;
          RwGetDeviceInfo(0xc,&local_85c,4);
          if (((((local_85c == 0) || (*(int *)(local_85c + 0x68) != 0x80)) ||
               (*(int *)(local_85c + 0x60) != local_8b0)) ||
              (((*(uint *)(local_85c + 0x78) & 4) == 0 ||
               ((*(uint *)(local_85c + 0x78) & 0x200) != 0)))) || (*(int *)(local_85c + 0xd4) == 0))
          {
LAB_0041a526:
            RwCloseDisplayDevice(iVar3);
          }
          else {
            iVar6 = RwStartDisplayDevice(iVar3,0);
            if (iVar6 == 0) {
              RwCloseDisplayDevice(iVar3);
              FUN_0044d5a0(s_Could_not_start_the_hardware_dis_004704e8);
            }
            else {
              local_858 = (undefined4 *)0x0;
              RwDeviceControl(0x450,0,&local_858,4);
              iVar6 = FUN_00417430(local_858);
              if (iVar6 != 0) {
                DAT_0048957c = 1;
                iVar6 = FUN_004010c0(s_UserEnabled3DHardware_00470530,0);
                if (iVar6 == 0) {
                  FUN_0043c8f0((byte *)s_IDS_NOT_USER_ENABLED_00470548);
                  FUN_0044d5a0(&DAT_004704e4);
                  iVar6 = FUN_004010c0(s_Displayed3DMessage_00470560,0);
                  if (iVar6 == 0) {
                    FUN_004010e0(s_Displayed3DMessage_00470560);
                    pbVar8 = FUN_0043c8f0((byte *)s_IDS_DISPLAYED3DMESSAGE_00470574);
                    FUN_0044d6b0(local_854,(char *)pbVar8);
                    pbVar8 = FUN_0043c8f0((byte *)s_IDS_3DHARDWARE_0047058c);
                    FUN_0044d6b0(local_454,(char *)pbVar8);
                    MessageBoxA((HWND)0x0,local_854,local_454,0x40);
                  }
                  RwStopDisplayDevice(iVar3);
                  goto LAB_0041a526;
                }
                local_8b8 = 1;
                DAT_00489578 = 1;
                FUN_0043c8f0((byte *)s_IDS_USING_HARDWARE_DRIVER_0047059c);
                FUN_0044d5a0(s__s__s_004704c0);
                break;
              }
              RwStopDisplayDevice(iVar3);
              RwCloseDisplayDevice(iVar3);
              FUN_0043c8f0((byte *)s_IDS_3D_DEVICE_REJECTED_00470518);
              FUN_0044d5a0(&DAT_004704e4);
            }
          }
        }
      }
      local_8bc = local_8bc + 1;
      iVar3 = RwExtract(iVar5,local_8bc,local_8ac,0x50);
    }
  }
  iVar3 = FUN_004010c0(s_forceMMX_004705b8,0);
  bVar12 = iVar3 == 1;
  if (((local_8b8 == 0) && (iVar3 = FUN_004010c0(s_disableMMX_004705c4,0), iVar3 == 0)) &&
     ((puVar7 = FUN_00455b40(0), puVar7 == (undefined *)0x2 &&
      (puVar7 = FUN_00455b40(0x17), puVar7 != (undefined *)0x0)))) {
    bVar12 = true;
  }
  if (bVar12) {
    iVar3 = 1;
    uVar13 = RwExtract(iVar5,1,local_8ac,0x50);
    uVar15 = extraout_ECX_01;
    while ((int)uVar13 != 0) {
      if ((local_8a8 == 'M') || (local_8a8 == 'm')) {
        uVar13 = FUN_0041a110(uVar15,(int)((ulonglong)uVar13 >> 0x20),local_8ac);
        iVar6 = (int)uVar13;
        if (iVar6 != 0) {
          local_54 = 0;
          RwGetDeviceInfo(0xc,&local_54,4);
          if (((local_54 != 0) && (*(int *)(local_54 + 0x68) == 0x80)) &&
             (*(int *)(local_54 + 0x60) == local_8b0)) {
            local_50 = 0x3ef;
            local_4c = 1;
            local_8b8 = RwStartDisplayDeviceExt(iVar6,0,1,&local_50);
            if (local_8b8 != 0) break;
          }
          RwCloseDisplayDevice(iVar6);
        }
      }
      iVar3 = iVar3 + 1;
      uVar13 = RwExtract(iVar5,iVar3,local_8ac,0x50);
      uVar15 = extraout_ECX_02;
    }
  }
  if (local_8b8 == 0) {
    iVar3 = 1;
    uVar13 = RwExtract(iVar5,1,local_8ac,0x50);
    uVar15 = extraout_ECX_03;
    while ((int)uVar13 != 0) {
      if (((local_8a8 != 'M') && (local_8a8 != 'm')) && ((local_8a8 != 'D' && (local_8a8 != 'd'))))
      {
        uVar13 = FUN_0041a110(uVar15,(int)((ulonglong)uVar13 >> 0x20),local_8ac);
        iVar6 = (int)uVar13;
        if (iVar6 != 0) {
          local_48 = 0;
          RwGetDeviceInfo(0xc,&local_48,4);
          if (((local_48 != 0) && (*(int *)(local_48 + 0x68) == 0x80)) &&
             (*(int *)(local_48 + 0x60) == local_8b0)) {
            local_44 = 0x3ef;
            local_40 = 1;
            local_8b8 = RwStartDisplayDeviceExt(iVar6,0,1,&local_44);
            if (local_8b8 != 0) break;
          }
          RwCloseDisplayDevice(iVar6);
        }
      }
      iVar3 = iVar3 + 1;
      uVar13 = RwExtract(iVar5,iVar3,local_8ac,0x50);
      uVar15 = extraout_ECX_04;
    }
  }
  if (local_8b8 == 0) {
    local_3c = 0x3ec;
    local_8b0 = 8;
    local_38 = 8;
    RwOpenExt(s_MSWindows_004705d0,0,1,&local_3c);
    pbVar8 = FUN_0043c8f0((byte *)s_IDS_USING_RENDERWARE_DRIVER_004705dc);
    this = (void *)FUN_00403350(0x49eda8,pbVar8);
    FUN_004049b0(*(void **)((int)this + 4),local_34);
    local_29 = DAT_004895b4;
    piVar9 = (int *)FUN_00404a00(local_34);
    bVar1 = (**(code **)(*piVar9 + 0x14))(10);
    FUN_00404dc0(local_34);
    iVar3 = FUN_00404b40(this,bVar1);
    FUN_00403ac0(iVar3);
  }
  else {
    pbVar8 = local_8ac;
    pbVar17 = &DAT_004705f8;
    pbVar14 = &DAT_004705fc;
    pbVar10 = FUN_0043c8f0((byte *)s_IDS_USING_SOFTWARE_DRIVER_00470600);
    iVar3 = FUN_00403350(0x49eda8,pbVar10);
    iVar3 = FUN_00403350(iVar3,pbVar14);
    iVar3 = FUN_00403350(iVar3,pbVar8);
    FUN_00403350(iVar3,pbVar17);
  }
  DAT_00489568 = local_8b0 >> 3;
  DAT_0048956c = DAT_00489568 << 7;
  DAT_00489570 = DAT_00489568 << 0xe;
  RwSetShapePath(&DAT_0047061c,1);
  DAT_00489574 = 2;
  if (DAT_00489578 != 0) {
    DAT_00489574 = 6;
  }
  uVar15 = DAT_00489574;
  uVar11 = RwPushCurrentMaterial(DAT_00489574);
  RwSetMaterialTextureModes(uVar11,uVar15);
  RwSetTextureDithering(2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


