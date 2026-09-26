// 0040ff2b FUN_0040ff2b [Global]
// programa: sfmain.exe

int __fastcall FUN_0040ff2b(undefined4 param_1,undefined1 *param_2)

{
  bool bVar1;
  int in_EAX;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar3;
  int unaff_EBX;
  undefined8 uVar4;
  int local_28;
  int local_14;
  
  if (DAT_0043d5e4 == 0) {
    if (*(int *)(in_EAX + 0x658) == 0) {
      bVar1 = false;
      if ((*(short *)(in_EAX + 0x4e42) != 0) ||
         (((DAT_0043d590 == 0 || (DAT_0043d594 != 0)) && (DAT_0043d598 == 0)))) {
        if (*(short *)(in_EAX + 0x4e42) == 0) {
          local_28 = FUN_0042984a();
          param_1 = extraout_ECX_00;
          uVar3 = extraout_EDX_00;
        }
        else {
          local_28 = FUN_00421bcd((undefined1 *)(in_EAX + 0x664),param_2);
          param_1 = extraout_ECX;
          uVar3 = extraout_EDX;
        }
        if (local_28 < 0) {
          if ((DAT_0043d594 == 0) && (DAT_0043d590 = 1, DAT_0043d634 != (HWND)0x0)) {
            uVar4 = FUN_00429192(param_1,uVar3);
            SetDlgItemTextA(DAT_0043d634,0x408,(LPCSTR)uVar4);
            param_1 = extraout_ECX_01;
          }
        }
        else {
          bVar1 = true;
        }
      }
      if (!bVar1) {
        local_28 = FUN_00429725();
        param_1 = extraout_ECX_02;
      }
      if (DAT_0043d704 != unaff_EBX) {
        DAT_0043d704 = unaff_EBX;
        FUN_004173ab(param_1,unaff_EBX);
      }
      if (((local_28 != unaff_EBX) && (DAT_0043d5a0 == 0)) &&
         ((*(undefined4 *)(in_EAX + 0x658) = 1, local_28 == -1 &&
          (iVar2 = Ordinal_111(), iVar2 == 0x2733)))) {
        local_28 = 0;
      }
      local_14 = local_28;
    }
    else {
      DAT_0043d6c0 = DAT_0043d6c0 + 1;
      FUN_004173ab(param_1,DAT_0043d6c0);
      FUN_004296b9(s_Output_lost__socket_busy____pack_00435c69);
      local_14 = unaff_EBX;
    }
  }
  else {
    local_14 = 0;
  }
  return local_14;
}


