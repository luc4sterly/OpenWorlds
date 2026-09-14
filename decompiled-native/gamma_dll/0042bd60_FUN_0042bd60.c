// 0042bd60 FUN_0042bd60 [Global]
// programa: gamma.dll

int __thiscall FUN_0042bd60(void *this,int param_1)

{
  bool bVar1;
  void *this_00;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)((int)this + 0x48);
  while( true ) {
    if (iVar2 == *(int *)((int)this + 0x44) * 0x11c + *(int *)((int)this + 0x48)) {
      return 0;
    }
    iVar3 = param_1;
    this_00 = (void *)FUN_0042be60(iVar2);
    bVar1 = FUN_00427480(this_00,iVar3);
    if (CONCAT31(extraout_var,bVar1) != 0) break;
    iVar2 = iVar2 + 0x11c;
  }
  return iVar2;
}


