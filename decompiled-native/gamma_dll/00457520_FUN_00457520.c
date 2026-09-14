// 00457520 FUN_00457520 [Global]
// programa: gamma.dll

int __cdecl FUN_00457520(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar3 = FUN_00458de0(param_1,4);
  uVar4 = FUN_00458de0(param_1,100);
  if (param_1 < 100) {
    iVar1 = FUN_00458f50();
  }
  else {
    iVar1 = FUN_00458f50();
    iVar1 = iVar1 + 1;
  }
  iVar1 = ((int)uVar3 - (int)uVar4) + iVar1;
  iVar2 = FUN_004574d0(param_1);
  if (iVar2 != 0) {
    if (param_1 < 0) {
      if (1 < param_2) {
        iVar1 = iVar1 + 1;
      }
    }
    else if (param_2 < 2) {
      iVar1 = iVar1 + -1;
    }
  }
  return iVar1;
}


