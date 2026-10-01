// 00413aeb FUN_00413aeb [Global]
// program: sfmain.exe

undefined1 * __fastcall FUN_00413aeb(undefined4 param_1,int param_2)

{
  byte bVar1;
  int in_EAX;
  DWORD DVar2;
  LPCSTR pCVar3;
  int iVar4;
  HWND pHVar5;
  uint uVar6;
  undefined1 *puVar7;
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
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined8 uVar8;
  undefined4 uVar9;
  CHAR local_1c4 [256];
  undefined1 local_c4 [88];
  _MEMORYSTATUS local_6c;
  byte local_4c [16];
  byte local_3c [16];
  tagPOINT local_2c;
  int local_24;
  undefined1 *local_20;
  int local_1c;
  int local_18;
  
  local_24 = in_EAX;
  local_18 = param_2;
  DVar2 = GetTickCount();
  uVar8 = FUN_00429192(extraout_ECX,extraout_EDX);
  wsprintfA(local_1c4,(LPCSTR)uVar8,DVar2);
  uVar8 = FUN_0042c7fc(extraout_ECX_00,extraout_EDX_00);
  uVar9 = (undefined4)uVar8;
  uVar8 = FUN_00429192(extraout_ECX_01,(int)((ulonglong)uVar8 >> 0x20));
  pCVar3 = (LPCSTR)uVar8;
  iVar4 = FUN_0042c5ad();
  wsprintfA(local_1c4 + iVar4,pCVar3,uVar9);
  uVar9 = 0x100;
  iVar4 = FUN_0042c5ad();
  Ordinal_57(local_1c4 + iVar4,uVar9);
  pHVar5 = GetActiveWindow();
  uVar8 = FUN_00429192(extraout_ECX_02,extraout_EDX_01);
  pCVar3 = (LPCSTR)uVar8;
  iVar4 = FUN_0042c5ad();
  wsprintfA(local_1c4 + iVar4,pCVar3,pHVar5);
  uVar9 = 0x100000;
  uVar8 = FUN_00429192(extraout_ECX_03,extraout_EDX_02);
  pCVar3 = (LPCSTR)uVar8;
  iVar4 = FUN_0042c5ad();
  wsprintfA(local_1c4 + iVar4,pCVar3,uVar9);
  local_6c.dwLength = 0x20;
  GlobalMemoryStatus(&local_6c);
  uVar8 = FUN_00429192(extraout_ECX_04,extraout_EDX_03);
  pCVar3 = (LPCSTR)uVar8;
  iVar4 = FUN_0042c5ad();
  wsprintfA(local_1c4 + iVar4,pCVar3,local_6c.dwMemoryLoad);
  uVar8 = FUN_00429192(extraout_ECX_05,extraout_EDX_04);
  pCVar3 = (LPCSTR)uVar8;
  iVar4 = FUN_0042c5ad();
  wsprintfA(local_1c4 + iVar4,pCVar3,local_6c.dwAvailPhys);
  uVar8 = FUN_00429192(extraout_ECX_06,extraout_EDX_05);
  pCVar3 = (LPCSTR)uVar8;
  iVar4 = FUN_0042c5ad();
  wsprintfA(local_1c4 + iVar4,pCVar3,local_6c.dwAvailPageFile);
  GetCursorPos(&local_2c);
  uVar8 = FUN_00429192(extraout_ECX_07,extraout_EDX_06);
  pCVar3 = (LPCSTR)uVar8;
  iVar4 = FUN_0042c5ad();
  wsprintfA(local_1c4 + iVar4,pCVar3,local_2c.x,local_2c.y);
  FUN_004020d3();
  FUN_0042c5ad();
  FUN_004020fd(local_c4,(int)local_1c4);
  FUN_004021a0(extraout_ECX_08,(int)local_c4);
  uVar8 = FUN_0042c7fc(extraout_ECX_09,extraout_EDX_07);
  uVar6 = (int)uVar8 + 0xfe61U ^ 0x375f;
  uVar8 = FUN_00429192(extraout_ECX_10,(int)((ulonglong)uVar8 >> 0x20));
  pCVar3 = (LPCSTR)uVar8;
  iVar4 = FUN_0042c5ad();
  wsprintfA(local_1c4 + iVar4,pCVar3,uVar6);
  FUN_004020d3();
  FUN_0042c5ad();
  FUN_004020fd(extraout_ECX_11,(int)local_1c4);
  FUN_004021a0(extraout_ECX_12,(int)local_c4);
  local_1c = 0;
  puVar7 = (undefined1 *)0x0;
  for (local_20 = (undefined1 *)0x0; (int)local_20 < 0x10; local_20 = local_20 + 1) {
    bVar1 = local_20[(int)local_3c] ^ local_20[(int)local_4c];
    if (local_18 == 0) {
      *(char *)(local_1c + local_24) = (char)((int)(uint)bVar1 >> 4) + 'A';
      *(byte *)(local_1c + 1 + local_24) = (bVar1 & 0xf) + 0x41;
      iVar4 = local_1c + 2;
      if (((uint)local_20 & 1) != 0) {
        *(undefined1 *)(local_1c + 2 + local_24) = 0x2d;
        iVar4 = local_1c + 3;
      }
    }
    else {
      local_20[local_24] = bVar1;
      iVar4 = local_1c;
    }
    local_1c = iVar4;
    puVar7 = local_20;
  }
  if (local_18 == 0) {
    puVar7 = (undefined1 *)(local_24 + local_1c + -1);
    *puVar7 = 0;
  }
  return puVar7;
}


