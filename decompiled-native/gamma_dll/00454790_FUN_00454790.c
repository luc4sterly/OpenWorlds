// 00454790 FUN_00454790 [Global]
// programa: gamma.dll

void __cdecl FUN_00454790(int param_1)

{
  bool bVar1;
  int *piVar2;
  
  piVar2 = (int *)(*(uint *)(param_1 + -4) & 0xfffffffe);
  FUN_00454380((int)piVar2,(uint *)(param_1 + -8));
  bVar1 = false;
  if (((piVar2[4] & 2U) == 0) && ((piVar2[4] & 0xfffffff8U) == (piVar2[3] & 0xfffffff8U) - 0x18)) {
    bVar1 = true;
  }
  if (bVar1) {
    FUN_00454680(piVar2);
    FUN_004590c0((int)piVar2);
  }
  return;
}


