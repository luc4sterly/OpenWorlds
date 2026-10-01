// 00434e50 FUN_00434e50 [Global]
// program: gamma.dll

void __cdecl FUN_00434e50(uint param_1,undefined *param_2)

{
  uint *this;
  int iVar1;
  int iVar2;
  
  this = FUN_0042c7f0();
  if (this == (uint *)0x0) {
    return;
  }
  iVar1 = FUN_0042ca00(this,param_1);
  if (iVar1 == 0) {
    return;
  }
  iVar2 = FUN_0042bd40(iVar1);
  for (iVar1 = *(int *)(iVar2 + 8); iVar1 != *(int *)(iVar2 + 4) * 0x104 + *(int *)(iVar2 + 8);
      iVar1 = iVar1 + 0x104) {
    (*(code *)param_2)(iVar1 + 4);
  }
  return;
}


