// 004574d0 FUN_004574d0 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_004574d0(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar2 = FUN_00458fc0(param_1,4);
  if (iVar2 == 0) {
    bVar1 = true;
    iVar2 = FUN_00458fc0(param_1,100);
    if (iVar2 == 0) {
      iVar2 = FUN_00458fc0(param_1,400);
      if (iVar2 != 100) {
        bVar1 = false;
      }
    }
    if (bVar1) {
      uVar3 = 1;
    }
  }
  return uVar3;
}


