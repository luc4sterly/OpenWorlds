// 0043a440 FUN_0043a440 [Global]
// program: gamma.dll

int __thiscall FUN_0043a440(int param_1,int param_2)

{
  void *this;
  int iVar1;
  float fVar2;
  
  fVar2 = (float)((float10)*(uint *)(param_1 + 0x18) +
                 (float10)*(uint *)(param_1 + 0x1c) / (float10)DAT_00472020);
  this = (void *)FUN_00403350(param_2,(byte *)s__shiftto_t__004767a8);
  iVar1 = FUN_00428120(this,fVar2);
  FUN_00427d00(iVar1);
  (**(code **)(**(int **)(param_1 + 0xc) + 0xc))(param_2);
  FUN_00427d00(param_2);
  (**(code **)(**(int **)(param_1 + 0x14) + 0xc))(param_2);
  FUN_00427d00(param_2);
  return param_2;
}


