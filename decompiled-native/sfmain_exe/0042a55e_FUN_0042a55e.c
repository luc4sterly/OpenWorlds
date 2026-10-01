// 0042a55e FUN_0042a55e [Global]
// program: sfmain.exe

int __fastcall FUN_0042a55e(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 uVar2;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar3;
  undefined4 extraout_EDX_01;
  int *unaff_EBX;
  undefined8 uVar4;
  int local_24;
  byte *local_1c;
  
  FUN_0042cd01(param_1,param_2);
  local_1c = FUN_0042d0b4(extraout_ECX,&DAT_0043766c);
  uVar2 = extraout_ECX_00;
  while (local_1c != (byte *)0x0) {
    local_1c = FUN_0042d0b4(uVar2,&DAT_0043766c);
    uVar2 = extraout_ECX_01;
  }
  FUN_0042b9b8();
  uVar4 = FUN_0042cd01(extraout_ECX_02,extraout_EDX);
  uVar4 = FUN_0042ba46(extraout_ECX_03,(int)((ulonglong)uVar4 >> 0x20));
  puVar1 = (undefined4 *)uVar4;
  uVar4 = FUN_0042cd01(extraout_ECX_04,(int)((ulonglong)uVar4 >> 0x20));
  *puVar1 = (int)uVar4;
  local_1c = FUN_0042d0b4(extraout_ECX_05,&DAT_0043766c);
  uVar2 = extraout_ECX_06;
  uVar3 = extraout_EDX_00;
  local_24 = 1;
  while (local_1c != (byte *)0x0) {
    uVar4 = FUN_0042cd01(uVar2,uVar3);
    puVar1[local_24] = (int)uVar4;
    local_1c = FUN_0042d0b4(extraout_ECX_08,&DAT_0043766c);
    uVar2 = extraout_ECX_07;
    uVar3 = extraout_EDX_01;
    local_24 = local_24 + 1;
  }
  *param_2 = local_24;
  *unaff_EBX = (int)puVar1;
  FUN_0042b9b8();
  return local_24;
}


