// 0044b300 FUN_0044b300 [Global]
// program: gamma.dll

int FUN_0044b300(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  
  do {
    if (*param_1 != *param_2) {
      return (uint)*param_1 - (uint)*param_2;
    }
  } while ((*param_1 != 0) &&
          (uVar1 = *param_2, param_2 = param_2 + 1, param_1 = param_1 + 1, uVar1 != 0));
  return 0;
}


