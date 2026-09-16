// 004492a0 FUN_004492a0 [Global]
// programa: gamma.dll

bool __fastcall FUN_004492a0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60);
  if (iVar1 != 0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 0x18))(*(int **)(param_1 + 0x18),iVar1);
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  ResetEvent(*(HANDLE *)(param_1 + 0x4c));
  return iVar1 == 0;
}


