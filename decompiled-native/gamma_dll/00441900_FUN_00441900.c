// 00441900 FUN_00441900 [Global]
// program: gamma.dll

int FUN_00441900(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *this;
  int *piVar1;
  int iVar2;
  int iVar3;
  
  this = (int *)(param_1 + -0xc);
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x68);
  EnterCriticalSection(lpCriticalSection);
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 1) {
    iVar2 = (**(code **)(*this + 0xd4))(1);
    LeaveCriticalSection(lpCriticalSection);
    return iVar2;
  }
  if (*(int *)(*(int *)(param_1 + 100) + 0x18) == 0) {
    *(undefined4 *)(param_1 + 8) = 1;
    iVar2 = (**(code **)(*this + 0xd4))(1);
    LeaveCriticalSection(lpCriticalSection);
    return iVar2;
  }
  iVar3 = FUN_00443a70(this);
  if (iVar3 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    return iVar3;
  }
  FUN_00449b50(this,1);
  (**(code **)(*this + 0x124))();
  (**(code **)(*this + 0xcc))(1);
  (**(code **)(*this + 0x110))();
  FUN_00449a00((int)this);
  piVar1 = *(int **)(*(int *)(param_1 + 100) + 0x98);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))(piVar1);
  }
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x4c) = 0;
    (**(code **)(*this + 0x114))();
  }
  iVar2 = (**(code **)(*this + 0xd4))(iVar2);
  LeaveCriticalSection(lpCriticalSection);
  return iVar2;
}


