// 00432645 FUN_00432645 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00432645(undefined4 param_1,int param_2)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  (*(code *)PTR_FUN_0043e818)();
  iVar1 = FUN_00432719(1,0x10);
  if (iVar1 != 0) {
    uVar3 = FUN_004331e1();
    puVar2 = (undefined4 *)((ulonglong)uVar3 >> 0x20);
    if ((int)uVar3 == 0) {
      puVar2[2] = param_2;
      puVar2[1] = in_EAX;
      puVar2[3] = (uint)*(byte *)(param_2 + 0x52);
      *puVar2 = _DAT_004e592c;
      _DAT_004e592c = puVar2;
    }
    else {
      FUN_0042b9b8();
    }
  }
  (*(code *)PTR_FUN_0043e81c)();
  return extraout_ECX;
}


