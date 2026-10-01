// 004418f0 FUN_004418f0 [Global]
// program: gamma.dll

int FUN_004418f0(int param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *this;
  int *piVar1;
  int iVar2;
  int iVar3;
  
  this = (int *)(param_1 + -0xc);
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x68);
  EnterCriticalSection(lpCriticalSection);
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 8) == 2) {
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  if (*(int *)(*(int *)(param_1 + 100) + 0x18) == 0) {
    iVar3 = 0;
    if (this != (int *)0x0) {
      iVar3 = param_1;
    }
    FUN_00443eb0(this,1,0,iVar3);
    *(undefined4 *)(param_1 + 8) = 2;
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  SetEvent(*(HANDLE *)(param_1 + 0x48));
  iVar2 = FUN_00443b10(this,param_2,param_3);
  if (iVar2 < 0) {
    LeaveCriticalSection(lpCriticalSection);
    return iVar2;
  }
  (**(code **)(*this + 0xcc))(1);
  FUN_00449b50(this,0);
  piVar1 = *(int **)(*(int *)(param_1 + 100) + 0x98);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))(piVar1);
  }
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x4c) = 0;
    (**(code **)(*this + 0x114))();
  }
  iVar3 = (**(code **)(*this + 0x120))();
  LeaveCriticalSection(lpCriticalSection);
  return iVar3;
}


