// 0042fe2e FUN_0042fe2e [Global]
// program: sfmain.exe

undefined4 __fastcall FUN_0042fe2e(undefined4 param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 extraout_ECX;
  uint unaff_EBX;
  
  if (*(int *)(param_2 + 0x10) < *(int *)(in_EAX + 0x10)) {
    return 1;
  }
  if (*(int *)(param_2 + 0x10) <= *(int *)(in_EAX + 0x10)) {
    iVar1 = FUN_0042fd49(param_2,unaff_EBX);
    iVar2 = FUN_0042fd49(extraout_ECX,unaff_EBX);
    if (iVar2 < iVar1) {
      return 1;
    }
  }
  return 0;
}


