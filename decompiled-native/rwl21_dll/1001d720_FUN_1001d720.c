// 1001d720 FUN_1001d720 [Global]
// program: RWL21.DLL

undefined4 FUN_1001d720(int *param_1)

{
  if (0 < param_1[2]) {
    param_1[2] = param_1[2] + -1;
  }
  return *(undefined4 *)(*param_1 + param_1[2] * 4);
}


