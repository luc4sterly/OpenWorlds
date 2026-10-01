// 0044b350 FUN_0044b350 [Global]
// program: gamma.dll

void FUN_0044b350(int param_1)

{
  int iVar1;
  
  iVar1 = -1;
  do {
    iVar1 = iVar1 + 1;
  } while (*(short *)(param_1 + iVar1 * 2) != 0);
  return;
}


