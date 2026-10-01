// 0040d86b FUN_0040d86b [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040d86b(undefined4 param_1,LPCSTR param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  HWND pHVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 uVar7;
  undefined4 extraout_EDX;
  uint *unaff_EBX;
  undefined8 uVar8;
  uint local_138;
  uint local_134;
  uint local_20;
  
  if ((DAT_004393a0 != 0) && (DAT_004393a4 != (int *)0x0)) {
    FUN_0042c6a0(param_1,DAT_00445b1c);
    uVar8 = FUN_0042c7fc(extraout_ECX,extraout_EDX);
    iVar4 = lstrlenA(param_2);
    uVar2 = unaff_EBX[5];
    FUN_0042c062(DAT_004393a4,0xc);
    FUN_004080a4(extraout_ECX_00,param_2);
    FUN_0042c062(DAT_004393a4,(int)(short)((short)iVar4 + 1));
    uVar1 = *unaff_EBX;
    if ((uint)((int)uVar8 - _DAT_004393ac) < 3) {
      local_20 = 0;
    }
    else {
      local_20 = 0x1000000;
    }
    *unaff_EBX = local_20 | 0x42000000;
    _DAT_004393ac = (int)uVar8;
    FUN_0042c062(DAT_004393a4,(int)(short)((short)uVar2 + 0x1c));
    uVar7 = extraout_ECX_01;
    if ((((DAT_0043d640 != (HWND)0x0) && ((*unaff_EBX & 0x1000000) != 0)) && (DAT_004393b0 != 0)) &&
       (iVar5 = FUN_0040d6c0(extraout_ECX_01,DAT_004393b8 + 1), iVar3 = DAT_00445b1c,
       iVar4 = DAT_004393b8, uVar7 = extraout_ECX_02, iVar5 != 0)) {
      DAT_004393b8 = DAT_004393b8 + 1;
      *(int *)(DAT_004393b0 + iVar4 * 4) = DAT_00445b1c;
      FUN_0040d5fb(extraout_ECX_02,iVar3);
      uVar7 = extraout_ECX_03;
    }
    *unaff_EBX = uVar1;
    uVar8 = FUN_0042c794(uVar7,unaff_EBX);
    DAT_00445b1c = (int)uVar8;
    if (DAT_0043d640 != (HWND)0x0) {
      local_134 = (uint)(0 < DAT_00445b1c);
      pHVar6 = GetDlgItem(DAT_0043d640,0x408);
      EnableWindow(pHVar6,local_134);
      local_138 = (uint)(0 < DAT_00445b1c);
      pHVar6 = GetDlgItem(DAT_0043d640,0x402);
      EnableWindow(pHVar6,local_138);
    }
  }
  return;
}


