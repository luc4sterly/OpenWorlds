// 00439bb0 FUN_00439bb0 [Global]
// programa: gamma.dll

int __thiscall FUN_00439bb0(int param_1,int param_2)

{
  FUN_00403350(param_2,(byte *)s__placeholder_00476790);
  if (*(int **)(param_1 + 0xc) == (int *)0x0) {
    FUN_00403350(param_2,(byte *)s__nil__004767a0);
  }
  else {
    (**(code **)(**(int **)(param_1 + 0xc) + 0xc))(param_2);
  }
  FUN_00427d00(param_2);
  return param_2;
}


