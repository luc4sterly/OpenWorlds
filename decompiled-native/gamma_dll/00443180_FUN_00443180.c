// 00443180 FUN_00443180 [Global]
// program: gamma.dll

bool __thiscall FUN_00443180(void *this,int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (**(int **)this == 0) {
    iVar1 = FUN_00442bc0(*(int **)this,param_1,param_2,param_3);
    return iVar1 == 0;
  }
  return false;
}


