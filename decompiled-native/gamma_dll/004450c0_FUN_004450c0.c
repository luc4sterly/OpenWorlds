// 004450c0 FUN_004450c0 [Global]
// program: gamma.dll

undefined4 __thiscall FUN_004450c0(int param_1,int *param_2)

{
  int iStack_10;
  
  (**(code **)(*param_2 + 0x24))(param_2,&iStack_10);
  if (iStack_10 == *(int *)(param_1 + 0x1c)) {
    return 0x80040208;
  }
  return 0;
}


