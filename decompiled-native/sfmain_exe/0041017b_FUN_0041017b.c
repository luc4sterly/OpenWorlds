// 0041017b FUN_0041017b [Global]
// program: sfmain.exe

undefined4 __fastcall FUN_0041017b(undefined4 param_1,int param_2)

{
  HWND in_EAX;
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 uVar2;
  undefined1 *unaff_EBX;
  undefined1 local_34;
  int local_30;
  int local_2c;
  undefined4 local_14;
  
  if (DAT_0043d584 == 0) {
    FUN_0040f8f4(param_1,DAT_00445b54);
    FUN_0042965d();
    FUN_0042965d();
    FUN_0042965d();
    param_1 = extraout_ECX;
  }
  if (DAT_004623bc == 0) {
    local_30 = 0;
  }
  else {
    local_2c = 0;
    while ((local_2c < DAT_0043d578 && (local_30 = FUN_0040ff2b(param_1,unaff_EBX), -1 < local_30)))
    {
      local_2c = local_2c + 1;
      param_1 = extraout_ECX_00;
    }
  }
  if (DAT_0043d584 == 0) {
    FUN_0042965d();
    FUN_0042965d();
    FUN_0042965d();
    FUN_0040fa60();
  }
  if ((local_30 < 0) && (iVar1 = Ordinal_111(), iVar1 != 0x2734)) {
    if (*(int *)(param_2 + 0x654) == 0) {
      local_34 = 1;
    }
    else {
      local_34 = 2;
    }
    *(undefined1 *)(param_2 + 4) = local_34;
    *(undefined4 *)(param_2 + 0x654) = 0;
    uVar2 = extraout_ECX_01;
    if (*(int *)(param_2 + 300) != -1) {
      KillTimer(in_EAX,2);
      _lclose(*(HFILE *)(param_2 + 300));
      *(undefined4 *)(param_2 + 300) = 0xffffffff;
      uVar2 = extraout_ECX_02;
    }
    FUN_004100f5(uVar2,param_2);
    local_14 = 0;
  }
  else {
    local_14 = 1;
  }
  return local_14;
}


