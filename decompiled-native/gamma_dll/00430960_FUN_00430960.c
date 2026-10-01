// 00430960 FUN_00430960 [Global]
// program: gamma.dll

int __cdecl FUN_00430960(int param_1,int param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  undefined3 extraout_var;
  void *this;
  uint uVar3;
  
  uVar3 = (param_2 - param_1) / 0x110;
  while (uVar1 = uVar3, 0 < (int)uVar1) {
    uVar3 = (int)((uVar1 + 1) - (uint)(uVar1 < 0x80000000)) >> 1;
    this = (void *)(param_1 + uVar3 * 0x110);
    bVar2 = FUN_004274e0(this,param_3);
    if (CONCAT31(extraout_var,bVar2) != 0) {
      param_1 = (int)this + 0x110;
      uVar3 = uVar1 - (uVar3 + 1);
    }
  }
  return param_1;
}


