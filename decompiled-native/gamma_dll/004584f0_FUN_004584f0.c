// 004584f0 FUN_004584f0 [Global]
// program: gamma.dll

void __cdecl FUN_004584f0(char *param_1,char *param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_3 != 0) {
    do {
      *param_1 = *param_2;
      if (*param_1 == '\0') {
        return;
      }
      uVar1 = uVar1 + 1;
      param_2 = param_2 + 2;
      param_1 = param_1 + 1;
    } while (uVar1 < param_3);
  }
  return;
}


