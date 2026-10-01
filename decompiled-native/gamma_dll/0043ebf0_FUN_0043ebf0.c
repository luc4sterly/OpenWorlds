// 0043ebf0 FUN_0043ebf0 [Global]
// program: gamma.dll

undefined4 FUN_0043ebf0(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    return 0x80070057;
  }
  iVar1 = 0;
  if (param_1 != 0xc) {
    iVar1 = param_1 + 8;
  }
  *param_2 = iVar1;
  (**(code **)(*(int *)*param_2 + 4))((int *)*param_2);
  return 0;
}


