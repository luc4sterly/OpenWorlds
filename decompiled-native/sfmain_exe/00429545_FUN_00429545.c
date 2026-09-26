// 00429545 FUN_00429545 [Global]
// programa: sfmain.exe

int __fastcall FUN_00429545(short param_1,undefined4 param_2)

{
  int *in_EAX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 uVar1;
  undefined4 extraout_ECX_03;
  undefined4 extraout_EDX;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined2 local_3c;
  short local_3a;
  int local_2c;
  int *local_28;
  undefined4 local_24;
  int local_18;
  int local_14;
  
  local_28 = in_EAX;
  local_24 = param_2;
  uVar2 = Ordinal_23(2,param_2,0);
  local_18 = (int)uVar2;
  if (local_18 == -1) {
    uVar2 = Ordinal_111();
    uVar1 = extraout_ECX_00;
  }
  else {
    uVar2 = uVar2 & 0xffffffff00000000;
    uVar1 = extraout_ECX;
  }
  local_2c = (int)uVar2;
  local_14 = local_2c;
  if ((local_2c == 0) && ((DAT_0043d58c != 0 || (param_1 != 0)))) {
    local_3c = 2;
    local_3a = param_1;
    uVar3 = Ordinal_2(local_18,&local_3c,0x10);
    uVar2 = CONCAT44((int)((ulonglong)uVar3 >> 0x20),local_2c);
    uVar1 = extraout_ECX_01;
    if ((int)uVar3 != 0) {
      uVar3 = Ordinal_111();
      uVar2 = CONCAT44((int)((ulonglong)uVar3 >> 0x20),local_2c);
      local_14 = (int)uVar3;
      uVar1 = extraout_ECX_02;
    }
  }
  local_2c = (int)uVar2;
  if (local_14 != 0) {
    FUN_00429482(uVar1,(int)(uVar2 >> 0x20));
    FUN_004296b9(s_Error_opening_connection__d__s_0043749e);
    FUN_004294e8(extraout_ECX_03,extraout_EDX);
    local_18 = -1;
  }
  *local_28 = local_18;
  return local_14;
}


